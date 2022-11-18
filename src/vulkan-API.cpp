#pragma once 

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
#define WINDOWS_IGNORE_PACKING_MISMATCH

//
#pragma pack(push,16)
#ifdef WIN32_
#include <windows.h>
#endif
#pragma pack(pop)

//
#pragma pack(push,1)
#include <volk/volk.h>
#pragma pack(pop)

//
#include <napi.h>
#include "./sizes.h"

//
static Napi::Value Dealloc(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    delete (void*)address;
    return Napi::BigInt::New(env, (uint64_t)0ull);
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

    return Napi::BigInt::New(env, (uint64_t)address);
}

static Napi::ArrayBuffer WrapArrayBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    bool lossless = true;
    if (info_[0].IsBigInt()) {
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
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
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((uint8_t*)address));
}

static Napi::Number DebugUint16(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((uint16_t*)address));
}

static Napi::Number DebugUint32(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((uint32_t*)address));
}

static Napi::Value DebugUint64(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::BigInt::New(env, (uint64_t)address);
}

static Napi::Number DebugFloat32(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((float*)address));
}

static Napi::Number DebugFloat64(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
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
    
static Napi::Value rawCreateInstance(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 0 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkInstanceCreateInfo const*)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pInstance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInstance = (VkInstance*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateInstance(pCreateInfo, pAllocator, pInstance);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyInstance(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyInstance(instance, pAllocator);
    return env.Null();
}
static Napi::Value rawEnumeratePhysicalDevices(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPhysicalDeviceCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPhysicalDeviceCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pPhysicalDevices)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPhysicalDevices = (VkPhysicalDevice*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
    return Napi::Number::New(env, result);
}
static Napi::Value rawGetDeviceProcAddr(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pName)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pName = (char const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceProcAddr(device, pName);
    return env.Null();
}
static Napi::Value rawGetInstanceProcAddr(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pName)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pName = (char const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetInstanceProcAddr(instance, pName);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkPhysicalDeviceProperties*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceQueueFamilyProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pQueueFamilyPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pQueueFamilyPropertyCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pQueueFamilyProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pQueueFamilyProperties = (VkQueueFamilyProperties*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceMemoryProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pMemoryProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryProperties = (VkPhysicalDeviceMemoryProperties*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceFeatures(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pFeatures)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFeatures = (VkPhysicalDeviceFeatures*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceFormatProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (format)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) format = (VkFormat)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pFormatProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFormatProperties = (VkFormatProperties*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceImageFormatProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (format)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) format = (VkFormat)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (type)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) type = (VkImageType)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (tiling)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) tiling = (VkImageTiling)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (usage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) usage = (VkImageUsageFlags)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 5 argument (flags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) flags = (VkImageCreateFlags)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 6 argument (pImageFormatProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImageFormatProperties = (VkImageFormatProperties*)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    return Napi::Number::New(env, result);
}
static Napi::Value rawCreateDevice(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkDeviceCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDevice = (VkDevice*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyDevice(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDevice(device, pAllocator);
    return env.Null();
}
static Napi::Value rawEnumerateInstanceVersion(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 0 argument (pApiVersion)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pApiVersion = (uint32_t*)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkEnumerateInstanceVersion(pApiVersion);
    return Napi::Number::New(env, result);
}
static Napi::Value rawEnumerateInstanceLayerProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 0 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkLayerProperties*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
    return Napi::Number::New(env, result);
}
static Napi::Value rawEnumerateInstanceExtensionProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 0 argument (pLayerName)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pLayerName = (char const*)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkExtensionProperties*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);
}
static Napi::Value rawEnumerateDeviceLayerProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkLayerProperties*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkEnumerateDeviceLayerProperties(physicalDevice, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);
}
static Napi::Value rawEnumerateDeviceExtensionProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pLayerName)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pLayerName = (char const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkExtensionProperties*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);
}
static Napi::Value rawGetDeviceQueue(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (queueFamilyIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queueFamilyIndex = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (queueIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queueIndex = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pQueue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pQueue = (VkQueue*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    return env.Null();
}
static Napi::Value rawQueueSubmit(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (queue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queue = (VkQueue)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (submitCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) submitCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSubmits)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSubmits = (VkSubmitInfo const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (fence)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) fence = (VkFence)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkQueueSubmit(queue, submitCount, pSubmits, fence);
    return Napi::Number::New(env, result);
}
static Napi::Value rawQueueWaitIdle(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (queue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queue = (VkQueue)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkQueueWaitIdle(queue);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDeviceWaitIdle(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkDeviceWaitIdle(device);
    return Napi::Number::New(env, result);
}
static Napi::Value rawAllocateMemory(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pAllocateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocateInfo = (VkMemoryAllocateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pMemory)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemory = (VkDeviceMemory*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    return Napi::Number::New(env, result);
}
static Napi::Value rawFreeMemory(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (memory)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memory = (VkDeviceMemory)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkFreeMemory(device, memory, pAllocator);
    return env.Null();
}
static Napi::Value rawMapMemory(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (memory)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memory = (VkDeviceMemory)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (offset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) offset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (size)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) size = (VkDeviceSize)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (flags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) flags = (VkMemoryMapFlags)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer of pointers) at 5 argument (ppData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ppData = (void**)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkMapMemory(device, memory, offset, size, flags, ppData);
    return Napi::Number::New(env, result);
}
static Napi::Value rawUnmapMemory(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (memory)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memory = (VkDeviceMemory)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkUnmapMemory(device, memory);
    return env.Null();
}
static Napi::Value rawFlushMappedMemoryRanges(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (memoryRangeCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memoryRangeCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMemoryRanges)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryRanges = (VkMappedMemoryRange const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    return Napi::Number::New(env, result);
}
static Napi::Value rawInvalidateMappedMemoryRanges(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (memoryRangeCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memoryRangeCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMemoryRanges)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryRanges = (VkMappedMemoryRange const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    return Napi::Number::New(env, result);
}
static Napi::Value rawGetDeviceMemoryCommitment(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (memory)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memory = (VkDeviceMemory)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCommittedMemoryInBytes)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCommittedMemoryInBytes = (VkDeviceSize*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    return env.Null();
}
static Napi::Value rawGetBufferMemoryRequirements(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMemoryRequirements)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryRequirements = (VkMemoryRequirements*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    return env.Null();
}
static Napi::Value rawBindBufferMemory(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (memory)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memory = (VkDeviceMemory)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (memoryOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memoryOffset = (VkDeviceSize)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkBindBufferMemory(device, buffer, memory, memoryOffset);
    return Napi::Number::New(env, result);
}
static Napi::Value rawGetImageMemoryRequirements(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (image)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) image = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMemoryRequirements)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryRequirements = (VkMemoryRequirements*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
    return env.Null();
}
static Napi::Value rawBindImageMemory(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (image)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) image = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (memory)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memory = (VkDeviceMemory)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (memoryOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memoryOffset = (VkDeviceSize)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkBindImageMemory(device, image, memory, memoryOffset);
    return Napi::Number::New(env, result);
}
static Napi::Value rawGetImageSparseMemoryRequirements(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (image)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) image = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSparseMemoryRequirementCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSparseMemoryRequirementCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSparseMemoryRequirements)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSparseMemoryRequirements = (VkSparseImageMemoryRequirements*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceSparseImageFormatProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (format)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) format = (VkFormat)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (type)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) type = (VkImageType)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (samples)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) samples = (VkSampleCountFlagBits)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (usage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) usage = (VkImageUsageFlags)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 5 argument (tiling)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) tiling = (VkImageTiling)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 6 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[7].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 7 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkSparseImageFormatProperties*)info_[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
    return env.Null();
}
static Napi::Value rawQueueBindSparse(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (queue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queue = (VkQueue)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (bindInfoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) bindInfoCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pBindInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBindInfo = (VkBindSparseInfo const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (fence)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) fence = (VkFence)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    return Napi::Number::New(env, result);
}
static Napi::Value rawCreateFence(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkFenceCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pFence)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFence = (VkFence*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateFence(device, pCreateInfo, pAllocator, pFence);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyFence(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (fence)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) fence = (VkFence)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyFence(device, fence, pAllocator);
    return env.Null();
}
static Napi::Value rawResetFences(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (fenceCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) fenceCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pFences)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFences = (VkFence const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkResetFences(device, fenceCount, pFences);
    return Napi::Number::New(env, result);
}
static Napi::Value rawGetFenceStatus(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (fence)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) fence = (VkFence)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetFenceStatus(device, fence);
    return Napi::Number::New(env, result);
}
static Napi::Value rawWaitForFences(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (fenceCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) fenceCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pFences)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFences = (VkFence const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (waitAll)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) waitAll = (VkBool32)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (timeout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) timeout = (uint64_t)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
    return Napi::Number::New(env, result);
}
static Napi::Value rawCreateSemaphore(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkSemaphoreCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSemaphore)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSemaphore = (VkSemaphore*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroySemaphore(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (semaphore)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) semaphore = (VkSemaphore)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroySemaphore(device, semaphore, pAllocator);
    return env.Null();
}
static Napi::Value rawCreateEvent(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkEventCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pEvent)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pEvent = (VkEvent*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyEvent(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (event)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) event = (VkEvent)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyEvent(device, event, pAllocator);
    return env.Null();
}
static Napi::Value rawGetEventStatus(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (event)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) event = (VkEvent)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetEventStatus(device, event);
    return Napi::Number::New(env, result);
}
static Napi::Value rawSetEvent(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (event)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) event = (VkEvent)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkSetEvent(device, event);
    return Napi::Number::New(env, result);
}
static Napi::Value rawResetEvent(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (event)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) event = (VkEvent)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkResetEvent(device, event);
    return Napi::Number::New(env, result);
}
static Napi::Value rawCreateQueryPool(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkQueryPoolCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pQueryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pQueryPool = (VkQueryPool*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyQueryPool(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyQueryPool(device, queryPool, pAllocator);
    return env.Null();
}
static Napi::Value rawGetQueryPoolResults(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (firstQuery)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstQuery = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (queryCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (dataSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dataSize = (size_t)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pData = (void*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 6 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (VkDeviceSize)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[7].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 7 argument (flags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) flags = (VkQueryResultFlags)info_[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    return Napi::Number::New(env, result);
}
static Napi::Value rawResetQueryPool(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (firstQuery)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstQuery = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (queryCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();
    
    ::vkResetQueryPool(device, queryPool, firstQuery, queryCount);
    return env.Null();
}
static Napi::Value rawCreateBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkBufferCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBuffer = (VkBuffer*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyBuffer(device, buffer, pAllocator);
    return env.Null();
}
static Napi::Value rawCreateBufferView(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkBufferViewCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pView)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pView = (VkBufferView*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyBufferView(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (bufferView)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) bufferView = (VkBufferView)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyBufferView(device, bufferView, pAllocator);
    return env.Null();
}
static Napi::Value rawCreateImage(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkImageCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pImage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImage = (VkImage*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateImage(device, pCreateInfo, pAllocator, pImage);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyImage(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (image)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) image = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyImage(device, image, pAllocator);
    return env.Null();
}
static Napi::Value rawGetImageSubresourceLayout(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (image)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) image = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSubresource)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSubresource = (VkImageSubresource const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pLayout = (VkSubresourceLayout*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
    return env.Null();
}
static Napi::Value rawCreateImageView(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkImageViewCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pView)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pView = (VkImageView*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateImageView(device, pCreateInfo, pAllocator, pView);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyImageView(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (imageView)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) imageView = (VkImageView)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyImageView(device, imageView, pAllocator);
    return env.Null();
}
static Napi::Value rawCreateShaderModule(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkShaderModuleCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pShaderModule)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pShaderModule = (VkShaderModule*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyShaderModule(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (shaderModule)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) shaderModule = (VkShaderModule)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyShaderModule(device, shaderModule, pAllocator);
    return env.Null();
}
static Napi::Value rawCreatePipelineCache(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkPipelineCacheCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pPipelineCache)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPipelineCache = (VkPipelineCache*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyPipelineCache(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipelineCache)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineCache = (VkPipelineCache)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyPipelineCache(device, pipelineCache, pAllocator);
    return env.Null();
}
static Napi::Value rawGetPipelineCacheData(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipelineCache)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineCache = (VkPipelineCache)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pDataSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDataSize = (size_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pData = (void*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
    return Napi::Number::New(env, result);
}
static Napi::Value rawMergePipelineCaches(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (dstCache)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstCache = (VkPipelineCache)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (srcCacheCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcCacheCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSrcCaches)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSrcCaches = (VkPipelineCache const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
    return Napi::Number::New(env, result);
}
static Napi::Value rawCreateGraphicsPipelines(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipelineCache)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineCache = (VkPipelineCache)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (createInfoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) createInfoCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCreateInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfos = (VkGraphicsPipelineCreateInfo const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pPipelines)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPipelines = (VkPipeline*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return Napi::Number::New(env, result);
}
static Napi::Value rawCreateComputePipelines(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipelineCache)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineCache = (VkPipelineCache)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (createInfoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) createInfoCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCreateInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfos = (VkComputePipelineCreateInfo const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pPipelines)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPipelines = (VkPipeline*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return Napi::Number::New(env, result);
}
#ifdef VK_HUAWEI_subpass_shading
static Napi::Value rawGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (renderpass)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) renderpass = (VkRenderPass)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMaxWorkgroupSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMaxWorkgroupSize = (VkExtent2D*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(device, renderpass, pMaxWorkgroupSize);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawDestroyPipeline(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipeline)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipeline = (VkPipeline)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyPipeline(device, pipeline, pAllocator);
    return env.Null();
}
static Napi::Value rawCreatePipelineLayout(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkPipelineLayoutCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pPipelineLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPipelineLayout = (VkPipelineLayout*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyPipelineLayout(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipelineLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineLayout = (VkPipelineLayout)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
    return env.Null();
}
static Napi::Value rawCreateSampler(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkSamplerCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSampler)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSampler = (VkSampler*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroySampler(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (sampler)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) sampler = (VkSampler)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroySampler(device, sampler, pAllocator);
    return env.Null();
}
static Napi::Value rawCreateDescriptorSetLayout(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkDescriptorSetLayoutCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSetLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSetLayout = (VkDescriptorSetLayout*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyDescriptorSetLayout(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (descriptorSetLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorSetLayout = (VkDescriptorSetLayout)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    return env.Null();
}
static Napi::Value rawCreateDescriptorPool(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkDescriptorPoolCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pDescriptorPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDescriptorPool = (VkDescriptorPool*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyDescriptorPool(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (descriptorPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorPool = (VkDescriptorPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
    return env.Null();
}
static Napi::Value rawResetDescriptorPool(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (descriptorPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorPool = (VkDescriptorPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (flags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) flags = (VkDescriptorPoolResetFlags)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkResetDescriptorPool(device, descriptorPool, flags);
    return Napi::Number::New(env, result);
}
static Napi::Value rawAllocateDescriptorSets(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pAllocateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocateInfo = (VkDescriptorSetAllocateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pDescriptorSets)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDescriptorSets = (VkDescriptorSet*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
    return Napi::Number::New(env, result);
}
static Napi::Value rawFreeDescriptorSets(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (descriptorPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorPool = (VkDescriptorPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (descriptorSetCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorSetCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pDescriptorSets)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDescriptorSets = (VkDescriptorSet const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    return Napi::Number::New(env, result);
}
static Napi::Value rawUpdateDescriptorSets(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (descriptorWriteCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorWriteCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pDescriptorWrites)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDescriptorWrites = (VkWriteDescriptorSet const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (descriptorCopyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorCopyCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pDescriptorCopies)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDescriptorCopies = (VkCopyDescriptorSet const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    return env.Null();
}
static Napi::Value rawCreateFramebuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkFramebufferCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pFramebuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFramebuffer = (VkFramebuffer*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyFramebuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (framebuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) framebuffer = (VkFramebuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyFramebuffer(device, framebuffer, pAllocator);
    return env.Null();
}
static Napi::Value rawCreateRenderPass(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkRenderPassCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pRenderPass)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRenderPass = (VkRenderPass*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyRenderPass(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (renderPass)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) renderPass = (VkRenderPass)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyRenderPass(device, renderPass, pAllocator);
    return env.Null();
}
static Napi::Value rawGetRenderAreaGranularity(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (renderPass)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) renderPass = (VkRenderPass)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pGranularity)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pGranularity = (VkExtent2D*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetRenderAreaGranularity(device, renderPass, pGranularity);
    return env.Null();
}
static Napi::Value rawCreateCommandPool(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkCommandPoolCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCommandPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCommandPool = (VkCommandPool*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyCommandPool(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (commandPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandPool = (VkCommandPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyCommandPool(device, commandPool, pAllocator);
    return env.Null();
}
static Napi::Value rawResetCommandPool(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (commandPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandPool = (VkCommandPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (flags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) flags = (VkCommandPoolResetFlags)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkResetCommandPool(device, commandPool, flags);
    return Napi::Number::New(env, result);
}
static Napi::Value rawAllocateCommandBuffers(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pAllocateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocateInfo = (VkCommandBufferAllocateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCommandBuffers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCommandBuffers = (VkCommandBuffer*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
    return Napi::Number::New(env, result);
}
static Napi::Value rawFreeCommandBuffers(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (commandPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandPool = (VkCommandPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (commandBufferCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBufferCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCommandBuffers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCommandBuffers = (VkCommandBuffer const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    return env.Null();
}
static Napi::Value rawBeginCommandBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pBeginInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBeginInfo = (VkCommandBufferBeginInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkBeginCommandBuffer(commandBuffer, pBeginInfo);
    return Napi::Number::New(env, result);
}
static Napi::Value rawEndCommandBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkEndCommandBuffer(commandBuffer);
    return Napi::Number::New(env, result);
}
static Napi::Value rawResetCommandBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (flags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) flags = (VkCommandBufferResetFlags)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkResetCommandBuffer(commandBuffer, flags);
    return Napi::Number::New(env, result);
}
static Napi::Value rawCmdBindPipeline(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipelineBindPoint)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineBindPoint = (VkPipelineBindPoint)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (pipeline)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipeline = (VkPipeline)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    return env.Null();
}
static Napi::Value rawCmdSetViewport(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstViewport)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstViewport = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (viewportCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) viewportCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pViewports)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pViewports = (VkViewport const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    return env.Null();
}
static Napi::Value rawCmdSetScissor(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstScissor)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstScissor = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (scissorCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) scissorCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pScissors)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pScissors = (VkRect2D const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    return env.Null();
}
static Napi::Value rawCmdSetLineWidth(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (lineWidth)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) lineWidth = (float)info_[1].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetLineWidth(commandBuffer, lineWidth);
    return env.Null();
}
static Napi::Value rawCmdSetDepthBias(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (depthBiasConstantFactor)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depthBiasConstantFactor = (float)info_[1].As<Napi::Number>().FloatValue();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (depthBiasClamp)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depthBiasClamp = (float)info_[2].As<Napi::Number>().FloatValue();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (depthBiasSlopeFactor)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depthBiasSlopeFactor = (float)info_[3].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    return env.Null();
}
static Napi::Value rawCmdSetBlendConstants(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (blendConstants)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) blendConstants = (float const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetBlendConstants(commandBuffer, blendConstants);
    return env.Null();
}
static Napi::Value rawCmdSetDepthBounds(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (minDepthBounds)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) minDepthBounds = (float)info_[1].As<Napi::Number>().FloatValue();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (maxDepthBounds)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) maxDepthBounds = (float)info_[2].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    return env.Null();
}
static Napi::Value rawCmdSetStencilCompareMask(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (faceMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) faceMask = (VkStencilFaceFlags)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (compareMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) compareMask = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    return env.Null();
}
static Napi::Value rawCmdSetStencilWriteMask(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (faceMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) faceMask = (VkStencilFaceFlags)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (writeMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) writeMask = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    return env.Null();
}
static Napi::Value rawCmdSetStencilReference(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (faceMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) faceMask = (VkStencilFaceFlags)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (reference)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) reference = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetStencilReference(commandBuffer, faceMask, reference);
    return env.Null();
}
static Napi::Value rawCmdBindDescriptorSets(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipelineBindPoint)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineBindPoint = (VkPipelineBindPoint)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (layout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) layout = (VkPipelineLayout)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (firstSet)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstSet = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (descriptorSetCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorSetCount = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pDescriptorSets)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDescriptorSets = (VkDescriptorSet const*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 6 argument (dynamicOffsetCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dynamicOffsetCount = (uint32_t)info_[6].As<Napi::Number>().Uint32Value();

    if (!info_[7].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 7 argument (pDynamicOffsets)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDynamicOffsets = (uint32_t const*)info_[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    return env.Null();
}
static Napi::Value rawCmdBindIndexBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (offset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) offset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (indexType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) indexType = (VkIndexType)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    return env.Null();
}
static Napi::Value rawCmdBindVertexBuffers(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstBinding)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstBinding = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (bindingCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) bindingCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pBuffers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBuffers = (VkBuffer const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pOffsets)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pOffsets = (VkDeviceSize const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    return env.Null();
}
static Napi::Value rawCmdDraw(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (vertexCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) vertexCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (instanceCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instanceCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (firstVertex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstVertex = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (firstInstance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstInstance = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    return env.Null();
}
static Napi::Value rawCmdDrawIndexed(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (indexCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) indexCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (instanceCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instanceCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (firstIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstIndex = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (vertexOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) vertexOffset = (int32_t)info_[4].As<Napi::Number>().Int32Value();

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (firstInstance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstInstance = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    return env.Null();
}
#ifdef VK_EXT_multi_draw
static Napi::Value rawCmdDrawMultiEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (drawCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) drawCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pVertexInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pVertexInfo = (VkMultiDrawInfoEXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (instanceCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instanceCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (firstInstance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstInstance = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
    return env.Null();
}
#endif
#ifdef VK_EXT_multi_draw
static Napi::Value rawCmdDrawMultiIndexedEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (drawCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) drawCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pIndexInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pIndexInfo = (VkMultiDrawIndexedInfoEXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (instanceCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instanceCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (firstInstance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstInstance = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 6 argument (pVertexOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pVertexOffset = (int32_t const*)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
    return env.Null();
}
#endif
static Napi::Value rawCmdDrawIndirect(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (offset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) offset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (drawCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) drawCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    return env.Null();
}
static Napi::Value rawCmdDrawIndexedIndirect(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (offset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) offset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (drawCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) drawCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    return env.Null();
}
static Napi::Value rawCmdDispatch(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (groupCountX)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupCountX = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (groupCountY)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupCountY = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (groupCountZ)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupCountZ = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    return env.Null();
}
static Napi::Value rawCmdDispatchIndirect(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (offset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) offset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDispatchIndirect(commandBuffer, buffer, offset);
    return env.Null();
}
#ifdef VK_HUAWEI_subpass_shading
static Napi::Value rawCmdSubpassShadingHUAWEI(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSubpassShadingHUAWEI(commandBuffer);
    return env.Null();
}
#endif
static Napi::Value rawCmdCopyBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (srcBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcBuffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (dstBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstBuffer = (VkBuffer)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (regionCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) regionCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pRegions)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRegions = (VkBufferCopy const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    return env.Null();
}
static Napi::Value rawCmdCopyImage(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (srcImage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcImage = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (srcImageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcImageLayout = (VkImageLayout)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (dstImage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstImage = (VkImage)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (dstImageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstImageLayout = (VkImageLayout)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (regionCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) regionCount = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 6 argument (pRegions)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRegions = (VkImageCopy const*)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    return env.Null();
}
static Napi::Value rawCmdBlitImage(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (srcImage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcImage = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (srcImageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcImageLayout = (VkImageLayout)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (dstImage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstImage = (VkImage)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (dstImageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstImageLayout = (VkImageLayout)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (regionCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) regionCount = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 6 argument (pRegions)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRegions = (VkImageBlit const*)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[7].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 7 argument (filter)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) filter = (VkFilter)info_[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    return env.Null();
}
static Napi::Value rawCmdCopyBufferToImage(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (srcBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcBuffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (dstImage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstImage = (VkImage)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (dstImageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstImageLayout = (VkImageLayout)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (regionCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) regionCount = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pRegions)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRegions = (VkBufferImageCopy const*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    return env.Null();
}
static Napi::Value rawCmdCopyImageToBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (srcImage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcImage = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (srcImageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcImageLayout = (VkImageLayout)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (dstBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstBuffer = (VkBuffer)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (regionCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) regionCount = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pRegions)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRegions = (VkBufferImageCopy const*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    return env.Null();
}
#ifdef VK_NV_copy_memory_indirect
static Napi::Value rawCmdCopyMemoryIndirectNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (copyBufferAddress)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) copyBufferAddress = (VkDeviceAddress)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (copyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) copyCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
    return env.Null();
}
#endif
#ifdef VK_NV_copy_memory_indirect
static Napi::Value rawCmdCopyMemoryToImageIndirectNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (copyBufferAddress)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) copyBufferAddress = (VkDeviceAddress)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (copyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) copyCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (dstImage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstImage = (VkImage)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 5 argument (dstImageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstImageLayout = (VkImageLayout)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 6 argument (pImageSubresources)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImageSubresources = (VkImageSubresourceLayers const*)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
    return env.Null();
}
#endif
static Napi::Value rawCmdUpdateBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (dstBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstBuffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (dstOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstOffset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (dataSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dataSize = (VkDeviceSize)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pData = (void const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    return env.Null();
}
static Napi::Value rawCmdFillBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (dstBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstBuffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (dstOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstOffset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (size)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) size = (VkDeviceSize)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (data)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) data = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    return env.Null();
}
static Napi::Value rawCmdClearColorImage(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (image)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) image = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (imageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) imageLayout = (VkImageLayout)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pColor)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pColor = (VkClearColorValue const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (rangeCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) rangeCount = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pRanges)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRanges = (VkImageSubresourceRange const*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    return env.Null();
}
static Napi::Value rawCmdClearDepthStencilImage(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (image)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) image = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (imageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) imageLayout = (VkImageLayout)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pDepthStencil)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDepthStencil = (VkClearDepthStencilValue const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (rangeCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) rangeCount = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pRanges)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRanges = (VkImageSubresourceRange const*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    return env.Null();
}
static Napi::Value rawCmdClearAttachments(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (attachmentCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) attachmentCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAttachments)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAttachments = (VkClearAttachment const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (rectCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) rectCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pRects)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRects = (VkClearRect const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    return env.Null();
}
static Napi::Value rawCmdResolveImage(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (srcImage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcImage = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (srcImageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcImageLayout = (VkImageLayout)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (dstImage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstImage = (VkImage)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (dstImageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstImageLayout = (VkImageLayout)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (regionCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) regionCount = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 6 argument (pRegions)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRegions = (VkImageResolve const*)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    return env.Null();
}
static Napi::Value rawCmdSetEvent(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (event)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) event = (VkEvent)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (stageMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stageMask = (VkPipelineStageFlags)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetEvent(commandBuffer, event, stageMask);
    return env.Null();
}
static Napi::Value rawCmdResetEvent(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (event)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) event = (VkEvent)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (stageMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stageMask = (VkPipelineStageFlags)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdResetEvent(commandBuffer, event, stageMask);
    return env.Null();
}
static Napi::Value rawCmdWaitEvents(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 11) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (eventCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) eventCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pEvents)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pEvents = (VkEvent const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (srcStageMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcStageMask = (VkPipelineStageFlags)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (dstStageMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstStageMask = (VkPipelineStageFlags)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (memoryBarrierCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memoryBarrierCount = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 6 argument (pMemoryBarriers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryBarriers = (VkMemoryBarrier const*)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[7].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 7 argument (bufferMemoryBarrierCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) bufferMemoryBarrierCount = (uint32_t)info_[7].As<Napi::Number>().Uint32Value();

    if (!info_[8].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 8 argument (pBufferMemoryBarriers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBufferMemoryBarriers = (VkBufferMemoryBarrier const*)info_[8].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[9].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 9 argument (imageMemoryBarrierCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) imageMemoryBarrierCount = (uint32_t)info_[9].As<Napi::Number>().Uint32Value();

    if (!info_[10].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 10 argument (pImageMemoryBarriers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImageMemoryBarriers = (VkImageMemoryBarrier const*)info_[10].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    return env.Null();
}
static Napi::Value rawCmdPipelineBarrier(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 10) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (srcStageMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcStageMask = (VkPipelineStageFlags)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (dstStageMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstStageMask = (VkPipelineStageFlags)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (dependencyFlags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dependencyFlags = (VkDependencyFlags)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (memoryBarrierCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memoryBarrierCount = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pMemoryBarriers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryBarriers = (VkMemoryBarrier const*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 6 argument (bufferMemoryBarrierCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) bufferMemoryBarrierCount = (uint32_t)info_[6].As<Napi::Number>().Uint32Value();

    if (!info_[7].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 7 argument (pBufferMemoryBarriers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBufferMemoryBarriers = (VkBufferMemoryBarrier const*)info_[7].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[8].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 8 argument (imageMemoryBarrierCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) imageMemoryBarrierCount = (uint32_t)info_[8].As<Napi::Number>().Uint32Value();

    if (!info_[9].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 9 argument (pImageMemoryBarriers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImageMemoryBarriers = (VkImageMemoryBarrier const*)info_[9].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    return env.Null();
}
static Napi::Value rawCmdBeginQuery(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (query)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) query = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (flags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) flags = (VkQueryControlFlags)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
    return env.Null();
}
static Napi::Value rawCmdEndQuery(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (query)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) query = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdEndQuery(commandBuffer, queryPool, query);
    return env.Null();
}
#ifdef VK_EXT_conditional_rendering
static Napi::Value rawCmdBeginConditionalRenderingEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pConditionalRenderingBegin)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pConditionalRenderingBegin = (VkConditionalRenderingBeginInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
    return env.Null();
}
#endif
#ifdef VK_EXT_conditional_rendering
static Napi::Value rawCmdEndConditionalRenderingEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndConditionalRenderingEXT(commandBuffer);
    return env.Null();
}
#endif
static Napi::Value rawCmdResetQueryPool(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (firstQuery)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstQuery = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (queryCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    return env.Null();
}
static Napi::Value rawCmdWriteTimestamp(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipelineStage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineStage = (VkPipelineStageFlagBits)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (query)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) query = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    return env.Null();
}
static Napi::Value rawCmdCopyQueryPoolResults(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (firstQuery)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstQuery = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (queryCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (dstBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstBuffer = (VkBuffer)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 5 argument (dstOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstOffset = (VkDeviceSize)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 6 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (VkDeviceSize)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[7].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 7 argument (flags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) flags = (VkQueryResultFlags)info_[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    return env.Null();
}
static Napi::Value rawCmdPushConstants(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (layout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) layout = (VkPipelineLayout)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (stageFlags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stageFlags = (VkShaderStageFlags)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (offset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) offset = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (size)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) size = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pValues)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pValues = (void const*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    return env.Null();
}
static Napi::Value rawCmdBeginRenderPass(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pRenderPassBegin)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRenderPassBegin = (VkRenderPassBeginInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (contents)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) contents = (VkSubpassContents)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    return env.Null();
}
static Napi::Value rawCmdNextSubpass(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (contents)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) contents = (VkSubpassContents)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdNextSubpass(commandBuffer, contents);
    return env.Null();
}
static Napi::Value rawCmdEndRenderPass(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndRenderPass(commandBuffer);
    return env.Null();
}
static Napi::Value rawCmdExecuteCommands(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (commandBufferCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBufferCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCommandBuffers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCommandBuffers = (VkCommandBuffer const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    return env.Null();
}
#ifdef VK_KHR_android_surface
static Napi::Value rawCreateAndroidSurfaceKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkAndroidSurfaceCreateInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_display
static Napi::Value rawGetPhysicalDeviceDisplayPropertiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkDisplayPropertiesKHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_display
static Napi::Value rawGetPhysicalDeviceDisplayPlanePropertiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkDisplayPlanePropertiesKHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_display
static Napi::Value rawGetDisplayPlaneSupportedDisplaysKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (planeIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) planeIndex = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pDisplayCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDisplayCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pDisplays)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDisplays = (VkDisplayKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_display
static Napi::Value rawGetDisplayModePropertiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (display)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) display = (VkDisplayKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkDisplayModePropertiesKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_display
static Napi::Value rawCreateDisplayModeKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (display)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) display = (VkDisplayKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkDisplayModeCreateInfoKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pMode)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMode = (VkDisplayModeKHR*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_display
static Napi::Value rawGetDisplayPlaneCapabilitiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (mode)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) mode = (VkDisplayModeKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (planeIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) planeIndex = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCapabilities)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCapabilities = (VkDisplayPlaneCapabilitiesKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_display
static Napi::Value rawCreateDisplayPlaneSurfaceKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkDisplaySurfaceCreateInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_display_swapchain
static Napi::Value rawCreateSharedSwapchainsKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (swapchainCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchainCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCreateInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfos = (VkSwapchainCreateInfoKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pSwapchains)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSwapchains = (VkSwapchainKHR*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_surface
static Napi::Value rawDestroySurfaceKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (surface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) surface = (VkSurfaceKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroySurfaceKHR(instance, surface, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_KHR_surface
static Napi::Value rawGetPhysicalDeviceSurfaceSupportKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (queueFamilyIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queueFamilyIndex = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (surface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) surface = (VkSurfaceKHR)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSupported)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSupported = (VkBool32*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_surface
static Napi::Value rawGetPhysicalDeviceSurfaceCapabilitiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (surface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) surface = (VkSurfaceKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSurfaceCapabilities)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurfaceCapabilities = (VkSurfaceCapabilitiesKHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_surface
static Napi::Value rawGetPhysicalDeviceSurfaceFormatsKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (surface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) surface = (VkSurfaceKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSurfaceFormatCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurfaceFormatCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurfaceFormats)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurfaceFormats = (VkSurfaceFormatKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_surface
static Napi::Value rawGetPhysicalDeviceSurfacePresentModesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (surface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) surface = (VkSurfaceKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pPresentModeCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPresentModeCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pPresentModes)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPresentModes = (VkPresentModeKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_swapchain
static Napi::Value rawCreateSwapchainKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkSwapchainCreateInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSwapchain)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSwapchain = (VkSwapchainKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_swapchain
static Napi::Value rawDestroySwapchainKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (swapchain)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchain = (VkSwapchainKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroySwapchainKHR(device, swapchain, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_KHR_swapchain
static Napi::Value rawGetSwapchainImagesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (swapchain)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchain = (VkSwapchainKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSwapchainImageCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSwapchainImageCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSwapchainImages)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSwapchainImages = (VkImage*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_swapchain
static Napi::Value rawAcquireNextImageKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (swapchain)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchain = (VkSwapchainKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (timeout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) timeout = (uint64_t)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (semaphore)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) semaphore = (VkSemaphore)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (fence)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) fence = (VkFence)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pImageIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImageIndex = (uint32_t*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_swapchain
static Napi::Value rawQueuePresentKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (queue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queue = (VkQueue)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPresentInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPresentInfo = (VkPresentInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkQueuePresentKHR(queue, pPresentInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NN_vi_surface
static Napi::Value rawCreateViSurfaceNN(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkViSurfaceCreateInfoNN const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_wayland_surface
static Napi::Value rawCreateWaylandSurfaceKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkWaylandSurfaceCreateInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_wayland_surface
static Napi::Value rawGetPhysicalDeviceWaylandPresentationSupportKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (queueFamilyIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queueFamilyIndex = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (display)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) display = (wl_display*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_win32_surface
static Napi::Value rawCreateWin32SurfaceKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkWin32SurfaceCreateInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_win32_surface
static Napi::Value rawGetPhysicalDeviceWin32PresentationSupportKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (queueFamilyIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queueFamilyIndex = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();
    
    decltype(auto) result = ::vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_xlib_surface
static Napi::Value rawCreateXlibSurfaceKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkXlibSurfaceCreateInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_xlib_surface
static Napi::Value rawGetPhysicalDeviceXlibPresentationSupportKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (queueFamilyIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queueFamilyIndex = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (dpy)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dpy = (Display*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (visualID)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) visualID = (VisualID)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_xcb_surface
static Napi::Value rawCreateXcbSurfaceKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkXcbSurfaceCreateInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_xcb_surface
static Napi::Value rawGetPhysicalDeviceXcbPresentationSupportKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (queueFamilyIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queueFamilyIndex = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (connection)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) connection = (xcb_connection_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (visual_id)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) visual_id = (xcb_visualid_t)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_directfb_surface
static Napi::Value rawCreateDirectFBSurfaceEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkDirectFBSurfaceCreateInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateDirectFBSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_directfb_surface
static Napi::Value rawGetPhysicalDeviceDirectFBPresentationSupportEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (queueFamilyIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queueFamilyIndex = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (dfb)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dfb = (IDirectFB*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceDirectFBPresentationSupportEXT(physicalDevice, queueFamilyIndex, dfb);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_FUCHSIA_imagepipe_surface
static Napi::Value rawCreateImagePipeSurfaceFUCHSIA(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkImagePipeSurfaceCreateInfoFUCHSIA const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateImagePipeSurfaceFUCHSIA(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_GGP_stream_descriptor_surface
static Napi::Value rawCreateStreamDescriptorSurfaceGGP(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkStreamDescriptorSurfaceCreateInfoGGP const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateStreamDescriptorSurfaceGGP(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_QNX_screen_surface
static Napi::Value rawCreateScreenSurfaceQNX(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkScreenSurfaceCreateInfoQNX const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateScreenSurfaceQNX(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_QNX_screen_surface
static Napi::Value rawGetPhysicalDeviceScreenPresentationSupportQNX(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (queueFamilyIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queueFamilyIndex = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (window)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) window = (_screen_window*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceScreenPresentationSupportQNX(physicalDevice, queueFamilyIndex, window);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_debug_report
static Napi::Value rawCreateDebugReportCallbackEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkDebugReportCallbackCreateInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCallback)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCallback = (VkDebugReportCallbackEXT*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_debug_report
static Napi::Value rawDestroyDebugReportCallbackEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (callback)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) callback = (VkDebugReportCallbackEXT)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDebugReportCallbackEXT(instance, callback, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_EXT_debug_report
static Napi::Value rawDebugReportMessageEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (flags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) flags = (VkDebugReportFlagsEXT)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (objectType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) objectType = (VkDebugReportObjectTypeEXT)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (object)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) object = (uint64_t)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (location)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) location = (size_t)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (messageCode)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) messageCode = (int32_t)info_[5].As<Napi::Number>().Int32Value();

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 6 argument (pLayerPrefix)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pLayerPrefix = (char const*)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[7].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 7 argument (pMessage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMessage = (char const*)info_[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
    return env.Null();
}
#endif
#ifdef VK_EXT_debug_marker
static Napi::Value rawDebugMarkerSetObjectNameEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pNameInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pNameInfo = (VkDebugMarkerObjectNameInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkDebugMarkerSetObjectNameEXT(device, pNameInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_debug_marker
static Napi::Value rawDebugMarkerSetObjectTagEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pTagInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pTagInfo = (VkDebugMarkerObjectTagInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkDebugMarkerSetObjectTagEXT(device, pTagInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_debug_marker
static Napi::Value rawCmdDebugMarkerBeginEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pMarkerInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMarkerInfo = (VkDebugMarkerMarkerInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_debug_marker
static Napi::Value rawCmdDebugMarkerEndEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDebugMarkerEndEXT(commandBuffer);
    return env.Null();
}
#endif
#ifdef VK_EXT_debug_marker
static Napi::Value rawCmdDebugMarkerInsertEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pMarkerInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMarkerInfo = (VkDebugMarkerMarkerInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    return env.Null();
}
#endif
#ifdef VK_NV_external_memory_capabilities
static Napi::Value rawGetPhysicalDeviceExternalImageFormatPropertiesNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (format)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) format = (VkFormat)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (type)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) type = (VkImageType)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (tiling)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) tiling = (VkImageTiling)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (usage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) usage = (VkImageUsageFlags)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 5 argument (flags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) flags = (VkImageCreateFlags)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 6 argument (externalHandleType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) externalHandleType = (VkExternalMemoryHandleTypeFlagsNV)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[7].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 7 argument (pExternalImageFormatProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pExternalImageFormatProperties = (VkExternalImageFormatPropertiesNV*)info_[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_external_memory_win32
static Napi::Value rawGetMemoryWin32HandleNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (memory)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memory = (VkDeviceMemory)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (handleType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) handleType = (VkExternalMemoryHandleTypeFlagsNV)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pHandle)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pHandle = (HANDLE*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetMemoryWin32HandleNV(device, memory, handleType, pHandle);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_device_generated_commands
static Napi::Value rawCmdExecuteGeneratedCommandsNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (isPreprocessed)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) isPreprocessed = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pGeneratedCommandsInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pGeneratedCommandsInfo = (VkGeneratedCommandsInfoNV const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    return env.Null();
}
#endif
#ifdef VK_NV_device_generated_commands
static Napi::Value rawCmdPreprocessGeneratedCommandsNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pGeneratedCommandsInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pGeneratedCommandsInfo = (VkGeneratedCommandsInfoNV const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
    return env.Null();
}
#endif
#ifdef VK_NV_device_generated_commands
static Napi::Value rawCmdBindPipelineShaderGroupNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipelineBindPoint)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineBindPoint = (VkPipelineBindPoint)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (pipeline)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipeline = (VkPipeline)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (groupIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupIndex = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    return env.Null();
}
#endif
#ifdef VK_NV_device_generated_commands
static Napi::Value rawGetGeneratedCommandsMemoryRequirementsNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkGeneratedCommandsMemoryRequirementsInfoNV const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMemoryRequirements)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryRequirements = (VkMemoryRequirements2*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetGeneratedCommandsMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
    return env.Null();
}
#endif
#ifdef VK_NV_device_generated_commands
static Napi::Value rawCreateIndirectCommandsLayoutNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkIndirectCommandsLayoutCreateInfoNV const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pIndirectCommandsLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pIndirectCommandsLayout = (VkIndirectCommandsLayoutNV*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateIndirectCommandsLayoutNV(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_device_generated_commands
static Napi::Value rawDestroyIndirectCommandsLayoutNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (indirectCommandsLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) indirectCommandsLayout = (VkIndirectCommandsLayoutNV)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyIndirectCommandsLayoutNV(device, indirectCommandsLayout, pAllocator);
    return env.Null();
}
#endif
static Napi::Value rawGetPhysicalDeviceFeatures2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pFeatures)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFeatures = (VkPhysicalDeviceFeatures2*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceProperties2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkPhysicalDeviceProperties2*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceProperties2(physicalDevice, pProperties);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceFormatProperties2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (format)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) format = (VkFormat)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pFormatProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFormatProperties = (VkFormatProperties2*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceImageFormatProperties2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pImageFormatInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImageFormatInfo = (VkPhysicalDeviceImageFormatInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pImageFormatProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImageFormatProperties = (VkImageFormatProperties2*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    return Napi::Number::New(env, result);
}
static Napi::Value rawGetPhysicalDeviceQueueFamilyProperties2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pQueueFamilyPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pQueueFamilyPropertyCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pQueueFamilyProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pQueueFamilyProperties = (VkQueueFamilyProperties2*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceMemoryProperties2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pMemoryProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryProperties = (VkPhysicalDeviceMemoryProperties2*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceSparseImageFormatProperties2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pFormatInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFormatInfo = (VkPhysicalDeviceSparseImageFormatInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkSparseImageFormatProperties2*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    return env.Null();
}
#ifdef VK_KHR_push_descriptor
static Napi::Value rawCmdPushDescriptorSetKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipelineBindPoint)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineBindPoint = (VkPipelineBindPoint)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (layout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) layout = (VkPipelineLayout)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (set)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) set = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (descriptorWriteCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorWriteCount = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pDescriptorWrites)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDescriptorWrites = (VkWriteDescriptorSet const*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    return env.Null();
}
#endif
static Napi::Value rawTrimCommandPool(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (commandPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandPool = (VkCommandPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (flags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) flags = (VkCommandPoolTrimFlags)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkTrimCommandPool(device, commandPool, flags);
    return env.Null();
}
static Napi::Value rawGetPhysicalDeviceExternalBufferProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pExternalBufferInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pExternalBufferInfo = (VkPhysicalDeviceExternalBufferInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pExternalBufferProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pExternalBufferProperties = (VkExternalBufferProperties*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    return env.Null();
}
#ifdef VK_KHR_external_memory_win32
static Napi::Value rawGetMemoryWin32HandleKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pGetWin32HandleInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pGetWin32HandleInfo = (VkMemoryGetWin32HandleInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pHandle)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pHandle = (HANDLE*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_external_memory_win32
static Napi::Value rawGetMemoryWin32HandlePropertiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (handleType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) handleType = (VkExternalMemoryHandleTypeFlagBits)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (handle)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) handle = (HANDLE)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pMemoryWin32HandleProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryWin32HandleProperties = (VkMemoryWin32HandlePropertiesKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_external_memory_fd
static Napi::Value rawGetMemoryFdKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pGetFdInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pGetFdInfo = (VkMemoryGetFdInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pFd)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFd = (int*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetMemoryFdKHR(device, pGetFdInfo, pFd);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_external_memory_fd
static Napi::Value rawGetMemoryFdPropertiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (handleType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) handleType = (VkExternalMemoryHandleTypeFlagBits)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (fd)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) fd = (int)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pMemoryFdProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryFdProperties = (VkMemoryFdPropertiesKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_FUCHSIA_external_memory
static Napi::Value rawGetMemoryZirconHandleFUCHSIA(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pGetZirconHandleInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pGetZirconHandleInfo = (VkMemoryGetZirconHandleInfoFUCHSIA const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pZirconHandle)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pZirconHandle = (zx_handle_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetMemoryZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_FUCHSIA_external_memory
static Napi::Value rawGetMemoryZirconHandlePropertiesFUCHSIA(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (handleType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) handleType = (VkExternalMemoryHandleTypeFlagBits)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (zirconHandle)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) zirconHandle = (zx_handle_t)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pMemoryZirconHandleProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryZirconHandleProperties = (VkMemoryZirconHandlePropertiesFUCHSIA*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetMemoryZirconHandlePropertiesFUCHSIA(device, handleType, zirconHandle, pMemoryZirconHandleProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_external_memory_rdma
static Napi::Value rawGetMemoryRemoteAddressNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pMemoryGetRemoteAddressInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryGetRemoteAddressInfo = (VkMemoryGetRemoteAddressInfoNV const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAddress)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAddress = (VkRemoteAddressNV*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetMemoryRemoteAddressNV(device, pMemoryGetRemoteAddressInfo, pAddress);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawGetPhysicalDeviceExternalSemaphoreProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pExternalSemaphoreInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pExternalSemaphoreInfo = (VkPhysicalDeviceExternalSemaphoreInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pExternalSemaphoreProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pExternalSemaphoreProperties = (VkExternalSemaphoreProperties*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    return env.Null();
}
#ifdef VK_KHR_external_semaphore_win32
static Napi::Value rawGetSemaphoreWin32HandleKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pGetWin32HandleInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pGetWin32HandleInfo = (VkSemaphoreGetWin32HandleInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pHandle)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pHandle = (HANDLE*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_external_semaphore_win32
static Napi::Value rawImportSemaphoreWin32HandleKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pImportSemaphoreWin32HandleInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImportSemaphoreWin32HandleInfo = (VkImportSemaphoreWin32HandleInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_external_semaphore_fd
static Napi::Value rawGetSemaphoreFdKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pGetFdInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pGetFdInfo = (VkSemaphoreGetFdInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pFd)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFd = (int*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetSemaphoreFdKHR(device, pGetFdInfo, pFd);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_external_semaphore_fd
static Napi::Value rawImportSemaphoreFdKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pImportSemaphoreFdInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImportSemaphoreFdInfo = (VkImportSemaphoreFdInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_FUCHSIA_external_semaphore
static Napi::Value rawGetSemaphoreZirconHandleFUCHSIA(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pGetZirconHandleInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pGetZirconHandleInfo = (VkSemaphoreGetZirconHandleInfoFUCHSIA const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pZirconHandle)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pZirconHandle = (zx_handle_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetSemaphoreZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_FUCHSIA_external_semaphore
static Napi::Value rawImportSemaphoreZirconHandleFUCHSIA(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pImportSemaphoreZirconHandleInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImportSemaphoreZirconHandleInfo = (VkImportSemaphoreZirconHandleInfoFUCHSIA const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkImportSemaphoreZirconHandleFUCHSIA(device, pImportSemaphoreZirconHandleInfo);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawGetPhysicalDeviceExternalFenceProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pExternalFenceInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pExternalFenceInfo = (VkPhysicalDeviceExternalFenceInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pExternalFenceProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pExternalFenceProperties = (VkExternalFenceProperties*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    return env.Null();
}
#ifdef VK_KHR_external_fence_win32
static Napi::Value rawGetFenceWin32HandleKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pGetWin32HandleInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pGetWin32HandleInfo = (VkFenceGetWin32HandleInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pHandle)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pHandle = (HANDLE*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_external_fence_win32
static Napi::Value rawImportFenceWin32HandleKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pImportFenceWin32HandleInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImportFenceWin32HandleInfo = (VkImportFenceWin32HandleInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_external_fence_fd
static Napi::Value rawGetFenceFdKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pGetFdInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pGetFdInfo = (VkFenceGetFdInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pFd)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFd = (int*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetFenceFdKHR(device, pGetFdInfo, pFd);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_external_fence_fd
static Napi::Value rawImportFenceFdKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pImportFenceFdInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImportFenceFdInfo = (VkImportFenceFdInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkImportFenceFdKHR(device, pImportFenceFdInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_direct_mode_display
static Napi::Value rawReleaseDisplayEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (display)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) display = (VkDisplayKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkReleaseDisplayEXT(physicalDevice, display);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_acquire_xlib_display
static Napi::Value rawAcquireXlibDisplayEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (dpy)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dpy = (Display*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (display)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) display = (VkDisplayKHR)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkAcquireXlibDisplayEXT(physicalDevice, dpy, display);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_acquire_xlib_display
static Napi::Value rawGetRandROutputDisplayEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (dpy)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dpy = (Display*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (rrOutput)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) rrOutput = (RROutput)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pDisplay)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDisplay = (VkDisplayKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_acquire_winrt_display
static Napi::Value rawAcquireWinrtDisplayNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (display)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) display = (VkDisplayKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkAcquireWinrtDisplayNV(physicalDevice, display);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_acquire_winrt_display
static Napi::Value rawGetWinrtDisplayNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (deviceRelativeId)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) deviceRelativeId = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pDisplay)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDisplay = (VkDisplayKHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetWinrtDisplayNV(physicalDevice, deviceRelativeId, pDisplay);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_display_control
static Napi::Value rawDisplayPowerControlEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (display)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) display = (VkDisplayKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pDisplayPowerInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDisplayPowerInfo = (VkDisplayPowerInfoEXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkDisplayPowerControlEXT(device, display, pDisplayPowerInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_display_control
static Napi::Value rawRegisterDeviceEventEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pDeviceEventInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDeviceEventInfo = (VkDeviceEventInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pFence)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFence = (VkFence*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_display_control
static Napi::Value rawRegisterDisplayEventEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (display)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) display = (VkDisplayKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pDisplayEventInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDisplayEventInfo = (VkDisplayEventInfoEXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pFence)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFence = (VkFence*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_display_control
static Napi::Value rawGetSwapchainCounterEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (swapchain)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchain = (VkSwapchainKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (counter)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) counter = (VkSurfaceCounterFlagBitsEXT)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCounterValue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCounterValue = (uint64_t*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_display_surface_counter
static Napi::Value rawGetPhysicalDeviceSurfaceCapabilities2EXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (surface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) surface = (VkSurfaceKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSurfaceCapabilities)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurfaceCapabilities = (VkSurfaceCapabilities2EXT*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawEnumeratePhysicalDeviceGroups(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPhysicalDeviceGroupCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPhysicalDeviceGroupCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pPhysicalDeviceGroupProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPhysicalDeviceGroupProperties = (VkPhysicalDeviceGroupProperties*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    return Napi::Number::New(env, result);
}
static Napi::Value rawGetDeviceGroupPeerMemoryFeatures(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (heapIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) heapIndex = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (localDeviceIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) localDeviceIndex = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (remoteDeviceIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) remoteDeviceIndex = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pPeerMemoryFeatures)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPeerMemoryFeatures = (VkPeerMemoryFeatureFlags*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    return env.Null();
}
static Napi::Value rawBindBufferMemory2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (bindInfoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) bindInfoCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pBindInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBindInfos = (VkBindBufferMemoryInfo const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkBindBufferMemory2(device, bindInfoCount, pBindInfos);
    return Napi::Number::New(env, result);
}
static Napi::Value rawBindImageMemory2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (bindInfoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) bindInfoCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pBindInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBindInfos = (VkBindImageMemoryInfo const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkBindImageMemory2(device, bindInfoCount, pBindInfos);
    return Napi::Number::New(env, result);
}
static Napi::Value rawCmdSetDeviceMask(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (deviceMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) deviceMask = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDeviceMask(commandBuffer, deviceMask);
    return env.Null();
}
#ifdef VK_KHR_device_group
static Napi::Value rawGetDeviceGroupPresentCapabilitiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pDeviceGroupPresentCapabilities)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDeviceGroupPresentCapabilities = (VkDeviceGroupPresentCapabilitiesKHR*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_device_group
static Napi::Value rawGetDeviceGroupSurfacePresentModesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (surface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) surface = (VkSurfaceKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pModes)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pModes = (VkDeviceGroupPresentModeFlagsKHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_device_group
static Napi::Value rawAcquireNextImage2KHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pAcquireInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAcquireInfo = (VkAcquireNextImageInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pImageIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImageIndex = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawCmdDispatchBase(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (baseGroupX)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) baseGroupX = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (baseGroupY)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) baseGroupY = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (baseGroupZ)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) baseGroupZ = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (groupCountX)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupCountX = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (groupCountY)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupCountY = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();

    if (!info_[6].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 6 argument (groupCountZ)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupCountZ = (uint32_t)info_[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    return env.Null();
}
#ifdef VK_KHR_device_group
static Napi::Value rawGetPhysicalDevicePresentRectanglesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (surface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) surface = (VkSurfaceKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pRectCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRectCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pRects)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRects = (VkRect2D*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawCreateDescriptorUpdateTemplate(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkDescriptorUpdateTemplateCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pDescriptorUpdateTemplate)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDescriptorUpdateTemplate = (VkDescriptorUpdateTemplate*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyDescriptorUpdateTemplate(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (descriptorUpdateTemplate)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorUpdateTemplate = (VkDescriptorUpdateTemplate)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
    return env.Null();
}
static Napi::Value rawUpdateDescriptorSetWithTemplate(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (descriptorSet)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorSet = (VkDescriptorSet)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (descriptorUpdateTemplate)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorUpdateTemplate = (VkDescriptorUpdateTemplate)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pData = (void const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    return env.Null();
}
#ifdef VK_KHR_descriptor_update_template
static Napi::Value rawCmdPushDescriptorSetWithTemplateKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (descriptorUpdateTemplate)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorUpdateTemplate = (VkDescriptorUpdateTemplate)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (layout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) layout = (VkPipelineLayout)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (set)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) set = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pData = (void const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    return env.Null();
}
#endif
#ifdef VK_EXT_hdr_metadata
static Napi::Value rawSetHdrMetadataEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (swapchainCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchainCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSwapchains)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSwapchains = (VkSwapchainKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pMetadata)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMetadata = (VkHdrMetadataEXT const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
    return env.Null();
}
#endif
#ifdef VK_KHR_shared_presentable_image
static Napi::Value rawGetSwapchainStatusKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (swapchain)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchain = (VkSwapchainKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetSwapchainStatusKHR(device, swapchain);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_GOOGLE_display_timing
static Napi::Value rawGetRefreshCycleDurationGOOGLE(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (swapchain)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchain = (VkSwapchainKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pDisplayTimingProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDisplayTimingProperties = (VkRefreshCycleDurationGOOGLE*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_GOOGLE_display_timing
static Napi::Value rawGetPastPresentationTimingGOOGLE(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (swapchain)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchain = (VkSwapchainKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pPresentationTimingCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPresentationTimingCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pPresentationTimings)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPresentationTimings = (VkPastPresentationTimingGOOGLE*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_MVK_ios_surface
static Napi::Value rawCreateIOSSurfaceMVK(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkIOSSurfaceCreateInfoMVK const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_MVK_macos_surface
static Napi::Value rawCreateMacOSSurfaceMVK(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkMacOSSurfaceCreateInfoMVK const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_metal_surface
static Napi::Value rawCreateMetalSurfaceEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkMetalSurfaceCreateInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateMetalSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_clip_space_w_scaling
static Napi::Value rawCmdSetViewportWScalingNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstViewport)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstViewport = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (viewportCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) viewportCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pViewportWScalings)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pViewportWScalings = (VkViewportWScalingNV const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    return env.Null();
}
#endif
#ifdef VK_EXT_discard_rectangles
static Napi::Value rawCmdSetDiscardRectangleEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstDiscardRectangle)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstDiscardRectangle = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (discardRectangleCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) discardRectangleCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pDiscardRectangles)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDiscardRectangles = (VkRect2D const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    return env.Null();
}
#endif
#ifdef VK_EXT_sample_locations
static Napi::Value rawCmdSetSampleLocationsEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pSampleLocationsInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSampleLocationsInfo = (VkSampleLocationsInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_sample_locations
static Napi::Value rawGetPhysicalDeviceMultisamplePropertiesEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (samples)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) samples = (VkSampleCountFlagBits)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMultisampleProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMultisampleProperties = (VkMultisamplePropertiesEXT*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
    return env.Null();
}
#endif
#ifdef VK_KHR_get_surface_capabilities2
static Napi::Value rawGetPhysicalDeviceSurfaceCapabilities2KHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pSurfaceInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurfaceInfo = (VkPhysicalDeviceSurfaceInfo2KHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSurfaceCapabilities)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurfaceCapabilities = (VkSurfaceCapabilities2KHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_get_surface_capabilities2
static Napi::Value rawGetPhysicalDeviceSurfaceFormats2KHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pSurfaceInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurfaceInfo = (VkPhysicalDeviceSurfaceInfo2KHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSurfaceFormatCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurfaceFormatCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurfaceFormats)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurfaceFormats = (VkSurfaceFormat2KHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_get_display_properties2
static Napi::Value rawGetPhysicalDeviceDisplayProperties2KHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkDisplayProperties2KHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_get_display_properties2
static Napi::Value rawGetPhysicalDeviceDisplayPlaneProperties2KHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkDisplayPlaneProperties2KHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_get_display_properties2
static Napi::Value rawGetDisplayModeProperties2KHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (display)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) display = (VkDisplayKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkDisplayModeProperties2KHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_get_display_properties2
static Napi::Value rawGetDisplayPlaneCapabilities2KHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pDisplayPlaneInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDisplayPlaneInfo = (VkDisplayPlaneInfo2KHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCapabilities)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCapabilities = (VkDisplayPlaneCapabilities2KHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawGetBufferMemoryRequirements2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkBufferMemoryRequirementsInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMemoryRequirements)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryRequirements = (VkMemoryRequirements2*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    return env.Null();
}
static Napi::Value rawGetImageMemoryRequirements2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkImageMemoryRequirementsInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMemoryRequirements)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryRequirements = (VkMemoryRequirements2*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
    return env.Null();
}
static Napi::Value rawGetImageSparseMemoryRequirements2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkImageSparseMemoryRequirementsInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSparseMemoryRequirementCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSparseMemoryRequirementCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSparseMemoryRequirements)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSparseMemoryRequirements = (VkSparseImageMemoryRequirements2*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    return env.Null();
}
static Napi::Value rawGetDeviceBufferMemoryRequirements(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkDeviceBufferMemoryRequirements const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMemoryRequirements)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryRequirements = (VkMemoryRequirements2*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements);
    return env.Null();
}
static Napi::Value rawGetDeviceImageMemoryRequirements(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkDeviceImageMemoryRequirements const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMemoryRequirements)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryRequirements = (VkMemoryRequirements2*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements);
    return env.Null();
}
static Napi::Value rawGetDeviceImageSparseMemoryRequirements(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkDeviceImageMemoryRequirements const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSparseMemoryRequirementCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSparseMemoryRequirementCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSparseMemoryRequirements)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSparseMemoryRequirements = (VkSparseImageMemoryRequirements2*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    return env.Null();
}
static Napi::Value rawCreateSamplerYcbcrConversion(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkSamplerYcbcrConversionCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pYcbcrConversion)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pYcbcrConversion = (VkSamplerYcbcrConversion*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroySamplerYcbcrConversion(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (ycbcrConversion)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ycbcrConversion = (VkSamplerYcbcrConversion)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
    return env.Null();
}
static Napi::Value rawGetDeviceQueue2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pQueueInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pQueueInfo = (VkDeviceQueueInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pQueue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pQueue = (VkQueue*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceQueue2(device, pQueueInfo, pQueue);
    return env.Null();
}
#ifdef VK_EXT_validation_cache
static Napi::Value rawCreateValidationCacheEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkValidationCacheCreateInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pValidationCache)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pValidationCache = (VkValidationCacheEXT*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_validation_cache
static Napi::Value rawDestroyValidationCacheEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (validationCache)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) validationCache = (VkValidationCacheEXT)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyValidationCacheEXT(device, validationCache, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_EXT_validation_cache
static Napi::Value rawGetValidationCacheDataEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (validationCache)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) validationCache = (VkValidationCacheEXT)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pDataSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDataSize = (size_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pData = (void*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_validation_cache
static Napi::Value rawMergeValidationCachesEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (dstCache)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstCache = (VkValidationCacheEXT)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (srcCacheCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) srcCacheCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSrcCaches)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSrcCaches = (VkValidationCacheEXT const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkMergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawGetDescriptorSetLayoutSupport(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkDescriptorSetLayoutCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSupport)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSupport = (VkDescriptorSetLayoutSupport*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
    return env.Null();
}
#ifdef VK_ANDROID_native_buffer
static Napi::Value rawGetSwapchainGrallocUsageANDROID(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (format)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) format = (VkFormat)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (imageUsage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) imageUsage = (VkImageUsageFlags)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (grallocUsage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) grallocUsage = (int*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetSwapchainGrallocUsageANDROID(device, format, imageUsage, grallocUsage);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_ANDROID_native_buffer
static Napi::Value rawGetSwapchainGrallocUsage2ANDROID(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (format)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) format = (VkFormat)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (imageUsage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) imageUsage = (VkImageUsageFlags)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (swapchainImageUsage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchainImageUsage = (VkSwapchainImageUsageFlagsANDROID)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (grallocConsumerUsage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) grallocConsumerUsage = (uint64_t*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (grallocProducerUsage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) grallocProducerUsage = (uint64_t*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetSwapchainGrallocUsage2ANDROID(device, format, imageUsage, swapchainImageUsage, grallocConsumerUsage, grallocProducerUsage);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_ANDROID_native_buffer
static Napi::Value rawAcquireImageANDROID(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (image)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) image = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (nativeFenceFd)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) nativeFenceFd = (int)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (semaphore)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) semaphore = (VkSemaphore)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (fence)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) fence = (VkFence)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkAcquireImageANDROID(device, image, nativeFenceFd, semaphore, fence);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_ANDROID_native_buffer
static Napi::Value rawQueueSignalReleaseImageANDROID(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (queue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queue = (VkQueue)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (waitSemaphoreCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) waitSemaphoreCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pWaitSemaphores)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pWaitSemaphores = (VkSemaphore const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (image)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) image = (VkImage)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pNativeFenceFd)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pNativeFenceFd = (int*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkQueueSignalReleaseImageANDROID(queue, waitSemaphoreCount, pWaitSemaphores, image, pNativeFenceFd);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_AMD_shader_info
static Napi::Value rawGetShaderInfoAMD(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipeline)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipeline = (VkPipeline)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (shaderStage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) shaderStage = (VkShaderStageFlagBits)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (infoType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) infoType = (VkShaderInfoTypeAMD)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pInfoSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfoSize = (size_t*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (void*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_AMD_display_native_hdr
static Napi::Value rawSetLocalDimmingAMD(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (swapChain)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapChain = (VkSwapchainKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (localDimmingEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) localDimmingEnable = (VkBool32)info_[2].As<Napi::Number>().Uint32Value();
    
    ::vkSetLocalDimmingAMD(device, swapChain, localDimmingEnable);
    return env.Null();
}
#endif
#ifdef VK_EXT_calibrated_timestamps
static Napi::Value rawGetPhysicalDeviceCalibrateableTimeDomainsEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pTimeDomainCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pTimeDomainCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pTimeDomains)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pTimeDomains = (VkTimeDomainEXT*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_calibrated_timestamps
static Napi::Value rawGetCalibratedTimestampsEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (timestampCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) timestampCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pTimestampInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pTimestampInfos = (VkCalibratedTimestampInfoEXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pTimestamps)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pTimestamps = (uint64_t*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pMaxDeviation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMaxDeviation = (uint64_t*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_debug_utils
static Napi::Value rawSetDebugUtilsObjectNameEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pNameInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pNameInfo = (VkDebugUtilsObjectNameInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkSetDebugUtilsObjectNameEXT(device, pNameInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_debug_utils
static Napi::Value rawSetDebugUtilsObjectTagEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pTagInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pTagInfo = (VkDebugUtilsObjectTagInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkSetDebugUtilsObjectTagEXT(device, pTagInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_debug_utils
static Napi::Value rawQueueBeginDebugUtilsLabelEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (queue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queue = (VkQueue)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pLabelInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pLabelInfo = (VkDebugUtilsLabelEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_debug_utils
static Napi::Value rawQueueEndDebugUtilsLabelEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (queue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queue = (VkQueue)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkQueueEndDebugUtilsLabelEXT(queue);
    return env.Null();
}
#endif
#ifdef VK_EXT_debug_utils
static Napi::Value rawQueueInsertDebugUtilsLabelEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (queue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queue = (VkQueue)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pLabelInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pLabelInfo = (VkDebugUtilsLabelEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_debug_utils
static Napi::Value rawCmdBeginDebugUtilsLabelEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pLabelInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pLabelInfo = (VkDebugUtilsLabelEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_debug_utils
static Napi::Value rawCmdEndDebugUtilsLabelEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndDebugUtilsLabelEXT(commandBuffer);
    return env.Null();
}
#endif
#ifdef VK_EXT_debug_utils
static Napi::Value rawCmdInsertDebugUtilsLabelEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pLabelInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pLabelInfo = (VkDebugUtilsLabelEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_debug_utils
static Napi::Value rawCreateDebugUtilsMessengerEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkDebugUtilsMessengerCreateInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pMessenger)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMessenger = (VkDebugUtilsMessengerEXT*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_debug_utils
static Napi::Value rawDestroyDebugUtilsMessengerEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (messenger)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) messenger = (VkDebugUtilsMessengerEXT)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_EXT_debug_utils
static Napi::Value rawSubmitDebugUtilsMessageEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (messageSeverity)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) messageSeverity = (VkDebugUtilsMessageSeverityFlagBitsEXT)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (messageTypes)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) messageTypes = (VkDebugUtilsMessageTypeFlagsEXT)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCallbackData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCallbackData = (VkDebugUtilsMessengerCallbackDataEXT const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    return env.Null();
}
#endif
#ifdef VK_EXT_external_memory_host
static Napi::Value rawGetMemoryHostPointerPropertiesEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (handleType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) handleType = (VkExternalMemoryHandleTypeFlagBits)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pHostPointer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pHostPointer = (void const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pMemoryHostPointerProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryHostPointerProperties = (VkMemoryHostPointerPropertiesEXT*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_AMD_buffer_marker
static Napi::Value rawCmdWriteBufferMarkerAMD(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipelineStage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineStage = (VkPipelineStageFlagBits)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (dstBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstBuffer = (VkBuffer)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (dstOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstOffset = (VkDeviceSize)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (marker)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) marker = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    return env.Null();
}
#endif
static Napi::Value rawCreateRenderPass2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkRenderPassCreateInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pRenderPass)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRenderPass = (VkRenderPass*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    return Napi::Number::New(env, result);
}
static Napi::Value rawCmdBeginRenderPass2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pRenderPassBegin)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRenderPassBegin = (VkRenderPassBeginInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSubpassBeginInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSubpassBeginInfo = (VkSubpassBeginInfo const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    return env.Null();
}
static Napi::Value rawCmdNextSubpass2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pSubpassBeginInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSubpassBeginInfo = (VkSubpassBeginInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSubpassEndInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSubpassEndInfo = (VkSubpassEndInfo const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    return env.Null();
}
static Napi::Value rawCmdEndRenderPass2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pSubpassEndInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSubpassEndInfo = (VkSubpassEndInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    return env.Null();
}
static Napi::Value rawGetSemaphoreCounterValue(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (semaphore)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) semaphore = (VkSemaphore)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pValue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pValue = (uint64_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetSemaphoreCounterValue(device, semaphore, pValue);
    return Napi::Number::New(env, result);
}
static Napi::Value rawWaitSemaphores(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pWaitInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pWaitInfo = (VkSemaphoreWaitInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (timeout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) timeout = (uint64_t)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkWaitSemaphores(device, pWaitInfo, timeout);
    return Napi::Number::New(env, result);
}
static Napi::Value rawSignalSemaphore(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pSignalInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSignalInfo = (VkSemaphoreSignalInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkSignalSemaphore(device, pSignalInfo);
    return Napi::Number::New(env, result);
}
#ifdef VK_ANDROID_external_memory_android_hardware_buffer
static Napi::Value rawGetAndroidHardwareBufferPropertiesANDROID(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (AHardwareBuffer const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkAndroidHardwareBufferPropertiesANDROID*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_ANDROID_external_memory_android_hardware_buffer
static Napi::Value rawGetMemoryAndroidHardwareBufferANDROID(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkMemoryGetAndroidHardwareBufferInfoANDROID const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer of pointers) at 2 argument (pBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBuffer = (AHardwareBuffer**)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawCmdDrawIndirectCount(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (offset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) offset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (countBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) countBuffer = (VkBuffer)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (countBufferOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) countBufferOffset = (VkDeviceSize)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (maxDrawCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) maxDrawCount = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();

    if (!info_[6].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 6 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return env.Null();
}
static Napi::Value rawCmdDrawIndexedIndirectCount(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (offset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) offset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (countBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) countBuffer = (VkBuffer)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (countBufferOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) countBufferOffset = (VkDeviceSize)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (maxDrawCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) maxDrawCount = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();

    if (!info_[6].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 6 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return env.Null();
}
#ifdef VK_NV_device_diagnostic_checkpoints
static Napi::Value rawCmdSetCheckpointNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCheckpointMarker)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCheckpointMarker = (void const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
    return env.Null();
}
#endif
#ifdef VK_NV_device_diagnostic_checkpoints
static Napi::Value rawGetQueueCheckpointDataNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (queue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queue = (VkQueue)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCheckpointDataCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCheckpointDataCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCheckpointData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCheckpointData = (VkCheckpointDataNV*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
    return env.Null();
}
#endif
#ifdef VK_EXT_transform_feedback
static Napi::Value rawCmdBindTransformFeedbackBuffersEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstBinding)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstBinding = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (bindingCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) bindingCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pBuffers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBuffers = (VkBuffer const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pOffsets)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pOffsets = (VkDeviceSize const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pSizes)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSizes = (VkDeviceSize const*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
    return env.Null();
}
#endif
#ifdef VK_EXT_transform_feedback
static Napi::Value rawCmdBeginTransformFeedbackEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstCounterBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstCounterBuffer = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (counterBufferCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) counterBufferCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCounterBuffers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCounterBuffers = (VkBuffer const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pCounterBufferOffsets)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCounterBufferOffsets = (VkDeviceSize const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    return env.Null();
}
#endif
#ifdef VK_EXT_transform_feedback
static Napi::Value rawCmdEndTransformFeedbackEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstCounterBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstCounterBuffer = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (counterBufferCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) counterBufferCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCounterBuffers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCounterBuffers = (VkBuffer const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pCounterBufferOffsets)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCounterBufferOffsets = (VkDeviceSize const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    return env.Null();
}
#endif
#ifdef VK_EXT_transform_feedback
static Napi::Value rawCmdBeginQueryIndexedEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (query)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) query = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (flags)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) flags = (VkQueryControlFlags)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (index)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) index = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
    return env.Null();
}
#endif
#ifdef VK_EXT_transform_feedback
static Napi::Value rawCmdEndQueryIndexedEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (query)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) query = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (index)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) index = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
    return env.Null();
}
#endif
#ifdef VK_EXT_transform_feedback
static Napi::Value rawCmdDrawIndirectByteCountEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (instanceCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instanceCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (firstInstance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstInstance = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (counterBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) counterBuffer = (VkBuffer)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (counterBufferOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) counterBufferOffset = (VkDeviceSize)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (counterOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) counterOffset = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();

    if (!info_[6].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 6 argument (vertexStride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) vertexStride = (uint32_t)info_[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    return env.Null();
}
#endif
#ifdef VK_NV_scissor_exclusive
static Napi::Value rawCmdSetExclusiveScissorNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstExclusiveScissor)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstExclusiveScissor = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (exclusiveScissorCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) exclusiveScissorCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pExclusiveScissors)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pExclusiveScissors = (VkRect2D const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
    return env.Null();
}
#endif
#ifdef VK_NV_shading_rate_image
static Napi::Value rawCmdBindShadingRateImageNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (imageView)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) imageView = (VkImageView)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (imageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) imageLayout = (VkImageLayout)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
    return env.Null();
}
#endif
#ifdef VK_NV_shading_rate_image
static Napi::Value rawCmdSetViewportShadingRatePaletteNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstViewport)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstViewport = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (viewportCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) viewportCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pShadingRatePalettes)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pShadingRatePalettes = (VkShadingRatePaletteNV const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
    return env.Null();
}
#endif
#ifdef VK_NV_shading_rate_image
static Napi::Value rawCmdSetCoarseSampleOrderNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (sampleOrderType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) sampleOrderType = (VkCoarseSampleOrderTypeNV)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (customSampleOrderCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) customSampleOrderCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCustomSampleOrders)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCustomSampleOrders = (VkCoarseSampleOrderCustomNV const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
    return env.Null();
}
#endif
#ifdef VK_NV_mesh_shader
static Napi::Value rawCmdDrawMeshTasksNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (taskCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) taskCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (firstTask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstTask = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    return env.Null();
}
#endif
#ifdef VK_NV_mesh_shader
static Napi::Value rawCmdDrawMeshTasksIndirectNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (offset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) offset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (drawCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) drawCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    return env.Null();
}
#endif
#ifdef VK_NV_mesh_shader
static Napi::Value rawCmdDrawMeshTasksIndirectCountNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (offset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) offset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (countBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) countBuffer = (VkBuffer)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (countBufferOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) countBufferOffset = (VkDeviceSize)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (maxDrawCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) maxDrawCount = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();

    if (!info_[6].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 6 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return env.Null();
}
#endif
#ifdef VK_EXT_mesh_shader
static Napi::Value rawCmdDrawMeshTasksEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (groupCountX)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupCountX = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (groupCountY)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupCountY = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (groupCountZ)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupCountZ = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
    return env.Null();
}
#endif
#ifdef VK_EXT_mesh_shader
static Napi::Value rawCmdDrawMeshTasksIndirectEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (offset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) offset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (drawCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) drawCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
    return env.Null();
}
#endif
#ifdef VK_EXT_mesh_shader
static Napi::Value rawCmdDrawMeshTasksIndirectCountEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (offset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) offset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (countBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) countBuffer = (VkBuffer)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (countBufferOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) countBufferOffset = (VkDeviceSize)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (maxDrawCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) maxDrawCount = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();

    if (!info_[6].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 6 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return env.Null();
}
#endif
#ifdef VK_NV_ray_tracing
static Napi::Value rawCompileDeferredNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipeline)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipeline = (VkPipeline)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (shader)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) shader = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();
    
    decltype(auto) result = ::vkCompileDeferredNV(device, pipeline, shader);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_ray_tracing
static Napi::Value rawCreateAccelerationStructureNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkAccelerationStructureCreateInfoNV const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pAccelerationStructure)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAccelerationStructure = (VkAccelerationStructureNV*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_HUAWEI_invocation_mask
static Napi::Value rawCmdBindInvocationMaskHUAWEI(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (imageView)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) imageView = (VkImageView)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (imageLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) imageLayout = (VkImageLayout)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
    return env.Null();
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawDestroyAccelerationStructureKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (accelerationStructure)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) accelerationStructure = (VkAccelerationStructureKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyAccelerationStructureKHR(device, accelerationStructure, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_NV_ray_tracing
static Napi::Value rawDestroyAccelerationStructureNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (accelerationStructure)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) accelerationStructure = (VkAccelerationStructureNV)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_NV_ray_tracing
static Napi::Value rawGetAccelerationStructureMemoryRequirementsNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkAccelerationStructureMemoryRequirementsInfoNV const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMemoryRequirements)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryRequirements = (VkMemoryRequirements2KHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
    return env.Null();
}
#endif
#ifdef VK_NV_ray_tracing
static Napi::Value rawBindAccelerationStructureMemoryNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (bindInfoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) bindInfoCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pBindInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBindInfos = (VkBindAccelerationStructureMemoryInfoNV const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkBindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_ray_tracing
static Napi::Value rawCmdCopyAccelerationStructureNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (dst)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dst = (VkAccelerationStructureNV)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (src)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) src = (VkAccelerationStructureNV)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (mode)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) mode = (VkCopyAccelerationStructureModeKHR)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
    return env.Null();
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCmdCopyAccelerationStructureKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkCopyAccelerationStructureInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
    return env.Null();
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCopyAccelerationStructureKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (deferredOperation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) deferredOperation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkCopyAccelerationStructureInfoKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCopyAccelerationStructureKHR(device, deferredOperation, pInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCmdCopyAccelerationStructureToMemoryKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkCopyAccelerationStructureToMemoryInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
    return env.Null();
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCopyAccelerationStructureToMemoryKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (deferredOperation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) deferredOperation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkCopyAccelerationStructureToMemoryInfoKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCopyAccelerationStructureToMemoryKHR(device, deferredOperation, pInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCmdCopyMemoryToAccelerationStructureKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkCopyMemoryToAccelerationStructureInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
    return env.Null();
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCopyMemoryToAccelerationStructureKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (deferredOperation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) deferredOperation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkCopyMemoryToAccelerationStructureInfoKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCopyMemoryToAccelerationStructureKHR(device, deferredOperation, pInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCmdWriteAccelerationStructuresPropertiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (accelerationStructureCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) accelerationStructureCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAccelerationStructures)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAccelerationStructures = (VkAccelerationStructureKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (queryType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryType = (VkQueryType)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (firstQuery)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstQuery = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    return env.Null();
}
#endif
#ifdef VK_NV_ray_tracing
static Napi::Value rawCmdWriteAccelerationStructuresPropertiesNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (accelerationStructureCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) accelerationStructureCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAccelerationStructures)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAccelerationStructures = (VkAccelerationStructureNV const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (queryType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryType = (VkQueryType)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (firstQuery)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstQuery = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    return env.Null();
}
#endif
#ifdef VK_NV_ray_tracing
static Napi::Value rawCmdBuildAccelerationStructureNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 9) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkAccelerationStructureInfoNV const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (instanceData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instanceData = (VkBuffer)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (instanceOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instanceOffset = (VkDeviceSize)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (update)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) update = (VkBool32)info_[4].As<Napi::Number>().Uint32Value();

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 5 argument (dst)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dst = (VkAccelerationStructureNV)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 6 argument (src)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) src = (VkAccelerationStructureNV)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[7].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 7 argument (scratch)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) scratch = (VkBuffer)info_[7].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[8].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 8 argument (scratchOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) scratchOffset = (VkDeviceSize)info_[8].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
    return env.Null();
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawWriteAccelerationStructuresPropertiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (accelerationStructureCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) accelerationStructureCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAccelerationStructures)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAccelerationStructures = (VkAccelerationStructureKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (queryType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryType = (VkQueryType)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (dataSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dataSize = (size_t)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pData = (void*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 6 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (size_t)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkWriteAccelerationStructuresPropertiesKHR(device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawCmdTraceRaysKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pRaygenShaderBindingTable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRaygenShaderBindingTable = (VkStridedDeviceAddressRegionKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMissShaderBindingTable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMissShaderBindingTable = (VkStridedDeviceAddressRegionKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pHitShaderBindingTable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pHitShaderBindingTable = (VkStridedDeviceAddressRegionKHR const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pCallableShaderBindingTable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCallableShaderBindingTable = (VkStridedDeviceAddressRegionKHR const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (width)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) width = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();

    if (!info_[6].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 6 argument (height)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) height = (uint32_t)info_[6].As<Napi::Number>().Uint32Value();

    if (!info_[7].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 7 argument (depth)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depth = (uint32_t)info_[7].As<Napi::Number>().Uint32Value();
    
    ::vkCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    return env.Null();
}
#endif
#ifdef VK_NV_ray_tracing
static Napi::Value rawCmdTraceRaysNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 15) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (raygenShaderBindingTableBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) raygenShaderBindingTableBuffer = (VkBuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (raygenShaderBindingOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) raygenShaderBindingOffset = (VkDeviceSize)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (missShaderBindingTableBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) missShaderBindingTableBuffer = (VkBuffer)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (missShaderBindingOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) missShaderBindingOffset = (VkDeviceSize)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 5 argument (missShaderBindingStride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) missShaderBindingStride = (VkDeviceSize)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 6 argument (hitShaderBindingTableBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) hitShaderBindingTableBuffer = (VkBuffer)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[7].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 7 argument (hitShaderBindingOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) hitShaderBindingOffset = (VkDeviceSize)info_[7].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[8].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 8 argument (hitShaderBindingStride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) hitShaderBindingStride = (VkDeviceSize)info_[8].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[9].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 9 argument (callableShaderBindingTableBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) callableShaderBindingTableBuffer = (VkBuffer)info_[9].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[10].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 10 argument (callableShaderBindingOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) callableShaderBindingOffset = (VkDeviceSize)info_[10].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[11].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 11 argument (callableShaderBindingStride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) callableShaderBindingStride = (VkDeviceSize)info_[11].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[12].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 12 argument (width)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) width = (uint32_t)info_[12].As<Napi::Number>().Uint32Value();

    if (!info_[13].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 13 argument (height)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) height = (uint32_t)info_[13].As<Napi::Number>().Uint32Value();

    if (!info_[14].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 14 argument (depth)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depth = (uint32_t)info_[14].As<Napi::Number>().Uint32Value();
    
    ::vkCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
    return env.Null();
}
#endif
#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawGetRayTracingShaderGroupHandlesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipeline)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipeline = (VkPipeline)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (firstGroup)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstGroup = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (groupCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (dataSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dataSize = (size_t)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pData = (void*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetRayTracingShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawGetRayTracingCaptureReplayShaderGroupHandlesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipeline)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipeline = (VkPipeline)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (firstGroup)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstGroup = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (groupCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (dataSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dataSize = (size_t)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pData = (void*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_ray_tracing
static Napi::Value rawGetAccelerationStructureHandleNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (accelerationStructure)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) accelerationStructure = (VkAccelerationStructureNV)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (dataSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dataSize = (size_t)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pData = (void*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_ray_tracing
static Napi::Value rawCreateRayTracingPipelinesNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipelineCache)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineCache = (VkPipelineCache)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (createInfoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) createInfoCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCreateInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfos = (VkRayTracingPipelineCreateInfoNV const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pPipelines)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPipelines = (VkPipeline*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawCreateRayTracingPipelinesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (deferredOperation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) deferredOperation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (pipelineCache)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineCache = (VkPipelineCache)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (createInfoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) createInfoCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pCreateInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfos = (VkRayTracingPipelineCreateInfoKHR const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 6 argument (pPipelines)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPipelines = (VkPipeline*)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_cooperative_matrix
static Napi::Value rawGetPhysicalDeviceCooperativeMatrixPropertiesNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertyCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkCooperativeMatrixPropertiesNV*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawCmdTraceRaysIndirectKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pRaygenShaderBindingTable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRaygenShaderBindingTable = (VkStridedDeviceAddressRegionKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMissShaderBindingTable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMissShaderBindingTable = (VkStridedDeviceAddressRegionKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pHitShaderBindingTable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pHitShaderBindingTable = (VkStridedDeviceAddressRegionKHR const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pCallableShaderBindingTable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCallableShaderBindingTable = (VkStridedDeviceAddressRegionKHR const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 5 argument (indirectDeviceAddress)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) indirectDeviceAddress = (VkDeviceAddress)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
    return env.Null();
}
#endif
#ifdef VK_KHR_ray_tracing_maintenance1
static Napi::Value rawCmdTraceRaysIndirect2KHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (indirectDeviceAddress)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) indirectDeviceAddress = (VkDeviceAddress)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
    return env.Null();
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawGetDeviceAccelerationStructureCompatibilityKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pVersionInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pVersionInfo = (VkAccelerationStructureVersionInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCompatibility)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCompatibility = (VkAccelerationStructureCompatibilityKHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceAccelerationStructureCompatibilityKHR(device, pVersionInfo, pCompatibility);
    return env.Null();
}
#endif
#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawGetRayTracingShaderGroupStackSizeKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (pipeline)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipeline = (VkPipeline)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (group)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) group = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (groupShader)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) groupShader = (VkShaderGroupShaderKHR)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetRayTracingShaderGroupStackSizeKHR(device, pipeline, group, groupShader);
    return Napi::BigInt::New(env, (uint64_t)result);
}
#endif
#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawCmdSetRayTracingPipelineStackSizeKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (pipelineStackSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pipelineStackSize = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
    return env.Null();
}
#endif
#ifdef VK_NVX_image_view_handle
static Napi::Value rawGetImageViewHandleNVX(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkImageViewHandleInfoNVX const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetImageViewHandleNVX(device, pInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NVX_image_view_handle
static Napi::Value rawGetImageViewAddressNVX(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (imageView)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) imageView = (VkImageView)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkImageViewAddressPropertiesNVX*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetImageViewAddressNVX(device, imageView, pProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_full_screen_exclusive
static Napi::Value rawGetPhysicalDeviceSurfacePresentModes2EXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pSurfaceInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurfaceInfo = (VkPhysicalDeviceSurfaceInfo2KHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pPresentModeCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPresentModeCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pPresentModes)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPresentModes = (VkPresentModeKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_full_screen_exclusive
static Napi::Value rawGetDeviceGroupSurfacePresentModes2EXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pSurfaceInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurfaceInfo = (VkPhysicalDeviceSurfaceInfo2KHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pModes)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pModes = (VkDeviceGroupPresentModeFlagsKHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_full_screen_exclusive
static Napi::Value rawAcquireFullScreenExclusiveModeEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (swapchain)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchain = (VkSwapchainKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkAcquireFullScreenExclusiveModeEXT(device, swapchain);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_full_screen_exclusive
static Napi::Value rawReleaseFullScreenExclusiveModeEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (swapchain)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchain = (VkSwapchainKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkReleaseFullScreenExclusiveModeEXT(device, swapchain);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_performance_query
static Napi::Value rawEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (queueFamilyIndex)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queueFamilyIndex = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCounterCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCounterCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCounters)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCounters = (VkPerformanceCounterKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pCounterDescriptions)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCounterDescriptions = (VkPerformanceCounterDescriptionKHR*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_performance_query
static Napi::Value rawGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPerformanceQueryCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPerformanceQueryCreateInfo = (VkQueryPoolPerformanceCreateInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pNumPasses)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pNumPasses = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
    return env.Null();
}
#endif
#ifdef VK_KHR_performance_query
static Napi::Value rawAcquireProfilingLockKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkAcquireProfilingLockInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkAcquireProfilingLockKHR(device, pInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_performance_query
static Napi::Value rawReleaseProfilingLockKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkReleaseProfilingLockKHR(device);
    return env.Null();
}
#endif
#ifdef VK_EXT_image_drm_format_modifier
static Napi::Value rawGetImageDrmFormatModifierPropertiesEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (image)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) image = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkImageDrmFormatModifierPropertiesEXT*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawGetBufferOpaqueCaptureAddress(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkBufferDeviceAddressInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetBufferOpaqueCaptureAddress(device, pInfo);
    return Napi::BigInt::New(env, (uint64_t)result);
}
static Napi::Value rawGetBufferDeviceAddress(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkBufferDeviceAddressInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetBufferDeviceAddress(device, pInfo);
    return Napi::BigInt::New(env, (uint64_t)result);
}
#ifdef VK_EXT_headless_surface
static Napi::Value rawCreateHeadlessSurfaceEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (instance)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) instance = (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkHeadlessSurfaceCreateInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSurface)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSurface = (VkSurfaceKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_coverage_reduction_mode
static Napi::Value rawGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCombinationCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCombinationCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCombinations)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCombinations = (VkFramebufferMixedSamplesCombinationNV*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, pCombinationCount, pCombinations);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_INTEL_performance_query
static Napi::Value rawInitializePerformanceApiINTEL(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInitializeInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInitializeInfo = (VkInitializePerformanceApiInfoINTEL const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkInitializePerformanceApiINTEL(device, pInitializeInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_INTEL_performance_query
static Napi::Value rawUninitializePerformanceApiINTEL(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkUninitializePerformanceApiINTEL(device);
    return env.Null();
}
#endif
#ifdef VK_INTEL_performance_query
static Napi::Value rawCmdSetPerformanceMarkerINTEL(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pMarkerInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMarkerInfo = (VkPerformanceMarkerInfoINTEL const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_INTEL_performance_query
static Napi::Value rawCmdSetPerformanceStreamMarkerINTEL(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pMarkerInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMarkerInfo = (VkPerformanceStreamMarkerInfoINTEL const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_INTEL_performance_query
static Napi::Value rawCmdSetPerformanceOverrideINTEL(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pOverrideInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pOverrideInfo = (VkPerformanceOverrideInfoINTEL const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_INTEL_performance_query
static Napi::Value rawAcquirePerformanceConfigurationINTEL(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pAcquireInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAcquireInfo = (VkPerformanceConfigurationAcquireInfoINTEL const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pConfiguration)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pConfiguration = (VkPerformanceConfigurationINTEL*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkAcquirePerformanceConfigurationINTEL(device, pAcquireInfo, pConfiguration);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_INTEL_performance_query
static Napi::Value rawReleasePerformanceConfigurationINTEL(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (configuration)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) configuration = (VkPerformanceConfigurationINTEL)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkReleasePerformanceConfigurationINTEL(device, configuration);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_INTEL_performance_query
static Napi::Value rawQueueSetPerformanceConfigurationINTEL(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (queue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queue = (VkQueue)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (configuration)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) configuration = (VkPerformanceConfigurationINTEL)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkQueueSetPerformanceConfigurationINTEL(queue, configuration);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_INTEL_performance_query
static Napi::Value rawGetPerformanceParameterINTEL(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (parameter)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) parameter = (VkPerformanceParameterTypeINTEL)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pValue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pValue = (VkPerformanceValueINTEL*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPerformanceParameterINTEL(device, parameter, pValue);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawGetDeviceMemoryOpaqueCaptureAddress(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkDeviceMemoryOpaqueCaptureAddressInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
    return Napi::BigInt::New(env, (uint64_t)result);
}
#ifdef VK_KHR_pipeline_executable_properties
static Napi::Value rawGetPipelineExecutablePropertiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPipelineInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPipelineInfo = (VkPipelineInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pExecutableCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pExecutableCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkPipelineExecutablePropertiesKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPipelineExecutablePropertiesKHR(device, pPipelineInfo, pExecutableCount, pProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_pipeline_executable_properties
static Napi::Value rawGetPipelineExecutableStatisticsKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pExecutableInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pExecutableInfo = (VkPipelineExecutableInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pStatisticCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pStatisticCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pStatistics)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pStatistics = (VkPipelineExecutableStatisticKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, pStatisticCount, pStatistics);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_pipeline_executable_properties
static Napi::Value rawGetPipelineExecutableInternalRepresentationsKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pExecutableInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pExecutableInfo = (VkPipelineExecutableInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pInternalRepresentationCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInternalRepresentationCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pInternalRepresentations)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInternalRepresentations = (VkPipelineExecutableInternalRepresentationKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_line_rasterization
static Napi::Value rawCmdSetLineStippleEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (lineStippleFactor)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) lineStippleFactor = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (lineStipplePattern)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) lineStipplePattern = (uint16_t)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    return env.Null();
}
#endif
static Napi::Value rawGetPhysicalDeviceToolProperties(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pToolCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pToolCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pToolProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pToolProperties = (VkPhysicalDeviceToolProperties*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties);
    return Napi::Number::New(env, result);
}
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCreateAccelerationStructureKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkAccelerationStructureCreateInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pAccelerationStructure)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAccelerationStructure = (VkAccelerationStructureKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateAccelerationStructureKHR(device, pCreateInfo, pAllocator, pAccelerationStructure);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCmdBuildAccelerationStructuresKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (infoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) infoCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfos = (VkAccelerationStructureBuildGeometryInfoKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer of pointers) at 3 argument (ppBuildRangeInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ppBuildRangeInfos = (VkAccelerationStructureBuildRangeInfoKHR* const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    return env.Null();
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCmdBuildAccelerationStructuresIndirectKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (infoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) infoCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfos = (VkAccelerationStructureBuildGeometryInfoKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pIndirectDeviceAddresses)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pIndirectDeviceAddresses = (VkDeviceAddress const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pIndirectStrides)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pIndirectStrides = (uint32_t const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer of pointers) at 5 argument (ppMaxPrimitiveCounts)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ppMaxPrimitiveCounts = (uint32_t* const*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
    return env.Null();
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawBuildAccelerationStructuresKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (deferredOperation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) deferredOperation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (infoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) infoCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfos = (VkAccelerationStructureBuildGeometryInfoKHR const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer of pointers) at 4 argument (ppBuildRangeInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ppBuildRangeInfos = (VkAccelerationStructureBuildRangeInfoKHR* const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkBuildAccelerationStructuresKHR(device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawGetAccelerationStructureDeviceAddressKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkAccelerationStructureDeviceAddressInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetAccelerationStructureDeviceAddressKHR(device, pInfo);
    return Napi::BigInt::New(env, (uint64_t)result);
}
#endif
#ifdef VK_KHR_deferred_host_operations
static Napi::Value rawCreateDeferredOperationKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pDeferredOperation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDeferredOperation = (VkDeferredOperationKHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateDeferredOperationKHR(device, pAllocator, pDeferredOperation);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_deferred_host_operations
static Napi::Value rawDestroyDeferredOperationKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (operation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) operation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDeferredOperationKHR(device, operation, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_KHR_deferred_host_operations
static Napi::Value rawGetDeferredOperationMaxConcurrencyKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (operation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) operation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDeferredOperationMaxConcurrencyKHR(device, operation);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_deferred_host_operations
static Napi::Value rawGetDeferredOperationResultKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (operation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) operation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDeferredOperationResultKHR(device, operation);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_deferred_host_operations
static Napi::Value rawDeferredOperationJoinKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (operation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) operation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkDeferredOperationJoinKHR(device, operation);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawCmdSetCullMode(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (cullMode)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) cullMode = (VkCullModeFlags)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetCullMode(commandBuffer, cullMode);
    return env.Null();
}
static Napi::Value rawCmdSetFrontFace(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (frontFace)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) frontFace = (VkFrontFace)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetFrontFace(commandBuffer, frontFace);
    return env.Null();
}
static Napi::Value rawCmdSetPrimitiveTopology(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (primitiveTopology)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) primitiveTopology = (VkPrimitiveTopology)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    return env.Null();
}
static Napi::Value rawCmdSetViewportWithCount(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (viewportCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) viewportCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pViewports)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pViewports = (VkViewport const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    return env.Null();
}
static Napi::Value rawCmdSetScissorWithCount(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (scissorCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) scissorCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pScissors)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pScissors = (VkRect2D const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    return env.Null();
}
static Napi::Value rawCmdBindVertexBuffers2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstBinding)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstBinding = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (bindingCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) bindingCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pBuffers)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBuffers = (VkBuffer const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pOffsets)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pOffsets = (VkDeviceSize const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pSizes)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSizes = (VkDeviceSize const*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 6 argument (pStrides)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pStrides = (VkDeviceSize const*)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    return env.Null();
}
static Napi::Value rawCmdSetDepthTestEnable(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (depthTestEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depthTestEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    return env.Null();
}
static Napi::Value rawCmdSetDepthWriteEnable(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (depthWriteEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depthWriteEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    return env.Null();
}
static Napi::Value rawCmdSetDepthCompareOp(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (depthCompareOp)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depthCompareOp = (VkCompareOp)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    return env.Null();
}
static Napi::Value rawCmdSetDepthBoundsTestEnable(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (depthBoundsTestEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depthBoundsTestEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    return env.Null();
}
static Napi::Value rawCmdSetStencilTestEnable(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (stencilTestEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stencilTestEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    return env.Null();
}
static Napi::Value rawCmdSetStencilOp(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (faceMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) faceMask = (VkStencilFaceFlags)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (failOp)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) failOp = (VkStencilOp)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (passOp)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) passOp = (VkStencilOp)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (depthFailOp)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depthFailOp = (VkStencilOp)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 5 argument (compareOp)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) compareOp = (VkCompareOp)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    return env.Null();
}
#ifdef VK_EXT_extended_dynamic_state2
static Napi::Value rawCmdSetPatchControlPointsEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (patchControlPoints)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) patchControlPoints = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
    return env.Null();
}
#endif
static Napi::Value rawCmdSetRasterizerDiscardEnable(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (rasterizerDiscardEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) rasterizerDiscardEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    return env.Null();
}
static Napi::Value rawCmdSetDepthBiasEnable(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (depthBiasEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depthBiasEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    return env.Null();
}
#ifdef VK_EXT_extended_dynamic_state2
static Napi::Value rawCmdSetLogicOpEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (logicOp)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) logicOp = (VkLogicOp)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetLogicOpEXT(commandBuffer, logicOp);
    return env.Null();
}
#endif
static Napi::Value rawCmdSetPrimitiveRestartEnable(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (primitiveRestartEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) primitiveRestartEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    return env.Null();
}
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetTessellationDomainOriginEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (domainOrigin)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) domainOrigin = (VkTessellationDomainOrigin)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetDepthClampEnableEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (depthClampEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depthClampEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetPolygonModeEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (polygonMode)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) polygonMode = (VkPolygonMode)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetPolygonModeEXT(commandBuffer, polygonMode);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetRasterizationSamplesEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (rasterizationSamples)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) rasterizationSamples = (VkSampleCountFlagBits)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetSampleMaskEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (samples)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) samples = (VkSampleCountFlagBits)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSampleMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSampleMask = (VkSampleMask const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetAlphaToCoverageEnableEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (alphaToCoverageEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) alphaToCoverageEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetAlphaToOneEnableEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (alphaToOneEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) alphaToOneEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetLogicOpEnableEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (logicOpEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) logicOpEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetColorBlendEnableEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstAttachment)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstAttachment = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (attachmentCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) attachmentCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pColorBlendEnables)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pColorBlendEnables = (VkBool32 const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetColorBlendEquationEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstAttachment)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstAttachment = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (attachmentCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) attachmentCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pColorBlendEquations)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pColorBlendEquations = (VkColorBlendEquationEXT const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetColorWriteMaskEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstAttachment)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstAttachment = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (attachmentCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) attachmentCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pColorWriteMasks)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pColorWriteMasks = (VkColorComponentFlags const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetRasterizationStreamEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (rasterizationStream)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) rasterizationStream = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetConservativeRasterizationModeEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (conservativeRasterizationMode)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) conservativeRasterizationMode = (VkConservativeRasterizationModeEXT)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetExtraPrimitiveOverestimationSizeEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (extraPrimitiveOverestimationSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) extraPrimitiveOverestimationSize = (float)info_[1].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetDepthClipEnableEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (depthClipEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) depthClipEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetSampleLocationsEnableEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (sampleLocationsEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) sampleLocationsEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetColorBlendAdvancedEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstAttachment)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstAttachment = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (attachmentCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) attachmentCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pColorBlendAdvanced)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pColorBlendAdvanced = (VkColorBlendAdvancedEXT const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetProvokingVertexModeEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (provokingVertexMode)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) provokingVertexMode = (VkProvokingVertexModeEXT)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetLineRasterizationModeEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (lineRasterizationMode)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) lineRasterizationMode = (VkLineRasterizationModeEXT)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetLineStippleEnableEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (stippledLineEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stippledLineEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetDepthClipNegativeOneToOneEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (negativeOneToOne)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) negativeOneToOne = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetViewportWScalingEnableNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (viewportWScalingEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) viewportWScalingEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetViewportSwizzleNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (firstViewport)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstViewport = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (viewportCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) viewportCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pViewportSwizzles)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pViewportSwizzles = (VkViewportSwizzleNV const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetCoverageToColorEnableNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (coverageToColorEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) coverageToColorEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetCoverageToColorLocationNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (coverageToColorLocation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) coverageToColorLocation = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetCoverageModulationModeNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (coverageModulationMode)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) coverageModulationMode = (VkCoverageModulationModeNV)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetCoverageModulationTableEnableNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (coverageModulationTableEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) coverageModulationTableEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetCoverageModulationTableNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (coverageModulationTableCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) coverageModulationTableCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCoverageModulationTable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCoverageModulationTable = (float const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetShadingRateImageEnableNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (shadingRateImageEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) shadingRateImageEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetCoverageReductionModeNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (coverageReductionMode)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) coverageReductionMode = (VkCoverageReductionModeNV)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
    return env.Null();
}
#endif
#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetRepresentativeFragmentTestEnableNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (representativeFragmentTestEnable)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) representativeFragmentTestEnable = (VkBool32)info_[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
    return env.Null();
}
#endif
static Napi::Value rawCreatePrivateDataSlot(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkPrivateDataSlotCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pPrivateDataSlot)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPrivateDataSlot = (VkPrivateDataSlot*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    return Napi::Number::New(env, result);
}
static Napi::Value rawDestroyPrivateDataSlot(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (privateDataSlot)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) privateDataSlot = (VkPrivateDataSlot)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyPrivateDataSlot(device, privateDataSlot, pAllocator);
    return env.Null();
}
static Napi::Value rawSetPrivateData(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (objectType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) objectType = (VkObjectType)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (objectHandle)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) objectHandle = (uint64_t)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (privateDataSlot)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) privateDataSlot = (VkPrivateDataSlot)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (data)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) data = (uint64_t)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkSetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
    return Napi::Number::New(env, result);
}
static Napi::Value rawGetPrivateData(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (objectType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) objectType = (VkObjectType)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (objectHandle)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) objectHandle = (uint64_t)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (privateDataSlot)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) privateDataSlot = (VkPrivateDataSlot)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pData = (uint64_t*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPrivateData(device, objectType, objectHandle, privateDataSlot, pData);
    return env.Null();
}
static Napi::Value rawCmdCopyBuffer2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCopyBufferInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCopyBufferInfo = (VkCopyBufferInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    return env.Null();
}
static Napi::Value rawCmdCopyImage2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCopyImageInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCopyImageInfo = (VkCopyImageInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyImage2(commandBuffer, pCopyImageInfo);
    return env.Null();
}
static Napi::Value rawCmdBlitImage2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pBlitImageInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBlitImageInfo = (VkBlitImageInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBlitImage2(commandBuffer, pBlitImageInfo);
    return env.Null();
}
static Napi::Value rawCmdCopyBufferToImage2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCopyBufferToImageInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCopyBufferToImageInfo = (VkCopyBufferToImageInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    return env.Null();
}
static Napi::Value rawCmdCopyImageToBuffer2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCopyImageToBufferInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCopyImageToBufferInfo = (VkCopyImageToBufferInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    return env.Null();
}
static Napi::Value rawCmdResolveImage2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pResolveImageInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pResolveImageInfo = (VkResolveImageInfo2 const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdResolveImage2(commandBuffer, pResolveImageInfo);
    return env.Null();
}
#ifdef VK_KHR_fragment_shading_rate
static Napi::Value rawCmdSetFragmentShadingRateKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pFragmentSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFragmentSize = (VkExtent2D const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (combinerOps)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) combinerOps = (VkFragmentShadingRateCombinerOpKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
    return env.Null();
}
#endif
#ifdef VK_KHR_fragment_shading_rate
static Napi::Value rawGetPhysicalDeviceFragmentShadingRatesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pFragmentShadingRateCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFragmentShadingRateCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pFragmentShadingRates)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFragmentShadingRates = (VkPhysicalDeviceFragmentShadingRateKHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_fragment_shading_rate_enums
static Napi::Value rawCmdSetFragmentShadingRateEnumNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (shadingRate)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) shadingRate = (VkFragmentShadingRateNV)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (combinerOps)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) combinerOps = (VkFragmentShadingRateCombinerOpKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
    return env.Null();
}
#endif
#ifdef VK_KHR_acceleration_structure
static Napi::Value rawGetAccelerationStructureBuildSizesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buildType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buildType = (VkAccelerationStructureBuildTypeKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pBuildInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBuildInfo = (VkAccelerationStructureBuildGeometryInfoKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pMaxPrimitiveCounts)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMaxPrimitiveCounts = (uint32_t const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pSizeInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSizeInfo = (VkAccelerationStructureBuildSizesInfoKHR*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetAccelerationStructureBuildSizesKHR(device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_vertex_input_dynamic_state
static Napi::Value rawCmdSetVertexInputEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (vertexBindingDescriptionCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) vertexBindingDescriptionCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pVertexBindingDescriptions)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pVertexBindingDescriptions = (VkVertexInputBindingDescription2EXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (vertexAttributeDescriptionCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) vertexAttributeDescriptionCount = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 4 argument (pVertexAttributeDescriptions)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pVertexAttributeDescriptions = (VkVertexInputAttributeDescription2EXT const*)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    return env.Null();
}
#endif
#ifdef VK_EXT_color_write_enable
static Napi::Value rawCmdSetColorWriteEnableEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (attachmentCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) attachmentCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pColorWriteEnables)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pColorWriteEnables = (VkBool32 const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
    return env.Null();
}
#endif
static Napi::Value rawCmdSetEvent2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (event)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) event = (VkEvent)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pDependencyInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDependencyInfo = (VkDependencyInfo const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetEvent2(commandBuffer, event, pDependencyInfo);
    return env.Null();
}
static Napi::Value rawCmdResetEvent2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (event)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) event = (VkEvent)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (stageMask)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stageMask = (VkPipelineStageFlags2)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdResetEvent2(commandBuffer, event, stageMask);
    return env.Null();
}
static Napi::Value rawCmdWaitEvents2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (eventCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) eventCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pEvents)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pEvents = (VkEvent const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pDependencyInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDependencyInfos = (VkDependencyInfo const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    return env.Null();
}
static Napi::Value rawCmdPipelineBarrier2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pDependencyInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDependencyInfo = (VkDependencyInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    return env.Null();
}
static Napi::Value rawQueueSubmit2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (queue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queue = (VkQueue)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (submitCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) submitCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSubmits)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSubmits = (VkSubmitInfo2 const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (fence)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) fence = (VkFence)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkQueueSubmit2(queue, submitCount, pSubmits, fence);
    return Napi::Number::New(env, result);
}
static Napi::Value rawCmdWriteTimestamp2(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (stage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stage = (VkPipelineStageFlags2)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (query)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) query = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    return env.Null();
}
#ifdef VK_KHR_synchronization2
static Napi::Value rawCmdWriteBufferMarker2AMD(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (stage)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stage = (VkPipelineStageFlags2)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (dstBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstBuffer = (VkBuffer)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (dstOffset)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dstOffset = (VkDeviceSize)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 4 argument (marker)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) marker = (uint32_t)info_[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
    return env.Null();
}
#endif
#ifdef VK_KHR_synchronization2
static Napi::Value rawGetQueueCheckpointData2NV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (queue)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queue = (VkQueue)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCheckpointDataCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCheckpointDataCount = (uint32_t*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCheckpointData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCheckpointData = (VkCheckpointData2NV*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData);
    return env.Null();
}
#endif
#ifdef VK_KHR_video_queue
static Napi::Value rawGetPhysicalDeviceVideoCapabilitiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pVideoProfile)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pVideoProfile = (VkVideoProfileInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCapabilities)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCapabilities = (VkVideoCapabilitiesKHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceVideoCapabilitiesKHR(physicalDevice, pVideoProfile, pCapabilities);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_video_queue
static Napi::Value rawGetPhysicalDeviceVideoFormatPropertiesKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pVideoFormatInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pVideoFormatInfo = (VkPhysicalDeviceVideoFormatInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pVideoFormatPropertyCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pVideoFormatPropertyCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pVideoFormatProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pVideoFormatProperties = (VkVideoFormatPropertiesKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceVideoFormatPropertiesKHR(physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_video_queue
static Napi::Value rawCreateVideoSessionKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkVideoSessionCreateInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pVideoSession)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pVideoSession = (VkVideoSessionKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateVideoSessionKHR(device, pCreateInfo, pAllocator, pVideoSession);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_video_queue
static Napi::Value rawDestroyVideoSessionKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (videoSession)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) videoSession = (VkVideoSessionKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyVideoSessionKHR(device, videoSession, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_KHR_video_queue
static Napi::Value rawCreateVideoSessionParametersKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkVideoSessionParametersCreateInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pVideoSessionParameters)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pVideoSessionParameters = (VkVideoSessionParametersKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateVideoSessionParametersKHR(device, pCreateInfo, pAllocator, pVideoSessionParameters);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_video_queue
static Napi::Value rawUpdateVideoSessionParametersKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (videoSessionParameters)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) videoSessionParameters = (VkVideoSessionParametersKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pUpdateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pUpdateInfo = (VkVideoSessionParametersUpdateInfoKHR const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkUpdateVideoSessionParametersKHR(device, videoSessionParameters, pUpdateInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_video_queue
static Napi::Value rawDestroyVideoSessionParametersKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (videoSessionParameters)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) videoSessionParameters = (VkVideoSessionParametersKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyVideoSessionParametersKHR(device, videoSessionParameters, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_KHR_video_queue
static Napi::Value rawGetVideoSessionMemoryRequirementsKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (videoSession)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) videoSession = (VkVideoSessionKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMemoryRequirementsCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryRequirementsCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pMemoryRequirements)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMemoryRequirements = (VkVideoSessionMemoryRequirementsKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetVideoSessionMemoryRequirementsKHR(device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_video_queue
static Napi::Value rawBindVideoSessionMemoryKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (videoSession)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) videoSession = (VkVideoSessionKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (bindSessionMemoryInfoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) bindSessionMemoryInfoCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pBindSessionMemoryInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBindSessionMemoryInfos = (VkBindVideoSessionMemoryInfoKHR const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkBindVideoSessionMemoryKHR(device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_video_decode_queue
static Napi::Value rawCmdDecodeVideoKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pDecodeInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDecodeInfo = (VkVideoDecodeInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
    return env.Null();
}
#endif
#ifdef VK_KHR_video_queue
static Napi::Value rawCmdBeginVideoCodingKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pBeginInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBeginInfo = (VkVideoBeginCodingInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
    return env.Null();
}
#endif
#ifdef VK_KHR_video_queue
static Napi::Value rawCmdControlVideoCodingKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCodingControlInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCodingControlInfo = (VkVideoCodingControlInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
    return env.Null();
}
#endif
#ifdef VK_KHR_video_queue
static Napi::Value rawCmdEndVideoCodingKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pEndCodingInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pEndCodingInfo = (VkVideoEndCodingInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
    return env.Null();
}
#endif
#ifdef VK_KHR_video_encode_queue
static Napi::Value rawCmdEncodeVideoKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pEncodeInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pEncodeInfo = (VkVideoEncodeInfoKHR const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
    return env.Null();
}
#endif
#ifdef VK_NV_memory_decompression
static Napi::Value rawCmdDecompressMemoryNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (decompressRegionCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) decompressRegionCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pDecompressMemoryRegions)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pDecompressMemoryRegions = (VkDecompressMemoryRegionNV const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
    return env.Null();
}
#endif
#ifdef VK_NV_memory_decompression
static Napi::Value rawCmdDecompressMemoryIndirectCountNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (indirectCommandsAddress)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) indirectCommandsAddress = (VkDeviceAddress)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (indirectCommandsCountAddress)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) indirectCommandsCountAddress = (VkDeviceAddress)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 3 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (uint32_t)info_[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
    return env.Null();
}
#endif
#ifdef VK_NVX_binary_import
static Napi::Value rawCreateCuModuleNVX(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkCuModuleCreateInfoNVX const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pModule)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pModule = (VkCuModuleNVX*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateCuModuleNVX(device, pCreateInfo, pAllocator, pModule);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NVX_binary_import
static Napi::Value rawCreateCuFunctionNVX(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkCuFunctionCreateInfoNVX const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pFunction)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFunction = (VkCuFunctionNVX*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateCuFunctionNVX(device, pCreateInfo, pAllocator, pFunction);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NVX_binary_import
static Napi::Value rawDestroyCuModuleNVX(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (module)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) module = (VkCuModuleNVX)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyCuModuleNVX(device, module, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_NVX_binary_import
static Napi::Value rawDestroyCuFunctionNVX(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (function)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) function = (VkCuFunctionNVX)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyCuFunctionNVX(device, function, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_NVX_binary_import
static Napi::Value rawCmdCuLaunchKernelNVX(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pLaunchInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pLaunchInfo = (VkCuLaunchInfoNVX const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_pageable_device_local_memory
static Napi::Value rawSetDeviceMemoryPriorityEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (memory)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) memory = (VkDeviceMemory)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (priority)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) priority = (float)info_[2].As<Napi::Number>().FloatValue();
    
    ::vkSetDeviceMemoryPriorityEXT(device, memory, priority);
    return env.Null();
}
#endif
#ifdef VK_EXT_acquire_drm_display
static Napi::Value rawAcquireDrmDisplayEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (drmFd)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) drmFd = (int32_t)info_[1].As<Napi::Number>().Int32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (display)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) display = (VkDisplayKHR)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkAcquireDrmDisplayEXT(physicalDevice, drmFd, display);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_acquire_drm_display
static Napi::Value rawGetDrmDisplayEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (drmFd)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) drmFd = (int32_t)info_[1].As<Napi::Number>().Int32Value();

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (connectorId)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) connectorId = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (display)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) display = (VkDisplayKHR*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDrmDisplayEXT(physicalDevice, drmFd, connectorId, display);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_KHR_present_wait
static Napi::Value rawWaitForPresentKHR(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (swapchain)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) swapchain = (VkSwapchainKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (presentId)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) presentId = (uint64_t)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (timeout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) timeout = (uint64_t)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkWaitForPresentKHR(device, swapchain, presentId, timeout);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_FUCHSIA_buffer_collection
static Napi::Value rawCreateBufferCollectionFUCHSIA(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkBufferCollectionCreateInfoFUCHSIA const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pCollection)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCollection = (VkBufferCollectionFUCHSIA*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateBufferCollectionFUCHSIA(device, pCreateInfo, pAllocator, pCollection);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_FUCHSIA_buffer_collection
static Napi::Value rawSetBufferCollectionBufferConstraintsFUCHSIA(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (collection)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) collection = (VkBufferCollectionFUCHSIA)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pBufferConstraintsInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBufferConstraintsInfo = (VkBufferConstraintsInfoFUCHSIA const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkSetBufferCollectionBufferConstraintsFUCHSIA(device, collection, pBufferConstraintsInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_FUCHSIA_buffer_collection
static Napi::Value rawSetBufferCollectionImageConstraintsFUCHSIA(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (collection)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) collection = (VkBufferCollectionFUCHSIA)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pImageConstraintsInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImageConstraintsInfo = (VkImageConstraintsInfoFUCHSIA const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkSetBufferCollectionImageConstraintsFUCHSIA(device, collection, pImageConstraintsInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_FUCHSIA_buffer_collection
static Napi::Value rawDestroyBufferCollectionFUCHSIA(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (collection)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) collection = (VkBufferCollectionFUCHSIA)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyBufferCollectionFUCHSIA(device, collection, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_FUCHSIA_buffer_collection
static Napi::Value rawGetBufferCollectionPropertiesFUCHSIA(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (collection)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) collection = (VkBufferCollectionFUCHSIA)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkBufferCollectionPropertiesFUCHSIA*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetBufferCollectionPropertiesFUCHSIA(device, collection, pProperties);
    return Napi::Number::New(env, result);
}
#endif
static Napi::Value rawCmdBeginRendering(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pRenderingInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRenderingInfo = (VkRenderingInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginRendering(commandBuffer, pRenderingInfo);
    return env.Null();
}
static Napi::Value rawCmdEndRendering(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndRendering(commandBuffer);
    return env.Null();
}
#ifdef VK_VALVE_descriptor_set_host_mapping
static Napi::Value rawGetDescriptorSetLayoutHostMappingInfoVALVE(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pBindingReference)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBindingReference = (VkDescriptorSetBindingReferenceVALVE const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pHostMapping)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pHostMapping = (VkDescriptorSetLayoutHostMappingInfoVALVE*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDescriptorSetLayoutHostMappingInfoVALVE(device, pBindingReference, pHostMapping);
    return env.Null();
}
#endif
#ifdef VK_VALVE_descriptor_set_host_mapping
static Napi::Value rawGetDescriptorSetHostMappingVALVE(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (descriptorSet)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) descriptorSet = (VkDescriptorSet)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer of pointers) at 2 argument (ppData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) ppData = (void**)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDescriptorSetHostMappingVALVE(device, descriptorSet, ppData);
    return env.Null();
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCreateMicromapEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkMicromapCreateInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pMicromap)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMicromap = (VkMicromapEXT*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateMicromapEXT(device, pCreateInfo, pAllocator, pMicromap);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCmdBuildMicromapsEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (infoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) infoCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfos = (VkMicromapBuildInfoEXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
    return env.Null();
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawBuildMicromapsEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (deferredOperation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) deferredOperation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 2 argument (infoCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) infoCount = (uint32_t)info_[2].As<Napi::Number>().Uint32Value();

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pInfos)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfos = (VkMicromapBuildInfoEXT const*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkBuildMicromapsEXT(device, deferredOperation, infoCount, pInfos);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawDestroyMicromapEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (micromap)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) micromap = (VkMicromapEXT)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyMicromapEXT(device, micromap, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCmdCopyMicromapEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkCopyMicromapInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyMicromapEXT(commandBuffer, pInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCopyMicromapEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (deferredOperation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) deferredOperation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkCopyMicromapInfoEXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCopyMicromapEXT(device, deferredOperation, pInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCmdCopyMicromapToMemoryEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkCopyMicromapToMemoryInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCopyMicromapToMemoryEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (deferredOperation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) deferredOperation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkCopyMicromapToMemoryInfoEXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCopyMicromapToMemoryEXT(device, deferredOperation, pInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCmdCopyMemoryToMicromapEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkCopyMemoryToMicromapInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCopyMemoryToMicromapEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (deferredOperation)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) deferredOperation = (VkDeferredOperationKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pInfo = (VkCopyMemoryToMicromapInfoEXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCopyMemoryToMicromapEXT(device, deferredOperation, pInfo);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCmdWriteMicromapsPropertiesEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (micromapCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) micromapCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMicromaps)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMicromaps = (VkMicromapEXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (queryType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryType = (VkQueryType)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (queryPool)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryPool = (VkQueryPool)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 5 argument (firstQuery)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) firstQuery = (uint32_t)info_[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
    return env.Null();
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawWriteMicromapsPropertiesEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsNumber()) { Napi::TypeError::New(env, "Wrong type, needs Number at 1 argument (micromapCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) micromapCount = (uint32_t)info_[1].As<Napi::Number>().Uint32Value();

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pMicromaps)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMicromaps = (VkMicromapEXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (queryType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) queryType = (VkQueryType)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (dataSize)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) dataSize = (size_t)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[5].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 5 argument (pData)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pData = (void*)info_[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[6].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 6 argument (stride)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) stride = (size_t)info_[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkWriteMicromapsPropertiesEXT(device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawGetDeviceMicromapCompatibilityEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pVersionInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pVersionInfo = (VkMicromapVersionInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pCompatibility)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCompatibility = (VkAccelerationStructureCompatibilityKHR*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceMicromapCompatibilityEXT(device, pVersionInfo, pCompatibility);
    return env.Null();
}
#endif
#ifdef VK_EXT_opacity_micromap
static Napi::Value rawGetMicromapBuildSizesEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (buildType)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) buildType = (VkAccelerationStructureBuildTypeKHR)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pBuildInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pBuildInfo = (VkMicromapBuildInfoEXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSizeInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSizeInfo = (VkMicromapBuildSizesInfoEXT*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetMicromapBuildSizesEXT(device, buildType, pBuildInfo, pSizeInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_shader_module_identifier
static Napi::Value rawGetShaderModuleIdentifierEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (shaderModule)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) shaderModule = (VkShaderModule)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pIdentifier)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pIdentifier = (VkShaderModuleIdentifierEXT*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetShaderModuleIdentifierEXT(device, shaderModule, pIdentifier);
    return env.Null();
}
#endif
#ifdef VK_EXT_shader_module_identifier
static Napi::Value rawGetShaderModuleCreateInfoIdentifierEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkShaderModuleCreateInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pIdentifier)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pIdentifier = (VkShaderModuleIdentifierEXT*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetShaderModuleCreateInfoIdentifierEXT(device, pCreateInfo, pIdentifier);
    return env.Null();
}
#endif
#ifdef VK_EXT_image_compression_control
static Napi::Value rawGetImageSubresourceLayout2EXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (image)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) image = (VkImage)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pSubresource)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSubresource = (VkImageSubresource2EXT const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pLayout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pLayout = (VkSubresourceLayout2EXT*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetImageSubresourceLayout2EXT(device, image, pSubresource, pLayout);
    return env.Null();
}
#endif
#ifdef VK_EXT_pipeline_properties
static Napi::Value rawGetPipelinePropertiesEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pPipelineInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPipelineInfo = (VkPipelineInfoEXT const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pPipelineProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPipelineProperties = (VkBaseOutStructure*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPipelinePropertiesEXT(device, pPipelineInfo, pPipelineProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_EXT_metal_objects
static Napi::Value rawExportMetalObjectsEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pMetalObjectsInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pMetalObjectsInfo = (VkExportMetalObjectsInfoEXT*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkExportMetalObjectsEXT(device, pMetalObjectsInfo);
    return env.Null();
}
#endif
#ifdef VK_QCOM_tile_properties
static Napi::Value rawGetFramebufferTilePropertiesQCOM(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (framebuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) framebuffer = (VkFramebuffer)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pPropertiesCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pPropertiesCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkTilePropertiesQCOM*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetFramebufferTilePropertiesQCOM(device, framebuffer, pPropertiesCount, pProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_QCOM_tile_properties
static Napi::Value rawGetDynamicRenderingTilePropertiesQCOM(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pRenderingInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pRenderingInfo = (VkRenderingInfo const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pProperties = (VkTilePropertiesQCOM*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDynamicRenderingTilePropertiesQCOM(device, pRenderingInfo, pProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_optical_flow
static Napi::Value rawGetPhysicalDeviceOpticalFlowImageFormatsNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (physicalDevice)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) physicalDevice = (VkPhysicalDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pOpticalFlowImageFormatInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pOpticalFlowImageFormatInfo = (VkOpticalFlowImageFormatInfoNV const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pFormatCount)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFormatCount = (uint32_t*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pImageFormatProperties)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pImageFormatProperties = (VkOpticalFlowImageFormatPropertiesNV*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetPhysicalDeviceOpticalFlowImageFormatsNV(physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_optical_flow
static Napi::Value rawCreateOpticalFlowSessionNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pCreateInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pCreateInfo = (VkOpticalFlowSessionCreateInfoNV const*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 3 argument (pSession)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pSession = (VkOpticalFlowSessionNV*)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkCreateOpticalFlowSessionNV(device, pCreateInfo, pAllocator, pSession);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_optical_flow
static Napi::Value rawDestroyOpticalFlowSessionNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (session)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) session = (VkOpticalFlowSessionNV)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pAllocator)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pAllocator = (VkAllocationCallbacks const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyOpticalFlowSessionNV(device, session, pAllocator);
    return env.Null();
}
#endif
#ifdef VK_NV_optical_flow
static Napi::Value rawBindOpticalFlowSessionImageNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (session)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) session = (VkOpticalFlowSessionNV)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 2 argument (bindingPoint)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) bindingPoint = (VkOpticalFlowSessionBindingPointNV)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[3].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 3 argument (view)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) view = (VkImageView)info_[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[4].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 4 argument (layout)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) layout = (VkImageLayout)info_[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkBindOpticalFlowSessionImageNV(device, session, bindingPoint, view, layout);
    return Napi::Number::New(env, result);
}
#endif
#ifdef VK_NV_optical_flow
static Napi::Value rawCmdOpticalFlowExecuteNV(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (commandBuffer)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) commandBuffer = (VkCommandBuffer)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 1 argument (session)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) session = (VkOpticalFlowSessionNV)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pExecuteInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pExecuteInfo = (VkOpticalFlowExecuteInfoNV const*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
    return env.Null();
}
#endif
#ifdef VK_EXT_device_fault
static Napi::Value rawGetDeviceFaultInfoEXT(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    if (info_.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }
    
    if (!info_[0].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (handle) at 0 argument (device)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) device = (VkDevice)info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[1].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 1 argument (pFaultCounts)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFaultCounts = (VkDeviceFaultCountsEXT*)info_[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info_[2].IsBigInt()) { Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer) at 2 argument (pFaultInfo)").ThrowAsJavaScriptException(); return env.Null(); }
    decltype(auto) pFaultInfo = (VkDeviceFaultInfoEXT*)info_[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    decltype(auto) result = ::vkGetDeviceFaultInfoEXT(device, pFaultCounts, pFaultInfo);
    return Napi::Number::New(env, result);
}
#endif

static Napi::Object Init(Napi::Env env, Napi::Object exports) {
    volkInitialize();

    exports["vkCreateInstance"] = Napi::Function::New(env, rawCreateInstance);
    exports["vkDestroyInstance"] = Napi::Function::New(env, rawDestroyInstance);
    exports["vkEnumeratePhysicalDevices"] = Napi::Function::New(env, rawEnumeratePhysicalDevices);
    exports["vkGetDeviceProcAddr"] = Napi::Function::New(env, rawGetDeviceProcAddr);
    exports["vkGetInstanceProcAddr"] = Napi::Function::New(env, rawGetInstanceProcAddr);
    exports["vkGetPhysicalDeviceProperties"] = Napi::Function::New(env, rawGetPhysicalDeviceProperties);
    exports["vkGetPhysicalDeviceQueueFamilyProperties"] = Napi::Function::New(env, rawGetPhysicalDeviceQueueFamilyProperties);
    exports["vkGetPhysicalDeviceMemoryProperties"] = Napi::Function::New(env, rawGetPhysicalDeviceMemoryProperties);
    exports["vkGetPhysicalDeviceFeatures"] = Napi::Function::New(env, rawGetPhysicalDeviceFeatures);
    exports["vkGetPhysicalDeviceFormatProperties"] = Napi::Function::New(env, rawGetPhysicalDeviceFormatProperties);
    exports["vkGetPhysicalDeviceImageFormatProperties"] = Napi::Function::New(env, rawGetPhysicalDeviceImageFormatProperties);
    exports["vkCreateDevice"] = Napi::Function::New(env, rawCreateDevice);
    exports["vkDestroyDevice"] = Napi::Function::New(env, rawDestroyDevice);
    exports["vkEnumerateInstanceVersion"] = Napi::Function::New(env, rawEnumerateInstanceVersion);
    exports["vkEnumerateInstanceLayerProperties"] = Napi::Function::New(env, rawEnumerateInstanceLayerProperties);
    exports["vkEnumerateInstanceExtensionProperties"] = Napi::Function::New(env, rawEnumerateInstanceExtensionProperties);
    exports["vkEnumerateDeviceLayerProperties"] = Napi::Function::New(env, rawEnumerateDeviceLayerProperties);
    exports["vkEnumerateDeviceExtensionProperties"] = Napi::Function::New(env, rawEnumerateDeviceExtensionProperties);
    exports["vkGetDeviceQueue"] = Napi::Function::New(env, rawGetDeviceQueue);
    exports["vkQueueSubmit"] = Napi::Function::New(env, rawQueueSubmit);
    exports["vkQueueWaitIdle"] = Napi::Function::New(env, rawQueueWaitIdle);
    exports["vkDeviceWaitIdle"] = Napi::Function::New(env, rawDeviceWaitIdle);
    exports["vkAllocateMemory"] = Napi::Function::New(env, rawAllocateMemory);
    exports["vkFreeMemory"] = Napi::Function::New(env, rawFreeMemory);
    exports["vkMapMemory"] = Napi::Function::New(env, rawMapMemory);
    exports["vkUnmapMemory"] = Napi::Function::New(env, rawUnmapMemory);
    exports["vkFlushMappedMemoryRanges"] = Napi::Function::New(env, rawFlushMappedMemoryRanges);
    exports["vkInvalidateMappedMemoryRanges"] = Napi::Function::New(env, rawInvalidateMappedMemoryRanges);
    exports["vkGetDeviceMemoryCommitment"] = Napi::Function::New(env, rawGetDeviceMemoryCommitment);
    exports["vkGetBufferMemoryRequirements"] = Napi::Function::New(env, rawGetBufferMemoryRequirements);
    exports["vkBindBufferMemory"] = Napi::Function::New(env, rawBindBufferMemory);
    exports["vkGetImageMemoryRequirements"] = Napi::Function::New(env, rawGetImageMemoryRequirements);
    exports["vkBindImageMemory"] = Napi::Function::New(env, rawBindImageMemory);
    exports["vkGetImageSparseMemoryRequirements"] = Napi::Function::New(env, rawGetImageSparseMemoryRequirements);
    exports["vkGetPhysicalDeviceSparseImageFormatProperties"] = Napi::Function::New(env, rawGetPhysicalDeviceSparseImageFormatProperties);
    exports["vkQueueBindSparse"] = Napi::Function::New(env, rawQueueBindSparse);
    exports["vkCreateFence"] = Napi::Function::New(env, rawCreateFence);
    exports["vkDestroyFence"] = Napi::Function::New(env, rawDestroyFence);
    exports["vkResetFences"] = Napi::Function::New(env, rawResetFences);
    exports["vkGetFenceStatus"] = Napi::Function::New(env, rawGetFenceStatus);
    exports["vkWaitForFences"] = Napi::Function::New(env, rawWaitForFences);
    exports["vkCreateSemaphore"] = Napi::Function::New(env, rawCreateSemaphore);
    exports["vkDestroySemaphore"] = Napi::Function::New(env, rawDestroySemaphore);
    exports["vkCreateEvent"] = Napi::Function::New(env, rawCreateEvent);
    exports["vkDestroyEvent"] = Napi::Function::New(env, rawDestroyEvent);
    exports["vkGetEventStatus"] = Napi::Function::New(env, rawGetEventStatus);
    exports["vkSetEvent"] = Napi::Function::New(env, rawSetEvent);
    exports["vkResetEvent"] = Napi::Function::New(env, rawResetEvent);
    exports["vkCreateQueryPool"] = Napi::Function::New(env, rawCreateQueryPool);
    exports["vkDestroyQueryPool"] = Napi::Function::New(env, rawDestroyQueryPool);
    exports["vkGetQueryPoolResults"] = Napi::Function::New(env, rawGetQueryPoolResults);
    exports["vkResetQueryPool"] = Napi::Function::New(env, rawResetQueryPool);
    exports["vkCreateBuffer"] = Napi::Function::New(env, rawCreateBuffer);
    exports["vkDestroyBuffer"] = Napi::Function::New(env, rawDestroyBuffer);
    exports["vkCreateBufferView"] = Napi::Function::New(env, rawCreateBufferView);
    exports["vkDestroyBufferView"] = Napi::Function::New(env, rawDestroyBufferView);
    exports["vkCreateImage"] = Napi::Function::New(env, rawCreateImage);
    exports["vkDestroyImage"] = Napi::Function::New(env, rawDestroyImage);
    exports["vkGetImageSubresourceLayout"] = Napi::Function::New(env, rawGetImageSubresourceLayout);
    exports["vkCreateImageView"] = Napi::Function::New(env, rawCreateImageView);
    exports["vkDestroyImageView"] = Napi::Function::New(env, rawDestroyImageView);
    exports["vkCreateShaderModule"] = Napi::Function::New(env, rawCreateShaderModule);
    exports["vkDestroyShaderModule"] = Napi::Function::New(env, rawDestroyShaderModule);
    exports["vkCreatePipelineCache"] = Napi::Function::New(env, rawCreatePipelineCache);
    exports["vkDestroyPipelineCache"] = Napi::Function::New(env, rawDestroyPipelineCache);
    exports["vkGetPipelineCacheData"] = Napi::Function::New(env, rawGetPipelineCacheData);
    exports["vkMergePipelineCaches"] = Napi::Function::New(env, rawMergePipelineCaches);
    exports["vkCreateGraphicsPipelines"] = Napi::Function::New(env, rawCreateGraphicsPipelines);
    exports["vkCreateComputePipelines"] = Napi::Function::New(env, rawCreateComputePipelines);
#ifdef VK_HUAWEI_subpass_shading
    exports["vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI"] = Napi::Function::New(env, rawGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI);
#endif
    exports["vkDestroyPipeline"] = Napi::Function::New(env, rawDestroyPipeline);
    exports["vkCreatePipelineLayout"] = Napi::Function::New(env, rawCreatePipelineLayout);
    exports["vkDestroyPipelineLayout"] = Napi::Function::New(env, rawDestroyPipelineLayout);
    exports["vkCreateSampler"] = Napi::Function::New(env, rawCreateSampler);
    exports["vkDestroySampler"] = Napi::Function::New(env, rawDestroySampler);
    exports["vkCreateDescriptorSetLayout"] = Napi::Function::New(env, rawCreateDescriptorSetLayout);
    exports["vkDestroyDescriptorSetLayout"] = Napi::Function::New(env, rawDestroyDescriptorSetLayout);
    exports["vkCreateDescriptorPool"] = Napi::Function::New(env, rawCreateDescriptorPool);
    exports["vkDestroyDescriptorPool"] = Napi::Function::New(env, rawDestroyDescriptorPool);
    exports["vkResetDescriptorPool"] = Napi::Function::New(env, rawResetDescriptorPool);
    exports["vkAllocateDescriptorSets"] = Napi::Function::New(env, rawAllocateDescriptorSets);
    exports["vkFreeDescriptorSets"] = Napi::Function::New(env, rawFreeDescriptorSets);
    exports["vkUpdateDescriptorSets"] = Napi::Function::New(env, rawUpdateDescriptorSets);
    exports["vkCreateFramebuffer"] = Napi::Function::New(env, rawCreateFramebuffer);
    exports["vkDestroyFramebuffer"] = Napi::Function::New(env, rawDestroyFramebuffer);
    exports["vkCreateRenderPass"] = Napi::Function::New(env, rawCreateRenderPass);
    exports["vkDestroyRenderPass"] = Napi::Function::New(env, rawDestroyRenderPass);
    exports["vkGetRenderAreaGranularity"] = Napi::Function::New(env, rawGetRenderAreaGranularity);
    exports["vkCreateCommandPool"] = Napi::Function::New(env, rawCreateCommandPool);
    exports["vkDestroyCommandPool"] = Napi::Function::New(env, rawDestroyCommandPool);
    exports["vkResetCommandPool"] = Napi::Function::New(env, rawResetCommandPool);
    exports["vkAllocateCommandBuffers"] = Napi::Function::New(env, rawAllocateCommandBuffers);
    exports["vkFreeCommandBuffers"] = Napi::Function::New(env, rawFreeCommandBuffers);
    exports["vkBeginCommandBuffer"] = Napi::Function::New(env, rawBeginCommandBuffer);
    exports["vkEndCommandBuffer"] = Napi::Function::New(env, rawEndCommandBuffer);
    exports["vkResetCommandBuffer"] = Napi::Function::New(env, rawResetCommandBuffer);
    exports["vkCmdBindPipeline"] = Napi::Function::New(env, rawCmdBindPipeline);
    exports["vkCmdSetViewport"] = Napi::Function::New(env, rawCmdSetViewport);
    exports["vkCmdSetScissor"] = Napi::Function::New(env, rawCmdSetScissor);
    exports["vkCmdSetLineWidth"] = Napi::Function::New(env, rawCmdSetLineWidth);
    exports["vkCmdSetDepthBias"] = Napi::Function::New(env, rawCmdSetDepthBias);
    exports["vkCmdSetBlendConstants"] = Napi::Function::New(env, rawCmdSetBlendConstants);
    exports["vkCmdSetDepthBounds"] = Napi::Function::New(env, rawCmdSetDepthBounds);
    exports["vkCmdSetStencilCompareMask"] = Napi::Function::New(env, rawCmdSetStencilCompareMask);
    exports["vkCmdSetStencilWriteMask"] = Napi::Function::New(env, rawCmdSetStencilWriteMask);
    exports["vkCmdSetStencilReference"] = Napi::Function::New(env, rawCmdSetStencilReference);
    exports["vkCmdBindDescriptorSets"] = Napi::Function::New(env, rawCmdBindDescriptorSets);
    exports["vkCmdBindIndexBuffer"] = Napi::Function::New(env, rawCmdBindIndexBuffer);
    exports["vkCmdBindVertexBuffers"] = Napi::Function::New(env, rawCmdBindVertexBuffers);
    exports["vkCmdDraw"] = Napi::Function::New(env, rawCmdDraw);
    exports["vkCmdDrawIndexed"] = Napi::Function::New(env, rawCmdDrawIndexed);
#ifdef VK_EXT_multi_draw
    exports["vkCmdDrawMultiEXT"] = Napi::Function::New(env, rawCmdDrawMultiEXT);
#endif
#ifdef VK_EXT_multi_draw
    exports["vkCmdDrawMultiIndexedEXT"] = Napi::Function::New(env, rawCmdDrawMultiIndexedEXT);
#endif
    exports["vkCmdDrawIndirect"] = Napi::Function::New(env, rawCmdDrawIndirect);
    exports["vkCmdDrawIndexedIndirect"] = Napi::Function::New(env, rawCmdDrawIndexedIndirect);
    exports["vkCmdDispatch"] = Napi::Function::New(env, rawCmdDispatch);
    exports["vkCmdDispatchIndirect"] = Napi::Function::New(env, rawCmdDispatchIndirect);
#ifdef VK_HUAWEI_subpass_shading
    exports["vkCmdSubpassShadingHUAWEI"] = Napi::Function::New(env, rawCmdSubpassShadingHUAWEI);
#endif
    exports["vkCmdCopyBuffer"] = Napi::Function::New(env, rawCmdCopyBuffer);
    exports["vkCmdCopyImage"] = Napi::Function::New(env, rawCmdCopyImage);
    exports["vkCmdBlitImage"] = Napi::Function::New(env, rawCmdBlitImage);
    exports["vkCmdCopyBufferToImage"] = Napi::Function::New(env, rawCmdCopyBufferToImage);
    exports["vkCmdCopyImageToBuffer"] = Napi::Function::New(env, rawCmdCopyImageToBuffer);
#ifdef VK_NV_copy_memory_indirect
    exports["vkCmdCopyMemoryIndirectNV"] = Napi::Function::New(env, rawCmdCopyMemoryIndirectNV);
#endif
#ifdef VK_NV_copy_memory_indirect
    exports["vkCmdCopyMemoryToImageIndirectNV"] = Napi::Function::New(env, rawCmdCopyMemoryToImageIndirectNV);
#endif
    exports["vkCmdUpdateBuffer"] = Napi::Function::New(env, rawCmdUpdateBuffer);
    exports["vkCmdFillBuffer"] = Napi::Function::New(env, rawCmdFillBuffer);
    exports["vkCmdClearColorImage"] = Napi::Function::New(env, rawCmdClearColorImage);
    exports["vkCmdClearDepthStencilImage"] = Napi::Function::New(env, rawCmdClearDepthStencilImage);
    exports["vkCmdClearAttachments"] = Napi::Function::New(env, rawCmdClearAttachments);
    exports["vkCmdResolveImage"] = Napi::Function::New(env, rawCmdResolveImage);
    exports["vkCmdSetEvent"] = Napi::Function::New(env, rawCmdSetEvent);
    exports["vkCmdResetEvent"] = Napi::Function::New(env, rawCmdResetEvent);
    exports["vkCmdWaitEvents"] = Napi::Function::New(env, rawCmdWaitEvents);
    exports["vkCmdPipelineBarrier"] = Napi::Function::New(env, rawCmdPipelineBarrier);
    exports["vkCmdBeginQuery"] = Napi::Function::New(env, rawCmdBeginQuery);
    exports["vkCmdEndQuery"] = Napi::Function::New(env, rawCmdEndQuery);
#ifdef VK_EXT_conditional_rendering
    exports["vkCmdBeginConditionalRenderingEXT"] = Napi::Function::New(env, rawCmdBeginConditionalRenderingEXT);
#endif
#ifdef VK_EXT_conditional_rendering
    exports["vkCmdEndConditionalRenderingEXT"] = Napi::Function::New(env, rawCmdEndConditionalRenderingEXT);
#endif
    exports["vkCmdResetQueryPool"] = Napi::Function::New(env, rawCmdResetQueryPool);
    exports["vkCmdWriteTimestamp"] = Napi::Function::New(env, rawCmdWriteTimestamp);
    exports["vkCmdCopyQueryPoolResults"] = Napi::Function::New(env, rawCmdCopyQueryPoolResults);
    exports["vkCmdPushConstants"] = Napi::Function::New(env, rawCmdPushConstants);
    exports["vkCmdBeginRenderPass"] = Napi::Function::New(env, rawCmdBeginRenderPass);
    exports["vkCmdNextSubpass"] = Napi::Function::New(env, rawCmdNextSubpass);
    exports["vkCmdEndRenderPass"] = Napi::Function::New(env, rawCmdEndRenderPass);
    exports["vkCmdExecuteCommands"] = Napi::Function::New(env, rawCmdExecuteCommands);
#ifdef VK_KHR_android_surface
    exports["vkCreateAndroidSurfaceKHR"] = Napi::Function::New(env, rawCreateAndroidSurfaceKHR);
#endif
#ifdef VK_KHR_display
    exports["vkGetPhysicalDeviceDisplayPropertiesKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceDisplayPropertiesKHR);
#endif
#ifdef VK_KHR_display
    exports["vkGetPhysicalDeviceDisplayPlanePropertiesKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceDisplayPlanePropertiesKHR);
#endif
#ifdef VK_KHR_display
    exports["vkGetDisplayPlaneSupportedDisplaysKHR"] = Napi::Function::New(env, rawGetDisplayPlaneSupportedDisplaysKHR);
#endif
#ifdef VK_KHR_display
    exports["vkGetDisplayModePropertiesKHR"] = Napi::Function::New(env, rawGetDisplayModePropertiesKHR);
#endif
#ifdef VK_KHR_display
    exports["vkCreateDisplayModeKHR"] = Napi::Function::New(env, rawCreateDisplayModeKHR);
#endif
#ifdef VK_KHR_display
    exports["vkGetDisplayPlaneCapabilitiesKHR"] = Napi::Function::New(env, rawGetDisplayPlaneCapabilitiesKHR);
#endif
#ifdef VK_KHR_display
    exports["vkCreateDisplayPlaneSurfaceKHR"] = Napi::Function::New(env, rawCreateDisplayPlaneSurfaceKHR);
#endif
#ifdef VK_KHR_display_swapchain
    exports["vkCreateSharedSwapchainsKHR"] = Napi::Function::New(env, rawCreateSharedSwapchainsKHR);
#endif
#ifdef VK_KHR_surface
    exports["vkDestroySurfaceKHR"] = Napi::Function::New(env, rawDestroySurfaceKHR);
#endif
#ifdef VK_KHR_surface
    exports["vkGetPhysicalDeviceSurfaceSupportKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceSurfaceSupportKHR);
#endif
#ifdef VK_KHR_surface
    exports["vkGetPhysicalDeviceSurfaceCapabilitiesKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceSurfaceCapabilitiesKHR);
#endif
#ifdef VK_KHR_surface
    exports["vkGetPhysicalDeviceSurfaceFormatsKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceSurfaceFormatsKHR);
#endif
#ifdef VK_KHR_surface
    exports["vkGetPhysicalDeviceSurfacePresentModesKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceSurfacePresentModesKHR);
#endif
#ifdef VK_KHR_swapchain
    exports["vkCreateSwapchainKHR"] = Napi::Function::New(env, rawCreateSwapchainKHR);
#endif
#ifdef VK_KHR_swapchain
    exports["vkDestroySwapchainKHR"] = Napi::Function::New(env, rawDestroySwapchainKHR);
#endif
#ifdef VK_KHR_swapchain
    exports["vkGetSwapchainImagesKHR"] = Napi::Function::New(env, rawGetSwapchainImagesKHR);
#endif
#ifdef VK_KHR_swapchain
    exports["vkAcquireNextImageKHR"] = Napi::Function::New(env, rawAcquireNextImageKHR);
#endif
#ifdef VK_KHR_swapchain
    exports["vkQueuePresentKHR"] = Napi::Function::New(env, rawQueuePresentKHR);
#endif
#ifdef VK_NN_vi_surface
    exports["vkCreateViSurfaceNN"] = Napi::Function::New(env, rawCreateViSurfaceNN);
#endif
#ifdef VK_KHR_wayland_surface
    exports["vkCreateWaylandSurfaceKHR"] = Napi::Function::New(env, rawCreateWaylandSurfaceKHR);
#endif
#ifdef VK_KHR_wayland_surface
    exports["vkGetPhysicalDeviceWaylandPresentationSupportKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceWaylandPresentationSupportKHR);
#endif
#ifdef VK_KHR_win32_surface
    exports["vkCreateWin32SurfaceKHR"] = Napi::Function::New(env, rawCreateWin32SurfaceKHR);
#endif
#ifdef VK_KHR_win32_surface
    exports["vkGetPhysicalDeviceWin32PresentationSupportKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceWin32PresentationSupportKHR);
#endif
#ifdef VK_KHR_xlib_surface
    exports["vkCreateXlibSurfaceKHR"] = Napi::Function::New(env, rawCreateXlibSurfaceKHR);
#endif
#ifdef VK_KHR_xlib_surface
    exports["vkGetPhysicalDeviceXlibPresentationSupportKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceXlibPresentationSupportKHR);
#endif
#ifdef VK_KHR_xcb_surface
    exports["vkCreateXcbSurfaceKHR"] = Napi::Function::New(env, rawCreateXcbSurfaceKHR);
#endif
#ifdef VK_KHR_xcb_surface
    exports["vkGetPhysicalDeviceXcbPresentationSupportKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceXcbPresentationSupportKHR);
#endif
#ifdef VK_EXT_directfb_surface
    exports["vkCreateDirectFBSurfaceEXT"] = Napi::Function::New(env, rawCreateDirectFBSurfaceEXT);
#endif
#ifdef VK_EXT_directfb_surface
    exports["vkGetPhysicalDeviceDirectFBPresentationSupportEXT"] = Napi::Function::New(env, rawGetPhysicalDeviceDirectFBPresentationSupportEXT);
#endif
#ifdef VK_FUCHSIA_imagepipe_surface
    exports["vkCreateImagePipeSurfaceFUCHSIA"] = Napi::Function::New(env, rawCreateImagePipeSurfaceFUCHSIA);
#endif
#ifdef VK_GGP_stream_descriptor_surface
    exports["vkCreateStreamDescriptorSurfaceGGP"] = Napi::Function::New(env, rawCreateStreamDescriptorSurfaceGGP);
#endif
#ifdef VK_QNX_screen_surface
    exports["vkCreateScreenSurfaceQNX"] = Napi::Function::New(env, rawCreateScreenSurfaceQNX);
#endif
#ifdef VK_QNX_screen_surface
    exports["vkGetPhysicalDeviceScreenPresentationSupportQNX"] = Napi::Function::New(env, rawGetPhysicalDeviceScreenPresentationSupportQNX);
#endif
#ifdef VK_EXT_debug_report
    exports["vkCreateDebugReportCallbackEXT"] = Napi::Function::New(env, rawCreateDebugReportCallbackEXT);
#endif
#ifdef VK_EXT_debug_report
    exports["vkDestroyDebugReportCallbackEXT"] = Napi::Function::New(env, rawDestroyDebugReportCallbackEXT);
#endif
#ifdef VK_EXT_debug_report
    exports["vkDebugReportMessageEXT"] = Napi::Function::New(env, rawDebugReportMessageEXT);
#endif
#ifdef VK_EXT_debug_marker
    exports["vkDebugMarkerSetObjectNameEXT"] = Napi::Function::New(env, rawDebugMarkerSetObjectNameEXT);
#endif
#ifdef VK_EXT_debug_marker
    exports["vkDebugMarkerSetObjectTagEXT"] = Napi::Function::New(env, rawDebugMarkerSetObjectTagEXT);
#endif
#ifdef VK_EXT_debug_marker
    exports["vkCmdDebugMarkerBeginEXT"] = Napi::Function::New(env, rawCmdDebugMarkerBeginEXT);
#endif
#ifdef VK_EXT_debug_marker
    exports["vkCmdDebugMarkerEndEXT"] = Napi::Function::New(env, rawCmdDebugMarkerEndEXT);
#endif
#ifdef VK_EXT_debug_marker
    exports["vkCmdDebugMarkerInsertEXT"] = Napi::Function::New(env, rawCmdDebugMarkerInsertEXT);
#endif
#ifdef VK_NV_external_memory_capabilities
    exports["vkGetPhysicalDeviceExternalImageFormatPropertiesNV"] = Napi::Function::New(env, rawGetPhysicalDeviceExternalImageFormatPropertiesNV);
#endif
#ifdef VK_NV_external_memory_win32
    exports["vkGetMemoryWin32HandleNV"] = Napi::Function::New(env, rawGetMemoryWin32HandleNV);
#endif
#ifdef VK_NV_device_generated_commands
    exports["vkCmdExecuteGeneratedCommandsNV"] = Napi::Function::New(env, rawCmdExecuteGeneratedCommandsNV);
#endif
#ifdef VK_NV_device_generated_commands
    exports["vkCmdPreprocessGeneratedCommandsNV"] = Napi::Function::New(env, rawCmdPreprocessGeneratedCommandsNV);
#endif
#ifdef VK_NV_device_generated_commands
    exports["vkCmdBindPipelineShaderGroupNV"] = Napi::Function::New(env, rawCmdBindPipelineShaderGroupNV);
#endif
#ifdef VK_NV_device_generated_commands
    exports["vkGetGeneratedCommandsMemoryRequirementsNV"] = Napi::Function::New(env, rawGetGeneratedCommandsMemoryRequirementsNV);
#endif
#ifdef VK_NV_device_generated_commands
    exports["vkCreateIndirectCommandsLayoutNV"] = Napi::Function::New(env, rawCreateIndirectCommandsLayoutNV);
#endif
#ifdef VK_NV_device_generated_commands
    exports["vkDestroyIndirectCommandsLayoutNV"] = Napi::Function::New(env, rawDestroyIndirectCommandsLayoutNV);
#endif
    exports["vkGetPhysicalDeviceFeatures2"] = Napi::Function::New(env, rawGetPhysicalDeviceFeatures2);
    exports["vkGetPhysicalDeviceProperties2"] = Napi::Function::New(env, rawGetPhysicalDeviceProperties2);
    exports["vkGetPhysicalDeviceFormatProperties2"] = Napi::Function::New(env, rawGetPhysicalDeviceFormatProperties2);
    exports["vkGetPhysicalDeviceImageFormatProperties2"] = Napi::Function::New(env, rawGetPhysicalDeviceImageFormatProperties2);
    exports["vkGetPhysicalDeviceQueueFamilyProperties2"] = Napi::Function::New(env, rawGetPhysicalDeviceQueueFamilyProperties2);
    exports["vkGetPhysicalDeviceMemoryProperties2"] = Napi::Function::New(env, rawGetPhysicalDeviceMemoryProperties2);
    exports["vkGetPhysicalDeviceSparseImageFormatProperties2"] = Napi::Function::New(env, rawGetPhysicalDeviceSparseImageFormatProperties2);
#ifdef VK_KHR_push_descriptor
    exports["vkCmdPushDescriptorSetKHR"] = Napi::Function::New(env, rawCmdPushDescriptorSetKHR);
#endif
    exports["vkTrimCommandPool"] = Napi::Function::New(env, rawTrimCommandPool);
    exports["vkGetPhysicalDeviceExternalBufferProperties"] = Napi::Function::New(env, rawGetPhysicalDeviceExternalBufferProperties);
#ifdef VK_KHR_external_memory_win32
    exports["vkGetMemoryWin32HandleKHR"] = Napi::Function::New(env, rawGetMemoryWin32HandleKHR);
#endif
#ifdef VK_KHR_external_memory_win32
    exports["vkGetMemoryWin32HandlePropertiesKHR"] = Napi::Function::New(env, rawGetMemoryWin32HandlePropertiesKHR);
#endif
#ifdef VK_KHR_external_memory_fd
    exports["vkGetMemoryFdKHR"] = Napi::Function::New(env, rawGetMemoryFdKHR);
#endif
#ifdef VK_KHR_external_memory_fd
    exports["vkGetMemoryFdPropertiesKHR"] = Napi::Function::New(env, rawGetMemoryFdPropertiesKHR);
#endif
#ifdef VK_FUCHSIA_external_memory
    exports["vkGetMemoryZirconHandleFUCHSIA"] = Napi::Function::New(env, rawGetMemoryZirconHandleFUCHSIA);
#endif
#ifdef VK_FUCHSIA_external_memory
    exports["vkGetMemoryZirconHandlePropertiesFUCHSIA"] = Napi::Function::New(env, rawGetMemoryZirconHandlePropertiesFUCHSIA);
#endif
#ifdef VK_NV_external_memory_rdma
    exports["vkGetMemoryRemoteAddressNV"] = Napi::Function::New(env, rawGetMemoryRemoteAddressNV);
#endif
    exports["vkGetPhysicalDeviceExternalSemaphoreProperties"] = Napi::Function::New(env, rawGetPhysicalDeviceExternalSemaphoreProperties);
#ifdef VK_KHR_external_semaphore_win32
    exports["vkGetSemaphoreWin32HandleKHR"] = Napi::Function::New(env, rawGetSemaphoreWin32HandleKHR);
#endif
#ifdef VK_KHR_external_semaphore_win32
    exports["vkImportSemaphoreWin32HandleKHR"] = Napi::Function::New(env, rawImportSemaphoreWin32HandleKHR);
#endif
#ifdef VK_KHR_external_semaphore_fd
    exports["vkGetSemaphoreFdKHR"] = Napi::Function::New(env, rawGetSemaphoreFdKHR);
#endif
#ifdef VK_KHR_external_semaphore_fd
    exports["vkImportSemaphoreFdKHR"] = Napi::Function::New(env, rawImportSemaphoreFdKHR);
#endif
#ifdef VK_FUCHSIA_external_semaphore
    exports["vkGetSemaphoreZirconHandleFUCHSIA"] = Napi::Function::New(env, rawGetSemaphoreZirconHandleFUCHSIA);
#endif
#ifdef VK_FUCHSIA_external_semaphore
    exports["vkImportSemaphoreZirconHandleFUCHSIA"] = Napi::Function::New(env, rawImportSemaphoreZirconHandleFUCHSIA);
#endif
    exports["vkGetPhysicalDeviceExternalFenceProperties"] = Napi::Function::New(env, rawGetPhysicalDeviceExternalFenceProperties);
#ifdef VK_KHR_external_fence_win32
    exports["vkGetFenceWin32HandleKHR"] = Napi::Function::New(env, rawGetFenceWin32HandleKHR);
#endif
#ifdef VK_KHR_external_fence_win32
    exports["vkImportFenceWin32HandleKHR"] = Napi::Function::New(env, rawImportFenceWin32HandleKHR);
#endif
#ifdef VK_KHR_external_fence_fd
    exports["vkGetFenceFdKHR"] = Napi::Function::New(env, rawGetFenceFdKHR);
#endif
#ifdef VK_KHR_external_fence_fd
    exports["vkImportFenceFdKHR"] = Napi::Function::New(env, rawImportFenceFdKHR);
#endif
#ifdef VK_EXT_direct_mode_display
    exports["vkReleaseDisplayEXT"] = Napi::Function::New(env, rawReleaseDisplayEXT);
#endif
#ifdef VK_EXT_acquire_xlib_display
    exports["vkAcquireXlibDisplayEXT"] = Napi::Function::New(env, rawAcquireXlibDisplayEXT);
#endif
#ifdef VK_EXT_acquire_xlib_display
    exports["vkGetRandROutputDisplayEXT"] = Napi::Function::New(env, rawGetRandROutputDisplayEXT);
#endif
#ifdef VK_NV_acquire_winrt_display
    exports["vkAcquireWinrtDisplayNV"] = Napi::Function::New(env, rawAcquireWinrtDisplayNV);
#endif
#ifdef VK_NV_acquire_winrt_display
    exports["vkGetWinrtDisplayNV"] = Napi::Function::New(env, rawGetWinrtDisplayNV);
#endif
#ifdef VK_EXT_display_control
    exports["vkDisplayPowerControlEXT"] = Napi::Function::New(env, rawDisplayPowerControlEXT);
#endif
#ifdef VK_EXT_display_control
    exports["vkRegisterDeviceEventEXT"] = Napi::Function::New(env, rawRegisterDeviceEventEXT);
#endif
#ifdef VK_EXT_display_control
    exports["vkRegisterDisplayEventEXT"] = Napi::Function::New(env, rawRegisterDisplayEventEXT);
#endif
#ifdef VK_EXT_display_control
    exports["vkGetSwapchainCounterEXT"] = Napi::Function::New(env, rawGetSwapchainCounterEXT);
#endif
#ifdef VK_EXT_display_surface_counter
    exports["vkGetPhysicalDeviceSurfaceCapabilities2EXT"] = Napi::Function::New(env, rawGetPhysicalDeviceSurfaceCapabilities2EXT);
#endif
    exports["vkEnumeratePhysicalDeviceGroups"] = Napi::Function::New(env, rawEnumeratePhysicalDeviceGroups);
    exports["vkGetDeviceGroupPeerMemoryFeatures"] = Napi::Function::New(env, rawGetDeviceGroupPeerMemoryFeatures);
    exports["vkBindBufferMemory2"] = Napi::Function::New(env, rawBindBufferMemory2);
    exports["vkBindImageMemory2"] = Napi::Function::New(env, rawBindImageMemory2);
    exports["vkCmdSetDeviceMask"] = Napi::Function::New(env, rawCmdSetDeviceMask);
#ifdef VK_KHR_device_group
    exports["vkGetDeviceGroupPresentCapabilitiesKHR"] = Napi::Function::New(env, rawGetDeviceGroupPresentCapabilitiesKHR);
#endif
#ifdef VK_KHR_device_group
    exports["vkGetDeviceGroupSurfacePresentModesKHR"] = Napi::Function::New(env, rawGetDeviceGroupSurfacePresentModesKHR);
#endif
#ifdef VK_KHR_device_group
    exports["vkAcquireNextImage2KHR"] = Napi::Function::New(env, rawAcquireNextImage2KHR);
#endif
    exports["vkCmdDispatchBase"] = Napi::Function::New(env, rawCmdDispatchBase);
#ifdef VK_KHR_device_group
    exports["vkGetPhysicalDevicePresentRectanglesKHR"] = Napi::Function::New(env, rawGetPhysicalDevicePresentRectanglesKHR);
#endif
    exports["vkCreateDescriptorUpdateTemplate"] = Napi::Function::New(env, rawCreateDescriptorUpdateTemplate);
    exports["vkDestroyDescriptorUpdateTemplate"] = Napi::Function::New(env, rawDestroyDescriptorUpdateTemplate);
    exports["vkUpdateDescriptorSetWithTemplate"] = Napi::Function::New(env, rawUpdateDescriptorSetWithTemplate);
#ifdef VK_KHR_descriptor_update_template
    exports["vkCmdPushDescriptorSetWithTemplateKHR"] = Napi::Function::New(env, rawCmdPushDescriptorSetWithTemplateKHR);
#endif
#ifdef VK_EXT_hdr_metadata
    exports["vkSetHdrMetadataEXT"] = Napi::Function::New(env, rawSetHdrMetadataEXT);
#endif
#ifdef VK_KHR_shared_presentable_image
    exports["vkGetSwapchainStatusKHR"] = Napi::Function::New(env, rawGetSwapchainStatusKHR);
#endif
#ifdef VK_GOOGLE_display_timing
    exports["vkGetRefreshCycleDurationGOOGLE"] = Napi::Function::New(env, rawGetRefreshCycleDurationGOOGLE);
#endif
#ifdef VK_GOOGLE_display_timing
    exports["vkGetPastPresentationTimingGOOGLE"] = Napi::Function::New(env, rawGetPastPresentationTimingGOOGLE);
#endif
#ifdef VK_MVK_ios_surface
    exports["vkCreateIOSSurfaceMVK"] = Napi::Function::New(env, rawCreateIOSSurfaceMVK);
#endif
#ifdef VK_MVK_macos_surface
    exports["vkCreateMacOSSurfaceMVK"] = Napi::Function::New(env, rawCreateMacOSSurfaceMVK);
#endif
#ifdef VK_EXT_metal_surface
    exports["vkCreateMetalSurfaceEXT"] = Napi::Function::New(env, rawCreateMetalSurfaceEXT);
#endif
#ifdef VK_NV_clip_space_w_scaling
    exports["vkCmdSetViewportWScalingNV"] = Napi::Function::New(env, rawCmdSetViewportWScalingNV);
#endif
#ifdef VK_EXT_discard_rectangles
    exports["vkCmdSetDiscardRectangleEXT"] = Napi::Function::New(env, rawCmdSetDiscardRectangleEXT);
#endif
#ifdef VK_EXT_sample_locations
    exports["vkCmdSetSampleLocationsEXT"] = Napi::Function::New(env, rawCmdSetSampleLocationsEXT);
#endif
#ifdef VK_EXT_sample_locations
    exports["vkGetPhysicalDeviceMultisamplePropertiesEXT"] = Napi::Function::New(env, rawGetPhysicalDeviceMultisamplePropertiesEXT);
#endif
#ifdef VK_KHR_get_surface_capabilities2
    exports["vkGetPhysicalDeviceSurfaceCapabilities2KHR"] = Napi::Function::New(env, rawGetPhysicalDeviceSurfaceCapabilities2KHR);
#endif
#ifdef VK_KHR_get_surface_capabilities2
    exports["vkGetPhysicalDeviceSurfaceFormats2KHR"] = Napi::Function::New(env, rawGetPhysicalDeviceSurfaceFormats2KHR);
#endif
#ifdef VK_KHR_get_display_properties2
    exports["vkGetPhysicalDeviceDisplayProperties2KHR"] = Napi::Function::New(env, rawGetPhysicalDeviceDisplayProperties2KHR);
#endif
#ifdef VK_KHR_get_display_properties2
    exports["vkGetPhysicalDeviceDisplayPlaneProperties2KHR"] = Napi::Function::New(env, rawGetPhysicalDeviceDisplayPlaneProperties2KHR);
#endif
#ifdef VK_KHR_get_display_properties2
    exports["vkGetDisplayModeProperties2KHR"] = Napi::Function::New(env, rawGetDisplayModeProperties2KHR);
#endif
#ifdef VK_KHR_get_display_properties2
    exports["vkGetDisplayPlaneCapabilities2KHR"] = Napi::Function::New(env, rawGetDisplayPlaneCapabilities2KHR);
#endif
    exports["vkGetBufferMemoryRequirements2"] = Napi::Function::New(env, rawGetBufferMemoryRequirements2);
    exports["vkGetImageMemoryRequirements2"] = Napi::Function::New(env, rawGetImageMemoryRequirements2);
    exports["vkGetImageSparseMemoryRequirements2"] = Napi::Function::New(env, rawGetImageSparseMemoryRequirements2);
    exports["vkGetDeviceBufferMemoryRequirements"] = Napi::Function::New(env, rawGetDeviceBufferMemoryRequirements);
    exports["vkGetDeviceImageMemoryRequirements"] = Napi::Function::New(env, rawGetDeviceImageMemoryRequirements);
    exports["vkGetDeviceImageSparseMemoryRequirements"] = Napi::Function::New(env, rawGetDeviceImageSparseMemoryRequirements);
    exports["vkCreateSamplerYcbcrConversion"] = Napi::Function::New(env, rawCreateSamplerYcbcrConversion);
    exports["vkDestroySamplerYcbcrConversion"] = Napi::Function::New(env, rawDestroySamplerYcbcrConversion);
    exports["vkGetDeviceQueue2"] = Napi::Function::New(env, rawGetDeviceQueue2);
#ifdef VK_EXT_validation_cache
    exports["vkCreateValidationCacheEXT"] = Napi::Function::New(env, rawCreateValidationCacheEXT);
#endif
#ifdef VK_EXT_validation_cache
    exports["vkDestroyValidationCacheEXT"] = Napi::Function::New(env, rawDestroyValidationCacheEXT);
#endif
#ifdef VK_EXT_validation_cache
    exports["vkGetValidationCacheDataEXT"] = Napi::Function::New(env, rawGetValidationCacheDataEXT);
#endif
#ifdef VK_EXT_validation_cache
    exports["vkMergeValidationCachesEXT"] = Napi::Function::New(env, rawMergeValidationCachesEXT);
#endif
    exports["vkGetDescriptorSetLayoutSupport"] = Napi::Function::New(env, rawGetDescriptorSetLayoutSupport);
#ifdef VK_ANDROID_native_buffer
    exports["vkGetSwapchainGrallocUsageANDROID"] = Napi::Function::New(env, rawGetSwapchainGrallocUsageANDROID);
#endif
#ifdef VK_ANDROID_native_buffer
    exports["vkGetSwapchainGrallocUsage2ANDROID"] = Napi::Function::New(env, rawGetSwapchainGrallocUsage2ANDROID);
#endif
#ifdef VK_ANDROID_native_buffer
    exports["vkAcquireImageANDROID"] = Napi::Function::New(env, rawAcquireImageANDROID);
#endif
#ifdef VK_ANDROID_native_buffer
    exports["vkQueueSignalReleaseImageANDROID"] = Napi::Function::New(env, rawQueueSignalReleaseImageANDROID);
#endif
#ifdef VK_AMD_shader_info
    exports["vkGetShaderInfoAMD"] = Napi::Function::New(env, rawGetShaderInfoAMD);
#endif
#ifdef VK_AMD_display_native_hdr
    exports["vkSetLocalDimmingAMD"] = Napi::Function::New(env, rawSetLocalDimmingAMD);
#endif
#ifdef VK_EXT_calibrated_timestamps
    exports["vkGetPhysicalDeviceCalibrateableTimeDomainsEXT"] = Napi::Function::New(env, rawGetPhysicalDeviceCalibrateableTimeDomainsEXT);
#endif
#ifdef VK_EXT_calibrated_timestamps
    exports["vkGetCalibratedTimestampsEXT"] = Napi::Function::New(env, rawGetCalibratedTimestampsEXT);
#endif
#ifdef VK_EXT_debug_utils
    exports["vkSetDebugUtilsObjectNameEXT"] = Napi::Function::New(env, rawSetDebugUtilsObjectNameEXT);
#endif
#ifdef VK_EXT_debug_utils
    exports["vkSetDebugUtilsObjectTagEXT"] = Napi::Function::New(env, rawSetDebugUtilsObjectTagEXT);
#endif
#ifdef VK_EXT_debug_utils
    exports["vkQueueBeginDebugUtilsLabelEXT"] = Napi::Function::New(env, rawQueueBeginDebugUtilsLabelEXT);
#endif
#ifdef VK_EXT_debug_utils
    exports["vkQueueEndDebugUtilsLabelEXT"] = Napi::Function::New(env, rawQueueEndDebugUtilsLabelEXT);
#endif
#ifdef VK_EXT_debug_utils
    exports["vkQueueInsertDebugUtilsLabelEXT"] = Napi::Function::New(env, rawQueueInsertDebugUtilsLabelEXT);
#endif
#ifdef VK_EXT_debug_utils
    exports["vkCmdBeginDebugUtilsLabelEXT"] = Napi::Function::New(env, rawCmdBeginDebugUtilsLabelEXT);
#endif
#ifdef VK_EXT_debug_utils
    exports["vkCmdEndDebugUtilsLabelEXT"] = Napi::Function::New(env, rawCmdEndDebugUtilsLabelEXT);
#endif
#ifdef VK_EXT_debug_utils
    exports["vkCmdInsertDebugUtilsLabelEXT"] = Napi::Function::New(env, rawCmdInsertDebugUtilsLabelEXT);
#endif
#ifdef VK_EXT_debug_utils
    exports["vkCreateDebugUtilsMessengerEXT"] = Napi::Function::New(env, rawCreateDebugUtilsMessengerEXT);
#endif
#ifdef VK_EXT_debug_utils
    exports["vkDestroyDebugUtilsMessengerEXT"] = Napi::Function::New(env, rawDestroyDebugUtilsMessengerEXT);
#endif
#ifdef VK_EXT_debug_utils
    exports["vkSubmitDebugUtilsMessageEXT"] = Napi::Function::New(env, rawSubmitDebugUtilsMessageEXT);
#endif
#ifdef VK_EXT_external_memory_host
    exports["vkGetMemoryHostPointerPropertiesEXT"] = Napi::Function::New(env, rawGetMemoryHostPointerPropertiesEXT);
#endif
#ifdef VK_AMD_buffer_marker
    exports["vkCmdWriteBufferMarkerAMD"] = Napi::Function::New(env, rawCmdWriteBufferMarkerAMD);
#endif
    exports["vkCreateRenderPass2"] = Napi::Function::New(env, rawCreateRenderPass2);
    exports["vkCmdBeginRenderPass2"] = Napi::Function::New(env, rawCmdBeginRenderPass2);
    exports["vkCmdNextSubpass2"] = Napi::Function::New(env, rawCmdNextSubpass2);
    exports["vkCmdEndRenderPass2"] = Napi::Function::New(env, rawCmdEndRenderPass2);
    exports["vkGetSemaphoreCounterValue"] = Napi::Function::New(env, rawGetSemaphoreCounterValue);
    exports["vkWaitSemaphores"] = Napi::Function::New(env, rawWaitSemaphores);
    exports["vkSignalSemaphore"] = Napi::Function::New(env, rawSignalSemaphore);
#ifdef VK_ANDROID_external_memory_android_hardware_buffer
    exports["vkGetAndroidHardwareBufferPropertiesANDROID"] = Napi::Function::New(env, rawGetAndroidHardwareBufferPropertiesANDROID);
#endif
#ifdef VK_ANDROID_external_memory_android_hardware_buffer
    exports["vkGetMemoryAndroidHardwareBufferANDROID"] = Napi::Function::New(env, rawGetMemoryAndroidHardwareBufferANDROID);
#endif
    exports["vkCmdDrawIndirectCount"] = Napi::Function::New(env, rawCmdDrawIndirectCount);
    exports["vkCmdDrawIndexedIndirectCount"] = Napi::Function::New(env, rawCmdDrawIndexedIndirectCount);
#ifdef VK_NV_device_diagnostic_checkpoints
    exports["vkCmdSetCheckpointNV"] = Napi::Function::New(env, rawCmdSetCheckpointNV);
#endif
#ifdef VK_NV_device_diagnostic_checkpoints
    exports["vkGetQueueCheckpointDataNV"] = Napi::Function::New(env, rawGetQueueCheckpointDataNV);
#endif
#ifdef VK_EXT_transform_feedback
    exports["vkCmdBindTransformFeedbackBuffersEXT"] = Napi::Function::New(env, rawCmdBindTransformFeedbackBuffersEXT);
#endif
#ifdef VK_EXT_transform_feedback
    exports["vkCmdBeginTransformFeedbackEXT"] = Napi::Function::New(env, rawCmdBeginTransformFeedbackEXT);
#endif
#ifdef VK_EXT_transform_feedback
    exports["vkCmdEndTransformFeedbackEXT"] = Napi::Function::New(env, rawCmdEndTransformFeedbackEXT);
#endif
#ifdef VK_EXT_transform_feedback
    exports["vkCmdBeginQueryIndexedEXT"] = Napi::Function::New(env, rawCmdBeginQueryIndexedEXT);
#endif
#ifdef VK_EXT_transform_feedback
    exports["vkCmdEndQueryIndexedEXT"] = Napi::Function::New(env, rawCmdEndQueryIndexedEXT);
#endif
#ifdef VK_EXT_transform_feedback
    exports["vkCmdDrawIndirectByteCountEXT"] = Napi::Function::New(env, rawCmdDrawIndirectByteCountEXT);
#endif
#ifdef VK_NV_scissor_exclusive
    exports["vkCmdSetExclusiveScissorNV"] = Napi::Function::New(env, rawCmdSetExclusiveScissorNV);
#endif
#ifdef VK_NV_shading_rate_image
    exports["vkCmdBindShadingRateImageNV"] = Napi::Function::New(env, rawCmdBindShadingRateImageNV);
#endif
#ifdef VK_NV_shading_rate_image
    exports["vkCmdSetViewportShadingRatePaletteNV"] = Napi::Function::New(env, rawCmdSetViewportShadingRatePaletteNV);
#endif
#ifdef VK_NV_shading_rate_image
    exports["vkCmdSetCoarseSampleOrderNV"] = Napi::Function::New(env, rawCmdSetCoarseSampleOrderNV);
#endif
#ifdef VK_NV_mesh_shader
    exports["vkCmdDrawMeshTasksNV"] = Napi::Function::New(env, rawCmdDrawMeshTasksNV);
#endif
#ifdef VK_NV_mesh_shader
    exports["vkCmdDrawMeshTasksIndirectNV"] = Napi::Function::New(env, rawCmdDrawMeshTasksIndirectNV);
#endif
#ifdef VK_NV_mesh_shader
    exports["vkCmdDrawMeshTasksIndirectCountNV"] = Napi::Function::New(env, rawCmdDrawMeshTasksIndirectCountNV);
#endif
#ifdef VK_EXT_mesh_shader
    exports["vkCmdDrawMeshTasksEXT"] = Napi::Function::New(env, rawCmdDrawMeshTasksEXT);
#endif
#ifdef VK_EXT_mesh_shader
    exports["vkCmdDrawMeshTasksIndirectEXT"] = Napi::Function::New(env, rawCmdDrawMeshTasksIndirectEXT);
#endif
#ifdef VK_EXT_mesh_shader
    exports["vkCmdDrawMeshTasksIndirectCountEXT"] = Napi::Function::New(env, rawCmdDrawMeshTasksIndirectCountEXT);
#endif
#ifdef VK_NV_ray_tracing
    exports["vkCompileDeferredNV"] = Napi::Function::New(env, rawCompileDeferredNV);
#endif
#ifdef VK_NV_ray_tracing
    exports["vkCreateAccelerationStructureNV"] = Napi::Function::New(env, rawCreateAccelerationStructureNV);
#endif
#ifdef VK_HUAWEI_invocation_mask
    exports["vkCmdBindInvocationMaskHUAWEI"] = Napi::Function::New(env, rawCmdBindInvocationMaskHUAWEI);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkDestroyAccelerationStructureKHR"] = Napi::Function::New(env, rawDestroyAccelerationStructureKHR);
#endif
#ifdef VK_NV_ray_tracing
    exports["vkDestroyAccelerationStructureNV"] = Napi::Function::New(env, rawDestroyAccelerationStructureNV);
#endif
#ifdef VK_NV_ray_tracing
    exports["vkGetAccelerationStructureMemoryRequirementsNV"] = Napi::Function::New(env, rawGetAccelerationStructureMemoryRequirementsNV);
#endif
#ifdef VK_NV_ray_tracing
    exports["vkBindAccelerationStructureMemoryNV"] = Napi::Function::New(env, rawBindAccelerationStructureMemoryNV);
#endif
#ifdef VK_NV_ray_tracing
    exports["vkCmdCopyAccelerationStructureNV"] = Napi::Function::New(env, rawCmdCopyAccelerationStructureNV);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkCmdCopyAccelerationStructureKHR"] = Napi::Function::New(env, rawCmdCopyAccelerationStructureKHR);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkCopyAccelerationStructureKHR"] = Napi::Function::New(env, rawCopyAccelerationStructureKHR);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkCmdCopyAccelerationStructureToMemoryKHR"] = Napi::Function::New(env, rawCmdCopyAccelerationStructureToMemoryKHR);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkCopyAccelerationStructureToMemoryKHR"] = Napi::Function::New(env, rawCopyAccelerationStructureToMemoryKHR);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkCmdCopyMemoryToAccelerationStructureKHR"] = Napi::Function::New(env, rawCmdCopyMemoryToAccelerationStructureKHR);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkCopyMemoryToAccelerationStructureKHR"] = Napi::Function::New(env, rawCopyMemoryToAccelerationStructureKHR);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkCmdWriteAccelerationStructuresPropertiesKHR"] = Napi::Function::New(env, rawCmdWriteAccelerationStructuresPropertiesKHR);
#endif
#ifdef VK_NV_ray_tracing
    exports["vkCmdWriteAccelerationStructuresPropertiesNV"] = Napi::Function::New(env, rawCmdWriteAccelerationStructuresPropertiesNV);
#endif
#ifdef VK_NV_ray_tracing
    exports["vkCmdBuildAccelerationStructureNV"] = Napi::Function::New(env, rawCmdBuildAccelerationStructureNV);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkWriteAccelerationStructuresPropertiesKHR"] = Napi::Function::New(env, rawWriteAccelerationStructuresPropertiesKHR);
#endif
#ifdef VK_KHR_ray_tracing_pipeline
    exports["vkCmdTraceRaysKHR"] = Napi::Function::New(env, rawCmdTraceRaysKHR);
#endif
#ifdef VK_NV_ray_tracing
    exports["vkCmdTraceRaysNV"] = Napi::Function::New(env, rawCmdTraceRaysNV);
#endif
#ifdef VK_KHR_ray_tracing_pipeline
    exports["vkGetRayTracingShaderGroupHandlesKHR"] = Napi::Function::New(env, rawGetRayTracingShaderGroupHandlesKHR);
#endif
#ifdef VK_KHR_ray_tracing_pipeline
    exports["vkGetRayTracingCaptureReplayShaderGroupHandlesKHR"] = Napi::Function::New(env, rawGetRayTracingCaptureReplayShaderGroupHandlesKHR);
#endif
#ifdef VK_NV_ray_tracing
    exports["vkGetAccelerationStructureHandleNV"] = Napi::Function::New(env, rawGetAccelerationStructureHandleNV);
#endif
#ifdef VK_NV_ray_tracing
    exports["vkCreateRayTracingPipelinesNV"] = Napi::Function::New(env, rawCreateRayTracingPipelinesNV);
#endif
#ifdef VK_KHR_ray_tracing_pipeline
    exports["vkCreateRayTracingPipelinesKHR"] = Napi::Function::New(env, rawCreateRayTracingPipelinesKHR);
#endif
#ifdef VK_NV_cooperative_matrix
    exports["vkGetPhysicalDeviceCooperativeMatrixPropertiesNV"] = Napi::Function::New(env, rawGetPhysicalDeviceCooperativeMatrixPropertiesNV);
#endif
#ifdef VK_KHR_ray_tracing_pipeline
    exports["vkCmdTraceRaysIndirectKHR"] = Napi::Function::New(env, rawCmdTraceRaysIndirectKHR);
#endif
#ifdef VK_KHR_ray_tracing_maintenance1
    exports["vkCmdTraceRaysIndirect2KHR"] = Napi::Function::New(env, rawCmdTraceRaysIndirect2KHR);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkGetDeviceAccelerationStructureCompatibilityKHR"] = Napi::Function::New(env, rawGetDeviceAccelerationStructureCompatibilityKHR);
#endif
#ifdef VK_KHR_ray_tracing_pipeline
    exports["vkGetRayTracingShaderGroupStackSizeKHR"] = Napi::Function::New(env, rawGetRayTracingShaderGroupStackSizeKHR);
#endif
#ifdef VK_KHR_ray_tracing_pipeline
    exports["vkCmdSetRayTracingPipelineStackSizeKHR"] = Napi::Function::New(env, rawCmdSetRayTracingPipelineStackSizeKHR);
#endif
#ifdef VK_NVX_image_view_handle
    exports["vkGetImageViewHandleNVX"] = Napi::Function::New(env, rawGetImageViewHandleNVX);
#endif
#ifdef VK_NVX_image_view_handle
    exports["vkGetImageViewAddressNVX"] = Napi::Function::New(env, rawGetImageViewAddressNVX);
#endif
#ifdef VK_EXT_full_screen_exclusive
    exports["vkGetPhysicalDeviceSurfacePresentModes2EXT"] = Napi::Function::New(env, rawGetPhysicalDeviceSurfacePresentModes2EXT);
#endif
#ifdef VK_EXT_full_screen_exclusive
    exports["vkGetDeviceGroupSurfacePresentModes2EXT"] = Napi::Function::New(env, rawGetDeviceGroupSurfacePresentModes2EXT);
#endif
#ifdef VK_EXT_full_screen_exclusive
    exports["vkAcquireFullScreenExclusiveModeEXT"] = Napi::Function::New(env, rawAcquireFullScreenExclusiveModeEXT);
#endif
#ifdef VK_EXT_full_screen_exclusive
    exports["vkReleaseFullScreenExclusiveModeEXT"] = Napi::Function::New(env, rawReleaseFullScreenExclusiveModeEXT);
#endif
#ifdef VK_KHR_performance_query
    exports["vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR"] = Napi::Function::New(env, rawEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
#endif
#ifdef VK_KHR_performance_query
    exports["vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
#endif
#ifdef VK_KHR_performance_query
    exports["vkAcquireProfilingLockKHR"] = Napi::Function::New(env, rawAcquireProfilingLockKHR);
#endif
#ifdef VK_KHR_performance_query
    exports["vkReleaseProfilingLockKHR"] = Napi::Function::New(env, rawReleaseProfilingLockKHR);
#endif
#ifdef VK_EXT_image_drm_format_modifier
    exports["vkGetImageDrmFormatModifierPropertiesEXT"] = Napi::Function::New(env, rawGetImageDrmFormatModifierPropertiesEXT);
#endif
    exports["vkGetBufferOpaqueCaptureAddress"] = Napi::Function::New(env, rawGetBufferOpaqueCaptureAddress);
    exports["vkGetBufferDeviceAddress"] = Napi::Function::New(env, rawGetBufferDeviceAddress);
#ifdef VK_EXT_headless_surface
    exports["vkCreateHeadlessSurfaceEXT"] = Napi::Function::New(env, rawCreateHeadlessSurfaceEXT);
#endif
#ifdef VK_NV_coverage_reduction_mode
    exports["vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV"] = Napi::Function::New(env, rawGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
#endif
#ifdef VK_INTEL_performance_query
    exports["vkInitializePerformanceApiINTEL"] = Napi::Function::New(env, rawInitializePerformanceApiINTEL);
#endif
#ifdef VK_INTEL_performance_query
    exports["vkUninitializePerformanceApiINTEL"] = Napi::Function::New(env, rawUninitializePerformanceApiINTEL);
#endif
#ifdef VK_INTEL_performance_query
    exports["vkCmdSetPerformanceMarkerINTEL"] = Napi::Function::New(env, rawCmdSetPerformanceMarkerINTEL);
#endif
#ifdef VK_INTEL_performance_query
    exports["vkCmdSetPerformanceStreamMarkerINTEL"] = Napi::Function::New(env, rawCmdSetPerformanceStreamMarkerINTEL);
#endif
#ifdef VK_INTEL_performance_query
    exports["vkCmdSetPerformanceOverrideINTEL"] = Napi::Function::New(env, rawCmdSetPerformanceOverrideINTEL);
#endif
#ifdef VK_INTEL_performance_query
    exports["vkAcquirePerformanceConfigurationINTEL"] = Napi::Function::New(env, rawAcquirePerformanceConfigurationINTEL);
#endif
#ifdef VK_INTEL_performance_query
    exports["vkReleasePerformanceConfigurationINTEL"] = Napi::Function::New(env, rawReleasePerformanceConfigurationINTEL);
#endif
#ifdef VK_INTEL_performance_query
    exports["vkQueueSetPerformanceConfigurationINTEL"] = Napi::Function::New(env, rawQueueSetPerformanceConfigurationINTEL);
#endif
#ifdef VK_INTEL_performance_query
    exports["vkGetPerformanceParameterINTEL"] = Napi::Function::New(env, rawGetPerformanceParameterINTEL);
#endif
    exports["vkGetDeviceMemoryOpaqueCaptureAddress"] = Napi::Function::New(env, rawGetDeviceMemoryOpaqueCaptureAddress);
#ifdef VK_KHR_pipeline_executable_properties
    exports["vkGetPipelineExecutablePropertiesKHR"] = Napi::Function::New(env, rawGetPipelineExecutablePropertiesKHR);
#endif
#ifdef VK_KHR_pipeline_executable_properties
    exports["vkGetPipelineExecutableStatisticsKHR"] = Napi::Function::New(env, rawGetPipelineExecutableStatisticsKHR);
#endif
#ifdef VK_KHR_pipeline_executable_properties
    exports["vkGetPipelineExecutableInternalRepresentationsKHR"] = Napi::Function::New(env, rawGetPipelineExecutableInternalRepresentationsKHR);
#endif
#ifdef VK_EXT_line_rasterization
    exports["vkCmdSetLineStippleEXT"] = Napi::Function::New(env, rawCmdSetLineStippleEXT);
#endif
    exports["vkGetPhysicalDeviceToolProperties"] = Napi::Function::New(env, rawGetPhysicalDeviceToolProperties);
#ifdef VK_KHR_acceleration_structure
    exports["vkCreateAccelerationStructureKHR"] = Napi::Function::New(env, rawCreateAccelerationStructureKHR);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkCmdBuildAccelerationStructuresKHR"] = Napi::Function::New(env, rawCmdBuildAccelerationStructuresKHR);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkCmdBuildAccelerationStructuresIndirectKHR"] = Napi::Function::New(env, rawCmdBuildAccelerationStructuresIndirectKHR);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkBuildAccelerationStructuresKHR"] = Napi::Function::New(env, rawBuildAccelerationStructuresKHR);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkGetAccelerationStructureDeviceAddressKHR"] = Napi::Function::New(env, rawGetAccelerationStructureDeviceAddressKHR);
#endif
#ifdef VK_KHR_deferred_host_operations
    exports["vkCreateDeferredOperationKHR"] = Napi::Function::New(env, rawCreateDeferredOperationKHR);
#endif
#ifdef VK_KHR_deferred_host_operations
    exports["vkDestroyDeferredOperationKHR"] = Napi::Function::New(env, rawDestroyDeferredOperationKHR);
#endif
#ifdef VK_KHR_deferred_host_operations
    exports["vkGetDeferredOperationMaxConcurrencyKHR"] = Napi::Function::New(env, rawGetDeferredOperationMaxConcurrencyKHR);
#endif
#ifdef VK_KHR_deferred_host_operations
    exports["vkGetDeferredOperationResultKHR"] = Napi::Function::New(env, rawGetDeferredOperationResultKHR);
#endif
#ifdef VK_KHR_deferred_host_operations
    exports["vkDeferredOperationJoinKHR"] = Napi::Function::New(env, rawDeferredOperationJoinKHR);
#endif
    exports["vkCmdSetCullMode"] = Napi::Function::New(env, rawCmdSetCullMode);
    exports["vkCmdSetFrontFace"] = Napi::Function::New(env, rawCmdSetFrontFace);
    exports["vkCmdSetPrimitiveTopology"] = Napi::Function::New(env, rawCmdSetPrimitiveTopology);
    exports["vkCmdSetViewportWithCount"] = Napi::Function::New(env, rawCmdSetViewportWithCount);
    exports["vkCmdSetScissorWithCount"] = Napi::Function::New(env, rawCmdSetScissorWithCount);
    exports["vkCmdBindVertexBuffers2"] = Napi::Function::New(env, rawCmdBindVertexBuffers2);
    exports["vkCmdSetDepthTestEnable"] = Napi::Function::New(env, rawCmdSetDepthTestEnable);
    exports["vkCmdSetDepthWriteEnable"] = Napi::Function::New(env, rawCmdSetDepthWriteEnable);
    exports["vkCmdSetDepthCompareOp"] = Napi::Function::New(env, rawCmdSetDepthCompareOp);
    exports["vkCmdSetDepthBoundsTestEnable"] = Napi::Function::New(env, rawCmdSetDepthBoundsTestEnable);
    exports["vkCmdSetStencilTestEnable"] = Napi::Function::New(env, rawCmdSetStencilTestEnable);
    exports["vkCmdSetStencilOp"] = Napi::Function::New(env, rawCmdSetStencilOp);
#ifdef VK_EXT_extended_dynamic_state2
    exports["vkCmdSetPatchControlPointsEXT"] = Napi::Function::New(env, rawCmdSetPatchControlPointsEXT);
#endif
    exports["vkCmdSetRasterizerDiscardEnable"] = Napi::Function::New(env, rawCmdSetRasterizerDiscardEnable);
    exports["vkCmdSetDepthBiasEnable"] = Napi::Function::New(env, rawCmdSetDepthBiasEnable);
#ifdef VK_EXT_extended_dynamic_state2
    exports["vkCmdSetLogicOpEXT"] = Napi::Function::New(env, rawCmdSetLogicOpEXT);
#endif
    exports["vkCmdSetPrimitiveRestartEnable"] = Napi::Function::New(env, rawCmdSetPrimitiveRestartEnable);
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetTessellationDomainOriginEXT"] = Napi::Function::New(env, rawCmdSetTessellationDomainOriginEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetDepthClampEnableEXT"] = Napi::Function::New(env, rawCmdSetDepthClampEnableEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetPolygonModeEXT"] = Napi::Function::New(env, rawCmdSetPolygonModeEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetRasterizationSamplesEXT"] = Napi::Function::New(env, rawCmdSetRasterizationSamplesEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetSampleMaskEXT"] = Napi::Function::New(env, rawCmdSetSampleMaskEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetAlphaToCoverageEnableEXT"] = Napi::Function::New(env, rawCmdSetAlphaToCoverageEnableEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetAlphaToOneEnableEXT"] = Napi::Function::New(env, rawCmdSetAlphaToOneEnableEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetLogicOpEnableEXT"] = Napi::Function::New(env, rawCmdSetLogicOpEnableEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetColorBlendEnableEXT"] = Napi::Function::New(env, rawCmdSetColorBlendEnableEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetColorBlendEquationEXT"] = Napi::Function::New(env, rawCmdSetColorBlendEquationEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetColorWriteMaskEXT"] = Napi::Function::New(env, rawCmdSetColorWriteMaskEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetRasterizationStreamEXT"] = Napi::Function::New(env, rawCmdSetRasterizationStreamEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetConservativeRasterizationModeEXT"] = Napi::Function::New(env, rawCmdSetConservativeRasterizationModeEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetExtraPrimitiveOverestimationSizeEXT"] = Napi::Function::New(env, rawCmdSetExtraPrimitiveOverestimationSizeEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetDepthClipEnableEXT"] = Napi::Function::New(env, rawCmdSetDepthClipEnableEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetSampleLocationsEnableEXT"] = Napi::Function::New(env, rawCmdSetSampleLocationsEnableEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetColorBlendAdvancedEXT"] = Napi::Function::New(env, rawCmdSetColorBlendAdvancedEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetProvokingVertexModeEXT"] = Napi::Function::New(env, rawCmdSetProvokingVertexModeEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetLineRasterizationModeEXT"] = Napi::Function::New(env, rawCmdSetLineRasterizationModeEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetLineStippleEnableEXT"] = Napi::Function::New(env, rawCmdSetLineStippleEnableEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetDepthClipNegativeOneToOneEXT"] = Napi::Function::New(env, rawCmdSetDepthClipNegativeOneToOneEXT);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetViewportWScalingEnableNV"] = Napi::Function::New(env, rawCmdSetViewportWScalingEnableNV);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetViewportSwizzleNV"] = Napi::Function::New(env, rawCmdSetViewportSwizzleNV);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetCoverageToColorEnableNV"] = Napi::Function::New(env, rawCmdSetCoverageToColorEnableNV);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetCoverageToColorLocationNV"] = Napi::Function::New(env, rawCmdSetCoverageToColorLocationNV);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetCoverageModulationModeNV"] = Napi::Function::New(env, rawCmdSetCoverageModulationModeNV);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetCoverageModulationTableEnableNV"] = Napi::Function::New(env, rawCmdSetCoverageModulationTableEnableNV);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetCoverageModulationTableNV"] = Napi::Function::New(env, rawCmdSetCoverageModulationTableNV);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetShadingRateImageEnableNV"] = Napi::Function::New(env, rawCmdSetShadingRateImageEnableNV);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetCoverageReductionModeNV"] = Napi::Function::New(env, rawCmdSetCoverageReductionModeNV);
#endif
#ifdef VK_EXT_extended_dynamic_state3
    exports["vkCmdSetRepresentativeFragmentTestEnableNV"] = Napi::Function::New(env, rawCmdSetRepresentativeFragmentTestEnableNV);
#endif
    exports["vkCreatePrivateDataSlot"] = Napi::Function::New(env, rawCreatePrivateDataSlot);
    exports["vkDestroyPrivateDataSlot"] = Napi::Function::New(env, rawDestroyPrivateDataSlot);
    exports["vkSetPrivateData"] = Napi::Function::New(env, rawSetPrivateData);
    exports["vkGetPrivateData"] = Napi::Function::New(env, rawGetPrivateData);
    exports["vkCmdCopyBuffer2"] = Napi::Function::New(env, rawCmdCopyBuffer2);
    exports["vkCmdCopyImage2"] = Napi::Function::New(env, rawCmdCopyImage2);
    exports["vkCmdBlitImage2"] = Napi::Function::New(env, rawCmdBlitImage2);
    exports["vkCmdCopyBufferToImage2"] = Napi::Function::New(env, rawCmdCopyBufferToImage2);
    exports["vkCmdCopyImageToBuffer2"] = Napi::Function::New(env, rawCmdCopyImageToBuffer2);
    exports["vkCmdResolveImage2"] = Napi::Function::New(env, rawCmdResolveImage2);
#ifdef VK_KHR_fragment_shading_rate
    exports["vkCmdSetFragmentShadingRateKHR"] = Napi::Function::New(env, rawCmdSetFragmentShadingRateKHR);
#endif
#ifdef VK_KHR_fragment_shading_rate
    exports["vkGetPhysicalDeviceFragmentShadingRatesKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceFragmentShadingRatesKHR);
#endif
#ifdef VK_NV_fragment_shading_rate_enums
    exports["vkCmdSetFragmentShadingRateEnumNV"] = Napi::Function::New(env, rawCmdSetFragmentShadingRateEnumNV);
#endif
#ifdef VK_KHR_acceleration_structure
    exports["vkGetAccelerationStructureBuildSizesKHR"] = Napi::Function::New(env, rawGetAccelerationStructureBuildSizesKHR);
#endif
#ifdef VK_EXT_vertex_input_dynamic_state
    exports["vkCmdSetVertexInputEXT"] = Napi::Function::New(env, rawCmdSetVertexInputEXT);
#endif
#ifdef VK_EXT_color_write_enable
    exports["vkCmdSetColorWriteEnableEXT"] = Napi::Function::New(env, rawCmdSetColorWriteEnableEXT);
#endif
    exports["vkCmdSetEvent2"] = Napi::Function::New(env, rawCmdSetEvent2);
    exports["vkCmdResetEvent2"] = Napi::Function::New(env, rawCmdResetEvent2);
    exports["vkCmdWaitEvents2"] = Napi::Function::New(env, rawCmdWaitEvents2);
    exports["vkCmdPipelineBarrier2"] = Napi::Function::New(env, rawCmdPipelineBarrier2);
    exports["vkQueueSubmit2"] = Napi::Function::New(env, rawQueueSubmit2);
    exports["vkCmdWriteTimestamp2"] = Napi::Function::New(env, rawCmdWriteTimestamp2);
#ifdef VK_KHR_synchronization2
    exports["vkCmdWriteBufferMarker2AMD"] = Napi::Function::New(env, rawCmdWriteBufferMarker2AMD);
#endif
#ifdef VK_KHR_synchronization2
    exports["vkGetQueueCheckpointData2NV"] = Napi::Function::New(env, rawGetQueueCheckpointData2NV);
#endif
#ifdef VK_KHR_video_queue
    exports["vkGetPhysicalDeviceVideoCapabilitiesKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceVideoCapabilitiesKHR);
#endif
#ifdef VK_KHR_video_queue
    exports["vkGetPhysicalDeviceVideoFormatPropertiesKHR"] = Napi::Function::New(env, rawGetPhysicalDeviceVideoFormatPropertiesKHR);
#endif
#ifdef VK_KHR_video_queue
    exports["vkCreateVideoSessionKHR"] = Napi::Function::New(env, rawCreateVideoSessionKHR);
#endif
#ifdef VK_KHR_video_queue
    exports["vkDestroyVideoSessionKHR"] = Napi::Function::New(env, rawDestroyVideoSessionKHR);
#endif
#ifdef VK_KHR_video_queue
    exports["vkCreateVideoSessionParametersKHR"] = Napi::Function::New(env, rawCreateVideoSessionParametersKHR);
#endif
#ifdef VK_KHR_video_queue
    exports["vkUpdateVideoSessionParametersKHR"] = Napi::Function::New(env, rawUpdateVideoSessionParametersKHR);
#endif
#ifdef VK_KHR_video_queue
    exports["vkDestroyVideoSessionParametersKHR"] = Napi::Function::New(env, rawDestroyVideoSessionParametersKHR);
#endif
#ifdef VK_KHR_video_queue
    exports["vkGetVideoSessionMemoryRequirementsKHR"] = Napi::Function::New(env, rawGetVideoSessionMemoryRequirementsKHR);
#endif
#ifdef VK_KHR_video_queue
    exports["vkBindVideoSessionMemoryKHR"] = Napi::Function::New(env, rawBindVideoSessionMemoryKHR);
#endif
#ifdef VK_KHR_video_decode_queue
    exports["vkCmdDecodeVideoKHR"] = Napi::Function::New(env, rawCmdDecodeVideoKHR);
#endif
#ifdef VK_KHR_video_queue
    exports["vkCmdBeginVideoCodingKHR"] = Napi::Function::New(env, rawCmdBeginVideoCodingKHR);
#endif
#ifdef VK_KHR_video_queue
    exports["vkCmdControlVideoCodingKHR"] = Napi::Function::New(env, rawCmdControlVideoCodingKHR);
#endif
#ifdef VK_KHR_video_queue
    exports["vkCmdEndVideoCodingKHR"] = Napi::Function::New(env, rawCmdEndVideoCodingKHR);
#endif
#ifdef VK_KHR_video_encode_queue
    exports["vkCmdEncodeVideoKHR"] = Napi::Function::New(env, rawCmdEncodeVideoKHR);
#endif
#ifdef VK_NV_memory_decompression
    exports["vkCmdDecompressMemoryNV"] = Napi::Function::New(env, rawCmdDecompressMemoryNV);
#endif
#ifdef VK_NV_memory_decompression
    exports["vkCmdDecompressMemoryIndirectCountNV"] = Napi::Function::New(env, rawCmdDecompressMemoryIndirectCountNV);
#endif
#ifdef VK_NVX_binary_import
    exports["vkCreateCuModuleNVX"] = Napi::Function::New(env, rawCreateCuModuleNVX);
#endif
#ifdef VK_NVX_binary_import
    exports["vkCreateCuFunctionNVX"] = Napi::Function::New(env, rawCreateCuFunctionNVX);
#endif
#ifdef VK_NVX_binary_import
    exports["vkDestroyCuModuleNVX"] = Napi::Function::New(env, rawDestroyCuModuleNVX);
#endif
#ifdef VK_NVX_binary_import
    exports["vkDestroyCuFunctionNVX"] = Napi::Function::New(env, rawDestroyCuFunctionNVX);
#endif
#ifdef VK_NVX_binary_import
    exports["vkCmdCuLaunchKernelNVX"] = Napi::Function::New(env, rawCmdCuLaunchKernelNVX);
#endif
#ifdef VK_EXT_pageable_device_local_memory
    exports["vkSetDeviceMemoryPriorityEXT"] = Napi::Function::New(env, rawSetDeviceMemoryPriorityEXT);
#endif
#ifdef VK_EXT_acquire_drm_display
    exports["vkAcquireDrmDisplayEXT"] = Napi::Function::New(env, rawAcquireDrmDisplayEXT);
#endif
#ifdef VK_EXT_acquire_drm_display
    exports["vkGetDrmDisplayEXT"] = Napi::Function::New(env, rawGetDrmDisplayEXT);
#endif
#ifdef VK_KHR_present_wait
    exports["vkWaitForPresentKHR"] = Napi::Function::New(env, rawWaitForPresentKHR);
#endif
#ifdef VK_FUCHSIA_buffer_collection
    exports["vkCreateBufferCollectionFUCHSIA"] = Napi::Function::New(env, rawCreateBufferCollectionFUCHSIA);
#endif
#ifdef VK_FUCHSIA_buffer_collection
    exports["vkSetBufferCollectionBufferConstraintsFUCHSIA"] = Napi::Function::New(env, rawSetBufferCollectionBufferConstraintsFUCHSIA);
#endif
#ifdef VK_FUCHSIA_buffer_collection
    exports["vkSetBufferCollectionImageConstraintsFUCHSIA"] = Napi::Function::New(env, rawSetBufferCollectionImageConstraintsFUCHSIA);
#endif
#ifdef VK_FUCHSIA_buffer_collection
    exports["vkDestroyBufferCollectionFUCHSIA"] = Napi::Function::New(env, rawDestroyBufferCollectionFUCHSIA);
#endif
#ifdef VK_FUCHSIA_buffer_collection
    exports["vkGetBufferCollectionPropertiesFUCHSIA"] = Napi::Function::New(env, rawGetBufferCollectionPropertiesFUCHSIA);
#endif
    exports["vkCmdBeginRendering"] = Napi::Function::New(env, rawCmdBeginRendering);
    exports["vkCmdEndRendering"] = Napi::Function::New(env, rawCmdEndRendering);
#ifdef VK_VALVE_descriptor_set_host_mapping
    exports["vkGetDescriptorSetLayoutHostMappingInfoVALVE"] = Napi::Function::New(env, rawGetDescriptorSetLayoutHostMappingInfoVALVE);
#endif
#ifdef VK_VALVE_descriptor_set_host_mapping
    exports["vkGetDescriptorSetHostMappingVALVE"] = Napi::Function::New(env, rawGetDescriptorSetHostMappingVALVE);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkCreateMicromapEXT"] = Napi::Function::New(env, rawCreateMicromapEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkCmdBuildMicromapsEXT"] = Napi::Function::New(env, rawCmdBuildMicromapsEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkBuildMicromapsEXT"] = Napi::Function::New(env, rawBuildMicromapsEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkDestroyMicromapEXT"] = Napi::Function::New(env, rawDestroyMicromapEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkCmdCopyMicromapEXT"] = Napi::Function::New(env, rawCmdCopyMicromapEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkCopyMicromapEXT"] = Napi::Function::New(env, rawCopyMicromapEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkCmdCopyMicromapToMemoryEXT"] = Napi::Function::New(env, rawCmdCopyMicromapToMemoryEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkCopyMicromapToMemoryEXT"] = Napi::Function::New(env, rawCopyMicromapToMemoryEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkCmdCopyMemoryToMicromapEXT"] = Napi::Function::New(env, rawCmdCopyMemoryToMicromapEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkCopyMemoryToMicromapEXT"] = Napi::Function::New(env, rawCopyMemoryToMicromapEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkCmdWriteMicromapsPropertiesEXT"] = Napi::Function::New(env, rawCmdWriteMicromapsPropertiesEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkWriteMicromapsPropertiesEXT"] = Napi::Function::New(env, rawWriteMicromapsPropertiesEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkGetDeviceMicromapCompatibilityEXT"] = Napi::Function::New(env, rawGetDeviceMicromapCompatibilityEXT);
#endif
#ifdef VK_EXT_opacity_micromap
    exports["vkGetMicromapBuildSizesEXT"] = Napi::Function::New(env, rawGetMicromapBuildSizesEXT);
#endif
#ifdef VK_EXT_shader_module_identifier
    exports["vkGetShaderModuleIdentifierEXT"] = Napi::Function::New(env, rawGetShaderModuleIdentifierEXT);
#endif
#ifdef VK_EXT_shader_module_identifier
    exports["vkGetShaderModuleCreateInfoIdentifierEXT"] = Napi::Function::New(env, rawGetShaderModuleCreateInfoIdentifierEXT);
#endif
#ifdef VK_EXT_image_compression_control
    exports["vkGetImageSubresourceLayout2EXT"] = Napi::Function::New(env, rawGetImageSubresourceLayout2EXT);
#endif
#ifdef VK_EXT_pipeline_properties
    exports["vkGetPipelinePropertiesEXT"] = Napi::Function::New(env, rawGetPipelinePropertiesEXT);
#endif
#ifdef VK_EXT_metal_objects
    exports["vkExportMetalObjectsEXT"] = Napi::Function::New(env, rawExportMetalObjectsEXT);
#endif
#ifdef VK_QCOM_tile_properties
    exports["vkGetFramebufferTilePropertiesQCOM"] = Napi::Function::New(env, rawGetFramebufferTilePropertiesQCOM);
#endif
#ifdef VK_QCOM_tile_properties
    exports["vkGetDynamicRenderingTilePropertiesQCOM"] = Napi::Function::New(env, rawGetDynamicRenderingTilePropertiesQCOM);
#endif
#ifdef VK_NV_optical_flow
    exports["vkGetPhysicalDeviceOpticalFlowImageFormatsNV"] = Napi::Function::New(env, rawGetPhysicalDeviceOpticalFlowImageFormatsNV);
#endif
#ifdef VK_NV_optical_flow
    exports["vkCreateOpticalFlowSessionNV"] = Napi::Function::New(env, rawCreateOpticalFlowSessionNV);
#endif
#ifdef VK_NV_optical_flow
    exports["vkDestroyOpticalFlowSessionNV"] = Napi::Function::New(env, rawDestroyOpticalFlowSessionNV);
#endif
#ifdef VK_NV_optical_flow
    exports["vkBindOpticalFlowSessionImageNV"] = Napi::Function::New(env, rawBindOpticalFlowSessionImageNV);
#endif
#ifdef VK_NV_optical_flow
    exports["vkCmdOpticalFlowExecuteNV"] = Napi::Function::New(env, rawCmdOpticalFlowExecuteNV);
#endif
#ifdef VK_EXT_device_fault
    exports["vkGetDeviceFaultInfoEXT"] = Napi::Function::New(env, rawGetDeviceFaultInfoEXT);
#endif

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
    