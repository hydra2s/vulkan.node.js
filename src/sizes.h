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
        case VK_STRUCTURE_TYPE_APPLICATION_INFO: return sizeof(VkApplicationInfo); break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO: return sizeof(VkDeviceQueueCreateInfo); break;
        case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO: return sizeof(VkDeviceCreateInfo); break;
        case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO: return sizeof(VkInstanceCreateInfo); break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO: return sizeof(VkMemoryAllocateInfo); break;
        case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE: return sizeof(VkMappedMemoryRange); break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET: return sizeof(VkWriteDescriptorSet); break;
        case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET: return sizeof(VkCopyDescriptorSet); break;
        case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO: return sizeof(VkBufferCreateInfo); break;
        case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO: return sizeof(VkBufferViewCreateInfo); break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER: return sizeof(VkMemoryBarrier); break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER: return sizeof(VkBufferMemoryBarrier); break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER: return sizeof(VkImageMemoryBarrier); break;
        case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO: return sizeof(VkImageCreateInfo); break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO: return sizeof(VkImageViewCreateInfo); break;
        case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO: return sizeof(VkBindSparseInfo); break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO: return sizeof(VkShaderModuleCreateInfo); break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO: return sizeof(VkDescriptorSetLayoutCreateInfo); break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO: return sizeof(VkDescriptorPoolCreateInfo); break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO: return sizeof(VkDescriptorSetAllocateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO: return sizeof(VkPipelineShaderStageCreateInfo); break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO: return sizeof(VkComputePipelineCreateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO: return sizeof(VkPipelineVertexInputStateCreateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO: return sizeof(VkPipelineInputAssemblyStateCreateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO: return sizeof(VkPipelineTessellationStateCreateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO: return sizeof(VkPipelineViewportStateCreateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO: return sizeof(VkPipelineRasterizationStateCreateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO: return sizeof(VkPipelineMultisampleStateCreateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO: return sizeof(VkPipelineColorBlendStateCreateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO: return sizeof(VkPipelineDynamicStateCreateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO: return sizeof(VkPipelineDepthStencilStateCreateInfo); break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO: return sizeof(VkGraphicsPipelineCreateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO: return sizeof(VkPipelineCacheCreateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: return sizeof(VkPipelineLayoutCreateInfo); break;
        case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO: return sizeof(VkSamplerCreateInfo); break;
        case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO: return sizeof(VkCommandPoolCreateInfo); break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO: return sizeof(VkCommandBufferAllocateInfo); break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO: return sizeof(VkCommandBufferInheritanceInfo); break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO: return sizeof(VkCommandBufferBeginInfo); break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO: return sizeof(VkRenderPassBeginInfo); break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO: return sizeof(VkRenderPassCreateInfo); break;
        case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO: return sizeof(VkEventCreateInfo); break;
        case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO: return sizeof(VkFenceCreateInfo); break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO: return sizeof(VkSemaphoreCreateInfo); break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO: return sizeof(VkQueryPoolCreateInfo); break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO: return sizeof(VkFramebufferCreateInfo); break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO: return sizeof(VkSubmitInfo); break;
#ifdef VK_KHR_display
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR: return sizeof(VkDisplayModeCreateInfoKHR); break;
#endif
#ifdef VK_KHR_display
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR: return sizeof(VkDisplaySurfaceCreateInfoKHR); break;
#endif
#ifdef VK_KHR_display_swapchain
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR: return sizeof(VkDisplayPresentInfoKHR); break;
#endif
#ifdef VK_KHR_android_surface
        case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR: return sizeof(VkAndroidSurfaceCreateInfoKHR); break;
#endif
#ifdef VK_NN_vi_surface
        case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN: return sizeof(VkViSurfaceCreateInfoNN); break;
#endif
#ifdef VK_KHR_wayland_surface
        case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR: return sizeof(VkWaylandSurfaceCreateInfoKHR); break;
#endif
#ifdef VK_KHR_win32_surface
        case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR: return sizeof(VkWin32SurfaceCreateInfoKHR); break;
#endif
#ifdef VK_KHR_xlib_surface
        case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR: return sizeof(VkXlibSurfaceCreateInfoKHR); break;
#endif
#ifdef VK_KHR_xcb_surface
        case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR: return sizeof(VkXcbSurfaceCreateInfoKHR); break;
#endif
#ifdef VK_EXT_directfb_surface
        case VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT: return sizeof(VkDirectFBSurfaceCreateInfoEXT); break;
#endif
#ifdef VK_FUCHSIA_imagepipe_surface
        case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA: return sizeof(VkImagePipeSurfaceCreateInfoFUCHSIA); break;
#endif
#ifdef VK_GGP_stream_descriptor_surface
        case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP: return sizeof(VkStreamDescriptorSurfaceCreateInfoGGP); break;
#endif
#ifdef VK_QNX_screen_surface
        case VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX: return sizeof(VkScreenSurfaceCreateInfoQNX); break;
#endif
#ifdef VK_KHR_swapchain
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR: return sizeof(VkSwapchainCreateInfoKHR); break;
#endif
#ifdef VK_KHR_swapchain
        case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR: return sizeof(VkPresentInfoKHR); break;
#endif
#ifdef VK_EXT_debug_report
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT: return sizeof(VkDebugReportCallbackCreateInfoEXT); break;
#endif
#ifdef VK_EXT_validation_flags
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT: return sizeof(VkValidationFlagsEXT); break;
#endif
#ifdef VK_EXT_validation_features
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT: return sizeof(VkValidationFeaturesEXT); break;
#endif
#ifdef VK_AMD_rasterization_order
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD: return sizeof(VkPipelineRasterizationStateRasterizationOrderAMD); break;
#endif
#ifdef VK_EXT_debug_marker
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT: return sizeof(VkDebugMarkerObjectNameInfoEXT); break;
#endif
#ifdef VK_EXT_debug_marker
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT: return sizeof(VkDebugMarkerObjectTagInfoEXT); break;
#endif
#ifdef VK_EXT_debug_marker
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT: return sizeof(VkDebugMarkerMarkerInfoEXT); break;
#endif
#ifdef VK_NV_dedicated_allocation
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV: return sizeof(VkDedicatedAllocationImageCreateInfoNV); break;
#endif
#ifdef VK_NV_dedicated_allocation
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV: return sizeof(VkDedicatedAllocationBufferCreateInfoNV); break;
#endif
#ifdef VK_NV_dedicated_allocation
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV: return sizeof(VkDedicatedAllocationMemoryAllocateInfoNV); break;
#endif
#ifdef VK_NV_external_memory
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV: return sizeof(VkExternalMemoryImageCreateInfoNV); break;
#endif
#ifdef VK_NV_external_memory
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV: return sizeof(VkExportMemoryAllocateInfoNV); break;
#endif
#ifdef VK_NV_external_memory_win32
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV: return sizeof(VkImportMemoryWin32HandleInfoNV); break;
#endif
#ifdef VK_NV_external_memory_win32
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV: return sizeof(VkExportMemoryWin32HandleInfoNV); break;
#endif
#ifdef VK_NV_win32_keyed_mutex
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV: return sizeof(VkWin32KeyedMutexAcquireReleaseInfoNV); break;
#endif
#ifdef VK_NV_device_generated_commands
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV: return sizeof(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV); break;
#endif
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO: return sizeof(VkDevicePrivateDataCreateInfo); break;
        case VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO: return sizeof(VkPrivateDataSlotCreateInfo); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES: return sizeof(VkPhysicalDevicePrivateDataFeatures); break;
#ifdef VK_NV_device_generated_commands
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV: return sizeof(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV); break;
#endif
#ifdef VK_EXT_multi_draw
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceMultiDrawPropertiesEXT); break;
#endif
#ifdef VK_NV_device_generated_commands
        case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV: return sizeof(VkGraphicsShaderGroupCreateInfoNV); break;
#endif
#ifdef VK_NV_device_generated_commands
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV: return sizeof(VkGraphicsPipelineShaderGroupsCreateInfoNV); break;
#endif
#ifdef VK_NV_device_generated_commands
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV: return sizeof(VkIndirectCommandsLayoutTokenNV); break;
#endif
#ifdef VK_NV_device_generated_commands
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV: return sizeof(VkIndirectCommandsLayoutCreateInfoNV); break;
#endif
#ifdef VK_NV_device_generated_commands
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV: return sizeof(VkGeneratedCommandsInfoNV); break;
#endif
#ifdef VK_NV_device_generated_commands
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV: return sizeof(VkGeneratedCommandsMemoryRequirementsInfoNV); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2: return sizeof(VkPhysicalDeviceFeatures2); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2: return sizeof(VkPhysicalDeviceProperties2); break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2: return sizeof(VkFormatProperties2); break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2: return sizeof(VkImageFormatProperties2); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2: return sizeof(VkPhysicalDeviceImageFormatInfo2); break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2: return sizeof(VkQueueFamilyProperties2); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2: return sizeof(VkPhysicalDeviceMemoryProperties2); break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2: return sizeof(VkSparseImageFormatProperties2); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2: return sizeof(VkPhysicalDeviceSparseImageFormatInfo2); break;
#ifdef VK_KHR_push_descriptor
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR: return sizeof(VkPhysicalDevicePushDescriptorPropertiesKHR); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES: return sizeof(VkPhysicalDeviceDriverProperties); break;
#ifdef VK_KHR_incremental_present
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR: return sizeof(VkPresentRegionsKHR); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES: return sizeof(VkPhysicalDeviceVariablePointersFeatures); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO: return sizeof(VkPhysicalDeviceExternalImageFormatInfo); break;
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES: return sizeof(VkExternalImageFormatProperties); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO: return sizeof(VkPhysicalDeviceExternalBufferInfo); break;
        case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES: return sizeof(VkExternalBufferProperties); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES: return sizeof(VkPhysicalDeviceIDProperties); break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO: return sizeof(VkExternalMemoryImageCreateInfo); break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO: return sizeof(VkExternalMemoryBufferCreateInfo); break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO: return sizeof(VkExportMemoryAllocateInfo); break;
#ifdef VK_KHR_external_memory_win32
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR: return sizeof(VkImportMemoryWin32HandleInfoKHR); break;
#endif
#ifdef VK_KHR_external_memory_win32
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR: return sizeof(VkExportMemoryWin32HandleInfoKHR); break;
#endif
#ifdef VK_FUCHSIA_external_memory
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA: return sizeof(VkImportMemoryZirconHandleInfoFUCHSIA); break;
#endif
#ifdef VK_FUCHSIA_external_memory
        case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA: return sizeof(VkMemoryZirconHandlePropertiesFUCHSIA); break;
#endif
#ifdef VK_FUCHSIA_external_memory
        case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA: return sizeof(VkMemoryGetZirconHandleInfoFUCHSIA); break;
#endif
#ifdef VK_KHR_external_memory_win32
        case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR: return sizeof(VkMemoryWin32HandlePropertiesKHR); break;
#endif
#ifdef VK_KHR_external_memory_win32
        case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR: return sizeof(VkMemoryGetWin32HandleInfoKHR); break;
#endif
#ifdef VK_KHR_external_memory_fd
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR: return sizeof(VkImportMemoryFdInfoKHR); break;
#endif
#ifdef VK_KHR_external_memory_fd
        case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR: return sizeof(VkMemoryFdPropertiesKHR); break;
#endif
#ifdef VK_KHR_external_memory_fd
        case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR: return sizeof(VkMemoryGetFdInfoKHR); break;
#endif
#ifdef VK_KHR_win32_keyed_mutex
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR: return sizeof(VkWin32KeyedMutexAcquireReleaseInfoKHR); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO: return sizeof(VkPhysicalDeviceExternalSemaphoreInfo); break;
        case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES: return sizeof(VkExternalSemaphoreProperties); break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO: return sizeof(VkExportSemaphoreCreateInfo); break;
#ifdef VK_KHR_external_semaphore_win32
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: return sizeof(VkImportSemaphoreWin32HandleInfoKHR); break;
#endif
#ifdef VK_KHR_external_semaphore_win32
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: return sizeof(VkExportSemaphoreWin32HandleInfoKHR); break;
#endif
#ifdef VK_KHR_external_semaphore_win32
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR: return sizeof(VkD3D12FenceSubmitInfoKHR); break;
#endif
#ifdef VK_KHR_external_semaphore_win32
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR: return sizeof(VkSemaphoreGetWin32HandleInfoKHR); break;
#endif
#ifdef VK_KHR_external_semaphore_fd
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR: return sizeof(VkImportSemaphoreFdInfoKHR); break;
#endif
#ifdef VK_KHR_external_semaphore_fd
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR: return sizeof(VkSemaphoreGetFdInfoKHR); break;
#endif
#ifdef VK_FUCHSIA_external_semaphore
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA: return sizeof(VkImportSemaphoreZirconHandleInfoFUCHSIA); break;
#endif
#ifdef VK_FUCHSIA_external_semaphore
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA: return sizeof(VkSemaphoreGetZirconHandleInfoFUCHSIA); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO: return sizeof(VkPhysicalDeviceExternalFenceInfo); break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES: return sizeof(VkExternalFenceProperties); break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO: return sizeof(VkExportFenceCreateInfo); break;
#ifdef VK_KHR_external_fence_win32
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR: return sizeof(VkImportFenceWin32HandleInfoKHR); break;
#endif
#ifdef VK_KHR_external_fence_win32
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR: return sizeof(VkExportFenceWin32HandleInfoKHR); break;
#endif
#ifdef VK_KHR_external_fence_win32
        case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR: return sizeof(VkFenceGetWin32HandleInfoKHR); break;
#endif
#ifdef VK_KHR_external_fence_fd
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR: return sizeof(VkImportFenceFdInfoKHR); break;
#endif
#ifdef VK_KHR_external_fence_fd
        case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR: return sizeof(VkFenceGetFdInfoKHR); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES: return sizeof(VkPhysicalDeviceMultiviewFeatures); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES: return sizeof(VkPhysicalDeviceMultiviewProperties); break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO: return sizeof(VkRenderPassMultiviewCreateInfo); break;
#ifdef VK_EXT_display_surface_counter
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT: return sizeof(VkSurfaceCapabilities2EXT); break;
#endif
#ifdef VK_EXT_display_control
        case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT: return sizeof(VkDisplayPowerInfoEXT); break;
#endif
#ifdef VK_EXT_display_control
        case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT: return sizeof(VkDeviceEventInfoEXT); break;
#endif
#ifdef VK_EXT_display_control
        case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT: return sizeof(VkDisplayEventInfoEXT); break;
#endif
#ifdef VK_EXT_display_control
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT: return sizeof(VkSwapchainCounterCreateInfoEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES: return sizeof(VkPhysicalDeviceGroupProperties); break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO: return sizeof(VkMemoryAllocateFlagsInfo); break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO: return sizeof(VkBindBufferMemoryInfo); break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO: return sizeof(VkBindBufferMemoryDeviceGroupInfo); break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO: return sizeof(VkBindImageMemoryInfo); break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO: return sizeof(VkBindImageMemoryDeviceGroupInfo); break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO: return sizeof(VkDeviceGroupRenderPassBeginInfo); break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO: return sizeof(VkDeviceGroupCommandBufferBeginInfo); break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO: return sizeof(VkDeviceGroupSubmitInfo); break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO: return sizeof(VkDeviceGroupBindSparseInfo); break;
#ifdef VK_KHR_device_group
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR: return sizeof(VkDeviceGroupPresentCapabilitiesKHR); break;
#endif
#ifdef VK_KHR_device_group
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR: return sizeof(VkImageSwapchainCreateInfoKHR); break;
#endif
#ifdef VK_KHR_device_group
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR: return sizeof(VkBindImageMemorySwapchainInfoKHR); break;
#endif
#ifdef VK_KHR_device_group
        case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR: return sizeof(VkAcquireNextImageInfoKHR); break;
#endif
#ifdef VK_KHR_device_group
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR: return sizeof(VkDeviceGroupPresentInfoKHR); break;
#endif
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO: return sizeof(VkDeviceGroupDeviceCreateInfo); break;
#ifdef VK_KHR_device_group
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR: return sizeof(VkDeviceGroupSwapchainCreateInfoKHR); break;
#endif
        case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO: return sizeof(VkDescriptorUpdateTemplateCreateInfo); break;
#ifdef VK_KHR_present_id
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR: return sizeof(VkPhysicalDevicePresentIdFeaturesKHR); break;
#endif
#ifdef VK_KHR_present_id
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR: return sizeof(VkPresentIdKHR); break;
#endif
#ifdef VK_KHR_present_wait
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR: return sizeof(VkPhysicalDevicePresentWaitFeaturesKHR); break;
#endif
#ifdef VK_EXT_hdr_metadata
        case VK_STRUCTURE_TYPE_HDR_METADATA_EXT: return sizeof(VkHdrMetadataEXT); break;
#endif
#ifdef VK_AMD_display_native_hdr
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD: return sizeof(VkDisplayNativeHdrSurfaceCapabilitiesAMD); break;
#endif
#ifdef VK_AMD_display_native_hdr
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD: return sizeof(VkSwapchainDisplayNativeHdrCreateInfoAMD); break;
#endif
#ifdef VK_GOOGLE_display_timing
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE: return sizeof(VkPresentTimesInfoGOOGLE); break;
#endif
#ifdef VK_MVK_ios_surface
        case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK: return sizeof(VkIOSSurfaceCreateInfoMVK); break;
#endif
#ifdef VK_MVK_macos_surface
        case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK: return sizeof(VkMacOSSurfaceCreateInfoMVK); break;
#endif
#ifdef VK_EXT_metal_surface
        case VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT: return sizeof(VkMetalSurfaceCreateInfoEXT); break;
#endif
#ifdef VK_NV_clip_space_w_scaling
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV: return sizeof(VkPipelineViewportWScalingStateCreateInfoNV); break;
#endif
#ifdef VK_NV_viewport_swizzle
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV: return sizeof(VkPipelineViewportSwizzleStateCreateInfoNV); break;
#endif
#ifdef VK_EXT_discard_rectangles
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceDiscardRectanglePropertiesEXT); break;
#endif
#ifdef VK_EXT_discard_rectangles
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT: return sizeof(VkPipelineDiscardRectangleStateCreateInfoEXT); break;
#endif
#ifdef VK_NVX_multiview_per_view_attributes
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX: return sizeof(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX); break;
#endif
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO: return sizeof(VkRenderPassInputAttachmentAspectCreateInfo); break;
#ifdef VK_KHR_get_surface_capabilities2
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR: return sizeof(VkPhysicalDeviceSurfaceInfo2KHR); break;
#endif
#ifdef VK_KHR_get_surface_capabilities2
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR: return sizeof(VkSurfaceCapabilities2KHR); break;
#endif
#ifdef VK_KHR_get_surface_capabilities2
        case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR: return sizeof(VkSurfaceFormat2KHR); break;
#endif
#ifdef VK_KHR_get_display_properties2
        case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR: return sizeof(VkDisplayProperties2KHR); break;
#endif
#ifdef VK_KHR_get_display_properties2
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR: return sizeof(VkDisplayPlaneProperties2KHR); break;
#endif
#ifdef VK_KHR_get_display_properties2
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR: return sizeof(VkDisplayModeProperties2KHR); break;
#endif
#ifdef VK_KHR_get_display_properties2
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR: return sizeof(VkDisplayPlaneInfo2KHR); break;
#endif
#ifdef VK_KHR_get_display_properties2
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR: return sizeof(VkDisplayPlaneCapabilities2KHR); break;
#endif
#ifdef VK_KHR_shared_presentable_image
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR: return sizeof(VkSharedPresentSurfaceCapabilitiesKHR); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES: return sizeof(VkPhysicalDevice16BitStorageFeatures); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES: return sizeof(VkPhysicalDeviceSubgroupProperties); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES: return sizeof(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures); break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2: return sizeof(VkBufferMemoryRequirementsInfo2); break;
        case VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS: return sizeof(VkDeviceBufferMemoryRequirements); break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2: return sizeof(VkImageMemoryRequirementsInfo2); break;
        case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2: return sizeof(VkImageSparseMemoryRequirementsInfo2); break;
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS: return sizeof(VkDeviceImageMemoryRequirements); break;
        case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2: return sizeof(VkMemoryRequirements2); break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2: return sizeof(VkSparseImageMemoryRequirements2); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES: return sizeof(VkPhysicalDevicePointClippingProperties); break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS: return sizeof(VkMemoryDedicatedRequirements); break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO: return sizeof(VkMemoryDedicatedAllocateInfo); break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO: return sizeof(VkImageViewUsageCreateInfo); break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO: return sizeof(VkPipelineTessellationDomainOriginStateCreateInfo); break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO: return sizeof(VkSamplerYcbcrConversionInfo); break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO: return sizeof(VkSamplerYcbcrConversionCreateInfo); break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO: return sizeof(VkBindImagePlaneMemoryInfo); break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO: return sizeof(VkImagePlaneMemoryRequirementsInfo); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES: return sizeof(VkPhysicalDeviceSamplerYcbcrConversionFeatures); break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES: return sizeof(VkSamplerYcbcrConversionImageFormatProperties); break;
#ifdef VK_AMD_texture_gather_bias_lod
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD: return sizeof(VkTextureLODGatherFormatPropertiesAMD); break;
#endif
#ifdef VK_EXT_conditional_rendering
        case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT: return sizeof(VkConditionalRenderingBeginInfoEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO: return sizeof(VkProtectedSubmitInfo); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES: return sizeof(VkPhysicalDeviceProtectedMemoryFeatures); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES: return sizeof(VkPhysicalDeviceProtectedMemoryProperties); break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2: return sizeof(VkDeviceQueueInfo2); break;
#ifdef VK_NV_fragment_coverage_to_color
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV: return sizeof(VkPipelineCoverageToColorStateCreateInfoNV); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES: return sizeof(VkPhysicalDeviceSamplerFilterMinmaxProperties); break;
#ifdef VK_EXT_sample_locations
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: return sizeof(VkSampleLocationsInfoEXT); break;
#endif
#ifdef VK_EXT_sample_locations
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT: return sizeof(VkRenderPassSampleLocationsBeginInfoEXT); break;
#endif
#ifdef VK_EXT_sample_locations
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT: return sizeof(VkPipelineSampleLocationsStateCreateInfoEXT); break;
#endif
#ifdef VK_EXT_sample_locations
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceSampleLocationsPropertiesEXT); break;
#endif
#ifdef VK_EXT_sample_locations
        case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT: return sizeof(VkMultisamplePropertiesEXT); break;
#endif
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO: return sizeof(VkSamplerReductionModeCreateInfo); break;
#ifdef VK_EXT_blend_operation_advanced
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT: return sizeof(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT); break;
#endif
#ifdef VK_EXT_multi_draw
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT: return sizeof(VkPhysicalDeviceMultiDrawFeaturesEXT); break;
#endif
#ifdef VK_EXT_blend_operation_advanced
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT); break;
#endif
#ifdef VK_EXT_blend_operation_advanced
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT: return sizeof(VkPipelineColorBlendAdvancedStateCreateInfoEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES: return sizeof(VkPhysicalDeviceInlineUniformBlockFeatures); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES: return sizeof(VkPhysicalDeviceInlineUniformBlockProperties); break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK: return sizeof(VkWriteDescriptorSetInlineUniformBlock); break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO: return sizeof(VkDescriptorPoolInlineUniformBlockCreateInfo); break;
#ifdef VK_NV_framebuffer_mixed_samples
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV: return sizeof(VkPipelineCoverageModulationStateCreateInfoNV); break;
#endif
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO: return sizeof(VkImageFormatListCreateInfo); break;
#ifdef VK_EXT_validation_cache
        case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT: return sizeof(VkValidationCacheCreateInfoEXT); break;
#endif
#ifdef VK_EXT_validation_cache
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT: return sizeof(VkShaderModuleValidationCacheCreateInfoEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES: return sizeof(VkPhysicalDeviceMaintenance3Properties); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES: return sizeof(VkPhysicalDeviceMaintenance4Features); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES: return sizeof(VkPhysicalDeviceMaintenance4Properties); break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT: return sizeof(VkDescriptorSetLayoutSupport); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES: return sizeof(VkPhysicalDeviceShaderDrawParametersFeatures); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES: return sizeof(VkPhysicalDeviceShaderFloat16Int8Features); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES: return sizeof(VkPhysicalDeviceFloatControlsProperties); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES: return sizeof(VkPhysicalDeviceHostQueryResetFeatures); break;
#ifdef VK_ANDROID_native_buffer
        case VK_STRUCTURE_TYPE_NATIVE_BUFFER_ANDROID: return sizeof(VkNativeBufferANDROID); break;
#endif
#ifdef VK_ANDROID_native_buffer
        case VK_STRUCTURE_TYPE_SWAPCHAIN_IMAGE_CREATE_INFO_ANDROID: return sizeof(VkSwapchainImageCreateInfoANDROID); break;
#endif
#ifdef VK_ANDROID_native_buffer
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENTATION_PROPERTIES_ANDROID: return sizeof(VkPhysicalDevicePresentationPropertiesANDROID); break;
#endif
#ifdef VK_KHR_global_priority
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR: return sizeof(VkDeviceQueueGlobalPriorityCreateInfoKHR); break;
#endif
#ifdef VK_KHR_global_priority
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR: return sizeof(VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR); break;
#endif
#ifdef VK_KHR_global_priority
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR: return sizeof(VkQueueFamilyGlobalPriorityPropertiesKHR); break;
#endif
#ifdef VK_EXT_debug_utils
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT: return sizeof(VkDebugUtilsObjectNameInfoEXT); break;
#endif
#ifdef VK_EXT_debug_utils
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT: return sizeof(VkDebugUtilsObjectTagInfoEXT); break;
#endif
#ifdef VK_EXT_debug_utils
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT: return sizeof(VkDebugUtilsLabelEXT); break;
#endif
#ifdef VK_EXT_debug_utils
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT: return sizeof(VkDebugUtilsMessengerCreateInfoEXT); break;
#endif
#ifdef VK_EXT_debug_utils
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT: return sizeof(VkDebugUtilsMessengerCallbackDataEXT); break;
#endif
#ifdef VK_EXT_device_memory_report
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT: return sizeof(VkPhysicalDeviceDeviceMemoryReportFeaturesEXT); break;
#endif
#ifdef VK_EXT_device_memory_report
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT: return sizeof(VkDeviceDeviceMemoryReportCreateInfoEXT); break;
#endif
#ifdef VK_EXT_device_memory_report
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT: return sizeof(VkDeviceMemoryReportCallbackDataEXT); break;
#endif
#ifdef VK_EXT_external_memory_host
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT: return sizeof(VkImportMemoryHostPointerInfoEXT); break;
#endif
#ifdef VK_EXT_external_memory_host
        case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT: return sizeof(VkMemoryHostPointerPropertiesEXT); break;
#endif
#ifdef VK_EXT_external_memory_host
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceExternalMemoryHostPropertiesEXT); break;
#endif
#ifdef VK_EXT_conservative_rasterization
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceConservativeRasterizationPropertiesEXT); break;
#endif
#ifdef VK_EXT_calibrated_timestamps
        case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT: return sizeof(VkCalibratedTimestampInfoEXT); break;
#endif
#ifdef VK_AMD_shader_core_properties
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD: return sizeof(VkPhysicalDeviceShaderCorePropertiesAMD); break;
#endif
#ifdef VK_AMD_shader_core_properties2
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD: return sizeof(VkPhysicalDeviceShaderCoreProperties2AMD); break;
#endif
#ifdef VK_EXT_conservative_rasterization
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT: return sizeof(VkPipelineRasterizationConservativeStateCreateInfoEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES: return sizeof(VkPhysicalDeviceDescriptorIndexingFeatures); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES: return sizeof(VkPhysicalDeviceDescriptorIndexingProperties); break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO: return sizeof(VkDescriptorSetLayoutBindingFlagsCreateInfo); break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO: return sizeof(VkDescriptorSetVariableDescriptorCountAllocateInfo); break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT: return sizeof(VkDescriptorSetVariableDescriptorCountLayoutSupport); break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2: return sizeof(VkAttachmentDescription2); break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2: return sizeof(VkAttachmentReference2); break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2: return sizeof(VkSubpassDescription2); break;
        case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2: return sizeof(VkSubpassDependency2); break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2: return sizeof(VkRenderPassCreateInfo2); break;
        case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO: return sizeof(VkSubpassBeginInfo); break;
        case VK_STRUCTURE_TYPE_SUBPASS_END_INFO: return sizeof(VkSubpassEndInfo); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES: return sizeof(VkPhysicalDeviceTimelineSemaphoreFeatures); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES: return sizeof(VkPhysicalDeviceTimelineSemaphoreProperties); break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO: return sizeof(VkSemaphoreTypeCreateInfo); break;
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO: return sizeof(VkTimelineSemaphoreSubmitInfo); break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO: return sizeof(VkSemaphoreWaitInfo); break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO: return sizeof(VkSemaphoreSignalInfo); break;
#ifdef VK_EXT_vertex_attribute_divisor
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT: return sizeof(VkPipelineVertexInputDivisorStateCreateInfoEXT); break;
#endif
#ifdef VK_EXT_vertex_attribute_divisor
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT); break;
#endif
#ifdef VK_EXT_pci_bus_info
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT: return sizeof(VkPhysicalDevicePCIBusInfoPropertiesEXT); break;
#endif
#ifdef VK_ANDROID_external_memory_android_hardware_buffer
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID: return sizeof(VkImportAndroidHardwareBufferInfoANDROID); break;
#endif
#ifdef VK_ANDROID_external_memory_android_hardware_buffer
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID: return sizeof(VkAndroidHardwareBufferUsageANDROID); break;
#endif
#ifdef VK_ANDROID_external_memory_android_hardware_buffer
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID: return sizeof(VkAndroidHardwareBufferPropertiesANDROID); break;
#endif
#ifdef VK_ANDROID_external_memory_android_hardware_buffer
        case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID: return sizeof(VkMemoryGetAndroidHardwareBufferInfoANDROID); break;
#endif
#ifdef VK_ANDROID_external_memory_android_hardware_buffer
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID: return sizeof(VkAndroidHardwareBufferFormatPropertiesANDROID); break;
#endif
#ifdef VK_EXT_conditional_rendering
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT: return sizeof(VkCommandBufferInheritanceConditionalRenderingInfoEXT); break;
#endif
#ifdef VK_ANDROID_external_memory_android_hardware_buffer
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID: return sizeof(VkExternalFormatANDROID); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES: return sizeof(VkPhysicalDevice8BitStorageFeatures); break;
#ifdef VK_EXT_conditional_rendering
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT: return sizeof(VkPhysicalDeviceConditionalRenderingFeaturesEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES: return sizeof(VkPhysicalDeviceVulkanMemoryModelFeatures); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES: return sizeof(VkPhysicalDeviceShaderAtomicInt64Features); break;
#ifdef VK_EXT_shader_atomic_float
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT: return sizeof(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT); break;
#endif
#ifdef VK_EXT_shader_atomic_float2
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT: return sizeof(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT); break;
#endif
#ifdef VK_EXT_vertex_attribute_divisor
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT: return sizeof(VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT); break;
#endif
#ifdef VK_NV_device_diagnostic_checkpoints
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV: return sizeof(VkQueueFamilyCheckpointPropertiesNV); break;
#endif
#ifdef VK_NV_device_diagnostic_checkpoints
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV: return sizeof(VkCheckpointDataNV); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES: return sizeof(VkPhysicalDeviceDepthStencilResolveProperties); break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE: return sizeof(VkSubpassDescriptionDepthStencilResolve); break;
#ifdef VK_EXT_astc_decode_mode
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT: return sizeof(VkImageViewASTCDecodeModeEXT); break;
#endif
#ifdef VK_EXT_astc_decode_mode
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT: return sizeof(VkPhysicalDeviceASTCDecodeFeaturesEXT); break;
#endif
#ifdef VK_EXT_transform_feedback
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT: return sizeof(VkPhysicalDeviceTransformFeedbackFeaturesEXT); break;
#endif
#ifdef VK_EXT_transform_feedback
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceTransformFeedbackPropertiesEXT); break;
#endif
#ifdef VK_EXT_transform_feedback
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT: return sizeof(VkPipelineRasterizationStateStreamCreateInfoEXT); break;
#endif
#ifdef VK_NV_representative_fragment_test
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV: return sizeof(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV); break;
#endif
#ifdef VK_NV_representative_fragment_test
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV: return sizeof(VkPipelineRepresentativeFragmentTestStateCreateInfoNV); break;
#endif
#ifdef VK_NV_scissor_exclusive
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV: return sizeof(VkPhysicalDeviceExclusiveScissorFeaturesNV); break;
#endif
#ifdef VK_NV_scissor_exclusive
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV: return sizeof(VkPipelineViewportExclusiveScissorStateCreateInfoNV); break;
#endif
#ifdef VK_NV_corner_sampled_image
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV: return sizeof(VkPhysicalDeviceCornerSampledImageFeaturesNV); break;
#endif
#ifdef VK_NV_compute_shader_derivatives
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV: return sizeof(VkPhysicalDeviceComputeShaderDerivativesFeaturesNV); break;
#endif
#ifdef VK_NV_shader_image_footprint
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV: return sizeof(VkPhysicalDeviceShaderImageFootprintFeaturesNV); break;
#endif
#ifdef VK_NV_dedicated_allocation_image_aliasing
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV: return sizeof(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV); break;
#endif
#ifdef VK_NV_copy_memory_indirect
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV: return sizeof(VkPhysicalDeviceCopyMemoryIndirectFeaturesNV); break;
#endif
#ifdef VK_NV_copy_memory_indirect
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV: return sizeof(VkPhysicalDeviceCopyMemoryIndirectPropertiesNV); break;
#endif
#ifdef VK_NV_memory_decompression
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV: return sizeof(VkPhysicalDeviceMemoryDecompressionFeaturesNV); break;
#endif
#ifdef VK_NV_memory_decompression
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV: return sizeof(VkPhysicalDeviceMemoryDecompressionPropertiesNV); break;
#endif
#ifdef VK_NV_shading_rate_image
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV: return sizeof(VkPipelineViewportShadingRateImageStateCreateInfoNV); break;
#endif
#ifdef VK_NV_shading_rate_image
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV: return sizeof(VkPhysicalDeviceShadingRateImageFeaturesNV); break;
#endif
#ifdef VK_NV_shading_rate_image
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV: return sizeof(VkPhysicalDeviceShadingRateImagePropertiesNV); break;
#endif
#ifdef VK_HUAWEI_invocation_mask
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI: return sizeof(VkPhysicalDeviceInvocationMaskFeaturesHUAWEI); break;
#endif
#ifdef VK_NV_shading_rate_image
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV: return sizeof(VkPipelineViewportCoarseSampleOrderStateCreateInfoNV); break;
#endif
#ifdef VK_NV_mesh_shader
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV: return sizeof(VkPhysicalDeviceMeshShaderFeaturesNV); break;
#endif
#ifdef VK_NV_mesh_shader
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV: return sizeof(VkPhysicalDeviceMeshShaderPropertiesNV); break;
#endif
#ifdef VK_EXT_mesh_shader
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT: return sizeof(VkPhysicalDeviceMeshShaderFeaturesEXT); break;
#endif
#ifdef VK_EXT_mesh_shader
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceMeshShaderPropertiesEXT); break;
#endif
#ifdef VK_NV_ray_tracing
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV: return sizeof(VkRayTracingShaderGroupCreateInfoNV); break;
#endif
#ifdef VK_KHR_ray_tracing_pipeline
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR: return sizeof(VkRayTracingShaderGroupCreateInfoKHR); break;
#endif
#ifdef VK_NV_ray_tracing
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV: return sizeof(VkRayTracingPipelineCreateInfoNV); break;
#endif
#ifdef VK_KHR_ray_tracing_pipeline
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR: return sizeof(VkRayTracingPipelineCreateInfoKHR); break;
#endif
#ifdef VK_NV_ray_tracing
        case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV: return sizeof(VkGeometryTrianglesNV); break;
#endif
#ifdef VK_NV_ray_tracing
        case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV: return sizeof(VkGeometryAABBNV); break;
#endif
#ifdef VK_NV_ray_tracing
        case VK_STRUCTURE_TYPE_GEOMETRY_NV: return sizeof(VkGeometryNV); break;
#endif
#ifdef VK_NV_ray_tracing
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV: return sizeof(VkAccelerationStructureInfoNV); break;
#endif
#ifdef VK_NV_ray_tracing
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV: return sizeof(VkAccelerationStructureCreateInfoNV); break;
#endif
#ifdef VK_NV_ray_tracing
        case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV: return sizeof(VkBindAccelerationStructureMemoryInfoNV); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR: return sizeof(VkWriteDescriptorSetAccelerationStructureKHR); break;
#endif
#ifdef VK_NV_ray_tracing
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV: return sizeof(VkWriteDescriptorSetAccelerationStructureNV); break;
#endif
#ifdef VK_NV_ray_tracing
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV: return sizeof(VkAccelerationStructureMemoryRequirementsInfoNV); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR: return sizeof(VkPhysicalDeviceAccelerationStructureFeaturesKHR); break;
#endif
#ifdef VK_KHR_ray_tracing_pipeline
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR: return sizeof(VkPhysicalDeviceRayTracingPipelineFeaturesKHR); break;
#endif
#ifdef VK_KHR_ray_query
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR: return sizeof(VkPhysicalDeviceRayQueryFeaturesKHR); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR: return sizeof(VkPhysicalDeviceAccelerationStructurePropertiesKHR); break;
#endif
#ifdef VK_KHR_ray_tracing_pipeline
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR: return sizeof(VkPhysicalDeviceRayTracingPipelinePropertiesKHR); break;
#endif
#ifdef VK_NV_ray_tracing
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV: return sizeof(VkPhysicalDeviceRayTracingPropertiesNV); break;
#endif
#ifdef VK_KHR_ray_tracing_maintenance1
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR: return sizeof(VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR); break;
#endif
#ifdef VK_EXT_image_drm_format_modifier
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT: return sizeof(VkDrmFormatModifierPropertiesListEXT); break;
#endif
#ifdef VK_EXT_image_drm_format_modifier
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT: return sizeof(VkPhysicalDeviceImageDrmFormatModifierInfoEXT); break;
#endif
#ifdef VK_EXT_image_drm_format_modifier
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT: return sizeof(VkImageDrmFormatModifierListCreateInfoEXT); break;
#endif
#ifdef VK_EXT_image_drm_format_modifier
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT: return sizeof(VkImageDrmFormatModifierExplicitCreateInfoEXT); break;
#endif
#ifdef VK_EXT_image_drm_format_modifier
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT: return sizeof(VkImageDrmFormatModifierPropertiesEXT); break;
#endif
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO: return sizeof(VkImageStencilUsageCreateInfo); break;
#ifdef VK_AMD_memory_overallocation_behavior
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD: return sizeof(VkDeviceMemoryOverallocationCreateInfoAMD); break;
#endif
#ifdef VK_EXT_fragment_density_map
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT: return sizeof(VkPhysicalDeviceFragmentDensityMapFeaturesEXT); break;
#endif
#ifdef VK_EXT_fragment_density_map2
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT: return sizeof(VkPhysicalDeviceFragmentDensityMap2FeaturesEXT); break;
#endif
#ifdef VK_QCOM_fragment_density_map_offset
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM: return sizeof(VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM); break;
#endif
#ifdef VK_EXT_fragment_density_map
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceFragmentDensityMapPropertiesEXT); break;
#endif
#ifdef VK_EXT_fragment_density_map2
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceFragmentDensityMap2PropertiesEXT); break;
#endif
#ifdef VK_QCOM_fragment_density_map_offset
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM: return sizeof(VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM); break;
#endif
#ifdef VK_EXT_fragment_density_map
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT: return sizeof(VkRenderPassFragmentDensityMapCreateInfoEXT); break;
#endif
#ifdef VK_QCOM_fragment_density_map_offset
        case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM: return sizeof(VkSubpassFragmentDensityMapOffsetEndInfoQCOM); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES: return sizeof(VkPhysicalDeviceScalarBlockLayoutFeatures); break;
#ifdef VK_KHR_surface_protected_capabilities
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR: return sizeof(VkSurfaceProtectedCapabilitiesKHR); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES: return sizeof(VkPhysicalDeviceUniformBufferStandardLayoutFeatures); break;
#ifdef VK_EXT_depth_clip_enable
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT: return sizeof(VkPhysicalDeviceDepthClipEnableFeaturesEXT); break;
#endif
#ifdef VK_EXT_depth_clip_enable
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT: return sizeof(VkPipelineRasterizationDepthClipStateCreateInfoEXT); break;
#endif
#ifdef VK_EXT_memory_budget
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceMemoryBudgetPropertiesEXT); break;
#endif
#ifdef VK_EXT_memory_priority
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT: return sizeof(VkPhysicalDeviceMemoryPriorityFeaturesEXT); break;
#endif
#ifdef VK_EXT_memory_priority
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT: return sizeof(VkMemoryPriorityAllocateInfoEXT); break;
#endif
#ifdef VK_EXT_pageable_device_local_memory
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT: return sizeof(VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES: return sizeof(VkPhysicalDeviceBufferDeviceAddressFeatures); break;
#ifdef VK_EXT_buffer_device_address
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT: return sizeof(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT); break;
#endif
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO: return sizeof(VkBufferDeviceAddressInfo); break;
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO: return sizeof(VkBufferOpaqueCaptureAddressCreateInfo); break;
#ifdef VK_EXT_buffer_device_address
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT: return sizeof(VkBufferDeviceAddressCreateInfoEXT); break;
#endif
#ifdef VK_EXT_filter_cubic
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT: return sizeof(VkPhysicalDeviceImageViewImageFormatInfoEXT); break;
#endif
#ifdef VK_EXT_filter_cubic
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT: return sizeof(VkFilterCubicImageViewImageFormatPropertiesEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES: return sizeof(VkPhysicalDeviceImagelessFramebufferFeatures); break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO: return sizeof(VkFramebufferAttachmentsCreateInfo); break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO: return sizeof(VkFramebufferAttachmentImageInfo); break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO: return sizeof(VkRenderPassAttachmentBeginInfo); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES: return sizeof(VkPhysicalDeviceTextureCompressionASTCHDRFeatures); break;
#ifdef VK_NV_cooperative_matrix
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV: return sizeof(VkPhysicalDeviceCooperativeMatrixFeaturesNV); break;
#endif
#ifdef VK_NV_cooperative_matrix
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV: return sizeof(VkPhysicalDeviceCooperativeMatrixPropertiesNV); break;
#endif
#ifdef VK_NV_cooperative_matrix
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV: return sizeof(VkCooperativeMatrixPropertiesNV); break;
#endif
#ifdef VK_EXT_ycbcr_image_arrays
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT: return sizeof(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT); break;
#endif
#ifdef VK_NVX_image_view_handle
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX: return sizeof(VkImageViewHandleInfoNVX); break;
#endif
#ifdef VK_NVX_image_view_handle
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX: return sizeof(VkImageViewAddressPropertiesNVX); break;
#endif
#ifdef VK_GGP_frame_token
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP: return sizeof(VkPresentFrameTokenGGP); break;
#endif
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO: return sizeof(VkPipelineCreationFeedbackCreateInfo); break;
#ifdef VK_EXT_full_screen_exclusive
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT: return sizeof(VkSurfaceFullScreenExclusiveInfoEXT); break;
#endif
#ifdef VK_EXT_full_screen_exclusive
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT: return sizeof(VkSurfaceFullScreenExclusiveWin32InfoEXT); break;
#endif
#ifdef VK_EXT_full_screen_exclusive
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT: return sizeof(VkSurfaceCapabilitiesFullScreenExclusiveEXT); break;
#endif
#ifdef VK_NV_present_barrier
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV: return sizeof(VkPhysicalDevicePresentBarrierFeaturesNV); break;
#endif
#ifdef VK_NV_present_barrier
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV: return sizeof(VkSurfaceCapabilitiesPresentBarrierNV); break;
#endif
#ifdef VK_NV_present_barrier
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV: return sizeof(VkSwapchainPresentBarrierCreateInfoNV); break;
#endif
#ifdef VK_KHR_performance_query
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR: return sizeof(VkPhysicalDevicePerformanceQueryFeaturesKHR); break;
#endif
#ifdef VK_KHR_performance_query
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR: return sizeof(VkPhysicalDevicePerformanceQueryPropertiesKHR); break;
#endif
#ifdef VK_KHR_performance_query
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR: return sizeof(VkPerformanceCounterKHR); break;
#endif
#ifdef VK_KHR_performance_query
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR: return sizeof(VkPerformanceCounterDescriptionKHR); break;
#endif
#ifdef VK_KHR_performance_query
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR: return sizeof(VkQueryPoolPerformanceCreateInfoKHR); break;
#endif
#ifdef VK_KHR_performance_query
        case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR: return sizeof(VkAcquireProfilingLockInfoKHR); break;
#endif
#ifdef VK_KHR_performance_query
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR: return sizeof(VkPerformanceQuerySubmitInfoKHR); break;
#endif
#ifdef VK_EXT_headless_surface
        case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT: return sizeof(VkHeadlessSurfaceCreateInfoEXT); break;
#endif
#ifdef VK_NV_coverage_reduction_mode
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV: return sizeof(VkPhysicalDeviceCoverageReductionModeFeaturesNV); break;
#endif
#ifdef VK_NV_coverage_reduction_mode
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV: return sizeof(VkPipelineCoverageReductionStateCreateInfoNV); break;
#endif
#ifdef VK_NV_coverage_reduction_mode
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV: return sizeof(VkFramebufferMixedSamplesCombinationNV); break;
#endif
#ifdef VK_INTEL_shader_integer_functions2
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL: return sizeof(VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL); break;
#endif
#ifdef VK_INTEL_performance_query
        case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL: return sizeof(VkInitializePerformanceApiInfoINTEL); break;
#endif
#ifdef VK_INTEL_performance_query
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL: return sizeof(VkQueryPoolPerformanceQueryCreateInfoINTEL); break;
#endif
#ifdef VK_INTEL_performance_query
        case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL: return sizeof(VkPerformanceMarkerInfoINTEL); break;
#endif
#ifdef VK_INTEL_performance_query
        case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL: return sizeof(VkPerformanceStreamMarkerInfoINTEL); break;
#endif
#ifdef VK_INTEL_performance_query
        case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL: return sizeof(VkPerformanceOverrideInfoINTEL); break;
#endif
#ifdef VK_INTEL_performance_query
        case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL: return sizeof(VkPerformanceConfigurationAcquireInfoINTEL); break;
#endif
#ifdef VK_KHR_shader_clock
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR: return sizeof(VkPhysicalDeviceShaderClockFeaturesKHR); break;
#endif
#ifdef VK_EXT_index_type_uint8
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT: return sizeof(VkPhysicalDeviceIndexTypeUint8FeaturesEXT); break;
#endif
#ifdef VK_NV_shader_sm_builtins
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV: return sizeof(VkPhysicalDeviceShaderSMBuiltinsPropertiesNV); break;
#endif
#ifdef VK_NV_shader_sm_builtins
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV: return sizeof(VkPhysicalDeviceShaderSMBuiltinsFeaturesNV); break;
#endif
#ifdef VK_EXT_fragment_shader_interlock
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT: return sizeof(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES: return sizeof(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures); break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT: return sizeof(VkAttachmentReferenceStencilLayout); break;
#ifdef VK_EXT_primitive_topology_list_restart
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT: return sizeof(VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT); break;
#endif
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT: return sizeof(VkAttachmentDescriptionStencilLayout); break;
#ifdef VK_KHR_pipeline_executable_properties
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR: return sizeof(VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR); break;
#endif
#ifdef VK_KHR_pipeline_executable_properties
        case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR: return sizeof(VkPipelineInfoKHR); break;
#endif
#ifdef VK_KHR_pipeline_executable_properties
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR: return sizeof(VkPipelineExecutablePropertiesKHR); break;
#endif
#ifdef VK_KHR_pipeline_executable_properties
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR: return sizeof(VkPipelineExecutableInfoKHR); break;
#endif
#ifdef VK_KHR_pipeline_executable_properties
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR: return sizeof(VkPipelineExecutableStatisticKHR); break;
#endif
#ifdef VK_KHR_pipeline_executable_properties
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR: return sizeof(VkPipelineExecutableInternalRepresentationKHR); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES: return sizeof(VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures); break;
#ifdef VK_EXT_texel_buffer_alignment
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT: return sizeof(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES: return sizeof(VkPhysicalDeviceTexelBufferAlignmentProperties); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES: return sizeof(VkPhysicalDeviceSubgroupSizeControlFeatures); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES: return sizeof(VkPhysicalDeviceSubgroupSizeControlProperties); break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO: return sizeof(VkPipelineShaderStageRequiredSubgroupSizeCreateInfo); break;
#ifdef VK_HUAWEI_subpass_shading
        case VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI: return sizeof(VkSubpassShadingPipelineCreateInfoHUAWEI); break;
#endif
#ifdef VK_HUAWEI_subpass_shading
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI: return sizeof(VkPhysicalDeviceSubpassShadingPropertiesHUAWEI); break;
#endif
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO: return sizeof(VkMemoryOpaqueCaptureAddressAllocateInfo); break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO: return sizeof(VkDeviceMemoryOpaqueCaptureAddressInfo); break;
#ifdef VK_EXT_line_rasterization
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT: return sizeof(VkPhysicalDeviceLineRasterizationFeaturesEXT); break;
#endif
#ifdef VK_EXT_line_rasterization
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceLineRasterizationPropertiesEXT); break;
#endif
#ifdef VK_EXT_line_rasterization
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT: return sizeof(VkPipelineRasterizationLineStateCreateInfoEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES: return sizeof(VkPhysicalDevicePipelineCreationCacheControlFeatures); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: return sizeof(VkPhysicalDeviceVulkan11Features); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: return sizeof(VkPhysicalDeviceVulkan11Properties); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: return sizeof(VkPhysicalDeviceVulkan12Features); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: return sizeof(VkPhysicalDeviceVulkan12Properties); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: return sizeof(VkPhysicalDeviceVulkan13Features); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES: return sizeof(VkPhysicalDeviceVulkan13Properties); break;
#ifdef VK_AMD_pipeline_compiler_control
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD: return sizeof(VkPipelineCompilerControlCreateInfoAMD); break;
#endif
#ifdef VK_AMD_device_coherent_memory
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD: return sizeof(VkPhysicalDeviceCoherentMemoryFeaturesAMD); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES: return sizeof(VkPhysicalDeviceToolProperties); break;
#ifdef VK_EXT_custom_border_color
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT: return sizeof(VkSamplerCustomBorderColorCreateInfoEXT); break;
#endif
#ifdef VK_EXT_custom_border_color
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceCustomBorderColorPropertiesEXT); break;
#endif
#ifdef VK_EXT_custom_border_color
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT: return sizeof(VkPhysicalDeviceCustomBorderColorFeaturesEXT); break;
#endif
#ifdef VK_EXT_border_color_swizzle
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT: return sizeof(VkSamplerBorderColorComponentMappingCreateInfoEXT); break;
#endif
#ifdef VK_EXT_border_color_swizzle
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT: return sizeof(VkPhysicalDeviceBorderColorSwizzleFeaturesEXT); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR: return sizeof(VkAccelerationStructureGeometryTrianglesDataKHR); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR: return sizeof(VkAccelerationStructureGeometryAabbsDataKHR); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR: return sizeof(VkAccelerationStructureGeometryInstancesDataKHR); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR: return sizeof(VkAccelerationStructureGeometryKHR); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR: return sizeof(VkAccelerationStructureBuildGeometryInfoKHR); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR: return sizeof(VkAccelerationStructureCreateInfoKHR); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR: return sizeof(VkAccelerationStructureDeviceAddressInfoKHR); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR: return sizeof(VkAccelerationStructureVersionInfoKHR); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR: return sizeof(VkCopyAccelerationStructureInfoKHR); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR: return sizeof(VkCopyAccelerationStructureToMemoryInfoKHR); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR: return sizeof(VkCopyMemoryToAccelerationStructureInfoKHR); break;
#endif
#ifdef VK_KHR_ray_tracing_pipeline
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR: return sizeof(VkRayTracingPipelineInterfaceCreateInfoKHR); break;
#endif
#ifdef VK_KHR_pipeline_library
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR: return sizeof(VkPipelineLibraryCreateInfoKHR); break;
#endif
#ifdef VK_EXT_extended_dynamic_state
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT: return sizeof(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT); break;
#endif
#ifdef VK_EXT_extended_dynamic_state2
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT: return sizeof(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT); break;
#endif
#ifdef VK_EXT_extended_dynamic_state3
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT: return sizeof(VkPhysicalDeviceExtendedDynamicState3FeaturesEXT); break;
#endif
#ifdef VK_EXT_extended_dynamic_state3
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceExtendedDynamicState3PropertiesEXT); break;
#endif
#ifdef VK_QCOM_render_pass_transform
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM: return sizeof(VkRenderPassTransformBeginInfoQCOM); break;
#endif
#ifdef VK_QCOM_rotated_copy_commands
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM: return sizeof(VkCopyCommandTransformInfoQCOM); break;
#endif
#ifdef VK_QCOM_render_pass_transform
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM: return sizeof(VkCommandBufferInheritanceRenderPassTransformInfoQCOM); break;
#endif
#ifdef VK_NV_device_diagnostics_config
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV: return sizeof(VkPhysicalDeviceDiagnosticsConfigFeaturesNV); break;
#endif
#ifdef VK_NV_device_diagnostics_config
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV: return sizeof(VkDeviceDiagnosticsConfigCreateInfoNV); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES: return sizeof(VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures); break;
#ifdef VK_KHR_shader_subgroup_uniform_control_flow
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR: return sizeof(VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR); break;
#endif
#ifdef VK_EXT_robustness2
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT: return sizeof(VkPhysicalDeviceRobustness2FeaturesEXT); break;
#endif
#ifdef VK_EXT_robustness2
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceRobustness2PropertiesEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES: return sizeof(VkPhysicalDeviceImageRobustnessFeatures); break;
#ifdef VK_KHR_workgroup_memory_explicit_layout
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR: return sizeof(VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR); break;
#endif
#ifdef VK_KHR_portability_subset
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR: return sizeof(VkPhysicalDevicePortabilitySubsetFeaturesKHR); break;
#endif
#ifdef VK_KHR_portability_subset
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR: return sizeof(VkPhysicalDevicePortabilitySubsetPropertiesKHR); break;
#endif
#ifdef VK_EXT_4444_formats
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT: return sizeof(VkPhysicalDevice4444FormatsFeaturesEXT); break;
#endif
#ifdef VK_HUAWEI_subpass_shading
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI: return sizeof(VkPhysicalDeviceSubpassShadingFeaturesHUAWEI); break;
#endif
        case VK_STRUCTURE_TYPE_BUFFER_COPY_2: return sizeof(VkBufferCopy2); break;
        case VK_STRUCTURE_TYPE_IMAGE_COPY_2: return sizeof(VkImageCopy2); break;
        case VK_STRUCTURE_TYPE_IMAGE_BLIT_2: return sizeof(VkImageBlit2); break;
        case VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2: return sizeof(VkBufferImageCopy2); break;
        case VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2: return sizeof(VkImageResolve2); break;
        case VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2: return sizeof(VkCopyBufferInfo2); break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2: return sizeof(VkCopyImageInfo2); break;
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2: return sizeof(VkBlitImageInfo2); break;
        case VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2: return sizeof(VkCopyBufferToImageInfo2); break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2: return sizeof(VkCopyImageToBufferInfo2); break;
        case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2: return sizeof(VkResolveImageInfo2); break;
#ifdef VK_EXT_shader_image_atomic_int64
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT: return sizeof(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT); break;
#endif
#ifdef VK_KHR_fragment_shading_rate
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: return sizeof(VkFragmentShadingRateAttachmentInfoKHR); break;
#endif
#ifdef VK_KHR_fragment_shading_rate
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR: return sizeof(VkPipelineFragmentShadingRateStateCreateInfoKHR); break;
#endif
#ifdef VK_KHR_fragment_shading_rate
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR: return sizeof(VkPhysicalDeviceFragmentShadingRateFeaturesKHR); break;
#endif
#ifdef VK_KHR_fragment_shading_rate
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR: return sizeof(VkPhysicalDeviceFragmentShadingRatePropertiesKHR); break;
#endif
#ifdef VK_KHR_fragment_shading_rate
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR: return sizeof(VkPhysicalDeviceFragmentShadingRateKHR); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES: return sizeof(VkPhysicalDeviceShaderTerminateInvocationFeatures); break;
#ifdef VK_NV_fragment_shading_rate_enums
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV: return sizeof(VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV); break;
#endif
#ifdef VK_NV_fragment_shading_rate_enums
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV: return sizeof(VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV); break;
#endif
#ifdef VK_NV_fragment_shading_rate_enums
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV: return sizeof(VkPipelineFragmentShadingRateEnumStateCreateInfoNV); break;
#endif
#ifdef VK_KHR_acceleration_structure
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR: return sizeof(VkAccelerationStructureBuildSizesInfoKHR); break;
#endif
#ifdef VK_EXT_image_2d_view_of_3d
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT: return sizeof(VkPhysicalDeviceImage2DViewOf3DFeaturesEXT); break;
#endif
#ifdef VK_EXT_mutable_descriptor_type
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT: return sizeof(VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT); break;
#endif
#ifdef VK_EXT_mutable_descriptor_type
        case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT: return sizeof(VkMutableDescriptorTypeCreateInfoEXT); break;
#endif
#ifdef VK_EXT_depth_clip_control
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT: return sizeof(VkPhysicalDeviceDepthClipControlFeaturesEXT); break;
#endif
#ifdef VK_EXT_depth_clip_control
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT: return sizeof(VkPipelineViewportDepthClipControlCreateInfoEXT); break;
#endif
#ifdef VK_EXT_vertex_input_dynamic_state
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT: return sizeof(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT); break;
#endif
#ifdef VK_NV_external_memory_rdma
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV: return sizeof(VkPhysicalDeviceExternalMemoryRDMAFeaturesNV); break;
#endif
#ifdef VK_EXT_vertex_input_dynamic_state
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT: return sizeof(VkVertexInputBindingDescription2EXT); break;
#endif
#ifdef VK_EXT_vertex_input_dynamic_state
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT: return sizeof(VkVertexInputAttributeDescription2EXT); break;
#endif
#ifdef VK_EXT_color_write_enable
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT: return sizeof(VkPhysicalDeviceColorWriteEnableFeaturesEXT); break;
#endif
#ifdef VK_EXT_color_write_enable
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT: return sizeof(VkPipelineColorWriteCreateInfoEXT); break;
#endif
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2: return sizeof(VkMemoryBarrier2); break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2: return sizeof(VkImageMemoryBarrier2); break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2: return sizeof(VkBufferMemoryBarrier2); break;
        case VK_STRUCTURE_TYPE_DEPENDENCY_INFO: return sizeof(VkDependencyInfo); break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO: return sizeof(VkSemaphoreSubmitInfo); break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO: return sizeof(VkCommandBufferSubmitInfo); break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO_2: return sizeof(VkSubmitInfo2); break;
#ifdef VK_KHR_synchronization2
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV: return sizeof(VkQueueFamilyCheckpointProperties2NV); break;
#endif
#ifdef VK_KHR_synchronization2
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV: return sizeof(VkCheckpointData2NV); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES: return sizeof(VkPhysicalDeviceSynchronization2Features); break;
#ifdef VK_EXT_primitives_generated_query
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT: return sizeof(VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT); break;
#endif
#ifdef VK_EXT_legacy_dithering
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT: return sizeof(VkPhysicalDeviceLegacyDitheringFeaturesEXT); break;
#endif
#ifdef VK_EXT_multisampled_render_to_single_sampled
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT: return sizeof(VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT); break;
#endif
#ifdef VK_EXT_multisampled_render_to_single_sampled
        case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT: return sizeof(VkSubpassResolvePerformanceQueryEXT); break;
#endif
#ifdef VK_EXT_multisampled_render_to_single_sampled
        case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT: return sizeof(VkMultisampledRenderToSingleSampledInfoEXT); break;
#endif
#ifdef VK_EXT_pipeline_protected_access
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT: return sizeof(VkPhysicalDevicePipelineProtectedAccessFeaturesEXT); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR: return sizeof(VkQueueFamilyVideoPropertiesKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR: return sizeof(VkQueueFamilyQueryResultStatusPropertiesKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR: return sizeof(VkVideoProfileListInfoKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR: return sizeof(VkPhysicalDeviceVideoFormatInfoKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR: return sizeof(VkVideoFormatPropertiesKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR: return sizeof(VkVideoProfileInfoKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR: return sizeof(VkVideoCapabilitiesKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR: return sizeof(VkVideoSessionMemoryRequirementsKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR: return sizeof(VkBindVideoSessionMemoryInfoKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR: return sizeof(VkVideoPictureResourceInfoKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR: return sizeof(VkVideoReferenceSlotInfoKHR); break;
#endif
#ifdef VK_KHR_video_decode_queue
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR: return sizeof(VkVideoDecodeCapabilitiesKHR); break;
#endif
#ifdef VK_KHR_video_decode_queue
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR: return sizeof(VkVideoDecodeUsageInfoKHR); break;
#endif
#ifdef VK_KHR_video_decode_queue
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR: return sizeof(VkVideoDecodeInfoKHR); break;
#endif
#ifdef VK_EXT_video_decode_h264
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_EXT: return sizeof(VkVideoDecodeH264ProfileInfoEXT); break;
#endif
#ifdef VK_EXT_video_decode_h264
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_EXT: return sizeof(VkVideoDecodeH264CapabilitiesEXT); break;
#endif
#ifdef VK_EXT_video_decode_h264
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_EXT: return sizeof(VkVideoDecodeH264SessionParametersAddInfoEXT); break;
#endif
#ifdef VK_EXT_video_decode_h264
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_EXT: return sizeof(VkVideoDecodeH264SessionParametersCreateInfoEXT); break;
#endif
#ifdef VK_EXT_video_decode_h264
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_EXT: return sizeof(VkVideoDecodeH264PictureInfoEXT); break;
#endif
#ifdef VK_EXT_video_decode_h264
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_EXT: return sizeof(VkVideoDecodeH264DpbSlotInfoEXT); break;
#endif
#ifdef VK_EXT_video_decode_h265
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_EXT: return sizeof(VkVideoDecodeH265ProfileInfoEXT); break;
#endif
#ifdef VK_EXT_video_decode_h265
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_EXT: return sizeof(VkVideoDecodeH265CapabilitiesEXT); break;
#endif
#ifdef VK_EXT_video_decode_h265
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_EXT: return sizeof(VkVideoDecodeH265SessionParametersAddInfoEXT); break;
#endif
#ifdef VK_EXT_video_decode_h265
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_EXT: return sizeof(VkVideoDecodeH265SessionParametersCreateInfoEXT); break;
#endif
#ifdef VK_EXT_video_decode_h265
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_EXT: return sizeof(VkVideoDecodeH265PictureInfoEXT); break;
#endif
#ifdef VK_EXT_video_decode_h265
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_EXT: return sizeof(VkVideoDecodeH265DpbSlotInfoEXT); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR: return sizeof(VkVideoSessionCreateInfoKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR: return sizeof(VkVideoSessionParametersCreateInfoKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR: return sizeof(VkVideoSessionParametersUpdateInfoKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR: return sizeof(VkVideoBeginCodingInfoKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR: return sizeof(VkVideoEndCodingInfoKHR); break;
#endif
#ifdef VK_KHR_video_queue
        case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR: return sizeof(VkVideoCodingControlInfoKHR); break;
#endif
#ifdef VK_KHR_video_encode_queue
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR: return sizeof(VkVideoEncodeUsageInfoKHR); break;
#endif
#ifdef VK_KHR_video_encode_queue
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR: return sizeof(VkVideoEncodeInfoKHR); break;
#endif
#ifdef VK_KHR_video_encode_queue
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR: return sizeof(VkVideoEncodeRateControlInfoKHR); break;
#endif
#ifdef VK_KHR_video_encode_queue
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR: return sizeof(VkVideoEncodeRateControlLayerInfoKHR); break;
#endif
#ifdef VK_KHR_video_encode_queue
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR: return sizeof(VkVideoEncodeCapabilitiesKHR); break;
#endif
#ifdef VK_EXT_video_encode_h264
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_EXT: return sizeof(VkVideoEncodeH264CapabilitiesEXT); break;
#endif
#ifdef VK_EXT_video_encode_h264
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_EXT: return sizeof(VkVideoEncodeH264SessionParametersAddInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h264
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_EXT: return sizeof(VkVideoEncodeH264SessionParametersCreateInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h264
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_EXT: return sizeof(VkVideoEncodeH264DpbSlotInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h264
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_VCL_FRAME_INFO_EXT: return sizeof(VkVideoEncodeH264VclFrameInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h264
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_REFERENCE_LISTS_INFO_EXT: return sizeof(VkVideoEncodeH264ReferenceListsInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h264
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_EMIT_PICTURE_PARAMETERS_INFO_EXT: return sizeof(VkVideoEncodeH264EmitPictureParametersInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h264
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_EXT: return sizeof(VkVideoEncodeH264ProfileInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h264
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_EXT: return sizeof(VkVideoEncodeH264NaluSliceInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h264
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_EXT: return sizeof(VkVideoEncodeH264RateControlInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h264
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_EXT: return sizeof(VkVideoEncodeH264RateControlLayerInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h265
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_EXT: return sizeof(VkVideoEncodeH265CapabilitiesEXT); break;
#endif
#ifdef VK_EXT_video_encode_h265
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_EXT: return sizeof(VkVideoEncodeH265SessionParametersAddInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h265
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_EXT: return sizeof(VkVideoEncodeH265SessionParametersCreateInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h265
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_VCL_FRAME_INFO_EXT: return sizeof(VkVideoEncodeH265VclFrameInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h265
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_EMIT_PICTURE_PARAMETERS_INFO_EXT: return sizeof(VkVideoEncodeH265EmitPictureParametersInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h265
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_EXT: return sizeof(VkVideoEncodeH265NaluSliceSegmentInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h265
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_EXT: return sizeof(VkVideoEncodeH265RateControlInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h265
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_EXT: return sizeof(VkVideoEncodeH265RateControlLayerInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h265
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_EXT: return sizeof(VkVideoEncodeH265ProfileInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h265
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_EXT: return sizeof(VkVideoEncodeH265DpbSlotInfoEXT); break;
#endif
#ifdef VK_EXT_video_encode_h265
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_REFERENCE_LISTS_INFO_EXT: return sizeof(VkVideoEncodeH265ReferenceListsInfoEXT); break;
#endif
#ifdef VK_NV_inherited_viewport_scissor
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV: return sizeof(VkPhysicalDeviceInheritedViewportScissorFeaturesNV); break;
#endif
#ifdef VK_NV_inherited_viewport_scissor
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV: return sizeof(VkCommandBufferInheritanceViewportScissorInfoNV); break;
#endif
#ifdef VK_EXT_ycbcr_2plane_444_formats
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT: return sizeof(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT); break;
#endif
#ifdef VK_EXT_provoking_vertex
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT: return sizeof(VkPhysicalDeviceProvokingVertexFeaturesEXT); break;
#endif
#ifdef VK_EXT_provoking_vertex
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceProvokingVertexPropertiesEXT); break;
#endif
#ifdef VK_EXT_provoking_vertex
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT: return sizeof(VkPipelineRasterizationProvokingVertexStateCreateInfoEXT); break;
#endif
#ifdef VK_NVX_binary_import
        case VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX: return sizeof(VkCuModuleCreateInfoNVX); break;
#endif
#ifdef VK_NVX_binary_import
        case VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX: return sizeof(VkCuFunctionCreateInfoNVX); break;
#endif
#ifdef VK_NVX_binary_import
        case VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX: return sizeof(VkCuLaunchInfoNVX); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES: return sizeof(VkPhysicalDeviceShaderIntegerDotProductFeatures); break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES: return sizeof(VkPhysicalDeviceShaderIntegerDotProductProperties); break;
#ifdef VK_EXT_physical_device_drm
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceDrmPropertiesEXT); break;
#endif
#ifdef VK_KHR_fragment_shader_barycentric
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR: return sizeof(VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR); break;
#endif
#ifdef VK_KHR_fragment_shader_barycentric
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR: return sizeof(VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR); break;
#endif
#ifdef VK_NV_ray_tracing_motion_blur
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV: return sizeof(VkPhysicalDeviceRayTracingMotionBlurFeaturesNV); break;
#endif
#ifdef VK_NV_ray_tracing_motion_blur
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV: return sizeof(VkAccelerationStructureGeometryMotionTrianglesDataNV); break;
#endif
#ifdef VK_NV_ray_tracing_motion_blur
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV: return sizeof(VkAccelerationStructureMotionInfoNV); break;
#endif
#ifdef VK_NV_external_memory_rdma
        case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV: return sizeof(VkMemoryGetRemoteAddressInfoNV); break;
#endif
#ifdef VK_FUCHSIA_buffer_collection
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA: return sizeof(VkImportMemoryBufferCollectionFUCHSIA); break;
#endif
#ifdef VK_FUCHSIA_buffer_collection
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA: return sizeof(VkBufferCollectionImageCreateInfoFUCHSIA); break;
#endif
#ifdef VK_FUCHSIA_buffer_collection
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA: return sizeof(VkBufferCollectionBufferCreateInfoFUCHSIA); break;
#endif
#ifdef VK_FUCHSIA_buffer_collection
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA: return sizeof(VkBufferCollectionCreateInfoFUCHSIA); break;
#endif
#ifdef VK_FUCHSIA_buffer_collection
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA: return sizeof(VkBufferCollectionPropertiesFUCHSIA); break;
#endif
#ifdef VK_FUCHSIA_buffer_collection
        case VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA: return sizeof(VkBufferConstraintsInfoFUCHSIA); break;
#endif
#ifdef VK_FUCHSIA_buffer_collection
        case VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA: return sizeof(VkSysmemColorSpaceFUCHSIA); break;
#endif
#ifdef VK_FUCHSIA_buffer_collection
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA: return sizeof(VkImageFormatConstraintsInfoFUCHSIA); break;
#endif
#ifdef VK_FUCHSIA_buffer_collection
        case VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA: return sizeof(VkImageConstraintsInfoFUCHSIA); break;
#endif
#ifdef VK_FUCHSIA_buffer_collection
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA: return sizeof(VkBufferCollectionConstraintsInfoFUCHSIA); break;
#endif
#ifdef VK_EXT_rgba10x6_formats
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT: return sizeof(VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT); break;
#endif
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3: return sizeof(VkFormatProperties3); break;
#ifdef VK_EXT_image_drm_format_modifier
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT: return sizeof(VkDrmFormatModifierPropertiesList2EXT); break;
#endif
#ifdef VK_ANDROID_external_memory_android_hardware_buffer
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID: return sizeof(VkAndroidHardwareBufferFormatProperties2ANDROID); break;
#endif
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO: return sizeof(VkPipelineRenderingCreateInfo); break;
        case VK_STRUCTURE_TYPE_RENDERING_INFO: return sizeof(VkRenderingInfo); break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO: return sizeof(VkRenderingAttachmentInfo); break;
#ifdef VK_KHR_dynamic_rendering
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: return sizeof(VkRenderingFragmentShadingRateAttachmentInfoKHR); break;
#endif
#ifdef VK_KHR_dynamic_rendering
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT: return sizeof(VkRenderingFragmentDensityMapAttachmentInfoEXT); break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES: return sizeof(VkPhysicalDeviceDynamicRenderingFeatures); break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO: return sizeof(VkCommandBufferInheritanceRenderingInfo); break;
#ifdef VK_KHR_dynamic_rendering
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD: return sizeof(VkAttachmentSampleCountInfoAMD); break;
#endif
#ifdef VK_KHR_dynamic_rendering
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX: return sizeof(VkMultiviewPerViewAttributesInfoNVX); break;
#endif
#ifdef VK_EXT_image_view_min_lod
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT: return sizeof(VkPhysicalDeviceImageViewMinLodFeaturesEXT); break;
#endif
#ifdef VK_EXT_image_view_min_lod
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT: return sizeof(VkImageViewMinLodCreateInfoEXT); break;
#endif
#ifdef VK_EXT_rasterization_order_attachment_access
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT: return sizeof(VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT); break;
#endif
#ifdef VK_NV_linear_color_attachment
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV: return sizeof(VkPhysicalDeviceLinearColorAttachmentFeaturesNV); break;
#endif
#ifdef VK_EXT_graphics_pipeline_library
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT: return sizeof(VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT); break;
#endif
#ifdef VK_EXT_graphics_pipeline_library
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT); break;
#endif
#ifdef VK_EXT_graphics_pipeline_library
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT: return sizeof(VkGraphicsPipelineLibraryCreateInfoEXT); break;
#endif
#ifdef VK_VALVE_descriptor_set_host_mapping
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE: return sizeof(VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE); break;
#endif
#ifdef VK_VALVE_descriptor_set_host_mapping
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE: return sizeof(VkDescriptorSetBindingReferenceVALVE); break;
#endif
#ifdef VK_VALVE_descriptor_set_host_mapping
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE: return sizeof(VkDescriptorSetLayoutHostMappingInfoVALVE); break;
#endif
#ifdef VK_EXT_shader_module_identifier
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT: return sizeof(VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT); break;
#endif
#ifdef VK_EXT_shader_module_identifier
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT); break;
#endif
#ifdef VK_EXT_shader_module_identifier
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT: return sizeof(VkPipelineShaderStageModuleIdentifierCreateInfoEXT); break;
#endif
#ifdef VK_EXT_shader_module_identifier
        case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT: return sizeof(VkShaderModuleIdentifierEXT); break;
#endif
#ifdef VK_EXT_image_compression_control
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT: return sizeof(VkImageCompressionControlEXT); break;
#endif
#ifdef VK_EXT_image_compression_control
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT: return sizeof(VkPhysicalDeviceImageCompressionControlFeaturesEXT); break;
#endif
#ifdef VK_EXT_image_compression_control
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT: return sizeof(VkImageCompressionPropertiesEXT); break;
#endif
#ifdef VK_EXT_image_compression_control_swapchain
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT: return sizeof(VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT); break;
#endif
#ifdef VK_EXT_image_compression_control
        case VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_EXT: return sizeof(VkImageSubresource2EXT); break;
#endif
#ifdef VK_EXT_image_compression_control
        case VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_EXT: return sizeof(VkSubresourceLayout2EXT); break;
#endif
#ifdef VK_EXT_subpass_merge_feedback
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT: return sizeof(VkRenderPassCreationControlEXT); break;
#endif
#ifdef VK_EXT_subpass_merge_feedback
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT: return sizeof(VkRenderPassCreationFeedbackCreateInfoEXT); break;
#endif
#ifdef VK_EXT_subpass_merge_feedback
        case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT: return sizeof(VkRenderPassSubpassFeedbackCreateInfoEXT); break;
#endif
#ifdef VK_EXT_subpass_merge_feedback
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT: return sizeof(VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT); break;
#endif
#ifdef VK_EXT_opacity_micromap
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT: return sizeof(VkMicromapBuildInfoEXT); break;
#endif
#ifdef VK_EXT_opacity_micromap
        case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT: return sizeof(VkMicromapCreateInfoEXT); break;
#endif
#ifdef VK_EXT_opacity_micromap
        case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT: return sizeof(VkMicromapVersionInfoEXT); break;
#endif
#ifdef VK_EXT_opacity_micromap
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT: return sizeof(VkCopyMicromapInfoEXT); break;
#endif
#ifdef VK_EXT_opacity_micromap
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT: return sizeof(VkCopyMicromapToMemoryInfoEXT); break;
#endif
#ifdef VK_EXT_opacity_micromap
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT: return sizeof(VkCopyMemoryToMicromapInfoEXT); break;
#endif
#ifdef VK_EXT_opacity_micromap
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT: return sizeof(VkMicromapBuildSizesInfoEXT); break;
#endif
#ifdef VK_EXT_opacity_micromap
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT: return sizeof(VkPhysicalDeviceOpacityMicromapFeaturesEXT); break;
#endif
#ifdef VK_EXT_opacity_micromap
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT: return sizeof(VkPhysicalDeviceOpacityMicromapPropertiesEXT); break;
#endif
#ifdef VK_EXT_opacity_micromap
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT: return sizeof(VkAccelerationStructureTrianglesOpacityMicromapEXT); break;
#endif
#ifdef VK_EXT_pipeline_properties
        case VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT: return sizeof(VkPipelinePropertiesIdentifierEXT); break;
#endif
#ifdef VK_EXT_pipeline_properties
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT: return sizeof(VkPhysicalDevicePipelinePropertiesFeaturesEXT); break;
#endif
#ifdef VK_AMD_shader_early_and_late_fragment_tests
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD: return sizeof(VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD); break;
#endif
#ifdef VK_EXT_metal_objects
        case VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT: return sizeof(VkExportMetalObjectCreateInfoEXT); break;
#endif
#ifdef VK_EXT_metal_objects
        case VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT: return sizeof(VkExportMetalObjectsInfoEXT); break;
#endif
#ifdef VK_EXT_metal_objects
        case VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT: return sizeof(VkExportMetalDeviceInfoEXT); break;
#endif
#ifdef VK_EXT_metal_objects
        case VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT: return sizeof(VkExportMetalCommandQueueInfoEXT); break;
#endif
#ifdef VK_EXT_metal_objects
        case VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT: return sizeof(VkExportMetalBufferInfoEXT); break;
#endif
#ifdef VK_EXT_metal_objects
        case VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT: return sizeof(VkImportMetalBufferInfoEXT); break;
#endif
#ifdef VK_EXT_metal_objects
        case VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT: return sizeof(VkExportMetalTextureInfoEXT); break;
#endif
#ifdef VK_EXT_metal_objects
        case VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT: return sizeof(VkImportMetalTextureInfoEXT); break;
#endif
#ifdef VK_EXT_metal_objects
        case VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT: return sizeof(VkExportMetalIOSurfaceInfoEXT); break;
#endif
#ifdef VK_EXT_metal_objects
        case VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT: return sizeof(VkImportMetalIOSurfaceInfoEXT); break;
#endif
#ifdef VK_EXT_metal_objects
        case VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT: return sizeof(VkExportMetalSharedEventInfoEXT); break;
#endif
#ifdef VK_EXT_metal_objects
        case VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT: return sizeof(VkImportMetalSharedEventInfoEXT); break;
#endif
#ifdef VK_EXT_non_seamless_cube_map
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT: return sizeof(VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT); break;
#endif
#ifdef VK_EXT_pipeline_robustness
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT: return sizeof(VkPhysicalDevicePipelineRobustnessFeaturesEXT); break;
#endif
#ifdef VK_EXT_pipeline_robustness
        case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT: return sizeof(VkPipelineRobustnessCreateInfoEXT); break;
#endif
#ifdef VK_EXT_pipeline_robustness
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT: return sizeof(VkPhysicalDevicePipelineRobustnessPropertiesEXT); break;
#endif
#ifdef VK_QCOM_image_processing
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM: return sizeof(VkImageViewSampleWeightCreateInfoQCOM); break;
#endif
#ifdef VK_QCOM_image_processing
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM: return sizeof(VkPhysicalDeviceImageProcessingFeaturesQCOM); break;
#endif
#ifdef VK_QCOM_image_processing
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM: return sizeof(VkPhysicalDeviceImageProcessingPropertiesQCOM); break;
#endif
#ifdef VK_QCOM_tile_properties
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM: return sizeof(VkPhysicalDeviceTilePropertiesFeaturesQCOM); break;
#endif
#ifdef VK_QCOM_tile_properties
        case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM: return sizeof(VkTilePropertiesQCOM); break;
#endif
#ifdef VK_SEC_amigo_profiling
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC: return sizeof(VkPhysicalDeviceAmigoProfilingFeaturesSEC); break;
#endif
#ifdef VK_SEC_amigo_profiling
        case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC: return sizeof(VkAmigoProfilingSubmitInfoSEC); break;
#endif
#ifdef VK_EXT_attachment_feedback_loop_layout
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT: return sizeof(VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT); break;
#endif
#ifdef VK_EXT_depth_clamp_zero_one
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT: return sizeof(VkPhysicalDeviceDepthClampZeroOneFeaturesEXT); break;
#endif
#ifdef VK_EXT_device_address_binding_report
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT: return sizeof(VkPhysicalDeviceAddressBindingReportFeaturesEXT); break;
#endif
#ifdef VK_EXT_device_address_binding_report
        case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT: return sizeof(VkDeviceAddressBindingCallbackDataEXT); break;
#endif
#ifdef VK_NV_optical_flow
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV: return sizeof(VkPhysicalDeviceOpticalFlowFeaturesNV); break;
#endif
#ifdef VK_NV_optical_flow
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV: return sizeof(VkPhysicalDeviceOpticalFlowPropertiesNV); break;
#endif
#ifdef VK_NV_optical_flow
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV: return sizeof(VkOpticalFlowImageFormatInfoNV); break;
#endif
#ifdef VK_NV_optical_flow
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV: return sizeof(VkOpticalFlowImageFormatPropertiesNV); break;
#endif
#ifdef VK_NV_optical_flow
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV: return sizeof(VkOpticalFlowSessionCreateInfoNV); break;
#endif
#ifdef VK_NV_optical_flow
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV: return sizeof(VkOpticalFlowSessionCreatePrivateDataInfoNV); break;
#endif
#ifdef VK_NV_optical_flow
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV: return sizeof(VkOpticalFlowExecuteInfoNV); break;
#endif
#ifdef VK_EXT_device_fault
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT: return sizeof(VkPhysicalDeviceFaultFeaturesEXT); break;
#endif
#ifdef VK_EXT_device_fault
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT: return sizeof(VkDeviceFaultCountsEXT); break;
#endif
#ifdef VK_EXT_device_fault
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT: return sizeof(VkDeviceFaultInfoEXT); break;
#endif
#ifdef VK_ARM_shader_core_builtins
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM: return sizeof(VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM); break;
#endif
#ifdef VK_ARM_shader_core_builtins
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM: return sizeof(VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM); break;
#endif
#ifdef VK_NV_ray_tracing_invocation_reorder
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV: return sizeof(VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV); break;
#endif
#ifdef VK_NV_ray_tracing_invocation_reorder
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV: return sizeof(VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV); break;
#endif
        //default: 
    };
    return 0ull;
};
    