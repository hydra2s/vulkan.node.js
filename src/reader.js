(async()=>{
    const { parseXml } = (await import('@rgrove/parse-xml'));
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
    let structsOnly = (s)=>{ return s.attributes["category"] == "struct"; };

    //
    let parseParam = (e)=>{
        let parsed = { name: "", type: "void", isPointer: false, isConst: false };
        if (e) {
            e.forEach((p)=>{
                if (p.type == "text" && p.text == "*") { parsed.isPointer = true; };
                if (p.type == "text" && p.text == "const") { parsed.isConst = true; };
                if (p.type == "element" && p.name == "type") { parsed.type = p.children[0].text; };
                if (p.type == "element" && p.name == "name") { parsed.name = p.children[0].text; };
            });
            return parsed;
        }
        return parsed;
    }

    // 
    let parseStructs = (types)=>{
        let tick = 0;
        return types.filter(structsOnly).map((T)=>{
            let parsed = {};
            parsed.name = T.attributes["name"];
            parsed.params = [];

            if (T.children) {
                T.children.forEach((d)=>{
                    let param = {};
                    if (d.type == "element" && d.name == "member" && d.attributes["values"]) { param.value = d.attributes["values"]; };
                    parsed.params.push({...param, ...parseParam(d.children)});
                });
            };

            

            return parsed;
        }).filter((obj)=>(Object.keys(obj).length > 0));
    };

    //
    let parseRequirements = (types)=>{
        let requirements = {};
        types.map((T)=>{
            
            if (T.attributes["name"] && T.attributes["requires"]) {
                requirements[T.attributes["name"]] = T.attributes["requires"];
            };

        });
        return requirements;
    };

    // TODO: more details
    let parseTypes = (types)=>{
        return types.map((T)=>{
            let parsed = {};
            if (T.children) {
                T.children.forEach((d)=>{
                    if (d.type == "element" && d.name == "type") { parsed.type = d.children[0].text; };
                    if (d.type == "element" && d.name == "name") { parsed.name = d.children[0].text; };
                });
            };
            return parsed;
        }).filter((obj)=>(Object.keys(obj).length > 0));
    };

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
    let extractChildren = (e)=>{
        return e.children;
    }

    //
    let commandParse = (command)=>{
        let cmds = [...(command.children||[])];
        let proto = parseParam(cmds.shift()?.children||[]);
        let params = cmds.map(extractChildren).map(parseParam);
        return { proto, params };
    };

    //
    let parseCommands = (commands)=>{
        return commands.map(commandParse).filter((cmd)=>!!cmd.proto.name);
    }

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
    let U64Types = ["uint64_t", "uintptr_t", "size_t", "VkDeviceSize", "VkDeviceAddress"];
    let U32Types = ["uint32_t", "VkFlags"];

    //
    let passArg = (param, I) => {
        if (param.isPointer) {
            return `
    if (!info[${I}].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    ${param.type}* ${param.name} = (${param.type}*)info[${I}].As<Napi::BigInt>().Uint64Value();`;
        } else
        if (param.type == "float") {
            return `
    if (!info[${I}].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    ${param.type} ${param.name} = (${param.type})info[${I}].As<Napi::Number>().FloatValue();`;
        } else
        if (param.type == "double") {
            return `
    if (!info[${I}].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    ${param.type} ${param.name} = (${param.type})info[${I}].As<Napi::Number>().DoubleValue();`;
        } else
        if (U32Types.indexOf(param.type) >= 0) {
            return `
    if (!info[${I}].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    ${param.type} ${param.name} = (${param.type})info[${I}].As<Napi::Number>().Uint32Value();`;
        } else
        if (param.type == "int32_t") {
            return `
    if (!info[${I}].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    ${param.type} ${param.name} = (${param.type})info[${I}].As<Napi::Number>().Int32Value();`;
        } else 
        //if (U64Types.indexOf(param.type) >= 0) 
        {   // any other is 64-bit number handlers
            return `
    if (!info[${I}].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    ${param.type} ${param.name} = (${param.type})info[${I}].As<Napi::BigInt>().Uint64Value();`;
        }
    };

    //
    let passDispatch = (proto, params)=>{
        if (U32Types.indexOf(proto.type) >= 0) {
            return `
    auto result = ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
    return Napi::Number::New(env, result);
`;
        } else
        if (U64Types.indexOf(proto.type) >= 0 || proto.type.isPointer) {
            return `
    auto result = ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
    return Napi::BigInt::New(env, result);
`;
        } else 
        {
        return `
    ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
    return env.Null();
`;
        }
    };

    //
    let makeCommand = (command)=>{
return `
#ifdef __cplusplus
inline 
#endif
Napi::Value ${command.proto.name.replace(/^vk/, "raw")}(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < ${command.params.length}) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    ${command.params.map(passArg).join(`
`)}
    ${passDispatch(command.proto, command.params)}
        
}
`
    }
    



    // 
    let parseDocs = (path = "../../Vulkan-Docs/xml/vk.xml")=>{
        let docs = getDocs(path); fs.writeFileSync("vulkan.json", JSON.stringify(filterNoSpaced(JSON5.parse(JSON5.stringify(docs))), null, 2).trim(), "utf8");
        let loaded = getComponents(docs); 
        fs.writeFileSync("commands.json", JSON.stringify(loaded.commands, null, 2).trim(), "utf8");
        fs.writeFileSync("types.json", JSON.stringify(loaded.types, null, 2).trim(), "utf8");
        
        //
        let parsed = parseCommands(loaded.commands[0].children);
        fs.writeFileSync("parsed-commands.json", JSON.stringify(parsed, null, 2).trim(), "utf8");

        let parsedStructs = parseStructs(loaded.types.children);
        let parsedTypes = parseTypes(loaded.types.children);
        let parsedRequirements = parseRequirements(loaded.types.children);
        fs.writeFileSync("parsed-types.json", JSON.stringify(parsedTypes, null, 2).trim(), "utf8");
        fs.writeFileSync("parsed-requirements.json", JSON.stringify(parsedRequirements, null, 2).trim(), "utf8");
        fs.writeFileSync("parsed-structs.json", JSON.stringify(parsedStructs, null, 2).trim(), "utf8");

        //
        let usedBy = formExtensionTypeMap(loaded.extensions);
        let sTypeMap = formSTypeMap(filterSType(loaded.structs));
        return {usedBy, sTypeMap, parsed};
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



    let makeCmdWrap = (cmd)=>{
//return `let ${cmd.proto.name} = ()=>{
    //return native.${command.proto.name}(${command.params.map((p=>p.name)).join(", ")});
//}`
    }

    // 
    let genHeader = ()=>{
        let map = parseDocs();

        fs.writeFileSync("./vulkan-API.cpp", `
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
#include <volk/volk.h>
#include <napi.h>

    
${map.parsed.map(makeCommand).join(`
`)}

    

#endif
    `);

    fs.writeFileSync("./vulkan-API.js", `export default require('bindings')('native');
`);
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