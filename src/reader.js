const parseXml = require('@rgrove/parse-xml');
const fs = require('fs');

// 
let getDocs = (path = "../Vulkan-Docs/xml/vk.xml") => {
    return parseXml(fs.readFileSync(path).toString("utf-8"));
};

// 
let getComponents = (doc)=>{
    let registry = doc.children.find((e,i)=>{ return e.type == "element" && e.name == "registry"; });
    let types = registry.children.find((e,i)=>{ return e.type == "element" && e.name == "types"; });
    let structs = types.children.filter((e,i)=>{ return e.type == "element" && e.name == "type" && e.attributes["category"] == "struct"; });
    let extensions = registry.children.find((e,i)=>{ return e.type == "element" && e.name == "extensions"; });
    return { registry, types, structs, extensions };
};

// 
let extract = (ec)=>{
    return ec.children.find((en,ind)=>{ return en.type=="text"; }).text;
};

// 
let memberByName = (e,name)=>{
    return e.children.find((em,im)=>{
        if (em.type == "element" && em.name == "member") {

            return !!em.children.find((ec,ic)=>{ 
                return ec.type=="element" && ec.name=="name" && extract(ec).includes(name);
            });

        };
        return false;
    });
};

// 
let filterSType = (structs)=>{
    return structs.filter((e,i)=>{ 
        return !!memberByName(e,"sType");
    });
};

// 
let formSTypeMap = (hasSType)=>{
    let sTypeMap = {};
    hasSType.map((e,i)=>{
        let sType = memberByName(e,"sType");
        let defVal = sType.attributes["values"];
        if (defVal) {
            sTypeMap[defVal] = e.attributes["name"];
        };
    });
    return sTypeMap;
};

// 
let formExtensionTypeMap = (extensions)=>{
    let usedBy = {};
    extensions.children.filter((e,i)=>{
        return e.type == "element" && e.name == "extension";
    }).map((e,i)=>{
        let extName = e.attributes["name"];
        e.children.filter((ec,ic)=>{  return ec.type == "element" && ec.name == "require"; }).map((ec,ic)=>{
            ec.children.filter((em,im)=>{ return em.type == "element" && em.name == "type"; }).map((em,im)=>{
                usedBy[em.attributes["name"]] = extName;
            });
        });
    });
    return usedBy;
};

// 
let parseDocs = (path = "../Vulkan-Docs/xml/vk.xml")=>{
    let loaded = getComponents(getDocs(path));
    let usedBy = formExtensionTypeMap(loaded.extensions);
    let sTypeMap = formSTypeMap(filterSType(loaded.structs));
    return {usedBy, sTypeMap};
};

// 
let cases = (map)=>{
    let cases = [];
    for (let k in map.sTypeMap) {
        let s = map.sTypeMap[k];
        let by = map.usedBy[s];
        if (by) { cases.push(`#ifdef ${by}`); };
        cases.push(`        case ${k}: return sizeof(${s}); break;`);
        if (by) { cases.push(`#endif`); }; 
    }
    return cases.join("\n");
};

// 
let genHeader = ()=>{
    let map = parseDocs();

    fs.writeFileSync("./sizes.h", `
#ifdef __cplusplus
#pragma once 
#endif

// 
#ifndef VULKAN_SIZES_H
#define VULKAN_SIZES_H

//
#ifdef _WIN32
#ifndef VK_USE_PLATFORM_WIN32_KHR
#define VK_USE_PLATFORM_WIN32_KHR
#include <windows.h>
#endif
#else
#ifdef __linux__ 
//FD defaultly
#endif
#endif

//
#include <vulkan/vulkan.h>

// 
#ifdef __cplusplus
inline 
#endif
size_t vkGetStructureSizeBySType(VkStructureType sType) {
    switch(sType) {
${cases(map)}
        //default: 
    };
    return 0ull;
};
#endif
`);
}

// 
genHeader();
