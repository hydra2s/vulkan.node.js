
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

    

#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateInstance(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstanceCreateInfo* pCreateInfo = (VkInstanceCreateInfo*)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance* pInstance = (VkInstance*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateInstance(pCreateInfo, pAllocator, pInstance);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyInstance(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void  = (void)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyInstance(instance, pAllocator, );
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawEnumeratePhysicalDevices(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPhysicalDeviceCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice* pPhysicalDevices = (VkPhysicalDevice*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceProcAddr(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    char* pName = (char*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceProcAddr(device, pName);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetInstanceProcAddr(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    char* pName = (char*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetInstanceProcAddr(instance, pName);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceProperties* pProperties = (VkPhysicalDeviceProperties*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceQueueFamilyProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pQueueFamilyPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueueFamilyProperties* pQueueFamilyProperties = (VkQueueFamilyProperties*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceMemoryProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceMemoryProperties* pMemoryProperties = (VkPhysicalDeviceMemoryProperties*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceFeatures(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceFeatures* pFeatures = (VkPhysicalDeviceFeatures*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceFormatProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormatProperties* pFormatProperties = (VkFormatProperties*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceImageFormatProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageType type = (VkImageType)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageTiling tiling = (VkImageTiling)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageUsageFlags usage = (VkImageUsageFlags)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageCreateFlags flags = (VkImageCreateFlags)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageFormatProperties* pImageFormatProperties = (VkImageFormatProperties*)info[6].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateDevice(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceCreateInfo* pCreateInfo = (VkDeviceCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice* pDevice = (VkDevice*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyDevice(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void  = (void)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyDevice(device, pAllocator, );
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawEnumerateInstanceVersion(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pApiVersion = (uint32_t*)info[0].As<Napi::BigInt>().Uint64Value();
    
    ::vkEnumerateInstanceVersion(pApiVersion);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawEnumerateInstanceLayerProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkLayerProperties* pProperties = (VkLayerProperties*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawEnumerateInstanceExtensionProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    char* pLayerName = (char*)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExtensionProperties* pProperties = (VkExtensionProperties*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawEnumerateDeviceLayerProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkLayerProperties* pProperties = (VkLayerProperties*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkEnumerateDeviceLayerProperties(physicalDevice, pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawEnumerateDeviceExtensionProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    char* pLayerName = (char*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExtensionProperties* pProperties = (VkExtensionProperties*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceQueue(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueIndex = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue* pQueue = (VkQueue*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawQueueSubmit(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t submitCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubmitInfo* pSubmits = (VkSubmitInfo*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkQueueSubmit(queue, submitCount, pSubmits, fence);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawQueueWaitIdle(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value();
    
    ::vkQueueWaitIdle(queue);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDeviceWaitIdle(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void  = (void)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkDeviceWaitIdle(device, );
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawAllocateMemory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryAllocateInfo* pAllocateInfo = (VkMemoryAllocateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory* pMemory = (VkDeviceMemory*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawFreeMemory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkFreeMemory(device, memory, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawMapMemory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize size = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryMapFlags flags = (VkMemoryMapFlags)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void ppData = (void)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkMapMemory(device, memory, offset, size, flags, ppData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawUnmapMemory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkUnmapMemory(device, memory);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawFlushMappedMemoryRanges(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t memoryRangeCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMappedMemoryRange* pMemoryRanges = (VkMappedMemoryRange*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawInvalidateMappedMemoryRanges(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t memoryRangeCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMappedMemoryRange* pMemoryRanges = (VkMappedMemoryRange*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceMemoryCommitment(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pCommittedMemoryInBytes = (VkDeviceSize*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetBufferMemoryRequirements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements* pMemoryRequirements = (VkMemoryRequirements*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawBindBufferMemory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize memoryOffset = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkBindBufferMemory(device, buffer, memory, memoryOffset);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetImageMemoryRequirements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements* pMemoryRequirements = (VkMemoryRequirements*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawBindImageMemory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize memoryOffset = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkBindImageMemory(device, image, memory, memoryOffset);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetImageSparseMemoryRequirements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pSparseMemoryRequirementCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSparseImageMemoryRequirements* pSparseMemoryRequirements = (VkSparseImageMemoryRequirements*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceSparseImageFormatProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageType type = (VkImageType)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampleCountFlagBits samples = (VkSampleCountFlagBits)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageUsageFlags usage = (VkImageUsageFlags)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageTiling tiling = (VkImageTiling)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[6].As<Napi::BigInt>().Uint64Value();

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSparseImageFormatProperties* pProperties = (VkSparseImageFormatProperties*)info[7].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawQueueBindSparse(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindInfoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBindSparseInfo* pBindInfo = (VkBindSparseInfo*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateFence(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFenceCreateInfo* pCreateInfo = (VkFenceCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence* pFence = (VkFence*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateFence(device, pCreateInfo, pAllocator, pFence);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyFence(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyFence(device, fence, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawResetFences(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t fenceCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence* pFences = (VkFence*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkResetFences(device, fenceCount, pFences);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetFenceStatus(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetFenceStatus(device, fence);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawWaitForFences(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t fenceCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence* pFences = (VkFence*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 waitAll = (VkBool32)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t timeout = (uint64_t)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateSemaphore(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphoreCreateInfo* pCreateInfo = (VkSemaphoreCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphore* pSemaphore = (VkSemaphore*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroySemaphore(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphore semaphore = (VkSemaphore)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroySemaphore(device, semaphore, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateEvent(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEventCreateInfo* pCreateInfo = (VkEventCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent* pEvent = (VkEvent*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyEvent(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyEvent(device, event, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetEventStatus(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetEventStatus(device, event);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawSetEvent(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkSetEvent(device, event);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawResetEvent(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkResetEvent(device, event);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateQueryPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPoolCreateInfo* pCreateInfo = (VkQueryPoolCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool* pQueryPool = (VkQueryPool*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyQueryPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyQueryPool(device, queryPool, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetQueryPoolResults(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queryCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t dataSize = (size_t)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize stride = (VkDeviceSize)info[6].As<Napi::BigInt>().Uint64Value();

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryResultFlags flags = (VkQueryResultFlags)info[7].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawResetQueryPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queryCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkResetQueryPool(device, queryPool, firstQuery, queryCount);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCreateInfo* pCreateInfo = (VkBufferCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer* pBuffer = (VkBuffer*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyBuffer(device, buffer, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateBufferView(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferViewCreateInfo* pCreateInfo = (VkBufferViewCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferView* pView = (VkBufferView*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyBufferView(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferView bufferView = (VkBufferView)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyBufferView(device, bufferView, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageCreateInfo* pCreateInfo = (VkImageCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage* pImage = (VkImage*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateImage(device, pCreateInfo, pAllocator, pImage);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyImage(device, image, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetImageSubresourceLayout(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageSubresource* pSubresource = (VkImageSubresource*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubresourceLayout* pLayout = (VkSubresourceLayout*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateImageView(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageViewCreateInfo* pCreateInfo = (VkImageViewCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageView* pView = (VkImageView*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateImageView(device, pCreateInfo, pAllocator, pView);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyImageView(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageView imageView = (VkImageView)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyImageView(device, imageView, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateShaderModule(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModuleCreateInfo* pCreateInfo = (VkShaderModuleCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModule* pShaderModule = (VkShaderModule*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyShaderModule(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModule shaderModule = (VkShaderModule)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyShaderModule(device, shaderModule, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreatePipelineCache(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCacheCreateInfo* pCreateInfo = (VkPipelineCacheCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache* pPipelineCache = (VkPipelineCache*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyPipelineCache(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache pipelineCache = (VkPipelineCache)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyPipelineCache(device, pipelineCache, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPipelineCacheData(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache pipelineCache = (VkPipelineCache)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t* pDataSize = (size_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawMergePipelineCaches(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache dstCache = (VkPipelineCache)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t srcCacheCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache* pSrcCaches = (VkPipelineCache*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateGraphicsPipelines(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache pipelineCache = (VkPipelineCache)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t createInfoCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkGraphicsPipelineCreateInfo* pCreateInfos = (VkGraphicsPipelineCreateInfo*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline* pPipelines = (VkPipeline*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateComputePipelines(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache pipelineCache = (VkPipelineCache)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t createInfoCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkComputePipelineCreateInfo* pCreateInfos = (VkComputePipelineCreateInfo*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline* pPipelines = (VkPipeline*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPass renderpass = (VkRenderPass)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExtent2D* pMaxWorkgroupSize = (VkExtent2D*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(device, renderpass, pMaxWorkgroupSize);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyPipeline(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyPipeline(device, pipeline, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreatePipelineLayout(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayoutCreateInfo* pCreateInfo = (VkPipelineLayoutCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayout* pPipelineLayout = (VkPipelineLayout*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyPipelineLayout(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayout pipelineLayout = (VkPipelineLayout)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateSampler(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSamplerCreateInfo* pCreateInfo = (VkSamplerCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampler* pSampler = (VkSampler*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroySampler(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampler sampler = (VkSampler)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroySampler(device, sampler, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateDescriptorSetLayout(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetLayoutCreateInfo* pCreateInfo = (VkDescriptorSetLayoutCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetLayout* pSetLayout = (VkDescriptorSetLayout*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyDescriptorSetLayout(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetLayout descriptorSetLayout = (VkDescriptorSetLayout)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateDescriptorPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorPoolCreateInfo* pCreateInfo = (VkDescriptorPoolCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorPool* pDescriptorPool = (VkDescriptorPool*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyDescriptorPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorPool descriptorPool = (VkDescriptorPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawResetDescriptorPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorPool descriptorPool = (VkDescriptorPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorPoolResetFlags flags = (VkDescriptorPoolResetFlags)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void  = (void)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkResetDescriptorPool(device, descriptorPool, flags, );
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawAllocateDescriptorSets(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetAllocateInfo* pAllocateInfo = (VkDescriptorSetAllocateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSet* pDescriptorSets = (VkDescriptorSet*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawFreeDescriptorSets(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorPool descriptorPool = (VkDescriptorPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t descriptorSetCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSet* pDescriptorSets = (VkDescriptorSet*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawUpdateDescriptorSets(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t descriptorWriteCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkWriteDescriptorSet* pDescriptorWrites = (VkWriteDescriptorSet*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t descriptorCopyCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyDescriptorSet* pDescriptorCopies = (VkCopyDescriptorSet*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateFramebuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFramebufferCreateInfo* pCreateInfo = (VkFramebufferCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFramebuffer* pFramebuffer = (VkFramebuffer*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyFramebuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFramebuffer framebuffer = (VkFramebuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyFramebuffer(device, framebuffer, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateRenderPass(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPassCreateInfo* pCreateInfo = (VkRenderPassCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPass* pRenderPass = (VkRenderPass*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyRenderPass(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPass renderPass = (VkRenderPass)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyRenderPass(device, renderPass, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetRenderAreaGranularity(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPass renderPass = (VkRenderPass)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExtent2D* pGranularity = (VkExtent2D*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetRenderAreaGranularity(device, renderPass, pGranularity);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateCommandPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPoolCreateInfo* pCreateInfo = (VkCommandPoolCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPool* pCommandPool = (VkCommandPool*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyCommandPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPool commandPool = (VkCommandPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyCommandPool(device, commandPool, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawResetCommandPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPool commandPool = (VkCommandPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPoolResetFlags flags = (VkCommandPoolResetFlags)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkResetCommandPool(device, commandPool, flags);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawAllocateCommandBuffers(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBufferAllocateInfo* pAllocateInfo = (VkCommandBufferAllocateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer* pCommandBuffers = (VkCommandBuffer*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawFreeCommandBuffers(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPool commandPool = (VkCommandPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t commandBufferCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer* pCommandBuffers = (VkCommandBuffer*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawBeginCommandBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBufferBeginInfo* pBeginInfo = (VkCommandBufferBeginInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void  = (void)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkBeginCommandBuffer(commandBuffer, pBeginInfo, );
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawEndCommandBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void  = (void)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkEndCommandBuffer(commandBuffer, );
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawResetCommandBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBufferResetFlags flags = (VkCommandBufferResetFlags)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void  = (void)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkResetCommandBuffer(commandBuffer, flags, );
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBindPipeline(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineBindPoint pipelineBindPoint = (VkPipelineBindPoint)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetViewport(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstViewport = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t viewportCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkViewport* pViewports = (VkViewport*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetScissor(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstScissor = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t scissorCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRect2D* pScissors = (VkRect2D*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetLineWidth(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float lineWidth = (float)info[1].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetLineWidth(commandBuffer, lineWidth);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetDepthBias(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float depthBiasConstantFactor = (float)info[1].As<Napi::Number>().FloatValue();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float depthBiasClamp = (float)info[2].As<Napi::Number>().FloatValue();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float depthBiasSlopeFactor = (float)info[3].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetBlendConstants(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float blendConstants = (float)info[1].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetBlendConstants(commandBuffer, blendConstants);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetDepthBounds(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float minDepthBounds = (float)info[1].As<Napi::Number>().FloatValue();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float maxDepthBounds = (float)info[2].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetStencilCompareMask(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilFaceFlags faceMask = (VkStencilFaceFlags)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t compareMask = (uint32_t)info[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetStencilWriteMask(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilFaceFlags faceMask = (VkStencilFaceFlags)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t writeMask = (uint32_t)info[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetStencilReference(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilFaceFlags faceMask = (VkStencilFaceFlags)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t reference = (uint32_t)info[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetStencilReference(commandBuffer, faceMask, reference);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBindDescriptorSets(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineBindPoint pipelineBindPoint = (VkPipelineBindPoint)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayout layout = (VkPipelineLayout)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstSet = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t descriptorSetCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSet* pDescriptorSets = (VkDescriptorSet*)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t dynamicOffsetCount = (uint32_t)info[6].As<Napi::Number>().Uint32Value();

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pDynamicOffsets = (uint32_t*)info[7].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBindIndexBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkIndexType indexType = (VkIndexType)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBindVertexBuffers(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstBinding = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindingCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer* pBuffers = (VkBuffer*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pOffsets = (VkDeviceSize*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDraw(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

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


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawIndexed(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

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


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawMultiEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t drawCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMultiDrawInfoEXT* pVertexInfo = (VkMultiDrawInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t instanceCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstInstance = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawMultiIndexedEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t drawCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMultiDrawIndexedInfoEXT* pIndexInfo = (VkMultiDrawIndexedInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t instanceCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstInstance = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int32_t* pVertexOffset = (int32_t*)info[6].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawIndirect(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t drawCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawIndexedIndirect(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t drawCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDispatch(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountX = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountY = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountZ = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDispatchIndirect(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdDispatchIndirect(commandBuffer, buffer, offset);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSubpassShadingHUAWEI(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSubpassShadingHUAWEI(commandBuffer);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer srcBuffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t regionCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCopy* pRegions = (VkBufferCopy*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage srcImage = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout srcImageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage dstImage = (VkImage)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout dstImageLayout = (VkImageLayout)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t regionCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageCopy* pRegions = (VkImageCopy*)info[6].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBlitImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage srcImage = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout srcImageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage dstImage = (VkImage)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout dstImageLayout = (VkImageLayout)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t regionCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageBlit* pRegions = (VkImageBlit*)info[6].As<Napi::BigInt>().Uint64Value();

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFilter filter = (VkFilter)info[7].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyBufferToImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer srcBuffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage dstImage = (VkImage)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout dstImageLayout = (VkImageLayout)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t regionCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferImageCopy* pRegions = (VkBufferImageCopy*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyImageToBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage srcImage = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout srcImageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t regionCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferImageCopy* pRegions = (VkBufferImageCopy*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyMemoryIndirectNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress copyBufferAddress = (VkDeviceAddress)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t copyCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyMemoryToImageIndirectNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress copyBufferAddress = (VkDeviceAddress)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t copyCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage dstImage = (VkImage)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout dstImageLayout = (VkImageLayout)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageSubresourceLayers* pImageSubresources = (VkImageSubresourceLayers*)info[6].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdUpdateBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize dstOffset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize dataSize = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdFillBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize dstOffset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize size = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t data = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdClearColorImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout imageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkClearColorValue* pColor = (VkClearColorValue*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t rangeCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageSubresourceRange* pRanges = (VkImageSubresourceRange*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdClearDepthStencilImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout imageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkClearDepthStencilValue* pDepthStencil = (VkClearDepthStencilValue*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t rangeCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageSubresourceRange* pRanges = (VkImageSubresourceRange*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdClearAttachments(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t attachmentCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkClearAttachment* pAttachments = (VkClearAttachment*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t rectCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkClearRect* pRects = (VkClearRect*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdResolveImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage srcImage = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout srcImageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage dstImage = (VkImage)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout dstImageLayout = (VkImageLayout)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t regionCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageResolve* pRegions = (VkImageResolve*)info[6].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetEvent(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags stageMask = (VkPipelineStageFlags)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetEvent(commandBuffer, event, stageMask);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdResetEvent(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags stageMask = (VkPipelineStageFlags)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdResetEvent(commandBuffer, event, stageMask);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdWaitEvents(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 11) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t eventCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent* pEvents = (VkEvent*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags srcStageMask = (VkPipelineStageFlags)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags dstStageMask = (VkPipelineStageFlags)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t memoryBarrierCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryBarrier* pMemoryBarriers = (VkMemoryBarrier*)info[6].As<Napi::BigInt>().Uint64Value();

    if (!info[7].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bufferMemoryBarrierCount = (uint32_t)info[7].As<Napi::Number>().Uint32Value();

    if (!info[8].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferMemoryBarrier* pBufferMemoryBarriers = (VkBufferMemoryBarrier*)info[8].As<Napi::BigInt>().Uint64Value();

    if (!info[9].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t imageMemoryBarrierCount = (uint32_t)info[9].As<Napi::Number>().Uint32Value();

    if (!info[10].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageMemoryBarrier* pImageMemoryBarriers = (VkImageMemoryBarrier*)info[10].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdPipelineBarrier(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 10) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags srcStageMask = (VkPipelineStageFlags)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags dstStageMask = (VkPipelineStageFlags)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDependencyFlags dependencyFlags = (VkDependencyFlags)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t memoryBarrierCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryBarrier* pMemoryBarriers = (VkMemoryBarrier*)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bufferMemoryBarrierCount = (uint32_t)info[6].As<Napi::Number>().Uint32Value();

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferMemoryBarrier* pBufferMemoryBarriers = (VkBufferMemoryBarrier*)info[7].As<Napi::BigInt>().Uint64Value();

    if (!info[8].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t imageMemoryBarrierCount = (uint32_t)info[8].As<Napi::Number>().Uint32Value();

    if (!info[9].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageMemoryBarrier* pImageMemoryBarriers = (VkImageMemoryBarrier*)info[9].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBeginQuery(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t query = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryControlFlags flags = (VkQueryControlFlags)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdEndQuery(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t query = (uint32_t)info[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdEndQuery(commandBuffer, queryPool, query);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBeginConditionalRenderingEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin = (VkConditionalRenderingBeginInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdEndConditionalRenderingEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdEndConditionalRenderingEXT(commandBuffer);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdResetQueryPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queryCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdWriteTimestamp(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlagBits pipelineStage = (VkPipelineStageFlagBits)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t query = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyQueryPoolResults(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queryCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize dstOffset = (VkDeviceSize)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize stride = (VkDeviceSize)info[6].As<Napi::BigInt>().Uint64Value();

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryResultFlags flags = (VkQueryResultFlags)info[7].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdPushConstants(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayout layout = (VkPipelineLayout)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderStageFlags stageFlags = (VkShaderStageFlags)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t offset = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t size = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pValues = (void*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBeginRenderPass(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPassBeginInfo* pRenderPassBegin = (VkRenderPassBeginInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubpassContents contents = (VkSubpassContents)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdNextSubpass(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubpassContents contents = (VkSubpassContents)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdNextSubpass(commandBuffer, contents);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdEndRenderPass(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdEndRenderPass(commandBuffer);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdExecuteCommands(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t commandBufferCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer* pCommandBuffers = (VkCommandBuffer*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateAndroidSurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAndroidSurfaceCreateInfoKHR* pCreateInfo = (VkAndroidSurfaceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceDisplayPropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPropertiesKHR* pProperties = (VkDisplayPropertiesKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceDisplayPlanePropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPlanePropertiesKHR* pProperties = (VkDisplayPlanePropertiesKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDisplayPlaneSupportedDisplaysKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t planeIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pDisplayCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR* pDisplays = (VkDisplayKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDisplayModePropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayModePropertiesKHR* pProperties = (VkDisplayModePropertiesKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateDisplayModeKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayModeCreateInfoKHR* pCreateInfo = (VkDisplayModeCreateInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayModeKHR* pMode = (VkDisplayModeKHR*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDisplayPlaneCapabilitiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayModeKHR mode = (VkDisplayModeKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t planeIndex = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPlaneCapabilitiesKHR* pCapabilities = (VkDisplayPlaneCapabilitiesKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateDisplayPlaneSurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplaySurfaceCreateInfoKHR* pCreateInfo = (VkDisplaySurfaceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateSharedSwapchainsKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t swapchainCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainCreateInfoKHR* pCreateInfos = (VkSwapchainCreateInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR* pSwapchains = (VkSwapchainKHR*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroySurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroySurfaceKHR(instance, surface, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceSurfaceSupportKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32* pSupported = (VkBool32*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceSurfaceCapabilitiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceCapabilitiesKHR* pSurfaceCapabilities = (VkSurfaceCapabilitiesKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceSurfaceFormatsKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pSurfaceFormatCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceFormatKHR* pSurfaceFormats = (VkSurfaceFormatKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceSurfacePresentModesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPresentModeCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPresentModeKHR* pPresentModes = (VkPresentModeKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateSwapchainKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainCreateInfoKHR* pCreateInfo = (VkSwapchainCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR* pSwapchain = (VkSwapchainKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroySwapchainKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroySwapchainKHR(device, swapchain, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetSwapchainImagesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pSwapchainImageCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage* pSwapchainImages = (VkImage*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawAcquireNextImageKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t timeout = (uint64_t)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphore semaphore = (VkSemaphore)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pImageIndex = (uint32_t*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawQueuePresentKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPresentInfoKHR* pPresentInfo = (VkPresentInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkQueuePresentKHR(queue, pPresentInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateViSurfaceNN(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkViSurfaceCreateInfoNN* pCreateInfo = (VkViSurfaceCreateInfoNN*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateWaylandSurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkWaylandSurfaceCreateInfoKHR* pCreateInfo = (VkWaylandSurfaceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceWaylandPresentationSupportKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    wl_display* display = (wl_display*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateWin32SurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkWin32SurfaceCreateInfoKHR* pCreateInfo = (VkWin32SurfaceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceWin32PresentationSupportKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateXlibSurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkXlibSurfaceCreateInfoKHR* pCreateInfo = (VkXlibSurfaceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceXlibPresentationSupportKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    Display* dpy = (Display*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VisualID visualID = (VisualID)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateXcbSurfaceKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkXcbSurfaceCreateInfoKHR* pCreateInfo = (VkXcbSurfaceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceXcbPresentationSupportKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    xcb_connection_t* connection = (xcb_connection_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    xcb_visualid_t visual_id = (xcb_visualid_t)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateDirectFBSurfaceEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDirectFBSurfaceCreateInfoEXT* pCreateInfo = (VkDirectFBSurfaceCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateDirectFBSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceDirectFBPresentationSupportEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    IDirectFB* dfb = (IDirectFB*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceDirectFBPresentationSupportEXT(physicalDevice, queueFamilyIndex, dfb);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateImagePipeSurfaceFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo = (VkImagePipeSurfaceCreateInfoFUCHSIA*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateImagePipeSurfaceFUCHSIA(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateStreamDescriptorSurfaceGGP(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo = (VkStreamDescriptorSurfaceCreateInfoGGP*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateStreamDescriptorSurfaceGGP(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateScreenSurfaceQNX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkScreenSurfaceCreateInfoQNX* pCreateInfo = (VkScreenSurfaceCreateInfoQNX*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateScreenSurfaceQNX(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceScreenPresentationSupportQNX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    _screen_window* window = (_screen_window*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceScreenPresentationSupportQNX(physicalDevice, queueFamilyIndex, window);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateDebugReportCallbackEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugReportCallbackCreateInfoEXT* pCreateInfo = (VkDebugReportCallbackCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugReportCallbackEXT* pCallback = (VkDebugReportCallbackEXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyDebugReportCallbackEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugReportCallbackEXT callback = (VkDebugReportCallbackEXT)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyDebugReportCallbackEXT(instance, callback, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDebugReportMessageEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugReportFlagsEXT flags = (VkDebugReportFlagsEXT)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugReportObjectTypeEXT objectType = (VkDebugReportObjectTypeEXT)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t object = (uint64_t)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t location = (size_t)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    int32_t messageCode = (int32_t)info[5].As<Napi::Number>().Int32Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    char* pLayerPrefix = (char*)info[6].As<Napi::BigInt>().Uint64Value();

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    char* pMessage = (char*)info[7].As<Napi::BigInt>().Uint64Value();
    
    ::vkDebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDebugMarkerSetObjectNameEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugMarkerObjectNameInfoEXT* pNameInfo = (VkDebugMarkerObjectNameInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkDebugMarkerSetObjectNameEXT(device, pNameInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDebugMarkerSetObjectTagEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugMarkerObjectTagInfoEXT* pTagInfo = (VkDebugMarkerObjectTagInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkDebugMarkerSetObjectTagEXT(device, pTagInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDebugMarkerBeginEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugMarkerMarkerInfoEXT* pMarkerInfo = (VkDebugMarkerMarkerInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDebugMarkerEndEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdDebugMarkerEndEXT(commandBuffer);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDebugMarkerInsertEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugMarkerMarkerInfoEXT* pMarkerInfo = (VkDebugMarkerMarkerInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceExternalImageFormatPropertiesNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageType type = (VkImageType)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageTiling tiling = (VkImageTiling)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageUsageFlags usage = (VkImageUsageFlags)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageCreateFlags flags = (VkImageCreateFlags)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalMemoryHandleTypeFlagsNV externalHandleType = (VkExternalMemoryHandleTypeFlagsNV)info[6].As<Napi::BigInt>().Uint64Value();

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties = (VkExternalImageFormatPropertiesNV*)info[7].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetMemoryWin32HandleNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalMemoryHandleTypeFlagsNV handleType = (VkExternalMemoryHandleTypeFlagsNV)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    HANDLE* pHandle = (HANDLE*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetMemoryWin32HandleNV(device, memory, handleType, pHandle);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdExecuteGeneratedCommandsNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 isPreprocessed = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo = (VkGeneratedCommandsInfoNV*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdPreprocessGeneratedCommandsNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo = (VkGeneratedCommandsInfoNV*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBindPipelineShaderGroupNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineBindPoint pipelineBindPoint = (VkPipelineBindPoint)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupIndex = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetGeneratedCommandsMemoryRequirementsNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo = (VkGeneratedCommandsMemoryRequirementsInfoNV*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements2* pMemoryRequirements = (VkMemoryRequirements2*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetGeneratedCommandsMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateIndirectCommandsLayoutNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo = (VkIndirectCommandsLayoutCreateInfoNV*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkIndirectCommandsLayoutNV* pIndirectCommandsLayout = (VkIndirectCommandsLayoutNV*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateIndirectCommandsLayoutNV(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyIndirectCommandsLayoutNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkIndirectCommandsLayoutNV indirectCommandsLayout = (VkIndirectCommandsLayoutNV)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyIndirectCommandsLayoutNV(device, indirectCommandsLayout, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceFeatures2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceFeatures2* pFeatures = (VkPhysicalDeviceFeatures2*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceProperties2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceProperties2* pProperties = (VkPhysicalDeviceProperties2*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceProperties2(physicalDevice, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceFormatProperties2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormatProperties2* pFormatProperties = (VkFormatProperties2*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceImageFormatProperties2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo = (VkPhysicalDeviceImageFormatInfo2*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageFormatProperties2* pImageFormatProperties = (VkImageFormatProperties2*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceQueueFamilyProperties2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pQueueFamilyPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueueFamilyProperties2* pQueueFamilyProperties = (VkQueueFamilyProperties2*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceMemoryProperties2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceMemoryProperties2* pMemoryProperties = (VkPhysicalDeviceMemoryProperties2*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceSparseImageFormatProperties2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo = (VkPhysicalDeviceSparseImageFormatInfo2*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSparseImageFormatProperties2* pProperties = (VkSparseImageFormatProperties2*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdPushDescriptorSetKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineBindPoint pipelineBindPoint = (VkPipelineBindPoint)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayout layout = (VkPipelineLayout)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t set = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t descriptorWriteCount = (uint32_t)info[4].As<Napi::Number>().Uint32Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkWriteDescriptorSet* pDescriptorWrites = (VkWriteDescriptorSet*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawTrimCommandPool(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPool commandPool = (VkCommandPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandPoolTrimFlags flags = (VkCommandPoolTrimFlags)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkTrimCommandPool(device, commandPool, flags);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceExternalBufferProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo = (VkPhysicalDeviceExternalBufferInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalBufferProperties* pExternalBufferProperties = (VkExternalBufferProperties*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetMemoryWin32HandleKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo = (VkMemoryGetWin32HandleInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    HANDLE* pHandle = (HANDLE*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetMemoryWin32HandlePropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalMemoryHandleTypeFlagBits handleType = (VkExternalMemoryHandleTypeFlagBits)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    HANDLE handle = (HANDLE)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties = (VkMemoryWin32HandlePropertiesKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetMemoryFdKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryGetFdInfoKHR* pGetFdInfo = (VkMemoryGetFdInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int* pFd = (int*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetMemoryFdKHR(device, pGetFdInfo, pFd);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetMemoryFdPropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalMemoryHandleTypeFlagBits handleType = (VkExternalMemoryHandleTypeFlagBits)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int fd = (int)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryFdPropertiesKHR* pMemoryFdProperties = (VkMemoryFdPropertiesKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetMemoryZirconHandleFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo = (VkMemoryGetZirconHandleInfoFUCHSIA*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    zx_handle_t* pZirconHandle = (zx_handle_t*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetMemoryZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetMemoryZirconHandlePropertiesFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalMemoryHandleTypeFlagBits handleType = (VkExternalMemoryHandleTypeFlagBits)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    zx_handle_t zirconHandle = (zx_handle_t)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties = (VkMemoryZirconHandlePropertiesFUCHSIA*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetMemoryZirconHandlePropertiesFUCHSIA(device, handleType, zirconHandle, pMemoryZirconHandleProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetMemoryRemoteAddressNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo = (VkMemoryGetRemoteAddressInfoNV*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRemoteAddressNV* pAddress = (VkRemoteAddressNV*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetMemoryRemoteAddressNV(device, pMemoryGetRemoteAddressInfo, pAddress);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceExternalSemaphoreProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo = (VkPhysicalDeviceExternalSemaphoreInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalSemaphoreProperties* pExternalSemaphoreProperties = (VkExternalSemaphoreProperties*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetSemaphoreWin32HandleKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo = (VkSemaphoreGetWin32HandleInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    HANDLE* pHandle = (HANDLE*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawImportSemaphoreWin32HandleKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo = (VkImportSemaphoreWin32HandleInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetSemaphoreFdKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphoreGetFdInfoKHR* pGetFdInfo = (VkSemaphoreGetFdInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int* pFd = (int*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetSemaphoreFdKHR(device, pGetFdInfo, pFd);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawImportSemaphoreFdKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo = (VkImportSemaphoreFdInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetSemaphoreZirconHandleFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo = (VkSemaphoreGetZirconHandleInfoFUCHSIA*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    zx_handle_t* pZirconHandle = (zx_handle_t*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetSemaphoreZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawImportSemaphoreZirconHandleFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo = (VkImportSemaphoreZirconHandleInfoFUCHSIA*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkImportSemaphoreZirconHandleFUCHSIA(device, pImportSemaphoreZirconHandleInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceExternalFenceProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo = (VkPhysicalDeviceExternalFenceInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalFenceProperties* pExternalFenceProperties = (VkExternalFenceProperties*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetFenceWin32HandleKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo = (VkFenceGetWin32HandleInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    HANDLE* pHandle = (HANDLE*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawImportFenceWin32HandleKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo = (VkImportFenceWin32HandleInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetFenceFdKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFenceGetFdInfoKHR* pGetFdInfo = (VkFenceGetFdInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int* pFd = (int*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetFenceFdKHR(device, pGetFdInfo, pFd);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawImportFenceFdKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImportFenceFdInfoKHR* pImportFenceFdInfo = (VkImportFenceFdInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkImportFenceFdKHR(device, pImportFenceFdInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawReleaseDisplayEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkReleaseDisplayEXT(physicalDevice, display);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawAcquireXlibDisplayEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    Display* dpy = (Display*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkAcquireXlibDisplayEXT(physicalDevice, dpy, display);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetRandROutputDisplayEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    Display* dpy = (Display*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    RROutput rrOutput = (RROutput)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR* pDisplay = (VkDisplayKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawAcquireWinrtDisplayNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkAcquireWinrtDisplayNV(physicalDevice, display);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetWinrtDisplayNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t deviceRelativeId = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR* pDisplay = (VkDisplayKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetWinrtDisplayNV(physicalDevice, deviceRelativeId, pDisplay);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDisplayPowerControlEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPowerInfoEXT* pDisplayPowerInfo = (VkDisplayPowerInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDisplayPowerControlEXT(device, display, pDisplayPowerInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawRegisterDeviceEventEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceEventInfoEXT* pDeviceEventInfo = (VkDeviceEventInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence* pFence = (VkFence*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawRegisterDisplayEventEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayEventInfoEXT* pDisplayEventInfo = (VkDisplayEventInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence* pFence = (VkFence*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetSwapchainCounterEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceCounterFlagBitsEXT counter = (VkSurfaceCounterFlagBitsEXT)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* pCounterValue = (uint64_t*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceSurfaceCapabilities2EXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceCapabilities2EXT* pSurfaceCapabilities = (VkSurfaceCapabilities2EXT*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawEnumeratePhysicalDeviceGroups(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPhysicalDeviceGroupCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties = (VkPhysicalDeviceGroupProperties*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceGroupPeerMemoryFeatures(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t heapIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t localDeviceIndex = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t remoteDeviceIndex = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPeerMemoryFeatureFlags* pPeerMemoryFeatures = (VkPeerMemoryFeatureFlags*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawBindBufferMemory2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindInfoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBindBufferMemoryInfo* pBindInfos = (VkBindBufferMemoryInfo*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkBindBufferMemory2(device, bindInfoCount, pBindInfos);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawBindImageMemory2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindInfoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBindImageMemoryInfo* pBindInfos = (VkBindImageMemoryInfo*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkBindImageMemory2(device, bindInfoCount, pBindInfos);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetDeviceMask(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t deviceMask = (uint32_t)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetDeviceMask(commandBuffer, deviceMask);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceGroupPresentCapabilitiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities = (VkDeviceGroupPresentCapabilitiesKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceGroupSurfacePresentModesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceGroupPresentModeFlagsKHR* pModes = (VkDeviceGroupPresentModeFlagsKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawAcquireNextImage2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAcquireNextImageInfoKHR* pAcquireInfo = (VkAcquireNextImageInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pImageIndex = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDispatchBase(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

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


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDevicePresentRectanglesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR surface = (VkSurfaceKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pRectCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRect2D* pRects = (VkRect2D*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateDescriptorUpdateTemplate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorUpdateTemplateCreateInfo* pCreateInfo = (VkDescriptorUpdateTemplateCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate = (VkDescriptorUpdateTemplate*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyDescriptorUpdateTemplate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorUpdateTemplate descriptorUpdateTemplate = (VkDescriptorUpdateTemplate)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawUpdateDescriptorSetWithTemplate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSet descriptorSet = (VkDescriptorSet)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorUpdateTemplate descriptorUpdateTemplate = (VkDescriptorUpdateTemplate)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdPushDescriptorSetWithTemplateKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorUpdateTemplate descriptorUpdateTemplate = (VkDescriptorUpdateTemplate)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineLayout layout = (VkPipelineLayout)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t set = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawSetHdrMetadataEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t swapchainCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR* pSwapchains = (VkSwapchainKHR*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkHdrMetadataEXT* pMetadata = (VkHdrMetadataEXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetSwapchainStatusKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetSwapchainStatusKHR(device, swapchain);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetRefreshCycleDurationGOOGLE(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties = (VkRefreshCycleDurationGOOGLE*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPastPresentationTimingGOOGLE(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPresentationTimingCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPastPresentationTimingGOOGLE* pPresentationTimings = (VkPastPresentationTimingGOOGLE*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateIOSSurfaceMVK(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkIOSSurfaceCreateInfoMVK* pCreateInfo = (VkIOSSurfaceCreateInfoMVK*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateMacOSSurfaceMVK(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMacOSSurfaceCreateInfoMVK* pCreateInfo = (VkMacOSSurfaceCreateInfoMVK*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateMetalSurfaceEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMetalSurfaceCreateInfoEXT* pCreateInfo = (VkMetalSurfaceCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateMetalSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetViewportWScalingNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstViewport = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t viewportCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkViewportWScalingNV* pViewportWScalings = (VkViewportWScalingNV*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetDiscardRectangleEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstDiscardRectangle = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t discardRectangleCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRect2D* pDiscardRectangles = (VkRect2D*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetSampleLocationsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampleLocationsInfoEXT* pSampleLocationsInfo = (VkSampleLocationsInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceMultisamplePropertiesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampleCountFlagBits samples = (VkSampleCountFlagBits)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMultisamplePropertiesEXT* pMultisampleProperties = (VkMultisamplePropertiesEXT*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceSurfaceCapabilities2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo = (VkPhysicalDeviceSurfaceInfo2KHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceCapabilities2KHR* pSurfaceCapabilities = (VkSurfaceCapabilities2KHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceSurfaceFormats2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo = (VkPhysicalDeviceSurfaceInfo2KHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pSurfaceFormatCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceFormat2KHR* pSurfaceFormats = (VkSurfaceFormat2KHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceDisplayProperties2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayProperties2KHR* pProperties = (VkDisplayProperties2KHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceDisplayPlaneProperties2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPlaneProperties2KHR* pProperties = (VkDisplayPlaneProperties2KHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDisplayModeProperties2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayModeProperties2KHR* pProperties = (VkDisplayModeProperties2KHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDisplayPlaneCapabilities2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo = (VkDisplayPlaneInfo2KHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayPlaneCapabilities2KHR* pCapabilities = (VkDisplayPlaneCapabilities2KHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetBufferMemoryRequirements2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferMemoryRequirementsInfo2* pInfo = (VkBufferMemoryRequirementsInfo2*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements2* pMemoryRequirements = (VkMemoryRequirements2*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetImageMemoryRequirements2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageMemoryRequirementsInfo2* pInfo = (VkImageMemoryRequirementsInfo2*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements2* pMemoryRequirements = (VkMemoryRequirements2*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetImageSparseMemoryRequirements2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageSparseMemoryRequirementsInfo2* pInfo = (VkImageSparseMemoryRequirementsInfo2*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pSparseMemoryRequirementCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSparseImageMemoryRequirements2* pSparseMemoryRequirements = (VkSparseImageMemoryRequirements2*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceBufferMemoryRequirements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceBufferMemoryRequirements* pInfo = (VkDeviceBufferMemoryRequirements*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements2* pMemoryRequirements = (VkMemoryRequirements2*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceImageMemoryRequirements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceImageMemoryRequirements* pInfo = (VkDeviceImageMemoryRequirements*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements2* pMemoryRequirements = (VkMemoryRequirements2*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceImageSparseMemoryRequirements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceImageMemoryRequirements* pInfo = (VkDeviceImageMemoryRequirements*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pSparseMemoryRequirementCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSparseImageMemoryRequirements2* pSparseMemoryRequirements = (VkSparseImageMemoryRequirements2*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateSamplerYcbcrConversion(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSamplerYcbcrConversionCreateInfo* pCreateInfo = (VkSamplerYcbcrConversionCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSamplerYcbcrConversion* pYcbcrConversion = (VkSamplerYcbcrConversion*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroySamplerYcbcrConversion(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSamplerYcbcrConversion ycbcrConversion = (VkSamplerYcbcrConversion)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceQueue2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceQueueInfo2* pQueueInfo = (VkDeviceQueueInfo2*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue* pQueue = (VkQueue*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceQueue2(device, pQueueInfo, pQueue);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateValidationCacheEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkValidationCacheCreateInfoEXT* pCreateInfo = (VkValidationCacheCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkValidationCacheEXT* pValidationCache = (VkValidationCacheEXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyValidationCacheEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkValidationCacheEXT validationCache = (VkValidationCacheEXT)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyValidationCacheEXT(device, validationCache, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetValidationCacheDataEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkValidationCacheEXT validationCache = (VkValidationCacheEXT)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t* pDataSize = (size_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawMergeValidationCachesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkValidationCacheEXT dstCache = (VkValidationCacheEXT)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t srcCacheCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkValidationCacheEXT* pSrcCaches = (VkValidationCacheEXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkMergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDescriptorSetLayoutSupport(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetLayoutCreateInfo* pCreateInfo = (VkDescriptorSetLayoutCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetLayoutSupport* pSupport = (VkDescriptorSetLayoutSupport*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetSwapchainGrallocUsageANDROID(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageUsageFlags imageUsage = (VkImageUsageFlags)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int* grallocUsage = (int*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetSwapchainGrallocUsageANDROID(device, format, imageUsage, grallocUsage);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetSwapchainGrallocUsage2ANDROID(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFormat format = (VkFormat)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageUsageFlags imageUsage = (VkImageUsageFlags)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainImageUsageFlagsANDROID swapchainImageUsage = (VkSwapchainImageUsageFlagsANDROID)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* grallocConsumerUsage = (uint64_t*)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* grallocProducerUsage = (uint64_t*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetSwapchainGrallocUsage2ANDROID(device, format, imageUsage, swapchainImageUsage, grallocConsumerUsage, grallocProducerUsage);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawAcquireImageANDROID(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int nativeFenceFd = (int)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphore semaphore = (VkSemaphore)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkAcquireImageANDROID(device, image, nativeFenceFd, semaphore, fence);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawQueueSignalReleaseImageANDROID(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t waitSemaphoreCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphore* pWaitSemaphores = (VkSemaphore*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    int* pNativeFenceFd = (int*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkQueueSignalReleaseImageANDROID(queue, waitSemaphoreCount, pWaitSemaphores, image, pNativeFenceFd);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetShaderInfoAMD(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderStageFlagBits shaderStage = (VkShaderStageFlagBits)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderInfoTypeAMD infoType = (VkShaderInfoTypeAMD)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t* pInfoSize = (size_t*)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pInfo = (void*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawSetLocalDimmingAMD(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapChain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 localDimmingEnable = (VkBool32)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkSetLocalDimmingAMD(device, swapChain, localDimmingEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceCalibrateableTimeDomainsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pTimeDomainCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkTimeDomainEXT* pTimeDomains = (VkTimeDomainEXT*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetCalibratedTimestampsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t timestampCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCalibratedTimestampInfoEXT* pTimestampInfos = (VkCalibratedTimestampInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* pTimestamps = (uint64_t*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* pMaxDeviation = (uint64_t*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawSetDebugUtilsObjectNameEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsObjectNameInfoEXT* pNameInfo = (VkDebugUtilsObjectNameInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkSetDebugUtilsObjectNameEXT(device, pNameInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawSetDebugUtilsObjectTagEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsObjectTagInfoEXT* pTagInfo = (VkDebugUtilsObjectTagInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkSetDebugUtilsObjectTagEXT(device, pTagInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawQueueBeginDebugUtilsLabelEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsLabelEXT* pLabelInfo = (VkDebugUtilsLabelEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawQueueEndDebugUtilsLabelEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value();
    
    ::vkQueueEndDebugUtilsLabelEXT(queue);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawQueueInsertDebugUtilsLabelEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsLabelEXT* pLabelInfo = (VkDebugUtilsLabelEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBeginDebugUtilsLabelEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsLabelEXT* pLabelInfo = (VkDebugUtilsLabelEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdEndDebugUtilsLabelEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdEndDebugUtilsLabelEXT(commandBuffer);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdInsertDebugUtilsLabelEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsLabelEXT* pLabelInfo = (VkDebugUtilsLabelEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateDebugUtilsMessengerEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo = (VkDebugUtilsMessengerCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsMessengerEXT* pMessenger = (VkDebugUtilsMessengerEXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyDebugUtilsMessengerEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsMessengerEXT messenger = (VkDebugUtilsMessengerEXT)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawSubmitDebugUtilsMessageEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity = (VkDebugUtilsMessageSeverityFlagBitsEXT)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsMessageTypeFlagsEXT messageTypes = (VkDebugUtilsMessageTypeFlagsEXT)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDebugUtilsMessengerCallbackDataEXT* pCallbackData = (VkDebugUtilsMessengerCallbackDataEXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetMemoryHostPointerPropertiesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExternalMemoryHandleTypeFlagBits handleType = (VkExternalMemoryHandleTypeFlagBits)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pHostPointer = (void*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties = (VkMemoryHostPointerPropertiesEXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdWriteBufferMarkerAMD(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlagBits pipelineStage = (VkPipelineStageFlagBits)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize dstOffset = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t marker = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateRenderPass2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPassCreateInfo2* pCreateInfo = (VkRenderPassCreateInfo2*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPass* pRenderPass = (VkRenderPass*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBeginRenderPass2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderPassBeginInfo* pRenderPassBegin = (VkRenderPassBeginInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubpassBeginInfo* pSubpassBeginInfo = (VkSubpassBeginInfo*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdNextSubpass2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubpassBeginInfo* pSubpassBeginInfo = (VkSubpassBeginInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubpassEndInfo* pSubpassEndInfo = (VkSubpassEndInfo*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdEndRenderPass2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubpassEndInfo* pSubpassEndInfo = (VkSubpassEndInfo*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetSemaphoreCounterValue(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphore semaphore = (VkSemaphore)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* pValue = (uint64_t*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetSemaphoreCounterValue(device, semaphore, pValue);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawWaitSemaphores(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphoreWaitInfo* pWaitInfo = (VkSemaphoreWaitInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t timeout = (uint64_t)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkWaitSemaphores(device, pWaitInfo, timeout);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawSignalSemaphore(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSemaphoreSignalInfo* pSignalInfo = (VkSemaphoreSignalInfo*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkSignalSemaphore(device, pSignalInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetAndroidHardwareBufferPropertiesANDROID(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    AHardwareBuffer* buffer = (AHardwareBuffer*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAndroidHardwareBufferPropertiesANDROID* pProperties = (VkAndroidHardwareBufferPropertiesANDROID*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetMemoryAndroidHardwareBufferANDROID(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo = (VkMemoryGetAndroidHardwareBufferInfoANDROID*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    AHardwareBuffer pBuffer = (AHardwareBuffer)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawIndirectCount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer countBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize countBufferOffset = (VkDeviceSize)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t maxDrawCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawIndexedIndirectCount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer countBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize countBufferOffset = (VkDeviceSize)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t maxDrawCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetCheckpointNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pCheckpointMarker = (void*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetQueueCheckpointDataNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pCheckpointDataCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCheckpointDataNV* pCheckpointData = (VkCheckpointDataNV*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBindTransformFeedbackBuffersEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstBinding = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindingCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer* pBuffers = (VkBuffer*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pOffsets = (VkDeviceSize*)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pSizes = (VkDeviceSize*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBeginTransformFeedbackEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstCounterBuffer = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t counterBufferCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer* pCounterBuffers = (VkBuffer*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pCounterBufferOffsets = (VkDeviceSize*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdEndTransformFeedbackEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstCounterBuffer = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t counterBufferCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer* pCounterBuffers = (VkBuffer*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pCounterBufferOffsets = (VkDeviceSize*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBeginQueryIndexedEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t query = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryControlFlags flags = (VkQueryControlFlags)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t index = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdEndQueryIndexedEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t query = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t index = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawIndirectByteCountEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t instanceCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstInstance = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer counterBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize counterBufferOffset = (VkDeviceSize)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t counterOffset = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t vertexStride = (uint32_t)info[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetExclusiveScissorNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstExclusiveScissor = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t exclusiveScissorCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRect2D* pExclusiveScissors = (VkRect2D*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBindShadingRateImageNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageView imageView = (VkImageView)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout imageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetViewportShadingRatePaletteNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstViewport = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t viewportCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShadingRatePaletteNV* pShadingRatePalettes = (VkShadingRatePaletteNV*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetCoarseSampleOrderNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCoarseSampleOrderTypeNV sampleOrderType = (VkCoarseSampleOrderTypeNV)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t customSampleOrderCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCoarseSampleOrderCustomNV* pCustomSampleOrders = (VkCoarseSampleOrderCustomNV*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawMeshTasksNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t taskCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstTask = (uint32_t)info[2].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawMeshTasksIndirectNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t drawCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawMeshTasksIndirectCountNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer countBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize countBufferOffset = (VkDeviceSize)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t maxDrawCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawMeshTasksEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountX = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountY = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCountZ = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawMeshTasksIndirectEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t drawCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDrawMeshTasksIndirectCountEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer buffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize offset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer countBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize countBufferOffset = (VkDeviceSize)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t maxDrawCount = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[6].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCompileDeferredNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t shader = (uint32_t)info[2].As<Napi::Number>().Uint32Value();
    
    ::vkCompileDeferredNV(device, pipeline, shader);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateAccelerationStructureNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureCreateInfoNV* pCreateInfo = (VkAccelerationStructureCreateInfoNV*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV* pAccelerationStructure = (VkAccelerationStructureNV*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBindInvocationMaskHUAWEI(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageView imageView = (VkImageView)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout imageLayout = (VkImageLayout)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyAccelerationStructureKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureKHR accelerationStructure = (VkAccelerationStructureKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyAccelerationStructureKHR(device, accelerationStructure, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyAccelerationStructureNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV accelerationStructure = (VkAccelerationStructureNV)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetAccelerationStructureMemoryRequirementsNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureMemoryRequirementsInfoNV* pInfo = (VkAccelerationStructureMemoryRequirementsInfoNV*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMemoryRequirements2KHR* pMemoryRequirements = (VkMemoryRequirements2KHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawBindAccelerationStructureMemoryNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindInfoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBindAccelerationStructureMemoryInfoNV* pBindInfos = (VkBindAccelerationStructureMemoryInfoNV*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkBindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyAccelerationStructureNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV dst = (VkAccelerationStructureNV)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV src = (VkAccelerationStructureNV)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyAccelerationStructureModeKHR mode = (VkCopyAccelerationStructureModeKHR)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyAccelerationStructureKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyAccelerationStructureInfoKHR* pInfo = (VkCopyAccelerationStructureInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCopyAccelerationStructureKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyAccelerationStructureInfoKHR* pInfo = (VkCopyAccelerationStructureInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCopyAccelerationStructureKHR(device, deferredOperation, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyAccelerationStructureToMemoryKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyAccelerationStructureToMemoryInfoKHR* pInfo = (VkCopyAccelerationStructureToMemoryInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCopyAccelerationStructureToMemoryKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyAccelerationStructureToMemoryInfoKHR* pInfo = (VkCopyAccelerationStructureToMemoryInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCopyAccelerationStructureToMemoryKHR(device, deferredOperation, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyMemoryToAccelerationStructureKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMemoryToAccelerationStructureInfoKHR* pInfo = (VkCopyMemoryToAccelerationStructureInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCopyMemoryToAccelerationStructureKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMemoryToAccelerationStructureInfoKHR* pInfo = (VkCopyMemoryToAccelerationStructureInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCopyMemoryToAccelerationStructureKHR(device, deferredOperation, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdWriteAccelerationStructuresPropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t accelerationStructureCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureKHR* pAccelerationStructures = (VkAccelerationStructureKHR*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryType queryType = (VkQueryType)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdWriteAccelerationStructuresPropertiesNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t accelerationStructureCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV* pAccelerationStructures = (VkAccelerationStructureNV*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryType queryType = (VkQueryType)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBuildAccelerationStructureNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 9) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureInfoNV* pInfo = (VkAccelerationStructureInfoNV*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer instanceData = (VkBuffer)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize instanceOffset = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 update = (VkBool32)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV dst = (VkAccelerationStructureNV)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV src = (VkAccelerationStructureNV)info[6].As<Napi::BigInt>().Uint64Value();

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer scratch = (VkBuffer)info[7].As<Napi::BigInt>().Uint64Value();

    if (!info[8].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize scratchOffset = (VkDeviceSize)info[8].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawWriteAccelerationStructuresPropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t accelerationStructureCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureKHR* pAccelerationStructures = (VkAccelerationStructureKHR*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryType queryType = (VkQueryType)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t dataSize = (size_t)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t stride = (size_t)info[6].As<Napi::BigInt>().Uint64Value();
    
    ::vkWriteAccelerationStructuresPropertiesKHR(device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdTraceRaysKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 8) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t width = (uint32_t)info[5].As<Napi::Number>().Uint32Value();

    if (!info[6].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t height = (uint32_t)info[6].As<Napi::Number>().Uint32Value();

    if (!info[7].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t depth = (uint32_t)info[7].As<Napi::Number>().Uint32Value();
    
    ::vkCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdTraceRaysNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 15) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer raygenShaderBindingTableBuffer = (VkBuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize raygenShaderBindingOffset = (VkDeviceSize)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer missShaderBindingTableBuffer = (VkBuffer)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize missShaderBindingOffset = (VkDeviceSize)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize missShaderBindingStride = (VkDeviceSize)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer hitShaderBindingTableBuffer = (VkBuffer)info[6].As<Napi::BigInt>().Uint64Value();

    if (!info[7].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize hitShaderBindingOffset = (VkDeviceSize)info[7].As<Napi::BigInt>().Uint64Value();

    if (!info[8].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize hitShaderBindingStride = (VkDeviceSize)info[8].As<Napi::BigInt>().Uint64Value();

    if (!info[9].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer callableShaderBindingTableBuffer = (VkBuffer)info[9].As<Napi::BigInt>().Uint64Value();

    if (!info[10].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize callableShaderBindingOffset = (VkDeviceSize)info[10].As<Napi::BigInt>().Uint64Value();

    if (!info[11].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize callableShaderBindingStride = (VkDeviceSize)info[11].As<Napi::BigInt>().Uint64Value();

    if (!info[12].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t width = (uint32_t)info[12].As<Napi::Number>().Uint32Value();

    if (!info[13].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t height = (uint32_t)info[13].As<Napi::Number>().Uint32Value();

    if (!info[14].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t depth = (uint32_t)info[14].As<Napi::Number>().Uint32Value();
    
    ::vkCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetRayTracingShaderGroupHandlesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstGroup = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t dataSize = (size_t)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetRayTracingShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetRayTracingCaptureReplayShaderGroupHandlesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstGroup = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t groupCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t dataSize = (size_t)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetAccelerationStructureHandleNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureNV accelerationStructure = (VkAccelerationStructureNV)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t dataSize = (size_t)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateRayTracingPipelinesNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache pipelineCache = (VkPipelineCache)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t createInfoCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRayTracingPipelineCreateInfoNV* pCreateInfos = (VkRayTracingPipelineCreateInfoNV*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline* pPipelines = (VkPipeline*)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateRayTracingPipelinesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineCache pipelineCache = (VkPipelineCache)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t createInfoCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRayTracingPipelineCreateInfoKHR* pCreateInfos = (VkRayTracingPipelineCreateInfoKHR*)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline* pPipelines = (VkPipeline*)info[6].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceCooperativeMatrixPropertiesNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertyCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCooperativeMatrixPropertiesNV* pProperties = (VkCooperativeMatrixPropertiesNV*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, pPropertyCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdTraceRaysIndirectKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable = (VkStridedDeviceAddressRegionKHR*)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress indirectDeviceAddress = (VkDeviceAddress)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdTraceRaysIndirect2KHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress indirectDeviceAddress = (VkDeviceAddress)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceAccelerationStructureCompatibilityKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureVersionInfoKHR* pVersionInfo = (VkAccelerationStructureVersionInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureCompatibilityKHR* pCompatibility = (VkAccelerationStructureCompatibilityKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceAccelerationStructureCompatibilityKHR(device, pVersionInfo, pCompatibility);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetRayTracingShaderGroupStackSizeKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipeline pipeline = (VkPipeline)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t group = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderGroupShaderKHR groupShader = (VkShaderGroupShaderKHR)info[3].As<Napi::BigInt>().Uint64Value();
    
    auto result = ::vkGetRayTracingShaderGroupStackSizeKHR(device, pipeline, group, groupShader);
    return Napi::BigInt::New(env, result);

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetRayTracingPipelineStackSizeKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t pipelineStackSize = (uint32_t)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetImageViewHandleNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageViewHandleInfoNVX* pInfo = (VkImageViewHandleInfoNVX*)info[1].As<Napi::BigInt>().Uint64Value();
    
    auto result = ::vkGetImageViewHandleNVX(device, pInfo);
    return Napi::Number::New(env, result);

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetImageViewAddressNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageView imageView = (VkImageView)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageViewAddressPropertiesNVX* pProperties = (VkImageViewAddressPropertiesNVX*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetImageViewAddressNVX(device, imageView, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceSurfacePresentModes2EXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo = (VkPhysicalDeviceSurfaceInfo2KHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPresentModeCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPresentModeKHR* pPresentModes = (VkPresentModeKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceGroupSurfacePresentModes2EXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo = (VkPhysicalDeviceSurfaceInfo2KHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceGroupPresentModeFlagsKHR* pModes = (VkDeviceGroupPresentModeFlagsKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawAcquireFullScreenExclusiveModeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkAcquireFullScreenExclusiveModeEXT(device, swapchain);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawReleaseFullScreenExclusiveModeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkReleaseFullScreenExclusiveModeEXT(device, swapchain);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t queueFamilyIndex = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pCounterCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceCounterKHR* pCounters = (VkPerformanceCounterKHR*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceCounterDescriptionKHR* pCounterDescriptions = (VkPerformanceCounterDescriptionKHR*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo = (VkQueryPoolPerformanceCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pNumPasses = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawAcquireProfilingLockKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAcquireProfilingLockInfoKHR* pInfo = (VkAcquireProfilingLockInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkAcquireProfilingLockKHR(device, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawReleaseProfilingLockKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();
    
    ::vkReleaseProfilingLockKHR(device);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetImageDrmFormatModifierPropertiesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageDrmFormatModifierPropertiesEXT* pProperties = (VkImageDrmFormatModifierPropertiesEXT*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetBufferOpaqueCaptureAddress(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferDeviceAddressInfo* pInfo = (VkBufferDeviceAddressInfo*)info[1].As<Napi::BigInt>().Uint64Value();
    
    auto result = ::vkGetBufferOpaqueCaptureAddress(device, pInfo);
    return Napi::BigInt::New(env, result);

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetBufferDeviceAddress(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferDeviceAddressInfo* pInfo = (VkBufferDeviceAddressInfo*)info[1].As<Napi::BigInt>().Uint64Value();
    
    auto result = ::vkGetBufferDeviceAddress(device, pInfo);
    return Napi::BigInt::New(env, result);

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateHeadlessSurfaceEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInstance instance = (VkInstance)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkHeadlessSurfaceCreateInfoEXT* pCreateInfo = (VkHeadlessSurfaceCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSurfaceKHR* pSurface = (VkSurfaceKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pCombinationCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFramebufferMixedSamplesCombinationNV* pCombinations = (VkFramebufferMixedSamplesCombinationNV*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, pCombinationCount, pCombinations);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawInitializePerformanceApiINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkInitializePerformanceApiInfoINTEL* pInitializeInfo = (VkInitializePerformanceApiInfoINTEL*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkInitializePerformanceApiINTEL(device, pInitializeInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawUninitializePerformanceApiINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();
    
    ::vkUninitializePerformanceApiINTEL(device);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetPerformanceMarkerINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceMarkerInfoINTEL* pMarkerInfo = (VkPerformanceMarkerInfoINTEL*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetPerformanceStreamMarkerINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo = (VkPerformanceStreamMarkerInfoINTEL*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetPerformanceOverrideINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceOverrideInfoINTEL* pOverrideInfo = (VkPerformanceOverrideInfoINTEL*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawAcquirePerformanceConfigurationINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo = (VkPerformanceConfigurationAcquireInfoINTEL*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceConfigurationINTEL* pConfiguration = (VkPerformanceConfigurationINTEL*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkAcquirePerformanceConfigurationINTEL(device, pAcquireInfo, pConfiguration);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawReleasePerformanceConfigurationINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceConfigurationINTEL configuration = (VkPerformanceConfigurationINTEL)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkReleasePerformanceConfigurationINTEL(device, configuration);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawQueueSetPerformanceConfigurationINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceConfigurationINTEL configuration = (VkPerformanceConfigurationINTEL)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkQueueSetPerformanceConfigurationINTEL(queue, configuration);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPerformanceParameterINTEL(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceParameterTypeINTEL parameter = (VkPerformanceParameterTypeINTEL)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPerformanceValueINTEL* pValue = (VkPerformanceValueINTEL*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPerformanceParameterINTEL(device, parameter, pValue);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceMemoryOpaqueCaptureAddress(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo = (VkDeviceMemoryOpaqueCaptureAddressInfo*)info[1].As<Napi::BigInt>().Uint64Value();
    
    auto result = ::vkGetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
    return Napi::BigInt::New(env, result);

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPipelineExecutablePropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineInfoKHR* pPipelineInfo = (VkPipelineInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pExecutableCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineExecutablePropertiesKHR* pProperties = (VkPipelineExecutablePropertiesKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPipelineExecutablePropertiesKHR(device, pPipelineInfo, pExecutableCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPipelineExecutableStatisticsKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineExecutableInfoKHR* pExecutableInfo = (VkPipelineExecutableInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pStatisticCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineExecutableStatisticKHR* pStatistics = (VkPipelineExecutableStatisticKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, pStatisticCount, pStatistics);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPipelineExecutableInternalRepresentationsKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineExecutableInfoKHR* pExecutableInfo = (VkPipelineExecutableInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pInternalRepresentationCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations = (VkPipelineExecutableInternalRepresentationKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetLineStippleEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t lineStippleFactor = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint16_t lineStipplePattern = (uint16_t)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceToolProperties(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pToolCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceToolProperties* pToolProperties = (VkPhysicalDeviceToolProperties*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateAccelerationStructureKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureCreateInfoKHR* pCreateInfo = (VkAccelerationStructureCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureKHR* pAccelerationStructure = (VkAccelerationStructureKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateAccelerationStructureKHR(device, pCreateInfo, pAllocator, pAccelerationStructure);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBuildAccelerationStructuresKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t infoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildGeometryInfoKHR* pInfos = (VkAccelerationStructureBuildGeometryInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildRangeInfoKHR ppBuildRangeInfos = (VkAccelerationStructureBuildRangeInfoKHR)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBuildAccelerationStructuresIndirectKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t infoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildGeometryInfoKHR* pInfos = (VkAccelerationStructureBuildGeometryInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress* pIndirectDeviceAddresses = (VkDeviceAddress*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pIndirectStrides = (uint32_t*)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t ppMaxPrimitiveCounts = (uint32_t)info[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawBuildAccelerationStructuresKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t infoCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildGeometryInfoKHR* pInfos = (VkAccelerationStructureBuildGeometryInfoKHR*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildRangeInfoKHR ppBuildRangeInfos = (VkAccelerationStructureBuildRangeInfoKHR)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkBuildAccelerationStructuresKHR(device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetAccelerationStructureDeviceAddressKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureDeviceAddressInfoKHR* pInfo = (VkAccelerationStructureDeviceAddressInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    auto result = ::vkGetAccelerationStructureDeviceAddressKHR(device, pInfo);
    return Napi::BigInt::New(env, result);

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateDeferredOperationKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR* pDeferredOperation = (VkDeferredOperationKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateDeferredOperationKHR(device, pAllocator, pDeferredOperation);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyDeferredOperationKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR operation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyDeferredOperationKHR(device, operation, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeferredOperationMaxConcurrencyKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR operation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();
    
    auto result = ::vkGetDeferredOperationMaxConcurrencyKHR(device, operation);
    return Napi::Number::New(env, result);

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeferredOperationResultKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR operation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeferredOperationResultKHR(device, operation);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDeferredOperationJoinKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR operation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkDeferredOperationJoinKHR(device, operation);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetCullMode(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCullModeFlags cullMode = (VkCullModeFlags)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetCullMode(commandBuffer, cullMode);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetFrontFace(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFrontFace frontFace = (VkFrontFace)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetFrontFace(commandBuffer, frontFace);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetPrimitiveTopology(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPrimitiveTopology primitiveTopology = (VkPrimitiveTopology)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetViewportWithCount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t viewportCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkViewport* pViewports = (VkViewport*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetScissorWithCount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t scissorCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRect2D* pScissors = (VkRect2D*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBindVertexBuffers2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstBinding = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindingCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer* pBuffers = (VkBuffer*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pOffsets = (VkDeviceSize*)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pSizes = (VkDeviceSize*)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize* pStrides = (VkDeviceSize*)info[6].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetDepthTestEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 depthTestEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetDepthWriteEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 depthWriteEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetDepthCompareOp(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCompareOp depthCompareOp = (VkCompareOp)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetDepthBoundsTestEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 depthBoundsTestEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetStencilTestEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 stencilTestEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetStencilOp(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilFaceFlags faceMask = (VkStencilFaceFlags)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilOp failOp = (VkStencilOp)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilOp passOp = (VkStencilOp)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkStencilOp depthFailOp = (VkStencilOp)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCompareOp compareOp = (VkCompareOp)info[5].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetPatchControlPointsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t patchControlPoints = (uint32_t)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetRasterizerDiscardEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 rasterizerDiscardEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetDepthBiasEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 depthBiasEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetLogicOpEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkLogicOp logicOp = (VkLogicOp)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetLogicOpEXT(commandBuffer, logicOp);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetPrimitiveRestartEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 primitiveRestartEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetTessellationDomainOriginEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkTessellationDomainOrigin domainOrigin = (VkTessellationDomainOrigin)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetDepthClampEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 depthClampEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetPolygonModeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPolygonMode polygonMode = (VkPolygonMode)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetPolygonModeEXT(commandBuffer, polygonMode);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetRasterizationSamplesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampleCountFlagBits rasterizationSamples = (VkSampleCountFlagBits)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetSampleMaskEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampleCountFlagBits samples = (VkSampleCountFlagBits)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSampleMask* pSampleMask = (VkSampleMask*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetAlphaToCoverageEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 alphaToCoverageEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetAlphaToOneEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 alphaToOneEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetLogicOpEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 logicOpEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetColorBlendEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstAttachment = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t attachmentCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32* pColorBlendEnables = (VkBool32*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetColorBlendEquationEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstAttachment = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t attachmentCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkColorBlendEquationEXT* pColorBlendEquations = (VkColorBlendEquationEXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetColorWriteMaskEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstAttachment = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t attachmentCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkColorComponentFlags* pColorWriteMasks = (VkColorComponentFlags*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetRasterizationStreamEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t rasterizationStream = (uint32_t)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetConservativeRasterizationModeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkConservativeRasterizationModeEXT conservativeRasterizationMode = (VkConservativeRasterizationModeEXT)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetExtraPrimitiveOverestimationSizeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float extraPrimitiveOverestimationSize = (float)info[1].As<Napi::Number>().FloatValue();
    
    ::vkCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetDepthClipEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 depthClipEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetSampleLocationsEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 sampleLocationsEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetColorBlendAdvancedEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstAttachment = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t attachmentCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkColorBlendAdvancedEXT* pColorBlendAdvanced = (VkColorBlendAdvancedEXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetProvokingVertexModeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkProvokingVertexModeEXT provokingVertexMode = (VkProvokingVertexModeEXT)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetLineRasterizationModeEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkLineRasterizationModeEXT lineRasterizationMode = (VkLineRasterizationModeEXT)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetLineStippleEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 stippledLineEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetDepthClipNegativeOneToOneEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 negativeOneToOne = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetViewportWScalingEnableNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 viewportWScalingEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetViewportSwizzleNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstViewport = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t viewportCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkViewportSwizzleNV* pViewportSwizzles = (VkViewportSwizzleNV*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetCoverageToColorEnableNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 coverageToColorEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetCoverageToColorLocationNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t coverageToColorLocation = (uint32_t)info[1].As<Napi::Number>().Uint32Value();
    
    ::vkCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetCoverageModulationModeNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCoverageModulationModeNV coverageModulationMode = (VkCoverageModulationModeNV)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetCoverageModulationTableEnableNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 coverageModulationTableEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetCoverageModulationTableNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t coverageModulationTableCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    float* pCoverageModulationTable = (float*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetShadingRateImageEnableNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 shadingRateImageEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetCoverageReductionModeNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCoverageReductionModeNV coverageReductionMode = (VkCoverageReductionModeNV)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetRepresentativeFragmentTestEnableNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32 representativeFragmentTestEnable = (VkBool32)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreatePrivateDataSlot(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPrivateDataSlotCreateInfo* pCreateInfo = (VkPrivateDataSlotCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPrivateDataSlot* pPrivateDataSlot = (VkPrivateDataSlot*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyPrivateDataSlot(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPrivateDataSlot privateDataSlot = (VkPrivateDataSlot)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyPrivateDataSlot(device, privateDataSlot, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawSetPrivateData(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkObjectType objectType = (VkObjectType)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t objectHandle = (uint64_t)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPrivateDataSlot privateDataSlot = (VkPrivateDataSlot)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t data = (uint64_t)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkSetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPrivateData(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkObjectType objectType = (VkObjectType)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t objectHandle = (uint64_t)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPrivateDataSlot privateDataSlot = (VkPrivateDataSlot)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t* pData = (uint64_t*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPrivateData(device, objectType, objectHandle, privateDataSlot, pData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyBuffer2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyBufferInfo2* pCopyBufferInfo = (VkCopyBufferInfo2*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyImage2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyImageInfo2* pCopyImageInfo = (VkCopyImageInfo2*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyImage2(commandBuffer, pCopyImageInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBlitImage2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBlitImageInfo2* pBlitImageInfo = (VkBlitImageInfo2*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBlitImage2(commandBuffer, pBlitImageInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyBufferToImage2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyBufferToImageInfo2* pCopyBufferToImageInfo = (VkCopyBufferToImageInfo2*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyImageToBuffer2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyImageToBufferInfo2* pCopyImageToBufferInfo = (VkCopyImageToBufferInfo2*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdResolveImage2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkResolveImageInfo2* pResolveImageInfo = (VkResolveImageInfo2*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdResolveImage2(commandBuffer, pResolveImageInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetFragmentShadingRateKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExtent2D* pFragmentSize = (VkExtent2D*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFragmentShadingRateCombinerOpKHR combinerOps = (VkFragmentShadingRateCombinerOpKHR)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceFragmentShadingRatesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pFragmentShadingRateCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates = (VkPhysicalDeviceFragmentShadingRateKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetFragmentShadingRateEnumNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFragmentShadingRateNV shadingRate = (VkFragmentShadingRateNV)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFragmentShadingRateCombinerOpKHR combinerOps = (VkFragmentShadingRateCombinerOpKHR)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetAccelerationStructureBuildSizesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildTypeKHR buildType = (VkAccelerationStructureBuildTypeKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo = (VkAccelerationStructureBuildGeometryInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pMaxPrimitiveCounts = (uint32_t*)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo = (VkAccelerationStructureBuildSizesInfoKHR*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetAccelerationStructureBuildSizesKHR(device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetVertexInputEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t vertexBindingDescriptionCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions = (VkVertexInputBindingDescription2EXT*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t vertexAttributeDescriptionCount = (uint32_t)info[3].As<Napi::Number>().Uint32Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions = (VkVertexInputAttributeDescription2EXT*)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetColorWriteEnableEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t attachmentCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBool32* pColorWriteEnables = (VkBool32*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdSetEvent2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDependencyInfo* pDependencyInfo = (VkDependencyInfo*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdSetEvent2(commandBuffer, event, pDependencyInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdResetEvent2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent event = (VkEvent)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags2 stageMask = (VkPipelineStageFlags2)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdResetEvent2(commandBuffer, event, stageMask);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdWaitEvents2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t eventCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkEvent* pEvents = (VkEvent*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDependencyInfo* pDependencyInfos = (VkDependencyInfo*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdPipelineBarrier2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDependencyInfo* pDependencyInfo = (VkDependencyInfo*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawQueueSubmit2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t submitCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubmitInfo2* pSubmits = (VkSubmitInfo2*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFence fence = (VkFence)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkQueueSubmit2(queue, submitCount, pSubmits, fence);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdWriteTimestamp2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags2 stage = (VkPipelineStageFlags2)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t query = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdWriteBufferMarker2AMD(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineStageFlags2 stage = (VkPipelineStageFlags2)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBuffer dstBuffer = (VkBuffer)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceSize dstOffset = (VkDeviceSize)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t marker = (uint32_t)info[4].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetQueueCheckpointData2NV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueue queue = (VkQueue)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pCheckpointDataCount = (uint32_t*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCheckpointData2NV* pCheckpointData = (VkCheckpointData2NV*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceVideoCapabilitiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoProfileInfoKHR* pVideoProfile = (VkVideoProfileInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoCapabilitiesKHR* pCapabilities = (VkVideoCapabilitiesKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceVideoCapabilitiesKHR(physicalDevice, pVideoProfile, pCapabilities);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceVideoFormatPropertiesKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo = (VkPhysicalDeviceVideoFormatInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pVideoFormatPropertyCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoFormatPropertiesKHR* pVideoFormatProperties = (VkVideoFormatPropertiesKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceVideoFormatPropertiesKHR(physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateVideoSessionKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionCreateInfoKHR* pCreateInfo = (VkVideoSessionCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionKHR* pVideoSession = (VkVideoSessionKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateVideoSessionKHR(device, pCreateInfo, pAllocator, pVideoSession);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyVideoSessionKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionKHR videoSession = (VkVideoSessionKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyVideoSessionKHR(device, videoSession, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateVideoSessionParametersKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionParametersCreateInfoKHR* pCreateInfo = (VkVideoSessionParametersCreateInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionParametersKHR* pVideoSessionParameters = (VkVideoSessionParametersKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateVideoSessionParametersKHR(device, pCreateInfo, pAllocator, pVideoSessionParameters);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawUpdateVideoSessionParametersKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionParametersKHR videoSessionParameters = (VkVideoSessionParametersKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo = (VkVideoSessionParametersUpdateInfoKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkUpdateVideoSessionParametersKHR(device, videoSessionParameters, pUpdateInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyVideoSessionParametersKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionParametersKHR videoSessionParameters = (VkVideoSessionParametersKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyVideoSessionParametersKHR(device, videoSessionParameters, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetVideoSessionMemoryRequirementsKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionKHR videoSession = (VkVideoSessionKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pMemoryRequirementsCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements = (VkVideoSessionMemoryRequirementsKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetVideoSessionMemoryRequirementsKHR(device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawBindVideoSessionMemoryKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoSessionKHR videoSession = (VkVideoSessionKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t bindSessionMemoryInfoCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos = (VkBindVideoSessionMemoryInfoKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkBindVideoSessionMemoryKHR(device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDecodeVideoKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoDecodeInfoKHR* pDecodeInfo = (VkVideoDecodeInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBeginVideoCodingKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoBeginCodingInfoKHR* pBeginInfo = (VkVideoBeginCodingInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdControlVideoCodingKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoCodingControlInfoKHR* pCodingControlInfo = (VkVideoCodingControlInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdEndVideoCodingKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoEndCodingInfoKHR* pEndCodingInfo = (VkVideoEndCodingInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdEncodeVideoKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkVideoEncodeInfoKHR* pEncodeInfo = (VkVideoEncodeInfoKHR*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDecompressMemoryNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t decompressRegionCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDecompressMemoryRegionNV* pDecompressMemoryRegions = (VkDecompressMemoryRegionNV*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdDecompressMemoryIndirectCountNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress indirectCommandsAddress = (VkDeviceAddress)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceAddress indirectCommandsCountAddress = (VkDeviceAddress)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t stride = (uint32_t)info[3].As<Napi::Number>().Uint32Value();
    
    ::vkCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateCuModuleNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuModuleCreateInfoNVX* pCreateInfo = (VkCuModuleCreateInfoNVX*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuModuleNVX* pModule = (VkCuModuleNVX*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateCuModuleNVX(device, pCreateInfo, pAllocator, pModule);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateCuFunctionNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuFunctionCreateInfoNVX* pCreateInfo = (VkCuFunctionCreateInfoNVX*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuFunctionNVX* pFunction = (VkCuFunctionNVX*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateCuFunctionNVX(device, pCreateInfo, pAllocator, pFunction);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyCuModuleNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuModuleNVX module = (VkCuModuleNVX)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyCuModuleNVX(device, module, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyCuFunctionNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuFunctionNVX function = (VkCuFunctionNVX)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyCuFunctionNVX(device, function, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCuLaunchKernelNVX(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCuLaunchInfoNVX* pLaunchInfo = (VkCuLaunchInfoNVX*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawSetDeviceMemoryPriorityEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceMemory memory = (VkDeviceMemory)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    float priority = (float)info[2].As<Napi::Number>().FloatValue();
    
    ::vkSetDeviceMemoryPriorityEXT(device, memory, priority);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawAcquireDrmDisplayEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    int32_t drmFd = (int32_t)info[1].As<Napi::Number>().Int32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR display = (VkDisplayKHR)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkAcquireDrmDisplayEXT(physicalDevice, drmFd, display);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDrmDisplayEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    int32_t drmFd = (int32_t)info[1].As<Napi::Number>().Int32Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t connectorId = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDisplayKHR* display = (VkDisplayKHR*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDrmDisplayEXT(physicalDevice, drmFd, connectorId, display);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawWaitForPresentKHR(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSwapchainKHR swapchain = (VkSwapchainKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t presentId = (uint64_t)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint64_t timeout = (uint64_t)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkWaitForPresentKHR(device, swapchain, presentId, timeout);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateBufferCollectionFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionCreateInfoFUCHSIA* pCreateInfo = (VkBufferCollectionCreateInfoFUCHSIA*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionFUCHSIA* pCollection = (VkBufferCollectionFUCHSIA*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateBufferCollectionFUCHSIA(device, pCreateInfo, pAllocator, pCollection);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawSetBufferCollectionBufferConstraintsFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionFUCHSIA collection = (VkBufferCollectionFUCHSIA)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo = (VkBufferConstraintsInfoFUCHSIA*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkSetBufferCollectionBufferConstraintsFUCHSIA(device, collection, pBufferConstraintsInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawSetBufferCollectionImageConstraintsFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionFUCHSIA collection = (VkBufferCollectionFUCHSIA)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo = (VkImageConstraintsInfoFUCHSIA*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkSetBufferCollectionImageConstraintsFUCHSIA(device, collection, pImageConstraintsInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyBufferCollectionFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionFUCHSIA collection = (VkBufferCollectionFUCHSIA)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyBufferCollectionFUCHSIA(device, collection, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetBufferCollectionPropertiesFUCHSIA(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionFUCHSIA collection = (VkBufferCollectionFUCHSIA)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBufferCollectionPropertiesFUCHSIA* pProperties = (VkBufferCollectionPropertiesFUCHSIA*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetBufferCollectionPropertiesFUCHSIA(device, collection, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBeginRendering(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderingInfo* pRenderingInfo = (VkRenderingInfo*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBeginRendering(commandBuffer, pRenderingInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdEndRendering(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdEndRendering(commandBuffer);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDescriptorSetLayoutHostMappingInfoVALVE(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetBindingReferenceVALVE* pBindingReference = (VkDescriptorSetBindingReferenceVALVE*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping = (VkDescriptorSetLayoutHostMappingInfoVALVE*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDescriptorSetLayoutHostMappingInfoVALVE(device, pBindingReference, pHostMapping);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDescriptorSetHostMappingVALVE(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDescriptorSet descriptorSet = (VkDescriptorSet)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void ppData = (void)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDescriptorSetHostMappingVALVE(device, descriptorSet, ppData);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateMicromapEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapCreateInfoEXT* pCreateInfo = (VkMicromapCreateInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapEXT* pMicromap = (VkMicromapEXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateMicromapEXT(device, pCreateInfo, pAllocator, pMicromap);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdBuildMicromapsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t infoCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapBuildInfoEXT* pInfos = (VkMicromapBuildInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawBuildMicromapsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t infoCount = (uint32_t)info[2].As<Napi::Number>().Uint32Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapBuildInfoEXT* pInfos = (VkMicromapBuildInfoEXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkBuildMicromapsEXT(device, deferredOperation, infoCount, pInfos);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyMicromapEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapEXT micromap = (VkMicromapEXT)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyMicromapEXT(device, micromap, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyMicromapEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMicromapInfoEXT* pInfo = (VkCopyMicromapInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyMicromapEXT(commandBuffer, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCopyMicromapEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMicromapInfoEXT* pInfo = (VkCopyMicromapInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCopyMicromapEXT(device, deferredOperation, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyMicromapToMemoryEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMicromapToMemoryInfoEXT* pInfo = (VkCopyMicromapToMemoryInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCopyMicromapToMemoryEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMicromapToMemoryInfoEXT* pInfo = (VkCopyMicromapToMemoryInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCopyMicromapToMemoryEXT(device, deferredOperation, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdCopyMemoryToMicromapEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMemoryToMicromapInfoEXT* pInfo = (VkCopyMemoryToMicromapInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCopyMemoryToMicromapEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeferredOperationKHR deferredOperation = (VkDeferredOperationKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCopyMemoryToMicromapInfoEXT* pInfo = (VkCopyMemoryToMicromapInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCopyMemoryToMicromapEXT(device, deferredOperation, pInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdWriteMicromapsPropertiesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 6) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t micromapCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapEXT* pMicromaps = (VkMicromapEXT*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryType queryType = (VkQueryType)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryPool queryPool = (VkQueryPool)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t firstQuery = (uint32_t)info[5].As<Napi::Number>().Uint32Value();
    
    ::vkCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawWriteMicromapsPropertiesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 7) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsNumber()) { Napi::TypeError::New(env, "Needs Number").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t micromapCount = (uint32_t)info[1].As<Napi::Number>().Uint32Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapEXT* pMicromaps = (VkMicromapEXT*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkQueryType queryType = (VkQueryType)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t dataSize = (size_t)info[4].As<Napi::BigInt>().Uint64Value();

    if (!info[5].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    void* pData = (void*)info[5].As<Napi::BigInt>().Uint64Value();

    if (!info[6].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    size_t stride = (size_t)info[6].As<Napi::BigInt>().Uint64Value();
    
    ::vkWriteMicromapsPropertiesEXT(device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceMicromapCompatibilityEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapVersionInfoEXT* pVersionInfo = (VkMicromapVersionInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureCompatibilityKHR* pCompatibility = (VkAccelerationStructureCompatibilityKHR*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceMicromapCompatibilityEXT(device, pVersionInfo, pCompatibility);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetMicromapBuildSizesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAccelerationStructureBuildTypeKHR buildType = (VkAccelerationStructureBuildTypeKHR)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapBuildInfoEXT* pBuildInfo = (VkMicromapBuildInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkMicromapBuildSizesInfoEXT* pSizeInfo = (VkMicromapBuildSizesInfoEXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetMicromapBuildSizesEXT(device, buildType, pBuildInfo, pSizeInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetShaderModuleIdentifierEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModule shaderModule = (VkShaderModule)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModuleIdentifierEXT* pIdentifier = (VkShaderModuleIdentifierEXT*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetShaderModuleIdentifierEXT(device, shaderModule, pIdentifier);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetShaderModuleCreateInfoIdentifierEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModuleCreateInfo* pCreateInfo = (VkShaderModuleCreateInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkShaderModuleIdentifierEXT* pIdentifier = (VkShaderModuleIdentifierEXT*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetShaderModuleCreateInfoIdentifierEXT(device, pCreateInfo, pIdentifier);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetImageSubresourceLayout2EXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImage image = (VkImage)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageSubresource2EXT* pSubresource = (VkImageSubresource2EXT*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkSubresourceLayout2EXT* pLayout = (VkSubresourceLayout2EXT*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetImageSubresourceLayout2EXT(device, image, pSubresource, pLayout);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPipelinePropertiesEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPipelineInfoEXT* pPipelineInfo = (VkPipelineInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkBaseOutStructure* pPipelineProperties = (VkBaseOutStructure*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPipelinePropertiesEXT(device, pPipelineInfo, pPipelineProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawExportMetalObjectsEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkExportMetalObjectsInfoEXT* pMetalObjectsInfo = (VkExportMetalObjectsInfoEXT*)info[1].As<Napi::BigInt>().Uint64Value();
    
    ::vkExportMetalObjectsEXT(device, pMetalObjectsInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetFramebufferTilePropertiesQCOM(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkFramebuffer framebuffer = (VkFramebuffer)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pPropertiesCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkTilePropertiesQCOM* pProperties = (VkTilePropertiesQCOM*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetFramebufferTilePropertiesQCOM(device, framebuffer, pPropertiesCount, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDynamicRenderingTilePropertiesQCOM(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkRenderingInfo* pRenderingInfo = (VkRenderingInfo*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkTilePropertiesQCOM* pProperties = (VkTilePropertiesQCOM*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDynamicRenderingTilePropertiesQCOM(device, pRenderingInfo, pProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetPhysicalDeviceOpticalFlowImageFormatsNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkPhysicalDevice physicalDevice = (VkPhysicalDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo = (VkOpticalFlowImageFormatInfoNV*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    uint32_t* pFormatCount = (uint32_t*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties = (VkOpticalFlowImageFormatPropertiesNV*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetPhysicalDeviceOpticalFlowImageFormatsNV(physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCreateOpticalFlowSessionNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 4) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowSessionCreateInfoNV* pCreateInfo = (VkOpticalFlowSessionCreateInfoNV*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowSessionNV* pSession = (VkOpticalFlowSessionNV*)info[3].As<Napi::BigInt>().Uint64Value();
    
    ::vkCreateOpticalFlowSessionNV(device, pCreateInfo, pAllocator, pSession);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawDestroyOpticalFlowSessionNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowSessionNV session = (VkOpticalFlowSessionNV)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkAllocationCallbacks* pAllocator = (VkAllocationCallbacks*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkDestroyOpticalFlowSessionNV(device, session, pAllocator);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawBindOpticalFlowSessionImageNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 5) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowSessionNV session = (VkOpticalFlowSessionNV)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowSessionBindingPointNV bindingPoint = (VkOpticalFlowSessionBindingPointNV)info[2].As<Napi::BigInt>().Uint64Value();

    if (!info[3].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageView view = (VkImageView)info[3].As<Napi::BigInt>().Uint64Value();

    if (!info[4].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkImageLayout layout = (VkImageLayout)info[4].As<Napi::BigInt>().Uint64Value();
    
    ::vkBindOpticalFlowSessionImageNV(device, session, bindingPoint, view, layout);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawCmdOpticalFlowExecuteNV(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkCommandBuffer commandBuffer = (VkCommandBuffer)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowSessionNV session = (VkOpticalFlowSessionNV)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkOpticalFlowExecuteInfoNV* pExecuteInfo = (VkOpticalFlowExecuteInfoNV*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
    return env.Null();

        
}


#ifdef __cplusplus
inline 
#endif
Napi::Value rawGetDeviceFaultInfoEXT(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); return env.Null();
    }

    
    if (!info[0].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDevice device = (VkDevice)info[0].As<Napi::BigInt>().Uint64Value();

    if (!info[1].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceFaultCountsEXT* pFaultCounts = (VkDeviceFaultCountsEXT*)info[1].As<Napi::BigInt>().Uint64Value();

    if (!info[2].IsBigInt()) { Napi::TypeError::New(env, "Needs BigInt").ThrowAsJavaScriptException(); return env.Null(); }
    VkDeviceFaultInfoEXT* pFaultInfo = (VkDeviceFaultInfoEXT*)info[2].As<Napi::BigInt>().Uint64Value();
    
    ::vkGetDeviceFaultInfoEXT(device, pFaultCounts, pFaultInfo);
    return env.Null();

        
}


    

#endif
    