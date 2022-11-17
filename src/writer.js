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
static Napi::Value ${command.proto.name.replace(/^vk/, "raw")}(const Napi::CallbackInfo& info) {
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

#define NAPI_VERSION 6
#define NAPI_EXPERIMENTAL

//
#define VK_NO_PROTOTYPES

// 
#ifndef VULKAN_SIZES_H
#define VULKAN_SIZES_H

/*
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
*/

//
#include <volk/volk.h>
#include <napi.h>


static Napi::BigInt Dealloc(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    delete (void*)address;
    return Napi::BigInt::New(env, 0ull);
}

static Napi::BigInt GetAddress(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    uint64_t address = 0ull;
    if (info[0].IsString()) {
        auto STR = info[0].As<Napi::String>().Utf8Value();
        auto ptr = Napi::Uint8Array::New(env, STR.length()); // you can't use directly c_str, it should to be context visible
        memcpy(ptr.Data(), STR.c_str(), STR.size());
        address = uint64_t(ptr.Data());
    }
    if (info[0].IsTypedArray()) {
        auto TA = info[0].As<Napi::TypedArray>();
        auto AB = TA.ArrayBuffer();
        address = uint64_t(AB.Data()) + TA.ByteOffset();
    }
    if (info[0].IsDataView()) {
        auto TA = info[0].As<Napi::DataView>();
        auto AB = TA.ArrayBuffer();
        address = uint64_t(AB.Data()) + TA.ByteOffset();
    }
    if (info[0].IsArrayBuffer()) {
        auto AB = info[0].As<Napi::ArrayBuffer>();
        address = uint64_t(AB.Data());
    }
    if (info[0].IsExternal()) {
        auto AB = info[0].As<Napi::External<void>>();
        address = uint64_t(AB.Data());
    }

    return Napi::BigInt::New(env, address);
}


static Napi::ArrayBuffer WrapArrayBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    bool lossless = true;
    if (info[0].IsBigInt()) {
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    size_t byteLength = 0ull;
    if (info[1].IsBigInt()) { byteLength = info[1].As<Napi::BigInt>().Uint64Value(&lossless); }
    if (info[1].IsNumber()) { byteLength = info[1].As<Napi::Number>().Uint32Value(); }
    return Napi::ArrayBuffer::New(env, (void*)address, byteLength);
}


static Napi::Number DebugUint8(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    return Napi::Number::New(env, *((uint8_t*)address));
}

Napi::Number DebugUint16(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    return Napi::Number::New(env, *((uint16_t*)address));
}

static Napi::Number DebugUint32(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    return Napi::Number::New(env, *((uint32_t*)address));
}

static Napi::BigInt DebugUint64(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    return Napi::BigInt::New(env, *((uint64_t*)address));
}


static Napi::Number DebugFloat32(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    return Napi::Number::New(env, *((float*)address));
}

static Napi::Number DebugFloat64(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    return Napi::Number::New(env, *((double*)address));
}
    
${map.parsed.map((cmd,i)=>makeCommand(cmd,i,map)).join(`
`)}

Napi::Object Init(Napi::Env env, Napi::Object exports) {

${map.parsed.map((cmd,i)=>{
    let by = map.usedBy[cmd.proto.name];
    return `${by ? `#ifdef ${by}` : ``}
    //exports["${cmd.proto.name}"] = Napi::Function::New(env, ${cmd.proto.name.replace(/^vk/, "raw")});
${by ? `#endif` : ``}`;
}).join(`
`)}

    exports["uint8" ] = Napi::Function::New(env, DebugUint8);
    exports["uint16"] = Napi::Function::New(env, DebugUint16);
    exports["uint32"] = Napi::Function::New(env, DebugUint32);
    exports["uint64"] = Napi::Function::New(env, DebugUint64);
    exports["float32"] = Napi::Function::New(env, DebugFloat32);
    exports["float64"] = Napi::Function::New(env, DebugFloat64);
    exports["nativeAddress"] = Napi::Function::New(env, GetAddress);
    exports["arrayBuffer"] = Napi::Function::New(env, WrapArrayBuffer);
    return exports;
}

NODE_API_MODULE(native, Init)

#endif
    `);

    await fs.promises.writeFile("./vulkan-API.js", `
import { createRequire } from 'module';
const require = createRequire(import.meta.url);
const native = require('../build/Debug/node-vulkan-api')('native');

console.log(native);

// get native address for Vulkan API 'const char*'
String.prototype.charAddress = function (isUtf16 = false) {
    return native.nativeAddress(this.toString(), isUtf16);
};

// 
DataView.prototype.address = 
Uint8Array.prototype.address = 
Uint16Array.prototype.address = 
Uint32Array.prototype.address = 
BigUint64Array.prototype.address = 
Int8Array.prototype.address = 
Int16Array.prototype.address = 
Int32Array.prototype.address = 
BigInt64Array.prototype.address = 
Float32Array.prototype.address = 
Float64Array.prototype.address = 
ArrayBuffer.prototype.address = 
SharedArrayBuffer.prototype.address = 
function () { return native.nativeAddress(this); }

if (typeof exports != "undefined") { exports.nativeAddress = native.nativeAddress; }

export default native;
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
