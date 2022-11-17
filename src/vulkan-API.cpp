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
#include <volk/volk.h>
#include <napi.h>

static Napi::Value Dealloc(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    delete (void*)address;
    return Napi::BigInt::New(env, (uint64_t)0ull);
}

static Napi::Value GetAddress(const Napi::CallbackInfo& info) {
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

    return Napi::BigInt::New(env, (uint64_t)address);
}


static Napi::ArrayBuffer WrapArrayBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    bool lossless = true;
    if (info[0].IsBigInt()) {
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    size_t byteLength = 0ull;
    if (info[1].IsBigInt()) { byteLength = info[1].As<Napi::Number>().Int64Value(); }
    if (info[1].IsNumber()) { byteLength = info[1].As<Napi::Number>().Uint32Value(); }
    return Napi::ArrayBuffer::New(env, (void*)address, byteLength);
}


static Napi::Number DebugUint8(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((uint8_t*)address));
}

static Napi::Number DebugUint16(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((uint16_t*)address));
}

static Napi::Number DebugUint32(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((uint32_t*)address));
}

static Napi::Value DebugUint64(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::BigInt::New(env, (uint64_t)address);
}


static Napi::Number DebugFloat32(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((float*)address));
}

static Napi::Number DebugFloat64(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((double*)address));
}
    

static Napi::Value rawCreateInstance(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstanceCreateInfo* pCreateInfo = (VkInstanceCreateInfo*)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance* pInstance = (VkInstance*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateInstance(pCreateInfo, pAllocator, pInstance);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyInstance(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyInstance(instance, pAllocator);
    return env.Null();

}



static Napi::Value rawEnumeratePhysicalDevices(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPhysicalDeviceCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice* pPhysicalDevices = (VkPhysicalDevice*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
    return Napi::Number::New(env, result);

}



static Napi::Value rawGetDeviceProcAddr(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    char* pName = (char*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceProcAddr(device, pName);
    return env.Null();

}



static Napi::Value rawGetInstanceProcAddr(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    char* pName = (char*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetInstanceProcAddr(instance, pName);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceProperties* pProperties = (VkPhysicalDeviceProperties*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceQueueFamilyProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pQueueFamilyPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueueFamilyProperties* pQueueFamilyProperties = (VkQueueFamilyProperties*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceMemoryProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceMemoryProperties* pMemoryProperties = (VkPhysicalDeviceMemoryProperties*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceFeatures(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceFeatures* pFeatures = (VkPhysicalDeviceFeatures*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceFormatProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormatProperties* pFormatProperties = (VkFormatProperties*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceImageFormatProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageType type = (VkImageType)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageTiling tiling = (VkImageTiling)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageUsageFlags usage = (VkImageUsageFlags)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageCreateFlags flags = (VkImageCreateFlags)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageFormatProperties* pImageFormatProperties = (VkImageFormatProperties*)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    return Napi::Number::New(env, result);

}



static Napi::Value rawCreateDevice(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceCreateInfo* pCreateInfo = (VkDeviceCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice* pDevice = (VkDevice*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyDevice(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDevice(device, pAllocator);
    return env.Null();

}



static Napi::Value rawEnumerateInstanceVersion(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pApiVersion = (uint32_t*)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkEnumerateInstanceVersion(pApiVersion);
    return Napi::Number::New(env, result);

}



static Napi::Value rawEnumerateInstanceLayerProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkLayerProperties* pProperties = (VkLayerProperties*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
    return Napi::Number::New(env, result);

}



static Napi::Value rawEnumerateInstanceExtensionProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    char* pLayerName = (char*)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExtensionProperties* pProperties = (VkExtensionProperties*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);

}



static Napi::Value rawEnumerateDeviceLayerProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkLayerProperties* pProperties = (VkLayerProperties*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkEnumerateDeviceLayerProperties(physicalDevice, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);

}



static Napi::Value rawEnumerateDeviceExtensionProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    char* pLayerName = (char*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExtensionProperties* pProperties = (VkExtensionProperties*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);

}



static Napi::Value rawGetDeviceQueue(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueIndex = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue* pQueue = (VkQueue*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    return env.Null();

}



static Napi::Value rawQueueSubmit(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t submitCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubmitInfo* pSubmits = (VkSubmitInfo*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkQueueSubmit(queue, submitCount, pSubmits, fence);
    return Napi::Number::New(env, result);

}



static Napi::Value rawQueueWaitIdle(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkQueueWaitIdle(queue);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDeviceWaitIdle(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkDeviceWaitIdle(device);
    return Napi::Number::New(env, result);

}



static Napi::Value rawAllocateMemory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryAllocateInfo* pAllocateInfo = (VkMemoryAllocateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory* pMemory = (VkDeviceMemory*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    return Napi::Number::New(env, result);

}



static Napi::Value rawFreeMemory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkFreeMemory(device, memory, pAllocator);
    return env.Null();

}



static Napi::Value rawMapMemory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize size = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryMapFlags flags = (VkMemoryMapFlags)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void** ppData = (void**)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkMapMemory(device, memory, offset, size, flags, ppData);
    return Napi::Number::New(env, result);

}



static Napi::Value rawUnmapMemory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkUnmapMemory(device, memory);
    return env.Null();

}



static Napi::Value rawFlushMappedMemoryRanges(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t memoryRangeCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMappedMemoryRange* pMemoryRanges = (VkMappedMemoryRange*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    return Napi::Number::New(env, result);

}



static Napi::Value rawInvalidateMappedMemoryRanges(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t memoryRangeCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMappedMemoryRange* pMemoryRanges = (VkMappedMemoryRange*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    return Napi::Number::New(env, result);

}



static Napi::Value rawGetDeviceMemoryCommitment(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pCommittedMemoryInBytes = (VkDeviceSize*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    return env.Null();

}



static Napi::Value rawGetBufferMemoryRequirements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements* pMemoryRequirements = (VkMemoryRequirements*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    return env.Null();

}



static Napi::Value rawBindBufferMemory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize memoryOffset = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkBindBufferMemory(device, buffer, memory, memoryOffset);
    return Napi::Number::New(env, result);

}



static Napi::Value rawGetImageMemoryRequirements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements* pMemoryRequirements = (VkMemoryRequirements*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
    return env.Null();

}



static Napi::Value rawBindImageMemory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize memoryOffset = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkBindImageMemory(device, image, memory, memoryOffset);
    return Napi::Number::New(env, result);

}



static Napi::Value rawGetImageSparseMemoryRequirements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pSparseMemoryRequirementCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSparseImageMemoryRequirements* pSparseMemoryRequirements = (VkSparseImageMemoryRequirements*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceSparseImageFormatProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageType type = (VkImageType)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampleCountFlagBits samples = (VkSampleCountFlagBits)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageUsageFlags usage = (VkImageUsageFlags)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageTiling tiling = (VkImageTiling)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSparseImageFormatProperties* pProperties = (VkSparseImageFormatProperties*)info[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
    return env.Null();

}



static Napi::Value rawQueueBindSparse(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindInfoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBindSparseInfo* pBindInfo = (VkBindSparseInfo*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    return Napi::Number::New(env, result);

}



static Napi::Value rawCreateFence(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFenceCreateInfo* pCreateInfo = (VkFenceCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence* pFence = (VkFence*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateFence(device, pCreateInfo, pAllocator, pFence);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyFence(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyFence(device, fence, pAllocator);
    return env.Null();

}



static Napi::Value rawResetFences(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t fenceCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence* pFences = (VkFence*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkResetFences(device, fenceCount, pFences);
    return Napi::Number::New(env, result);

}



static Napi::Value rawGetFenceStatus(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetFenceStatus(device, fence);
    return Napi::Number::New(env, result);

}



static Napi::Value rawWaitForFences(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t fenceCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence* pFences = (VkFence*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 waitAll = (VkBool32)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t timeout = (uint64_t)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
    return Napi::Number::New(env, result);

}



static Napi::Value rawCreateSemaphore(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphoreCreateInfo* pCreateInfo = (VkSemaphoreCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphore* pSemaphore = (VkSemaphore*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroySemaphore(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphore semaphore = (VkSemaphore)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroySemaphore(device, semaphore, pAllocator);
    return env.Null();

}



static Napi::Value rawCreateEvent(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEventCreateInfo* pCreateInfo = (VkEventCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent* pEvent = (VkEvent*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyEvent(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyEvent(device, event, pAllocator);
    return env.Null();

}



static Napi::Value rawGetEventStatus(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetEventStatus(device, event);
    return Napi::Number::New(env, result);

}



static Napi::Value rawSetEvent(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkSetEvent(device, event);
    return Napi::Number::New(env, result);

}



static Napi::Value rawResetEvent(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkResetEvent(device, event);
    return Napi::Number::New(env, result);

}



static Napi::Value rawCreateQueryPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPoolCreateInfo* pCreateInfo = (VkQueryPoolCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool* pQueryPool = (VkQueryPool*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyQueryPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyQueryPool(device, queryPool, pAllocator);
    return env.Null();

}



static Napi::Value rawGetQueryPoolResults(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queryCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t dataSize = (size_t)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize stride = (VkDeviceSize)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryResultFlags flags = (VkQueryResultFlags)info[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    return Napi::Number::New(env, result);

}



static Napi::Value rawResetQueryPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queryCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkResetQueryPool(device, queryPool, firstQuery, queryCount);
    return env.Null();

}



static Napi::Value rawCreateBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCreateInfo* pCreateInfo = (VkBufferCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer* pBuffer = (VkBuffer*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyBuffer(device, buffer, pAllocator);
    return env.Null();

}



static Napi::Value rawCreateBufferView(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferViewCreateInfo* pCreateInfo = (VkBufferViewCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferView* pView = (VkBufferView*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyBufferView(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferView bufferView = (VkBufferView)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyBufferView(device, bufferView, pAllocator);
    return env.Null();

}



static Napi::Value rawCreateImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageCreateInfo* pCreateInfo = (VkImageCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage* pImage = (VkImage*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateImage(device, pCreateInfo, pAllocator, pImage);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyImage(device, image, pAllocator);
    return env.Null();

}



static Napi::Value rawGetImageSubresourceLayout(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageSubresource* pSubresource = (VkImageSubresource*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubresourceLayout* pLayout = (VkSubresourceLayout*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
    return env.Null();

}



static Napi::Value rawCreateImageView(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageViewCreateInfo* pCreateInfo = (VkImageViewCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageView* pView = (VkImageView*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateImageView(device, pCreateInfo, pAllocator, pView);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyImageView(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageView imageView = (VkImageView)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyImageView(device, imageView, pAllocator);
    return env.Null();

}



static Napi::Value rawCreateShaderModule(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModuleCreateInfo* pCreateInfo = (VkShaderModuleCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModule* pShaderModule = (VkShaderModule*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyShaderModule(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModule shaderModule = (VkShaderModule)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyShaderModule(device, shaderModule, pAllocator);
    return env.Null();

}



static Napi::Value rawCreatePipelineCache(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCacheCreateInfo* pCreateInfo = (VkPipelineCacheCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache* pPipelineCache = (VkPipelineCache*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyPipelineCache(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache pipelineCache = (VkPipelineCache)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyPipelineCache(device, pipelineCache, pAllocator);
    return env.Null();

}



static Napi::Value rawGetPipelineCacheData(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache pipelineCache = (VkPipelineCache)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t* pDataSize = (size_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
    return Napi::Number::New(env, result);

}



static Napi::Value rawMergePipelineCaches(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache dstCache = (VkPipelineCache)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t srcCacheCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache* pSrcCaches = (VkPipelineCache*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
    return Napi::Number::New(env, result);

}



static Napi::Value rawCreateGraphicsPipelines(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache pipelineCache = (VkPipelineCache)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t createInfoCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkGraphicsPipelineCreateInfo* pCreateInfos = (VkGraphicsPipelineCreateInfo*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline* pPipelines = (VkPipeline*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return Napi::Number::New(env, result);

}



static Napi::Value rawCreateComputePipelines(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache pipelineCache = (VkPipelineCache)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t createInfoCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkComputePipelineCreateInfo* pCreateInfos = (VkComputePipelineCreateInfo*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline* pPipelines = (VkPipeline*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return Napi::Number::New(env, result);

}


#ifdef VK_HUAWEI_subpass_shading
static Napi::Value rawGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPass renderpass = (VkRenderPass)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExtent2D* pMaxWorkgroupSize = (VkExtent2D*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(device, renderpass, pMaxWorkgroupSize);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawDestroyPipeline(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyPipeline(device, pipeline, pAllocator);
    return env.Null();

}



static Napi::Value rawCreatePipelineLayout(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayoutCreateInfo* pCreateInfo = (VkPipelineLayoutCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayout* pPipelineLayout = (VkPipelineLayout*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyPipelineLayout(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayout pipelineLayout = (VkPipelineLayout)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
    return env.Null();

}



static Napi::Value rawCreateSampler(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSamplerCreateInfo* pCreateInfo = (VkSamplerCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampler* pSampler = (VkSampler*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroySampler(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampler sampler = (VkSampler)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroySampler(device, sampler, pAllocator);
    return env.Null();

}



static Napi::Value rawCreateDescriptorSetLayout(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetLayoutCreateInfo* pCreateInfo = (VkDescriptorSetLayoutCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetLayout* pSetLayout = (VkDescriptorSetLayout*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyDescriptorSetLayout(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetLayout descriptorSetLayout = (VkDescriptorSetLayout)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    return env.Null();

}



static Napi::Value rawCreateDescriptorPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorPoolCreateInfo* pCreateInfo = (VkDescriptorPoolCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorPool* pDescriptorPool = (VkDescriptorPool*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyDescriptorPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorPool descriptorPool = (VkDescriptorPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
    return env.Null();

}



static Napi::Value rawResetDescriptorPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorPool descriptorPool = (VkDescriptorPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorPoolResetFlags flags = (VkDescriptorPoolResetFlags)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkResetDescriptorPool(device, descriptorPool, flags);
    return Napi::Number::New(env, result);

}



static Napi::Value rawAllocateDescriptorSets(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetAllocateInfo* pAllocateInfo = (VkDescriptorSetAllocateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSet* pDescriptorSets = (VkDescriptorSet*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
    return Napi::Number::New(env, result);

}



static Napi::Value rawFreeDescriptorSets(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorPool descriptorPool = (VkDescriptorPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t descriptorSetCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSet* pDescriptorSets = (VkDescriptorSet*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    return Napi::Number::New(env, result);

}



static Napi::Value rawUpdateDescriptorSets(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t descriptorWriteCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkWriteDescriptorSet* pDescriptorWrites = (VkWriteDescriptorSet*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t descriptorCopyCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyDescriptorSet* pDescriptorCopies = (VkCopyDescriptorSet*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    return env.Null();

}



static Napi::Value rawCreateFramebuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFramebufferCreateInfo* pCreateInfo = (VkFramebufferCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFramebuffer* pFramebuffer = (VkFramebuffer*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyFramebuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFramebuffer framebuffer = (VkFramebuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyFramebuffer(device, framebuffer, pAllocator);
    return env.Null();

}



static Napi::Value rawCreateRenderPass(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPassCreateInfo* pCreateInfo = (VkRenderPassCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPass* pRenderPass = (VkRenderPass*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyRenderPass(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPass renderPass = (VkRenderPass)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyRenderPass(device, renderPass, pAllocator);
    return env.Null();

}



static Napi::Value rawGetRenderAreaGranularity(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPass renderPass = (VkRenderPass)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExtent2D* pGranularity = (VkExtent2D*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetRenderAreaGranularity(device, renderPass, pGranularity);
    return env.Null();

}



static Napi::Value rawCreateCommandPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPoolCreateInfo* pCreateInfo = (VkCommandPoolCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPool* pCommandPool = (VkCommandPool*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyCommandPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPool commandPool = (VkCommandPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyCommandPool(device, commandPool, pAllocator);
    return env.Null();

}



static Napi::Value rawResetCommandPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPool commandPool = (VkCommandPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPoolResetFlags flags = (VkCommandPoolResetFlags)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkResetCommandPool(device, commandPool, flags);
    return Napi::Number::New(env, result);

}



static Napi::Value rawAllocateCommandBuffers(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBufferAllocateInfo* pAllocateInfo = (VkCommandBufferAllocateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer* pCommandBuffers = (VkCommandBuffer*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
    return Napi::Number::New(env, result);

}



static Napi::Value rawFreeCommandBuffers(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPool commandPool = (VkCommandPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t commandBufferCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer* pCommandBuffers = (VkCommandBuffer*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    return env.Null();

}



static Napi::Value rawBeginCommandBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBufferBeginInfo* pBeginInfo = (VkCommandBufferBeginInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkBeginCommandBuffer(commandBuffer, pBeginInfo);
    return Napi::Number::New(env, result);

}



static Napi::Value rawEndCommandBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkEndCommandBuffer(commandBuffer);
    return Napi::Number::New(env, result);

}



static Napi::Value rawResetCommandBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBufferResetFlags flags = (VkCommandBufferResetFlags)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkResetCommandBuffer(commandBuffer, flags);
    return Napi::Number::New(env, result);

}



static Napi::Value rawCmdBindPipeline(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineBindPoint pipelineBindPoint = (VkPipelineBindPoint)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    return env.Null();

}



static Napi::Value rawCmdSetViewport(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstViewport = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t viewportCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkViewport* pViewports = (VkViewport*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    return env.Null();

}



static Napi::Value rawCmdSetScissor(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstScissor = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t scissorCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRect2D* pScissors = (VkRect2D*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    return env.Null();

}



static Napi::Value rawCmdSetLineWidth(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float lineWidth = (float)info[1].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetLineWidth(commandBuffer, lineWidth);
    return env.Null();

}



static Napi::Value rawCmdSetDepthBias(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float depthBiasConstantFactor = (float)info[1].As<Napi::Number>().FloatValue();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float depthBiasClamp = (float)info[2].As<Napi::Number>().FloatValue();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float depthBiasSlopeFactor = (float)info[3].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    return env.Null();

}



static Napi::Value rawCmdSetBlendConstants(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    float* blendConstants = (float*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetBlendConstants(commandBuffer, blendConstants);
    return env.Null();

}



static Napi::Value rawCmdSetDepthBounds(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float minDepthBounds = (float)info[1].As<Napi::Number>().FloatValue();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float maxDepthBounds = (float)info[2].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    return env.Null();

}



static Napi::Value rawCmdSetStencilCompareMask(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilFaceFlags faceMask = (VkStencilFaceFlags)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t compareMask = (uint32_t)info[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    return env.Null();

}



static Napi::Value rawCmdSetStencilWriteMask(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilFaceFlags faceMask = (VkStencilFaceFlags)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t writeMask = (uint32_t)info[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    return env.Null();

}



static Napi::Value rawCmdSetStencilReference(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilFaceFlags faceMask = (VkStencilFaceFlags)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t reference = (uint32_t)info[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetStencilReference(commandBuffer, faceMask, reference);
    return env.Null();

}



static Napi::Value rawCmdBindDescriptorSets(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineBindPoint pipelineBindPoint = (VkPipelineBindPoint)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayout layout = (VkPipelineLayout)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstSet = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t descriptorSetCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSet* pDescriptorSets = (VkDescriptorSet*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t dynamicOffsetCount = (uint32_t)info[6].As<Napi::Number>().Uint32Value();

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pDynamicOffsets = (uint32_t*)info[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    return env.Null();

}



static Napi::Value rawCmdBindIndexBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkIndexType indexType = (VkIndexType)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    return env.Null();

}



static Napi::Value rawCmdBindVertexBuffers(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstBinding = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindingCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer* pBuffers = (VkBuffer*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pOffsets = (VkDeviceSize*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    return env.Null();

}



static Napi::Value rawCmdDraw(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t vertexCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t instanceCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstVertex = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstInstance = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    return env.Null();

}



static Napi::Value rawCmdDrawIndexed(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t indexCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t instanceCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstIndex = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    int32_t vertexOffset = (int32_t)info[4].As<Napi::Number>().Int32Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstInstance = (uint32_t)info[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    return env.Null();

}


#ifdef VK_EXT_multi_draw
static Napi::Value rawCmdDrawMultiEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t drawCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMultiDrawInfoEXT* pVertexInfo = (VkMultiDrawInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t instanceCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstInstance = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
    return env.Null();

}
#endif

#ifdef VK_EXT_multi_draw
static Napi::Value rawCmdDrawMultiIndexedEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t drawCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMultiDrawIndexedInfoEXT* pIndexInfo = (VkMultiDrawIndexedInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t instanceCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstInstance = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int32_t* pVertexOffset = (int32_t*)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
    return env.Null();

}
#endif


static Napi::Value rawCmdDrawIndirect(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t drawCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    return env.Null();

}



static Napi::Value rawCmdDrawIndexedIndirect(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t drawCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    return env.Null();

}



static Napi::Value rawCmdDispatch(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountX = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountY = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountZ = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    return env.Null();

}



static Napi::Value rawCmdDispatchIndirect(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDispatchIndirect(commandBuffer, buffer, offset);
    return env.Null();

}


#ifdef VK_HUAWEI_subpass_shading
static Napi::Value rawCmdSubpassShadingHUAWEI(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSubpassShadingHUAWEI(commandBuffer);
    return env.Null();

}
#endif


static Napi::Value rawCmdCopyBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer srcBuffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t regionCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCopy* pRegions = (VkBufferCopy*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    return env.Null();

}



static Napi::Value rawCmdCopyImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage srcImage = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout srcImageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage dstImage = (VkImage)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout dstImageLayout = (VkImageLayout)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t regionCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageCopy* pRegions = (VkImageCopy*)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    return env.Null();

}



static Napi::Value rawCmdBlitImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage srcImage = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout srcImageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage dstImage = (VkImage)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout dstImageLayout = (VkImageLayout)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t regionCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageBlit* pRegions = (VkImageBlit*)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFilter filter = (VkFilter)info[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    return env.Null();

}



static Napi::Value rawCmdCopyBufferToImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer srcBuffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage dstImage = (VkImage)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout dstImageLayout = (VkImageLayout)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t regionCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferImageCopy* pRegions = (VkBufferImageCopy*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    return env.Null();

}



static Napi::Value rawCmdCopyImageToBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage srcImage = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout srcImageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t regionCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferImageCopy* pRegions = (VkBufferImageCopy*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    return env.Null();

}


#ifdef VK_NV_copy_memory_indirect
static Napi::Value rawCmdCopyMemoryIndirectNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress copyBufferAddress = (VkDeviceAddress)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t copyCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
    return env.Null();

}
#endif

#ifdef VK_NV_copy_memory_indirect
static Napi::Value rawCmdCopyMemoryToImageIndirectNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress copyBufferAddress = (VkDeviceAddress)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t copyCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage dstImage = (VkImage)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout dstImageLayout = (VkImageLayout)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageSubresourceLayers* pImageSubresources = (VkImageSubresourceLayers*)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
    return env.Null();

}
#endif


static Napi::Value rawCmdUpdateBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize dstOffset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize dataSize = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    return env.Null();

}



static Napi::Value rawCmdFillBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize dstOffset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize size = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t data = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    return env.Null();

}



static Napi::Value rawCmdClearColorImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout imageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkClearColorValue* pColor = (VkClearColorValue*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t rangeCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageSubresourceRange* pRanges = (VkImageSubresourceRange*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    return env.Null();

}



static Napi::Value rawCmdClearDepthStencilImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout imageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkClearDepthStencilValue* pDepthStencil = (VkClearDepthStencilValue*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t rangeCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageSubresourceRange* pRanges = (VkImageSubresourceRange*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    return env.Null();

}



static Napi::Value rawCmdClearAttachments(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t attachmentCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkClearAttachment* pAttachments = (VkClearAttachment*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t rectCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkClearRect* pRects = (VkClearRect*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    return env.Null();

}



static Napi::Value rawCmdResolveImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage srcImage = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout srcImageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage dstImage = (VkImage)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout dstImageLayout = (VkImageLayout)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t regionCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageResolve* pRegions = (VkImageResolve*)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    return env.Null();

}



static Napi::Value rawCmdSetEvent(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags stageMask = (VkPipelineStageFlags)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetEvent(commandBuffer, event, stageMask);
    return env.Null();

}



static Napi::Value rawCmdResetEvent(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags stageMask = (VkPipelineStageFlags)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdResetEvent(commandBuffer, event, stageMask);
    return env.Null();

}



static Napi::Value rawCmdWaitEvents(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 11) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t eventCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent* pEvents = (VkEvent*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags srcStageMask = (VkPipelineStageFlags)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags dstStageMask = (VkPipelineStageFlags)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t memoryBarrierCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryBarrier* pMemoryBarriers = (VkMemoryBarrier*)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[7].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bufferMemoryBarrierCount = (uint32_t)info[7].As<Napi::Number>().Uint32Value();

    if (!info[8].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferMemoryBarrier* pBufferMemoryBarriers = (VkBufferMemoryBarrier*)info[8].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[9].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t imageMemoryBarrierCount = (uint32_t)info[9].As<Napi::Number>().Uint32Value();

    if (!info[10].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageMemoryBarrier* pImageMemoryBarriers = (VkImageMemoryBarrier*)info[10].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    return env.Null();

}



static Napi::Value rawCmdPipelineBarrier(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 10) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags srcStageMask = (VkPipelineStageFlags)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags dstStageMask = (VkPipelineStageFlags)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDependencyFlags dependencyFlags = (VkDependencyFlags)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t memoryBarrierCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryBarrier* pMemoryBarriers = (VkMemoryBarrier*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bufferMemoryBarrierCount = (uint32_t)info[6].As<Napi::Number>().Uint32Value();

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferMemoryBarrier* pBufferMemoryBarriers = (VkBufferMemoryBarrier*)info[7].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[8].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t imageMemoryBarrierCount = (uint32_t)info[8].As<Napi::Number>().Uint32Value();

    if (!info[9].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageMemoryBarrier* pImageMemoryBarriers = (VkImageMemoryBarrier*)info[9].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    return env.Null();

}



static Napi::Value rawCmdBeginQuery(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t query = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryControlFlags flags = (VkQueryControlFlags)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
    return env.Null();

}



static Napi::Value rawCmdEndQuery(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t query = (uint32_t)info[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdEndQuery(commandBuffer, queryPool, query);
    return env.Null();

}


#ifdef VK_EXT_conditional_rendering
static Napi::Value rawCmdBeginConditionalRenderingEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin = (VkConditionalRenderingBeginInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
    return env.Null();

}
#endif

#ifdef VK_EXT_conditional_rendering
static Napi::Value rawCmdEndConditionalRenderingEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndConditionalRenderingEXT(commandBuffer);
    return env.Null();

}
#endif


static Napi::Value rawCmdResetQueryPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queryCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    return env.Null();

}



static Napi::Value rawCmdWriteTimestamp(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlagBits pipelineStage = (VkPipelineStageFlagBits)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t query = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    return env.Null();

}



static Napi::Value rawCmdCopyQueryPoolResults(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queryCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize dstOffset = (VkDeviceSize)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize stride = (VkDeviceSize)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryResultFlags flags = (VkQueryResultFlags)info[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    return env.Null();

}



static Napi::Value rawCmdPushConstants(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayout layout = (VkPipelineLayout)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderStageFlags stageFlags = (VkShaderStageFlags)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t offset = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t size = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pValues = (void*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    return env.Null();

}



static Napi::Value rawCmdBeginRenderPass(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPassBeginInfo* pRenderPassBegin = (VkRenderPassBeginInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubpassContents contents = (VkSubpassContents)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    return env.Null();

}



static Napi::Value rawCmdNextSubpass(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubpassContents contents = (VkSubpassContents)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdNextSubpass(commandBuffer, contents);
    return env.Null();

}



static Napi::Value rawCmdEndRenderPass(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndRenderPass(commandBuffer);
    return env.Null();

}



static Napi::Value rawCmdExecuteCommands(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t commandBufferCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer* pCommandBuffers = (VkCommandBuffer*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    return env.Null();

}


#ifdef VK_KHR_android_surface
static Napi::Value rawCreateAndroidSurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAndroidSurfaceCreateInfoKHR* pCreateInfo = (VkAndroidSurfaceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_display
static Napi::Value rawGetPhysicalDeviceDisplayPropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPropertiesKHR* pProperties = (VkDisplayPropertiesKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_display
static Napi::Value rawGetPhysicalDeviceDisplayPlanePropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPlanePropertiesKHR* pProperties = (VkDisplayPlanePropertiesKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_display
static Napi::Value rawGetDisplayPlaneSupportedDisplaysKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t planeIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pDisplayCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR* pDisplays = (VkDisplayKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_display
static Napi::Value rawGetDisplayModePropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayModePropertiesKHR* pProperties = (VkDisplayModePropertiesKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_display
static Napi::Value rawCreateDisplayModeKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayModeCreateInfoKHR* pCreateInfo = (VkDisplayModeCreateInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayModeKHR* pMode = (VkDisplayModeKHR*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_display
static Napi::Value rawGetDisplayPlaneCapabilitiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayModeKHR mode = (VkDisplayModeKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t planeIndex = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPlaneCapabilitiesKHR* pCapabilities = (VkDisplayPlaneCapabilitiesKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_display
static Napi::Value rawCreateDisplayPlaneSurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplaySurfaceCreateInfoKHR* pCreateInfo = (VkDisplaySurfaceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_display_swapchain
static Napi::Value rawCreateSharedSwapchainsKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t swapchainCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainCreateInfoKHR* pCreateInfos = (VkSwapchainCreateInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR* pSwapchains = (VkSwapchainKHR*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_surface
static Napi::Value rawDestroySurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroySurfaceKHR(instance, surface, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_KHR_surface
static Napi::Value rawGetPhysicalDeviceSurfaceSupportKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32* pSupported = (VkBool32*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_surface
static Napi::Value rawGetPhysicalDeviceSurfaceCapabilitiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceCapabilitiesKHR* pSurfaceCapabilities = (VkSurfaceCapabilitiesKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_surface
static Napi::Value rawGetPhysicalDeviceSurfaceFormatsKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pSurfaceFormatCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceFormatKHR* pSurfaceFormats = (VkSurfaceFormatKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_surface
static Napi::Value rawGetPhysicalDeviceSurfacePresentModesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPresentModeCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPresentModeKHR* pPresentModes = (VkPresentModeKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_swapchain
static Napi::Value rawCreateSwapchainKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainCreateInfoKHR* pCreateInfo = (VkSwapchainCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR* pSwapchain = (VkSwapchainKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_swapchain
static Napi::Value rawDestroySwapchainKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroySwapchainKHR(device, swapchain, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_KHR_swapchain
static Napi::Value rawGetSwapchainImagesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pSwapchainImageCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage* pSwapchainImages = (VkImage*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_swapchain
static Napi::Value rawAcquireNextImageKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t timeout = (uint64_t)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphore semaphore = (VkSemaphore)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pImageIndex = (uint32_t*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_swapchain
static Napi::Value rawQueuePresentKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPresentInfoKHR* pPresentInfo = (VkPresentInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkQueuePresentKHR(queue, pPresentInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NN_vi_surface
static Napi::Value rawCreateViSurfaceNN(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkViSurfaceCreateInfoNN* pCreateInfo = (VkViSurfaceCreateInfoNN*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_wayland_surface
static Napi::Value rawCreateWaylandSurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkWaylandSurfaceCreateInfoKHR* pCreateInfo = (VkWaylandSurfaceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_wayland_surface
static Napi::Value rawGetPhysicalDeviceWaylandPresentationSupportKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    wl_display* display = (wl_display*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_win32_surface
static Napi::Value rawCreateWin32SurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkWin32SurfaceCreateInfoKHR* pCreateInfo = (VkWin32SurfaceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_win32_surface
static Napi::Value rawGetPhysicalDeviceWin32PresentationSupportKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();
    
    auto result = ::vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_xlib_surface
static Napi::Value rawCreateXlibSurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkXlibSurfaceCreateInfoKHR* pCreateInfo = (VkXlibSurfaceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_xlib_surface
static Napi::Value rawGetPhysicalDeviceXlibPresentationSupportKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    Display* dpy = (Display*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VisualID visualID = (VisualID)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_xcb_surface
static Napi::Value rawCreateXcbSurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkXcbSurfaceCreateInfoKHR* pCreateInfo = (VkXcbSurfaceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_xcb_surface
static Napi::Value rawGetPhysicalDeviceXcbPresentationSupportKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    xcb_connection_t* connection = (xcb_connection_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    xcb_visualid_t visual_id = (xcb_visualid_t)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_directfb_surface
static Napi::Value rawCreateDirectFBSurfaceEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDirectFBSurfaceCreateInfoEXT* pCreateInfo = (VkDirectFBSurfaceCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateDirectFBSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_directfb_surface
static Napi::Value rawGetPhysicalDeviceDirectFBPresentationSupportEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    IDirectFB* dfb = (IDirectFB*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceDirectFBPresentationSupportEXT(physicalDevice, queueFamilyIndex, dfb);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_FUCHSIA_imagepipe_surface
static Napi::Value rawCreateImagePipeSurfaceFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo = (VkImagePipeSurfaceCreateInfoFUCHSIA*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateImagePipeSurfaceFUCHSIA(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_GGP_stream_descriptor_surface
static Napi::Value rawCreateStreamDescriptorSurfaceGGP(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo = (VkStreamDescriptorSurfaceCreateInfoGGP*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateStreamDescriptorSurfaceGGP(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_QNX_screen_surface
static Napi::Value rawCreateScreenSurfaceQNX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkScreenSurfaceCreateInfoQNX* pCreateInfo = (VkScreenSurfaceCreateInfoQNX*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateScreenSurfaceQNX(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_QNX_screen_surface
static Napi::Value rawGetPhysicalDeviceScreenPresentationSupportQNX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    _screen_window* window = (_screen_window*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceScreenPresentationSupportQNX(physicalDevice, queueFamilyIndex, window);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_debug_report
static Napi::Value rawCreateDebugReportCallbackEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugReportCallbackCreateInfoEXT* pCreateInfo = (VkDebugReportCallbackCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugReportCallbackEXT* pCallback = (VkDebugReportCallbackEXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_debug_report
static Napi::Value rawDestroyDebugReportCallbackEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugReportCallbackEXT callback = (VkDebugReportCallbackEXT)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDebugReportCallbackEXT(instance, callback, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_EXT_debug_report
static Napi::Value rawDebugReportMessageEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugReportFlagsEXT flags = (VkDebugReportFlagsEXT)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugReportObjectTypeEXT objectType = (VkDebugReportObjectTypeEXT)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t object = (uint64_t)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t location = (size_t)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    int32_t messageCode = (int32_t)info[5].As<Napi::Number>().Int32Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    char* pLayerPrefix = (char*)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    char* pMessage = (char*)info[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
    return env.Null();

}
#endif

#ifdef VK_EXT_debug_marker
static Napi::Value rawDebugMarkerSetObjectNameEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugMarkerObjectNameInfoEXT* pNameInfo = (VkDebugMarkerObjectNameInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkDebugMarkerSetObjectNameEXT(device, pNameInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_debug_marker
static Napi::Value rawDebugMarkerSetObjectTagEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugMarkerObjectTagInfoEXT* pTagInfo = (VkDebugMarkerObjectTagInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkDebugMarkerSetObjectTagEXT(device, pTagInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_debug_marker
static Napi::Value rawCmdDebugMarkerBeginEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugMarkerMarkerInfoEXT* pMarkerInfo = (VkDebugMarkerMarkerInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_debug_marker
static Napi::Value rawCmdDebugMarkerEndEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDebugMarkerEndEXT(commandBuffer);
    return env.Null();

}
#endif

#ifdef VK_EXT_debug_marker
static Napi::Value rawCmdDebugMarkerInsertEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugMarkerMarkerInfoEXT* pMarkerInfo = (VkDebugMarkerMarkerInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    return env.Null();

}
#endif

#ifdef VK_NV_external_memory_capabilities
static Napi::Value rawGetPhysicalDeviceExternalImageFormatPropertiesNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageType type = (VkImageType)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageTiling tiling = (VkImageTiling)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageUsageFlags usage = (VkImageUsageFlags)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageCreateFlags flags = (VkImageCreateFlags)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalMemoryHandleTypeFlagsNV externalHandleType = (VkExternalMemoryHandleTypeFlagsNV)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties = (VkExternalImageFormatPropertiesNV*)info[7].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_external_memory_win32
static Napi::Value rawGetMemoryWin32HandleNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalMemoryHandleTypeFlagsNV handleType = (VkExternalMemoryHandleTypeFlagsNV)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    HANDLE* pHandle = (HANDLE*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetMemoryWin32HandleNV(device, memory, handleType, pHandle);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_device_generated_commands
static Napi::Value rawCmdExecuteGeneratedCommandsNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 isPreprocessed = (VkBool32)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo = (VkGeneratedCommandsInfoNV*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    return env.Null();

}
#endif

#ifdef VK_NV_device_generated_commands
static Napi::Value rawCmdPreprocessGeneratedCommandsNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo = (VkGeneratedCommandsInfoNV*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
    return env.Null();

}
#endif

#ifdef VK_NV_device_generated_commands
static Napi::Value rawCmdBindPipelineShaderGroupNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineBindPoint pipelineBindPoint = (VkPipelineBindPoint)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupIndex = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    return env.Null();

}
#endif

#ifdef VK_NV_device_generated_commands
static Napi::Value rawGetGeneratedCommandsMemoryRequirementsNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo = (VkGeneratedCommandsMemoryRequirementsInfoNV*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements2* pMemoryRequirements = (VkMemoryRequirements2*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetGeneratedCommandsMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
    return env.Null();

}
#endif

#ifdef VK_NV_device_generated_commands
static Napi::Value rawCreateIndirectCommandsLayoutNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo = (VkIndirectCommandsLayoutCreateInfoNV*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkIndirectCommandsLayoutNV* pIndirectCommandsLayout = (VkIndirectCommandsLayoutNV*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateIndirectCommandsLayoutNV(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_device_generated_commands
static Napi::Value rawDestroyIndirectCommandsLayoutNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkIndirectCommandsLayoutNV indirectCommandsLayout = (VkIndirectCommandsLayoutNV)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyIndirectCommandsLayoutNV(device, indirectCommandsLayout, pAllocator);
    return env.Null();

}
#endif


static Napi::Value rawGetPhysicalDeviceFeatures2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceFeatures2* pFeatures = (VkPhysicalDeviceFeatures2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceProperties2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceProperties2* pProperties = (VkPhysicalDeviceProperties2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceProperties2(physicalDevice, pProperties);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceFormatProperties2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormatProperties2* pFormatProperties = (VkFormatProperties2*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceImageFormatProperties2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo = (VkPhysicalDeviceImageFormatInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageFormatProperties2* pImageFormatProperties = (VkImageFormatProperties2*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    return Napi::Number::New(env, result);

}



static Napi::Value rawGetPhysicalDeviceQueueFamilyProperties2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pQueueFamilyPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueueFamilyProperties2* pQueueFamilyProperties = (VkQueueFamilyProperties2*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceMemoryProperties2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceMemoryProperties2* pMemoryProperties = (VkPhysicalDeviceMemoryProperties2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceSparseImageFormatProperties2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo = (VkPhysicalDeviceSparseImageFormatInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSparseImageFormatProperties2* pProperties = (VkSparseImageFormatProperties2*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    return env.Null();

}


#ifdef VK_KHR_push_descriptor
static Napi::Value rawCmdPushDescriptorSetKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineBindPoint pipelineBindPoint = (VkPipelineBindPoint)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayout layout = (VkPipelineLayout)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t set = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t descriptorWriteCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkWriteDescriptorSet* pDescriptorWrites = (VkWriteDescriptorSet*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    return env.Null();

}
#endif


static Napi::Value rawTrimCommandPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPool commandPool = (VkCommandPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPoolTrimFlags flags = (VkCommandPoolTrimFlags)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkTrimCommandPool(device, commandPool, flags);
    return env.Null();

}



static Napi::Value rawGetPhysicalDeviceExternalBufferProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo = (VkPhysicalDeviceExternalBufferInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalBufferProperties* pExternalBufferProperties = (VkExternalBufferProperties*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    return env.Null();

}


#ifdef VK_KHR_external_memory_win32
static Napi::Value rawGetMemoryWin32HandleKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo = (VkMemoryGetWin32HandleInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    HANDLE* pHandle = (HANDLE*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_external_memory_win32
static Napi::Value rawGetMemoryWin32HandlePropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalMemoryHandleTypeFlagBits handleType = (VkExternalMemoryHandleTypeFlagBits)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    HANDLE handle = (HANDLE)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties = (VkMemoryWin32HandlePropertiesKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_external_memory_fd
static Napi::Value rawGetMemoryFdKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryGetFdInfoKHR* pGetFdInfo = (VkMemoryGetFdInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int* pFd = (int*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetMemoryFdKHR(device, pGetFdInfo, pFd);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_external_memory_fd
static Napi::Value rawGetMemoryFdPropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalMemoryHandleTypeFlagBits handleType = (VkExternalMemoryHandleTypeFlagBits)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int fd = (int)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryFdPropertiesKHR* pMemoryFdProperties = (VkMemoryFdPropertiesKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_FUCHSIA_external_memory
static Napi::Value rawGetMemoryZirconHandleFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo = (VkMemoryGetZirconHandleInfoFUCHSIA*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    zx_handle_t* pZirconHandle = (zx_handle_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetMemoryZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_FUCHSIA_external_memory
static Napi::Value rawGetMemoryZirconHandlePropertiesFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalMemoryHandleTypeFlagBits handleType = (VkExternalMemoryHandleTypeFlagBits)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    zx_handle_t zirconHandle = (zx_handle_t)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties = (VkMemoryZirconHandlePropertiesFUCHSIA*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetMemoryZirconHandlePropertiesFUCHSIA(device, handleType, zirconHandle, pMemoryZirconHandleProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_external_memory_rdma
static Napi::Value rawGetMemoryRemoteAddressNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo = (VkMemoryGetRemoteAddressInfoNV*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRemoteAddressNV* pAddress = (VkRemoteAddressNV*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetMemoryRemoteAddressNV(device, pMemoryGetRemoteAddressInfo, pAddress);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawGetPhysicalDeviceExternalSemaphoreProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo = (VkPhysicalDeviceExternalSemaphoreInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalSemaphoreProperties* pExternalSemaphoreProperties = (VkExternalSemaphoreProperties*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    return env.Null();

}


#ifdef VK_KHR_external_semaphore_win32
static Napi::Value rawGetSemaphoreWin32HandleKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo = (VkSemaphoreGetWin32HandleInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    HANDLE* pHandle = (HANDLE*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_external_semaphore_win32
static Napi::Value rawImportSemaphoreWin32HandleKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo = (VkImportSemaphoreWin32HandleInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_external_semaphore_fd
static Napi::Value rawGetSemaphoreFdKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphoreGetFdInfoKHR* pGetFdInfo = (VkSemaphoreGetFdInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int* pFd = (int*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetSemaphoreFdKHR(device, pGetFdInfo, pFd);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_external_semaphore_fd
static Napi::Value rawImportSemaphoreFdKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo = (VkImportSemaphoreFdInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_FUCHSIA_external_semaphore
static Napi::Value rawGetSemaphoreZirconHandleFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo = (VkSemaphoreGetZirconHandleInfoFUCHSIA*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    zx_handle_t* pZirconHandle = (zx_handle_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetSemaphoreZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_FUCHSIA_external_semaphore
static Napi::Value rawImportSemaphoreZirconHandleFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo = (VkImportSemaphoreZirconHandleInfoFUCHSIA*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkImportSemaphoreZirconHandleFUCHSIA(device, pImportSemaphoreZirconHandleInfo);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawGetPhysicalDeviceExternalFenceProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo = (VkPhysicalDeviceExternalFenceInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalFenceProperties* pExternalFenceProperties = (VkExternalFenceProperties*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    return env.Null();

}


#ifdef VK_KHR_external_fence_win32
static Napi::Value rawGetFenceWin32HandleKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo = (VkFenceGetWin32HandleInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    HANDLE* pHandle = (HANDLE*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_external_fence_win32
static Napi::Value rawImportFenceWin32HandleKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo = (VkImportFenceWin32HandleInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_external_fence_fd
static Napi::Value rawGetFenceFdKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFenceGetFdInfoKHR* pGetFdInfo = (VkFenceGetFdInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int* pFd = (int*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetFenceFdKHR(device, pGetFdInfo, pFd);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_external_fence_fd
static Napi::Value rawImportFenceFdKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImportFenceFdInfoKHR* pImportFenceFdInfo = (VkImportFenceFdInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkImportFenceFdKHR(device, pImportFenceFdInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_direct_mode_display
static Napi::Value rawReleaseDisplayEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkReleaseDisplayEXT(physicalDevice, display);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_acquire_xlib_display
static Napi::Value rawAcquireXlibDisplayEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    Display* dpy = (Display*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkAcquireXlibDisplayEXT(physicalDevice, dpy, display);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_acquire_xlib_display
static Napi::Value rawGetRandROutputDisplayEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    Display* dpy = (Display*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    RROutput rrOutput = (RROutput)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR* pDisplay = (VkDisplayKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_acquire_winrt_display
static Napi::Value rawAcquireWinrtDisplayNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkAcquireWinrtDisplayNV(physicalDevice, display);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_acquire_winrt_display
static Napi::Value rawGetWinrtDisplayNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t deviceRelativeId = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR* pDisplay = (VkDisplayKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetWinrtDisplayNV(physicalDevice, deviceRelativeId, pDisplay);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_display_control
static Napi::Value rawDisplayPowerControlEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPowerInfoEXT* pDisplayPowerInfo = (VkDisplayPowerInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkDisplayPowerControlEXT(device, display, pDisplayPowerInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_display_control
static Napi::Value rawRegisterDeviceEventEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceEventInfoEXT* pDeviceEventInfo = (VkDeviceEventInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence* pFence = (VkFence*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_display_control
static Napi::Value rawRegisterDisplayEventEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayEventInfoEXT* pDisplayEventInfo = (VkDisplayEventInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence* pFence = (VkFence*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_display_control
static Napi::Value rawGetSwapchainCounterEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceCounterFlagBitsEXT counter = (VkSurfaceCounterFlagBitsEXT)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* pCounterValue = (uint64_t*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_display_surface_counter
static Napi::Value rawGetPhysicalDeviceSurfaceCapabilities2EXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceCapabilities2EXT* pSurfaceCapabilities = (VkSurfaceCapabilities2EXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawEnumeratePhysicalDeviceGroups(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPhysicalDeviceGroupCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties = (VkPhysicalDeviceGroupProperties*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    return Napi::Number::New(env, result);

}



static Napi::Value rawGetDeviceGroupPeerMemoryFeatures(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t heapIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t localDeviceIndex = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t remoteDeviceIndex = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPeerMemoryFeatureFlags* pPeerMemoryFeatures = (VkPeerMemoryFeatureFlags*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    return env.Null();

}



static Napi::Value rawBindBufferMemory2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindInfoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBindBufferMemoryInfo* pBindInfos = (VkBindBufferMemoryInfo*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkBindBufferMemory2(device, bindInfoCount, pBindInfos);
    return Napi::Number::New(env, result);

}



static Napi::Value rawBindImageMemory2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindInfoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBindImageMemoryInfo* pBindInfos = (VkBindImageMemoryInfo*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkBindImageMemory2(device, bindInfoCount, pBindInfos);
    return Napi::Number::New(env, result);

}



static Napi::Value rawCmdSetDeviceMask(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t deviceMask = (uint32_t)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDeviceMask(commandBuffer, deviceMask);
    return env.Null();

}


#ifdef VK_KHR_device_group
static Napi::Value rawGetDeviceGroupPresentCapabilitiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities = (VkDeviceGroupPresentCapabilitiesKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_device_group
static Napi::Value rawGetDeviceGroupSurfacePresentModesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceGroupPresentModeFlagsKHR* pModes = (VkDeviceGroupPresentModeFlagsKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_device_group
static Napi::Value rawAcquireNextImage2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAcquireNextImageInfoKHR* pAcquireInfo = (VkAcquireNextImageInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pImageIndex = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawCmdDispatchBase(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t baseGroupX = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t baseGroupY = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t baseGroupZ = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountX = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountY = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountZ = (uint32_t)info[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    return env.Null();

}


#ifdef VK_KHR_device_group
static Napi::Value rawGetPhysicalDevicePresentRectanglesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pRectCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRect2D* pRects = (VkRect2D*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawCreateDescriptorUpdateTemplate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorUpdateTemplateCreateInfo* pCreateInfo = (VkDescriptorUpdateTemplateCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate = (VkDescriptorUpdateTemplate*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyDescriptorUpdateTemplate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorUpdateTemplate descriptorUpdateTemplate = (VkDescriptorUpdateTemplate)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
    return env.Null();

}



static Napi::Value rawUpdateDescriptorSetWithTemplate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSet descriptorSet = (VkDescriptorSet)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorUpdateTemplate descriptorUpdateTemplate = (VkDescriptorUpdateTemplate)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    return env.Null();

}


#ifdef VK_KHR_descriptor_update_template
static Napi::Value rawCmdPushDescriptorSetWithTemplateKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorUpdateTemplate descriptorUpdateTemplate = (VkDescriptorUpdateTemplate)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayout layout = (VkPipelineLayout)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t set = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    return env.Null();

}
#endif

#ifdef VK_EXT_hdr_metadata
static Napi::Value rawSetHdrMetadataEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t swapchainCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR* pSwapchains = (VkSwapchainKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkHdrMetadataEXT* pMetadata = (VkHdrMetadataEXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
    return env.Null();

}
#endif

#ifdef VK_KHR_shared_presentable_image
static Napi::Value rawGetSwapchainStatusKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetSwapchainStatusKHR(device, swapchain);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_GOOGLE_display_timing
static Napi::Value rawGetRefreshCycleDurationGOOGLE(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties = (VkRefreshCycleDurationGOOGLE*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_GOOGLE_display_timing
static Napi::Value rawGetPastPresentationTimingGOOGLE(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPresentationTimingCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPastPresentationTimingGOOGLE* pPresentationTimings = (VkPastPresentationTimingGOOGLE*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_MVK_ios_surface
static Napi::Value rawCreateIOSSurfaceMVK(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkIOSSurfaceCreateInfoMVK* pCreateInfo = (VkIOSSurfaceCreateInfoMVK*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_MVK_macos_surface
static Napi::Value rawCreateMacOSSurfaceMVK(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMacOSSurfaceCreateInfoMVK* pCreateInfo = (VkMacOSSurfaceCreateInfoMVK*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_metal_surface
static Napi::Value rawCreateMetalSurfaceEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMetalSurfaceCreateInfoEXT* pCreateInfo = (VkMetalSurfaceCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateMetalSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_clip_space_w_scaling
static Napi::Value rawCmdSetViewportWScalingNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstViewport = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t viewportCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkViewportWScalingNV* pViewportWScalings = (VkViewportWScalingNV*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    return env.Null();

}
#endif

#ifdef VK_EXT_discard_rectangles
static Napi::Value rawCmdSetDiscardRectangleEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstDiscardRectangle = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t discardRectangleCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRect2D* pDiscardRectangles = (VkRect2D*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    return env.Null();

}
#endif

#ifdef VK_EXT_sample_locations
static Napi::Value rawCmdSetSampleLocationsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampleLocationsInfoEXT* pSampleLocationsInfo = (VkSampleLocationsInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_sample_locations
static Napi::Value rawGetPhysicalDeviceMultisamplePropertiesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampleCountFlagBits samples = (VkSampleCountFlagBits)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMultisamplePropertiesEXT* pMultisampleProperties = (VkMultisamplePropertiesEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
    return env.Null();

}
#endif

#ifdef VK_KHR_get_surface_capabilities2
static Napi::Value rawGetPhysicalDeviceSurfaceCapabilities2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo = (VkPhysicalDeviceSurfaceInfo2KHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceCapabilities2KHR* pSurfaceCapabilities = (VkSurfaceCapabilities2KHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_get_surface_capabilities2
static Napi::Value rawGetPhysicalDeviceSurfaceFormats2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo = (VkPhysicalDeviceSurfaceInfo2KHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pSurfaceFormatCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceFormat2KHR* pSurfaceFormats = (VkSurfaceFormat2KHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_get_display_properties2
static Napi::Value rawGetPhysicalDeviceDisplayProperties2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayProperties2KHR* pProperties = (VkDisplayProperties2KHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_get_display_properties2
static Napi::Value rawGetPhysicalDeviceDisplayPlaneProperties2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPlaneProperties2KHR* pProperties = (VkDisplayPlaneProperties2KHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_get_display_properties2
static Napi::Value rawGetDisplayModeProperties2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayModeProperties2KHR* pProperties = (VkDisplayModeProperties2KHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_get_display_properties2
static Napi::Value rawGetDisplayPlaneCapabilities2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo = (VkDisplayPlaneInfo2KHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPlaneCapabilities2KHR* pCapabilities = (VkDisplayPlaneCapabilities2KHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawGetBufferMemoryRequirements2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferMemoryRequirementsInfo2* pInfo = (VkBufferMemoryRequirementsInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements2* pMemoryRequirements = (VkMemoryRequirements2*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    return env.Null();

}



static Napi::Value rawGetImageMemoryRequirements2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageMemoryRequirementsInfo2* pInfo = (VkImageMemoryRequirementsInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements2* pMemoryRequirements = (VkMemoryRequirements2*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
    return env.Null();

}



static Napi::Value rawGetImageSparseMemoryRequirements2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageSparseMemoryRequirementsInfo2* pInfo = (VkImageSparseMemoryRequirementsInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pSparseMemoryRequirementCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSparseImageMemoryRequirements2* pSparseMemoryRequirements = (VkSparseImageMemoryRequirements2*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    return env.Null();

}



static Napi::Value rawGetDeviceBufferMemoryRequirements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceBufferMemoryRequirements* pInfo = (VkDeviceBufferMemoryRequirements*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements2* pMemoryRequirements = (VkMemoryRequirements2*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements);
    return env.Null();

}



static Napi::Value rawGetDeviceImageMemoryRequirements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceImageMemoryRequirements* pInfo = (VkDeviceImageMemoryRequirements*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements2* pMemoryRequirements = (VkMemoryRequirements2*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements);
    return env.Null();

}



static Napi::Value rawGetDeviceImageSparseMemoryRequirements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceImageMemoryRequirements* pInfo = (VkDeviceImageMemoryRequirements*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pSparseMemoryRequirementCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSparseImageMemoryRequirements2* pSparseMemoryRequirements = (VkSparseImageMemoryRequirements2*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    return env.Null();

}



static Napi::Value rawCreateSamplerYcbcrConversion(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSamplerYcbcrConversionCreateInfo* pCreateInfo = (VkSamplerYcbcrConversionCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSamplerYcbcrConversion* pYcbcrConversion = (VkSamplerYcbcrConversion*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroySamplerYcbcrConversion(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSamplerYcbcrConversion ycbcrConversion = (VkSamplerYcbcrConversion)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
    return env.Null();

}



static Napi::Value rawGetDeviceQueue2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceQueueInfo2* pQueueInfo = (VkDeviceQueueInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue* pQueue = (VkQueue*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceQueue2(device, pQueueInfo, pQueue);
    return env.Null();

}


#ifdef VK_EXT_validation_cache
static Napi::Value rawCreateValidationCacheEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkValidationCacheCreateInfoEXT* pCreateInfo = (VkValidationCacheCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkValidationCacheEXT* pValidationCache = (VkValidationCacheEXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_validation_cache
static Napi::Value rawDestroyValidationCacheEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkValidationCacheEXT validationCache = (VkValidationCacheEXT)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyValidationCacheEXT(device, validationCache, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_EXT_validation_cache
static Napi::Value rawGetValidationCacheDataEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkValidationCacheEXT validationCache = (VkValidationCacheEXT)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t* pDataSize = (size_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_validation_cache
static Napi::Value rawMergeValidationCachesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkValidationCacheEXT dstCache = (VkValidationCacheEXT)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t srcCacheCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkValidationCacheEXT* pSrcCaches = (VkValidationCacheEXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkMergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawGetDescriptorSetLayoutSupport(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetLayoutCreateInfo* pCreateInfo = (VkDescriptorSetLayoutCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetLayoutSupport* pSupport = (VkDescriptorSetLayoutSupport*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
    return env.Null();

}


#ifdef VK_ANDROID_native_buffer
static Napi::Value rawGetSwapchainGrallocUsageANDROID(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageUsageFlags imageUsage = (VkImageUsageFlags)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int* grallocUsage = (int*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetSwapchainGrallocUsageANDROID(device, format, imageUsage, grallocUsage);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_ANDROID_native_buffer
static Napi::Value rawGetSwapchainGrallocUsage2ANDROID(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageUsageFlags imageUsage = (VkImageUsageFlags)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainImageUsageFlagsANDROID swapchainImageUsage = (VkSwapchainImageUsageFlagsANDROID)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* grallocConsumerUsage = (uint64_t*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* grallocProducerUsage = (uint64_t*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetSwapchainGrallocUsage2ANDROID(device, format, imageUsage, swapchainImageUsage, grallocConsumerUsage, grallocProducerUsage);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_ANDROID_native_buffer
static Napi::Value rawAcquireImageANDROID(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int nativeFenceFd = (int)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphore semaphore = (VkSemaphore)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkAcquireImageANDROID(device, image, nativeFenceFd, semaphore, fence);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_ANDROID_native_buffer
static Napi::Value rawQueueSignalReleaseImageANDROID(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t waitSemaphoreCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphore* pWaitSemaphores = (VkSemaphore*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int* pNativeFenceFd = (int*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkQueueSignalReleaseImageANDROID(queue, waitSemaphoreCount, pWaitSemaphores, image, pNativeFenceFd);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_AMD_shader_info
static Napi::Value rawGetShaderInfoAMD(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderStageFlagBits shaderStage = (VkShaderStageFlagBits)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderInfoTypeAMD infoType = (VkShaderInfoTypeAMD)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t* pInfoSize = (size_t*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pInfo = (void*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_AMD_display_native_hdr
static Napi::Value rawSetLocalDimmingAMD(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapChain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 localDimmingEnable = (VkBool32)info[2].As<Napi::Number>().Uint32Value();
    
    ::vkSetLocalDimmingAMD(device, swapChain, localDimmingEnable);
    return env.Null();

}
#endif

#ifdef VK_EXT_calibrated_timestamps
static Napi::Value rawGetPhysicalDeviceCalibrateableTimeDomainsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pTimeDomainCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkTimeDomainEXT* pTimeDomains = (VkTimeDomainEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_calibrated_timestamps
static Napi::Value rawGetCalibratedTimestampsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t timestampCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCalibratedTimestampInfoEXT* pTimestampInfos = (VkCalibratedTimestampInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* pTimestamps = (uint64_t*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* pMaxDeviation = (uint64_t*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_debug_utils
static Napi::Value rawSetDebugUtilsObjectNameEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsObjectNameInfoEXT* pNameInfo = (VkDebugUtilsObjectNameInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkSetDebugUtilsObjectNameEXT(device, pNameInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_debug_utils
static Napi::Value rawSetDebugUtilsObjectTagEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsObjectTagInfoEXT* pTagInfo = (VkDebugUtilsObjectTagInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkSetDebugUtilsObjectTagEXT(device, pTagInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_debug_utils
static Napi::Value rawQueueBeginDebugUtilsLabelEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsLabelEXT* pLabelInfo = (VkDebugUtilsLabelEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_debug_utils
static Napi::Value rawQueueEndDebugUtilsLabelEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkQueueEndDebugUtilsLabelEXT(queue);
    return env.Null();

}
#endif

#ifdef VK_EXT_debug_utils
static Napi::Value rawQueueInsertDebugUtilsLabelEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsLabelEXT* pLabelInfo = (VkDebugUtilsLabelEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_debug_utils
static Napi::Value rawCmdBeginDebugUtilsLabelEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsLabelEXT* pLabelInfo = (VkDebugUtilsLabelEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_debug_utils
static Napi::Value rawCmdEndDebugUtilsLabelEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndDebugUtilsLabelEXT(commandBuffer);
    return env.Null();

}
#endif

#ifdef VK_EXT_debug_utils
static Napi::Value rawCmdInsertDebugUtilsLabelEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsLabelEXT* pLabelInfo = (VkDebugUtilsLabelEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_debug_utils
static Napi::Value rawCreateDebugUtilsMessengerEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo = (VkDebugUtilsMessengerCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsMessengerEXT* pMessenger = (VkDebugUtilsMessengerEXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_debug_utils
static Napi::Value rawDestroyDebugUtilsMessengerEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsMessengerEXT messenger = (VkDebugUtilsMessengerEXT)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_EXT_debug_utils
static Napi::Value rawSubmitDebugUtilsMessageEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity = (VkDebugUtilsMessageSeverityFlagBitsEXT)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsMessageTypeFlagsEXT messageTypes = (VkDebugUtilsMessageTypeFlagsEXT)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsMessengerCallbackDataEXT* pCallbackData = (VkDebugUtilsMessengerCallbackDataEXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    return env.Null();

}
#endif

#ifdef VK_EXT_external_memory_host
static Napi::Value rawGetMemoryHostPointerPropertiesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalMemoryHandleTypeFlagBits handleType = (VkExternalMemoryHandleTypeFlagBits)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pHostPointer = (void*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties = (VkMemoryHostPointerPropertiesEXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_AMD_buffer_marker
static Napi::Value rawCmdWriteBufferMarkerAMD(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlagBits pipelineStage = (VkPipelineStageFlagBits)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize dstOffset = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t marker = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    return env.Null();

}
#endif


static Napi::Value rawCreateRenderPass2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPassCreateInfo2* pCreateInfo = (VkRenderPassCreateInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPass* pRenderPass = (VkRenderPass*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    return Napi::Number::New(env, result);

}



static Napi::Value rawCmdBeginRenderPass2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPassBeginInfo* pRenderPassBegin = (VkRenderPassBeginInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubpassBeginInfo* pSubpassBeginInfo = (VkSubpassBeginInfo*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    return env.Null();

}



static Napi::Value rawCmdNextSubpass2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubpassBeginInfo* pSubpassBeginInfo = (VkSubpassBeginInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubpassEndInfo* pSubpassEndInfo = (VkSubpassEndInfo*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    return env.Null();

}



static Napi::Value rawCmdEndRenderPass2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubpassEndInfo* pSubpassEndInfo = (VkSubpassEndInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    return env.Null();

}



static Napi::Value rawGetSemaphoreCounterValue(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphore semaphore = (VkSemaphore)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* pValue = (uint64_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetSemaphoreCounterValue(device, semaphore, pValue);
    return Napi::Number::New(env, result);

}



static Napi::Value rawWaitSemaphores(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphoreWaitInfo* pWaitInfo = (VkSemaphoreWaitInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t timeout = (uint64_t)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkWaitSemaphores(device, pWaitInfo, timeout);
    return Napi::Number::New(env, result);

}



static Napi::Value rawSignalSemaphore(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphoreSignalInfo* pSignalInfo = (VkSemaphoreSignalInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkSignalSemaphore(device, pSignalInfo);
    return Napi::Number::New(env, result);

}


#ifdef VK_ANDROID_external_memory_android_hardware_buffer
static Napi::Value rawGetAndroidHardwareBufferPropertiesANDROID(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    AHardwareBuffer* buffer = (AHardwareBuffer*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAndroidHardwareBufferPropertiesANDROID* pProperties = (VkAndroidHardwareBufferPropertiesANDROID*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_ANDROID_external_memory_android_hardware_buffer
static Napi::Value rawGetMemoryAndroidHardwareBufferANDROID(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo = (VkMemoryGetAndroidHardwareBufferInfoANDROID*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    AHardwareBuffer** pBuffer = (AHardwareBuffer**)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawCmdDrawIndirectCount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer countBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize countBufferOffset = (VkDeviceSize)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t maxDrawCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return env.Null();

}



static Napi::Value rawCmdDrawIndexedIndirectCount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer countBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize countBufferOffset = (VkDeviceSize)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t maxDrawCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return env.Null();

}


#ifdef VK_NV_device_diagnostic_checkpoints
static Napi::Value rawCmdSetCheckpointNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pCheckpointMarker = (void*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
    return env.Null();

}
#endif

#ifdef VK_NV_device_diagnostic_checkpoints
static Napi::Value rawGetQueueCheckpointDataNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pCheckpointDataCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCheckpointDataNV* pCheckpointData = (VkCheckpointDataNV*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
    return env.Null();

}
#endif

#ifdef VK_EXT_transform_feedback
static Napi::Value rawCmdBindTransformFeedbackBuffersEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstBinding = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindingCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer* pBuffers = (VkBuffer*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pOffsets = (VkDeviceSize*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pSizes = (VkDeviceSize*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
    return env.Null();

}
#endif

#ifdef VK_EXT_transform_feedback
static Napi::Value rawCmdBeginTransformFeedbackEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstCounterBuffer = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t counterBufferCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer* pCounterBuffers = (VkBuffer*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pCounterBufferOffsets = (VkDeviceSize*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    return env.Null();

}
#endif

#ifdef VK_EXT_transform_feedback
static Napi::Value rawCmdEndTransformFeedbackEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstCounterBuffer = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t counterBufferCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer* pCounterBuffers = (VkBuffer*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pCounterBufferOffsets = (VkDeviceSize*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    return env.Null();

}
#endif

#ifdef VK_EXT_transform_feedback
static Napi::Value rawCmdBeginQueryIndexedEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t query = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryControlFlags flags = (VkQueryControlFlags)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t index = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
    return env.Null();

}
#endif

#ifdef VK_EXT_transform_feedback
static Napi::Value rawCmdEndQueryIndexedEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t query = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t index = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
    return env.Null();

}
#endif

#ifdef VK_EXT_transform_feedback
static Napi::Value rawCmdDrawIndirectByteCountEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t instanceCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstInstance = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer counterBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize counterBufferOffset = (VkDeviceSize)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t counterOffset = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t vertexStride = (uint32_t)info[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    return env.Null();

}
#endif

#ifdef VK_NV_scissor_exclusive
static Napi::Value rawCmdSetExclusiveScissorNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstExclusiveScissor = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t exclusiveScissorCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRect2D* pExclusiveScissors = (VkRect2D*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
    return env.Null();

}
#endif

#ifdef VK_NV_shading_rate_image
static Napi::Value rawCmdBindShadingRateImageNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageView imageView = (VkImageView)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout imageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
    return env.Null();

}
#endif

#ifdef VK_NV_shading_rate_image
static Napi::Value rawCmdSetViewportShadingRatePaletteNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstViewport = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t viewportCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShadingRatePaletteNV* pShadingRatePalettes = (VkShadingRatePaletteNV*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
    return env.Null();

}
#endif

#ifdef VK_NV_shading_rate_image
static Napi::Value rawCmdSetCoarseSampleOrderNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCoarseSampleOrderTypeNV sampleOrderType = (VkCoarseSampleOrderTypeNV)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t customSampleOrderCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCoarseSampleOrderCustomNV* pCustomSampleOrders = (VkCoarseSampleOrderCustomNV*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
    return env.Null();

}
#endif

#ifdef VK_NV_mesh_shader
static Napi::Value rawCmdDrawMeshTasksNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t taskCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstTask = (uint32_t)info[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    return env.Null();

}
#endif

#ifdef VK_NV_mesh_shader
static Napi::Value rawCmdDrawMeshTasksIndirectNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t drawCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    return env.Null();

}
#endif

#ifdef VK_NV_mesh_shader
static Napi::Value rawCmdDrawMeshTasksIndirectCountNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer countBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize countBufferOffset = (VkDeviceSize)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t maxDrawCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return env.Null();

}
#endif

#ifdef VK_EXT_mesh_shader
static Napi::Value rawCmdDrawMeshTasksEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountX = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountY = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountZ = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
    return env.Null();

}
#endif

#ifdef VK_EXT_mesh_shader
static Napi::Value rawCmdDrawMeshTasksIndirectEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t drawCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
    return env.Null();

}
#endif

#ifdef VK_EXT_mesh_shader
static Napi::Value rawCmdDrawMeshTasksIndirectCountEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer countBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize countBufferOffset = (VkDeviceSize)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t maxDrawCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return env.Null();

}
#endif

#ifdef VK_NV_ray_tracing
static Napi::Value rawCompileDeferredNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t shader = (uint32_t)info[2].As<Napi::Number>().Uint32Value();
    
    auto result = ::vkCompileDeferredNV(device, pipeline, shader);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_ray_tracing
static Napi::Value rawCreateAccelerationStructureNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureCreateInfoNV* pCreateInfo = (VkAccelerationStructureCreateInfoNV*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV* pAccelerationStructure = (VkAccelerationStructureNV*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_HUAWEI_invocation_mask
static Napi::Value rawCmdBindInvocationMaskHUAWEI(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageView imageView = (VkImageView)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout imageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
    return env.Null();

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawDestroyAccelerationStructureKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureKHR accelerationStructure = (VkAccelerationStructureKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyAccelerationStructureKHR(device, accelerationStructure, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_NV_ray_tracing
static Napi::Value rawDestroyAccelerationStructureNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV accelerationStructure = (VkAccelerationStructureNV)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_NV_ray_tracing
static Napi::Value rawGetAccelerationStructureMemoryRequirementsNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureMemoryRequirementsInfoNV* pInfo = (VkAccelerationStructureMemoryRequirementsInfoNV*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements2KHR* pMemoryRequirements = (VkMemoryRequirements2KHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
    return env.Null();

}
#endif

#ifdef VK_NV_ray_tracing
static Napi::Value rawBindAccelerationStructureMemoryNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindInfoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBindAccelerationStructureMemoryInfoNV* pBindInfos = (VkBindAccelerationStructureMemoryInfoNV*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkBindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_ray_tracing
static Napi::Value rawCmdCopyAccelerationStructureNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV dst = (VkAccelerationStructureNV)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV src = (VkAccelerationStructureNV)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyAccelerationStructureModeKHR mode = (VkCopyAccelerationStructureModeKHR)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
    return env.Null();

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCmdCopyAccelerationStructureKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyAccelerationStructureInfoKHR* pInfo = (VkCopyAccelerationStructureInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
    return env.Null();

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCopyAccelerationStructureKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyAccelerationStructureInfoKHR* pInfo = (VkCopyAccelerationStructureInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCopyAccelerationStructureKHR(device, deferredOperation, pInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCmdCopyAccelerationStructureToMemoryKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyAccelerationStructureToMemoryInfoKHR* pInfo = (VkCopyAccelerationStructureToMemoryInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
    return env.Null();

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCopyAccelerationStructureToMemoryKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyAccelerationStructureToMemoryInfoKHR* pInfo = (VkCopyAccelerationStructureToMemoryInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCopyAccelerationStructureToMemoryKHR(device, deferredOperation, pInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCmdCopyMemoryToAccelerationStructureKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMemoryToAccelerationStructureInfoKHR* pInfo = (VkCopyMemoryToAccelerationStructureInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
    return env.Null();

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCopyMemoryToAccelerationStructureKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMemoryToAccelerationStructureInfoKHR* pInfo = (VkCopyMemoryToAccelerationStructureInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCopyMemoryToAccelerationStructureKHR(device, deferredOperation, pInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCmdWriteAccelerationStructuresPropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t accelerationStructureCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureKHR* pAccelerationStructures = (VkAccelerationStructureKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryType queryType = (VkQueryType)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    return env.Null();

}
#endif

#ifdef VK_NV_ray_tracing
static Napi::Value rawCmdWriteAccelerationStructuresPropertiesNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t accelerationStructureCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV* pAccelerationStructures = (VkAccelerationStructureNV*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryType queryType = (VkQueryType)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    return env.Null();

}
#endif

#ifdef VK_NV_ray_tracing
static Napi::Value rawCmdBuildAccelerationStructureNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 9) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureInfoNV* pInfo = (VkAccelerationStructureInfoNV*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer instanceData = (VkBuffer)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize instanceOffset = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 update = (VkBool32)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV dst = (VkAccelerationStructureNV)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV src = (VkAccelerationStructureNV)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer scratch = (VkBuffer)info[7].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[8].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize scratchOffset = (VkDeviceSize)info[8].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
    return env.Null();

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawWriteAccelerationStructuresPropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t accelerationStructureCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureKHR* pAccelerationStructures = (VkAccelerationStructureKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryType queryType = (VkQueryType)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t dataSize = (size_t)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t stride = (size_t)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkWriteAccelerationStructuresPropertiesKHR(device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawCmdTraceRaysKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t width = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t height = (uint32_t)info[6].As<Napi::Number>().Uint32Value();

    if (!info[7].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t depth = (uint32_t)info[7].As<Napi::Number>().Uint32Value();
    
    ::vkCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    return env.Null();

}
#endif

#ifdef VK_NV_ray_tracing
static Napi::Value rawCmdTraceRaysNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 15) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer raygenShaderBindingTableBuffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize raygenShaderBindingOffset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer missShaderBindingTableBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize missShaderBindingOffset = (VkDeviceSize)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize missShaderBindingStride = (VkDeviceSize)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer hitShaderBindingTableBuffer = (VkBuffer)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize hitShaderBindingOffset = (VkDeviceSize)info[7].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[8].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize hitShaderBindingStride = (VkDeviceSize)info[8].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[9].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer callableShaderBindingTableBuffer = (VkBuffer)info[9].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[10].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize callableShaderBindingOffset = (VkDeviceSize)info[10].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[11].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize callableShaderBindingStride = (VkDeviceSize)info[11].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[12].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t width = (uint32_t)info[12].As<Napi::Number>().Uint32Value();

    if (!info[13].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t height = (uint32_t)info[13].As<Napi::Number>().Uint32Value();

    if (!info[14].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t depth = (uint32_t)info[14].As<Napi::Number>().Uint32Value();
    
    ::vkCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
    return env.Null();

}
#endif

#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawGetRayTracingShaderGroupHandlesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstGroup = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t dataSize = (size_t)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetRayTracingShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawGetRayTracingCaptureReplayShaderGroupHandlesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstGroup = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t dataSize = (size_t)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_ray_tracing
static Napi::Value rawGetAccelerationStructureHandleNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV accelerationStructure = (VkAccelerationStructureNV)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t dataSize = (size_t)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_ray_tracing
static Napi::Value rawCreateRayTracingPipelinesNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache pipelineCache = (VkPipelineCache)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t createInfoCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRayTracingPipelineCreateInfoNV* pCreateInfos = (VkRayTracingPipelineCreateInfoNV*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline* pPipelines = (VkPipeline*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawCreateRayTracingPipelinesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache pipelineCache = (VkPipelineCache)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t createInfoCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRayTracingPipelineCreateInfoKHR* pCreateInfos = (VkRayTracingPipelineCreateInfoKHR*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline* pPipelines = (VkPipeline*)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_cooperative_matrix
static Napi::Value rawGetPhysicalDeviceCooperativeMatrixPropertiesNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCooperativeMatrixPropertiesNV* pProperties = (VkCooperativeMatrixPropertiesNV*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, pPropertyCount, pProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawCmdTraceRaysIndirectKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress indirectDeviceAddress = (VkDeviceAddress)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
    return env.Null();

}
#endif

#ifdef VK_KHR_ray_tracing_maintenance1
static Napi::Value rawCmdTraceRaysIndirect2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress indirectDeviceAddress = (VkDeviceAddress)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
    return env.Null();

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawGetDeviceAccelerationStructureCompatibilityKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureVersionInfoKHR* pVersionInfo = (VkAccelerationStructureVersionInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureCompatibilityKHR* pCompatibility = (VkAccelerationStructureCompatibilityKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceAccelerationStructureCompatibilityKHR(device, pVersionInfo, pCompatibility);
    return env.Null();

}
#endif

#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawGetRayTracingShaderGroupStackSizeKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t group = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderGroupShaderKHR groupShader = (VkShaderGroupShaderKHR)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetRayTracingShaderGroupStackSizeKHR(device, pipeline, group, groupShader);
    return Napi::BigInt::New(env, (uint64_t)result);

}
#endif

#ifdef VK_KHR_ray_tracing_pipeline
static Napi::Value rawCmdSetRayTracingPipelineStackSizeKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t pipelineStackSize = (uint32_t)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
    return env.Null();

}
#endif

#ifdef VK_NVX_image_view_handle
static Napi::Value rawGetImageViewHandleNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageViewHandleInfoNVX* pInfo = (VkImageViewHandleInfoNVX*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetImageViewHandleNVX(device, pInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NVX_image_view_handle
static Napi::Value rawGetImageViewAddressNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageView imageView = (VkImageView)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageViewAddressPropertiesNVX* pProperties = (VkImageViewAddressPropertiesNVX*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetImageViewAddressNVX(device, imageView, pProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_full_screen_exclusive
static Napi::Value rawGetPhysicalDeviceSurfacePresentModes2EXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo = (VkPhysicalDeviceSurfaceInfo2KHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPresentModeCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPresentModeKHR* pPresentModes = (VkPresentModeKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_full_screen_exclusive
static Napi::Value rawGetDeviceGroupSurfacePresentModes2EXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo = (VkPhysicalDeviceSurfaceInfo2KHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceGroupPresentModeFlagsKHR* pModes = (VkDeviceGroupPresentModeFlagsKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_full_screen_exclusive
static Napi::Value rawAcquireFullScreenExclusiveModeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkAcquireFullScreenExclusiveModeEXT(device, swapchain);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_full_screen_exclusive
static Napi::Value rawReleaseFullScreenExclusiveModeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkReleaseFullScreenExclusiveModeEXT(device, swapchain);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_performance_query
static Napi::Value rawEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pCounterCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceCounterKHR* pCounters = (VkPerformanceCounterKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceCounterDescriptionKHR* pCounterDescriptions = (VkPerformanceCounterDescriptionKHR*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_performance_query
static Napi::Value rawGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo = (VkQueryPoolPerformanceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pNumPasses = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
    return env.Null();

}
#endif

#ifdef VK_KHR_performance_query
static Napi::Value rawAcquireProfilingLockKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAcquireProfilingLockInfoKHR* pInfo = (VkAcquireProfilingLockInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkAcquireProfilingLockKHR(device, pInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_performance_query
static Napi::Value rawReleaseProfilingLockKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkReleaseProfilingLockKHR(device);
    return env.Null();

}
#endif

#ifdef VK_EXT_image_drm_format_modifier
static Napi::Value rawGetImageDrmFormatModifierPropertiesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageDrmFormatModifierPropertiesEXT* pProperties = (VkImageDrmFormatModifierPropertiesEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawGetBufferOpaqueCaptureAddress(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferDeviceAddressInfo* pInfo = (VkBufferDeviceAddressInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetBufferOpaqueCaptureAddress(device, pInfo);
    return Napi::BigInt::New(env, (uint64_t)result);

}



static Napi::Value rawGetBufferDeviceAddress(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferDeviceAddressInfo* pInfo = (VkBufferDeviceAddressInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetBufferDeviceAddress(device, pInfo);
    return Napi::BigInt::New(env, (uint64_t)result);

}


#ifdef VK_EXT_headless_surface
static Napi::Value rawCreateHeadlessSurfaceEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkHeadlessSurfaceCreateInfoEXT* pCreateInfo = (VkHeadlessSurfaceCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_coverage_reduction_mode
static Napi::Value rawGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pCombinationCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFramebufferMixedSamplesCombinationNV* pCombinations = (VkFramebufferMixedSamplesCombinationNV*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, pCombinationCount, pCombinations);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_INTEL_performance_query
static Napi::Value rawInitializePerformanceApiINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInitializePerformanceApiInfoINTEL* pInitializeInfo = (VkInitializePerformanceApiInfoINTEL*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkInitializePerformanceApiINTEL(device, pInitializeInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_INTEL_performance_query
static Napi::Value rawUninitializePerformanceApiINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkUninitializePerformanceApiINTEL(device);
    return env.Null();

}
#endif

#ifdef VK_INTEL_performance_query
static Napi::Value rawCmdSetPerformanceMarkerINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceMarkerInfoINTEL* pMarkerInfo = (VkPerformanceMarkerInfoINTEL*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_INTEL_performance_query
static Napi::Value rawCmdSetPerformanceStreamMarkerINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo = (VkPerformanceStreamMarkerInfoINTEL*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_INTEL_performance_query
static Napi::Value rawCmdSetPerformanceOverrideINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceOverrideInfoINTEL* pOverrideInfo = (VkPerformanceOverrideInfoINTEL*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_INTEL_performance_query
static Napi::Value rawAcquirePerformanceConfigurationINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo = (VkPerformanceConfigurationAcquireInfoINTEL*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceConfigurationINTEL* pConfiguration = (VkPerformanceConfigurationINTEL*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkAcquirePerformanceConfigurationINTEL(device, pAcquireInfo, pConfiguration);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_INTEL_performance_query
static Napi::Value rawReleasePerformanceConfigurationINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceConfigurationINTEL configuration = (VkPerformanceConfigurationINTEL)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkReleasePerformanceConfigurationINTEL(device, configuration);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_INTEL_performance_query
static Napi::Value rawQueueSetPerformanceConfigurationINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceConfigurationINTEL configuration = (VkPerformanceConfigurationINTEL)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkQueueSetPerformanceConfigurationINTEL(queue, configuration);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_INTEL_performance_query
static Napi::Value rawGetPerformanceParameterINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceParameterTypeINTEL parameter = (VkPerformanceParameterTypeINTEL)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceValueINTEL* pValue = (VkPerformanceValueINTEL*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPerformanceParameterINTEL(device, parameter, pValue);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawGetDeviceMemoryOpaqueCaptureAddress(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo = (VkDeviceMemoryOpaqueCaptureAddressInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
    return Napi::BigInt::New(env, (uint64_t)result);

}


#ifdef VK_KHR_pipeline_executable_properties
static Napi::Value rawGetPipelineExecutablePropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineInfoKHR* pPipelineInfo = (VkPipelineInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pExecutableCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineExecutablePropertiesKHR* pProperties = (VkPipelineExecutablePropertiesKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPipelineExecutablePropertiesKHR(device, pPipelineInfo, pExecutableCount, pProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_pipeline_executable_properties
static Napi::Value rawGetPipelineExecutableStatisticsKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineExecutableInfoKHR* pExecutableInfo = (VkPipelineExecutableInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pStatisticCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineExecutableStatisticKHR* pStatistics = (VkPipelineExecutableStatisticKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, pStatisticCount, pStatistics);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_pipeline_executable_properties
static Napi::Value rawGetPipelineExecutableInternalRepresentationsKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineExecutableInfoKHR* pExecutableInfo = (VkPipelineExecutableInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pInternalRepresentationCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations = (VkPipelineExecutableInternalRepresentationKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_line_rasterization
static Napi::Value rawCmdSetLineStippleEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t lineStippleFactor = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint16_t lineStipplePattern = (uint16_t)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    return env.Null();

}
#endif


static Napi::Value rawGetPhysicalDeviceToolProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pToolCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceToolProperties* pToolProperties = (VkPhysicalDeviceToolProperties*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties);
    return Napi::Number::New(env, result);

}


#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCreateAccelerationStructureKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureCreateInfoKHR* pCreateInfo = (VkAccelerationStructureCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureKHR* pAccelerationStructure = (VkAccelerationStructureKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateAccelerationStructureKHR(device, pCreateInfo, pAllocator, pAccelerationStructure);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCmdBuildAccelerationStructuresKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t infoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildGeometryInfoKHR* pInfos = (VkAccelerationStructureBuildGeometryInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildRangeInfoKHR** ppBuildRangeInfos = (VkAccelerationStructureBuildRangeInfoKHR**)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    return env.Null();

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawCmdBuildAccelerationStructuresIndirectKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t infoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildGeometryInfoKHR* pInfos = (VkAccelerationStructureBuildGeometryInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress* pIndirectDeviceAddresses = (VkDeviceAddress*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pIndirectStrides = (uint32_t*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t** ppMaxPrimitiveCounts = (uint32_t**)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
    return env.Null();

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawBuildAccelerationStructuresKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t infoCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildGeometryInfoKHR* pInfos = (VkAccelerationStructureBuildGeometryInfoKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildRangeInfoKHR** ppBuildRangeInfos = (VkAccelerationStructureBuildRangeInfoKHR**)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkBuildAccelerationStructuresKHR(device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawGetAccelerationStructureDeviceAddressKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureDeviceAddressInfoKHR* pInfo = (VkAccelerationStructureDeviceAddressInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetAccelerationStructureDeviceAddressKHR(device, pInfo);
    return Napi::BigInt::New(env, (uint64_t)result);

}
#endif

#ifdef VK_KHR_deferred_host_operations
static Napi::Value rawCreateDeferredOperationKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR* pDeferredOperation = (VkDeferredOperationKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateDeferredOperationKHR(device, pAllocator, pDeferredOperation);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_deferred_host_operations
static Napi::Value rawDestroyDeferredOperationKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR operation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyDeferredOperationKHR(device, operation, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_KHR_deferred_host_operations
static Napi::Value rawGetDeferredOperationMaxConcurrencyKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR operation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDeferredOperationMaxConcurrencyKHR(device, operation);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_deferred_host_operations
static Napi::Value rawGetDeferredOperationResultKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR operation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDeferredOperationResultKHR(device, operation);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_deferred_host_operations
static Napi::Value rawDeferredOperationJoinKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR operation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkDeferredOperationJoinKHR(device, operation);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawCmdSetCullMode(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCullModeFlags cullMode = (VkCullModeFlags)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetCullMode(commandBuffer, cullMode);
    return env.Null();

}



static Napi::Value rawCmdSetFrontFace(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFrontFace frontFace = (VkFrontFace)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetFrontFace(commandBuffer, frontFace);
    return env.Null();

}



static Napi::Value rawCmdSetPrimitiveTopology(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPrimitiveTopology primitiveTopology = (VkPrimitiveTopology)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    return env.Null();

}



static Napi::Value rawCmdSetViewportWithCount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t viewportCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkViewport* pViewports = (VkViewport*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    return env.Null();

}



static Napi::Value rawCmdSetScissorWithCount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t scissorCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRect2D* pScissors = (VkRect2D*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    return env.Null();

}



static Napi::Value rawCmdBindVertexBuffers2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstBinding = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindingCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer* pBuffers = (VkBuffer*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pOffsets = (VkDeviceSize*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pSizes = (VkDeviceSize*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pStrides = (VkDeviceSize*)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    return env.Null();

}



static Napi::Value rawCmdSetDepthTestEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 depthTestEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    return env.Null();

}



static Napi::Value rawCmdSetDepthWriteEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 depthWriteEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    return env.Null();

}



static Napi::Value rawCmdSetDepthCompareOp(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCompareOp depthCompareOp = (VkCompareOp)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    return env.Null();

}



static Napi::Value rawCmdSetDepthBoundsTestEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 depthBoundsTestEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    return env.Null();

}



static Napi::Value rawCmdSetStencilTestEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 stencilTestEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    return env.Null();

}



static Napi::Value rawCmdSetStencilOp(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilFaceFlags faceMask = (VkStencilFaceFlags)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilOp failOp = (VkStencilOp)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilOp passOp = (VkStencilOp)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilOp depthFailOp = (VkStencilOp)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCompareOp compareOp = (VkCompareOp)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    return env.Null();

}


#ifdef VK_EXT_extended_dynamic_state2
static Napi::Value rawCmdSetPatchControlPointsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t patchControlPoints = (uint32_t)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
    return env.Null();

}
#endif


static Napi::Value rawCmdSetRasterizerDiscardEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 rasterizerDiscardEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    return env.Null();

}



static Napi::Value rawCmdSetDepthBiasEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 depthBiasEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    return env.Null();

}


#ifdef VK_EXT_extended_dynamic_state2
static Napi::Value rawCmdSetLogicOpEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkLogicOp logicOp = (VkLogicOp)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetLogicOpEXT(commandBuffer, logicOp);
    return env.Null();

}
#endif


static Napi::Value rawCmdSetPrimitiveRestartEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 primitiveRestartEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    return env.Null();

}


#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetTessellationDomainOriginEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkTessellationDomainOrigin domainOrigin = (VkTessellationDomainOrigin)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetDepthClampEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 depthClampEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetPolygonModeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPolygonMode polygonMode = (VkPolygonMode)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetPolygonModeEXT(commandBuffer, polygonMode);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetRasterizationSamplesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampleCountFlagBits rasterizationSamples = (VkSampleCountFlagBits)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetSampleMaskEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampleCountFlagBits samples = (VkSampleCountFlagBits)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampleMask* pSampleMask = (VkSampleMask*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetAlphaToCoverageEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 alphaToCoverageEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetAlphaToOneEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 alphaToOneEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetLogicOpEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 logicOpEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetColorBlendEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstAttachment = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t attachmentCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32* pColorBlendEnables = (VkBool32*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetColorBlendEquationEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstAttachment = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t attachmentCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkColorBlendEquationEXT* pColorBlendEquations = (VkColorBlendEquationEXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetColorWriteMaskEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstAttachment = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t attachmentCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkColorComponentFlags* pColorWriteMasks = (VkColorComponentFlags*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetRasterizationStreamEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t rasterizationStream = (uint32_t)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetConservativeRasterizationModeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkConservativeRasterizationModeEXT conservativeRasterizationMode = (VkConservativeRasterizationModeEXT)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetExtraPrimitiveOverestimationSizeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float extraPrimitiveOverestimationSize = (float)info[1].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetDepthClipEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 depthClipEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetSampleLocationsEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 sampleLocationsEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetColorBlendAdvancedEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstAttachment = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t attachmentCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkColorBlendAdvancedEXT* pColorBlendAdvanced = (VkColorBlendAdvancedEXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetProvokingVertexModeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkProvokingVertexModeEXT provokingVertexMode = (VkProvokingVertexModeEXT)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetLineRasterizationModeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkLineRasterizationModeEXT lineRasterizationMode = (VkLineRasterizationModeEXT)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetLineStippleEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 stippledLineEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetDepthClipNegativeOneToOneEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 negativeOneToOne = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetViewportWScalingEnableNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 viewportWScalingEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetViewportSwizzleNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstViewport = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t viewportCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkViewportSwizzleNV* pViewportSwizzles = (VkViewportSwizzleNV*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetCoverageToColorEnableNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 coverageToColorEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetCoverageToColorLocationNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t coverageToColorLocation = (uint32_t)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetCoverageModulationModeNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCoverageModulationModeNV coverageModulationMode = (VkCoverageModulationModeNV)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetCoverageModulationTableEnableNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 coverageModulationTableEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetCoverageModulationTableNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t coverageModulationTableCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    float* pCoverageModulationTable = (float*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetShadingRateImageEnableNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 shadingRateImageEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetCoverageReductionModeNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCoverageReductionModeNV coverageReductionMode = (VkCoverageReductionModeNV)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
    return env.Null();

}
#endif

#ifdef VK_EXT_extended_dynamic_state3
static Napi::Value rawCmdSetRepresentativeFragmentTestEnableNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 representativeFragmentTestEnable = (VkBool32)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
    return env.Null();

}
#endif


static Napi::Value rawCreatePrivateDataSlot(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPrivateDataSlotCreateInfo* pCreateInfo = (VkPrivateDataSlotCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPrivateDataSlot* pPrivateDataSlot = (VkPrivateDataSlot*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    return Napi::Number::New(env, result);

}



static Napi::Value rawDestroyPrivateDataSlot(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPrivateDataSlot privateDataSlot = (VkPrivateDataSlot)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyPrivateDataSlot(device, privateDataSlot, pAllocator);
    return env.Null();

}



static Napi::Value rawSetPrivateData(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkObjectType objectType = (VkObjectType)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t objectHandle = (uint64_t)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPrivateDataSlot privateDataSlot = (VkPrivateDataSlot)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t data = (uint64_t)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkSetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
    return Napi::Number::New(env, result);

}



static Napi::Value rawGetPrivateData(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkObjectType objectType = (VkObjectType)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t objectHandle = (uint64_t)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPrivateDataSlot privateDataSlot = (VkPrivateDataSlot)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* pData = (uint64_t*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetPrivateData(device, objectType, objectHandle, privateDataSlot, pData);
    return env.Null();

}



static Napi::Value rawCmdCopyBuffer2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyBufferInfo2* pCopyBufferInfo = (VkCopyBufferInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    return env.Null();

}



static Napi::Value rawCmdCopyImage2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyImageInfo2* pCopyImageInfo = (VkCopyImageInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyImage2(commandBuffer, pCopyImageInfo);
    return env.Null();

}



static Napi::Value rawCmdBlitImage2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBlitImageInfo2* pBlitImageInfo = (VkBlitImageInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBlitImage2(commandBuffer, pBlitImageInfo);
    return env.Null();

}



static Napi::Value rawCmdCopyBufferToImage2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyBufferToImageInfo2* pCopyBufferToImageInfo = (VkCopyBufferToImageInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    return env.Null();

}



static Napi::Value rawCmdCopyImageToBuffer2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyImageToBufferInfo2* pCopyImageToBufferInfo = (VkCopyImageToBufferInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    return env.Null();

}



static Napi::Value rawCmdResolveImage2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkResolveImageInfo2* pResolveImageInfo = (VkResolveImageInfo2*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdResolveImage2(commandBuffer, pResolveImageInfo);
    return env.Null();

}


#ifdef VK_KHR_fragment_shading_rate
static Napi::Value rawCmdSetFragmentShadingRateKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExtent2D* pFragmentSize = (VkExtent2D*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFragmentShadingRateCombinerOpKHR* combinerOps = (VkFragmentShadingRateCombinerOpKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
    return env.Null();

}
#endif

#ifdef VK_KHR_fragment_shading_rate
static Napi::Value rawGetPhysicalDeviceFragmentShadingRatesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pFragmentShadingRateCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates = (VkPhysicalDeviceFragmentShadingRateKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_fragment_shading_rate_enums
static Napi::Value rawCmdSetFragmentShadingRateEnumNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFragmentShadingRateNV shadingRate = (VkFragmentShadingRateNV)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFragmentShadingRateCombinerOpKHR* combinerOps = (VkFragmentShadingRateCombinerOpKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
    return env.Null();

}
#endif

#ifdef VK_KHR_acceleration_structure
static Napi::Value rawGetAccelerationStructureBuildSizesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildTypeKHR buildType = (VkAccelerationStructureBuildTypeKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo = (VkAccelerationStructureBuildGeometryInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pMaxPrimitiveCounts = (uint32_t*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo = (VkAccelerationStructureBuildSizesInfoKHR*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetAccelerationStructureBuildSizesKHR(device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_vertex_input_dynamic_state
static Napi::Value rawCmdSetVertexInputEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t vertexBindingDescriptionCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions = (VkVertexInputBindingDescription2EXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t vertexAttributeDescriptionCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions = (VkVertexInputAttributeDescription2EXT*)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    return env.Null();

}
#endif

#ifdef VK_EXT_color_write_enable
static Napi::Value rawCmdSetColorWriteEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t attachmentCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32* pColorWriteEnables = (VkBool32*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
    return env.Null();

}
#endif


static Napi::Value rawCmdSetEvent2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDependencyInfo* pDependencyInfo = (VkDependencyInfo*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdSetEvent2(commandBuffer, event, pDependencyInfo);
    return env.Null();

}



static Napi::Value rawCmdResetEvent2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags2 stageMask = (VkPipelineStageFlags2)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdResetEvent2(commandBuffer, event, stageMask);
    return env.Null();

}



static Napi::Value rawCmdWaitEvents2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t eventCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent* pEvents = (VkEvent*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDependencyInfo* pDependencyInfos = (VkDependencyInfo*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    return env.Null();

}



static Napi::Value rawCmdPipelineBarrier2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDependencyInfo* pDependencyInfo = (VkDependencyInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    return env.Null();

}



static Napi::Value rawQueueSubmit2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t submitCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubmitInfo2* pSubmits = (VkSubmitInfo2*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkQueueSubmit2(queue, submitCount, pSubmits, fence);
    return Napi::Number::New(env, result);

}



static Napi::Value rawCmdWriteTimestamp2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags2 stage = (VkPipelineStageFlags2)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t query = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    return env.Null();

}


#ifdef VK_KHR_synchronization2
static Napi::Value rawCmdWriteBufferMarker2AMD(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags2 stage = (VkPipelineStageFlags2)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize dstOffset = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t marker = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
    return env.Null();

}
#endif

#ifdef VK_KHR_synchronization2
static Napi::Value rawGetQueueCheckpointData2NV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pCheckpointDataCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCheckpointData2NV* pCheckpointData = (VkCheckpointData2NV*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData);
    return env.Null();

}
#endif

#ifdef VK_KHR_video_queue
static Napi::Value rawGetPhysicalDeviceVideoCapabilitiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoProfileInfoKHR* pVideoProfile = (VkVideoProfileInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoCapabilitiesKHR* pCapabilities = (VkVideoCapabilitiesKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceVideoCapabilitiesKHR(physicalDevice, pVideoProfile, pCapabilities);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_video_queue
static Napi::Value rawGetPhysicalDeviceVideoFormatPropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo = (VkPhysicalDeviceVideoFormatInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pVideoFormatPropertyCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoFormatPropertiesKHR* pVideoFormatProperties = (VkVideoFormatPropertiesKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceVideoFormatPropertiesKHR(physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_video_queue
static Napi::Value rawCreateVideoSessionKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionCreateInfoKHR* pCreateInfo = (VkVideoSessionCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionKHR* pVideoSession = (VkVideoSessionKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateVideoSessionKHR(device, pCreateInfo, pAllocator, pVideoSession);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_video_queue
static Napi::Value rawDestroyVideoSessionKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionKHR videoSession = (VkVideoSessionKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyVideoSessionKHR(device, videoSession, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_KHR_video_queue
static Napi::Value rawCreateVideoSessionParametersKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionParametersCreateInfoKHR* pCreateInfo = (VkVideoSessionParametersCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionParametersKHR* pVideoSessionParameters = (VkVideoSessionParametersKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateVideoSessionParametersKHR(device, pCreateInfo, pAllocator, pVideoSessionParameters);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_video_queue
static Napi::Value rawUpdateVideoSessionParametersKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionParametersKHR videoSessionParameters = (VkVideoSessionParametersKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo = (VkVideoSessionParametersUpdateInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkUpdateVideoSessionParametersKHR(device, videoSessionParameters, pUpdateInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_video_queue
static Napi::Value rawDestroyVideoSessionParametersKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionParametersKHR videoSessionParameters = (VkVideoSessionParametersKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyVideoSessionParametersKHR(device, videoSessionParameters, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_KHR_video_queue
static Napi::Value rawGetVideoSessionMemoryRequirementsKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionKHR videoSession = (VkVideoSessionKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pMemoryRequirementsCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements = (VkVideoSessionMemoryRequirementsKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetVideoSessionMemoryRequirementsKHR(device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_video_queue
static Napi::Value rawBindVideoSessionMemoryKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionKHR videoSession = (VkVideoSessionKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindSessionMemoryInfoCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos = (VkBindVideoSessionMemoryInfoKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkBindVideoSessionMemoryKHR(device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_video_decode_queue
static Napi::Value rawCmdDecodeVideoKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoDecodeInfoKHR* pDecodeInfo = (VkVideoDecodeInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
    return env.Null();

}
#endif

#ifdef VK_KHR_video_queue
static Napi::Value rawCmdBeginVideoCodingKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoBeginCodingInfoKHR* pBeginInfo = (VkVideoBeginCodingInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
    return env.Null();

}
#endif

#ifdef VK_KHR_video_queue
static Napi::Value rawCmdControlVideoCodingKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoCodingControlInfoKHR* pCodingControlInfo = (VkVideoCodingControlInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
    return env.Null();

}
#endif

#ifdef VK_KHR_video_queue
static Napi::Value rawCmdEndVideoCodingKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoEndCodingInfoKHR* pEndCodingInfo = (VkVideoEndCodingInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
    return env.Null();

}
#endif

#ifdef VK_KHR_video_encode_queue
static Napi::Value rawCmdEncodeVideoKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoEncodeInfoKHR* pEncodeInfo = (VkVideoEncodeInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
    return env.Null();

}
#endif

#ifdef VK_NV_memory_decompression
static Napi::Value rawCmdDecompressMemoryNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t decompressRegionCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDecompressMemoryRegionNV* pDecompressMemoryRegions = (VkDecompressMemoryRegionNV*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
    return env.Null();

}
#endif

#ifdef VK_NV_memory_decompression
static Napi::Value rawCmdDecompressMemoryIndirectCountNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress indirectCommandsAddress = (VkDeviceAddress)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress indirectCommandsCountAddress = (VkDeviceAddress)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
    return env.Null();

}
#endif

#ifdef VK_NVX_binary_import
static Napi::Value rawCreateCuModuleNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuModuleCreateInfoNVX* pCreateInfo = (VkCuModuleCreateInfoNVX*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuModuleNVX* pModule = (VkCuModuleNVX*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateCuModuleNVX(device, pCreateInfo, pAllocator, pModule);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NVX_binary_import
static Napi::Value rawCreateCuFunctionNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuFunctionCreateInfoNVX* pCreateInfo = (VkCuFunctionCreateInfoNVX*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuFunctionNVX* pFunction = (VkCuFunctionNVX*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateCuFunctionNVX(device, pCreateInfo, pAllocator, pFunction);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NVX_binary_import
static Napi::Value rawDestroyCuModuleNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuModuleNVX module = (VkCuModuleNVX)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyCuModuleNVX(device, module, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_NVX_binary_import
static Napi::Value rawDestroyCuFunctionNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuFunctionNVX function = (VkCuFunctionNVX)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyCuFunctionNVX(device, function, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_NVX_binary_import
static Napi::Value rawCmdCuLaunchKernelNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuLaunchInfoNVX* pLaunchInfo = (VkCuLaunchInfoNVX*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_pageable_device_local_memory
static Napi::Value rawSetDeviceMemoryPriorityEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float priority = (float)info[2].As<Napi::Number>().FloatValue();
    
    ::vkSetDeviceMemoryPriorityEXT(device, memory, priority);
    return env.Null();

}
#endif

#ifdef VK_EXT_acquire_drm_display
static Napi::Value rawAcquireDrmDisplayEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    int32_t drmFd = (int32_t)info[1].As<Napi::Number>().Int32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkAcquireDrmDisplayEXT(physicalDevice, drmFd, display);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_acquire_drm_display
static Napi::Value rawGetDrmDisplayEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    int32_t drmFd = (int32_t)info[1].As<Napi::Number>().Int32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t connectorId = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR* display = (VkDisplayKHR*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDrmDisplayEXT(physicalDevice, drmFd, connectorId, display);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_KHR_present_wait
static Napi::Value rawWaitForPresentKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t presentId = (uint64_t)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t timeout = (uint64_t)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkWaitForPresentKHR(device, swapchain, presentId, timeout);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_FUCHSIA_buffer_collection
static Napi::Value rawCreateBufferCollectionFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionCreateInfoFUCHSIA* pCreateInfo = (VkBufferCollectionCreateInfoFUCHSIA*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionFUCHSIA* pCollection = (VkBufferCollectionFUCHSIA*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateBufferCollectionFUCHSIA(device, pCreateInfo, pAllocator, pCollection);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_FUCHSIA_buffer_collection
static Napi::Value rawSetBufferCollectionBufferConstraintsFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionFUCHSIA collection = (VkBufferCollectionFUCHSIA)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo = (VkBufferConstraintsInfoFUCHSIA*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkSetBufferCollectionBufferConstraintsFUCHSIA(device, collection, pBufferConstraintsInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_FUCHSIA_buffer_collection
static Napi::Value rawSetBufferCollectionImageConstraintsFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionFUCHSIA collection = (VkBufferCollectionFUCHSIA)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo = (VkImageConstraintsInfoFUCHSIA*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkSetBufferCollectionImageConstraintsFUCHSIA(device, collection, pImageConstraintsInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_FUCHSIA_buffer_collection
static Napi::Value rawDestroyBufferCollectionFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionFUCHSIA collection = (VkBufferCollectionFUCHSIA)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyBufferCollectionFUCHSIA(device, collection, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_FUCHSIA_buffer_collection
static Napi::Value rawGetBufferCollectionPropertiesFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionFUCHSIA collection = (VkBufferCollectionFUCHSIA)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionPropertiesFUCHSIA* pProperties = (VkBufferCollectionPropertiesFUCHSIA*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetBufferCollectionPropertiesFUCHSIA(device, collection, pProperties);
    return Napi::Number::New(env, result);

}
#endif


static Napi::Value rawCmdBeginRendering(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderingInfo* pRenderingInfo = (VkRenderingInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBeginRendering(commandBuffer, pRenderingInfo);
    return env.Null();

}



static Napi::Value rawCmdEndRendering(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdEndRendering(commandBuffer);
    return env.Null();

}


#ifdef VK_VALVE_descriptor_set_host_mapping
static Napi::Value rawGetDescriptorSetLayoutHostMappingInfoVALVE(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetBindingReferenceVALVE* pBindingReference = (VkDescriptorSetBindingReferenceVALVE*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping = (VkDescriptorSetLayoutHostMappingInfoVALVE*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDescriptorSetLayoutHostMappingInfoVALVE(device, pBindingReference, pHostMapping);
    return env.Null();

}
#endif

#ifdef VK_VALVE_descriptor_set_host_mapping
static Napi::Value rawGetDescriptorSetHostMappingVALVE(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSet descriptorSet = (VkDescriptorSet)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void** ppData = (void**)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDescriptorSetHostMappingVALVE(device, descriptorSet, ppData);
    return env.Null();

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCreateMicromapEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapCreateInfoEXT* pCreateInfo = (VkMicromapCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapEXT* pMicromap = (VkMicromapEXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateMicromapEXT(device, pCreateInfo, pAllocator, pMicromap);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCmdBuildMicromapsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t infoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapBuildInfoEXT* pInfos = (VkMicromapBuildInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
    return env.Null();

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawBuildMicromapsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t infoCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapBuildInfoEXT* pInfos = (VkMicromapBuildInfoEXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkBuildMicromapsEXT(device, deferredOperation, infoCount, pInfos);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawDestroyMicromapEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapEXT micromap = (VkMicromapEXT)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyMicromapEXT(device, micromap, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCmdCopyMicromapEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMicromapInfoEXT* pInfo = (VkCopyMicromapInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyMicromapEXT(commandBuffer, pInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCopyMicromapEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMicromapInfoEXT* pInfo = (VkCopyMicromapInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCopyMicromapEXT(device, deferredOperation, pInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCmdCopyMicromapToMemoryEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMicromapToMemoryInfoEXT* pInfo = (VkCopyMicromapToMemoryInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCopyMicromapToMemoryEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMicromapToMemoryInfoEXT* pInfo = (VkCopyMicromapToMemoryInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCopyMicromapToMemoryEXT(device, deferredOperation, pInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCmdCopyMemoryToMicromapEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMemoryToMicromapInfoEXT* pInfo = (VkCopyMemoryToMicromapInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCopyMemoryToMicromapEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMemoryToMicromapInfoEXT* pInfo = (VkCopyMemoryToMicromapInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCopyMemoryToMicromapEXT(device, deferredOperation, pInfo);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawCmdWriteMicromapsPropertiesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t micromapCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapEXT* pMicromaps = (VkMicromapEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryType queryType = (VkQueryType)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
    return env.Null();

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawWriteMicromapsPropertiesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t micromapCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapEXT* pMicromaps = (VkMicromapEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryType queryType = (VkQueryType)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t dataSize = (size_t)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[5].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t stride = (size_t)info[6].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkWriteMicromapsPropertiesEXT(device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawGetDeviceMicromapCompatibilityEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapVersionInfoEXT* pVersionInfo = (VkMicromapVersionInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureCompatibilityKHR* pCompatibility = (VkAccelerationStructureCompatibilityKHR*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetDeviceMicromapCompatibilityEXT(device, pVersionInfo, pCompatibility);
    return env.Null();

}
#endif

#ifdef VK_EXT_opacity_micromap
static Napi::Value rawGetMicromapBuildSizesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildTypeKHR buildType = (VkAccelerationStructureBuildTypeKHR)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapBuildInfoEXT* pBuildInfo = (VkMicromapBuildInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapBuildSizesInfoEXT* pSizeInfo = (VkMicromapBuildSizesInfoEXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetMicromapBuildSizesEXT(device, buildType, pBuildInfo, pSizeInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_shader_module_identifier
static Napi::Value rawGetShaderModuleIdentifierEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModule shaderModule = (VkShaderModule)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModuleIdentifierEXT* pIdentifier = (VkShaderModuleIdentifierEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetShaderModuleIdentifierEXT(device, shaderModule, pIdentifier);
    return env.Null();

}
#endif

#ifdef VK_EXT_shader_module_identifier
static Napi::Value rawGetShaderModuleCreateInfoIdentifierEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModuleCreateInfo* pCreateInfo = (VkShaderModuleCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModuleIdentifierEXT* pIdentifier = (VkShaderModuleIdentifierEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetShaderModuleCreateInfoIdentifierEXT(device, pCreateInfo, pIdentifier);
    return env.Null();

}
#endif

#ifdef VK_EXT_image_compression_control
static Napi::Value rawGetImageSubresourceLayout2EXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageSubresource2EXT* pSubresource = (VkImageSubresource2EXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubresourceLayout2EXT* pLayout = (VkSubresourceLayout2EXT*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkGetImageSubresourceLayout2EXT(device, image, pSubresource, pLayout);
    return env.Null();

}
#endif

#ifdef VK_EXT_pipeline_properties
static Napi::Value rawGetPipelinePropertiesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineInfoEXT* pPipelineInfo = (VkPipelineInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBaseOutStructure* pPipelineProperties = (VkBaseOutStructure*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPipelinePropertiesEXT(device, pPipelineInfo, pPipelineProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_EXT_metal_objects
static Napi::Value rawExportMetalObjectsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExportMetalObjectsInfoEXT* pMetalObjectsInfo = (VkExportMetalObjectsInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkExportMetalObjectsEXT(device, pMetalObjectsInfo);
    return env.Null();

}
#endif

#ifdef VK_QCOM_tile_properties
static Napi::Value rawGetFramebufferTilePropertiesQCOM(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFramebuffer framebuffer = (VkFramebuffer)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertiesCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkTilePropertiesQCOM* pProperties = (VkTilePropertiesQCOM*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetFramebufferTilePropertiesQCOM(device, framebuffer, pPropertiesCount, pProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_QCOM_tile_properties
static Napi::Value rawGetDynamicRenderingTilePropertiesQCOM(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderingInfo* pRenderingInfo = (VkRenderingInfo*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkTilePropertiesQCOM* pProperties = (VkTilePropertiesQCOM*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDynamicRenderingTilePropertiesQCOM(device, pRenderingInfo, pProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_optical_flow
static Napi::Value rawGetPhysicalDeviceOpticalFlowImageFormatsNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo = (VkOpticalFlowImageFormatInfoNV*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pFormatCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties = (VkOpticalFlowImageFormatPropertiesNV*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetPhysicalDeviceOpticalFlowImageFormatsNV(physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_optical_flow
static Napi::Value rawCreateOpticalFlowSessionNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowSessionCreateInfoNV* pCreateInfo = (VkOpticalFlowSessionCreateInfoNV*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowSessionNV* pSession = (VkOpticalFlowSessionNV*)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkCreateOpticalFlowSessionNV(device, pCreateInfo, pAllocator, pSession);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_optical_flow
static Napi::Value rawDestroyOpticalFlowSessionNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowSessionNV session = (VkOpticalFlowSessionNV)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkDestroyOpticalFlowSessionNV(device, session, pAllocator);
    return env.Null();

}
#endif

#ifdef VK_NV_optical_flow
static Napi::Value rawBindOpticalFlowSessionImageNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowSessionNV session = (VkOpticalFlowSessionNV)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowSessionBindingPointNV bindingPoint = (VkOpticalFlowSessionBindingPointNV)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageView view = (VkImageView)info[3].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout layout = (VkImageLayout)info[4].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkBindOpticalFlowSessionImageNV(device, session, bindingPoint, view, layout);
    return Napi::Number::New(env, result);

}
#endif

#ifdef VK_NV_optical_flow
static Napi::Value rawCmdOpticalFlowExecuteNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowSessionNV session = (VkOpticalFlowSessionNV)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowExecuteInfoNV* pExecuteInfo = (VkOpticalFlowExecuteInfoNV*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    ::vkCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
    return env.Null();

}
#endif

#ifdef VK_EXT_device_fault
static Napi::Value rawGetDeviceFaultInfoEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    bool lossless = true;

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceFaultCountsEXT* pFaultCounts = (VkDeviceFaultCountsEXT*)info[1].As<Napi::BigInt>().Uint64Value(&lossless);;

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceFaultInfoEXT* pFaultInfo = (VkDeviceFaultInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value(&lossless);;
    
    auto result = ::vkGetDeviceFaultInfoEXT(device, pFaultCounts, pFaultInfo);
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
    