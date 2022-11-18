let getWriter = async()=>{

    const fs = await import('fs');

    //
    let F64Types = ["double", "float64_t"];
    let F32Types = ["float", "float32_t"];
    let U8Types = ["uint8_t", "char8_t", "char"];
    let U16Types = ["uint16_t"];
    let U64Types = ["uint64_t", "uintptr_t", "size_t", "VkDeviceSize", "VkDeviceAddress", "VkDeviceOffset", "VkDeviceOrHostAddressKHR", "VkFlags64", "VkImage", "VkBuffer", "VkAccelerationStructureKHR", "VkQueue", "VkDeviceMemory", "HANDLE"];
    let U32Types = ["uint32_t", "VkFlags", "VkResult", "VkBool32", "VkStructureType"];
    let Pointables = ["VkOffset2D","VkExtent2D","VkRect2D","VkTransformMatrixKHR","VkTransformMatrixNV"];
    let U24Types = ["uint24_t"];

    

    //
    let IsDouble = (T,B=0)=>{
        return F64Types.indexOf(T) >= 0 || T.indexOf("float64") >= 0 || T.indexOf("double") >= 0 || B == 64;
    }

    //
    let IsFloat = (T,B=0)=>{
        return F32Types.indexOf(T) >= 0 || T.indexOf("float32") >= 0 || T.indexOf("float") >= 0 || B == 32;
    }

    //
    let IsFloat32 = IsFloat;
    let IsFloat64 = IsDouble;

    //
    let IsUint64 = (T,B=0)=>{
        return U64Types.indexOf(T) >= 0 || T.indexOf("Flags64") >= 0 || T.indexOf("Flags2") >= 0 || T.indexOf("FlagBits2") >= 0 || T.indexOf("uint64") >= 0 || B == 64;
    }

    //
    let IsUint24 = (T,B=0)=>{
        return U24Types.indexOf(T) >= 0 || T.indexOf("uint24") >= 0 || B == 24;
    }

    //
    let IsUint32 = (T,B=0)=>{
        return U32Types.indexOf(T) >= 0 || T.indexOf("Flags") >= 0 || T.indexOf("FlagBits") >= 0 || T.indexOf("uint32") >= 0 || B == 32;
    }

    //
    let IsUint16 = (T,B=0)=>{
        return U16Types.indexOf(T) >= 0 || T.indexOf("uint16") >= 0 || B == 16;
    }

    //
    let IsUint8 = (T,B=0)=>{
        return U8Types.indexOf(T) >= 0 || T.indexOf("uint8") >= 0 || T.indexOf("char") >= 0|| B == 8;
    }

    //
    let IsInt64 = (T,B=0)=>{
        return T.indexOf("int64") >= 0 || B == 64;
    }

    //
    let IsInt24 = (T,B=0)=>{
        return T.indexOf("int24") >= 0 || B == 24;
    }

    //
    let IsInt32 = (T,B=0)=>{
        return T.indexOf("int32") >= 0 || B == 32;
    }

    //
    let IsInt16 = (T,B=0)=>{
        return T.indexOf("int16") >= 0 || B == 16;
    }

    //
    let IsInt8 = (T,B=0)=>{
        return T.indexOf("int8") >= 0 || B == 8;
    }


    //
    let IsPointableValue = (param)=>{
        let P = param.isPointer, T = param.type, F = param.isFixedArray, B = param.bitfield;
        if (P || IsUint8(T,B) || IsUint16(T,B) || IsUint32(T,B) || IsUint64(T,B) || IsFloat32(T,B) || IsFloat64(T,B) || IsInt8(T,B) || IsInt16(T,B) || IsInt32(T,B) || IsInt64(T,B)) { return false; } else
        if (Pointables.indexOf(T) >= 0) { return true; } else
        return false;
    }

    //
    let IsNumberValue = (param)=>{
        let P = param.isPointer, T = param.type, F = param.isFixedArray, B = param.bitfield;
        if (P) { return false; } else
        if (IsPointableValue(param)) { return false; } else
        if (IsUint8(T,B) || IsUint16(T,B) || IsUint32(T,B) || IsFloat32(T,B) || IsFloat64(T,B) || IsInt8(T,B) || IsInt16(T,B) || IsInt32(T,B)) { return true; } else
        return false;
    }

    //
    let IsBigIntValue = (param)=>{
        let P = param.isPointer, T = param.type, F = param.isFixedArray, B = param.bitfield;
        if (IsUint64(T,B) || IsInt64(T,B)) { return true; } else
        if (F) { return false; } else 
        if (P) { return true; } else
        return false;
    }

    let IsHandle = (param)=>{
        if (["VkImage", "VkBuffer", "VkAccelerationStructureKHR", "VkQueue", "VkDeviceMemory", "HANDLE"].indexOf(param.type) >= 0) return true; 
    }

    //
    //let Uint64Getter = (I=0)=> `info_[${I}].As<Napi::Number>().Int64Value();`
    //let Uint64Return = (N)=> `Napi::Number::New(env, (int64_t)${N});`;

    //
    let Uint64Getter = (I=0)=> `info_[${I}].As<Napi::BigInt>().Uint64Value(&lossless);`
    let Uint64Return = (N)=> `Napi::BigInt::New(env, (uint64_t)${N});`;

    

    

    //
    let passArg = (param, I) => {
        if (param.isPointerSet) {
            return param.isConst ?
            `
    if (!info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer of pointers) at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type}* const*)${Uint64Getter(I)};` : 
            `
    if (!info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer of pointers) at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type}**)${Uint64Getter(I)};`
        } else

        if (param.isPointer || param.isFixedArray) {
            return param.isConst ?
            `
    if (!info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type} const*)${Uint64Getter(I)};` :
            `
    if (!info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type}*)${Uint64Getter(I)};`
        } else

        if (param.type == "float") {
            return `
    if (!info_[${I}].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})info_[${I}].As<Napi::Number>().FloatValue();`;
        } else

        if (param.type == "double") {
            return `
    if (!info_[${I}].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})info_[${I}].As<Napi::Number>().DoubleValue();`;
        } else

        if (U32Types.indexOf(param.type) >= 0) {
            return `
    if (!info_[${I}].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})info_[${I}].As<Napi::Number>().Uint32Value();`;
        } else

        if (param.type == "int32_t") {
            return `
    if (!info_[${I}].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})info_[${I}].As<Napi::Number>().Int32Value();`;
        } else 

        //if (U64Types.indexOf(param.type) >= 0) 
        {   // any other is 64-bit number handlers
            return `
    if (!info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})${Uint64Getter(I)};`;
        }
    };

    //
    let passDispatch = (proto, params)=>{
        if (U64Types.indexOf(proto.type) >= 0 || proto.isPointer) {
            return `
    decltype(auto) result = ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
    return ${Uint64Return(`result`)}
`;
        } else 
        if (U32Types.indexOf(proto.type) >= 0) {
            return `
    decltype(auto) result = ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
    return Napi::Number::New(env, result);
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
    decltype(auto) result = ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
    return ${Uint64Return(`result`)}
`;
        }
    };

    //
    let makeCommand = (command,i,map)=>{
        let by = map.usedBy[command.proto.name];
return (by ? `#ifdef ${by.name}
` : ``) + 
`static Napi::Value ${command.proto.name.replace(/^vk/, "raw")}(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < ${command.params.length}) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    ${command.params.map(passArg).join(`
`)}
    ${passDispatch(command.proto, command.params)}}`+ (by ? `
#endif` : ``);
    }
    
    // 
    let cases = (map)=>{
        let cases = [];
        for (let k in map.sTypeMap) {
            let s = map.sTypeMap[k];
            let by = map.usedBy[s];
            if (by) { cases.push(`#ifdef ${by.name}`); };
            cases.push(`        case ${k}: return sizeof(${s}); break;`);
            if (by) { cases.push(`#endif`); }; 
        }
        return cases.join("\n");
    };

    /*
    function capitalizeFirstLetter(string) {
        return string.charAt(0).toUpperCase() + string.slice(1);
    }
    */

    //
    /*
    let TypeOfGet = (N)=>{
        if (N.type == "double") { return `info_[0].As<Napi::Number>().DoubleValue()` };
        if (N.type == "float") { return `info_[0].As<Napi::Number>().FloatValue()` };
        if (N.type == "uint16_t") { return `info_[0].As<Napi::Number>().Uint16Value()` };
        if (N.type == "uint8_t") { return `info_[0].As<Napi::Number>().Uint8Value()` };
        return `info_[0].As<Napi::Number>().Uint32Value()`
    };

    //
    let ReturnOf = (T,P,B,N)=>{
        let pointable = IsPointableValue(T,P);
        let number = IsNumberValue(T,P);
return number && !pointable || B ? 
`return Napi::Number::New(env, ${N});` : 
`return Napi::BigInt::New(env, (uint64_t)${IsPointableValue(T,P)?`&`:``}${N});`;
    };*/


    /*
    //
    let writeStructureSettersAndGetters = (struct, map)=>{
        let by = map.usedBy[struct.name];
        let structed = {name: struct.name, params: []};
        struct.params.forEach((param)=>{
            structed.params.push(`
${by ? `#ifdef ${byy.name}` : ``}
static Napi::Value ${struct.name}_get${capitalizeFirstLetter(param.name)}(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;

    ${struct.name}* ptr = nullptr;
    if (info_[0].IsBigInt()) {
        ptr = (${struct.name}*)${Uint64Getter(0)};
        ${ReturnOf(param.type, param.isPointer, param.isBitfield, `ptr->${param.name}`)}
    }

    ${ReturnOf(param.type, true, false, 0)};
}
static Napi::Value ${struct.name}_set${capitalizeFirstLetter(param.name)}(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;

    //using type = ${param.type} ${param.isPointerSet?`*`:``}${param.isConst?`const`:``}${param.isPointer?`*`:``};
    ${struct.name}* ptr = nullptr;
    ${param.text} = {};
    using type_ = decltype(${param.name});
    
    if (info_[0].IsBigInt()) {
        ptr = (${struct.name}*)${Uint64Getter(0)};
    }
    ${IsNumberValue(param.type,param.isPointer)?
    `if (info_[1].IsNumber()) {
        ${param.name} = (type_)(${TypeOfGet(param)});
    }`:``}
    if (info_[1].IsBigInt()) {
        ${(IsBigIntValue(param.type,param.isPointer,param.isFixedArray)||param.isPointer)?
        `${param.name} = (type_)(${`info_[1].As<Napi::BigInt>().Uint64Value(&lossless)`});`:
        `memcpy(&${param.name}, (type_*)(${`info_[1].As<Napi::BigInt>().Uint64Value(&lossless)`}), sizeof(type_));`}
    }
    ${param.isBitfield ? `ptr->${param.name} = ${param.name};` : `memcpy(&ptr->${param.name}, &${param.name}, sizeof(type_));`}
    return env.Null();
}
${by ? `#endif ${by}` : ``}
`);
        });
        return structed.params.join(`
`);
    };*/

    let AsFixedArray = (param) => {
        if (param.isFixedArray) {
            if (!isNaN(param.length)) { return `[${parseInt(param.length)}]`; } else { return `[enums.${param.length}]`; };
        }
        return ``;
    }

    let writeParam = (param, map)=>{
if (IsPointableValue(param))              { return `    ${param.name}: ${param.type}${AsFixedArray(param)},` } else 
if (IsHandle(param))                      { return `    ${param.name}: C.uint64_t${AsFixedArray(param)},` } else 
if (IsBigIntValue(param))                 { return `    ${param.name}: C.uint64_t${AsFixedArray(param)},` } else 
if (IsUint24(param.type, param.bitfield)) { return `    ${param.name}: uint24_t${AsFixedArray(param)},` } else 
if (IsUint8 (param.type, param.bitfield)) { return `    ${param.name}: C.uint8_t${AsFixedArray(param)},` } else 
if (IsUint16(param.type, param.bitfield)) { return `    ${param.name}: C.uint16_t${AsFixedArray(param)},` } else 
if (IsUint32(param.type, param.bitfield)) { return `    ${param.name}: C.uint32_t${AsFixedArray(param)},` } else 
if (IsInt24 (param.type, param.bitfield)) { return `    ${param.name}: int24_t${AsFixedArray(param)},` } else 
if (IsInt8  (param.type, param.bitfield)) { return `    ${param.name}: C.int8_t${AsFixedArray(param)},` } else 
if (IsInt16 (param.type, param.bitfield)) { return `    ${param.name}: C.int16_t${AsFixedArray(param)},` } else 
if (IsInt32 (param.type, param.bitfield)) { return `    ${param.name}: C.int32_t${AsFixedArray(param)},` } else 
if ( IsFloat(param.type, param.bitfield)) { return `    ${param.name}: C.float${AsFixedArray(param)},` } else 
if (IsDouble(param.type, param.bitfield)) { return `    ${param.name}: C.double${AsFixedArray(param)},` } else 
return `    ${param.name}: C.uint32_t,`
    };

    // make structures with specific fixes
    let writeStructure = (structure, map)=> {
        if (structure.name == "VkTransformMatrixKHR" || structure.name == "VkTransformMatrixNV") {
return `
const ${structure.name} = new T.StructBuffer("${structure.name}", {
    matrix: C.float[3][4],
});    
`       } else
        if (structure.name == "VkAccelerationStructureInstanceKHR" || structure.name == "VkAccelerationStructureInstanceNV") {
return `
const ${structure.name} = new T.StructBuffer("${structure.name}", {
    transform: VkTransformMatrixKHR,
    instanceCustomIndex: uint24_t,
    mask: C.uint8_t,
    instanceShaderBindingTableRecordOffset: uint24_t,
    flags: C.uint8_t,
    accelerationStructureReference: C.uint64_t,
});
`
        } else {
    return `
const ${structure.name} = new T.StructBuffer("${structure.name}", {
${structure.params.map(writeParam, map).join(`
`)}
});
`
        }
    };

    let availableEnums = [];
    let cvtEnum = (e, map)=>{
        let by = map.usedBy[e.name];
        
        if (e.name.indexOf(`EXTENSION_NAME`) >= 0) { availableEnums.push(e); return `const ${e.name} = "${eval(e.value)}";`};
        if ('value' in e) { availableEnums.push(e); return `const ${e.name} = ${eval(e.value)};`};
        if ('bitpos' in e) {
            let value = 1 << e.bitpos;
            availableEnums.push(e);
            return `const ${e.name} = ${value};`
        }
        if ('offset' in e) {
            const extBase = 1000000000n;
            const extBlockSize = 1000n;

            let offset = BigInt(e.offset);
            let extnumber = BigInt(e.extnumber || by.number || 0);
            let value = extBase + (extnumber - 1n) * extBlockSize + offset;
            if (e.dir) value *= -1n;
            availableEnums.push(e);
            return `const ${e.name} = ${parseInt(value)};`
        }

        return ``;
    }

    let mapEnums = (e)=>{
        return e.map(cvtEnum).filter((e)=>(!!e)).join(`
`);
    }

    // 
    let writeCodes = async (map)=>{

        availableEnums = [];
        await fs.promises.writeFile("./vulkan-enums.js", `
${map.parsedEnums.map((e)=>cvtEnum(e,map)).filter((e)=>(!!e)).join(`
`)}

export default { 
    ${availableEnums.map((p)=>p.name).filter((e)=>(!!e)).join(`,
    `)}
};
`);

        await fs.promises.writeFile("./vulkan-structs.js", `
import {default as enums} from "./vulkan-enums.js";
import * as T from "struct-buffer";
const C = T.default;
const uint24_t = C.uint8_t[3];//C.registerType("uint24_t", 3, false);
const  int24_t = C.uint8_t[3];//C.registerType(" int24_t", 3, false);

const VK_MAKE_API_VERSION = (variant, major, minor, patch) => {
    return ((((variant)) << 29) | (((major)) << 22) | (((minor)) << 12) | ((patch)));
};

//
${map.parsedStructs.map((s)=>writeStructure(s,map)).join(`
`)}

export default { 
    ${map.parsedStructs.map((p)=>p.name).join(`,
    `)}, 
    VK_MAKE_API_VERSION
};
`);

        await fs.promises.writeFile("./vulkan-API.cpp", `#pragma once 

#ifndef NAPI_VERSION
#define NAPI_VERSION 8
#endif

#ifndef NAPI_EXPERIMENTAL
#define NAPI_EXPERIMENTAL
#endif

//
#ifndef VK_NO_PROTOTYPES
#define VK_NO_PROTOTYPES
#endif

//
#include <volk/volk.h>
#include <napi.h>
#include "./sizes.h"

//
static Napi::Value Dealloc(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = ${Uint64Getter(0)};
    }
    delete (void*)address;
    return ${Uint64Return(`0ull`)}
}

static Napi::Value GetAddress(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();

    uint64_t address = 0ull;
    if (info_[0].IsString()) {
        decltype(auto) STR = info_[0].As<Napi::String>().Utf8Value();
        decltype(auto) ptr = Napi::Uint8Array::New(env, STR.length()); // you can't use directly c_str, it should to be context visible
        memcpy(ptr.Data(), STR.c_str(), STR.size());
        address = uint64_t(ptr.Data());
    }
    if (info_[0].IsTypedArray()) {
        decltype(auto) TA = info_[0].As<Napi::TypedArray>();
        decltype(auto) AB = TA.ArrayBuffer();
        address = uint64_t(AB.Data()) + TA.ByteOffset();
    }
    if (info_[0].IsDataView()) {
        decltype(auto) TA = info_[0].As<Napi::DataView>();
        decltype(auto) AB = TA.ArrayBuffer();
        address = uint64_t(AB.Data()) + TA.ByteOffset();
    }
    if (info_[0].IsArrayBuffer()) {
        decltype(auto) AB = info_[0].As<Napi::ArrayBuffer>();
        address = uint64_t(AB.Data());
    }
    if (info_[0].IsExternal()) {
        decltype(auto) AB = info_[0].As<Napi::External<void>>();
        address = uint64_t(AB.Data());
    }

    return ${Uint64Return(`address`)}
}

static Napi::ArrayBuffer WrapArrayBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    bool lossless = true;
    if (info_[0].IsBigInt()) {
        address = ${Uint64Getter(0)};
    }
    size_t byteLength = 0ull;
    if (info_[1].IsBigInt()) { byteLength = info_[1].As<Napi::Number>().Int64Value(); }
    if (info_[1].IsNumber()) { byteLength = info_[1].As<Napi::Number>().Uint32Value(); }
    return Napi::ArrayBuffer::New(env, (void*)address, byteLength);
}

static Napi::Number DebugUint8(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = ${Uint64Getter(0)};
    }
    return Napi::Number::New(env, *((uint8_t*)address));
}

static Napi::Number DebugUint16(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = ${Uint64Getter(0)};
    }
    return Napi::Number::New(env, *((uint16_t*)address));
}

static Napi::Number DebugUint32(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = ${Uint64Getter(0)};
    }
    return Napi::Number::New(env, *((uint32_t*)address));
}

static Napi::Value DebugUint64(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = ${Uint64Getter(0)};
    }
    return ${Uint64Return(`address`)}
}

static Napi::Number DebugFloat32(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = ${Uint64Getter(0)};
    }
    return Napi::Number::New(env, *((float*)address));
}

static Napi::Number DebugFloat64(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = ${Uint64Getter(0)};
    }
    return Napi::Number::New(env, *((double*)address));
}

static Napi::Value rawGetStructureSizeBySType(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsNumber()) {
        return Napi::Number::New(env, vkGetStructureSizeBySType((VkStructureType)info_[0].As<Napi::Number>().Uint32Value()));
    }
    return Napi::Number::New(env, 0);
}
    
${map.parsed.map((cmd,i)=>makeCommand(cmd,i,map)).join(`
`)}

static Napi::Object Init(Napi::Env env, Napi::Object exports) {
    volkInitialize();

${map.parsed.map((cmd,i)=>{
    let by = map.usedBy[cmd.proto.name];
    return (by ? `#ifdef ${by.name}
` : ``) + `    exports["${cmd.proto.name}"] = Napi::Function::New(env, ${cmd.proto.name.replace(/^vk/, "raw")});` + (by ? `
#endif` : ``);
}).join(`
`)}

    exports["vkGetStructureSizeBySType"] = Napi::Function::New(env, rawGetStructureSizeBySType);
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
    `);

    await fs.promises.writeFile("./vulkan-API.js", `
import { createRequire } from 'module';
const require = createRequire(import.meta.url);
const native = require('bindings')('native');
const sharedStructs = require('shared-structs');
const fs = require('fs');
const path = require('path');



// get native address for Vulkan API 'const char*'
String.prototype.charAddress = function (isUtf16 = false) {
    return native.nativeAddress(this.toString(), isUtf16);
};

// 
DataView.prototype.address = 
Uint8Array.prototype.address = 
Uint16Array.prototype.address = 
Uint32Array.prototype.address = 
BigInt64Array.prototype.address = 
Int8Array.prototype.address = 
Int16Array.prototype.address = 
Int32Array.prototype.address = 
BigUint64Array.prototype.address = 
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
