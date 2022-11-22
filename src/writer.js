let getWriter = async()=>{

    const fs = await import('fs');

    //
    let Handles = ["VkCommandPool", "VkDescriptorSetLayout", "VkDescriptorSet", "VkShaderModule", "VkPipelineCache", "VkRenderPass", "VkImageView", "VkImage", "VkBuffer", "VkAccelerationStructureKHR", "VkQueue", "VkDeviceMemory", "HANDLE", "VkPhysicalDevice", "VkCommandBuffer", "VkSurfaceKHR", "VkFramebuffer", "VkSwapchainKHR", "VkSurfaceKHR", "VkPipeline", "VkPipelineLayout", "VkSemaphore", "VkSampler", "VkFence"];
    let F64Types = ["double", "float64_t"];
    let F32Types = ["float", "float32_t"];
    let U8Types = ["uint8_t", "char8_t", "char"];
    let U16Types = ["uint16_t"];
    let U64Types = ["LPCWSTR", "uint64_t", "uintptr_t", "size_t", "VkDeviceSize", "VkDeviceAddress", "VkDeviceOffset", "VkDeviceOrHostAddressKHR", "VkFlags64"].concat(Handles);
    let U32Types = ["DWORD", "uint32_t", "VkFlags", "VkBool32", "VkStructureType"];
    let Pointables = ["VkOffset2D","VkExtent2D","VkRect2D","VkTransformMatrixKHR","VkTransformMatrixNV","VkPhysicalDeviceFeatures","VkPhysicalDeviceProperties","VkMemoryRequirements"];
    let U24Types = ["uint24_t"];

    // // // // // // // // // // // // // // // // // // // 
    // TODO: Underlying Enums Types Support (such as Uint32)
    // // // // // // // // // // // // // // // // // // // 

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
    let IsPointableValue = (param, map)=>{
        let P = param.isPointer, T = param.type, F = param.isFixedArray, B = param.bitfield;
        if (map.parsedEnums.find((e)=>(e.extends == param.type || e.type == param.type))) { return false; };
        if (P || IsUint8(T,B) || IsUint16(T,B) || IsUint32(T,B) || IsUint64(T,B) || IsFloat32(T,B) || IsFloat64(T,B) || IsInt8(T,B) || IsInt16(T,B) || IsInt32(T,B) || IsInt64(T,B)) { return false; } else
        if (Pointables.indexOf(T) >= 0) { return true; } else
        return true;
    }

    //
    let IsNumberValue = (param, map)=>{
        let P = param.isPointer, T = param.type, F = param.isFixedArray, B = param.bitfield;
        if (P) { return false; } else
        if (IsPointableValue(param, map)) { return false; } else
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
    if (!info_[${I}].IsNumber() && !info_[${I}].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs Number or BigInt (handle) at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ${param.name} = (${param.type})(info_[${I}].IsBigInt() ? info_[${I}].As<Napi::BigInt>().Uint64Value(&lossless) : info_[${I}].As<Napi::Number>().Int64Value());`;
        }
    };

    //
    let passDispatch = (proto, params)=>{
        if (IsUint64(proto.type) || IsInt64(proto.type) || proto.isPointer) {
            return `uint64_t returnable = 0ull; try {
        decltype(auto) result = ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
        returnable = (uint64_t)(result);
        return Napi::BigInt::New(env, result);
    } catch(std::exception e) {
        std::cerr << "Exception with ${proto.name} command." << std::endl;
        std::cerr << "Caller pointer: " << ((uint64_t)(::${proto.name})) << std::endl;
        std::cerr << "Argument list: " << std::endl;
        ${params.map((p)=>`        std::cerr << "    ${p.name}: " << (uint64_t)(${p.name}) << std::endl;`).join(`
`)}
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        throw e;
    }
    return Napi::BigInt::New(env, returnable);
`;
        } else 
        if (IsUint32(proto.type) || IsUint16(proto.type) || IsUint8(proto.type) || IsInt32(proto.type) || IsInt16(proto.type) || IsInt8(proto.type) || IsFloat32(proto.type) || IsFloat64(proto.type)) {
            return `int32_t returnable = 0; try {
        decltype(auto) result = ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
        returnable = (int32_t)(result);
        if (typeid(decltype(result)) == typeid(VkResult) && result < 0) {
            std::string errorMsg = "Vulkan API Exception: " + std::to_string(result);
            std::cerr << errorMsg << std::endl;
            //Napi::Error::New(env, errorMsg).ThrowAsJavaScriptException();
            throw std::exception(errorMsg.c_str());
        }
        ${proto.name == "vkCreateInstance" ? "volkLoadInstance(*pInstance);" : ""}
        ${proto.name == "vkCreateDevice" ? "volkLoadDevice(*pDevice);" : ""}
        return Napi::Number::New(env, result);
    } catch(std::exception e) {
        std::cerr << "Exception with ${proto.name} command." << std::endl;
        std::cerr << "Caller pointer: " << ((uint64_t)(::${proto.name})) << std::endl;
        std::cerr << "Argument list: " << std::endl;
        ${params.map((p)=>`        std::cerr << "    ${p.name}: " << (uint64_t)(${p.name}) << std::endl;`).join(`
`)}
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        throw e;
    }
    return Napi::Number::New(env, returnable);
`;
        } else 
        if (proto.type.indexOf("void") >= 0 || proto.type.indexOf("PFN_vkVoidFunction") >= 0) {
        return `try {
        ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
    } catch(std::exception e) {
        std::cerr << "Exception with ${proto.name} command." << std::endl;
        std::cerr << "Caller pointer: " << ((uint64_t)(::${proto.name})) << std::endl;
        std::cerr << "Argument list: " << std::endl;
        ${params.map((p)=>`        std::cerr << "    ${p.name}: " << (uint64_t)(${p.name}) << std::endl;`).join(`
`)}
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        throw e;
    }
    return env.Null();
`;
        } else
        {
        return `uint64_t returnable = 0ull; try {
        decltype(auto) result = ::${proto.name}(${params.map((p)=>{return p.name}).join(", ")});
        returnable = (int32_t)(result);
        return Napi::BigInt::New(env, result);
    } catch(std::exception e) {
        std::cerr << "Exception with ${proto.name} command." << std::endl;
        std::cerr << "Caller pointer: " << ((uint64_t)(::${proto.name})) << std::endl;
        std::cerr << "Argument list: " << std::endl;
        ${params.map((p)=>`        std::cerr << "    ${p.name}: " << (uint64_t)(${p.name}) << std::endl;`).join(`
`)}
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        throw e;
    }
    return Napi::BigInt::New(env, returnable);
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
if (IsPointableValue(param, map))              { paramStr = `    ${param.name}: ${AsFixedArray(name, param, param.type)},` } else 
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
        let is64bit = IsUint64(e.extends || e.type || "")?`n`:``;
        if (e.name.indexOf(`EXTENSION_NAME`) >= 0 && e.name.indexOf(`VK_MAX_EXTENSION_NAME_SIZE`) < 0) { availableEnums.push(e); return `    get ${e.name}() { return "${eval(e.value)}" },`} else
        if ('value' in e) { availableEnums.push(e); return `    get ${e.name}() { return ${BigInt(eval(e.value))}${is64bit} },`} else
        if ('bitpos' in e) {
            let value = 1n << BigInt(e.bitpos);
            availableEnums.push(e);
            return `    get ${e.name}() { return ${BigInt(value)}${is64bit} },`
        } else
        if ('offset' in e) {
            const extBase = 1000000000n;
            const extBlockSize = 1000n;

            let offset = BigInt(e.offset);
            let extnumber = BigInt(e.extnumber || by.number || 0);
            let value = extBase + (extnumber - 1n) * extBlockSize + offset;
            if (e.dir) value *= -1n;
            availableEnums.push(e);
            return `    get ${e.name}() { return ${BigInt(value)}${is64bit} },`
        } else
        if ('alias' in e) {
            return `    get ${e.name}() { return (E["${e.alias}"]||0${is64bit}) },`
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
#ifdef ENABLE_GLFW_SUPPORT
#include "./glfw.hpp"
#endif

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

    //
#ifdef ENABLE_GLFW_SUPPORT
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
#endif

    volkInitialize();

#ifdef ENABLE_GLFW_SUPPORT
    glfwInitVulkanLoader(vkGetInstanceProcAddr);
#endif

${map.parsedStructs.map((cmd,i)=>writeStructureOffsetsGot(cmd,map)).join(`
`)}

${map.parsed.map((cmd,i)=>{
    let by = map.usedBy[cmd.proto.name];
    return (by ? `#ifdef ${by.name}
` : ``) + `    exports["${cmd.proto.name}"] = Napi::Function::New(env, ${cmd.proto.name.replace(/^vk/, "raw")});` + (by ? `
#endif` : ``);
}).join(`
`)}

    // TODO: Unified Syntax

#ifdef ENABLE_GLFW_SUPPORT
    // Context functions
    exports.Set("glfwMakeContextCurrent", Napi::Function::New(env, __glfwMakeContextCurrent));
    exports.Set("glfwGetCurrentContext", Napi::Function::New(env, __glfwGetCurrentContext));
    exports.Set("glfwSwapInterval", Napi::Function::New(env, __glfwSwapInterval));
    exports.Set("glfwExtensionSupported", Napi::Function::New(env, __glfwExtensionSupported));

    // Initialization, version and error functions
    exports.Set("glfwInit", Napi::Function::New(env, __glfwInit));
    exports.Set("glfwTerminate", Napi::Function::New(env, __glfwTerminate));
    exports.Set("glfwInitHint", Napi::Function::New(env, __glfwInitHint));
    exports.Set("glfwGetVersion", Napi::Function::New(env, __glfwGetVersion));
    exports.Set("glfwGetVersionString", Napi::Function::New(env, __glfwGetVersionString));
    exports.Set("glfwGetError", Napi::Function::New(env, __glfwGetError));
    exports.Set("glfwSetErrorCallback", Napi::Function::New(env, __glfwSetErrorCallback));

    // Input functions
    exports.Set("glfwGetInputMode", Napi::Function::New(env, __glfwGetInputMode));
    exports.Set("glfwSetInputMode", Napi::Function::New(env, __glfwSetInputMode));
    exports.Set("glfwRawMouseMotionSupported", Napi::Function::New(env, __glfwRawMouseMotionSupported));
    exports.Set("glfwGetKeyName", Napi::Function::New(env, __glfwGetKeyName));
    exports.Set("glfwGetKeyScancode", Napi::Function::New(env, __glfwGetKeyScancode));
    exports.Set("glfwGetKey", Napi::Function::New(env, __glfwGetKey));
    exports.Set("glfwGetMouseButton", Napi::Function::New(env, __glfwGetMouseButton));
    exports.Set("glfwGetCursorPos", Napi::Function::New(env, __glfwGetCursorPos));
    exports.Set("glfwSetCursorPos", Napi::Function::New(env, __glfwSetCursorPos));
    exports.Set("glfwCreateCursor", Napi::Function::New(env, __glfwCreateCursor));
    exports.Set("glfwCreateStandardCursor", Napi::Function::New(env, __glfwCreateStandardCursor));
    exports.Set("glfwDestroyCursor", Napi::Function::New(env, __glfwDestroyCursor));
    exports.Set("glfwSetCursor", Napi::Function::New(env, __glfwSetCursor));
    exports.Set("glfwSetKeyCallback", Napi::Function::New(env, __glfwSetKeyCallback));
    exports.Set("glfwSetCharCallback", Napi::Function::New(env, __glfwSetCharCallback));
    exports.Set("glfwSetCharModsCallback", Napi::Function::New(env, __glfwSetCharModsCallback));
    exports.Set("glfwSetMouseButtonCallback", Napi::Function::New(env, __glfwSetMouseButtonCallback));
    exports.Set("glfwSetCursorPosCallback", Napi::Function::New(env, __glfwSetCursorPosCallback));
    exports.Set("glfwSetCursorEnterCallback", Napi::Function::New(env, __glfwSetCursorEnterCallback));
    exports.Set("glfwSetScrollCallback", Napi::Function::New(env, __glfwSetScrollCallback));
    exports.Set("glfwSetDropCallback", Napi::Function::New(env, __glfwSetDropCallback));
    exports.Set("glfwJoystickPresent", Napi::Function::New(env, __glfwJoystickPresent));
    exports.Set("glfwGetJoystickAxes", Napi::Function::New(env, __glfwGetJoystickAxes));
    exports.Set("glfwGetJoystickButtons", Napi::Function::New(env, __glfwGetJoystickButtons));
    exports.Set("glfwGetJoystickHats", Napi::Function::New(env, __glfwGetJoystickHats));
    exports.Set("glfwGetJoystickName", Napi::Function::New(env, __glfwGetJoystickName));
    exports.Set("glfwGetJoystickGUID", Napi::Function::New(env, __glfwGetJoystickGUID));
    exports.Set("glfwJoystickIsGamepad", Napi::Function::New(env, __glfwJoystickIsGamepad));
    exports.Set("glfwSetJoystickCallback", Napi::Function::New(env, __glfwSetJoystickCallback));
    exports.Set("glfwUpdateGamepadMappings", Napi::Function::New(env, __glfwUpdateGamepadMappings));
    exports.Set("glfwGetGamepadName", Napi::Function::New(env, __glfwGetGamepadName));
    exports.Set("glfwGetGamepadState", Napi::Function::New(env, __glfwGetGamepadState));
    exports.Set("glfwSetClipboardString", Napi::Function::New(env, __glfwSetClipboardString));
    exports.Set("glfwGetClipboardString", Napi::Function::New(env, __glfwGetClipboardString));
    exports.Set("glfwGetTime", Napi::Function::New(env, __glfwGetTime));
    exports.Set("glfwSetTime", Napi::Function::New(env, __glfwSetTime));
    exports.Set("glfwGetTimerValue", Napi::Function::New(env, __glfwGetTimerValue));
    exports.Set("glfwGetTimerFrequency", Napi::Function::New(env, __glfwGetTimerFrequency));

    // Monitor functions
    exports.Set("glfwGetMonitors", Napi::Function::New(env, __glfwGetMonitors));
    exports.Set("glfwGetPrimaryMonitor", Napi::Function::New(env, __glfwGetPrimaryMonitor));
    exports.Set("glfwGetMonitorPos", Napi::Function::New(env, __glfwGetMonitorPos));
    exports.Set("glfwGetMonitorWorkarea", Napi::Function::New(env, __glfwGetMonitorWorkarea));
    exports.Set("glfwGetMonitorPhysicalSize", Napi::Function::New(env, __glfwGetMonitorPhysicalSize));
    exports.Set("glfwGetMonitorContentScale", Napi::Function::New(env, __glfwGetMonitorContentScale));
    exports.Set("glfwGetMonitorName", Napi::Function::New(env, __glfwGetMonitorName));
    exports.Set("glfwSetMonitorCallback", Napi::Function::New(env, __glfwSetMonitorCallback));
    exports.Set("glfwGetVideoModes", Napi::Function::New(env, __glfwGetVideoModes));
    exports.Set("glfwGetVideoMode", Napi::Function::New(env, __glfwGetVideoMode));
    exports.Set("glfwSetGamma", Napi::Function::New(env, __glfwSetGamma));
    exports.Set("glfwGetGammaRamp", Napi::Function::New(env, __glfwGetGammaRamp));
    exports.Set("glfwSetGammaRamp", Napi::Function::New(env, __glfwSetGammaRamp));

    // Window functions
    exports.Set("glfwDefaultWindowHints", Napi::Function::New(env, __glfwDefaultWindowHints));
    exports.Set("glfwWindowHint", Napi::Function::New(env, __glfwWindowHint));
    exports.Set("glfwWindowHintString", Napi::Function::New(env, __glfwWindowHintString));
    exports.Set("glfwCreateWindow", Napi::Function::New(env, __glfwCreateWindow));
    exports.Set("glfwDestroyWindow", Napi::Function::New(env, __glfwDestroyWindow));
    exports.Set("glfwWindowShouldClose", Napi::Function::New(env, __glfwWindowShouldClose));
    exports.Set("glfwSetWindowShouldClose", Napi::Function::New(env, __glfwSetWindowShouldClose));
    exports.Set("glfwSetWindowTitle", Napi::Function::New(env, __glfwSetWindowTitle));
    exports.Set("glfwSetWindowIcon", Napi::Function::New(env, __glfwSetWindowIcon));
    exports.Set("glfwGetWindowPos", Napi::Function::New(env, __glfwGetWindowPos));
    exports.Set("glfwSetWindowPos", Napi::Function::New(env, __glfwSetWindowPos));
    exports.Set("glfwGetWindowSize", Napi::Function::New(env, __glfwGetWindowSize));
    exports.Set("glfwSetWindowSizeLimits", Napi::Function::New(env, __glfwSetWindowSizeLimits));
    exports.Set("glfwSetWindowAspectRatio", Napi::Function::New(env, __glfwSetWindowAspectRatio));
    exports.Set("glfwSetWindowSize", Napi::Function::New(env, __glfwSetWindowSize));
    exports.Set("glfwGetFramebufferSize", Napi::Function::New(env, __glfwGetFramebufferSize));
    exports.Set("glfwGetWindowFrameSize", Napi::Function::New(env, __glfwGetWindowFrameSize));
    exports.Set("glfwGetWindowContentScale", Napi::Function::New(env, __glfwGetWindowContentScale));
    exports.Set("glfwGetWindowOpacity", Napi::Function::New(env, __glfwGetWindowOpacity));
    exports.Set("glfwSetWindowOpacity", Napi::Function::New(env, __glfwSetWindowOpacity));
    exports.Set("glfwIconifyWindow", Napi::Function::New(env, __glfwIconifyWindow));
    exports.Set("glfwRestoreWindow", Napi::Function::New(env, __glfwRestoreWindow));
    exports.Set("glfwMaximizeWindow", Napi::Function::New(env, __glfwMaximizeWindow));
    exports.Set("glfwShowWindow", Napi::Function::New(env, __glfwShowWindow));
    exports.Set("glfwHideWindow", Napi::Function::New(env, __glfwHideWindow));
    exports.Set("glfwFocusWindow", Napi::Function::New(env, __glfwFocusWindow));
    exports.Set("glfwRequestWindowAttention", Napi::Function::New(env, __glfwRequestWindowAttention));
    exports.Set("glfwGetWindowMonitor", Napi::Function::New(env, __glfwGetWindowMonitor));
    exports.Set("glfwSetWindowMonitor", Napi::Function::New(env, __glfwSetWindowMonitor));
    exports.Set("glfwGetWindowAttrib", Napi::Function::New(env, __glfwGetWindowAttrib));
    exports.Set("glfwSetWindowAttrib", Napi::Function::New(env, __glfwSetWindowAttrib));
    exports.Set("glfwSetWindowPosCallback", Napi::Function::New(env, __glfwSetWindowPosCallback));
    exports.Set("glfwSetWindowSizeCallback", Napi::Function::New(env, __glfwSetWindowSizeCallback));
    exports.Set("glfwSetWindowCloseCallback", Napi::Function::New(env, __glfwSetWindowCloseCallback));
    exports.Set("glfwSetWindowRefreshCallback", Napi::Function::New(env, __glfwSetWindowRefreshCallback));
    exports.Set("glfwSetWindowFocusCallback", Napi::Function::New(env, __glfwSetWindowFocusCallback));
    exports.Set("glfwSetWindowIconifyCallback", Napi::Function::New(env, __glfwSetWindowIconifyCallback));
    exports.Set("glfwSetWindowMaximizeCallback", Napi::Function::New(env, __glfwSetWindowMaximizeCallback));
    exports.Set("glfwSetFramebufferSizeCallback", Napi::Function::New(env, __glfwSetFramebufferSizeCallback));
    exports.Set("glfwSetWindowContentScaleCallback", Napi::Function::New(env, __glfwSetWindowContentScaleCallback));
    exports.Set("glfwPollEvents", Napi::Function::New(env, __glfwPollEvents));
    exports.Set("glfwWaitEvents", Napi::Function::New(env, __glfwWaitEvents));
    exports.Set("glfwWaitEventsTimeout", Napi::Function::New(env, __glfwWaitEventsTimeout));
    exports.Set("glfwPostEmptyEvent", Napi::Function::New(env, __glfwPostEmptyEvent));
    exports.Set("glfwSwapBuffers", Napi::Function::New(env, __glfwSwapBuffers));

    // TODO: Unified Syntax
    exports["glfwCreateWindowSurface"] = Napi::Function::New(env, __glfwCreateWindowSurface);
    exports["glfwVulkanSupported"] = Napi::Function::New(env, __glfwVulkanSupported);
    exports["glfwGetRequiredInstanceExtensions"] = Napi::Function::New(env, __glfwGetRequiredInstanceExtensions);
    exports["glfwGetPhysicalDevicePresentationSupport"] = Napi::Function::New(env, __glfwGetPhysicalDevicePresentationSupport);
#endif

    // TODO: Unified Syntax
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
