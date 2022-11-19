
import {default as V} from "./vulkan-API.js";
import {default as E} from "./vulkan-enums.js";
import {default as C} from "./typed.js";
const callof = (fn)=>{ return fn ? fn() : 0; };

const VK_MAKE_API_VERSION = (variant, major, minor, patch) => {
    return ((((variant)) << 29) | (((major)) << 22) | (((minor)) << 12) | ((patch)));
};

//

const VkBaseOutStructure = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBaseOutStructure", {
    sType: "u32("+(V.VkBaseOutStructure_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBaseOutStructure_pNext_offsetof||0)+")",
}, (V.VkBaseOutStructure_sizeof||0))));


const VkBaseInStructure = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBaseInStructure", {
    sType: "u32("+(V.VkBaseInStructure_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBaseInStructure_pNext_offsetof||0)+")",
}, (V.VkBaseInStructure_sizeof||0))));


const VkOffset2D = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkOffset2D", {
    x: "i32("+(V.VkOffset2D_x_offsetof||0)+")",
    y: "i32("+(V.VkOffset2D_y_offsetof||0)+")",
}, (V.VkOffset2D_sizeof||0))));


const VkOffset3D = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkOffset3D", {
    x: "i32("+(V.VkOffset3D_x_offsetof||0)+")",
    y: "i32("+(V.VkOffset3D_y_offsetof||0)+")",
    z: "i32("+(V.VkOffset3D_z_offsetof||0)+")",
}, (V.VkOffset3D_sizeof||0))));


const VkExtent2D = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExtent2D", {
    width: "u32("+(V.VkExtent2D_width_offsetof||0)+")",
    height: "u32("+(V.VkExtent2D_height_offsetof||0)+")",
}, (V.VkExtent2D_sizeof||0))));


const VkExtent3D = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExtent3D", {
    width: "u32("+(V.VkExtent3D_width_offsetof||0)+")",
    height: "u32("+(V.VkExtent3D_height_offsetof||0)+")",
    depth: "u32("+(V.VkExtent3D_depth_offsetof||0)+")",
}, (V.VkExtent3D_sizeof||0))));


const VkViewport = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkViewport", {
    x: "f32("+(V.VkViewport_x_offsetof||0)+")",
    y: "f32("+(V.VkViewport_y_offsetof||0)+")",
    width: "f32("+(V.VkViewport_width_offsetof||0)+")",
    height: "f32("+(V.VkViewport_height_offsetof||0)+")",
    minDepth: "f32("+(V.VkViewport_minDepth_offsetof||0)+")",
    maxDepth: "f32("+(V.VkViewport_maxDepth_offsetof||0)+")",
}, (V.VkViewport_sizeof||0))));


const VkRect2D = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRect2D", {
    offset: "VkOffset2D("+(V.VkRect2D_offset_offsetof||0)+")",
    extent: "VkExtent2D("+(V.VkRect2D_extent_offsetof||0)+")",
}, (V.VkRect2D_sizeof||0))));


const VkClearRect = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkClearRect", {
    rect: "VkRect2D("+(V.VkClearRect_rect_offsetof||0)+")",
    baseArrayLayer: "u32("+(V.VkClearRect_baseArrayLayer_offsetof||0)+")",
    layerCount: "u32("+(V.VkClearRect_layerCount_offsetof||0)+")",
}, (V.VkClearRect_sizeof||0))));


const VkComponentMapping = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkComponentMapping", {
    r: "u32("+(V.VkComponentMapping_r_offsetof||0)+")",
    g: "u32("+(V.VkComponentMapping_g_offsetof||0)+")",
    b: "u32("+(V.VkComponentMapping_b_offsetof||0)+")",
    a: "u32("+(V.VkComponentMapping_a_offsetof||0)+")",
}, (V.VkComponentMapping_sizeof||0))));


const VkPhysicalDeviceProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceProperties", {
    apiVersion: "u32("+(V.VkPhysicalDeviceProperties_apiVersion_offsetof||0)+")",
    driverVersion: "u32("+(V.VkPhysicalDeviceProperties_driverVersion_offsetof||0)+")",
    vendorID: "u32("+(V.VkPhysicalDeviceProperties_vendorID_offsetof||0)+")",
    deviceID: "u32("+(V.VkPhysicalDeviceProperties_deviceID_offsetof||0)+")",
    deviceType: "u32("+(V.VkPhysicalDeviceProperties_deviceType_offsetof||0)+")",
    deviceName: "u8["+(E.VK_MAX_PHYSICAL_DEVICE_NAME_SIZE||1)+"]("+(V.VkPhysicalDeviceProperties_deviceName_offsetof||0)+")",
    pipelineCacheUUID: "u8["+(E.VK_UUID_SIZE||1)+"]("+(V.VkPhysicalDeviceProperties_pipelineCacheUUID_offsetof||0)+")",
    limits: "u32("+(V.VkPhysicalDeviceProperties_limits_offsetof||0)+")",
    sparseProperties: "u32("+(V.VkPhysicalDeviceProperties_sparseProperties_offsetof||0)+")",
}, (V.VkPhysicalDeviceProperties_sizeof||0))));


const VkExtensionProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExtensionProperties", {
    extensionName: "u8["+(E.VK_MAX_EXTENSION_NAME_SIZE||1)+"]("+(V.VkExtensionProperties_extensionName_offsetof||0)+")",
    specVersion: "u32("+(V.VkExtensionProperties_specVersion_offsetof||0)+")",
}, (V.VkExtensionProperties_sizeof||0))));


const VkLayerProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkLayerProperties", {
    layerName: "u8["+(E.VK_MAX_EXTENSION_NAME_SIZE||1)+"]("+(V.VkLayerProperties_layerName_offsetof||0)+")",
    specVersion: "u32("+(V.VkLayerProperties_specVersion_offsetof||0)+")",
    implementationVersion: "u32("+(V.VkLayerProperties_implementationVersion_offsetof||0)+")",
    description: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkLayerProperties_description_offsetof||0)+")",
}, (V.VkLayerProperties_sizeof||0))));


const VkApplicationInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkApplicationInfo", {
    sType: "u32("+(V.VkApplicationInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkApplicationInfo_pNext_offsetof||0)+")",
    pApplicationName: "u64("+(V.VkApplicationInfo_pApplicationName_offsetof||0)+")",
    applicationVersion: "u32("+(V.VkApplicationInfo_applicationVersion_offsetof||0)+")",
    pEngineName: "u64("+(V.VkApplicationInfo_pEngineName_offsetof||0)+")",
    engineVersion: "u32("+(V.VkApplicationInfo_engineVersion_offsetof||0)+")",
    apiVersion: "u32("+(V.VkApplicationInfo_apiVersion_offsetof||0)+")",
}, (V.VkApplicationInfo_sizeof||0))));


const VkAllocationCallbacks = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAllocationCallbacks", {
    pUserData: "u64("+(V.VkAllocationCallbacks_pUserData_offsetof||0)+")",
    pfnAllocation: "u32("+(V.VkAllocationCallbacks_pfnAllocation_offsetof||0)+")",
    pfnReallocation: "u32("+(V.VkAllocationCallbacks_pfnReallocation_offsetof||0)+")",
    pfnFree: "u32("+(V.VkAllocationCallbacks_pfnFree_offsetof||0)+")",
    pfnInternalAllocation: "u32("+(V.VkAllocationCallbacks_pfnInternalAllocation_offsetof||0)+")",
    pfnInternalFree: "u32("+(V.VkAllocationCallbacks_pfnInternalFree_offsetof||0)+")",
}, (V.VkAllocationCallbacks_sizeof||0))));


const VkDeviceQueueCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceQueueCreateInfo", {
    sType: "u32("+(V.VkDeviceQueueCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceQueueCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDeviceQueueCreateInfo_flags_offsetof||0)+")",
    queueFamilyIndex: "u32("+(V.VkDeviceQueueCreateInfo_queueFamilyIndex_offsetof||0)+")",
    queueCount: "u32("+(V.VkDeviceQueueCreateInfo_queueCount_offsetof||0)+")",
    pQueuePriorities: "u64("+(V.VkDeviceQueueCreateInfo_pQueuePriorities_offsetof||0)+")",
}, (V.VkDeviceQueueCreateInfo_sizeof||0))));


const VkDeviceCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceCreateInfo", {
    sType: "u32("+(V.VkDeviceCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDeviceCreateInfo_flags_offsetof||0)+")",
    queueCreateInfoCount: "u32("+(V.VkDeviceCreateInfo_queueCreateInfoCount_offsetof||0)+")",
    pQueueCreateInfos: "u64("+(V.VkDeviceCreateInfo_pQueueCreateInfos_offsetof||0)+")",
    enabledLayerCount: "u32("+(V.VkDeviceCreateInfo_enabledLayerCount_offsetof||0)+")",
    ppEnabledLayerNames: "u64("+(V.VkDeviceCreateInfo_ppEnabledLayerNames_offsetof||0)+")",
    enabledExtensionCount: "u32("+(V.VkDeviceCreateInfo_enabledExtensionCount_offsetof||0)+")",
    ppEnabledExtensionNames: "u64("+(V.VkDeviceCreateInfo_ppEnabledExtensionNames_offsetof||0)+")",
    pEnabledFeatures: "u64("+(V.VkDeviceCreateInfo_pEnabledFeatures_offsetof||0)+")",
}, (V.VkDeviceCreateInfo_sizeof||0))));


const VkInstanceCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkInstanceCreateInfo", {
    sType: "u32("+(V.VkInstanceCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkInstanceCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkInstanceCreateInfo_flags_offsetof||0)+")",
    pApplicationInfo: "u64("+(V.VkInstanceCreateInfo_pApplicationInfo_offsetof||0)+")",
    enabledLayerCount: "u32("+(V.VkInstanceCreateInfo_enabledLayerCount_offsetof||0)+")",
    ppEnabledLayerNames: "u64("+(V.VkInstanceCreateInfo_ppEnabledLayerNames_offsetof||0)+")",
    enabledExtensionCount: "u32("+(V.VkInstanceCreateInfo_enabledExtensionCount_offsetof||0)+")",
    ppEnabledExtensionNames: "u64("+(V.VkInstanceCreateInfo_ppEnabledExtensionNames_offsetof||0)+")",
}, (V.VkInstanceCreateInfo_sizeof||0))));


const VkQueueFamilyProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkQueueFamilyProperties", {
    queueFlags: "u32("+(V.VkQueueFamilyProperties_queueFlags_offsetof||0)+")",
    queueCount: "u32("+(V.VkQueueFamilyProperties_queueCount_offsetof||0)+")",
    timestampValidBits: "u32("+(V.VkQueueFamilyProperties_timestampValidBits_offsetof||0)+")",
    minImageTransferGranularity: "u32("+(V.VkQueueFamilyProperties_minImageTransferGranularity_offsetof||0)+")",
}, (V.VkQueueFamilyProperties_sizeof||0))));


const VkPhysicalDeviceMemoryProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMemoryProperties", {
    memoryTypeCount: "u32("+(V.VkPhysicalDeviceMemoryProperties_memoryTypeCount_offsetof||0)+")",
    memoryTypes: "u32["+(E.VK_MAX_MEMORY_TYPES||1)+"]("+(V.VkPhysicalDeviceMemoryProperties_memoryTypes_offsetof||0)+")",
    memoryHeapCount: "u32("+(V.VkPhysicalDeviceMemoryProperties_memoryHeapCount_offsetof||0)+")",
    memoryHeaps: "u32["+(E.VK_MAX_MEMORY_HEAPS||1)+"]("+(V.VkPhysicalDeviceMemoryProperties_memoryHeaps_offsetof||0)+")",
}, (V.VkPhysicalDeviceMemoryProperties_sizeof||0))));


const VkMemoryAllocateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryAllocateInfo", {
    sType: "u32("+(V.VkMemoryAllocateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryAllocateInfo_pNext_offsetof||0)+")",
    allocationSize: "u64("+(V.VkMemoryAllocateInfo_allocationSize_offsetof||0)+")",
    memoryTypeIndex: "u32("+(V.VkMemoryAllocateInfo_memoryTypeIndex_offsetof||0)+")",
}, (V.VkMemoryAllocateInfo_sizeof||0))));


const VkMemoryRequirements = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryRequirements", {
    size: "u64("+(V.VkMemoryRequirements_size_offsetof||0)+")",
    alignment: "u64("+(V.VkMemoryRequirements_alignment_offsetof||0)+")",
    memoryTypeBits: "u32("+(V.VkMemoryRequirements_memoryTypeBits_offsetof||0)+")",
}, (V.VkMemoryRequirements_sizeof||0))));


const VkSparseImageFormatProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSparseImageFormatProperties", {
    aspectMask: "u32("+(V.VkSparseImageFormatProperties_aspectMask_offsetof||0)+")",
    imageGranularity: "u32("+(V.VkSparseImageFormatProperties_imageGranularity_offsetof||0)+")",
    flags: "u32("+(V.VkSparseImageFormatProperties_flags_offsetof||0)+")",
}, (V.VkSparseImageFormatProperties_sizeof||0))));


const VkSparseImageMemoryRequirements = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSparseImageMemoryRequirements", {
    formatProperties: "u32("+(V.VkSparseImageMemoryRequirements_formatProperties_offsetof||0)+")",
    imageMipTailFirstLod: "u32("+(V.VkSparseImageMemoryRequirements_imageMipTailFirstLod_offsetof||0)+")",
    imageMipTailSize: "u64("+(V.VkSparseImageMemoryRequirements_imageMipTailSize_offsetof||0)+")",
    imageMipTailOffset: "u64("+(V.VkSparseImageMemoryRequirements_imageMipTailOffset_offsetof||0)+")",
    imageMipTailStride: "u64("+(V.VkSparseImageMemoryRequirements_imageMipTailStride_offsetof||0)+")",
}, (V.VkSparseImageMemoryRequirements_sizeof||0))));


const VkMemoryType = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryType", {
    propertyFlags: "u32("+(V.VkMemoryType_propertyFlags_offsetof||0)+")",
    heapIndex: "u32("+(V.VkMemoryType_heapIndex_offsetof||0)+")",
}, (V.VkMemoryType_sizeof||0))));


const VkMemoryHeap = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryHeap", {
    size: "u64("+(V.VkMemoryHeap_size_offsetof||0)+")",
    flags: "u32("+(V.VkMemoryHeap_flags_offsetof||0)+")",
}, (V.VkMemoryHeap_sizeof||0))));


const VkMappedMemoryRange = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMappedMemoryRange", {
    sType: "u32("+(V.VkMappedMemoryRange_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMappedMemoryRange_pNext_offsetof||0)+")",
    memory: "u64("+(V.VkMappedMemoryRange_memory_offsetof||0)+")",
    offset: "u64("+(V.VkMappedMemoryRange_offset_offsetof||0)+")",
    size: "u64("+(V.VkMappedMemoryRange_size_offsetof||0)+")",
}, (V.VkMappedMemoryRange_sizeof||0))));


const VkFormatProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkFormatProperties", {
    linearTilingFeatures: "u32("+(V.VkFormatProperties_linearTilingFeatures_offsetof||0)+")",
    optimalTilingFeatures: "u32("+(V.VkFormatProperties_optimalTilingFeatures_offsetof||0)+")",
    bufferFeatures: "u32("+(V.VkFormatProperties_bufferFeatures_offsetof||0)+")",
}, (V.VkFormatProperties_sizeof||0))));


const VkImageFormatProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageFormatProperties", {
    maxExtent: "u32("+(V.VkImageFormatProperties_maxExtent_offsetof||0)+")",
    maxMipLevels: "u32("+(V.VkImageFormatProperties_maxMipLevels_offsetof||0)+")",
    maxArrayLayers: "u32("+(V.VkImageFormatProperties_maxArrayLayers_offsetof||0)+")",
    sampleCounts: "u32("+(V.VkImageFormatProperties_sampleCounts_offsetof||0)+")",
    maxResourceSize: "u64("+(V.VkImageFormatProperties_maxResourceSize_offsetof||0)+")",
}, (V.VkImageFormatProperties_sizeof||0))));


const VkDescriptorBufferInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorBufferInfo", {
    buffer: "u64("+(V.VkDescriptorBufferInfo_buffer_offsetof||0)+")",
    offset: "u64("+(V.VkDescriptorBufferInfo_offset_offsetof||0)+")",
    range: "u64("+(V.VkDescriptorBufferInfo_range_offsetof||0)+")",
}, (V.VkDescriptorBufferInfo_sizeof||0))));


const VkDescriptorImageInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorImageInfo", {
    sampler: "u64("+(V.VkDescriptorImageInfo_sampler_offsetof||0)+")",
    imageView: "u32("+(V.VkDescriptorImageInfo_imageView_offsetof||0)+")",
    imageLayout: "u32("+(V.VkDescriptorImageInfo_imageLayout_offsetof||0)+")",
}, (V.VkDescriptorImageInfo_sizeof||0))));


const VkWriteDescriptorSet = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkWriteDescriptorSet", {
    sType: "u32("+(V.VkWriteDescriptorSet_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkWriteDescriptorSet_pNext_offsetof||0)+")",
    dstSet: "u32("+(V.VkWriteDescriptorSet_dstSet_offsetof||0)+")",
    dstBinding: "u32("+(V.VkWriteDescriptorSet_dstBinding_offsetof||0)+")",
    dstArrayElement: "u32("+(V.VkWriteDescriptorSet_dstArrayElement_offsetof||0)+")",
    descriptorCount: "u32("+(V.VkWriteDescriptorSet_descriptorCount_offsetof||0)+")",
    descriptorType: "u32("+(V.VkWriteDescriptorSet_descriptorType_offsetof||0)+")",
    pImageInfo: "u64("+(V.VkWriteDescriptorSet_pImageInfo_offsetof||0)+")",
    pBufferInfo: "u64("+(V.VkWriteDescriptorSet_pBufferInfo_offsetof||0)+")",
    pTexelBufferView: "u64("+(V.VkWriteDescriptorSet_pTexelBufferView_offsetof||0)+")",
}, (V.VkWriteDescriptorSet_sizeof||0))));


const VkCopyDescriptorSet = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyDescriptorSet", {
    sType: "u32("+(V.VkCopyDescriptorSet_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCopyDescriptorSet_pNext_offsetof||0)+")",
    srcSet: "u32("+(V.VkCopyDescriptorSet_srcSet_offsetof||0)+")",
    srcBinding: "u32("+(V.VkCopyDescriptorSet_srcBinding_offsetof||0)+")",
    srcArrayElement: "u32("+(V.VkCopyDescriptorSet_srcArrayElement_offsetof||0)+")",
    dstSet: "u32("+(V.VkCopyDescriptorSet_dstSet_offsetof||0)+")",
    dstBinding: "u32("+(V.VkCopyDescriptorSet_dstBinding_offsetof||0)+")",
    dstArrayElement: "u32("+(V.VkCopyDescriptorSet_dstArrayElement_offsetof||0)+")",
    descriptorCount: "u32("+(V.VkCopyDescriptorSet_descriptorCount_offsetof||0)+")",
}, (V.VkCopyDescriptorSet_sizeof||0))));


const VkBufferCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferCreateInfo", {
    sType: "u32("+(V.VkBufferCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkBufferCreateInfo_flags_offsetof||0)+")",
    size: "u64("+(V.VkBufferCreateInfo_size_offsetof||0)+")",
    usage: "u32("+(V.VkBufferCreateInfo_usage_offsetof||0)+")",
    sharingMode: "u32("+(V.VkBufferCreateInfo_sharingMode_offsetof||0)+")",
    queueFamilyIndexCount: "u32("+(V.VkBufferCreateInfo_queueFamilyIndexCount_offsetof||0)+")",
    pQueueFamilyIndices: "u64("+(V.VkBufferCreateInfo_pQueueFamilyIndices_offsetof||0)+")",
}, (V.VkBufferCreateInfo_sizeof||0))));


const VkBufferViewCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferViewCreateInfo", {
    sType: "u32("+(V.VkBufferViewCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferViewCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkBufferViewCreateInfo_flags_offsetof||0)+")",
    buffer: "u64("+(V.VkBufferViewCreateInfo_buffer_offsetof||0)+")",
    format: "u32("+(V.VkBufferViewCreateInfo_format_offsetof||0)+")",
    offset: "u64("+(V.VkBufferViewCreateInfo_offset_offsetof||0)+")",
    range: "u64("+(V.VkBufferViewCreateInfo_range_offsetof||0)+")",
}, (V.VkBufferViewCreateInfo_sizeof||0))));


const VkImageSubresource = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageSubresource", {
    aspectMask: "u32("+(V.VkImageSubresource_aspectMask_offsetof||0)+")",
    mipLevel: "u32("+(V.VkImageSubresource_mipLevel_offsetof||0)+")",
    arrayLayer: "u32("+(V.VkImageSubresource_arrayLayer_offsetof||0)+")",
}, (V.VkImageSubresource_sizeof||0))));


const VkImageSubresourceLayers = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageSubresourceLayers", {
    aspectMask: "u32("+(V.VkImageSubresourceLayers_aspectMask_offsetof||0)+")",
    mipLevel: "u32("+(V.VkImageSubresourceLayers_mipLevel_offsetof||0)+")",
    baseArrayLayer: "u32("+(V.VkImageSubresourceLayers_baseArrayLayer_offsetof||0)+")",
    layerCount: "u32("+(V.VkImageSubresourceLayers_layerCount_offsetof||0)+")",
}, (V.VkImageSubresourceLayers_sizeof||0))));


const VkImageSubresourceRange = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageSubresourceRange", {
    aspectMask: "u32("+(V.VkImageSubresourceRange_aspectMask_offsetof||0)+")",
    baseMipLevel: "u32("+(V.VkImageSubresourceRange_baseMipLevel_offsetof||0)+")",
    levelCount: "u32("+(V.VkImageSubresourceRange_levelCount_offsetof||0)+")",
    baseArrayLayer: "u32("+(V.VkImageSubresourceRange_baseArrayLayer_offsetof||0)+")",
    layerCount: "u32("+(V.VkImageSubresourceRange_layerCount_offsetof||0)+")",
}, (V.VkImageSubresourceRange_sizeof||0))));


const VkMemoryBarrier = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryBarrier", {
    sType: "u32("+(V.VkMemoryBarrier_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryBarrier_pNext_offsetof||0)+")",
    srcAccessMask: "u32("+(V.VkMemoryBarrier_srcAccessMask_offsetof||0)+")",
    dstAccessMask: "u32("+(V.VkMemoryBarrier_dstAccessMask_offsetof||0)+")",
}, (V.VkMemoryBarrier_sizeof||0))));


const VkBufferMemoryBarrier = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferMemoryBarrier", {
    sType: "u32("+(V.VkBufferMemoryBarrier_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferMemoryBarrier_pNext_offsetof||0)+")",
    srcAccessMask: "u32("+(V.VkBufferMemoryBarrier_srcAccessMask_offsetof||0)+")",
    dstAccessMask: "u32("+(V.VkBufferMemoryBarrier_dstAccessMask_offsetof||0)+")",
    srcQueueFamilyIndex: "u32("+(V.VkBufferMemoryBarrier_srcQueueFamilyIndex_offsetof||0)+")",
    dstQueueFamilyIndex: "u32("+(V.VkBufferMemoryBarrier_dstQueueFamilyIndex_offsetof||0)+")",
    buffer: "u64("+(V.VkBufferMemoryBarrier_buffer_offsetof||0)+")",
    offset: "u64("+(V.VkBufferMemoryBarrier_offset_offsetof||0)+")",
    size: "u64("+(V.VkBufferMemoryBarrier_size_offsetof||0)+")",
}, (V.VkBufferMemoryBarrier_sizeof||0))));


const VkImageMemoryBarrier = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageMemoryBarrier", {
    sType: "u32("+(V.VkImageMemoryBarrier_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageMemoryBarrier_pNext_offsetof||0)+")",
    srcAccessMask: "u32("+(V.VkImageMemoryBarrier_srcAccessMask_offsetof||0)+")",
    dstAccessMask: "u32("+(V.VkImageMemoryBarrier_dstAccessMask_offsetof||0)+")",
    oldLayout: "u32("+(V.VkImageMemoryBarrier_oldLayout_offsetof||0)+")",
    newLayout: "u32("+(V.VkImageMemoryBarrier_newLayout_offsetof||0)+")",
    srcQueueFamilyIndex: "u32("+(V.VkImageMemoryBarrier_srcQueueFamilyIndex_offsetof||0)+")",
    dstQueueFamilyIndex: "u32("+(V.VkImageMemoryBarrier_dstQueueFamilyIndex_offsetof||0)+")",
    image: "u64("+(V.VkImageMemoryBarrier_image_offsetof||0)+")",
    subresourceRange: "u32("+(V.VkImageMemoryBarrier_subresourceRange_offsetof||0)+")",
}, (V.VkImageMemoryBarrier_sizeof||0))));


const VkImageCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageCreateInfo", {
    sType: "u32("+(V.VkImageCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkImageCreateInfo_flags_offsetof||0)+")",
    imageType: "u32("+(V.VkImageCreateInfo_imageType_offsetof||0)+")",
    format: "u32("+(V.VkImageCreateInfo_format_offsetof||0)+")",
    extent: "u32("+(V.VkImageCreateInfo_extent_offsetof||0)+")",
    mipLevels: "u32("+(V.VkImageCreateInfo_mipLevels_offsetof||0)+")",
    arrayLayers: "u32("+(V.VkImageCreateInfo_arrayLayers_offsetof||0)+")",
    samples: "u32("+(V.VkImageCreateInfo_samples_offsetof||0)+")",
    tiling: "u32("+(V.VkImageCreateInfo_tiling_offsetof||0)+")",
    usage: "u32("+(V.VkImageCreateInfo_usage_offsetof||0)+")",
    sharingMode: "u32("+(V.VkImageCreateInfo_sharingMode_offsetof||0)+")",
    queueFamilyIndexCount: "u32("+(V.VkImageCreateInfo_queueFamilyIndexCount_offsetof||0)+")",
    pQueueFamilyIndices: "u64("+(V.VkImageCreateInfo_pQueueFamilyIndices_offsetof||0)+")",
    initialLayout: "u32("+(V.VkImageCreateInfo_initialLayout_offsetof||0)+")",
}, (V.VkImageCreateInfo_sizeof||0))));


const VkSubresourceLayout = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubresourceLayout", {
    offset: "u64("+(V.VkSubresourceLayout_offset_offsetof||0)+")",
    size: "u64("+(V.VkSubresourceLayout_size_offsetof||0)+")",
    rowPitch: "u64("+(V.VkSubresourceLayout_rowPitch_offsetof||0)+")",
    arrayPitch: "u64("+(V.VkSubresourceLayout_arrayPitch_offsetof||0)+")",
    depthPitch: "u64("+(V.VkSubresourceLayout_depthPitch_offsetof||0)+")",
}, (V.VkSubresourceLayout_sizeof||0))));


const VkImageViewCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageViewCreateInfo", {
    sType: "u32("+(V.VkImageViewCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageViewCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkImageViewCreateInfo_flags_offsetof||0)+")",
    image: "u64("+(V.VkImageViewCreateInfo_image_offsetof||0)+")",
    viewType: "u32("+(V.VkImageViewCreateInfo_viewType_offsetof||0)+")",
    format: "u32("+(V.VkImageViewCreateInfo_format_offsetof||0)+")",
    components: "u32("+(V.VkImageViewCreateInfo_components_offsetof||0)+")",
    subresourceRange: "u32("+(V.VkImageViewCreateInfo_subresourceRange_offsetof||0)+")",
}, (V.VkImageViewCreateInfo_sizeof||0))));


const VkBufferCopy = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferCopy", {
    srcOffset: "u64("+(V.VkBufferCopy_srcOffset_offsetof||0)+")",
    dstOffset: "u64("+(V.VkBufferCopy_dstOffset_offsetof||0)+")",
    size: "u64("+(V.VkBufferCopy_size_offsetof||0)+")",
}, (V.VkBufferCopy_sizeof||0))));


const VkSparseMemoryBind = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSparseMemoryBind", {
    resourceOffset: "u64("+(V.VkSparseMemoryBind_resourceOffset_offsetof||0)+")",
    size: "u64("+(V.VkSparseMemoryBind_size_offsetof||0)+")",
    memory: "u64("+(V.VkSparseMemoryBind_memory_offsetof||0)+")",
    memoryOffset: "u64("+(V.VkSparseMemoryBind_memoryOffset_offsetof||0)+")",
    flags: "u32("+(V.VkSparseMemoryBind_flags_offsetof||0)+")",
}, (V.VkSparseMemoryBind_sizeof||0))));


const VkSparseImageMemoryBind = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSparseImageMemoryBind", {
    subresource: "u32("+(V.VkSparseImageMemoryBind_subresource_offsetof||0)+")",
    offset: "u32("+(V.VkSparseImageMemoryBind_offset_offsetof||0)+")",
    extent: "u32("+(V.VkSparseImageMemoryBind_extent_offsetof||0)+")",
    memory: "u64("+(V.VkSparseImageMemoryBind_memory_offsetof||0)+")",
    memoryOffset: "u64("+(V.VkSparseImageMemoryBind_memoryOffset_offsetof||0)+")",
    flags: "u32("+(V.VkSparseImageMemoryBind_flags_offsetof||0)+")",
}, (V.VkSparseImageMemoryBind_sizeof||0))));


const VkSparseBufferMemoryBindInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSparseBufferMemoryBindInfo", {
    buffer: "u64("+(V.VkSparseBufferMemoryBindInfo_buffer_offsetof||0)+")",
    bindCount: "u32("+(V.VkSparseBufferMemoryBindInfo_bindCount_offsetof||0)+")",
    pBinds: "u64("+(V.VkSparseBufferMemoryBindInfo_pBinds_offsetof||0)+")",
}, (V.VkSparseBufferMemoryBindInfo_sizeof||0))));


const VkSparseImageOpaqueMemoryBindInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSparseImageOpaqueMemoryBindInfo", {
    image: "u64("+(V.VkSparseImageOpaqueMemoryBindInfo_image_offsetof||0)+")",
    bindCount: "u32("+(V.VkSparseImageOpaqueMemoryBindInfo_bindCount_offsetof||0)+")",
    pBinds: "u64("+(V.VkSparseImageOpaqueMemoryBindInfo_pBinds_offsetof||0)+")",
}, (V.VkSparseImageOpaqueMemoryBindInfo_sizeof||0))));


const VkSparseImageMemoryBindInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSparseImageMemoryBindInfo", {
    image: "u64("+(V.VkSparseImageMemoryBindInfo_image_offsetof||0)+")",
    bindCount: "u32("+(V.VkSparseImageMemoryBindInfo_bindCount_offsetof||0)+")",
    pBinds: "u64("+(V.VkSparseImageMemoryBindInfo_pBinds_offsetof||0)+")",
}, (V.VkSparseImageMemoryBindInfo_sizeof||0))));


const VkBindSparseInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBindSparseInfo", {
    sType: "u32("+(V.VkBindSparseInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBindSparseInfo_pNext_offsetof||0)+")",
    waitSemaphoreCount: "u32("+(V.VkBindSparseInfo_waitSemaphoreCount_offsetof||0)+")",
    pWaitSemaphores: "u64("+(V.VkBindSparseInfo_pWaitSemaphores_offsetof||0)+")",
    bufferBindCount: "u32("+(V.VkBindSparseInfo_bufferBindCount_offsetof||0)+")",
    pBufferBinds: "u64("+(V.VkBindSparseInfo_pBufferBinds_offsetof||0)+")",
    imageOpaqueBindCount: "u32("+(V.VkBindSparseInfo_imageOpaqueBindCount_offsetof||0)+")",
    pImageOpaqueBinds: "u64("+(V.VkBindSparseInfo_pImageOpaqueBinds_offsetof||0)+")",
    imageBindCount: "u32("+(V.VkBindSparseInfo_imageBindCount_offsetof||0)+")",
    pImageBinds: "u64("+(V.VkBindSparseInfo_pImageBinds_offsetof||0)+")",
    signalSemaphoreCount: "u32("+(V.VkBindSparseInfo_signalSemaphoreCount_offsetof||0)+")",
    pSignalSemaphores: "u64("+(V.VkBindSparseInfo_pSignalSemaphores_offsetof||0)+")",
}, (V.VkBindSparseInfo_sizeof||0))));


const VkImageCopy = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageCopy", {
    srcSubresource: "u32("+(V.VkImageCopy_srcSubresource_offsetof||0)+")",
    srcOffset: "u32("+(V.VkImageCopy_srcOffset_offsetof||0)+")",
    dstSubresource: "u32("+(V.VkImageCopy_dstSubresource_offsetof||0)+")",
    dstOffset: "u32("+(V.VkImageCopy_dstOffset_offsetof||0)+")",
    extent: "u32("+(V.VkImageCopy_extent_offsetof||0)+")",
}, (V.VkImageCopy_sizeof||0))));


const VkImageBlit = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageBlit", {
    srcSubresource: "u32("+(V.VkImageBlit_srcSubresource_offsetof||0)+")",
    srcOffsets: "u32[2]("+(V.VkImageBlit_srcOffsets_offsetof||0)+")",
    dstSubresource: "u32("+(V.VkImageBlit_dstSubresource_offsetof||0)+")",
    dstOffsets: "u32[2]("+(V.VkImageBlit_dstOffsets_offsetof||0)+")",
}, (V.VkImageBlit_sizeof||0))));


const VkBufferImageCopy = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferImageCopy", {
    bufferOffset: "u64("+(V.VkBufferImageCopy_bufferOffset_offsetof||0)+")",
    bufferRowLength: "u32("+(V.VkBufferImageCopy_bufferRowLength_offsetof||0)+")",
    bufferImageHeight: "u32("+(V.VkBufferImageCopy_bufferImageHeight_offsetof||0)+")",
    imageSubresource: "u32("+(V.VkBufferImageCopy_imageSubresource_offsetof||0)+")",
    imageOffset: "u32("+(V.VkBufferImageCopy_imageOffset_offsetof||0)+")",
    imageExtent: "u32("+(V.VkBufferImageCopy_imageExtent_offsetof||0)+")",
}, (V.VkBufferImageCopy_sizeof||0))));


const VkCopyMemoryIndirectCommandNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyMemoryIndirectCommandNV", {
    srcAddress: "u64("+(V.VkCopyMemoryIndirectCommandNV_srcAddress_offsetof||0)+")",
    dstAddress: "u64("+(V.VkCopyMemoryIndirectCommandNV_dstAddress_offsetof||0)+")",
    size: "u64("+(V.VkCopyMemoryIndirectCommandNV_size_offsetof||0)+")",
}, (V.VkCopyMemoryIndirectCommandNV_sizeof||0))));


const VkCopyMemoryToImageIndirectCommandNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyMemoryToImageIndirectCommandNV", {
    srcAddress: "u64("+(V.VkCopyMemoryToImageIndirectCommandNV_srcAddress_offsetof||0)+")",
    bufferRowLength: "u32("+(V.VkCopyMemoryToImageIndirectCommandNV_bufferRowLength_offsetof||0)+")",
    bufferImageHeight: "u32("+(V.VkCopyMemoryToImageIndirectCommandNV_bufferImageHeight_offsetof||0)+")",
    imageSubresource: "u32("+(V.VkCopyMemoryToImageIndirectCommandNV_imageSubresource_offsetof||0)+")",
    imageOffset: "u32("+(V.VkCopyMemoryToImageIndirectCommandNV_imageOffset_offsetof||0)+")",
    imageExtent: "u32("+(V.VkCopyMemoryToImageIndirectCommandNV_imageExtent_offsetof||0)+")",
}, (V.VkCopyMemoryToImageIndirectCommandNV_sizeof||0))));


const VkImageResolve = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageResolve", {
    srcSubresource: "u32("+(V.VkImageResolve_srcSubresource_offsetof||0)+")",
    srcOffset: "u32("+(V.VkImageResolve_srcOffset_offsetof||0)+")",
    dstSubresource: "u32("+(V.VkImageResolve_dstSubresource_offsetof||0)+")",
    dstOffset: "u32("+(V.VkImageResolve_dstOffset_offsetof||0)+")",
    extent: "u32("+(V.VkImageResolve_extent_offsetof||0)+")",
}, (V.VkImageResolve_sizeof||0))));


const VkShaderModuleCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkShaderModuleCreateInfo", {
    sType: "u32("+(V.VkShaderModuleCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkShaderModuleCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkShaderModuleCreateInfo_flags_offsetof||0)+")",
    codeSize: "u64("+(V.VkShaderModuleCreateInfo_codeSize_offsetof||0)+")",
    pCode: "u64("+(V.VkShaderModuleCreateInfo_pCode_offsetof||0)+")",
}, (V.VkShaderModuleCreateInfo_sizeof||0))));


const VkDescriptorSetLayoutBinding = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorSetLayoutBinding", {
    binding: "u32("+(V.VkDescriptorSetLayoutBinding_binding_offsetof||0)+")",
    descriptorType: "u32("+(V.VkDescriptorSetLayoutBinding_descriptorType_offsetof||0)+")",
    descriptorCount: "u32("+(V.VkDescriptorSetLayoutBinding_descriptorCount_offsetof||0)+")",
    stageFlags: "u32("+(V.VkDescriptorSetLayoutBinding_stageFlags_offsetof||0)+")",
    pImmutableSamplers: "u64("+(V.VkDescriptorSetLayoutBinding_pImmutableSamplers_offsetof||0)+")",
}, (V.VkDescriptorSetLayoutBinding_sizeof||0))));


const VkDescriptorSetLayoutCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorSetLayoutCreateInfo", {
    sType: "u32("+(V.VkDescriptorSetLayoutCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDescriptorSetLayoutCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDescriptorSetLayoutCreateInfo_flags_offsetof||0)+")",
    bindingCount: "u32("+(V.VkDescriptorSetLayoutCreateInfo_bindingCount_offsetof||0)+")",
    pBindings: "u64("+(V.VkDescriptorSetLayoutCreateInfo_pBindings_offsetof||0)+")",
}, (V.VkDescriptorSetLayoutCreateInfo_sizeof||0))));


const VkDescriptorPoolSize = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorPoolSize", {
    type: "u32("+(V.VkDescriptorPoolSize_type_offsetof||0)+")",
    descriptorCount: "u32("+(V.VkDescriptorPoolSize_descriptorCount_offsetof||0)+")",
}, (V.VkDescriptorPoolSize_sizeof||0))));


const VkDescriptorPoolCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorPoolCreateInfo", {
    sType: "u32("+(V.VkDescriptorPoolCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDescriptorPoolCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDescriptorPoolCreateInfo_flags_offsetof||0)+")",
    maxSets: "u32("+(V.VkDescriptorPoolCreateInfo_maxSets_offsetof||0)+")",
    poolSizeCount: "u32("+(V.VkDescriptorPoolCreateInfo_poolSizeCount_offsetof||0)+")",
    pPoolSizes: "u64("+(V.VkDescriptorPoolCreateInfo_pPoolSizes_offsetof||0)+")",
}, (V.VkDescriptorPoolCreateInfo_sizeof||0))));


const VkDescriptorSetAllocateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorSetAllocateInfo", {
    sType: "u32("+(V.VkDescriptorSetAllocateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDescriptorSetAllocateInfo_pNext_offsetof||0)+")",
    descriptorPool: "u32("+(V.VkDescriptorSetAllocateInfo_descriptorPool_offsetof||0)+")",
    descriptorSetCount: "u32("+(V.VkDescriptorSetAllocateInfo_descriptorSetCount_offsetof||0)+")",
    pSetLayouts: "u64("+(V.VkDescriptorSetAllocateInfo_pSetLayouts_offsetof||0)+")",
}, (V.VkDescriptorSetAllocateInfo_sizeof||0))));


const VkSpecializationMapEntry = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSpecializationMapEntry", {
    constantID: "u32("+(V.VkSpecializationMapEntry_constantID_offsetof||0)+")",
    offset: "u32("+(V.VkSpecializationMapEntry_offset_offsetof||0)+")",
    size: "u64("+(V.VkSpecializationMapEntry_size_offsetof||0)+")",
}, (V.VkSpecializationMapEntry_sizeof||0))));


const VkSpecializationInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSpecializationInfo", {
    mapEntryCount: "u32("+(V.VkSpecializationInfo_mapEntryCount_offsetof||0)+")",
    pMapEntries: "u64("+(V.VkSpecializationInfo_pMapEntries_offsetof||0)+")",
    dataSize: "u64("+(V.VkSpecializationInfo_dataSize_offsetof||0)+")",
    pData: "u64("+(V.VkSpecializationInfo_pData_offsetof||0)+")",
}, (V.VkSpecializationInfo_sizeof||0))));


const VkPipelineShaderStageCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineShaderStageCreateInfo", {
    sType: "u32("+(V.VkPipelineShaderStageCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineShaderStageCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineShaderStageCreateInfo_flags_offsetof||0)+")",
    stage: "u32("+(V.VkPipelineShaderStageCreateInfo_stage_offsetof||0)+")",
    module: "u32("+(V.VkPipelineShaderStageCreateInfo_module_offsetof||0)+")",
    pName: "u64("+(V.VkPipelineShaderStageCreateInfo_pName_offsetof||0)+")",
    pSpecializationInfo: "u64("+(V.VkPipelineShaderStageCreateInfo_pSpecializationInfo_offsetof||0)+")",
}, (V.VkPipelineShaderStageCreateInfo_sizeof||0))));


const VkComputePipelineCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkComputePipelineCreateInfo", {
    sType: "u32("+(V.VkComputePipelineCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkComputePipelineCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkComputePipelineCreateInfo_flags_offsetof||0)+")",
    stage: "u32("+(V.VkComputePipelineCreateInfo_stage_offsetof||0)+")",
    layout: "u64("+(V.VkComputePipelineCreateInfo_layout_offsetof||0)+")",
    basePipelineHandle: "u64("+(V.VkComputePipelineCreateInfo_basePipelineHandle_offsetof||0)+")",
    basePipelineIndex: "i32("+(V.VkComputePipelineCreateInfo_basePipelineIndex_offsetof||0)+")",
}, (V.VkComputePipelineCreateInfo_sizeof||0))));


const VkVertexInputBindingDescription = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVertexInputBindingDescription", {
    binding: "u32("+(V.VkVertexInputBindingDescription_binding_offsetof||0)+")",
    stride: "u32("+(V.VkVertexInputBindingDescription_stride_offsetof||0)+")",
    inputRate: "u32("+(V.VkVertexInputBindingDescription_inputRate_offsetof||0)+")",
}, (V.VkVertexInputBindingDescription_sizeof||0))));


const VkVertexInputAttributeDescription = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVertexInputAttributeDescription", {
    location: "u32("+(V.VkVertexInputAttributeDescription_location_offsetof||0)+")",
    binding: "u32("+(V.VkVertexInputAttributeDescription_binding_offsetof||0)+")",
    format: "u32("+(V.VkVertexInputAttributeDescription_format_offsetof||0)+")",
    offset: "u32("+(V.VkVertexInputAttributeDescription_offset_offsetof||0)+")",
}, (V.VkVertexInputAttributeDescription_sizeof||0))));


const VkPipelineVertexInputStateCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineVertexInputStateCreateInfo", {
    sType: "u32("+(V.VkPipelineVertexInputStateCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineVertexInputStateCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineVertexInputStateCreateInfo_flags_offsetof||0)+")",
    vertexBindingDescriptionCount: "u32("+(V.VkPipelineVertexInputStateCreateInfo_vertexBindingDescriptionCount_offsetof||0)+")",
    pVertexBindingDescriptions: "u64("+(V.VkPipelineVertexInputStateCreateInfo_pVertexBindingDescriptions_offsetof||0)+")",
    vertexAttributeDescriptionCount: "u32("+(V.VkPipelineVertexInputStateCreateInfo_vertexAttributeDescriptionCount_offsetof||0)+")",
    pVertexAttributeDescriptions: "u64("+(V.VkPipelineVertexInputStateCreateInfo_pVertexAttributeDescriptions_offsetof||0)+")",
}, (V.VkPipelineVertexInputStateCreateInfo_sizeof||0))));


const VkPipelineInputAssemblyStateCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineInputAssemblyStateCreateInfo", {
    sType: "u32("+(V.VkPipelineInputAssemblyStateCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineInputAssemblyStateCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineInputAssemblyStateCreateInfo_flags_offsetof||0)+")",
    topology: "u32("+(V.VkPipelineInputAssemblyStateCreateInfo_topology_offsetof||0)+")",
    primitiveRestartEnable: "u32("+(V.VkPipelineInputAssemblyStateCreateInfo_primitiveRestartEnable_offsetof||0)+")",
}, (V.VkPipelineInputAssemblyStateCreateInfo_sizeof||0))));


const VkPipelineTessellationStateCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineTessellationStateCreateInfo", {
    sType: "u32("+(V.VkPipelineTessellationStateCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineTessellationStateCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineTessellationStateCreateInfo_flags_offsetof||0)+")",
    patchControlPoints: "u32("+(V.VkPipelineTessellationStateCreateInfo_patchControlPoints_offsetof||0)+")",
}, (V.VkPipelineTessellationStateCreateInfo_sizeof||0))));


const VkPipelineViewportStateCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineViewportStateCreateInfo", {
    sType: "u32("+(V.VkPipelineViewportStateCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineViewportStateCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineViewportStateCreateInfo_flags_offsetof||0)+")",
    viewportCount: "u32("+(V.VkPipelineViewportStateCreateInfo_viewportCount_offsetof||0)+")",
    pViewports: "u64("+(V.VkPipelineViewportStateCreateInfo_pViewports_offsetof||0)+")",
    scissorCount: "u32("+(V.VkPipelineViewportStateCreateInfo_scissorCount_offsetof||0)+")",
    pScissors: "u64("+(V.VkPipelineViewportStateCreateInfo_pScissors_offsetof||0)+")",
}, (V.VkPipelineViewportStateCreateInfo_sizeof||0))));


const VkPipelineRasterizationStateCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineRasterizationStateCreateInfo", {
    sType: "u32("+(V.VkPipelineRasterizationStateCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineRasterizationStateCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineRasterizationStateCreateInfo_flags_offsetof||0)+")",
    depthClampEnable: "u32("+(V.VkPipelineRasterizationStateCreateInfo_depthClampEnable_offsetof||0)+")",
    rasterizerDiscardEnable: "u32("+(V.VkPipelineRasterizationStateCreateInfo_rasterizerDiscardEnable_offsetof||0)+")",
    polygonMode: "u32("+(V.VkPipelineRasterizationStateCreateInfo_polygonMode_offsetof||0)+")",
    cullMode: "u32("+(V.VkPipelineRasterizationStateCreateInfo_cullMode_offsetof||0)+")",
    frontFace: "u32("+(V.VkPipelineRasterizationStateCreateInfo_frontFace_offsetof||0)+")",
    depthBiasEnable: "u32("+(V.VkPipelineRasterizationStateCreateInfo_depthBiasEnable_offsetof||0)+")",
    depthBiasConstantFactor: "f32("+(V.VkPipelineRasterizationStateCreateInfo_depthBiasConstantFactor_offsetof||0)+")",
    depthBiasClamp: "f32("+(V.VkPipelineRasterizationStateCreateInfo_depthBiasClamp_offsetof||0)+")",
    depthBiasSlopeFactor: "f32("+(V.VkPipelineRasterizationStateCreateInfo_depthBiasSlopeFactor_offsetof||0)+")",
    lineWidth: "f32("+(V.VkPipelineRasterizationStateCreateInfo_lineWidth_offsetof||0)+")",
}, (V.VkPipelineRasterizationStateCreateInfo_sizeof||0))));


const VkPipelineMultisampleStateCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineMultisampleStateCreateInfo", {
    sType: "u32("+(V.VkPipelineMultisampleStateCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineMultisampleStateCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineMultisampleStateCreateInfo_flags_offsetof||0)+")",
    rasterizationSamples: "u32("+(V.VkPipelineMultisampleStateCreateInfo_rasterizationSamples_offsetof||0)+")",
    sampleShadingEnable: "u32("+(V.VkPipelineMultisampleStateCreateInfo_sampleShadingEnable_offsetof||0)+")",
    minSampleShading: "f32("+(V.VkPipelineMultisampleStateCreateInfo_minSampleShading_offsetof||0)+")",
    pSampleMask: "u64("+(V.VkPipelineMultisampleStateCreateInfo_pSampleMask_offsetof||0)+")",
    alphaToCoverageEnable: "u32("+(V.VkPipelineMultisampleStateCreateInfo_alphaToCoverageEnable_offsetof||0)+")",
    alphaToOneEnable: "u32("+(V.VkPipelineMultisampleStateCreateInfo_alphaToOneEnable_offsetof||0)+")",
}, (V.VkPipelineMultisampleStateCreateInfo_sizeof||0))));


const VkPipelineColorBlendAttachmentState = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineColorBlendAttachmentState", {
    blendEnable: "u32("+(V.VkPipelineColorBlendAttachmentState_blendEnable_offsetof||0)+")",
    srcColorBlendFactor: "u32("+(V.VkPipelineColorBlendAttachmentState_srcColorBlendFactor_offsetof||0)+")",
    dstColorBlendFactor: "u32("+(V.VkPipelineColorBlendAttachmentState_dstColorBlendFactor_offsetof||0)+")",
    colorBlendOp: "u32("+(V.VkPipelineColorBlendAttachmentState_colorBlendOp_offsetof||0)+")",
    srcAlphaBlendFactor: "u32("+(V.VkPipelineColorBlendAttachmentState_srcAlphaBlendFactor_offsetof||0)+")",
    dstAlphaBlendFactor: "u32("+(V.VkPipelineColorBlendAttachmentState_dstAlphaBlendFactor_offsetof||0)+")",
    alphaBlendOp: "u32("+(V.VkPipelineColorBlendAttachmentState_alphaBlendOp_offsetof||0)+")",
    colorWriteMask: "u32("+(V.VkPipelineColorBlendAttachmentState_colorWriteMask_offsetof||0)+")",
}, (V.VkPipelineColorBlendAttachmentState_sizeof||0))));


const VkPipelineColorBlendStateCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineColorBlendStateCreateInfo", {
    sType: "u32("+(V.VkPipelineColorBlendStateCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineColorBlendStateCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineColorBlendStateCreateInfo_flags_offsetof||0)+")",
    logicOpEnable: "u32("+(V.VkPipelineColorBlendStateCreateInfo_logicOpEnable_offsetof||0)+")",
    logicOp: "u32("+(V.VkPipelineColorBlendStateCreateInfo_logicOp_offsetof||0)+")",
    attachmentCount: "u32("+(V.VkPipelineColorBlendStateCreateInfo_attachmentCount_offsetof||0)+")",
    pAttachments: "u64("+(V.VkPipelineColorBlendStateCreateInfo_pAttachments_offsetof||0)+")",
    blendConstants: "f32[4]("+(V.VkPipelineColorBlendStateCreateInfo_blendConstants_offsetof||0)+")",
}, (V.VkPipelineColorBlendStateCreateInfo_sizeof||0))));


const VkPipelineDynamicStateCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineDynamicStateCreateInfo", {
    sType: "u32("+(V.VkPipelineDynamicStateCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineDynamicStateCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineDynamicStateCreateInfo_flags_offsetof||0)+")",
    dynamicStateCount: "u32("+(V.VkPipelineDynamicStateCreateInfo_dynamicStateCount_offsetof||0)+")",
    pDynamicStates: "u64("+(V.VkPipelineDynamicStateCreateInfo_pDynamicStates_offsetof||0)+")",
}, (V.VkPipelineDynamicStateCreateInfo_sizeof||0))));


const VkStencilOpState = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkStencilOpState", {
    failOp: "u32("+(V.VkStencilOpState_failOp_offsetof||0)+")",
    passOp: "u32("+(V.VkStencilOpState_passOp_offsetof||0)+")",
    depthFailOp: "u32("+(V.VkStencilOpState_depthFailOp_offsetof||0)+")",
    compareOp: "u32("+(V.VkStencilOpState_compareOp_offsetof||0)+")",
    compareMask: "u32("+(V.VkStencilOpState_compareMask_offsetof||0)+")",
    writeMask: "u32("+(V.VkStencilOpState_writeMask_offsetof||0)+")",
    reference: "u32("+(V.VkStencilOpState_reference_offsetof||0)+")",
}, (V.VkStencilOpState_sizeof||0))));


const VkPipelineDepthStencilStateCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineDepthStencilStateCreateInfo", {
    sType: "u32("+(V.VkPipelineDepthStencilStateCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineDepthStencilStateCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineDepthStencilStateCreateInfo_flags_offsetof||0)+")",
    depthTestEnable: "u32("+(V.VkPipelineDepthStencilStateCreateInfo_depthTestEnable_offsetof||0)+")",
    depthWriteEnable: "u32("+(V.VkPipelineDepthStencilStateCreateInfo_depthWriteEnable_offsetof||0)+")",
    depthCompareOp: "u32("+(V.VkPipelineDepthStencilStateCreateInfo_depthCompareOp_offsetof||0)+")",
    depthBoundsTestEnable: "u32("+(V.VkPipelineDepthStencilStateCreateInfo_depthBoundsTestEnable_offsetof||0)+")",
    stencilTestEnable: "u32("+(V.VkPipelineDepthStencilStateCreateInfo_stencilTestEnable_offsetof||0)+")",
    front: "u32("+(V.VkPipelineDepthStencilStateCreateInfo_front_offsetof||0)+")",
    back: "u32("+(V.VkPipelineDepthStencilStateCreateInfo_back_offsetof||0)+")",
    minDepthBounds: "f32("+(V.VkPipelineDepthStencilStateCreateInfo_minDepthBounds_offsetof||0)+")",
    maxDepthBounds: "f32("+(V.VkPipelineDepthStencilStateCreateInfo_maxDepthBounds_offsetof||0)+")",
}, (V.VkPipelineDepthStencilStateCreateInfo_sizeof||0))));


const VkGraphicsPipelineCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkGraphicsPipelineCreateInfo", {
    sType: "u32("+(V.VkGraphicsPipelineCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkGraphicsPipelineCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkGraphicsPipelineCreateInfo_flags_offsetof||0)+")",
    stageCount: "u32("+(V.VkGraphicsPipelineCreateInfo_stageCount_offsetof||0)+")",
    pStages: "u64("+(V.VkGraphicsPipelineCreateInfo_pStages_offsetof||0)+")",
    pVertexInputState: "u64("+(V.VkGraphicsPipelineCreateInfo_pVertexInputState_offsetof||0)+")",
    pInputAssemblyState: "u64("+(V.VkGraphicsPipelineCreateInfo_pInputAssemblyState_offsetof||0)+")",
    pTessellationState: "u64("+(V.VkGraphicsPipelineCreateInfo_pTessellationState_offsetof||0)+")",
    pViewportState: "u64("+(V.VkGraphicsPipelineCreateInfo_pViewportState_offsetof||0)+")",
    pRasterizationState: "u64("+(V.VkGraphicsPipelineCreateInfo_pRasterizationState_offsetof||0)+")",
    pMultisampleState: "u64("+(V.VkGraphicsPipelineCreateInfo_pMultisampleState_offsetof||0)+")",
    pDepthStencilState: "u64("+(V.VkGraphicsPipelineCreateInfo_pDepthStencilState_offsetof||0)+")",
    pColorBlendState: "u64("+(V.VkGraphicsPipelineCreateInfo_pColorBlendState_offsetof||0)+")",
    pDynamicState: "u64("+(V.VkGraphicsPipelineCreateInfo_pDynamicState_offsetof||0)+")",
    layout: "u64("+(V.VkGraphicsPipelineCreateInfo_layout_offsetof||0)+")",
    renderPass: "u32("+(V.VkGraphicsPipelineCreateInfo_renderPass_offsetof||0)+")",
    subpass: "u32("+(V.VkGraphicsPipelineCreateInfo_subpass_offsetof||0)+")",
    basePipelineHandle: "u64("+(V.VkGraphicsPipelineCreateInfo_basePipelineHandle_offsetof||0)+")",
    basePipelineIndex: "i32("+(V.VkGraphicsPipelineCreateInfo_basePipelineIndex_offsetof||0)+")",
}, (V.VkGraphicsPipelineCreateInfo_sizeof||0))));


const VkPipelineCacheCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineCacheCreateInfo", {
    sType: "u32("+(V.VkPipelineCacheCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineCacheCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineCacheCreateInfo_flags_offsetof||0)+")",
    initialDataSize: "u64("+(V.VkPipelineCacheCreateInfo_initialDataSize_offsetof||0)+")",
    pInitialData: "u64("+(V.VkPipelineCacheCreateInfo_pInitialData_offsetof||0)+")",
}, (V.VkPipelineCacheCreateInfo_sizeof||0))));


const VkPipelineCacheHeaderVersionOne = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineCacheHeaderVersionOne", {
    headerSize: "u32("+(V.VkPipelineCacheHeaderVersionOne_headerSize_offsetof||0)+")",
    headerVersion: "u32("+(V.VkPipelineCacheHeaderVersionOne_headerVersion_offsetof||0)+")",
    vendorID: "u32("+(V.VkPipelineCacheHeaderVersionOne_vendorID_offsetof||0)+")",
    deviceID: "u32("+(V.VkPipelineCacheHeaderVersionOne_deviceID_offsetof||0)+")",
    pipelineCacheUUID: "u8["+(E.VK_UUID_SIZE||1)+"]("+(V.VkPipelineCacheHeaderVersionOne_pipelineCacheUUID_offsetof||0)+")",
}, (V.VkPipelineCacheHeaderVersionOne_sizeof||0))));


const VkPushConstantRange = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPushConstantRange", {
    stageFlags: "u32("+(V.VkPushConstantRange_stageFlags_offsetof||0)+")",
    offset: "u32("+(V.VkPushConstantRange_offset_offsetof||0)+")",
    size: "u32("+(V.VkPushConstantRange_size_offsetof||0)+")",
}, (V.VkPushConstantRange_sizeof||0))));


const VkPipelineLayoutCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineLayoutCreateInfo", {
    sType: "u32("+(V.VkPipelineLayoutCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineLayoutCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineLayoutCreateInfo_flags_offsetof||0)+")",
    setLayoutCount: "u32("+(V.VkPipelineLayoutCreateInfo_setLayoutCount_offsetof||0)+")",
    pSetLayouts: "u64("+(V.VkPipelineLayoutCreateInfo_pSetLayouts_offsetof||0)+")",
    pushConstantRangeCount: "u32("+(V.VkPipelineLayoutCreateInfo_pushConstantRangeCount_offsetof||0)+")",
    pPushConstantRanges: "u64("+(V.VkPipelineLayoutCreateInfo_pPushConstantRanges_offsetof||0)+")",
}, (V.VkPipelineLayoutCreateInfo_sizeof||0))));


const VkSamplerCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSamplerCreateInfo", {
    sType: "u32("+(V.VkSamplerCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSamplerCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkSamplerCreateInfo_flags_offsetof||0)+")",
    magFilter: "u32("+(V.VkSamplerCreateInfo_magFilter_offsetof||0)+")",
    minFilter: "u32("+(V.VkSamplerCreateInfo_minFilter_offsetof||0)+")",
    mipmapMode: "u32("+(V.VkSamplerCreateInfo_mipmapMode_offsetof||0)+")",
    addressModeU: "u32("+(V.VkSamplerCreateInfo_addressModeU_offsetof||0)+")",
    addressModeV: "u32("+(V.VkSamplerCreateInfo_addressModeV_offsetof||0)+")",
    addressModeW: "u32("+(V.VkSamplerCreateInfo_addressModeW_offsetof||0)+")",
    mipLodBias: "f32("+(V.VkSamplerCreateInfo_mipLodBias_offsetof||0)+")",
    anisotropyEnable: "u32("+(V.VkSamplerCreateInfo_anisotropyEnable_offsetof||0)+")",
    maxAnisotropy: "f32("+(V.VkSamplerCreateInfo_maxAnisotropy_offsetof||0)+")",
    compareEnable: "u32("+(V.VkSamplerCreateInfo_compareEnable_offsetof||0)+")",
    compareOp: "u32("+(V.VkSamplerCreateInfo_compareOp_offsetof||0)+")",
    minLod: "f32("+(V.VkSamplerCreateInfo_minLod_offsetof||0)+")",
    maxLod: "f32("+(V.VkSamplerCreateInfo_maxLod_offsetof||0)+")",
    borderColor: "u32("+(V.VkSamplerCreateInfo_borderColor_offsetof||0)+")",
    unnormalizedCoordinates: "u32("+(V.VkSamplerCreateInfo_unnormalizedCoordinates_offsetof||0)+")",
}, (V.VkSamplerCreateInfo_sizeof||0))));


const VkCommandPoolCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCommandPoolCreateInfo", {
    sType: "u32("+(V.VkCommandPoolCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCommandPoolCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkCommandPoolCreateInfo_flags_offsetof||0)+")",
    queueFamilyIndex: "u32("+(V.VkCommandPoolCreateInfo_queueFamilyIndex_offsetof||0)+")",
}, (V.VkCommandPoolCreateInfo_sizeof||0))));


const VkCommandBufferAllocateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCommandBufferAllocateInfo", {
    sType: "u32("+(V.VkCommandBufferAllocateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCommandBufferAllocateInfo_pNext_offsetof||0)+")",
    commandPool: "u32("+(V.VkCommandBufferAllocateInfo_commandPool_offsetof||0)+")",
    level: "u32("+(V.VkCommandBufferAllocateInfo_level_offsetof||0)+")",
    commandBufferCount: "u32("+(V.VkCommandBufferAllocateInfo_commandBufferCount_offsetof||0)+")",
}, (V.VkCommandBufferAllocateInfo_sizeof||0))));


const VkCommandBufferInheritanceInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCommandBufferInheritanceInfo", {
    sType: "u32("+(V.VkCommandBufferInheritanceInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCommandBufferInheritanceInfo_pNext_offsetof||0)+")",
    renderPass: "u32("+(V.VkCommandBufferInheritanceInfo_renderPass_offsetof||0)+")",
    subpass: "u32("+(V.VkCommandBufferInheritanceInfo_subpass_offsetof||0)+")",
    framebuffer: "u64("+(V.VkCommandBufferInheritanceInfo_framebuffer_offsetof||0)+")",
    occlusionQueryEnable: "u32("+(V.VkCommandBufferInheritanceInfo_occlusionQueryEnable_offsetof||0)+")",
    queryFlags: "u32("+(V.VkCommandBufferInheritanceInfo_queryFlags_offsetof||0)+")",
    pipelineStatistics: "u32("+(V.VkCommandBufferInheritanceInfo_pipelineStatistics_offsetof||0)+")",
}, (V.VkCommandBufferInheritanceInfo_sizeof||0))));


const VkCommandBufferBeginInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCommandBufferBeginInfo", {
    sType: "u32("+(V.VkCommandBufferBeginInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCommandBufferBeginInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkCommandBufferBeginInfo_flags_offsetof||0)+")",
    pInheritanceInfo: "u64("+(V.VkCommandBufferBeginInfo_pInheritanceInfo_offsetof||0)+")",
}, (V.VkCommandBufferBeginInfo_sizeof||0))));


const VkRenderPassBeginInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassBeginInfo", {
    sType: "u32("+(V.VkRenderPassBeginInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderPassBeginInfo_pNext_offsetof||0)+")",
    renderPass: "u32("+(V.VkRenderPassBeginInfo_renderPass_offsetof||0)+")",
    framebuffer: "u64("+(V.VkRenderPassBeginInfo_framebuffer_offsetof||0)+")",
    renderArea: "VkRect2D("+(V.VkRenderPassBeginInfo_renderArea_offsetof||0)+")",
    clearValueCount: "u32("+(V.VkRenderPassBeginInfo_clearValueCount_offsetof||0)+")",
    pClearValues: "u64("+(V.VkRenderPassBeginInfo_pClearValues_offsetof||0)+")",
}, (V.VkRenderPassBeginInfo_sizeof||0))));


const VkClearDepthStencilValue = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkClearDepthStencilValue", {
    depth: "f32("+(V.VkClearDepthStencilValue_depth_offsetof||0)+")",
    stencil: "u32("+(V.VkClearDepthStencilValue_stencil_offsetof||0)+")",
}, (V.VkClearDepthStencilValue_sizeof||0))));


const VkClearAttachment = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkClearAttachment", {
    aspectMask: "u32("+(V.VkClearAttachment_aspectMask_offsetof||0)+")",
    colorAttachment: "u32("+(V.VkClearAttachment_colorAttachment_offsetof||0)+")",
    clearValue: "u32("+(V.VkClearAttachment_clearValue_offsetof||0)+")",
}, (V.VkClearAttachment_sizeof||0))));


const VkAttachmentDescription = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAttachmentDescription", {
    flags: "u32("+(V.VkAttachmentDescription_flags_offsetof||0)+")",
    format: "u32("+(V.VkAttachmentDescription_format_offsetof||0)+")",
    samples: "u32("+(V.VkAttachmentDescription_samples_offsetof||0)+")",
    loadOp: "u32("+(V.VkAttachmentDescription_loadOp_offsetof||0)+")",
    storeOp: "u32("+(V.VkAttachmentDescription_storeOp_offsetof||0)+")",
    stencilLoadOp: "u32("+(V.VkAttachmentDescription_stencilLoadOp_offsetof||0)+")",
    stencilStoreOp: "u32("+(V.VkAttachmentDescription_stencilStoreOp_offsetof||0)+")",
    initialLayout: "u32("+(V.VkAttachmentDescription_initialLayout_offsetof||0)+")",
    finalLayout: "u32("+(V.VkAttachmentDescription_finalLayout_offsetof||0)+")",
}, (V.VkAttachmentDescription_sizeof||0))));


const VkAttachmentReference = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAttachmentReference", {
    attachment: "u32("+(V.VkAttachmentReference_attachment_offsetof||0)+")",
    layout: "u32("+(V.VkAttachmentReference_layout_offsetof||0)+")",
}, (V.VkAttachmentReference_sizeof||0))));


const VkSubpassDescription = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubpassDescription", {
    flags: "u32("+(V.VkSubpassDescription_flags_offsetof||0)+")",
    pipelineBindPoint: "u32("+(V.VkSubpassDescription_pipelineBindPoint_offsetof||0)+")",
    inputAttachmentCount: "u32("+(V.VkSubpassDescription_inputAttachmentCount_offsetof||0)+")",
    pInputAttachments: "u64("+(V.VkSubpassDescription_pInputAttachments_offsetof||0)+")",
    colorAttachmentCount: "u32("+(V.VkSubpassDescription_colorAttachmentCount_offsetof||0)+")",
    pColorAttachments: "u64("+(V.VkSubpassDescription_pColorAttachments_offsetof||0)+")",
    pResolveAttachments: "u64("+(V.VkSubpassDescription_pResolveAttachments_offsetof||0)+")",
    pDepthStencilAttachment: "u64("+(V.VkSubpassDescription_pDepthStencilAttachment_offsetof||0)+")",
    preserveAttachmentCount: "u32("+(V.VkSubpassDescription_preserveAttachmentCount_offsetof||0)+")",
    pPreserveAttachments: "u64("+(V.VkSubpassDescription_pPreserveAttachments_offsetof||0)+")",
}, (V.VkSubpassDescription_sizeof||0))));


const VkSubpassDependency = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubpassDependency", {
    srcSubpass: "u32("+(V.VkSubpassDependency_srcSubpass_offsetof||0)+")",
    dstSubpass: "u32("+(V.VkSubpassDependency_dstSubpass_offsetof||0)+")",
    srcStageMask: "u32("+(V.VkSubpassDependency_srcStageMask_offsetof||0)+")",
    dstStageMask: "u32("+(V.VkSubpassDependency_dstStageMask_offsetof||0)+")",
    srcAccessMask: "u32("+(V.VkSubpassDependency_srcAccessMask_offsetof||0)+")",
    dstAccessMask: "u32("+(V.VkSubpassDependency_dstAccessMask_offsetof||0)+")",
    dependencyFlags: "u32("+(V.VkSubpassDependency_dependencyFlags_offsetof||0)+")",
}, (V.VkSubpassDependency_sizeof||0))));


const VkRenderPassCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassCreateInfo", {
    sType: "u32("+(V.VkRenderPassCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderPassCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkRenderPassCreateInfo_flags_offsetof||0)+")",
    attachmentCount: "u32("+(V.VkRenderPassCreateInfo_attachmentCount_offsetof||0)+")",
    pAttachments: "u64("+(V.VkRenderPassCreateInfo_pAttachments_offsetof||0)+")",
    subpassCount: "u32("+(V.VkRenderPassCreateInfo_subpassCount_offsetof||0)+")",
    pSubpasses: "u64("+(V.VkRenderPassCreateInfo_pSubpasses_offsetof||0)+")",
    dependencyCount: "u32("+(V.VkRenderPassCreateInfo_dependencyCount_offsetof||0)+")",
    pDependencies: "u64("+(V.VkRenderPassCreateInfo_pDependencies_offsetof||0)+")",
}, (V.VkRenderPassCreateInfo_sizeof||0))));


const VkEventCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkEventCreateInfo", {
    sType: "u32("+(V.VkEventCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkEventCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkEventCreateInfo_flags_offsetof||0)+")",
}, (V.VkEventCreateInfo_sizeof||0))));


const VkFenceCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkFenceCreateInfo", {
    sType: "u32("+(V.VkFenceCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkFenceCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkFenceCreateInfo_flags_offsetof||0)+")",
}, (V.VkFenceCreateInfo_sizeof||0))));


const VkPhysicalDeviceFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFeatures", {
    robustBufferAccess: "u32("+(V.VkPhysicalDeviceFeatures_robustBufferAccess_offsetof||0)+")",
    fullDrawIndexUint32: "u32("+(V.VkPhysicalDeviceFeatures_fullDrawIndexUint32_offsetof||0)+")",
    imageCubeArray: "u32("+(V.VkPhysicalDeviceFeatures_imageCubeArray_offsetof||0)+")",
    independentBlend: "u32("+(V.VkPhysicalDeviceFeatures_independentBlend_offsetof||0)+")",
    geometryShader: "u32("+(V.VkPhysicalDeviceFeatures_geometryShader_offsetof||0)+")",
    tessellationShader: "u32("+(V.VkPhysicalDeviceFeatures_tessellationShader_offsetof||0)+")",
    sampleRateShading: "u32("+(V.VkPhysicalDeviceFeatures_sampleRateShading_offsetof||0)+")",
    dualSrcBlend: "u32("+(V.VkPhysicalDeviceFeatures_dualSrcBlend_offsetof||0)+")",
    logicOp: "u32("+(V.VkPhysicalDeviceFeatures_logicOp_offsetof||0)+")",
    multiDrawIndirect: "u32("+(V.VkPhysicalDeviceFeatures_multiDrawIndirect_offsetof||0)+")",
    drawIndirectFirstInstance: "u32("+(V.VkPhysicalDeviceFeatures_drawIndirectFirstInstance_offsetof||0)+")",
    depthClamp: "u32("+(V.VkPhysicalDeviceFeatures_depthClamp_offsetof||0)+")",
    depthBiasClamp: "u32("+(V.VkPhysicalDeviceFeatures_depthBiasClamp_offsetof||0)+")",
    fillModeNonSolid: "u32("+(V.VkPhysicalDeviceFeatures_fillModeNonSolid_offsetof||0)+")",
    depthBounds: "u32("+(V.VkPhysicalDeviceFeatures_depthBounds_offsetof||0)+")",
    wideLines: "u32("+(V.VkPhysicalDeviceFeatures_wideLines_offsetof||0)+")",
    largePoints: "u32("+(V.VkPhysicalDeviceFeatures_largePoints_offsetof||0)+")",
    alphaToOne: "u32("+(V.VkPhysicalDeviceFeatures_alphaToOne_offsetof||0)+")",
    multiViewport: "u32("+(V.VkPhysicalDeviceFeatures_multiViewport_offsetof||0)+")",
    samplerAnisotropy: "u32("+(V.VkPhysicalDeviceFeatures_samplerAnisotropy_offsetof||0)+")",
    textureCompressionETC2: "u32("+(V.VkPhysicalDeviceFeatures_textureCompressionETC2_offsetof||0)+")",
    textureCompressionASTC_LDR: "u32("+(V.VkPhysicalDeviceFeatures_textureCompressionASTC_LDR_offsetof||0)+")",
    textureCompressionBC: "u32("+(V.VkPhysicalDeviceFeatures_textureCompressionBC_offsetof||0)+")",
    occlusionQueryPrecise: "u32("+(V.VkPhysicalDeviceFeatures_occlusionQueryPrecise_offsetof||0)+")",
    pipelineStatisticsQuery: "u32("+(V.VkPhysicalDeviceFeatures_pipelineStatisticsQuery_offsetof||0)+")",
    vertexPipelineStoresAndAtomics: "u32("+(V.VkPhysicalDeviceFeatures_vertexPipelineStoresAndAtomics_offsetof||0)+")",
    fragmentStoresAndAtomics: "u32("+(V.VkPhysicalDeviceFeatures_fragmentStoresAndAtomics_offsetof||0)+")",
    shaderTessellationAndGeometryPointSize: "u32("+(V.VkPhysicalDeviceFeatures_shaderTessellationAndGeometryPointSize_offsetof||0)+")",
    shaderImageGatherExtended: "u32("+(V.VkPhysicalDeviceFeatures_shaderImageGatherExtended_offsetof||0)+")",
    shaderStorageImageExtendedFormats: "u32("+(V.VkPhysicalDeviceFeatures_shaderStorageImageExtendedFormats_offsetof||0)+")",
    shaderStorageImageMultisample: "u32("+(V.VkPhysicalDeviceFeatures_shaderStorageImageMultisample_offsetof||0)+")",
    shaderStorageImageReadWithoutFormat: "u32("+(V.VkPhysicalDeviceFeatures_shaderStorageImageReadWithoutFormat_offsetof||0)+")",
    shaderStorageImageWriteWithoutFormat: "u32("+(V.VkPhysicalDeviceFeatures_shaderStorageImageWriteWithoutFormat_offsetof||0)+")",
    shaderUniformBufferArrayDynamicIndexing: "u32("+(V.VkPhysicalDeviceFeatures_shaderUniformBufferArrayDynamicIndexing_offsetof||0)+")",
    shaderSampledImageArrayDynamicIndexing: "u32("+(V.VkPhysicalDeviceFeatures_shaderSampledImageArrayDynamicIndexing_offsetof||0)+")",
    shaderStorageBufferArrayDynamicIndexing: "u32("+(V.VkPhysicalDeviceFeatures_shaderStorageBufferArrayDynamicIndexing_offsetof||0)+")",
    shaderStorageImageArrayDynamicIndexing: "u32("+(V.VkPhysicalDeviceFeatures_shaderStorageImageArrayDynamicIndexing_offsetof||0)+")",
    shaderClipDistance: "u32("+(V.VkPhysicalDeviceFeatures_shaderClipDistance_offsetof||0)+")",
    shaderCullDistance: "u32("+(V.VkPhysicalDeviceFeatures_shaderCullDistance_offsetof||0)+")",
    shaderFloat64: "u32("+(V.VkPhysicalDeviceFeatures_shaderFloat64_offsetof||0)+")",
    shaderInt64: "u32("+(V.VkPhysicalDeviceFeatures_shaderInt64_offsetof||0)+")",
    shaderInt16: "u32("+(V.VkPhysicalDeviceFeatures_shaderInt16_offsetof||0)+")",
    shaderResourceResidency: "u32("+(V.VkPhysicalDeviceFeatures_shaderResourceResidency_offsetof||0)+")",
    shaderResourceMinLod: "u32("+(V.VkPhysicalDeviceFeatures_shaderResourceMinLod_offsetof||0)+")",
    sparseBinding: "u32("+(V.VkPhysicalDeviceFeatures_sparseBinding_offsetof||0)+")",
    sparseResidencyBuffer: "u32("+(V.VkPhysicalDeviceFeatures_sparseResidencyBuffer_offsetof||0)+")",
    sparseResidencyImage2D: "u32("+(V.VkPhysicalDeviceFeatures_sparseResidencyImage2D_offsetof||0)+")",
    sparseResidencyImage3D: "u32("+(V.VkPhysicalDeviceFeatures_sparseResidencyImage3D_offsetof||0)+")",
    sparseResidency2Samples: "u32("+(V.VkPhysicalDeviceFeatures_sparseResidency2Samples_offsetof||0)+")",
    sparseResidency4Samples: "u32("+(V.VkPhysicalDeviceFeatures_sparseResidency4Samples_offsetof||0)+")",
    sparseResidency8Samples: "u32("+(V.VkPhysicalDeviceFeatures_sparseResidency8Samples_offsetof||0)+")",
    sparseResidency16Samples: "u32("+(V.VkPhysicalDeviceFeatures_sparseResidency16Samples_offsetof||0)+")",
    sparseResidencyAliased: "u32("+(V.VkPhysicalDeviceFeatures_sparseResidencyAliased_offsetof||0)+")",
    variableMultisampleRate: "u32("+(V.VkPhysicalDeviceFeatures_variableMultisampleRate_offsetof||0)+")",
    inheritedQueries: "u32("+(V.VkPhysicalDeviceFeatures_inheritedQueries_offsetof||0)+")",
}, (V.VkPhysicalDeviceFeatures_sizeof||0))));


const VkPhysicalDeviceSparseProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSparseProperties", {
    residencyStandard2DBlockShape: "u32("+(V.VkPhysicalDeviceSparseProperties_residencyStandard2DBlockShape_offsetof||0)+")",
    residencyStandard2DMultisampleBlockShape: "u32("+(V.VkPhysicalDeviceSparseProperties_residencyStandard2DMultisampleBlockShape_offsetof||0)+")",
    residencyStandard3DBlockShape: "u32("+(V.VkPhysicalDeviceSparseProperties_residencyStandard3DBlockShape_offsetof||0)+")",
    residencyAlignedMipSize: "u32("+(V.VkPhysicalDeviceSparseProperties_residencyAlignedMipSize_offsetof||0)+")",
    residencyNonResidentStrict: "u32("+(V.VkPhysicalDeviceSparseProperties_residencyNonResidentStrict_offsetof||0)+")",
}, (V.VkPhysicalDeviceSparseProperties_sizeof||0))));


const VkPhysicalDeviceLimits = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceLimits", {
    maxImageDimension1D: "u32("+(V.VkPhysicalDeviceLimits_maxImageDimension1D_offsetof||0)+")",
    maxImageDimension2D: "u32("+(V.VkPhysicalDeviceLimits_maxImageDimension2D_offsetof||0)+")",
    maxImageDimension3D: "u32("+(V.VkPhysicalDeviceLimits_maxImageDimension3D_offsetof||0)+")",
    maxImageDimensionCube: "u32("+(V.VkPhysicalDeviceLimits_maxImageDimensionCube_offsetof||0)+")",
    maxImageArrayLayers: "u32("+(V.VkPhysicalDeviceLimits_maxImageArrayLayers_offsetof||0)+")",
    maxTexelBufferElements: "u32("+(V.VkPhysicalDeviceLimits_maxTexelBufferElements_offsetof||0)+")",
    maxUniformBufferRange: "u32("+(V.VkPhysicalDeviceLimits_maxUniformBufferRange_offsetof||0)+")",
    maxStorageBufferRange: "u32("+(V.VkPhysicalDeviceLimits_maxStorageBufferRange_offsetof||0)+")",
    maxPushConstantsSize: "u32("+(V.VkPhysicalDeviceLimits_maxPushConstantsSize_offsetof||0)+")",
    maxMemoryAllocationCount: "u32("+(V.VkPhysicalDeviceLimits_maxMemoryAllocationCount_offsetof||0)+")",
    maxSamplerAllocationCount: "u32("+(V.VkPhysicalDeviceLimits_maxSamplerAllocationCount_offsetof||0)+")",
    bufferImageGranularity: "u64("+(V.VkPhysicalDeviceLimits_bufferImageGranularity_offsetof||0)+")",
    sparseAddressSpaceSize: "u64("+(V.VkPhysicalDeviceLimits_sparseAddressSpaceSize_offsetof||0)+")",
    maxBoundDescriptorSets: "u32("+(V.VkPhysicalDeviceLimits_maxBoundDescriptorSets_offsetof||0)+")",
    maxPerStageDescriptorSamplers: "u32("+(V.VkPhysicalDeviceLimits_maxPerStageDescriptorSamplers_offsetof||0)+")",
    maxPerStageDescriptorUniformBuffers: "u32("+(V.VkPhysicalDeviceLimits_maxPerStageDescriptorUniformBuffers_offsetof||0)+")",
    maxPerStageDescriptorStorageBuffers: "u32("+(V.VkPhysicalDeviceLimits_maxPerStageDescriptorStorageBuffers_offsetof||0)+")",
    maxPerStageDescriptorSampledImages: "u32("+(V.VkPhysicalDeviceLimits_maxPerStageDescriptorSampledImages_offsetof||0)+")",
    maxPerStageDescriptorStorageImages: "u32("+(V.VkPhysicalDeviceLimits_maxPerStageDescriptorStorageImages_offsetof||0)+")",
    maxPerStageDescriptorInputAttachments: "u32("+(V.VkPhysicalDeviceLimits_maxPerStageDescriptorInputAttachments_offsetof||0)+")",
    maxPerStageResources: "u32("+(V.VkPhysicalDeviceLimits_maxPerStageResources_offsetof||0)+")",
    maxDescriptorSetSamplers: "u32("+(V.VkPhysicalDeviceLimits_maxDescriptorSetSamplers_offsetof||0)+")",
    maxDescriptorSetUniformBuffers: "u32("+(V.VkPhysicalDeviceLimits_maxDescriptorSetUniformBuffers_offsetof||0)+")",
    maxDescriptorSetUniformBuffersDynamic: "u32("+(V.VkPhysicalDeviceLimits_maxDescriptorSetUniformBuffersDynamic_offsetof||0)+")",
    maxDescriptorSetStorageBuffers: "u32("+(V.VkPhysicalDeviceLimits_maxDescriptorSetStorageBuffers_offsetof||0)+")",
    maxDescriptorSetStorageBuffersDynamic: "u32("+(V.VkPhysicalDeviceLimits_maxDescriptorSetStorageBuffersDynamic_offsetof||0)+")",
    maxDescriptorSetSampledImages: "u32("+(V.VkPhysicalDeviceLimits_maxDescriptorSetSampledImages_offsetof||0)+")",
    maxDescriptorSetStorageImages: "u32("+(V.VkPhysicalDeviceLimits_maxDescriptorSetStorageImages_offsetof||0)+")",
    maxDescriptorSetInputAttachments: "u32("+(V.VkPhysicalDeviceLimits_maxDescriptorSetInputAttachments_offsetof||0)+")",
    maxVertexInputAttributes: "u32("+(V.VkPhysicalDeviceLimits_maxVertexInputAttributes_offsetof||0)+")",
    maxVertexInputBindings: "u32("+(V.VkPhysicalDeviceLimits_maxVertexInputBindings_offsetof||0)+")",
    maxVertexInputAttributeOffset: "u32("+(V.VkPhysicalDeviceLimits_maxVertexInputAttributeOffset_offsetof||0)+")",
    maxVertexInputBindingStride: "u32("+(V.VkPhysicalDeviceLimits_maxVertexInputBindingStride_offsetof||0)+")",
    maxVertexOutputComponents: "u32("+(V.VkPhysicalDeviceLimits_maxVertexOutputComponents_offsetof||0)+")",
    maxTessellationGenerationLevel: "u32("+(V.VkPhysicalDeviceLimits_maxTessellationGenerationLevel_offsetof||0)+")",
    maxTessellationPatchSize: "u32("+(V.VkPhysicalDeviceLimits_maxTessellationPatchSize_offsetof||0)+")",
    maxTessellationControlPerVertexInputComponents: "u32("+(V.VkPhysicalDeviceLimits_maxTessellationControlPerVertexInputComponents_offsetof||0)+")",
    maxTessellationControlPerVertexOutputComponents: "u32("+(V.VkPhysicalDeviceLimits_maxTessellationControlPerVertexOutputComponents_offsetof||0)+")",
    maxTessellationControlPerPatchOutputComponents: "u32("+(V.VkPhysicalDeviceLimits_maxTessellationControlPerPatchOutputComponents_offsetof||0)+")",
    maxTessellationControlTotalOutputComponents: "u32("+(V.VkPhysicalDeviceLimits_maxTessellationControlTotalOutputComponents_offsetof||0)+")",
    maxTessellationEvaluationInputComponents: "u32("+(V.VkPhysicalDeviceLimits_maxTessellationEvaluationInputComponents_offsetof||0)+")",
    maxTessellationEvaluationOutputComponents: "u32("+(V.VkPhysicalDeviceLimits_maxTessellationEvaluationOutputComponents_offsetof||0)+")",
    maxGeometryShaderInvocations: "u32("+(V.VkPhysicalDeviceLimits_maxGeometryShaderInvocations_offsetof||0)+")",
    maxGeometryInputComponents: "u32("+(V.VkPhysicalDeviceLimits_maxGeometryInputComponents_offsetof||0)+")",
    maxGeometryOutputComponents: "u32("+(V.VkPhysicalDeviceLimits_maxGeometryOutputComponents_offsetof||0)+")",
    maxGeometryOutputVertices: "u32("+(V.VkPhysicalDeviceLimits_maxGeometryOutputVertices_offsetof||0)+")",
    maxGeometryTotalOutputComponents: "u32("+(V.VkPhysicalDeviceLimits_maxGeometryTotalOutputComponents_offsetof||0)+")",
    maxFragmentInputComponents: "u32("+(V.VkPhysicalDeviceLimits_maxFragmentInputComponents_offsetof||0)+")",
    maxFragmentOutputAttachments: "u32("+(V.VkPhysicalDeviceLimits_maxFragmentOutputAttachments_offsetof||0)+")",
    maxFragmentDualSrcAttachments: "u32("+(V.VkPhysicalDeviceLimits_maxFragmentDualSrcAttachments_offsetof||0)+")",
    maxFragmentCombinedOutputResources: "u32("+(V.VkPhysicalDeviceLimits_maxFragmentCombinedOutputResources_offsetof||0)+")",
    maxComputeSharedMemorySize: "u32("+(V.VkPhysicalDeviceLimits_maxComputeSharedMemorySize_offsetof||0)+")",
    maxComputeWorkGroupCount: "u32[3]("+(V.VkPhysicalDeviceLimits_maxComputeWorkGroupCount_offsetof||0)+")",
    maxComputeWorkGroupInvocations: "u32("+(V.VkPhysicalDeviceLimits_maxComputeWorkGroupInvocations_offsetof||0)+")",
    maxComputeWorkGroupSize: "u32[3]("+(V.VkPhysicalDeviceLimits_maxComputeWorkGroupSize_offsetof||0)+")",
    subPixelPrecisionBits: "u32("+(V.VkPhysicalDeviceLimits_subPixelPrecisionBits_offsetof||0)+")",
    subTexelPrecisionBits: "u32("+(V.VkPhysicalDeviceLimits_subTexelPrecisionBits_offsetof||0)+")",
    mipmapPrecisionBits: "u32("+(V.VkPhysicalDeviceLimits_mipmapPrecisionBits_offsetof||0)+")",
    maxDrawIndexedIndexValue: "u32("+(V.VkPhysicalDeviceLimits_maxDrawIndexedIndexValue_offsetof||0)+")",
    maxDrawIndirectCount: "u32("+(V.VkPhysicalDeviceLimits_maxDrawIndirectCount_offsetof||0)+")",
    maxSamplerLodBias: "f32("+(V.VkPhysicalDeviceLimits_maxSamplerLodBias_offsetof||0)+")",
    maxSamplerAnisotropy: "f32("+(V.VkPhysicalDeviceLimits_maxSamplerAnisotropy_offsetof||0)+")",
    maxViewports: "u32("+(V.VkPhysicalDeviceLimits_maxViewports_offsetof||0)+")",
    maxViewportDimensions: "u32[2]("+(V.VkPhysicalDeviceLimits_maxViewportDimensions_offsetof||0)+")",
    viewportBoundsRange: "f32[2]("+(V.VkPhysicalDeviceLimits_viewportBoundsRange_offsetof||0)+")",
    viewportSubPixelBits: "u32("+(V.VkPhysicalDeviceLimits_viewportSubPixelBits_offsetof||0)+")",
    minMemoryMapAlignment: "u64("+(V.VkPhysicalDeviceLimits_minMemoryMapAlignment_offsetof||0)+")",
    minTexelBufferOffsetAlignment: "u64("+(V.VkPhysicalDeviceLimits_minTexelBufferOffsetAlignment_offsetof||0)+")",
    minUniformBufferOffsetAlignment: "u64("+(V.VkPhysicalDeviceLimits_minUniformBufferOffsetAlignment_offsetof||0)+")",
    minStorageBufferOffsetAlignment: "u64("+(V.VkPhysicalDeviceLimits_minStorageBufferOffsetAlignment_offsetof||0)+")",
    minTexelOffset: "i32("+(V.VkPhysicalDeviceLimits_minTexelOffset_offsetof||0)+")",
    maxTexelOffset: "u32("+(V.VkPhysicalDeviceLimits_maxTexelOffset_offsetof||0)+")",
    minTexelGatherOffset: "i32("+(V.VkPhysicalDeviceLimits_minTexelGatherOffset_offsetof||0)+")",
    maxTexelGatherOffset: "u32("+(V.VkPhysicalDeviceLimits_maxTexelGatherOffset_offsetof||0)+")",
    minInterpolationOffset: "f32("+(V.VkPhysicalDeviceLimits_minInterpolationOffset_offsetof||0)+")",
    maxInterpolationOffset: "f32("+(V.VkPhysicalDeviceLimits_maxInterpolationOffset_offsetof||0)+")",
    subPixelInterpolationOffsetBits: "u32("+(V.VkPhysicalDeviceLimits_subPixelInterpolationOffsetBits_offsetof||0)+")",
    maxFramebufferWidth: "u32("+(V.VkPhysicalDeviceLimits_maxFramebufferWidth_offsetof||0)+")",
    maxFramebufferHeight: "u32("+(V.VkPhysicalDeviceLimits_maxFramebufferHeight_offsetof||0)+")",
    maxFramebufferLayers: "u32("+(V.VkPhysicalDeviceLimits_maxFramebufferLayers_offsetof||0)+")",
    framebufferColorSampleCounts: "u32("+(V.VkPhysicalDeviceLimits_framebufferColorSampleCounts_offsetof||0)+")",
    framebufferDepthSampleCounts: "u32("+(V.VkPhysicalDeviceLimits_framebufferDepthSampleCounts_offsetof||0)+")",
    framebufferStencilSampleCounts: "u32("+(V.VkPhysicalDeviceLimits_framebufferStencilSampleCounts_offsetof||0)+")",
    framebufferNoAttachmentsSampleCounts: "u32("+(V.VkPhysicalDeviceLimits_framebufferNoAttachmentsSampleCounts_offsetof||0)+")",
    maxColorAttachments: "u32("+(V.VkPhysicalDeviceLimits_maxColorAttachments_offsetof||0)+")",
    sampledImageColorSampleCounts: "u32("+(V.VkPhysicalDeviceLimits_sampledImageColorSampleCounts_offsetof||0)+")",
    sampledImageIntegerSampleCounts: "u32("+(V.VkPhysicalDeviceLimits_sampledImageIntegerSampleCounts_offsetof||0)+")",
    sampledImageDepthSampleCounts: "u32("+(V.VkPhysicalDeviceLimits_sampledImageDepthSampleCounts_offsetof||0)+")",
    sampledImageStencilSampleCounts: "u32("+(V.VkPhysicalDeviceLimits_sampledImageStencilSampleCounts_offsetof||0)+")",
    storageImageSampleCounts: "u32("+(V.VkPhysicalDeviceLimits_storageImageSampleCounts_offsetof||0)+")",
    maxSampleMaskWords: "u32("+(V.VkPhysicalDeviceLimits_maxSampleMaskWords_offsetof||0)+")",
    timestampComputeAndGraphics: "u32("+(V.VkPhysicalDeviceLimits_timestampComputeAndGraphics_offsetof||0)+")",
    timestampPeriod: "f32("+(V.VkPhysicalDeviceLimits_timestampPeriod_offsetof||0)+")",
    maxClipDistances: "u32("+(V.VkPhysicalDeviceLimits_maxClipDistances_offsetof||0)+")",
    maxCullDistances: "u32("+(V.VkPhysicalDeviceLimits_maxCullDistances_offsetof||0)+")",
    maxCombinedClipAndCullDistances: "u32("+(V.VkPhysicalDeviceLimits_maxCombinedClipAndCullDistances_offsetof||0)+")",
    discreteQueuePriorities: "u32("+(V.VkPhysicalDeviceLimits_discreteQueuePriorities_offsetof||0)+")",
    pointSizeRange: "f32[2]("+(V.VkPhysicalDeviceLimits_pointSizeRange_offsetof||0)+")",
    lineWidthRange: "f32[2]("+(V.VkPhysicalDeviceLimits_lineWidthRange_offsetof||0)+")",
    pointSizeGranularity: "f32("+(V.VkPhysicalDeviceLimits_pointSizeGranularity_offsetof||0)+")",
    lineWidthGranularity: "f32("+(V.VkPhysicalDeviceLimits_lineWidthGranularity_offsetof||0)+")",
    strictLines: "u32("+(V.VkPhysicalDeviceLimits_strictLines_offsetof||0)+")",
    standardSampleLocations: "u32("+(V.VkPhysicalDeviceLimits_standardSampleLocations_offsetof||0)+")",
    optimalBufferCopyOffsetAlignment: "u64("+(V.VkPhysicalDeviceLimits_optimalBufferCopyOffsetAlignment_offsetof||0)+")",
    optimalBufferCopyRowPitchAlignment: "u64("+(V.VkPhysicalDeviceLimits_optimalBufferCopyRowPitchAlignment_offsetof||0)+")",
    nonCoherentAtomSize: "u64("+(V.VkPhysicalDeviceLimits_nonCoherentAtomSize_offsetof||0)+")",
}, (V.VkPhysicalDeviceLimits_sizeof||0))));


const VkSemaphoreCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSemaphoreCreateInfo", {
    sType: "u32("+(V.VkSemaphoreCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSemaphoreCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkSemaphoreCreateInfo_flags_offsetof||0)+")",
}, (V.VkSemaphoreCreateInfo_sizeof||0))));


const VkQueryPoolCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkQueryPoolCreateInfo", {
    sType: "u32("+(V.VkQueryPoolCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkQueryPoolCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkQueryPoolCreateInfo_flags_offsetof||0)+")",
    queryType: "u32("+(V.VkQueryPoolCreateInfo_queryType_offsetof||0)+")",
    queryCount: "u32("+(V.VkQueryPoolCreateInfo_queryCount_offsetof||0)+")",
    pipelineStatistics: "u32("+(V.VkQueryPoolCreateInfo_pipelineStatistics_offsetof||0)+")",
}, (V.VkQueryPoolCreateInfo_sizeof||0))));


const VkFramebufferCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkFramebufferCreateInfo", {
    sType: "u32("+(V.VkFramebufferCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkFramebufferCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkFramebufferCreateInfo_flags_offsetof||0)+")",
    renderPass: "u32("+(V.VkFramebufferCreateInfo_renderPass_offsetof||0)+")",
    attachmentCount: "u32("+(V.VkFramebufferCreateInfo_attachmentCount_offsetof||0)+")",
    pAttachments: "u64("+(V.VkFramebufferCreateInfo_pAttachments_offsetof||0)+")",
    width: "u32("+(V.VkFramebufferCreateInfo_width_offsetof||0)+")",
    height: "u32("+(V.VkFramebufferCreateInfo_height_offsetof||0)+")",
    layers: "u32("+(V.VkFramebufferCreateInfo_layers_offsetof||0)+")",
}, (V.VkFramebufferCreateInfo_sizeof||0))));


const VkDrawIndirectCommand = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDrawIndirectCommand", {
    vertexCount: "u32("+(V.VkDrawIndirectCommand_vertexCount_offsetof||0)+")",
    instanceCount: "u32("+(V.VkDrawIndirectCommand_instanceCount_offsetof||0)+")",
    firstVertex: "u32("+(V.VkDrawIndirectCommand_firstVertex_offsetof||0)+")",
    firstInstance: "u32("+(V.VkDrawIndirectCommand_firstInstance_offsetof||0)+")",
}, (V.VkDrawIndirectCommand_sizeof||0))));


const VkDrawIndexedIndirectCommand = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDrawIndexedIndirectCommand", {
    indexCount: "u32("+(V.VkDrawIndexedIndirectCommand_indexCount_offsetof||0)+")",
    instanceCount: "u32("+(V.VkDrawIndexedIndirectCommand_instanceCount_offsetof||0)+")",
    firstIndex: "u32("+(V.VkDrawIndexedIndirectCommand_firstIndex_offsetof||0)+")",
    vertexOffset: "i32("+(V.VkDrawIndexedIndirectCommand_vertexOffset_offsetof||0)+")",
    firstInstance: "u32("+(V.VkDrawIndexedIndirectCommand_firstInstance_offsetof||0)+")",
}, (V.VkDrawIndexedIndirectCommand_sizeof||0))));


const VkDispatchIndirectCommand = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDispatchIndirectCommand", {
    x: "u32("+(V.VkDispatchIndirectCommand_x_offsetof||0)+")",
    y: "u32("+(V.VkDispatchIndirectCommand_y_offsetof||0)+")",
    z: "u32("+(V.VkDispatchIndirectCommand_z_offsetof||0)+")",
}, (V.VkDispatchIndirectCommand_sizeof||0))));


const VkMultiDrawInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMultiDrawInfoEXT", {
    firstVertex: "u32("+(V.VkMultiDrawInfoEXT_firstVertex_offsetof||0)+")",
    vertexCount: "u32("+(V.VkMultiDrawInfoEXT_vertexCount_offsetof||0)+")",
}, (V.VkMultiDrawInfoEXT_sizeof||0))));


const VkMultiDrawIndexedInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMultiDrawIndexedInfoEXT", {
    firstIndex: "u32("+(V.VkMultiDrawIndexedInfoEXT_firstIndex_offsetof||0)+")",
    indexCount: "u32("+(V.VkMultiDrawIndexedInfoEXT_indexCount_offsetof||0)+")",
    vertexOffset: "i32("+(V.VkMultiDrawIndexedInfoEXT_vertexOffset_offsetof||0)+")",
}, (V.VkMultiDrawIndexedInfoEXT_sizeof||0))));


const VkSubmitInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubmitInfo", {
    sType: "u32("+(V.VkSubmitInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSubmitInfo_pNext_offsetof||0)+")",
    waitSemaphoreCount: "u32("+(V.VkSubmitInfo_waitSemaphoreCount_offsetof||0)+")",
    pWaitSemaphores: "u64("+(V.VkSubmitInfo_pWaitSemaphores_offsetof||0)+")",
    pWaitDstStageMask: "u64("+(V.VkSubmitInfo_pWaitDstStageMask_offsetof||0)+")",
    commandBufferCount: "u32("+(V.VkSubmitInfo_commandBufferCount_offsetof||0)+")",
    pCommandBuffers: "u64("+(V.VkSubmitInfo_pCommandBuffers_offsetof||0)+")",
    signalSemaphoreCount: "u32("+(V.VkSubmitInfo_signalSemaphoreCount_offsetof||0)+")",
    pSignalSemaphores: "u64("+(V.VkSubmitInfo_pSignalSemaphores_offsetof||0)+")",
}, (V.VkSubmitInfo_sizeof||0))));


const VkDisplayPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayPropertiesKHR", {
    display: "u32("+(V.VkDisplayPropertiesKHR_display_offsetof||0)+")",
    displayName: "u64("+(V.VkDisplayPropertiesKHR_displayName_offsetof||0)+")",
    physicalDimensions: "VkExtent2D("+(V.VkDisplayPropertiesKHR_physicalDimensions_offsetof||0)+")",
    physicalResolution: "VkExtent2D("+(V.VkDisplayPropertiesKHR_physicalResolution_offsetof||0)+")",
    supportedTransforms: "u32("+(V.VkDisplayPropertiesKHR_supportedTransforms_offsetof||0)+")",
    planeReorderPossible: "u32("+(V.VkDisplayPropertiesKHR_planeReorderPossible_offsetof||0)+")",
    persistentContent: "u32("+(V.VkDisplayPropertiesKHR_persistentContent_offsetof||0)+")",
}, (V.VkDisplayPropertiesKHR_sizeof||0))));


const VkDisplayPlanePropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayPlanePropertiesKHR", {
    currentDisplay: "u32("+(V.VkDisplayPlanePropertiesKHR_currentDisplay_offsetof||0)+")",
    currentStackIndex: "u32("+(V.VkDisplayPlanePropertiesKHR_currentStackIndex_offsetof||0)+")",
}, (V.VkDisplayPlanePropertiesKHR_sizeof||0))));


const VkDisplayModeParametersKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayModeParametersKHR", {
    visibleRegion: "VkExtent2D("+(V.VkDisplayModeParametersKHR_visibleRegion_offsetof||0)+")",
    refreshRate: "u32("+(V.VkDisplayModeParametersKHR_refreshRate_offsetof||0)+")",
}, (V.VkDisplayModeParametersKHR_sizeof||0))));


const VkDisplayModePropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayModePropertiesKHR", {
    displayMode: "u32("+(V.VkDisplayModePropertiesKHR_displayMode_offsetof||0)+")",
    parameters: "u32("+(V.VkDisplayModePropertiesKHR_parameters_offsetof||0)+")",
}, (V.VkDisplayModePropertiesKHR_sizeof||0))));


const VkDisplayModeCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayModeCreateInfoKHR", {
    sType: "u32("+(V.VkDisplayModeCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDisplayModeCreateInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDisplayModeCreateInfoKHR_flags_offsetof||0)+")",
    parameters: "u32("+(V.VkDisplayModeCreateInfoKHR_parameters_offsetof||0)+")",
}, (V.VkDisplayModeCreateInfoKHR_sizeof||0))));


const VkDisplayPlaneCapabilitiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayPlaneCapabilitiesKHR", {
    supportedAlpha: "u32("+(V.VkDisplayPlaneCapabilitiesKHR_supportedAlpha_offsetof||0)+")",
    minSrcPosition: "VkOffset2D("+(V.VkDisplayPlaneCapabilitiesKHR_minSrcPosition_offsetof||0)+")",
    maxSrcPosition: "VkOffset2D("+(V.VkDisplayPlaneCapabilitiesKHR_maxSrcPosition_offsetof||0)+")",
    minSrcExtent: "VkExtent2D("+(V.VkDisplayPlaneCapabilitiesKHR_minSrcExtent_offsetof||0)+")",
    maxSrcExtent: "VkExtent2D("+(V.VkDisplayPlaneCapabilitiesKHR_maxSrcExtent_offsetof||0)+")",
    minDstPosition: "VkOffset2D("+(V.VkDisplayPlaneCapabilitiesKHR_minDstPosition_offsetof||0)+")",
    maxDstPosition: "VkOffset2D("+(V.VkDisplayPlaneCapabilitiesKHR_maxDstPosition_offsetof||0)+")",
    minDstExtent: "VkExtent2D("+(V.VkDisplayPlaneCapabilitiesKHR_minDstExtent_offsetof||0)+")",
    maxDstExtent: "VkExtent2D("+(V.VkDisplayPlaneCapabilitiesKHR_maxDstExtent_offsetof||0)+")",
}, (V.VkDisplayPlaneCapabilitiesKHR_sizeof||0))));


const VkDisplaySurfaceCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplaySurfaceCreateInfoKHR", {
    sType: "u32("+(V.VkDisplaySurfaceCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDisplaySurfaceCreateInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDisplaySurfaceCreateInfoKHR_flags_offsetof||0)+")",
    displayMode: "u32("+(V.VkDisplaySurfaceCreateInfoKHR_displayMode_offsetof||0)+")",
    planeIndex: "u32("+(V.VkDisplaySurfaceCreateInfoKHR_planeIndex_offsetof||0)+")",
    planeStackIndex: "u32("+(V.VkDisplaySurfaceCreateInfoKHR_planeStackIndex_offsetof||0)+")",
    transform: "u32("+(V.VkDisplaySurfaceCreateInfoKHR_transform_offsetof||0)+")",
    globalAlpha: "f32("+(V.VkDisplaySurfaceCreateInfoKHR_globalAlpha_offsetof||0)+")",
    alphaMode: "u32("+(V.VkDisplaySurfaceCreateInfoKHR_alphaMode_offsetof||0)+")",
    imageExtent: "VkExtent2D("+(V.VkDisplaySurfaceCreateInfoKHR_imageExtent_offsetof||0)+")",
}, (V.VkDisplaySurfaceCreateInfoKHR_sizeof||0))));


const VkDisplayPresentInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayPresentInfoKHR", {
    sType: "u32("+(V.VkDisplayPresentInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDisplayPresentInfoKHR_pNext_offsetof||0)+")",
    srcRect: "VkRect2D("+(V.VkDisplayPresentInfoKHR_srcRect_offsetof||0)+")",
    dstRect: "VkRect2D("+(V.VkDisplayPresentInfoKHR_dstRect_offsetof||0)+")",
    persistent: "u32("+(V.VkDisplayPresentInfoKHR_persistent_offsetof||0)+")",
}, (V.VkDisplayPresentInfoKHR_sizeof||0))));


const VkSurfaceCapabilitiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSurfaceCapabilitiesKHR", {
    minImageCount: "u32("+(V.VkSurfaceCapabilitiesKHR_minImageCount_offsetof||0)+")",
    maxImageCount: "u32("+(V.VkSurfaceCapabilitiesKHR_maxImageCount_offsetof||0)+")",
    currentExtent: "VkExtent2D("+(V.VkSurfaceCapabilitiesKHR_currentExtent_offsetof||0)+")",
    minImageExtent: "VkExtent2D("+(V.VkSurfaceCapabilitiesKHR_minImageExtent_offsetof||0)+")",
    maxImageExtent: "VkExtent2D("+(V.VkSurfaceCapabilitiesKHR_maxImageExtent_offsetof||0)+")",
    maxImageArrayLayers: "u32("+(V.VkSurfaceCapabilitiesKHR_maxImageArrayLayers_offsetof||0)+")",
    supportedTransforms: "u32("+(V.VkSurfaceCapabilitiesKHR_supportedTransforms_offsetof||0)+")",
    currentTransform: "u32("+(V.VkSurfaceCapabilitiesKHR_currentTransform_offsetof||0)+")",
    supportedCompositeAlpha: "u32("+(V.VkSurfaceCapabilitiesKHR_supportedCompositeAlpha_offsetof||0)+")",
    supportedUsageFlags: "u32("+(V.VkSurfaceCapabilitiesKHR_supportedUsageFlags_offsetof||0)+")",
}, (V.VkSurfaceCapabilitiesKHR_sizeof||0))));


const VkAndroidSurfaceCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAndroidSurfaceCreateInfoKHR", {
    sType: "u32("+(V.VkAndroidSurfaceCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAndroidSurfaceCreateInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkAndroidSurfaceCreateInfoKHR_flags_offsetof||0)+")",
    window: "u64("+(V.VkAndroidSurfaceCreateInfoKHR_window_offsetof||0)+")",
}, (V.VkAndroidSurfaceCreateInfoKHR_sizeof||0))));


const VkViSurfaceCreateInfoNN = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkViSurfaceCreateInfoNN", {
    sType: "u32("+(V.VkViSurfaceCreateInfoNN_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkViSurfaceCreateInfoNN_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkViSurfaceCreateInfoNN_flags_offsetof||0)+")",
    window: "u64("+(V.VkViSurfaceCreateInfoNN_window_offsetof||0)+")",
}, (V.VkViSurfaceCreateInfoNN_sizeof||0))));


const VkWaylandSurfaceCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkWaylandSurfaceCreateInfoKHR", {
    sType: "u32("+(V.VkWaylandSurfaceCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkWaylandSurfaceCreateInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkWaylandSurfaceCreateInfoKHR_flags_offsetof||0)+")",
    display: "u64("+(V.VkWaylandSurfaceCreateInfoKHR_display_offsetof||0)+")",
    surface: "u64("+(V.VkWaylandSurfaceCreateInfoKHR_surface_offsetof||0)+")",
}, (V.VkWaylandSurfaceCreateInfoKHR_sizeof||0))));


const VkWin32SurfaceCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkWin32SurfaceCreateInfoKHR", {
    sType: "u32("+(V.VkWin32SurfaceCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkWin32SurfaceCreateInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkWin32SurfaceCreateInfoKHR_flags_offsetof||0)+")",
    hinstance: "u32("+(V.VkWin32SurfaceCreateInfoKHR_hinstance_offsetof||0)+")",
    hwnd: "u32("+(V.VkWin32SurfaceCreateInfoKHR_hwnd_offsetof||0)+")",
}, (V.VkWin32SurfaceCreateInfoKHR_sizeof||0))));


const VkXlibSurfaceCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkXlibSurfaceCreateInfoKHR", {
    sType: "u32("+(V.VkXlibSurfaceCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkXlibSurfaceCreateInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkXlibSurfaceCreateInfoKHR_flags_offsetof||0)+")",
    dpy: "u64("+(V.VkXlibSurfaceCreateInfoKHR_dpy_offsetof||0)+")",
    window: "u32("+(V.VkXlibSurfaceCreateInfoKHR_window_offsetof||0)+")",
}, (V.VkXlibSurfaceCreateInfoKHR_sizeof||0))));


const VkXcbSurfaceCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkXcbSurfaceCreateInfoKHR", {
    sType: "u32("+(V.VkXcbSurfaceCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkXcbSurfaceCreateInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkXcbSurfaceCreateInfoKHR_flags_offsetof||0)+")",
    connection: "u64("+(V.VkXcbSurfaceCreateInfoKHR_connection_offsetof||0)+")",
    window: "u32("+(V.VkXcbSurfaceCreateInfoKHR_window_offsetof||0)+")",
}, (V.VkXcbSurfaceCreateInfoKHR_sizeof||0))));


const VkDirectFBSurfaceCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDirectFBSurfaceCreateInfoEXT", {
    sType: "u32("+(V.VkDirectFBSurfaceCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDirectFBSurfaceCreateInfoEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDirectFBSurfaceCreateInfoEXT_flags_offsetof||0)+")",
    dfb: "u64("+(V.VkDirectFBSurfaceCreateInfoEXT_dfb_offsetof||0)+")",
    surface: "u64("+(V.VkDirectFBSurfaceCreateInfoEXT_surface_offsetof||0)+")",
}, (V.VkDirectFBSurfaceCreateInfoEXT_sizeof||0))));


const VkImagePipeSurfaceCreateInfoFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImagePipeSurfaceCreateInfoFUCHSIA", {
    sType: "u32("+(V.VkImagePipeSurfaceCreateInfoFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImagePipeSurfaceCreateInfoFUCHSIA_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkImagePipeSurfaceCreateInfoFUCHSIA_flags_offsetof||0)+")",
    imagePipeHandle: "u32("+(V.VkImagePipeSurfaceCreateInfoFUCHSIA_imagePipeHandle_offsetof||0)+")",
}, (V.VkImagePipeSurfaceCreateInfoFUCHSIA_sizeof||0))));


const VkStreamDescriptorSurfaceCreateInfoGGP = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkStreamDescriptorSurfaceCreateInfoGGP", {
    sType: "u32("+(V.VkStreamDescriptorSurfaceCreateInfoGGP_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkStreamDescriptorSurfaceCreateInfoGGP_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkStreamDescriptorSurfaceCreateInfoGGP_flags_offsetof||0)+")",
    streamDescriptor: "u32("+(V.VkStreamDescriptorSurfaceCreateInfoGGP_streamDescriptor_offsetof||0)+")",
}, (V.VkStreamDescriptorSurfaceCreateInfoGGP_sizeof||0))));


const VkScreenSurfaceCreateInfoQNX = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkScreenSurfaceCreateInfoQNX", {
    sType: "u32("+(V.VkScreenSurfaceCreateInfoQNX_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkScreenSurfaceCreateInfoQNX_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkScreenSurfaceCreateInfoQNX_flags_offsetof||0)+")",
    context: "u64("+(V.VkScreenSurfaceCreateInfoQNX_context_offsetof||0)+")",
    window: "u64("+(V.VkScreenSurfaceCreateInfoQNX_window_offsetof||0)+")",
}, (V.VkScreenSurfaceCreateInfoQNX_sizeof||0))));


const VkSurfaceFormatKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSurfaceFormatKHR", {
    format: "u32("+(V.VkSurfaceFormatKHR_format_offsetof||0)+")",
    colorSpace: "u32("+(V.VkSurfaceFormatKHR_colorSpace_offsetof||0)+")",
}, (V.VkSurfaceFormatKHR_sizeof||0))));


const VkSwapchainCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSwapchainCreateInfoKHR", {
    sType: "u32("+(V.VkSwapchainCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSwapchainCreateInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkSwapchainCreateInfoKHR_flags_offsetof||0)+")",
    surface: "u64("+(V.VkSwapchainCreateInfoKHR_surface_offsetof||0)+")",
    minImageCount: "u32("+(V.VkSwapchainCreateInfoKHR_minImageCount_offsetof||0)+")",
    imageFormat: "u32("+(V.VkSwapchainCreateInfoKHR_imageFormat_offsetof||0)+")",
    imageColorSpace: "u32("+(V.VkSwapchainCreateInfoKHR_imageColorSpace_offsetof||0)+")",
    imageExtent: "VkExtent2D("+(V.VkSwapchainCreateInfoKHR_imageExtent_offsetof||0)+")",
    imageArrayLayers: "u32("+(V.VkSwapchainCreateInfoKHR_imageArrayLayers_offsetof||0)+")",
    imageUsage: "u32("+(V.VkSwapchainCreateInfoKHR_imageUsage_offsetof||0)+")",
    imageSharingMode: "u32("+(V.VkSwapchainCreateInfoKHR_imageSharingMode_offsetof||0)+")",
    queueFamilyIndexCount: "u32("+(V.VkSwapchainCreateInfoKHR_queueFamilyIndexCount_offsetof||0)+")",
    pQueueFamilyIndices: "u64("+(V.VkSwapchainCreateInfoKHR_pQueueFamilyIndices_offsetof||0)+")",
    preTransform: "u32("+(V.VkSwapchainCreateInfoKHR_preTransform_offsetof||0)+")",
    compositeAlpha: "u32("+(V.VkSwapchainCreateInfoKHR_compositeAlpha_offsetof||0)+")",
    presentMode: "u32("+(V.VkSwapchainCreateInfoKHR_presentMode_offsetof||0)+")",
    clipped: "u32("+(V.VkSwapchainCreateInfoKHR_clipped_offsetof||0)+")",
    oldSwapchain: "u64("+(V.VkSwapchainCreateInfoKHR_oldSwapchain_offsetof||0)+")",
}, (V.VkSwapchainCreateInfoKHR_sizeof||0))));


const VkPresentInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPresentInfoKHR", {
    sType: "u32("+(V.VkPresentInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPresentInfoKHR_pNext_offsetof||0)+")",
    waitSemaphoreCount: "u32("+(V.VkPresentInfoKHR_waitSemaphoreCount_offsetof||0)+")",
    pWaitSemaphores: "u64("+(V.VkPresentInfoKHR_pWaitSemaphores_offsetof||0)+")",
    swapchainCount: "u32("+(V.VkPresentInfoKHR_swapchainCount_offsetof||0)+")",
    pSwapchains: "u64("+(V.VkPresentInfoKHR_pSwapchains_offsetof||0)+")",
    pImageIndices: "u64("+(V.VkPresentInfoKHR_pImageIndices_offsetof||0)+")",
    pResults: "u64("+(V.VkPresentInfoKHR_pResults_offsetof||0)+")",
}, (V.VkPresentInfoKHR_sizeof||0))));


const VkDebugReportCallbackCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDebugReportCallbackCreateInfoEXT", {
    sType: "u32("+(V.VkDebugReportCallbackCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDebugReportCallbackCreateInfoEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDebugReportCallbackCreateInfoEXT_flags_offsetof||0)+")",
    pfnCallback: "u32("+(V.VkDebugReportCallbackCreateInfoEXT_pfnCallback_offsetof||0)+")",
    pUserData: "u64("+(V.VkDebugReportCallbackCreateInfoEXT_pUserData_offsetof||0)+")",
}, (V.VkDebugReportCallbackCreateInfoEXT_sizeof||0))));


const VkValidationFlagsEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkValidationFlagsEXT", {
    sType: "u32("+(V.VkValidationFlagsEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkValidationFlagsEXT_pNext_offsetof||0)+")",
    disabledValidationCheckCount: "u32("+(V.VkValidationFlagsEXT_disabledValidationCheckCount_offsetof||0)+")",
    pDisabledValidationChecks: "u64("+(V.VkValidationFlagsEXT_pDisabledValidationChecks_offsetof||0)+")",
}, (V.VkValidationFlagsEXT_sizeof||0))));


const VkValidationFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkValidationFeaturesEXT", {
    sType: "u32("+(V.VkValidationFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkValidationFeaturesEXT_pNext_offsetof||0)+")",
    enabledValidationFeatureCount: "u32("+(V.VkValidationFeaturesEXT_enabledValidationFeatureCount_offsetof||0)+")",
    pEnabledValidationFeatures: "u64("+(V.VkValidationFeaturesEXT_pEnabledValidationFeatures_offsetof||0)+")",
    disabledValidationFeatureCount: "u32("+(V.VkValidationFeaturesEXT_disabledValidationFeatureCount_offsetof||0)+")",
    pDisabledValidationFeatures: "u64("+(V.VkValidationFeaturesEXT_pDisabledValidationFeatures_offsetof||0)+")",
}, (V.VkValidationFeaturesEXT_sizeof||0))));


const VkPipelineRasterizationStateRasterizationOrderAMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineRasterizationStateRasterizationOrderAMD", {
    sType: "u32("+(V.VkPipelineRasterizationStateRasterizationOrderAMD_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineRasterizationStateRasterizationOrderAMD_pNext_offsetof||0)+")",
    rasterizationOrder: "u32("+(V.VkPipelineRasterizationStateRasterizationOrderAMD_rasterizationOrder_offsetof||0)+")",
}, (V.VkPipelineRasterizationStateRasterizationOrderAMD_sizeof||0))));


const VkDebugMarkerObjectNameInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDebugMarkerObjectNameInfoEXT", {
    sType: "u32("+(V.VkDebugMarkerObjectNameInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDebugMarkerObjectNameInfoEXT_pNext_offsetof||0)+")",
    objectType: "u32("+(V.VkDebugMarkerObjectNameInfoEXT_objectType_offsetof||0)+")",
    object: "u64("+(V.VkDebugMarkerObjectNameInfoEXT_object_offsetof||0)+")",
    pObjectName: "u64("+(V.VkDebugMarkerObjectNameInfoEXT_pObjectName_offsetof||0)+")",
}, (V.VkDebugMarkerObjectNameInfoEXT_sizeof||0))));


const VkDebugMarkerObjectTagInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDebugMarkerObjectTagInfoEXT", {
    sType: "u32("+(V.VkDebugMarkerObjectTagInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDebugMarkerObjectTagInfoEXT_pNext_offsetof||0)+")",
    objectType: "u32("+(V.VkDebugMarkerObjectTagInfoEXT_objectType_offsetof||0)+")",
    object: "u64("+(V.VkDebugMarkerObjectTagInfoEXT_object_offsetof||0)+")",
    tagName: "u64("+(V.VkDebugMarkerObjectTagInfoEXT_tagName_offsetof||0)+")",
    tagSize: "u64("+(V.VkDebugMarkerObjectTagInfoEXT_tagSize_offsetof||0)+")",
    pTag: "u64("+(V.VkDebugMarkerObjectTagInfoEXT_pTag_offsetof||0)+")",
}, (V.VkDebugMarkerObjectTagInfoEXT_sizeof||0))));


const VkDebugMarkerMarkerInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDebugMarkerMarkerInfoEXT", {
    sType: "u32("+(V.VkDebugMarkerMarkerInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDebugMarkerMarkerInfoEXT_pNext_offsetof||0)+")",
    pMarkerName: "u64("+(V.VkDebugMarkerMarkerInfoEXT_pMarkerName_offsetof||0)+")",
    color: "f32[4]("+(V.VkDebugMarkerMarkerInfoEXT_color_offsetof||0)+")",
}, (V.VkDebugMarkerMarkerInfoEXT_sizeof||0))));


const VkDedicatedAllocationImageCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDedicatedAllocationImageCreateInfoNV", {
    sType: "u32("+(V.VkDedicatedAllocationImageCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDedicatedAllocationImageCreateInfoNV_pNext_offsetof||0)+")",
    dedicatedAllocation: "u32("+(V.VkDedicatedAllocationImageCreateInfoNV_dedicatedAllocation_offsetof||0)+")",
}, (V.VkDedicatedAllocationImageCreateInfoNV_sizeof||0))));


const VkDedicatedAllocationBufferCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDedicatedAllocationBufferCreateInfoNV", {
    sType: "u32("+(V.VkDedicatedAllocationBufferCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDedicatedAllocationBufferCreateInfoNV_pNext_offsetof||0)+")",
    dedicatedAllocation: "u32("+(V.VkDedicatedAllocationBufferCreateInfoNV_dedicatedAllocation_offsetof||0)+")",
}, (V.VkDedicatedAllocationBufferCreateInfoNV_sizeof||0))));


const VkDedicatedAllocationMemoryAllocateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDedicatedAllocationMemoryAllocateInfoNV", {
    sType: "u32("+(V.VkDedicatedAllocationMemoryAllocateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDedicatedAllocationMemoryAllocateInfoNV_pNext_offsetof||0)+")",
    image: "u64("+(V.VkDedicatedAllocationMemoryAllocateInfoNV_image_offsetof||0)+")",
    buffer: "u64("+(V.VkDedicatedAllocationMemoryAllocateInfoNV_buffer_offsetof||0)+")",
}, (V.VkDedicatedAllocationMemoryAllocateInfoNV_sizeof||0))));


const VkExternalImageFormatPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExternalImageFormatPropertiesNV", {
    imageFormatProperties: "u32("+(V.VkExternalImageFormatPropertiesNV_imageFormatProperties_offsetof||0)+")",
    externalMemoryFeatures: "u32("+(V.VkExternalImageFormatPropertiesNV_externalMemoryFeatures_offsetof||0)+")",
    exportFromImportedHandleTypes: "u32("+(V.VkExternalImageFormatPropertiesNV_exportFromImportedHandleTypes_offsetof||0)+")",
    compatibleHandleTypes: "u32("+(V.VkExternalImageFormatPropertiesNV_compatibleHandleTypes_offsetof||0)+")",
}, (V.VkExternalImageFormatPropertiesNV_sizeof||0))));


const VkExternalMemoryImageCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExternalMemoryImageCreateInfoNV", {
    sType: "u32("+(V.VkExternalMemoryImageCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExternalMemoryImageCreateInfoNV_pNext_offsetof||0)+")",
    handleTypes: "u32("+(V.VkExternalMemoryImageCreateInfoNV_handleTypes_offsetof||0)+")",
}, (V.VkExternalMemoryImageCreateInfoNV_sizeof||0))));


const VkExportMemoryAllocateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportMemoryAllocateInfoNV", {
    sType: "u32("+(V.VkExportMemoryAllocateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportMemoryAllocateInfoNV_pNext_offsetof||0)+")",
    handleTypes: "u32("+(V.VkExportMemoryAllocateInfoNV_handleTypes_offsetof||0)+")",
}, (V.VkExportMemoryAllocateInfoNV_sizeof||0))));


const VkImportMemoryWin32HandleInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportMemoryWin32HandleInfoNV", {
    sType: "u32("+(V.VkImportMemoryWin32HandleInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportMemoryWin32HandleInfoNV_pNext_offsetof||0)+")",
    handleType: "u32("+(V.VkImportMemoryWin32HandleInfoNV_handleType_offsetof||0)+")",
    handle: "u64("+(V.VkImportMemoryWin32HandleInfoNV_handle_offsetof||0)+")",
}, (V.VkImportMemoryWin32HandleInfoNV_sizeof||0))));


const VkExportMemoryWin32HandleInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportMemoryWin32HandleInfoNV", {
    sType: "u32("+(V.VkExportMemoryWin32HandleInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportMemoryWin32HandleInfoNV_pNext_offsetof||0)+")",
    pAttributes: "u64("+(V.VkExportMemoryWin32HandleInfoNV_pAttributes_offsetof||0)+")",
    dwAccess: "u32("+(V.VkExportMemoryWin32HandleInfoNV_dwAccess_offsetof||0)+")",
}, (V.VkExportMemoryWin32HandleInfoNV_sizeof||0))));


const VkWin32KeyedMutexAcquireReleaseInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkWin32KeyedMutexAcquireReleaseInfoNV", {
    sType: "u32("+(V.VkWin32KeyedMutexAcquireReleaseInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkWin32KeyedMutexAcquireReleaseInfoNV_pNext_offsetof||0)+")",
    acquireCount: "u32("+(V.VkWin32KeyedMutexAcquireReleaseInfoNV_acquireCount_offsetof||0)+")",
    pAcquireSyncs: "u64("+(V.VkWin32KeyedMutexAcquireReleaseInfoNV_pAcquireSyncs_offsetof||0)+")",
    pAcquireKeys: "u64("+(V.VkWin32KeyedMutexAcquireReleaseInfoNV_pAcquireKeys_offsetof||0)+")",
    pAcquireTimeoutMilliseconds: "u64("+(V.VkWin32KeyedMutexAcquireReleaseInfoNV_pAcquireTimeoutMilliseconds_offsetof||0)+")",
    releaseCount: "u32("+(V.VkWin32KeyedMutexAcquireReleaseInfoNV_releaseCount_offsetof||0)+")",
    pReleaseSyncs: "u64("+(V.VkWin32KeyedMutexAcquireReleaseInfoNV_pReleaseSyncs_offsetof||0)+")",
    pReleaseKeys: "u64("+(V.VkWin32KeyedMutexAcquireReleaseInfoNV_pReleaseKeys_offsetof||0)+")",
}, (V.VkWin32KeyedMutexAcquireReleaseInfoNV_sizeof||0))));


const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV_pNext_offsetof||0)+")",
    deviceGeneratedCommands: "u32("+(V.VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV_deviceGeneratedCommands_offsetof||0)+")",
}, (V.VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV_sizeof||0))));


const VkDevicePrivateDataCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDevicePrivateDataCreateInfo", {
    sType: "u32("+(V.VkDevicePrivateDataCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDevicePrivateDataCreateInfo_pNext_offsetof||0)+")",
    privateDataSlotRequestCount: "u32("+(V.VkDevicePrivateDataCreateInfo_privateDataSlotRequestCount_offsetof||0)+")",
}, (V.VkDevicePrivateDataCreateInfo_sizeof||0))));

const VkDevicePrivateDataCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy("VkDevicePrivateDataCreateInfo"));


const VkPrivateDataSlotCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPrivateDataSlotCreateInfo", {
    sType: "u32("+(V.VkPrivateDataSlotCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPrivateDataSlotCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPrivateDataSlotCreateInfo_flags_offsetof||0)+")",
}, (V.VkPrivateDataSlotCreateInfo_sizeof||0))));

const VkPrivateDataSlotCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy("VkPrivateDataSlotCreateInfo"));


const VkPhysicalDevicePrivateDataFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePrivateDataFeatures", {
    sType: "u32("+(V.VkPhysicalDevicePrivateDataFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePrivateDataFeatures_pNext_offsetof||0)+")",
    privateData: "u32("+(V.VkPhysicalDevicePrivateDataFeatures_privateData_offsetof||0)+")",
}, (V.VkPhysicalDevicePrivateDataFeatures_sizeof||0))));

const VkPhysicalDevicePrivateDataFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDevicePrivateDataFeatures"));


const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV", {
    sType: "u32("+(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_pNext_offsetof||0)+")",
    maxGraphicsShaderGroupCount: "u32("+(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_maxGraphicsShaderGroupCount_offsetof||0)+")",
    maxIndirectSequenceCount: "u32("+(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_maxIndirectSequenceCount_offsetof||0)+")",
    maxIndirectCommandsTokenCount: "u32("+(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_maxIndirectCommandsTokenCount_offsetof||0)+")",
    maxIndirectCommandsStreamCount: "u32("+(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_maxIndirectCommandsStreamCount_offsetof||0)+")",
    maxIndirectCommandsTokenOffset: "u32("+(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_maxIndirectCommandsTokenOffset_offsetof||0)+")",
    maxIndirectCommandsStreamStride: "u32("+(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_maxIndirectCommandsStreamStride_offsetof||0)+")",
    minSequencesCountBufferOffsetAlignment: "u32("+(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_minSequencesCountBufferOffsetAlignment_offsetof||0)+")",
    minSequencesIndexBufferOffsetAlignment: "u32("+(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_minSequencesIndexBufferOffsetAlignment_offsetof||0)+")",
    minIndirectCommandsBufferOffsetAlignment: "u32("+(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_minIndirectCommandsBufferOffsetAlignment_offsetof||0)+")",
}, (V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_sizeof||0))));


const VkPhysicalDeviceMultiDrawPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMultiDrawPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceMultiDrawPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMultiDrawPropertiesEXT_pNext_offsetof||0)+")",
    maxMultiDrawCount: "u32("+(V.VkPhysicalDeviceMultiDrawPropertiesEXT_maxMultiDrawCount_offsetof||0)+")",
}, (V.VkPhysicalDeviceMultiDrawPropertiesEXT_sizeof||0))));


const VkGraphicsShaderGroupCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkGraphicsShaderGroupCreateInfoNV", {
    sType: "u32("+(V.VkGraphicsShaderGroupCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkGraphicsShaderGroupCreateInfoNV_pNext_offsetof||0)+")",
    stageCount: "u32("+(V.VkGraphicsShaderGroupCreateInfoNV_stageCount_offsetof||0)+")",
    pStages: "u64("+(V.VkGraphicsShaderGroupCreateInfoNV_pStages_offsetof||0)+")",
    pVertexInputState: "u64("+(V.VkGraphicsShaderGroupCreateInfoNV_pVertexInputState_offsetof||0)+")",
    pTessellationState: "u64("+(V.VkGraphicsShaderGroupCreateInfoNV_pTessellationState_offsetof||0)+")",
}, (V.VkGraphicsShaderGroupCreateInfoNV_sizeof||0))));


const VkGraphicsPipelineShaderGroupsCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkGraphicsPipelineShaderGroupsCreateInfoNV", {
    sType: "u32("+(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_pNext_offsetof||0)+")",
    groupCount: "u32("+(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_groupCount_offsetof||0)+")",
    pGroups: "u64("+(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_pGroups_offsetof||0)+")",
    pipelineCount: "u32("+(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_pipelineCount_offsetof||0)+")",
    pPipelines: "u64("+(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_pPipelines_offsetof||0)+")",
}, (V.VkGraphicsPipelineShaderGroupsCreateInfoNV_sizeof||0))));


const VkBindShaderGroupIndirectCommandNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBindShaderGroupIndirectCommandNV", {
    groupIndex: "u32("+(V.VkBindShaderGroupIndirectCommandNV_groupIndex_offsetof||0)+")",
}, (V.VkBindShaderGroupIndirectCommandNV_sizeof||0))));


const VkBindIndexBufferIndirectCommandNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBindIndexBufferIndirectCommandNV", {
    bufferAddress: "u64("+(V.VkBindIndexBufferIndirectCommandNV_bufferAddress_offsetof||0)+")",
    size: "u32("+(V.VkBindIndexBufferIndirectCommandNV_size_offsetof||0)+")",
    indexType: "u32("+(V.VkBindIndexBufferIndirectCommandNV_indexType_offsetof||0)+")",
}, (V.VkBindIndexBufferIndirectCommandNV_sizeof||0))));


const VkBindVertexBufferIndirectCommandNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBindVertexBufferIndirectCommandNV", {
    bufferAddress: "u64("+(V.VkBindVertexBufferIndirectCommandNV_bufferAddress_offsetof||0)+")",
    size: "u32("+(V.VkBindVertexBufferIndirectCommandNV_size_offsetof||0)+")",
    stride: "u32("+(V.VkBindVertexBufferIndirectCommandNV_stride_offsetof||0)+")",
}, (V.VkBindVertexBufferIndirectCommandNV_sizeof||0))));


const VkSetStateFlagsIndirectCommandNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSetStateFlagsIndirectCommandNV", {
    data: "u32("+(V.VkSetStateFlagsIndirectCommandNV_data_offsetof||0)+")",
}, (V.VkSetStateFlagsIndirectCommandNV_sizeof||0))));


const VkIndirectCommandsStreamNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkIndirectCommandsStreamNV", {
    buffer: "u64("+(V.VkIndirectCommandsStreamNV_buffer_offsetof||0)+")",
    offset: "u64("+(V.VkIndirectCommandsStreamNV_offset_offsetof||0)+")",
}, (V.VkIndirectCommandsStreamNV_sizeof||0))));


const VkIndirectCommandsLayoutTokenNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkIndirectCommandsLayoutTokenNV", {
    sType: "u32("+(V.VkIndirectCommandsLayoutTokenNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkIndirectCommandsLayoutTokenNV_pNext_offsetof||0)+")",
    tokenType: "u32("+(V.VkIndirectCommandsLayoutTokenNV_tokenType_offsetof||0)+")",
    stream: "u32("+(V.VkIndirectCommandsLayoutTokenNV_stream_offsetof||0)+")",
    offset: "u32("+(V.VkIndirectCommandsLayoutTokenNV_offset_offsetof||0)+")",
    vertexBindingUnit: "u32("+(V.VkIndirectCommandsLayoutTokenNV_vertexBindingUnit_offsetof||0)+")",
    vertexDynamicStride: "u32("+(V.VkIndirectCommandsLayoutTokenNV_vertexDynamicStride_offsetof||0)+")",
    pushconstantPipelineLayout: "u64("+(V.VkIndirectCommandsLayoutTokenNV_pushconstantPipelineLayout_offsetof||0)+")",
    pushconstantShaderStageFlags: "u32("+(V.VkIndirectCommandsLayoutTokenNV_pushconstantShaderStageFlags_offsetof||0)+")",
    pushconstantOffset: "u32("+(V.VkIndirectCommandsLayoutTokenNV_pushconstantOffset_offsetof||0)+")",
    pushconstantSize: "u32("+(V.VkIndirectCommandsLayoutTokenNV_pushconstantSize_offsetof||0)+")",
    indirectStateFlags: "u32("+(V.VkIndirectCommandsLayoutTokenNV_indirectStateFlags_offsetof||0)+")",
    indexTypeCount: "u32("+(V.VkIndirectCommandsLayoutTokenNV_indexTypeCount_offsetof||0)+")",
    pIndexTypes: "u64("+(V.VkIndirectCommandsLayoutTokenNV_pIndexTypes_offsetof||0)+")",
    pIndexTypeValues: "u64("+(V.VkIndirectCommandsLayoutTokenNV_pIndexTypeValues_offsetof||0)+")",
}, (V.VkIndirectCommandsLayoutTokenNV_sizeof||0))));


const VkIndirectCommandsLayoutCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkIndirectCommandsLayoutCreateInfoNV", {
    sType: "u32("+(V.VkIndirectCommandsLayoutCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkIndirectCommandsLayoutCreateInfoNV_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkIndirectCommandsLayoutCreateInfoNV_flags_offsetof||0)+")",
    pipelineBindPoint: "u32("+(V.VkIndirectCommandsLayoutCreateInfoNV_pipelineBindPoint_offsetof||0)+")",
    tokenCount: "u32("+(V.VkIndirectCommandsLayoutCreateInfoNV_tokenCount_offsetof||0)+")",
    pTokens: "u64("+(V.VkIndirectCommandsLayoutCreateInfoNV_pTokens_offsetof||0)+")",
    streamCount: "u32("+(V.VkIndirectCommandsLayoutCreateInfoNV_streamCount_offsetof||0)+")",
    pStreamStrides: "u64("+(V.VkIndirectCommandsLayoutCreateInfoNV_pStreamStrides_offsetof||0)+")",
}, (V.VkIndirectCommandsLayoutCreateInfoNV_sizeof||0))));


const VkGeneratedCommandsInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkGeneratedCommandsInfoNV", {
    sType: "u32("+(V.VkGeneratedCommandsInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkGeneratedCommandsInfoNV_pNext_offsetof||0)+")",
    pipelineBindPoint: "u32("+(V.VkGeneratedCommandsInfoNV_pipelineBindPoint_offsetof||0)+")",
    pipeline: "u64("+(V.VkGeneratedCommandsInfoNV_pipeline_offsetof||0)+")",
    indirectCommandsLayout: "u32("+(V.VkGeneratedCommandsInfoNV_indirectCommandsLayout_offsetof||0)+")",
    streamCount: "u32("+(V.VkGeneratedCommandsInfoNV_streamCount_offsetof||0)+")",
    pStreams: "u64("+(V.VkGeneratedCommandsInfoNV_pStreams_offsetof||0)+")",
    sequencesCount: "u32("+(V.VkGeneratedCommandsInfoNV_sequencesCount_offsetof||0)+")",
    preprocessBuffer: "u64("+(V.VkGeneratedCommandsInfoNV_preprocessBuffer_offsetof||0)+")",
    preprocessOffset: "u64("+(V.VkGeneratedCommandsInfoNV_preprocessOffset_offsetof||0)+")",
    preprocessSize: "u64("+(V.VkGeneratedCommandsInfoNV_preprocessSize_offsetof||0)+")",
    sequencesCountBuffer: "u64("+(V.VkGeneratedCommandsInfoNV_sequencesCountBuffer_offsetof||0)+")",
    sequencesCountOffset: "u64("+(V.VkGeneratedCommandsInfoNV_sequencesCountOffset_offsetof||0)+")",
    sequencesIndexBuffer: "u64("+(V.VkGeneratedCommandsInfoNV_sequencesIndexBuffer_offsetof||0)+")",
    sequencesIndexOffset: "u64("+(V.VkGeneratedCommandsInfoNV_sequencesIndexOffset_offsetof||0)+")",
}, (V.VkGeneratedCommandsInfoNV_sizeof||0))));


const VkGeneratedCommandsMemoryRequirementsInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkGeneratedCommandsMemoryRequirementsInfoNV", {
    sType: "u32("+(V.VkGeneratedCommandsMemoryRequirementsInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkGeneratedCommandsMemoryRequirementsInfoNV_pNext_offsetof||0)+")",
    pipelineBindPoint: "u32("+(V.VkGeneratedCommandsMemoryRequirementsInfoNV_pipelineBindPoint_offsetof||0)+")",
    pipeline: "u64("+(V.VkGeneratedCommandsMemoryRequirementsInfoNV_pipeline_offsetof||0)+")",
    indirectCommandsLayout: "u32("+(V.VkGeneratedCommandsMemoryRequirementsInfoNV_indirectCommandsLayout_offsetof||0)+")",
    maxSequencesCount: "u32("+(V.VkGeneratedCommandsMemoryRequirementsInfoNV_maxSequencesCount_offsetof||0)+")",
}, (V.VkGeneratedCommandsMemoryRequirementsInfoNV_sizeof||0))));


const VkPhysicalDeviceFeatures2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFeatures2", {
    sType: "u32("+(V.VkPhysicalDeviceFeatures2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFeatures2_pNext_offsetof||0)+")",
    features: "u32("+(V.VkPhysicalDeviceFeatures2_features_offsetof||0)+")",
}, (V.VkPhysicalDeviceFeatures2_sizeof||0))));

const VkPhysicalDeviceFeatures2KHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceFeatures2"));


const VkPhysicalDeviceProperties2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceProperties2", {
    sType: "u32("+(V.VkPhysicalDeviceProperties2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceProperties2_pNext_offsetof||0)+")",
    properties: "u32("+(V.VkPhysicalDeviceProperties2_properties_offsetof||0)+")",
}, (V.VkPhysicalDeviceProperties2_sizeof||0))));

const VkPhysicalDeviceProperties2KHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceProperties2"));


const VkFormatProperties2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkFormatProperties2", {
    sType: "u32("+(V.VkFormatProperties2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkFormatProperties2_pNext_offsetof||0)+")",
    formatProperties: "u32("+(V.VkFormatProperties2_formatProperties_offsetof||0)+")",
}, (V.VkFormatProperties2_sizeof||0))));

const VkFormatProperties2KHR = new Proxy(function(){}, new C.ConstructProxy("VkFormatProperties2"));


const VkImageFormatProperties2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageFormatProperties2", {
    sType: "u32("+(V.VkImageFormatProperties2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageFormatProperties2_pNext_offsetof||0)+")",
    imageFormatProperties: "u32("+(V.VkImageFormatProperties2_imageFormatProperties_offsetof||0)+")",
}, (V.VkImageFormatProperties2_sizeof||0))));

const VkImageFormatProperties2KHR = new Proxy(function(){}, new C.ConstructProxy("VkImageFormatProperties2"));


const VkPhysicalDeviceImageFormatInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceImageFormatInfo2", {
    sType: "u32("+(V.VkPhysicalDeviceImageFormatInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceImageFormatInfo2_pNext_offsetof||0)+")",
    format: "u32("+(V.VkPhysicalDeviceImageFormatInfo2_format_offsetof||0)+")",
    type: "u32("+(V.VkPhysicalDeviceImageFormatInfo2_type_offsetof||0)+")",
    tiling: "u32("+(V.VkPhysicalDeviceImageFormatInfo2_tiling_offsetof||0)+")",
    usage: "u32("+(V.VkPhysicalDeviceImageFormatInfo2_usage_offsetof||0)+")",
    flags: "u32("+(V.VkPhysicalDeviceImageFormatInfo2_flags_offsetof||0)+")",
}, (V.VkPhysicalDeviceImageFormatInfo2_sizeof||0))));

const VkPhysicalDeviceImageFormatInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceImageFormatInfo2"));


const VkQueueFamilyProperties2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkQueueFamilyProperties2", {
    sType: "u32("+(V.VkQueueFamilyProperties2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkQueueFamilyProperties2_pNext_offsetof||0)+")",
    queueFamilyProperties: "u32("+(V.VkQueueFamilyProperties2_queueFamilyProperties_offsetof||0)+")",
}, (V.VkQueueFamilyProperties2_sizeof||0))));

const VkQueueFamilyProperties2KHR = new Proxy(function(){}, new C.ConstructProxy("VkQueueFamilyProperties2"));


const VkPhysicalDeviceMemoryProperties2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMemoryProperties2", {
    sType: "u32("+(V.VkPhysicalDeviceMemoryProperties2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMemoryProperties2_pNext_offsetof||0)+")",
    memoryProperties: "u32("+(V.VkPhysicalDeviceMemoryProperties2_memoryProperties_offsetof||0)+")",
}, (V.VkPhysicalDeviceMemoryProperties2_sizeof||0))));

const VkPhysicalDeviceMemoryProperties2KHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceMemoryProperties2"));


const VkSparseImageFormatProperties2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSparseImageFormatProperties2", {
    sType: "u32("+(V.VkSparseImageFormatProperties2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSparseImageFormatProperties2_pNext_offsetof||0)+")",
    properties: "u32("+(V.VkSparseImageFormatProperties2_properties_offsetof||0)+")",
}, (V.VkSparseImageFormatProperties2_sizeof||0))));

const VkSparseImageFormatProperties2KHR = new Proxy(function(){}, new C.ConstructProxy("VkSparseImageFormatProperties2"));


const VkPhysicalDeviceSparseImageFormatInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSparseImageFormatInfo2", {
    sType: "u32("+(V.VkPhysicalDeviceSparseImageFormatInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSparseImageFormatInfo2_pNext_offsetof||0)+")",
    format: "u32("+(V.VkPhysicalDeviceSparseImageFormatInfo2_format_offsetof||0)+")",
    type: "u32("+(V.VkPhysicalDeviceSparseImageFormatInfo2_type_offsetof||0)+")",
    samples: "u32("+(V.VkPhysicalDeviceSparseImageFormatInfo2_samples_offsetof||0)+")",
    usage: "u32("+(V.VkPhysicalDeviceSparseImageFormatInfo2_usage_offsetof||0)+")",
    tiling: "u32("+(V.VkPhysicalDeviceSparseImageFormatInfo2_tiling_offsetof||0)+")",
}, (V.VkPhysicalDeviceSparseImageFormatInfo2_sizeof||0))));

const VkPhysicalDeviceSparseImageFormatInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceSparseImageFormatInfo2"));


const VkPhysicalDevicePushDescriptorPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePushDescriptorPropertiesKHR", {
    sType: "u32("+(V.VkPhysicalDevicePushDescriptorPropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePushDescriptorPropertiesKHR_pNext_offsetof||0)+")",
    maxPushDescriptors: "u32("+(V.VkPhysicalDevicePushDescriptorPropertiesKHR_maxPushDescriptors_offsetof||0)+")",
}, (V.VkPhysicalDevicePushDescriptorPropertiesKHR_sizeof||0))));


const VkConformanceVersion = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkConformanceVersion", {
    major: "u8("+(V.VkConformanceVersion_major_offsetof||0)+")",
    minor: "u8("+(V.VkConformanceVersion_minor_offsetof||0)+")",
    subminor: "u8("+(V.VkConformanceVersion_subminor_offsetof||0)+")",
    patch: "u8("+(V.VkConformanceVersion_patch_offsetof||0)+")",
}, (V.VkConformanceVersion_sizeof||0))));

const VkConformanceVersionKHR = new Proxy(function(){}, new C.ConstructProxy("VkConformanceVersion"));


const VkPhysicalDeviceDriverProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDriverProperties", {
    sType: "u32("+(V.VkPhysicalDeviceDriverProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDriverProperties_pNext_offsetof||0)+")",
    driverID: "u32("+(V.VkPhysicalDeviceDriverProperties_driverID_offsetof||0)+")",
    driverName: "u8["+(E.VK_MAX_DRIVER_NAME_SIZE||1)+"]("+(V.VkPhysicalDeviceDriverProperties_driverName_offsetof||0)+")",
    driverInfo: "u8["+(E.VK_MAX_DRIVER_INFO_SIZE||1)+"]("+(V.VkPhysicalDeviceDriverProperties_driverInfo_offsetof||0)+")",
    conformanceVersion: "u32("+(V.VkPhysicalDeviceDriverProperties_conformanceVersion_offsetof||0)+")",
}, (V.VkPhysicalDeviceDriverProperties_sizeof||0))));

const VkPhysicalDeviceDriverPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceDriverProperties"));


const VkPresentRegionsKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPresentRegionsKHR", {
    sType: "u32("+(V.VkPresentRegionsKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPresentRegionsKHR_pNext_offsetof||0)+")",
    swapchainCount: "u32("+(V.VkPresentRegionsKHR_swapchainCount_offsetof||0)+")",
    pRegions: "u64("+(V.VkPresentRegionsKHR_pRegions_offsetof||0)+")",
}, (V.VkPresentRegionsKHR_sizeof||0))));


const VkPresentRegionKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPresentRegionKHR", {
    rectangleCount: "u32("+(V.VkPresentRegionKHR_rectangleCount_offsetof||0)+")",
    pRectangles: "u64("+(V.VkPresentRegionKHR_pRectangles_offsetof||0)+")",
}, (V.VkPresentRegionKHR_sizeof||0))));


const VkRectLayerKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRectLayerKHR", {
    offset: "VkOffset2D("+(V.VkRectLayerKHR_offset_offsetof||0)+")",
    extent: "VkExtent2D("+(V.VkRectLayerKHR_extent_offsetof||0)+")",
    layer: "u32("+(V.VkRectLayerKHR_layer_offsetof||0)+")",
}, (V.VkRectLayerKHR_sizeof||0))));


const VkPhysicalDeviceVariablePointersFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceVariablePointersFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceVariablePointersFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceVariablePointersFeatures_pNext_offsetof||0)+")",
    variablePointersStorageBuffer: "u32("+(V.VkPhysicalDeviceVariablePointersFeatures_variablePointersStorageBuffer_offsetof||0)+")",
    variablePointers: "u32("+(V.VkPhysicalDeviceVariablePointersFeatures_variablePointers_offsetof||0)+")",
}, (V.VkPhysicalDeviceVariablePointersFeatures_sizeof||0))));

const VkPhysicalDeviceVariablePointersFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceVariablePointersFeatures"));

const VkPhysicalDeviceVariablePointerFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceVariablePointersFeatures"));

const VkPhysicalDeviceVariablePointerFeatures = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceVariablePointersFeatures"));


const VkExternalMemoryProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExternalMemoryProperties", {
    externalMemoryFeatures: "u32("+(V.VkExternalMemoryProperties_externalMemoryFeatures_offsetof||0)+")",
    exportFromImportedHandleTypes: "u32("+(V.VkExternalMemoryProperties_exportFromImportedHandleTypes_offsetof||0)+")",
    compatibleHandleTypes: "u32("+(V.VkExternalMemoryProperties_compatibleHandleTypes_offsetof||0)+")",
}, (V.VkExternalMemoryProperties_sizeof||0))));

const VkExternalMemoryPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkExternalMemoryProperties"));


const VkPhysicalDeviceExternalImageFormatInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceExternalImageFormatInfo", {
    sType: "u32("+(V.VkPhysicalDeviceExternalImageFormatInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceExternalImageFormatInfo_pNext_offsetof||0)+")",
    handleType: "u32("+(V.VkPhysicalDeviceExternalImageFormatInfo_handleType_offsetof||0)+")",
}, (V.VkPhysicalDeviceExternalImageFormatInfo_sizeof||0))));

const VkPhysicalDeviceExternalImageFormatInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceExternalImageFormatInfo"));


const VkExternalImageFormatProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExternalImageFormatProperties", {
    sType: "u32("+(V.VkExternalImageFormatProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExternalImageFormatProperties_pNext_offsetof||0)+")",
    externalMemoryProperties: "u32("+(V.VkExternalImageFormatProperties_externalMemoryProperties_offsetof||0)+")",
}, (V.VkExternalImageFormatProperties_sizeof||0))));

const VkExternalImageFormatPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkExternalImageFormatProperties"));


const VkPhysicalDeviceExternalBufferInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceExternalBufferInfo", {
    sType: "u32("+(V.VkPhysicalDeviceExternalBufferInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceExternalBufferInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPhysicalDeviceExternalBufferInfo_flags_offsetof||0)+")",
    usage: "u32("+(V.VkPhysicalDeviceExternalBufferInfo_usage_offsetof||0)+")",
    handleType: "u32("+(V.VkPhysicalDeviceExternalBufferInfo_handleType_offsetof||0)+")",
}, (V.VkPhysicalDeviceExternalBufferInfo_sizeof||0))));

const VkPhysicalDeviceExternalBufferInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceExternalBufferInfo"));


const VkExternalBufferProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExternalBufferProperties", {
    sType: "u32("+(V.VkExternalBufferProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExternalBufferProperties_pNext_offsetof||0)+")",
    externalMemoryProperties: "u32("+(V.VkExternalBufferProperties_externalMemoryProperties_offsetof||0)+")",
}, (V.VkExternalBufferProperties_sizeof||0))));

const VkExternalBufferPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkExternalBufferProperties"));


const VkPhysicalDeviceIDProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceIDProperties", {
    sType: "u32("+(V.VkPhysicalDeviceIDProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceIDProperties_pNext_offsetof||0)+")",
    deviceUUID: "u8["+(E.VK_UUID_SIZE||1)+"]("+(V.VkPhysicalDeviceIDProperties_deviceUUID_offsetof||0)+")",
    driverUUID: "u8["+(E.VK_UUID_SIZE||1)+"]("+(V.VkPhysicalDeviceIDProperties_driverUUID_offsetof||0)+")",
    deviceLUID: "u8["+(E.VK_LUID_SIZE||1)+"]("+(V.VkPhysicalDeviceIDProperties_deviceLUID_offsetof||0)+")",
    deviceNodeMask: "u32("+(V.VkPhysicalDeviceIDProperties_deviceNodeMask_offsetof||0)+")",
    deviceLUIDValid: "u32("+(V.VkPhysicalDeviceIDProperties_deviceLUIDValid_offsetof||0)+")",
}, (V.VkPhysicalDeviceIDProperties_sizeof||0))));

const VkPhysicalDeviceIDPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceIDProperties"));


const VkExternalMemoryImageCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExternalMemoryImageCreateInfo", {
    sType: "u32("+(V.VkExternalMemoryImageCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExternalMemoryImageCreateInfo_pNext_offsetof||0)+")",
    handleTypes: "u32("+(V.VkExternalMemoryImageCreateInfo_handleTypes_offsetof||0)+")",
}, (V.VkExternalMemoryImageCreateInfo_sizeof||0))));

const VkExternalMemoryImageCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkExternalMemoryImageCreateInfo"));


const VkExternalMemoryBufferCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExternalMemoryBufferCreateInfo", {
    sType: "u32("+(V.VkExternalMemoryBufferCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExternalMemoryBufferCreateInfo_pNext_offsetof||0)+")",
    handleTypes: "u32("+(V.VkExternalMemoryBufferCreateInfo_handleTypes_offsetof||0)+")",
}, (V.VkExternalMemoryBufferCreateInfo_sizeof||0))));

const VkExternalMemoryBufferCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkExternalMemoryBufferCreateInfo"));


const VkExportMemoryAllocateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportMemoryAllocateInfo", {
    sType: "u32("+(V.VkExportMemoryAllocateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportMemoryAllocateInfo_pNext_offsetof||0)+")",
    handleTypes: "u32("+(V.VkExportMemoryAllocateInfo_handleTypes_offsetof||0)+")",
}, (V.VkExportMemoryAllocateInfo_sizeof||0))));

const VkExportMemoryAllocateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkExportMemoryAllocateInfo"));


const VkImportMemoryWin32HandleInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportMemoryWin32HandleInfoKHR", {
    sType: "u32("+(V.VkImportMemoryWin32HandleInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportMemoryWin32HandleInfoKHR_pNext_offsetof||0)+")",
    handleType: "u32("+(V.VkImportMemoryWin32HandleInfoKHR_handleType_offsetof||0)+")",
    handle: "u64("+(V.VkImportMemoryWin32HandleInfoKHR_handle_offsetof||0)+")",
    name: "u32("+(V.VkImportMemoryWin32HandleInfoKHR_name_offsetof||0)+")",
}, (V.VkImportMemoryWin32HandleInfoKHR_sizeof||0))));


const VkExportMemoryWin32HandleInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportMemoryWin32HandleInfoKHR", {
    sType: "u32("+(V.VkExportMemoryWin32HandleInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportMemoryWin32HandleInfoKHR_pNext_offsetof||0)+")",
    pAttributes: "u64("+(V.VkExportMemoryWin32HandleInfoKHR_pAttributes_offsetof||0)+")",
    dwAccess: "u32("+(V.VkExportMemoryWin32HandleInfoKHR_dwAccess_offsetof||0)+")",
    name: "u32("+(V.VkExportMemoryWin32HandleInfoKHR_name_offsetof||0)+")",
}, (V.VkExportMemoryWin32HandleInfoKHR_sizeof||0))));


const VkImportMemoryZirconHandleInfoFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportMemoryZirconHandleInfoFUCHSIA", {
    sType: "u32("+(V.VkImportMemoryZirconHandleInfoFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportMemoryZirconHandleInfoFUCHSIA_pNext_offsetof||0)+")",
    handleType: "u32("+(V.VkImportMemoryZirconHandleInfoFUCHSIA_handleType_offsetof||0)+")",
    handle: "u32("+(V.VkImportMemoryZirconHandleInfoFUCHSIA_handle_offsetof||0)+")",
}, (V.VkImportMemoryZirconHandleInfoFUCHSIA_sizeof||0))));


const VkMemoryZirconHandlePropertiesFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryZirconHandlePropertiesFUCHSIA", {
    sType: "u32("+(V.VkMemoryZirconHandlePropertiesFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryZirconHandlePropertiesFUCHSIA_pNext_offsetof||0)+")",
    memoryTypeBits: "u32("+(V.VkMemoryZirconHandlePropertiesFUCHSIA_memoryTypeBits_offsetof||0)+")",
}, (V.VkMemoryZirconHandlePropertiesFUCHSIA_sizeof||0))));


const VkMemoryGetZirconHandleInfoFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryGetZirconHandleInfoFUCHSIA", {
    sType: "u32("+(V.VkMemoryGetZirconHandleInfoFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryGetZirconHandleInfoFUCHSIA_pNext_offsetof||0)+")",
    memory: "u64("+(V.VkMemoryGetZirconHandleInfoFUCHSIA_memory_offsetof||0)+")",
    handleType: "u32("+(V.VkMemoryGetZirconHandleInfoFUCHSIA_handleType_offsetof||0)+")",
}, (V.VkMemoryGetZirconHandleInfoFUCHSIA_sizeof||0))));


const VkMemoryWin32HandlePropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryWin32HandlePropertiesKHR", {
    sType: "u32("+(V.VkMemoryWin32HandlePropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryWin32HandlePropertiesKHR_pNext_offsetof||0)+")",
    memoryTypeBits: "u32("+(V.VkMemoryWin32HandlePropertiesKHR_memoryTypeBits_offsetof||0)+")",
}, (V.VkMemoryWin32HandlePropertiesKHR_sizeof||0))));


const VkMemoryGetWin32HandleInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryGetWin32HandleInfoKHR", {
    sType: "u32("+(V.VkMemoryGetWin32HandleInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryGetWin32HandleInfoKHR_pNext_offsetof||0)+")",
    memory: "u64("+(V.VkMemoryGetWin32HandleInfoKHR_memory_offsetof||0)+")",
    handleType: "u32("+(V.VkMemoryGetWin32HandleInfoKHR_handleType_offsetof||0)+")",
}, (V.VkMemoryGetWin32HandleInfoKHR_sizeof||0))));


const VkImportMemoryFdInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportMemoryFdInfoKHR", {
    sType: "u32("+(V.VkImportMemoryFdInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportMemoryFdInfoKHR_pNext_offsetof||0)+")",
    handleType: "u32("+(V.VkImportMemoryFdInfoKHR_handleType_offsetof||0)+")",
    fd: "u32("+(V.VkImportMemoryFdInfoKHR_fd_offsetof||0)+")",
}, (V.VkImportMemoryFdInfoKHR_sizeof||0))));


const VkMemoryFdPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryFdPropertiesKHR", {
    sType: "u32("+(V.VkMemoryFdPropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryFdPropertiesKHR_pNext_offsetof||0)+")",
    memoryTypeBits: "u32("+(V.VkMemoryFdPropertiesKHR_memoryTypeBits_offsetof||0)+")",
}, (V.VkMemoryFdPropertiesKHR_sizeof||0))));


const VkMemoryGetFdInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryGetFdInfoKHR", {
    sType: "u32("+(V.VkMemoryGetFdInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryGetFdInfoKHR_pNext_offsetof||0)+")",
    memory: "u64("+(V.VkMemoryGetFdInfoKHR_memory_offsetof||0)+")",
    handleType: "u32("+(V.VkMemoryGetFdInfoKHR_handleType_offsetof||0)+")",
}, (V.VkMemoryGetFdInfoKHR_sizeof||0))));


const VkWin32KeyedMutexAcquireReleaseInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkWin32KeyedMutexAcquireReleaseInfoKHR", {
    sType: "u32("+(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_pNext_offsetof||0)+")",
    acquireCount: "u32("+(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_acquireCount_offsetof||0)+")",
    pAcquireSyncs: "u64("+(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_pAcquireSyncs_offsetof||0)+")",
    pAcquireKeys: "u64("+(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_pAcquireKeys_offsetof||0)+")",
    pAcquireTimeouts: "u64("+(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_pAcquireTimeouts_offsetof||0)+")",
    releaseCount: "u32("+(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_releaseCount_offsetof||0)+")",
    pReleaseSyncs: "u64("+(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_pReleaseSyncs_offsetof||0)+")",
    pReleaseKeys: "u64("+(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_pReleaseKeys_offsetof||0)+")",
}, (V.VkWin32KeyedMutexAcquireReleaseInfoKHR_sizeof||0))));


const VkPhysicalDeviceExternalSemaphoreInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceExternalSemaphoreInfo", {
    sType: "u32("+(V.VkPhysicalDeviceExternalSemaphoreInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceExternalSemaphoreInfo_pNext_offsetof||0)+")",
    handleType: "u32("+(V.VkPhysicalDeviceExternalSemaphoreInfo_handleType_offsetof||0)+")",
}, (V.VkPhysicalDeviceExternalSemaphoreInfo_sizeof||0))));

const VkPhysicalDeviceExternalSemaphoreInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceExternalSemaphoreInfo"));


const VkExternalSemaphoreProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExternalSemaphoreProperties", {
    sType: "u32("+(V.VkExternalSemaphoreProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExternalSemaphoreProperties_pNext_offsetof||0)+")",
    exportFromImportedHandleTypes: "u32("+(V.VkExternalSemaphoreProperties_exportFromImportedHandleTypes_offsetof||0)+")",
    compatibleHandleTypes: "u32("+(V.VkExternalSemaphoreProperties_compatibleHandleTypes_offsetof||0)+")",
    externalSemaphoreFeatures: "u32("+(V.VkExternalSemaphoreProperties_externalSemaphoreFeatures_offsetof||0)+")",
}, (V.VkExternalSemaphoreProperties_sizeof||0))));

const VkExternalSemaphorePropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkExternalSemaphoreProperties"));


const VkExportSemaphoreCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportSemaphoreCreateInfo", {
    sType: "u32("+(V.VkExportSemaphoreCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportSemaphoreCreateInfo_pNext_offsetof||0)+")",
    handleTypes: "u32("+(V.VkExportSemaphoreCreateInfo_handleTypes_offsetof||0)+")",
}, (V.VkExportSemaphoreCreateInfo_sizeof||0))));

const VkExportSemaphoreCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkExportSemaphoreCreateInfo"));


const VkImportSemaphoreWin32HandleInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportSemaphoreWin32HandleInfoKHR", {
    sType: "u32("+(V.VkImportSemaphoreWin32HandleInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportSemaphoreWin32HandleInfoKHR_pNext_offsetof||0)+")",
    semaphore: "u64("+(V.VkImportSemaphoreWin32HandleInfoKHR_semaphore_offsetof||0)+")",
    flags: "u32("+(V.VkImportSemaphoreWin32HandleInfoKHR_flags_offsetof||0)+")",
    handleType: "u32("+(V.VkImportSemaphoreWin32HandleInfoKHR_handleType_offsetof||0)+")",
    handle: "u64("+(V.VkImportSemaphoreWin32HandleInfoKHR_handle_offsetof||0)+")",
    name: "u32("+(V.VkImportSemaphoreWin32HandleInfoKHR_name_offsetof||0)+")",
}, (V.VkImportSemaphoreWin32HandleInfoKHR_sizeof||0))));


const VkExportSemaphoreWin32HandleInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportSemaphoreWin32HandleInfoKHR", {
    sType: "u32("+(V.VkExportSemaphoreWin32HandleInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportSemaphoreWin32HandleInfoKHR_pNext_offsetof||0)+")",
    pAttributes: "u64("+(V.VkExportSemaphoreWin32HandleInfoKHR_pAttributes_offsetof||0)+")",
    dwAccess: "u32("+(V.VkExportSemaphoreWin32HandleInfoKHR_dwAccess_offsetof||0)+")",
    name: "u32("+(V.VkExportSemaphoreWin32HandleInfoKHR_name_offsetof||0)+")",
}, (V.VkExportSemaphoreWin32HandleInfoKHR_sizeof||0))));


const VkD3D12FenceSubmitInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkD3D12FenceSubmitInfoKHR", {
    sType: "u32("+(V.VkD3D12FenceSubmitInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkD3D12FenceSubmitInfoKHR_pNext_offsetof||0)+")",
    waitSemaphoreValuesCount: "u32("+(V.VkD3D12FenceSubmitInfoKHR_waitSemaphoreValuesCount_offsetof||0)+")",
    pWaitSemaphoreValues: "u64("+(V.VkD3D12FenceSubmitInfoKHR_pWaitSemaphoreValues_offsetof||0)+")",
    signalSemaphoreValuesCount: "u32("+(V.VkD3D12FenceSubmitInfoKHR_signalSemaphoreValuesCount_offsetof||0)+")",
    pSignalSemaphoreValues: "u64("+(V.VkD3D12FenceSubmitInfoKHR_pSignalSemaphoreValues_offsetof||0)+")",
}, (V.VkD3D12FenceSubmitInfoKHR_sizeof||0))));


const VkSemaphoreGetWin32HandleInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSemaphoreGetWin32HandleInfoKHR", {
    sType: "u32("+(V.VkSemaphoreGetWin32HandleInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSemaphoreGetWin32HandleInfoKHR_pNext_offsetof||0)+")",
    semaphore: "u64("+(V.VkSemaphoreGetWin32HandleInfoKHR_semaphore_offsetof||0)+")",
    handleType: "u32("+(V.VkSemaphoreGetWin32HandleInfoKHR_handleType_offsetof||0)+")",
}, (V.VkSemaphoreGetWin32HandleInfoKHR_sizeof||0))));


const VkImportSemaphoreFdInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportSemaphoreFdInfoKHR", {
    sType: "u32("+(V.VkImportSemaphoreFdInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportSemaphoreFdInfoKHR_pNext_offsetof||0)+")",
    semaphore: "u64("+(V.VkImportSemaphoreFdInfoKHR_semaphore_offsetof||0)+")",
    flags: "u32("+(V.VkImportSemaphoreFdInfoKHR_flags_offsetof||0)+")",
    handleType: "u32("+(V.VkImportSemaphoreFdInfoKHR_handleType_offsetof||0)+")",
    fd: "u32("+(V.VkImportSemaphoreFdInfoKHR_fd_offsetof||0)+")",
}, (V.VkImportSemaphoreFdInfoKHR_sizeof||0))));


const VkSemaphoreGetFdInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSemaphoreGetFdInfoKHR", {
    sType: "u32("+(V.VkSemaphoreGetFdInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSemaphoreGetFdInfoKHR_pNext_offsetof||0)+")",
    semaphore: "u64("+(V.VkSemaphoreGetFdInfoKHR_semaphore_offsetof||0)+")",
    handleType: "u32("+(V.VkSemaphoreGetFdInfoKHR_handleType_offsetof||0)+")",
}, (V.VkSemaphoreGetFdInfoKHR_sizeof||0))));


const VkImportSemaphoreZirconHandleInfoFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportSemaphoreZirconHandleInfoFUCHSIA", {
    sType: "u32("+(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_pNext_offsetof||0)+")",
    semaphore: "u64("+(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_semaphore_offsetof||0)+")",
    flags: "u32("+(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_flags_offsetof||0)+")",
    handleType: "u32("+(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_handleType_offsetof||0)+")",
    zirconHandle: "u32("+(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_zirconHandle_offsetof||0)+")",
}, (V.VkImportSemaphoreZirconHandleInfoFUCHSIA_sizeof||0))));


const VkSemaphoreGetZirconHandleInfoFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSemaphoreGetZirconHandleInfoFUCHSIA", {
    sType: "u32("+(V.VkSemaphoreGetZirconHandleInfoFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSemaphoreGetZirconHandleInfoFUCHSIA_pNext_offsetof||0)+")",
    semaphore: "u64("+(V.VkSemaphoreGetZirconHandleInfoFUCHSIA_semaphore_offsetof||0)+")",
    handleType: "u32("+(V.VkSemaphoreGetZirconHandleInfoFUCHSIA_handleType_offsetof||0)+")",
}, (V.VkSemaphoreGetZirconHandleInfoFUCHSIA_sizeof||0))));


const VkPhysicalDeviceExternalFenceInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceExternalFenceInfo", {
    sType: "u32("+(V.VkPhysicalDeviceExternalFenceInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceExternalFenceInfo_pNext_offsetof||0)+")",
    handleType: "u32("+(V.VkPhysicalDeviceExternalFenceInfo_handleType_offsetof||0)+")",
}, (V.VkPhysicalDeviceExternalFenceInfo_sizeof||0))));

const VkPhysicalDeviceExternalFenceInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceExternalFenceInfo"));


const VkExternalFenceProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExternalFenceProperties", {
    sType: "u32("+(V.VkExternalFenceProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExternalFenceProperties_pNext_offsetof||0)+")",
    exportFromImportedHandleTypes: "u32("+(V.VkExternalFenceProperties_exportFromImportedHandleTypes_offsetof||0)+")",
    compatibleHandleTypes: "u32("+(V.VkExternalFenceProperties_compatibleHandleTypes_offsetof||0)+")",
    externalFenceFeatures: "u32("+(V.VkExternalFenceProperties_externalFenceFeatures_offsetof||0)+")",
}, (V.VkExternalFenceProperties_sizeof||0))));

const VkExternalFencePropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkExternalFenceProperties"));


const VkExportFenceCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportFenceCreateInfo", {
    sType: "u32("+(V.VkExportFenceCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportFenceCreateInfo_pNext_offsetof||0)+")",
    handleTypes: "u32("+(V.VkExportFenceCreateInfo_handleTypes_offsetof||0)+")",
}, (V.VkExportFenceCreateInfo_sizeof||0))));

const VkExportFenceCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkExportFenceCreateInfo"));


const VkImportFenceWin32HandleInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportFenceWin32HandleInfoKHR", {
    sType: "u32("+(V.VkImportFenceWin32HandleInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportFenceWin32HandleInfoKHR_pNext_offsetof||0)+")",
    fence: "u32("+(V.VkImportFenceWin32HandleInfoKHR_fence_offsetof||0)+")",
    flags: "u32("+(V.VkImportFenceWin32HandleInfoKHR_flags_offsetof||0)+")",
    handleType: "u32("+(V.VkImportFenceWin32HandleInfoKHR_handleType_offsetof||0)+")",
    handle: "u64("+(V.VkImportFenceWin32HandleInfoKHR_handle_offsetof||0)+")",
    name: "u32("+(V.VkImportFenceWin32HandleInfoKHR_name_offsetof||0)+")",
}, (V.VkImportFenceWin32HandleInfoKHR_sizeof||0))));


const VkExportFenceWin32HandleInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportFenceWin32HandleInfoKHR", {
    sType: "u32("+(V.VkExportFenceWin32HandleInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportFenceWin32HandleInfoKHR_pNext_offsetof||0)+")",
    pAttributes: "u64("+(V.VkExportFenceWin32HandleInfoKHR_pAttributes_offsetof||0)+")",
    dwAccess: "u32("+(V.VkExportFenceWin32HandleInfoKHR_dwAccess_offsetof||0)+")",
    name: "u32("+(V.VkExportFenceWin32HandleInfoKHR_name_offsetof||0)+")",
}, (V.VkExportFenceWin32HandleInfoKHR_sizeof||0))));


const VkFenceGetWin32HandleInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkFenceGetWin32HandleInfoKHR", {
    sType: "u32("+(V.VkFenceGetWin32HandleInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkFenceGetWin32HandleInfoKHR_pNext_offsetof||0)+")",
    fence: "u32("+(V.VkFenceGetWin32HandleInfoKHR_fence_offsetof||0)+")",
    handleType: "u32("+(V.VkFenceGetWin32HandleInfoKHR_handleType_offsetof||0)+")",
}, (V.VkFenceGetWin32HandleInfoKHR_sizeof||0))));


const VkImportFenceFdInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportFenceFdInfoKHR", {
    sType: "u32("+(V.VkImportFenceFdInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportFenceFdInfoKHR_pNext_offsetof||0)+")",
    fence: "u32("+(V.VkImportFenceFdInfoKHR_fence_offsetof||0)+")",
    flags: "u32("+(V.VkImportFenceFdInfoKHR_flags_offsetof||0)+")",
    handleType: "u32("+(V.VkImportFenceFdInfoKHR_handleType_offsetof||0)+")",
    fd: "u32("+(V.VkImportFenceFdInfoKHR_fd_offsetof||0)+")",
}, (V.VkImportFenceFdInfoKHR_sizeof||0))));


const VkFenceGetFdInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkFenceGetFdInfoKHR", {
    sType: "u32("+(V.VkFenceGetFdInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkFenceGetFdInfoKHR_pNext_offsetof||0)+")",
    fence: "u32("+(V.VkFenceGetFdInfoKHR_fence_offsetof||0)+")",
    handleType: "u32("+(V.VkFenceGetFdInfoKHR_handleType_offsetof||0)+")",
}, (V.VkFenceGetFdInfoKHR_sizeof||0))));


const VkPhysicalDeviceMultiviewFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMultiviewFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceMultiviewFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMultiviewFeatures_pNext_offsetof||0)+")",
    multiview: "u32("+(V.VkPhysicalDeviceMultiviewFeatures_multiview_offsetof||0)+")",
    multiviewGeometryShader: "u32("+(V.VkPhysicalDeviceMultiviewFeatures_multiviewGeometryShader_offsetof||0)+")",
    multiviewTessellationShader: "u32("+(V.VkPhysicalDeviceMultiviewFeatures_multiviewTessellationShader_offsetof||0)+")",
}, (V.VkPhysicalDeviceMultiviewFeatures_sizeof||0))));

const VkPhysicalDeviceMultiviewFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceMultiviewFeatures"));


const VkPhysicalDeviceMultiviewProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMultiviewProperties", {
    sType: "u32("+(V.VkPhysicalDeviceMultiviewProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMultiviewProperties_pNext_offsetof||0)+")",
    maxMultiviewViewCount: "u32("+(V.VkPhysicalDeviceMultiviewProperties_maxMultiviewViewCount_offsetof||0)+")",
    maxMultiviewInstanceIndex: "u32("+(V.VkPhysicalDeviceMultiviewProperties_maxMultiviewInstanceIndex_offsetof||0)+")",
}, (V.VkPhysicalDeviceMultiviewProperties_sizeof||0))));

const VkPhysicalDeviceMultiviewPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceMultiviewProperties"));


const VkRenderPassMultiviewCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassMultiviewCreateInfo", {
    sType: "u32("+(V.VkRenderPassMultiviewCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderPassMultiviewCreateInfo_pNext_offsetof||0)+")",
    subpassCount: "u32("+(V.VkRenderPassMultiviewCreateInfo_subpassCount_offsetof||0)+")",
    pViewMasks: "u64("+(V.VkRenderPassMultiviewCreateInfo_pViewMasks_offsetof||0)+")",
    dependencyCount: "u32("+(V.VkRenderPassMultiviewCreateInfo_dependencyCount_offsetof||0)+")",
    pViewOffsets: "u64("+(V.VkRenderPassMultiviewCreateInfo_pViewOffsets_offsetof||0)+")",
    correlationMaskCount: "u32("+(V.VkRenderPassMultiviewCreateInfo_correlationMaskCount_offsetof||0)+")",
    pCorrelationMasks: "u64("+(V.VkRenderPassMultiviewCreateInfo_pCorrelationMasks_offsetof||0)+")",
}, (V.VkRenderPassMultiviewCreateInfo_sizeof||0))));

const VkRenderPassMultiviewCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkRenderPassMultiviewCreateInfo"));


const VkSurfaceCapabilities2EXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSurfaceCapabilities2EXT", {
    sType: "u32("+(V.VkSurfaceCapabilities2EXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSurfaceCapabilities2EXT_pNext_offsetof||0)+")",
    minImageCount: "u32("+(V.VkSurfaceCapabilities2EXT_minImageCount_offsetof||0)+")",
    maxImageCount: "u32("+(V.VkSurfaceCapabilities2EXT_maxImageCount_offsetof||0)+")",
    currentExtent: "VkExtent2D("+(V.VkSurfaceCapabilities2EXT_currentExtent_offsetof||0)+")",
    minImageExtent: "VkExtent2D("+(V.VkSurfaceCapabilities2EXT_minImageExtent_offsetof||0)+")",
    maxImageExtent: "VkExtent2D("+(V.VkSurfaceCapabilities2EXT_maxImageExtent_offsetof||0)+")",
    maxImageArrayLayers: "u32("+(V.VkSurfaceCapabilities2EXT_maxImageArrayLayers_offsetof||0)+")",
    supportedTransforms: "u32("+(V.VkSurfaceCapabilities2EXT_supportedTransforms_offsetof||0)+")",
    currentTransform: "u32("+(V.VkSurfaceCapabilities2EXT_currentTransform_offsetof||0)+")",
    supportedCompositeAlpha: "u32("+(V.VkSurfaceCapabilities2EXT_supportedCompositeAlpha_offsetof||0)+")",
    supportedUsageFlags: "u32("+(V.VkSurfaceCapabilities2EXT_supportedUsageFlags_offsetof||0)+")",
    supportedSurfaceCounters: "u32("+(V.VkSurfaceCapabilities2EXT_supportedSurfaceCounters_offsetof||0)+")",
}, (V.VkSurfaceCapabilities2EXT_sizeof||0))));


const VkDisplayPowerInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayPowerInfoEXT", {
    sType: "u32("+(V.VkDisplayPowerInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDisplayPowerInfoEXT_pNext_offsetof||0)+")",
    powerState: "u32("+(V.VkDisplayPowerInfoEXT_powerState_offsetof||0)+")",
}, (V.VkDisplayPowerInfoEXT_sizeof||0))));


const VkDeviceEventInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceEventInfoEXT", {
    sType: "u32("+(V.VkDeviceEventInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceEventInfoEXT_pNext_offsetof||0)+")",
    deviceEvent: "u32("+(V.VkDeviceEventInfoEXT_deviceEvent_offsetof||0)+")",
}, (V.VkDeviceEventInfoEXT_sizeof||0))));


const VkDisplayEventInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayEventInfoEXT", {
    sType: "u32("+(V.VkDisplayEventInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDisplayEventInfoEXT_pNext_offsetof||0)+")",
    displayEvent: "u32("+(V.VkDisplayEventInfoEXT_displayEvent_offsetof||0)+")",
}, (V.VkDisplayEventInfoEXT_sizeof||0))));


const VkSwapchainCounterCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSwapchainCounterCreateInfoEXT", {
    sType: "u32("+(V.VkSwapchainCounterCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSwapchainCounterCreateInfoEXT_pNext_offsetof||0)+")",
    surfaceCounters: "u32("+(V.VkSwapchainCounterCreateInfoEXT_surfaceCounters_offsetof||0)+")",
}, (V.VkSwapchainCounterCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceGroupProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceGroupProperties", {
    sType: "u32("+(V.VkPhysicalDeviceGroupProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceGroupProperties_pNext_offsetof||0)+")",
    physicalDeviceCount: "u32("+(V.VkPhysicalDeviceGroupProperties_physicalDeviceCount_offsetof||0)+")",
    physicalDevices: "u64["+(E.VK_MAX_DEVICE_GROUP_SIZE||1)+"]("+(V.VkPhysicalDeviceGroupProperties_physicalDevices_offsetof||0)+")",
    subsetAllocation: "u32("+(V.VkPhysicalDeviceGroupProperties_subsetAllocation_offsetof||0)+")",
}, (V.VkPhysicalDeviceGroupProperties_sizeof||0))));

const VkPhysicalDeviceGroupPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceGroupProperties"));


const VkMemoryAllocateFlagsInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryAllocateFlagsInfo", {
    sType: "u32("+(V.VkMemoryAllocateFlagsInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryAllocateFlagsInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkMemoryAllocateFlagsInfo_flags_offsetof||0)+")",
    deviceMask: "u32("+(V.VkMemoryAllocateFlagsInfo_deviceMask_offsetof||0)+")",
}, (V.VkMemoryAllocateFlagsInfo_sizeof||0))));

const VkMemoryAllocateFlagsInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkMemoryAllocateFlagsInfo"));


const VkBindBufferMemoryInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBindBufferMemoryInfo", {
    sType: "u32("+(V.VkBindBufferMemoryInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBindBufferMemoryInfo_pNext_offsetof||0)+")",
    buffer: "u64("+(V.VkBindBufferMemoryInfo_buffer_offsetof||0)+")",
    memory: "u64("+(V.VkBindBufferMemoryInfo_memory_offsetof||0)+")",
    memoryOffset: "u64("+(V.VkBindBufferMemoryInfo_memoryOffset_offsetof||0)+")",
}, (V.VkBindBufferMemoryInfo_sizeof||0))));

const VkBindBufferMemoryInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkBindBufferMemoryInfo"));


const VkBindBufferMemoryDeviceGroupInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBindBufferMemoryDeviceGroupInfo", {
    sType: "u32("+(V.VkBindBufferMemoryDeviceGroupInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBindBufferMemoryDeviceGroupInfo_pNext_offsetof||0)+")",
    deviceIndexCount: "u32("+(V.VkBindBufferMemoryDeviceGroupInfo_deviceIndexCount_offsetof||0)+")",
    pDeviceIndices: "u64("+(V.VkBindBufferMemoryDeviceGroupInfo_pDeviceIndices_offsetof||0)+")",
}, (V.VkBindBufferMemoryDeviceGroupInfo_sizeof||0))));

const VkBindBufferMemoryDeviceGroupInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkBindBufferMemoryDeviceGroupInfo"));


const VkBindImageMemoryInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBindImageMemoryInfo", {
    sType: "u32("+(V.VkBindImageMemoryInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBindImageMemoryInfo_pNext_offsetof||0)+")",
    image: "u64("+(V.VkBindImageMemoryInfo_image_offsetof||0)+")",
    memory: "u64("+(V.VkBindImageMemoryInfo_memory_offsetof||0)+")",
    memoryOffset: "u64("+(V.VkBindImageMemoryInfo_memoryOffset_offsetof||0)+")",
}, (V.VkBindImageMemoryInfo_sizeof||0))));

const VkBindImageMemoryInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkBindImageMemoryInfo"));


const VkBindImageMemoryDeviceGroupInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBindImageMemoryDeviceGroupInfo", {
    sType: "u32("+(V.VkBindImageMemoryDeviceGroupInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBindImageMemoryDeviceGroupInfo_pNext_offsetof||0)+")",
    deviceIndexCount: "u32("+(V.VkBindImageMemoryDeviceGroupInfo_deviceIndexCount_offsetof||0)+")",
    pDeviceIndices: "u64("+(V.VkBindImageMemoryDeviceGroupInfo_pDeviceIndices_offsetof||0)+")",
    splitInstanceBindRegionCount: "u32("+(V.VkBindImageMemoryDeviceGroupInfo_splitInstanceBindRegionCount_offsetof||0)+")",
    pSplitInstanceBindRegions: "u64("+(V.VkBindImageMemoryDeviceGroupInfo_pSplitInstanceBindRegions_offsetof||0)+")",
}, (V.VkBindImageMemoryDeviceGroupInfo_sizeof||0))));

const VkBindImageMemoryDeviceGroupInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkBindImageMemoryDeviceGroupInfo"));


const VkDeviceGroupRenderPassBeginInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceGroupRenderPassBeginInfo", {
    sType: "u32("+(V.VkDeviceGroupRenderPassBeginInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceGroupRenderPassBeginInfo_pNext_offsetof||0)+")",
    deviceMask: "u32("+(V.VkDeviceGroupRenderPassBeginInfo_deviceMask_offsetof||0)+")",
    deviceRenderAreaCount: "u32("+(V.VkDeviceGroupRenderPassBeginInfo_deviceRenderAreaCount_offsetof||0)+")",
    pDeviceRenderAreas: "u64("+(V.VkDeviceGroupRenderPassBeginInfo_pDeviceRenderAreas_offsetof||0)+")",
}, (V.VkDeviceGroupRenderPassBeginInfo_sizeof||0))));

const VkDeviceGroupRenderPassBeginInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkDeviceGroupRenderPassBeginInfo"));


const VkDeviceGroupCommandBufferBeginInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceGroupCommandBufferBeginInfo", {
    sType: "u32("+(V.VkDeviceGroupCommandBufferBeginInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceGroupCommandBufferBeginInfo_pNext_offsetof||0)+")",
    deviceMask: "u32("+(V.VkDeviceGroupCommandBufferBeginInfo_deviceMask_offsetof||0)+")",
}, (V.VkDeviceGroupCommandBufferBeginInfo_sizeof||0))));

const VkDeviceGroupCommandBufferBeginInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkDeviceGroupCommandBufferBeginInfo"));


const VkDeviceGroupSubmitInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceGroupSubmitInfo", {
    sType: "u32("+(V.VkDeviceGroupSubmitInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceGroupSubmitInfo_pNext_offsetof||0)+")",
    waitSemaphoreCount: "u32("+(V.VkDeviceGroupSubmitInfo_waitSemaphoreCount_offsetof||0)+")",
    pWaitSemaphoreDeviceIndices: "u64("+(V.VkDeviceGroupSubmitInfo_pWaitSemaphoreDeviceIndices_offsetof||0)+")",
    commandBufferCount: "u32("+(V.VkDeviceGroupSubmitInfo_commandBufferCount_offsetof||0)+")",
    pCommandBufferDeviceMasks: "u64("+(V.VkDeviceGroupSubmitInfo_pCommandBufferDeviceMasks_offsetof||0)+")",
    signalSemaphoreCount: "u32("+(V.VkDeviceGroupSubmitInfo_signalSemaphoreCount_offsetof||0)+")",
    pSignalSemaphoreDeviceIndices: "u64("+(V.VkDeviceGroupSubmitInfo_pSignalSemaphoreDeviceIndices_offsetof||0)+")",
}, (V.VkDeviceGroupSubmitInfo_sizeof||0))));

const VkDeviceGroupSubmitInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkDeviceGroupSubmitInfo"));


const VkDeviceGroupBindSparseInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceGroupBindSparseInfo", {
    sType: "u32("+(V.VkDeviceGroupBindSparseInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceGroupBindSparseInfo_pNext_offsetof||0)+")",
    resourceDeviceIndex: "u32("+(V.VkDeviceGroupBindSparseInfo_resourceDeviceIndex_offsetof||0)+")",
    memoryDeviceIndex: "u32("+(V.VkDeviceGroupBindSparseInfo_memoryDeviceIndex_offsetof||0)+")",
}, (V.VkDeviceGroupBindSparseInfo_sizeof||0))));

const VkDeviceGroupBindSparseInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkDeviceGroupBindSparseInfo"));


const VkDeviceGroupPresentCapabilitiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceGroupPresentCapabilitiesKHR", {
    sType: "u32("+(V.VkDeviceGroupPresentCapabilitiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceGroupPresentCapabilitiesKHR_pNext_offsetof||0)+")",
    presentMask: "u32["+(E.VK_MAX_DEVICE_GROUP_SIZE||1)+"]("+(V.VkDeviceGroupPresentCapabilitiesKHR_presentMask_offsetof||0)+")",
    modes: "u32("+(V.VkDeviceGroupPresentCapabilitiesKHR_modes_offsetof||0)+")",
}, (V.VkDeviceGroupPresentCapabilitiesKHR_sizeof||0))));


const VkImageSwapchainCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageSwapchainCreateInfoKHR", {
    sType: "u32("+(V.VkImageSwapchainCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageSwapchainCreateInfoKHR_pNext_offsetof||0)+")",
    swapchain: "u64("+(V.VkImageSwapchainCreateInfoKHR_swapchain_offsetof||0)+")",
}, (V.VkImageSwapchainCreateInfoKHR_sizeof||0))));


const VkBindImageMemorySwapchainInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBindImageMemorySwapchainInfoKHR", {
    sType: "u32("+(V.VkBindImageMemorySwapchainInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBindImageMemorySwapchainInfoKHR_pNext_offsetof||0)+")",
    swapchain: "u64("+(V.VkBindImageMemorySwapchainInfoKHR_swapchain_offsetof||0)+")",
    imageIndex: "u32("+(V.VkBindImageMemorySwapchainInfoKHR_imageIndex_offsetof||0)+")",
}, (V.VkBindImageMemorySwapchainInfoKHR_sizeof||0))));


const VkAcquireNextImageInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAcquireNextImageInfoKHR", {
    sType: "u32("+(V.VkAcquireNextImageInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAcquireNextImageInfoKHR_pNext_offsetof||0)+")",
    swapchain: "u64("+(V.VkAcquireNextImageInfoKHR_swapchain_offsetof||0)+")",
    timeout: "u64("+(V.VkAcquireNextImageInfoKHR_timeout_offsetof||0)+")",
    semaphore: "u64("+(V.VkAcquireNextImageInfoKHR_semaphore_offsetof||0)+")",
    fence: "u32("+(V.VkAcquireNextImageInfoKHR_fence_offsetof||0)+")",
    deviceMask: "u32("+(V.VkAcquireNextImageInfoKHR_deviceMask_offsetof||0)+")",
}, (V.VkAcquireNextImageInfoKHR_sizeof||0))));


const VkDeviceGroupPresentInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceGroupPresentInfoKHR", {
    sType: "u32("+(V.VkDeviceGroupPresentInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceGroupPresentInfoKHR_pNext_offsetof||0)+")",
    swapchainCount: "u32("+(V.VkDeviceGroupPresentInfoKHR_swapchainCount_offsetof||0)+")",
    pDeviceMasks: "u64("+(V.VkDeviceGroupPresentInfoKHR_pDeviceMasks_offsetof||0)+")",
    mode: "u32("+(V.VkDeviceGroupPresentInfoKHR_mode_offsetof||0)+")",
}, (V.VkDeviceGroupPresentInfoKHR_sizeof||0))));


const VkDeviceGroupDeviceCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceGroupDeviceCreateInfo", {
    sType: "u32("+(V.VkDeviceGroupDeviceCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceGroupDeviceCreateInfo_pNext_offsetof||0)+")",
    physicalDeviceCount: "u32("+(V.VkDeviceGroupDeviceCreateInfo_physicalDeviceCount_offsetof||0)+")",
    pPhysicalDevices: "u64("+(V.VkDeviceGroupDeviceCreateInfo_pPhysicalDevices_offsetof||0)+")",
}, (V.VkDeviceGroupDeviceCreateInfo_sizeof||0))));

const VkDeviceGroupDeviceCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkDeviceGroupDeviceCreateInfo"));


const VkDeviceGroupSwapchainCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceGroupSwapchainCreateInfoKHR", {
    sType: "u32("+(V.VkDeviceGroupSwapchainCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceGroupSwapchainCreateInfoKHR_pNext_offsetof||0)+")",
    modes: "u32("+(V.VkDeviceGroupSwapchainCreateInfoKHR_modes_offsetof||0)+")",
}, (V.VkDeviceGroupSwapchainCreateInfoKHR_sizeof||0))));


const VkDescriptorUpdateTemplateEntry = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorUpdateTemplateEntry", {
    dstBinding: "u32("+(V.VkDescriptorUpdateTemplateEntry_dstBinding_offsetof||0)+")",
    dstArrayElement: "u32("+(V.VkDescriptorUpdateTemplateEntry_dstArrayElement_offsetof||0)+")",
    descriptorCount: "u32("+(V.VkDescriptorUpdateTemplateEntry_descriptorCount_offsetof||0)+")",
    descriptorType: "u32("+(V.VkDescriptorUpdateTemplateEntry_descriptorType_offsetof||0)+")",
    offset: "u64("+(V.VkDescriptorUpdateTemplateEntry_offset_offsetof||0)+")",
    stride: "u64("+(V.VkDescriptorUpdateTemplateEntry_stride_offsetof||0)+")",
}, (V.VkDescriptorUpdateTemplateEntry_sizeof||0))));

const VkDescriptorUpdateTemplateEntryKHR = new Proxy(function(){}, new C.ConstructProxy("VkDescriptorUpdateTemplateEntry"));


const VkDescriptorUpdateTemplateCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorUpdateTemplateCreateInfo", {
    sType: "u32("+(V.VkDescriptorUpdateTemplateCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDescriptorUpdateTemplateCreateInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDescriptorUpdateTemplateCreateInfo_flags_offsetof||0)+")",
    descriptorUpdateEntryCount: "u32("+(V.VkDescriptorUpdateTemplateCreateInfo_descriptorUpdateEntryCount_offsetof||0)+")",
    pDescriptorUpdateEntries: "u64("+(V.VkDescriptorUpdateTemplateCreateInfo_pDescriptorUpdateEntries_offsetof||0)+")",
    templateType: "u32("+(V.VkDescriptorUpdateTemplateCreateInfo_templateType_offsetof||0)+")",
    descriptorSetLayout: "u32("+(V.VkDescriptorUpdateTemplateCreateInfo_descriptorSetLayout_offsetof||0)+")",
    pipelineBindPoint: "u32("+(V.VkDescriptorUpdateTemplateCreateInfo_pipelineBindPoint_offsetof||0)+")",
    pipelineLayout: "u64("+(V.VkDescriptorUpdateTemplateCreateInfo_pipelineLayout_offsetof||0)+")",
    set: "u32("+(V.VkDescriptorUpdateTemplateCreateInfo_set_offsetof||0)+")",
}, (V.VkDescriptorUpdateTemplateCreateInfo_sizeof||0))));

const VkDescriptorUpdateTemplateCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkDescriptorUpdateTemplateCreateInfo"));


const VkXYColorEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkXYColorEXT", {
    x: "f32("+(V.VkXYColorEXT_x_offsetof||0)+")",
    y: "f32("+(V.VkXYColorEXT_y_offsetof||0)+")",
}, (V.VkXYColorEXT_sizeof||0))));


const VkPhysicalDevicePresentIdFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePresentIdFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDevicePresentIdFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePresentIdFeaturesKHR_pNext_offsetof||0)+")",
    presentId: "u32("+(V.VkPhysicalDevicePresentIdFeaturesKHR_presentId_offsetof||0)+")",
}, (V.VkPhysicalDevicePresentIdFeaturesKHR_sizeof||0))));


const VkPresentIdKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPresentIdKHR", {
    sType: "u32("+(V.VkPresentIdKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPresentIdKHR_pNext_offsetof||0)+")",
    swapchainCount: "u32("+(V.VkPresentIdKHR_swapchainCount_offsetof||0)+")",
    pPresentIds: "u64("+(V.VkPresentIdKHR_pPresentIds_offsetof||0)+")",
}, (V.VkPresentIdKHR_sizeof||0))));


const VkPhysicalDevicePresentWaitFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePresentWaitFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDevicePresentWaitFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePresentWaitFeaturesKHR_pNext_offsetof||0)+")",
    presentWait: "u32("+(V.VkPhysicalDevicePresentWaitFeaturesKHR_presentWait_offsetof||0)+")",
}, (V.VkPhysicalDevicePresentWaitFeaturesKHR_sizeof||0))));


const VkHdrMetadataEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkHdrMetadataEXT", {
    sType: "u32("+(V.VkHdrMetadataEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkHdrMetadataEXT_pNext_offsetof||0)+")",
    displayPrimaryRed: "u32("+(V.VkHdrMetadataEXT_displayPrimaryRed_offsetof||0)+")",
    displayPrimaryGreen: "u32("+(V.VkHdrMetadataEXT_displayPrimaryGreen_offsetof||0)+")",
    displayPrimaryBlue: "u32("+(V.VkHdrMetadataEXT_displayPrimaryBlue_offsetof||0)+")",
    whitePoint: "u32("+(V.VkHdrMetadataEXT_whitePoint_offsetof||0)+")",
    maxLuminance: "f32("+(V.VkHdrMetadataEXT_maxLuminance_offsetof||0)+")",
    minLuminance: "f32("+(V.VkHdrMetadataEXT_minLuminance_offsetof||0)+")",
    maxContentLightLevel: "f32("+(V.VkHdrMetadataEXT_maxContentLightLevel_offsetof||0)+")",
    maxFrameAverageLightLevel: "f32("+(V.VkHdrMetadataEXT_maxFrameAverageLightLevel_offsetof||0)+")",
}, (V.VkHdrMetadataEXT_sizeof||0))));


const VkDisplayNativeHdrSurfaceCapabilitiesAMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayNativeHdrSurfaceCapabilitiesAMD", {
    sType: "u32("+(V.VkDisplayNativeHdrSurfaceCapabilitiesAMD_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDisplayNativeHdrSurfaceCapabilitiesAMD_pNext_offsetof||0)+")",
    localDimmingSupport: "u32("+(V.VkDisplayNativeHdrSurfaceCapabilitiesAMD_localDimmingSupport_offsetof||0)+")",
}, (V.VkDisplayNativeHdrSurfaceCapabilitiesAMD_sizeof||0))));


const VkSwapchainDisplayNativeHdrCreateInfoAMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSwapchainDisplayNativeHdrCreateInfoAMD", {
    sType: "u32("+(V.VkSwapchainDisplayNativeHdrCreateInfoAMD_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSwapchainDisplayNativeHdrCreateInfoAMD_pNext_offsetof||0)+")",
    localDimmingEnable: "u32("+(V.VkSwapchainDisplayNativeHdrCreateInfoAMD_localDimmingEnable_offsetof||0)+")",
}, (V.VkSwapchainDisplayNativeHdrCreateInfoAMD_sizeof||0))));


const VkRefreshCycleDurationGOOGLE = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRefreshCycleDurationGOOGLE", {
    refreshDuration: "u64("+(V.VkRefreshCycleDurationGOOGLE_refreshDuration_offsetof||0)+")",
}, (V.VkRefreshCycleDurationGOOGLE_sizeof||0))));


const VkPastPresentationTimingGOOGLE = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPastPresentationTimingGOOGLE", {
    presentID: "u32("+(V.VkPastPresentationTimingGOOGLE_presentID_offsetof||0)+")",
    desiredPresentTime: "u64("+(V.VkPastPresentationTimingGOOGLE_desiredPresentTime_offsetof||0)+")",
    actualPresentTime: "u64("+(V.VkPastPresentationTimingGOOGLE_actualPresentTime_offsetof||0)+")",
    earliestPresentTime: "u64("+(V.VkPastPresentationTimingGOOGLE_earliestPresentTime_offsetof||0)+")",
    presentMargin: "u64("+(V.VkPastPresentationTimingGOOGLE_presentMargin_offsetof||0)+")",
}, (V.VkPastPresentationTimingGOOGLE_sizeof||0))));


const VkPresentTimesInfoGOOGLE = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPresentTimesInfoGOOGLE", {
    sType: "u32("+(V.VkPresentTimesInfoGOOGLE_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPresentTimesInfoGOOGLE_pNext_offsetof||0)+")",
    swapchainCount: "u32("+(V.VkPresentTimesInfoGOOGLE_swapchainCount_offsetof||0)+")",
    pTimes: "u64("+(V.VkPresentTimesInfoGOOGLE_pTimes_offsetof||0)+")",
}, (V.VkPresentTimesInfoGOOGLE_sizeof||0))));


const VkPresentTimeGOOGLE = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPresentTimeGOOGLE", {
    presentID: "u32("+(V.VkPresentTimeGOOGLE_presentID_offsetof||0)+")",
    desiredPresentTime: "u64("+(V.VkPresentTimeGOOGLE_desiredPresentTime_offsetof||0)+")",
}, (V.VkPresentTimeGOOGLE_sizeof||0))));


const VkIOSSurfaceCreateInfoMVK = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkIOSSurfaceCreateInfoMVK", {
    sType: "u32("+(V.VkIOSSurfaceCreateInfoMVK_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkIOSSurfaceCreateInfoMVK_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkIOSSurfaceCreateInfoMVK_flags_offsetof||0)+")",
    pView: "u64("+(V.VkIOSSurfaceCreateInfoMVK_pView_offsetof||0)+")",
}, (V.VkIOSSurfaceCreateInfoMVK_sizeof||0))));


const VkMacOSSurfaceCreateInfoMVK = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMacOSSurfaceCreateInfoMVK", {
    sType: "u32("+(V.VkMacOSSurfaceCreateInfoMVK_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMacOSSurfaceCreateInfoMVK_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkMacOSSurfaceCreateInfoMVK_flags_offsetof||0)+")",
    pView: "u64("+(V.VkMacOSSurfaceCreateInfoMVK_pView_offsetof||0)+")",
}, (V.VkMacOSSurfaceCreateInfoMVK_sizeof||0))));


const VkMetalSurfaceCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMetalSurfaceCreateInfoEXT", {
    sType: "u32("+(V.VkMetalSurfaceCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMetalSurfaceCreateInfoEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkMetalSurfaceCreateInfoEXT_flags_offsetof||0)+")",
    pLayer: "u64("+(V.VkMetalSurfaceCreateInfoEXT_pLayer_offsetof||0)+")",
}, (V.VkMetalSurfaceCreateInfoEXT_sizeof||0))));


const VkViewportWScalingNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkViewportWScalingNV", {
    xcoeff: "f32("+(V.VkViewportWScalingNV_xcoeff_offsetof||0)+")",
    ycoeff: "f32("+(V.VkViewportWScalingNV_ycoeff_offsetof||0)+")",
}, (V.VkViewportWScalingNV_sizeof||0))));


const VkPipelineViewportWScalingStateCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineViewportWScalingStateCreateInfoNV", {
    sType: "u32("+(V.VkPipelineViewportWScalingStateCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineViewportWScalingStateCreateInfoNV_pNext_offsetof||0)+")",
    viewportWScalingEnable: "u32("+(V.VkPipelineViewportWScalingStateCreateInfoNV_viewportWScalingEnable_offsetof||0)+")",
    viewportCount: "u32("+(V.VkPipelineViewportWScalingStateCreateInfoNV_viewportCount_offsetof||0)+")",
    pViewportWScalings: "u64("+(V.VkPipelineViewportWScalingStateCreateInfoNV_pViewportWScalings_offsetof||0)+")",
}, (V.VkPipelineViewportWScalingStateCreateInfoNV_sizeof||0))));


const VkViewportSwizzleNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkViewportSwizzleNV", {
    x: "u32("+(V.VkViewportSwizzleNV_x_offsetof||0)+")",
    y: "u32("+(V.VkViewportSwizzleNV_y_offsetof||0)+")",
    z: "u32("+(V.VkViewportSwizzleNV_z_offsetof||0)+")",
    w: "u32("+(V.VkViewportSwizzleNV_w_offsetof||0)+")",
}, (V.VkViewportSwizzleNV_sizeof||0))));


const VkPipelineViewportSwizzleStateCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineViewportSwizzleStateCreateInfoNV", {
    sType: "u32("+(V.VkPipelineViewportSwizzleStateCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineViewportSwizzleStateCreateInfoNV_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineViewportSwizzleStateCreateInfoNV_flags_offsetof||0)+")",
    viewportCount: "u32("+(V.VkPipelineViewportSwizzleStateCreateInfoNV_viewportCount_offsetof||0)+")",
    pViewportSwizzles: "u64("+(V.VkPipelineViewportSwizzleStateCreateInfoNV_pViewportSwizzles_offsetof||0)+")",
}, (V.VkPipelineViewportSwizzleStateCreateInfoNV_sizeof||0))));


const VkPhysicalDeviceDiscardRectanglePropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDiscardRectanglePropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceDiscardRectanglePropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDiscardRectanglePropertiesEXT_pNext_offsetof||0)+")",
    maxDiscardRectangles: "u32("+(V.VkPhysicalDeviceDiscardRectanglePropertiesEXT_maxDiscardRectangles_offsetof||0)+")",
}, (V.VkPhysicalDeviceDiscardRectanglePropertiesEXT_sizeof||0))));


const VkPipelineDiscardRectangleStateCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineDiscardRectangleStateCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineDiscardRectangleStateCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineDiscardRectangleStateCreateInfoEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineDiscardRectangleStateCreateInfoEXT_flags_offsetof||0)+")",
    discardRectangleMode: "u32("+(V.VkPipelineDiscardRectangleStateCreateInfoEXT_discardRectangleMode_offsetof||0)+")",
    discardRectangleCount: "u32("+(V.VkPipelineDiscardRectangleStateCreateInfoEXT_discardRectangleCount_offsetof||0)+")",
    pDiscardRectangles: "u64("+(V.VkPipelineDiscardRectangleStateCreateInfoEXT_pDiscardRectangles_offsetof||0)+")",
}, (V.VkPipelineDiscardRectangleStateCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX", {
    sType: "u32("+(V.VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX_pNext_offsetof||0)+")",
    perViewPositionAllComponents: "u32("+(V.VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX_perViewPositionAllComponents_offsetof||0)+")",
}, (V.VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX_sizeof||0))));


const VkInputAttachmentAspectReference = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkInputAttachmentAspectReference", {
    subpass: "u32("+(V.VkInputAttachmentAspectReference_subpass_offsetof||0)+")",
    inputAttachmentIndex: "u32("+(V.VkInputAttachmentAspectReference_inputAttachmentIndex_offsetof||0)+")",
    aspectMask: "u32("+(V.VkInputAttachmentAspectReference_aspectMask_offsetof||0)+")",
}, (V.VkInputAttachmentAspectReference_sizeof||0))));

const VkInputAttachmentAspectReferenceKHR = new Proxy(function(){}, new C.ConstructProxy("VkInputAttachmentAspectReference"));


const VkRenderPassInputAttachmentAspectCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassInputAttachmentAspectCreateInfo", {
    sType: "u32("+(V.VkRenderPassInputAttachmentAspectCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderPassInputAttachmentAspectCreateInfo_pNext_offsetof||0)+")",
    aspectReferenceCount: "u32("+(V.VkRenderPassInputAttachmentAspectCreateInfo_aspectReferenceCount_offsetof||0)+")",
    pAspectReferences: "u64("+(V.VkRenderPassInputAttachmentAspectCreateInfo_pAspectReferences_offsetof||0)+")",
}, (V.VkRenderPassInputAttachmentAspectCreateInfo_sizeof||0))));

const VkRenderPassInputAttachmentAspectCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkRenderPassInputAttachmentAspectCreateInfo"));


const VkPhysicalDeviceSurfaceInfo2KHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSurfaceInfo2KHR", {
    sType: "u32("+(V.VkPhysicalDeviceSurfaceInfo2KHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSurfaceInfo2KHR_pNext_offsetof||0)+")",
    surface: "u64("+(V.VkPhysicalDeviceSurfaceInfo2KHR_surface_offsetof||0)+")",
}, (V.VkPhysicalDeviceSurfaceInfo2KHR_sizeof||0))));


const VkSurfaceCapabilities2KHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSurfaceCapabilities2KHR", {
    sType: "u32("+(V.VkSurfaceCapabilities2KHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSurfaceCapabilities2KHR_pNext_offsetof||0)+")",
    surfaceCapabilities: "u32("+(V.VkSurfaceCapabilities2KHR_surfaceCapabilities_offsetof||0)+")",
}, (V.VkSurfaceCapabilities2KHR_sizeof||0))));


const VkSurfaceFormat2KHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSurfaceFormat2KHR", {
    sType: "u32("+(V.VkSurfaceFormat2KHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSurfaceFormat2KHR_pNext_offsetof||0)+")",
    surfaceFormat: "u32("+(V.VkSurfaceFormat2KHR_surfaceFormat_offsetof||0)+")",
}, (V.VkSurfaceFormat2KHR_sizeof||0))));


const VkDisplayProperties2KHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayProperties2KHR", {
    sType: "u32("+(V.VkDisplayProperties2KHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDisplayProperties2KHR_pNext_offsetof||0)+")",
    displayProperties: "u32("+(V.VkDisplayProperties2KHR_displayProperties_offsetof||0)+")",
}, (V.VkDisplayProperties2KHR_sizeof||0))));


const VkDisplayPlaneProperties2KHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayPlaneProperties2KHR", {
    sType: "u32("+(V.VkDisplayPlaneProperties2KHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDisplayPlaneProperties2KHR_pNext_offsetof||0)+")",
    displayPlaneProperties: "u32("+(V.VkDisplayPlaneProperties2KHR_displayPlaneProperties_offsetof||0)+")",
}, (V.VkDisplayPlaneProperties2KHR_sizeof||0))));


const VkDisplayModeProperties2KHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayModeProperties2KHR", {
    sType: "u32("+(V.VkDisplayModeProperties2KHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDisplayModeProperties2KHR_pNext_offsetof||0)+")",
    displayModeProperties: "u32("+(V.VkDisplayModeProperties2KHR_displayModeProperties_offsetof||0)+")",
}, (V.VkDisplayModeProperties2KHR_sizeof||0))));


const VkDisplayPlaneInfo2KHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayPlaneInfo2KHR", {
    sType: "u32("+(V.VkDisplayPlaneInfo2KHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDisplayPlaneInfo2KHR_pNext_offsetof||0)+")",
    mode: "u32("+(V.VkDisplayPlaneInfo2KHR_mode_offsetof||0)+")",
    planeIndex: "u32("+(V.VkDisplayPlaneInfo2KHR_planeIndex_offsetof||0)+")",
}, (V.VkDisplayPlaneInfo2KHR_sizeof||0))));


const VkDisplayPlaneCapabilities2KHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDisplayPlaneCapabilities2KHR", {
    sType: "u32("+(V.VkDisplayPlaneCapabilities2KHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDisplayPlaneCapabilities2KHR_pNext_offsetof||0)+")",
    capabilities: "u32("+(V.VkDisplayPlaneCapabilities2KHR_capabilities_offsetof||0)+")",
}, (V.VkDisplayPlaneCapabilities2KHR_sizeof||0))));


const VkSharedPresentSurfaceCapabilitiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSharedPresentSurfaceCapabilitiesKHR", {
    sType: "u32("+(V.VkSharedPresentSurfaceCapabilitiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSharedPresentSurfaceCapabilitiesKHR_pNext_offsetof||0)+")",
    sharedPresentSupportedUsageFlags: "u32("+(V.VkSharedPresentSurfaceCapabilitiesKHR_sharedPresentSupportedUsageFlags_offsetof||0)+")",
}, (V.VkSharedPresentSurfaceCapabilitiesKHR_sizeof||0))));


const VkPhysicalDevice16BitStorageFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevice16BitStorageFeatures", {
    sType: "u32("+(V.VkPhysicalDevice16BitStorageFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevice16BitStorageFeatures_pNext_offsetof||0)+")",
    storageBuffer16BitAccess: "u32("+(V.VkPhysicalDevice16BitStorageFeatures_storageBuffer16BitAccess_offsetof||0)+")",
    uniformAndStorageBuffer16BitAccess: "u32("+(V.VkPhysicalDevice16BitStorageFeatures_uniformAndStorageBuffer16BitAccess_offsetof||0)+")",
    storagePushConstant16: "u32("+(V.VkPhysicalDevice16BitStorageFeatures_storagePushConstant16_offsetof||0)+")",
    storageInputOutput16: "u32("+(V.VkPhysicalDevice16BitStorageFeatures_storageInputOutput16_offsetof||0)+")",
}, (V.VkPhysicalDevice16BitStorageFeatures_sizeof||0))));

const VkPhysicalDevice16BitStorageFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDevice16BitStorageFeatures"));


const VkPhysicalDeviceSubgroupProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSubgroupProperties", {
    sType: "u32("+(V.VkPhysicalDeviceSubgroupProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSubgroupProperties_pNext_offsetof||0)+")",
    subgroupSize: "u32("+(V.VkPhysicalDeviceSubgroupProperties_subgroupSize_offsetof||0)+")",
    supportedStages: "u32("+(V.VkPhysicalDeviceSubgroupProperties_supportedStages_offsetof||0)+")",
    supportedOperations: "u32("+(V.VkPhysicalDeviceSubgroupProperties_supportedOperations_offsetof||0)+")",
    quadOperationsInAllStages: "u32("+(V.VkPhysicalDeviceSubgroupProperties_quadOperationsInAllStages_offsetof||0)+")",
}, (V.VkPhysicalDeviceSubgroupProperties_sizeof||0))));


const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pNext_offsetof||0)+")",
    shaderSubgroupExtendedTypes: "u32("+(V.VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_shaderSubgroupExtendedTypes_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_sizeof||0))));

const VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures"));


const VkBufferMemoryRequirementsInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferMemoryRequirementsInfo2", {
    sType: "u32("+(V.VkBufferMemoryRequirementsInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferMemoryRequirementsInfo2_pNext_offsetof||0)+")",
    buffer: "u64("+(V.VkBufferMemoryRequirementsInfo2_buffer_offsetof||0)+")",
}, (V.VkBufferMemoryRequirementsInfo2_sizeof||0))));

const VkBufferMemoryRequirementsInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkBufferMemoryRequirementsInfo2"));


const VkDeviceBufferMemoryRequirements = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceBufferMemoryRequirements", {
    sType: "u32("+(V.VkDeviceBufferMemoryRequirements_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceBufferMemoryRequirements_pNext_offsetof||0)+")",
    pCreateInfo: "u64("+(V.VkDeviceBufferMemoryRequirements_pCreateInfo_offsetof||0)+")",
}, (V.VkDeviceBufferMemoryRequirements_sizeof||0))));

const VkDeviceBufferMemoryRequirementsKHR = new Proxy(function(){}, new C.ConstructProxy("VkDeviceBufferMemoryRequirements"));


const VkImageMemoryRequirementsInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageMemoryRequirementsInfo2", {
    sType: "u32("+(V.VkImageMemoryRequirementsInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageMemoryRequirementsInfo2_pNext_offsetof||0)+")",
    image: "u64("+(V.VkImageMemoryRequirementsInfo2_image_offsetof||0)+")",
}, (V.VkImageMemoryRequirementsInfo2_sizeof||0))));

const VkImageMemoryRequirementsInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkImageMemoryRequirementsInfo2"));


const VkImageSparseMemoryRequirementsInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageSparseMemoryRequirementsInfo2", {
    sType: "u32("+(V.VkImageSparseMemoryRequirementsInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageSparseMemoryRequirementsInfo2_pNext_offsetof||0)+")",
    image: "u64("+(V.VkImageSparseMemoryRequirementsInfo2_image_offsetof||0)+")",
}, (V.VkImageSparseMemoryRequirementsInfo2_sizeof||0))));

const VkImageSparseMemoryRequirementsInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkImageSparseMemoryRequirementsInfo2"));


const VkDeviceImageMemoryRequirements = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceImageMemoryRequirements", {
    sType: "u32("+(V.VkDeviceImageMemoryRequirements_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceImageMemoryRequirements_pNext_offsetof||0)+")",
    pCreateInfo: "u64("+(V.VkDeviceImageMemoryRequirements_pCreateInfo_offsetof||0)+")",
    planeAspect: "u32("+(V.VkDeviceImageMemoryRequirements_planeAspect_offsetof||0)+")",
}, (V.VkDeviceImageMemoryRequirements_sizeof||0))));

const VkDeviceImageMemoryRequirementsKHR = new Proxy(function(){}, new C.ConstructProxy("VkDeviceImageMemoryRequirements"));


const VkMemoryRequirements2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryRequirements2", {
    sType: "u32("+(V.VkMemoryRequirements2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryRequirements2_pNext_offsetof||0)+")",
    memoryRequirements: "u32("+(V.VkMemoryRequirements2_memoryRequirements_offsetof||0)+")",
}, (V.VkMemoryRequirements2_sizeof||0))));

const VkMemoryRequirements2KHR = new Proxy(function(){}, new C.ConstructProxy("VkMemoryRequirements2"));


const VkSparseImageMemoryRequirements2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSparseImageMemoryRequirements2", {
    sType: "u32("+(V.VkSparseImageMemoryRequirements2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSparseImageMemoryRequirements2_pNext_offsetof||0)+")",
    memoryRequirements: "u32("+(V.VkSparseImageMemoryRequirements2_memoryRequirements_offsetof||0)+")",
}, (V.VkSparseImageMemoryRequirements2_sizeof||0))));

const VkSparseImageMemoryRequirements2KHR = new Proxy(function(){}, new C.ConstructProxy("VkSparseImageMemoryRequirements2"));


const VkPhysicalDevicePointClippingProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePointClippingProperties", {
    sType: "u32("+(V.VkPhysicalDevicePointClippingProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePointClippingProperties_pNext_offsetof||0)+")",
    pointClippingBehavior: "u32("+(V.VkPhysicalDevicePointClippingProperties_pointClippingBehavior_offsetof||0)+")",
}, (V.VkPhysicalDevicePointClippingProperties_sizeof||0))));

const VkPhysicalDevicePointClippingPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDevicePointClippingProperties"));


const VkMemoryDedicatedRequirements = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryDedicatedRequirements", {
    sType: "u32("+(V.VkMemoryDedicatedRequirements_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryDedicatedRequirements_pNext_offsetof||0)+")",
    prefersDedicatedAllocation: "u32("+(V.VkMemoryDedicatedRequirements_prefersDedicatedAllocation_offsetof||0)+")",
    requiresDedicatedAllocation: "u32("+(V.VkMemoryDedicatedRequirements_requiresDedicatedAllocation_offsetof||0)+")",
}, (V.VkMemoryDedicatedRequirements_sizeof||0))));

const VkMemoryDedicatedRequirementsKHR = new Proxy(function(){}, new C.ConstructProxy("VkMemoryDedicatedRequirements"));


const VkMemoryDedicatedAllocateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryDedicatedAllocateInfo", {
    sType: "u32("+(V.VkMemoryDedicatedAllocateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryDedicatedAllocateInfo_pNext_offsetof||0)+")",
    image: "u64("+(V.VkMemoryDedicatedAllocateInfo_image_offsetof||0)+")",
    buffer: "u64("+(V.VkMemoryDedicatedAllocateInfo_buffer_offsetof||0)+")",
}, (V.VkMemoryDedicatedAllocateInfo_sizeof||0))));

const VkMemoryDedicatedAllocateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkMemoryDedicatedAllocateInfo"));


const VkImageViewUsageCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageViewUsageCreateInfo", {
    sType: "u32("+(V.VkImageViewUsageCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageViewUsageCreateInfo_pNext_offsetof||0)+")",
    usage: "u32("+(V.VkImageViewUsageCreateInfo_usage_offsetof||0)+")",
}, (V.VkImageViewUsageCreateInfo_sizeof||0))));

const VkImageViewUsageCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkImageViewUsageCreateInfo"));


const VkPipelineTessellationDomainOriginStateCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineTessellationDomainOriginStateCreateInfo", {
    sType: "u32("+(V.VkPipelineTessellationDomainOriginStateCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineTessellationDomainOriginStateCreateInfo_pNext_offsetof||0)+")",
    domainOrigin: "u32("+(V.VkPipelineTessellationDomainOriginStateCreateInfo_domainOrigin_offsetof||0)+")",
}, (V.VkPipelineTessellationDomainOriginStateCreateInfo_sizeof||0))));

const VkPipelineTessellationDomainOriginStateCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkPipelineTessellationDomainOriginStateCreateInfo"));


const VkSamplerYcbcrConversionInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSamplerYcbcrConversionInfo", {
    sType: "u32("+(V.VkSamplerYcbcrConversionInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSamplerYcbcrConversionInfo_pNext_offsetof||0)+")",
    conversion: "u32("+(V.VkSamplerYcbcrConversionInfo_conversion_offsetof||0)+")",
}, (V.VkSamplerYcbcrConversionInfo_sizeof||0))));

const VkSamplerYcbcrConversionInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkSamplerYcbcrConversionInfo"));


const VkSamplerYcbcrConversionCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSamplerYcbcrConversionCreateInfo", {
    sType: "u32("+(V.VkSamplerYcbcrConversionCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSamplerYcbcrConversionCreateInfo_pNext_offsetof||0)+")",
    format: "u32("+(V.VkSamplerYcbcrConversionCreateInfo_format_offsetof||0)+")",
    ycbcrModel: "u32("+(V.VkSamplerYcbcrConversionCreateInfo_ycbcrModel_offsetof||0)+")",
    ycbcrRange: "u32("+(V.VkSamplerYcbcrConversionCreateInfo_ycbcrRange_offsetof||0)+")",
    components: "u32("+(V.VkSamplerYcbcrConversionCreateInfo_components_offsetof||0)+")",
    xChromaOffset: "u32("+(V.VkSamplerYcbcrConversionCreateInfo_xChromaOffset_offsetof||0)+")",
    yChromaOffset: "u32("+(V.VkSamplerYcbcrConversionCreateInfo_yChromaOffset_offsetof||0)+")",
    chromaFilter: "u32("+(V.VkSamplerYcbcrConversionCreateInfo_chromaFilter_offsetof||0)+")",
    forceExplicitReconstruction: "u32("+(V.VkSamplerYcbcrConversionCreateInfo_forceExplicitReconstruction_offsetof||0)+")",
}, (V.VkSamplerYcbcrConversionCreateInfo_sizeof||0))));

const VkSamplerYcbcrConversionCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkSamplerYcbcrConversionCreateInfo"));


const VkBindImagePlaneMemoryInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBindImagePlaneMemoryInfo", {
    sType: "u32("+(V.VkBindImagePlaneMemoryInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBindImagePlaneMemoryInfo_pNext_offsetof||0)+")",
    planeAspect: "u32("+(V.VkBindImagePlaneMemoryInfo_planeAspect_offsetof||0)+")",
}, (V.VkBindImagePlaneMemoryInfo_sizeof||0))));

const VkBindImagePlaneMemoryInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkBindImagePlaneMemoryInfo"));


const VkImagePlaneMemoryRequirementsInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImagePlaneMemoryRequirementsInfo", {
    sType: "u32("+(V.VkImagePlaneMemoryRequirementsInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImagePlaneMemoryRequirementsInfo_pNext_offsetof||0)+")",
    planeAspect: "u32("+(V.VkImagePlaneMemoryRequirementsInfo_planeAspect_offsetof||0)+")",
}, (V.VkImagePlaneMemoryRequirementsInfo_sizeof||0))));

const VkImagePlaneMemoryRequirementsInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkImagePlaneMemoryRequirementsInfo"));


const VkPhysicalDeviceSamplerYcbcrConversionFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSamplerYcbcrConversionFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceSamplerYcbcrConversionFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSamplerYcbcrConversionFeatures_pNext_offsetof||0)+")",
    samplerYcbcrConversion: "u32("+(V.VkPhysicalDeviceSamplerYcbcrConversionFeatures_samplerYcbcrConversion_offsetof||0)+")",
}, (V.VkPhysicalDeviceSamplerYcbcrConversionFeatures_sizeof||0))));

const VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceSamplerYcbcrConversionFeatures"));


const VkSamplerYcbcrConversionImageFormatProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSamplerYcbcrConversionImageFormatProperties", {
    sType: "u32("+(V.VkSamplerYcbcrConversionImageFormatProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSamplerYcbcrConversionImageFormatProperties_pNext_offsetof||0)+")",
    combinedImageSamplerDescriptorCount: "u32("+(V.VkSamplerYcbcrConversionImageFormatProperties_combinedImageSamplerDescriptorCount_offsetof||0)+")",
}, (V.VkSamplerYcbcrConversionImageFormatProperties_sizeof||0))));

const VkSamplerYcbcrConversionImageFormatPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkSamplerYcbcrConversionImageFormatProperties"));


const VkTextureLODGatherFormatPropertiesAMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkTextureLODGatherFormatPropertiesAMD", {
    sType: "u32("+(V.VkTextureLODGatherFormatPropertiesAMD_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkTextureLODGatherFormatPropertiesAMD_pNext_offsetof||0)+")",
    supportsTextureGatherLODBiasAMD: "u32("+(V.VkTextureLODGatherFormatPropertiesAMD_supportsTextureGatherLODBiasAMD_offsetof||0)+")",
}, (V.VkTextureLODGatherFormatPropertiesAMD_sizeof||0))));


const VkConditionalRenderingBeginInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkConditionalRenderingBeginInfoEXT", {
    sType: "u32("+(V.VkConditionalRenderingBeginInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkConditionalRenderingBeginInfoEXT_pNext_offsetof||0)+")",
    buffer: "u64("+(V.VkConditionalRenderingBeginInfoEXT_buffer_offsetof||0)+")",
    offset: "u64("+(V.VkConditionalRenderingBeginInfoEXT_offset_offsetof||0)+")",
    flags: "u32("+(V.VkConditionalRenderingBeginInfoEXT_flags_offsetof||0)+")",
}, (V.VkConditionalRenderingBeginInfoEXT_sizeof||0))));


const VkProtectedSubmitInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkProtectedSubmitInfo", {
    sType: "u32("+(V.VkProtectedSubmitInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkProtectedSubmitInfo_pNext_offsetof||0)+")",
    protectedSubmit: "u32("+(V.VkProtectedSubmitInfo_protectedSubmit_offsetof||0)+")",
}, (V.VkProtectedSubmitInfo_sizeof||0))));


const VkPhysicalDeviceProtectedMemoryFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceProtectedMemoryFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceProtectedMemoryFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceProtectedMemoryFeatures_pNext_offsetof||0)+")",
    protectedMemory: "u32("+(V.VkPhysicalDeviceProtectedMemoryFeatures_protectedMemory_offsetof||0)+")",
}, (V.VkPhysicalDeviceProtectedMemoryFeatures_sizeof||0))));


const VkPhysicalDeviceProtectedMemoryProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceProtectedMemoryProperties", {
    sType: "u32("+(V.VkPhysicalDeviceProtectedMemoryProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceProtectedMemoryProperties_pNext_offsetof||0)+")",
    protectedNoFault: "u32("+(V.VkPhysicalDeviceProtectedMemoryProperties_protectedNoFault_offsetof||0)+")",
}, (V.VkPhysicalDeviceProtectedMemoryProperties_sizeof||0))));


const VkDeviceQueueInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceQueueInfo2", {
    sType: "u32("+(V.VkDeviceQueueInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceQueueInfo2_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDeviceQueueInfo2_flags_offsetof||0)+")",
    queueFamilyIndex: "u32("+(V.VkDeviceQueueInfo2_queueFamilyIndex_offsetof||0)+")",
    queueIndex: "u32("+(V.VkDeviceQueueInfo2_queueIndex_offsetof||0)+")",
}, (V.VkDeviceQueueInfo2_sizeof||0))));


const VkPipelineCoverageToColorStateCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineCoverageToColorStateCreateInfoNV", {
    sType: "u32("+(V.VkPipelineCoverageToColorStateCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineCoverageToColorStateCreateInfoNV_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineCoverageToColorStateCreateInfoNV_flags_offsetof||0)+")",
    coverageToColorEnable: "u32("+(V.VkPipelineCoverageToColorStateCreateInfoNV_coverageToColorEnable_offsetof||0)+")",
    coverageToColorLocation: "u32("+(V.VkPipelineCoverageToColorStateCreateInfoNV_coverageToColorLocation_offsetof||0)+")",
}, (V.VkPipelineCoverageToColorStateCreateInfoNV_sizeof||0))));


const VkPhysicalDeviceSamplerFilterMinmaxProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSamplerFilterMinmaxProperties", {
    sType: "u32("+(V.VkPhysicalDeviceSamplerFilterMinmaxProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSamplerFilterMinmaxProperties_pNext_offsetof||0)+")",
    filterMinmaxSingleComponentFormats: "u32("+(V.VkPhysicalDeviceSamplerFilterMinmaxProperties_filterMinmaxSingleComponentFormats_offsetof||0)+")",
    filterMinmaxImageComponentMapping: "u32("+(V.VkPhysicalDeviceSamplerFilterMinmaxProperties_filterMinmaxImageComponentMapping_offsetof||0)+")",
}, (V.VkPhysicalDeviceSamplerFilterMinmaxProperties_sizeof||0))));

const VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceSamplerFilterMinmaxProperties"));


const VkSampleLocationEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSampleLocationEXT", {
    x: "f32("+(V.VkSampleLocationEXT_x_offsetof||0)+")",
    y: "f32("+(V.VkSampleLocationEXT_y_offsetof||0)+")",
}, (V.VkSampleLocationEXT_sizeof||0))));


const VkSampleLocationsInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSampleLocationsInfoEXT", {
    sType: "u32("+(V.VkSampleLocationsInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSampleLocationsInfoEXT_pNext_offsetof||0)+")",
    sampleLocationsPerPixel: "u32("+(V.VkSampleLocationsInfoEXT_sampleLocationsPerPixel_offsetof||0)+")",
    sampleLocationGridSize: "VkExtent2D("+(V.VkSampleLocationsInfoEXT_sampleLocationGridSize_offsetof||0)+")",
    sampleLocationsCount: "u32("+(V.VkSampleLocationsInfoEXT_sampleLocationsCount_offsetof||0)+")",
    pSampleLocations: "u64("+(V.VkSampleLocationsInfoEXT_pSampleLocations_offsetof||0)+")",
}, (V.VkSampleLocationsInfoEXT_sizeof||0))));


const VkAttachmentSampleLocationsEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAttachmentSampleLocationsEXT", {
    attachmentIndex: "u32("+(V.VkAttachmentSampleLocationsEXT_attachmentIndex_offsetof||0)+")",
    sampleLocationsInfo: "u32("+(V.VkAttachmentSampleLocationsEXT_sampleLocationsInfo_offsetof||0)+")",
}, (V.VkAttachmentSampleLocationsEXT_sizeof||0))));


const VkSubpassSampleLocationsEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubpassSampleLocationsEXT", {
    subpassIndex: "u32("+(V.VkSubpassSampleLocationsEXT_subpassIndex_offsetof||0)+")",
    sampleLocationsInfo: "u32("+(V.VkSubpassSampleLocationsEXT_sampleLocationsInfo_offsetof||0)+")",
}, (V.VkSubpassSampleLocationsEXT_sizeof||0))));


const VkRenderPassSampleLocationsBeginInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassSampleLocationsBeginInfoEXT", {
    sType: "u32("+(V.VkRenderPassSampleLocationsBeginInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderPassSampleLocationsBeginInfoEXT_pNext_offsetof||0)+")",
    attachmentInitialSampleLocationsCount: "u32("+(V.VkRenderPassSampleLocationsBeginInfoEXT_attachmentInitialSampleLocationsCount_offsetof||0)+")",
    pAttachmentInitialSampleLocations: "u64("+(V.VkRenderPassSampleLocationsBeginInfoEXT_pAttachmentInitialSampleLocations_offsetof||0)+")",
    postSubpassSampleLocationsCount: "u32("+(V.VkRenderPassSampleLocationsBeginInfoEXT_postSubpassSampleLocationsCount_offsetof||0)+")",
    pPostSubpassSampleLocations: "u64("+(V.VkRenderPassSampleLocationsBeginInfoEXT_pPostSubpassSampleLocations_offsetof||0)+")",
}, (V.VkRenderPassSampleLocationsBeginInfoEXT_sizeof||0))));


const VkPipelineSampleLocationsStateCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineSampleLocationsStateCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineSampleLocationsStateCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineSampleLocationsStateCreateInfoEXT_pNext_offsetof||0)+")",
    sampleLocationsEnable: "u32("+(V.VkPipelineSampleLocationsStateCreateInfoEXT_sampleLocationsEnable_offsetof||0)+")",
    sampleLocationsInfo: "u32("+(V.VkPipelineSampleLocationsStateCreateInfoEXT_sampleLocationsInfo_offsetof||0)+")",
}, (V.VkPipelineSampleLocationsStateCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceSampleLocationsPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSampleLocationsPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_pNext_offsetof||0)+")",
    sampleLocationSampleCounts: "u32("+(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_sampleLocationSampleCounts_offsetof||0)+")",
    maxSampleLocationGridSize: "VkExtent2D("+(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_maxSampleLocationGridSize_offsetof||0)+")",
    sampleLocationCoordinateRange: "f32[2]("+(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_sampleLocationCoordinateRange_offsetof||0)+")",
    sampleLocationSubPixelBits: "u32("+(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_sampleLocationSubPixelBits_offsetof||0)+")",
    variableSampleLocations: "u32("+(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_variableSampleLocations_offsetof||0)+")",
}, (V.VkPhysicalDeviceSampleLocationsPropertiesEXT_sizeof||0))));


const VkMultisamplePropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMultisamplePropertiesEXT", {
    sType: "u32("+(V.VkMultisamplePropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMultisamplePropertiesEXT_pNext_offsetof||0)+")",
    maxSampleLocationGridSize: "VkExtent2D("+(V.VkMultisamplePropertiesEXT_maxSampleLocationGridSize_offsetof||0)+")",
}, (V.VkMultisamplePropertiesEXT_sizeof||0))));


const VkSamplerReductionModeCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSamplerReductionModeCreateInfo", {
    sType: "u32("+(V.VkSamplerReductionModeCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSamplerReductionModeCreateInfo_pNext_offsetof||0)+")",
    reductionMode: "u32("+(V.VkSamplerReductionModeCreateInfo_reductionMode_offsetof||0)+")",
}, (V.VkSamplerReductionModeCreateInfo_sizeof||0))));

const VkSamplerReductionModeCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy("VkSamplerReductionModeCreateInfo"));


const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT_pNext_offsetof||0)+")",
    advancedBlendCoherentOperations: "u32("+(V.VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT_advancedBlendCoherentOperations_offsetof||0)+")",
}, (V.VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceMultiDrawFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMultiDrawFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceMultiDrawFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMultiDrawFeaturesEXT_pNext_offsetof||0)+")",
    multiDraw: "u32("+(V.VkPhysicalDeviceMultiDrawFeaturesEXT_multiDraw_offsetof||0)+")",
}, (V.VkPhysicalDeviceMultiDrawFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_pNext_offsetof||0)+")",
    advancedBlendMaxColorAttachments: "u32("+(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_advancedBlendMaxColorAttachments_offsetof||0)+")",
    advancedBlendIndependentBlend: "u32("+(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_advancedBlendIndependentBlend_offsetof||0)+")",
    advancedBlendNonPremultipliedSrcColor: "u32("+(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_advancedBlendNonPremultipliedSrcColor_offsetof||0)+")",
    advancedBlendNonPremultipliedDstColor: "u32("+(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_advancedBlendNonPremultipliedDstColor_offsetof||0)+")",
    advancedBlendCorrelatedOverlap: "u32("+(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_advancedBlendCorrelatedOverlap_offsetof||0)+")",
    advancedBlendAllOperations: "u32("+(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_advancedBlendAllOperations_offsetof||0)+")",
}, (V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_sizeof||0))));


const VkPipelineColorBlendAdvancedStateCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineColorBlendAdvancedStateCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineColorBlendAdvancedStateCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineColorBlendAdvancedStateCreateInfoEXT_pNext_offsetof||0)+")",
    srcPremultiplied: "u32("+(V.VkPipelineColorBlendAdvancedStateCreateInfoEXT_srcPremultiplied_offsetof||0)+")",
    dstPremultiplied: "u32("+(V.VkPipelineColorBlendAdvancedStateCreateInfoEXT_dstPremultiplied_offsetof||0)+")",
    blendOverlap: "u32("+(V.VkPipelineColorBlendAdvancedStateCreateInfoEXT_blendOverlap_offsetof||0)+")",
}, (V.VkPipelineColorBlendAdvancedStateCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceInlineUniformBlockFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceInlineUniformBlockFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceInlineUniformBlockFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceInlineUniformBlockFeatures_pNext_offsetof||0)+")",
    inlineUniformBlock: "u32("+(V.VkPhysicalDeviceInlineUniformBlockFeatures_inlineUniformBlock_offsetof||0)+")",
    descriptorBindingInlineUniformBlockUpdateAfterBind: "u32("+(V.VkPhysicalDeviceInlineUniformBlockFeatures_descriptorBindingInlineUniformBlockUpdateAfterBind_offsetof||0)+")",
}, (V.VkPhysicalDeviceInlineUniformBlockFeatures_sizeof||0))));

const VkPhysicalDeviceInlineUniformBlockFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceInlineUniformBlockFeatures"));


const VkPhysicalDeviceInlineUniformBlockProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceInlineUniformBlockProperties", {
    sType: "u32("+(V.VkPhysicalDeviceInlineUniformBlockProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceInlineUniformBlockProperties_pNext_offsetof||0)+")",
    maxInlineUniformBlockSize: "u32("+(V.VkPhysicalDeviceInlineUniformBlockProperties_maxInlineUniformBlockSize_offsetof||0)+")",
    maxPerStageDescriptorInlineUniformBlocks: "u32("+(V.VkPhysicalDeviceInlineUniformBlockProperties_maxPerStageDescriptorInlineUniformBlocks_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks: "u32("+(V.VkPhysicalDeviceInlineUniformBlockProperties_maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks_offsetof||0)+")",
    maxDescriptorSetInlineUniformBlocks: "u32("+(V.VkPhysicalDeviceInlineUniformBlockProperties_maxDescriptorSetInlineUniformBlocks_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindInlineUniformBlocks: "u32("+(V.VkPhysicalDeviceInlineUniformBlockProperties_maxDescriptorSetUpdateAfterBindInlineUniformBlocks_offsetof||0)+")",
}, (V.VkPhysicalDeviceInlineUniformBlockProperties_sizeof||0))));

const VkPhysicalDeviceInlineUniformBlockPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceInlineUniformBlockProperties"));


const VkWriteDescriptorSetInlineUniformBlock = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkWriteDescriptorSetInlineUniformBlock", {
    sType: "u32("+(V.VkWriteDescriptorSetInlineUniformBlock_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkWriteDescriptorSetInlineUniformBlock_pNext_offsetof||0)+")",
    dataSize: "u32("+(V.VkWriteDescriptorSetInlineUniformBlock_dataSize_offsetof||0)+")",
    pData: "u64("+(V.VkWriteDescriptorSetInlineUniformBlock_pData_offsetof||0)+")",
}, (V.VkWriteDescriptorSetInlineUniformBlock_sizeof||0))));

const VkWriteDescriptorSetInlineUniformBlockEXT = new Proxy(function(){}, new C.ConstructProxy("VkWriteDescriptorSetInlineUniformBlock"));


const VkDescriptorPoolInlineUniformBlockCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorPoolInlineUniformBlockCreateInfo", {
    sType: "u32("+(V.VkDescriptorPoolInlineUniformBlockCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDescriptorPoolInlineUniformBlockCreateInfo_pNext_offsetof||0)+")",
    maxInlineUniformBlockBindings: "u32("+(V.VkDescriptorPoolInlineUniformBlockCreateInfo_maxInlineUniformBlockBindings_offsetof||0)+")",
}, (V.VkDescriptorPoolInlineUniformBlockCreateInfo_sizeof||0))));

const VkDescriptorPoolInlineUniformBlockCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy("VkDescriptorPoolInlineUniformBlockCreateInfo"));


const VkPipelineCoverageModulationStateCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineCoverageModulationStateCreateInfoNV", {
    sType: "u32("+(V.VkPipelineCoverageModulationStateCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineCoverageModulationStateCreateInfoNV_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineCoverageModulationStateCreateInfoNV_flags_offsetof||0)+")",
    coverageModulationMode: "u32("+(V.VkPipelineCoverageModulationStateCreateInfoNV_coverageModulationMode_offsetof||0)+")",
    coverageModulationTableEnable: "u32("+(V.VkPipelineCoverageModulationStateCreateInfoNV_coverageModulationTableEnable_offsetof||0)+")",
    coverageModulationTableCount: "u32("+(V.VkPipelineCoverageModulationStateCreateInfoNV_coverageModulationTableCount_offsetof||0)+")",
    pCoverageModulationTable: "u64("+(V.VkPipelineCoverageModulationStateCreateInfoNV_pCoverageModulationTable_offsetof||0)+")",
}, (V.VkPipelineCoverageModulationStateCreateInfoNV_sizeof||0))));


const VkImageFormatListCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageFormatListCreateInfo", {
    sType: "u32("+(V.VkImageFormatListCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageFormatListCreateInfo_pNext_offsetof||0)+")",
    viewFormatCount: "u32("+(V.VkImageFormatListCreateInfo_viewFormatCount_offsetof||0)+")",
    pViewFormats: "u64("+(V.VkImageFormatListCreateInfo_pViewFormats_offsetof||0)+")",
}, (V.VkImageFormatListCreateInfo_sizeof||0))));

const VkImageFormatListCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkImageFormatListCreateInfo"));


const VkValidationCacheCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkValidationCacheCreateInfoEXT", {
    sType: "u32("+(V.VkValidationCacheCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkValidationCacheCreateInfoEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkValidationCacheCreateInfoEXT_flags_offsetof||0)+")",
    initialDataSize: "u64("+(V.VkValidationCacheCreateInfoEXT_initialDataSize_offsetof||0)+")",
    pInitialData: "u64("+(V.VkValidationCacheCreateInfoEXT_pInitialData_offsetof||0)+")",
}, (V.VkValidationCacheCreateInfoEXT_sizeof||0))));


const VkShaderModuleValidationCacheCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkShaderModuleValidationCacheCreateInfoEXT", {
    sType: "u32("+(V.VkShaderModuleValidationCacheCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkShaderModuleValidationCacheCreateInfoEXT_pNext_offsetof||0)+")",
    validationCache: "u32("+(V.VkShaderModuleValidationCacheCreateInfoEXT_validationCache_offsetof||0)+")",
}, (V.VkShaderModuleValidationCacheCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceMaintenance3Properties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMaintenance3Properties", {
    sType: "u32("+(V.VkPhysicalDeviceMaintenance3Properties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMaintenance3Properties_pNext_offsetof||0)+")",
    maxPerSetDescriptors: "u32("+(V.VkPhysicalDeviceMaintenance3Properties_maxPerSetDescriptors_offsetof||0)+")",
    maxMemoryAllocationSize: "u64("+(V.VkPhysicalDeviceMaintenance3Properties_maxMemoryAllocationSize_offsetof||0)+")",
}, (V.VkPhysicalDeviceMaintenance3Properties_sizeof||0))));

const VkPhysicalDeviceMaintenance3PropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceMaintenance3Properties"));


const VkPhysicalDeviceMaintenance4Features = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMaintenance4Features", {
    sType: "u32("+(V.VkPhysicalDeviceMaintenance4Features_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMaintenance4Features_pNext_offsetof||0)+")",
    maintenance4: "u32("+(V.VkPhysicalDeviceMaintenance4Features_maintenance4_offsetof||0)+")",
}, (V.VkPhysicalDeviceMaintenance4Features_sizeof||0))));

const VkPhysicalDeviceMaintenance4FeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceMaintenance4Features"));


const VkPhysicalDeviceMaintenance4Properties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMaintenance4Properties", {
    sType: "u32("+(V.VkPhysicalDeviceMaintenance4Properties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMaintenance4Properties_pNext_offsetof||0)+")",
    maxBufferSize: "u64("+(V.VkPhysicalDeviceMaintenance4Properties_maxBufferSize_offsetof||0)+")",
}, (V.VkPhysicalDeviceMaintenance4Properties_sizeof||0))));

const VkPhysicalDeviceMaintenance4PropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceMaintenance4Properties"));


const VkDescriptorSetLayoutSupport = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorSetLayoutSupport", {
    sType: "u32("+(V.VkDescriptorSetLayoutSupport_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDescriptorSetLayoutSupport_pNext_offsetof||0)+")",
    supported: "u32("+(V.VkDescriptorSetLayoutSupport_supported_offsetof||0)+")",
}, (V.VkDescriptorSetLayoutSupport_sizeof||0))));

const VkDescriptorSetLayoutSupportKHR = new Proxy(function(){}, new C.ConstructProxy("VkDescriptorSetLayoutSupport"));


const VkPhysicalDeviceShaderDrawParametersFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderDrawParametersFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceShaderDrawParametersFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderDrawParametersFeatures_pNext_offsetof||0)+")",
    shaderDrawParameters: "u32("+(V.VkPhysicalDeviceShaderDrawParametersFeatures_shaderDrawParameters_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderDrawParametersFeatures_sizeof||0))));

const VkPhysicalDeviceShaderDrawParameterFeatures = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceShaderDrawParametersFeatures"));


const VkPhysicalDeviceShaderFloat16Int8Features = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderFloat16Int8Features", {
    sType: "u32("+(V.VkPhysicalDeviceShaderFloat16Int8Features_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderFloat16Int8Features_pNext_offsetof||0)+")",
    shaderFloat16: "u32("+(V.VkPhysicalDeviceShaderFloat16Int8Features_shaderFloat16_offsetof||0)+")",
    shaderInt8: "u32("+(V.VkPhysicalDeviceShaderFloat16Int8Features_shaderInt8_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderFloat16Int8Features_sizeof||0))));

const VkPhysicalDeviceShaderFloat16Int8FeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceShaderFloat16Int8Features"));

const VkPhysicalDeviceFloat16Int8FeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceShaderFloat16Int8Features"));


const VkPhysicalDeviceFloatControlsProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFloatControlsProperties", {
    sType: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFloatControlsProperties_pNext_offsetof||0)+")",
    denormBehaviorIndependence: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_denormBehaviorIndependence_offsetof||0)+")",
    roundingModeIndependence: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_roundingModeIndependence_offsetof||0)+")",
    shaderSignedZeroInfNanPreserveFloat16: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderSignedZeroInfNanPreserveFloat16_offsetof||0)+")",
    shaderSignedZeroInfNanPreserveFloat32: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderSignedZeroInfNanPreserveFloat32_offsetof||0)+")",
    shaderSignedZeroInfNanPreserveFloat64: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderSignedZeroInfNanPreserveFloat64_offsetof||0)+")",
    shaderDenormPreserveFloat16: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderDenormPreserveFloat16_offsetof||0)+")",
    shaderDenormPreserveFloat32: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderDenormPreserveFloat32_offsetof||0)+")",
    shaderDenormPreserveFloat64: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderDenormPreserveFloat64_offsetof||0)+")",
    shaderDenormFlushToZeroFloat16: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderDenormFlushToZeroFloat16_offsetof||0)+")",
    shaderDenormFlushToZeroFloat32: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderDenormFlushToZeroFloat32_offsetof||0)+")",
    shaderDenormFlushToZeroFloat64: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderDenormFlushToZeroFloat64_offsetof||0)+")",
    shaderRoundingModeRTEFloat16: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderRoundingModeRTEFloat16_offsetof||0)+")",
    shaderRoundingModeRTEFloat32: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderRoundingModeRTEFloat32_offsetof||0)+")",
    shaderRoundingModeRTEFloat64: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderRoundingModeRTEFloat64_offsetof||0)+")",
    shaderRoundingModeRTZFloat16: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderRoundingModeRTZFloat16_offsetof||0)+")",
    shaderRoundingModeRTZFloat32: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderRoundingModeRTZFloat32_offsetof||0)+")",
    shaderRoundingModeRTZFloat64: "u32("+(V.VkPhysicalDeviceFloatControlsProperties_shaderRoundingModeRTZFloat64_offsetof||0)+")",
}, (V.VkPhysicalDeviceFloatControlsProperties_sizeof||0))));

const VkPhysicalDeviceFloatControlsPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceFloatControlsProperties"));


const VkPhysicalDeviceHostQueryResetFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceHostQueryResetFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceHostQueryResetFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceHostQueryResetFeatures_pNext_offsetof||0)+")",
    hostQueryReset: "u32("+(V.VkPhysicalDeviceHostQueryResetFeatures_hostQueryReset_offsetof||0)+")",
}, (V.VkPhysicalDeviceHostQueryResetFeatures_sizeof||0))));

const VkPhysicalDeviceHostQueryResetFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceHostQueryResetFeatures"));


const VkNativeBufferUsage2ANDROID = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkNativeBufferUsage2ANDROID", {
    consumer: "u64("+(V.VkNativeBufferUsage2ANDROID_consumer_offsetof||0)+")",
    producer: "u64("+(V.VkNativeBufferUsage2ANDROID_producer_offsetof||0)+")",
}, (V.VkNativeBufferUsage2ANDROID_sizeof||0))));


const VkNativeBufferANDROID = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkNativeBufferANDROID", {
    sType: "u32("+(V.VkNativeBufferANDROID_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkNativeBufferANDROID_pNext_offsetof||0)+")",
    handle: "u64("+(V.VkNativeBufferANDROID_handle_offsetof||0)+")",
    stride: "u32("+(V.VkNativeBufferANDROID_stride_offsetof||0)+")",
    format: "u32("+(V.VkNativeBufferANDROID_format_offsetof||0)+")",
    usage: "u32("+(V.VkNativeBufferANDROID_usage_offsetof||0)+")",
    usage2: "u32("+(V.VkNativeBufferANDROID_usage2_offsetof||0)+")",
}, (V.VkNativeBufferANDROID_sizeof||0))));


const VkSwapchainImageCreateInfoANDROID = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSwapchainImageCreateInfoANDROID", {
    sType: "u32("+(V.VkSwapchainImageCreateInfoANDROID_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSwapchainImageCreateInfoANDROID_pNext_offsetof||0)+")",
    usage: "u32("+(V.VkSwapchainImageCreateInfoANDROID_usage_offsetof||0)+")",
}, (V.VkSwapchainImageCreateInfoANDROID_sizeof||0))));


const VkPhysicalDevicePresentationPropertiesANDROID = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePresentationPropertiesANDROID", {
    sType: "u32("+(V.VkPhysicalDevicePresentationPropertiesANDROID_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePresentationPropertiesANDROID_pNext_offsetof||0)+")",
    sharedImage: "u32("+(V.VkPhysicalDevicePresentationPropertiesANDROID_sharedImage_offsetof||0)+")",
}, (V.VkPhysicalDevicePresentationPropertiesANDROID_sizeof||0))));


const VkShaderResourceUsageAMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkShaderResourceUsageAMD", {
    numUsedVgprs: "u32("+(V.VkShaderResourceUsageAMD_numUsedVgprs_offsetof||0)+")",
    numUsedSgprs: "u32("+(V.VkShaderResourceUsageAMD_numUsedSgprs_offsetof||0)+")",
    ldsSizePerLocalWorkGroup: "u32("+(V.VkShaderResourceUsageAMD_ldsSizePerLocalWorkGroup_offsetof||0)+")",
    ldsUsageSizeInBytes: "u64("+(V.VkShaderResourceUsageAMD_ldsUsageSizeInBytes_offsetof||0)+")",
    scratchMemUsageInBytes: "u64("+(V.VkShaderResourceUsageAMD_scratchMemUsageInBytes_offsetof||0)+")",
}, (V.VkShaderResourceUsageAMD_sizeof||0))));


const VkShaderStatisticsInfoAMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkShaderStatisticsInfoAMD", {
    shaderStageMask: "u32("+(V.VkShaderStatisticsInfoAMD_shaderStageMask_offsetof||0)+")",
    resourceUsage: "u32("+(V.VkShaderStatisticsInfoAMD_resourceUsage_offsetof||0)+")",
    numPhysicalVgprs: "u32("+(V.VkShaderStatisticsInfoAMD_numPhysicalVgprs_offsetof||0)+")",
    numPhysicalSgprs: "u32("+(V.VkShaderStatisticsInfoAMD_numPhysicalSgprs_offsetof||0)+")",
    numAvailableVgprs: "u32("+(V.VkShaderStatisticsInfoAMD_numAvailableVgprs_offsetof||0)+")",
    numAvailableSgprs: "u32("+(V.VkShaderStatisticsInfoAMD_numAvailableSgprs_offsetof||0)+")",
    computeWorkGroupSize: "u32[3]("+(V.VkShaderStatisticsInfoAMD_computeWorkGroupSize_offsetof||0)+")",
}, (V.VkShaderStatisticsInfoAMD_sizeof||0))));


const VkDeviceQueueGlobalPriorityCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceQueueGlobalPriorityCreateInfoKHR", {
    sType: "u32("+(V.VkDeviceQueueGlobalPriorityCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceQueueGlobalPriorityCreateInfoKHR_pNext_offsetof||0)+")",
    globalPriority: "u32("+(V.VkDeviceQueueGlobalPriorityCreateInfoKHR_globalPriority_offsetof||0)+")",
}, (V.VkDeviceQueueGlobalPriorityCreateInfoKHR_sizeof||0))));

const VkDeviceQueueGlobalPriorityCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy("VkDeviceQueueGlobalPriorityCreateInfoKHR"));


const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR_pNext_offsetof||0)+")",
    globalPriorityQuery: "u32("+(V.VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR_globalPriorityQuery_offsetof||0)+")",
}, (V.VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR_sizeof||0))));

const VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR"));


const VkQueueFamilyGlobalPriorityPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkQueueFamilyGlobalPriorityPropertiesKHR", {
    sType: "u32("+(V.VkQueueFamilyGlobalPriorityPropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkQueueFamilyGlobalPriorityPropertiesKHR_pNext_offsetof||0)+")",
    priorityCount: "u32("+(V.VkQueueFamilyGlobalPriorityPropertiesKHR_priorityCount_offsetof||0)+")",
    priorities: "u32["+(E.VK_MAX_GLOBAL_PRIORITY_SIZE_KHR||1)+"]("+(V.VkQueueFamilyGlobalPriorityPropertiesKHR_priorities_offsetof||0)+")",
}, (V.VkQueueFamilyGlobalPriorityPropertiesKHR_sizeof||0))));

const VkQueueFamilyGlobalPriorityPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy("VkQueueFamilyGlobalPriorityPropertiesKHR"));


const VkDebugUtilsObjectNameInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDebugUtilsObjectNameInfoEXT", {
    sType: "u32("+(V.VkDebugUtilsObjectNameInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDebugUtilsObjectNameInfoEXT_pNext_offsetof||0)+")",
    objectType: "u32("+(V.VkDebugUtilsObjectNameInfoEXT_objectType_offsetof||0)+")",
    objectHandle: "u64("+(V.VkDebugUtilsObjectNameInfoEXT_objectHandle_offsetof||0)+")",
    pObjectName: "u64("+(V.VkDebugUtilsObjectNameInfoEXT_pObjectName_offsetof||0)+")",
}, (V.VkDebugUtilsObjectNameInfoEXT_sizeof||0))));


const VkDebugUtilsObjectTagInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDebugUtilsObjectTagInfoEXT", {
    sType: "u32("+(V.VkDebugUtilsObjectTagInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDebugUtilsObjectTagInfoEXT_pNext_offsetof||0)+")",
    objectType: "u32("+(V.VkDebugUtilsObjectTagInfoEXT_objectType_offsetof||0)+")",
    objectHandle: "u64("+(V.VkDebugUtilsObjectTagInfoEXT_objectHandle_offsetof||0)+")",
    tagName: "u64("+(V.VkDebugUtilsObjectTagInfoEXT_tagName_offsetof||0)+")",
    tagSize: "u64("+(V.VkDebugUtilsObjectTagInfoEXT_tagSize_offsetof||0)+")",
    pTag: "u64("+(V.VkDebugUtilsObjectTagInfoEXT_pTag_offsetof||0)+")",
}, (V.VkDebugUtilsObjectTagInfoEXT_sizeof||0))));


const VkDebugUtilsLabelEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDebugUtilsLabelEXT", {
    sType: "u32("+(V.VkDebugUtilsLabelEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDebugUtilsLabelEXT_pNext_offsetof||0)+")",
    pLabelName: "u64("+(V.VkDebugUtilsLabelEXT_pLabelName_offsetof||0)+")",
    color: "f32[4]("+(V.VkDebugUtilsLabelEXT_color_offsetof||0)+")",
}, (V.VkDebugUtilsLabelEXT_sizeof||0))));


const VkDebugUtilsMessengerCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDebugUtilsMessengerCreateInfoEXT", {
    sType: "u32("+(V.VkDebugUtilsMessengerCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDebugUtilsMessengerCreateInfoEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDebugUtilsMessengerCreateInfoEXT_flags_offsetof||0)+")",
    messageSeverity: "u32("+(V.VkDebugUtilsMessengerCreateInfoEXT_messageSeverity_offsetof||0)+")",
    messageType: "u32("+(V.VkDebugUtilsMessengerCreateInfoEXT_messageType_offsetof||0)+")",
    pfnUserCallback: "u32("+(V.VkDebugUtilsMessengerCreateInfoEXT_pfnUserCallback_offsetof||0)+")",
    pUserData: "u64("+(V.VkDebugUtilsMessengerCreateInfoEXT_pUserData_offsetof||0)+")",
}, (V.VkDebugUtilsMessengerCreateInfoEXT_sizeof||0))));


const VkDebugUtilsMessengerCallbackDataEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDebugUtilsMessengerCallbackDataEXT", {
    sType: "u32("+(V.VkDebugUtilsMessengerCallbackDataEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDebugUtilsMessengerCallbackDataEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDebugUtilsMessengerCallbackDataEXT_flags_offsetof||0)+")",
    pMessageIdName: "u64("+(V.VkDebugUtilsMessengerCallbackDataEXT_pMessageIdName_offsetof||0)+")",
    messageIdNumber: "i32("+(V.VkDebugUtilsMessengerCallbackDataEXT_messageIdNumber_offsetof||0)+")",
    pMessage: "u64("+(V.VkDebugUtilsMessengerCallbackDataEXT_pMessage_offsetof||0)+")",
    queueLabelCount: "u32("+(V.VkDebugUtilsMessengerCallbackDataEXT_queueLabelCount_offsetof||0)+")",
    pQueueLabels: "u64("+(V.VkDebugUtilsMessengerCallbackDataEXT_pQueueLabels_offsetof||0)+")",
    cmdBufLabelCount: "u32("+(V.VkDebugUtilsMessengerCallbackDataEXT_cmdBufLabelCount_offsetof||0)+")",
    pCmdBufLabels: "u64("+(V.VkDebugUtilsMessengerCallbackDataEXT_pCmdBufLabels_offsetof||0)+")",
    objectCount: "u32("+(V.VkDebugUtilsMessengerCallbackDataEXT_objectCount_offsetof||0)+")",
    pObjects: "u64("+(V.VkDebugUtilsMessengerCallbackDataEXT_pObjects_offsetof||0)+")",
}, (V.VkDebugUtilsMessengerCallbackDataEXT_sizeof||0))));


const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDeviceMemoryReportFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceDeviceMemoryReportFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDeviceMemoryReportFeaturesEXT_pNext_offsetof||0)+")",
    deviceMemoryReport: "u32("+(V.VkPhysicalDeviceDeviceMemoryReportFeaturesEXT_deviceMemoryReport_offsetof||0)+")",
}, (V.VkPhysicalDeviceDeviceMemoryReportFeaturesEXT_sizeof||0))));


const VkDeviceDeviceMemoryReportCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceDeviceMemoryReportCreateInfoEXT", {
    sType: "u32("+(V.VkDeviceDeviceMemoryReportCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceDeviceMemoryReportCreateInfoEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDeviceDeviceMemoryReportCreateInfoEXT_flags_offsetof||0)+")",
    pfnUserCallback: "u32("+(V.VkDeviceDeviceMemoryReportCreateInfoEXT_pfnUserCallback_offsetof||0)+")",
    pUserData: "u64("+(V.VkDeviceDeviceMemoryReportCreateInfoEXT_pUserData_offsetof||0)+")",
}, (V.VkDeviceDeviceMemoryReportCreateInfoEXT_sizeof||0))));


const VkDeviceMemoryReportCallbackDataEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceMemoryReportCallbackDataEXT", {
    sType: "u32("+(V.VkDeviceMemoryReportCallbackDataEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceMemoryReportCallbackDataEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDeviceMemoryReportCallbackDataEXT_flags_offsetof||0)+")",
    type: "u32("+(V.VkDeviceMemoryReportCallbackDataEXT_type_offsetof||0)+")",
    memoryObjectId: "u64("+(V.VkDeviceMemoryReportCallbackDataEXT_memoryObjectId_offsetof||0)+")",
    size: "u64("+(V.VkDeviceMemoryReportCallbackDataEXT_size_offsetof||0)+")",
    objectType: "u32("+(V.VkDeviceMemoryReportCallbackDataEXT_objectType_offsetof||0)+")",
    objectHandle: "u64("+(V.VkDeviceMemoryReportCallbackDataEXT_objectHandle_offsetof||0)+")",
    heapIndex: "u32("+(V.VkDeviceMemoryReportCallbackDataEXT_heapIndex_offsetof||0)+")",
}, (V.VkDeviceMemoryReportCallbackDataEXT_sizeof||0))));


const VkImportMemoryHostPointerInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportMemoryHostPointerInfoEXT", {
    sType: "u32("+(V.VkImportMemoryHostPointerInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportMemoryHostPointerInfoEXT_pNext_offsetof||0)+")",
    handleType: "u32("+(V.VkImportMemoryHostPointerInfoEXT_handleType_offsetof||0)+")",
    pHostPointer: "u64("+(V.VkImportMemoryHostPointerInfoEXT_pHostPointer_offsetof||0)+")",
}, (V.VkImportMemoryHostPointerInfoEXT_sizeof||0))));


const VkMemoryHostPointerPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryHostPointerPropertiesEXT", {
    sType: "u32("+(V.VkMemoryHostPointerPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryHostPointerPropertiesEXT_pNext_offsetof||0)+")",
    memoryTypeBits: "u32("+(V.VkMemoryHostPointerPropertiesEXT_memoryTypeBits_offsetof||0)+")",
}, (V.VkMemoryHostPointerPropertiesEXT_sizeof||0))));


const VkPhysicalDeviceExternalMemoryHostPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceExternalMemoryHostPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceExternalMemoryHostPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceExternalMemoryHostPropertiesEXT_pNext_offsetof||0)+")",
    minImportedHostPointerAlignment: "u64("+(V.VkPhysicalDeviceExternalMemoryHostPropertiesEXT_minImportedHostPointerAlignment_offsetof||0)+")",
}, (V.VkPhysicalDeviceExternalMemoryHostPropertiesEXT_sizeof||0))));


const VkPhysicalDeviceConservativeRasterizationPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceConservativeRasterizationPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_pNext_offsetof||0)+")",
    primitiveOverestimationSize: "f32("+(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_primitiveOverestimationSize_offsetof||0)+")",
    maxExtraPrimitiveOverestimationSize: "f32("+(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_maxExtraPrimitiveOverestimationSize_offsetof||0)+")",
    extraPrimitiveOverestimationSizeGranularity: "f32("+(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_extraPrimitiveOverestimationSizeGranularity_offsetof||0)+")",
    primitiveUnderestimation: "u32("+(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_primitiveUnderestimation_offsetof||0)+")",
    conservativePointAndLineRasterization: "u32("+(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_conservativePointAndLineRasterization_offsetof||0)+")",
    degenerateTrianglesRasterized: "u32("+(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_degenerateTrianglesRasterized_offsetof||0)+")",
    degenerateLinesRasterized: "u32("+(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_degenerateLinesRasterized_offsetof||0)+")",
    fullyCoveredFragmentShaderInputVariable: "u32("+(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_fullyCoveredFragmentShaderInputVariable_offsetof||0)+")",
    conservativeRasterizationPostDepthCoverage: "u32("+(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_conservativeRasterizationPostDepthCoverage_offsetof||0)+")",
}, (V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_sizeof||0))));


const VkCalibratedTimestampInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCalibratedTimestampInfoEXT", {
    sType: "u32("+(V.VkCalibratedTimestampInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCalibratedTimestampInfoEXT_pNext_offsetof||0)+")",
    timeDomain: "u32("+(V.VkCalibratedTimestampInfoEXT_timeDomain_offsetof||0)+")",
}, (V.VkCalibratedTimestampInfoEXT_sizeof||0))));


const VkPhysicalDeviceShaderCorePropertiesAMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderCorePropertiesAMD", {
    sType: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_pNext_offsetof||0)+")",
    shaderEngineCount: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_shaderEngineCount_offsetof||0)+")",
    shaderArraysPerEngineCount: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_shaderArraysPerEngineCount_offsetof||0)+")",
    computeUnitsPerShaderArray: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_computeUnitsPerShaderArray_offsetof||0)+")",
    simdPerComputeUnit: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_simdPerComputeUnit_offsetof||0)+")",
    wavefrontsPerSimd: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_wavefrontsPerSimd_offsetof||0)+")",
    wavefrontSize: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_wavefrontSize_offsetof||0)+")",
    sgprsPerSimd: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_sgprsPerSimd_offsetof||0)+")",
    minSgprAllocation: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_minSgprAllocation_offsetof||0)+")",
    maxSgprAllocation: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_maxSgprAllocation_offsetof||0)+")",
    sgprAllocationGranularity: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_sgprAllocationGranularity_offsetof||0)+")",
    vgprsPerSimd: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_vgprsPerSimd_offsetof||0)+")",
    minVgprAllocation: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_minVgprAllocation_offsetof||0)+")",
    maxVgprAllocation: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_maxVgprAllocation_offsetof||0)+")",
    vgprAllocationGranularity: "u32("+(V.VkPhysicalDeviceShaderCorePropertiesAMD_vgprAllocationGranularity_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderCorePropertiesAMD_sizeof||0))));


const VkPhysicalDeviceShaderCoreProperties2AMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderCoreProperties2AMD", {
    sType: "u32("+(V.VkPhysicalDeviceShaderCoreProperties2AMD_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderCoreProperties2AMD_pNext_offsetof||0)+")",
    shaderCoreFeatures: "u32("+(V.VkPhysicalDeviceShaderCoreProperties2AMD_shaderCoreFeatures_offsetof||0)+")",
    activeComputeUnitCount: "u32("+(V.VkPhysicalDeviceShaderCoreProperties2AMD_activeComputeUnitCount_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderCoreProperties2AMD_sizeof||0))));


const VkPipelineRasterizationConservativeStateCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineRasterizationConservativeStateCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineRasterizationConservativeStateCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineRasterizationConservativeStateCreateInfoEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineRasterizationConservativeStateCreateInfoEXT_flags_offsetof||0)+")",
    conservativeRasterizationMode: "u32("+(V.VkPipelineRasterizationConservativeStateCreateInfoEXT_conservativeRasterizationMode_offsetof||0)+")",
    extraPrimitiveOverestimationSize: "f32("+(V.VkPipelineRasterizationConservativeStateCreateInfoEXT_extraPrimitiveOverestimationSize_offsetof||0)+")",
}, (V.VkPipelineRasterizationConservativeStateCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceDescriptorIndexingFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDescriptorIndexingFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_pNext_offsetof||0)+")",
    shaderInputAttachmentArrayDynamicIndexing: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderInputAttachmentArrayDynamicIndexing_offsetof||0)+")",
    shaderUniformTexelBufferArrayDynamicIndexing: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderUniformTexelBufferArrayDynamicIndexing_offsetof||0)+")",
    shaderStorageTexelBufferArrayDynamicIndexing: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderStorageTexelBufferArrayDynamicIndexing_offsetof||0)+")",
    shaderUniformBufferArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderUniformBufferArrayNonUniformIndexing_offsetof||0)+")",
    shaderSampledImageArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderSampledImageArrayNonUniformIndexing_offsetof||0)+")",
    shaderStorageBufferArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderStorageBufferArrayNonUniformIndexing_offsetof||0)+")",
    shaderStorageImageArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderStorageImageArrayNonUniformIndexing_offsetof||0)+")",
    shaderInputAttachmentArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderInputAttachmentArrayNonUniformIndexing_offsetof||0)+")",
    shaderUniformTexelBufferArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderUniformTexelBufferArrayNonUniformIndexing_offsetof||0)+")",
    shaderStorageTexelBufferArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderStorageTexelBufferArrayNonUniformIndexing_offsetof||0)+")",
    descriptorBindingUniformBufferUpdateAfterBind: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingUniformBufferUpdateAfterBind_offsetof||0)+")",
    descriptorBindingSampledImageUpdateAfterBind: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingSampledImageUpdateAfterBind_offsetof||0)+")",
    descriptorBindingStorageImageUpdateAfterBind: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingStorageImageUpdateAfterBind_offsetof||0)+")",
    descriptorBindingStorageBufferUpdateAfterBind: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingStorageBufferUpdateAfterBind_offsetof||0)+")",
    descriptorBindingUniformTexelBufferUpdateAfterBind: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingUniformTexelBufferUpdateAfterBind_offsetof||0)+")",
    descriptorBindingStorageTexelBufferUpdateAfterBind: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingStorageTexelBufferUpdateAfterBind_offsetof||0)+")",
    descriptorBindingUpdateUnusedWhilePending: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingUpdateUnusedWhilePending_offsetof||0)+")",
    descriptorBindingPartiallyBound: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingPartiallyBound_offsetof||0)+")",
    descriptorBindingVariableDescriptorCount: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingVariableDescriptorCount_offsetof||0)+")",
    runtimeDescriptorArray: "u32("+(V.VkPhysicalDeviceDescriptorIndexingFeatures_runtimeDescriptorArray_offsetof||0)+")",
}, (V.VkPhysicalDeviceDescriptorIndexingFeatures_sizeof||0))));

const VkPhysicalDeviceDescriptorIndexingFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceDescriptorIndexingFeatures"));


const VkPhysicalDeviceDescriptorIndexingProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDescriptorIndexingProperties", {
    sType: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDescriptorIndexingProperties_pNext_offsetof||0)+")",
    maxUpdateAfterBindDescriptorsInAllPools: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxUpdateAfterBindDescriptorsInAllPools_offsetof||0)+")",
    shaderUniformBufferArrayNonUniformIndexingNative: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_shaderUniformBufferArrayNonUniformIndexingNative_offsetof||0)+")",
    shaderSampledImageArrayNonUniformIndexingNative: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_shaderSampledImageArrayNonUniformIndexingNative_offsetof||0)+")",
    shaderStorageBufferArrayNonUniformIndexingNative: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_shaderStorageBufferArrayNonUniformIndexingNative_offsetof||0)+")",
    shaderStorageImageArrayNonUniformIndexingNative: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_shaderStorageImageArrayNonUniformIndexingNative_offsetof||0)+")",
    shaderInputAttachmentArrayNonUniformIndexingNative: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_shaderInputAttachmentArrayNonUniformIndexingNative_offsetof||0)+")",
    robustBufferAccessUpdateAfterBind: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_robustBufferAccessUpdateAfterBind_offsetof||0)+")",
    quadDivergentImplicitLod: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_quadDivergentImplicitLod_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindSamplers: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageDescriptorUpdateAfterBindSamplers_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindUniformBuffers: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageDescriptorUpdateAfterBindUniformBuffers_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindStorageBuffers: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageDescriptorUpdateAfterBindStorageBuffers_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindSampledImages: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageDescriptorUpdateAfterBindSampledImages_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindStorageImages: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageDescriptorUpdateAfterBindStorageImages_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindInputAttachments: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageDescriptorUpdateAfterBindInputAttachments_offsetof||0)+")",
    maxPerStageUpdateAfterBindResources: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageUpdateAfterBindResources_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindSamplers: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindSamplers_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindUniformBuffers: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindUniformBuffers_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindUniformBuffersDynamic: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindUniformBuffersDynamic_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindStorageBuffers: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindStorageBuffers_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindStorageBuffersDynamic: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindStorageBuffersDynamic_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindSampledImages: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindSampledImages_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindStorageImages: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindStorageImages_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindInputAttachments: "u32("+(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindInputAttachments_offsetof||0)+")",
}, (V.VkPhysicalDeviceDescriptorIndexingProperties_sizeof||0))));

const VkPhysicalDeviceDescriptorIndexingPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceDescriptorIndexingProperties"));


const VkDescriptorSetLayoutBindingFlagsCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorSetLayoutBindingFlagsCreateInfo", {
    sType: "u32("+(V.VkDescriptorSetLayoutBindingFlagsCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDescriptorSetLayoutBindingFlagsCreateInfo_pNext_offsetof||0)+")",
    bindingCount: "u32("+(V.VkDescriptorSetLayoutBindingFlagsCreateInfo_bindingCount_offsetof||0)+")",
    pBindingFlags: "u64("+(V.VkDescriptorSetLayoutBindingFlagsCreateInfo_pBindingFlags_offsetof||0)+")",
}, (V.VkDescriptorSetLayoutBindingFlagsCreateInfo_sizeof||0))));

const VkDescriptorSetLayoutBindingFlagsCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy("VkDescriptorSetLayoutBindingFlagsCreateInfo"));


const VkDescriptorSetVariableDescriptorCountAllocateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorSetVariableDescriptorCountAllocateInfo", {
    sType: "u32("+(V.VkDescriptorSetVariableDescriptorCountAllocateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDescriptorSetVariableDescriptorCountAllocateInfo_pNext_offsetof||0)+")",
    descriptorSetCount: "u32("+(V.VkDescriptorSetVariableDescriptorCountAllocateInfo_descriptorSetCount_offsetof||0)+")",
    pDescriptorCounts: "u64("+(V.VkDescriptorSetVariableDescriptorCountAllocateInfo_pDescriptorCounts_offsetof||0)+")",
}, (V.VkDescriptorSetVariableDescriptorCountAllocateInfo_sizeof||0))));

const VkDescriptorSetVariableDescriptorCountAllocateInfoEXT = new Proxy(function(){}, new C.ConstructProxy("VkDescriptorSetVariableDescriptorCountAllocateInfo"));


const VkDescriptorSetVariableDescriptorCountLayoutSupport = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorSetVariableDescriptorCountLayoutSupport", {
    sType: "u32("+(V.VkDescriptorSetVariableDescriptorCountLayoutSupport_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDescriptorSetVariableDescriptorCountLayoutSupport_pNext_offsetof||0)+")",
    maxVariableDescriptorCount: "u32("+(V.VkDescriptorSetVariableDescriptorCountLayoutSupport_maxVariableDescriptorCount_offsetof||0)+")",
}, (V.VkDescriptorSetVariableDescriptorCountLayoutSupport_sizeof||0))));

const VkDescriptorSetVariableDescriptorCountLayoutSupportEXT = new Proxy(function(){}, new C.ConstructProxy("VkDescriptorSetVariableDescriptorCountLayoutSupport"));


const VkAttachmentDescription2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAttachmentDescription2", {
    sType: "u32("+(V.VkAttachmentDescription2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAttachmentDescription2_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkAttachmentDescription2_flags_offsetof||0)+")",
    format: "u32("+(V.VkAttachmentDescription2_format_offsetof||0)+")",
    samples: "u32("+(V.VkAttachmentDescription2_samples_offsetof||0)+")",
    loadOp: "u32("+(V.VkAttachmentDescription2_loadOp_offsetof||0)+")",
    storeOp: "u32("+(V.VkAttachmentDescription2_storeOp_offsetof||0)+")",
    stencilLoadOp: "u32("+(V.VkAttachmentDescription2_stencilLoadOp_offsetof||0)+")",
    stencilStoreOp: "u32("+(V.VkAttachmentDescription2_stencilStoreOp_offsetof||0)+")",
    initialLayout: "u32("+(V.VkAttachmentDescription2_initialLayout_offsetof||0)+")",
    finalLayout: "u32("+(V.VkAttachmentDescription2_finalLayout_offsetof||0)+")",
}, (V.VkAttachmentDescription2_sizeof||0))));

const VkAttachmentDescription2KHR = new Proxy(function(){}, new C.ConstructProxy("VkAttachmentDescription2"));


const VkAttachmentReference2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAttachmentReference2", {
    sType: "u32("+(V.VkAttachmentReference2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAttachmentReference2_pNext_offsetof||0)+")",
    attachment: "u32("+(V.VkAttachmentReference2_attachment_offsetof||0)+")",
    layout: "u32("+(V.VkAttachmentReference2_layout_offsetof||0)+")",
    aspectMask: "u32("+(V.VkAttachmentReference2_aspectMask_offsetof||0)+")",
}, (V.VkAttachmentReference2_sizeof||0))));

const VkAttachmentReference2KHR = new Proxy(function(){}, new C.ConstructProxy("VkAttachmentReference2"));


const VkSubpassDescription2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubpassDescription2", {
    sType: "u32("+(V.VkSubpassDescription2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSubpassDescription2_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkSubpassDescription2_flags_offsetof||0)+")",
    pipelineBindPoint: "u32("+(V.VkSubpassDescription2_pipelineBindPoint_offsetof||0)+")",
    viewMask: "u32("+(V.VkSubpassDescription2_viewMask_offsetof||0)+")",
    inputAttachmentCount: "u32("+(V.VkSubpassDescription2_inputAttachmentCount_offsetof||0)+")",
    pInputAttachments: "u64("+(V.VkSubpassDescription2_pInputAttachments_offsetof||0)+")",
    colorAttachmentCount: "u32("+(V.VkSubpassDescription2_colorAttachmentCount_offsetof||0)+")",
    pColorAttachments: "u64("+(V.VkSubpassDescription2_pColorAttachments_offsetof||0)+")",
    pResolveAttachments: "u64("+(V.VkSubpassDescription2_pResolveAttachments_offsetof||0)+")",
    pDepthStencilAttachment: "u64("+(V.VkSubpassDescription2_pDepthStencilAttachment_offsetof||0)+")",
    preserveAttachmentCount: "u32("+(V.VkSubpassDescription2_preserveAttachmentCount_offsetof||0)+")",
    pPreserveAttachments: "u64("+(V.VkSubpassDescription2_pPreserveAttachments_offsetof||0)+")",
}, (V.VkSubpassDescription2_sizeof||0))));

const VkSubpassDescription2KHR = new Proxy(function(){}, new C.ConstructProxy("VkSubpassDescription2"));


const VkSubpassDependency2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubpassDependency2", {
    sType: "u32("+(V.VkSubpassDependency2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSubpassDependency2_pNext_offsetof||0)+")",
    srcSubpass: "u32("+(V.VkSubpassDependency2_srcSubpass_offsetof||0)+")",
    dstSubpass: "u32("+(V.VkSubpassDependency2_dstSubpass_offsetof||0)+")",
    srcStageMask: "u32("+(V.VkSubpassDependency2_srcStageMask_offsetof||0)+")",
    dstStageMask: "u32("+(V.VkSubpassDependency2_dstStageMask_offsetof||0)+")",
    srcAccessMask: "u32("+(V.VkSubpassDependency2_srcAccessMask_offsetof||0)+")",
    dstAccessMask: "u32("+(V.VkSubpassDependency2_dstAccessMask_offsetof||0)+")",
    dependencyFlags: "u32("+(V.VkSubpassDependency2_dependencyFlags_offsetof||0)+")",
    viewOffset: "i32("+(V.VkSubpassDependency2_viewOffset_offsetof||0)+")",
}, (V.VkSubpassDependency2_sizeof||0))));

const VkSubpassDependency2KHR = new Proxy(function(){}, new C.ConstructProxy("VkSubpassDependency2"));


const VkRenderPassCreateInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassCreateInfo2", {
    sType: "u32("+(V.VkRenderPassCreateInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderPassCreateInfo2_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkRenderPassCreateInfo2_flags_offsetof||0)+")",
    attachmentCount: "u32("+(V.VkRenderPassCreateInfo2_attachmentCount_offsetof||0)+")",
    pAttachments: "u64("+(V.VkRenderPassCreateInfo2_pAttachments_offsetof||0)+")",
    subpassCount: "u32("+(V.VkRenderPassCreateInfo2_subpassCount_offsetof||0)+")",
    pSubpasses: "u64("+(V.VkRenderPassCreateInfo2_pSubpasses_offsetof||0)+")",
    dependencyCount: "u32("+(V.VkRenderPassCreateInfo2_dependencyCount_offsetof||0)+")",
    pDependencies: "u64("+(V.VkRenderPassCreateInfo2_pDependencies_offsetof||0)+")",
    correlatedViewMaskCount: "u32("+(V.VkRenderPassCreateInfo2_correlatedViewMaskCount_offsetof||0)+")",
    pCorrelatedViewMasks: "u64("+(V.VkRenderPassCreateInfo2_pCorrelatedViewMasks_offsetof||0)+")",
}, (V.VkRenderPassCreateInfo2_sizeof||0))));

const VkRenderPassCreateInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkRenderPassCreateInfo2"));


const VkSubpassBeginInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubpassBeginInfo", {
    sType: "u32("+(V.VkSubpassBeginInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSubpassBeginInfo_pNext_offsetof||0)+")",
    contents: "u32("+(V.VkSubpassBeginInfo_contents_offsetof||0)+")",
}, (V.VkSubpassBeginInfo_sizeof||0))));

const VkSubpassBeginInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkSubpassBeginInfo"));


const VkSubpassEndInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubpassEndInfo", {
    sType: "u32("+(V.VkSubpassEndInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSubpassEndInfo_pNext_offsetof||0)+")",
}, (V.VkSubpassEndInfo_sizeof||0))));

const VkSubpassEndInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkSubpassEndInfo"));


const VkPhysicalDeviceTimelineSemaphoreFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceTimelineSemaphoreFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceTimelineSemaphoreFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceTimelineSemaphoreFeatures_pNext_offsetof||0)+")",
    timelineSemaphore: "u32("+(V.VkPhysicalDeviceTimelineSemaphoreFeatures_timelineSemaphore_offsetof||0)+")",
}, (V.VkPhysicalDeviceTimelineSemaphoreFeatures_sizeof||0))));

const VkPhysicalDeviceTimelineSemaphoreFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceTimelineSemaphoreFeatures"));


const VkPhysicalDeviceTimelineSemaphoreProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceTimelineSemaphoreProperties", {
    sType: "u32("+(V.VkPhysicalDeviceTimelineSemaphoreProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceTimelineSemaphoreProperties_pNext_offsetof||0)+")",
    maxTimelineSemaphoreValueDifference: "u64("+(V.VkPhysicalDeviceTimelineSemaphoreProperties_maxTimelineSemaphoreValueDifference_offsetof||0)+")",
}, (V.VkPhysicalDeviceTimelineSemaphoreProperties_sizeof||0))));

const VkPhysicalDeviceTimelineSemaphorePropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceTimelineSemaphoreProperties"));


const VkSemaphoreTypeCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSemaphoreTypeCreateInfo", {
    sType: "u32("+(V.VkSemaphoreTypeCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSemaphoreTypeCreateInfo_pNext_offsetof||0)+")",
    semaphoreType: "u32("+(V.VkSemaphoreTypeCreateInfo_semaphoreType_offsetof||0)+")",
    initialValue: "u64("+(V.VkSemaphoreTypeCreateInfo_initialValue_offsetof||0)+")",
}, (V.VkSemaphoreTypeCreateInfo_sizeof||0))));

const VkSemaphoreTypeCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkSemaphoreTypeCreateInfo"));


const VkTimelineSemaphoreSubmitInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkTimelineSemaphoreSubmitInfo", {
    sType: "u32("+(V.VkTimelineSemaphoreSubmitInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkTimelineSemaphoreSubmitInfo_pNext_offsetof||0)+")",
    waitSemaphoreValueCount: "u32("+(V.VkTimelineSemaphoreSubmitInfo_waitSemaphoreValueCount_offsetof||0)+")",
    pWaitSemaphoreValues: "u64("+(V.VkTimelineSemaphoreSubmitInfo_pWaitSemaphoreValues_offsetof||0)+")",
    signalSemaphoreValueCount: "u32("+(V.VkTimelineSemaphoreSubmitInfo_signalSemaphoreValueCount_offsetof||0)+")",
    pSignalSemaphoreValues: "u64("+(V.VkTimelineSemaphoreSubmitInfo_pSignalSemaphoreValues_offsetof||0)+")",
}, (V.VkTimelineSemaphoreSubmitInfo_sizeof||0))));

const VkTimelineSemaphoreSubmitInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkTimelineSemaphoreSubmitInfo"));


const VkSemaphoreWaitInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSemaphoreWaitInfo", {
    sType: "u32("+(V.VkSemaphoreWaitInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSemaphoreWaitInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkSemaphoreWaitInfo_flags_offsetof||0)+")",
    semaphoreCount: "u32("+(V.VkSemaphoreWaitInfo_semaphoreCount_offsetof||0)+")",
    pSemaphores: "u64("+(V.VkSemaphoreWaitInfo_pSemaphores_offsetof||0)+")",
    pValues: "u64("+(V.VkSemaphoreWaitInfo_pValues_offsetof||0)+")",
}, (V.VkSemaphoreWaitInfo_sizeof||0))));

const VkSemaphoreWaitInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkSemaphoreWaitInfo"));


const VkSemaphoreSignalInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSemaphoreSignalInfo", {
    sType: "u32("+(V.VkSemaphoreSignalInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSemaphoreSignalInfo_pNext_offsetof||0)+")",
    semaphore: "u64("+(V.VkSemaphoreSignalInfo_semaphore_offsetof||0)+")",
    value: "u64("+(V.VkSemaphoreSignalInfo_value_offsetof||0)+")",
}, (V.VkSemaphoreSignalInfo_sizeof||0))));

const VkSemaphoreSignalInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkSemaphoreSignalInfo"));


const VkVertexInputBindingDivisorDescriptionEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVertexInputBindingDivisorDescriptionEXT", {
    binding: "u32("+(V.VkVertexInputBindingDivisorDescriptionEXT_binding_offsetof||0)+")",
    divisor: "u32("+(V.VkVertexInputBindingDivisorDescriptionEXT_divisor_offsetof||0)+")",
}, (V.VkVertexInputBindingDivisorDescriptionEXT_sizeof||0))));


const VkPipelineVertexInputDivisorStateCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineVertexInputDivisorStateCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineVertexInputDivisorStateCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineVertexInputDivisorStateCreateInfoEXT_pNext_offsetof||0)+")",
    vertexBindingDivisorCount: "u32("+(V.VkPipelineVertexInputDivisorStateCreateInfoEXT_vertexBindingDivisorCount_offsetof||0)+")",
    pVertexBindingDivisors: "u64("+(V.VkPipelineVertexInputDivisorStateCreateInfoEXT_pVertexBindingDivisors_offsetof||0)+")",
}, (V.VkPipelineVertexInputDivisorStateCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT_pNext_offsetof||0)+")",
    maxVertexAttribDivisor: "u32("+(V.VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT_maxVertexAttribDivisor_offsetof||0)+")",
}, (V.VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT_sizeof||0))));


const VkPhysicalDevicePCIBusInfoPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePCIBusInfoPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_pNext_offsetof||0)+")",
    pciDomain: "u32("+(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_pciDomain_offsetof||0)+")",
    pciBus: "u32("+(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_pciBus_offsetof||0)+")",
    pciDevice: "u32("+(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_pciDevice_offsetof||0)+")",
    pciFunction: "u32("+(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_pciFunction_offsetof||0)+")",
}, (V.VkPhysicalDevicePCIBusInfoPropertiesEXT_sizeof||0))));


const VkImportAndroidHardwareBufferInfoANDROID = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportAndroidHardwareBufferInfoANDROID", {
    sType: "u32("+(V.VkImportAndroidHardwareBufferInfoANDROID_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportAndroidHardwareBufferInfoANDROID_pNext_offsetof||0)+")",
    buffer: "u64("+(V.VkImportAndroidHardwareBufferInfoANDROID_buffer_offsetof||0)+")",
}, (V.VkImportAndroidHardwareBufferInfoANDROID_sizeof||0))));


const VkAndroidHardwareBufferUsageANDROID = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAndroidHardwareBufferUsageANDROID", {
    sType: "u32("+(V.VkAndroidHardwareBufferUsageANDROID_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAndroidHardwareBufferUsageANDROID_pNext_offsetof||0)+")",
    androidHardwareBufferUsage: "u64("+(V.VkAndroidHardwareBufferUsageANDROID_androidHardwareBufferUsage_offsetof||0)+")",
}, (V.VkAndroidHardwareBufferUsageANDROID_sizeof||0))));


const VkAndroidHardwareBufferPropertiesANDROID = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAndroidHardwareBufferPropertiesANDROID", {
    sType: "u32("+(V.VkAndroidHardwareBufferPropertiesANDROID_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAndroidHardwareBufferPropertiesANDROID_pNext_offsetof||0)+")",
    allocationSize: "u64("+(V.VkAndroidHardwareBufferPropertiesANDROID_allocationSize_offsetof||0)+")",
    memoryTypeBits: "u32("+(V.VkAndroidHardwareBufferPropertiesANDROID_memoryTypeBits_offsetof||0)+")",
}, (V.VkAndroidHardwareBufferPropertiesANDROID_sizeof||0))));


const VkMemoryGetAndroidHardwareBufferInfoANDROID = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryGetAndroidHardwareBufferInfoANDROID", {
    sType: "u32("+(V.VkMemoryGetAndroidHardwareBufferInfoANDROID_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryGetAndroidHardwareBufferInfoANDROID_pNext_offsetof||0)+")",
    memory: "u64("+(V.VkMemoryGetAndroidHardwareBufferInfoANDROID_memory_offsetof||0)+")",
}, (V.VkMemoryGetAndroidHardwareBufferInfoANDROID_sizeof||0))));


const VkAndroidHardwareBufferFormatPropertiesANDROID = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAndroidHardwareBufferFormatPropertiesANDROID", {
    sType: "u32("+(V.VkAndroidHardwareBufferFormatPropertiesANDROID_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAndroidHardwareBufferFormatPropertiesANDROID_pNext_offsetof||0)+")",
    format: "u32("+(V.VkAndroidHardwareBufferFormatPropertiesANDROID_format_offsetof||0)+")",
    externalFormat: "u64("+(V.VkAndroidHardwareBufferFormatPropertiesANDROID_externalFormat_offsetof||0)+")",
    formatFeatures: "u32("+(V.VkAndroidHardwareBufferFormatPropertiesANDROID_formatFeatures_offsetof||0)+")",
    samplerYcbcrConversionComponents: "u32("+(V.VkAndroidHardwareBufferFormatPropertiesANDROID_samplerYcbcrConversionComponents_offsetof||0)+")",
    suggestedYcbcrModel: "u32("+(V.VkAndroidHardwareBufferFormatPropertiesANDROID_suggestedYcbcrModel_offsetof||0)+")",
    suggestedYcbcrRange: "u32("+(V.VkAndroidHardwareBufferFormatPropertiesANDROID_suggestedYcbcrRange_offsetof||0)+")",
    suggestedXChromaOffset: "u32("+(V.VkAndroidHardwareBufferFormatPropertiesANDROID_suggestedXChromaOffset_offsetof||0)+")",
    suggestedYChromaOffset: "u32("+(V.VkAndroidHardwareBufferFormatPropertiesANDROID_suggestedYChromaOffset_offsetof||0)+")",
}, (V.VkAndroidHardwareBufferFormatPropertiesANDROID_sizeof||0))));


const VkCommandBufferInheritanceConditionalRenderingInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCommandBufferInheritanceConditionalRenderingInfoEXT", {
    sType: "u32("+(V.VkCommandBufferInheritanceConditionalRenderingInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCommandBufferInheritanceConditionalRenderingInfoEXT_pNext_offsetof||0)+")",
    conditionalRenderingEnable: "u32("+(V.VkCommandBufferInheritanceConditionalRenderingInfoEXT_conditionalRenderingEnable_offsetof||0)+")",
}, (V.VkCommandBufferInheritanceConditionalRenderingInfoEXT_sizeof||0))));


const VkExternalFormatANDROID = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExternalFormatANDROID", {
    sType: "u32("+(V.VkExternalFormatANDROID_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExternalFormatANDROID_pNext_offsetof||0)+")",
    externalFormat: "u64("+(V.VkExternalFormatANDROID_externalFormat_offsetof||0)+")",
}, (V.VkExternalFormatANDROID_sizeof||0))));


const VkPhysicalDevice8BitStorageFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevice8BitStorageFeatures", {
    sType: "u32("+(V.VkPhysicalDevice8BitStorageFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevice8BitStorageFeatures_pNext_offsetof||0)+")",
    storageBuffer8BitAccess: "u32("+(V.VkPhysicalDevice8BitStorageFeatures_storageBuffer8BitAccess_offsetof||0)+")",
    uniformAndStorageBuffer8BitAccess: "u32("+(V.VkPhysicalDevice8BitStorageFeatures_uniformAndStorageBuffer8BitAccess_offsetof||0)+")",
    storagePushConstant8: "u32("+(V.VkPhysicalDevice8BitStorageFeatures_storagePushConstant8_offsetof||0)+")",
}, (V.VkPhysicalDevice8BitStorageFeatures_sizeof||0))));

const VkPhysicalDevice8BitStorageFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDevice8BitStorageFeatures"));


const VkPhysicalDeviceConditionalRenderingFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceConditionalRenderingFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceConditionalRenderingFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceConditionalRenderingFeaturesEXT_pNext_offsetof||0)+")",
    conditionalRendering: "u32("+(V.VkPhysicalDeviceConditionalRenderingFeaturesEXT_conditionalRendering_offsetof||0)+")",
    inheritedConditionalRendering: "u32("+(V.VkPhysicalDeviceConditionalRenderingFeaturesEXT_inheritedConditionalRendering_offsetof||0)+")",
}, (V.VkPhysicalDeviceConditionalRenderingFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceVulkanMemoryModelFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceVulkanMemoryModelFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceVulkanMemoryModelFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceVulkanMemoryModelFeatures_pNext_offsetof||0)+")",
    vulkanMemoryModel: "u32("+(V.VkPhysicalDeviceVulkanMemoryModelFeatures_vulkanMemoryModel_offsetof||0)+")",
    vulkanMemoryModelDeviceScope: "u32("+(V.VkPhysicalDeviceVulkanMemoryModelFeatures_vulkanMemoryModelDeviceScope_offsetof||0)+")",
    vulkanMemoryModelAvailabilityVisibilityChains: "u32("+(V.VkPhysicalDeviceVulkanMemoryModelFeatures_vulkanMemoryModelAvailabilityVisibilityChains_offsetof||0)+")",
}, (V.VkPhysicalDeviceVulkanMemoryModelFeatures_sizeof||0))));

const VkPhysicalDeviceVulkanMemoryModelFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceVulkanMemoryModelFeatures"));


const VkPhysicalDeviceShaderAtomicInt64Features = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderAtomicInt64Features", {
    sType: "u32("+(V.VkPhysicalDeviceShaderAtomicInt64Features_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderAtomicInt64Features_pNext_offsetof||0)+")",
    shaderBufferInt64Atomics: "u32("+(V.VkPhysicalDeviceShaderAtomicInt64Features_shaderBufferInt64Atomics_offsetof||0)+")",
    shaderSharedInt64Atomics: "u32("+(V.VkPhysicalDeviceShaderAtomicInt64Features_shaderSharedInt64Atomics_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderAtomicInt64Features_sizeof||0))));

const VkPhysicalDeviceShaderAtomicInt64FeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceShaderAtomicInt64Features"));


const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_pNext_offsetof||0)+")",
    shaderBufferFloat32Atomics: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderBufferFloat32Atomics_offsetof||0)+")",
    shaderBufferFloat32AtomicAdd: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderBufferFloat32AtomicAdd_offsetof||0)+")",
    shaderBufferFloat64Atomics: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderBufferFloat64Atomics_offsetof||0)+")",
    shaderBufferFloat64AtomicAdd: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderBufferFloat64AtomicAdd_offsetof||0)+")",
    shaderSharedFloat32Atomics: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderSharedFloat32Atomics_offsetof||0)+")",
    shaderSharedFloat32AtomicAdd: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderSharedFloat32AtomicAdd_offsetof||0)+")",
    shaderSharedFloat64Atomics: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderSharedFloat64Atomics_offsetof||0)+")",
    shaderSharedFloat64AtomicAdd: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderSharedFloat64AtomicAdd_offsetof||0)+")",
    shaderImageFloat32Atomics: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderImageFloat32Atomics_offsetof||0)+")",
    shaderImageFloat32AtomicAdd: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderImageFloat32AtomicAdd_offsetof||0)+")",
    sparseImageFloat32Atomics: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_sparseImageFloat32Atomics_offsetof||0)+")",
    sparseImageFloat32AtomicAdd: "u32("+(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_sparseImageFloat32AtomicAdd_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_pNext_offsetof||0)+")",
    shaderBufferFloat16Atomics: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderBufferFloat16Atomics_offsetof||0)+")",
    shaderBufferFloat16AtomicAdd: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderBufferFloat16AtomicAdd_offsetof||0)+")",
    shaderBufferFloat16AtomicMinMax: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderBufferFloat16AtomicMinMax_offsetof||0)+")",
    shaderBufferFloat32AtomicMinMax: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderBufferFloat32AtomicMinMax_offsetof||0)+")",
    shaderBufferFloat64AtomicMinMax: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderBufferFloat64AtomicMinMax_offsetof||0)+")",
    shaderSharedFloat16Atomics: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderSharedFloat16Atomics_offsetof||0)+")",
    shaderSharedFloat16AtomicAdd: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderSharedFloat16AtomicAdd_offsetof||0)+")",
    shaderSharedFloat16AtomicMinMax: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderSharedFloat16AtomicMinMax_offsetof||0)+")",
    shaderSharedFloat32AtomicMinMax: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderSharedFloat32AtomicMinMax_offsetof||0)+")",
    shaderSharedFloat64AtomicMinMax: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderSharedFloat64AtomicMinMax_offsetof||0)+")",
    shaderImageFloat32AtomicMinMax: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderImageFloat32AtomicMinMax_offsetof||0)+")",
    sparseImageFloat32AtomicMinMax: "u32("+(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_sparseImageFloat32AtomicMinMax_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_sizeof||0))));


const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT_pNext_offsetof||0)+")",
    vertexAttributeInstanceRateDivisor: "u32("+(V.VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT_vertexAttributeInstanceRateDivisor_offsetof||0)+")",
    vertexAttributeInstanceRateZeroDivisor: "u32("+(V.VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT_vertexAttributeInstanceRateZeroDivisor_offsetof||0)+")",
}, (V.VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT_sizeof||0))));


const VkQueueFamilyCheckpointPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkQueueFamilyCheckpointPropertiesNV", {
    sType: "u32("+(V.VkQueueFamilyCheckpointPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkQueueFamilyCheckpointPropertiesNV_pNext_offsetof||0)+")",
    checkpointExecutionStageMask: "u32("+(V.VkQueueFamilyCheckpointPropertiesNV_checkpointExecutionStageMask_offsetof||0)+")",
}, (V.VkQueueFamilyCheckpointPropertiesNV_sizeof||0))));


const VkCheckpointDataNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCheckpointDataNV", {
    sType: "u32("+(V.VkCheckpointDataNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCheckpointDataNV_pNext_offsetof||0)+")",
    stage: "u32("+(V.VkCheckpointDataNV_stage_offsetof||0)+")",
    pCheckpointMarker: "u64("+(V.VkCheckpointDataNV_pCheckpointMarker_offsetof||0)+")",
}, (V.VkCheckpointDataNV_sizeof||0))));


const VkPhysicalDeviceDepthStencilResolveProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDepthStencilResolveProperties", {
    sType: "u32("+(V.VkPhysicalDeviceDepthStencilResolveProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDepthStencilResolveProperties_pNext_offsetof||0)+")",
    supportedDepthResolveModes: "u32("+(V.VkPhysicalDeviceDepthStencilResolveProperties_supportedDepthResolveModes_offsetof||0)+")",
    supportedStencilResolveModes: "u32("+(V.VkPhysicalDeviceDepthStencilResolveProperties_supportedStencilResolveModes_offsetof||0)+")",
    independentResolveNone: "u32("+(V.VkPhysicalDeviceDepthStencilResolveProperties_independentResolveNone_offsetof||0)+")",
    independentResolve: "u32("+(V.VkPhysicalDeviceDepthStencilResolveProperties_independentResolve_offsetof||0)+")",
}, (V.VkPhysicalDeviceDepthStencilResolveProperties_sizeof||0))));

const VkPhysicalDeviceDepthStencilResolvePropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceDepthStencilResolveProperties"));


const VkSubpassDescriptionDepthStencilResolve = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubpassDescriptionDepthStencilResolve", {
    sType: "u32("+(V.VkSubpassDescriptionDepthStencilResolve_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSubpassDescriptionDepthStencilResolve_pNext_offsetof||0)+")",
    depthResolveMode: "u32("+(V.VkSubpassDescriptionDepthStencilResolve_depthResolveMode_offsetof||0)+")",
    stencilResolveMode: "u32("+(V.VkSubpassDescriptionDepthStencilResolve_stencilResolveMode_offsetof||0)+")",
    pDepthStencilResolveAttachment: "u64("+(V.VkSubpassDescriptionDepthStencilResolve_pDepthStencilResolveAttachment_offsetof||0)+")",
}, (V.VkSubpassDescriptionDepthStencilResolve_sizeof||0))));

const VkSubpassDescriptionDepthStencilResolveKHR = new Proxy(function(){}, new C.ConstructProxy("VkSubpassDescriptionDepthStencilResolve"));


const VkImageViewASTCDecodeModeEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageViewASTCDecodeModeEXT", {
    sType: "u32("+(V.VkImageViewASTCDecodeModeEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageViewASTCDecodeModeEXT_pNext_offsetof||0)+")",
    decodeMode: "u32("+(V.VkImageViewASTCDecodeModeEXT_decodeMode_offsetof||0)+")",
}, (V.VkImageViewASTCDecodeModeEXT_sizeof||0))));


const VkPhysicalDeviceASTCDecodeFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceASTCDecodeFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceASTCDecodeFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceASTCDecodeFeaturesEXT_pNext_offsetof||0)+")",
    decodeModeSharedExponent: "u32("+(V.VkPhysicalDeviceASTCDecodeFeaturesEXT_decodeModeSharedExponent_offsetof||0)+")",
}, (V.VkPhysicalDeviceASTCDecodeFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceTransformFeedbackFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceTransformFeedbackFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceTransformFeedbackFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceTransformFeedbackFeaturesEXT_pNext_offsetof||0)+")",
    transformFeedback: "u32("+(V.VkPhysicalDeviceTransformFeedbackFeaturesEXT_transformFeedback_offsetof||0)+")",
    geometryStreams: "u32("+(V.VkPhysicalDeviceTransformFeedbackFeaturesEXT_geometryStreams_offsetof||0)+")",
}, (V.VkPhysicalDeviceTransformFeedbackFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceTransformFeedbackPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceTransformFeedbackPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_pNext_offsetof||0)+")",
    maxTransformFeedbackStreams: "u32("+(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_maxTransformFeedbackStreams_offsetof||0)+")",
    maxTransformFeedbackBuffers: "u32("+(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_maxTransformFeedbackBuffers_offsetof||0)+")",
    maxTransformFeedbackBufferSize: "u64("+(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_maxTransformFeedbackBufferSize_offsetof||0)+")",
    maxTransformFeedbackStreamDataSize: "u32("+(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_maxTransformFeedbackStreamDataSize_offsetof||0)+")",
    maxTransformFeedbackBufferDataSize: "u32("+(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_maxTransformFeedbackBufferDataSize_offsetof||0)+")",
    maxTransformFeedbackBufferDataStride: "u32("+(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_maxTransformFeedbackBufferDataStride_offsetof||0)+")",
    transformFeedbackQueries: "u32("+(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_transformFeedbackQueries_offsetof||0)+")",
    transformFeedbackStreamsLinesTriangles: "u32("+(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_transformFeedbackStreamsLinesTriangles_offsetof||0)+")",
    transformFeedbackRasterizationStreamSelect: "u32("+(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_transformFeedbackRasterizationStreamSelect_offsetof||0)+")",
    transformFeedbackDraw: "u32("+(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_transformFeedbackDraw_offsetof||0)+")",
}, (V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_sizeof||0))));


const VkPipelineRasterizationStateStreamCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineRasterizationStateStreamCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineRasterizationStateStreamCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineRasterizationStateStreamCreateInfoEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineRasterizationStateStreamCreateInfoEXT_flags_offsetof||0)+")",
    rasterizationStream: "u32("+(V.VkPipelineRasterizationStateStreamCreateInfoEXT_rasterizationStream_offsetof||0)+")",
}, (V.VkPipelineRasterizationStateStreamCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV_pNext_offsetof||0)+")",
    representativeFragmentTest: "u32("+(V.VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV_representativeFragmentTest_offsetof||0)+")",
}, (V.VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV_sizeof||0))));


const VkPipelineRepresentativeFragmentTestStateCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineRepresentativeFragmentTestStateCreateInfoNV", {
    sType: "u32("+(V.VkPipelineRepresentativeFragmentTestStateCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineRepresentativeFragmentTestStateCreateInfoNV_pNext_offsetof||0)+")",
    representativeFragmentTestEnable: "u32("+(V.VkPipelineRepresentativeFragmentTestStateCreateInfoNV_representativeFragmentTestEnable_offsetof||0)+")",
}, (V.VkPipelineRepresentativeFragmentTestStateCreateInfoNV_sizeof||0))));


const VkPhysicalDeviceExclusiveScissorFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceExclusiveScissorFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceExclusiveScissorFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceExclusiveScissorFeaturesNV_pNext_offsetof||0)+")",
    exclusiveScissor: "u32("+(V.VkPhysicalDeviceExclusiveScissorFeaturesNV_exclusiveScissor_offsetof||0)+")",
}, (V.VkPhysicalDeviceExclusiveScissorFeaturesNV_sizeof||0))));


const VkPipelineViewportExclusiveScissorStateCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineViewportExclusiveScissorStateCreateInfoNV", {
    sType: "u32("+(V.VkPipelineViewportExclusiveScissorStateCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineViewportExclusiveScissorStateCreateInfoNV_pNext_offsetof||0)+")",
    exclusiveScissorCount: "u32("+(V.VkPipelineViewportExclusiveScissorStateCreateInfoNV_exclusiveScissorCount_offsetof||0)+")",
    pExclusiveScissors: "u64("+(V.VkPipelineViewportExclusiveScissorStateCreateInfoNV_pExclusiveScissors_offsetof||0)+")",
}, (V.VkPipelineViewportExclusiveScissorStateCreateInfoNV_sizeof||0))));


const VkPhysicalDeviceCornerSampledImageFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceCornerSampledImageFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceCornerSampledImageFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceCornerSampledImageFeaturesNV_pNext_offsetof||0)+")",
    cornerSampledImage: "u32("+(V.VkPhysicalDeviceCornerSampledImageFeaturesNV_cornerSampledImage_offsetof||0)+")",
}, (V.VkPhysicalDeviceCornerSampledImageFeaturesNV_sizeof||0))));


const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceComputeShaderDerivativesFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceComputeShaderDerivativesFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceComputeShaderDerivativesFeaturesNV_pNext_offsetof||0)+")",
    computeDerivativeGroupQuads: "u32("+(V.VkPhysicalDeviceComputeShaderDerivativesFeaturesNV_computeDerivativeGroupQuads_offsetof||0)+")",
    computeDerivativeGroupLinear: "u32("+(V.VkPhysicalDeviceComputeShaderDerivativesFeaturesNV_computeDerivativeGroupLinear_offsetof||0)+")",
}, (V.VkPhysicalDeviceComputeShaderDerivativesFeaturesNV_sizeof||0))));

const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR"));


const VkPhysicalDeviceShaderImageFootprintFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderImageFootprintFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceShaderImageFootprintFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderImageFootprintFeaturesNV_pNext_offsetof||0)+")",
    imageFootprint: "u32("+(V.VkPhysicalDeviceShaderImageFootprintFeaturesNV_imageFootprint_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderImageFootprintFeaturesNV_sizeof||0))));


const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV_pNext_offsetof||0)+")",
    dedicatedAllocationImageAliasing: "u32("+(V.VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV_dedicatedAllocationImageAliasing_offsetof||0)+")",
}, (V.VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV_sizeof||0))));


const VkPhysicalDeviceCopyMemoryIndirectFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceCopyMemoryIndirectFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceCopyMemoryIndirectFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceCopyMemoryIndirectFeaturesNV_pNext_offsetof||0)+")",
    indirectCopy: "u32("+(V.VkPhysicalDeviceCopyMemoryIndirectFeaturesNV_indirectCopy_offsetof||0)+")",
}, (V.VkPhysicalDeviceCopyMemoryIndirectFeaturesNV_sizeof||0))));


const VkPhysicalDeviceCopyMemoryIndirectPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceCopyMemoryIndirectPropertiesNV", {
    sType: "u32("+(V.VkPhysicalDeviceCopyMemoryIndirectPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceCopyMemoryIndirectPropertiesNV_pNext_offsetof||0)+")",
    supportedQueues: "u32("+(V.VkPhysicalDeviceCopyMemoryIndirectPropertiesNV_supportedQueues_offsetof||0)+")",
}, (V.VkPhysicalDeviceCopyMemoryIndirectPropertiesNV_sizeof||0))));


const VkPhysicalDeviceMemoryDecompressionFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMemoryDecompressionFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceMemoryDecompressionFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMemoryDecompressionFeaturesNV_pNext_offsetof||0)+")",
    memoryDecompression: "u32("+(V.VkPhysicalDeviceMemoryDecompressionFeaturesNV_memoryDecompression_offsetof||0)+")",
}, (V.VkPhysicalDeviceMemoryDecompressionFeaturesNV_sizeof||0))));


const VkPhysicalDeviceMemoryDecompressionPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMemoryDecompressionPropertiesNV", {
    sType: "u32("+(V.VkPhysicalDeviceMemoryDecompressionPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMemoryDecompressionPropertiesNV_pNext_offsetof||0)+")",
    decompressionMethods: "u32("+(V.VkPhysicalDeviceMemoryDecompressionPropertiesNV_decompressionMethods_offsetof||0)+")",
    maxDecompressionIndirectCount: "u64("+(V.VkPhysicalDeviceMemoryDecompressionPropertiesNV_maxDecompressionIndirectCount_offsetof||0)+")",
}, (V.VkPhysicalDeviceMemoryDecompressionPropertiesNV_sizeof||0))));


const VkShadingRatePaletteNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkShadingRatePaletteNV", {
    shadingRatePaletteEntryCount: "u32("+(V.VkShadingRatePaletteNV_shadingRatePaletteEntryCount_offsetof||0)+")",
    pShadingRatePaletteEntries: "u64("+(V.VkShadingRatePaletteNV_pShadingRatePaletteEntries_offsetof||0)+")",
}, (V.VkShadingRatePaletteNV_sizeof||0))));


const VkPipelineViewportShadingRateImageStateCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineViewportShadingRateImageStateCreateInfoNV", {
    sType: "u32("+(V.VkPipelineViewportShadingRateImageStateCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineViewportShadingRateImageStateCreateInfoNV_pNext_offsetof||0)+")",
    shadingRateImageEnable: "u32("+(V.VkPipelineViewportShadingRateImageStateCreateInfoNV_shadingRateImageEnable_offsetof||0)+")",
    viewportCount: "u32("+(V.VkPipelineViewportShadingRateImageStateCreateInfoNV_viewportCount_offsetof||0)+")",
    pShadingRatePalettes: "u64("+(V.VkPipelineViewportShadingRateImageStateCreateInfoNV_pShadingRatePalettes_offsetof||0)+")",
}, (V.VkPipelineViewportShadingRateImageStateCreateInfoNV_sizeof||0))));


const VkPhysicalDeviceShadingRateImageFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShadingRateImageFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceShadingRateImageFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShadingRateImageFeaturesNV_pNext_offsetof||0)+")",
    shadingRateImage: "u32("+(V.VkPhysicalDeviceShadingRateImageFeaturesNV_shadingRateImage_offsetof||0)+")",
    shadingRateCoarseSampleOrder: "u32("+(V.VkPhysicalDeviceShadingRateImageFeaturesNV_shadingRateCoarseSampleOrder_offsetof||0)+")",
}, (V.VkPhysicalDeviceShadingRateImageFeaturesNV_sizeof||0))));


const VkPhysicalDeviceShadingRateImagePropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShadingRateImagePropertiesNV", {
    sType: "u32("+(V.VkPhysicalDeviceShadingRateImagePropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShadingRateImagePropertiesNV_pNext_offsetof||0)+")",
    shadingRateTexelSize: "VkExtent2D("+(V.VkPhysicalDeviceShadingRateImagePropertiesNV_shadingRateTexelSize_offsetof||0)+")",
    shadingRatePaletteSize: "u32("+(V.VkPhysicalDeviceShadingRateImagePropertiesNV_shadingRatePaletteSize_offsetof||0)+")",
    shadingRateMaxCoarseSamples: "u32("+(V.VkPhysicalDeviceShadingRateImagePropertiesNV_shadingRateMaxCoarseSamples_offsetof||0)+")",
}, (V.VkPhysicalDeviceShadingRateImagePropertiesNV_sizeof||0))));


const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceInvocationMaskFeaturesHUAWEI", {
    sType: "u32("+(V.VkPhysicalDeviceInvocationMaskFeaturesHUAWEI_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceInvocationMaskFeaturesHUAWEI_pNext_offsetof||0)+")",
    invocationMask: "u32("+(V.VkPhysicalDeviceInvocationMaskFeaturesHUAWEI_invocationMask_offsetof||0)+")",
}, (V.VkPhysicalDeviceInvocationMaskFeaturesHUAWEI_sizeof||0))));


const VkCoarseSampleLocationNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCoarseSampleLocationNV", {
    pixelX: "u32("+(V.VkCoarseSampleLocationNV_pixelX_offsetof||0)+")",
    pixelY: "u32("+(V.VkCoarseSampleLocationNV_pixelY_offsetof||0)+")",
    sample: "u32("+(V.VkCoarseSampleLocationNV_sample_offsetof||0)+")",
}, (V.VkCoarseSampleLocationNV_sizeof||0))));


const VkCoarseSampleOrderCustomNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCoarseSampleOrderCustomNV", {
    shadingRate: "u32("+(V.VkCoarseSampleOrderCustomNV_shadingRate_offsetof||0)+")",
    sampleCount: "u32("+(V.VkCoarseSampleOrderCustomNV_sampleCount_offsetof||0)+")",
    sampleLocationCount: "u32("+(V.VkCoarseSampleOrderCustomNV_sampleLocationCount_offsetof||0)+")",
    pSampleLocations: "u64("+(V.VkCoarseSampleOrderCustomNV_pSampleLocations_offsetof||0)+")",
}, (V.VkCoarseSampleOrderCustomNV_sizeof||0))));


const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineViewportCoarseSampleOrderStateCreateInfoNV", {
    sType: "u32("+(V.VkPipelineViewportCoarseSampleOrderStateCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineViewportCoarseSampleOrderStateCreateInfoNV_pNext_offsetof||0)+")",
    sampleOrderType: "u32("+(V.VkPipelineViewportCoarseSampleOrderStateCreateInfoNV_sampleOrderType_offsetof||0)+")",
    customSampleOrderCount: "u32("+(V.VkPipelineViewportCoarseSampleOrderStateCreateInfoNV_customSampleOrderCount_offsetof||0)+")",
    pCustomSampleOrders: "u64("+(V.VkPipelineViewportCoarseSampleOrderStateCreateInfoNV_pCustomSampleOrders_offsetof||0)+")",
}, (V.VkPipelineViewportCoarseSampleOrderStateCreateInfoNV_sizeof||0))));


const VkPhysicalDeviceMeshShaderFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMeshShaderFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceMeshShaderFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMeshShaderFeaturesNV_pNext_offsetof||0)+")",
    taskShader: "u32("+(V.VkPhysicalDeviceMeshShaderFeaturesNV_taskShader_offsetof||0)+")",
    meshShader: "u32("+(V.VkPhysicalDeviceMeshShaderFeaturesNV_meshShader_offsetof||0)+")",
}, (V.VkPhysicalDeviceMeshShaderFeaturesNV_sizeof||0))));


const VkPhysicalDeviceMeshShaderPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMeshShaderPropertiesNV", {
    sType: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_pNext_offsetof||0)+")",
    maxDrawMeshTasksCount: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxDrawMeshTasksCount_offsetof||0)+")",
    maxTaskWorkGroupInvocations: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxTaskWorkGroupInvocations_offsetof||0)+")",
    maxTaskWorkGroupSize: "u32[3]("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxTaskWorkGroupSize_offsetof||0)+")",
    maxTaskTotalMemorySize: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxTaskTotalMemorySize_offsetof||0)+")",
    maxTaskOutputCount: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxTaskOutputCount_offsetof||0)+")",
    maxMeshWorkGroupInvocations: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxMeshWorkGroupInvocations_offsetof||0)+")",
    maxMeshWorkGroupSize: "u32[3]("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxMeshWorkGroupSize_offsetof||0)+")",
    maxMeshTotalMemorySize: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxMeshTotalMemorySize_offsetof||0)+")",
    maxMeshOutputVertices: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxMeshOutputVertices_offsetof||0)+")",
    maxMeshOutputPrimitives: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxMeshOutputPrimitives_offsetof||0)+")",
    maxMeshMultiviewViewCount: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxMeshMultiviewViewCount_offsetof||0)+")",
    meshOutputPerVertexGranularity: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_meshOutputPerVertexGranularity_offsetof||0)+")",
    meshOutputPerPrimitiveGranularity: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesNV_meshOutputPerPrimitiveGranularity_offsetof||0)+")",
}, (V.VkPhysicalDeviceMeshShaderPropertiesNV_sizeof||0))));


const VkDrawMeshTasksIndirectCommandNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDrawMeshTasksIndirectCommandNV", {
    taskCount: "u32("+(V.VkDrawMeshTasksIndirectCommandNV_taskCount_offsetof||0)+")",
    firstTask: "u32("+(V.VkDrawMeshTasksIndirectCommandNV_firstTask_offsetof||0)+")",
}, (V.VkDrawMeshTasksIndirectCommandNV_sizeof||0))));


const VkPhysicalDeviceMeshShaderFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMeshShaderFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceMeshShaderFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMeshShaderFeaturesEXT_pNext_offsetof||0)+")",
    taskShader: "u32("+(V.VkPhysicalDeviceMeshShaderFeaturesEXT_taskShader_offsetof||0)+")",
    meshShader: "u32("+(V.VkPhysicalDeviceMeshShaderFeaturesEXT_meshShader_offsetof||0)+")",
    multiviewMeshShader: "u32("+(V.VkPhysicalDeviceMeshShaderFeaturesEXT_multiviewMeshShader_offsetof||0)+")",
    primitiveFragmentShadingRateMeshShader: "u32("+(V.VkPhysicalDeviceMeshShaderFeaturesEXT_primitiveFragmentShadingRateMeshShader_offsetof||0)+")",
    meshShaderQueries: "u32("+(V.VkPhysicalDeviceMeshShaderFeaturesEXT_meshShaderQueries_offsetof||0)+")",
}, (V.VkPhysicalDeviceMeshShaderFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceMeshShaderPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMeshShaderPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_pNext_offsetof||0)+")",
    maxTaskWorkGroupTotalCount: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskWorkGroupTotalCount_offsetof||0)+")",
    maxTaskWorkGroupCount: "u32[3]("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskWorkGroupCount_offsetof||0)+")",
    maxTaskWorkGroupInvocations: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskWorkGroupInvocations_offsetof||0)+")",
    maxTaskWorkGroupSize: "u32[3]("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskWorkGroupSize_offsetof||0)+")",
    maxTaskPayloadSize: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskPayloadSize_offsetof||0)+")",
    maxTaskSharedMemorySize: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskSharedMemorySize_offsetof||0)+")",
    maxTaskPayloadAndSharedMemorySize: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskPayloadAndSharedMemorySize_offsetof||0)+")",
    maxMeshWorkGroupTotalCount: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshWorkGroupTotalCount_offsetof||0)+")",
    maxMeshWorkGroupCount: "u32[3]("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshWorkGroupCount_offsetof||0)+")",
    maxMeshWorkGroupInvocations: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshWorkGroupInvocations_offsetof||0)+")",
    maxMeshWorkGroupSize: "u32[3]("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshWorkGroupSize_offsetof||0)+")",
    maxMeshSharedMemorySize: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshSharedMemorySize_offsetof||0)+")",
    maxMeshPayloadAndSharedMemorySize: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshPayloadAndSharedMemorySize_offsetof||0)+")",
    maxMeshOutputMemorySize: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshOutputMemorySize_offsetof||0)+")",
    maxMeshPayloadAndOutputMemorySize: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshPayloadAndOutputMemorySize_offsetof||0)+")",
    maxMeshOutputComponents: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshOutputComponents_offsetof||0)+")",
    maxMeshOutputVertices: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshOutputVertices_offsetof||0)+")",
    maxMeshOutputPrimitives: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshOutputPrimitives_offsetof||0)+")",
    maxMeshOutputLayers: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshOutputLayers_offsetof||0)+")",
    maxMeshMultiviewViewCount: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshMultiviewViewCount_offsetof||0)+")",
    meshOutputPerVertexGranularity: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_meshOutputPerVertexGranularity_offsetof||0)+")",
    meshOutputPerPrimitiveGranularity: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_meshOutputPerPrimitiveGranularity_offsetof||0)+")",
    maxPreferredTaskWorkGroupInvocations: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxPreferredTaskWorkGroupInvocations_offsetof||0)+")",
    maxPreferredMeshWorkGroupInvocations: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxPreferredMeshWorkGroupInvocations_offsetof||0)+")",
    prefersLocalInvocationVertexOutput: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_prefersLocalInvocationVertexOutput_offsetof||0)+")",
    prefersLocalInvocationPrimitiveOutput: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_prefersLocalInvocationPrimitiveOutput_offsetof||0)+")",
    prefersCompactVertexOutput: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_prefersCompactVertexOutput_offsetof||0)+")",
    prefersCompactPrimitiveOutput: "u32("+(V.VkPhysicalDeviceMeshShaderPropertiesEXT_prefersCompactPrimitiveOutput_offsetof||0)+")",
}, (V.VkPhysicalDeviceMeshShaderPropertiesEXT_sizeof||0))));


const VkDrawMeshTasksIndirectCommandEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDrawMeshTasksIndirectCommandEXT", {
    groupCountX: "u32("+(V.VkDrawMeshTasksIndirectCommandEXT_groupCountX_offsetof||0)+")",
    groupCountY: "u32("+(V.VkDrawMeshTasksIndirectCommandEXT_groupCountY_offsetof||0)+")",
    groupCountZ: "u32("+(V.VkDrawMeshTasksIndirectCommandEXT_groupCountZ_offsetof||0)+")",
}, (V.VkDrawMeshTasksIndirectCommandEXT_sizeof||0))));


const VkRayTracingShaderGroupCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRayTracingShaderGroupCreateInfoNV", {
    sType: "u32("+(V.VkRayTracingShaderGroupCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRayTracingShaderGroupCreateInfoNV_pNext_offsetof||0)+")",
    type: "u32("+(V.VkRayTracingShaderGroupCreateInfoNV_type_offsetof||0)+")",
    generalShader: "u32("+(V.VkRayTracingShaderGroupCreateInfoNV_generalShader_offsetof||0)+")",
    closestHitShader: "u32("+(V.VkRayTracingShaderGroupCreateInfoNV_closestHitShader_offsetof||0)+")",
    anyHitShader: "u32("+(V.VkRayTracingShaderGroupCreateInfoNV_anyHitShader_offsetof||0)+")",
    intersectionShader: "u32("+(V.VkRayTracingShaderGroupCreateInfoNV_intersectionShader_offsetof||0)+")",
}, (V.VkRayTracingShaderGroupCreateInfoNV_sizeof||0))));


const VkRayTracingShaderGroupCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRayTracingShaderGroupCreateInfoKHR", {
    sType: "u32("+(V.VkRayTracingShaderGroupCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRayTracingShaderGroupCreateInfoKHR_pNext_offsetof||0)+")",
    type: "u32("+(V.VkRayTracingShaderGroupCreateInfoKHR_type_offsetof||0)+")",
    generalShader: "u32("+(V.VkRayTracingShaderGroupCreateInfoKHR_generalShader_offsetof||0)+")",
    closestHitShader: "u32("+(V.VkRayTracingShaderGroupCreateInfoKHR_closestHitShader_offsetof||0)+")",
    anyHitShader: "u32("+(V.VkRayTracingShaderGroupCreateInfoKHR_anyHitShader_offsetof||0)+")",
    intersectionShader: "u32("+(V.VkRayTracingShaderGroupCreateInfoKHR_intersectionShader_offsetof||0)+")",
    pShaderGroupCaptureReplayHandle: "u64("+(V.VkRayTracingShaderGroupCreateInfoKHR_pShaderGroupCaptureReplayHandle_offsetof||0)+")",
}, (V.VkRayTracingShaderGroupCreateInfoKHR_sizeof||0))));


const VkRayTracingPipelineCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRayTracingPipelineCreateInfoNV", {
    sType: "u32("+(V.VkRayTracingPipelineCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRayTracingPipelineCreateInfoNV_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkRayTracingPipelineCreateInfoNV_flags_offsetof||0)+")",
    stageCount: "u32("+(V.VkRayTracingPipelineCreateInfoNV_stageCount_offsetof||0)+")",
    pStages: "u64("+(V.VkRayTracingPipelineCreateInfoNV_pStages_offsetof||0)+")",
    groupCount: "u32("+(V.VkRayTracingPipelineCreateInfoNV_groupCount_offsetof||0)+")",
    pGroups: "u64("+(V.VkRayTracingPipelineCreateInfoNV_pGroups_offsetof||0)+")",
    maxRecursionDepth: "u32("+(V.VkRayTracingPipelineCreateInfoNV_maxRecursionDepth_offsetof||0)+")",
    layout: "u64("+(V.VkRayTracingPipelineCreateInfoNV_layout_offsetof||0)+")",
    basePipelineHandle: "u64("+(V.VkRayTracingPipelineCreateInfoNV_basePipelineHandle_offsetof||0)+")",
    basePipelineIndex: "i32("+(V.VkRayTracingPipelineCreateInfoNV_basePipelineIndex_offsetof||0)+")",
}, (V.VkRayTracingPipelineCreateInfoNV_sizeof||0))));


const VkRayTracingPipelineCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRayTracingPipelineCreateInfoKHR", {
    sType: "u32("+(V.VkRayTracingPipelineCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRayTracingPipelineCreateInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkRayTracingPipelineCreateInfoKHR_flags_offsetof||0)+")",
    stageCount: "u32("+(V.VkRayTracingPipelineCreateInfoKHR_stageCount_offsetof||0)+")",
    pStages: "u64("+(V.VkRayTracingPipelineCreateInfoKHR_pStages_offsetof||0)+")",
    groupCount: "u32("+(V.VkRayTracingPipelineCreateInfoKHR_groupCount_offsetof||0)+")",
    pGroups: "u64("+(V.VkRayTracingPipelineCreateInfoKHR_pGroups_offsetof||0)+")",
    maxPipelineRayRecursionDepth: "u32("+(V.VkRayTracingPipelineCreateInfoKHR_maxPipelineRayRecursionDepth_offsetof||0)+")",
    pLibraryInfo: "u64("+(V.VkRayTracingPipelineCreateInfoKHR_pLibraryInfo_offsetof||0)+")",
    pLibraryInterface: "u64("+(V.VkRayTracingPipelineCreateInfoKHR_pLibraryInterface_offsetof||0)+")",
    pDynamicState: "u64("+(V.VkRayTracingPipelineCreateInfoKHR_pDynamicState_offsetof||0)+")",
    layout: "u64("+(V.VkRayTracingPipelineCreateInfoKHR_layout_offsetof||0)+")",
    basePipelineHandle: "u64("+(V.VkRayTracingPipelineCreateInfoKHR_basePipelineHandle_offsetof||0)+")",
    basePipelineIndex: "i32("+(V.VkRayTracingPipelineCreateInfoKHR_basePipelineIndex_offsetof||0)+")",
}, (V.VkRayTracingPipelineCreateInfoKHR_sizeof||0))));


const VkGeometryTrianglesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkGeometryTrianglesNV", {
    sType: "u32("+(V.VkGeometryTrianglesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkGeometryTrianglesNV_pNext_offsetof||0)+")",
    vertexData: "u64("+(V.VkGeometryTrianglesNV_vertexData_offsetof||0)+")",
    vertexOffset: "u64("+(V.VkGeometryTrianglesNV_vertexOffset_offsetof||0)+")",
    vertexCount: "u32("+(V.VkGeometryTrianglesNV_vertexCount_offsetof||0)+")",
    vertexStride: "u64("+(V.VkGeometryTrianglesNV_vertexStride_offsetof||0)+")",
    vertexFormat: "u32("+(V.VkGeometryTrianglesNV_vertexFormat_offsetof||0)+")",
    indexData: "u64("+(V.VkGeometryTrianglesNV_indexData_offsetof||0)+")",
    indexOffset: "u64("+(V.VkGeometryTrianglesNV_indexOffset_offsetof||0)+")",
    indexCount: "u32("+(V.VkGeometryTrianglesNV_indexCount_offsetof||0)+")",
    indexType: "u32("+(V.VkGeometryTrianglesNV_indexType_offsetof||0)+")",
    transformData: "u64("+(V.VkGeometryTrianglesNV_transformData_offsetof||0)+")",
    transformOffset: "u64("+(V.VkGeometryTrianglesNV_transformOffset_offsetof||0)+")",
}, (V.VkGeometryTrianglesNV_sizeof||0))));


const VkGeometryAABBNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkGeometryAABBNV", {
    sType: "u32("+(V.VkGeometryAABBNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkGeometryAABBNV_pNext_offsetof||0)+")",
    aabbData: "u64("+(V.VkGeometryAABBNV_aabbData_offsetof||0)+")",
    numAABBs: "u32("+(V.VkGeometryAABBNV_numAABBs_offsetof||0)+")",
    stride: "u32("+(V.VkGeometryAABBNV_stride_offsetof||0)+")",
    offset: "u64("+(V.VkGeometryAABBNV_offset_offsetof||0)+")",
}, (V.VkGeometryAABBNV_sizeof||0))));


const VkGeometryDataNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkGeometryDataNV", {
    triangles: "u32("+(V.VkGeometryDataNV_triangles_offsetof||0)+")",
    aabbs: "u32("+(V.VkGeometryDataNV_aabbs_offsetof||0)+")",
}, (V.VkGeometryDataNV_sizeof||0))));


const VkGeometryNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkGeometryNV", {
    sType: "u32("+(V.VkGeometryNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkGeometryNV_pNext_offsetof||0)+")",
    geometryType: "u32("+(V.VkGeometryNV_geometryType_offsetof||0)+")",
    geometry: "u32("+(V.VkGeometryNV_geometry_offsetof||0)+")",
    flags: "u32("+(V.VkGeometryNV_flags_offsetof||0)+")",
}, (V.VkGeometryNV_sizeof||0))));


const VkAccelerationStructureInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureInfoNV", {
    sType: "u32("+(V.VkAccelerationStructureInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureInfoNV_pNext_offsetof||0)+")",
    type: "u32("+(V.VkAccelerationStructureInfoNV_type_offsetof||0)+")",
    flags: "u32("+(V.VkAccelerationStructureInfoNV_flags_offsetof||0)+")",
    instanceCount: "u32("+(V.VkAccelerationStructureInfoNV_instanceCount_offsetof||0)+")",
    geometryCount: "u32("+(V.VkAccelerationStructureInfoNV_geometryCount_offsetof||0)+")",
    pGeometries: "u64("+(V.VkAccelerationStructureInfoNV_pGeometries_offsetof||0)+")",
}, (V.VkAccelerationStructureInfoNV_sizeof||0))));


const VkAccelerationStructureCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureCreateInfoNV", {
    sType: "u32("+(V.VkAccelerationStructureCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureCreateInfoNV_pNext_offsetof||0)+")",
    compactedSize: "u64("+(V.VkAccelerationStructureCreateInfoNV_compactedSize_offsetof||0)+")",
    info: "u32("+(V.VkAccelerationStructureCreateInfoNV_info_offsetof||0)+")",
}, (V.VkAccelerationStructureCreateInfoNV_sizeof||0))));


const VkBindAccelerationStructureMemoryInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBindAccelerationStructureMemoryInfoNV", {
    sType: "u32("+(V.VkBindAccelerationStructureMemoryInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBindAccelerationStructureMemoryInfoNV_pNext_offsetof||0)+")",
    accelerationStructure: "u32("+(V.VkBindAccelerationStructureMemoryInfoNV_accelerationStructure_offsetof||0)+")",
    memory: "u64("+(V.VkBindAccelerationStructureMemoryInfoNV_memory_offsetof||0)+")",
    memoryOffset: "u64("+(V.VkBindAccelerationStructureMemoryInfoNV_memoryOffset_offsetof||0)+")",
    deviceIndexCount: "u32("+(V.VkBindAccelerationStructureMemoryInfoNV_deviceIndexCount_offsetof||0)+")",
    pDeviceIndices: "u64("+(V.VkBindAccelerationStructureMemoryInfoNV_pDeviceIndices_offsetof||0)+")",
}, (V.VkBindAccelerationStructureMemoryInfoNV_sizeof||0))));


const VkWriteDescriptorSetAccelerationStructureKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkWriteDescriptorSetAccelerationStructureKHR", {
    sType: "u32("+(V.VkWriteDescriptorSetAccelerationStructureKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkWriteDescriptorSetAccelerationStructureKHR_pNext_offsetof||0)+")",
    accelerationStructureCount: "u32("+(V.VkWriteDescriptorSetAccelerationStructureKHR_accelerationStructureCount_offsetof||0)+")",
    pAccelerationStructures: "u64("+(V.VkWriteDescriptorSetAccelerationStructureKHR_pAccelerationStructures_offsetof||0)+")",
}, (V.VkWriteDescriptorSetAccelerationStructureKHR_sizeof||0))));


const VkWriteDescriptorSetAccelerationStructureNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkWriteDescriptorSetAccelerationStructureNV", {
    sType: "u32("+(V.VkWriteDescriptorSetAccelerationStructureNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkWriteDescriptorSetAccelerationStructureNV_pNext_offsetof||0)+")",
    accelerationStructureCount: "u32("+(V.VkWriteDescriptorSetAccelerationStructureNV_accelerationStructureCount_offsetof||0)+")",
    pAccelerationStructures: "u64("+(V.VkWriteDescriptorSetAccelerationStructureNV_pAccelerationStructures_offsetof||0)+")",
}, (V.VkWriteDescriptorSetAccelerationStructureNV_sizeof||0))));


const VkAccelerationStructureMemoryRequirementsInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureMemoryRequirementsInfoNV", {
    sType: "u32("+(V.VkAccelerationStructureMemoryRequirementsInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureMemoryRequirementsInfoNV_pNext_offsetof||0)+")",
    type: "u32("+(V.VkAccelerationStructureMemoryRequirementsInfoNV_type_offsetof||0)+")",
    accelerationStructure: "u32("+(V.VkAccelerationStructureMemoryRequirementsInfoNV_accelerationStructure_offsetof||0)+")",
}, (V.VkAccelerationStructureMemoryRequirementsInfoNV_sizeof||0))));


const VkPhysicalDeviceAccelerationStructureFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceAccelerationStructureFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_pNext_offsetof||0)+")",
    accelerationStructure: "u32("+(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_accelerationStructure_offsetof||0)+")",
    accelerationStructureCaptureReplay: "u32("+(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_accelerationStructureCaptureReplay_offsetof||0)+")",
    accelerationStructureIndirectBuild: "u32("+(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_accelerationStructureIndirectBuild_offsetof||0)+")",
    accelerationStructureHostCommands: "u32("+(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_accelerationStructureHostCommands_offsetof||0)+")",
    descriptorBindingAccelerationStructureUpdateAfterBind: "u32("+(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_descriptorBindingAccelerationStructureUpdateAfterBind_offsetof||0)+")",
}, (V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_sizeof||0))));


const VkPhysicalDeviceRayTracingPipelineFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRayTracingPipelineFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_pNext_offsetof||0)+")",
    rayTracingPipeline: "u32("+(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_rayTracingPipeline_offsetof||0)+")",
    rayTracingPipelineShaderGroupHandleCaptureReplay: "u32("+(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_rayTracingPipelineShaderGroupHandleCaptureReplay_offsetof||0)+")",
    rayTracingPipelineShaderGroupHandleCaptureReplayMixed: "u32("+(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_rayTracingPipelineShaderGroupHandleCaptureReplayMixed_offsetof||0)+")",
    rayTracingPipelineTraceRaysIndirect: "u32("+(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_rayTracingPipelineTraceRaysIndirect_offsetof||0)+")",
    rayTraversalPrimitiveCulling: "u32("+(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_rayTraversalPrimitiveCulling_offsetof||0)+")",
}, (V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_sizeof||0))));


const VkPhysicalDeviceRayQueryFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRayQueryFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceRayQueryFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRayQueryFeaturesKHR_pNext_offsetof||0)+")",
    rayQuery: "u32("+(V.VkPhysicalDeviceRayQueryFeaturesKHR_rayQuery_offsetof||0)+")",
}, (V.VkPhysicalDeviceRayQueryFeaturesKHR_sizeof||0))));


const VkPhysicalDeviceAccelerationStructurePropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceAccelerationStructurePropertiesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_pNext_offsetof||0)+")",
    maxGeometryCount: "u64("+(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxGeometryCount_offsetof||0)+")",
    maxInstanceCount: "u64("+(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxInstanceCount_offsetof||0)+")",
    maxPrimitiveCount: "u64("+(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxPrimitiveCount_offsetof||0)+")",
    maxPerStageDescriptorAccelerationStructures: "u32("+(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxPerStageDescriptorAccelerationStructures_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindAccelerationStructures: "u32("+(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxPerStageDescriptorUpdateAfterBindAccelerationStructures_offsetof||0)+")",
    maxDescriptorSetAccelerationStructures: "u32("+(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxDescriptorSetAccelerationStructures_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindAccelerationStructures: "u32("+(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxDescriptorSetUpdateAfterBindAccelerationStructures_offsetof||0)+")",
    minAccelerationStructureScratchOffsetAlignment: "u32("+(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_minAccelerationStructureScratchOffsetAlignment_offsetof||0)+")",
}, (V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_sizeof||0))));


const VkPhysicalDeviceRayTracingPipelinePropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRayTracingPipelinePropertiesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_pNext_offsetof||0)+")",
    shaderGroupHandleSize: "u32("+(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_shaderGroupHandleSize_offsetof||0)+")",
    maxRayRecursionDepth: "u32("+(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_maxRayRecursionDepth_offsetof||0)+")",
    maxShaderGroupStride: "u32("+(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_maxShaderGroupStride_offsetof||0)+")",
    shaderGroupBaseAlignment: "u32("+(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_shaderGroupBaseAlignment_offsetof||0)+")",
    shaderGroupHandleCaptureReplaySize: "u32("+(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_shaderGroupHandleCaptureReplaySize_offsetof||0)+")",
    maxRayDispatchInvocationCount: "u32("+(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_maxRayDispatchInvocationCount_offsetof||0)+")",
    shaderGroupHandleAlignment: "u32("+(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_shaderGroupHandleAlignment_offsetof||0)+")",
    maxRayHitAttributeSize: "u32("+(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_maxRayHitAttributeSize_offsetof||0)+")",
}, (V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_sizeof||0))));


const VkPhysicalDeviceRayTracingPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRayTracingPropertiesNV", {
    sType: "u32("+(V.VkPhysicalDeviceRayTracingPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRayTracingPropertiesNV_pNext_offsetof||0)+")",
    shaderGroupHandleSize: "u32("+(V.VkPhysicalDeviceRayTracingPropertiesNV_shaderGroupHandleSize_offsetof||0)+")",
    maxRecursionDepth: "u32("+(V.VkPhysicalDeviceRayTracingPropertiesNV_maxRecursionDepth_offsetof||0)+")",
    maxShaderGroupStride: "u32("+(V.VkPhysicalDeviceRayTracingPropertiesNV_maxShaderGroupStride_offsetof||0)+")",
    shaderGroupBaseAlignment: "u32("+(V.VkPhysicalDeviceRayTracingPropertiesNV_shaderGroupBaseAlignment_offsetof||0)+")",
    maxGeometryCount: "u64("+(V.VkPhysicalDeviceRayTracingPropertiesNV_maxGeometryCount_offsetof||0)+")",
    maxInstanceCount: "u64("+(V.VkPhysicalDeviceRayTracingPropertiesNV_maxInstanceCount_offsetof||0)+")",
    maxTriangleCount: "u64("+(V.VkPhysicalDeviceRayTracingPropertiesNV_maxTriangleCount_offsetof||0)+")",
    maxDescriptorSetAccelerationStructures: "u32("+(V.VkPhysicalDeviceRayTracingPropertiesNV_maxDescriptorSetAccelerationStructures_offsetof||0)+")",
}, (V.VkPhysicalDeviceRayTracingPropertiesNV_sizeof||0))));


const VkStridedDeviceAddressRegionKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkStridedDeviceAddressRegionKHR", {
    deviceAddress: "u64("+(V.VkStridedDeviceAddressRegionKHR_deviceAddress_offsetof||0)+")",
    stride: "u64("+(V.VkStridedDeviceAddressRegionKHR_stride_offsetof||0)+")",
    size: "u64("+(V.VkStridedDeviceAddressRegionKHR_size_offsetof||0)+")",
}, (V.VkStridedDeviceAddressRegionKHR_sizeof||0))));


const VkTraceRaysIndirectCommandKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkTraceRaysIndirectCommandKHR", {
    width: "u32("+(V.VkTraceRaysIndirectCommandKHR_width_offsetof||0)+")",
    height: "u32("+(V.VkTraceRaysIndirectCommandKHR_height_offsetof||0)+")",
    depth: "u32("+(V.VkTraceRaysIndirectCommandKHR_depth_offsetof||0)+")",
}, (V.VkTraceRaysIndirectCommandKHR_sizeof||0))));


const VkTraceRaysIndirectCommand2KHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkTraceRaysIndirectCommand2KHR", {
    raygenShaderRecordAddress: "u64("+(V.VkTraceRaysIndirectCommand2KHR_raygenShaderRecordAddress_offsetof||0)+")",
    raygenShaderRecordSize: "u64("+(V.VkTraceRaysIndirectCommand2KHR_raygenShaderRecordSize_offsetof||0)+")",
    missShaderBindingTableAddress: "u64("+(V.VkTraceRaysIndirectCommand2KHR_missShaderBindingTableAddress_offsetof||0)+")",
    missShaderBindingTableSize: "u64("+(V.VkTraceRaysIndirectCommand2KHR_missShaderBindingTableSize_offsetof||0)+")",
    missShaderBindingTableStride: "u64("+(V.VkTraceRaysIndirectCommand2KHR_missShaderBindingTableStride_offsetof||0)+")",
    hitShaderBindingTableAddress: "u64("+(V.VkTraceRaysIndirectCommand2KHR_hitShaderBindingTableAddress_offsetof||0)+")",
    hitShaderBindingTableSize: "u64("+(V.VkTraceRaysIndirectCommand2KHR_hitShaderBindingTableSize_offsetof||0)+")",
    hitShaderBindingTableStride: "u64("+(V.VkTraceRaysIndirectCommand2KHR_hitShaderBindingTableStride_offsetof||0)+")",
    callableShaderBindingTableAddress: "u64("+(V.VkTraceRaysIndirectCommand2KHR_callableShaderBindingTableAddress_offsetof||0)+")",
    callableShaderBindingTableSize: "u64("+(V.VkTraceRaysIndirectCommand2KHR_callableShaderBindingTableSize_offsetof||0)+")",
    callableShaderBindingTableStride: "u64("+(V.VkTraceRaysIndirectCommand2KHR_callableShaderBindingTableStride_offsetof||0)+")",
    width: "u32("+(V.VkTraceRaysIndirectCommand2KHR_width_offsetof||0)+")",
    height: "u32("+(V.VkTraceRaysIndirectCommand2KHR_height_offsetof||0)+")",
    depth: "u32("+(V.VkTraceRaysIndirectCommand2KHR_depth_offsetof||0)+")",
}, (V.VkTraceRaysIndirectCommand2KHR_sizeof||0))));


const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR_pNext_offsetof||0)+")",
    rayTracingMaintenance1: "u32("+(V.VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR_rayTracingMaintenance1_offsetof||0)+")",
    rayTracingPipelineTraceRaysIndirect2: "u32("+(V.VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR_rayTracingPipelineTraceRaysIndirect2_offsetof||0)+")",
}, (V.VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR_sizeof||0))));


const VkDrmFormatModifierPropertiesListEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDrmFormatModifierPropertiesListEXT", {
    sType: "u32("+(V.VkDrmFormatModifierPropertiesListEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDrmFormatModifierPropertiesListEXT_pNext_offsetof||0)+")",
    drmFormatModifierCount: "u32("+(V.VkDrmFormatModifierPropertiesListEXT_drmFormatModifierCount_offsetof||0)+")",
    pDrmFormatModifierProperties: "u64("+(V.VkDrmFormatModifierPropertiesListEXT_pDrmFormatModifierProperties_offsetof||0)+")",
}, (V.VkDrmFormatModifierPropertiesListEXT_sizeof||0))));


const VkDrmFormatModifierPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDrmFormatModifierPropertiesEXT", {
    drmFormatModifier: "u64("+(V.VkDrmFormatModifierPropertiesEXT_drmFormatModifier_offsetof||0)+")",
    drmFormatModifierPlaneCount: "u32("+(V.VkDrmFormatModifierPropertiesEXT_drmFormatModifierPlaneCount_offsetof||0)+")",
    drmFormatModifierTilingFeatures: "u32("+(V.VkDrmFormatModifierPropertiesEXT_drmFormatModifierTilingFeatures_offsetof||0)+")",
}, (V.VkDrmFormatModifierPropertiesEXT_sizeof||0))));


const VkPhysicalDeviceImageDrmFormatModifierInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceImageDrmFormatModifierInfoEXT", {
    sType: "u32("+(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_pNext_offsetof||0)+")",
    drmFormatModifier: "u64("+(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_drmFormatModifier_offsetof||0)+")",
    sharingMode: "u32("+(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_sharingMode_offsetof||0)+")",
    queueFamilyIndexCount: "u32("+(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_queueFamilyIndexCount_offsetof||0)+")",
    pQueueFamilyIndices: "u64("+(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_pQueueFamilyIndices_offsetof||0)+")",
}, (V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_sizeof||0))));


const VkImageDrmFormatModifierListCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageDrmFormatModifierListCreateInfoEXT", {
    sType: "u32("+(V.VkImageDrmFormatModifierListCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageDrmFormatModifierListCreateInfoEXT_pNext_offsetof||0)+")",
    drmFormatModifierCount: "u32("+(V.VkImageDrmFormatModifierListCreateInfoEXT_drmFormatModifierCount_offsetof||0)+")",
    pDrmFormatModifiers: "u64("+(V.VkImageDrmFormatModifierListCreateInfoEXT_pDrmFormatModifiers_offsetof||0)+")",
}, (V.VkImageDrmFormatModifierListCreateInfoEXT_sizeof||0))));


const VkImageDrmFormatModifierExplicitCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageDrmFormatModifierExplicitCreateInfoEXT", {
    sType: "u32("+(V.VkImageDrmFormatModifierExplicitCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageDrmFormatModifierExplicitCreateInfoEXT_pNext_offsetof||0)+")",
    drmFormatModifier: "u64("+(V.VkImageDrmFormatModifierExplicitCreateInfoEXT_drmFormatModifier_offsetof||0)+")",
    drmFormatModifierPlaneCount: "u32("+(V.VkImageDrmFormatModifierExplicitCreateInfoEXT_drmFormatModifierPlaneCount_offsetof||0)+")",
    pPlaneLayouts: "u64("+(V.VkImageDrmFormatModifierExplicitCreateInfoEXT_pPlaneLayouts_offsetof||0)+")",
}, (V.VkImageDrmFormatModifierExplicitCreateInfoEXT_sizeof||0))));


const VkImageDrmFormatModifierPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageDrmFormatModifierPropertiesEXT", {
    sType: "u32("+(V.VkImageDrmFormatModifierPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageDrmFormatModifierPropertiesEXT_pNext_offsetof||0)+")",
    drmFormatModifier: "u64("+(V.VkImageDrmFormatModifierPropertiesEXT_drmFormatModifier_offsetof||0)+")",
}, (V.VkImageDrmFormatModifierPropertiesEXT_sizeof||0))));


const VkImageStencilUsageCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageStencilUsageCreateInfo", {
    sType: "u32("+(V.VkImageStencilUsageCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageStencilUsageCreateInfo_pNext_offsetof||0)+")",
    stencilUsage: "u32("+(V.VkImageStencilUsageCreateInfo_stencilUsage_offsetof||0)+")",
}, (V.VkImageStencilUsageCreateInfo_sizeof||0))));

const VkImageStencilUsageCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy("VkImageStencilUsageCreateInfo"));


const VkDeviceMemoryOverallocationCreateInfoAMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceMemoryOverallocationCreateInfoAMD", {
    sType: "u32("+(V.VkDeviceMemoryOverallocationCreateInfoAMD_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceMemoryOverallocationCreateInfoAMD_pNext_offsetof||0)+")",
    overallocationBehavior: "u32("+(V.VkDeviceMemoryOverallocationCreateInfoAMD_overallocationBehavior_offsetof||0)+")",
}, (V.VkDeviceMemoryOverallocationCreateInfoAMD_sizeof||0))));


const VkPhysicalDeviceFragmentDensityMapFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentDensityMapFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentDensityMapFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentDensityMapFeaturesEXT_pNext_offsetof||0)+")",
    fragmentDensityMap: "u32("+(V.VkPhysicalDeviceFragmentDensityMapFeaturesEXT_fragmentDensityMap_offsetof||0)+")",
    fragmentDensityMapDynamic: "u32("+(V.VkPhysicalDeviceFragmentDensityMapFeaturesEXT_fragmentDensityMapDynamic_offsetof||0)+")",
    fragmentDensityMapNonSubsampledImages: "u32("+(V.VkPhysicalDeviceFragmentDensityMapFeaturesEXT_fragmentDensityMapNonSubsampledImages_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentDensityMapFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentDensityMap2FeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentDensityMap2FeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentDensityMap2FeaturesEXT_pNext_offsetof||0)+")",
    fragmentDensityMapDeferred: "u32("+(V.VkPhysicalDeviceFragmentDensityMap2FeaturesEXT_fragmentDensityMapDeferred_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentDensityMap2FeaturesEXT_sizeof||0))));


const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM_pNext_offsetof||0)+")",
    fragmentDensityMapOffset: "u32("+(V.VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM_fragmentDensityMapOffset_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM_sizeof||0))));


const VkPhysicalDeviceFragmentDensityMapPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentDensityMapPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentDensityMapPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentDensityMapPropertiesEXT_pNext_offsetof||0)+")",
    minFragmentDensityTexelSize: "VkExtent2D("+(V.VkPhysicalDeviceFragmentDensityMapPropertiesEXT_minFragmentDensityTexelSize_offsetof||0)+")",
    maxFragmentDensityTexelSize: "VkExtent2D("+(V.VkPhysicalDeviceFragmentDensityMapPropertiesEXT_maxFragmentDensityTexelSize_offsetof||0)+")",
    fragmentDensityInvocations: "u32("+(V.VkPhysicalDeviceFragmentDensityMapPropertiesEXT_fragmentDensityInvocations_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentDensityMapPropertiesEXT_sizeof||0))));


const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentDensityMap2PropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_pNext_offsetof||0)+")",
    subsampledLoads: "u32("+(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_subsampledLoads_offsetof||0)+")",
    subsampledCoarseReconstructionEarlyAccess: "u32("+(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_subsampledCoarseReconstructionEarlyAccess_offsetof||0)+")",
    maxSubsampledArrayLayers: "u32("+(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_maxSubsampledArrayLayers_offsetof||0)+")",
    maxDescriptorSetSubsampledSamplers: "u32("+(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_maxDescriptorSetSubsampledSamplers_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_sizeof||0))));


const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM_pNext_offsetof||0)+")",
    fragmentDensityOffsetGranularity: "VkExtent2D("+(V.VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM_fragmentDensityOffsetGranularity_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM_sizeof||0))));


const VkRenderPassFragmentDensityMapCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassFragmentDensityMapCreateInfoEXT", {
    sType: "u32("+(V.VkRenderPassFragmentDensityMapCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderPassFragmentDensityMapCreateInfoEXT_pNext_offsetof||0)+")",
    fragmentDensityMapAttachment: "u32("+(V.VkRenderPassFragmentDensityMapCreateInfoEXT_fragmentDensityMapAttachment_offsetof||0)+")",
}, (V.VkRenderPassFragmentDensityMapCreateInfoEXT_sizeof||0))));


const VkSubpassFragmentDensityMapOffsetEndInfoQCOM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubpassFragmentDensityMapOffsetEndInfoQCOM", {
    sType: "u32("+(V.VkSubpassFragmentDensityMapOffsetEndInfoQCOM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSubpassFragmentDensityMapOffsetEndInfoQCOM_pNext_offsetof||0)+")",
    fragmentDensityOffsetCount: "u32("+(V.VkSubpassFragmentDensityMapOffsetEndInfoQCOM_fragmentDensityOffsetCount_offsetof||0)+")",
    pFragmentDensityOffsets: "u64("+(V.VkSubpassFragmentDensityMapOffsetEndInfoQCOM_pFragmentDensityOffsets_offsetof||0)+")",
}, (V.VkSubpassFragmentDensityMapOffsetEndInfoQCOM_sizeof||0))));


const VkPhysicalDeviceScalarBlockLayoutFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceScalarBlockLayoutFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceScalarBlockLayoutFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceScalarBlockLayoutFeatures_pNext_offsetof||0)+")",
    scalarBlockLayout: "u32("+(V.VkPhysicalDeviceScalarBlockLayoutFeatures_scalarBlockLayout_offsetof||0)+")",
}, (V.VkPhysicalDeviceScalarBlockLayoutFeatures_sizeof||0))));

const VkPhysicalDeviceScalarBlockLayoutFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceScalarBlockLayoutFeatures"));


const VkSurfaceProtectedCapabilitiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSurfaceProtectedCapabilitiesKHR", {
    sType: "u32("+(V.VkSurfaceProtectedCapabilitiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSurfaceProtectedCapabilitiesKHR_pNext_offsetof||0)+")",
    supportsProtected: "u32("+(V.VkSurfaceProtectedCapabilitiesKHR_supportsProtected_offsetof||0)+")",
}, (V.VkSurfaceProtectedCapabilitiesKHR_sizeof||0))));


const VkPhysicalDeviceUniformBufferStandardLayoutFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceUniformBufferStandardLayoutFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceUniformBufferStandardLayoutFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pNext_offsetof||0)+")",
    uniformBufferStandardLayout: "u32("+(V.VkPhysicalDeviceUniformBufferStandardLayoutFeatures_uniformBufferStandardLayout_offsetof||0)+")",
}, (V.VkPhysicalDeviceUniformBufferStandardLayoutFeatures_sizeof||0))));

const VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceUniformBufferStandardLayoutFeatures"));


const VkPhysicalDeviceDepthClipEnableFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDepthClipEnableFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceDepthClipEnableFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDepthClipEnableFeaturesEXT_pNext_offsetof||0)+")",
    depthClipEnable: "u32("+(V.VkPhysicalDeviceDepthClipEnableFeaturesEXT_depthClipEnable_offsetof||0)+")",
}, (V.VkPhysicalDeviceDepthClipEnableFeaturesEXT_sizeof||0))));


const VkPipelineRasterizationDepthClipStateCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineRasterizationDepthClipStateCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineRasterizationDepthClipStateCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineRasterizationDepthClipStateCreateInfoEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineRasterizationDepthClipStateCreateInfoEXT_flags_offsetof||0)+")",
    depthClipEnable: "u32("+(V.VkPipelineRasterizationDepthClipStateCreateInfoEXT_depthClipEnable_offsetof||0)+")",
}, (V.VkPipelineRasterizationDepthClipStateCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceMemoryBudgetPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMemoryBudgetPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceMemoryBudgetPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMemoryBudgetPropertiesEXT_pNext_offsetof||0)+")",
    heapBudget: "u64["+(E.VK_MAX_MEMORY_HEAPS||1)+"]("+(V.VkPhysicalDeviceMemoryBudgetPropertiesEXT_heapBudget_offsetof||0)+")",
    heapUsage: "u64["+(E.VK_MAX_MEMORY_HEAPS||1)+"]("+(V.VkPhysicalDeviceMemoryBudgetPropertiesEXT_heapUsage_offsetof||0)+")",
}, (V.VkPhysicalDeviceMemoryBudgetPropertiesEXT_sizeof||0))));


const VkPhysicalDeviceMemoryPriorityFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMemoryPriorityFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceMemoryPriorityFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMemoryPriorityFeaturesEXT_pNext_offsetof||0)+")",
    memoryPriority: "u32("+(V.VkPhysicalDeviceMemoryPriorityFeaturesEXT_memoryPriority_offsetof||0)+")",
}, (V.VkPhysicalDeviceMemoryPriorityFeaturesEXT_sizeof||0))));


const VkMemoryPriorityAllocateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryPriorityAllocateInfoEXT", {
    sType: "u32("+(V.VkMemoryPriorityAllocateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryPriorityAllocateInfoEXT_pNext_offsetof||0)+")",
    priority: "f32("+(V.VkMemoryPriorityAllocateInfoEXT_priority_offsetof||0)+")",
}, (V.VkMemoryPriorityAllocateInfoEXT_sizeof||0))));


const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT_pNext_offsetof||0)+")",
    pageableDeviceLocalMemory: "u32("+(V.VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT_pageableDeviceLocalMemory_offsetof||0)+")",
}, (V.VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceBufferDeviceAddressFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceBufferDeviceAddressFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceBufferDeviceAddressFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceBufferDeviceAddressFeatures_pNext_offsetof||0)+")",
    bufferDeviceAddress: "u32("+(V.VkPhysicalDeviceBufferDeviceAddressFeatures_bufferDeviceAddress_offsetof||0)+")",
    bufferDeviceAddressCaptureReplay: "u32("+(V.VkPhysicalDeviceBufferDeviceAddressFeatures_bufferDeviceAddressCaptureReplay_offsetof||0)+")",
    bufferDeviceAddressMultiDevice: "u32("+(V.VkPhysicalDeviceBufferDeviceAddressFeatures_bufferDeviceAddressMultiDevice_offsetof||0)+")",
}, (V.VkPhysicalDeviceBufferDeviceAddressFeatures_sizeof||0))));

const VkPhysicalDeviceBufferDeviceAddressFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceBufferDeviceAddressFeatures"));


const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceBufferDeviceAddressFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceBufferDeviceAddressFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceBufferDeviceAddressFeaturesEXT_pNext_offsetof||0)+")",
    bufferDeviceAddress: "u32("+(V.VkPhysicalDeviceBufferDeviceAddressFeaturesEXT_bufferDeviceAddress_offsetof||0)+")",
    bufferDeviceAddressCaptureReplay: "u32("+(V.VkPhysicalDeviceBufferDeviceAddressFeaturesEXT_bufferDeviceAddressCaptureReplay_offsetof||0)+")",
    bufferDeviceAddressMultiDevice: "u32("+(V.VkPhysicalDeviceBufferDeviceAddressFeaturesEXT_bufferDeviceAddressMultiDevice_offsetof||0)+")",
}, (V.VkPhysicalDeviceBufferDeviceAddressFeaturesEXT_sizeof||0))));

const VkPhysicalDeviceBufferAddressFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceBufferDeviceAddressFeaturesEXT"));


const VkBufferDeviceAddressInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferDeviceAddressInfo", {
    sType: "u32("+(V.VkBufferDeviceAddressInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferDeviceAddressInfo_pNext_offsetof||0)+")",
    buffer: "u64("+(V.VkBufferDeviceAddressInfo_buffer_offsetof||0)+")",
}, (V.VkBufferDeviceAddressInfo_sizeof||0))));

const VkBufferDeviceAddressInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkBufferDeviceAddressInfo"));

const VkBufferDeviceAddressInfoEXT = new Proxy(function(){}, new C.ConstructProxy("VkBufferDeviceAddressInfo"));


const VkBufferOpaqueCaptureAddressCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferOpaqueCaptureAddressCreateInfo", {
    sType: "u32("+(V.VkBufferOpaqueCaptureAddressCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferOpaqueCaptureAddressCreateInfo_pNext_offsetof||0)+")",
    opaqueCaptureAddress: "u64("+(V.VkBufferOpaqueCaptureAddressCreateInfo_opaqueCaptureAddress_offsetof||0)+")",
}, (V.VkBufferOpaqueCaptureAddressCreateInfo_sizeof||0))));

const VkBufferOpaqueCaptureAddressCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkBufferOpaqueCaptureAddressCreateInfo"));


const VkBufferDeviceAddressCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferDeviceAddressCreateInfoEXT", {
    sType: "u32("+(V.VkBufferDeviceAddressCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferDeviceAddressCreateInfoEXT_pNext_offsetof||0)+")",
    deviceAddress: "u64("+(V.VkBufferDeviceAddressCreateInfoEXT_deviceAddress_offsetof||0)+")",
}, (V.VkBufferDeviceAddressCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceImageViewImageFormatInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceImageViewImageFormatInfoEXT", {
    sType: "u32("+(V.VkPhysicalDeviceImageViewImageFormatInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceImageViewImageFormatInfoEXT_pNext_offsetof||0)+")",
    imageViewType: "u32("+(V.VkPhysicalDeviceImageViewImageFormatInfoEXT_imageViewType_offsetof||0)+")",
}, (V.VkPhysicalDeviceImageViewImageFormatInfoEXT_sizeof||0))));


const VkFilterCubicImageViewImageFormatPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkFilterCubicImageViewImageFormatPropertiesEXT", {
    sType: "u32("+(V.VkFilterCubicImageViewImageFormatPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkFilterCubicImageViewImageFormatPropertiesEXT_pNext_offsetof||0)+")",
    filterCubic: "u32("+(V.VkFilterCubicImageViewImageFormatPropertiesEXT_filterCubic_offsetof||0)+")",
    filterCubicMinmax: "u32("+(V.VkFilterCubicImageViewImageFormatPropertiesEXT_filterCubicMinmax_offsetof||0)+")",
}, (V.VkFilterCubicImageViewImageFormatPropertiesEXT_sizeof||0))));


const VkPhysicalDeviceImagelessFramebufferFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceImagelessFramebufferFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceImagelessFramebufferFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceImagelessFramebufferFeatures_pNext_offsetof||0)+")",
    imagelessFramebuffer: "u32("+(V.VkPhysicalDeviceImagelessFramebufferFeatures_imagelessFramebuffer_offsetof||0)+")",
}, (V.VkPhysicalDeviceImagelessFramebufferFeatures_sizeof||0))));

const VkPhysicalDeviceImagelessFramebufferFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceImagelessFramebufferFeatures"));


const VkFramebufferAttachmentsCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkFramebufferAttachmentsCreateInfo", {
    sType: "u32("+(V.VkFramebufferAttachmentsCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkFramebufferAttachmentsCreateInfo_pNext_offsetof||0)+")",
    attachmentImageInfoCount: "u32("+(V.VkFramebufferAttachmentsCreateInfo_attachmentImageInfoCount_offsetof||0)+")",
    pAttachmentImageInfos: "u64("+(V.VkFramebufferAttachmentsCreateInfo_pAttachmentImageInfos_offsetof||0)+")",
}, (V.VkFramebufferAttachmentsCreateInfo_sizeof||0))));

const VkFramebufferAttachmentsCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkFramebufferAttachmentsCreateInfo"));


const VkFramebufferAttachmentImageInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkFramebufferAttachmentImageInfo", {
    sType: "u32("+(V.VkFramebufferAttachmentImageInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkFramebufferAttachmentImageInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkFramebufferAttachmentImageInfo_flags_offsetof||0)+")",
    usage: "u32("+(V.VkFramebufferAttachmentImageInfo_usage_offsetof||0)+")",
    width: "u32("+(V.VkFramebufferAttachmentImageInfo_width_offsetof||0)+")",
    height: "u32("+(V.VkFramebufferAttachmentImageInfo_height_offsetof||0)+")",
    layerCount: "u32("+(V.VkFramebufferAttachmentImageInfo_layerCount_offsetof||0)+")",
    viewFormatCount: "u32("+(V.VkFramebufferAttachmentImageInfo_viewFormatCount_offsetof||0)+")",
    pViewFormats: "u64("+(V.VkFramebufferAttachmentImageInfo_pViewFormats_offsetof||0)+")",
}, (V.VkFramebufferAttachmentImageInfo_sizeof||0))));

const VkFramebufferAttachmentImageInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkFramebufferAttachmentImageInfo"));


const VkRenderPassAttachmentBeginInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassAttachmentBeginInfo", {
    sType: "u32("+(V.VkRenderPassAttachmentBeginInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderPassAttachmentBeginInfo_pNext_offsetof||0)+")",
    attachmentCount: "u32("+(V.VkRenderPassAttachmentBeginInfo_attachmentCount_offsetof||0)+")",
    pAttachments: "u64("+(V.VkRenderPassAttachmentBeginInfo_pAttachments_offsetof||0)+")",
}, (V.VkRenderPassAttachmentBeginInfo_sizeof||0))));

const VkRenderPassAttachmentBeginInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkRenderPassAttachmentBeginInfo"));


const VkPhysicalDeviceTextureCompressionASTCHDRFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceTextureCompressionASTCHDRFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceTextureCompressionASTCHDRFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceTextureCompressionASTCHDRFeatures_pNext_offsetof||0)+")",
    textureCompressionASTC_HDR: "u32("+(V.VkPhysicalDeviceTextureCompressionASTCHDRFeatures_textureCompressionASTC_HDR_offsetof||0)+")",
}, (V.VkPhysicalDeviceTextureCompressionASTCHDRFeatures_sizeof||0))));

const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceTextureCompressionASTCHDRFeatures"));


const VkPhysicalDeviceCooperativeMatrixFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceCooperativeMatrixFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceCooperativeMatrixFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceCooperativeMatrixFeaturesNV_pNext_offsetof||0)+")",
    cooperativeMatrix: "u32("+(V.VkPhysicalDeviceCooperativeMatrixFeaturesNV_cooperativeMatrix_offsetof||0)+")",
    cooperativeMatrixRobustBufferAccess: "u32("+(V.VkPhysicalDeviceCooperativeMatrixFeaturesNV_cooperativeMatrixRobustBufferAccess_offsetof||0)+")",
}, (V.VkPhysicalDeviceCooperativeMatrixFeaturesNV_sizeof||0))));


const VkPhysicalDeviceCooperativeMatrixPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceCooperativeMatrixPropertiesNV", {
    sType: "u32("+(V.VkPhysicalDeviceCooperativeMatrixPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceCooperativeMatrixPropertiesNV_pNext_offsetof||0)+")",
    cooperativeMatrixSupportedStages: "u32("+(V.VkPhysicalDeviceCooperativeMatrixPropertiesNV_cooperativeMatrixSupportedStages_offsetof||0)+")",
}, (V.VkPhysicalDeviceCooperativeMatrixPropertiesNV_sizeof||0))));


const VkCooperativeMatrixPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCooperativeMatrixPropertiesNV", {
    sType: "u32("+(V.VkCooperativeMatrixPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCooperativeMatrixPropertiesNV_pNext_offsetof||0)+")",
    MSize: "u32("+(V.VkCooperativeMatrixPropertiesNV_MSize_offsetof||0)+")",
    NSize: "u32("+(V.VkCooperativeMatrixPropertiesNV_NSize_offsetof||0)+")",
    KSize: "u32("+(V.VkCooperativeMatrixPropertiesNV_KSize_offsetof||0)+")",
    AType: "u32("+(V.VkCooperativeMatrixPropertiesNV_AType_offsetof||0)+")",
    BType: "u32("+(V.VkCooperativeMatrixPropertiesNV_BType_offsetof||0)+")",
    CType: "u32("+(V.VkCooperativeMatrixPropertiesNV_CType_offsetof||0)+")",
    DType: "u32("+(V.VkCooperativeMatrixPropertiesNV_DType_offsetof||0)+")",
    scope: "u32("+(V.VkCooperativeMatrixPropertiesNV_scope_offsetof||0)+")",
}, (V.VkCooperativeMatrixPropertiesNV_sizeof||0))));


const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceYcbcrImageArraysFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceYcbcrImageArraysFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceYcbcrImageArraysFeaturesEXT_pNext_offsetof||0)+")",
    ycbcrImageArrays: "u32("+(V.VkPhysicalDeviceYcbcrImageArraysFeaturesEXT_ycbcrImageArrays_offsetof||0)+")",
}, (V.VkPhysicalDeviceYcbcrImageArraysFeaturesEXT_sizeof||0))));


const VkImageViewHandleInfoNVX = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageViewHandleInfoNVX", {
    sType: "u32("+(V.VkImageViewHandleInfoNVX_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageViewHandleInfoNVX_pNext_offsetof||0)+")",
    imageView: "u32("+(V.VkImageViewHandleInfoNVX_imageView_offsetof||0)+")",
    descriptorType: "u32("+(V.VkImageViewHandleInfoNVX_descriptorType_offsetof||0)+")",
    sampler: "u64("+(V.VkImageViewHandleInfoNVX_sampler_offsetof||0)+")",
}, (V.VkImageViewHandleInfoNVX_sizeof||0))));


const VkImageViewAddressPropertiesNVX = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageViewAddressPropertiesNVX", {
    sType: "u32("+(V.VkImageViewAddressPropertiesNVX_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageViewAddressPropertiesNVX_pNext_offsetof||0)+")",
    deviceAddress: "u64("+(V.VkImageViewAddressPropertiesNVX_deviceAddress_offsetof||0)+")",
    size: "u64("+(V.VkImageViewAddressPropertiesNVX_size_offsetof||0)+")",
}, (V.VkImageViewAddressPropertiesNVX_sizeof||0))));


const VkPresentFrameTokenGGP = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPresentFrameTokenGGP", {
    sType: "u32("+(V.VkPresentFrameTokenGGP_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPresentFrameTokenGGP_pNext_offsetof||0)+")",
    frameToken: "u32("+(V.VkPresentFrameTokenGGP_frameToken_offsetof||0)+")",
}, (V.VkPresentFrameTokenGGP_sizeof||0))));


const VkPipelineCreationFeedback = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineCreationFeedback", {
    flags: "u32("+(V.VkPipelineCreationFeedback_flags_offsetof||0)+")",
    duration: "u64("+(V.VkPipelineCreationFeedback_duration_offsetof||0)+")",
}, (V.VkPipelineCreationFeedback_sizeof||0))));

const VkPipelineCreationFeedbackEXT = new Proxy(function(){}, new C.ConstructProxy("VkPipelineCreationFeedback"));


const VkPipelineCreationFeedbackCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineCreationFeedbackCreateInfo", {
    sType: "u32("+(V.VkPipelineCreationFeedbackCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineCreationFeedbackCreateInfo_pNext_offsetof||0)+")",
    pPipelineCreationFeedback: "u64("+(V.VkPipelineCreationFeedbackCreateInfo_pPipelineCreationFeedback_offsetof||0)+")",
    pipelineStageCreationFeedbackCount: "u32("+(V.VkPipelineCreationFeedbackCreateInfo_pipelineStageCreationFeedbackCount_offsetof||0)+")",
    pPipelineStageCreationFeedbacks: "u64("+(V.VkPipelineCreationFeedbackCreateInfo_pPipelineStageCreationFeedbacks_offsetof||0)+")",
}, (V.VkPipelineCreationFeedbackCreateInfo_sizeof||0))));

const VkPipelineCreationFeedbackCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy("VkPipelineCreationFeedbackCreateInfo"));


const VkSurfaceFullScreenExclusiveInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSurfaceFullScreenExclusiveInfoEXT", {
    sType: "u32("+(V.VkSurfaceFullScreenExclusiveInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSurfaceFullScreenExclusiveInfoEXT_pNext_offsetof||0)+")",
    fullScreenExclusive: "u32("+(V.VkSurfaceFullScreenExclusiveInfoEXT_fullScreenExclusive_offsetof||0)+")",
}, (V.VkSurfaceFullScreenExclusiveInfoEXT_sizeof||0))));


const VkSurfaceFullScreenExclusiveWin32InfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSurfaceFullScreenExclusiveWin32InfoEXT", {
    sType: "u32("+(V.VkSurfaceFullScreenExclusiveWin32InfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSurfaceFullScreenExclusiveWin32InfoEXT_pNext_offsetof||0)+")",
    hmonitor: "u32("+(V.VkSurfaceFullScreenExclusiveWin32InfoEXT_hmonitor_offsetof||0)+")",
}, (V.VkSurfaceFullScreenExclusiveWin32InfoEXT_sizeof||0))));


const VkSurfaceCapabilitiesFullScreenExclusiveEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSurfaceCapabilitiesFullScreenExclusiveEXT", {
    sType: "u32("+(V.VkSurfaceCapabilitiesFullScreenExclusiveEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSurfaceCapabilitiesFullScreenExclusiveEXT_pNext_offsetof||0)+")",
    fullScreenExclusiveSupported: "u32("+(V.VkSurfaceCapabilitiesFullScreenExclusiveEXT_fullScreenExclusiveSupported_offsetof||0)+")",
}, (V.VkSurfaceCapabilitiesFullScreenExclusiveEXT_sizeof||0))));


const VkPhysicalDevicePresentBarrierFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePresentBarrierFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDevicePresentBarrierFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePresentBarrierFeaturesNV_pNext_offsetof||0)+")",
    presentBarrier: "u32("+(V.VkPhysicalDevicePresentBarrierFeaturesNV_presentBarrier_offsetof||0)+")",
}, (V.VkPhysicalDevicePresentBarrierFeaturesNV_sizeof||0))));


const VkSurfaceCapabilitiesPresentBarrierNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSurfaceCapabilitiesPresentBarrierNV", {
    sType: "u32("+(V.VkSurfaceCapabilitiesPresentBarrierNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSurfaceCapabilitiesPresentBarrierNV_pNext_offsetof||0)+")",
    presentBarrierSupported: "u32("+(V.VkSurfaceCapabilitiesPresentBarrierNV_presentBarrierSupported_offsetof||0)+")",
}, (V.VkSurfaceCapabilitiesPresentBarrierNV_sizeof||0))));


const VkSwapchainPresentBarrierCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSwapchainPresentBarrierCreateInfoNV", {
    sType: "u32("+(V.VkSwapchainPresentBarrierCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSwapchainPresentBarrierCreateInfoNV_pNext_offsetof||0)+")",
    presentBarrierEnable: "u32("+(V.VkSwapchainPresentBarrierCreateInfoNV_presentBarrierEnable_offsetof||0)+")",
}, (V.VkSwapchainPresentBarrierCreateInfoNV_sizeof||0))));


const VkPhysicalDevicePerformanceQueryFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePerformanceQueryFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDevicePerformanceQueryFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePerformanceQueryFeaturesKHR_pNext_offsetof||0)+")",
    performanceCounterQueryPools: "u32("+(V.VkPhysicalDevicePerformanceQueryFeaturesKHR_performanceCounterQueryPools_offsetof||0)+")",
    performanceCounterMultipleQueryPools: "u32("+(V.VkPhysicalDevicePerformanceQueryFeaturesKHR_performanceCounterMultipleQueryPools_offsetof||0)+")",
}, (V.VkPhysicalDevicePerformanceQueryFeaturesKHR_sizeof||0))));


const VkPhysicalDevicePerformanceQueryPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePerformanceQueryPropertiesKHR", {
    sType: "u32("+(V.VkPhysicalDevicePerformanceQueryPropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePerformanceQueryPropertiesKHR_pNext_offsetof||0)+")",
    allowCommandBufferQueryCopies: "u32("+(V.VkPhysicalDevicePerformanceQueryPropertiesKHR_allowCommandBufferQueryCopies_offsetof||0)+")",
}, (V.VkPhysicalDevicePerformanceQueryPropertiesKHR_sizeof||0))));


const VkPerformanceCounterKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPerformanceCounterKHR", {
    sType: "u32("+(V.VkPerformanceCounterKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPerformanceCounterKHR_pNext_offsetof||0)+")",
    unit: "u32("+(V.VkPerformanceCounterKHR_unit_offsetof||0)+")",
    scope: "u32("+(V.VkPerformanceCounterKHR_scope_offsetof||0)+")",
    storage: "u32("+(V.VkPerformanceCounterKHR_storage_offsetof||0)+")",
    uuid: "u8["+(E.VK_UUID_SIZE||1)+"]("+(V.VkPerformanceCounterKHR_uuid_offsetof||0)+")",
}, (V.VkPerformanceCounterKHR_sizeof||0))));


const VkPerformanceCounterDescriptionKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPerformanceCounterDescriptionKHR", {
    sType: "u32("+(V.VkPerformanceCounterDescriptionKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPerformanceCounterDescriptionKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPerformanceCounterDescriptionKHR_flags_offsetof||0)+")",
    name: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkPerformanceCounterDescriptionKHR_name_offsetof||0)+")",
    category: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkPerformanceCounterDescriptionKHR_category_offsetof||0)+")",
    description: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkPerformanceCounterDescriptionKHR_description_offsetof||0)+")",
}, (V.VkPerformanceCounterDescriptionKHR_sizeof||0))));


const VkQueryPoolPerformanceCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkQueryPoolPerformanceCreateInfoKHR", {
    sType: "u32("+(V.VkQueryPoolPerformanceCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkQueryPoolPerformanceCreateInfoKHR_pNext_offsetof||0)+")",
    queueFamilyIndex: "u32("+(V.VkQueryPoolPerformanceCreateInfoKHR_queueFamilyIndex_offsetof||0)+")",
    counterIndexCount: "u32("+(V.VkQueryPoolPerformanceCreateInfoKHR_counterIndexCount_offsetof||0)+")",
    pCounterIndices: "u64("+(V.VkQueryPoolPerformanceCreateInfoKHR_pCounterIndices_offsetof||0)+")",
}, (V.VkQueryPoolPerformanceCreateInfoKHR_sizeof||0))));


const VkAcquireProfilingLockInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAcquireProfilingLockInfoKHR", {
    sType: "u32("+(V.VkAcquireProfilingLockInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAcquireProfilingLockInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkAcquireProfilingLockInfoKHR_flags_offsetof||0)+")",
    timeout: "u64("+(V.VkAcquireProfilingLockInfoKHR_timeout_offsetof||0)+")",
}, (V.VkAcquireProfilingLockInfoKHR_sizeof||0))));


const VkPerformanceQuerySubmitInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPerformanceQuerySubmitInfoKHR", {
    sType: "u32("+(V.VkPerformanceQuerySubmitInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPerformanceQuerySubmitInfoKHR_pNext_offsetof||0)+")",
    counterPassIndex: "u32("+(V.VkPerformanceQuerySubmitInfoKHR_counterPassIndex_offsetof||0)+")",
}, (V.VkPerformanceQuerySubmitInfoKHR_sizeof||0))));


const VkHeadlessSurfaceCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkHeadlessSurfaceCreateInfoEXT", {
    sType: "u32("+(V.VkHeadlessSurfaceCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkHeadlessSurfaceCreateInfoEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkHeadlessSurfaceCreateInfoEXT_flags_offsetof||0)+")",
}, (V.VkHeadlessSurfaceCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceCoverageReductionModeFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceCoverageReductionModeFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceCoverageReductionModeFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceCoverageReductionModeFeaturesNV_pNext_offsetof||0)+")",
    coverageReductionMode: "u32("+(V.VkPhysicalDeviceCoverageReductionModeFeaturesNV_coverageReductionMode_offsetof||0)+")",
}, (V.VkPhysicalDeviceCoverageReductionModeFeaturesNV_sizeof||0))));


const VkPipelineCoverageReductionStateCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineCoverageReductionStateCreateInfoNV", {
    sType: "u32("+(V.VkPipelineCoverageReductionStateCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineCoverageReductionStateCreateInfoNV_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkPipelineCoverageReductionStateCreateInfoNV_flags_offsetof||0)+")",
    coverageReductionMode: "u32("+(V.VkPipelineCoverageReductionStateCreateInfoNV_coverageReductionMode_offsetof||0)+")",
}, (V.VkPipelineCoverageReductionStateCreateInfoNV_sizeof||0))));


const VkFramebufferMixedSamplesCombinationNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkFramebufferMixedSamplesCombinationNV", {
    sType: "u32("+(V.VkFramebufferMixedSamplesCombinationNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkFramebufferMixedSamplesCombinationNV_pNext_offsetof||0)+")",
    coverageReductionMode: "u32("+(V.VkFramebufferMixedSamplesCombinationNV_coverageReductionMode_offsetof||0)+")",
    rasterizationSamples: "u32("+(V.VkFramebufferMixedSamplesCombinationNV_rasterizationSamples_offsetof||0)+")",
    depthStencilSamples: "u32("+(V.VkFramebufferMixedSamplesCombinationNV_depthStencilSamples_offsetof||0)+")",
    colorSamples: "u32("+(V.VkFramebufferMixedSamplesCombinationNV_colorSamples_offsetof||0)+")",
}, (V.VkFramebufferMixedSamplesCombinationNV_sizeof||0))));


const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL", {
    sType: "u32("+(V.VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL_pNext_offsetof||0)+")",
    shaderIntegerFunctions2: "u32("+(V.VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL_shaderIntegerFunctions2_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL_sizeof||0))));


const VkPerformanceValueINTEL = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPerformanceValueINTEL", {
    type: "u32("+(V.VkPerformanceValueINTEL_type_offsetof||0)+")",
    data: "u32("+(V.VkPerformanceValueINTEL_data_offsetof||0)+")",
}, (V.VkPerformanceValueINTEL_sizeof||0))));


const VkInitializePerformanceApiInfoINTEL = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkInitializePerformanceApiInfoINTEL", {
    sType: "u32("+(V.VkInitializePerformanceApiInfoINTEL_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkInitializePerformanceApiInfoINTEL_pNext_offsetof||0)+")",
    pUserData: "u64("+(V.VkInitializePerformanceApiInfoINTEL_pUserData_offsetof||0)+")",
}, (V.VkInitializePerformanceApiInfoINTEL_sizeof||0))));


const VkQueryPoolPerformanceQueryCreateInfoINTEL = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkQueryPoolPerformanceQueryCreateInfoINTEL", {
    sType: "u32("+(V.VkQueryPoolPerformanceQueryCreateInfoINTEL_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkQueryPoolPerformanceQueryCreateInfoINTEL_pNext_offsetof||0)+")",
    performanceCountersSampling: "u32("+(V.VkQueryPoolPerformanceQueryCreateInfoINTEL_performanceCountersSampling_offsetof||0)+")",
}, (V.VkQueryPoolPerformanceQueryCreateInfoINTEL_sizeof||0))));

const VkQueryPoolCreateInfoINTEL = new Proxy(function(){}, new C.ConstructProxy("VkQueryPoolPerformanceQueryCreateInfoINTEL"));


const VkPerformanceMarkerInfoINTEL = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPerformanceMarkerInfoINTEL", {
    sType: "u32("+(V.VkPerformanceMarkerInfoINTEL_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPerformanceMarkerInfoINTEL_pNext_offsetof||0)+")",
    marker: "u64("+(V.VkPerformanceMarkerInfoINTEL_marker_offsetof||0)+")",
}, (V.VkPerformanceMarkerInfoINTEL_sizeof||0))));


const VkPerformanceStreamMarkerInfoINTEL = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPerformanceStreamMarkerInfoINTEL", {
    sType: "u32("+(V.VkPerformanceStreamMarkerInfoINTEL_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPerformanceStreamMarkerInfoINTEL_pNext_offsetof||0)+")",
    marker: "u32("+(V.VkPerformanceStreamMarkerInfoINTEL_marker_offsetof||0)+")",
}, (V.VkPerformanceStreamMarkerInfoINTEL_sizeof||0))));


const VkPerformanceOverrideInfoINTEL = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPerformanceOverrideInfoINTEL", {
    sType: "u32("+(V.VkPerformanceOverrideInfoINTEL_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPerformanceOverrideInfoINTEL_pNext_offsetof||0)+")",
    type: "u32("+(V.VkPerformanceOverrideInfoINTEL_type_offsetof||0)+")",
    enable: "u32("+(V.VkPerformanceOverrideInfoINTEL_enable_offsetof||0)+")",
    parameter: "u64("+(V.VkPerformanceOverrideInfoINTEL_parameter_offsetof||0)+")",
}, (V.VkPerformanceOverrideInfoINTEL_sizeof||0))));


const VkPerformanceConfigurationAcquireInfoINTEL = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPerformanceConfigurationAcquireInfoINTEL", {
    sType: "u32("+(V.VkPerformanceConfigurationAcquireInfoINTEL_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPerformanceConfigurationAcquireInfoINTEL_pNext_offsetof||0)+")",
    type: "u32("+(V.VkPerformanceConfigurationAcquireInfoINTEL_type_offsetof||0)+")",
}, (V.VkPerformanceConfigurationAcquireInfoINTEL_sizeof||0))));


const VkPhysicalDeviceShaderClockFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderClockFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceShaderClockFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderClockFeaturesKHR_pNext_offsetof||0)+")",
    shaderSubgroupClock: "u32("+(V.VkPhysicalDeviceShaderClockFeaturesKHR_shaderSubgroupClock_offsetof||0)+")",
    shaderDeviceClock: "u32("+(V.VkPhysicalDeviceShaderClockFeaturesKHR_shaderDeviceClock_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderClockFeaturesKHR_sizeof||0))));


const VkPhysicalDeviceIndexTypeUint8FeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceIndexTypeUint8FeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceIndexTypeUint8FeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceIndexTypeUint8FeaturesEXT_pNext_offsetof||0)+")",
    indexTypeUint8: "u32("+(V.VkPhysicalDeviceIndexTypeUint8FeaturesEXT_indexTypeUint8_offsetof||0)+")",
}, (V.VkPhysicalDeviceIndexTypeUint8FeaturesEXT_sizeof||0))));


const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderSMBuiltinsPropertiesNV", {
    sType: "u32("+(V.VkPhysicalDeviceShaderSMBuiltinsPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderSMBuiltinsPropertiesNV_pNext_offsetof||0)+")",
    shaderSMCount: "u32("+(V.VkPhysicalDeviceShaderSMBuiltinsPropertiesNV_shaderSMCount_offsetof||0)+")",
    shaderWarpsPerSM: "u32("+(V.VkPhysicalDeviceShaderSMBuiltinsPropertiesNV_shaderWarpsPerSM_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderSMBuiltinsPropertiesNV_sizeof||0))));


const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderSMBuiltinsFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceShaderSMBuiltinsFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderSMBuiltinsFeaturesNV_pNext_offsetof||0)+")",
    shaderSMBuiltins: "u32("+(V.VkPhysicalDeviceShaderSMBuiltinsFeaturesNV_shaderSMBuiltins_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderSMBuiltinsFeaturesNV_sizeof||0))));


const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT_pNext_offsetof||0)+")",
    fragmentShaderSampleInterlock: "u32("+(V.VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT_fragmentShaderSampleInterlock_offsetof||0)+")",
    fragmentShaderPixelInterlock: "u32("+(V.VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT_fragmentShaderPixelInterlock_offsetof||0)+")",
    fragmentShaderShadingRateInterlock: "u32("+(V.VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT_fragmentShaderShadingRateInterlock_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pNext_offsetof||0)+")",
    separateDepthStencilLayouts: "u32("+(V.VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_separateDepthStencilLayouts_offsetof||0)+")",
}, (V.VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_sizeof||0))));

const VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures"));


const VkAttachmentReferenceStencilLayout = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAttachmentReferenceStencilLayout", {
    sType: "u32("+(V.VkAttachmentReferenceStencilLayout_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAttachmentReferenceStencilLayout_pNext_offsetof||0)+")",
    stencilLayout: "u32("+(V.VkAttachmentReferenceStencilLayout_stencilLayout_offsetof||0)+")",
}, (V.VkAttachmentReferenceStencilLayout_sizeof||0))));


const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT_pNext_offsetof||0)+")",
    primitiveTopologyListRestart: "u32("+(V.VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT_primitiveTopologyListRestart_offsetof||0)+")",
    primitiveTopologyPatchListRestart: "u32("+(V.VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT_primitiveTopologyPatchListRestart_offsetof||0)+")",
}, (V.VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT_sizeof||0))));

const VkAttachmentReferenceStencilLayoutKHR = new Proxy(function(){}, new C.ConstructProxy("VkAttachmentReferenceStencilLayout"));


const VkAttachmentDescriptionStencilLayout = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAttachmentDescriptionStencilLayout", {
    sType: "u32("+(V.VkAttachmentDescriptionStencilLayout_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAttachmentDescriptionStencilLayout_pNext_offsetof||0)+")",
    stencilInitialLayout: "u32("+(V.VkAttachmentDescriptionStencilLayout_stencilInitialLayout_offsetof||0)+")",
    stencilFinalLayout: "u32("+(V.VkAttachmentDescriptionStencilLayout_stencilFinalLayout_offsetof||0)+")",
}, (V.VkAttachmentDescriptionStencilLayout_sizeof||0))));

const VkAttachmentDescriptionStencilLayoutKHR = new Proxy(function(){}, new C.ConstructProxy("VkAttachmentDescriptionStencilLayout"));


const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR_pNext_offsetof||0)+")",
    pipelineExecutableInfo: "u32("+(V.VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR_pipelineExecutableInfo_offsetof||0)+")",
}, (V.VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR_sizeof||0))));


const VkPipelineInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineInfoKHR", {
    sType: "u32("+(V.VkPipelineInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineInfoKHR_pNext_offsetof||0)+")",
    pipeline: "u64("+(V.VkPipelineInfoKHR_pipeline_offsetof||0)+")",
}, (V.VkPipelineInfoKHR_sizeof||0))));

const VkPipelineInfoEXT = new Proxy(function(){}, new C.ConstructProxy("VkPipelineInfoKHR"));


const VkPipelineExecutablePropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineExecutablePropertiesKHR", {
    sType: "u32("+(V.VkPipelineExecutablePropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineExecutablePropertiesKHR_pNext_offsetof||0)+")",
    stages: "u32("+(V.VkPipelineExecutablePropertiesKHR_stages_offsetof||0)+")",
    name: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkPipelineExecutablePropertiesKHR_name_offsetof||0)+")",
    description: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkPipelineExecutablePropertiesKHR_description_offsetof||0)+")",
    subgroupSize: "u32("+(V.VkPipelineExecutablePropertiesKHR_subgroupSize_offsetof||0)+")",
}, (V.VkPipelineExecutablePropertiesKHR_sizeof||0))));


const VkPipelineExecutableInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineExecutableInfoKHR", {
    sType: "u32("+(V.VkPipelineExecutableInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineExecutableInfoKHR_pNext_offsetof||0)+")",
    pipeline: "u64("+(V.VkPipelineExecutableInfoKHR_pipeline_offsetof||0)+")",
    executableIndex: "u32("+(V.VkPipelineExecutableInfoKHR_executableIndex_offsetof||0)+")",
}, (V.VkPipelineExecutableInfoKHR_sizeof||0))));


const VkPipelineExecutableStatisticKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineExecutableStatisticKHR", {
    sType: "u32("+(V.VkPipelineExecutableStatisticKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineExecutableStatisticKHR_pNext_offsetof||0)+")",
    name: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkPipelineExecutableStatisticKHR_name_offsetof||0)+")",
    description: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkPipelineExecutableStatisticKHR_description_offsetof||0)+")",
    format: "u32("+(V.VkPipelineExecutableStatisticKHR_format_offsetof||0)+")",
    value: "u32("+(V.VkPipelineExecutableStatisticKHR_value_offsetof||0)+")",
}, (V.VkPipelineExecutableStatisticKHR_sizeof||0))));


const VkPipelineExecutableInternalRepresentationKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineExecutableInternalRepresentationKHR", {
    sType: "u32("+(V.VkPipelineExecutableInternalRepresentationKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineExecutableInternalRepresentationKHR_pNext_offsetof||0)+")",
    name: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkPipelineExecutableInternalRepresentationKHR_name_offsetof||0)+")",
    description: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkPipelineExecutableInternalRepresentationKHR_description_offsetof||0)+")",
    isText: "u32("+(V.VkPipelineExecutableInternalRepresentationKHR_isText_offsetof||0)+")",
    dataSize: "u64("+(V.VkPipelineExecutableInternalRepresentationKHR_dataSize_offsetof||0)+")",
    pData: "u64("+(V.VkPipelineExecutableInternalRepresentationKHR_pData_offsetof||0)+")",
}, (V.VkPipelineExecutableInternalRepresentationKHR_sizeof||0))));


const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures_pNext_offsetof||0)+")",
    shaderDemoteToHelperInvocation: "u32("+(V.VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures_shaderDemoteToHelperInvocation_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures_sizeof||0))));

const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures"));


const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT_pNext_offsetof||0)+")",
    texelBufferAlignment: "u32("+(V.VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT_texelBufferAlignment_offsetof||0)+")",
}, (V.VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceTexelBufferAlignmentProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceTexelBufferAlignmentProperties", {
    sType: "u32("+(V.VkPhysicalDeviceTexelBufferAlignmentProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceTexelBufferAlignmentProperties_pNext_offsetof||0)+")",
    storageTexelBufferOffsetAlignmentBytes: "u64("+(V.VkPhysicalDeviceTexelBufferAlignmentProperties_storageTexelBufferOffsetAlignmentBytes_offsetof||0)+")",
    storageTexelBufferOffsetSingleTexelAlignment: "u32("+(V.VkPhysicalDeviceTexelBufferAlignmentProperties_storageTexelBufferOffsetSingleTexelAlignment_offsetof||0)+")",
    uniformTexelBufferOffsetAlignmentBytes: "u64("+(V.VkPhysicalDeviceTexelBufferAlignmentProperties_uniformTexelBufferOffsetAlignmentBytes_offsetof||0)+")",
    uniformTexelBufferOffsetSingleTexelAlignment: "u32("+(V.VkPhysicalDeviceTexelBufferAlignmentProperties_uniformTexelBufferOffsetSingleTexelAlignment_offsetof||0)+")",
}, (V.VkPhysicalDeviceTexelBufferAlignmentProperties_sizeof||0))));

const VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceTexelBufferAlignmentProperties"));


const VkPhysicalDeviceSubgroupSizeControlFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSubgroupSizeControlFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceSubgroupSizeControlFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSubgroupSizeControlFeatures_pNext_offsetof||0)+")",
    subgroupSizeControl: "u32("+(V.VkPhysicalDeviceSubgroupSizeControlFeatures_subgroupSizeControl_offsetof||0)+")",
    computeFullSubgroups: "u32("+(V.VkPhysicalDeviceSubgroupSizeControlFeatures_computeFullSubgroups_offsetof||0)+")",
}, (V.VkPhysicalDeviceSubgroupSizeControlFeatures_sizeof||0))));

const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceSubgroupSizeControlFeatures"));


const VkPhysicalDeviceSubgroupSizeControlProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSubgroupSizeControlProperties", {
    sType: "u32("+(V.VkPhysicalDeviceSubgroupSizeControlProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSubgroupSizeControlProperties_pNext_offsetof||0)+")",
    minSubgroupSize: "u32("+(V.VkPhysicalDeviceSubgroupSizeControlProperties_minSubgroupSize_offsetof||0)+")",
    maxSubgroupSize: "u32("+(V.VkPhysicalDeviceSubgroupSizeControlProperties_maxSubgroupSize_offsetof||0)+")",
    maxComputeWorkgroupSubgroups: "u32("+(V.VkPhysicalDeviceSubgroupSizeControlProperties_maxComputeWorkgroupSubgroups_offsetof||0)+")",
    requiredSubgroupSizeStages: "u32("+(V.VkPhysicalDeviceSubgroupSizeControlProperties_requiredSubgroupSizeStages_offsetof||0)+")",
}, (V.VkPhysicalDeviceSubgroupSizeControlProperties_sizeof||0))));

const VkPhysicalDeviceSubgroupSizeControlPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceSubgroupSizeControlProperties"));


const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineShaderStageRequiredSubgroupSizeCreateInfo", {
    sType: "u32("+(V.VkPipelineShaderStageRequiredSubgroupSizeCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineShaderStageRequiredSubgroupSizeCreateInfo_pNext_offsetof||0)+")",
    requiredSubgroupSize: "u32("+(V.VkPipelineShaderStageRequiredSubgroupSizeCreateInfo_requiredSubgroupSize_offsetof||0)+")",
}, (V.VkPipelineShaderStageRequiredSubgroupSizeCreateInfo_sizeof||0))));

const VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy("VkPipelineShaderStageRequiredSubgroupSizeCreateInfo"));


const VkSubpassShadingPipelineCreateInfoHUAWEI = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubpassShadingPipelineCreateInfoHUAWEI", {
    sType: "u32("+(V.VkSubpassShadingPipelineCreateInfoHUAWEI_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSubpassShadingPipelineCreateInfoHUAWEI_pNext_offsetof||0)+")",
    renderPass: "u32("+(V.VkSubpassShadingPipelineCreateInfoHUAWEI_renderPass_offsetof||0)+")",
    subpass: "u32("+(V.VkSubpassShadingPipelineCreateInfoHUAWEI_subpass_offsetof||0)+")",
}, (V.VkSubpassShadingPipelineCreateInfoHUAWEI_sizeof||0))));


const VkPhysicalDeviceSubpassShadingPropertiesHUAWEI = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSubpassShadingPropertiesHUAWEI", {
    sType: "u32("+(V.VkPhysicalDeviceSubpassShadingPropertiesHUAWEI_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSubpassShadingPropertiesHUAWEI_pNext_offsetof||0)+")",
    maxSubpassShadingWorkgroupSizeAspectRatio: "u32("+(V.VkPhysicalDeviceSubpassShadingPropertiesHUAWEI_maxSubpassShadingWorkgroupSizeAspectRatio_offsetof||0)+")",
}, (V.VkPhysicalDeviceSubpassShadingPropertiesHUAWEI_sizeof||0))));


const VkMemoryOpaqueCaptureAddressAllocateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryOpaqueCaptureAddressAllocateInfo", {
    sType: "u32("+(V.VkMemoryOpaqueCaptureAddressAllocateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryOpaqueCaptureAddressAllocateInfo_pNext_offsetof||0)+")",
    opaqueCaptureAddress: "u64("+(V.VkMemoryOpaqueCaptureAddressAllocateInfo_opaqueCaptureAddress_offsetof||0)+")",
}, (V.VkMemoryOpaqueCaptureAddressAllocateInfo_sizeof||0))));

const VkMemoryOpaqueCaptureAddressAllocateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkMemoryOpaqueCaptureAddressAllocateInfo"));


const VkDeviceMemoryOpaqueCaptureAddressInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceMemoryOpaqueCaptureAddressInfo", {
    sType: "u32("+(V.VkDeviceMemoryOpaqueCaptureAddressInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceMemoryOpaqueCaptureAddressInfo_pNext_offsetof||0)+")",
    memory: "u64("+(V.VkDeviceMemoryOpaqueCaptureAddressInfo_memory_offsetof||0)+")",
}, (V.VkDeviceMemoryOpaqueCaptureAddressInfo_sizeof||0))));

const VkDeviceMemoryOpaqueCaptureAddressInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkDeviceMemoryOpaqueCaptureAddressInfo"));


const VkPhysicalDeviceLineRasterizationFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceLineRasterizationFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_pNext_offsetof||0)+")",
    rectangularLines: "u32("+(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_rectangularLines_offsetof||0)+")",
    bresenhamLines: "u32("+(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_bresenhamLines_offsetof||0)+")",
    smoothLines: "u32("+(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_smoothLines_offsetof||0)+")",
    stippledRectangularLines: "u32("+(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_stippledRectangularLines_offsetof||0)+")",
    stippledBresenhamLines: "u32("+(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_stippledBresenhamLines_offsetof||0)+")",
    stippledSmoothLines: "u32("+(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_stippledSmoothLines_offsetof||0)+")",
}, (V.VkPhysicalDeviceLineRasterizationFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceLineRasterizationPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceLineRasterizationPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceLineRasterizationPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceLineRasterizationPropertiesEXT_pNext_offsetof||0)+")",
    lineSubPixelPrecisionBits: "u32("+(V.VkPhysicalDeviceLineRasterizationPropertiesEXT_lineSubPixelPrecisionBits_offsetof||0)+")",
}, (V.VkPhysicalDeviceLineRasterizationPropertiesEXT_sizeof||0))));


const VkPipelineRasterizationLineStateCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineRasterizationLineStateCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineRasterizationLineStateCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineRasterizationLineStateCreateInfoEXT_pNext_offsetof||0)+")",
    lineRasterizationMode: "u32("+(V.VkPipelineRasterizationLineStateCreateInfoEXT_lineRasterizationMode_offsetof||0)+")",
    stippledLineEnable: "u32("+(V.VkPipelineRasterizationLineStateCreateInfoEXT_stippledLineEnable_offsetof||0)+")",
    lineStippleFactor: "u32("+(V.VkPipelineRasterizationLineStateCreateInfoEXT_lineStippleFactor_offsetof||0)+")",
    lineStipplePattern: "u16("+(V.VkPipelineRasterizationLineStateCreateInfoEXT_lineStipplePattern_offsetof||0)+")",
}, (V.VkPipelineRasterizationLineStateCreateInfoEXT_sizeof||0))));


const VkPhysicalDevicePipelineCreationCacheControlFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePipelineCreationCacheControlFeatures", {
    sType: "u32("+(V.VkPhysicalDevicePipelineCreationCacheControlFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePipelineCreationCacheControlFeatures_pNext_offsetof||0)+")",
    pipelineCreationCacheControl: "u32("+(V.VkPhysicalDevicePipelineCreationCacheControlFeatures_pipelineCreationCacheControl_offsetof||0)+")",
}, (V.VkPhysicalDevicePipelineCreationCacheControlFeatures_sizeof||0))));

const VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDevicePipelineCreationCacheControlFeatures"));


const VkPhysicalDeviceVulkan11Features = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceVulkan11Features", {
    sType: "u32("+(V.VkPhysicalDeviceVulkan11Features_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceVulkan11Features_pNext_offsetof||0)+")",
    storageBuffer16BitAccess: "u32("+(V.VkPhysicalDeviceVulkan11Features_storageBuffer16BitAccess_offsetof||0)+")",
    uniformAndStorageBuffer16BitAccess: "u32("+(V.VkPhysicalDeviceVulkan11Features_uniformAndStorageBuffer16BitAccess_offsetof||0)+")",
    storagePushConstant16: "u32("+(V.VkPhysicalDeviceVulkan11Features_storagePushConstant16_offsetof||0)+")",
    storageInputOutput16: "u32("+(V.VkPhysicalDeviceVulkan11Features_storageInputOutput16_offsetof||0)+")",
    multiview: "u32("+(V.VkPhysicalDeviceVulkan11Features_multiview_offsetof||0)+")",
    multiviewGeometryShader: "u32("+(V.VkPhysicalDeviceVulkan11Features_multiviewGeometryShader_offsetof||0)+")",
    multiviewTessellationShader: "u32("+(V.VkPhysicalDeviceVulkan11Features_multiviewTessellationShader_offsetof||0)+")",
    variablePointersStorageBuffer: "u32("+(V.VkPhysicalDeviceVulkan11Features_variablePointersStorageBuffer_offsetof||0)+")",
    variablePointers: "u32("+(V.VkPhysicalDeviceVulkan11Features_variablePointers_offsetof||0)+")",
    protectedMemory: "u32("+(V.VkPhysicalDeviceVulkan11Features_protectedMemory_offsetof||0)+")",
    samplerYcbcrConversion: "u32("+(V.VkPhysicalDeviceVulkan11Features_samplerYcbcrConversion_offsetof||0)+")",
    shaderDrawParameters: "u32("+(V.VkPhysicalDeviceVulkan11Features_shaderDrawParameters_offsetof||0)+")",
}, (V.VkPhysicalDeviceVulkan11Features_sizeof||0))));


const VkPhysicalDeviceVulkan11Properties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceVulkan11Properties", {
    sType: "u32("+(V.VkPhysicalDeviceVulkan11Properties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceVulkan11Properties_pNext_offsetof||0)+")",
    deviceUUID: "u8["+(E.VK_UUID_SIZE||1)+"]("+(V.VkPhysicalDeviceVulkan11Properties_deviceUUID_offsetof||0)+")",
    driverUUID: "u8["+(E.VK_UUID_SIZE||1)+"]("+(V.VkPhysicalDeviceVulkan11Properties_driverUUID_offsetof||0)+")",
    deviceLUID: "u8["+(E.VK_LUID_SIZE||1)+"]("+(V.VkPhysicalDeviceVulkan11Properties_deviceLUID_offsetof||0)+")",
    deviceNodeMask: "u32("+(V.VkPhysicalDeviceVulkan11Properties_deviceNodeMask_offsetof||0)+")",
    deviceLUIDValid: "u32("+(V.VkPhysicalDeviceVulkan11Properties_deviceLUIDValid_offsetof||0)+")",
    subgroupSize: "u32("+(V.VkPhysicalDeviceVulkan11Properties_subgroupSize_offsetof||0)+")",
    subgroupSupportedStages: "u32("+(V.VkPhysicalDeviceVulkan11Properties_subgroupSupportedStages_offsetof||0)+")",
    subgroupSupportedOperations: "u32("+(V.VkPhysicalDeviceVulkan11Properties_subgroupSupportedOperations_offsetof||0)+")",
    subgroupQuadOperationsInAllStages: "u32("+(V.VkPhysicalDeviceVulkan11Properties_subgroupQuadOperationsInAllStages_offsetof||0)+")",
    pointClippingBehavior: "u32("+(V.VkPhysicalDeviceVulkan11Properties_pointClippingBehavior_offsetof||0)+")",
    maxMultiviewViewCount: "u32("+(V.VkPhysicalDeviceVulkan11Properties_maxMultiviewViewCount_offsetof||0)+")",
    maxMultiviewInstanceIndex: "u32("+(V.VkPhysicalDeviceVulkan11Properties_maxMultiviewInstanceIndex_offsetof||0)+")",
    protectedNoFault: "u32("+(V.VkPhysicalDeviceVulkan11Properties_protectedNoFault_offsetof||0)+")",
    maxPerSetDescriptors: "u32("+(V.VkPhysicalDeviceVulkan11Properties_maxPerSetDescriptors_offsetof||0)+")",
    maxMemoryAllocationSize: "u64("+(V.VkPhysicalDeviceVulkan11Properties_maxMemoryAllocationSize_offsetof||0)+")",
}, (V.VkPhysicalDeviceVulkan11Properties_sizeof||0))));


const VkPhysicalDeviceVulkan12Features = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceVulkan12Features", {
    sType: "u32("+(V.VkPhysicalDeviceVulkan12Features_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceVulkan12Features_pNext_offsetof||0)+")",
    samplerMirrorClampToEdge: "u32("+(V.VkPhysicalDeviceVulkan12Features_samplerMirrorClampToEdge_offsetof||0)+")",
    drawIndirectCount: "u32("+(V.VkPhysicalDeviceVulkan12Features_drawIndirectCount_offsetof||0)+")",
    storageBuffer8BitAccess: "u32("+(V.VkPhysicalDeviceVulkan12Features_storageBuffer8BitAccess_offsetof||0)+")",
    uniformAndStorageBuffer8BitAccess: "u32("+(V.VkPhysicalDeviceVulkan12Features_uniformAndStorageBuffer8BitAccess_offsetof||0)+")",
    storagePushConstant8: "u32("+(V.VkPhysicalDeviceVulkan12Features_storagePushConstant8_offsetof||0)+")",
    shaderBufferInt64Atomics: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderBufferInt64Atomics_offsetof||0)+")",
    shaderSharedInt64Atomics: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderSharedInt64Atomics_offsetof||0)+")",
    shaderFloat16: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderFloat16_offsetof||0)+")",
    shaderInt8: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderInt8_offsetof||0)+")",
    descriptorIndexing: "u32("+(V.VkPhysicalDeviceVulkan12Features_descriptorIndexing_offsetof||0)+")",
    shaderInputAttachmentArrayDynamicIndexing: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderInputAttachmentArrayDynamicIndexing_offsetof||0)+")",
    shaderUniformTexelBufferArrayDynamicIndexing: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderUniformTexelBufferArrayDynamicIndexing_offsetof||0)+")",
    shaderStorageTexelBufferArrayDynamicIndexing: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderStorageTexelBufferArrayDynamicIndexing_offsetof||0)+")",
    shaderUniformBufferArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderUniformBufferArrayNonUniformIndexing_offsetof||0)+")",
    shaderSampledImageArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderSampledImageArrayNonUniformIndexing_offsetof||0)+")",
    shaderStorageBufferArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderStorageBufferArrayNonUniformIndexing_offsetof||0)+")",
    shaderStorageImageArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderStorageImageArrayNonUniformIndexing_offsetof||0)+")",
    shaderInputAttachmentArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderInputAttachmentArrayNonUniformIndexing_offsetof||0)+")",
    shaderUniformTexelBufferArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderUniformTexelBufferArrayNonUniformIndexing_offsetof||0)+")",
    shaderStorageTexelBufferArrayNonUniformIndexing: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderStorageTexelBufferArrayNonUniformIndexing_offsetof||0)+")",
    descriptorBindingUniformBufferUpdateAfterBind: "u32("+(V.VkPhysicalDeviceVulkan12Features_descriptorBindingUniformBufferUpdateAfterBind_offsetof||0)+")",
    descriptorBindingSampledImageUpdateAfterBind: "u32("+(V.VkPhysicalDeviceVulkan12Features_descriptorBindingSampledImageUpdateAfterBind_offsetof||0)+")",
    descriptorBindingStorageImageUpdateAfterBind: "u32("+(V.VkPhysicalDeviceVulkan12Features_descriptorBindingStorageImageUpdateAfterBind_offsetof||0)+")",
    descriptorBindingStorageBufferUpdateAfterBind: "u32("+(V.VkPhysicalDeviceVulkan12Features_descriptorBindingStorageBufferUpdateAfterBind_offsetof||0)+")",
    descriptorBindingUniformTexelBufferUpdateAfterBind: "u32("+(V.VkPhysicalDeviceVulkan12Features_descriptorBindingUniformTexelBufferUpdateAfterBind_offsetof||0)+")",
    descriptorBindingStorageTexelBufferUpdateAfterBind: "u32("+(V.VkPhysicalDeviceVulkan12Features_descriptorBindingStorageTexelBufferUpdateAfterBind_offsetof||0)+")",
    descriptorBindingUpdateUnusedWhilePending: "u32("+(V.VkPhysicalDeviceVulkan12Features_descriptorBindingUpdateUnusedWhilePending_offsetof||0)+")",
    descriptorBindingPartiallyBound: "u32("+(V.VkPhysicalDeviceVulkan12Features_descriptorBindingPartiallyBound_offsetof||0)+")",
    descriptorBindingVariableDescriptorCount: "u32("+(V.VkPhysicalDeviceVulkan12Features_descriptorBindingVariableDescriptorCount_offsetof||0)+")",
    runtimeDescriptorArray: "u32("+(V.VkPhysicalDeviceVulkan12Features_runtimeDescriptorArray_offsetof||0)+")",
    samplerFilterMinmax: "u32("+(V.VkPhysicalDeviceVulkan12Features_samplerFilterMinmax_offsetof||0)+")",
    scalarBlockLayout: "u32("+(V.VkPhysicalDeviceVulkan12Features_scalarBlockLayout_offsetof||0)+")",
    imagelessFramebuffer: "u32("+(V.VkPhysicalDeviceVulkan12Features_imagelessFramebuffer_offsetof||0)+")",
    uniformBufferStandardLayout: "u32("+(V.VkPhysicalDeviceVulkan12Features_uniformBufferStandardLayout_offsetof||0)+")",
    shaderSubgroupExtendedTypes: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderSubgroupExtendedTypes_offsetof||0)+")",
    separateDepthStencilLayouts: "u32("+(V.VkPhysicalDeviceVulkan12Features_separateDepthStencilLayouts_offsetof||0)+")",
    hostQueryReset: "u32("+(V.VkPhysicalDeviceVulkan12Features_hostQueryReset_offsetof||0)+")",
    timelineSemaphore: "u32("+(V.VkPhysicalDeviceVulkan12Features_timelineSemaphore_offsetof||0)+")",
    bufferDeviceAddress: "u32("+(V.VkPhysicalDeviceVulkan12Features_bufferDeviceAddress_offsetof||0)+")",
    bufferDeviceAddressCaptureReplay: "u32("+(V.VkPhysicalDeviceVulkan12Features_bufferDeviceAddressCaptureReplay_offsetof||0)+")",
    bufferDeviceAddressMultiDevice: "u32("+(V.VkPhysicalDeviceVulkan12Features_bufferDeviceAddressMultiDevice_offsetof||0)+")",
    vulkanMemoryModel: "u32("+(V.VkPhysicalDeviceVulkan12Features_vulkanMemoryModel_offsetof||0)+")",
    vulkanMemoryModelDeviceScope: "u32("+(V.VkPhysicalDeviceVulkan12Features_vulkanMemoryModelDeviceScope_offsetof||0)+")",
    vulkanMemoryModelAvailabilityVisibilityChains: "u32("+(V.VkPhysicalDeviceVulkan12Features_vulkanMemoryModelAvailabilityVisibilityChains_offsetof||0)+")",
    shaderOutputViewportIndex: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderOutputViewportIndex_offsetof||0)+")",
    shaderOutputLayer: "u32("+(V.VkPhysicalDeviceVulkan12Features_shaderOutputLayer_offsetof||0)+")",
    subgroupBroadcastDynamicId: "u32("+(V.VkPhysicalDeviceVulkan12Features_subgroupBroadcastDynamicId_offsetof||0)+")",
}, (V.VkPhysicalDeviceVulkan12Features_sizeof||0))));


const VkPhysicalDeviceVulkan12Properties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceVulkan12Properties", {
    sType: "u32("+(V.VkPhysicalDeviceVulkan12Properties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceVulkan12Properties_pNext_offsetof||0)+")",
    driverID: "u32("+(V.VkPhysicalDeviceVulkan12Properties_driverID_offsetof||0)+")",
    driverName: "u8["+(E.VK_MAX_DRIVER_NAME_SIZE||1)+"]("+(V.VkPhysicalDeviceVulkan12Properties_driverName_offsetof||0)+")",
    driverInfo: "u8["+(E.VK_MAX_DRIVER_INFO_SIZE||1)+"]("+(V.VkPhysicalDeviceVulkan12Properties_driverInfo_offsetof||0)+")",
    conformanceVersion: "u32("+(V.VkPhysicalDeviceVulkan12Properties_conformanceVersion_offsetof||0)+")",
    denormBehaviorIndependence: "u32("+(V.VkPhysicalDeviceVulkan12Properties_denormBehaviorIndependence_offsetof||0)+")",
    roundingModeIndependence: "u32("+(V.VkPhysicalDeviceVulkan12Properties_roundingModeIndependence_offsetof||0)+")",
    shaderSignedZeroInfNanPreserveFloat16: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderSignedZeroInfNanPreserveFloat16_offsetof||0)+")",
    shaderSignedZeroInfNanPreserveFloat32: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderSignedZeroInfNanPreserveFloat32_offsetof||0)+")",
    shaderSignedZeroInfNanPreserveFloat64: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderSignedZeroInfNanPreserveFloat64_offsetof||0)+")",
    shaderDenormPreserveFloat16: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderDenormPreserveFloat16_offsetof||0)+")",
    shaderDenormPreserveFloat32: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderDenormPreserveFloat32_offsetof||0)+")",
    shaderDenormPreserveFloat64: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderDenormPreserveFloat64_offsetof||0)+")",
    shaderDenormFlushToZeroFloat16: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderDenormFlushToZeroFloat16_offsetof||0)+")",
    shaderDenormFlushToZeroFloat32: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderDenormFlushToZeroFloat32_offsetof||0)+")",
    shaderDenormFlushToZeroFloat64: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderDenormFlushToZeroFloat64_offsetof||0)+")",
    shaderRoundingModeRTEFloat16: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderRoundingModeRTEFloat16_offsetof||0)+")",
    shaderRoundingModeRTEFloat32: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderRoundingModeRTEFloat32_offsetof||0)+")",
    shaderRoundingModeRTEFloat64: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderRoundingModeRTEFloat64_offsetof||0)+")",
    shaderRoundingModeRTZFloat16: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderRoundingModeRTZFloat16_offsetof||0)+")",
    shaderRoundingModeRTZFloat32: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderRoundingModeRTZFloat32_offsetof||0)+")",
    shaderRoundingModeRTZFloat64: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderRoundingModeRTZFloat64_offsetof||0)+")",
    maxUpdateAfterBindDescriptorsInAllPools: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxUpdateAfterBindDescriptorsInAllPools_offsetof||0)+")",
    shaderUniformBufferArrayNonUniformIndexingNative: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderUniformBufferArrayNonUniformIndexingNative_offsetof||0)+")",
    shaderSampledImageArrayNonUniformIndexingNative: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderSampledImageArrayNonUniformIndexingNative_offsetof||0)+")",
    shaderStorageBufferArrayNonUniformIndexingNative: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderStorageBufferArrayNonUniformIndexingNative_offsetof||0)+")",
    shaderStorageImageArrayNonUniformIndexingNative: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderStorageImageArrayNonUniformIndexingNative_offsetof||0)+")",
    shaderInputAttachmentArrayNonUniformIndexingNative: "u32("+(V.VkPhysicalDeviceVulkan12Properties_shaderInputAttachmentArrayNonUniformIndexingNative_offsetof||0)+")",
    robustBufferAccessUpdateAfterBind: "u32("+(V.VkPhysicalDeviceVulkan12Properties_robustBufferAccessUpdateAfterBind_offsetof||0)+")",
    quadDivergentImplicitLod: "u32("+(V.VkPhysicalDeviceVulkan12Properties_quadDivergentImplicitLod_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindSamplers: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxPerStageDescriptorUpdateAfterBindSamplers_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindUniformBuffers: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxPerStageDescriptorUpdateAfterBindUniformBuffers_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindStorageBuffers: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxPerStageDescriptorUpdateAfterBindStorageBuffers_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindSampledImages: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxPerStageDescriptorUpdateAfterBindSampledImages_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindStorageImages: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxPerStageDescriptorUpdateAfterBindStorageImages_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindInputAttachments: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxPerStageDescriptorUpdateAfterBindInputAttachments_offsetof||0)+")",
    maxPerStageUpdateAfterBindResources: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxPerStageUpdateAfterBindResources_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindSamplers: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindSamplers_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindUniformBuffers: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindUniformBuffers_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindUniformBuffersDynamic: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindUniformBuffersDynamic_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindStorageBuffers: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindStorageBuffers_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindStorageBuffersDynamic: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindStorageBuffersDynamic_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindSampledImages: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindSampledImages_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindStorageImages: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindStorageImages_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindInputAttachments: "u32("+(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindInputAttachments_offsetof||0)+")",
    supportedDepthResolveModes: "u32("+(V.VkPhysicalDeviceVulkan12Properties_supportedDepthResolveModes_offsetof||0)+")",
    supportedStencilResolveModes: "u32("+(V.VkPhysicalDeviceVulkan12Properties_supportedStencilResolveModes_offsetof||0)+")",
    independentResolveNone: "u32("+(V.VkPhysicalDeviceVulkan12Properties_independentResolveNone_offsetof||0)+")",
    independentResolve: "u32("+(V.VkPhysicalDeviceVulkan12Properties_independentResolve_offsetof||0)+")",
    filterMinmaxSingleComponentFormats: "u32("+(V.VkPhysicalDeviceVulkan12Properties_filterMinmaxSingleComponentFormats_offsetof||0)+")",
    filterMinmaxImageComponentMapping: "u32("+(V.VkPhysicalDeviceVulkan12Properties_filterMinmaxImageComponentMapping_offsetof||0)+")",
    maxTimelineSemaphoreValueDifference: "u64("+(V.VkPhysicalDeviceVulkan12Properties_maxTimelineSemaphoreValueDifference_offsetof||0)+")",
    framebufferIntegerColorSampleCounts: "u32("+(V.VkPhysicalDeviceVulkan12Properties_framebufferIntegerColorSampleCounts_offsetof||0)+")",
}, (V.VkPhysicalDeviceVulkan12Properties_sizeof||0))));


const VkPhysicalDeviceVulkan13Features = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceVulkan13Features", {
    sType: "u32("+(V.VkPhysicalDeviceVulkan13Features_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceVulkan13Features_pNext_offsetof||0)+")",
    robustImageAccess: "u32("+(V.VkPhysicalDeviceVulkan13Features_robustImageAccess_offsetof||0)+")",
    inlineUniformBlock: "u32("+(V.VkPhysicalDeviceVulkan13Features_inlineUniformBlock_offsetof||0)+")",
    descriptorBindingInlineUniformBlockUpdateAfterBind: "u32("+(V.VkPhysicalDeviceVulkan13Features_descriptorBindingInlineUniformBlockUpdateAfterBind_offsetof||0)+")",
    pipelineCreationCacheControl: "u32("+(V.VkPhysicalDeviceVulkan13Features_pipelineCreationCacheControl_offsetof||0)+")",
    privateData: "u32("+(V.VkPhysicalDeviceVulkan13Features_privateData_offsetof||0)+")",
    shaderDemoteToHelperInvocation: "u32("+(V.VkPhysicalDeviceVulkan13Features_shaderDemoteToHelperInvocation_offsetof||0)+")",
    shaderTerminateInvocation: "u32("+(V.VkPhysicalDeviceVulkan13Features_shaderTerminateInvocation_offsetof||0)+")",
    subgroupSizeControl: "u32("+(V.VkPhysicalDeviceVulkan13Features_subgroupSizeControl_offsetof||0)+")",
    computeFullSubgroups: "u32("+(V.VkPhysicalDeviceVulkan13Features_computeFullSubgroups_offsetof||0)+")",
    synchronization2: "u32("+(V.VkPhysicalDeviceVulkan13Features_synchronization2_offsetof||0)+")",
    textureCompressionASTC_HDR: "u32("+(V.VkPhysicalDeviceVulkan13Features_textureCompressionASTC_HDR_offsetof||0)+")",
    shaderZeroInitializeWorkgroupMemory: "u32("+(V.VkPhysicalDeviceVulkan13Features_shaderZeroInitializeWorkgroupMemory_offsetof||0)+")",
    dynamicRendering: "u32("+(V.VkPhysicalDeviceVulkan13Features_dynamicRendering_offsetof||0)+")",
    shaderIntegerDotProduct: "u32("+(V.VkPhysicalDeviceVulkan13Features_shaderIntegerDotProduct_offsetof||0)+")",
    maintenance4: "u32("+(V.VkPhysicalDeviceVulkan13Features_maintenance4_offsetof||0)+")",
}, (V.VkPhysicalDeviceVulkan13Features_sizeof||0))));


const VkPhysicalDeviceVulkan13Properties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceVulkan13Properties", {
    sType: "u32("+(V.VkPhysicalDeviceVulkan13Properties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceVulkan13Properties_pNext_offsetof||0)+")",
    minSubgroupSize: "u32("+(V.VkPhysicalDeviceVulkan13Properties_minSubgroupSize_offsetof||0)+")",
    maxSubgroupSize: "u32("+(V.VkPhysicalDeviceVulkan13Properties_maxSubgroupSize_offsetof||0)+")",
    maxComputeWorkgroupSubgroups: "u32("+(V.VkPhysicalDeviceVulkan13Properties_maxComputeWorkgroupSubgroups_offsetof||0)+")",
    requiredSubgroupSizeStages: "u32("+(V.VkPhysicalDeviceVulkan13Properties_requiredSubgroupSizeStages_offsetof||0)+")",
    maxInlineUniformBlockSize: "u32("+(V.VkPhysicalDeviceVulkan13Properties_maxInlineUniformBlockSize_offsetof||0)+")",
    maxPerStageDescriptorInlineUniformBlocks: "u32("+(V.VkPhysicalDeviceVulkan13Properties_maxPerStageDescriptorInlineUniformBlocks_offsetof||0)+")",
    maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks: "u32("+(V.VkPhysicalDeviceVulkan13Properties_maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks_offsetof||0)+")",
    maxDescriptorSetInlineUniformBlocks: "u32("+(V.VkPhysicalDeviceVulkan13Properties_maxDescriptorSetInlineUniformBlocks_offsetof||0)+")",
    maxDescriptorSetUpdateAfterBindInlineUniformBlocks: "u32("+(V.VkPhysicalDeviceVulkan13Properties_maxDescriptorSetUpdateAfterBindInlineUniformBlocks_offsetof||0)+")",
    maxInlineUniformTotalSize: "u32("+(V.VkPhysicalDeviceVulkan13Properties_maxInlineUniformTotalSize_offsetof||0)+")",
    integerDotProduct8BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct8BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProduct8BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct8BitSignedAccelerated_offsetof||0)+")",
    integerDotProduct8BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct8BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProduct4x8BitPackedUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct4x8BitPackedUnsignedAccelerated_offsetof||0)+")",
    integerDotProduct4x8BitPackedSignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct4x8BitPackedSignedAccelerated_offsetof||0)+")",
    integerDotProduct4x8BitPackedMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct4x8BitPackedMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProduct16BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct16BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProduct16BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct16BitSignedAccelerated_offsetof||0)+")",
    integerDotProduct16BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct16BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProduct32BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct32BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProduct32BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct32BitSignedAccelerated_offsetof||0)+")",
    integerDotProduct32BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct32BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProduct64BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct64BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProduct64BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct64BitSignedAccelerated_offsetof||0)+")",
    integerDotProduct64BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct64BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating8BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating8BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating8BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating8BitSignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating16BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating16BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating16BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating16BitSignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating32BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating32BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating32BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating32BitSignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating64BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating64BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating64BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating64BitSignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated_offsetof||0)+")",
    storageTexelBufferOffsetAlignmentBytes: "u64("+(V.VkPhysicalDeviceVulkan13Properties_storageTexelBufferOffsetAlignmentBytes_offsetof||0)+")",
    storageTexelBufferOffsetSingleTexelAlignment: "u32("+(V.VkPhysicalDeviceVulkan13Properties_storageTexelBufferOffsetSingleTexelAlignment_offsetof||0)+")",
    uniformTexelBufferOffsetAlignmentBytes: "u64("+(V.VkPhysicalDeviceVulkan13Properties_uniformTexelBufferOffsetAlignmentBytes_offsetof||0)+")",
    uniformTexelBufferOffsetSingleTexelAlignment: "u32("+(V.VkPhysicalDeviceVulkan13Properties_uniformTexelBufferOffsetSingleTexelAlignment_offsetof||0)+")",
    maxBufferSize: "u64("+(V.VkPhysicalDeviceVulkan13Properties_maxBufferSize_offsetof||0)+")",
}, (V.VkPhysicalDeviceVulkan13Properties_sizeof||0))));


const VkPipelineCompilerControlCreateInfoAMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineCompilerControlCreateInfoAMD", {
    sType: "u32("+(V.VkPipelineCompilerControlCreateInfoAMD_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineCompilerControlCreateInfoAMD_pNext_offsetof||0)+")",
    compilerControlFlags: "u32("+(V.VkPipelineCompilerControlCreateInfoAMD_compilerControlFlags_offsetof||0)+")",
}, (V.VkPipelineCompilerControlCreateInfoAMD_sizeof||0))));


const VkPhysicalDeviceCoherentMemoryFeaturesAMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceCoherentMemoryFeaturesAMD", {
    sType: "u32("+(V.VkPhysicalDeviceCoherentMemoryFeaturesAMD_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceCoherentMemoryFeaturesAMD_pNext_offsetof||0)+")",
    deviceCoherentMemory: "u32("+(V.VkPhysicalDeviceCoherentMemoryFeaturesAMD_deviceCoherentMemory_offsetof||0)+")",
}, (V.VkPhysicalDeviceCoherentMemoryFeaturesAMD_sizeof||0))));


const VkPhysicalDeviceToolProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceToolProperties", {
    sType: "u32("+(V.VkPhysicalDeviceToolProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceToolProperties_pNext_offsetof||0)+")",
    name: "u8["+(E.VK_MAX_EXTENSION_NAME_SIZE||1)+"]("+(V.VkPhysicalDeviceToolProperties_name_offsetof||0)+")",
    version: "u8["+(E.VK_MAX_EXTENSION_NAME_SIZE||1)+"]("+(V.VkPhysicalDeviceToolProperties_version_offsetof||0)+")",
    purposes: "u32("+(V.VkPhysicalDeviceToolProperties_purposes_offsetof||0)+")",
    description: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkPhysicalDeviceToolProperties_description_offsetof||0)+")",
    layer: "u8["+(E.VK_MAX_EXTENSION_NAME_SIZE||1)+"]("+(V.VkPhysicalDeviceToolProperties_layer_offsetof||0)+")",
}, (V.VkPhysicalDeviceToolProperties_sizeof||0))));

const VkPhysicalDeviceToolPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceToolProperties"));


const VkSamplerCustomBorderColorCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSamplerCustomBorderColorCreateInfoEXT", {
    sType: "u32("+(V.VkSamplerCustomBorderColorCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSamplerCustomBorderColorCreateInfoEXT_pNext_offsetof||0)+")",
    customBorderColor: "u32("+(V.VkSamplerCustomBorderColorCreateInfoEXT_customBorderColor_offsetof||0)+")",
    format: "u32("+(V.VkSamplerCustomBorderColorCreateInfoEXT_format_offsetof||0)+")",
}, (V.VkSamplerCustomBorderColorCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceCustomBorderColorPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceCustomBorderColorPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceCustomBorderColorPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceCustomBorderColorPropertiesEXT_pNext_offsetof||0)+")",
    maxCustomBorderColorSamplers: "u32("+(V.VkPhysicalDeviceCustomBorderColorPropertiesEXT_maxCustomBorderColorSamplers_offsetof||0)+")",
}, (V.VkPhysicalDeviceCustomBorderColorPropertiesEXT_sizeof||0))));


const VkPhysicalDeviceCustomBorderColorFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceCustomBorderColorFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceCustomBorderColorFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceCustomBorderColorFeaturesEXT_pNext_offsetof||0)+")",
    customBorderColors: "u32("+(V.VkPhysicalDeviceCustomBorderColorFeaturesEXT_customBorderColors_offsetof||0)+")",
    customBorderColorWithoutFormat: "u32("+(V.VkPhysicalDeviceCustomBorderColorFeaturesEXT_customBorderColorWithoutFormat_offsetof||0)+")",
}, (V.VkPhysicalDeviceCustomBorderColorFeaturesEXT_sizeof||0))));


const VkSamplerBorderColorComponentMappingCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSamplerBorderColorComponentMappingCreateInfoEXT", {
    sType: "u32("+(V.VkSamplerBorderColorComponentMappingCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSamplerBorderColorComponentMappingCreateInfoEXT_pNext_offsetof||0)+")",
    components: "u32("+(V.VkSamplerBorderColorComponentMappingCreateInfoEXT_components_offsetof||0)+")",
    srgb: "u32("+(V.VkSamplerBorderColorComponentMappingCreateInfoEXT_srgb_offsetof||0)+")",
}, (V.VkSamplerBorderColorComponentMappingCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceBorderColorSwizzleFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceBorderColorSwizzleFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceBorderColorSwizzleFeaturesEXT_pNext_offsetof||0)+")",
    borderColorSwizzle: "u32("+(V.VkPhysicalDeviceBorderColorSwizzleFeaturesEXT_borderColorSwizzle_offsetof||0)+")",
    borderColorSwizzleFromImage: "u32("+(V.VkPhysicalDeviceBorderColorSwizzleFeaturesEXT_borderColorSwizzleFromImage_offsetof||0)+")",
}, (V.VkPhysicalDeviceBorderColorSwizzleFeaturesEXT_sizeof||0))));


const VkAccelerationStructureGeometryTrianglesDataKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureGeometryTrianglesDataKHR", {
    sType: "u32("+(V.VkAccelerationStructureGeometryTrianglesDataKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureGeometryTrianglesDataKHR_pNext_offsetof||0)+")",
    vertexFormat: "u32("+(V.VkAccelerationStructureGeometryTrianglesDataKHR_vertexFormat_offsetof||0)+")",
    vertexData: "u32("+(V.VkAccelerationStructureGeometryTrianglesDataKHR_vertexData_offsetof||0)+")",
    vertexStride: "u64("+(V.VkAccelerationStructureGeometryTrianglesDataKHR_vertexStride_offsetof||0)+")",
    maxVertex: "u32("+(V.VkAccelerationStructureGeometryTrianglesDataKHR_maxVertex_offsetof||0)+")",
    indexType: "u32("+(V.VkAccelerationStructureGeometryTrianglesDataKHR_indexType_offsetof||0)+")",
    indexData: "u32("+(V.VkAccelerationStructureGeometryTrianglesDataKHR_indexData_offsetof||0)+")",
    transformData: "u32("+(V.VkAccelerationStructureGeometryTrianglesDataKHR_transformData_offsetof||0)+")",
}, (V.VkAccelerationStructureGeometryTrianglesDataKHR_sizeof||0))));


const VkAccelerationStructureGeometryAabbsDataKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureGeometryAabbsDataKHR", {
    sType: "u32("+(V.VkAccelerationStructureGeometryAabbsDataKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureGeometryAabbsDataKHR_pNext_offsetof||0)+")",
    data: "u32("+(V.VkAccelerationStructureGeometryAabbsDataKHR_data_offsetof||0)+")",
    stride: "u64("+(V.VkAccelerationStructureGeometryAabbsDataKHR_stride_offsetof||0)+")",
}, (V.VkAccelerationStructureGeometryAabbsDataKHR_sizeof||0))));


const VkAccelerationStructureGeometryInstancesDataKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureGeometryInstancesDataKHR", {
    sType: "u32("+(V.VkAccelerationStructureGeometryInstancesDataKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureGeometryInstancesDataKHR_pNext_offsetof||0)+")",
    arrayOfPointers: "u32("+(V.VkAccelerationStructureGeometryInstancesDataKHR_arrayOfPointers_offsetof||0)+")",
    data: "u32("+(V.VkAccelerationStructureGeometryInstancesDataKHR_data_offsetof||0)+")",
}, (V.VkAccelerationStructureGeometryInstancesDataKHR_sizeof||0))));


const VkAccelerationStructureGeometryKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureGeometryKHR", {
    sType: "u32("+(V.VkAccelerationStructureGeometryKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureGeometryKHR_pNext_offsetof||0)+")",
    geometryType: "u32("+(V.VkAccelerationStructureGeometryKHR_geometryType_offsetof||0)+")",
    geometry: "u32("+(V.VkAccelerationStructureGeometryKHR_geometry_offsetof||0)+")",
    flags: "u32("+(V.VkAccelerationStructureGeometryKHR_flags_offsetof||0)+")",
}, (V.VkAccelerationStructureGeometryKHR_sizeof||0))));


const VkAccelerationStructureBuildGeometryInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureBuildGeometryInfoKHR", {
    sType: "u32("+(V.VkAccelerationStructureBuildGeometryInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureBuildGeometryInfoKHR_pNext_offsetof||0)+")",
    type: "u32("+(V.VkAccelerationStructureBuildGeometryInfoKHR_type_offsetof||0)+")",
    flags: "u32("+(V.VkAccelerationStructureBuildGeometryInfoKHR_flags_offsetof||0)+")",
    mode: "u32("+(V.VkAccelerationStructureBuildGeometryInfoKHR_mode_offsetof||0)+")",
    srcAccelerationStructure: "u64("+(V.VkAccelerationStructureBuildGeometryInfoKHR_srcAccelerationStructure_offsetof||0)+")",
    dstAccelerationStructure: "u64("+(V.VkAccelerationStructureBuildGeometryInfoKHR_dstAccelerationStructure_offsetof||0)+")",
    geometryCount: "u32("+(V.VkAccelerationStructureBuildGeometryInfoKHR_geometryCount_offsetof||0)+")",
    pGeometries: "u64("+(V.VkAccelerationStructureBuildGeometryInfoKHR_pGeometries_offsetof||0)+")",
    ppGeometries: "u64("+(V.VkAccelerationStructureBuildGeometryInfoKHR_ppGeometries_offsetof||0)+")",
    scratchData: "u64("+(V.VkAccelerationStructureBuildGeometryInfoKHR_scratchData_offsetof||0)+")",
}, (V.VkAccelerationStructureBuildGeometryInfoKHR_sizeof||0))));


const VkAccelerationStructureBuildRangeInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureBuildRangeInfoKHR", {
    primitiveCount: "u32("+(V.VkAccelerationStructureBuildRangeInfoKHR_primitiveCount_offsetof||0)+")",
    primitiveOffset: "u32("+(V.VkAccelerationStructureBuildRangeInfoKHR_primitiveOffset_offsetof||0)+")",
    firstVertex: "u32("+(V.VkAccelerationStructureBuildRangeInfoKHR_firstVertex_offsetof||0)+")",
    transformOffset: "u32("+(V.VkAccelerationStructureBuildRangeInfoKHR_transformOffset_offsetof||0)+")",
}, (V.VkAccelerationStructureBuildRangeInfoKHR_sizeof||0))));


const VkAccelerationStructureCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureCreateInfoKHR", {
    sType: "u32("+(V.VkAccelerationStructureCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureCreateInfoKHR_pNext_offsetof||0)+")",
    createFlags: "u32("+(V.VkAccelerationStructureCreateInfoKHR_createFlags_offsetof||0)+")",
    buffer: "u64("+(V.VkAccelerationStructureCreateInfoKHR_buffer_offsetof||0)+")",
    offset: "u64("+(V.VkAccelerationStructureCreateInfoKHR_offset_offsetof||0)+")",
    size: "u64("+(V.VkAccelerationStructureCreateInfoKHR_size_offsetof||0)+")",
    type: "u32("+(V.VkAccelerationStructureCreateInfoKHR_type_offsetof||0)+")",
    deviceAddress: "u64("+(V.VkAccelerationStructureCreateInfoKHR_deviceAddress_offsetof||0)+")",
}, (V.VkAccelerationStructureCreateInfoKHR_sizeof||0))));


const VkAabbPositionsKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAabbPositionsKHR", {
    minX: "f32("+(V.VkAabbPositionsKHR_minX_offsetof||0)+")",
    minY: "f32("+(V.VkAabbPositionsKHR_minY_offsetof||0)+")",
    minZ: "f32("+(V.VkAabbPositionsKHR_minZ_offsetof||0)+")",
    maxX: "f32("+(V.VkAabbPositionsKHR_maxX_offsetof||0)+")",
    maxY: "f32("+(V.VkAabbPositionsKHR_maxY_offsetof||0)+")",
    maxZ: "f32("+(V.VkAabbPositionsKHR_maxZ_offsetof||0)+")",
}, (V.VkAabbPositionsKHR_sizeof||0))));

const VkAabbPositionsNV = new Proxy(function(){}, new C.ConstructProxy("VkAabbPositionsKHR"));


const VkTransformMatrixKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkTransformMatrixKHR", {
    matrix: "u32(0)[12]",
}, (V.VkTransformMatrixKHR_sizeof||0))));    


const VkTransformMatrixNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkTransformMatrixNV", {
    matrix: "u32(0)[12]",
}, (V.VkTransformMatrixNV_sizeof||0))));    


const VkAccelerationStructureInstanceKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureInstanceKHR", {
    transform: "VkTransformMatrixKHR("+(V.VkAccelerationStructureInstanceKHR_transform_offsetof||0)+")",
    instanceCustomIndex: "u24("+(V.VkAccelerationStructureInstanceKHR_instanceCustomIndex_offsetof||0)+")",
    mask: "u8("+(V.VkAccelerationStructureInstanceKHR_mask_offsetof||0)+")",
    instanceShaderBindingTableRecordOffset: "u24("+(V.VkAccelerationStructureInstanceKHR_instanceShaderBindingTableRecordOffset_offsetof||0)+")",
    flags: "u8("+(V.VkAccelerationStructureInstanceKHR_flags_offsetof||0)+")",
    accelerationStructureReference: "u64("+(V.VkAccelerationStructureInstanceKHR_accelerationStructureReference_offsetof||0)+")",
}, (V.VkAccelerationStructureInstanceKHR_sizeof||0))));

const VkAccelerationStructureInstanceNV = new Proxy(function(){}, new C.ConstructProxy("VkAccelerationStructureInstanceKHR"));


const VkAccelerationStructureDeviceAddressInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureDeviceAddressInfoKHR", {
    sType: "u32("+(V.VkAccelerationStructureDeviceAddressInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureDeviceAddressInfoKHR_pNext_offsetof||0)+")",
    accelerationStructure: "u64("+(V.VkAccelerationStructureDeviceAddressInfoKHR_accelerationStructure_offsetof||0)+")",
}, (V.VkAccelerationStructureDeviceAddressInfoKHR_sizeof||0))));


const VkAccelerationStructureVersionInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureVersionInfoKHR", {
    sType: "u32("+(V.VkAccelerationStructureVersionInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureVersionInfoKHR_pNext_offsetof||0)+")",
    pVersionData: "u64("+(V.VkAccelerationStructureVersionInfoKHR_pVersionData_offsetof||0)+")",
}, (V.VkAccelerationStructureVersionInfoKHR_sizeof||0))));


const VkCopyAccelerationStructureInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyAccelerationStructureInfoKHR", {
    sType: "u32("+(V.VkCopyAccelerationStructureInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCopyAccelerationStructureInfoKHR_pNext_offsetof||0)+")",
    src: "u64("+(V.VkCopyAccelerationStructureInfoKHR_src_offsetof||0)+")",
    dst: "u64("+(V.VkCopyAccelerationStructureInfoKHR_dst_offsetof||0)+")",
    mode: "u32("+(V.VkCopyAccelerationStructureInfoKHR_mode_offsetof||0)+")",
}, (V.VkCopyAccelerationStructureInfoKHR_sizeof||0))));


const VkCopyAccelerationStructureToMemoryInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyAccelerationStructureToMemoryInfoKHR", {
    sType: "u32("+(V.VkCopyAccelerationStructureToMemoryInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCopyAccelerationStructureToMemoryInfoKHR_pNext_offsetof||0)+")",
    src: "u64("+(V.VkCopyAccelerationStructureToMemoryInfoKHR_src_offsetof||0)+")",
    dst: "u64("+(V.VkCopyAccelerationStructureToMemoryInfoKHR_dst_offsetof||0)+")",
    mode: "u32("+(V.VkCopyAccelerationStructureToMemoryInfoKHR_mode_offsetof||0)+")",
}, (V.VkCopyAccelerationStructureToMemoryInfoKHR_sizeof||0))));


const VkCopyMemoryToAccelerationStructureInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyMemoryToAccelerationStructureInfoKHR", {
    sType: "u32("+(V.VkCopyMemoryToAccelerationStructureInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCopyMemoryToAccelerationStructureInfoKHR_pNext_offsetof||0)+")",
    src: "u32("+(V.VkCopyMemoryToAccelerationStructureInfoKHR_src_offsetof||0)+")",
    dst: "u64("+(V.VkCopyMemoryToAccelerationStructureInfoKHR_dst_offsetof||0)+")",
    mode: "u32("+(V.VkCopyMemoryToAccelerationStructureInfoKHR_mode_offsetof||0)+")",
}, (V.VkCopyMemoryToAccelerationStructureInfoKHR_sizeof||0))));


const VkRayTracingPipelineInterfaceCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRayTracingPipelineInterfaceCreateInfoKHR", {
    sType: "u32("+(V.VkRayTracingPipelineInterfaceCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRayTracingPipelineInterfaceCreateInfoKHR_pNext_offsetof||0)+")",
    maxPipelineRayPayloadSize: "u32("+(V.VkRayTracingPipelineInterfaceCreateInfoKHR_maxPipelineRayPayloadSize_offsetof||0)+")",
    maxPipelineRayHitAttributeSize: "u32("+(V.VkRayTracingPipelineInterfaceCreateInfoKHR_maxPipelineRayHitAttributeSize_offsetof||0)+")",
}, (V.VkRayTracingPipelineInterfaceCreateInfoKHR_sizeof||0))));


const VkPipelineLibraryCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineLibraryCreateInfoKHR", {
    sType: "u32("+(V.VkPipelineLibraryCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineLibraryCreateInfoKHR_pNext_offsetof||0)+")",
    libraryCount: "u32("+(V.VkPipelineLibraryCreateInfoKHR_libraryCount_offsetof||0)+")",
    pLibraries: "u64("+(V.VkPipelineLibraryCreateInfoKHR_pLibraries_offsetof||0)+")",
}, (V.VkPipelineLibraryCreateInfoKHR_sizeof||0))));


const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceExtendedDynamicStateFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceExtendedDynamicStateFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceExtendedDynamicStateFeaturesEXT_pNext_offsetof||0)+")",
    extendedDynamicState: "u32("+(V.VkPhysicalDeviceExtendedDynamicStateFeaturesEXT_extendedDynamicState_offsetof||0)+")",
}, (V.VkPhysicalDeviceExtendedDynamicStateFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceExtendedDynamicState2FeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceExtendedDynamicState2FeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceExtendedDynamicState2FeaturesEXT_pNext_offsetof||0)+")",
    extendedDynamicState2: "u32("+(V.VkPhysicalDeviceExtendedDynamicState2FeaturesEXT_extendedDynamicState2_offsetof||0)+")",
    extendedDynamicState2LogicOp: "u32("+(V.VkPhysicalDeviceExtendedDynamicState2FeaturesEXT_extendedDynamicState2LogicOp_offsetof||0)+")",
    extendedDynamicState2PatchControlPoints: "u32("+(V.VkPhysicalDeviceExtendedDynamicState2FeaturesEXT_extendedDynamicState2PatchControlPoints_offsetof||0)+")",
}, (V.VkPhysicalDeviceExtendedDynamicState2FeaturesEXT_sizeof||0))));


const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_pNext_offsetof||0)+")",
    extendedDynamicState3TessellationDomainOrigin: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3TessellationDomainOrigin_offsetof||0)+")",
    extendedDynamicState3DepthClampEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3DepthClampEnable_offsetof||0)+")",
    extendedDynamicState3PolygonMode: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3PolygonMode_offsetof||0)+")",
    extendedDynamicState3RasterizationSamples: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3RasterizationSamples_offsetof||0)+")",
    extendedDynamicState3SampleMask: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3SampleMask_offsetof||0)+")",
    extendedDynamicState3AlphaToCoverageEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3AlphaToCoverageEnable_offsetof||0)+")",
    extendedDynamicState3AlphaToOneEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3AlphaToOneEnable_offsetof||0)+")",
    extendedDynamicState3LogicOpEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3LogicOpEnable_offsetof||0)+")",
    extendedDynamicState3ColorBlendEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ColorBlendEnable_offsetof||0)+")",
    extendedDynamicState3ColorBlendEquation: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ColorBlendEquation_offsetof||0)+")",
    extendedDynamicState3ColorWriteMask: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ColorWriteMask_offsetof||0)+")",
    extendedDynamicState3RasterizationStream: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3RasterizationStream_offsetof||0)+")",
    extendedDynamicState3ConservativeRasterizationMode: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ConservativeRasterizationMode_offsetof||0)+")",
    extendedDynamicState3ExtraPrimitiveOverestimationSize: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ExtraPrimitiveOverestimationSize_offsetof||0)+")",
    extendedDynamicState3DepthClipEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3DepthClipEnable_offsetof||0)+")",
    extendedDynamicState3SampleLocationsEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3SampleLocationsEnable_offsetof||0)+")",
    extendedDynamicState3ColorBlendAdvanced: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ColorBlendAdvanced_offsetof||0)+")",
    extendedDynamicState3ProvokingVertexMode: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ProvokingVertexMode_offsetof||0)+")",
    extendedDynamicState3LineRasterizationMode: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3LineRasterizationMode_offsetof||0)+")",
    extendedDynamicState3LineStippleEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3LineStippleEnable_offsetof||0)+")",
    extendedDynamicState3DepthClipNegativeOneToOne: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3DepthClipNegativeOneToOne_offsetof||0)+")",
    extendedDynamicState3ViewportWScalingEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ViewportWScalingEnable_offsetof||0)+")",
    extendedDynamicState3ViewportSwizzle: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ViewportSwizzle_offsetof||0)+")",
    extendedDynamicState3CoverageToColorEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3CoverageToColorEnable_offsetof||0)+")",
    extendedDynamicState3CoverageToColorLocation: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3CoverageToColorLocation_offsetof||0)+")",
    extendedDynamicState3CoverageModulationMode: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3CoverageModulationMode_offsetof||0)+")",
    extendedDynamicState3CoverageModulationTableEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3CoverageModulationTableEnable_offsetof||0)+")",
    extendedDynamicState3CoverageModulationTable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3CoverageModulationTable_offsetof||0)+")",
    extendedDynamicState3CoverageReductionMode: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3CoverageReductionMode_offsetof||0)+")",
    extendedDynamicState3RepresentativeFragmentTestEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3RepresentativeFragmentTestEnable_offsetof||0)+")",
    extendedDynamicState3ShadingRateImageEnable: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ShadingRateImageEnable_offsetof||0)+")",
}, (V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_sizeof||0))));


const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceExtendedDynamicState3PropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3PropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceExtendedDynamicState3PropertiesEXT_pNext_offsetof||0)+")",
    dynamicPrimitiveTopologyUnrestricted: "u32("+(V.VkPhysicalDeviceExtendedDynamicState3PropertiesEXT_dynamicPrimitiveTopologyUnrestricted_offsetof||0)+")",
}, (V.VkPhysicalDeviceExtendedDynamicState3PropertiesEXT_sizeof||0))));


const VkColorBlendEquationEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkColorBlendEquationEXT", {
    srcColorBlendFactor: "u32("+(V.VkColorBlendEquationEXT_srcColorBlendFactor_offsetof||0)+")",
    dstColorBlendFactor: "u32("+(V.VkColorBlendEquationEXT_dstColorBlendFactor_offsetof||0)+")",
    colorBlendOp: "u32("+(V.VkColorBlendEquationEXT_colorBlendOp_offsetof||0)+")",
    srcAlphaBlendFactor: "u32("+(V.VkColorBlendEquationEXT_srcAlphaBlendFactor_offsetof||0)+")",
    dstAlphaBlendFactor: "u32("+(V.VkColorBlendEquationEXT_dstAlphaBlendFactor_offsetof||0)+")",
    alphaBlendOp: "u32("+(V.VkColorBlendEquationEXT_alphaBlendOp_offsetof||0)+")",
}, (V.VkColorBlendEquationEXT_sizeof||0))));


const VkColorBlendAdvancedEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkColorBlendAdvancedEXT", {
    advancedBlendOp: "u32("+(V.VkColorBlendAdvancedEXT_advancedBlendOp_offsetof||0)+")",
    srcPremultiplied: "u32("+(V.VkColorBlendAdvancedEXT_srcPremultiplied_offsetof||0)+")",
    dstPremultiplied: "u32("+(V.VkColorBlendAdvancedEXT_dstPremultiplied_offsetof||0)+")",
    blendOverlap: "u32("+(V.VkColorBlendAdvancedEXT_blendOverlap_offsetof||0)+")",
    clampResults: "u32("+(V.VkColorBlendAdvancedEXT_clampResults_offsetof||0)+")",
}, (V.VkColorBlendAdvancedEXT_sizeof||0))));


const VkRenderPassTransformBeginInfoQCOM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassTransformBeginInfoQCOM", {
    sType: "u32("+(V.VkRenderPassTransformBeginInfoQCOM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderPassTransformBeginInfoQCOM_pNext_offsetof||0)+")",
    transform: "u32("+(V.VkRenderPassTransformBeginInfoQCOM_transform_offsetof||0)+")",
}, (V.VkRenderPassTransformBeginInfoQCOM_sizeof||0))));


const VkCopyCommandTransformInfoQCOM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyCommandTransformInfoQCOM", {
    sType: "u32("+(V.VkCopyCommandTransformInfoQCOM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCopyCommandTransformInfoQCOM_pNext_offsetof||0)+")",
    transform: "u32("+(V.VkCopyCommandTransformInfoQCOM_transform_offsetof||0)+")",
}, (V.VkCopyCommandTransformInfoQCOM_sizeof||0))));


const VkCommandBufferInheritanceRenderPassTransformInfoQCOM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCommandBufferInheritanceRenderPassTransformInfoQCOM", {
    sType: "u32("+(V.VkCommandBufferInheritanceRenderPassTransformInfoQCOM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCommandBufferInheritanceRenderPassTransformInfoQCOM_pNext_offsetof||0)+")",
    transform: "u32("+(V.VkCommandBufferInheritanceRenderPassTransformInfoQCOM_transform_offsetof||0)+")",
    renderArea: "VkRect2D("+(V.VkCommandBufferInheritanceRenderPassTransformInfoQCOM_renderArea_offsetof||0)+")",
}, (V.VkCommandBufferInheritanceRenderPassTransformInfoQCOM_sizeof||0))));


const VkPhysicalDeviceDiagnosticsConfigFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDiagnosticsConfigFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceDiagnosticsConfigFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDiagnosticsConfigFeaturesNV_pNext_offsetof||0)+")",
    diagnosticsConfig: "u32("+(V.VkPhysicalDeviceDiagnosticsConfigFeaturesNV_diagnosticsConfig_offsetof||0)+")",
}, (V.VkPhysicalDeviceDiagnosticsConfigFeaturesNV_sizeof||0))));


const VkDeviceDiagnosticsConfigCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceDiagnosticsConfigCreateInfoNV", {
    sType: "u32("+(V.VkDeviceDiagnosticsConfigCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceDiagnosticsConfigCreateInfoNV_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDeviceDiagnosticsConfigCreateInfoNV_flags_offsetof||0)+")",
}, (V.VkDeviceDiagnosticsConfigCreateInfoNV_sizeof||0))));


const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures_pNext_offsetof||0)+")",
    shaderZeroInitializeWorkgroupMemory: "u32("+(V.VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures_shaderZeroInitializeWorkgroupMemory_offsetof||0)+")",
}, (V.VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures_sizeof||0))));

const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures"));


const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR_pNext_offsetof||0)+")",
    shaderSubgroupUniformControlFlow: "u32("+(V.VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR_shaderSubgroupUniformControlFlow_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR_sizeof||0))));


const VkPhysicalDeviceRobustness2FeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRobustness2FeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceRobustness2FeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRobustness2FeaturesEXT_pNext_offsetof||0)+")",
    robustBufferAccess2: "u32("+(V.VkPhysicalDeviceRobustness2FeaturesEXT_robustBufferAccess2_offsetof||0)+")",
    robustImageAccess2: "u32("+(V.VkPhysicalDeviceRobustness2FeaturesEXT_robustImageAccess2_offsetof||0)+")",
    nullDescriptor: "u32("+(V.VkPhysicalDeviceRobustness2FeaturesEXT_nullDescriptor_offsetof||0)+")",
}, (V.VkPhysicalDeviceRobustness2FeaturesEXT_sizeof||0))));


const VkPhysicalDeviceRobustness2PropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRobustness2PropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceRobustness2PropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRobustness2PropertiesEXT_pNext_offsetof||0)+")",
    robustStorageBufferAccessSizeAlignment: "u64("+(V.VkPhysicalDeviceRobustness2PropertiesEXT_robustStorageBufferAccessSizeAlignment_offsetof||0)+")",
    robustUniformBufferAccessSizeAlignment: "u64("+(V.VkPhysicalDeviceRobustness2PropertiesEXT_robustUniformBufferAccessSizeAlignment_offsetof||0)+")",
}, (V.VkPhysicalDeviceRobustness2PropertiesEXT_sizeof||0))));


const VkPhysicalDeviceImageRobustnessFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceImageRobustnessFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceImageRobustnessFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceImageRobustnessFeatures_pNext_offsetof||0)+")",
    robustImageAccess: "u32("+(V.VkPhysicalDeviceImageRobustnessFeatures_robustImageAccess_offsetof||0)+")",
}, (V.VkPhysicalDeviceImageRobustnessFeatures_sizeof||0))));

const VkPhysicalDeviceImageRobustnessFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceImageRobustnessFeatures"));


const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_pNext_offsetof||0)+")",
    workgroupMemoryExplicitLayout: "u32("+(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_workgroupMemoryExplicitLayout_offsetof||0)+")",
    workgroupMemoryExplicitLayoutScalarBlockLayout: "u32("+(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_workgroupMemoryExplicitLayoutScalarBlockLayout_offsetof||0)+")",
    workgroupMemoryExplicitLayout8BitAccess: "u32("+(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_workgroupMemoryExplicitLayout8BitAccess_offsetof||0)+")",
    workgroupMemoryExplicitLayout16BitAccess: "u32("+(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_workgroupMemoryExplicitLayout16BitAccess_offsetof||0)+")",
}, (V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_sizeof||0))));


const VkPhysicalDevicePortabilitySubsetFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePortabilitySubsetFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_pNext_offsetof||0)+")",
    constantAlphaColorBlendFactors: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_constantAlphaColorBlendFactors_offsetof||0)+")",
    events: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_events_offsetof||0)+")",
    imageViewFormatReinterpretation: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_imageViewFormatReinterpretation_offsetof||0)+")",
    imageViewFormatSwizzle: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_imageViewFormatSwizzle_offsetof||0)+")",
    imageView2DOn3DImage: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_imageView2DOn3DImage_offsetof||0)+")",
    multisampleArrayImage: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_multisampleArrayImage_offsetof||0)+")",
    mutableComparisonSamplers: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_mutableComparisonSamplers_offsetof||0)+")",
    pointPolygons: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_pointPolygons_offsetof||0)+")",
    samplerMipLodBias: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_samplerMipLodBias_offsetof||0)+")",
    separateStencilMaskRef: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_separateStencilMaskRef_offsetof||0)+")",
    shaderSampleRateInterpolationFunctions: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_shaderSampleRateInterpolationFunctions_offsetof||0)+")",
    tessellationIsolines: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_tessellationIsolines_offsetof||0)+")",
    tessellationPointMode: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_tessellationPointMode_offsetof||0)+")",
    triangleFans: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_triangleFans_offsetof||0)+")",
    vertexAttributeAccessBeyondStride: "u32("+(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_vertexAttributeAccessBeyondStride_offsetof||0)+")",
}, (V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_sizeof||0))));


const VkPhysicalDevicePortabilitySubsetPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePortabilitySubsetPropertiesKHR", {
    sType: "u32("+(V.VkPhysicalDevicePortabilitySubsetPropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePortabilitySubsetPropertiesKHR_pNext_offsetof||0)+")",
    minVertexInputBindingStrideAlignment: "u32("+(V.VkPhysicalDevicePortabilitySubsetPropertiesKHR_minVertexInputBindingStrideAlignment_offsetof||0)+")",
}, (V.VkPhysicalDevicePortabilitySubsetPropertiesKHR_sizeof||0))));


const VkPhysicalDevice4444FormatsFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevice4444FormatsFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDevice4444FormatsFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevice4444FormatsFeaturesEXT_pNext_offsetof||0)+")",
    formatA4R4G4B4: "u32("+(V.VkPhysicalDevice4444FormatsFeaturesEXT_formatA4R4G4B4_offsetof||0)+")",
    formatA4B4G4R4: "u32("+(V.VkPhysicalDevice4444FormatsFeaturesEXT_formatA4B4G4R4_offsetof||0)+")",
}, (V.VkPhysicalDevice4444FormatsFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceSubpassShadingFeaturesHUAWEI = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSubpassShadingFeaturesHUAWEI", {
    sType: "u32("+(V.VkPhysicalDeviceSubpassShadingFeaturesHUAWEI_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSubpassShadingFeaturesHUAWEI_pNext_offsetof||0)+")",
    subpassShading: "u32("+(V.VkPhysicalDeviceSubpassShadingFeaturesHUAWEI_subpassShading_offsetof||0)+")",
}, (V.VkPhysicalDeviceSubpassShadingFeaturesHUAWEI_sizeof||0))));


const VkBufferCopy2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferCopy2", {
    sType: "u32("+(V.VkBufferCopy2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferCopy2_pNext_offsetof||0)+")",
    srcOffset: "u64("+(V.VkBufferCopy2_srcOffset_offsetof||0)+")",
    dstOffset: "u64("+(V.VkBufferCopy2_dstOffset_offsetof||0)+")",
    size: "u64("+(V.VkBufferCopy2_size_offsetof||0)+")",
}, (V.VkBufferCopy2_sizeof||0))));

const VkBufferCopy2KHR = new Proxy(function(){}, new C.ConstructProxy("VkBufferCopy2"));


const VkImageCopy2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageCopy2", {
    sType: "u32("+(V.VkImageCopy2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageCopy2_pNext_offsetof||0)+")",
    srcSubresource: "u32("+(V.VkImageCopy2_srcSubresource_offsetof||0)+")",
    srcOffset: "u32("+(V.VkImageCopy2_srcOffset_offsetof||0)+")",
    dstSubresource: "u32("+(V.VkImageCopy2_dstSubresource_offsetof||0)+")",
    dstOffset: "u32("+(V.VkImageCopy2_dstOffset_offsetof||0)+")",
    extent: "u32("+(V.VkImageCopy2_extent_offsetof||0)+")",
}, (V.VkImageCopy2_sizeof||0))));

const VkImageCopy2KHR = new Proxy(function(){}, new C.ConstructProxy("VkImageCopy2"));


const VkImageBlit2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageBlit2", {
    sType: "u32("+(V.VkImageBlit2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageBlit2_pNext_offsetof||0)+")",
    srcSubresource: "u32("+(V.VkImageBlit2_srcSubresource_offsetof||0)+")",
    srcOffsets: "u32[2]("+(V.VkImageBlit2_srcOffsets_offsetof||0)+")",
    dstSubresource: "u32("+(V.VkImageBlit2_dstSubresource_offsetof||0)+")",
    dstOffsets: "u32[2]("+(V.VkImageBlit2_dstOffsets_offsetof||0)+")",
}, (V.VkImageBlit2_sizeof||0))));

const VkImageBlit2KHR = new Proxy(function(){}, new C.ConstructProxy("VkImageBlit2"));


const VkBufferImageCopy2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferImageCopy2", {
    sType: "u32("+(V.VkBufferImageCopy2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferImageCopy2_pNext_offsetof||0)+")",
    bufferOffset: "u64("+(V.VkBufferImageCopy2_bufferOffset_offsetof||0)+")",
    bufferRowLength: "u32("+(V.VkBufferImageCopy2_bufferRowLength_offsetof||0)+")",
    bufferImageHeight: "u32("+(V.VkBufferImageCopy2_bufferImageHeight_offsetof||0)+")",
    imageSubresource: "u32("+(V.VkBufferImageCopy2_imageSubresource_offsetof||0)+")",
    imageOffset: "u32("+(V.VkBufferImageCopy2_imageOffset_offsetof||0)+")",
    imageExtent: "u32("+(V.VkBufferImageCopy2_imageExtent_offsetof||0)+")",
}, (V.VkBufferImageCopy2_sizeof||0))));

const VkBufferImageCopy2KHR = new Proxy(function(){}, new C.ConstructProxy("VkBufferImageCopy2"));


const VkImageResolve2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageResolve2", {
    sType: "u32("+(V.VkImageResolve2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageResolve2_pNext_offsetof||0)+")",
    srcSubresource: "u32("+(V.VkImageResolve2_srcSubresource_offsetof||0)+")",
    srcOffset: "u32("+(V.VkImageResolve2_srcOffset_offsetof||0)+")",
    dstSubresource: "u32("+(V.VkImageResolve2_dstSubresource_offsetof||0)+")",
    dstOffset: "u32("+(V.VkImageResolve2_dstOffset_offsetof||0)+")",
    extent: "u32("+(V.VkImageResolve2_extent_offsetof||0)+")",
}, (V.VkImageResolve2_sizeof||0))));

const VkImageResolve2KHR = new Proxy(function(){}, new C.ConstructProxy("VkImageResolve2"));


const VkCopyBufferInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyBufferInfo2", {
    sType: "u32("+(V.VkCopyBufferInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCopyBufferInfo2_pNext_offsetof||0)+")",
    srcBuffer: "u64("+(V.VkCopyBufferInfo2_srcBuffer_offsetof||0)+")",
    dstBuffer: "u64("+(V.VkCopyBufferInfo2_dstBuffer_offsetof||0)+")",
    regionCount: "u32("+(V.VkCopyBufferInfo2_regionCount_offsetof||0)+")",
    pRegions: "u64("+(V.VkCopyBufferInfo2_pRegions_offsetof||0)+")",
}, (V.VkCopyBufferInfo2_sizeof||0))));

const VkCopyBufferInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkCopyBufferInfo2"));


const VkCopyImageInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyImageInfo2", {
    sType: "u32("+(V.VkCopyImageInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCopyImageInfo2_pNext_offsetof||0)+")",
    srcImage: "u64("+(V.VkCopyImageInfo2_srcImage_offsetof||0)+")",
    srcImageLayout: "u32("+(V.VkCopyImageInfo2_srcImageLayout_offsetof||0)+")",
    dstImage: "u64("+(V.VkCopyImageInfo2_dstImage_offsetof||0)+")",
    dstImageLayout: "u32("+(V.VkCopyImageInfo2_dstImageLayout_offsetof||0)+")",
    regionCount: "u32("+(V.VkCopyImageInfo2_regionCount_offsetof||0)+")",
    pRegions: "u64("+(V.VkCopyImageInfo2_pRegions_offsetof||0)+")",
}, (V.VkCopyImageInfo2_sizeof||0))));

const VkCopyImageInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkCopyImageInfo2"));


const VkBlitImageInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBlitImageInfo2", {
    sType: "u32("+(V.VkBlitImageInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBlitImageInfo2_pNext_offsetof||0)+")",
    srcImage: "u64("+(V.VkBlitImageInfo2_srcImage_offsetof||0)+")",
    srcImageLayout: "u32("+(V.VkBlitImageInfo2_srcImageLayout_offsetof||0)+")",
    dstImage: "u64("+(V.VkBlitImageInfo2_dstImage_offsetof||0)+")",
    dstImageLayout: "u32("+(V.VkBlitImageInfo2_dstImageLayout_offsetof||0)+")",
    regionCount: "u32("+(V.VkBlitImageInfo2_regionCount_offsetof||0)+")",
    pRegions: "u64("+(V.VkBlitImageInfo2_pRegions_offsetof||0)+")",
    filter: "u32("+(V.VkBlitImageInfo2_filter_offsetof||0)+")",
}, (V.VkBlitImageInfo2_sizeof||0))));

const VkBlitImageInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkBlitImageInfo2"));


const VkCopyBufferToImageInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyBufferToImageInfo2", {
    sType: "u32("+(V.VkCopyBufferToImageInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCopyBufferToImageInfo2_pNext_offsetof||0)+")",
    srcBuffer: "u64("+(V.VkCopyBufferToImageInfo2_srcBuffer_offsetof||0)+")",
    dstImage: "u64("+(V.VkCopyBufferToImageInfo2_dstImage_offsetof||0)+")",
    dstImageLayout: "u32("+(V.VkCopyBufferToImageInfo2_dstImageLayout_offsetof||0)+")",
    regionCount: "u32("+(V.VkCopyBufferToImageInfo2_regionCount_offsetof||0)+")",
    pRegions: "u64("+(V.VkCopyBufferToImageInfo2_pRegions_offsetof||0)+")",
}, (V.VkCopyBufferToImageInfo2_sizeof||0))));

const VkCopyBufferToImageInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkCopyBufferToImageInfo2"));


const VkCopyImageToBufferInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyImageToBufferInfo2", {
    sType: "u32("+(V.VkCopyImageToBufferInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCopyImageToBufferInfo2_pNext_offsetof||0)+")",
    srcImage: "u64("+(V.VkCopyImageToBufferInfo2_srcImage_offsetof||0)+")",
    srcImageLayout: "u32("+(V.VkCopyImageToBufferInfo2_srcImageLayout_offsetof||0)+")",
    dstBuffer: "u64("+(V.VkCopyImageToBufferInfo2_dstBuffer_offsetof||0)+")",
    regionCount: "u32("+(V.VkCopyImageToBufferInfo2_regionCount_offsetof||0)+")",
    pRegions: "u64("+(V.VkCopyImageToBufferInfo2_pRegions_offsetof||0)+")",
}, (V.VkCopyImageToBufferInfo2_sizeof||0))));

const VkCopyImageToBufferInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkCopyImageToBufferInfo2"));


const VkResolveImageInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkResolveImageInfo2", {
    sType: "u32("+(V.VkResolveImageInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkResolveImageInfo2_pNext_offsetof||0)+")",
    srcImage: "u64("+(V.VkResolveImageInfo2_srcImage_offsetof||0)+")",
    srcImageLayout: "u32("+(V.VkResolveImageInfo2_srcImageLayout_offsetof||0)+")",
    dstImage: "u64("+(V.VkResolveImageInfo2_dstImage_offsetof||0)+")",
    dstImageLayout: "u32("+(V.VkResolveImageInfo2_dstImageLayout_offsetof||0)+")",
    regionCount: "u32("+(V.VkResolveImageInfo2_regionCount_offsetof||0)+")",
    pRegions: "u64("+(V.VkResolveImageInfo2_pRegions_offsetof||0)+")",
}, (V.VkResolveImageInfo2_sizeof||0))));

const VkResolveImageInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkResolveImageInfo2"));


const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT_pNext_offsetof||0)+")",
    shaderImageInt64Atomics: "u32("+(V.VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT_shaderImageInt64Atomics_offsetof||0)+")",
    sparseImageInt64Atomics: "u32("+(V.VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT_sparseImageInt64Atomics_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT_sizeof||0))));


const VkFragmentShadingRateAttachmentInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkFragmentShadingRateAttachmentInfoKHR", {
    sType: "u32("+(V.VkFragmentShadingRateAttachmentInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkFragmentShadingRateAttachmentInfoKHR_pNext_offsetof||0)+")",
    pFragmentShadingRateAttachment: "u64("+(V.VkFragmentShadingRateAttachmentInfoKHR_pFragmentShadingRateAttachment_offsetof||0)+")",
    shadingRateAttachmentTexelSize: "VkExtent2D("+(V.VkFragmentShadingRateAttachmentInfoKHR_shadingRateAttachmentTexelSize_offsetof||0)+")",
}, (V.VkFragmentShadingRateAttachmentInfoKHR_sizeof||0))));


const VkPipelineFragmentShadingRateStateCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineFragmentShadingRateStateCreateInfoKHR", {
    sType: "u32("+(V.VkPipelineFragmentShadingRateStateCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineFragmentShadingRateStateCreateInfoKHR_pNext_offsetof||0)+")",
    fragmentSize: "VkExtent2D("+(V.VkPipelineFragmentShadingRateStateCreateInfoKHR_fragmentSize_offsetof||0)+")",
    combinerOps: "u32[2]("+(V.VkPipelineFragmentShadingRateStateCreateInfoKHR_combinerOps_offsetof||0)+")",
}, (V.VkPipelineFragmentShadingRateStateCreateInfoKHR_sizeof||0))));


const VkPhysicalDeviceFragmentShadingRateFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentShadingRateFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentShadingRateFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentShadingRateFeaturesKHR_pNext_offsetof||0)+")",
    pipelineFragmentShadingRate: "u32("+(V.VkPhysicalDeviceFragmentShadingRateFeaturesKHR_pipelineFragmentShadingRate_offsetof||0)+")",
    primitiveFragmentShadingRate: "u32("+(V.VkPhysicalDeviceFragmentShadingRateFeaturesKHR_primitiveFragmentShadingRate_offsetof||0)+")",
    attachmentFragmentShadingRate: "u32("+(V.VkPhysicalDeviceFragmentShadingRateFeaturesKHR_attachmentFragmentShadingRate_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentShadingRateFeaturesKHR_sizeof||0))));


const VkPhysicalDeviceFragmentShadingRatePropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentShadingRatePropertiesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_pNext_offsetof||0)+")",
    minFragmentShadingRateAttachmentTexelSize: "VkExtent2D("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_minFragmentShadingRateAttachmentTexelSize_offsetof||0)+")",
    maxFragmentShadingRateAttachmentTexelSize: "VkExtent2D("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_maxFragmentShadingRateAttachmentTexelSize_offsetof||0)+")",
    maxFragmentShadingRateAttachmentTexelSizeAspectRatio: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_maxFragmentShadingRateAttachmentTexelSizeAspectRatio_offsetof||0)+")",
    primitiveFragmentShadingRateWithMultipleViewports: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_primitiveFragmentShadingRateWithMultipleViewports_offsetof||0)+")",
    layeredShadingRateAttachments: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_layeredShadingRateAttachments_offsetof||0)+")",
    fragmentShadingRateNonTrivialCombinerOps: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateNonTrivialCombinerOps_offsetof||0)+")",
    maxFragmentSize: "VkExtent2D("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_maxFragmentSize_offsetof||0)+")",
    maxFragmentSizeAspectRatio: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_maxFragmentSizeAspectRatio_offsetof||0)+")",
    maxFragmentShadingRateCoverageSamples: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_maxFragmentShadingRateCoverageSamples_offsetof||0)+")",
    maxFragmentShadingRateRasterizationSamples: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_maxFragmentShadingRateRasterizationSamples_offsetof||0)+")",
    fragmentShadingRateWithShaderDepthStencilWrites: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateWithShaderDepthStencilWrites_offsetof||0)+")",
    fragmentShadingRateWithSampleMask: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateWithSampleMask_offsetof||0)+")",
    fragmentShadingRateWithShaderSampleMask: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateWithShaderSampleMask_offsetof||0)+")",
    fragmentShadingRateWithConservativeRasterization: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateWithConservativeRasterization_offsetof||0)+")",
    fragmentShadingRateWithFragmentShaderInterlock: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateWithFragmentShaderInterlock_offsetof||0)+")",
    fragmentShadingRateWithCustomSampleLocations: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateWithCustomSampleLocations_offsetof||0)+")",
    fragmentShadingRateStrictMultiplyCombiner: "u32("+(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateStrictMultiplyCombiner_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_sizeof||0))));


const VkPhysicalDeviceFragmentShadingRateKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentShadingRateKHR", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentShadingRateKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentShadingRateKHR_pNext_offsetof||0)+")",
    sampleCounts: "u32("+(V.VkPhysicalDeviceFragmentShadingRateKHR_sampleCounts_offsetof||0)+")",
    fragmentSize: "VkExtent2D("+(V.VkPhysicalDeviceFragmentShadingRateKHR_fragmentSize_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentShadingRateKHR_sizeof||0))));


const VkPhysicalDeviceShaderTerminateInvocationFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderTerminateInvocationFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceShaderTerminateInvocationFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderTerminateInvocationFeatures_pNext_offsetof||0)+")",
    shaderTerminateInvocation: "u32("+(V.VkPhysicalDeviceShaderTerminateInvocationFeatures_shaderTerminateInvocation_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderTerminateInvocationFeatures_sizeof||0))));

const VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceShaderTerminateInvocationFeatures"));


const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_pNext_offsetof||0)+")",
    fragmentShadingRateEnums: "u32("+(V.VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_fragmentShadingRateEnums_offsetof||0)+")",
    supersampleFragmentShadingRates: "u32("+(V.VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_supersampleFragmentShadingRates_offsetof||0)+")",
    noInvocationFragmentShadingRates: "u32("+(V.VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_noInvocationFragmentShadingRates_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_sizeof||0))));


const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV_pNext_offsetof||0)+")",
    maxFragmentShadingRateInvocationCount: "u32("+(V.VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV_maxFragmentShadingRateInvocationCount_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV_sizeof||0))));


const VkPipelineFragmentShadingRateEnumStateCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineFragmentShadingRateEnumStateCreateInfoNV", {
    sType: "u32("+(V.VkPipelineFragmentShadingRateEnumStateCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineFragmentShadingRateEnumStateCreateInfoNV_pNext_offsetof||0)+")",
    shadingRateType: "u32("+(V.VkPipelineFragmentShadingRateEnumStateCreateInfoNV_shadingRateType_offsetof||0)+")",
    shadingRate: "u32("+(V.VkPipelineFragmentShadingRateEnumStateCreateInfoNV_shadingRate_offsetof||0)+")",
    combinerOps: "u32[2]("+(V.VkPipelineFragmentShadingRateEnumStateCreateInfoNV_combinerOps_offsetof||0)+")",
}, (V.VkPipelineFragmentShadingRateEnumStateCreateInfoNV_sizeof||0))));


const VkAccelerationStructureBuildSizesInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureBuildSizesInfoKHR", {
    sType: "u32("+(V.VkAccelerationStructureBuildSizesInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureBuildSizesInfoKHR_pNext_offsetof||0)+")",
    accelerationStructureSize: "u64("+(V.VkAccelerationStructureBuildSizesInfoKHR_accelerationStructureSize_offsetof||0)+")",
    updateScratchSize: "u64("+(V.VkAccelerationStructureBuildSizesInfoKHR_updateScratchSize_offsetof||0)+")",
    buildScratchSize: "u64("+(V.VkAccelerationStructureBuildSizesInfoKHR_buildScratchSize_offsetof||0)+")",
}, (V.VkAccelerationStructureBuildSizesInfoKHR_sizeof||0))));


const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceImage2DViewOf3DFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceImage2DViewOf3DFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceImage2DViewOf3DFeaturesEXT_pNext_offsetof||0)+")",
    image2DViewOf3D: "u32("+(V.VkPhysicalDeviceImage2DViewOf3DFeaturesEXT_image2DViewOf3D_offsetof||0)+")",
    sampler2DViewOf3D: "u32("+(V.VkPhysicalDeviceImage2DViewOf3DFeaturesEXT_sampler2DViewOf3D_offsetof||0)+")",
}, (V.VkPhysicalDeviceImage2DViewOf3DFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT_pNext_offsetof||0)+")",
    mutableDescriptorType: "u32("+(V.VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT_mutableDescriptorType_offsetof||0)+")",
}, (V.VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT_sizeof||0))));

const VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT"));


const VkMutableDescriptorTypeListEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMutableDescriptorTypeListEXT", {
    descriptorTypeCount: "u32("+(V.VkMutableDescriptorTypeListEXT_descriptorTypeCount_offsetof||0)+")",
    pDescriptorTypes: "u64("+(V.VkMutableDescriptorTypeListEXT_pDescriptorTypes_offsetof||0)+")",
}, (V.VkMutableDescriptorTypeListEXT_sizeof||0))));

const VkMutableDescriptorTypeListVALVE = new Proxy(function(){}, new C.ConstructProxy("VkMutableDescriptorTypeListEXT"));


const VkMutableDescriptorTypeCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMutableDescriptorTypeCreateInfoEXT", {
    sType: "u32("+(V.VkMutableDescriptorTypeCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMutableDescriptorTypeCreateInfoEXT_pNext_offsetof||0)+")",
    mutableDescriptorTypeListCount: "u32("+(V.VkMutableDescriptorTypeCreateInfoEXT_mutableDescriptorTypeListCount_offsetof||0)+")",
    pMutableDescriptorTypeLists: "u64("+(V.VkMutableDescriptorTypeCreateInfoEXT_pMutableDescriptorTypeLists_offsetof||0)+")",
}, (V.VkMutableDescriptorTypeCreateInfoEXT_sizeof||0))));

const VkMutableDescriptorTypeCreateInfoVALVE = new Proxy(function(){}, new C.ConstructProxy("VkMutableDescriptorTypeCreateInfoEXT"));


const VkPhysicalDeviceDepthClipControlFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDepthClipControlFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceDepthClipControlFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDepthClipControlFeaturesEXT_pNext_offsetof||0)+")",
    depthClipControl: "u32("+(V.VkPhysicalDeviceDepthClipControlFeaturesEXT_depthClipControl_offsetof||0)+")",
}, (V.VkPhysicalDeviceDepthClipControlFeaturesEXT_sizeof||0))));


const VkPipelineViewportDepthClipControlCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineViewportDepthClipControlCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineViewportDepthClipControlCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineViewportDepthClipControlCreateInfoEXT_pNext_offsetof||0)+")",
    negativeOneToOne: "u32("+(V.VkPipelineViewportDepthClipControlCreateInfoEXT_negativeOneToOne_offsetof||0)+")",
}, (V.VkPipelineViewportDepthClipControlCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT_pNext_offsetof||0)+")",
    vertexInputDynamicState: "u32("+(V.VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT_vertexInputDynamicState_offsetof||0)+")",
}, (V.VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceExternalMemoryRDMAFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceExternalMemoryRDMAFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceExternalMemoryRDMAFeaturesNV_pNext_offsetof||0)+")",
    externalMemoryRDMA: "u32("+(V.VkPhysicalDeviceExternalMemoryRDMAFeaturesNV_externalMemoryRDMA_offsetof||0)+")",
}, (V.VkPhysicalDeviceExternalMemoryRDMAFeaturesNV_sizeof||0))));


const VkVertexInputBindingDescription2EXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVertexInputBindingDescription2EXT", {
    sType: "u32("+(V.VkVertexInputBindingDescription2EXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVertexInputBindingDescription2EXT_pNext_offsetof||0)+")",
    binding: "u32("+(V.VkVertexInputBindingDescription2EXT_binding_offsetof||0)+")",
    stride: "u32("+(V.VkVertexInputBindingDescription2EXT_stride_offsetof||0)+")",
    inputRate: "u32("+(V.VkVertexInputBindingDescription2EXT_inputRate_offsetof||0)+")",
    divisor: "u32("+(V.VkVertexInputBindingDescription2EXT_divisor_offsetof||0)+")",
}, (V.VkVertexInputBindingDescription2EXT_sizeof||0))));


const VkVertexInputAttributeDescription2EXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVertexInputAttributeDescription2EXT", {
    sType: "u32("+(V.VkVertexInputAttributeDescription2EXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVertexInputAttributeDescription2EXT_pNext_offsetof||0)+")",
    location: "u32("+(V.VkVertexInputAttributeDescription2EXT_location_offsetof||0)+")",
    binding: "u32("+(V.VkVertexInputAttributeDescription2EXT_binding_offsetof||0)+")",
    format: "u32("+(V.VkVertexInputAttributeDescription2EXT_format_offsetof||0)+")",
    offset: "u32("+(V.VkVertexInputAttributeDescription2EXT_offset_offsetof||0)+")",
}, (V.VkVertexInputAttributeDescription2EXT_sizeof||0))));


const VkPhysicalDeviceColorWriteEnableFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceColorWriteEnableFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceColorWriteEnableFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceColorWriteEnableFeaturesEXT_pNext_offsetof||0)+")",
    colorWriteEnable: "u32("+(V.VkPhysicalDeviceColorWriteEnableFeaturesEXT_colorWriteEnable_offsetof||0)+")",
}, (V.VkPhysicalDeviceColorWriteEnableFeaturesEXT_sizeof||0))));


const VkPipelineColorWriteCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineColorWriteCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineColorWriteCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineColorWriteCreateInfoEXT_pNext_offsetof||0)+")",
    attachmentCount: "u32("+(V.VkPipelineColorWriteCreateInfoEXT_attachmentCount_offsetof||0)+")",
    pColorWriteEnables: "u64("+(V.VkPipelineColorWriteCreateInfoEXT_pColorWriteEnables_offsetof||0)+")",
}, (V.VkPipelineColorWriteCreateInfoEXT_sizeof||0))));


const VkMemoryBarrier2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryBarrier2", {
    sType: "u32("+(V.VkMemoryBarrier2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryBarrier2_pNext_offsetof||0)+")",
    srcStageMask: "u64("+(V.VkMemoryBarrier2_srcStageMask_offsetof||0)+")",
    srcAccessMask: "u64("+(V.VkMemoryBarrier2_srcAccessMask_offsetof||0)+")",
    dstStageMask: "u64("+(V.VkMemoryBarrier2_dstStageMask_offsetof||0)+")",
    dstAccessMask: "u64("+(V.VkMemoryBarrier2_dstAccessMask_offsetof||0)+")",
}, (V.VkMemoryBarrier2_sizeof||0))));

const VkMemoryBarrier2KHR = new Proxy(function(){}, new C.ConstructProxy("VkMemoryBarrier2"));


const VkImageMemoryBarrier2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageMemoryBarrier2", {
    sType: "u32("+(V.VkImageMemoryBarrier2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageMemoryBarrier2_pNext_offsetof||0)+")",
    srcStageMask: "u64("+(V.VkImageMemoryBarrier2_srcStageMask_offsetof||0)+")",
    srcAccessMask: "u64("+(V.VkImageMemoryBarrier2_srcAccessMask_offsetof||0)+")",
    dstStageMask: "u64("+(V.VkImageMemoryBarrier2_dstStageMask_offsetof||0)+")",
    dstAccessMask: "u64("+(V.VkImageMemoryBarrier2_dstAccessMask_offsetof||0)+")",
    oldLayout: "u32("+(V.VkImageMemoryBarrier2_oldLayout_offsetof||0)+")",
    newLayout: "u32("+(V.VkImageMemoryBarrier2_newLayout_offsetof||0)+")",
    srcQueueFamilyIndex: "u32("+(V.VkImageMemoryBarrier2_srcQueueFamilyIndex_offsetof||0)+")",
    dstQueueFamilyIndex: "u32("+(V.VkImageMemoryBarrier2_dstQueueFamilyIndex_offsetof||0)+")",
    image: "u64("+(V.VkImageMemoryBarrier2_image_offsetof||0)+")",
    subresourceRange: "u32("+(V.VkImageMemoryBarrier2_subresourceRange_offsetof||0)+")",
}, (V.VkImageMemoryBarrier2_sizeof||0))));

const VkImageMemoryBarrier2KHR = new Proxy(function(){}, new C.ConstructProxy("VkImageMemoryBarrier2"));


const VkBufferMemoryBarrier2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferMemoryBarrier2", {
    sType: "u32("+(V.VkBufferMemoryBarrier2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferMemoryBarrier2_pNext_offsetof||0)+")",
    srcStageMask: "u64("+(V.VkBufferMemoryBarrier2_srcStageMask_offsetof||0)+")",
    srcAccessMask: "u64("+(V.VkBufferMemoryBarrier2_srcAccessMask_offsetof||0)+")",
    dstStageMask: "u64("+(V.VkBufferMemoryBarrier2_dstStageMask_offsetof||0)+")",
    dstAccessMask: "u64("+(V.VkBufferMemoryBarrier2_dstAccessMask_offsetof||0)+")",
    srcQueueFamilyIndex: "u32("+(V.VkBufferMemoryBarrier2_srcQueueFamilyIndex_offsetof||0)+")",
    dstQueueFamilyIndex: "u32("+(V.VkBufferMemoryBarrier2_dstQueueFamilyIndex_offsetof||0)+")",
    buffer: "u64("+(V.VkBufferMemoryBarrier2_buffer_offsetof||0)+")",
    offset: "u64("+(V.VkBufferMemoryBarrier2_offset_offsetof||0)+")",
    size: "u64("+(V.VkBufferMemoryBarrier2_size_offsetof||0)+")",
}, (V.VkBufferMemoryBarrier2_sizeof||0))));

const VkBufferMemoryBarrier2KHR = new Proxy(function(){}, new C.ConstructProxy("VkBufferMemoryBarrier2"));


const VkDependencyInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDependencyInfo", {
    sType: "u32("+(V.VkDependencyInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDependencyInfo_pNext_offsetof||0)+")",
    dependencyFlags: "u32("+(V.VkDependencyInfo_dependencyFlags_offsetof||0)+")",
    memoryBarrierCount: "u32("+(V.VkDependencyInfo_memoryBarrierCount_offsetof||0)+")",
    pMemoryBarriers: "u64("+(V.VkDependencyInfo_pMemoryBarriers_offsetof||0)+")",
    bufferMemoryBarrierCount: "u32("+(V.VkDependencyInfo_bufferMemoryBarrierCount_offsetof||0)+")",
    pBufferMemoryBarriers: "u64("+(V.VkDependencyInfo_pBufferMemoryBarriers_offsetof||0)+")",
    imageMemoryBarrierCount: "u32("+(V.VkDependencyInfo_imageMemoryBarrierCount_offsetof||0)+")",
    pImageMemoryBarriers: "u64("+(V.VkDependencyInfo_pImageMemoryBarriers_offsetof||0)+")",
}, (V.VkDependencyInfo_sizeof||0))));

const VkDependencyInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkDependencyInfo"));


const VkSemaphoreSubmitInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSemaphoreSubmitInfo", {
    sType: "u32("+(V.VkSemaphoreSubmitInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSemaphoreSubmitInfo_pNext_offsetof||0)+")",
    semaphore: "u64("+(V.VkSemaphoreSubmitInfo_semaphore_offsetof||0)+")",
    value: "u64("+(V.VkSemaphoreSubmitInfo_value_offsetof||0)+")",
    stageMask: "u64("+(V.VkSemaphoreSubmitInfo_stageMask_offsetof||0)+")",
    deviceIndex: "u32("+(V.VkSemaphoreSubmitInfo_deviceIndex_offsetof||0)+")",
}, (V.VkSemaphoreSubmitInfo_sizeof||0))));

const VkSemaphoreSubmitInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkSemaphoreSubmitInfo"));


const VkCommandBufferSubmitInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCommandBufferSubmitInfo", {
    sType: "u32("+(V.VkCommandBufferSubmitInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCommandBufferSubmitInfo_pNext_offsetof||0)+")",
    commandBuffer: "u64("+(V.VkCommandBufferSubmitInfo_commandBuffer_offsetof||0)+")",
    deviceMask: "u32("+(V.VkCommandBufferSubmitInfo_deviceMask_offsetof||0)+")",
}, (V.VkCommandBufferSubmitInfo_sizeof||0))));

const VkCommandBufferSubmitInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkCommandBufferSubmitInfo"));


const VkSubmitInfo2 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubmitInfo2", {
    sType: "u32("+(V.VkSubmitInfo2_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSubmitInfo2_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkSubmitInfo2_flags_offsetof||0)+")",
    waitSemaphoreInfoCount: "u32("+(V.VkSubmitInfo2_waitSemaphoreInfoCount_offsetof||0)+")",
    pWaitSemaphoreInfos: "u64("+(V.VkSubmitInfo2_pWaitSemaphoreInfos_offsetof||0)+")",
    commandBufferInfoCount: "u32("+(V.VkSubmitInfo2_commandBufferInfoCount_offsetof||0)+")",
    pCommandBufferInfos: "u64("+(V.VkSubmitInfo2_pCommandBufferInfos_offsetof||0)+")",
    signalSemaphoreInfoCount: "u32("+(V.VkSubmitInfo2_signalSemaphoreInfoCount_offsetof||0)+")",
    pSignalSemaphoreInfos: "u64("+(V.VkSubmitInfo2_pSignalSemaphoreInfos_offsetof||0)+")",
}, (V.VkSubmitInfo2_sizeof||0))));

const VkSubmitInfo2KHR = new Proxy(function(){}, new C.ConstructProxy("VkSubmitInfo2"));


const VkQueueFamilyCheckpointProperties2NV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkQueueFamilyCheckpointProperties2NV", {
    sType: "u32("+(V.VkQueueFamilyCheckpointProperties2NV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkQueueFamilyCheckpointProperties2NV_pNext_offsetof||0)+")",
    checkpointExecutionStageMask: "u64("+(V.VkQueueFamilyCheckpointProperties2NV_checkpointExecutionStageMask_offsetof||0)+")",
}, (V.VkQueueFamilyCheckpointProperties2NV_sizeof||0))));


const VkCheckpointData2NV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCheckpointData2NV", {
    sType: "u32("+(V.VkCheckpointData2NV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCheckpointData2NV_pNext_offsetof||0)+")",
    stage: "u64("+(V.VkCheckpointData2NV_stage_offsetof||0)+")",
    pCheckpointMarker: "u64("+(V.VkCheckpointData2NV_pCheckpointMarker_offsetof||0)+")",
}, (V.VkCheckpointData2NV_sizeof||0))));


const VkPhysicalDeviceSynchronization2Features = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSynchronization2Features", {
    sType: "u32("+(V.VkPhysicalDeviceSynchronization2Features_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSynchronization2Features_pNext_offsetof||0)+")",
    synchronization2: "u32("+(V.VkPhysicalDeviceSynchronization2Features_synchronization2_offsetof||0)+")",
}, (V.VkPhysicalDeviceSynchronization2Features_sizeof||0))));

const VkPhysicalDeviceSynchronization2FeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceSynchronization2Features"));


const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_pNext_offsetof||0)+")",
    primitivesGeneratedQuery: "u32("+(V.VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_primitivesGeneratedQuery_offsetof||0)+")",
    primitivesGeneratedQueryWithRasterizerDiscard: "u32("+(V.VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_primitivesGeneratedQueryWithRasterizerDiscard_offsetof||0)+")",
    primitivesGeneratedQueryWithNonZeroStreams: "u32("+(V.VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_primitivesGeneratedQueryWithNonZeroStreams_offsetof||0)+")",
}, (V.VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceLegacyDitheringFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceLegacyDitheringFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceLegacyDitheringFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceLegacyDitheringFeaturesEXT_pNext_offsetof||0)+")",
    legacyDithering: "u32("+(V.VkPhysicalDeviceLegacyDitheringFeaturesEXT_legacyDithering_offsetof||0)+")",
}, (V.VkPhysicalDeviceLegacyDitheringFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT_pNext_offsetof||0)+")",
    multisampledRenderToSingleSampled: "u32("+(V.VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT_multisampledRenderToSingleSampled_offsetof||0)+")",
}, (V.VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT_sizeof||0))));


const VkSubpassResolvePerformanceQueryEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubpassResolvePerformanceQueryEXT", {
    sType: "u32("+(V.VkSubpassResolvePerformanceQueryEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSubpassResolvePerformanceQueryEXT_pNext_offsetof||0)+")",
    optimal: "u32("+(V.VkSubpassResolvePerformanceQueryEXT_optimal_offsetof||0)+")",
}, (V.VkSubpassResolvePerformanceQueryEXT_sizeof||0))));


const VkMultisampledRenderToSingleSampledInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMultisampledRenderToSingleSampledInfoEXT", {
    sType: "u32("+(V.VkMultisampledRenderToSingleSampledInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMultisampledRenderToSingleSampledInfoEXT_pNext_offsetof||0)+")",
    multisampledRenderToSingleSampledEnable: "u32("+(V.VkMultisampledRenderToSingleSampledInfoEXT_multisampledRenderToSingleSampledEnable_offsetof||0)+")",
    rasterizationSamples: "u32("+(V.VkMultisampledRenderToSingleSampledInfoEXT_rasterizationSamples_offsetof||0)+")",
}, (V.VkMultisampledRenderToSingleSampledInfoEXT_sizeof||0))));


const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePipelineProtectedAccessFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDevicePipelineProtectedAccessFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePipelineProtectedAccessFeaturesEXT_pNext_offsetof||0)+")",
    pipelineProtectedAccess: "u32("+(V.VkPhysicalDevicePipelineProtectedAccessFeaturesEXT_pipelineProtectedAccess_offsetof||0)+")",
}, (V.VkPhysicalDevicePipelineProtectedAccessFeaturesEXT_sizeof||0))));


const VkQueueFamilyVideoPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkQueueFamilyVideoPropertiesKHR", {
    sType: "u32("+(V.VkQueueFamilyVideoPropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkQueueFamilyVideoPropertiesKHR_pNext_offsetof||0)+")",
    videoCodecOperations: "u32("+(V.VkQueueFamilyVideoPropertiesKHR_videoCodecOperations_offsetof||0)+")",
}, (V.VkQueueFamilyVideoPropertiesKHR_sizeof||0))));


const VkQueueFamilyQueryResultStatusPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkQueueFamilyQueryResultStatusPropertiesKHR", {
    sType: "u32("+(V.VkQueueFamilyQueryResultStatusPropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkQueueFamilyQueryResultStatusPropertiesKHR_pNext_offsetof||0)+")",
    queryResultStatusSupport: "u32("+(V.VkQueueFamilyQueryResultStatusPropertiesKHR_queryResultStatusSupport_offsetof||0)+")",
}, (V.VkQueueFamilyQueryResultStatusPropertiesKHR_sizeof||0))));


const VkVideoProfileListInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoProfileListInfoKHR", {
    sType: "u32("+(V.VkVideoProfileListInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoProfileListInfoKHR_pNext_offsetof||0)+")",
    profileCount: "u32("+(V.VkVideoProfileListInfoKHR_profileCount_offsetof||0)+")",
    pProfiles: "u64("+(V.VkVideoProfileListInfoKHR_pProfiles_offsetof||0)+")",
}, (V.VkVideoProfileListInfoKHR_sizeof||0))));


const VkPhysicalDeviceVideoFormatInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceVideoFormatInfoKHR", {
    sType: "u32("+(V.VkPhysicalDeviceVideoFormatInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceVideoFormatInfoKHR_pNext_offsetof||0)+")",
    imageUsage: "u32("+(V.VkPhysicalDeviceVideoFormatInfoKHR_imageUsage_offsetof||0)+")",
}, (V.VkPhysicalDeviceVideoFormatInfoKHR_sizeof||0))));


const VkVideoFormatPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoFormatPropertiesKHR", {
    sType: "u32("+(V.VkVideoFormatPropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoFormatPropertiesKHR_pNext_offsetof||0)+")",
    format: "u32("+(V.VkVideoFormatPropertiesKHR_format_offsetof||0)+")",
    componentMapping: "u32("+(V.VkVideoFormatPropertiesKHR_componentMapping_offsetof||0)+")",
    imageCreateFlags: "u32("+(V.VkVideoFormatPropertiesKHR_imageCreateFlags_offsetof||0)+")",
    imageType: "u32("+(V.VkVideoFormatPropertiesKHR_imageType_offsetof||0)+")",
    imageTiling: "u32("+(V.VkVideoFormatPropertiesKHR_imageTiling_offsetof||0)+")",
    imageUsageFlags: "u32("+(V.VkVideoFormatPropertiesKHR_imageUsageFlags_offsetof||0)+")",
}, (V.VkVideoFormatPropertiesKHR_sizeof||0))));


const VkVideoProfileInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoProfileInfoKHR", {
    sType: "u32("+(V.VkVideoProfileInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoProfileInfoKHR_pNext_offsetof||0)+")",
    videoCodecOperation: "u32("+(V.VkVideoProfileInfoKHR_videoCodecOperation_offsetof||0)+")",
    chromaSubsampling: "u32("+(V.VkVideoProfileInfoKHR_chromaSubsampling_offsetof||0)+")",
    lumaBitDepth: "u32("+(V.VkVideoProfileInfoKHR_lumaBitDepth_offsetof||0)+")",
    chromaBitDepth: "u32("+(V.VkVideoProfileInfoKHR_chromaBitDepth_offsetof||0)+")",
}, (V.VkVideoProfileInfoKHR_sizeof||0))));


const VkVideoCapabilitiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoCapabilitiesKHR", {
    sType: "u32("+(V.VkVideoCapabilitiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoCapabilitiesKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkVideoCapabilitiesKHR_flags_offsetof||0)+")",
    minBitstreamBufferOffsetAlignment: "u64("+(V.VkVideoCapabilitiesKHR_minBitstreamBufferOffsetAlignment_offsetof||0)+")",
    minBitstreamBufferSizeAlignment: "u64("+(V.VkVideoCapabilitiesKHR_minBitstreamBufferSizeAlignment_offsetof||0)+")",
    pictureAccessGranularity: "VkExtent2D("+(V.VkVideoCapabilitiesKHR_pictureAccessGranularity_offsetof||0)+")",
    minCodedExtent: "VkExtent2D("+(V.VkVideoCapabilitiesKHR_minCodedExtent_offsetof||0)+")",
    maxCodedExtent: "VkExtent2D("+(V.VkVideoCapabilitiesKHR_maxCodedExtent_offsetof||0)+")",
    maxDpbSlots: "u32("+(V.VkVideoCapabilitiesKHR_maxDpbSlots_offsetof||0)+")",
    maxActiveReferencePictures: "u32("+(V.VkVideoCapabilitiesKHR_maxActiveReferencePictures_offsetof||0)+")",
    stdHeaderVersion: "u32("+(V.VkVideoCapabilitiesKHR_stdHeaderVersion_offsetof||0)+")",
}, (V.VkVideoCapabilitiesKHR_sizeof||0))));


const VkVideoSessionMemoryRequirementsKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoSessionMemoryRequirementsKHR", {
    sType: "u32("+(V.VkVideoSessionMemoryRequirementsKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoSessionMemoryRequirementsKHR_pNext_offsetof||0)+")",
    memoryBindIndex: "u32("+(V.VkVideoSessionMemoryRequirementsKHR_memoryBindIndex_offsetof||0)+")",
    memoryRequirements: "u32("+(V.VkVideoSessionMemoryRequirementsKHR_memoryRequirements_offsetof||0)+")",
}, (V.VkVideoSessionMemoryRequirementsKHR_sizeof||0))));


const VkBindVideoSessionMemoryInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBindVideoSessionMemoryInfoKHR", {
    sType: "u32("+(V.VkBindVideoSessionMemoryInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBindVideoSessionMemoryInfoKHR_pNext_offsetof||0)+")",
    memoryBindIndex: "u32("+(V.VkBindVideoSessionMemoryInfoKHR_memoryBindIndex_offsetof||0)+")",
    memory: "u64("+(V.VkBindVideoSessionMemoryInfoKHR_memory_offsetof||0)+")",
    memoryOffset: "u64("+(V.VkBindVideoSessionMemoryInfoKHR_memoryOffset_offsetof||0)+")",
    memorySize: "u64("+(V.VkBindVideoSessionMemoryInfoKHR_memorySize_offsetof||0)+")",
}, (V.VkBindVideoSessionMemoryInfoKHR_sizeof||0))));


const VkVideoPictureResourceInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoPictureResourceInfoKHR", {
    sType: "u32("+(V.VkVideoPictureResourceInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoPictureResourceInfoKHR_pNext_offsetof||0)+")",
    codedOffset: "VkOffset2D("+(V.VkVideoPictureResourceInfoKHR_codedOffset_offsetof||0)+")",
    codedExtent: "VkExtent2D("+(V.VkVideoPictureResourceInfoKHR_codedExtent_offsetof||0)+")",
    baseArrayLayer: "u32("+(V.VkVideoPictureResourceInfoKHR_baseArrayLayer_offsetof||0)+")",
    imageViewBinding: "u32("+(V.VkVideoPictureResourceInfoKHR_imageViewBinding_offsetof||0)+")",
}, (V.VkVideoPictureResourceInfoKHR_sizeof||0))));


const VkVideoReferenceSlotInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoReferenceSlotInfoKHR", {
    sType: "u32("+(V.VkVideoReferenceSlotInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoReferenceSlotInfoKHR_pNext_offsetof||0)+")",
    slotIndex: "i32("+(V.VkVideoReferenceSlotInfoKHR_slotIndex_offsetof||0)+")",
    pPictureResource: "u64("+(V.VkVideoReferenceSlotInfoKHR_pPictureResource_offsetof||0)+")",
}, (V.VkVideoReferenceSlotInfoKHR_sizeof||0))));


const VkVideoDecodeCapabilitiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeCapabilitiesKHR", {
    sType: "u32("+(V.VkVideoDecodeCapabilitiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeCapabilitiesKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkVideoDecodeCapabilitiesKHR_flags_offsetof||0)+")",
}, (V.VkVideoDecodeCapabilitiesKHR_sizeof||0))));


const VkVideoDecodeUsageInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeUsageInfoKHR", {
    sType: "u32("+(V.VkVideoDecodeUsageInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeUsageInfoKHR_pNext_offsetof||0)+")",
    videoUsageHints: "u32("+(V.VkVideoDecodeUsageInfoKHR_videoUsageHints_offsetof||0)+")",
}, (V.VkVideoDecodeUsageInfoKHR_sizeof||0))));


const VkVideoDecodeInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeInfoKHR", {
    sType: "u32("+(V.VkVideoDecodeInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkVideoDecodeInfoKHR_flags_offsetof||0)+")",
    srcBuffer: "u64("+(V.VkVideoDecodeInfoKHR_srcBuffer_offsetof||0)+")",
    srcBufferOffset: "u64("+(V.VkVideoDecodeInfoKHR_srcBufferOffset_offsetof||0)+")",
    srcBufferRange: "u64("+(V.VkVideoDecodeInfoKHR_srcBufferRange_offsetof||0)+")",
    dstPictureResource: "u32("+(V.VkVideoDecodeInfoKHR_dstPictureResource_offsetof||0)+")",
    pSetupReferenceSlot: "u64("+(V.VkVideoDecodeInfoKHR_pSetupReferenceSlot_offsetof||0)+")",
    referenceSlotCount: "u32("+(V.VkVideoDecodeInfoKHR_referenceSlotCount_offsetof||0)+")",
    pReferenceSlots: "u64("+(V.VkVideoDecodeInfoKHR_pReferenceSlots_offsetof||0)+")",
}, (V.VkVideoDecodeInfoKHR_sizeof||0))));


const VkVideoDecodeH264ProfileInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeH264ProfileInfoEXT", {
    sType: "u32("+(V.VkVideoDecodeH264ProfileInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeH264ProfileInfoEXT_pNext_offsetof||0)+")",
    stdProfileIdc: "u32("+(V.VkVideoDecodeH264ProfileInfoEXT_stdProfileIdc_offsetof||0)+")",
    pictureLayout: "u32("+(V.VkVideoDecodeH264ProfileInfoEXT_pictureLayout_offsetof||0)+")",
}, (V.VkVideoDecodeH264ProfileInfoEXT_sizeof||0))));


const VkVideoDecodeH264CapabilitiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeH264CapabilitiesEXT", {
    sType: "u32("+(V.VkVideoDecodeH264CapabilitiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeH264CapabilitiesEXT_pNext_offsetof||0)+")",
    maxLevelIdc: "u32("+(V.VkVideoDecodeH264CapabilitiesEXT_maxLevelIdc_offsetof||0)+")",
    fieldOffsetGranularity: "VkOffset2D("+(V.VkVideoDecodeH264CapabilitiesEXT_fieldOffsetGranularity_offsetof||0)+")",
}, (V.VkVideoDecodeH264CapabilitiesEXT_sizeof||0))));


const VkVideoDecodeH264SessionParametersAddInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeH264SessionParametersAddInfoEXT", {
    sType: "u32("+(V.VkVideoDecodeH264SessionParametersAddInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeH264SessionParametersAddInfoEXT_pNext_offsetof||0)+")",
    stdSPSCount: "u32("+(V.VkVideoDecodeH264SessionParametersAddInfoEXT_stdSPSCount_offsetof||0)+")",
    pStdSPSs: "u64("+(V.VkVideoDecodeH264SessionParametersAddInfoEXT_pStdSPSs_offsetof||0)+")",
    stdPPSCount: "u32("+(V.VkVideoDecodeH264SessionParametersAddInfoEXT_stdPPSCount_offsetof||0)+")",
    pStdPPSs: "u64("+(V.VkVideoDecodeH264SessionParametersAddInfoEXT_pStdPPSs_offsetof||0)+")",
}, (V.VkVideoDecodeH264SessionParametersAddInfoEXT_sizeof||0))));


const VkVideoDecodeH264SessionParametersCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeH264SessionParametersCreateInfoEXT", {
    sType: "u32("+(V.VkVideoDecodeH264SessionParametersCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeH264SessionParametersCreateInfoEXT_pNext_offsetof||0)+")",
    maxStdSPSCount: "u32("+(V.VkVideoDecodeH264SessionParametersCreateInfoEXT_maxStdSPSCount_offsetof||0)+")",
    maxStdPPSCount: "u32("+(V.VkVideoDecodeH264SessionParametersCreateInfoEXT_maxStdPPSCount_offsetof||0)+")",
    pParametersAddInfo: "u64("+(V.VkVideoDecodeH264SessionParametersCreateInfoEXT_pParametersAddInfo_offsetof||0)+")",
}, (V.VkVideoDecodeH264SessionParametersCreateInfoEXT_sizeof||0))));


const VkVideoDecodeH264PictureInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeH264PictureInfoEXT", {
    sType: "u32("+(V.VkVideoDecodeH264PictureInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeH264PictureInfoEXT_pNext_offsetof||0)+")",
    pStdPictureInfo: "u64("+(V.VkVideoDecodeH264PictureInfoEXT_pStdPictureInfo_offsetof||0)+")",
    sliceCount: "u32("+(V.VkVideoDecodeH264PictureInfoEXT_sliceCount_offsetof||0)+")",
    pSliceOffsets: "u64("+(V.VkVideoDecodeH264PictureInfoEXT_pSliceOffsets_offsetof||0)+")",
}, (V.VkVideoDecodeH264PictureInfoEXT_sizeof||0))));


const VkVideoDecodeH264DpbSlotInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeH264DpbSlotInfoEXT", {
    sType: "u32("+(V.VkVideoDecodeH264DpbSlotInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeH264DpbSlotInfoEXT_pNext_offsetof||0)+")",
    pStdReferenceInfo: "u64("+(V.VkVideoDecodeH264DpbSlotInfoEXT_pStdReferenceInfo_offsetof||0)+")",
}, (V.VkVideoDecodeH264DpbSlotInfoEXT_sizeof||0))));


const VkVideoDecodeH265ProfileInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeH265ProfileInfoEXT", {
    sType: "u32("+(V.VkVideoDecodeH265ProfileInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeH265ProfileInfoEXT_pNext_offsetof||0)+")",
    stdProfileIdc: "u32("+(V.VkVideoDecodeH265ProfileInfoEXT_stdProfileIdc_offsetof||0)+")",
}, (V.VkVideoDecodeH265ProfileInfoEXT_sizeof||0))));


const VkVideoDecodeH265CapabilitiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeH265CapabilitiesEXT", {
    sType: "u32("+(V.VkVideoDecodeH265CapabilitiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeH265CapabilitiesEXT_pNext_offsetof||0)+")",
    maxLevelIdc: "u32("+(V.VkVideoDecodeH265CapabilitiesEXT_maxLevelIdc_offsetof||0)+")",
}, (V.VkVideoDecodeH265CapabilitiesEXT_sizeof||0))));


const VkVideoDecodeH265SessionParametersAddInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeH265SessionParametersAddInfoEXT", {
    sType: "u32("+(V.VkVideoDecodeH265SessionParametersAddInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeH265SessionParametersAddInfoEXT_pNext_offsetof||0)+")",
    stdVPSCount: "u32("+(V.VkVideoDecodeH265SessionParametersAddInfoEXT_stdVPSCount_offsetof||0)+")",
    pStdVPSs: "u64("+(V.VkVideoDecodeH265SessionParametersAddInfoEXT_pStdVPSs_offsetof||0)+")",
    stdSPSCount: "u32("+(V.VkVideoDecodeH265SessionParametersAddInfoEXT_stdSPSCount_offsetof||0)+")",
    pStdSPSs: "u64("+(V.VkVideoDecodeH265SessionParametersAddInfoEXT_pStdSPSs_offsetof||0)+")",
    stdPPSCount: "u32("+(V.VkVideoDecodeH265SessionParametersAddInfoEXT_stdPPSCount_offsetof||0)+")",
    pStdPPSs: "u64("+(V.VkVideoDecodeH265SessionParametersAddInfoEXT_pStdPPSs_offsetof||0)+")",
}, (V.VkVideoDecodeH265SessionParametersAddInfoEXT_sizeof||0))));


const VkVideoDecodeH265SessionParametersCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeH265SessionParametersCreateInfoEXT", {
    sType: "u32("+(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_pNext_offsetof||0)+")",
    maxStdVPSCount: "u32("+(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_maxStdVPSCount_offsetof||0)+")",
    maxStdSPSCount: "u32("+(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_maxStdSPSCount_offsetof||0)+")",
    maxStdPPSCount: "u32("+(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_maxStdPPSCount_offsetof||0)+")",
    pParametersAddInfo: "u64("+(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_pParametersAddInfo_offsetof||0)+")",
}, (V.VkVideoDecodeH265SessionParametersCreateInfoEXT_sizeof||0))));


const VkVideoDecodeH265PictureInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeH265PictureInfoEXT", {
    sType: "u32("+(V.VkVideoDecodeH265PictureInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeH265PictureInfoEXT_pNext_offsetof||0)+")",
    pStdPictureInfo: "u64("+(V.VkVideoDecodeH265PictureInfoEXT_pStdPictureInfo_offsetof||0)+")",
    sliceCount: "u32("+(V.VkVideoDecodeH265PictureInfoEXT_sliceCount_offsetof||0)+")",
    pSliceOffsets: "u64("+(V.VkVideoDecodeH265PictureInfoEXT_pSliceOffsets_offsetof||0)+")",
}, (V.VkVideoDecodeH265PictureInfoEXT_sizeof||0))));


const VkVideoDecodeH265DpbSlotInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoDecodeH265DpbSlotInfoEXT", {
    sType: "u32("+(V.VkVideoDecodeH265DpbSlotInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoDecodeH265DpbSlotInfoEXT_pNext_offsetof||0)+")",
    pStdReferenceInfo: "u64("+(V.VkVideoDecodeH265DpbSlotInfoEXT_pStdReferenceInfo_offsetof||0)+")",
}, (V.VkVideoDecodeH265DpbSlotInfoEXT_sizeof||0))));


const VkVideoSessionCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoSessionCreateInfoKHR", {
    sType: "u32("+(V.VkVideoSessionCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoSessionCreateInfoKHR_pNext_offsetof||0)+")",
    queueFamilyIndex: "u32("+(V.VkVideoSessionCreateInfoKHR_queueFamilyIndex_offsetof||0)+")",
    flags: "u32("+(V.VkVideoSessionCreateInfoKHR_flags_offsetof||0)+")",
    pVideoProfile: "u64("+(V.VkVideoSessionCreateInfoKHR_pVideoProfile_offsetof||0)+")",
    pictureFormat: "u32("+(V.VkVideoSessionCreateInfoKHR_pictureFormat_offsetof||0)+")",
    maxCodedExtent: "VkExtent2D("+(V.VkVideoSessionCreateInfoKHR_maxCodedExtent_offsetof||0)+")",
    referencePictureFormat: "u32("+(V.VkVideoSessionCreateInfoKHR_referencePictureFormat_offsetof||0)+")",
    maxDpbSlots: "u32("+(V.VkVideoSessionCreateInfoKHR_maxDpbSlots_offsetof||0)+")",
    maxActiveReferencePictures: "u32("+(V.VkVideoSessionCreateInfoKHR_maxActiveReferencePictures_offsetof||0)+")",
    pStdHeaderVersion: "u64("+(V.VkVideoSessionCreateInfoKHR_pStdHeaderVersion_offsetof||0)+")",
}, (V.VkVideoSessionCreateInfoKHR_sizeof||0))));


const VkVideoSessionParametersCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoSessionParametersCreateInfoKHR", {
    sType: "u32("+(V.VkVideoSessionParametersCreateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoSessionParametersCreateInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkVideoSessionParametersCreateInfoKHR_flags_offsetof||0)+")",
    videoSessionParametersTemplate: "u32("+(V.VkVideoSessionParametersCreateInfoKHR_videoSessionParametersTemplate_offsetof||0)+")",
    videoSession: "u32("+(V.VkVideoSessionParametersCreateInfoKHR_videoSession_offsetof||0)+")",
}, (V.VkVideoSessionParametersCreateInfoKHR_sizeof||0))));


const VkVideoSessionParametersUpdateInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoSessionParametersUpdateInfoKHR", {
    sType: "u32("+(V.VkVideoSessionParametersUpdateInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoSessionParametersUpdateInfoKHR_pNext_offsetof||0)+")",
    updateSequenceCount: "u32("+(V.VkVideoSessionParametersUpdateInfoKHR_updateSequenceCount_offsetof||0)+")",
}, (V.VkVideoSessionParametersUpdateInfoKHR_sizeof||0))));


const VkVideoBeginCodingInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoBeginCodingInfoKHR", {
    sType: "u32("+(V.VkVideoBeginCodingInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoBeginCodingInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkVideoBeginCodingInfoKHR_flags_offsetof||0)+")",
    videoSession: "u32("+(V.VkVideoBeginCodingInfoKHR_videoSession_offsetof||0)+")",
    videoSessionParameters: "u32("+(V.VkVideoBeginCodingInfoKHR_videoSessionParameters_offsetof||0)+")",
    referenceSlotCount: "u32("+(V.VkVideoBeginCodingInfoKHR_referenceSlotCount_offsetof||0)+")",
    pReferenceSlots: "u64("+(V.VkVideoBeginCodingInfoKHR_pReferenceSlots_offsetof||0)+")",
}, (V.VkVideoBeginCodingInfoKHR_sizeof||0))));


const VkVideoEndCodingInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEndCodingInfoKHR", {
    sType: "u32("+(V.VkVideoEndCodingInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEndCodingInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkVideoEndCodingInfoKHR_flags_offsetof||0)+")",
}, (V.VkVideoEndCodingInfoKHR_sizeof||0))));


const VkVideoCodingControlInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoCodingControlInfoKHR", {
    sType: "u32("+(V.VkVideoCodingControlInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoCodingControlInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkVideoCodingControlInfoKHR_flags_offsetof||0)+")",
}, (V.VkVideoCodingControlInfoKHR_sizeof||0))));


const VkVideoEncodeUsageInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeUsageInfoKHR", {
    sType: "u32("+(V.VkVideoEncodeUsageInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeUsageInfoKHR_pNext_offsetof||0)+")",
    videoUsageHints: "u32("+(V.VkVideoEncodeUsageInfoKHR_videoUsageHints_offsetof||0)+")",
    videoContentHints: "u32("+(V.VkVideoEncodeUsageInfoKHR_videoContentHints_offsetof||0)+")",
    tuningMode: "u32("+(V.VkVideoEncodeUsageInfoKHR_tuningMode_offsetof||0)+")",
}, (V.VkVideoEncodeUsageInfoKHR_sizeof||0))));


const VkVideoEncodeInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeInfoKHR", {
    sType: "u32("+(V.VkVideoEncodeInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkVideoEncodeInfoKHR_flags_offsetof||0)+")",
    qualityLevel: "u32("+(V.VkVideoEncodeInfoKHR_qualityLevel_offsetof||0)+")",
    dstBitstreamBuffer: "u64("+(V.VkVideoEncodeInfoKHR_dstBitstreamBuffer_offsetof||0)+")",
    dstBitstreamBufferOffset: "u64("+(V.VkVideoEncodeInfoKHR_dstBitstreamBufferOffset_offsetof||0)+")",
    dstBitstreamBufferMaxRange: "u64("+(V.VkVideoEncodeInfoKHR_dstBitstreamBufferMaxRange_offsetof||0)+")",
    srcPictureResource: "u32("+(V.VkVideoEncodeInfoKHR_srcPictureResource_offsetof||0)+")",
    pSetupReferenceSlot: "u64("+(V.VkVideoEncodeInfoKHR_pSetupReferenceSlot_offsetof||0)+")",
    referenceSlotCount: "u32("+(V.VkVideoEncodeInfoKHR_referenceSlotCount_offsetof||0)+")",
    pReferenceSlots: "u64("+(V.VkVideoEncodeInfoKHR_pReferenceSlots_offsetof||0)+")",
    precedingExternallyEncodedBytes: "u32("+(V.VkVideoEncodeInfoKHR_precedingExternallyEncodedBytes_offsetof||0)+")",
}, (V.VkVideoEncodeInfoKHR_sizeof||0))));


const VkVideoEncodeRateControlInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeRateControlInfoKHR", {
    sType: "u32("+(V.VkVideoEncodeRateControlInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeRateControlInfoKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkVideoEncodeRateControlInfoKHR_flags_offsetof||0)+")",
    rateControlMode: "u32("+(V.VkVideoEncodeRateControlInfoKHR_rateControlMode_offsetof||0)+")",
    layerCount: "u8("+(V.VkVideoEncodeRateControlInfoKHR_layerCount_offsetof||0)+")",
    pLayerConfigs: "u64("+(V.VkVideoEncodeRateControlInfoKHR_pLayerConfigs_offsetof||0)+")",
}, (V.VkVideoEncodeRateControlInfoKHR_sizeof||0))));


const VkVideoEncodeRateControlLayerInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeRateControlLayerInfoKHR", {
    sType: "u32("+(V.VkVideoEncodeRateControlLayerInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeRateControlLayerInfoKHR_pNext_offsetof||0)+")",
    averageBitrate: "u32("+(V.VkVideoEncodeRateControlLayerInfoKHR_averageBitrate_offsetof||0)+")",
    maxBitrate: "u32("+(V.VkVideoEncodeRateControlLayerInfoKHR_maxBitrate_offsetof||0)+")",
    frameRateNumerator: "u32("+(V.VkVideoEncodeRateControlLayerInfoKHR_frameRateNumerator_offsetof||0)+")",
    frameRateDenominator: "u32("+(V.VkVideoEncodeRateControlLayerInfoKHR_frameRateDenominator_offsetof||0)+")",
    virtualBufferSizeInMs: "u32("+(V.VkVideoEncodeRateControlLayerInfoKHR_virtualBufferSizeInMs_offsetof||0)+")",
    initialVirtualBufferSizeInMs: "u32("+(V.VkVideoEncodeRateControlLayerInfoKHR_initialVirtualBufferSizeInMs_offsetof||0)+")",
}, (V.VkVideoEncodeRateControlLayerInfoKHR_sizeof||0))));


const VkVideoEncodeCapabilitiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeCapabilitiesKHR", {
    sType: "u32("+(V.VkVideoEncodeCapabilitiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeCapabilitiesKHR_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkVideoEncodeCapabilitiesKHR_flags_offsetof||0)+")",
    rateControlModes: "u32("+(V.VkVideoEncodeCapabilitiesKHR_rateControlModes_offsetof||0)+")",
    rateControlLayerCount: "u8("+(V.VkVideoEncodeCapabilitiesKHR_rateControlLayerCount_offsetof||0)+")",
    qualityLevelCount: "u8("+(V.VkVideoEncodeCapabilitiesKHR_qualityLevelCount_offsetof||0)+")",
    inputImageDataFillAlignment: "VkExtent2D("+(V.VkVideoEncodeCapabilitiesKHR_inputImageDataFillAlignment_offsetof||0)+")",
}, (V.VkVideoEncodeCapabilitiesKHR_sizeof||0))));


const VkVideoEncodeH264CapabilitiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264CapabilitiesEXT", {
    sType: "u32("+(V.VkVideoEncodeH264CapabilitiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH264CapabilitiesEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkVideoEncodeH264CapabilitiesEXT_flags_offsetof||0)+")",
    inputModeFlags: "u32("+(V.VkVideoEncodeH264CapabilitiesEXT_inputModeFlags_offsetof||0)+")",
    outputModeFlags: "u32("+(V.VkVideoEncodeH264CapabilitiesEXT_outputModeFlags_offsetof||0)+")",
    maxPPictureL0ReferenceCount: "u8("+(V.VkVideoEncodeH264CapabilitiesEXT_maxPPictureL0ReferenceCount_offsetof||0)+")",
    maxBPictureL0ReferenceCount: "u8("+(V.VkVideoEncodeH264CapabilitiesEXT_maxBPictureL0ReferenceCount_offsetof||0)+")",
    maxL1ReferenceCount: "u8("+(V.VkVideoEncodeH264CapabilitiesEXT_maxL1ReferenceCount_offsetof||0)+")",
    motionVectorsOverPicBoundariesFlag: "u32("+(V.VkVideoEncodeH264CapabilitiesEXT_motionVectorsOverPicBoundariesFlag_offsetof||0)+")",
    maxBytesPerPicDenom: "u32("+(V.VkVideoEncodeH264CapabilitiesEXT_maxBytesPerPicDenom_offsetof||0)+")",
    maxBitsPerMbDenom: "u32("+(V.VkVideoEncodeH264CapabilitiesEXT_maxBitsPerMbDenom_offsetof||0)+")",
    log2MaxMvLengthHorizontal: "u32("+(V.VkVideoEncodeH264CapabilitiesEXT_log2MaxMvLengthHorizontal_offsetof||0)+")",
    log2MaxMvLengthVertical: "u32("+(V.VkVideoEncodeH264CapabilitiesEXT_log2MaxMvLengthVertical_offsetof||0)+")",
}, (V.VkVideoEncodeH264CapabilitiesEXT_sizeof||0))));


const VkVideoEncodeH264SessionParametersAddInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264SessionParametersAddInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH264SessionParametersAddInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH264SessionParametersAddInfoEXT_pNext_offsetof||0)+")",
    stdSPSCount: "u32("+(V.VkVideoEncodeH264SessionParametersAddInfoEXT_stdSPSCount_offsetof||0)+")",
    pStdSPSs: "u64("+(V.VkVideoEncodeH264SessionParametersAddInfoEXT_pStdSPSs_offsetof||0)+")",
    stdPPSCount: "u32("+(V.VkVideoEncodeH264SessionParametersAddInfoEXT_stdPPSCount_offsetof||0)+")",
    pStdPPSs: "u64("+(V.VkVideoEncodeH264SessionParametersAddInfoEXT_pStdPPSs_offsetof||0)+")",
}, (V.VkVideoEncodeH264SessionParametersAddInfoEXT_sizeof||0))));


const VkVideoEncodeH264SessionParametersCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264SessionParametersCreateInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH264SessionParametersCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH264SessionParametersCreateInfoEXT_pNext_offsetof||0)+")",
    maxStdSPSCount: "u32("+(V.VkVideoEncodeH264SessionParametersCreateInfoEXT_maxStdSPSCount_offsetof||0)+")",
    maxStdPPSCount: "u32("+(V.VkVideoEncodeH264SessionParametersCreateInfoEXT_maxStdPPSCount_offsetof||0)+")",
    pParametersAddInfo: "u64("+(V.VkVideoEncodeH264SessionParametersCreateInfoEXT_pParametersAddInfo_offsetof||0)+")",
}, (V.VkVideoEncodeH264SessionParametersCreateInfoEXT_sizeof||0))));


const VkVideoEncodeH264DpbSlotInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264DpbSlotInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH264DpbSlotInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH264DpbSlotInfoEXT_pNext_offsetof||0)+")",
    slotIndex: "i8("+(V.VkVideoEncodeH264DpbSlotInfoEXT_slotIndex_offsetof||0)+")",
    pStdReferenceInfo: "u64("+(V.VkVideoEncodeH264DpbSlotInfoEXT_pStdReferenceInfo_offsetof||0)+")",
}, (V.VkVideoEncodeH264DpbSlotInfoEXT_sizeof||0))));


const VkVideoEncodeH264VclFrameInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264VclFrameInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH264VclFrameInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH264VclFrameInfoEXT_pNext_offsetof||0)+")",
    pReferenceFinalLists: "u64("+(V.VkVideoEncodeH264VclFrameInfoEXT_pReferenceFinalLists_offsetof||0)+")",
    naluSliceEntryCount: "u32("+(V.VkVideoEncodeH264VclFrameInfoEXT_naluSliceEntryCount_offsetof||0)+")",
    pNaluSliceEntries: "u64("+(V.VkVideoEncodeH264VclFrameInfoEXT_pNaluSliceEntries_offsetof||0)+")",
    pCurrentPictureInfo: "u64("+(V.VkVideoEncodeH264VclFrameInfoEXT_pCurrentPictureInfo_offsetof||0)+")",
}, (V.VkVideoEncodeH264VclFrameInfoEXT_sizeof||0))));


const VkVideoEncodeH264ReferenceListsInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264ReferenceListsInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH264ReferenceListsInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH264ReferenceListsInfoEXT_pNext_offsetof||0)+")",
    referenceList0EntryCount: "u8("+(V.VkVideoEncodeH264ReferenceListsInfoEXT_referenceList0EntryCount_offsetof||0)+")",
    pReferenceList0Entries: "u64("+(V.VkVideoEncodeH264ReferenceListsInfoEXT_pReferenceList0Entries_offsetof||0)+")",
    referenceList1EntryCount: "u8("+(V.VkVideoEncodeH264ReferenceListsInfoEXT_referenceList1EntryCount_offsetof||0)+")",
    pReferenceList1Entries: "u64("+(V.VkVideoEncodeH264ReferenceListsInfoEXT_pReferenceList1Entries_offsetof||0)+")",
    pMemMgmtCtrlOperations: "u64("+(V.VkVideoEncodeH264ReferenceListsInfoEXT_pMemMgmtCtrlOperations_offsetof||0)+")",
}, (V.VkVideoEncodeH264ReferenceListsInfoEXT_sizeof||0))));


const VkVideoEncodeH264EmitPictureParametersInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264EmitPictureParametersInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_pNext_offsetof||0)+")",
    spsId: "u8("+(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_spsId_offsetof||0)+")",
    emitSpsEnable: "u32("+(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_emitSpsEnable_offsetof||0)+")",
    ppsIdEntryCount: "u32("+(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_ppsIdEntryCount_offsetof||0)+")",
    ppsIdEntries: "u64("+(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_ppsIdEntries_offsetof||0)+")",
}, (V.VkVideoEncodeH264EmitPictureParametersInfoEXT_sizeof||0))));


const VkVideoEncodeH264ProfileInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264ProfileInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH264ProfileInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH264ProfileInfoEXT_pNext_offsetof||0)+")",
    stdProfileIdc: "u32("+(V.VkVideoEncodeH264ProfileInfoEXT_stdProfileIdc_offsetof||0)+")",
}, (V.VkVideoEncodeH264ProfileInfoEXT_sizeof||0))));


const VkVideoEncodeH264NaluSliceInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264NaluSliceInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH264NaluSliceInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH264NaluSliceInfoEXT_pNext_offsetof||0)+")",
    mbCount: "u32("+(V.VkVideoEncodeH264NaluSliceInfoEXT_mbCount_offsetof||0)+")",
    pReferenceFinalLists: "u64("+(V.VkVideoEncodeH264NaluSliceInfoEXT_pReferenceFinalLists_offsetof||0)+")",
    pSliceHeaderStd: "u64("+(V.VkVideoEncodeH264NaluSliceInfoEXT_pSliceHeaderStd_offsetof||0)+")",
}, (V.VkVideoEncodeH264NaluSliceInfoEXT_sizeof||0))));


const VkVideoEncodeH264RateControlInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264RateControlInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH264RateControlInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH264RateControlInfoEXT_pNext_offsetof||0)+")",
    gopFrameCount: "u32("+(V.VkVideoEncodeH264RateControlInfoEXT_gopFrameCount_offsetof||0)+")",
    idrPeriod: "u32("+(V.VkVideoEncodeH264RateControlInfoEXT_idrPeriod_offsetof||0)+")",
    consecutiveBFrameCount: "u32("+(V.VkVideoEncodeH264RateControlInfoEXT_consecutiveBFrameCount_offsetof||0)+")",
    rateControlStructure: "u32("+(V.VkVideoEncodeH264RateControlInfoEXT_rateControlStructure_offsetof||0)+")",
    temporalLayerCount: "u8("+(V.VkVideoEncodeH264RateControlInfoEXT_temporalLayerCount_offsetof||0)+")",
}, (V.VkVideoEncodeH264RateControlInfoEXT_sizeof||0))));


const VkVideoEncodeH264QpEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264QpEXT", {
    qpI: "i32("+(V.VkVideoEncodeH264QpEXT_qpI_offsetof||0)+")",
    qpP: "i32("+(V.VkVideoEncodeH264QpEXT_qpP_offsetof||0)+")",
    qpB: "i32("+(V.VkVideoEncodeH264QpEXT_qpB_offsetof||0)+")",
}, (V.VkVideoEncodeH264QpEXT_sizeof||0))));


const VkVideoEncodeH264FrameSizeEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264FrameSizeEXT", {
    frameISize: "u32("+(V.VkVideoEncodeH264FrameSizeEXT_frameISize_offsetof||0)+")",
    framePSize: "u32("+(V.VkVideoEncodeH264FrameSizeEXT_framePSize_offsetof||0)+")",
    frameBSize: "u32("+(V.VkVideoEncodeH264FrameSizeEXT_frameBSize_offsetof||0)+")",
}, (V.VkVideoEncodeH264FrameSizeEXT_sizeof||0))));


const VkVideoEncodeH264RateControlLayerInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH264RateControlLayerInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH264RateControlLayerInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH264RateControlLayerInfoEXT_pNext_offsetof||0)+")",
    temporalLayerId: "u8("+(V.VkVideoEncodeH264RateControlLayerInfoEXT_temporalLayerId_offsetof||0)+")",
    useInitialRcQp: "u32("+(V.VkVideoEncodeH264RateControlLayerInfoEXT_useInitialRcQp_offsetof||0)+")",
    initialRcQp: "u32("+(V.VkVideoEncodeH264RateControlLayerInfoEXT_initialRcQp_offsetof||0)+")",
    useMinQp: "u32("+(V.VkVideoEncodeH264RateControlLayerInfoEXT_useMinQp_offsetof||0)+")",
    minQp: "u32("+(V.VkVideoEncodeH264RateControlLayerInfoEXT_minQp_offsetof||0)+")",
    useMaxQp: "u32("+(V.VkVideoEncodeH264RateControlLayerInfoEXT_useMaxQp_offsetof||0)+")",
    maxQp: "u32("+(V.VkVideoEncodeH264RateControlLayerInfoEXT_maxQp_offsetof||0)+")",
    useMaxFrameSize: "u32("+(V.VkVideoEncodeH264RateControlLayerInfoEXT_useMaxFrameSize_offsetof||0)+")",
    maxFrameSize: "u32("+(V.VkVideoEncodeH264RateControlLayerInfoEXT_maxFrameSize_offsetof||0)+")",
}, (V.VkVideoEncodeH264RateControlLayerInfoEXT_sizeof||0))));


const VkVideoEncodeH265CapabilitiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265CapabilitiesEXT", {
    sType: "u32("+(V.VkVideoEncodeH265CapabilitiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH265CapabilitiesEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkVideoEncodeH265CapabilitiesEXT_flags_offsetof||0)+")",
    inputModeFlags: "u32("+(V.VkVideoEncodeH265CapabilitiesEXT_inputModeFlags_offsetof||0)+")",
    outputModeFlags: "u32("+(V.VkVideoEncodeH265CapabilitiesEXT_outputModeFlags_offsetof||0)+")",
    ctbSizes: "u32("+(V.VkVideoEncodeH265CapabilitiesEXT_ctbSizes_offsetof||0)+")",
    transformBlockSizes: "u32("+(V.VkVideoEncodeH265CapabilitiesEXT_transformBlockSizes_offsetof||0)+")",
    maxPPictureL0ReferenceCount: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_maxPPictureL0ReferenceCount_offsetof||0)+")",
    maxBPictureL0ReferenceCount: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_maxBPictureL0ReferenceCount_offsetof||0)+")",
    maxL1ReferenceCount: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_maxL1ReferenceCount_offsetof||0)+")",
    maxSubLayersCount: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_maxSubLayersCount_offsetof||0)+")",
    minLog2MinLumaCodingBlockSizeMinus3: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_minLog2MinLumaCodingBlockSizeMinus3_offsetof||0)+")",
    maxLog2MinLumaCodingBlockSizeMinus3: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_maxLog2MinLumaCodingBlockSizeMinus3_offsetof||0)+")",
    minLog2MinLumaTransformBlockSizeMinus2: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_minLog2MinLumaTransformBlockSizeMinus2_offsetof||0)+")",
    maxLog2MinLumaTransformBlockSizeMinus2: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_maxLog2MinLumaTransformBlockSizeMinus2_offsetof||0)+")",
    minMaxTransformHierarchyDepthInter: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_minMaxTransformHierarchyDepthInter_offsetof||0)+")",
    maxMaxTransformHierarchyDepthInter: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_maxMaxTransformHierarchyDepthInter_offsetof||0)+")",
    minMaxTransformHierarchyDepthIntra: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_minMaxTransformHierarchyDepthIntra_offsetof||0)+")",
    maxMaxTransformHierarchyDepthIntra: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_maxMaxTransformHierarchyDepthIntra_offsetof||0)+")",
    maxDiffCuQpDeltaDepth: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_maxDiffCuQpDeltaDepth_offsetof||0)+")",
    minMaxNumMergeCand: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_minMaxNumMergeCand_offsetof||0)+")",
    maxMaxNumMergeCand: "u8("+(V.VkVideoEncodeH265CapabilitiesEXT_maxMaxNumMergeCand_offsetof||0)+")",
}, (V.VkVideoEncodeH265CapabilitiesEXT_sizeof||0))));


const VkVideoEncodeH265SessionParametersAddInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265SessionParametersAddInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH265SessionParametersAddInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH265SessionParametersAddInfoEXT_pNext_offsetof||0)+")",
    stdVPSCount: "u32("+(V.VkVideoEncodeH265SessionParametersAddInfoEXT_stdVPSCount_offsetof||0)+")",
    pStdVPSs: "u64("+(V.VkVideoEncodeH265SessionParametersAddInfoEXT_pStdVPSs_offsetof||0)+")",
    stdSPSCount: "u32("+(V.VkVideoEncodeH265SessionParametersAddInfoEXT_stdSPSCount_offsetof||0)+")",
    pStdSPSs: "u64("+(V.VkVideoEncodeH265SessionParametersAddInfoEXT_pStdSPSs_offsetof||0)+")",
    stdPPSCount: "u32("+(V.VkVideoEncodeH265SessionParametersAddInfoEXT_stdPPSCount_offsetof||0)+")",
    pStdPPSs: "u64("+(V.VkVideoEncodeH265SessionParametersAddInfoEXT_pStdPPSs_offsetof||0)+")",
}, (V.VkVideoEncodeH265SessionParametersAddInfoEXT_sizeof||0))));


const VkVideoEncodeH265SessionParametersCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265SessionParametersCreateInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_pNext_offsetof||0)+")",
    maxStdVPSCount: "u32("+(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_maxStdVPSCount_offsetof||0)+")",
    maxStdSPSCount: "u32("+(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_maxStdSPSCount_offsetof||0)+")",
    maxStdPPSCount: "u32("+(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_maxStdPPSCount_offsetof||0)+")",
    pParametersAddInfo: "u64("+(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_pParametersAddInfo_offsetof||0)+")",
}, (V.VkVideoEncodeH265SessionParametersCreateInfoEXT_sizeof||0))));


const VkVideoEncodeH265VclFrameInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265VclFrameInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH265VclFrameInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH265VclFrameInfoEXT_pNext_offsetof||0)+")",
    pReferenceFinalLists: "u64("+(V.VkVideoEncodeH265VclFrameInfoEXT_pReferenceFinalLists_offsetof||0)+")",
    naluSliceSegmentEntryCount: "u32("+(V.VkVideoEncodeH265VclFrameInfoEXT_naluSliceSegmentEntryCount_offsetof||0)+")",
    pNaluSliceSegmentEntries: "u64("+(V.VkVideoEncodeH265VclFrameInfoEXT_pNaluSliceSegmentEntries_offsetof||0)+")",
    pCurrentPictureInfo: "u64("+(V.VkVideoEncodeH265VclFrameInfoEXT_pCurrentPictureInfo_offsetof||0)+")",
}, (V.VkVideoEncodeH265VclFrameInfoEXT_sizeof||0))));


const VkVideoEncodeH265EmitPictureParametersInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265EmitPictureParametersInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_pNext_offsetof||0)+")",
    vpsId: "u8("+(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_vpsId_offsetof||0)+")",
    spsId: "u8("+(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_spsId_offsetof||0)+")",
    emitVpsEnable: "u32("+(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_emitVpsEnable_offsetof||0)+")",
    emitSpsEnable: "u32("+(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_emitSpsEnable_offsetof||0)+")",
    ppsIdEntryCount: "u32("+(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_ppsIdEntryCount_offsetof||0)+")",
    ppsIdEntries: "u64("+(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_ppsIdEntries_offsetof||0)+")",
}, (V.VkVideoEncodeH265EmitPictureParametersInfoEXT_sizeof||0))));


const VkVideoEncodeH265NaluSliceSegmentInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265NaluSliceSegmentInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH265NaluSliceSegmentInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH265NaluSliceSegmentInfoEXT_pNext_offsetof||0)+")",
    ctbCount: "u32("+(V.VkVideoEncodeH265NaluSliceSegmentInfoEXT_ctbCount_offsetof||0)+")",
    pReferenceFinalLists: "u64("+(V.VkVideoEncodeH265NaluSliceSegmentInfoEXT_pReferenceFinalLists_offsetof||0)+")",
    pSliceSegmentHeaderStd: "u64("+(V.VkVideoEncodeH265NaluSliceSegmentInfoEXT_pSliceSegmentHeaderStd_offsetof||0)+")",
}, (V.VkVideoEncodeH265NaluSliceSegmentInfoEXT_sizeof||0))));


const VkVideoEncodeH265RateControlInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265RateControlInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH265RateControlInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH265RateControlInfoEXT_pNext_offsetof||0)+")",
    gopFrameCount: "u32("+(V.VkVideoEncodeH265RateControlInfoEXT_gopFrameCount_offsetof||0)+")",
    idrPeriod: "u32("+(V.VkVideoEncodeH265RateControlInfoEXT_idrPeriod_offsetof||0)+")",
    consecutiveBFrameCount: "u32("+(V.VkVideoEncodeH265RateControlInfoEXT_consecutiveBFrameCount_offsetof||0)+")",
    rateControlStructure: "u32("+(V.VkVideoEncodeH265RateControlInfoEXT_rateControlStructure_offsetof||0)+")",
    subLayerCount: "u8("+(V.VkVideoEncodeH265RateControlInfoEXT_subLayerCount_offsetof||0)+")",
}, (V.VkVideoEncodeH265RateControlInfoEXT_sizeof||0))));


const VkVideoEncodeH265QpEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265QpEXT", {
    qpI: "i32("+(V.VkVideoEncodeH265QpEXT_qpI_offsetof||0)+")",
    qpP: "i32("+(V.VkVideoEncodeH265QpEXT_qpP_offsetof||0)+")",
    qpB: "i32("+(V.VkVideoEncodeH265QpEXT_qpB_offsetof||0)+")",
}, (V.VkVideoEncodeH265QpEXT_sizeof||0))));


const VkVideoEncodeH265FrameSizeEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265FrameSizeEXT", {
    frameISize: "u32("+(V.VkVideoEncodeH265FrameSizeEXT_frameISize_offsetof||0)+")",
    framePSize: "u32("+(V.VkVideoEncodeH265FrameSizeEXT_framePSize_offsetof||0)+")",
    frameBSize: "u32("+(V.VkVideoEncodeH265FrameSizeEXT_frameBSize_offsetof||0)+")",
}, (V.VkVideoEncodeH265FrameSizeEXT_sizeof||0))));


const VkVideoEncodeH265RateControlLayerInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265RateControlLayerInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH265RateControlLayerInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH265RateControlLayerInfoEXT_pNext_offsetof||0)+")",
    temporalId: "u8("+(V.VkVideoEncodeH265RateControlLayerInfoEXT_temporalId_offsetof||0)+")",
    useInitialRcQp: "u32("+(V.VkVideoEncodeH265RateControlLayerInfoEXT_useInitialRcQp_offsetof||0)+")",
    initialRcQp: "u32("+(V.VkVideoEncodeH265RateControlLayerInfoEXT_initialRcQp_offsetof||0)+")",
    useMinQp: "u32("+(V.VkVideoEncodeH265RateControlLayerInfoEXT_useMinQp_offsetof||0)+")",
    minQp: "u32("+(V.VkVideoEncodeH265RateControlLayerInfoEXT_minQp_offsetof||0)+")",
    useMaxQp: "u32("+(V.VkVideoEncodeH265RateControlLayerInfoEXT_useMaxQp_offsetof||0)+")",
    maxQp: "u32("+(V.VkVideoEncodeH265RateControlLayerInfoEXT_maxQp_offsetof||0)+")",
    useMaxFrameSize: "u32("+(V.VkVideoEncodeH265RateControlLayerInfoEXT_useMaxFrameSize_offsetof||0)+")",
    maxFrameSize: "u32("+(V.VkVideoEncodeH265RateControlLayerInfoEXT_maxFrameSize_offsetof||0)+")",
}, (V.VkVideoEncodeH265RateControlLayerInfoEXT_sizeof||0))));


const VkVideoEncodeH265ProfileInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265ProfileInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH265ProfileInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH265ProfileInfoEXT_pNext_offsetof||0)+")",
    stdProfileIdc: "u32("+(V.VkVideoEncodeH265ProfileInfoEXT_stdProfileIdc_offsetof||0)+")",
}, (V.VkVideoEncodeH265ProfileInfoEXT_sizeof||0))));


const VkVideoEncodeH265DpbSlotInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265DpbSlotInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH265DpbSlotInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH265DpbSlotInfoEXT_pNext_offsetof||0)+")",
    slotIndex: "i8("+(V.VkVideoEncodeH265DpbSlotInfoEXT_slotIndex_offsetof||0)+")",
    pStdReferenceInfo: "u64("+(V.VkVideoEncodeH265DpbSlotInfoEXT_pStdReferenceInfo_offsetof||0)+")",
}, (V.VkVideoEncodeH265DpbSlotInfoEXT_sizeof||0))));


const VkVideoEncodeH265ReferenceListsInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkVideoEncodeH265ReferenceListsInfoEXT", {
    sType: "u32("+(V.VkVideoEncodeH265ReferenceListsInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkVideoEncodeH265ReferenceListsInfoEXT_pNext_offsetof||0)+")",
    referenceList0EntryCount: "u8("+(V.VkVideoEncodeH265ReferenceListsInfoEXT_referenceList0EntryCount_offsetof||0)+")",
    pReferenceList0Entries: "u64("+(V.VkVideoEncodeH265ReferenceListsInfoEXT_pReferenceList0Entries_offsetof||0)+")",
    referenceList1EntryCount: "u8("+(V.VkVideoEncodeH265ReferenceListsInfoEXT_referenceList1EntryCount_offsetof||0)+")",
    pReferenceList1Entries: "u64("+(V.VkVideoEncodeH265ReferenceListsInfoEXT_pReferenceList1Entries_offsetof||0)+")",
    pReferenceModifications: "u64("+(V.VkVideoEncodeH265ReferenceListsInfoEXT_pReferenceModifications_offsetof||0)+")",
}, (V.VkVideoEncodeH265ReferenceListsInfoEXT_sizeof||0))));


const VkPhysicalDeviceInheritedViewportScissorFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceInheritedViewportScissorFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceInheritedViewportScissorFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceInheritedViewportScissorFeaturesNV_pNext_offsetof||0)+")",
    inheritedViewportScissor2D: "u32("+(V.VkPhysicalDeviceInheritedViewportScissorFeaturesNV_inheritedViewportScissor2D_offsetof||0)+")",
}, (V.VkPhysicalDeviceInheritedViewportScissorFeaturesNV_sizeof||0))));


const VkCommandBufferInheritanceViewportScissorInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCommandBufferInheritanceViewportScissorInfoNV", {
    sType: "u32("+(V.VkCommandBufferInheritanceViewportScissorInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCommandBufferInheritanceViewportScissorInfoNV_pNext_offsetof||0)+")",
    viewportScissor2D: "u32("+(V.VkCommandBufferInheritanceViewportScissorInfoNV_viewportScissor2D_offsetof||0)+")",
    viewportDepthCount: "u32("+(V.VkCommandBufferInheritanceViewportScissorInfoNV_viewportDepthCount_offsetof||0)+")",
    pViewportDepths: "u64("+(V.VkCommandBufferInheritanceViewportScissorInfoNV_pViewportDepths_offsetof||0)+")",
}, (V.VkCommandBufferInheritanceViewportScissorInfoNV_sizeof||0))));


const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT_pNext_offsetof||0)+")",
    ycbcr2plane444Formats: "u32("+(V.VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT_ycbcr2plane444Formats_offsetof||0)+")",
}, (V.VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceProvokingVertexFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceProvokingVertexFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceProvokingVertexFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceProvokingVertexFeaturesEXT_pNext_offsetof||0)+")",
    provokingVertexLast: "u32("+(V.VkPhysicalDeviceProvokingVertexFeaturesEXT_provokingVertexLast_offsetof||0)+")",
    transformFeedbackPreservesProvokingVertex: "u32("+(V.VkPhysicalDeviceProvokingVertexFeaturesEXT_transformFeedbackPreservesProvokingVertex_offsetof||0)+")",
}, (V.VkPhysicalDeviceProvokingVertexFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceProvokingVertexPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceProvokingVertexPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceProvokingVertexPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceProvokingVertexPropertiesEXT_pNext_offsetof||0)+")",
    provokingVertexModePerPipeline: "u32("+(V.VkPhysicalDeviceProvokingVertexPropertiesEXT_provokingVertexModePerPipeline_offsetof||0)+")",
    transformFeedbackPreservesTriangleFanProvokingVertex: "u32("+(V.VkPhysicalDeviceProvokingVertexPropertiesEXT_transformFeedbackPreservesTriangleFanProvokingVertex_offsetof||0)+")",
}, (V.VkPhysicalDeviceProvokingVertexPropertiesEXT_sizeof||0))));


const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineRasterizationProvokingVertexStateCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineRasterizationProvokingVertexStateCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineRasterizationProvokingVertexStateCreateInfoEXT_pNext_offsetof||0)+")",
    provokingVertexMode: "u32("+(V.VkPipelineRasterizationProvokingVertexStateCreateInfoEXT_provokingVertexMode_offsetof||0)+")",
}, (V.VkPipelineRasterizationProvokingVertexStateCreateInfoEXT_sizeof||0))));


const VkCuModuleCreateInfoNVX = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCuModuleCreateInfoNVX", {
    sType: "u32("+(V.VkCuModuleCreateInfoNVX_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCuModuleCreateInfoNVX_pNext_offsetof||0)+")",
    dataSize: "u64("+(V.VkCuModuleCreateInfoNVX_dataSize_offsetof||0)+")",
    pData: "u64("+(V.VkCuModuleCreateInfoNVX_pData_offsetof||0)+")",
}, (V.VkCuModuleCreateInfoNVX_sizeof||0))));


const VkCuFunctionCreateInfoNVX = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCuFunctionCreateInfoNVX", {
    sType: "u32("+(V.VkCuFunctionCreateInfoNVX_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCuFunctionCreateInfoNVX_pNext_offsetof||0)+")",
    module: "u32("+(V.VkCuFunctionCreateInfoNVX_module_offsetof||0)+")",
    pName: "u64("+(V.VkCuFunctionCreateInfoNVX_pName_offsetof||0)+")",
}, (V.VkCuFunctionCreateInfoNVX_sizeof||0))));


const VkCuLaunchInfoNVX = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCuLaunchInfoNVX", {
    sType: "u32("+(V.VkCuLaunchInfoNVX_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCuLaunchInfoNVX_pNext_offsetof||0)+")",
    function: "u32("+(V.VkCuLaunchInfoNVX_function_offsetof||0)+")",
    gridDimX: "u32("+(V.VkCuLaunchInfoNVX_gridDimX_offsetof||0)+")",
    gridDimY: "u32("+(V.VkCuLaunchInfoNVX_gridDimY_offsetof||0)+")",
    gridDimZ: "u32("+(V.VkCuLaunchInfoNVX_gridDimZ_offsetof||0)+")",
    blockDimX: "u32("+(V.VkCuLaunchInfoNVX_blockDimX_offsetof||0)+")",
    blockDimY: "u32("+(V.VkCuLaunchInfoNVX_blockDimY_offsetof||0)+")",
    blockDimZ: "u32("+(V.VkCuLaunchInfoNVX_blockDimZ_offsetof||0)+")",
    sharedMemBytes: "u32("+(V.VkCuLaunchInfoNVX_sharedMemBytes_offsetof||0)+")",
    paramCount: "u64("+(V.VkCuLaunchInfoNVX_paramCount_offsetof||0)+")",
    pParams: "u64("+(V.VkCuLaunchInfoNVX_pParams_offsetof||0)+")",
    extraCount: "u64("+(V.VkCuLaunchInfoNVX_extraCount_offsetof||0)+")",
    pExtras: "u64("+(V.VkCuLaunchInfoNVX_pExtras_offsetof||0)+")",
}, (V.VkCuLaunchInfoNVX_sizeof||0))));


const VkPhysicalDeviceShaderIntegerDotProductFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderIntegerDotProductFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderIntegerDotProductFeatures_pNext_offsetof||0)+")",
    shaderIntegerDotProduct: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductFeatures_shaderIntegerDotProduct_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderIntegerDotProductFeatures_sizeof||0))));

const VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceShaderIntegerDotProductFeatures"));


const VkPhysicalDeviceShaderIntegerDotProductProperties = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderIntegerDotProductProperties", {
    sType: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_pNext_offsetof||0)+")",
    integerDotProduct8BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct8BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProduct8BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct8BitSignedAccelerated_offsetof||0)+")",
    integerDotProduct8BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct8BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProduct4x8BitPackedUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct4x8BitPackedUnsignedAccelerated_offsetof||0)+")",
    integerDotProduct4x8BitPackedSignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct4x8BitPackedSignedAccelerated_offsetof||0)+")",
    integerDotProduct4x8BitPackedMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct4x8BitPackedMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProduct16BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct16BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProduct16BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct16BitSignedAccelerated_offsetof||0)+")",
    integerDotProduct16BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct16BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProduct32BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct32BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProduct32BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct32BitSignedAccelerated_offsetof||0)+")",
    integerDotProduct32BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct32BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProduct64BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct64BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProduct64BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct64BitSignedAccelerated_offsetof||0)+")",
    integerDotProduct64BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct64BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating8BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating8BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating8BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating8BitSignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating16BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating16BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating16BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating16BitSignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating32BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating32BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating32BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating32BitSignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating64BitUnsignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating64BitUnsignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating64BitSignedAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating64BitSignedAccelerated_offsetof||0)+")",
    integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated: "u32("+(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderIntegerDotProductProperties_sizeof||0))));

const VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceShaderIntegerDotProductProperties"));


const VkPhysicalDeviceDrmPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDrmPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceDrmPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDrmPropertiesEXT_pNext_offsetof||0)+")",
    hasPrimary: "u32("+(V.VkPhysicalDeviceDrmPropertiesEXT_hasPrimary_offsetof||0)+")",
    hasRender: "u32("+(V.VkPhysicalDeviceDrmPropertiesEXT_hasRender_offsetof||0)+")",
    primaryMajor: "u64("+(V.VkPhysicalDeviceDrmPropertiesEXT_primaryMajor_offsetof||0)+")",
    primaryMinor: "u64("+(V.VkPhysicalDeviceDrmPropertiesEXT_primaryMinor_offsetof||0)+")",
    renderMajor: "u64("+(V.VkPhysicalDeviceDrmPropertiesEXT_renderMajor_offsetof||0)+")",
    renderMinor: "u64("+(V.VkPhysicalDeviceDrmPropertiesEXT_renderMinor_offsetof||0)+")",
}, (V.VkPhysicalDeviceDrmPropertiesEXT_sizeof||0))));


const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR_pNext_offsetof||0)+")",
    fragmentShaderBarycentric: "u32("+(V.VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR_fragmentShaderBarycentric_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR_sizeof||0))));


const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR", {
    sType: "u32("+(V.VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR_pNext_offsetof||0)+")",
    triStripVertexOrderIndependentOfProvokingVertex: "u32("+(V.VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR_triStripVertexOrderIndependentOfProvokingVertex_offsetof||0)+")",
}, (V.VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR_sizeof||0))));


const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRayTracingMotionBlurFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceRayTracingMotionBlurFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRayTracingMotionBlurFeaturesNV_pNext_offsetof||0)+")",
    rayTracingMotionBlur: "u32("+(V.VkPhysicalDeviceRayTracingMotionBlurFeaturesNV_rayTracingMotionBlur_offsetof||0)+")",
    rayTracingMotionBlurPipelineTraceRaysIndirect: "u32("+(V.VkPhysicalDeviceRayTracingMotionBlurFeaturesNV_rayTracingMotionBlurPipelineTraceRaysIndirect_offsetof||0)+")",
}, (V.VkPhysicalDeviceRayTracingMotionBlurFeaturesNV_sizeof||0))));


const VkAccelerationStructureGeometryMotionTrianglesDataNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureGeometryMotionTrianglesDataNV", {
    sType: "u32("+(V.VkAccelerationStructureGeometryMotionTrianglesDataNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureGeometryMotionTrianglesDataNV_pNext_offsetof||0)+")",
    vertexData: "u32("+(V.VkAccelerationStructureGeometryMotionTrianglesDataNV_vertexData_offsetof||0)+")",
}, (V.VkAccelerationStructureGeometryMotionTrianglesDataNV_sizeof||0))));


const VkAccelerationStructureMotionInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureMotionInfoNV", {
    sType: "u32("+(V.VkAccelerationStructureMotionInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureMotionInfoNV_pNext_offsetof||0)+")",
    maxInstances: "u32("+(V.VkAccelerationStructureMotionInfoNV_maxInstances_offsetof||0)+")",
    flags: "u32("+(V.VkAccelerationStructureMotionInfoNV_flags_offsetof||0)+")",
}, (V.VkAccelerationStructureMotionInfoNV_sizeof||0))));


const VkSRTDataNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSRTDataNV", {
    sx: "f32("+(V.VkSRTDataNV_sx_offsetof||0)+")",
    a: "f32("+(V.VkSRTDataNV_a_offsetof||0)+")",
    b: "f32("+(V.VkSRTDataNV_b_offsetof||0)+")",
    pvx: "f32("+(V.VkSRTDataNV_pvx_offsetof||0)+")",
    sy: "f32("+(V.VkSRTDataNV_sy_offsetof||0)+")",
    c: "f32("+(V.VkSRTDataNV_c_offsetof||0)+")",
    pvy: "f32("+(V.VkSRTDataNV_pvy_offsetof||0)+")",
    sz: "f32("+(V.VkSRTDataNV_sz_offsetof||0)+")",
    pvz: "f32("+(V.VkSRTDataNV_pvz_offsetof||0)+")",
    qx: "f32("+(V.VkSRTDataNV_qx_offsetof||0)+")",
    qy: "f32("+(V.VkSRTDataNV_qy_offsetof||0)+")",
    qz: "f32("+(V.VkSRTDataNV_qz_offsetof||0)+")",
    qw: "f32("+(V.VkSRTDataNV_qw_offsetof||0)+")",
    tx: "f32("+(V.VkSRTDataNV_tx_offsetof||0)+")",
    ty: "f32("+(V.VkSRTDataNV_ty_offsetof||0)+")",
    tz: "f32("+(V.VkSRTDataNV_tz_offsetof||0)+")",
}, (V.VkSRTDataNV_sizeof||0))));


const VkAccelerationStructureSRTMotionInstanceNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureSRTMotionInstanceNV", {
    transformT0: "u32("+(V.VkAccelerationStructureSRTMotionInstanceNV_transformT0_offsetof||0)+")",
    transformT1: "u32("+(V.VkAccelerationStructureSRTMotionInstanceNV_transformT1_offsetof||0)+")",
    instanceCustomIndex: "u24("+(V.VkAccelerationStructureSRTMotionInstanceNV_instanceCustomIndex_offsetof||0)+")",
    mask: "u8("+(V.VkAccelerationStructureSRTMotionInstanceNV_mask_offsetof||0)+")",
    instanceShaderBindingTableRecordOffset: "u24("+(V.VkAccelerationStructureSRTMotionInstanceNV_instanceShaderBindingTableRecordOffset_offsetof||0)+")",
    flags: "u8("+(V.VkAccelerationStructureSRTMotionInstanceNV_flags_offsetof||0)+")",
    accelerationStructureReference: "u64("+(V.VkAccelerationStructureSRTMotionInstanceNV_accelerationStructureReference_offsetof||0)+")",
}, (V.VkAccelerationStructureSRTMotionInstanceNV_sizeof||0))));


const VkAccelerationStructureMatrixMotionInstanceNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureMatrixMotionInstanceNV", {
    transformT0: "VkTransformMatrixKHR("+(V.VkAccelerationStructureMatrixMotionInstanceNV_transformT0_offsetof||0)+")",
    transformT1: "VkTransformMatrixKHR("+(V.VkAccelerationStructureMatrixMotionInstanceNV_transformT1_offsetof||0)+")",
    instanceCustomIndex: "u24("+(V.VkAccelerationStructureMatrixMotionInstanceNV_instanceCustomIndex_offsetof||0)+")",
    mask: "u8("+(V.VkAccelerationStructureMatrixMotionInstanceNV_mask_offsetof||0)+")",
    instanceShaderBindingTableRecordOffset: "u24("+(V.VkAccelerationStructureMatrixMotionInstanceNV_instanceShaderBindingTableRecordOffset_offsetof||0)+")",
    flags: "u8("+(V.VkAccelerationStructureMatrixMotionInstanceNV_flags_offsetof||0)+")",
    accelerationStructureReference: "u64("+(V.VkAccelerationStructureMatrixMotionInstanceNV_accelerationStructureReference_offsetof||0)+")",
}, (V.VkAccelerationStructureMatrixMotionInstanceNV_sizeof||0))));


const VkAccelerationStructureMotionInstanceNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureMotionInstanceNV", {
    type: "u32("+(V.VkAccelerationStructureMotionInstanceNV_type_offsetof||0)+")",
    flags: "u32("+(V.VkAccelerationStructureMotionInstanceNV_flags_offsetof||0)+")",
    data: "u32("+(V.VkAccelerationStructureMotionInstanceNV_data_offsetof||0)+")",
}, (V.VkAccelerationStructureMotionInstanceNV_sizeof||0))));


const VkMemoryGetRemoteAddressInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMemoryGetRemoteAddressInfoNV", {
    sType: "u32("+(V.VkMemoryGetRemoteAddressInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMemoryGetRemoteAddressInfoNV_pNext_offsetof||0)+")",
    memory: "u64("+(V.VkMemoryGetRemoteAddressInfoNV_memory_offsetof||0)+")",
    handleType: "u32("+(V.VkMemoryGetRemoteAddressInfoNV_handleType_offsetof||0)+")",
}, (V.VkMemoryGetRemoteAddressInfoNV_sizeof||0))));


const VkImportMemoryBufferCollectionFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportMemoryBufferCollectionFUCHSIA", {
    sType: "u32("+(V.VkImportMemoryBufferCollectionFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportMemoryBufferCollectionFUCHSIA_pNext_offsetof||0)+")",
    collection: "u32("+(V.VkImportMemoryBufferCollectionFUCHSIA_collection_offsetof||0)+")",
    index: "u32("+(V.VkImportMemoryBufferCollectionFUCHSIA_index_offsetof||0)+")",
}, (V.VkImportMemoryBufferCollectionFUCHSIA_sizeof||0))));


const VkBufferCollectionImageCreateInfoFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferCollectionImageCreateInfoFUCHSIA", {
    sType: "u32("+(V.VkBufferCollectionImageCreateInfoFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferCollectionImageCreateInfoFUCHSIA_pNext_offsetof||0)+")",
    collection: "u32("+(V.VkBufferCollectionImageCreateInfoFUCHSIA_collection_offsetof||0)+")",
    index: "u32("+(V.VkBufferCollectionImageCreateInfoFUCHSIA_index_offsetof||0)+")",
}, (V.VkBufferCollectionImageCreateInfoFUCHSIA_sizeof||0))));


const VkBufferCollectionBufferCreateInfoFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferCollectionBufferCreateInfoFUCHSIA", {
    sType: "u32("+(V.VkBufferCollectionBufferCreateInfoFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferCollectionBufferCreateInfoFUCHSIA_pNext_offsetof||0)+")",
    collection: "u32("+(V.VkBufferCollectionBufferCreateInfoFUCHSIA_collection_offsetof||0)+")",
    index: "u32("+(V.VkBufferCollectionBufferCreateInfoFUCHSIA_index_offsetof||0)+")",
}, (V.VkBufferCollectionBufferCreateInfoFUCHSIA_sizeof||0))));


const VkBufferCollectionCreateInfoFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferCollectionCreateInfoFUCHSIA", {
    sType: "u32("+(V.VkBufferCollectionCreateInfoFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferCollectionCreateInfoFUCHSIA_pNext_offsetof||0)+")",
    collectionToken: "u32("+(V.VkBufferCollectionCreateInfoFUCHSIA_collectionToken_offsetof||0)+")",
}, (V.VkBufferCollectionCreateInfoFUCHSIA_sizeof||0))));


const VkBufferCollectionPropertiesFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferCollectionPropertiesFUCHSIA", {
    sType: "u32("+(V.VkBufferCollectionPropertiesFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferCollectionPropertiesFUCHSIA_pNext_offsetof||0)+")",
    memoryTypeBits: "u32("+(V.VkBufferCollectionPropertiesFUCHSIA_memoryTypeBits_offsetof||0)+")",
    bufferCount: "u32("+(V.VkBufferCollectionPropertiesFUCHSIA_bufferCount_offsetof||0)+")",
    createInfoIndex: "u32("+(V.VkBufferCollectionPropertiesFUCHSIA_createInfoIndex_offsetof||0)+")",
    sysmemPixelFormat: "u64("+(V.VkBufferCollectionPropertiesFUCHSIA_sysmemPixelFormat_offsetof||0)+")",
    formatFeatures: "u32("+(V.VkBufferCollectionPropertiesFUCHSIA_formatFeatures_offsetof||0)+")",
    sysmemColorSpaceIndex: "u32("+(V.VkBufferCollectionPropertiesFUCHSIA_sysmemColorSpaceIndex_offsetof||0)+")",
    samplerYcbcrConversionComponents: "u32("+(V.VkBufferCollectionPropertiesFUCHSIA_samplerYcbcrConversionComponents_offsetof||0)+")",
    suggestedYcbcrModel: "u32("+(V.VkBufferCollectionPropertiesFUCHSIA_suggestedYcbcrModel_offsetof||0)+")",
    suggestedYcbcrRange: "u32("+(V.VkBufferCollectionPropertiesFUCHSIA_suggestedYcbcrRange_offsetof||0)+")",
    suggestedXChromaOffset: "u32("+(V.VkBufferCollectionPropertiesFUCHSIA_suggestedXChromaOffset_offsetof||0)+")",
    suggestedYChromaOffset: "u32("+(V.VkBufferCollectionPropertiesFUCHSIA_suggestedYChromaOffset_offsetof||0)+")",
}, (V.VkBufferCollectionPropertiesFUCHSIA_sizeof||0))));


const VkBufferConstraintsInfoFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferConstraintsInfoFUCHSIA", {
    sType: "u32("+(V.VkBufferConstraintsInfoFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferConstraintsInfoFUCHSIA_pNext_offsetof||0)+")",
    createInfo: "u32("+(V.VkBufferConstraintsInfoFUCHSIA_createInfo_offsetof||0)+")",
    requiredFormatFeatures: "u32("+(V.VkBufferConstraintsInfoFUCHSIA_requiredFormatFeatures_offsetof||0)+")",
    bufferCollectionConstraints: "u32("+(V.VkBufferConstraintsInfoFUCHSIA_bufferCollectionConstraints_offsetof||0)+")",
}, (V.VkBufferConstraintsInfoFUCHSIA_sizeof||0))));


const VkSysmemColorSpaceFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSysmemColorSpaceFUCHSIA", {
    sType: "u32("+(V.VkSysmemColorSpaceFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSysmemColorSpaceFUCHSIA_pNext_offsetof||0)+")",
    colorSpace: "u32("+(V.VkSysmemColorSpaceFUCHSIA_colorSpace_offsetof||0)+")",
}, (V.VkSysmemColorSpaceFUCHSIA_sizeof||0))));


const VkImageFormatConstraintsInfoFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageFormatConstraintsInfoFUCHSIA", {
    sType: "u32("+(V.VkImageFormatConstraintsInfoFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageFormatConstraintsInfoFUCHSIA_pNext_offsetof||0)+")",
    imageCreateInfo: "u32("+(V.VkImageFormatConstraintsInfoFUCHSIA_imageCreateInfo_offsetof||0)+")",
    requiredFormatFeatures: "u32("+(V.VkImageFormatConstraintsInfoFUCHSIA_requiredFormatFeatures_offsetof||0)+")",
    flags: "u32("+(V.VkImageFormatConstraintsInfoFUCHSIA_flags_offsetof||0)+")",
    sysmemPixelFormat: "u64("+(V.VkImageFormatConstraintsInfoFUCHSIA_sysmemPixelFormat_offsetof||0)+")",
    colorSpaceCount: "u32("+(V.VkImageFormatConstraintsInfoFUCHSIA_colorSpaceCount_offsetof||0)+")",
    pColorSpaces: "u64("+(V.VkImageFormatConstraintsInfoFUCHSIA_pColorSpaces_offsetof||0)+")",
}, (V.VkImageFormatConstraintsInfoFUCHSIA_sizeof||0))));


const VkImageConstraintsInfoFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageConstraintsInfoFUCHSIA", {
    sType: "u32("+(V.VkImageConstraintsInfoFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageConstraintsInfoFUCHSIA_pNext_offsetof||0)+")",
    formatConstraintsCount: "u32("+(V.VkImageConstraintsInfoFUCHSIA_formatConstraintsCount_offsetof||0)+")",
    pFormatConstraints: "u64("+(V.VkImageConstraintsInfoFUCHSIA_pFormatConstraints_offsetof||0)+")",
    bufferCollectionConstraints: "u32("+(V.VkImageConstraintsInfoFUCHSIA_bufferCollectionConstraints_offsetof||0)+")",
    flags: "u32("+(V.VkImageConstraintsInfoFUCHSIA_flags_offsetof||0)+")",
}, (V.VkImageConstraintsInfoFUCHSIA_sizeof||0))));


const VkBufferCollectionConstraintsInfoFUCHSIA = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkBufferCollectionConstraintsInfoFUCHSIA", {
    sType: "u32("+(V.VkBufferCollectionConstraintsInfoFUCHSIA_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkBufferCollectionConstraintsInfoFUCHSIA_pNext_offsetof||0)+")",
    minBufferCount: "u32("+(V.VkBufferCollectionConstraintsInfoFUCHSIA_minBufferCount_offsetof||0)+")",
    maxBufferCount: "u32("+(V.VkBufferCollectionConstraintsInfoFUCHSIA_maxBufferCount_offsetof||0)+")",
    minBufferCountForCamping: "u32("+(V.VkBufferCollectionConstraintsInfoFUCHSIA_minBufferCountForCamping_offsetof||0)+")",
    minBufferCountForDedicatedSlack: "u32("+(V.VkBufferCollectionConstraintsInfoFUCHSIA_minBufferCountForDedicatedSlack_offsetof||0)+")",
    minBufferCountForSharedSlack: "u32("+(V.VkBufferCollectionConstraintsInfoFUCHSIA_minBufferCountForSharedSlack_offsetof||0)+")",
}, (V.VkBufferCollectionConstraintsInfoFUCHSIA_sizeof||0))));


const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT_pNext_offsetof||0)+")",
    formatRgba10x6WithoutYCbCrSampler: "u32("+(V.VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT_formatRgba10x6WithoutYCbCrSampler_offsetof||0)+")",
}, (V.VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT_sizeof||0))));


const VkFormatProperties3 = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkFormatProperties3", {
    sType: "u32("+(V.VkFormatProperties3_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkFormatProperties3_pNext_offsetof||0)+")",
    linearTilingFeatures: "u64("+(V.VkFormatProperties3_linearTilingFeatures_offsetof||0)+")",
    optimalTilingFeatures: "u64("+(V.VkFormatProperties3_optimalTilingFeatures_offsetof||0)+")",
    bufferFeatures: "u64("+(V.VkFormatProperties3_bufferFeatures_offsetof||0)+")",
}, (V.VkFormatProperties3_sizeof||0))));

const VkFormatProperties3KHR = new Proxy(function(){}, new C.ConstructProxy("VkFormatProperties3"));


const VkDrmFormatModifierPropertiesList2EXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDrmFormatModifierPropertiesList2EXT", {
    sType: "u32("+(V.VkDrmFormatModifierPropertiesList2EXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDrmFormatModifierPropertiesList2EXT_pNext_offsetof||0)+")",
    drmFormatModifierCount: "u32("+(V.VkDrmFormatModifierPropertiesList2EXT_drmFormatModifierCount_offsetof||0)+")",
    pDrmFormatModifierProperties: "u64("+(V.VkDrmFormatModifierPropertiesList2EXT_pDrmFormatModifierProperties_offsetof||0)+")",
}, (V.VkDrmFormatModifierPropertiesList2EXT_sizeof||0))));


const VkDrmFormatModifierProperties2EXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDrmFormatModifierProperties2EXT", {
    drmFormatModifier: "u64("+(V.VkDrmFormatModifierProperties2EXT_drmFormatModifier_offsetof||0)+")",
    drmFormatModifierPlaneCount: "u32("+(V.VkDrmFormatModifierProperties2EXT_drmFormatModifierPlaneCount_offsetof||0)+")",
    drmFormatModifierTilingFeatures: "u64("+(V.VkDrmFormatModifierProperties2EXT_drmFormatModifierTilingFeatures_offsetof||0)+")",
}, (V.VkDrmFormatModifierProperties2EXT_sizeof||0))));


const VkAndroidHardwareBufferFormatProperties2ANDROID = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAndroidHardwareBufferFormatProperties2ANDROID", {
    sType: "u32("+(V.VkAndroidHardwareBufferFormatProperties2ANDROID_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAndroidHardwareBufferFormatProperties2ANDROID_pNext_offsetof||0)+")",
    format: "u32("+(V.VkAndroidHardwareBufferFormatProperties2ANDROID_format_offsetof||0)+")",
    externalFormat: "u64("+(V.VkAndroidHardwareBufferFormatProperties2ANDROID_externalFormat_offsetof||0)+")",
    formatFeatures: "u64("+(V.VkAndroidHardwareBufferFormatProperties2ANDROID_formatFeatures_offsetof||0)+")",
    samplerYcbcrConversionComponents: "u32("+(V.VkAndroidHardwareBufferFormatProperties2ANDROID_samplerYcbcrConversionComponents_offsetof||0)+")",
    suggestedYcbcrModel: "u32("+(V.VkAndroidHardwareBufferFormatProperties2ANDROID_suggestedYcbcrModel_offsetof||0)+")",
    suggestedYcbcrRange: "u32("+(V.VkAndroidHardwareBufferFormatProperties2ANDROID_suggestedYcbcrRange_offsetof||0)+")",
    suggestedXChromaOffset: "u32("+(V.VkAndroidHardwareBufferFormatProperties2ANDROID_suggestedXChromaOffset_offsetof||0)+")",
    suggestedYChromaOffset: "u32("+(V.VkAndroidHardwareBufferFormatProperties2ANDROID_suggestedYChromaOffset_offsetof||0)+")",
}, (V.VkAndroidHardwareBufferFormatProperties2ANDROID_sizeof||0))));


const VkPipelineRenderingCreateInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineRenderingCreateInfo", {
    sType: "u32("+(V.VkPipelineRenderingCreateInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineRenderingCreateInfo_pNext_offsetof||0)+")",
    viewMask: "u32("+(V.VkPipelineRenderingCreateInfo_viewMask_offsetof||0)+")",
    colorAttachmentCount: "u32("+(V.VkPipelineRenderingCreateInfo_colorAttachmentCount_offsetof||0)+")",
    pColorAttachmentFormats: "u64("+(V.VkPipelineRenderingCreateInfo_pColorAttachmentFormats_offsetof||0)+")",
    depthAttachmentFormat: "u32("+(V.VkPipelineRenderingCreateInfo_depthAttachmentFormat_offsetof||0)+")",
    stencilAttachmentFormat: "u32("+(V.VkPipelineRenderingCreateInfo_stencilAttachmentFormat_offsetof||0)+")",
}, (V.VkPipelineRenderingCreateInfo_sizeof||0))));

const VkPipelineRenderingCreateInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkPipelineRenderingCreateInfo"));


const VkRenderingInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderingInfo", {
    sType: "u32("+(V.VkRenderingInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderingInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkRenderingInfo_flags_offsetof||0)+")",
    renderArea: "VkRect2D("+(V.VkRenderingInfo_renderArea_offsetof||0)+")",
    layerCount: "u32("+(V.VkRenderingInfo_layerCount_offsetof||0)+")",
    viewMask: "u32("+(V.VkRenderingInfo_viewMask_offsetof||0)+")",
    colorAttachmentCount: "u32("+(V.VkRenderingInfo_colorAttachmentCount_offsetof||0)+")",
    pColorAttachments: "u64("+(V.VkRenderingInfo_pColorAttachments_offsetof||0)+")",
    pDepthAttachment: "u64("+(V.VkRenderingInfo_pDepthAttachment_offsetof||0)+")",
    pStencilAttachment: "u64("+(V.VkRenderingInfo_pStencilAttachment_offsetof||0)+")",
}, (V.VkRenderingInfo_sizeof||0))));

const VkRenderingInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkRenderingInfo"));


const VkRenderingAttachmentInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderingAttachmentInfo", {
    sType: "u32("+(V.VkRenderingAttachmentInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderingAttachmentInfo_pNext_offsetof||0)+")",
    imageView: "u32("+(V.VkRenderingAttachmentInfo_imageView_offsetof||0)+")",
    imageLayout: "u32("+(V.VkRenderingAttachmentInfo_imageLayout_offsetof||0)+")",
    resolveMode: "u32("+(V.VkRenderingAttachmentInfo_resolveMode_offsetof||0)+")",
    resolveImageView: "u32("+(V.VkRenderingAttachmentInfo_resolveImageView_offsetof||0)+")",
    resolveImageLayout: "u32("+(V.VkRenderingAttachmentInfo_resolveImageLayout_offsetof||0)+")",
    loadOp: "u32("+(V.VkRenderingAttachmentInfo_loadOp_offsetof||0)+")",
    storeOp: "u32("+(V.VkRenderingAttachmentInfo_storeOp_offsetof||0)+")",
    clearValue: "u32("+(V.VkRenderingAttachmentInfo_clearValue_offsetof||0)+")",
}, (V.VkRenderingAttachmentInfo_sizeof||0))));

const VkRenderingAttachmentInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkRenderingAttachmentInfo"));


const VkRenderingFragmentShadingRateAttachmentInfoKHR = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderingFragmentShadingRateAttachmentInfoKHR", {
    sType: "u32("+(V.VkRenderingFragmentShadingRateAttachmentInfoKHR_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderingFragmentShadingRateAttachmentInfoKHR_pNext_offsetof||0)+")",
    imageView: "u32("+(V.VkRenderingFragmentShadingRateAttachmentInfoKHR_imageView_offsetof||0)+")",
    imageLayout: "u32("+(V.VkRenderingFragmentShadingRateAttachmentInfoKHR_imageLayout_offsetof||0)+")",
    shadingRateAttachmentTexelSize: "VkExtent2D("+(V.VkRenderingFragmentShadingRateAttachmentInfoKHR_shadingRateAttachmentTexelSize_offsetof||0)+")",
}, (V.VkRenderingFragmentShadingRateAttachmentInfoKHR_sizeof||0))));


const VkRenderingFragmentDensityMapAttachmentInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderingFragmentDensityMapAttachmentInfoEXT", {
    sType: "u32("+(V.VkRenderingFragmentDensityMapAttachmentInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderingFragmentDensityMapAttachmentInfoEXT_pNext_offsetof||0)+")",
    imageView: "u32("+(V.VkRenderingFragmentDensityMapAttachmentInfoEXT_imageView_offsetof||0)+")",
    imageLayout: "u32("+(V.VkRenderingFragmentDensityMapAttachmentInfoEXT_imageLayout_offsetof||0)+")",
}, (V.VkRenderingFragmentDensityMapAttachmentInfoEXT_sizeof||0))));


const VkPhysicalDeviceDynamicRenderingFeatures = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDynamicRenderingFeatures", {
    sType: "u32("+(V.VkPhysicalDeviceDynamicRenderingFeatures_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDynamicRenderingFeatures_pNext_offsetof||0)+")",
    dynamicRendering: "u32("+(V.VkPhysicalDeviceDynamicRenderingFeatures_dynamicRendering_offsetof||0)+")",
}, (V.VkPhysicalDeviceDynamicRenderingFeatures_sizeof||0))));

const VkPhysicalDeviceDynamicRenderingFeaturesKHR = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceDynamicRenderingFeatures"));


const VkCommandBufferInheritanceRenderingInfo = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCommandBufferInheritanceRenderingInfo", {
    sType: "u32("+(V.VkCommandBufferInheritanceRenderingInfo_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCommandBufferInheritanceRenderingInfo_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkCommandBufferInheritanceRenderingInfo_flags_offsetof||0)+")",
    viewMask: "u32("+(V.VkCommandBufferInheritanceRenderingInfo_viewMask_offsetof||0)+")",
    colorAttachmentCount: "u32("+(V.VkCommandBufferInheritanceRenderingInfo_colorAttachmentCount_offsetof||0)+")",
    pColorAttachmentFormats: "u64("+(V.VkCommandBufferInheritanceRenderingInfo_pColorAttachmentFormats_offsetof||0)+")",
    depthAttachmentFormat: "u32("+(V.VkCommandBufferInheritanceRenderingInfo_depthAttachmentFormat_offsetof||0)+")",
    stencilAttachmentFormat: "u32("+(V.VkCommandBufferInheritanceRenderingInfo_stencilAttachmentFormat_offsetof||0)+")",
    rasterizationSamples: "u32("+(V.VkCommandBufferInheritanceRenderingInfo_rasterizationSamples_offsetof||0)+")",
}, (V.VkCommandBufferInheritanceRenderingInfo_sizeof||0))));

const VkCommandBufferInheritanceRenderingInfoKHR = new Proxy(function(){}, new C.ConstructProxy("VkCommandBufferInheritanceRenderingInfo"));


const VkAttachmentSampleCountInfoAMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAttachmentSampleCountInfoAMD", {
    sType: "u32("+(V.VkAttachmentSampleCountInfoAMD_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAttachmentSampleCountInfoAMD_pNext_offsetof||0)+")",
    colorAttachmentCount: "u32("+(V.VkAttachmentSampleCountInfoAMD_colorAttachmentCount_offsetof||0)+")",
    pColorAttachmentSamples: "u64("+(V.VkAttachmentSampleCountInfoAMD_pColorAttachmentSamples_offsetof||0)+")",
    depthStencilAttachmentSamples: "u32("+(V.VkAttachmentSampleCountInfoAMD_depthStencilAttachmentSamples_offsetof||0)+")",
}, (V.VkAttachmentSampleCountInfoAMD_sizeof||0))));

const VkAttachmentSampleCountInfoNV = new Proxy(function(){}, new C.ConstructProxy("VkAttachmentSampleCountInfoAMD"));


const VkMultiviewPerViewAttributesInfoNVX = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMultiviewPerViewAttributesInfoNVX", {
    sType: "u32("+(V.VkMultiviewPerViewAttributesInfoNVX_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMultiviewPerViewAttributesInfoNVX_pNext_offsetof||0)+")",
    perViewAttributes: "u32("+(V.VkMultiviewPerViewAttributesInfoNVX_perViewAttributes_offsetof||0)+")",
    perViewAttributesPositionXOnly: "u32("+(V.VkMultiviewPerViewAttributesInfoNVX_perViewAttributesPositionXOnly_offsetof||0)+")",
}, (V.VkMultiviewPerViewAttributesInfoNVX_sizeof||0))));


const VkPhysicalDeviceImageViewMinLodFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceImageViewMinLodFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceImageViewMinLodFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceImageViewMinLodFeaturesEXT_pNext_offsetof||0)+")",
    minLod: "u32("+(V.VkPhysicalDeviceImageViewMinLodFeaturesEXT_minLod_offsetof||0)+")",
}, (V.VkPhysicalDeviceImageViewMinLodFeaturesEXT_sizeof||0))));


const VkImageViewMinLodCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageViewMinLodCreateInfoEXT", {
    sType: "u32("+(V.VkImageViewMinLodCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageViewMinLodCreateInfoEXT_pNext_offsetof||0)+")",
    minLod: "f32("+(V.VkImageViewMinLodCreateInfoEXT_minLod_offsetof||0)+")",
}, (V.VkImageViewMinLodCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_pNext_offsetof||0)+")",
    rasterizationOrderColorAttachmentAccess: "u32("+(V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_rasterizationOrderColorAttachmentAccess_offsetof||0)+")",
    rasterizationOrderDepthAttachmentAccess: "u32("+(V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_rasterizationOrderDepthAttachmentAccess_offsetof||0)+")",
    rasterizationOrderStencilAttachmentAccess: "u32("+(V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_rasterizationOrderStencilAttachmentAccess_offsetof||0)+")",
}, (V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_sizeof||0))));

const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM = new Proxy(function(){}, new C.ConstructProxy("VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT"));


const VkPhysicalDeviceLinearColorAttachmentFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceLinearColorAttachmentFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceLinearColorAttachmentFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceLinearColorAttachmentFeaturesNV_pNext_offsetof||0)+")",
    linearColorAttachment: "u32("+(V.VkPhysicalDeviceLinearColorAttachmentFeaturesNV_linearColorAttachment_offsetof||0)+")",
}, (V.VkPhysicalDeviceLinearColorAttachmentFeaturesNV_sizeof||0))));


const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT_pNext_offsetof||0)+")",
    graphicsPipelineLibrary: "u32("+(V.VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT_graphicsPipelineLibrary_offsetof||0)+")",
}, (V.VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT_pNext_offsetof||0)+")",
    graphicsPipelineLibraryFastLinking: "u32("+(V.VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT_graphicsPipelineLibraryFastLinking_offsetof||0)+")",
    graphicsPipelineLibraryIndependentInterpolationDecoration: "u32("+(V.VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT_graphicsPipelineLibraryIndependentInterpolationDecoration_offsetof||0)+")",
}, (V.VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT_sizeof||0))));


const VkGraphicsPipelineLibraryCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkGraphicsPipelineLibraryCreateInfoEXT", {
    sType: "u32("+(V.VkGraphicsPipelineLibraryCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkGraphicsPipelineLibraryCreateInfoEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkGraphicsPipelineLibraryCreateInfoEXT_flags_offsetof||0)+")",
}, (V.VkGraphicsPipelineLibraryCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE", {
    sType: "u32("+(V.VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE_pNext_offsetof||0)+")",
    descriptorSetHostMapping: "u32("+(V.VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE_descriptorSetHostMapping_offsetof||0)+")",
}, (V.VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE_sizeof||0))));


const VkDescriptorSetBindingReferenceVALVE = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorSetBindingReferenceVALVE", {
    sType: "u32("+(V.VkDescriptorSetBindingReferenceVALVE_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDescriptorSetBindingReferenceVALVE_pNext_offsetof||0)+")",
    descriptorSetLayout: "u32("+(V.VkDescriptorSetBindingReferenceVALVE_descriptorSetLayout_offsetof||0)+")",
    binding: "u32("+(V.VkDescriptorSetBindingReferenceVALVE_binding_offsetof||0)+")",
}, (V.VkDescriptorSetBindingReferenceVALVE_sizeof||0))));


const VkDescriptorSetLayoutHostMappingInfoVALVE = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDescriptorSetLayoutHostMappingInfoVALVE", {
    sType: "u32("+(V.VkDescriptorSetLayoutHostMappingInfoVALVE_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDescriptorSetLayoutHostMappingInfoVALVE_pNext_offsetof||0)+")",
    descriptorOffset: "u64("+(V.VkDescriptorSetLayoutHostMappingInfoVALVE_descriptorOffset_offsetof||0)+")",
    descriptorSize: "u32("+(V.VkDescriptorSetLayoutHostMappingInfoVALVE_descriptorSize_offsetof||0)+")",
}, (V.VkDescriptorSetLayoutHostMappingInfoVALVE_sizeof||0))));


const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT_pNext_offsetof||0)+")",
    shaderModuleIdentifier: "u32("+(V.VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT_shaderModuleIdentifier_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT_pNext_offsetof||0)+")",
    shaderModuleIdentifierAlgorithmUUID: "u8["+(E.VK_UUID_SIZE||1)+"]("+(V.VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT_shaderModuleIdentifierAlgorithmUUID_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT_sizeof||0))));


const VkPipelineShaderStageModuleIdentifierCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineShaderStageModuleIdentifierCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineShaderStageModuleIdentifierCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineShaderStageModuleIdentifierCreateInfoEXT_pNext_offsetof||0)+")",
    identifierSize: "u32("+(V.VkPipelineShaderStageModuleIdentifierCreateInfoEXT_identifierSize_offsetof||0)+")",
    pIdentifier: "u64("+(V.VkPipelineShaderStageModuleIdentifierCreateInfoEXT_pIdentifier_offsetof||0)+")",
}, (V.VkPipelineShaderStageModuleIdentifierCreateInfoEXT_sizeof||0))));


const VkShaderModuleIdentifierEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkShaderModuleIdentifierEXT", {
    sType: "u32("+(V.VkShaderModuleIdentifierEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkShaderModuleIdentifierEXT_pNext_offsetof||0)+")",
    identifierSize: "u32("+(V.VkShaderModuleIdentifierEXT_identifierSize_offsetof||0)+")",
    identifier: "u8["+(E.VK_MAX_SHADER_MODULE_IDENTIFIER_SIZE_EXT||1)+"]("+(V.VkShaderModuleIdentifierEXT_identifier_offsetof||0)+")",
}, (V.VkShaderModuleIdentifierEXT_sizeof||0))));


const VkImageCompressionControlEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageCompressionControlEXT", {
    sType: "u32("+(V.VkImageCompressionControlEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageCompressionControlEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkImageCompressionControlEXT_flags_offsetof||0)+")",
    compressionControlPlaneCount: "u32("+(V.VkImageCompressionControlEXT_compressionControlPlaneCount_offsetof||0)+")",
    pFixedRateFlags: "u64("+(V.VkImageCompressionControlEXT_pFixedRateFlags_offsetof||0)+")",
}, (V.VkImageCompressionControlEXT_sizeof||0))));


const VkPhysicalDeviceImageCompressionControlFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceImageCompressionControlFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceImageCompressionControlFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceImageCompressionControlFeaturesEXT_pNext_offsetof||0)+")",
    imageCompressionControl: "u32("+(V.VkPhysicalDeviceImageCompressionControlFeaturesEXT_imageCompressionControl_offsetof||0)+")",
}, (V.VkPhysicalDeviceImageCompressionControlFeaturesEXT_sizeof||0))));


const VkImageCompressionPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageCompressionPropertiesEXT", {
    sType: "u32("+(V.VkImageCompressionPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageCompressionPropertiesEXT_pNext_offsetof||0)+")",
    imageCompressionFlags: "u32("+(V.VkImageCompressionPropertiesEXT_imageCompressionFlags_offsetof||0)+")",
    imageCompressionFixedRateFlags: "u32("+(V.VkImageCompressionPropertiesEXT_imageCompressionFixedRateFlags_offsetof||0)+")",
}, (V.VkImageCompressionPropertiesEXT_sizeof||0))));


const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT_pNext_offsetof||0)+")",
    imageCompressionControlSwapchain: "u32("+(V.VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT_imageCompressionControlSwapchain_offsetof||0)+")",
}, (V.VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT_sizeof||0))));


const VkImageSubresource2EXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageSubresource2EXT", {
    sType: "u32("+(V.VkImageSubresource2EXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageSubresource2EXT_pNext_offsetof||0)+")",
    imageSubresource: "u32("+(V.VkImageSubresource2EXT_imageSubresource_offsetof||0)+")",
}, (V.VkImageSubresource2EXT_sizeof||0))));


const VkSubresourceLayout2EXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkSubresourceLayout2EXT", {
    sType: "u32("+(V.VkSubresourceLayout2EXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkSubresourceLayout2EXT_pNext_offsetof||0)+")",
    subresourceLayout: "u32("+(V.VkSubresourceLayout2EXT_subresourceLayout_offsetof||0)+")",
}, (V.VkSubresourceLayout2EXT_sizeof||0))));


const VkRenderPassCreationControlEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassCreationControlEXT", {
    sType: "u32("+(V.VkRenderPassCreationControlEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderPassCreationControlEXT_pNext_offsetof||0)+")",
    disallowMerging: "u32("+(V.VkRenderPassCreationControlEXT_disallowMerging_offsetof||0)+")",
}, (V.VkRenderPassCreationControlEXT_sizeof||0))));


const VkRenderPassCreationFeedbackInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassCreationFeedbackInfoEXT", {
    postMergeSubpassCount: "u32("+(V.VkRenderPassCreationFeedbackInfoEXT_postMergeSubpassCount_offsetof||0)+")",
}, (V.VkRenderPassCreationFeedbackInfoEXT_sizeof||0))));


const VkRenderPassCreationFeedbackCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassCreationFeedbackCreateInfoEXT", {
    sType: "u32("+(V.VkRenderPassCreationFeedbackCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderPassCreationFeedbackCreateInfoEXT_pNext_offsetof||0)+")",
    pRenderPassFeedback: "u64("+(V.VkRenderPassCreationFeedbackCreateInfoEXT_pRenderPassFeedback_offsetof||0)+")",
}, (V.VkRenderPassCreationFeedbackCreateInfoEXT_sizeof||0))));


const VkRenderPassSubpassFeedbackInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassSubpassFeedbackInfoEXT", {
    subpassMergeStatus: "u32("+(V.VkRenderPassSubpassFeedbackInfoEXT_subpassMergeStatus_offsetof||0)+")",
    description: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkRenderPassSubpassFeedbackInfoEXT_description_offsetof||0)+")",
    postMergeIndex: "u32("+(V.VkRenderPassSubpassFeedbackInfoEXT_postMergeIndex_offsetof||0)+")",
}, (V.VkRenderPassSubpassFeedbackInfoEXT_sizeof||0))));


const VkRenderPassSubpassFeedbackCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkRenderPassSubpassFeedbackCreateInfoEXT", {
    sType: "u32("+(V.VkRenderPassSubpassFeedbackCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkRenderPassSubpassFeedbackCreateInfoEXT_pNext_offsetof||0)+")",
    pSubpassFeedback: "u64("+(V.VkRenderPassSubpassFeedbackCreateInfoEXT_pSubpassFeedback_offsetof||0)+")",
}, (V.VkRenderPassSubpassFeedbackCreateInfoEXT_sizeof||0))));


const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT_pNext_offsetof||0)+")",
    subpassMergeFeedback: "u32("+(V.VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT_subpassMergeFeedback_offsetof||0)+")",
}, (V.VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT_sizeof||0))));


const VkMicromapBuildInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMicromapBuildInfoEXT", {
    sType: "u32("+(V.VkMicromapBuildInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMicromapBuildInfoEXT_pNext_offsetof||0)+")",
    type: "u32("+(V.VkMicromapBuildInfoEXT_type_offsetof||0)+")",
    flags: "u32("+(V.VkMicromapBuildInfoEXT_flags_offsetof||0)+")",
    mode: "u32("+(V.VkMicromapBuildInfoEXT_mode_offsetof||0)+")",
    dstMicromap: "u32("+(V.VkMicromapBuildInfoEXT_dstMicromap_offsetof||0)+")",
    usageCountsCount: "u32("+(V.VkMicromapBuildInfoEXT_usageCountsCount_offsetof||0)+")",
    pUsageCounts: "u64("+(V.VkMicromapBuildInfoEXT_pUsageCounts_offsetof||0)+")",
    ppUsageCounts: "u64("+(V.VkMicromapBuildInfoEXT_ppUsageCounts_offsetof||0)+")",
    data: "u32("+(V.VkMicromapBuildInfoEXT_data_offsetof||0)+")",
    scratchData: "u64("+(V.VkMicromapBuildInfoEXT_scratchData_offsetof||0)+")",
    triangleArray: "u32("+(V.VkMicromapBuildInfoEXT_triangleArray_offsetof||0)+")",
    triangleArrayStride: "u64("+(V.VkMicromapBuildInfoEXT_triangleArrayStride_offsetof||0)+")",
}, (V.VkMicromapBuildInfoEXT_sizeof||0))));


const VkMicromapCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMicromapCreateInfoEXT", {
    sType: "u32("+(V.VkMicromapCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMicromapCreateInfoEXT_pNext_offsetof||0)+")",
    createFlags: "u32("+(V.VkMicromapCreateInfoEXT_createFlags_offsetof||0)+")",
    buffer: "u64("+(V.VkMicromapCreateInfoEXT_buffer_offsetof||0)+")",
    offset: "u64("+(V.VkMicromapCreateInfoEXT_offset_offsetof||0)+")",
    size: "u64("+(V.VkMicromapCreateInfoEXT_size_offsetof||0)+")",
    type: "u32("+(V.VkMicromapCreateInfoEXT_type_offsetof||0)+")",
    deviceAddress: "u64("+(V.VkMicromapCreateInfoEXT_deviceAddress_offsetof||0)+")",
}, (V.VkMicromapCreateInfoEXT_sizeof||0))));


const VkMicromapVersionInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMicromapVersionInfoEXT", {
    sType: "u32("+(V.VkMicromapVersionInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMicromapVersionInfoEXT_pNext_offsetof||0)+")",
    pVersionData: "u64("+(V.VkMicromapVersionInfoEXT_pVersionData_offsetof||0)+")",
}, (V.VkMicromapVersionInfoEXT_sizeof||0))));


const VkCopyMicromapInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyMicromapInfoEXT", {
    sType: "u32("+(V.VkCopyMicromapInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCopyMicromapInfoEXT_pNext_offsetof||0)+")",
    src: "u32("+(V.VkCopyMicromapInfoEXT_src_offsetof||0)+")",
    dst: "u32("+(V.VkCopyMicromapInfoEXT_dst_offsetof||0)+")",
    mode: "u32("+(V.VkCopyMicromapInfoEXT_mode_offsetof||0)+")",
}, (V.VkCopyMicromapInfoEXT_sizeof||0))));


const VkCopyMicromapToMemoryInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyMicromapToMemoryInfoEXT", {
    sType: "u32("+(V.VkCopyMicromapToMemoryInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCopyMicromapToMemoryInfoEXT_pNext_offsetof||0)+")",
    src: "u32("+(V.VkCopyMicromapToMemoryInfoEXT_src_offsetof||0)+")",
    dst: "u64("+(V.VkCopyMicromapToMemoryInfoEXT_dst_offsetof||0)+")",
    mode: "u32("+(V.VkCopyMicromapToMemoryInfoEXT_mode_offsetof||0)+")",
}, (V.VkCopyMicromapToMemoryInfoEXT_sizeof||0))));


const VkCopyMemoryToMicromapInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkCopyMemoryToMicromapInfoEXT", {
    sType: "u32("+(V.VkCopyMemoryToMicromapInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkCopyMemoryToMicromapInfoEXT_pNext_offsetof||0)+")",
    src: "u32("+(V.VkCopyMemoryToMicromapInfoEXT_src_offsetof||0)+")",
    dst: "u32("+(V.VkCopyMemoryToMicromapInfoEXT_dst_offsetof||0)+")",
    mode: "u32("+(V.VkCopyMemoryToMicromapInfoEXT_mode_offsetof||0)+")",
}, (V.VkCopyMemoryToMicromapInfoEXT_sizeof||0))));


const VkMicromapBuildSizesInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMicromapBuildSizesInfoEXT", {
    sType: "u32("+(V.VkMicromapBuildSizesInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkMicromapBuildSizesInfoEXT_pNext_offsetof||0)+")",
    micromapSize: "u64("+(V.VkMicromapBuildSizesInfoEXT_micromapSize_offsetof||0)+")",
    buildScratchSize: "u64("+(V.VkMicromapBuildSizesInfoEXT_buildScratchSize_offsetof||0)+")",
    discardable: "u32("+(V.VkMicromapBuildSizesInfoEXT_discardable_offsetof||0)+")",
}, (V.VkMicromapBuildSizesInfoEXT_sizeof||0))));


const VkMicromapUsageEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMicromapUsageEXT", {
    count: "u32("+(V.VkMicromapUsageEXT_count_offsetof||0)+")",
    subdivisionLevel: "u32("+(V.VkMicromapUsageEXT_subdivisionLevel_offsetof||0)+")",
    format: "u32("+(V.VkMicromapUsageEXT_format_offsetof||0)+")",
}, (V.VkMicromapUsageEXT_sizeof||0))));


const VkMicromapTriangleEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkMicromapTriangleEXT", {
    dataOffset: "u32("+(V.VkMicromapTriangleEXT_dataOffset_offsetof||0)+")",
    subdivisionLevel: "u16("+(V.VkMicromapTriangleEXT_subdivisionLevel_offsetof||0)+")",
    format: "u16("+(V.VkMicromapTriangleEXT_format_offsetof||0)+")",
}, (V.VkMicromapTriangleEXT_sizeof||0))));


const VkPhysicalDeviceOpacityMicromapFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceOpacityMicromapFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceOpacityMicromapFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceOpacityMicromapFeaturesEXT_pNext_offsetof||0)+")",
    micromap: "u32("+(V.VkPhysicalDeviceOpacityMicromapFeaturesEXT_micromap_offsetof||0)+")",
    micromapCaptureReplay: "u32("+(V.VkPhysicalDeviceOpacityMicromapFeaturesEXT_micromapCaptureReplay_offsetof||0)+")",
    micromapHostCommands: "u32("+(V.VkPhysicalDeviceOpacityMicromapFeaturesEXT_micromapHostCommands_offsetof||0)+")",
}, (V.VkPhysicalDeviceOpacityMicromapFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceOpacityMicromapPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceOpacityMicromapPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceOpacityMicromapPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceOpacityMicromapPropertiesEXT_pNext_offsetof||0)+")",
    maxOpacity2StateSubdivisionLevel: "u32("+(V.VkPhysicalDeviceOpacityMicromapPropertiesEXT_maxOpacity2StateSubdivisionLevel_offsetof||0)+")",
    maxOpacity4StateSubdivisionLevel: "u32("+(V.VkPhysicalDeviceOpacityMicromapPropertiesEXT_maxOpacity4StateSubdivisionLevel_offsetof||0)+")",
}, (V.VkPhysicalDeviceOpacityMicromapPropertiesEXT_sizeof||0))));


const VkAccelerationStructureTrianglesOpacityMicromapEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAccelerationStructureTrianglesOpacityMicromapEXT", {
    sType: "u32("+(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_pNext_offsetof||0)+")",
    indexType: "u32("+(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_indexType_offsetof||0)+")",
    indexBuffer: "u32("+(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_indexBuffer_offsetof||0)+")",
    indexStride: "u64("+(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_indexStride_offsetof||0)+")",
    baseTriangle: "u32("+(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_baseTriangle_offsetof||0)+")",
    usageCountsCount: "u32("+(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_usageCountsCount_offsetof||0)+")",
    pUsageCounts: "u64("+(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_pUsageCounts_offsetof||0)+")",
    ppUsageCounts: "u64("+(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_ppUsageCounts_offsetof||0)+")",
    micromap: "u32("+(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_micromap_offsetof||0)+")",
}, (V.VkAccelerationStructureTrianglesOpacityMicromapEXT_sizeof||0))));


const VkPipelinePropertiesIdentifierEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelinePropertiesIdentifierEXT", {
    sType: "u32("+(V.VkPipelinePropertiesIdentifierEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelinePropertiesIdentifierEXT_pNext_offsetof||0)+")",
    pipelineIdentifier: "u8["+(E.VK_UUID_SIZE||1)+"]("+(V.VkPipelinePropertiesIdentifierEXT_pipelineIdentifier_offsetof||0)+")",
}, (V.VkPipelinePropertiesIdentifierEXT_sizeof||0))));


const VkPhysicalDevicePipelinePropertiesFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePipelinePropertiesFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDevicePipelinePropertiesFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePipelinePropertiesFeaturesEXT_pNext_offsetof||0)+")",
    pipelinePropertiesIdentifier: "u32("+(V.VkPhysicalDevicePipelinePropertiesFeaturesEXT_pipelinePropertiesIdentifier_offsetof||0)+")",
}, (V.VkPhysicalDevicePipelinePropertiesFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD", {
    sType: "u32("+(V.VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD_pNext_offsetof||0)+")",
    shaderEarlyAndLateFragmentTests: "u32("+(V.VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD_shaderEarlyAndLateFragmentTests_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD_sizeof||0))));


const VkExportMetalObjectCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportMetalObjectCreateInfoEXT", {
    sType: "u32("+(V.VkExportMetalObjectCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportMetalObjectCreateInfoEXT_pNext_offsetof||0)+")",
    exportObjectType: "u32("+(V.VkExportMetalObjectCreateInfoEXT_exportObjectType_offsetof||0)+")",
}, (V.VkExportMetalObjectCreateInfoEXT_sizeof||0))));


const VkExportMetalObjectsInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportMetalObjectsInfoEXT", {
    sType: "u32("+(V.VkExportMetalObjectsInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportMetalObjectsInfoEXT_pNext_offsetof||0)+")",
}, (V.VkExportMetalObjectsInfoEXT_sizeof||0))));


const VkExportMetalDeviceInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportMetalDeviceInfoEXT", {
    sType: "u32("+(V.VkExportMetalDeviceInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportMetalDeviceInfoEXT_pNext_offsetof||0)+")",
    mtlDevice: "u32("+(V.VkExportMetalDeviceInfoEXT_mtlDevice_offsetof||0)+")",
}, (V.VkExportMetalDeviceInfoEXT_sizeof||0))));


const VkExportMetalCommandQueueInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportMetalCommandQueueInfoEXT", {
    sType: "u32("+(V.VkExportMetalCommandQueueInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportMetalCommandQueueInfoEXT_pNext_offsetof||0)+")",
    queue: "u64("+(V.VkExportMetalCommandQueueInfoEXT_queue_offsetof||0)+")",
    mtlCommandQueue: "u32("+(V.VkExportMetalCommandQueueInfoEXT_mtlCommandQueue_offsetof||0)+")",
}, (V.VkExportMetalCommandQueueInfoEXT_sizeof||0))));


const VkExportMetalBufferInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportMetalBufferInfoEXT", {
    sType: "u32("+(V.VkExportMetalBufferInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportMetalBufferInfoEXT_pNext_offsetof||0)+")",
    memory: "u64("+(V.VkExportMetalBufferInfoEXT_memory_offsetof||0)+")",
    mtlBuffer: "u32("+(V.VkExportMetalBufferInfoEXT_mtlBuffer_offsetof||0)+")",
}, (V.VkExportMetalBufferInfoEXT_sizeof||0))));


const VkImportMetalBufferInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportMetalBufferInfoEXT", {
    sType: "u32("+(V.VkImportMetalBufferInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportMetalBufferInfoEXT_pNext_offsetof||0)+")",
    mtlBuffer: "u32("+(V.VkImportMetalBufferInfoEXT_mtlBuffer_offsetof||0)+")",
}, (V.VkImportMetalBufferInfoEXT_sizeof||0))));


const VkExportMetalTextureInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportMetalTextureInfoEXT", {
    sType: "u32("+(V.VkExportMetalTextureInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportMetalTextureInfoEXT_pNext_offsetof||0)+")",
    image: "u64("+(V.VkExportMetalTextureInfoEXT_image_offsetof||0)+")",
    imageView: "u32("+(V.VkExportMetalTextureInfoEXT_imageView_offsetof||0)+")",
    bufferView: "u32("+(V.VkExportMetalTextureInfoEXT_bufferView_offsetof||0)+")",
    plane: "u32("+(V.VkExportMetalTextureInfoEXT_plane_offsetof||0)+")",
    mtlTexture: "u32("+(V.VkExportMetalTextureInfoEXT_mtlTexture_offsetof||0)+")",
}, (V.VkExportMetalTextureInfoEXT_sizeof||0))));


const VkImportMetalTextureInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportMetalTextureInfoEXT", {
    sType: "u32("+(V.VkImportMetalTextureInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportMetalTextureInfoEXT_pNext_offsetof||0)+")",
    plane: "u32("+(V.VkImportMetalTextureInfoEXT_plane_offsetof||0)+")",
    mtlTexture: "u32("+(V.VkImportMetalTextureInfoEXT_mtlTexture_offsetof||0)+")",
}, (V.VkImportMetalTextureInfoEXT_sizeof||0))));


const VkExportMetalIOSurfaceInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportMetalIOSurfaceInfoEXT", {
    sType: "u32("+(V.VkExportMetalIOSurfaceInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportMetalIOSurfaceInfoEXT_pNext_offsetof||0)+")",
    image: "u64("+(V.VkExportMetalIOSurfaceInfoEXT_image_offsetof||0)+")",
    ioSurface: "u32("+(V.VkExportMetalIOSurfaceInfoEXT_ioSurface_offsetof||0)+")",
}, (V.VkExportMetalIOSurfaceInfoEXT_sizeof||0))));


const VkImportMetalIOSurfaceInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportMetalIOSurfaceInfoEXT", {
    sType: "u32("+(V.VkImportMetalIOSurfaceInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportMetalIOSurfaceInfoEXT_pNext_offsetof||0)+")",
    ioSurface: "u32("+(V.VkImportMetalIOSurfaceInfoEXT_ioSurface_offsetof||0)+")",
}, (V.VkImportMetalIOSurfaceInfoEXT_sizeof||0))));


const VkExportMetalSharedEventInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkExportMetalSharedEventInfoEXT", {
    sType: "u32("+(V.VkExportMetalSharedEventInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkExportMetalSharedEventInfoEXT_pNext_offsetof||0)+")",
    semaphore: "u64("+(V.VkExportMetalSharedEventInfoEXT_semaphore_offsetof||0)+")",
    event: "u32("+(V.VkExportMetalSharedEventInfoEXT_event_offsetof||0)+")",
    mtlSharedEvent: "u32("+(V.VkExportMetalSharedEventInfoEXT_mtlSharedEvent_offsetof||0)+")",
}, (V.VkExportMetalSharedEventInfoEXT_sizeof||0))));


const VkImportMetalSharedEventInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImportMetalSharedEventInfoEXT", {
    sType: "u32("+(V.VkImportMetalSharedEventInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImportMetalSharedEventInfoEXT_pNext_offsetof||0)+")",
    mtlSharedEvent: "u32("+(V.VkImportMetalSharedEventInfoEXT_mtlSharedEvent_offsetof||0)+")",
}, (V.VkImportMetalSharedEventInfoEXT_sizeof||0))));


const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT_pNext_offsetof||0)+")",
    nonSeamlessCubeMap: "u32("+(V.VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT_nonSeamlessCubeMap_offsetof||0)+")",
}, (V.VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT_sizeof||0))));


const VkPhysicalDevicePipelineRobustnessFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePipelineRobustnessFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDevicePipelineRobustnessFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePipelineRobustnessFeaturesEXT_pNext_offsetof||0)+")",
    pipelineRobustness: "u32("+(V.VkPhysicalDevicePipelineRobustnessFeaturesEXT_pipelineRobustness_offsetof||0)+")",
}, (V.VkPhysicalDevicePipelineRobustnessFeaturesEXT_sizeof||0))));


const VkPipelineRobustnessCreateInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPipelineRobustnessCreateInfoEXT", {
    sType: "u32("+(V.VkPipelineRobustnessCreateInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPipelineRobustnessCreateInfoEXT_pNext_offsetof||0)+")",
    storageBuffers: "u32("+(V.VkPipelineRobustnessCreateInfoEXT_storageBuffers_offsetof||0)+")",
    uniformBuffers: "u32("+(V.VkPipelineRobustnessCreateInfoEXT_uniformBuffers_offsetof||0)+")",
    vertexInputs: "u32("+(V.VkPipelineRobustnessCreateInfoEXT_vertexInputs_offsetof||0)+")",
    images: "u32("+(V.VkPipelineRobustnessCreateInfoEXT_images_offsetof||0)+")",
}, (V.VkPipelineRobustnessCreateInfoEXT_sizeof||0))));


const VkPhysicalDevicePipelineRobustnessPropertiesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDevicePipelineRobustnessPropertiesEXT", {
    sType: "u32("+(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_pNext_offsetof||0)+")",
    defaultRobustnessStorageBuffers: "u32("+(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_defaultRobustnessStorageBuffers_offsetof||0)+")",
    defaultRobustnessUniformBuffers: "u32("+(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_defaultRobustnessUniformBuffers_offsetof||0)+")",
    defaultRobustnessVertexInputs: "u32("+(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_defaultRobustnessVertexInputs_offsetof||0)+")",
    defaultRobustnessImages: "u32("+(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_defaultRobustnessImages_offsetof||0)+")",
}, (V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_sizeof||0))));


const VkImageViewSampleWeightCreateInfoQCOM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkImageViewSampleWeightCreateInfoQCOM", {
    sType: "u32("+(V.VkImageViewSampleWeightCreateInfoQCOM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkImageViewSampleWeightCreateInfoQCOM_pNext_offsetof||0)+")",
    filterCenter: "VkOffset2D("+(V.VkImageViewSampleWeightCreateInfoQCOM_filterCenter_offsetof||0)+")",
    filterSize: "VkExtent2D("+(V.VkImageViewSampleWeightCreateInfoQCOM_filterSize_offsetof||0)+")",
    numPhases: "u32("+(V.VkImageViewSampleWeightCreateInfoQCOM_numPhases_offsetof||0)+")",
}, (V.VkImageViewSampleWeightCreateInfoQCOM_sizeof||0))));


const VkPhysicalDeviceImageProcessingFeaturesQCOM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceImageProcessingFeaturesQCOM", {
    sType: "u32("+(V.VkPhysicalDeviceImageProcessingFeaturesQCOM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceImageProcessingFeaturesQCOM_pNext_offsetof||0)+")",
    textureSampleWeighted: "u32("+(V.VkPhysicalDeviceImageProcessingFeaturesQCOM_textureSampleWeighted_offsetof||0)+")",
    textureBoxFilter: "u32("+(V.VkPhysicalDeviceImageProcessingFeaturesQCOM_textureBoxFilter_offsetof||0)+")",
    textureBlockMatch: "u32("+(V.VkPhysicalDeviceImageProcessingFeaturesQCOM_textureBlockMatch_offsetof||0)+")",
}, (V.VkPhysicalDeviceImageProcessingFeaturesQCOM_sizeof||0))));


const VkPhysicalDeviceImageProcessingPropertiesQCOM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceImageProcessingPropertiesQCOM", {
    sType: "u32("+(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_pNext_offsetof||0)+")",
    maxWeightFilterPhases: "u32("+(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_maxWeightFilterPhases_offsetof||0)+")",
    maxWeightFilterDimension: "VkExtent2D("+(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_maxWeightFilterDimension_offsetof||0)+")",
    maxBlockMatchRegion: "VkExtent2D("+(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_maxBlockMatchRegion_offsetof||0)+")",
    maxBoxFilterBlockSize: "VkExtent2D("+(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_maxBoxFilterBlockSize_offsetof||0)+")",
}, (V.VkPhysicalDeviceImageProcessingPropertiesQCOM_sizeof||0))));


const VkPhysicalDeviceTilePropertiesFeaturesQCOM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceTilePropertiesFeaturesQCOM", {
    sType: "u32("+(V.VkPhysicalDeviceTilePropertiesFeaturesQCOM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceTilePropertiesFeaturesQCOM_pNext_offsetof||0)+")",
    tileProperties: "u32("+(V.VkPhysicalDeviceTilePropertiesFeaturesQCOM_tileProperties_offsetof||0)+")",
}, (V.VkPhysicalDeviceTilePropertiesFeaturesQCOM_sizeof||0))));


const VkTilePropertiesQCOM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkTilePropertiesQCOM", {
    sType: "u32("+(V.VkTilePropertiesQCOM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkTilePropertiesQCOM_pNext_offsetof||0)+")",
    tileSize: "u32("+(V.VkTilePropertiesQCOM_tileSize_offsetof||0)+")",
    apronSize: "VkExtent2D("+(V.VkTilePropertiesQCOM_apronSize_offsetof||0)+")",
    origin: "VkOffset2D("+(V.VkTilePropertiesQCOM_origin_offsetof||0)+")",
}, (V.VkTilePropertiesQCOM_sizeof||0))));


const VkPhysicalDeviceAmigoProfilingFeaturesSEC = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceAmigoProfilingFeaturesSEC", {
    sType: "u32("+(V.VkPhysicalDeviceAmigoProfilingFeaturesSEC_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceAmigoProfilingFeaturesSEC_pNext_offsetof||0)+")",
    amigoProfiling: "u32("+(V.VkPhysicalDeviceAmigoProfilingFeaturesSEC_amigoProfiling_offsetof||0)+")",
}, (V.VkPhysicalDeviceAmigoProfilingFeaturesSEC_sizeof||0))));


const VkAmigoProfilingSubmitInfoSEC = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkAmigoProfilingSubmitInfoSEC", {
    sType: "u32("+(V.VkAmigoProfilingSubmitInfoSEC_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkAmigoProfilingSubmitInfoSEC_pNext_offsetof||0)+")",
    firstDrawTimestamp: "u64("+(V.VkAmigoProfilingSubmitInfoSEC_firstDrawTimestamp_offsetof||0)+")",
    swapBufferTimestamp: "u64("+(V.VkAmigoProfilingSubmitInfoSEC_swapBufferTimestamp_offsetof||0)+")",
}, (V.VkAmigoProfilingSubmitInfoSEC_sizeof||0))));


const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT_pNext_offsetof||0)+")",
    attachmentFeedbackLoopLayout: "u32("+(V.VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT_attachmentFeedbackLoopLayout_offsetof||0)+")",
}, (V.VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceDepthClampZeroOneFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceDepthClampZeroOneFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceDepthClampZeroOneFeaturesEXT_pNext_offsetof||0)+")",
    depthClampZeroOne: "u32("+(V.VkPhysicalDeviceDepthClampZeroOneFeaturesEXT_depthClampZeroOne_offsetof||0)+")",
}, (V.VkPhysicalDeviceDepthClampZeroOneFeaturesEXT_sizeof||0))));


const VkPhysicalDeviceAddressBindingReportFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceAddressBindingReportFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceAddressBindingReportFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceAddressBindingReportFeaturesEXT_pNext_offsetof||0)+")",
    reportAddressBinding: "u32("+(V.VkPhysicalDeviceAddressBindingReportFeaturesEXT_reportAddressBinding_offsetof||0)+")",
}, (V.VkPhysicalDeviceAddressBindingReportFeaturesEXT_sizeof||0))));


const VkDeviceAddressBindingCallbackDataEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceAddressBindingCallbackDataEXT", {
    sType: "u32("+(V.VkDeviceAddressBindingCallbackDataEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceAddressBindingCallbackDataEXT_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkDeviceAddressBindingCallbackDataEXT_flags_offsetof||0)+")",
    baseAddress: "u64("+(V.VkDeviceAddressBindingCallbackDataEXT_baseAddress_offsetof||0)+")",
    size: "u64("+(V.VkDeviceAddressBindingCallbackDataEXT_size_offsetof||0)+")",
    bindingType: "u32("+(V.VkDeviceAddressBindingCallbackDataEXT_bindingType_offsetof||0)+")",
}, (V.VkDeviceAddressBindingCallbackDataEXT_sizeof||0))));


const VkPhysicalDeviceOpticalFlowFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceOpticalFlowFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceOpticalFlowFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceOpticalFlowFeaturesNV_pNext_offsetof||0)+")",
    opticalFlow: "u32("+(V.VkPhysicalDeviceOpticalFlowFeaturesNV_opticalFlow_offsetof||0)+")",
}, (V.VkPhysicalDeviceOpticalFlowFeaturesNV_sizeof||0))));


const VkPhysicalDeviceOpticalFlowPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceOpticalFlowPropertiesNV", {
    sType: "u32("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_pNext_offsetof||0)+")",
    supportedOutputGridSizes: "u32("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_supportedOutputGridSizes_offsetof||0)+")",
    supportedHintGridSizes: "u32("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_supportedHintGridSizes_offsetof||0)+")",
    hintSupported: "u32("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_hintSupported_offsetof||0)+")",
    costSupported: "u32("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_costSupported_offsetof||0)+")",
    bidirectionalFlowSupported: "u32("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_bidirectionalFlowSupported_offsetof||0)+")",
    globalFlowSupported: "u32("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_globalFlowSupported_offsetof||0)+")",
    minWidth: "u32("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_minWidth_offsetof||0)+")",
    minHeight: "u32("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_minHeight_offsetof||0)+")",
    maxWidth: "u32("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_maxWidth_offsetof||0)+")",
    maxHeight: "u32("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_maxHeight_offsetof||0)+")",
    maxNumRegionsOfInterest: "u32("+(V.VkPhysicalDeviceOpticalFlowPropertiesNV_maxNumRegionsOfInterest_offsetof||0)+")",
}, (V.VkPhysicalDeviceOpticalFlowPropertiesNV_sizeof||0))));


const VkOpticalFlowImageFormatInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkOpticalFlowImageFormatInfoNV", {
    sType: "u32("+(V.VkOpticalFlowImageFormatInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkOpticalFlowImageFormatInfoNV_pNext_offsetof||0)+")",
    usage: "u32("+(V.VkOpticalFlowImageFormatInfoNV_usage_offsetof||0)+")",
}, (V.VkOpticalFlowImageFormatInfoNV_sizeof||0))));


const VkOpticalFlowImageFormatPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkOpticalFlowImageFormatPropertiesNV", {
    sType: "u32("+(V.VkOpticalFlowImageFormatPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkOpticalFlowImageFormatPropertiesNV_pNext_offsetof||0)+")",
    format: "u32("+(V.VkOpticalFlowImageFormatPropertiesNV_format_offsetof||0)+")",
}, (V.VkOpticalFlowImageFormatPropertiesNV_sizeof||0))));


const VkOpticalFlowSessionCreateInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkOpticalFlowSessionCreateInfoNV", {
    sType: "u32("+(V.VkOpticalFlowSessionCreateInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkOpticalFlowSessionCreateInfoNV_pNext_offsetof||0)+")",
    width: "u32("+(V.VkOpticalFlowSessionCreateInfoNV_width_offsetof||0)+")",
    height: "u32("+(V.VkOpticalFlowSessionCreateInfoNV_height_offsetof||0)+")",
    imageFormat: "u32("+(V.VkOpticalFlowSessionCreateInfoNV_imageFormat_offsetof||0)+")",
    flowVectorFormat: "u32("+(V.VkOpticalFlowSessionCreateInfoNV_flowVectorFormat_offsetof||0)+")",
    costFormat: "u32("+(V.VkOpticalFlowSessionCreateInfoNV_costFormat_offsetof||0)+")",
    outputGridSize: "u32("+(V.VkOpticalFlowSessionCreateInfoNV_outputGridSize_offsetof||0)+")",
    hintGridSize: "u32("+(V.VkOpticalFlowSessionCreateInfoNV_hintGridSize_offsetof||0)+")",
    performanceLevel: "u32("+(V.VkOpticalFlowSessionCreateInfoNV_performanceLevel_offsetof||0)+")",
    flags: "u32("+(V.VkOpticalFlowSessionCreateInfoNV_flags_offsetof||0)+")",
}, (V.VkOpticalFlowSessionCreateInfoNV_sizeof||0))));


const VkOpticalFlowSessionCreatePrivateDataInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkOpticalFlowSessionCreatePrivateDataInfoNV", {
    sType: "u32("+(V.VkOpticalFlowSessionCreatePrivateDataInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkOpticalFlowSessionCreatePrivateDataInfoNV_pNext_offsetof||0)+")",
    id: "u32("+(V.VkOpticalFlowSessionCreatePrivateDataInfoNV_id_offsetof||0)+")",
    size: "u32("+(V.VkOpticalFlowSessionCreatePrivateDataInfoNV_size_offsetof||0)+")",
    pPrivateData: "u64("+(V.VkOpticalFlowSessionCreatePrivateDataInfoNV_pPrivateData_offsetof||0)+")",
}, (V.VkOpticalFlowSessionCreatePrivateDataInfoNV_sizeof||0))));


const VkOpticalFlowExecuteInfoNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkOpticalFlowExecuteInfoNV", {
    sType: "u32("+(V.VkOpticalFlowExecuteInfoNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkOpticalFlowExecuteInfoNV_pNext_offsetof||0)+")",
    flags: "u32("+(V.VkOpticalFlowExecuteInfoNV_flags_offsetof||0)+")",
    regionCount: "u32("+(V.VkOpticalFlowExecuteInfoNV_regionCount_offsetof||0)+")",
    pRegions: "u64("+(V.VkOpticalFlowExecuteInfoNV_pRegions_offsetof||0)+")",
}, (V.VkOpticalFlowExecuteInfoNV_sizeof||0))));


const VkPhysicalDeviceFaultFeaturesEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceFaultFeaturesEXT", {
    sType: "u32("+(V.VkPhysicalDeviceFaultFeaturesEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceFaultFeaturesEXT_pNext_offsetof||0)+")",
    deviceFault: "u32("+(V.VkPhysicalDeviceFaultFeaturesEXT_deviceFault_offsetof||0)+")",
    deviceFaultVendorBinary: "u32("+(V.VkPhysicalDeviceFaultFeaturesEXT_deviceFaultVendorBinary_offsetof||0)+")",
}, (V.VkPhysicalDeviceFaultFeaturesEXT_sizeof||0))));


const VkDeviceFaultAddressInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceFaultAddressInfoEXT", {
    addressType: "u32("+(V.VkDeviceFaultAddressInfoEXT_addressType_offsetof||0)+")",
    reportedAddress: "u64("+(V.VkDeviceFaultAddressInfoEXT_reportedAddress_offsetof||0)+")",
    addressPrecision: "u64("+(V.VkDeviceFaultAddressInfoEXT_addressPrecision_offsetof||0)+")",
}, (V.VkDeviceFaultAddressInfoEXT_sizeof||0))));


const VkDeviceFaultVendorInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceFaultVendorInfoEXT", {
    description: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkDeviceFaultVendorInfoEXT_description_offsetof||0)+")",
    vendorFaultCode: "u64("+(V.VkDeviceFaultVendorInfoEXT_vendorFaultCode_offsetof||0)+")",
    vendorFaultData: "u64("+(V.VkDeviceFaultVendorInfoEXT_vendorFaultData_offsetof||0)+")",
}, (V.VkDeviceFaultVendorInfoEXT_sizeof||0))));


const VkDeviceFaultCountsEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceFaultCountsEXT", {
    sType: "u32("+(V.VkDeviceFaultCountsEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceFaultCountsEXT_pNext_offsetof||0)+")",
    addressInfoCount: "u32("+(V.VkDeviceFaultCountsEXT_addressInfoCount_offsetof||0)+")",
    vendorInfoCount: "u32("+(V.VkDeviceFaultCountsEXT_vendorInfoCount_offsetof||0)+")",
    vendorBinarySize: "u64("+(V.VkDeviceFaultCountsEXT_vendorBinarySize_offsetof||0)+")",
}, (V.VkDeviceFaultCountsEXT_sizeof||0))));


const VkDeviceFaultInfoEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceFaultInfoEXT", {
    sType: "u32("+(V.VkDeviceFaultInfoEXT_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkDeviceFaultInfoEXT_pNext_offsetof||0)+")",
    description: "u8["+(E.VK_MAX_DESCRIPTION_SIZE||1)+"]("+(V.VkDeviceFaultInfoEXT_description_offsetof||0)+")",
    pAddressInfos: "u64("+(V.VkDeviceFaultInfoEXT_pAddressInfos_offsetof||0)+")",
    pVendorInfos: "u64("+(V.VkDeviceFaultInfoEXT_pVendorInfos_offsetof||0)+")",
    pVendorBinaryData: "u64("+(V.VkDeviceFaultInfoEXT_pVendorBinaryData_offsetof||0)+")",
}, (V.VkDeviceFaultInfoEXT_sizeof||0))));


const VkDeviceFaultVendorBinaryHeaderVersionOneEXT = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDeviceFaultVendorBinaryHeaderVersionOneEXT", {
    headerSize: "u32("+(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_headerSize_offsetof||0)+")",
    headerVersion: "u32("+(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_headerVersion_offsetof||0)+")",
    vendorID: "u32("+(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_vendorID_offsetof||0)+")",
    deviceID: "u32("+(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_deviceID_offsetof||0)+")",
    driverVersion: "u32("+(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_driverVersion_offsetof||0)+")",
    pipelineCacheUUID: "u8["+(E.VK_UUID_SIZE||1)+"]("+(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_pipelineCacheUUID_offsetof||0)+")",
    applicationNameOffset: "u32("+(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_applicationNameOffset_offsetof||0)+")",
    applicationVersion: "u32("+(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_applicationVersion_offsetof||0)+")",
    engineNameOffset: "u32("+(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_engineNameOffset_offsetof||0)+")",
}, (V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_sizeof||0))));


const VkDecompressMemoryRegionNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkDecompressMemoryRegionNV", {
    srcAddress: "u64("+(V.VkDecompressMemoryRegionNV_srcAddress_offsetof||0)+")",
    dstAddress: "u64("+(V.VkDecompressMemoryRegionNV_dstAddress_offsetof||0)+")",
    compressedSize: "u64("+(V.VkDecompressMemoryRegionNV_compressedSize_offsetof||0)+")",
    decompressedSize: "u64("+(V.VkDecompressMemoryRegionNV_decompressedSize_offsetof||0)+")",
    decompressionMethod: "u32("+(V.VkDecompressMemoryRegionNV_decompressionMethod_offsetof||0)+")",
}, (V.VkDecompressMemoryRegionNV_sizeof||0))));


const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM", {
    sType: "u32("+(V.VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM_pNext_offsetof||0)+")",
    shaderCoreMask: "u64("+(V.VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM_shaderCoreMask_offsetof||0)+")",
    shaderCoreCount: "u32("+(V.VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM_shaderCoreCount_offsetof||0)+")",
    shaderWarpsPerCore: "u32("+(V.VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM_shaderWarpsPerCore_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM_sizeof||0))));


const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM", {
    sType: "u32("+(V.VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM_pNext_offsetof||0)+")",
    shaderCoreBuiltins: "u32("+(V.VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM_shaderCoreBuiltins_offsetof||0)+")",
}, (V.VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM_sizeof||0))));


const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV", {
    sType: "u32("+(V.VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV_pNext_offsetof||0)+")",
    rayTracingInvocationReorder: "u32("+(V.VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV_rayTracingInvocationReorder_offsetof||0)+")",
}, (V.VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV_sizeof||0))));


const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV = new Proxy(function(){}, new C.ConstructProxy(new C.CStruct("VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV", {
    sType: "u32("+(V.VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV_sType_offsetof||0)+")",
    pNext: "u64("+(V.VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV_pNext_offsetof||0)+")",
    rayTracingInvocationReorderReorderingHint: "u32("+(V.VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV_rayTracingInvocationReorderReorderingHint_offsetof||0)+")",
}, (V.VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV_sizeof||0))));


export default { 
    VkBaseOutStructure,
    VkBaseInStructure,
    VkOffset2D,
    VkOffset3D,
    VkExtent2D,
    VkExtent3D,
    VkViewport,
    VkRect2D,
    VkClearRect,
    VkComponentMapping,
    VkPhysicalDeviceProperties,
    VkExtensionProperties,
    VkLayerProperties,
    VkApplicationInfo,
    VkAllocationCallbacks,
    VkDeviceQueueCreateInfo,
    VkDeviceCreateInfo,
    VkInstanceCreateInfo,
    VkQueueFamilyProperties,
    VkPhysicalDeviceMemoryProperties,
    VkMemoryAllocateInfo,
    VkMemoryRequirements,
    VkSparseImageFormatProperties,
    VkSparseImageMemoryRequirements,
    VkMemoryType,
    VkMemoryHeap,
    VkMappedMemoryRange,
    VkFormatProperties,
    VkImageFormatProperties,
    VkDescriptorBufferInfo,
    VkDescriptorImageInfo,
    VkWriteDescriptorSet,
    VkCopyDescriptorSet,
    VkBufferCreateInfo,
    VkBufferViewCreateInfo,
    VkImageSubresource,
    VkImageSubresourceLayers,
    VkImageSubresourceRange,
    VkMemoryBarrier,
    VkBufferMemoryBarrier,
    VkImageMemoryBarrier,
    VkImageCreateInfo,
    VkSubresourceLayout,
    VkImageViewCreateInfo,
    VkBufferCopy,
    VkSparseMemoryBind,
    VkSparseImageMemoryBind,
    VkSparseBufferMemoryBindInfo,
    VkSparseImageOpaqueMemoryBindInfo,
    VkSparseImageMemoryBindInfo,
    VkBindSparseInfo,
    VkImageCopy,
    VkImageBlit,
    VkBufferImageCopy,
    VkCopyMemoryIndirectCommandNV,
    VkCopyMemoryToImageIndirectCommandNV,
    VkImageResolve,
    VkShaderModuleCreateInfo,
    VkDescriptorSetLayoutBinding,
    VkDescriptorSetLayoutCreateInfo,
    VkDescriptorPoolSize,
    VkDescriptorPoolCreateInfo,
    VkDescriptorSetAllocateInfo,
    VkSpecializationMapEntry,
    VkSpecializationInfo,
    VkPipelineShaderStageCreateInfo,
    VkComputePipelineCreateInfo,
    VkVertexInputBindingDescription,
    VkVertexInputAttributeDescription,
    VkPipelineVertexInputStateCreateInfo,
    VkPipelineInputAssemblyStateCreateInfo,
    VkPipelineTessellationStateCreateInfo,
    VkPipelineViewportStateCreateInfo,
    VkPipelineRasterizationStateCreateInfo,
    VkPipelineMultisampleStateCreateInfo,
    VkPipelineColorBlendAttachmentState,
    VkPipelineColorBlendStateCreateInfo,
    VkPipelineDynamicStateCreateInfo,
    VkStencilOpState,
    VkPipelineDepthStencilStateCreateInfo,
    VkGraphicsPipelineCreateInfo,
    VkPipelineCacheCreateInfo,
    VkPipelineCacheHeaderVersionOne,
    VkPushConstantRange,
    VkPipelineLayoutCreateInfo,
    VkSamplerCreateInfo,
    VkCommandPoolCreateInfo,
    VkCommandBufferAllocateInfo,
    VkCommandBufferInheritanceInfo,
    VkCommandBufferBeginInfo,
    VkRenderPassBeginInfo,
    VkClearDepthStencilValue,
    VkClearAttachment,
    VkAttachmentDescription,
    VkAttachmentReference,
    VkSubpassDescription,
    VkSubpassDependency,
    VkRenderPassCreateInfo,
    VkEventCreateInfo,
    VkFenceCreateInfo,
    VkPhysicalDeviceFeatures,
    VkPhysicalDeviceSparseProperties,
    VkPhysicalDeviceLimits,
    VkSemaphoreCreateInfo,
    VkQueryPoolCreateInfo,
    VkFramebufferCreateInfo,
    VkDrawIndirectCommand,
    VkDrawIndexedIndirectCommand,
    VkDispatchIndirectCommand,
    VkMultiDrawInfoEXT,
    VkMultiDrawIndexedInfoEXT,
    VkSubmitInfo,
    VkDisplayPropertiesKHR,
    VkDisplayPlanePropertiesKHR,
    VkDisplayModeParametersKHR,
    VkDisplayModePropertiesKHR,
    VkDisplayModeCreateInfoKHR,
    VkDisplayPlaneCapabilitiesKHR,
    VkDisplaySurfaceCreateInfoKHR,
    VkDisplayPresentInfoKHR,
    VkSurfaceCapabilitiesKHR,
    VkAndroidSurfaceCreateInfoKHR,
    VkViSurfaceCreateInfoNN,
    VkWaylandSurfaceCreateInfoKHR,
    VkWin32SurfaceCreateInfoKHR,
    VkXlibSurfaceCreateInfoKHR,
    VkXcbSurfaceCreateInfoKHR,
    VkDirectFBSurfaceCreateInfoEXT,
    VkImagePipeSurfaceCreateInfoFUCHSIA,
    VkStreamDescriptorSurfaceCreateInfoGGP,
    VkScreenSurfaceCreateInfoQNX,
    VkSurfaceFormatKHR,
    VkSwapchainCreateInfoKHR,
    VkPresentInfoKHR,
    VkDebugReportCallbackCreateInfoEXT,
    VkValidationFlagsEXT,
    VkValidationFeaturesEXT,
    VkPipelineRasterizationStateRasterizationOrderAMD,
    VkDebugMarkerObjectNameInfoEXT,
    VkDebugMarkerObjectTagInfoEXT,
    VkDebugMarkerMarkerInfoEXT,
    VkDedicatedAllocationImageCreateInfoNV,
    VkDedicatedAllocationBufferCreateInfoNV,
    VkDedicatedAllocationMemoryAllocateInfoNV,
    VkExternalImageFormatPropertiesNV,
    VkExternalMemoryImageCreateInfoNV,
    VkExportMemoryAllocateInfoNV,
    VkImportMemoryWin32HandleInfoNV,
    VkExportMemoryWin32HandleInfoNV,
    VkWin32KeyedMutexAcquireReleaseInfoNV,
    VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV,
    VkDevicePrivateDataCreateInfo,
    VkDevicePrivateDataCreateInfoEXT,
    VkPrivateDataSlotCreateInfo,
    VkPrivateDataSlotCreateInfoEXT,
    VkPhysicalDevicePrivateDataFeatures,
    VkPhysicalDevicePrivateDataFeaturesEXT,
    VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV,
    VkPhysicalDeviceMultiDrawPropertiesEXT,
    VkGraphicsShaderGroupCreateInfoNV,
    VkGraphicsPipelineShaderGroupsCreateInfoNV,
    VkBindShaderGroupIndirectCommandNV,
    VkBindIndexBufferIndirectCommandNV,
    VkBindVertexBufferIndirectCommandNV,
    VkSetStateFlagsIndirectCommandNV,
    VkIndirectCommandsStreamNV,
    VkIndirectCommandsLayoutTokenNV,
    VkIndirectCommandsLayoutCreateInfoNV,
    VkGeneratedCommandsInfoNV,
    VkGeneratedCommandsMemoryRequirementsInfoNV,
    VkPhysicalDeviceFeatures2,
    VkPhysicalDeviceFeatures2KHR,
    VkPhysicalDeviceProperties2,
    VkPhysicalDeviceProperties2KHR,
    VkFormatProperties2,
    VkFormatProperties2KHR,
    VkImageFormatProperties2,
    VkImageFormatProperties2KHR,
    VkPhysicalDeviceImageFormatInfo2,
    VkPhysicalDeviceImageFormatInfo2KHR,
    VkQueueFamilyProperties2,
    VkQueueFamilyProperties2KHR,
    VkPhysicalDeviceMemoryProperties2,
    VkPhysicalDeviceMemoryProperties2KHR,
    VkSparseImageFormatProperties2,
    VkSparseImageFormatProperties2KHR,
    VkPhysicalDeviceSparseImageFormatInfo2,
    VkPhysicalDeviceSparseImageFormatInfo2KHR,
    VkPhysicalDevicePushDescriptorPropertiesKHR,
    VkConformanceVersion,
    VkConformanceVersionKHR,
    VkPhysicalDeviceDriverProperties,
    VkPhysicalDeviceDriverPropertiesKHR,
    VkPresentRegionsKHR,
    VkPresentRegionKHR,
    VkRectLayerKHR,
    VkPhysicalDeviceVariablePointersFeatures,
    VkPhysicalDeviceVariablePointersFeaturesKHR,
    VkPhysicalDeviceVariablePointerFeaturesKHR,
    VkPhysicalDeviceVariablePointerFeatures,
    VkExternalMemoryProperties,
    VkExternalMemoryPropertiesKHR,
    VkPhysicalDeviceExternalImageFormatInfo,
    VkPhysicalDeviceExternalImageFormatInfoKHR,
    VkExternalImageFormatProperties,
    VkExternalImageFormatPropertiesKHR,
    VkPhysicalDeviceExternalBufferInfo,
    VkPhysicalDeviceExternalBufferInfoKHR,
    VkExternalBufferProperties,
    VkExternalBufferPropertiesKHR,
    VkPhysicalDeviceIDProperties,
    VkPhysicalDeviceIDPropertiesKHR,
    VkExternalMemoryImageCreateInfo,
    VkExternalMemoryImageCreateInfoKHR,
    VkExternalMemoryBufferCreateInfo,
    VkExternalMemoryBufferCreateInfoKHR,
    VkExportMemoryAllocateInfo,
    VkExportMemoryAllocateInfoKHR,
    VkImportMemoryWin32HandleInfoKHR,
    VkExportMemoryWin32HandleInfoKHR,
    VkImportMemoryZirconHandleInfoFUCHSIA,
    VkMemoryZirconHandlePropertiesFUCHSIA,
    VkMemoryGetZirconHandleInfoFUCHSIA,
    VkMemoryWin32HandlePropertiesKHR,
    VkMemoryGetWin32HandleInfoKHR,
    VkImportMemoryFdInfoKHR,
    VkMemoryFdPropertiesKHR,
    VkMemoryGetFdInfoKHR,
    VkWin32KeyedMutexAcquireReleaseInfoKHR,
    VkPhysicalDeviceExternalSemaphoreInfo,
    VkPhysicalDeviceExternalSemaphoreInfoKHR,
    VkExternalSemaphoreProperties,
    VkExternalSemaphorePropertiesKHR,
    VkExportSemaphoreCreateInfo,
    VkExportSemaphoreCreateInfoKHR,
    VkImportSemaphoreWin32HandleInfoKHR,
    VkExportSemaphoreWin32HandleInfoKHR,
    VkD3D12FenceSubmitInfoKHR,
    VkSemaphoreGetWin32HandleInfoKHR,
    VkImportSemaphoreFdInfoKHR,
    VkSemaphoreGetFdInfoKHR,
    VkImportSemaphoreZirconHandleInfoFUCHSIA,
    VkSemaphoreGetZirconHandleInfoFUCHSIA,
    VkPhysicalDeviceExternalFenceInfo,
    VkPhysicalDeviceExternalFenceInfoKHR,
    VkExternalFenceProperties,
    VkExternalFencePropertiesKHR,
    VkExportFenceCreateInfo,
    VkExportFenceCreateInfoKHR,
    VkImportFenceWin32HandleInfoKHR,
    VkExportFenceWin32HandleInfoKHR,
    VkFenceGetWin32HandleInfoKHR,
    VkImportFenceFdInfoKHR,
    VkFenceGetFdInfoKHR,
    VkPhysicalDeviceMultiviewFeatures,
    VkPhysicalDeviceMultiviewFeaturesKHR,
    VkPhysicalDeviceMultiviewProperties,
    VkPhysicalDeviceMultiviewPropertiesKHR,
    VkRenderPassMultiviewCreateInfo,
    VkRenderPassMultiviewCreateInfoKHR,
    VkSurfaceCapabilities2EXT,
    VkDisplayPowerInfoEXT,
    VkDeviceEventInfoEXT,
    VkDisplayEventInfoEXT,
    VkSwapchainCounterCreateInfoEXT,
    VkPhysicalDeviceGroupProperties,
    VkPhysicalDeviceGroupPropertiesKHR,
    VkMemoryAllocateFlagsInfo,
    VkMemoryAllocateFlagsInfoKHR,
    VkBindBufferMemoryInfo,
    VkBindBufferMemoryInfoKHR,
    VkBindBufferMemoryDeviceGroupInfo,
    VkBindBufferMemoryDeviceGroupInfoKHR,
    VkBindImageMemoryInfo,
    VkBindImageMemoryInfoKHR,
    VkBindImageMemoryDeviceGroupInfo,
    VkBindImageMemoryDeviceGroupInfoKHR,
    VkDeviceGroupRenderPassBeginInfo,
    VkDeviceGroupRenderPassBeginInfoKHR,
    VkDeviceGroupCommandBufferBeginInfo,
    VkDeviceGroupCommandBufferBeginInfoKHR,
    VkDeviceGroupSubmitInfo,
    VkDeviceGroupSubmitInfoKHR,
    VkDeviceGroupBindSparseInfo,
    VkDeviceGroupBindSparseInfoKHR,
    VkDeviceGroupPresentCapabilitiesKHR,
    VkImageSwapchainCreateInfoKHR,
    VkBindImageMemorySwapchainInfoKHR,
    VkAcquireNextImageInfoKHR,
    VkDeviceGroupPresentInfoKHR,
    VkDeviceGroupDeviceCreateInfo,
    VkDeviceGroupDeviceCreateInfoKHR,
    VkDeviceGroupSwapchainCreateInfoKHR,
    VkDescriptorUpdateTemplateEntry,
    VkDescriptorUpdateTemplateEntryKHR,
    VkDescriptorUpdateTemplateCreateInfo,
    VkDescriptorUpdateTemplateCreateInfoKHR,
    VkXYColorEXT,
    VkPhysicalDevicePresentIdFeaturesKHR,
    VkPresentIdKHR,
    VkPhysicalDevicePresentWaitFeaturesKHR,
    VkHdrMetadataEXT,
    VkDisplayNativeHdrSurfaceCapabilitiesAMD,
    VkSwapchainDisplayNativeHdrCreateInfoAMD,
    VkRefreshCycleDurationGOOGLE,
    VkPastPresentationTimingGOOGLE,
    VkPresentTimesInfoGOOGLE,
    VkPresentTimeGOOGLE,
    VkIOSSurfaceCreateInfoMVK,
    VkMacOSSurfaceCreateInfoMVK,
    VkMetalSurfaceCreateInfoEXT,
    VkViewportWScalingNV,
    VkPipelineViewportWScalingStateCreateInfoNV,
    VkViewportSwizzleNV,
    VkPipelineViewportSwizzleStateCreateInfoNV,
    VkPhysicalDeviceDiscardRectanglePropertiesEXT,
    VkPipelineDiscardRectangleStateCreateInfoEXT,
    VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX,
    VkInputAttachmentAspectReference,
    VkInputAttachmentAspectReferenceKHR,
    VkRenderPassInputAttachmentAspectCreateInfo,
    VkRenderPassInputAttachmentAspectCreateInfoKHR,
    VkPhysicalDeviceSurfaceInfo2KHR,
    VkSurfaceCapabilities2KHR,
    VkSurfaceFormat2KHR,
    VkDisplayProperties2KHR,
    VkDisplayPlaneProperties2KHR,
    VkDisplayModeProperties2KHR,
    VkDisplayPlaneInfo2KHR,
    VkDisplayPlaneCapabilities2KHR,
    VkSharedPresentSurfaceCapabilitiesKHR,
    VkPhysicalDevice16BitStorageFeatures,
    VkPhysicalDevice16BitStorageFeaturesKHR,
    VkPhysicalDeviceSubgroupProperties,
    VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures,
    VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR,
    VkBufferMemoryRequirementsInfo2,
    VkBufferMemoryRequirementsInfo2KHR,
    VkDeviceBufferMemoryRequirements,
    VkDeviceBufferMemoryRequirementsKHR,
    VkImageMemoryRequirementsInfo2,
    VkImageMemoryRequirementsInfo2KHR,
    VkImageSparseMemoryRequirementsInfo2,
    VkImageSparseMemoryRequirementsInfo2KHR,
    VkDeviceImageMemoryRequirements,
    VkDeviceImageMemoryRequirementsKHR,
    VkMemoryRequirements2,
    VkMemoryRequirements2KHR,
    VkSparseImageMemoryRequirements2,
    VkSparseImageMemoryRequirements2KHR,
    VkPhysicalDevicePointClippingProperties,
    VkPhysicalDevicePointClippingPropertiesKHR,
    VkMemoryDedicatedRequirements,
    VkMemoryDedicatedRequirementsKHR,
    VkMemoryDedicatedAllocateInfo,
    VkMemoryDedicatedAllocateInfoKHR,
    VkImageViewUsageCreateInfo,
    VkImageViewUsageCreateInfoKHR,
    VkPipelineTessellationDomainOriginStateCreateInfo,
    VkPipelineTessellationDomainOriginStateCreateInfoKHR,
    VkSamplerYcbcrConversionInfo,
    VkSamplerYcbcrConversionInfoKHR,
    VkSamplerYcbcrConversionCreateInfo,
    VkSamplerYcbcrConversionCreateInfoKHR,
    VkBindImagePlaneMemoryInfo,
    VkBindImagePlaneMemoryInfoKHR,
    VkImagePlaneMemoryRequirementsInfo,
    VkImagePlaneMemoryRequirementsInfoKHR,
    VkPhysicalDeviceSamplerYcbcrConversionFeatures,
    VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR,
    VkSamplerYcbcrConversionImageFormatProperties,
    VkSamplerYcbcrConversionImageFormatPropertiesKHR,
    VkTextureLODGatherFormatPropertiesAMD,
    VkConditionalRenderingBeginInfoEXT,
    VkProtectedSubmitInfo,
    VkPhysicalDeviceProtectedMemoryFeatures,
    VkPhysicalDeviceProtectedMemoryProperties,
    VkDeviceQueueInfo2,
    VkPipelineCoverageToColorStateCreateInfoNV,
    VkPhysicalDeviceSamplerFilterMinmaxProperties,
    VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT,
    VkSampleLocationEXT,
    VkSampleLocationsInfoEXT,
    VkAttachmentSampleLocationsEXT,
    VkSubpassSampleLocationsEXT,
    VkRenderPassSampleLocationsBeginInfoEXT,
    VkPipelineSampleLocationsStateCreateInfoEXT,
    VkPhysicalDeviceSampleLocationsPropertiesEXT,
    VkMultisamplePropertiesEXT,
    VkSamplerReductionModeCreateInfo,
    VkSamplerReductionModeCreateInfoEXT,
    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT,
    VkPhysicalDeviceMultiDrawFeaturesEXT,
    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT,
    VkPipelineColorBlendAdvancedStateCreateInfoEXT,
    VkPhysicalDeviceInlineUniformBlockFeatures,
    VkPhysicalDeviceInlineUniformBlockFeaturesEXT,
    VkPhysicalDeviceInlineUniformBlockProperties,
    VkPhysicalDeviceInlineUniformBlockPropertiesEXT,
    VkWriteDescriptorSetInlineUniformBlock,
    VkWriteDescriptorSetInlineUniformBlockEXT,
    VkDescriptorPoolInlineUniformBlockCreateInfo,
    VkDescriptorPoolInlineUniformBlockCreateInfoEXT,
    VkPipelineCoverageModulationStateCreateInfoNV,
    VkImageFormatListCreateInfo,
    VkImageFormatListCreateInfoKHR,
    VkValidationCacheCreateInfoEXT,
    VkShaderModuleValidationCacheCreateInfoEXT,
    VkPhysicalDeviceMaintenance3Properties,
    VkPhysicalDeviceMaintenance3PropertiesKHR,
    VkPhysicalDeviceMaintenance4Features,
    VkPhysicalDeviceMaintenance4FeaturesKHR,
    VkPhysicalDeviceMaintenance4Properties,
    VkPhysicalDeviceMaintenance4PropertiesKHR,
    VkDescriptorSetLayoutSupport,
    VkDescriptorSetLayoutSupportKHR,
    VkPhysicalDeviceShaderDrawParametersFeatures,
    VkPhysicalDeviceShaderDrawParameterFeatures,
    VkPhysicalDeviceShaderFloat16Int8Features,
    VkPhysicalDeviceShaderFloat16Int8FeaturesKHR,
    VkPhysicalDeviceFloat16Int8FeaturesKHR,
    VkPhysicalDeviceFloatControlsProperties,
    VkPhysicalDeviceFloatControlsPropertiesKHR,
    VkPhysicalDeviceHostQueryResetFeatures,
    VkPhysicalDeviceHostQueryResetFeaturesEXT,
    VkNativeBufferUsage2ANDROID,
    VkNativeBufferANDROID,
    VkSwapchainImageCreateInfoANDROID,
    VkPhysicalDevicePresentationPropertiesANDROID,
    VkShaderResourceUsageAMD,
    VkShaderStatisticsInfoAMD,
    VkDeviceQueueGlobalPriorityCreateInfoKHR,
    VkDeviceQueueGlobalPriorityCreateInfoEXT,
    VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR,
    VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT,
    VkQueueFamilyGlobalPriorityPropertiesKHR,
    VkQueueFamilyGlobalPriorityPropertiesEXT,
    VkDebugUtilsObjectNameInfoEXT,
    VkDebugUtilsObjectTagInfoEXT,
    VkDebugUtilsLabelEXT,
    VkDebugUtilsMessengerCreateInfoEXT,
    VkDebugUtilsMessengerCallbackDataEXT,
    VkPhysicalDeviceDeviceMemoryReportFeaturesEXT,
    VkDeviceDeviceMemoryReportCreateInfoEXT,
    VkDeviceMemoryReportCallbackDataEXT,
    VkImportMemoryHostPointerInfoEXT,
    VkMemoryHostPointerPropertiesEXT,
    VkPhysicalDeviceExternalMemoryHostPropertiesEXT,
    VkPhysicalDeviceConservativeRasterizationPropertiesEXT,
    VkCalibratedTimestampInfoEXT,
    VkPhysicalDeviceShaderCorePropertiesAMD,
    VkPhysicalDeviceShaderCoreProperties2AMD,
    VkPipelineRasterizationConservativeStateCreateInfoEXT,
    VkPhysicalDeviceDescriptorIndexingFeatures,
    VkPhysicalDeviceDescriptorIndexingFeaturesEXT,
    VkPhysicalDeviceDescriptorIndexingProperties,
    VkPhysicalDeviceDescriptorIndexingPropertiesEXT,
    VkDescriptorSetLayoutBindingFlagsCreateInfo,
    VkDescriptorSetLayoutBindingFlagsCreateInfoEXT,
    VkDescriptorSetVariableDescriptorCountAllocateInfo,
    VkDescriptorSetVariableDescriptorCountAllocateInfoEXT,
    VkDescriptorSetVariableDescriptorCountLayoutSupport,
    VkDescriptorSetVariableDescriptorCountLayoutSupportEXT,
    VkAttachmentDescription2,
    VkAttachmentDescription2KHR,
    VkAttachmentReference2,
    VkAttachmentReference2KHR,
    VkSubpassDescription2,
    VkSubpassDescription2KHR,
    VkSubpassDependency2,
    VkSubpassDependency2KHR,
    VkRenderPassCreateInfo2,
    VkRenderPassCreateInfo2KHR,
    VkSubpassBeginInfo,
    VkSubpassBeginInfoKHR,
    VkSubpassEndInfo,
    VkSubpassEndInfoKHR,
    VkPhysicalDeviceTimelineSemaphoreFeatures,
    VkPhysicalDeviceTimelineSemaphoreFeaturesKHR,
    VkPhysicalDeviceTimelineSemaphoreProperties,
    VkPhysicalDeviceTimelineSemaphorePropertiesKHR,
    VkSemaphoreTypeCreateInfo,
    VkSemaphoreTypeCreateInfoKHR,
    VkTimelineSemaphoreSubmitInfo,
    VkTimelineSemaphoreSubmitInfoKHR,
    VkSemaphoreWaitInfo,
    VkSemaphoreWaitInfoKHR,
    VkSemaphoreSignalInfo,
    VkSemaphoreSignalInfoKHR,
    VkVertexInputBindingDivisorDescriptionEXT,
    VkPipelineVertexInputDivisorStateCreateInfoEXT,
    VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT,
    VkPhysicalDevicePCIBusInfoPropertiesEXT,
    VkImportAndroidHardwareBufferInfoANDROID,
    VkAndroidHardwareBufferUsageANDROID,
    VkAndroidHardwareBufferPropertiesANDROID,
    VkMemoryGetAndroidHardwareBufferInfoANDROID,
    VkAndroidHardwareBufferFormatPropertiesANDROID,
    VkCommandBufferInheritanceConditionalRenderingInfoEXT,
    VkExternalFormatANDROID,
    VkPhysicalDevice8BitStorageFeatures,
    VkPhysicalDevice8BitStorageFeaturesKHR,
    VkPhysicalDeviceConditionalRenderingFeaturesEXT,
    VkPhysicalDeviceVulkanMemoryModelFeatures,
    VkPhysicalDeviceVulkanMemoryModelFeaturesKHR,
    VkPhysicalDeviceShaderAtomicInt64Features,
    VkPhysicalDeviceShaderAtomicInt64FeaturesKHR,
    VkPhysicalDeviceShaderAtomicFloatFeaturesEXT,
    VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT,
    VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT,
    VkQueueFamilyCheckpointPropertiesNV,
    VkCheckpointDataNV,
    VkPhysicalDeviceDepthStencilResolveProperties,
    VkPhysicalDeviceDepthStencilResolvePropertiesKHR,
    VkSubpassDescriptionDepthStencilResolve,
    VkSubpassDescriptionDepthStencilResolveKHR,
    VkImageViewASTCDecodeModeEXT,
    VkPhysicalDeviceASTCDecodeFeaturesEXT,
    VkPhysicalDeviceTransformFeedbackFeaturesEXT,
    VkPhysicalDeviceTransformFeedbackPropertiesEXT,
    VkPipelineRasterizationStateStreamCreateInfoEXT,
    VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV,
    VkPipelineRepresentativeFragmentTestStateCreateInfoNV,
    VkPhysicalDeviceExclusiveScissorFeaturesNV,
    VkPipelineViewportExclusiveScissorStateCreateInfoNV,
    VkPhysicalDeviceCornerSampledImageFeaturesNV,
    VkPhysicalDeviceComputeShaderDerivativesFeaturesNV,
    VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV,
    VkPhysicalDeviceShaderImageFootprintFeaturesNV,
    VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV,
    VkPhysicalDeviceCopyMemoryIndirectFeaturesNV,
    VkPhysicalDeviceCopyMemoryIndirectPropertiesNV,
    VkPhysicalDeviceMemoryDecompressionFeaturesNV,
    VkPhysicalDeviceMemoryDecompressionPropertiesNV,
    VkShadingRatePaletteNV,
    VkPipelineViewportShadingRateImageStateCreateInfoNV,
    VkPhysicalDeviceShadingRateImageFeaturesNV,
    VkPhysicalDeviceShadingRateImagePropertiesNV,
    VkPhysicalDeviceInvocationMaskFeaturesHUAWEI,
    VkCoarseSampleLocationNV,
    VkCoarseSampleOrderCustomNV,
    VkPipelineViewportCoarseSampleOrderStateCreateInfoNV,
    VkPhysicalDeviceMeshShaderFeaturesNV,
    VkPhysicalDeviceMeshShaderPropertiesNV,
    VkDrawMeshTasksIndirectCommandNV,
    VkPhysicalDeviceMeshShaderFeaturesEXT,
    VkPhysicalDeviceMeshShaderPropertiesEXT,
    VkDrawMeshTasksIndirectCommandEXT,
    VkRayTracingShaderGroupCreateInfoNV,
    VkRayTracingShaderGroupCreateInfoKHR,
    VkRayTracingPipelineCreateInfoNV,
    VkRayTracingPipelineCreateInfoKHR,
    VkGeometryTrianglesNV,
    VkGeometryAABBNV,
    VkGeometryDataNV,
    VkGeometryNV,
    VkAccelerationStructureInfoNV,
    VkAccelerationStructureCreateInfoNV,
    VkBindAccelerationStructureMemoryInfoNV,
    VkWriteDescriptorSetAccelerationStructureKHR,
    VkWriteDescriptorSetAccelerationStructureNV,
    VkAccelerationStructureMemoryRequirementsInfoNV,
    VkPhysicalDeviceAccelerationStructureFeaturesKHR,
    VkPhysicalDeviceRayTracingPipelineFeaturesKHR,
    VkPhysicalDeviceRayQueryFeaturesKHR,
    VkPhysicalDeviceAccelerationStructurePropertiesKHR,
    VkPhysicalDeviceRayTracingPipelinePropertiesKHR,
    VkPhysicalDeviceRayTracingPropertiesNV,
    VkStridedDeviceAddressRegionKHR,
    VkTraceRaysIndirectCommandKHR,
    VkTraceRaysIndirectCommand2KHR,
    VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR,
    VkDrmFormatModifierPropertiesListEXT,
    VkDrmFormatModifierPropertiesEXT,
    VkPhysicalDeviceImageDrmFormatModifierInfoEXT,
    VkImageDrmFormatModifierListCreateInfoEXT,
    VkImageDrmFormatModifierExplicitCreateInfoEXT,
    VkImageDrmFormatModifierPropertiesEXT,
    VkImageStencilUsageCreateInfo,
    VkImageStencilUsageCreateInfoEXT,
    VkDeviceMemoryOverallocationCreateInfoAMD,
    VkPhysicalDeviceFragmentDensityMapFeaturesEXT,
    VkPhysicalDeviceFragmentDensityMap2FeaturesEXT,
    VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM,
    VkPhysicalDeviceFragmentDensityMapPropertiesEXT,
    VkPhysicalDeviceFragmentDensityMap2PropertiesEXT,
    VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM,
    VkRenderPassFragmentDensityMapCreateInfoEXT,
    VkSubpassFragmentDensityMapOffsetEndInfoQCOM,
    VkPhysicalDeviceScalarBlockLayoutFeatures,
    VkPhysicalDeviceScalarBlockLayoutFeaturesEXT,
    VkSurfaceProtectedCapabilitiesKHR,
    VkPhysicalDeviceUniformBufferStandardLayoutFeatures,
    VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR,
    VkPhysicalDeviceDepthClipEnableFeaturesEXT,
    VkPipelineRasterizationDepthClipStateCreateInfoEXT,
    VkPhysicalDeviceMemoryBudgetPropertiesEXT,
    VkPhysicalDeviceMemoryPriorityFeaturesEXT,
    VkMemoryPriorityAllocateInfoEXT,
    VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT,
    VkPhysicalDeviceBufferDeviceAddressFeatures,
    VkPhysicalDeviceBufferDeviceAddressFeaturesKHR,
    VkPhysicalDeviceBufferDeviceAddressFeaturesEXT,
    VkPhysicalDeviceBufferAddressFeaturesEXT,
    VkBufferDeviceAddressInfo,
    VkBufferDeviceAddressInfoKHR,
    VkBufferDeviceAddressInfoEXT,
    VkBufferOpaqueCaptureAddressCreateInfo,
    VkBufferOpaqueCaptureAddressCreateInfoKHR,
    VkBufferDeviceAddressCreateInfoEXT,
    VkPhysicalDeviceImageViewImageFormatInfoEXT,
    VkFilterCubicImageViewImageFormatPropertiesEXT,
    VkPhysicalDeviceImagelessFramebufferFeatures,
    VkPhysicalDeviceImagelessFramebufferFeaturesKHR,
    VkFramebufferAttachmentsCreateInfo,
    VkFramebufferAttachmentsCreateInfoKHR,
    VkFramebufferAttachmentImageInfo,
    VkFramebufferAttachmentImageInfoKHR,
    VkRenderPassAttachmentBeginInfo,
    VkRenderPassAttachmentBeginInfoKHR,
    VkPhysicalDeviceTextureCompressionASTCHDRFeatures,
    VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT,
    VkPhysicalDeviceCooperativeMatrixFeaturesNV,
    VkPhysicalDeviceCooperativeMatrixPropertiesNV,
    VkCooperativeMatrixPropertiesNV,
    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT,
    VkImageViewHandleInfoNVX,
    VkImageViewAddressPropertiesNVX,
    VkPresentFrameTokenGGP,
    VkPipelineCreationFeedback,
    VkPipelineCreationFeedbackEXT,
    VkPipelineCreationFeedbackCreateInfo,
    VkPipelineCreationFeedbackCreateInfoEXT,
    VkSurfaceFullScreenExclusiveInfoEXT,
    VkSurfaceFullScreenExclusiveWin32InfoEXT,
    VkSurfaceCapabilitiesFullScreenExclusiveEXT,
    VkPhysicalDevicePresentBarrierFeaturesNV,
    VkSurfaceCapabilitiesPresentBarrierNV,
    VkSwapchainPresentBarrierCreateInfoNV,
    VkPhysicalDevicePerformanceQueryFeaturesKHR,
    VkPhysicalDevicePerformanceQueryPropertiesKHR,
    VkPerformanceCounterKHR,
    VkPerformanceCounterDescriptionKHR,
    VkQueryPoolPerformanceCreateInfoKHR,
    VkAcquireProfilingLockInfoKHR,
    VkPerformanceQuerySubmitInfoKHR,
    VkHeadlessSurfaceCreateInfoEXT,
    VkPhysicalDeviceCoverageReductionModeFeaturesNV,
    VkPipelineCoverageReductionStateCreateInfoNV,
    VkFramebufferMixedSamplesCombinationNV,
    VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL,
    VkPerformanceValueINTEL,
    VkInitializePerformanceApiInfoINTEL,
    VkQueryPoolPerformanceQueryCreateInfoINTEL,
    VkQueryPoolCreateInfoINTEL,
    VkPerformanceMarkerInfoINTEL,
    VkPerformanceStreamMarkerInfoINTEL,
    VkPerformanceOverrideInfoINTEL,
    VkPerformanceConfigurationAcquireInfoINTEL,
    VkPhysicalDeviceShaderClockFeaturesKHR,
    VkPhysicalDeviceIndexTypeUint8FeaturesEXT,
    VkPhysicalDeviceShaderSMBuiltinsPropertiesNV,
    VkPhysicalDeviceShaderSMBuiltinsFeaturesNV,
    VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT,
    VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures,
    VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR,
    VkAttachmentReferenceStencilLayout,
    VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT,
    VkAttachmentReferenceStencilLayoutKHR,
    VkAttachmentDescriptionStencilLayout,
    VkAttachmentDescriptionStencilLayoutKHR,
    VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR,
    VkPipelineInfoKHR,
    VkPipelineInfoEXT,
    VkPipelineExecutablePropertiesKHR,
    VkPipelineExecutableInfoKHR,
    VkPipelineExecutableStatisticKHR,
    VkPipelineExecutableInternalRepresentationKHR,
    VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures,
    VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT,
    VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT,
    VkPhysicalDeviceTexelBufferAlignmentProperties,
    VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT,
    VkPhysicalDeviceSubgroupSizeControlFeatures,
    VkPhysicalDeviceSubgroupSizeControlFeaturesEXT,
    VkPhysicalDeviceSubgroupSizeControlProperties,
    VkPhysicalDeviceSubgroupSizeControlPropertiesEXT,
    VkPipelineShaderStageRequiredSubgroupSizeCreateInfo,
    VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT,
    VkSubpassShadingPipelineCreateInfoHUAWEI,
    VkPhysicalDeviceSubpassShadingPropertiesHUAWEI,
    VkMemoryOpaqueCaptureAddressAllocateInfo,
    VkMemoryOpaqueCaptureAddressAllocateInfoKHR,
    VkDeviceMemoryOpaqueCaptureAddressInfo,
    VkDeviceMemoryOpaqueCaptureAddressInfoKHR,
    VkPhysicalDeviceLineRasterizationFeaturesEXT,
    VkPhysicalDeviceLineRasterizationPropertiesEXT,
    VkPipelineRasterizationLineStateCreateInfoEXT,
    VkPhysicalDevicePipelineCreationCacheControlFeatures,
    VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT,
    VkPhysicalDeviceVulkan11Features,
    VkPhysicalDeviceVulkan11Properties,
    VkPhysicalDeviceVulkan12Features,
    VkPhysicalDeviceVulkan12Properties,
    VkPhysicalDeviceVulkan13Features,
    VkPhysicalDeviceVulkan13Properties,
    VkPipelineCompilerControlCreateInfoAMD,
    VkPhysicalDeviceCoherentMemoryFeaturesAMD,
    VkPhysicalDeviceToolProperties,
    VkPhysicalDeviceToolPropertiesEXT,
    VkSamplerCustomBorderColorCreateInfoEXT,
    VkPhysicalDeviceCustomBorderColorPropertiesEXT,
    VkPhysicalDeviceCustomBorderColorFeaturesEXT,
    VkSamplerBorderColorComponentMappingCreateInfoEXT,
    VkPhysicalDeviceBorderColorSwizzleFeaturesEXT,
    VkAccelerationStructureGeometryTrianglesDataKHR,
    VkAccelerationStructureGeometryAabbsDataKHR,
    VkAccelerationStructureGeometryInstancesDataKHR,
    VkAccelerationStructureGeometryKHR,
    VkAccelerationStructureBuildGeometryInfoKHR,
    VkAccelerationStructureBuildRangeInfoKHR,
    VkAccelerationStructureCreateInfoKHR,
    VkAabbPositionsKHR,
    VkAabbPositionsNV,
    VkTransformMatrixKHR,
    VkTransformMatrixNV,
    VkAccelerationStructureInstanceKHR,
    VkAccelerationStructureInstanceNV,
    VkAccelerationStructureDeviceAddressInfoKHR,
    VkAccelerationStructureVersionInfoKHR,
    VkCopyAccelerationStructureInfoKHR,
    VkCopyAccelerationStructureToMemoryInfoKHR,
    VkCopyMemoryToAccelerationStructureInfoKHR,
    VkRayTracingPipelineInterfaceCreateInfoKHR,
    VkPipelineLibraryCreateInfoKHR,
    VkPhysicalDeviceExtendedDynamicStateFeaturesEXT,
    VkPhysicalDeviceExtendedDynamicState2FeaturesEXT,
    VkPhysicalDeviceExtendedDynamicState3FeaturesEXT,
    VkPhysicalDeviceExtendedDynamicState3PropertiesEXT,
    VkColorBlendEquationEXT,
    VkColorBlendAdvancedEXT,
    VkRenderPassTransformBeginInfoQCOM,
    VkCopyCommandTransformInfoQCOM,
    VkCommandBufferInheritanceRenderPassTransformInfoQCOM,
    VkPhysicalDeviceDiagnosticsConfigFeaturesNV,
    VkDeviceDiagnosticsConfigCreateInfoNV,
    VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures,
    VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR,
    VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR,
    VkPhysicalDeviceRobustness2FeaturesEXT,
    VkPhysicalDeviceRobustness2PropertiesEXT,
    VkPhysicalDeviceImageRobustnessFeatures,
    VkPhysicalDeviceImageRobustnessFeaturesEXT,
    VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR,
    VkPhysicalDevicePortabilitySubsetFeaturesKHR,
    VkPhysicalDevicePortabilitySubsetPropertiesKHR,
    VkPhysicalDevice4444FormatsFeaturesEXT,
    VkPhysicalDeviceSubpassShadingFeaturesHUAWEI,
    VkBufferCopy2,
    VkBufferCopy2KHR,
    VkImageCopy2,
    VkImageCopy2KHR,
    VkImageBlit2,
    VkImageBlit2KHR,
    VkBufferImageCopy2,
    VkBufferImageCopy2KHR,
    VkImageResolve2,
    VkImageResolve2KHR,
    VkCopyBufferInfo2,
    VkCopyBufferInfo2KHR,
    VkCopyImageInfo2,
    VkCopyImageInfo2KHR,
    VkBlitImageInfo2,
    VkBlitImageInfo2KHR,
    VkCopyBufferToImageInfo2,
    VkCopyBufferToImageInfo2KHR,
    VkCopyImageToBufferInfo2,
    VkCopyImageToBufferInfo2KHR,
    VkResolveImageInfo2,
    VkResolveImageInfo2KHR,
    VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT,
    VkFragmentShadingRateAttachmentInfoKHR,
    VkPipelineFragmentShadingRateStateCreateInfoKHR,
    VkPhysicalDeviceFragmentShadingRateFeaturesKHR,
    VkPhysicalDeviceFragmentShadingRatePropertiesKHR,
    VkPhysicalDeviceFragmentShadingRateKHR,
    VkPhysicalDeviceShaderTerminateInvocationFeatures,
    VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR,
    VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV,
    VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV,
    VkPipelineFragmentShadingRateEnumStateCreateInfoNV,
    VkAccelerationStructureBuildSizesInfoKHR,
    VkPhysicalDeviceImage2DViewOf3DFeaturesEXT,
    VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT,
    VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE,
    VkMutableDescriptorTypeListEXT,
    VkMutableDescriptorTypeListVALVE,
    VkMutableDescriptorTypeCreateInfoEXT,
    VkMutableDescriptorTypeCreateInfoVALVE,
    VkPhysicalDeviceDepthClipControlFeaturesEXT,
    VkPipelineViewportDepthClipControlCreateInfoEXT,
    VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT,
    VkPhysicalDeviceExternalMemoryRDMAFeaturesNV,
    VkVertexInputBindingDescription2EXT,
    VkVertexInputAttributeDescription2EXT,
    VkPhysicalDeviceColorWriteEnableFeaturesEXT,
    VkPipelineColorWriteCreateInfoEXT,
    VkMemoryBarrier2,
    VkMemoryBarrier2KHR,
    VkImageMemoryBarrier2,
    VkImageMemoryBarrier2KHR,
    VkBufferMemoryBarrier2,
    VkBufferMemoryBarrier2KHR,
    VkDependencyInfo,
    VkDependencyInfoKHR,
    VkSemaphoreSubmitInfo,
    VkSemaphoreSubmitInfoKHR,
    VkCommandBufferSubmitInfo,
    VkCommandBufferSubmitInfoKHR,
    VkSubmitInfo2,
    VkSubmitInfo2KHR,
    VkQueueFamilyCheckpointProperties2NV,
    VkCheckpointData2NV,
    VkPhysicalDeviceSynchronization2Features,
    VkPhysicalDeviceSynchronization2FeaturesKHR,
    VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT,
    VkPhysicalDeviceLegacyDitheringFeaturesEXT,
    VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT,
    VkSubpassResolvePerformanceQueryEXT,
    VkMultisampledRenderToSingleSampledInfoEXT,
    VkPhysicalDevicePipelineProtectedAccessFeaturesEXT,
    VkQueueFamilyVideoPropertiesKHR,
    VkQueueFamilyQueryResultStatusPropertiesKHR,
    VkVideoProfileListInfoKHR,
    VkPhysicalDeviceVideoFormatInfoKHR,
    VkVideoFormatPropertiesKHR,
    VkVideoProfileInfoKHR,
    VkVideoCapabilitiesKHR,
    VkVideoSessionMemoryRequirementsKHR,
    VkBindVideoSessionMemoryInfoKHR,
    VkVideoPictureResourceInfoKHR,
    VkVideoReferenceSlotInfoKHR,
    VkVideoDecodeCapabilitiesKHR,
    VkVideoDecodeUsageInfoKHR,
    VkVideoDecodeInfoKHR,
    VkVideoDecodeH264ProfileInfoEXT,
    VkVideoDecodeH264CapabilitiesEXT,
    VkVideoDecodeH264SessionParametersAddInfoEXT,
    VkVideoDecodeH264SessionParametersCreateInfoEXT,
    VkVideoDecodeH264PictureInfoEXT,
    VkVideoDecodeH264DpbSlotInfoEXT,
    VkVideoDecodeH265ProfileInfoEXT,
    VkVideoDecodeH265CapabilitiesEXT,
    VkVideoDecodeH265SessionParametersAddInfoEXT,
    VkVideoDecodeH265SessionParametersCreateInfoEXT,
    VkVideoDecodeH265PictureInfoEXT,
    VkVideoDecodeH265DpbSlotInfoEXT,
    VkVideoSessionCreateInfoKHR,
    VkVideoSessionParametersCreateInfoKHR,
    VkVideoSessionParametersUpdateInfoKHR,
    VkVideoBeginCodingInfoKHR,
    VkVideoEndCodingInfoKHR,
    VkVideoCodingControlInfoKHR,
    VkVideoEncodeUsageInfoKHR,
    VkVideoEncodeInfoKHR,
    VkVideoEncodeRateControlInfoKHR,
    VkVideoEncodeRateControlLayerInfoKHR,
    VkVideoEncodeCapabilitiesKHR,
    VkVideoEncodeH264CapabilitiesEXT,
    VkVideoEncodeH264SessionParametersAddInfoEXT,
    VkVideoEncodeH264SessionParametersCreateInfoEXT,
    VkVideoEncodeH264DpbSlotInfoEXT,
    VkVideoEncodeH264VclFrameInfoEXT,
    VkVideoEncodeH264ReferenceListsInfoEXT,
    VkVideoEncodeH264EmitPictureParametersInfoEXT,
    VkVideoEncodeH264ProfileInfoEXT,
    VkVideoEncodeH264NaluSliceInfoEXT,
    VkVideoEncodeH264RateControlInfoEXT,
    VkVideoEncodeH264QpEXT,
    VkVideoEncodeH264FrameSizeEXT,
    VkVideoEncodeH264RateControlLayerInfoEXT,
    VkVideoEncodeH265CapabilitiesEXT,
    VkVideoEncodeH265SessionParametersAddInfoEXT,
    VkVideoEncodeH265SessionParametersCreateInfoEXT,
    VkVideoEncodeH265VclFrameInfoEXT,
    VkVideoEncodeH265EmitPictureParametersInfoEXT,
    VkVideoEncodeH265NaluSliceSegmentInfoEXT,
    VkVideoEncodeH265RateControlInfoEXT,
    VkVideoEncodeH265QpEXT,
    VkVideoEncodeH265FrameSizeEXT,
    VkVideoEncodeH265RateControlLayerInfoEXT,
    VkVideoEncodeH265ProfileInfoEXT,
    VkVideoEncodeH265DpbSlotInfoEXT,
    VkVideoEncodeH265ReferenceListsInfoEXT,
    VkPhysicalDeviceInheritedViewportScissorFeaturesNV,
    VkCommandBufferInheritanceViewportScissorInfoNV,
    VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT,
    VkPhysicalDeviceProvokingVertexFeaturesEXT,
    VkPhysicalDeviceProvokingVertexPropertiesEXT,
    VkPipelineRasterizationProvokingVertexStateCreateInfoEXT,
    VkCuModuleCreateInfoNVX,
    VkCuFunctionCreateInfoNVX,
    VkCuLaunchInfoNVX,
    VkPhysicalDeviceShaderIntegerDotProductFeatures,
    VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR,
    VkPhysicalDeviceShaderIntegerDotProductProperties,
    VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR,
    VkPhysicalDeviceDrmPropertiesEXT,
    VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR,
    VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR,
    VkPhysicalDeviceRayTracingMotionBlurFeaturesNV,
    VkAccelerationStructureGeometryMotionTrianglesDataNV,
    VkAccelerationStructureMotionInfoNV,
    VkSRTDataNV,
    VkAccelerationStructureSRTMotionInstanceNV,
    VkAccelerationStructureMatrixMotionInstanceNV,
    VkAccelerationStructureMotionInstanceNV,
    VkMemoryGetRemoteAddressInfoNV,
    VkImportMemoryBufferCollectionFUCHSIA,
    VkBufferCollectionImageCreateInfoFUCHSIA,
    VkBufferCollectionBufferCreateInfoFUCHSIA,
    VkBufferCollectionCreateInfoFUCHSIA,
    VkBufferCollectionPropertiesFUCHSIA,
    VkBufferConstraintsInfoFUCHSIA,
    VkSysmemColorSpaceFUCHSIA,
    VkImageFormatConstraintsInfoFUCHSIA,
    VkImageConstraintsInfoFUCHSIA,
    VkBufferCollectionConstraintsInfoFUCHSIA,
    VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT,
    VkFormatProperties3,
    VkFormatProperties3KHR,
    VkDrmFormatModifierPropertiesList2EXT,
    VkDrmFormatModifierProperties2EXT,
    VkAndroidHardwareBufferFormatProperties2ANDROID,
    VkPipelineRenderingCreateInfo,
    VkPipelineRenderingCreateInfoKHR,
    VkRenderingInfo,
    VkRenderingInfoKHR,
    VkRenderingAttachmentInfo,
    VkRenderingAttachmentInfoKHR,
    VkRenderingFragmentShadingRateAttachmentInfoKHR,
    VkRenderingFragmentDensityMapAttachmentInfoEXT,
    VkPhysicalDeviceDynamicRenderingFeatures,
    VkPhysicalDeviceDynamicRenderingFeaturesKHR,
    VkCommandBufferInheritanceRenderingInfo,
    VkCommandBufferInheritanceRenderingInfoKHR,
    VkAttachmentSampleCountInfoAMD,
    VkAttachmentSampleCountInfoNV,
    VkMultiviewPerViewAttributesInfoNVX,
    VkPhysicalDeviceImageViewMinLodFeaturesEXT,
    VkImageViewMinLodCreateInfoEXT,
    VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT,
    VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM,
    VkPhysicalDeviceLinearColorAttachmentFeaturesNV,
    VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT,
    VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT,
    VkGraphicsPipelineLibraryCreateInfoEXT,
    VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE,
    VkDescriptorSetBindingReferenceVALVE,
    VkDescriptorSetLayoutHostMappingInfoVALVE,
    VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT,
    VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT,
    VkPipelineShaderStageModuleIdentifierCreateInfoEXT,
    VkShaderModuleIdentifierEXT,
    VkImageCompressionControlEXT,
    VkPhysicalDeviceImageCompressionControlFeaturesEXT,
    VkImageCompressionPropertiesEXT,
    VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT,
    VkImageSubresource2EXT,
    VkSubresourceLayout2EXT,
    VkRenderPassCreationControlEXT,
    VkRenderPassCreationFeedbackInfoEXT,
    VkRenderPassCreationFeedbackCreateInfoEXT,
    VkRenderPassSubpassFeedbackInfoEXT,
    VkRenderPassSubpassFeedbackCreateInfoEXT,
    VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT,
    VkMicromapBuildInfoEXT,
    VkMicromapCreateInfoEXT,
    VkMicromapVersionInfoEXT,
    VkCopyMicromapInfoEXT,
    VkCopyMicromapToMemoryInfoEXT,
    VkCopyMemoryToMicromapInfoEXT,
    VkMicromapBuildSizesInfoEXT,
    VkMicromapUsageEXT,
    VkMicromapTriangleEXT,
    VkPhysicalDeviceOpacityMicromapFeaturesEXT,
    VkPhysicalDeviceOpacityMicromapPropertiesEXT,
    VkAccelerationStructureTrianglesOpacityMicromapEXT,
    VkPipelinePropertiesIdentifierEXT,
    VkPhysicalDevicePipelinePropertiesFeaturesEXT,
    VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD,
    VkExportMetalObjectCreateInfoEXT,
    VkExportMetalObjectsInfoEXT,
    VkExportMetalDeviceInfoEXT,
    VkExportMetalCommandQueueInfoEXT,
    VkExportMetalBufferInfoEXT,
    VkImportMetalBufferInfoEXT,
    VkExportMetalTextureInfoEXT,
    VkImportMetalTextureInfoEXT,
    VkExportMetalIOSurfaceInfoEXT,
    VkImportMetalIOSurfaceInfoEXT,
    VkExportMetalSharedEventInfoEXT,
    VkImportMetalSharedEventInfoEXT,
    VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT,
    VkPhysicalDevicePipelineRobustnessFeaturesEXT,
    VkPipelineRobustnessCreateInfoEXT,
    VkPhysicalDevicePipelineRobustnessPropertiesEXT,
    VkImageViewSampleWeightCreateInfoQCOM,
    VkPhysicalDeviceImageProcessingFeaturesQCOM,
    VkPhysicalDeviceImageProcessingPropertiesQCOM,
    VkPhysicalDeviceTilePropertiesFeaturesQCOM,
    VkTilePropertiesQCOM,
    VkPhysicalDeviceAmigoProfilingFeaturesSEC,
    VkAmigoProfilingSubmitInfoSEC,
    VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT,
    VkPhysicalDeviceDepthClampZeroOneFeaturesEXT,
    VkPhysicalDeviceAddressBindingReportFeaturesEXT,
    VkDeviceAddressBindingCallbackDataEXT,
    VkPhysicalDeviceOpticalFlowFeaturesNV,
    VkPhysicalDeviceOpticalFlowPropertiesNV,
    VkOpticalFlowImageFormatInfoNV,
    VkOpticalFlowImageFormatPropertiesNV,
    VkOpticalFlowSessionCreateInfoNV,
    VkOpticalFlowSessionCreatePrivateDataInfoNV,
    VkOpticalFlowExecuteInfoNV,
    VkPhysicalDeviceFaultFeaturesEXT,
    VkDeviceFaultAddressInfoEXT,
    VkDeviceFaultVendorInfoEXT,
    VkDeviceFaultCountsEXT,
    VkDeviceFaultInfoEXT,
    VkDeviceFaultVendorBinaryHeaderVersionOneEXT,
    VkDecompressMemoryRegionNV,
    VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM,
    VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM,
    VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV,
    VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV, 
    VK_MAKE_API_VERSION
};
