let getWriter = async()=>{

    const fs = await import('fs');

    //
    let Handles = ["VkImage", "VkBuffer", "VkAccelerationStructureKHR", "VkQueue", "VkDeviceMemory", "HANDLE", "VkPhysicalDevice", "VkCommandBuffer", "VkSurfaceKHR", "VkFramebuffer", "VkSwapchainKHR", "VkSurfaceKHR", "VkPipeline", "VkPipelineLayout", "VkSemaphore", "VkSampler", "VkFence"];
    let F64Types = ["double", "float64_t"];
    let F32Types = ["float", "float32_t"];
    let U8Types = ["uint8_t", "char8_t", "char"];
    let U16Types = ["uint16_t"];
    let U64Types = ["uint64_t", "uintptr_t", "size_t", "VkDeviceSize", "VkDeviceAddress", "VkDeviceOffset", "VkDeviceOrHostAddressKHR", "VkFlags64"].concat(Handles);
    let U32Types = ["uint32_t", "VkFlags", "VkBool32", "VkStructureType"];
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
        return T == "VkResult" || T.indexOf("int32") >= 0 || B == 32;
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
        if (Handles.indexOf(param.type) >= 0) return true; 
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
    decltype(auto) ${param.name} = (${param.type}* const*)GetAddress(env, info_[${I}]);` : 
            `
    decltype(auto) ${param.name} = (${param.type}**)GetAddress(env, info_[${I}]);`
        } else

        if (param.isPointer || param.isFixedArray) {
            return param.isConst ?
            `
    decltype(auto) ${param.name} = (${param.type} const*)GetAddress(env, info_[${I}]);` :
            `
    decltype(auto) ${param.name} = (${param.type}*)GetAddress(env, info_[${I}]);`
        } else

        if (IsFloat32(param.type)) {
            return `
    if (!info_[${I}].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})info_[${I}].As<Napi::Number>().FloatValue();`;
        } else

        if (IsFloat64(param.type)) {
            return `
    if (!info_[${I}].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})info_[${I}].As<Napi::Number>().DoubleValue();`;
        } else

        if (IsUint32(param.type)) {
            return `
    if (!info_[${I}].IsNumber() && !info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs Number or BigInt at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})(info_[${I}].IsBigInt() ? info_[${I}].As<Napi::BigInt>().Uint64Value(&lossless) : info_[${I}].As<Napi::Number>().Uint32Value());`;
        } else

        if (IsInt32(param.type)) {
            return `
    if (!info_[${I}].IsNumber() && !info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs Number or BigInt at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})(info_[${I}].IsBigInt() ? info_[${I}].As<Napi::BigInt>().Int64Value(&lossless) : info_[${I}].As<Napi::Number>().Int32Value());`;
        } else 

        if (IsUint16(param.type)) {
            return `
    if (!info_[${I}].IsNumber() && !info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs Number or BigInt at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})(info_[${I}].IsBigInt() ? info_[${I}].As<Napi::BigInt>().Uint64Value(&lossless) : info_[${I}].As<Napi::Number>().Uint32Value());`;
        } else

        if (IsInt16(param.type)) {
            return `
    if (!info_[${I}].IsNumber() && !info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs Number or BigInt at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})(info_[${I}].IsBigInt() ? info_[${I}].As<Napi::BigInt>().Int64Value(&lossless) : info_[${I}].As<Napi::Number>().Int32Value());`;
        } else 

        if (IsUint8(param.type)) {
            return `
    if (!info_[${I}].IsNumber() && !info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs Number or BigInt at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})(info_[${I}].IsBigInt() ? info_[${I}].As<Napi::BigInt>().Uint64Value(&lossless) : info_[${I}].As<Napi::Number>().Uint32Value());`;
        } else

        if (IsInt8(param.type)) {
            return `
    if (!info_[${I}].IsNumber() && !info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs Number or BigInt at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})(info_[${I}].IsBigInt() ? info_[${I}].As<Napi::BigInt>().Int64Value(&lossless) : info_[${I}].As<Napi::Number>().Int32Value());`;
        } else 

        //if (U64Types.indexOf(param.type) >= 0) 
        {   // any other is 64-bit number handlers
            return `
    if (!info_[${I}].IsBigInt() && !info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs Number or BigInt (handle) at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})(info_[${I}].IsBigInt() ? info_[${I}].As<Napi::BigInt>().Uint64Value(&lossless) : info_[${I}].As<Napi::Number>().Int64Value());`;
        }
    };

    //
    let passDispatch = (proto, params)=>{
        if (IsUint64(proto.type) || IsInt64(proto.type) || proto.isPointer) {
            return `
    decltype(auto) result = ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
    return ${Uint64Return(`result`)}
`;
        } else 
        if (IsUint32(proto.type) || IsUint16(proto.type) || IsUint8(proto.type) || IsInt32(proto.type) || IsInt16(proto.type) || IsInt8(proto.type) || IsFloat32(proto.type) || IsFloat64(proto.type)) {
            return `
    try {
        decltype(auto) result = ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
        if (typeid(decltype(result)) == typeid(VkResult) && result < 0) {
            std::string errorMsg = "Vulkan API Exception: " + std::to_string(result) + " in ${proto.name}";
            Napi::Error::New(env, errorMsg).ThrowAsJavaScriptException();
            std::cerr << errorMsg << std::endl;
        }
        ${proto.name == "vkCreateInstance" ? "volkLoadInstance(*pInstance);" : ""}
        ${proto.name == "vkCreateDevice" ? "volkLoadDevice(*pDevice);" : ""}
        return Napi::Number::New(env, result);
    } catch(std::exception e) {
        std::cerr << "Exception with ${proto.name} command." << std::endl;
        std::cerr << "Argument list: " << std::endl;
        ${params.map((p)=>`        std::cerr << "    ${p.name}: " << (uint64_t)(${p.name}) << std::endl;`).join(`
`)}
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        throw e;
    }
    return env.Null();
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
    };

    //
    let writeStructureOffsetsGot = (struct, map)=>{
        let by = map.usedBy[struct.name];
        let structed = {name: struct.name, params: []};
        let params = struct.params.map((param)=>{
            if (!param.isBitfield) {
            return ((by ? `#ifdef ${by.name}
` : ``) + `    exports["${struct.name}_${param.name}_offsetof"] = Napi::Number::New(env, offsetof(${struct.name}, ${param.name}));` + (by ? `
#endif` : ``)) }
})
        params.push((by ? `#ifdef ${by.name}
` : ``) + `    exports["${struct.name}_sizeof"] = Napi::Number::New(env, sizeof(${struct.name}));` + (by ? `
#endif` : ``));
return params.join(`
`)};

    let AsFixedArray = (name, param, typed) => {
        if (param.isFixedArray) {
            if (!isNaN(param.length)) 
                { return `"${typed}[${parseInt(param.length)||1}]("+(V.${name}_${param.name}_offsetof||0)+")"` + (param.values ? `+";"+(E.${param.values}||0)` : ``); } else 
                { return `"${typed}["+(E.${param.length}||1)+"]("+(V.${name}_${param.name}_offsetof||0)+")"` + (param.values ? `+";"+(E.${param.values}||0)` : ``); };
        }
        return `"${typed}("+(V.${name}_${param.name}_offsetof||0)+")"` + (param.values ? `+";"+(E.${param.values}||0)` : ``);
    }

    let writeParam = (name, param, map)=>{
        let paramStr = `    ${param.name}: ${AsFixedArray(name, param, "u32")},`
if (IsPointableValue(param))              { paramStr = `    ${param.name}: ${AsFixedArray(name, param, param.type)},` } else 
if (IsHandle(param))                      { paramStr = `    ${param.name}: ${AsFixedArray(name, param, "u64")},` } else 
if (IsBigIntValue(param))                 { paramStr = `    ${param.name}: ${AsFixedArray(name, param, "u64")},` } else 
if (IsUint8 (param.type, param.bitfield)) { paramStr = `    ${param.name}: ${AsFixedArray(name, param, "u8" )},` } else 
if (IsUint16(param.type, param.bitfield)) { paramStr = `    ${param.name}: ${AsFixedArray(name, param, "u16")},` } else 
if (IsUint24(param.type, param.bitfield)) { paramStr = `    ${param.name}: ${AsFixedArray(name, param, "u24")},` } else 
if (IsUint32(param.type, param.bitfield)) { paramStr = `    ${param.name}: ${AsFixedArray(name, param, "u32")},` } else 
if (IsInt8  (param.type, param.bitfield)) { paramStr = `    ${param.name}: ${AsFixedArray(name, param, "i8" )},` } else 
if (IsInt16 (param.type, param.bitfield)) { paramStr = `    ${param.name}: ${AsFixedArray(name, param, "i16")},` } else 
if (IsInt32 (param.type, param.bitfield)) { paramStr = `    ${param.name}: ${AsFixedArray(name, param, "i32")},` } else 
if ( IsFloat(param.type, param.bitfield)) { paramStr = `    ${param.name}: ${AsFixedArray(name, param, "f32")},` } else 
if (IsDouble(param.type, param.bitfield)) { paramStr = `    ${param.name}: ${AsFixedArray(name, param, "f64")},` } 
return paramStr;
    };

    // make structures with specific fixes
    let writeStructure = (structure, map)=> {
        if (structure.name == "VkTransformMatrixKHR" || structure.name == "VkTransformMatrixNV") {
return `
const ${structure.name} = new Proxy(C.CStructView, new C.CStruct("${structure.name}", {
    matrix: "f32(0)[12];[1,0,0,0, 0,1,0,0, 0,0,1,0]",
}, (V.${structure.name}_sizeof||0)));    
`       } else
        /*if (structure.name == "VkAccelerationStructureInstanceKHR" || structure.name == "VkAccelerationStructureInstanceNV") {
return `
const ${structure.name} = new C.CStruct("${structure.name}", {
    transform: "VkTransformMatrixKHR(0)",
    instanceCustomIndex: "u24("+(0+48)+")",
    mask: "u8("+(3+48)+")",
    instanceShaderBindingTableRecordOffset: "u24("+(4+48)+")",
    flags: "u8("+(7+48)+")",
    accelerationStructureReference: "u64("+(8+48)+")",
}, (V.${structure.name}_sizeof||0));`
        } else*/ 
        if (structure.alias) {
return `const ${structure.name} = new Proxy(C.CStructView, new C.ConstructProxy("${structure.alias}"));
`;
        } else
        {
    return `
const ${structure.name} = new Proxy(C.CStructView, new C.CStruct("${structure.name}", {
${structure.params.map((p)=>(writeParam(structure.name, p, map))).join(`
`)}
}, (V.${structure.name}_sizeof||0)));
`
        }
    };

    let availableEnums = [];
    let cvtEnum = (e, map)=>{
        let by = map.usedBy[e.name];
        
        if (e.name.indexOf(`EXTENSION_NAME`) >= 0 && e.name.indexOf(`VK_MAX_EXTENSION_NAME_SIZE`) < 0) { availableEnums.push(e); return `    get ${e.name}() { return "${eval(e.value)}" },`} else
        if ('value' in e) { availableEnums.push(e); return `    get ${e.name}() { return ${BigInt(eval(e.value))}n },`} else
        if ('bitpos' in e) {
            let value = 1n << BigInt(e.bitpos);
            availableEnums.push(e);
            return `    get ${e.name}() { return ${BigInt(value)}n },`
        } else
        if ('offset' in e) {
            const extBase = 1000000000n;
            const extBlockSize = 1000n;

            let offset = BigInt(e.offset);
            let extnumber = BigInt(e.extnumber || by.number || 0);
            let value = extBase + (extnumber - 1n) * extBlockSize + offset;
            if (e.dir) value *= -1n;
            availableEnums.push(e);
            return `    get ${e.name}() { return ${BigInt(value)}n },`
        } else
        if ('alias' in e) {
            return `    get ${e.name}() { return (E["${e.alias}"]||0n) },`
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

const E = {
${map.parsedEnums.map((e)=>cvtEnum(e,map)).filter((e)=>(!!e)).join(`
`)}
};

export default E;
`);

  // TODO: use C++ offsets and own classes
        await fs.promises.writeFile("./vulkan-structs.js", `
import {default as V} from "./native.js";
import {default as E} from "./vulkan-enums.js";
import {default as C} from "./typed.js";
const callof = (fn)=>{ return fn ? fn() : 0; };

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

        await fs.promises.writeFile("./native.cpp", `#pragma once 
//
#ifndef NAPI_VERSION
#define NAPI_VERSION 8
#endif

//
#ifndef NAPI_EXPERIMENTAL
#define NAPI_EXPERIMENTAL
#endif

//
#ifndef VK_NO_PROTOTYPES
#define VK_NO_PROTOTYPES
#endif

//
#define WINDOWS_IGNORE_PACKING_MISMATCH

//
#ifdef _WIN32
#include <windows.h>
#include <eh.h>
#endif

//
#include <volk/volk.h>

//
#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <napi.h>

//
#include "./sizes.h"
#include "./native.hpp"

//
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

static std::vector<std::function<void(unsigned int u, EXCEPTION_POINTERS* pExp)>> EXC_HANDLERS = {};

static Napi::Object Init(Napi::Env env, Napi::Object exports) {
#ifdef _WIN32
    EXC_HANDLERS.push_back([env](unsigned int u, EXCEPTION_POINTERS* pExp) {
        std::string error = "SE Exception: ";
        char result[11]; sprintf_s(result, 11, "0x%08X", u);
        error += "Unexpected Error (" + std::string(result) + ")";
        Napi::Error::New(env, error).ThrowAsJavaScriptException();
        std::cerr << error << std::endl;
        throw std::exception(error.c_str());
    });

    _set_se_translator([](unsigned int u, EXCEPTION_POINTERS* pExp) {
        for (auto fx : EXC_HANDLERS) { fx(u, pExp); }
    });
#endif

    volkInitialize();

${map.parsedStructs.map((cmd,i)=>writeStructureOffsetsGot(cmd,map)).join(`
`)}

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
    exports["nativeAddress"] = Napi::Function::New(env, GetAddressJS);
    exports["arrayBuffer"] = Napi::Function::New(env, WrapArrayBuffer);
    exports["buffer"] = Napi::Function::New(env, WrapBuffer);
    exports["string"] = Napi::Function::New(env, WrapString);
    exports["stringUtf16"] = Napi::Function::New(env, WrapStringUTF16);
    return exports;
}

NODE_API_MODULE(native, Init)
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
