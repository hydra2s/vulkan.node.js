let getWriter = async()=>{

    const fs = await import('fs');

    //
    let U64Types = ["uint64_t", "uintptr_t", "size_t", "VkDeviceSize", "VkDeviceAddress"];
    let U32Types = ["uint32_t", "VkFlags", "VkResult", "VkBool32"];

    //
    let passArg = (param, I) => {
        if (param.isPointerSet) {
            return `
    if (!info[${I}].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    ${param.type}** ${param.name} = (${param.type}**)info[${I}].As<Napi::BigInt>().Uint64Value(&lossless);`;
        } else

        if (param.isPointer) {
            return `
    if (!info[${I}].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    ${param.type}* ${param.name} = (${param.type}*)info[${I}].As<Napi::BigInt>().Uint64Value(&lossless);`;
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
    ${param.type} ${param.name} = (${param.type})info[${I}].As<Napi::BigInt>().Uint64Value(&lossless);`;
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
        if (U64Types.indexOf(proto.type) >= 0 || proto.isPointer) {
            return `
    auto result = ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
    return Napi::BigInt::New(env, result);
`;
        } else 
        if (proto.type.indexOf("void") >= 0 || proto.type.indexOf("PFN_vkVoidFunction") >= 0) {
        return `
    ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
    return env.Null();
`;
        } else 
        {
        return `
    auto result = ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
    return Napi::BigInt::New(env, result);
`;
        }
    };

    //
    let makeCommand = (command,i,map)=>{
        let by = map.usedBy[command.proto.name];
return `${by ? `#ifdef ${by}` : ``}
#ifdef __cplusplus
inline 
#endif
Napi::Value ${command.proto.name.replace(/^vk/, "raw")}(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < ${command.params.length}) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    ${command.params.map(passArg).join(`
`)}
    ${passDispatch(command.proto, command.params)}
}
${by ? `#endif` : ``}
`
    }
    
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
    let writeCodes = async (map)=>{

        await fs.promises.writeFile("./vulkan-API.cpp", `#ifdef __cplusplus
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

    
${map.parsed.map((cmd,i)=>makeCommand(cmd,i,map)).join(`
`)}

#endif
    `);

    await fs.promises.writeFile("./vulkan-API.js", `export default require('bindings')('native');
`);
    await fs.promises.writeFile("./sizes.h", `#ifdef __cplusplus
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

    return { writeCodes };
}

export default getWriter;
