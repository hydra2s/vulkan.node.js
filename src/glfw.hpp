#pragma once

//
#define GLFW_INCLUDE_VULKAN

//
#ifndef VK_USE_PLATFORM_WIN32_KHR
#define VK_USE_PLATFORM_WIN32_KHR
#endif

//
#include <volk/volk.h>

//
#include "./native.hpp"
#include <napi.h>
#include <iostream>
#include <map>
#include <GLFW/glfw3.h>

// 
Napi::Boolean __glfwVulkanSupported(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    return Napi::Boolean::New(env, ::glfwVulkanSupported());
}

// TODO: make arrays
Napi::BigInt __glfwGetRequiredInstanceExtensions(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    return Napi::BigInt::New(env, (uint64_t)(::glfwGetRequiredInstanceExtensions((uint32_t*)GetAddress(env, info_[0]))));
}

//
Napi::Number __glfwCreateWindowSurface(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    return Napi::Number::New(env, ::glfwCreateWindowSurface(
        (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless),
        //info_[1].IsExternal() ? *info_[1].As<Napi::External<GLFWwindow*>>().Data() : (GLFWwindow*)GetAddress(env, info_[1]),
        info_[1].IsExternal() ? info_[1].As<Napi::External<GLFWwindow>>().Data() : (GLFWwindow*)GetAddress(env, info_[1]),
        (const VkAllocationCallbacks*)(GetAddress(env, info_[2])),
        (VkSurfaceKHR *)(GetAddress(env, info_[3]))
    ));
}

//
Napi::Boolean __glfwGetPhysicalDevicePresentationSupport(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;
    return Napi::Boolean::New(env, ::glfwGetPhysicalDevicePresentationSupport(
        (VkInstance)info_[0].As<Napi::BigInt>().Uint64Value(&lossless),
        (VkPhysicalDevice)info_[1].As<Napi::BigInt>().Uint64Value(&lossless),
        info_[2].As<Napi::Number>().Uint32Value()
    ));
}
