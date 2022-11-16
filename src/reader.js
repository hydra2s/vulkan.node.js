(async()=>{

    const { parseXml }  = (await import('@rgrove/parse-xml'));
    const fs = await import('fs');
    const JSON5  = (await import('json5')).default;
    const JSON6  = (await import('json-6')).default;
    const {JSOX}  = (await import('jsox'));

    // 
    let getDocs = (path = "../Vulkan-Docs/xml/vk.xml") => {
        return parseXml(fs.readFileSync(path,"utf8").replace(/\r?\n|\r/g, " ").replace(/\s+/g,' ').trim());
    };

    //
    let noSpaces = (xml)=>{
        let text = xml.text ? xml.text.trim() : "";
        if (text) { xml.text = text; };
        return xml.type == "text" ? !!text : true;
    };
    
    // unlock assign and trim operations
    let cloneObj = (obj)=>{
        //return JSON5.parse(JSON5.stringify(obj));
        return Array.isArray(obj) ? [...obj] : {...obj};
    };
    
    //
    let filterNoSpaced = (xml)=>{ let xmc = xml; if (xmc.children && xmc.children.length > 0) { xmc.children = xmc.children.filter(noSpaces).map(filterNoSpaced); } else { delete xmc.children; }; return xmc; };

    // 
    let getComponents = (doc)=>{
        let registry = filterNoSpaced(JSON5.parse(JSON5.stringify(doc.children.find((e,i)=>{ return e.type == "element" && e.name == "registry"; }))));
        let types = filterNoSpaced(registry.children.find((e,i)=>{ return e.type == "element" && e.name == "types"; }));
        let structs = types.children.filter((e,i)=>{ return e.type == "element" && e.name == "type" && e.attributes["category"] == "struct"; }).map(filterNoSpaced).filter(noSpaces);
        let extensions = filterNoSpaced(registry.children.find((e,i)=>{ return e.type == "element" && e.name == "extensions"; }));
        let commands = registry.children.filter((e,i)=>{ return e.type == "element" && e.name == "commands"; }).map(filterNoSpaced);
        return { registry, types, structs, extensions, commands };
    };

    // 
    let extract = (ec)=>{
        return ec.children.find((en,ind)=>{ return en.type=="text"; }).text;
    };

    // 
    let memberByName = (e,name)=>{
        return e.children ? e.children.find((em,im)=>{
            if (em.type == "element" && em.name == "member") {

                return !!em.children.find((ec,ic)=>{ 
                    return ec.type=="element" && ec.name=="name" && extract(ec).includes(name);
                });

            };
            return false;
        }) : null;
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
    let parseDocs = (path = "../../Vulkan-Docs/xml/vk.xml")=>{
        let docs = getDocs(path); fs.writeFileSync("vulkan.json", JSON.stringify(filterNoSpaced(JSON5.parse(JSON5.stringify(docs))), null, 2).trim(), "utf8");
        let loaded = getComponents(docs); fs.writeFileSync("commands.json", JSON.stringify(loaded.commands, null, 2).trim(), "utf8");
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

})();