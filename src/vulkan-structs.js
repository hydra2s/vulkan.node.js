
import {default as V} from "./vulkan-API.js";
import {default as enums} from "./vulkan-enums.js";
import {default as C} from "./typed.js";
const callof = (fn)=>{ return fn ? fn() : 0; };

const VK_MAKE_API_VERSION = (variant, major, minor, patch) => {
    return ((((variant)) << 29) | (((major)) << 22) | (((minor)) << 12) | ((patch)));
};

//

const VkBaseOutStructure = new C.CStruct("VkBaseOutStructure", {
    sType: "u32("+callof(V.VkBaseOutStructure_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBaseOutStructure_pNext_offsetof)+")",
}, callof(V.VkBaseOutStructure_sizeof));


const VkBaseInStructure = new C.CStruct("VkBaseInStructure", {
    sType: "u32("+callof(V.VkBaseInStructure_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBaseInStructure_pNext_offsetof)+")",
}, callof(V.VkBaseInStructure_sizeof));


const VkOffset2D = new C.CStruct("VkOffset2D", {
    x: "i32("+callof(V.VkOffset2D_x_offsetof)+")",
    y: "i32("+callof(V.VkOffset2D_y_offsetof)+")",
}, callof(V.VkOffset2D_sizeof));


const VkOffset3D = new C.CStruct("VkOffset3D", {
    x: "i32("+callof(V.VkOffset3D_x_offsetof)+")",
    y: "i32("+callof(V.VkOffset3D_y_offsetof)+")",
    z: "i32("+callof(V.VkOffset3D_z_offsetof)+")",
}, callof(V.VkOffset3D_sizeof));


const VkExtent2D = new C.CStruct("VkExtent2D", {
    width: "u32("+callof(V.VkExtent2D_width_offsetof)+")",
    height: "u32("+callof(V.VkExtent2D_height_offsetof)+")",
}, callof(V.VkExtent2D_sizeof));


const VkExtent3D = new C.CStruct("VkExtent3D", {
    width: "u32("+callof(V.VkExtent3D_width_offsetof)+")",
    height: "u32("+callof(V.VkExtent3D_height_offsetof)+")",
    depth: "u32("+callof(V.VkExtent3D_depth_offsetof)+")",
}, callof(V.VkExtent3D_sizeof));


const VkViewport = new C.CStruct("VkViewport", {
    x: "f32("+callof(V.VkViewport_x_offsetof)+")",
    y: "f32("+callof(V.VkViewport_y_offsetof)+")",
    width: "f32("+callof(V.VkViewport_width_offsetof)+")",
    height: "f32("+callof(V.VkViewport_height_offsetof)+")",
    minDepth: "f32("+callof(V.VkViewport_minDepth_offsetof)+")",
    maxDepth: "f32("+callof(V.VkViewport_maxDepth_offsetof)+")",
}, callof(V.VkViewport_sizeof));


const VkRect2D = new C.CStruct("VkRect2D", {
    offset: "VkOffset2D("+callof(V.VkRect2D_offset_offsetof)+")",
    extent: "VkExtent2D("+callof(V.VkRect2D_extent_offsetof)+")",
}, callof(V.VkRect2D_sizeof));


const VkClearRect = new C.CStruct("VkClearRect", {
    rect: "VkRect2D("+callof(V.VkClearRect_rect_offsetof)+")",
    baseArrayLayer: "u32("+callof(V.VkClearRect_baseArrayLayer_offsetof)+")",
    layerCount: "u32("+callof(V.VkClearRect_layerCount_offsetof)+")",
}, callof(V.VkClearRect_sizeof));


const VkComponentMapping = new C.CStruct("VkComponentMapping", {
    r: "u32("+callof(V.VkComponentMapping_r_offsetof)+")",
    g: "u32("+callof(V.VkComponentMapping_g_offsetof)+")",
    b: "u32("+callof(V.VkComponentMapping_b_offsetof)+")",
    a: "u32("+callof(V.VkComponentMapping_a_offsetof)+")",
}, callof(V.VkComponentMapping_sizeof));


const VkPhysicalDeviceProperties = new C.CStruct("VkPhysicalDeviceProperties", {
    apiVersion: "u32("+callof(V.VkPhysicalDeviceProperties_apiVersion_offsetof)+")",
    driverVersion: "u32("+callof(V.VkPhysicalDeviceProperties_driverVersion_offsetof)+")",
    vendorID: "u32("+callof(V.VkPhysicalDeviceProperties_vendorID_offsetof)+")",
    deviceID: "u32("+callof(V.VkPhysicalDeviceProperties_deviceID_offsetof)+")",
    deviceType: "u32("+callof(V.VkPhysicalDeviceProperties_deviceType_offsetof)+")",
    deviceName: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceProperties_deviceName_offsetof)+")",
    pipelineCacheUUID: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceProperties_pipelineCacheUUID_offsetof)+")",
    limits: "u32("+callof(V.VkPhysicalDeviceProperties_limits_offsetof)+")",
    sparseProperties: "u32("+callof(V.VkPhysicalDeviceProperties_sparseProperties_offsetof)+")",
}, callof(V.VkPhysicalDeviceProperties_sizeof));


const VkExtensionProperties = new C.CStruct("VkExtensionProperties", {
    extensionName: "u8["+(enums.NaN||1)+"]("+callof(V.VkExtensionProperties_extensionName_offsetof)+")",
    specVersion: "u32("+callof(V.VkExtensionProperties_specVersion_offsetof)+")",
}, callof(V.VkExtensionProperties_sizeof));


const VkLayerProperties = new C.CStruct("VkLayerProperties", {
    layerName: "u8["+(enums.NaN||1)+"]("+callof(V.VkLayerProperties_layerName_offsetof)+")",
    specVersion: "u32("+callof(V.VkLayerProperties_specVersion_offsetof)+")",
    implementationVersion: "u32("+callof(V.VkLayerProperties_implementationVersion_offsetof)+")",
    description: "u8["+(enums.NaN||1)+"]("+callof(V.VkLayerProperties_description_offsetof)+")",
}, callof(V.VkLayerProperties_sizeof));


const VkApplicationInfo = new C.CStruct("VkApplicationInfo", {
    sType: "u32("+callof(V.VkApplicationInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkApplicationInfo_pNext_offsetof)+")",
    pApplicationName: "u64("+callof(V.VkApplicationInfo_pApplicationName_offsetof)+")",
    applicationVersion: "u32("+callof(V.VkApplicationInfo_applicationVersion_offsetof)+")",
    pEngineName: "u64("+callof(V.VkApplicationInfo_pEngineName_offsetof)+")",
    engineVersion: "u32("+callof(V.VkApplicationInfo_engineVersion_offsetof)+")",
    apiVersion: "u32("+callof(V.VkApplicationInfo_apiVersion_offsetof)+")",
}, callof(V.VkApplicationInfo_sizeof));


const VkAllocationCallbacks = new C.CStruct("VkAllocationCallbacks", {
    pUserData: "u64("+callof(V.VkAllocationCallbacks_pUserData_offsetof)+")",
    pfnAllocation: "u32("+callof(V.VkAllocationCallbacks_pfnAllocation_offsetof)+")",
    pfnReallocation: "u32("+callof(V.VkAllocationCallbacks_pfnReallocation_offsetof)+")",
    pfnFree: "u32("+callof(V.VkAllocationCallbacks_pfnFree_offsetof)+")",
    pfnInternalAllocation: "u32("+callof(V.VkAllocationCallbacks_pfnInternalAllocation_offsetof)+")",
    pfnInternalFree: "u32("+callof(V.VkAllocationCallbacks_pfnInternalFree_offsetof)+")",
}, callof(V.VkAllocationCallbacks_sizeof));


const VkDeviceQueueCreateInfo = new C.CStruct("VkDeviceQueueCreateInfo", {
    sType: "u32("+callof(V.VkDeviceQueueCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceQueueCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDeviceQueueCreateInfo_flags_offsetof)+")",
    queueFamilyIndex: "u32("+callof(V.VkDeviceQueueCreateInfo_queueFamilyIndex_offsetof)+")",
    queueCount: "u32("+callof(V.VkDeviceQueueCreateInfo_queueCount_offsetof)+")",
    pQueuePriorities: "u64("+callof(V.VkDeviceQueueCreateInfo_pQueuePriorities_offsetof)+")",
}, callof(V.VkDeviceQueueCreateInfo_sizeof));


const VkDeviceCreateInfo = new C.CStruct("VkDeviceCreateInfo", {
    sType: "u32("+callof(V.VkDeviceCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDeviceCreateInfo_flags_offsetof)+")",
    queueCreateInfoCount: "u32("+callof(V.VkDeviceCreateInfo_queueCreateInfoCount_offsetof)+")",
    pQueueCreateInfos: "u64("+callof(V.VkDeviceCreateInfo_pQueueCreateInfos_offsetof)+")",
    enabledLayerCount: "u32("+callof(V.VkDeviceCreateInfo_enabledLayerCount_offsetof)+")",
    ppEnabledLayerNames: "u64("+callof(V.VkDeviceCreateInfo_ppEnabledLayerNames_offsetof)+")",
    enabledExtensionCount: "u32("+callof(V.VkDeviceCreateInfo_enabledExtensionCount_offsetof)+")",
    ppEnabledExtensionNames: "u64("+callof(V.VkDeviceCreateInfo_ppEnabledExtensionNames_offsetof)+")",
    pEnabledFeatures: "u64("+callof(V.VkDeviceCreateInfo_pEnabledFeatures_offsetof)+")",
}, callof(V.VkDeviceCreateInfo_sizeof));


const VkInstanceCreateInfo = new C.CStruct("VkInstanceCreateInfo", {
    sType: "u32("+callof(V.VkInstanceCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkInstanceCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkInstanceCreateInfo_flags_offsetof)+")",
    pApplicationInfo: "u64("+callof(V.VkInstanceCreateInfo_pApplicationInfo_offsetof)+")",
    enabledLayerCount: "u32("+callof(V.VkInstanceCreateInfo_enabledLayerCount_offsetof)+")",
    ppEnabledLayerNames: "u64("+callof(V.VkInstanceCreateInfo_ppEnabledLayerNames_offsetof)+")",
    enabledExtensionCount: "u32("+callof(V.VkInstanceCreateInfo_enabledExtensionCount_offsetof)+")",
    ppEnabledExtensionNames: "u64("+callof(V.VkInstanceCreateInfo_ppEnabledExtensionNames_offsetof)+")",
}, callof(V.VkInstanceCreateInfo_sizeof));


const VkQueueFamilyProperties = new C.CStruct("VkQueueFamilyProperties", {
    queueFlags: "u32("+callof(V.VkQueueFamilyProperties_queueFlags_offsetof)+")",
    queueCount: "u32("+callof(V.VkQueueFamilyProperties_queueCount_offsetof)+")",
    timestampValidBits: "u32("+callof(V.VkQueueFamilyProperties_timestampValidBits_offsetof)+")",
    minImageTransferGranularity: "u32("+callof(V.VkQueueFamilyProperties_minImageTransferGranularity_offsetof)+")",
}, callof(V.VkQueueFamilyProperties_sizeof));


const VkPhysicalDeviceMemoryProperties = new C.CStruct("VkPhysicalDeviceMemoryProperties", {
    memoryTypeCount: "u32("+callof(V.VkPhysicalDeviceMemoryProperties_memoryTypeCount_offsetof)+")",
    memoryTypes: "u32["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceMemoryProperties_memoryTypes_offsetof)+")",
    memoryHeapCount: "u32("+callof(V.VkPhysicalDeviceMemoryProperties_memoryHeapCount_offsetof)+")",
    memoryHeaps: "u32["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceMemoryProperties_memoryHeaps_offsetof)+")",
}, callof(V.VkPhysicalDeviceMemoryProperties_sizeof));


const VkMemoryAllocateInfo = new C.CStruct("VkMemoryAllocateInfo", {
    sType: "u32("+callof(V.VkMemoryAllocateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryAllocateInfo_pNext_offsetof)+")",
    allocationSize: "u64("+callof(V.VkMemoryAllocateInfo_allocationSize_offsetof)+")",
    memoryTypeIndex: "u32("+callof(V.VkMemoryAllocateInfo_memoryTypeIndex_offsetof)+")",
}, callof(V.VkMemoryAllocateInfo_sizeof));


const VkMemoryRequirements = new C.CStruct("VkMemoryRequirements", {
    size: "u64("+callof(V.VkMemoryRequirements_size_offsetof)+")",
    alignment: "u64("+callof(V.VkMemoryRequirements_alignment_offsetof)+")",
    memoryTypeBits: "u32("+callof(V.VkMemoryRequirements_memoryTypeBits_offsetof)+")",
}, callof(V.VkMemoryRequirements_sizeof));


const VkSparseImageFormatProperties = new C.CStruct("VkSparseImageFormatProperties", {
    aspectMask: "u32("+callof(V.VkSparseImageFormatProperties_aspectMask_offsetof)+")",
    imageGranularity: "u32("+callof(V.VkSparseImageFormatProperties_imageGranularity_offsetof)+")",
    flags: "u32("+callof(V.VkSparseImageFormatProperties_flags_offsetof)+")",
}, callof(V.VkSparseImageFormatProperties_sizeof));


const VkSparseImageMemoryRequirements = new C.CStruct("VkSparseImageMemoryRequirements", {
    formatProperties: "u32("+callof(V.VkSparseImageMemoryRequirements_formatProperties_offsetof)+")",
    imageMipTailFirstLod: "u32("+callof(V.VkSparseImageMemoryRequirements_imageMipTailFirstLod_offsetof)+")",
    imageMipTailSize: "u64("+callof(V.VkSparseImageMemoryRequirements_imageMipTailSize_offsetof)+")",
    imageMipTailOffset: "u64("+callof(V.VkSparseImageMemoryRequirements_imageMipTailOffset_offsetof)+")",
    imageMipTailStride: "u64("+callof(V.VkSparseImageMemoryRequirements_imageMipTailStride_offsetof)+")",
}, callof(V.VkSparseImageMemoryRequirements_sizeof));


const VkMemoryType = new C.CStruct("VkMemoryType", {
    propertyFlags: "u32("+callof(V.VkMemoryType_propertyFlags_offsetof)+")",
    heapIndex: "u32("+callof(V.VkMemoryType_heapIndex_offsetof)+")",
}, callof(V.VkMemoryType_sizeof));


const VkMemoryHeap = new C.CStruct("VkMemoryHeap", {
    size: "u64("+callof(V.VkMemoryHeap_size_offsetof)+")",
    flags: "u32("+callof(V.VkMemoryHeap_flags_offsetof)+")",
}, callof(V.VkMemoryHeap_sizeof));


const VkMappedMemoryRange = new C.CStruct("VkMappedMemoryRange", {
    sType: "u32("+callof(V.VkMappedMemoryRange_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMappedMemoryRange_pNext_offsetof)+")",
    memory: "u64("+callof(V.VkMappedMemoryRange_memory_offsetof)+")",
    offset: "u64("+callof(V.VkMappedMemoryRange_offset_offsetof)+")",
    size: "u64("+callof(V.VkMappedMemoryRange_size_offsetof)+")",
}, callof(V.VkMappedMemoryRange_sizeof));


const VkFormatProperties = new C.CStruct("VkFormatProperties", {
    linearTilingFeatures: "u32("+callof(V.VkFormatProperties_linearTilingFeatures_offsetof)+")",
    optimalTilingFeatures: "u32("+callof(V.VkFormatProperties_optimalTilingFeatures_offsetof)+")",
    bufferFeatures: "u32("+callof(V.VkFormatProperties_bufferFeatures_offsetof)+")",
}, callof(V.VkFormatProperties_sizeof));


const VkImageFormatProperties = new C.CStruct("VkImageFormatProperties", {
    maxExtent: "u32("+callof(V.VkImageFormatProperties_maxExtent_offsetof)+")",
    maxMipLevels: "u32("+callof(V.VkImageFormatProperties_maxMipLevels_offsetof)+")",
    maxArrayLayers: "u32("+callof(V.VkImageFormatProperties_maxArrayLayers_offsetof)+")",
    sampleCounts: "u32("+callof(V.VkImageFormatProperties_sampleCounts_offsetof)+")",
    maxResourceSize: "u64("+callof(V.VkImageFormatProperties_maxResourceSize_offsetof)+")",
}, callof(V.VkImageFormatProperties_sizeof));


const VkDescriptorBufferInfo = new C.CStruct("VkDescriptorBufferInfo", {
    buffer: "u64("+callof(V.VkDescriptorBufferInfo_buffer_offsetof)+")",
    offset: "u64("+callof(V.VkDescriptorBufferInfo_offset_offsetof)+")",
    range: "u64("+callof(V.VkDescriptorBufferInfo_range_offsetof)+")",
}, callof(V.VkDescriptorBufferInfo_sizeof));


const VkDescriptorImageInfo = new C.CStruct("VkDescriptorImageInfo", {
    sampler: "u64("+callof(V.VkDescriptorImageInfo_sampler_offsetof)+")",
    imageView: "u32("+callof(V.VkDescriptorImageInfo_imageView_offsetof)+")",
    imageLayout: "u32("+callof(V.VkDescriptorImageInfo_imageLayout_offsetof)+")",
}, callof(V.VkDescriptorImageInfo_sizeof));


const VkWriteDescriptorSet = new C.CStruct("VkWriteDescriptorSet", {
    sType: "u32("+callof(V.VkWriteDescriptorSet_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkWriteDescriptorSet_pNext_offsetof)+")",
    dstSet: "u32("+callof(V.VkWriteDescriptorSet_dstSet_offsetof)+")",
    dstBinding: "u32("+callof(V.VkWriteDescriptorSet_dstBinding_offsetof)+")",
    dstArrayElement: "u32("+callof(V.VkWriteDescriptorSet_dstArrayElement_offsetof)+")",
    descriptorCount: "u32("+callof(V.VkWriteDescriptorSet_descriptorCount_offsetof)+")",
    descriptorType: "u32("+callof(V.VkWriteDescriptorSet_descriptorType_offsetof)+")",
    pImageInfo: "u64("+callof(V.VkWriteDescriptorSet_pImageInfo_offsetof)+")",
    pBufferInfo: "u64("+callof(V.VkWriteDescriptorSet_pBufferInfo_offsetof)+")",
    pTexelBufferView: "u64("+callof(V.VkWriteDescriptorSet_pTexelBufferView_offsetof)+")",
}, callof(V.VkWriteDescriptorSet_sizeof));


const VkCopyDescriptorSet = new C.CStruct("VkCopyDescriptorSet", {
    sType: "u32("+callof(V.VkCopyDescriptorSet_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCopyDescriptorSet_pNext_offsetof)+")",
    srcSet: "u32("+callof(V.VkCopyDescriptorSet_srcSet_offsetof)+")",
    srcBinding: "u32("+callof(V.VkCopyDescriptorSet_srcBinding_offsetof)+")",
    srcArrayElement: "u32("+callof(V.VkCopyDescriptorSet_srcArrayElement_offsetof)+")",
    dstSet: "u32("+callof(V.VkCopyDescriptorSet_dstSet_offsetof)+")",
    dstBinding: "u32("+callof(V.VkCopyDescriptorSet_dstBinding_offsetof)+")",
    dstArrayElement: "u32("+callof(V.VkCopyDescriptorSet_dstArrayElement_offsetof)+")",
    descriptorCount: "u32("+callof(V.VkCopyDescriptorSet_descriptorCount_offsetof)+")",
}, callof(V.VkCopyDescriptorSet_sizeof));


const VkBufferCreateInfo = new C.CStruct("VkBufferCreateInfo", {
    sType: "u32("+callof(V.VkBufferCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkBufferCreateInfo_flags_offsetof)+")",
    size: "u64("+callof(V.VkBufferCreateInfo_size_offsetof)+")",
    usage: "u32("+callof(V.VkBufferCreateInfo_usage_offsetof)+")",
    sharingMode: "u32("+callof(V.VkBufferCreateInfo_sharingMode_offsetof)+")",
    queueFamilyIndexCount: "u32("+callof(V.VkBufferCreateInfo_queueFamilyIndexCount_offsetof)+")",
    pQueueFamilyIndices: "u64("+callof(V.VkBufferCreateInfo_pQueueFamilyIndices_offsetof)+")",
}, callof(V.VkBufferCreateInfo_sizeof));


const VkBufferViewCreateInfo = new C.CStruct("VkBufferViewCreateInfo", {
    sType: "u32("+callof(V.VkBufferViewCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferViewCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkBufferViewCreateInfo_flags_offsetof)+")",
    buffer: "u64("+callof(V.VkBufferViewCreateInfo_buffer_offsetof)+")",
    format: "u32("+callof(V.VkBufferViewCreateInfo_format_offsetof)+")",
    offset: "u64("+callof(V.VkBufferViewCreateInfo_offset_offsetof)+")",
    range: "u64("+callof(V.VkBufferViewCreateInfo_range_offsetof)+")",
}, callof(V.VkBufferViewCreateInfo_sizeof));


const VkImageSubresource = new C.CStruct("VkImageSubresource", {
    aspectMask: "u32("+callof(V.VkImageSubresource_aspectMask_offsetof)+")",
    mipLevel: "u32("+callof(V.VkImageSubresource_mipLevel_offsetof)+")",
    arrayLayer: "u32("+callof(V.VkImageSubresource_arrayLayer_offsetof)+")",
}, callof(V.VkImageSubresource_sizeof));


const VkImageSubresourceLayers = new C.CStruct("VkImageSubresourceLayers", {
    aspectMask: "u32("+callof(V.VkImageSubresourceLayers_aspectMask_offsetof)+")",
    mipLevel: "u32("+callof(V.VkImageSubresourceLayers_mipLevel_offsetof)+")",
    baseArrayLayer: "u32("+callof(V.VkImageSubresourceLayers_baseArrayLayer_offsetof)+")",
    layerCount: "u32("+callof(V.VkImageSubresourceLayers_layerCount_offsetof)+")",
}, callof(V.VkImageSubresourceLayers_sizeof));


const VkImageSubresourceRange = new C.CStruct("VkImageSubresourceRange", {
    aspectMask: "u32("+callof(V.VkImageSubresourceRange_aspectMask_offsetof)+")",
    baseMipLevel: "u32("+callof(V.VkImageSubresourceRange_baseMipLevel_offsetof)+")",
    levelCount: "u32("+callof(V.VkImageSubresourceRange_levelCount_offsetof)+")",
    baseArrayLayer: "u32("+callof(V.VkImageSubresourceRange_baseArrayLayer_offsetof)+")",
    layerCount: "u32("+callof(V.VkImageSubresourceRange_layerCount_offsetof)+")",
}, callof(V.VkImageSubresourceRange_sizeof));


const VkMemoryBarrier = new C.CStruct("VkMemoryBarrier", {
    sType: "u32("+callof(V.VkMemoryBarrier_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryBarrier_pNext_offsetof)+")",
    srcAccessMask: "u32("+callof(V.VkMemoryBarrier_srcAccessMask_offsetof)+")",
    dstAccessMask: "u32("+callof(V.VkMemoryBarrier_dstAccessMask_offsetof)+")",
}, callof(V.VkMemoryBarrier_sizeof));


const VkBufferMemoryBarrier = new C.CStruct("VkBufferMemoryBarrier", {
    sType: "u32("+callof(V.VkBufferMemoryBarrier_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferMemoryBarrier_pNext_offsetof)+")",
    srcAccessMask: "u32("+callof(V.VkBufferMemoryBarrier_srcAccessMask_offsetof)+")",
    dstAccessMask: "u32("+callof(V.VkBufferMemoryBarrier_dstAccessMask_offsetof)+")",
    srcQueueFamilyIndex: "u32("+callof(V.VkBufferMemoryBarrier_srcQueueFamilyIndex_offsetof)+")",
    dstQueueFamilyIndex: "u32("+callof(V.VkBufferMemoryBarrier_dstQueueFamilyIndex_offsetof)+")",
    buffer: "u64("+callof(V.VkBufferMemoryBarrier_buffer_offsetof)+")",
    offset: "u64("+callof(V.VkBufferMemoryBarrier_offset_offsetof)+")",
    size: "u64("+callof(V.VkBufferMemoryBarrier_size_offsetof)+")",
}, callof(V.VkBufferMemoryBarrier_sizeof));


const VkImageMemoryBarrier = new C.CStruct("VkImageMemoryBarrier", {
    sType: "u32("+callof(V.VkImageMemoryBarrier_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageMemoryBarrier_pNext_offsetof)+")",
    srcAccessMask: "u32("+callof(V.VkImageMemoryBarrier_srcAccessMask_offsetof)+")",
    dstAccessMask: "u32("+callof(V.VkImageMemoryBarrier_dstAccessMask_offsetof)+")",
    oldLayout: "u32("+callof(V.VkImageMemoryBarrier_oldLayout_offsetof)+")",
    newLayout: "u32("+callof(V.VkImageMemoryBarrier_newLayout_offsetof)+")",
    srcQueueFamilyIndex: "u32("+callof(V.VkImageMemoryBarrier_srcQueueFamilyIndex_offsetof)+")",
    dstQueueFamilyIndex: "u32("+callof(V.VkImageMemoryBarrier_dstQueueFamilyIndex_offsetof)+")",
    image: "u64("+callof(V.VkImageMemoryBarrier_image_offsetof)+")",
    subresourceRange: "u32("+callof(V.VkImageMemoryBarrier_subresourceRange_offsetof)+")",
}, callof(V.VkImageMemoryBarrier_sizeof));


const VkImageCreateInfo = new C.CStruct("VkImageCreateInfo", {
    sType: "u32("+callof(V.VkImageCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkImageCreateInfo_flags_offsetof)+")",
    imageType: "u32("+callof(V.VkImageCreateInfo_imageType_offsetof)+")",
    format: "u32("+callof(V.VkImageCreateInfo_format_offsetof)+")",
    extent: "u32("+callof(V.VkImageCreateInfo_extent_offsetof)+")",
    mipLevels: "u32("+callof(V.VkImageCreateInfo_mipLevels_offsetof)+")",
    arrayLayers: "u32("+callof(V.VkImageCreateInfo_arrayLayers_offsetof)+")",
    samples: "u32("+callof(V.VkImageCreateInfo_samples_offsetof)+")",
    tiling: "u32("+callof(V.VkImageCreateInfo_tiling_offsetof)+")",
    usage: "u32("+callof(V.VkImageCreateInfo_usage_offsetof)+")",
    sharingMode: "u32("+callof(V.VkImageCreateInfo_sharingMode_offsetof)+")",
    queueFamilyIndexCount: "u32("+callof(V.VkImageCreateInfo_queueFamilyIndexCount_offsetof)+")",
    pQueueFamilyIndices: "u64("+callof(V.VkImageCreateInfo_pQueueFamilyIndices_offsetof)+")",
    initialLayout: "u32("+callof(V.VkImageCreateInfo_initialLayout_offsetof)+")",
}, callof(V.VkImageCreateInfo_sizeof));


const VkSubresourceLayout = new C.CStruct("VkSubresourceLayout", {
    offset: "u64("+callof(V.VkSubresourceLayout_offset_offsetof)+")",
    size: "u64("+callof(V.VkSubresourceLayout_size_offsetof)+")",
    rowPitch: "u64("+callof(V.VkSubresourceLayout_rowPitch_offsetof)+")",
    arrayPitch: "u64("+callof(V.VkSubresourceLayout_arrayPitch_offsetof)+")",
    depthPitch: "u64("+callof(V.VkSubresourceLayout_depthPitch_offsetof)+")",
}, callof(V.VkSubresourceLayout_sizeof));


const VkImageViewCreateInfo = new C.CStruct("VkImageViewCreateInfo", {
    sType: "u32("+callof(V.VkImageViewCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageViewCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkImageViewCreateInfo_flags_offsetof)+")",
    image: "u64("+callof(V.VkImageViewCreateInfo_image_offsetof)+")",
    viewType: "u32("+callof(V.VkImageViewCreateInfo_viewType_offsetof)+")",
    format: "u32("+callof(V.VkImageViewCreateInfo_format_offsetof)+")",
    components: "u32("+callof(V.VkImageViewCreateInfo_components_offsetof)+")",
    subresourceRange: "u32("+callof(V.VkImageViewCreateInfo_subresourceRange_offsetof)+")",
}, callof(V.VkImageViewCreateInfo_sizeof));


const VkBufferCopy = new C.CStruct("VkBufferCopy", {
    srcOffset: "u64("+callof(V.VkBufferCopy_srcOffset_offsetof)+")",
    dstOffset: "u64("+callof(V.VkBufferCopy_dstOffset_offsetof)+")",
    size: "u64("+callof(V.VkBufferCopy_size_offsetof)+")",
}, callof(V.VkBufferCopy_sizeof));


const VkSparseMemoryBind = new C.CStruct("VkSparseMemoryBind", {
    resourceOffset: "u64("+callof(V.VkSparseMemoryBind_resourceOffset_offsetof)+")",
    size: "u64("+callof(V.VkSparseMemoryBind_size_offsetof)+")",
    memory: "u64("+callof(V.VkSparseMemoryBind_memory_offsetof)+")",
    memoryOffset: "u64("+callof(V.VkSparseMemoryBind_memoryOffset_offsetof)+")",
    flags: "u32("+callof(V.VkSparseMemoryBind_flags_offsetof)+")",
}, callof(V.VkSparseMemoryBind_sizeof));


const VkSparseImageMemoryBind = new C.CStruct("VkSparseImageMemoryBind", {
    subresource: "u32("+callof(V.VkSparseImageMemoryBind_subresource_offsetof)+")",
    offset: "u32("+callof(V.VkSparseImageMemoryBind_offset_offsetof)+")",
    extent: "u32("+callof(V.VkSparseImageMemoryBind_extent_offsetof)+")",
    memory: "u64("+callof(V.VkSparseImageMemoryBind_memory_offsetof)+")",
    memoryOffset: "u64("+callof(V.VkSparseImageMemoryBind_memoryOffset_offsetof)+")",
    flags: "u32("+callof(V.VkSparseImageMemoryBind_flags_offsetof)+")",
}, callof(V.VkSparseImageMemoryBind_sizeof));


const VkSparseBufferMemoryBindInfo = new C.CStruct("VkSparseBufferMemoryBindInfo", {
    buffer: "u64("+callof(V.VkSparseBufferMemoryBindInfo_buffer_offsetof)+")",
    bindCount: "u32("+callof(V.VkSparseBufferMemoryBindInfo_bindCount_offsetof)+")",
    pBinds: "u64("+callof(V.VkSparseBufferMemoryBindInfo_pBinds_offsetof)+")",
}, callof(V.VkSparseBufferMemoryBindInfo_sizeof));


const VkSparseImageOpaqueMemoryBindInfo = new C.CStruct("VkSparseImageOpaqueMemoryBindInfo", {
    image: "u64("+callof(V.VkSparseImageOpaqueMemoryBindInfo_image_offsetof)+")",
    bindCount: "u32("+callof(V.VkSparseImageOpaqueMemoryBindInfo_bindCount_offsetof)+")",
    pBinds: "u64("+callof(V.VkSparseImageOpaqueMemoryBindInfo_pBinds_offsetof)+")",
}, callof(V.VkSparseImageOpaqueMemoryBindInfo_sizeof));


const VkSparseImageMemoryBindInfo = new C.CStruct("VkSparseImageMemoryBindInfo", {
    image: "u64("+callof(V.VkSparseImageMemoryBindInfo_image_offsetof)+")",
    bindCount: "u32("+callof(V.VkSparseImageMemoryBindInfo_bindCount_offsetof)+")",
    pBinds: "u64("+callof(V.VkSparseImageMemoryBindInfo_pBinds_offsetof)+")",
}, callof(V.VkSparseImageMemoryBindInfo_sizeof));


const VkBindSparseInfo = new C.CStruct("VkBindSparseInfo", {
    sType: "u32("+callof(V.VkBindSparseInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBindSparseInfo_pNext_offsetof)+")",
    waitSemaphoreCount: "u32("+callof(V.VkBindSparseInfo_waitSemaphoreCount_offsetof)+")",
    pWaitSemaphores: "u64("+callof(V.VkBindSparseInfo_pWaitSemaphores_offsetof)+")",
    bufferBindCount: "u32("+callof(V.VkBindSparseInfo_bufferBindCount_offsetof)+")",
    pBufferBinds: "u64("+callof(V.VkBindSparseInfo_pBufferBinds_offsetof)+")",
    imageOpaqueBindCount: "u32("+callof(V.VkBindSparseInfo_imageOpaqueBindCount_offsetof)+")",
    pImageOpaqueBinds: "u64("+callof(V.VkBindSparseInfo_pImageOpaqueBinds_offsetof)+")",
    imageBindCount: "u32("+callof(V.VkBindSparseInfo_imageBindCount_offsetof)+")",
    pImageBinds: "u64("+callof(V.VkBindSparseInfo_pImageBinds_offsetof)+")",
    signalSemaphoreCount: "u32("+callof(V.VkBindSparseInfo_signalSemaphoreCount_offsetof)+")",
    pSignalSemaphores: "u64("+callof(V.VkBindSparseInfo_pSignalSemaphores_offsetof)+")",
}, callof(V.VkBindSparseInfo_sizeof));


const VkImageCopy = new C.CStruct("VkImageCopy", {
    srcSubresource: "u32("+callof(V.VkImageCopy_srcSubresource_offsetof)+")",
    srcOffset: "u32("+callof(V.VkImageCopy_srcOffset_offsetof)+")",
    dstSubresource: "u32("+callof(V.VkImageCopy_dstSubresource_offsetof)+")",
    dstOffset: "u32("+callof(V.VkImageCopy_dstOffset_offsetof)+")",
    extent: "u32("+callof(V.VkImageCopy_extent_offsetof)+")",
}, callof(V.VkImageCopy_sizeof));


const VkImageBlit = new C.CStruct("VkImageBlit", {
    srcSubresource: "u32("+callof(V.VkImageBlit_srcSubresource_offsetof)+")",
    srcOffsets: "u32[2]("+callof(V.VkImageBlit_srcOffsets_offsetof)+")",
    dstSubresource: "u32("+callof(V.VkImageBlit_dstSubresource_offsetof)+")",
    dstOffsets: "u32[2]("+callof(V.VkImageBlit_dstOffsets_offsetof)+")",
}, callof(V.VkImageBlit_sizeof));


const VkBufferImageCopy = new C.CStruct("VkBufferImageCopy", {
    bufferOffset: "u64("+callof(V.VkBufferImageCopy_bufferOffset_offsetof)+")",
    bufferRowLength: "u32("+callof(V.VkBufferImageCopy_bufferRowLength_offsetof)+")",
    bufferImageHeight: "u32("+callof(V.VkBufferImageCopy_bufferImageHeight_offsetof)+")",
    imageSubresource: "u32("+callof(V.VkBufferImageCopy_imageSubresource_offsetof)+")",
    imageOffset: "u32("+callof(V.VkBufferImageCopy_imageOffset_offsetof)+")",
    imageExtent: "u32("+callof(V.VkBufferImageCopy_imageExtent_offsetof)+")",
}, callof(V.VkBufferImageCopy_sizeof));


const VkCopyMemoryIndirectCommandNV = new C.CStruct("VkCopyMemoryIndirectCommandNV", {
    srcAddress: "u64("+callof(V.VkCopyMemoryIndirectCommandNV_srcAddress_offsetof)+")",
    dstAddress: "u64("+callof(V.VkCopyMemoryIndirectCommandNV_dstAddress_offsetof)+")",
    size: "u64("+callof(V.VkCopyMemoryIndirectCommandNV_size_offsetof)+")",
}, callof(V.VkCopyMemoryIndirectCommandNV_sizeof));


const VkCopyMemoryToImageIndirectCommandNV = new C.CStruct("VkCopyMemoryToImageIndirectCommandNV", {
    srcAddress: "u64("+callof(V.VkCopyMemoryToImageIndirectCommandNV_srcAddress_offsetof)+")",
    bufferRowLength: "u32("+callof(V.VkCopyMemoryToImageIndirectCommandNV_bufferRowLength_offsetof)+")",
    bufferImageHeight: "u32("+callof(V.VkCopyMemoryToImageIndirectCommandNV_bufferImageHeight_offsetof)+")",
    imageSubresource: "u32("+callof(V.VkCopyMemoryToImageIndirectCommandNV_imageSubresource_offsetof)+")",
    imageOffset: "u32("+callof(V.VkCopyMemoryToImageIndirectCommandNV_imageOffset_offsetof)+")",
    imageExtent: "u32("+callof(V.VkCopyMemoryToImageIndirectCommandNV_imageExtent_offsetof)+")",
}, callof(V.VkCopyMemoryToImageIndirectCommandNV_sizeof));


const VkImageResolve = new C.CStruct("VkImageResolve", {
    srcSubresource: "u32("+callof(V.VkImageResolve_srcSubresource_offsetof)+")",
    srcOffset: "u32("+callof(V.VkImageResolve_srcOffset_offsetof)+")",
    dstSubresource: "u32("+callof(V.VkImageResolve_dstSubresource_offsetof)+")",
    dstOffset: "u32("+callof(V.VkImageResolve_dstOffset_offsetof)+")",
    extent: "u32("+callof(V.VkImageResolve_extent_offsetof)+")",
}, callof(V.VkImageResolve_sizeof));


const VkShaderModuleCreateInfo = new C.CStruct("VkShaderModuleCreateInfo", {
    sType: "u32("+callof(V.VkShaderModuleCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkShaderModuleCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkShaderModuleCreateInfo_flags_offsetof)+")",
    codeSize: "u64("+callof(V.VkShaderModuleCreateInfo_codeSize_offsetof)+")",
    pCode: "u64("+callof(V.VkShaderModuleCreateInfo_pCode_offsetof)+")",
}, callof(V.VkShaderModuleCreateInfo_sizeof));


const VkDescriptorSetLayoutBinding = new C.CStruct("VkDescriptorSetLayoutBinding", {
    binding: "u32("+callof(V.VkDescriptorSetLayoutBinding_binding_offsetof)+")",
    descriptorType: "u32("+callof(V.VkDescriptorSetLayoutBinding_descriptorType_offsetof)+")",
    descriptorCount: "u32("+callof(V.VkDescriptorSetLayoutBinding_descriptorCount_offsetof)+")",
    stageFlags: "u32("+callof(V.VkDescriptorSetLayoutBinding_stageFlags_offsetof)+")",
    pImmutableSamplers: "u64("+callof(V.VkDescriptorSetLayoutBinding_pImmutableSamplers_offsetof)+")",
}, callof(V.VkDescriptorSetLayoutBinding_sizeof));


const VkDescriptorSetLayoutCreateInfo = new C.CStruct("VkDescriptorSetLayoutCreateInfo", {
    sType: "u32("+callof(V.VkDescriptorSetLayoutCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDescriptorSetLayoutCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDescriptorSetLayoutCreateInfo_flags_offsetof)+")",
    bindingCount: "u32("+callof(V.VkDescriptorSetLayoutCreateInfo_bindingCount_offsetof)+")",
    pBindings: "u64("+callof(V.VkDescriptorSetLayoutCreateInfo_pBindings_offsetof)+")",
}, callof(V.VkDescriptorSetLayoutCreateInfo_sizeof));


const VkDescriptorPoolSize = new C.CStruct("VkDescriptorPoolSize", {
    type: "u32("+callof(V.VkDescriptorPoolSize_type_offsetof)+")",
    descriptorCount: "u32("+callof(V.VkDescriptorPoolSize_descriptorCount_offsetof)+")",
}, callof(V.VkDescriptorPoolSize_sizeof));


const VkDescriptorPoolCreateInfo = new C.CStruct("VkDescriptorPoolCreateInfo", {
    sType: "u32("+callof(V.VkDescriptorPoolCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDescriptorPoolCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDescriptorPoolCreateInfo_flags_offsetof)+")",
    maxSets: "u32("+callof(V.VkDescriptorPoolCreateInfo_maxSets_offsetof)+")",
    poolSizeCount: "u32("+callof(V.VkDescriptorPoolCreateInfo_poolSizeCount_offsetof)+")",
    pPoolSizes: "u64("+callof(V.VkDescriptorPoolCreateInfo_pPoolSizes_offsetof)+")",
}, callof(V.VkDescriptorPoolCreateInfo_sizeof));


const VkDescriptorSetAllocateInfo = new C.CStruct("VkDescriptorSetAllocateInfo", {
    sType: "u32("+callof(V.VkDescriptorSetAllocateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDescriptorSetAllocateInfo_pNext_offsetof)+")",
    descriptorPool: "u32("+callof(V.VkDescriptorSetAllocateInfo_descriptorPool_offsetof)+")",
    descriptorSetCount: "u32("+callof(V.VkDescriptorSetAllocateInfo_descriptorSetCount_offsetof)+")",
    pSetLayouts: "u64("+callof(V.VkDescriptorSetAllocateInfo_pSetLayouts_offsetof)+")",
}, callof(V.VkDescriptorSetAllocateInfo_sizeof));


const VkSpecializationMapEntry = new C.CStruct("VkSpecializationMapEntry", {
    constantID: "u32("+callof(V.VkSpecializationMapEntry_constantID_offsetof)+")",
    offset: "u32("+callof(V.VkSpecializationMapEntry_offset_offsetof)+")",
    size: "u64("+callof(V.VkSpecializationMapEntry_size_offsetof)+")",
}, callof(V.VkSpecializationMapEntry_sizeof));


const VkSpecializationInfo = new C.CStruct("VkSpecializationInfo", {
    mapEntryCount: "u32("+callof(V.VkSpecializationInfo_mapEntryCount_offsetof)+")",
    pMapEntries: "u64("+callof(V.VkSpecializationInfo_pMapEntries_offsetof)+")",
    dataSize: "u64("+callof(V.VkSpecializationInfo_dataSize_offsetof)+")",
    pData: "u64("+callof(V.VkSpecializationInfo_pData_offsetof)+")",
}, callof(V.VkSpecializationInfo_sizeof));


const VkPipelineShaderStageCreateInfo = new C.CStruct("VkPipelineShaderStageCreateInfo", {
    sType: "u32("+callof(V.VkPipelineShaderStageCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineShaderStageCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineShaderStageCreateInfo_flags_offsetof)+")",
    stage: "u32("+callof(V.VkPipelineShaderStageCreateInfo_stage_offsetof)+")",
    module: "u32("+callof(V.VkPipelineShaderStageCreateInfo_module_offsetof)+")",
    pName: "u64("+callof(V.VkPipelineShaderStageCreateInfo_pName_offsetof)+")",
    pSpecializationInfo: "u64("+callof(V.VkPipelineShaderStageCreateInfo_pSpecializationInfo_offsetof)+")",
}, callof(V.VkPipelineShaderStageCreateInfo_sizeof));


const VkComputePipelineCreateInfo = new C.CStruct("VkComputePipelineCreateInfo", {
    sType: "u32("+callof(V.VkComputePipelineCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkComputePipelineCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkComputePipelineCreateInfo_flags_offsetof)+")",
    stage: "u32("+callof(V.VkComputePipelineCreateInfo_stage_offsetof)+")",
    layout: "u64("+callof(V.VkComputePipelineCreateInfo_layout_offsetof)+")",
    basePipelineHandle: "u64("+callof(V.VkComputePipelineCreateInfo_basePipelineHandle_offsetof)+")",
    basePipelineIndex: "i32("+callof(V.VkComputePipelineCreateInfo_basePipelineIndex_offsetof)+")",
}, callof(V.VkComputePipelineCreateInfo_sizeof));


const VkVertexInputBindingDescription = new C.CStruct("VkVertexInputBindingDescription", {
    binding: "u32("+callof(V.VkVertexInputBindingDescription_binding_offsetof)+")",
    stride: "u32("+callof(V.VkVertexInputBindingDescription_stride_offsetof)+")",
    inputRate: "u32("+callof(V.VkVertexInputBindingDescription_inputRate_offsetof)+")",
}, callof(V.VkVertexInputBindingDescription_sizeof));


const VkVertexInputAttributeDescription = new C.CStruct("VkVertexInputAttributeDescription", {
    location: "u32("+callof(V.VkVertexInputAttributeDescription_location_offsetof)+")",
    binding: "u32("+callof(V.VkVertexInputAttributeDescription_binding_offsetof)+")",
    format: "u32("+callof(V.VkVertexInputAttributeDescription_format_offsetof)+")",
    offset: "u32("+callof(V.VkVertexInputAttributeDescription_offset_offsetof)+")",
}, callof(V.VkVertexInputAttributeDescription_sizeof));


const VkPipelineVertexInputStateCreateInfo = new C.CStruct("VkPipelineVertexInputStateCreateInfo", {
    sType: "u32("+callof(V.VkPipelineVertexInputStateCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineVertexInputStateCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineVertexInputStateCreateInfo_flags_offsetof)+")",
    vertexBindingDescriptionCount: "u32("+callof(V.VkPipelineVertexInputStateCreateInfo_vertexBindingDescriptionCount_offsetof)+")",
    pVertexBindingDescriptions: "u64("+callof(V.VkPipelineVertexInputStateCreateInfo_pVertexBindingDescriptions_offsetof)+")",
    vertexAttributeDescriptionCount: "u32("+callof(V.VkPipelineVertexInputStateCreateInfo_vertexAttributeDescriptionCount_offsetof)+")",
    pVertexAttributeDescriptions: "u64("+callof(V.VkPipelineVertexInputStateCreateInfo_pVertexAttributeDescriptions_offsetof)+")",
}, callof(V.VkPipelineVertexInputStateCreateInfo_sizeof));


const VkPipelineInputAssemblyStateCreateInfo = new C.CStruct("VkPipelineInputAssemblyStateCreateInfo", {
    sType: "u32("+callof(V.VkPipelineInputAssemblyStateCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineInputAssemblyStateCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineInputAssemblyStateCreateInfo_flags_offsetof)+")",
    topology: "u32("+callof(V.VkPipelineInputAssemblyStateCreateInfo_topology_offsetof)+")",
    primitiveRestartEnable: "u32("+callof(V.VkPipelineInputAssemblyStateCreateInfo_primitiveRestartEnable_offsetof)+")",
}, callof(V.VkPipelineInputAssemblyStateCreateInfo_sizeof));


const VkPipelineTessellationStateCreateInfo = new C.CStruct("VkPipelineTessellationStateCreateInfo", {
    sType: "u32("+callof(V.VkPipelineTessellationStateCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineTessellationStateCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineTessellationStateCreateInfo_flags_offsetof)+")",
    patchControlPoints: "u32("+callof(V.VkPipelineTessellationStateCreateInfo_patchControlPoints_offsetof)+")",
}, callof(V.VkPipelineTessellationStateCreateInfo_sizeof));


const VkPipelineViewportStateCreateInfo = new C.CStruct("VkPipelineViewportStateCreateInfo", {
    sType: "u32("+callof(V.VkPipelineViewportStateCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineViewportStateCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineViewportStateCreateInfo_flags_offsetof)+")",
    viewportCount: "u32("+callof(V.VkPipelineViewportStateCreateInfo_viewportCount_offsetof)+")",
    pViewports: "u64("+callof(V.VkPipelineViewportStateCreateInfo_pViewports_offsetof)+")",
    scissorCount: "u32("+callof(V.VkPipelineViewportStateCreateInfo_scissorCount_offsetof)+")",
    pScissors: "u64("+callof(V.VkPipelineViewportStateCreateInfo_pScissors_offsetof)+")",
}, callof(V.VkPipelineViewportStateCreateInfo_sizeof));


const VkPipelineRasterizationStateCreateInfo = new C.CStruct("VkPipelineRasterizationStateCreateInfo", {
    sType: "u32("+callof(V.VkPipelineRasterizationStateCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineRasterizationStateCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineRasterizationStateCreateInfo_flags_offsetof)+")",
    depthClampEnable: "u32("+callof(V.VkPipelineRasterizationStateCreateInfo_depthClampEnable_offsetof)+")",
    rasterizerDiscardEnable: "u32("+callof(V.VkPipelineRasterizationStateCreateInfo_rasterizerDiscardEnable_offsetof)+")",
    polygonMode: "u32("+callof(V.VkPipelineRasterizationStateCreateInfo_polygonMode_offsetof)+")",
    cullMode: "u32("+callof(V.VkPipelineRasterizationStateCreateInfo_cullMode_offsetof)+")",
    frontFace: "u32("+callof(V.VkPipelineRasterizationStateCreateInfo_frontFace_offsetof)+")",
    depthBiasEnable: "u32("+callof(V.VkPipelineRasterizationStateCreateInfo_depthBiasEnable_offsetof)+")",
    depthBiasConstantFactor: "f32("+callof(V.VkPipelineRasterizationStateCreateInfo_depthBiasConstantFactor_offsetof)+")",
    depthBiasClamp: "f32("+callof(V.VkPipelineRasterizationStateCreateInfo_depthBiasClamp_offsetof)+")",
    depthBiasSlopeFactor: "f32("+callof(V.VkPipelineRasterizationStateCreateInfo_depthBiasSlopeFactor_offsetof)+")",
    lineWidth: "f32("+callof(V.VkPipelineRasterizationStateCreateInfo_lineWidth_offsetof)+")",
}, callof(V.VkPipelineRasterizationStateCreateInfo_sizeof));


const VkPipelineMultisampleStateCreateInfo = new C.CStruct("VkPipelineMultisampleStateCreateInfo", {
    sType: "u32("+callof(V.VkPipelineMultisampleStateCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineMultisampleStateCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineMultisampleStateCreateInfo_flags_offsetof)+")",
    rasterizationSamples: "u32("+callof(V.VkPipelineMultisampleStateCreateInfo_rasterizationSamples_offsetof)+")",
    sampleShadingEnable: "u32("+callof(V.VkPipelineMultisampleStateCreateInfo_sampleShadingEnable_offsetof)+")",
    minSampleShading: "f32("+callof(V.VkPipelineMultisampleStateCreateInfo_minSampleShading_offsetof)+")",
    pSampleMask: "u64("+callof(V.VkPipelineMultisampleStateCreateInfo_pSampleMask_offsetof)+")",
    alphaToCoverageEnable: "u32("+callof(V.VkPipelineMultisampleStateCreateInfo_alphaToCoverageEnable_offsetof)+")",
    alphaToOneEnable: "u32("+callof(V.VkPipelineMultisampleStateCreateInfo_alphaToOneEnable_offsetof)+")",
}, callof(V.VkPipelineMultisampleStateCreateInfo_sizeof));


const VkPipelineColorBlendAttachmentState = new C.CStruct("VkPipelineColorBlendAttachmentState", {
    blendEnable: "u32("+callof(V.VkPipelineColorBlendAttachmentState_blendEnable_offsetof)+")",
    srcColorBlendFactor: "u32("+callof(V.VkPipelineColorBlendAttachmentState_srcColorBlendFactor_offsetof)+")",
    dstColorBlendFactor: "u32("+callof(V.VkPipelineColorBlendAttachmentState_dstColorBlendFactor_offsetof)+")",
    colorBlendOp: "u32("+callof(V.VkPipelineColorBlendAttachmentState_colorBlendOp_offsetof)+")",
    srcAlphaBlendFactor: "u32("+callof(V.VkPipelineColorBlendAttachmentState_srcAlphaBlendFactor_offsetof)+")",
    dstAlphaBlendFactor: "u32("+callof(V.VkPipelineColorBlendAttachmentState_dstAlphaBlendFactor_offsetof)+")",
    alphaBlendOp: "u32("+callof(V.VkPipelineColorBlendAttachmentState_alphaBlendOp_offsetof)+")",
    colorWriteMask: "u32("+callof(V.VkPipelineColorBlendAttachmentState_colorWriteMask_offsetof)+")",
}, callof(V.VkPipelineColorBlendAttachmentState_sizeof));


const VkPipelineColorBlendStateCreateInfo = new C.CStruct("VkPipelineColorBlendStateCreateInfo", {
    sType: "u32("+callof(V.VkPipelineColorBlendStateCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineColorBlendStateCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineColorBlendStateCreateInfo_flags_offsetof)+")",
    logicOpEnable: "u32("+callof(V.VkPipelineColorBlendStateCreateInfo_logicOpEnable_offsetof)+")",
    logicOp: "u32("+callof(V.VkPipelineColorBlendStateCreateInfo_logicOp_offsetof)+")",
    attachmentCount: "u32("+callof(V.VkPipelineColorBlendStateCreateInfo_attachmentCount_offsetof)+")",
    pAttachments: "u64("+callof(V.VkPipelineColorBlendStateCreateInfo_pAttachments_offsetof)+")",
    blendConstants: "f32[4]("+callof(V.VkPipelineColorBlendStateCreateInfo_blendConstants_offsetof)+")",
}, callof(V.VkPipelineColorBlendStateCreateInfo_sizeof));


const VkPipelineDynamicStateCreateInfo = new C.CStruct("VkPipelineDynamicStateCreateInfo", {
    sType: "u32("+callof(V.VkPipelineDynamicStateCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineDynamicStateCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineDynamicStateCreateInfo_flags_offsetof)+")",
    dynamicStateCount: "u32("+callof(V.VkPipelineDynamicStateCreateInfo_dynamicStateCount_offsetof)+")",
    pDynamicStates: "u64("+callof(V.VkPipelineDynamicStateCreateInfo_pDynamicStates_offsetof)+")",
}, callof(V.VkPipelineDynamicStateCreateInfo_sizeof));


const VkStencilOpState = new C.CStruct("VkStencilOpState", {
    failOp: "u32("+callof(V.VkStencilOpState_failOp_offsetof)+")",
    passOp: "u32("+callof(V.VkStencilOpState_passOp_offsetof)+")",
    depthFailOp: "u32("+callof(V.VkStencilOpState_depthFailOp_offsetof)+")",
    compareOp: "u32("+callof(V.VkStencilOpState_compareOp_offsetof)+")",
    compareMask: "u32("+callof(V.VkStencilOpState_compareMask_offsetof)+")",
    writeMask: "u32("+callof(V.VkStencilOpState_writeMask_offsetof)+")",
    reference: "u32("+callof(V.VkStencilOpState_reference_offsetof)+")",
}, callof(V.VkStencilOpState_sizeof));


const VkPipelineDepthStencilStateCreateInfo = new C.CStruct("VkPipelineDepthStencilStateCreateInfo", {
    sType: "u32("+callof(V.VkPipelineDepthStencilStateCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineDepthStencilStateCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineDepthStencilStateCreateInfo_flags_offsetof)+")",
    depthTestEnable: "u32("+callof(V.VkPipelineDepthStencilStateCreateInfo_depthTestEnable_offsetof)+")",
    depthWriteEnable: "u32("+callof(V.VkPipelineDepthStencilStateCreateInfo_depthWriteEnable_offsetof)+")",
    depthCompareOp: "u32("+callof(V.VkPipelineDepthStencilStateCreateInfo_depthCompareOp_offsetof)+")",
    depthBoundsTestEnable: "u32("+callof(V.VkPipelineDepthStencilStateCreateInfo_depthBoundsTestEnable_offsetof)+")",
    stencilTestEnable: "u32("+callof(V.VkPipelineDepthStencilStateCreateInfo_stencilTestEnable_offsetof)+")",
    front: "u32("+callof(V.VkPipelineDepthStencilStateCreateInfo_front_offsetof)+")",
    back: "u32("+callof(V.VkPipelineDepthStencilStateCreateInfo_back_offsetof)+")",
    minDepthBounds: "f32("+callof(V.VkPipelineDepthStencilStateCreateInfo_minDepthBounds_offsetof)+")",
    maxDepthBounds: "f32("+callof(V.VkPipelineDepthStencilStateCreateInfo_maxDepthBounds_offsetof)+")",
}, callof(V.VkPipelineDepthStencilStateCreateInfo_sizeof));


const VkGraphicsPipelineCreateInfo = new C.CStruct("VkGraphicsPipelineCreateInfo", {
    sType: "u32("+callof(V.VkGraphicsPipelineCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkGraphicsPipelineCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkGraphicsPipelineCreateInfo_flags_offsetof)+")",
    stageCount: "u32("+callof(V.VkGraphicsPipelineCreateInfo_stageCount_offsetof)+")",
    pStages: "u64("+callof(V.VkGraphicsPipelineCreateInfo_pStages_offsetof)+")",
    pVertexInputState: "u64("+callof(V.VkGraphicsPipelineCreateInfo_pVertexInputState_offsetof)+")",
    pInputAssemblyState: "u64("+callof(V.VkGraphicsPipelineCreateInfo_pInputAssemblyState_offsetof)+")",
    pTessellationState: "u64("+callof(V.VkGraphicsPipelineCreateInfo_pTessellationState_offsetof)+")",
    pViewportState: "u64("+callof(V.VkGraphicsPipelineCreateInfo_pViewportState_offsetof)+")",
    pRasterizationState: "u64("+callof(V.VkGraphicsPipelineCreateInfo_pRasterizationState_offsetof)+")",
    pMultisampleState: "u64("+callof(V.VkGraphicsPipelineCreateInfo_pMultisampleState_offsetof)+")",
    pDepthStencilState: "u64("+callof(V.VkGraphicsPipelineCreateInfo_pDepthStencilState_offsetof)+")",
    pColorBlendState: "u64("+callof(V.VkGraphicsPipelineCreateInfo_pColorBlendState_offsetof)+")",
    pDynamicState: "u64("+callof(V.VkGraphicsPipelineCreateInfo_pDynamicState_offsetof)+")",
    layout: "u64("+callof(V.VkGraphicsPipelineCreateInfo_layout_offsetof)+")",
    renderPass: "u32("+callof(V.VkGraphicsPipelineCreateInfo_renderPass_offsetof)+")",
    subpass: "u32("+callof(V.VkGraphicsPipelineCreateInfo_subpass_offsetof)+")",
    basePipelineHandle: "u64("+callof(V.VkGraphicsPipelineCreateInfo_basePipelineHandle_offsetof)+")",
    basePipelineIndex: "i32("+callof(V.VkGraphicsPipelineCreateInfo_basePipelineIndex_offsetof)+")",
}, callof(V.VkGraphicsPipelineCreateInfo_sizeof));


const VkPipelineCacheCreateInfo = new C.CStruct("VkPipelineCacheCreateInfo", {
    sType: "u32("+callof(V.VkPipelineCacheCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineCacheCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineCacheCreateInfo_flags_offsetof)+")",
    initialDataSize: "u64("+callof(V.VkPipelineCacheCreateInfo_initialDataSize_offsetof)+")",
    pInitialData: "u64("+callof(V.VkPipelineCacheCreateInfo_pInitialData_offsetof)+")",
}, callof(V.VkPipelineCacheCreateInfo_sizeof));


const VkPipelineCacheHeaderVersionOne = new C.CStruct("VkPipelineCacheHeaderVersionOne", {
    headerSize: "u32("+callof(V.VkPipelineCacheHeaderVersionOne_headerSize_offsetof)+")",
    headerVersion: "u32("+callof(V.VkPipelineCacheHeaderVersionOne_headerVersion_offsetof)+")",
    vendorID: "u32("+callof(V.VkPipelineCacheHeaderVersionOne_vendorID_offsetof)+")",
    deviceID: "u32("+callof(V.VkPipelineCacheHeaderVersionOne_deviceID_offsetof)+")",
    pipelineCacheUUID: "u8["+(enums.NaN||1)+"]("+callof(V.VkPipelineCacheHeaderVersionOne_pipelineCacheUUID_offsetof)+")",
}, callof(V.VkPipelineCacheHeaderVersionOne_sizeof));


const VkPushConstantRange = new C.CStruct("VkPushConstantRange", {
    stageFlags: "u32("+callof(V.VkPushConstantRange_stageFlags_offsetof)+")",
    offset: "u32("+callof(V.VkPushConstantRange_offset_offsetof)+")",
    size: "u32("+callof(V.VkPushConstantRange_size_offsetof)+")",
}, callof(V.VkPushConstantRange_sizeof));


const VkPipelineLayoutCreateInfo = new C.CStruct("VkPipelineLayoutCreateInfo", {
    sType: "u32("+callof(V.VkPipelineLayoutCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineLayoutCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineLayoutCreateInfo_flags_offsetof)+")",
    setLayoutCount: "u32("+callof(V.VkPipelineLayoutCreateInfo_setLayoutCount_offsetof)+")",
    pSetLayouts: "u64("+callof(V.VkPipelineLayoutCreateInfo_pSetLayouts_offsetof)+")",
    pushConstantRangeCount: "u32("+callof(V.VkPipelineLayoutCreateInfo_pushConstantRangeCount_offsetof)+")",
    pPushConstantRanges: "u64("+callof(V.VkPipelineLayoutCreateInfo_pPushConstantRanges_offsetof)+")",
}, callof(V.VkPipelineLayoutCreateInfo_sizeof));


const VkSamplerCreateInfo = new C.CStruct("VkSamplerCreateInfo", {
    sType: "u32("+callof(V.VkSamplerCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSamplerCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkSamplerCreateInfo_flags_offsetof)+")",
    magFilter: "u32("+callof(V.VkSamplerCreateInfo_magFilter_offsetof)+")",
    minFilter: "u32("+callof(V.VkSamplerCreateInfo_minFilter_offsetof)+")",
    mipmapMode: "u32("+callof(V.VkSamplerCreateInfo_mipmapMode_offsetof)+")",
    addressModeU: "u32("+callof(V.VkSamplerCreateInfo_addressModeU_offsetof)+")",
    addressModeV: "u32("+callof(V.VkSamplerCreateInfo_addressModeV_offsetof)+")",
    addressModeW: "u32("+callof(V.VkSamplerCreateInfo_addressModeW_offsetof)+")",
    mipLodBias: "f32("+callof(V.VkSamplerCreateInfo_mipLodBias_offsetof)+")",
    anisotropyEnable: "u32("+callof(V.VkSamplerCreateInfo_anisotropyEnable_offsetof)+")",
    maxAnisotropy: "f32("+callof(V.VkSamplerCreateInfo_maxAnisotropy_offsetof)+")",
    compareEnable: "u32("+callof(V.VkSamplerCreateInfo_compareEnable_offsetof)+")",
    compareOp: "u32("+callof(V.VkSamplerCreateInfo_compareOp_offsetof)+")",
    minLod: "f32("+callof(V.VkSamplerCreateInfo_minLod_offsetof)+")",
    maxLod: "f32("+callof(V.VkSamplerCreateInfo_maxLod_offsetof)+")",
    borderColor: "u32("+callof(V.VkSamplerCreateInfo_borderColor_offsetof)+")",
    unnormalizedCoordinates: "u32("+callof(V.VkSamplerCreateInfo_unnormalizedCoordinates_offsetof)+")",
}, callof(V.VkSamplerCreateInfo_sizeof));


const VkCommandPoolCreateInfo = new C.CStruct("VkCommandPoolCreateInfo", {
    sType: "u32("+callof(V.VkCommandPoolCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCommandPoolCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkCommandPoolCreateInfo_flags_offsetof)+")",
    queueFamilyIndex: "u32("+callof(V.VkCommandPoolCreateInfo_queueFamilyIndex_offsetof)+")",
}, callof(V.VkCommandPoolCreateInfo_sizeof));


const VkCommandBufferAllocateInfo = new C.CStruct("VkCommandBufferAllocateInfo", {
    sType: "u32("+callof(V.VkCommandBufferAllocateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCommandBufferAllocateInfo_pNext_offsetof)+")",
    commandPool: "u32("+callof(V.VkCommandBufferAllocateInfo_commandPool_offsetof)+")",
    level: "u32("+callof(V.VkCommandBufferAllocateInfo_level_offsetof)+")",
    commandBufferCount: "u32("+callof(V.VkCommandBufferAllocateInfo_commandBufferCount_offsetof)+")",
}, callof(V.VkCommandBufferAllocateInfo_sizeof));


const VkCommandBufferInheritanceInfo = new C.CStruct("VkCommandBufferInheritanceInfo", {
    sType: "u32("+callof(V.VkCommandBufferInheritanceInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCommandBufferInheritanceInfo_pNext_offsetof)+")",
    renderPass: "u32("+callof(V.VkCommandBufferInheritanceInfo_renderPass_offsetof)+")",
    subpass: "u32("+callof(V.VkCommandBufferInheritanceInfo_subpass_offsetof)+")",
    framebuffer: "u64("+callof(V.VkCommandBufferInheritanceInfo_framebuffer_offsetof)+")",
    occlusionQueryEnable: "u32("+callof(V.VkCommandBufferInheritanceInfo_occlusionQueryEnable_offsetof)+")",
    queryFlags: "u32("+callof(V.VkCommandBufferInheritanceInfo_queryFlags_offsetof)+")",
    pipelineStatistics: "u32("+callof(V.VkCommandBufferInheritanceInfo_pipelineStatistics_offsetof)+")",
}, callof(V.VkCommandBufferInheritanceInfo_sizeof));


const VkCommandBufferBeginInfo = new C.CStruct("VkCommandBufferBeginInfo", {
    sType: "u32("+callof(V.VkCommandBufferBeginInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCommandBufferBeginInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkCommandBufferBeginInfo_flags_offsetof)+")",
    pInheritanceInfo: "u64("+callof(V.VkCommandBufferBeginInfo_pInheritanceInfo_offsetof)+")",
}, callof(V.VkCommandBufferBeginInfo_sizeof));


const VkRenderPassBeginInfo = new C.CStruct("VkRenderPassBeginInfo", {
    sType: "u32("+callof(V.VkRenderPassBeginInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderPassBeginInfo_pNext_offsetof)+")",
    renderPass: "u32("+callof(V.VkRenderPassBeginInfo_renderPass_offsetof)+")",
    framebuffer: "u64("+callof(V.VkRenderPassBeginInfo_framebuffer_offsetof)+")",
    renderArea: "VkRect2D("+callof(V.VkRenderPassBeginInfo_renderArea_offsetof)+")",
    clearValueCount: "u32("+callof(V.VkRenderPassBeginInfo_clearValueCount_offsetof)+")",
    pClearValues: "u64("+callof(V.VkRenderPassBeginInfo_pClearValues_offsetof)+")",
}, callof(V.VkRenderPassBeginInfo_sizeof));


const VkClearDepthStencilValue = new C.CStruct("VkClearDepthStencilValue", {
    depth: "f32("+callof(V.VkClearDepthStencilValue_depth_offsetof)+")",
    stencil: "u32("+callof(V.VkClearDepthStencilValue_stencil_offsetof)+")",
}, callof(V.VkClearDepthStencilValue_sizeof));


const VkClearAttachment = new C.CStruct("VkClearAttachment", {
    aspectMask: "u32("+callof(V.VkClearAttachment_aspectMask_offsetof)+")",
    colorAttachment: "u32("+callof(V.VkClearAttachment_colorAttachment_offsetof)+")",
    clearValue: "u32("+callof(V.VkClearAttachment_clearValue_offsetof)+")",
}, callof(V.VkClearAttachment_sizeof));


const VkAttachmentDescription = new C.CStruct("VkAttachmentDescription", {
    flags: "u32("+callof(V.VkAttachmentDescription_flags_offsetof)+")",
    format: "u32("+callof(V.VkAttachmentDescription_format_offsetof)+")",
    samples: "u32("+callof(V.VkAttachmentDescription_samples_offsetof)+")",
    loadOp: "u32("+callof(V.VkAttachmentDescription_loadOp_offsetof)+")",
    storeOp: "u32("+callof(V.VkAttachmentDescription_storeOp_offsetof)+")",
    stencilLoadOp: "u32("+callof(V.VkAttachmentDescription_stencilLoadOp_offsetof)+")",
    stencilStoreOp: "u32("+callof(V.VkAttachmentDescription_stencilStoreOp_offsetof)+")",
    initialLayout: "u32("+callof(V.VkAttachmentDescription_initialLayout_offsetof)+")",
    finalLayout: "u32("+callof(V.VkAttachmentDescription_finalLayout_offsetof)+")",
}, callof(V.VkAttachmentDescription_sizeof));


const VkAttachmentReference = new C.CStruct("VkAttachmentReference", {
    attachment: "u32("+callof(V.VkAttachmentReference_attachment_offsetof)+")",
    layout: "u32("+callof(V.VkAttachmentReference_layout_offsetof)+")",
}, callof(V.VkAttachmentReference_sizeof));


const VkSubpassDescription = new C.CStruct("VkSubpassDescription", {
    flags: "u32("+callof(V.VkSubpassDescription_flags_offsetof)+")",
    pipelineBindPoint: "u32("+callof(V.VkSubpassDescription_pipelineBindPoint_offsetof)+")",
    inputAttachmentCount: "u32("+callof(V.VkSubpassDescription_inputAttachmentCount_offsetof)+")",
    pInputAttachments: "u64("+callof(V.VkSubpassDescription_pInputAttachments_offsetof)+")",
    colorAttachmentCount: "u32("+callof(V.VkSubpassDescription_colorAttachmentCount_offsetof)+")",
    pColorAttachments: "u64("+callof(V.VkSubpassDescription_pColorAttachments_offsetof)+")",
    pResolveAttachments: "u64("+callof(V.VkSubpassDescription_pResolveAttachments_offsetof)+")",
    pDepthStencilAttachment: "u64("+callof(V.VkSubpassDescription_pDepthStencilAttachment_offsetof)+")",
    preserveAttachmentCount: "u32("+callof(V.VkSubpassDescription_preserveAttachmentCount_offsetof)+")",
    pPreserveAttachments: "u64("+callof(V.VkSubpassDescription_pPreserveAttachments_offsetof)+")",
}, callof(V.VkSubpassDescription_sizeof));


const VkSubpassDependency = new C.CStruct("VkSubpassDependency", {
    srcSubpass: "u32("+callof(V.VkSubpassDependency_srcSubpass_offsetof)+")",
    dstSubpass: "u32("+callof(V.VkSubpassDependency_dstSubpass_offsetof)+")",
    srcStageMask: "u32("+callof(V.VkSubpassDependency_srcStageMask_offsetof)+")",
    dstStageMask: "u32("+callof(V.VkSubpassDependency_dstStageMask_offsetof)+")",
    srcAccessMask: "u32("+callof(V.VkSubpassDependency_srcAccessMask_offsetof)+")",
    dstAccessMask: "u32("+callof(V.VkSubpassDependency_dstAccessMask_offsetof)+")",
    dependencyFlags: "u32("+callof(V.VkSubpassDependency_dependencyFlags_offsetof)+")",
}, callof(V.VkSubpassDependency_sizeof));


const VkRenderPassCreateInfo = new C.CStruct("VkRenderPassCreateInfo", {
    sType: "u32("+callof(V.VkRenderPassCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderPassCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkRenderPassCreateInfo_flags_offsetof)+")",
    attachmentCount: "u32("+callof(V.VkRenderPassCreateInfo_attachmentCount_offsetof)+")",
    pAttachments: "u64("+callof(V.VkRenderPassCreateInfo_pAttachments_offsetof)+")",
    subpassCount: "u32("+callof(V.VkRenderPassCreateInfo_subpassCount_offsetof)+")",
    pSubpasses: "u64("+callof(V.VkRenderPassCreateInfo_pSubpasses_offsetof)+")",
    dependencyCount: "u32("+callof(V.VkRenderPassCreateInfo_dependencyCount_offsetof)+")",
    pDependencies: "u64("+callof(V.VkRenderPassCreateInfo_pDependencies_offsetof)+")",
}, callof(V.VkRenderPassCreateInfo_sizeof));


const VkEventCreateInfo = new C.CStruct("VkEventCreateInfo", {
    sType: "u32("+callof(V.VkEventCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkEventCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkEventCreateInfo_flags_offsetof)+")",
}, callof(V.VkEventCreateInfo_sizeof));


const VkFenceCreateInfo = new C.CStruct("VkFenceCreateInfo", {
    sType: "u32("+callof(V.VkFenceCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkFenceCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkFenceCreateInfo_flags_offsetof)+")",
}, callof(V.VkFenceCreateInfo_sizeof));


const VkPhysicalDeviceFeatures = new C.CStruct("VkPhysicalDeviceFeatures", {
    robustBufferAccess: "u32("+callof(V.VkPhysicalDeviceFeatures_robustBufferAccess_offsetof)+")",
    fullDrawIndexUint32: "u32("+callof(V.VkPhysicalDeviceFeatures_fullDrawIndexUint32_offsetof)+")",
    imageCubeArray: "u32("+callof(V.VkPhysicalDeviceFeatures_imageCubeArray_offsetof)+")",
    independentBlend: "u32("+callof(V.VkPhysicalDeviceFeatures_independentBlend_offsetof)+")",
    geometryShader: "u32("+callof(V.VkPhysicalDeviceFeatures_geometryShader_offsetof)+")",
    tessellationShader: "u32("+callof(V.VkPhysicalDeviceFeatures_tessellationShader_offsetof)+")",
    sampleRateShading: "u32("+callof(V.VkPhysicalDeviceFeatures_sampleRateShading_offsetof)+")",
    dualSrcBlend: "u32("+callof(V.VkPhysicalDeviceFeatures_dualSrcBlend_offsetof)+")",
    logicOp: "u32("+callof(V.VkPhysicalDeviceFeatures_logicOp_offsetof)+")",
    multiDrawIndirect: "u32("+callof(V.VkPhysicalDeviceFeatures_multiDrawIndirect_offsetof)+")",
    drawIndirectFirstInstance: "u32("+callof(V.VkPhysicalDeviceFeatures_drawIndirectFirstInstance_offsetof)+")",
    depthClamp: "u32("+callof(V.VkPhysicalDeviceFeatures_depthClamp_offsetof)+")",
    depthBiasClamp: "u32("+callof(V.VkPhysicalDeviceFeatures_depthBiasClamp_offsetof)+")",
    fillModeNonSolid: "u32("+callof(V.VkPhysicalDeviceFeatures_fillModeNonSolid_offsetof)+")",
    depthBounds: "u32("+callof(V.VkPhysicalDeviceFeatures_depthBounds_offsetof)+")",
    wideLines: "u32("+callof(V.VkPhysicalDeviceFeatures_wideLines_offsetof)+")",
    largePoints: "u32("+callof(V.VkPhysicalDeviceFeatures_largePoints_offsetof)+")",
    alphaToOne: "u32("+callof(V.VkPhysicalDeviceFeatures_alphaToOne_offsetof)+")",
    multiViewport: "u32("+callof(V.VkPhysicalDeviceFeatures_multiViewport_offsetof)+")",
    samplerAnisotropy: "u32("+callof(V.VkPhysicalDeviceFeatures_samplerAnisotropy_offsetof)+")",
    textureCompressionETC2: "u32("+callof(V.VkPhysicalDeviceFeatures_textureCompressionETC2_offsetof)+")",
    textureCompressionASTC_LDR: "u32("+callof(V.VkPhysicalDeviceFeatures_textureCompressionASTC_LDR_offsetof)+")",
    textureCompressionBC: "u32("+callof(V.VkPhysicalDeviceFeatures_textureCompressionBC_offsetof)+")",
    occlusionQueryPrecise: "u32("+callof(V.VkPhysicalDeviceFeatures_occlusionQueryPrecise_offsetof)+")",
    pipelineStatisticsQuery: "u32("+callof(V.VkPhysicalDeviceFeatures_pipelineStatisticsQuery_offsetof)+")",
    vertexPipelineStoresAndAtomics: "u32("+callof(V.VkPhysicalDeviceFeatures_vertexPipelineStoresAndAtomics_offsetof)+")",
    fragmentStoresAndAtomics: "u32("+callof(V.VkPhysicalDeviceFeatures_fragmentStoresAndAtomics_offsetof)+")",
    shaderTessellationAndGeometryPointSize: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderTessellationAndGeometryPointSize_offsetof)+")",
    shaderImageGatherExtended: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderImageGatherExtended_offsetof)+")",
    shaderStorageImageExtendedFormats: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderStorageImageExtendedFormats_offsetof)+")",
    shaderStorageImageMultisample: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderStorageImageMultisample_offsetof)+")",
    shaderStorageImageReadWithoutFormat: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderStorageImageReadWithoutFormat_offsetof)+")",
    shaderStorageImageWriteWithoutFormat: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderStorageImageWriteWithoutFormat_offsetof)+")",
    shaderUniformBufferArrayDynamicIndexing: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderUniformBufferArrayDynamicIndexing_offsetof)+")",
    shaderSampledImageArrayDynamicIndexing: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderSampledImageArrayDynamicIndexing_offsetof)+")",
    shaderStorageBufferArrayDynamicIndexing: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderStorageBufferArrayDynamicIndexing_offsetof)+")",
    shaderStorageImageArrayDynamicIndexing: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderStorageImageArrayDynamicIndexing_offsetof)+")",
    shaderClipDistance: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderClipDistance_offsetof)+")",
    shaderCullDistance: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderCullDistance_offsetof)+")",
    shaderFloat64: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderFloat64_offsetof)+")",
    shaderInt64: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderInt64_offsetof)+")",
    shaderInt16: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderInt16_offsetof)+")",
    shaderResourceResidency: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderResourceResidency_offsetof)+")",
    shaderResourceMinLod: "u32("+callof(V.VkPhysicalDeviceFeatures_shaderResourceMinLod_offsetof)+")",
    sparseBinding: "u32("+callof(V.VkPhysicalDeviceFeatures_sparseBinding_offsetof)+")",
    sparseResidencyBuffer: "u32("+callof(V.VkPhysicalDeviceFeatures_sparseResidencyBuffer_offsetof)+")",
    sparseResidencyImage2D: "u32("+callof(V.VkPhysicalDeviceFeatures_sparseResidencyImage2D_offsetof)+")",
    sparseResidencyImage3D: "u32("+callof(V.VkPhysicalDeviceFeatures_sparseResidencyImage3D_offsetof)+")",
    sparseResidency2Samples: "u32("+callof(V.VkPhysicalDeviceFeatures_sparseResidency2Samples_offsetof)+")",
    sparseResidency4Samples: "u32("+callof(V.VkPhysicalDeviceFeatures_sparseResidency4Samples_offsetof)+")",
    sparseResidency8Samples: "u32("+callof(V.VkPhysicalDeviceFeatures_sparseResidency8Samples_offsetof)+")",
    sparseResidency16Samples: "u32("+callof(V.VkPhysicalDeviceFeatures_sparseResidency16Samples_offsetof)+")",
    sparseResidencyAliased: "u32("+callof(V.VkPhysicalDeviceFeatures_sparseResidencyAliased_offsetof)+")",
    variableMultisampleRate: "u32("+callof(V.VkPhysicalDeviceFeatures_variableMultisampleRate_offsetof)+")",
    inheritedQueries: "u32("+callof(V.VkPhysicalDeviceFeatures_inheritedQueries_offsetof)+")",
}, callof(V.VkPhysicalDeviceFeatures_sizeof));


const VkPhysicalDeviceSparseProperties = new C.CStruct("VkPhysicalDeviceSparseProperties", {
    residencyStandard2DBlockShape: "u32("+callof(V.VkPhysicalDeviceSparseProperties_residencyStandard2DBlockShape_offsetof)+")",
    residencyStandard2DMultisampleBlockShape: "u32("+callof(V.VkPhysicalDeviceSparseProperties_residencyStandard2DMultisampleBlockShape_offsetof)+")",
    residencyStandard3DBlockShape: "u32("+callof(V.VkPhysicalDeviceSparseProperties_residencyStandard3DBlockShape_offsetof)+")",
    residencyAlignedMipSize: "u32("+callof(V.VkPhysicalDeviceSparseProperties_residencyAlignedMipSize_offsetof)+")",
    residencyNonResidentStrict: "u32("+callof(V.VkPhysicalDeviceSparseProperties_residencyNonResidentStrict_offsetof)+")",
}, callof(V.VkPhysicalDeviceSparseProperties_sizeof));


const VkPhysicalDeviceLimits = new C.CStruct("VkPhysicalDeviceLimits", {
    maxImageDimension1D: "u32("+callof(V.VkPhysicalDeviceLimits_maxImageDimension1D_offsetof)+")",
    maxImageDimension2D: "u32("+callof(V.VkPhysicalDeviceLimits_maxImageDimension2D_offsetof)+")",
    maxImageDimension3D: "u32("+callof(V.VkPhysicalDeviceLimits_maxImageDimension3D_offsetof)+")",
    maxImageDimensionCube: "u32("+callof(V.VkPhysicalDeviceLimits_maxImageDimensionCube_offsetof)+")",
    maxImageArrayLayers: "u32("+callof(V.VkPhysicalDeviceLimits_maxImageArrayLayers_offsetof)+")",
    maxTexelBufferElements: "u32("+callof(V.VkPhysicalDeviceLimits_maxTexelBufferElements_offsetof)+")",
    maxUniformBufferRange: "u32("+callof(V.VkPhysicalDeviceLimits_maxUniformBufferRange_offsetof)+")",
    maxStorageBufferRange: "u32("+callof(V.VkPhysicalDeviceLimits_maxStorageBufferRange_offsetof)+")",
    maxPushConstantsSize: "u32("+callof(V.VkPhysicalDeviceLimits_maxPushConstantsSize_offsetof)+")",
    maxMemoryAllocationCount: "u32("+callof(V.VkPhysicalDeviceLimits_maxMemoryAllocationCount_offsetof)+")",
    maxSamplerAllocationCount: "u32("+callof(V.VkPhysicalDeviceLimits_maxSamplerAllocationCount_offsetof)+")",
    bufferImageGranularity: "u64("+callof(V.VkPhysicalDeviceLimits_bufferImageGranularity_offsetof)+")",
    sparseAddressSpaceSize: "u64("+callof(V.VkPhysicalDeviceLimits_sparseAddressSpaceSize_offsetof)+")",
    maxBoundDescriptorSets: "u32("+callof(V.VkPhysicalDeviceLimits_maxBoundDescriptorSets_offsetof)+")",
    maxPerStageDescriptorSamplers: "u32("+callof(V.VkPhysicalDeviceLimits_maxPerStageDescriptorSamplers_offsetof)+")",
    maxPerStageDescriptorUniformBuffers: "u32("+callof(V.VkPhysicalDeviceLimits_maxPerStageDescriptorUniformBuffers_offsetof)+")",
    maxPerStageDescriptorStorageBuffers: "u32("+callof(V.VkPhysicalDeviceLimits_maxPerStageDescriptorStorageBuffers_offsetof)+")",
    maxPerStageDescriptorSampledImages: "u32("+callof(V.VkPhysicalDeviceLimits_maxPerStageDescriptorSampledImages_offsetof)+")",
    maxPerStageDescriptorStorageImages: "u32("+callof(V.VkPhysicalDeviceLimits_maxPerStageDescriptorStorageImages_offsetof)+")",
    maxPerStageDescriptorInputAttachments: "u32("+callof(V.VkPhysicalDeviceLimits_maxPerStageDescriptorInputAttachments_offsetof)+")",
    maxPerStageResources: "u32("+callof(V.VkPhysicalDeviceLimits_maxPerStageResources_offsetof)+")",
    maxDescriptorSetSamplers: "u32("+callof(V.VkPhysicalDeviceLimits_maxDescriptorSetSamplers_offsetof)+")",
    maxDescriptorSetUniformBuffers: "u32("+callof(V.VkPhysicalDeviceLimits_maxDescriptorSetUniformBuffers_offsetof)+")",
    maxDescriptorSetUniformBuffersDynamic: "u32("+callof(V.VkPhysicalDeviceLimits_maxDescriptorSetUniformBuffersDynamic_offsetof)+")",
    maxDescriptorSetStorageBuffers: "u32("+callof(V.VkPhysicalDeviceLimits_maxDescriptorSetStorageBuffers_offsetof)+")",
    maxDescriptorSetStorageBuffersDynamic: "u32("+callof(V.VkPhysicalDeviceLimits_maxDescriptorSetStorageBuffersDynamic_offsetof)+")",
    maxDescriptorSetSampledImages: "u32("+callof(V.VkPhysicalDeviceLimits_maxDescriptorSetSampledImages_offsetof)+")",
    maxDescriptorSetStorageImages: "u32("+callof(V.VkPhysicalDeviceLimits_maxDescriptorSetStorageImages_offsetof)+")",
    maxDescriptorSetInputAttachments: "u32("+callof(V.VkPhysicalDeviceLimits_maxDescriptorSetInputAttachments_offsetof)+")",
    maxVertexInputAttributes: "u32("+callof(V.VkPhysicalDeviceLimits_maxVertexInputAttributes_offsetof)+")",
    maxVertexInputBindings: "u32("+callof(V.VkPhysicalDeviceLimits_maxVertexInputBindings_offsetof)+")",
    maxVertexInputAttributeOffset: "u32("+callof(V.VkPhysicalDeviceLimits_maxVertexInputAttributeOffset_offsetof)+")",
    maxVertexInputBindingStride: "u32("+callof(V.VkPhysicalDeviceLimits_maxVertexInputBindingStride_offsetof)+")",
    maxVertexOutputComponents: "u32("+callof(V.VkPhysicalDeviceLimits_maxVertexOutputComponents_offsetof)+")",
    maxTessellationGenerationLevel: "u32("+callof(V.VkPhysicalDeviceLimits_maxTessellationGenerationLevel_offsetof)+")",
    maxTessellationPatchSize: "u32("+callof(V.VkPhysicalDeviceLimits_maxTessellationPatchSize_offsetof)+")",
    maxTessellationControlPerVertexInputComponents: "u32("+callof(V.VkPhysicalDeviceLimits_maxTessellationControlPerVertexInputComponents_offsetof)+")",
    maxTessellationControlPerVertexOutputComponents: "u32("+callof(V.VkPhysicalDeviceLimits_maxTessellationControlPerVertexOutputComponents_offsetof)+")",
    maxTessellationControlPerPatchOutputComponents: "u32("+callof(V.VkPhysicalDeviceLimits_maxTessellationControlPerPatchOutputComponents_offsetof)+")",
    maxTessellationControlTotalOutputComponents: "u32("+callof(V.VkPhysicalDeviceLimits_maxTessellationControlTotalOutputComponents_offsetof)+")",
    maxTessellationEvaluationInputComponents: "u32("+callof(V.VkPhysicalDeviceLimits_maxTessellationEvaluationInputComponents_offsetof)+")",
    maxTessellationEvaluationOutputComponents: "u32("+callof(V.VkPhysicalDeviceLimits_maxTessellationEvaluationOutputComponents_offsetof)+")",
    maxGeometryShaderInvocations: "u32("+callof(V.VkPhysicalDeviceLimits_maxGeometryShaderInvocations_offsetof)+")",
    maxGeometryInputComponents: "u32("+callof(V.VkPhysicalDeviceLimits_maxGeometryInputComponents_offsetof)+")",
    maxGeometryOutputComponents: "u32("+callof(V.VkPhysicalDeviceLimits_maxGeometryOutputComponents_offsetof)+")",
    maxGeometryOutputVertices: "u32("+callof(V.VkPhysicalDeviceLimits_maxGeometryOutputVertices_offsetof)+")",
    maxGeometryTotalOutputComponents: "u32("+callof(V.VkPhysicalDeviceLimits_maxGeometryTotalOutputComponents_offsetof)+")",
    maxFragmentInputComponents: "u32("+callof(V.VkPhysicalDeviceLimits_maxFragmentInputComponents_offsetof)+")",
    maxFragmentOutputAttachments: "u32("+callof(V.VkPhysicalDeviceLimits_maxFragmentOutputAttachments_offsetof)+")",
    maxFragmentDualSrcAttachments: "u32("+callof(V.VkPhysicalDeviceLimits_maxFragmentDualSrcAttachments_offsetof)+")",
    maxFragmentCombinedOutputResources: "u32("+callof(V.VkPhysicalDeviceLimits_maxFragmentCombinedOutputResources_offsetof)+")",
    maxComputeSharedMemorySize: "u32("+callof(V.VkPhysicalDeviceLimits_maxComputeSharedMemorySize_offsetof)+")",
    maxComputeWorkGroupCount: "u32[3]("+callof(V.VkPhysicalDeviceLimits_maxComputeWorkGroupCount_offsetof)+")",
    maxComputeWorkGroupInvocations: "u32("+callof(V.VkPhysicalDeviceLimits_maxComputeWorkGroupInvocations_offsetof)+")",
    maxComputeWorkGroupSize: "u32[3]("+callof(V.VkPhysicalDeviceLimits_maxComputeWorkGroupSize_offsetof)+")",
    subPixelPrecisionBits: "u32("+callof(V.VkPhysicalDeviceLimits_subPixelPrecisionBits_offsetof)+")",
    subTexelPrecisionBits: "u32("+callof(V.VkPhysicalDeviceLimits_subTexelPrecisionBits_offsetof)+")",
    mipmapPrecisionBits: "u32("+callof(V.VkPhysicalDeviceLimits_mipmapPrecisionBits_offsetof)+")",
    maxDrawIndexedIndexValue: "u32("+callof(V.VkPhysicalDeviceLimits_maxDrawIndexedIndexValue_offsetof)+")",
    maxDrawIndirectCount: "u32("+callof(V.VkPhysicalDeviceLimits_maxDrawIndirectCount_offsetof)+")",
    maxSamplerLodBias: "f32("+callof(V.VkPhysicalDeviceLimits_maxSamplerLodBias_offsetof)+")",
    maxSamplerAnisotropy: "f32("+callof(V.VkPhysicalDeviceLimits_maxSamplerAnisotropy_offsetof)+")",
    maxViewports: "u32("+callof(V.VkPhysicalDeviceLimits_maxViewports_offsetof)+")",
    maxViewportDimensions: "u32[2]("+callof(V.VkPhysicalDeviceLimits_maxViewportDimensions_offsetof)+")",
    viewportBoundsRange: "f32[2]("+callof(V.VkPhysicalDeviceLimits_viewportBoundsRange_offsetof)+")",
    viewportSubPixelBits: "u32("+callof(V.VkPhysicalDeviceLimits_viewportSubPixelBits_offsetof)+")",
    minMemoryMapAlignment: "u64("+callof(V.VkPhysicalDeviceLimits_minMemoryMapAlignment_offsetof)+")",
    minTexelBufferOffsetAlignment: "u64("+callof(V.VkPhysicalDeviceLimits_minTexelBufferOffsetAlignment_offsetof)+")",
    minUniformBufferOffsetAlignment: "u64("+callof(V.VkPhysicalDeviceLimits_minUniformBufferOffsetAlignment_offsetof)+")",
    minStorageBufferOffsetAlignment: "u64("+callof(V.VkPhysicalDeviceLimits_minStorageBufferOffsetAlignment_offsetof)+")",
    minTexelOffset: "i32("+callof(V.VkPhysicalDeviceLimits_minTexelOffset_offsetof)+")",
    maxTexelOffset: "u32("+callof(V.VkPhysicalDeviceLimits_maxTexelOffset_offsetof)+")",
    minTexelGatherOffset: "i32("+callof(V.VkPhysicalDeviceLimits_minTexelGatherOffset_offsetof)+")",
    maxTexelGatherOffset: "u32("+callof(V.VkPhysicalDeviceLimits_maxTexelGatherOffset_offsetof)+")",
    minInterpolationOffset: "f32("+callof(V.VkPhysicalDeviceLimits_minInterpolationOffset_offsetof)+")",
    maxInterpolationOffset: "f32("+callof(V.VkPhysicalDeviceLimits_maxInterpolationOffset_offsetof)+")",
    subPixelInterpolationOffsetBits: "u32("+callof(V.VkPhysicalDeviceLimits_subPixelInterpolationOffsetBits_offsetof)+")",
    maxFramebufferWidth: "u32("+callof(V.VkPhysicalDeviceLimits_maxFramebufferWidth_offsetof)+")",
    maxFramebufferHeight: "u32("+callof(V.VkPhysicalDeviceLimits_maxFramebufferHeight_offsetof)+")",
    maxFramebufferLayers: "u32("+callof(V.VkPhysicalDeviceLimits_maxFramebufferLayers_offsetof)+")",
    framebufferColorSampleCounts: "u32("+callof(V.VkPhysicalDeviceLimits_framebufferColorSampleCounts_offsetof)+")",
    framebufferDepthSampleCounts: "u32("+callof(V.VkPhysicalDeviceLimits_framebufferDepthSampleCounts_offsetof)+")",
    framebufferStencilSampleCounts: "u32("+callof(V.VkPhysicalDeviceLimits_framebufferStencilSampleCounts_offsetof)+")",
    framebufferNoAttachmentsSampleCounts: "u32("+callof(V.VkPhysicalDeviceLimits_framebufferNoAttachmentsSampleCounts_offsetof)+")",
    maxColorAttachments: "u32("+callof(V.VkPhysicalDeviceLimits_maxColorAttachments_offsetof)+")",
    sampledImageColorSampleCounts: "u32("+callof(V.VkPhysicalDeviceLimits_sampledImageColorSampleCounts_offsetof)+")",
    sampledImageIntegerSampleCounts: "u32("+callof(V.VkPhysicalDeviceLimits_sampledImageIntegerSampleCounts_offsetof)+")",
    sampledImageDepthSampleCounts: "u32("+callof(V.VkPhysicalDeviceLimits_sampledImageDepthSampleCounts_offsetof)+")",
    sampledImageStencilSampleCounts: "u32("+callof(V.VkPhysicalDeviceLimits_sampledImageStencilSampleCounts_offsetof)+")",
    storageImageSampleCounts: "u32("+callof(V.VkPhysicalDeviceLimits_storageImageSampleCounts_offsetof)+")",
    maxSampleMaskWords: "u32("+callof(V.VkPhysicalDeviceLimits_maxSampleMaskWords_offsetof)+")",
    timestampComputeAndGraphics: "u32("+callof(V.VkPhysicalDeviceLimits_timestampComputeAndGraphics_offsetof)+")",
    timestampPeriod: "f32("+callof(V.VkPhysicalDeviceLimits_timestampPeriod_offsetof)+")",
    maxClipDistances: "u32("+callof(V.VkPhysicalDeviceLimits_maxClipDistances_offsetof)+")",
    maxCullDistances: "u32("+callof(V.VkPhysicalDeviceLimits_maxCullDistances_offsetof)+")",
    maxCombinedClipAndCullDistances: "u32("+callof(V.VkPhysicalDeviceLimits_maxCombinedClipAndCullDistances_offsetof)+")",
    discreteQueuePriorities: "u32("+callof(V.VkPhysicalDeviceLimits_discreteQueuePriorities_offsetof)+")",
    pointSizeRange: "f32[2]("+callof(V.VkPhysicalDeviceLimits_pointSizeRange_offsetof)+")",
    lineWidthRange: "f32[2]("+callof(V.VkPhysicalDeviceLimits_lineWidthRange_offsetof)+")",
    pointSizeGranularity: "f32("+callof(V.VkPhysicalDeviceLimits_pointSizeGranularity_offsetof)+")",
    lineWidthGranularity: "f32("+callof(V.VkPhysicalDeviceLimits_lineWidthGranularity_offsetof)+")",
    strictLines: "u32("+callof(V.VkPhysicalDeviceLimits_strictLines_offsetof)+")",
    standardSampleLocations: "u32("+callof(V.VkPhysicalDeviceLimits_standardSampleLocations_offsetof)+")",
    optimalBufferCopyOffsetAlignment: "u64("+callof(V.VkPhysicalDeviceLimits_optimalBufferCopyOffsetAlignment_offsetof)+")",
    optimalBufferCopyRowPitchAlignment: "u64("+callof(V.VkPhysicalDeviceLimits_optimalBufferCopyRowPitchAlignment_offsetof)+")",
    nonCoherentAtomSize: "u64("+callof(V.VkPhysicalDeviceLimits_nonCoherentAtomSize_offsetof)+")",
}, callof(V.VkPhysicalDeviceLimits_sizeof));


const VkSemaphoreCreateInfo = new C.CStruct("VkSemaphoreCreateInfo", {
    sType: "u32("+callof(V.VkSemaphoreCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSemaphoreCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkSemaphoreCreateInfo_flags_offsetof)+")",
}, callof(V.VkSemaphoreCreateInfo_sizeof));


const VkQueryPoolCreateInfo = new C.CStruct("VkQueryPoolCreateInfo", {
    sType: "u32("+callof(V.VkQueryPoolCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkQueryPoolCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkQueryPoolCreateInfo_flags_offsetof)+")",
    queryType: "u32("+callof(V.VkQueryPoolCreateInfo_queryType_offsetof)+")",
    queryCount: "u32("+callof(V.VkQueryPoolCreateInfo_queryCount_offsetof)+")",
    pipelineStatistics: "u32("+callof(V.VkQueryPoolCreateInfo_pipelineStatistics_offsetof)+")",
}, callof(V.VkQueryPoolCreateInfo_sizeof));


const VkFramebufferCreateInfo = new C.CStruct("VkFramebufferCreateInfo", {
    sType: "u32("+callof(V.VkFramebufferCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkFramebufferCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkFramebufferCreateInfo_flags_offsetof)+")",
    renderPass: "u32("+callof(V.VkFramebufferCreateInfo_renderPass_offsetof)+")",
    attachmentCount: "u32("+callof(V.VkFramebufferCreateInfo_attachmentCount_offsetof)+")",
    pAttachments: "u64("+callof(V.VkFramebufferCreateInfo_pAttachments_offsetof)+")",
    width: "u32("+callof(V.VkFramebufferCreateInfo_width_offsetof)+")",
    height: "u32("+callof(V.VkFramebufferCreateInfo_height_offsetof)+")",
    layers: "u32("+callof(V.VkFramebufferCreateInfo_layers_offsetof)+")",
}, callof(V.VkFramebufferCreateInfo_sizeof));


const VkDrawIndirectCommand = new C.CStruct("VkDrawIndirectCommand", {
    vertexCount: "u32("+callof(V.VkDrawIndirectCommand_vertexCount_offsetof)+")",
    instanceCount: "u32("+callof(V.VkDrawIndirectCommand_instanceCount_offsetof)+")",
    firstVertex: "u32("+callof(V.VkDrawIndirectCommand_firstVertex_offsetof)+")",
    firstInstance: "u32("+callof(V.VkDrawIndirectCommand_firstInstance_offsetof)+")",
}, callof(V.VkDrawIndirectCommand_sizeof));


const VkDrawIndexedIndirectCommand = new C.CStruct("VkDrawIndexedIndirectCommand", {
    indexCount: "u32("+callof(V.VkDrawIndexedIndirectCommand_indexCount_offsetof)+")",
    instanceCount: "u32("+callof(V.VkDrawIndexedIndirectCommand_instanceCount_offsetof)+")",
    firstIndex: "u32("+callof(V.VkDrawIndexedIndirectCommand_firstIndex_offsetof)+")",
    vertexOffset: "i32("+callof(V.VkDrawIndexedIndirectCommand_vertexOffset_offsetof)+")",
    firstInstance: "u32("+callof(V.VkDrawIndexedIndirectCommand_firstInstance_offsetof)+")",
}, callof(V.VkDrawIndexedIndirectCommand_sizeof));


const VkDispatchIndirectCommand = new C.CStruct("VkDispatchIndirectCommand", {
    x: "u32("+callof(V.VkDispatchIndirectCommand_x_offsetof)+")",
    y: "u32("+callof(V.VkDispatchIndirectCommand_y_offsetof)+")",
    z: "u32("+callof(V.VkDispatchIndirectCommand_z_offsetof)+")",
}, callof(V.VkDispatchIndirectCommand_sizeof));


const VkMultiDrawInfoEXT = new C.CStruct("VkMultiDrawInfoEXT", {
    firstVertex: "u32("+callof(V.VkMultiDrawInfoEXT_firstVertex_offsetof)+")",
    vertexCount: "u32("+callof(V.VkMultiDrawInfoEXT_vertexCount_offsetof)+")",
}, callof(V.VkMultiDrawInfoEXT_sizeof));


const VkMultiDrawIndexedInfoEXT = new C.CStruct("VkMultiDrawIndexedInfoEXT", {
    firstIndex: "u32("+callof(V.VkMultiDrawIndexedInfoEXT_firstIndex_offsetof)+")",
    indexCount: "u32("+callof(V.VkMultiDrawIndexedInfoEXT_indexCount_offsetof)+")",
    vertexOffset: "i32("+callof(V.VkMultiDrawIndexedInfoEXT_vertexOffset_offsetof)+")",
}, callof(V.VkMultiDrawIndexedInfoEXT_sizeof));


const VkSubmitInfo = new C.CStruct("VkSubmitInfo", {
    sType: "u32("+callof(V.VkSubmitInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSubmitInfo_pNext_offsetof)+")",
    waitSemaphoreCount: "u32("+callof(V.VkSubmitInfo_waitSemaphoreCount_offsetof)+")",
    pWaitSemaphores: "u64("+callof(V.VkSubmitInfo_pWaitSemaphores_offsetof)+")",
    pWaitDstStageMask: "u64("+callof(V.VkSubmitInfo_pWaitDstStageMask_offsetof)+")",
    commandBufferCount: "u32("+callof(V.VkSubmitInfo_commandBufferCount_offsetof)+")",
    pCommandBuffers: "u64("+callof(V.VkSubmitInfo_pCommandBuffers_offsetof)+")",
    signalSemaphoreCount: "u32("+callof(V.VkSubmitInfo_signalSemaphoreCount_offsetof)+")",
    pSignalSemaphores: "u64("+callof(V.VkSubmitInfo_pSignalSemaphores_offsetof)+")",
}, callof(V.VkSubmitInfo_sizeof));


const VkDisplayPropertiesKHR = new C.CStruct("VkDisplayPropertiesKHR", {
    display: "u32("+callof(V.VkDisplayPropertiesKHR_display_offsetof)+")",
    displayName: "u64("+callof(V.VkDisplayPropertiesKHR_displayName_offsetof)+")",
    physicalDimensions: "VkExtent2D("+callof(V.VkDisplayPropertiesKHR_physicalDimensions_offsetof)+")",
    physicalResolution: "VkExtent2D("+callof(V.VkDisplayPropertiesKHR_physicalResolution_offsetof)+")",
    supportedTransforms: "u32("+callof(V.VkDisplayPropertiesKHR_supportedTransforms_offsetof)+")",
    planeReorderPossible: "u32("+callof(V.VkDisplayPropertiesKHR_planeReorderPossible_offsetof)+")",
    persistentContent: "u32("+callof(V.VkDisplayPropertiesKHR_persistentContent_offsetof)+")",
}, callof(V.VkDisplayPropertiesKHR_sizeof));


const VkDisplayPlanePropertiesKHR = new C.CStruct("VkDisplayPlanePropertiesKHR", {
    currentDisplay: "u32("+callof(V.VkDisplayPlanePropertiesKHR_currentDisplay_offsetof)+")",
    currentStackIndex: "u32("+callof(V.VkDisplayPlanePropertiesKHR_currentStackIndex_offsetof)+")",
}, callof(V.VkDisplayPlanePropertiesKHR_sizeof));


const VkDisplayModeParametersKHR = new C.CStruct("VkDisplayModeParametersKHR", {
    visibleRegion: "VkExtent2D("+callof(V.VkDisplayModeParametersKHR_visibleRegion_offsetof)+")",
    refreshRate: "u32("+callof(V.VkDisplayModeParametersKHR_refreshRate_offsetof)+")",
}, callof(V.VkDisplayModeParametersKHR_sizeof));


const VkDisplayModePropertiesKHR = new C.CStruct("VkDisplayModePropertiesKHR", {
    displayMode: "u32("+callof(V.VkDisplayModePropertiesKHR_displayMode_offsetof)+")",
    parameters: "u32("+callof(V.VkDisplayModePropertiesKHR_parameters_offsetof)+")",
}, callof(V.VkDisplayModePropertiesKHR_sizeof));


const VkDisplayModeCreateInfoKHR = new C.CStruct("VkDisplayModeCreateInfoKHR", {
    sType: "u32("+callof(V.VkDisplayModeCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDisplayModeCreateInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDisplayModeCreateInfoKHR_flags_offsetof)+")",
    parameters: "u32("+callof(V.VkDisplayModeCreateInfoKHR_parameters_offsetof)+")",
}, callof(V.VkDisplayModeCreateInfoKHR_sizeof));


const VkDisplayPlaneCapabilitiesKHR = new C.CStruct("VkDisplayPlaneCapabilitiesKHR", {
    supportedAlpha: "u32("+callof(V.VkDisplayPlaneCapabilitiesKHR_supportedAlpha_offsetof)+")",
    minSrcPosition: "VkOffset2D("+callof(V.VkDisplayPlaneCapabilitiesKHR_minSrcPosition_offsetof)+")",
    maxSrcPosition: "VkOffset2D("+callof(V.VkDisplayPlaneCapabilitiesKHR_maxSrcPosition_offsetof)+")",
    minSrcExtent: "VkExtent2D("+callof(V.VkDisplayPlaneCapabilitiesKHR_minSrcExtent_offsetof)+")",
    maxSrcExtent: "VkExtent2D("+callof(V.VkDisplayPlaneCapabilitiesKHR_maxSrcExtent_offsetof)+")",
    minDstPosition: "VkOffset2D("+callof(V.VkDisplayPlaneCapabilitiesKHR_minDstPosition_offsetof)+")",
    maxDstPosition: "VkOffset2D("+callof(V.VkDisplayPlaneCapabilitiesKHR_maxDstPosition_offsetof)+")",
    minDstExtent: "VkExtent2D("+callof(V.VkDisplayPlaneCapabilitiesKHR_minDstExtent_offsetof)+")",
    maxDstExtent: "VkExtent2D("+callof(V.VkDisplayPlaneCapabilitiesKHR_maxDstExtent_offsetof)+")",
}, callof(V.VkDisplayPlaneCapabilitiesKHR_sizeof));


const VkDisplaySurfaceCreateInfoKHR = new C.CStruct("VkDisplaySurfaceCreateInfoKHR", {
    sType: "u32("+callof(V.VkDisplaySurfaceCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDisplaySurfaceCreateInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDisplaySurfaceCreateInfoKHR_flags_offsetof)+")",
    displayMode: "u32("+callof(V.VkDisplaySurfaceCreateInfoKHR_displayMode_offsetof)+")",
    planeIndex: "u32("+callof(V.VkDisplaySurfaceCreateInfoKHR_planeIndex_offsetof)+")",
    planeStackIndex: "u32("+callof(V.VkDisplaySurfaceCreateInfoKHR_planeStackIndex_offsetof)+")",
    transform: "u32("+callof(V.VkDisplaySurfaceCreateInfoKHR_transform_offsetof)+")",
    globalAlpha: "f32("+callof(V.VkDisplaySurfaceCreateInfoKHR_globalAlpha_offsetof)+")",
    alphaMode: "u32("+callof(V.VkDisplaySurfaceCreateInfoKHR_alphaMode_offsetof)+")",
    imageExtent: "VkExtent2D("+callof(V.VkDisplaySurfaceCreateInfoKHR_imageExtent_offsetof)+")",
}, callof(V.VkDisplaySurfaceCreateInfoKHR_sizeof));


const VkDisplayPresentInfoKHR = new C.CStruct("VkDisplayPresentInfoKHR", {
    sType: "u32("+callof(V.VkDisplayPresentInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDisplayPresentInfoKHR_pNext_offsetof)+")",
    srcRect: "VkRect2D("+callof(V.VkDisplayPresentInfoKHR_srcRect_offsetof)+")",
    dstRect: "VkRect2D("+callof(V.VkDisplayPresentInfoKHR_dstRect_offsetof)+")",
    persistent: "u32("+callof(V.VkDisplayPresentInfoKHR_persistent_offsetof)+")",
}, callof(V.VkDisplayPresentInfoKHR_sizeof));


const VkSurfaceCapabilitiesKHR = new C.CStruct("VkSurfaceCapabilitiesKHR", {
    minImageCount: "u32("+callof(V.VkSurfaceCapabilitiesKHR_minImageCount_offsetof)+")",
    maxImageCount: "u32("+callof(V.VkSurfaceCapabilitiesKHR_maxImageCount_offsetof)+")",
    currentExtent: "VkExtent2D("+callof(V.VkSurfaceCapabilitiesKHR_currentExtent_offsetof)+")",
    minImageExtent: "VkExtent2D("+callof(V.VkSurfaceCapabilitiesKHR_minImageExtent_offsetof)+")",
    maxImageExtent: "VkExtent2D("+callof(V.VkSurfaceCapabilitiesKHR_maxImageExtent_offsetof)+")",
    maxImageArrayLayers: "u32("+callof(V.VkSurfaceCapabilitiesKHR_maxImageArrayLayers_offsetof)+")",
    supportedTransforms: "u32("+callof(V.VkSurfaceCapabilitiesKHR_supportedTransforms_offsetof)+")",
    currentTransform: "u32("+callof(V.VkSurfaceCapabilitiesKHR_currentTransform_offsetof)+")",
    supportedCompositeAlpha: "u32("+callof(V.VkSurfaceCapabilitiesKHR_supportedCompositeAlpha_offsetof)+")",
    supportedUsageFlags: "u32("+callof(V.VkSurfaceCapabilitiesKHR_supportedUsageFlags_offsetof)+")",
}, callof(V.VkSurfaceCapabilitiesKHR_sizeof));


const VkAndroidSurfaceCreateInfoKHR = new C.CStruct("VkAndroidSurfaceCreateInfoKHR", {
    sType: "u32("+callof(V.VkAndroidSurfaceCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAndroidSurfaceCreateInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkAndroidSurfaceCreateInfoKHR_flags_offsetof)+")",
    window: "u64("+callof(V.VkAndroidSurfaceCreateInfoKHR_window_offsetof)+")",
}, callof(V.VkAndroidSurfaceCreateInfoKHR_sizeof));


const VkViSurfaceCreateInfoNN = new C.CStruct("VkViSurfaceCreateInfoNN", {
    sType: "u32("+callof(V.VkViSurfaceCreateInfoNN_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkViSurfaceCreateInfoNN_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkViSurfaceCreateInfoNN_flags_offsetof)+")",
    window: "u64("+callof(V.VkViSurfaceCreateInfoNN_window_offsetof)+")",
}, callof(V.VkViSurfaceCreateInfoNN_sizeof));


const VkWaylandSurfaceCreateInfoKHR = new C.CStruct("VkWaylandSurfaceCreateInfoKHR", {
    sType: "u32("+callof(V.VkWaylandSurfaceCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkWaylandSurfaceCreateInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkWaylandSurfaceCreateInfoKHR_flags_offsetof)+")",
    display: "u64("+callof(V.VkWaylandSurfaceCreateInfoKHR_display_offsetof)+")",
    surface: "u64("+callof(V.VkWaylandSurfaceCreateInfoKHR_surface_offsetof)+")",
}, callof(V.VkWaylandSurfaceCreateInfoKHR_sizeof));


const VkWin32SurfaceCreateInfoKHR = new C.CStruct("VkWin32SurfaceCreateInfoKHR", {
    sType: "u32("+callof(V.VkWin32SurfaceCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkWin32SurfaceCreateInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkWin32SurfaceCreateInfoKHR_flags_offsetof)+")",
    hinstance: "u32("+callof(V.VkWin32SurfaceCreateInfoKHR_hinstance_offsetof)+")",
    hwnd: "u32("+callof(V.VkWin32SurfaceCreateInfoKHR_hwnd_offsetof)+")",
}, callof(V.VkWin32SurfaceCreateInfoKHR_sizeof));


const VkXlibSurfaceCreateInfoKHR = new C.CStruct("VkXlibSurfaceCreateInfoKHR", {
    sType: "u32("+callof(V.VkXlibSurfaceCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkXlibSurfaceCreateInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkXlibSurfaceCreateInfoKHR_flags_offsetof)+")",
    dpy: "u64("+callof(V.VkXlibSurfaceCreateInfoKHR_dpy_offsetof)+")",
    window: "u32("+callof(V.VkXlibSurfaceCreateInfoKHR_window_offsetof)+")",
}, callof(V.VkXlibSurfaceCreateInfoKHR_sizeof));


const VkXcbSurfaceCreateInfoKHR = new C.CStruct("VkXcbSurfaceCreateInfoKHR", {
    sType: "u32("+callof(V.VkXcbSurfaceCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkXcbSurfaceCreateInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkXcbSurfaceCreateInfoKHR_flags_offsetof)+")",
    connection: "u64("+callof(V.VkXcbSurfaceCreateInfoKHR_connection_offsetof)+")",
    window: "u32("+callof(V.VkXcbSurfaceCreateInfoKHR_window_offsetof)+")",
}, callof(V.VkXcbSurfaceCreateInfoKHR_sizeof));


const VkDirectFBSurfaceCreateInfoEXT = new C.CStruct("VkDirectFBSurfaceCreateInfoEXT", {
    sType: "u32("+callof(V.VkDirectFBSurfaceCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDirectFBSurfaceCreateInfoEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDirectFBSurfaceCreateInfoEXT_flags_offsetof)+")",
    dfb: "u64("+callof(V.VkDirectFBSurfaceCreateInfoEXT_dfb_offsetof)+")",
    surface: "u64("+callof(V.VkDirectFBSurfaceCreateInfoEXT_surface_offsetof)+")",
}, callof(V.VkDirectFBSurfaceCreateInfoEXT_sizeof));


const VkImagePipeSurfaceCreateInfoFUCHSIA = new C.CStruct("VkImagePipeSurfaceCreateInfoFUCHSIA", {
    sType: "u32("+callof(V.VkImagePipeSurfaceCreateInfoFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImagePipeSurfaceCreateInfoFUCHSIA_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkImagePipeSurfaceCreateInfoFUCHSIA_flags_offsetof)+")",
    imagePipeHandle: "u32("+callof(V.VkImagePipeSurfaceCreateInfoFUCHSIA_imagePipeHandle_offsetof)+")",
}, callof(V.VkImagePipeSurfaceCreateInfoFUCHSIA_sizeof));


const VkStreamDescriptorSurfaceCreateInfoGGP = new C.CStruct("VkStreamDescriptorSurfaceCreateInfoGGP", {
    sType: "u32("+callof(V.VkStreamDescriptorSurfaceCreateInfoGGP_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkStreamDescriptorSurfaceCreateInfoGGP_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkStreamDescriptorSurfaceCreateInfoGGP_flags_offsetof)+")",
    streamDescriptor: "u32("+callof(V.VkStreamDescriptorSurfaceCreateInfoGGP_streamDescriptor_offsetof)+")",
}, callof(V.VkStreamDescriptorSurfaceCreateInfoGGP_sizeof));


const VkScreenSurfaceCreateInfoQNX = new C.CStruct("VkScreenSurfaceCreateInfoQNX", {
    sType: "u32("+callof(V.VkScreenSurfaceCreateInfoQNX_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkScreenSurfaceCreateInfoQNX_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkScreenSurfaceCreateInfoQNX_flags_offsetof)+")",
    context: "u64("+callof(V.VkScreenSurfaceCreateInfoQNX_context_offsetof)+")",
    window: "u64("+callof(V.VkScreenSurfaceCreateInfoQNX_window_offsetof)+")",
}, callof(V.VkScreenSurfaceCreateInfoQNX_sizeof));


const VkSurfaceFormatKHR = new C.CStruct("VkSurfaceFormatKHR", {
    format: "u32("+callof(V.VkSurfaceFormatKHR_format_offsetof)+")",
    colorSpace: "u32("+callof(V.VkSurfaceFormatKHR_colorSpace_offsetof)+")",
}, callof(V.VkSurfaceFormatKHR_sizeof));


const VkSwapchainCreateInfoKHR = new C.CStruct("VkSwapchainCreateInfoKHR", {
    sType: "u32("+callof(V.VkSwapchainCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSwapchainCreateInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkSwapchainCreateInfoKHR_flags_offsetof)+")",
    surface: "u64("+callof(V.VkSwapchainCreateInfoKHR_surface_offsetof)+")",
    minImageCount: "u32("+callof(V.VkSwapchainCreateInfoKHR_minImageCount_offsetof)+")",
    imageFormat: "u32("+callof(V.VkSwapchainCreateInfoKHR_imageFormat_offsetof)+")",
    imageColorSpace: "u32("+callof(V.VkSwapchainCreateInfoKHR_imageColorSpace_offsetof)+")",
    imageExtent: "VkExtent2D("+callof(V.VkSwapchainCreateInfoKHR_imageExtent_offsetof)+")",
    imageArrayLayers: "u32("+callof(V.VkSwapchainCreateInfoKHR_imageArrayLayers_offsetof)+")",
    imageUsage: "u32("+callof(V.VkSwapchainCreateInfoKHR_imageUsage_offsetof)+")",
    imageSharingMode: "u32("+callof(V.VkSwapchainCreateInfoKHR_imageSharingMode_offsetof)+")",
    queueFamilyIndexCount: "u32("+callof(V.VkSwapchainCreateInfoKHR_queueFamilyIndexCount_offsetof)+")",
    pQueueFamilyIndices: "u64("+callof(V.VkSwapchainCreateInfoKHR_pQueueFamilyIndices_offsetof)+")",
    preTransform: "u32("+callof(V.VkSwapchainCreateInfoKHR_preTransform_offsetof)+")",
    compositeAlpha: "u32("+callof(V.VkSwapchainCreateInfoKHR_compositeAlpha_offsetof)+")",
    presentMode: "u32("+callof(V.VkSwapchainCreateInfoKHR_presentMode_offsetof)+")",
    clipped: "u32("+callof(V.VkSwapchainCreateInfoKHR_clipped_offsetof)+")",
    oldSwapchain: "u64("+callof(V.VkSwapchainCreateInfoKHR_oldSwapchain_offsetof)+")",
}, callof(V.VkSwapchainCreateInfoKHR_sizeof));


const VkPresentInfoKHR = new C.CStruct("VkPresentInfoKHR", {
    sType: "u32("+callof(V.VkPresentInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPresentInfoKHR_pNext_offsetof)+")",
    waitSemaphoreCount: "u32("+callof(V.VkPresentInfoKHR_waitSemaphoreCount_offsetof)+")",
    pWaitSemaphores: "u64("+callof(V.VkPresentInfoKHR_pWaitSemaphores_offsetof)+")",
    swapchainCount: "u32("+callof(V.VkPresentInfoKHR_swapchainCount_offsetof)+")",
    pSwapchains: "u64("+callof(V.VkPresentInfoKHR_pSwapchains_offsetof)+")",
    pImageIndices: "u64("+callof(V.VkPresentInfoKHR_pImageIndices_offsetof)+")",
    pResults: "u64("+callof(V.VkPresentInfoKHR_pResults_offsetof)+")",
}, callof(V.VkPresentInfoKHR_sizeof));


const VkDebugReportCallbackCreateInfoEXT = new C.CStruct("VkDebugReportCallbackCreateInfoEXT", {
    sType: "u32("+callof(V.VkDebugReportCallbackCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDebugReportCallbackCreateInfoEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDebugReportCallbackCreateInfoEXT_flags_offsetof)+")",
    pfnCallback: "u32("+callof(V.VkDebugReportCallbackCreateInfoEXT_pfnCallback_offsetof)+")",
    pUserData: "u64("+callof(V.VkDebugReportCallbackCreateInfoEXT_pUserData_offsetof)+")",
}, callof(V.VkDebugReportCallbackCreateInfoEXT_sizeof));


const VkValidationFlagsEXT = new C.CStruct("VkValidationFlagsEXT", {
    sType: "u32("+callof(V.VkValidationFlagsEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkValidationFlagsEXT_pNext_offsetof)+")",
    disabledValidationCheckCount: "u32("+callof(V.VkValidationFlagsEXT_disabledValidationCheckCount_offsetof)+")",
    pDisabledValidationChecks: "u64("+callof(V.VkValidationFlagsEXT_pDisabledValidationChecks_offsetof)+")",
}, callof(V.VkValidationFlagsEXT_sizeof));


const VkValidationFeaturesEXT = new C.CStruct("VkValidationFeaturesEXT", {
    sType: "u32("+callof(V.VkValidationFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkValidationFeaturesEXT_pNext_offsetof)+")",
    enabledValidationFeatureCount: "u32("+callof(V.VkValidationFeaturesEXT_enabledValidationFeatureCount_offsetof)+")",
    pEnabledValidationFeatures: "u64("+callof(V.VkValidationFeaturesEXT_pEnabledValidationFeatures_offsetof)+")",
    disabledValidationFeatureCount: "u32("+callof(V.VkValidationFeaturesEXT_disabledValidationFeatureCount_offsetof)+")",
    pDisabledValidationFeatures: "u64("+callof(V.VkValidationFeaturesEXT_pDisabledValidationFeatures_offsetof)+")",
}, callof(V.VkValidationFeaturesEXT_sizeof));


const VkPipelineRasterizationStateRasterizationOrderAMD = new C.CStruct("VkPipelineRasterizationStateRasterizationOrderAMD", {
    sType: "u32("+callof(V.VkPipelineRasterizationStateRasterizationOrderAMD_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineRasterizationStateRasterizationOrderAMD_pNext_offsetof)+")",
    rasterizationOrder: "u32("+callof(V.VkPipelineRasterizationStateRasterizationOrderAMD_rasterizationOrder_offsetof)+")",
}, callof(V.VkPipelineRasterizationStateRasterizationOrderAMD_sizeof));


const VkDebugMarkerObjectNameInfoEXT = new C.CStruct("VkDebugMarkerObjectNameInfoEXT", {
    sType: "u32("+callof(V.VkDebugMarkerObjectNameInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDebugMarkerObjectNameInfoEXT_pNext_offsetof)+")",
    objectType: "u32("+callof(V.VkDebugMarkerObjectNameInfoEXT_objectType_offsetof)+")",
    object: "u64("+callof(V.VkDebugMarkerObjectNameInfoEXT_object_offsetof)+")",
    pObjectName: "u64("+callof(V.VkDebugMarkerObjectNameInfoEXT_pObjectName_offsetof)+")",
}, callof(V.VkDebugMarkerObjectNameInfoEXT_sizeof));


const VkDebugMarkerObjectTagInfoEXT = new C.CStruct("VkDebugMarkerObjectTagInfoEXT", {
    sType: "u32("+callof(V.VkDebugMarkerObjectTagInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDebugMarkerObjectTagInfoEXT_pNext_offsetof)+")",
    objectType: "u32("+callof(V.VkDebugMarkerObjectTagInfoEXT_objectType_offsetof)+")",
    object: "u64("+callof(V.VkDebugMarkerObjectTagInfoEXT_object_offsetof)+")",
    tagName: "u64("+callof(V.VkDebugMarkerObjectTagInfoEXT_tagName_offsetof)+")",
    tagSize: "u64("+callof(V.VkDebugMarkerObjectTagInfoEXT_tagSize_offsetof)+")",
    pTag: "u64("+callof(V.VkDebugMarkerObjectTagInfoEXT_pTag_offsetof)+")",
}, callof(V.VkDebugMarkerObjectTagInfoEXT_sizeof));


const VkDebugMarkerMarkerInfoEXT = new C.CStruct("VkDebugMarkerMarkerInfoEXT", {
    sType: "u32("+callof(V.VkDebugMarkerMarkerInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDebugMarkerMarkerInfoEXT_pNext_offsetof)+")",
    pMarkerName: "u64("+callof(V.VkDebugMarkerMarkerInfoEXT_pMarkerName_offsetof)+")",
    color: "f32[4]("+callof(V.VkDebugMarkerMarkerInfoEXT_color_offsetof)+")",
}, callof(V.VkDebugMarkerMarkerInfoEXT_sizeof));


const VkDedicatedAllocationImageCreateInfoNV = new C.CStruct("VkDedicatedAllocationImageCreateInfoNV", {
    sType: "u32("+callof(V.VkDedicatedAllocationImageCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDedicatedAllocationImageCreateInfoNV_pNext_offsetof)+")",
    dedicatedAllocation: "u32("+callof(V.VkDedicatedAllocationImageCreateInfoNV_dedicatedAllocation_offsetof)+")",
}, callof(V.VkDedicatedAllocationImageCreateInfoNV_sizeof));


const VkDedicatedAllocationBufferCreateInfoNV = new C.CStruct("VkDedicatedAllocationBufferCreateInfoNV", {
    sType: "u32("+callof(V.VkDedicatedAllocationBufferCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDedicatedAllocationBufferCreateInfoNV_pNext_offsetof)+")",
    dedicatedAllocation: "u32("+callof(V.VkDedicatedAllocationBufferCreateInfoNV_dedicatedAllocation_offsetof)+")",
}, callof(V.VkDedicatedAllocationBufferCreateInfoNV_sizeof));


const VkDedicatedAllocationMemoryAllocateInfoNV = new C.CStruct("VkDedicatedAllocationMemoryAllocateInfoNV", {
    sType: "u32("+callof(V.VkDedicatedAllocationMemoryAllocateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDedicatedAllocationMemoryAllocateInfoNV_pNext_offsetof)+")",
    image: "u64("+callof(V.VkDedicatedAllocationMemoryAllocateInfoNV_image_offsetof)+")",
    buffer: "u64("+callof(V.VkDedicatedAllocationMemoryAllocateInfoNV_buffer_offsetof)+")",
}, callof(V.VkDedicatedAllocationMemoryAllocateInfoNV_sizeof));


const VkExternalImageFormatPropertiesNV = new C.CStruct("VkExternalImageFormatPropertiesNV", {
    imageFormatProperties: "u32("+callof(V.VkExternalImageFormatPropertiesNV_imageFormatProperties_offsetof)+")",
    externalMemoryFeatures: "u32("+callof(V.VkExternalImageFormatPropertiesNV_externalMemoryFeatures_offsetof)+")",
    exportFromImportedHandleTypes: "u32("+callof(V.VkExternalImageFormatPropertiesNV_exportFromImportedHandleTypes_offsetof)+")",
    compatibleHandleTypes: "u32("+callof(V.VkExternalImageFormatPropertiesNV_compatibleHandleTypes_offsetof)+")",
}, callof(V.VkExternalImageFormatPropertiesNV_sizeof));


const VkExternalMemoryImageCreateInfoNV = new C.CStruct("VkExternalMemoryImageCreateInfoNV", {
    sType: "u32("+callof(V.VkExternalMemoryImageCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExternalMemoryImageCreateInfoNV_pNext_offsetof)+")",
    handleTypes: "u32("+callof(V.VkExternalMemoryImageCreateInfoNV_handleTypes_offsetof)+")",
}, callof(V.VkExternalMemoryImageCreateInfoNV_sizeof));


const VkExportMemoryAllocateInfoNV = new C.CStruct("VkExportMemoryAllocateInfoNV", {
    sType: "u32("+callof(V.VkExportMemoryAllocateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportMemoryAllocateInfoNV_pNext_offsetof)+")",
    handleTypes: "u32("+callof(V.VkExportMemoryAllocateInfoNV_handleTypes_offsetof)+")",
}, callof(V.VkExportMemoryAllocateInfoNV_sizeof));


const VkImportMemoryWin32HandleInfoNV = new C.CStruct("VkImportMemoryWin32HandleInfoNV", {
    sType: "u32("+callof(V.VkImportMemoryWin32HandleInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportMemoryWin32HandleInfoNV_pNext_offsetof)+")",
    handleType: "u32("+callof(V.VkImportMemoryWin32HandleInfoNV_handleType_offsetof)+")",
    handle: "u64("+callof(V.VkImportMemoryWin32HandleInfoNV_handle_offsetof)+")",
}, callof(V.VkImportMemoryWin32HandleInfoNV_sizeof));


const VkExportMemoryWin32HandleInfoNV = new C.CStruct("VkExportMemoryWin32HandleInfoNV", {
    sType: "u32("+callof(V.VkExportMemoryWin32HandleInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportMemoryWin32HandleInfoNV_pNext_offsetof)+")",
    pAttributes: "u64("+callof(V.VkExportMemoryWin32HandleInfoNV_pAttributes_offsetof)+")",
    dwAccess: "u32("+callof(V.VkExportMemoryWin32HandleInfoNV_dwAccess_offsetof)+")",
}, callof(V.VkExportMemoryWin32HandleInfoNV_sizeof));


const VkWin32KeyedMutexAcquireReleaseInfoNV = new C.CStruct("VkWin32KeyedMutexAcquireReleaseInfoNV", {
    sType: "u32("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoNV_pNext_offsetof)+")",
    acquireCount: "u32("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoNV_acquireCount_offsetof)+")",
    pAcquireSyncs: "u64("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoNV_pAcquireSyncs_offsetof)+")",
    pAcquireKeys: "u64("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoNV_pAcquireKeys_offsetof)+")",
    pAcquireTimeoutMilliseconds: "u64("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoNV_pAcquireTimeoutMilliseconds_offsetof)+")",
    releaseCount: "u32("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoNV_releaseCount_offsetof)+")",
    pReleaseSyncs: "u64("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoNV_pReleaseSyncs_offsetof)+")",
    pReleaseKeys: "u64("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoNV_pReleaseKeys_offsetof)+")",
}, callof(V.VkWin32KeyedMutexAcquireReleaseInfoNV_sizeof));


const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV = new C.CStruct("VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV_pNext_offsetof)+")",
    deviceGeneratedCommands: "u32("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV_deviceGeneratedCommands_offsetof)+")",
}, callof(V.VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV_sizeof));


const VkDevicePrivateDataCreateInfo = new C.CStruct("VkDevicePrivateDataCreateInfo", {
    sType: "u32("+callof(V.VkDevicePrivateDataCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDevicePrivateDataCreateInfo_pNext_offsetof)+")",
    privateDataSlotRequestCount: "u32("+callof(V.VkDevicePrivateDataCreateInfo_privateDataSlotRequestCount_offsetof)+")",
}, callof(V.VkDevicePrivateDataCreateInfo_sizeof));


const VkDevicePrivateDataCreateInfoEXT = new C.CStruct("VkDevicePrivateDataCreateInfoEXT", {

}, callof(V.VkDevicePrivateDataCreateInfoEXT_sizeof));


const VkPrivateDataSlotCreateInfo = new C.CStruct("VkPrivateDataSlotCreateInfo", {
    sType: "u32("+callof(V.VkPrivateDataSlotCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPrivateDataSlotCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPrivateDataSlotCreateInfo_flags_offsetof)+")",
}, callof(V.VkPrivateDataSlotCreateInfo_sizeof));


const VkPrivateDataSlotCreateInfoEXT = new C.CStruct("VkPrivateDataSlotCreateInfoEXT", {

}, callof(V.VkPrivateDataSlotCreateInfoEXT_sizeof));


const VkPhysicalDevicePrivateDataFeatures = new C.CStruct("VkPhysicalDevicePrivateDataFeatures", {
    sType: "u32("+callof(V.VkPhysicalDevicePrivateDataFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePrivateDataFeatures_pNext_offsetof)+")",
    privateData: "u32("+callof(V.VkPhysicalDevicePrivateDataFeatures_privateData_offsetof)+")",
}, callof(V.VkPhysicalDevicePrivateDataFeatures_sizeof));


const VkPhysicalDevicePrivateDataFeaturesEXT = new C.CStruct("VkPhysicalDevicePrivateDataFeaturesEXT", {

}, callof(V.VkPhysicalDevicePrivateDataFeaturesEXT_sizeof));


const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV = new C.CStruct("VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_pNext_offsetof)+")",
    maxGraphicsShaderGroupCount: "u32("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_maxGraphicsShaderGroupCount_offsetof)+")",
    maxIndirectSequenceCount: "u32("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_maxIndirectSequenceCount_offsetof)+")",
    maxIndirectCommandsTokenCount: "u32("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_maxIndirectCommandsTokenCount_offsetof)+")",
    maxIndirectCommandsStreamCount: "u32("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_maxIndirectCommandsStreamCount_offsetof)+")",
    maxIndirectCommandsTokenOffset: "u32("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_maxIndirectCommandsTokenOffset_offsetof)+")",
    maxIndirectCommandsStreamStride: "u32("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_maxIndirectCommandsStreamStride_offsetof)+")",
    minSequencesCountBufferOffsetAlignment: "u32("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_minSequencesCountBufferOffsetAlignment_offsetof)+")",
    minSequencesIndexBufferOffsetAlignment: "u32("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_minSequencesIndexBufferOffsetAlignment_offsetof)+")",
    minIndirectCommandsBufferOffsetAlignment: "u32("+callof(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_minIndirectCommandsBufferOffsetAlignment_offsetof)+")",
}, callof(V.VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_sizeof));


const VkPhysicalDeviceMultiDrawPropertiesEXT = new C.CStruct("VkPhysicalDeviceMultiDrawPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceMultiDrawPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMultiDrawPropertiesEXT_pNext_offsetof)+")",
    maxMultiDrawCount: "u32("+callof(V.VkPhysicalDeviceMultiDrawPropertiesEXT_maxMultiDrawCount_offsetof)+")",
}, callof(V.VkPhysicalDeviceMultiDrawPropertiesEXT_sizeof));


const VkGraphicsShaderGroupCreateInfoNV = new C.CStruct("VkGraphicsShaderGroupCreateInfoNV", {
    sType: "u32("+callof(V.VkGraphicsShaderGroupCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkGraphicsShaderGroupCreateInfoNV_pNext_offsetof)+")",
    stageCount: "u32("+callof(V.VkGraphicsShaderGroupCreateInfoNV_stageCount_offsetof)+")",
    pStages: "u64("+callof(V.VkGraphicsShaderGroupCreateInfoNV_pStages_offsetof)+")",
    pVertexInputState: "u64("+callof(V.VkGraphicsShaderGroupCreateInfoNV_pVertexInputState_offsetof)+")",
    pTessellationState: "u64("+callof(V.VkGraphicsShaderGroupCreateInfoNV_pTessellationState_offsetof)+")",
}, callof(V.VkGraphicsShaderGroupCreateInfoNV_sizeof));


const VkGraphicsPipelineShaderGroupsCreateInfoNV = new C.CStruct("VkGraphicsPipelineShaderGroupsCreateInfoNV", {
    sType: "u32("+callof(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_pNext_offsetof)+")",
    groupCount: "u32("+callof(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_groupCount_offsetof)+")",
    pGroups: "u64("+callof(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_pGroups_offsetof)+")",
    pipelineCount: "u32("+callof(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_pipelineCount_offsetof)+")",
    pPipelines: "u64("+callof(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_pPipelines_offsetof)+")",
}, callof(V.VkGraphicsPipelineShaderGroupsCreateInfoNV_sizeof));


const VkBindShaderGroupIndirectCommandNV = new C.CStruct("VkBindShaderGroupIndirectCommandNV", {
    groupIndex: "u32("+callof(V.VkBindShaderGroupIndirectCommandNV_groupIndex_offsetof)+")",
}, callof(V.VkBindShaderGroupIndirectCommandNV_sizeof));


const VkBindIndexBufferIndirectCommandNV = new C.CStruct("VkBindIndexBufferIndirectCommandNV", {
    bufferAddress: "u64("+callof(V.VkBindIndexBufferIndirectCommandNV_bufferAddress_offsetof)+")",
    size: "u32("+callof(V.VkBindIndexBufferIndirectCommandNV_size_offsetof)+")",
    indexType: "u32("+callof(V.VkBindIndexBufferIndirectCommandNV_indexType_offsetof)+")",
}, callof(V.VkBindIndexBufferIndirectCommandNV_sizeof));


const VkBindVertexBufferIndirectCommandNV = new C.CStruct("VkBindVertexBufferIndirectCommandNV", {
    bufferAddress: "u64("+callof(V.VkBindVertexBufferIndirectCommandNV_bufferAddress_offsetof)+")",
    size: "u32("+callof(V.VkBindVertexBufferIndirectCommandNV_size_offsetof)+")",
    stride: "u32("+callof(V.VkBindVertexBufferIndirectCommandNV_stride_offsetof)+")",
}, callof(V.VkBindVertexBufferIndirectCommandNV_sizeof));


const VkSetStateFlagsIndirectCommandNV = new C.CStruct("VkSetStateFlagsIndirectCommandNV", {
    data: "u32("+callof(V.VkSetStateFlagsIndirectCommandNV_data_offsetof)+")",
}, callof(V.VkSetStateFlagsIndirectCommandNV_sizeof));


const VkIndirectCommandsStreamNV = new C.CStruct("VkIndirectCommandsStreamNV", {
    buffer: "u64("+callof(V.VkIndirectCommandsStreamNV_buffer_offsetof)+")",
    offset: "u64("+callof(V.VkIndirectCommandsStreamNV_offset_offsetof)+")",
}, callof(V.VkIndirectCommandsStreamNV_sizeof));


const VkIndirectCommandsLayoutTokenNV = new C.CStruct("VkIndirectCommandsLayoutTokenNV", {
    sType: "u32("+callof(V.VkIndirectCommandsLayoutTokenNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkIndirectCommandsLayoutTokenNV_pNext_offsetof)+")",
    tokenType: "u32("+callof(V.VkIndirectCommandsLayoutTokenNV_tokenType_offsetof)+")",
    stream: "u32("+callof(V.VkIndirectCommandsLayoutTokenNV_stream_offsetof)+")",
    offset: "u32("+callof(V.VkIndirectCommandsLayoutTokenNV_offset_offsetof)+")",
    vertexBindingUnit: "u32("+callof(V.VkIndirectCommandsLayoutTokenNV_vertexBindingUnit_offsetof)+")",
    vertexDynamicStride: "u32("+callof(V.VkIndirectCommandsLayoutTokenNV_vertexDynamicStride_offsetof)+")",
    pushconstantPipelineLayout: "u64("+callof(V.VkIndirectCommandsLayoutTokenNV_pushconstantPipelineLayout_offsetof)+")",
    pushconstantShaderStageFlags: "u32("+callof(V.VkIndirectCommandsLayoutTokenNV_pushconstantShaderStageFlags_offsetof)+")",
    pushconstantOffset: "u32("+callof(V.VkIndirectCommandsLayoutTokenNV_pushconstantOffset_offsetof)+")",
    pushconstantSize: "u32("+callof(V.VkIndirectCommandsLayoutTokenNV_pushconstantSize_offsetof)+")",
    indirectStateFlags: "u32("+callof(V.VkIndirectCommandsLayoutTokenNV_indirectStateFlags_offsetof)+")",
    indexTypeCount: "u32("+callof(V.VkIndirectCommandsLayoutTokenNV_indexTypeCount_offsetof)+")",
    pIndexTypes: "u64("+callof(V.VkIndirectCommandsLayoutTokenNV_pIndexTypes_offsetof)+")",
    pIndexTypeValues: "u64("+callof(V.VkIndirectCommandsLayoutTokenNV_pIndexTypeValues_offsetof)+")",
}, callof(V.VkIndirectCommandsLayoutTokenNV_sizeof));


const VkIndirectCommandsLayoutCreateInfoNV = new C.CStruct("VkIndirectCommandsLayoutCreateInfoNV", {
    sType: "u32("+callof(V.VkIndirectCommandsLayoutCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkIndirectCommandsLayoutCreateInfoNV_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkIndirectCommandsLayoutCreateInfoNV_flags_offsetof)+")",
    pipelineBindPoint: "u32("+callof(V.VkIndirectCommandsLayoutCreateInfoNV_pipelineBindPoint_offsetof)+")",
    tokenCount: "u32("+callof(V.VkIndirectCommandsLayoutCreateInfoNV_tokenCount_offsetof)+")",
    pTokens: "u64("+callof(V.VkIndirectCommandsLayoutCreateInfoNV_pTokens_offsetof)+")",
    streamCount: "u32("+callof(V.VkIndirectCommandsLayoutCreateInfoNV_streamCount_offsetof)+")",
    pStreamStrides: "u64("+callof(V.VkIndirectCommandsLayoutCreateInfoNV_pStreamStrides_offsetof)+")",
}, callof(V.VkIndirectCommandsLayoutCreateInfoNV_sizeof));


const VkGeneratedCommandsInfoNV = new C.CStruct("VkGeneratedCommandsInfoNV", {
    sType: "u32("+callof(V.VkGeneratedCommandsInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkGeneratedCommandsInfoNV_pNext_offsetof)+")",
    pipelineBindPoint: "u32("+callof(V.VkGeneratedCommandsInfoNV_pipelineBindPoint_offsetof)+")",
    pipeline: "u64("+callof(V.VkGeneratedCommandsInfoNV_pipeline_offsetof)+")",
    indirectCommandsLayout: "u32("+callof(V.VkGeneratedCommandsInfoNV_indirectCommandsLayout_offsetof)+")",
    streamCount: "u32("+callof(V.VkGeneratedCommandsInfoNV_streamCount_offsetof)+")",
    pStreams: "u64("+callof(V.VkGeneratedCommandsInfoNV_pStreams_offsetof)+")",
    sequencesCount: "u32("+callof(V.VkGeneratedCommandsInfoNV_sequencesCount_offsetof)+")",
    preprocessBuffer: "u64("+callof(V.VkGeneratedCommandsInfoNV_preprocessBuffer_offsetof)+")",
    preprocessOffset: "u64("+callof(V.VkGeneratedCommandsInfoNV_preprocessOffset_offsetof)+")",
    preprocessSize: "u64("+callof(V.VkGeneratedCommandsInfoNV_preprocessSize_offsetof)+")",
    sequencesCountBuffer: "u64("+callof(V.VkGeneratedCommandsInfoNV_sequencesCountBuffer_offsetof)+")",
    sequencesCountOffset: "u64("+callof(V.VkGeneratedCommandsInfoNV_sequencesCountOffset_offsetof)+")",
    sequencesIndexBuffer: "u64("+callof(V.VkGeneratedCommandsInfoNV_sequencesIndexBuffer_offsetof)+")",
    sequencesIndexOffset: "u64("+callof(V.VkGeneratedCommandsInfoNV_sequencesIndexOffset_offsetof)+")",
}, callof(V.VkGeneratedCommandsInfoNV_sizeof));


const VkGeneratedCommandsMemoryRequirementsInfoNV = new C.CStruct("VkGeneratedCommandsMemoryRequirementsInfoNV", {
    sType: "u32("+callof(V.VkGeneratedCommandsMemoryRequirementsInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkGeneratedCommandsMemoryRequirementsInfoNV_pNext_offsetof)+")",
    pipelineBindPoint: "u32("+callof(V.VkGeneratedCommandsMemoryRequirementsInfoNV_pipelineBindPoint_offsetof)+")",
    pipeline: "u64("+callof(V.VkGeneratedCommandsMemoryRequirementsInfoNV_pipeline_offsetof)+")",
    indirectCommandsLayout: "u32("+callof(V.VkGeneratedCommandsMemoryRequirementsInfoNV_indirectCommandsLayout_offsetof)+")",
    maxSequencesCount: "u32("+callof(V.VkGeneratedCommandsMemoryRequirementsInfoNV_maxSequencesCount_offsetof)+")",
}, callof(V.VkGeneratedCommandsMemoryRequirementsInfoNV_sizeof));


const VkPhysicalDeviceFeatures2 = new C.CStruct("VkPhysicalDeviceFeatures2", {
    sType: "u32("+callof(V.VkPhysicalDeviceFeatures2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFeatures2_pNext_offsetof)+")",
    features: "u32("+callof(V.VkPhysicalDeviceFeatures2_features_offsetof)+")",
}, callof(V.VkPhysicalDeviceFeatures2_sizeof));


const VkPhysicalDeviceFeatures2KHR = new C.CStruct("VkPhysicalDeviceFeatures2KHR", {

}, callof(V.VkPhysicalDeviceFeatures2KHR_sizeof));


const VkPhysicalDeviceProperties2 = new C.CStruct("VkPhysicalDeviceProperties2", {
    sType: "u32("+callof(V.VkPhysicalDeviceProperties2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceProperties2_pNext_offsetof)+")",
    properties: "u32("+callof(V.VkPhysicalDeviceProperties2_properties_offsetof)+")",
}, callof(V.VkPhysicalDeviceProperties2_sizeof));


const VkPhysicalDeviceProperties2KHR = new C.CStruct("VkPhysicalDeviceProperties2KHR", {

}, callof(V.VkPhysicalDeviceProperties2KHR_sizeof));


const VkFormatProperties2 = new C.CStruct("VkFormatProperties2", {
    sType: "u32("+callof(V.VkFormatProperties2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkFormatProperties2_pNext_offsetof)+")",
    formatProperties: "u32("+callof(V.VkFormatProperties2_formatProperties_offsetof)+")",
}, callof(V.VkFormatProperties2_sizeof));


const VkFormatProperties2KHR = new C.CStruct("VkFormatProperties2KHR", {

}, callof(V.VkFormatProperties2KHR_sizeof));


const VkImageFormatProperties2 = new C.CStruct("VkImageFormatProperties2", {
    sType: "u32("+callof(V.VkImageFormatProperties2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageFormatProperties2_pNext_offsetof)+")",
    imageFormatProperties: "u32("+callof(V.VkImageFormatProperties2_imageFormatProperties_offsetof)+")",
}, callof(V.VkImageFormatProperties2_sizeof));


const VkImageFormatProperties2KHR = new C.CStruct("VkImageFormatProperties2KHR", {

}, callof(V.VkImageFormatProperties2KHR_sizeof));


const VkPhysicalDeviceImageFormatInfo2 = new C.CStruct("VkPhysicalDeviceImageFormatInfo2", {
    sType: "u32("+callof(V.VkPhysicalDeviceImageFormatInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceImageFormatInfo2_pNext_offsetof)+")",
    format: "u32("+callof(V.VkPhysicalDeviceImageFormatInfo2_format_offsetof)+")",
    type: "u32("+callof(V.VkPhysicalDeviceImageFormatInfo2_type_offsetof)+")",
    tiling: "u32("+callof(V.VkPhysicalDeviceImageFormatInfo2_tiling_offsetof)+")",
    usage: "u32("+callof(V.VkPhysicalDeviceImageFormatInfo2_usage_offsetof)+")",
    flags: "u32("+callof(V.VkPhysicalDeviceImageFormatInfo2_flags_offsetof)+")",
}, callof(V.VkPhysicalDeviceImageFormatInfo2_sizeof));


const VkPhysicalDeviceImageFormatInfo2KHR = new C.CStruct("VkPhysicalDeviceImageFormatInfo2KHR", {

}, callof(V.VkPhysicalDeviceImageFormatInfo2KHR_sizeof));


const VkQueueFamilyProperties2 = new C.CStruct("VkQueueFamilyProperties2", {
    sType: "u32("+callof(V.VkQueueFamilyProperties2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkQueueFamilyProperties2_pNext_offsetof)+")",
    queueFamilyProperties: "u32("+callof(V.VkQueueFamilyProperties2_queueFamilyProperties_offsetof)+")",
}, callof(V.VkQueueFamilyProperties2_sizeof));


const VkQueueFamilyProperties2KHR = new C.CStruct("VkQueueFamilyProperties2KHR", {

}, callof(V.VkQueueFamilyProperties2KHR_sizeof));


const VkPhysicalDeviceMemoryProperties2 = new C.CStruct("VkPhysicalDeviceMemoryProperties2", {
    sType: "u32("+callof(V.VkPhysicalDeviceMemoryProperties2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMemoryProperties2_pNext_offsetof)+")",
    memoryProperties: "u32("+callof(V.VkPhysicalDeviceMemoryProperties2_memoryProperties_offsetof)+")",
}, callof(V.VkPhysicalDeviceMemoryProperties2_sizeof));


const VkPhysicalDeviceMemoryProperties2KHR = new C.CStruct("VkPhysicalDeviceMemoryProperties2KHR", {

}, callof(V.VkPhysicalDeviceMemoryProperties2KHR_sizeof));


const VkSparseImageFormatProperties2 = new C.CStruct("VkSparseImageFormatProperties2", {
    sType: "u32("+callof(V.VkSparseImageFormatProperties2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSparseImageFormatProperties2_pNext_offsetof)+")",
    properties: "u32("+callof(V.VkSparseImageFormatProperties2_properties_offsetof)+")",
}, callof(V.VkSparseImageFormatProperties2_sizeof));


const VkSparseImageFormatProperties2KHR = new C.CStruct("VkSparseImageFormatProperties2KHR", {

}, callof(V.VkSparseImageFormatProperties2KHR_sizeof));


const VkPhysicalDeviceSparseImageFormatInfo2 = new C.CStruct("VkPhysicalDeviceSparseImageFormatInfo2", {
    sType: "u32("+callof(V.VkPhysicalDeviceSparseImageFormatInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSparseImageFormatInfo2_pNext_offsetof)+")",
    format: "u32("+callof(V.VkPhysicalDeviceSparseImageFormatInfo2_format_offsetof)+")",
    type: "u32("+callof(V.VkPhysicalDeviceSparseImageFormatInfo2_type_offsetof)+")",
    samples: "u32("+callof(V.VkPhysicalDeviceSparseImageFormatInfo2_samples_offsetof)+")",
    usage: "u32("+callof(V.VkPhysicalDeviceSparseImageFormatInfo2_usage_offsetof)+")",
    tiling: "u32("+callof(V.VkPhysicalDeviceSparseImageFormatInfo2_tiling_offsetof)+")",
}, callof(V.VkPhysicalDeviceSparseImageFormatInfo2_sizeof));


const VkPhysicalDeviceSparseImageFormatInfo2KHR = new C.CStruct("VkPhysicalDeviceSparseImageFormatInfo2KHR", {

}, callof(V.VkPhysicalDeviceSparseImageFormatInfo2KHR_sizeof));


const VkPhysicalDevicePushDescriptorPropertiesKHR = new C.CStruct("VkPhysicalDevicePushDescriptorPropertiesKHR", {
    sType: "u32("+callof(V.VkPhysicalDevicePushDescriptorPropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePushDescriptorPropertiesKHR_pNext_offsetof)+")",
    maxPushDescriptors: "u32("+callof(V.VkPhysicalDevicePushDescriptorPropertiesKHR_maxPushDescriptors_offsetof)+")",
}, callof(V.VkPhysicalDevicePushDescriptorPropertiesKHR_sizeof));


const VkConformanceVersion = new C.CStruct("VkConformanceVersion", {
    major: "u8("+callof(V.VkConformanceVersion_major_offsetof)+")",
    minor: "u8("+callof(V.VkConformanceVersion_minor_offsetof)+")",
    subminor: "u8("+callof(V.VkConformanceVersion_subminor_offsetof)+")",
    patch: "u8("+callof(V.VkConformanceVersion_patch_offsetof)+")",
}, callof(V.VkConformanceVersion_sizeof));


const VkConformanceVersionKHR = new C.CStruct("VkConformanceVersionKHR", {

}, callof(V.VkConformanceVersionKHR_sizeof));


const VkPhysicalDeviceDriverProperties = new C.CStruct("VkPhysicalDeviceDriverProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceDriverProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDriverProperties_pNext_offsetof)+")",
    driverID: "u32("+callof(V.VkPhysicalDeviceDriverProperties_driverID_offsetof)+")",
    driverName: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceDriverProperties_driverName_offsetof)+")",
    driverInfo: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceDriverProperties_driverInfo_offsetof)+")",
    conformanceVersion: "u32("+callof(V.VkPhysicalDeviceDriverProperties_conformanceVersion_offsetof)+")",
}, callof(V.VkPhysicalDeviceDriverProperties_sizeof));


const VkPhysicalDeviceDriverPropertiesKHR = new C.CStruct("VkPhysicalDeviceDriverPropertiesKHR", {

}, callof(V.VkPhysicalDeviceDriverPropertiesKHR_sizeof));


const VkPresentRegionsKHR = new C.CStruct("VkPresentRegionsKHR", {
    sType: "u32("+callof(V.VkPresentRegionsKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPresentRegionsKHR_pNext_offsetof)+")",
    swapchainCount: "u32("+callof(V.VkPresentRegionsKHR_swapchainCount_offsetof)+")",
    pRegions: "u64("+callof(V.VkPresentRegionsKHR_pRegions_offsetof)+")",
}, callof(V.VkPresentRegionsKHR_sizeof));


const VkPresentRegionKHR = new C.CStruct("VkPresentRegionKHR", {
    rectangleCount: "u32("+callof(V.VkPresentRegionKHR_rectangleCount_offsetof)+")",
    pRectangles: "u64("+callof(V.VkPresentRegionKHR_pRectangles_offsetof)+")",
}, callof(V.VkPresentRegionKHR_sizeof));


const VkRectLayerKHR = new C.CStruct("VkRectLayerKHR", {
    offset: "VkOffset2D("+callof(V.VkRectLayerKHR_offset_offsetof)+")",
    extent: "VkExtent2D("+callof(V.VkRectLayerKHR_extent_offsetof)+")",
    layer: "u32("+callof(V.VkRectLayerKHR_layer_offsetof)+")",
}, callof(V.VkRectLayerKHR_sizeof));


const VkPhysicalDeviceVariablePointersFeatures = new C.CStruct("VkPhysicalDeviceVariablePointersFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceVariablePointersFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceVariablePointersFeatures_pNext_offsetof)+")",
    variablePointersStorageBuffer: "u32("+callof(V.VkPhysicalDeviceVariablePointersFeatures_variablePointersStorageBuffer_offsetof)+")",
    variablePointers: "u32("+callof(V.VkPhysicalDeviceVariablePointersFeatures_variablePointers_offsetof)+")",
}, callof(V.VkPhysicalDeviceVariablePointersFeatures_sizeof));


const VkPhysicalDeviceVariablePointersFeaturesKHR = new C.CStruct("VkPhysicalDeviceVariablePointersFeaturesKHR", {

}, callof(V.VkPhysicalDeviceVariablePointersFeaturesKHR_sizeof));


const VkPhysicalDeviceVariablePointerFeaturesKHR = new C.CStruct("VkPhysicalDeviceVariablePointerFeaturesKHR", {

}, callof(V.VkPhysicalDeviceVariablePointerFeaturesKHR_sizeof));


const VkPhysicalDeviceVariablePointerFeatures = new C.CStruct("VkPhysicalDeviceVariablePointerFeatures", {

}, callof(V.VkPhysicalDeviceVariablePointerFeatures_sizeof));


const VkExternalMemoryProperties = new C.CStruct("VkExternalMemoryProperties", {
    externalMemoryFeatures: "u32("+callof(V.VkExternalMemoryProperties_externalMemoryFeatures_offsetof)+")",
    exportFromImportedHandleTypes: "u32("+callof(V.VkExternalMemoryProperties_exportFromImportedHandleTypes_offsetof)+")",
    compatibleHandleTypes: "u32("+callof(V.VkExternalMemoryProperties_compatibleHandleTypes_offsetof)+")",
}, callof(V.VkExternalMemoryProperties_sizeof));


const VkExternalMemoryPropertiesKHR = new C.CStruct("VkExternalMemoryPropertiesKHR", {

}, callof(V.VkExternalMemoryPropertiesKHR_sizeof));


const VkPhysicalDeviceExternalImageFormatInfo = new C.CStruct("VkPhysicalDeviceExternalImageFormatInfo", {
    sType: "u32("+callof(V.VkPhysicalDeviceExternalImageFormatInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceExternalImageFormatInfo_pNext_offsetof)+")",
    handleType: "u32("+callof(V.VkPhysicalDeviceExternalImageFormatInfo_handleType_offsetof)+")",
}, callof(V.VkPhysicalDeviceExternalImageFormatInfo_sizeof));


const VkPhysicalDeviceExternalImageFormatInfoKHR = new C.CStruct("VkPhysicalDeviceExternalImageFormatInfoKHR", {

}, callof(V.VkPhysicalDeviceExternalImageFormatInfoKHR_sizeof));


const VkExternalImageFormatProperties = new C.CStruct("VkExternalImageFormatProperties", {
    sType: "u32("+callof(V.VkExternalImageFormatProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExternalImageFormatProperties_pNext_offsetof)+")",
    externalMemoryProperties: "u32("+callof(V.VkExternalImageFormatProperties_externalMemoryProperties_offsetof)+")",
}, callof(V.VkExternalImageFormatProperties_sizeof));


const VkExternalImageFormatPropertiesKHR = new C.CStruct("VkExternalImageFormatPropertiesKHR", {

}, callof(V.VkExternalImageFormatPropertiesKHR_sizeof));


const VkPhysicalDeviceExternalBufferInfo = new C.CStruct("VkPhysicalDeviceExternalBufferInfo", {
    sType: "u32("+callof(V.VkPhysicalDeviceExternalBufferInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceExternalBufferInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPhysicalDeviceExternalBufferInfo_flags_offsetof)+")",
    usage: "u32("+callof(V.VkPhysicalDeviceExternalBufferInfo_usage_offsetof)+")",
    handleType: "u32("+callof(V.VkPhysicalDeviceExternalBufferInfo_handleType_offsetof)+")",
}, callof(V.VkPhysicalDeviceExternalBufferInfo_sizeof));


const VkPhysicalDeviceExternalBufferInfoKHR = new C.CStruct("VkPhysicalDeviceExternalBufferInfoKHR", {

}, callof(V.VkPhysicalDeviceExternalBufferInfoKHR_sizeof));


const VkExternalBufferProperties = new C.CStruct("VkExternalBufferProperties", {
    sType: "u32("+callof(V.VkExternalBufferProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExternalBufferProperties_pNext_offsetof)+")",
    externalMemoryProperties: "u32("+callof(V.VkExternalBufferProperties_externalMemoryProperties_offsetof)+")",
}, callof(V.VkExternalBufferProperties_sizeof));


const VkExternalBufferPropertiesKHR = new C.CStruct("VkExternalBufferPropertiesKHR", {

}, callof(V.VkExternalBufferPropertiesKHR_sizeof));


const VkPhysicalDeviceIDProperties = new C.CStruct("VkPhysicalDeviceIDProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceIDProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceIDProperties_pNext_offsetof)+")",
    deviceUUID: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceIDProperties_deviceUUID_offsetof)+")",
    driverUUID: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceIDProperties_driverUUID_offsetof)+")",
    deviceLUID: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceIDProperties_deviceLUID_offsetof)+")",
    deviceNodeMask: "u32("+callof(V.VkPhysicalDeviceIDProperties_deviceNodeMask_offsetof)+")",
    deviceLUIDValid: "u32("+callof(V.VkPhysicalDeviceIDProperties_deviceLUIDValid_offsetof)+")",
}, callof(V.VkPhysicalDeviceIDProperties_sizeof));


const VkPhysicalDeviceIDPropertiesKHR = new C.CStruct("VkPhysicalDeviceIDPropertiesKHR", {

}, callof(V.VkPhysicalDeviceIDPropertiesKHR_sizeof));


const VkExternalMemoryImageCreateInfo = new C.CStruct("VkExternalMemoryImageCreateInfo", {
    sType: "u32("+callof(V.VkExternalMemoryImageCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExternalMemoryImageCreateInfo_pNext_offsetof)+")",
    handleTypes: "u32("+callof(V.VkExternalMemoryImageCreateInfo_handleTypes_offsetof)+")",
}, callof(V.VkExternalMemoryImageCreateInfo_sizeof));


const VkExternalMemoryImageCreateInfoKHR = new C.CStruct("VkExternalMemoryImageCreateInfoKHR", {

}, callof(V.VkExternalMemoryImageCreateInfoKHR_sizeof));


const VkExternalMemoryBufferCreateInfo = new C.CStruct("VkExternalMemoryBufferCreateInfo", {
    sType: "u32("+callof(V.VkExternalMemoryBufferCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExternalMemoryBufferCreateInfo_pNext_offsetof)+")",
    handleTypes: "u32("+callof(V.VkExternalMemoryBufferCreateInfo_handleTypes_offsetof)+")",
}, callof(V.VkExternalMemoryBufferCreateInfo_sizeof));


const VkExternalMemoryBufferCreateInfoKHR = new C.CStruct("VkExternalMemoryBufferCreateInfoKHR", {

}, callof(V.VkExternalMemoryBufferCreateInfoKHR_sizeof));


const VkExportMemoryAllocateInfo = new C.CStruct("VkExportMemoryAllocateInfo", {
    sType: "u32("+callof(V.VkExportMemoryAllocateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportMemoryAllocateInfo_pNext_offsetof)+")",
    handleTypes: "u32("+callof(V.VkExportMemoryAllocateInfo_handleTypes_offsetof)+")",
}, callof(V.VkExportMemoryAllocateInfo_sizeof));


const VkExportMemoryAllocateInfoKHR = new C.CStruct("VkExportMemoryAllocateInfoKHR", {

}, callof(V.VkExportMemoryAllocateInfoKHR_sizeof));


const VkImportMemoryWin32HandleInfoKHR = new C.CStruct("VkImportMemoryWin32HandleInfoKHR", {
    sType: "u32("+callof(V.VkImportMemoryWin32HandleInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportMemoryWin32HandleInfoKHR_pNext_offsetof)+")",
    handleType: "u32("+callof(V.VkImportMemoryWin32HandleInfoKHR_handleType_offsetof)+")",
    handle: "u64("+callof(V.VkImportMemoryWin32HandleInfoKHR_handle_offsetof)+")",
    name: "u32("+callof(V.VkImportMemoryWin32HandleInfoKHR_name_offsetof)+")",
}, callof(V.VkImportMemoryWin32HandleInfoKHR_sizeof));


const VkExportMemoryWin32HandleInfoKHR = new C.CStruct("VkExportMemoryWin32HandleInfoKHR", {
    sType: "u32("+callof(V.VkExportMemoryWin32HandleInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportMemoryWin32HandleInfoKHR_pNext_offsetof)+")",
    pAttributes: "u64("+callof(V.VkExportMemoryWin32HandleInfoKHR_pAttributes_offsetof)+")",
    dwAccess: "u32("+callof(V.VkExportMemoryWin32HandleInfoKHR_dwAccess_offsetof)+")",
    name: "u32("+callof(V.VkExportMemoryWin32HandleInfoKHR_name_offsetof)+")",
}, callof(V.VkExportMemoryWin32HandleInfoKHR_sizeof));


const VkImportMemoryZirconHandleInfoFUCHSIA = new C.CStruct("VkImportMemoryZirconHandleInfoFUCHSIA", {
    sType: "u32("+callof(V.VkImportMemoryZirconHandleInfoFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportMemoryZirconHandleInfoFUCHSIA_pNext_offsetof)+")",
    handleType: "u32("+callof(V.VkImportMemoryZirconHandleInfoFUCHSIA_handleType_offsetof)+")",
    handle: "u32("+callof(V.VkImportMemoryZirconHandleInfoFUCHSIA_handle_offsetof)+")",
}, callof(V.VkImportMemoryZirconHandleInfoFUCHSIA_sizeof));


const VkMemoryZirconHandlePropertiesFUCHSIA = new C.CStruct("VkMemoryZirconHandlePropertiesFUCHSIA", {
    sType: "u32("+callof(V.VkMemoryZirconHandlePropertiesFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryZirconHandlePropertiesFUCHSIA_pNext_offsetof)+")",
    memoryTypeBits: "u32("+callof(V.VkMemoryZirconHandlePropertiesFUCHSIA_memoryTypeBits_offsetof)+")",
}, callof(V.VkMemoryZirconHandlePropertiesFUCHSIA_sizeof));


const VkMemoryGetZirconHandleInfoFUCHSIA = new C.CStruct("VkMemoryGetZirconHandleInfoFUCHSIA", {
    sType: "u32("+callof(V.VkMemoryGetZirconHandleInfoFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryGetZirconHandleInfoFUCHSIA_pNext_offsetof)+")",
    memory: "u64("+callof(V.VkMemoryGetZirconHandleInfoFUCHSIA_memory_offsetof)+")",
    handleType: "u32("+callof(V.VkMemoryGetZirconHandleInfoFUCHSIA_handleType_offsetof)+")",
}, callof(V.VkMemoryGetZirconHandleInfoFUCHSIA_sizeof));


const VkMemoryWin32HandlePropertiesKHR = new C.CStruct("VkMemoryWin32HandlePropertiesKHR", {
    sType: "u32("+callof(V.VkMemoryWin32HandlePropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryWin32HandlePropertiesKHR_pNext_offsetof)+")",
    memoryTypeBits: "u32("+callof(V.VkMemoryWin32HandlePropertiesKHR_memoryTypeBits_offsetof)+")",
}, callof(V.VkMemoryWin32HandlePropertiesKHR_sizeof));


const VkMemoryGetWin32HandleInfoKHR = new C.CStruct("VkMemoryGetWin32HandleInfoKHR", {
    sType: "u32("+callof(V.VkMemoryGetWin32HandleInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryGetWin32HandleInfoKHR_pNext_offsetof)+")",
    memory: "u64("+callof(V.VkMemoryGetWin32HandleInfoKHR_memory_offsetof)+")",
    handleType: "u32("+callof(V.VkMemoryGetWin32HandleInfoKHR_handleType_offsetof)+")",
}, callof(V.VkMemoryGetWin32HandleInfoKHR_sizeof));


const VkImportMemoryFdInfoKHR = new C.CStruct("VkImportMemoryFdInfoKHR", {
    sType: "u32("+callof(V.VkImportMemoryFdInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportMemoryFdInfoKHR_pNext_offsetof)+")",
    handleType: "u32("+callof(V.VkImportMemoryFdInfoKHR_handleType_offsetof)+")",
    fd: "u32("+callof(V.VkImportMemoryFdInfoKHR_fd_offsetof)+")",
}, callof(V.VkImportMemoryFdInfoKHR_sizeof));


const VkMemoryFdPropertiesKHR = new C.CStruct("VkMemoryFdPropertiesKHR", {
    sType: "u32("+callof(V.VkMemoryFdPropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryFdPropertiesKHR_pNext_offsetof)+")",
    memoryTypeBits: "u32("+callof(V.VkMemoryFdPropertiesKHR_memoryTypeBits_offsetof)+")",
}, callof(V.VkMemoryFdPropertiesKHR_sizeof));


const VkMemoryGetFdInfoKHR = new C.CStruct("VkMemoryGetFdInfoKHR", {
    sType: "u32("+callof(V.VkMemoryGetFdInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryGetFdInfoKHR_pNext_offsetof)+")",
    memory: "u64("+callof(V.VkMemoryGetFdInfoKHR_memory_offsetof)+")",
    handleType: "u32("+callof(V.VkMemoryGetFdInfoKHR_handleType_offsetof)+")",
}, callof(V.VkMemoryGetFdInfoKHR_sizeof));


const VkWin32KeyedMutexAcquireReleaseInfoKHR = new C.CStruct("VkWin32KeyedMutexAcquireReleaseInfoKHR", {
    sType: "u32("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_pNext_offsetof)+")",
    acquireCount: "u32("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_acquireCount_offsetof)+")",
    pAcquireSyncs: "u64("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_pAcquireSyncs_offsetof)+")",
    pAcquireKeys: "u64("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_pAcquireKeys_offsetof)+")",
    pAcquireTimeouts: "u64("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_pAcquireTimeouts_offsetof)+")",
    releaseCount: "u32("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_releaseCount_offsetof)+")",
    pReleaseSyncs: "u64("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_pReleaseSyncs_offsetof)+")",
    pReleaseKeys: "u64("+callof(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_pReleaseKeys_offsetof)+")",
}, callof(V.VkWin32KeyedMutexAcquireReleaseInfoKHR_sizeof));


const VkPhysicalDeviceExternalSemaphoreInfo = new C.CStruct("VkPhysicalDeviceExternalSemaphoreInfo", {
    sType: "u32("+callof(V.VkPhysicalDeviceExternalSemaphoreInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceExternalSemaphoreInfo_pNext_offsetof)+")",
    handleType: "u32("+callof(V.VkPhysicalDeviceExternalSemaphoreInfo_handleType_offsetof)+")",
}, callof(V.VkPhysicalDeviceExternalSemaphoreInfo_sizeof));


const VkPhysicalDeviceExternalSemaphoreInfoKHR = new C.CStruct("VkPhysicalDeviceExternalSemaphoreInfoKHR", {

}, callof(V.VkPhysicalDeviceExternalSemaphoreInfoKHR_sizeof));


const VkExternalSemaphoreProperties = new C.CStruct("VkExternalSemaphoreProperties", {
    sType: "u32("+callof(V.VkExternalSemaphoreProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExternalSemaphoreProperties_pNext_offsetof)+")",
    exportFromImportedHandleTypes: "u32("+callof(V.VkExternalSemaphoreProperties_exportFromImportedHandleTypes_offsetof)+")",
    compatibleHandleTypes: "u32("+callof(V.VkExternalSemaphoreProperties_compatibleHandleTypes_offsetof)+")",
    externalSemaphoreFeatures: "u32("+callof(V.VkExternalSemaphoreProperties_externalSemaphoreFeatures_offsetof)+")",
}, callof(V.VkExternalSemaphoreProperties_sizeof));


const VkExternalSemaphorePropertiesKHR = new C.CStruct("VkExternalSemaphorePropertiesKHR", {

}, callof(V.VkExternalSemaphorePropertiesKHR_sizeof));


const VkExportSemaphoreCreateInfo = new C.CStruct("VkExportSemaphoreCreateInfo", {
    sType: "u32("+callof(V.VkExportSemaphoreCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportSemaphoreCreateInfo_pNext_offsetof)+")",
    handleTypes: "u32("+callof(V.VkExportSemaphoreCreateInfo_handleTypes_offsetof)+")",
}, callof(V.VkExportSemaphoreCreateInfo_sizeof));


const VkExportSemaphoreCreateInfoKHR = new C.CStruct("VkExportSemaphoreCreateInfoKHR", {

}, callof(V.VkExportSemaphoreCreateInfoKHR_sizeof));


const VkImportSemaphoreWin32HandleInfoKHR = new C.CStruct("VkImportSemaphoreWin32HandleInfoKHR", {
    sType: "u32("+callof(V.VkImportSemaphoreWin32HandleInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportSemaphoreWin32HandleInfoKHR_pNext_offsetof)+")",
    semaphore: "u64("+callof(V.VkImportSemaphoreWin32HandleInfoKHR_semaphore_offsetof)+")",
    flags: "u32("+callof(V.VkImportSemaphoreWin32HandleInfoKHR_flags_offsetof)+")",
    handleType: "u32("+callof(V.VkImportSemaphoreWin32HandleInfoKHR_handleType_offsetof)+")",
    handle: "u64("+callof(V.VkImportSemaphoreWin32HandleInfoKHR_handle_offsetof)+")",
    name: "u32("+callof(V.VkImportSemaphoreWin32HandleInfoKHR_name_offsetof)+")",
}, callof(V.VkImportSemaphoreWin32HandleInfoKHR_sizeof));


const VkExportSemaphoreWin32HandleInfoKHR = new C.CStruct("VkExportSemaphoreWin32HandleInfoKHR", {
    sType: "u32("+callof(V.VkExportSemaphoreWin32HandleInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportSemaphoreWin32HandleInfoKHR_pNext_offsetof)+")",
    pAttributes: "u64("+callof(V.VkExportSemaphoreWin32HandleInfoKHR_pAttributes_offsetof)+")",
    dwAccess: "u32("+callof(V.VkExportSemaphoreWin32HandleInfoKHR_dwAccess_offsetof)+")",
    name: "u32("+callof(V.VkExportSemaphoreWin32HandleInfoKHR_name_offsetof)+")",
}, callof(V.VkExportSemaphoreWin32HandleInfoKHR_sizeof));


const VkD3D12FenceSubmitInfoKHR = new C.CStruct("VkD3D12FenceSubmitInfoKHR", {
    sType: "u32("+callof(V.VkD3D12FenceSubmitInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkD3D12FenceSubmitInfoKHR_pNext_offsetof)+")",
    waitSemaphoreValuesCount: "u32("+callof(V.VkD3D12FenceSubmitInfoKHR_waitSemaphoreValuesCount_offsetof)+")",
    pWaitSemaphoreValues: "u64("+callof(V.VkD3D12FenceSubmitInfoKHR_pWaitSemaphoreValues_offsetof)+")",
    signalSemaphoreValuesCount: "u32("+callof(V.VkD3D12FenceSubmitInfoKHR_signalSemaphoreValuesCount_offsetof)+")",
    pSignalSemaphoreValues: "u64("+callof(V.VkD3D12FenceSubmitInfoKHR_pSignalSemaphoreValues_offsetof)+")",
}, callof(V.VkD3D12FenceSubmitInfoKHR_sizeof));


const VkSemaphoreGetWin32HandleInfoKHR = new C.CStruct("VkSemaphoreGetWin32HandleInfoKHR", {
    sType: "u32("+callof(V.VkSemaphoreGetWin32HandleInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSemaphoreGetWin32HandleInfoKHR_pNext_offsetof)+")",
    semaphore: "u64("+callof(V.VkSemaphoreGetWin32HandleInfoKHR_semaphore_offsetof)+")",
    handleType: "u32("+callof(V.VkSemaphoreGetWin32HandleInfoKHR_handleType_offsetof)+")",
}, callof(V.VkSemaphoreGetWin32HandleInfoKHR_sizeof));


const VkImportSemaphoreFdInfoKHR = new C.CStruct("VkImportSemaphoreFdInfoKHR", {
    sType: "u32("+callof(V.VkImportSemaphoreFdInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportSemaphoreFdInfoKHR_pNext_offsetof)+")",
    semaphore: "u64("+callof(V.VkImportSemaphoreFdInfoKHR_semaphore_offsetof)+")",
    flags: "u32("+callof(V.VkImportSemaphoreFdInfoKHR_flags_offsetof)+")",
    handleType: "u32("+callof(V.VkImportSemaphoreFdInfoKHR_handleType_offsetof)+")",
    fd: "u32("+callof(V.VkImportSemaphoreFdInfoKHR_fd_offsetof)+")",
}, callof(V.VkImportSemaphoreFdInfoKHR_sizeof));


const VkSemaphoreGetFdInfoKHR = new C.CStruct("VkSemaphoreGetFdInfoKHR", {
    sType: "u32("+callof(V.VkSemaphoreGetFdInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSemaphoreGetFdInfoKHR_pNext_offsetof)+")",
    semaphore: "u64("+callof(V.VkSemaphoreGetFdInfoKHR_semaphore_offsetof)+")",
    handleType: "u32("+callof(V.VkSemaphoreGetFdInfoKHR_handleType_offsetof)+")",
}, callof(V.VkSemaphoreGetFdInfoKHR_sizeof));


const VkImportSemaphoreZirconHandleInfoFUCHSIA = new C.CStruct("VkImportSemaphoreZirconHandleInfoFUCHSIA", {
    sType: "u32("+callof(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_pNext_offsetof)+")",
    semaphore: "u64("+callof(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_semaphore_offsetof)+")",
    flags: "u32("+callof(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_flags_offsetof)+")",
    handleType: "u32("+callof(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_handleType_offsetof)+")",
    zirconHandle: "u32("+callof(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_zirconHandle_offsetof)+")",
}, callof(V.VkImportSemaphoreZirconHandleInfoFUCHSIA_sizeof));


const VkSemaphoreGetZirconHandleInfoFUCHSIA = new C.CStruct("VkSemaphoreGetZirconHandleInfoFUCHSIA", {
    sType: "u32("+callof(V.VkSemaphoreGetZirconHandleInfoFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSemaphoreGetZirconHandleInfoFUCHSIA_pNext_offsetof)+")",
    semaphore: "u64("+callof(V.VkSemaphoreGetZirconHandleInfoFUCHSIA_semaphore_offsetof)+")",
    handleType: "u32("+callof(V.VkSemaphoreGetZirconHandleInfoFUCHSIA_handleType_offsetof)+")",
}, callof(V.VkSemaphoreGetZirconHandleInfoFUCHSIA_sizeof));


const VkPhysicalDeviceExternalFenceInfo = new C.CStruct("VkPhysicalDeviceExternalFenceInfo", {
    sType: "u32("+callof(V.VkPhysicalDeviceExternalFenceInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceExternalFenceInfo_pNext_offsetof)+")",
    handleType: "u32("+callof(V.VkPhysicalDeviceExternalFenceInfo_handleType_offsetof)+")",
}, callof(V.VkPhysicalDeviceExternalFenceInfo_sizeof));


const VkPhysicalDeviceExternalFenceInfoKHR = new C.CStruct("VkPhysicalDeviceExternalFenceInfoKHR", {

}, callof(V.VkPhysicalDeviceExternalFenceInfoKHR_sizeof));


const VkExternalFenceProperties = new C.CStruct("VkExternalFenceProperties", {
    sType: "u32("+callof(V.VkExternalFenceProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExternalFenceProperties_pNext_offsetof)+")",
    exportFromImportedHandleTypes: "u32("+callof(V.VkExternalFenceProperties_exportFromImportedHandleTypes_offsetof)+")",
    compatibleHandleTypes: "u32("+callof(V.VkExternalFenceProperties_compatibleHandleTypes_offsetof)+")",
    externalFenceFeatures: "u32("+callof(V.VkExternalFenceProperties_externalFenceFeatures_offsetof)+")",
}, callof(V.VkExternalFenceProperties_sizeof));


const VkExternalFencePropertiesKHR = new C.CStruct("VkExternalFencePropertiesKHR", {

}, callof(V.VkExternalFencePropertiesKHR_sizeof));


const VkExportFenceCreateInfo = new C.CStruct("VkExportFenceCreateInfo", {
    sType: "u32("+callof(V.VkExportFenceCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportFenceCreateInfo_pNext_offsetof)+")",
    handleTypes: "u32("+callof(V.VkExportFenceCreateInfo_handleTypes_offsetof)+")",
}, callof(V.VkExportFenceCreateInfo_sizeof));


const VkExportFenceCreateInfoKHR = new C.CStruct("VkExportFenceCreateInfoKHR", {

}, callof(V.VkExportFenceCreateInfoKHR_sizeof));


const VkImportFenceWin32HandleInfoKHR = new C.CStruct("VkImportFenceWin32HandleInfoKHR", {
    sType: "u32("+callof(V.VkImportFenceWin32HandleInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportFenceWin32HandleInfoKHR_pNext_offsetof)+")",
    fence: "u32("+callof(V.VkImportFenceWin32HandleInfoKHR_fence_offsetof)+")",
    flags: "u32("+callof(V.VkImportFenceWin32HandleInfoKHR_flags_offsetof)+")",
    handleType: "u32("+callof(V.VkImportFenceWin32HandleInfoKHR_handleType_offsetof)+")",
    handle: "u64("+callof(V.VkImportFenceWin32HandleInfoKHR_handle_offsetof)+")",
    name: "u32("+callof(V.VkImportFenceWin32HandleInfoKHR_name_offsetof)+")",
}, callof(V.VkImportFenceWin32HandleInfoKHR_sizeof));


const VkExportFenceWin32HandleInfoKHR = new C.CStruct("VkExportFenceWin32HandleInfoKHR", {
    sType: "u32("+callof(V.VkExportFenceWin32HandleInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportFenceWin32HandleInfoKHR_pNext_offsetof)+")",
    pAttributes: "u64("+callof(V.VkExportFenceWin32HandleInfoKHR_pAttributes_offsetof)+")",
    dwAccess: "u32("+callof(V.VkExportFenceWin32HandleInfoKHR_dwAccess_offsetof)+")",
    name: "u32("+callof(V.VkExportFenceWin32HandleInfoKHR_name_offsetof)+")",
}, callof(V.VkExportFenceWin32HandleInfoKHR_sizeof));


const VkFenceGetWin32HandleInfoKHR = new C.CStruct("VkFenceGetWin32HandleInfoKHR", {
    sType: "u32("+callof(V.VkFenceGetWin32HandleInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkFenceGetWin32HandleInfoKHR_pNext_offsetof)+")",
    fence: "u32("+callof(V.VkFenceGetWin32HandleInfoKHR_fence_offsetof)+")",
    handleType: "u32("+callof(V.VkFenceGetWin32HandleInfoKHR_handleType_offsetof)+")",
}, callof(V.VkFenceGetWin32HandleInfoKHR_sizeof));


const VkImportFenceFdInfoKHR = new C.CStruct("VkImportFenceFdInfoKHR", {
    sType: "u32("+callof(V.VkImportFenceFdInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportFenceFdInfoKHR_pNext_offsetof)+")",
    fence: "u32("+callof(V.VkImportFenceFdInfoKHR_fence_offsetof)+")",
    flags: "u32("+callof(V.VkImportFenceFdInfoKHR_flags_offsetof)+")",
    handleType: "u32("+callof(V.VkImportFenceFdInfoKHR_handleType_offsetof)+")",
    fd: "u32("+callof(V.VkImportFenceFdInfoKHR_fd_offsetof)+")",
}, callof(V.VkImportFenceFdInfoKHR_sizeof));


const VkFenceGetFdInfoKHR = new C.CStruct("VkFenceGetFdInfoKHR", {
    sType: "u32("+callof(V.VkFenceGetFdInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkFenceGetFdInfoKHR_pNext_offsetof)+")",
    fence: "u32("+callof(V.VkFenceGetFdInfoKHR_fence_offsetof)+")",
    handleType: "u32("+callof(V.VkFenceGetFdInfoKHR_handleType_offsetof)+")",
}, callof(V.VkFenceGetFdInfoKHR_sizeof));


const VkPhysicalDeviceMultiviewFeatures = new C.CStruct("VkPhysicalDeviceMultiviewFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceMultiviewFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMultiviewFeatures_pNext_offsetof)+")",
    multiview: "u32("+callof(V.VkPhysicalDeviceMultiviewFeatures_multiview_offsetof)+")",
    multiviewGeometryShader: "u32("+callof(V.VkPhysicalDeviceMultiviewFeatures_multiviewGeometryShader_offsetof)+")",
    multiviewTessellationShader: "u32("+callof(V.VkPhysicalDeviceMultiviewFeatures_multiviewTessellationShader_offsetof)+")",
}, callof(V.VkPhysicalDeviceMultiviewFeatures_sizeof));


const VkPhysicalDeviceMultiviewFeaturesKHR = new C.CStruct("VkPhysicalDeviceMultiviewFeaturesKHR", {

}, callof(V.VkPhysicalDeviceMultiviewFeaturesKHR_sizeof));


const VkPhysicalDeviceMultiviewProperties = new C.CStruct("VkPhysicalDeviceMultiviewProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceMultiviewProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMultiviewProperties_pNext_offsetof)+")",
    maxMultiviewViewCount: "u32("+callof(V.VkPhysicalDeviceMultiviewProperties_maxMultiviewViewCount_offsetof)+")",
    maxMultiviewInstanceIndex: "u32("+callof(V.VkPhysicalDeviceMultiviewProperties_maxMultiviewInstanceIndex_offsetof)+")",
}, callof(V.VkPhysicalDeviceMultiviewProperties_sizeof));


const VkPhysicalDeviceMultiviewPropertiesKHR = new C.CStruct("VkPhysicalDeviceMultiviewPropertiesKHR", {

}, callof(V.VkPhysicalDeviceMultiviewPropertiesKHR_sizeof));


const VkRenderPassMultiviewCreateInfo = new C.CStruct("VkRenderPassMultiviewCreateInfo", {
    sType: "u32("+callof(V.VkRenderPassMultiviewCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderPassMultiviewCreateInfo_pNext_offsetof)+")",
    subpassCount: "u32("+callof(V.VkRenderPassMultiviewCreateInfo_subpassCount_offsetof)+")",
    pViewMasks: "u64("+callof(V.VkRenderPassMultiviewCreateInfo_pViewMasks_offsetof)+")",
    dependencyCount: "u32("+callof(V.VkRenderPassMultiviewCreateInfo_dependencyCount_offsetof)+")",
    pViewOffsets: "u64("+callof(V.VkRenderPassMultiviewCreateInfo_pViewOffsets_offsetof)+")",
    correlationMaskCount: "u32("+callof(V.VkRenderPassMultiviewCreateInfo_correlationMaskCount_offsetof)+")",
    pCorrelationMasks: "u64("+callof(V.VkRenderPassMultiviewCreateInfo_pCorrelationMasks_offsetof)+")",
}, callof(V.VkRenderPassMultiviewCreateInfo_sizeof));


const VkRenderPassMultiviewCreateInfoKHR = new C.CStruct("VkRenderPassMultiviewCreateInfoKHR", {

}, callof(V.VkRenderPassMultiviewCreateInfoKHR_sizeof));


const VkSurfaceCapabilities2EXT = new C.CStruct("VkSurfaceCapabilities2EXT", {
    sType: "u32("+callof(V.VkSurfaceCapabilities2EXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSurfaceCapabilities2EXT_pNext_offsetof)+")",
    minImageCount: "u32("+callof(V.VkSurfaceCapabilities2EXT_minImageCount_offsetof)+")",
    maxImageCount: "u32("+callof(V.VkSurfaceCapabilities2EXT_maxImageCount_offsetof)+")",
    currentExtent: "VkExtent2D("+callof(V.VkSurfaceCapabilities2EXT_currentExtent_offsetof)+")",
    minImageExtent: "VkExtent2D("+callof(V.VkSurfaceCapabilities2EXT_minImageExtent_offsetof)+")",
    maxImageExtent: "VkExtent2D("+callof(V.VkSurfaceCapabilities2EXT_maxImageExtent_offsetof)+")",
    maxImageArrayLayers: "u32("+callof(V.VkSurfaceCapabilities2EXT_maxImageArrayLayers_offsetof)+")",
    supportedTransforms: "u32("+callof(V.VkSurfaceCapabilities2EXT_supportedTransforms_offsetof)+")",
    currentTransform: "u32("+callof(V.VkSurfaceCapabilities2EXT_currentTransform_offsetof)+")",
    supportedCompositeAlpha: "u32("+callof(V.VkSurfaceCapabilities2EXT_supportedCompositeAlpha_offsetof)+")",
    supportedUsageFlags: "u32("+callof(V.VkSurfaceCapabilities2EXT_supportedUsageFlags_offsetof)+")",
    supportedSurfaceCounters: "u32("+callof(V.VkSurfaceCapabilities2EXT_supportedSurfaceCounters_offsetof)+")",
}, callof(V.VkSurfaceCapabilities2EXT_sizeof));


const VkDisplayPowerInfoEXT = new C.CStruct("VkDisplayPowerInfoEXT", {
    sType: "u32("+callof(V.VkDisplayPowerInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDisplayPowerInfoEXT_pNext_offsetof)+")",
    powerState: "u32("+callof(V.VkDisplayPowerInfoEXT_powerState_offsetof)+")",
}, callof(V.VkDisplayPowerInfoEXT_sizeof));


const VkDeviceEventInfoEXT = new C.CStruct("VkDeviceEventInfoEXT", {
    sType: "u32("+callof(V.VkDeviceEventInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceEventInfoEXT_pNext_offsetof)+")",
    deviceEvent: "u32("+callof(V.VkDeviceEventInfoEXT_deviceEvent_offsetof)+")",
}, callof(V.VkDeviceEventInfoEXT_sizeof));


const VkDisplayEventInfoEXT = new C.CStruct("VkDisplayEventInfoEXT", {
    sType: "u32("+callof(V.VkDisplayEventInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDisplayEventInfoEXT_pNext_offsetof)+")",
    displayEvent: "u32("+callof(V.VkDisplayEventInfoEXT_displayEvent_offsetof)+")",
}, callof(V.VkDisplayEventInfoEXT_sizeof));


const VkSwapchainCounterCreateInfoEXT = new C.CStruct("VkSwapchainCounterCreateInfoEXT", {
    sType: "u32("+callof(V.VkSwapchainCounterCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSwapchainCounterCreateInfoEXT_pNext_offsetof)+")",
    surfaceCounters: "u32("+callof(V.VkSwapchainCounterCreateInfoEXT_surfaceCounters_offsetof)+")",
}, callof(V.VkSwapchainCounterCreateInfoEXT_sizeof));


const VkPhysicalDeviceGroupProperties = new C.CStruct("VkPhysicalDeviceGroupProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceGroupProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceGroupProperties_pNext_offsetof)+")",
    physicalDeviceCount: "u32("+callof(V.VkPhysicalDeviceGroupProperties_physicalDeviceCount_offsetof)+")",
    physicalDevices: "u64["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceGroupProperties_physicalDevices_offsetof)+")",
    subsetAllocation: "u32("+callof(V.VkPhysicalDeviceGroupProperties_subsetAllocation_offsetof)+")",
}, callof(V.VkPhysicalDeviceGroupProperties_sizeof));


const VkPhysicalDeviceGroupPropertiesKHR = new C.CStruct("VkPhysicalDeviceGroupPropertiesKHR", {

}, callof(V.VkPhysicalDeviceGroupPropertiesKHR_sizeof));


const VkMemoryAllocateFlagsInfo = new C.CStruct("VkMemoryAllocateFlagsInfo", {
    sType: "u32("+callof(V.VkMemoryAllocateFlagsInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryAllocateFlagsInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkMemoryAllocateFlagsInfo_flags_offsetof)+")",
    deviceMask: "u32("+callof(V.VkMemoryAllocateFlagsInfo_deviceMask_offsetof)+")",
}, callof(V.VkMemoryAllocateFlagsInfo_sizeof));


const VkMemoryAllocateFlagsInfoKHR = new C.CStruct("VkMemoryAllocateFlagsInfoKHR", {

}, callof(V.VkMemoryAllocateFlagsInfoKHR_sizeof));


const VkBindBufferMemoryInfo = new C.CStruct("VkBindBufferMemoryInfo", {
    sType: "u32("+callof(V.VkBindBufferMemoryInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBindBufferMemoryInfo_pNext_offsetof)+")",
    buffer: "u64("+callof(V.VkBindBufferMemoryInfo_buffer_offsetof)+")",
    memory: "u64("+callof(V.VkBindBufferMemoryInfo_memory_offsetof)+")",
    memoryOffset: "u64("+callof(V.VkBindBufferMemoryInfo_memoryOffset_offsetof)+")",
}, callof(V.VkBindBufferMemoryInfo_sizeof));


const VkBindBufferMemoryInfoKHR = new C.CStruct("VkBindBufferMemoryInfoKHR", {

}, callof(V.VkBindBufferMemoryInfoKHR_sizeof));


const VkBindBufferMemoryDeviceGroupInfo = new C.CStruct("VkBindBufferMemoryDeviceGroupInfo", {
    sType: "u32("+callof(V.VkBindBufferMemoryDeviceGroupInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBindBufferMemoryDeviceGroupInfo_pNext_offsetof)+")",
    deviceIndexCount: "u32("+callof(V.VkBindBufferMemoryDeviceGroupInfo_deviceIndexCount_offsetof)+")",
    pDeviceIndices: "u64("+callof(V.VkBindBufferMemoryDeviceGroupInfo_pDeviceIndices_offsetof)+")",
}, callof(V.VkBindBufferMemoryDeviceGroupInfo_sizeof));


const VkBindBufferMemoryDeviceGroupInfoKHR = new C.CStruct("VkBindBufferMemoryDeviceGroupInfoKHR", {

}, callof(V.VkBindBufferMemoryDeviceGroupInfoKHR_sizeof));


const VkBindImageMemoryInfo = new C.CStruct("VkBindImageMemoryInfo", {
    sType: "u32("+callof(V.VkBindImageMemoryInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBindImageMemoryInfo_pNext_offsetof)+")",
    image: "u64("+callof(V.VkBindImageMemoryInfo_image_offsetof)+")",
    memory: "u64("+callof(V.VkBindImageMemoryInfo_memory_offsetof)+")",
    memoryOffset: "u64("+callof(V.VkBindImageMemoryInfo_memoryOffset_offsetof)+")",
}, callof(V.VkBindImageMemoryInfo_sizeof));


const VkBindImageMemoryInfoKHR = new C.CStruct("VkBindImageMemoryInfoKHR", {

}, callof(V.VkBindImageMemoryInfoKHR_sizeof));


const VkBindImageMemoryDeviceGroupInfo = new C.CStruct("VkBindImageMemoryDeviceGroupInfo", {
    sType: "u32("+callof(V.VkBindImageMemoryDeviceGroupInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBindImageMemoryDeviceGroupInfo_pNext_offsetof)+")",
    deviceIndexCount: "u32("+callof(V.VkBindImageMemoryDeviceGroupInfo_deviceIndexCount_offsetof)+")",
    pDeviceIndices: "u64("+callof(V.VkBindImageMemoryDeviceGroupInfo_pDeviceIndices_offsetof)+")",
    splitInstanceBindRegionCount: "u32("+callof(V.VkBindImageMemoryDeviceGroupInfo_splitInstanceBindRegionCount_offsetof)+")",
    pSplitInstanceBindRegions: "u64("+callof(V.VkBindImageMemoryDeviceGroupInfo_pSplitInstanceBindRegions_offsetof)+")",
}, callof(V.VkBindImageMemoryDeviceGroupInfo_sizeof));


const VkBindImageMemoryDeviceGroupInfoKHR = new C.CStruct("VkBindImageMemoryDeviceGroupInfoKHR", {

}, callof(V.VkBindImageMemoryDeviceGroupInfoKHR_sizeof));


const VkDeviceGroupRenderPassBeginInfo = new C.CStruct("VkDeviceGroupRenderPassBeginInfo", {
    sType: "u32("+callof(V.VkDeviceGroupRenderPassBeginInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceGroupRenderPassBeginInfo_pNext_offsetof)+")",
    deviceMask: "u32("+callof(V.VkDeviceGroupRenderPassBeginInfo_deviceMask_offsetof)+")",
    deviceRenderAreaCount: "u32("+callof(V.VkDeviceGroupRenderPassBeginInfo_deviceRenderAreaCount_offsetof)+")",
    pDeviceRenderAreas: "u64("+callof(V.VkDeviceGroupRenderPassBeginInfo_pDeviceRenderAreas_offsetof)+")",
}, callof(V.VkDeviceGroupRenderPassBeginInfo_sizeof));


const VkDeviceGroupRenderPassBeginInfoKHR = new C.CStruct("VkDeviceGroupRenderPassBeginInfoKHR", {

}, callof(V.VkDeviceGroupRenderPassBeginInfoKHR_sizeof));


const VkDeviceGroupCommandBufferBeginInfo = new C.CStruct("VkDeviceGroupCommandBufferBeginInfo", {
    sType: "u32("+callof(V.VkDeviceGroupCommandBufferBeginInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceGroupCommandBufferBeginInfo_pNext_offsetof)+")",
    deviceMask: "u32("+callof(V.VkDeviceGroupCommandBufferBeginInfo_deviceMask_offsetof)+")",
}, callof(V.VkDeviceGroupCommandBufferBeginInfo_sizeof));


const VkDeviceGroupCommandBufferBeginInfoKHR = new C.CStruct("VkDeviceGroupCommandBufferBeginInfoKHR", {

}, callof(V.VkDeviceGroupCommandBufferBeginInfoKHR_sizeof));


const VkDeviceGroupSubmitInfo = new C.CStruct("VkDeviceGroupSubmitInfo", {
    sType: "u32("+callof(V.VkDeviceGroupSubmitInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceGroupSubmitInfo_pNext_offsetof)+")",
    waitSemaphoreCount: "u32("+callof(V.VkDeviceGroupSubmitInfo_waitSemaphoreCount_offsetof)+")",
    pWaitSemaphoreDeviceIndices: "u64("+callof(V.VkDeviceGroupSubmitInfo_pWaitSemaphoreDeviceIndices_offsetof)+")",
    commandBufferCount: "u32("+callof(V.VkDeviceGroupSubmitInfo_commandBufferCount_offsetof)+")",
    pCommandBufferDeviceMasks: "u64("+callof(V.VkDeviceGroupSubmitInfo_pCommandBufferDeviceMasks_offsetof)+")",
    signalSemaphoreCount: "u32("+callof(V.VkDeviceGroupSubmitInfo_signalSemaphoreCount_offsetof)+")",
    pSignalSemaphoreDeviceIndices: "u64("+callof(V.VkDeviceGroupSubmitInfo_pSignalSemaphoreDeviceIndices_offsetof)+")",
}, callof(V.VkDeviceGroupSubmitInfo_sizeof));


const VkDeviceGroupSubmitInfoKHR = new C.CStruct("VkDeviceGroupSubmitInfoKHR", {

}, callof(V.VkDeviceGroupSubmitInfoKHR_sizeof));


const VkDeviceGroupBindSparseInfo = new C.CStruct("VkDeviceGroupBindSparseInfo", {
    sType: "u32("+callof(V.VkDeviceGroupBindSparseInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceGroupBindSparseInfo_pNext_offsetof)+")",
    resourceDeviceIndex: "u32("+callof(V.VkDeviceGroupBindSparseInfo_resourceDeviceIndex_offsetof)+")",
    memoryDeviceIndex: "u32("+callof(V.VkDeviceGroupBindSparseInfo_memoryDeviceIndex_offsetof)+")",
}, callof(V.VkDeviceGroupBindSparseInfo_sizeof));


const VkDeviceGroupBindSparseInfoKHR = new C.CStruct("VkDeviceGroupBindSparseInfoKHR", {

}, callof(V.VkDeviceGroupBindSparseInfoKHR_sizeof));


const VkDeviceGroupPresentCapabilitiesKHR = new C.CStruct("VkDeviceGroupPresentCapabilitiesKHR", {
    sType: "u32("+callof(V.VkDeviceGroupPresentCapabilitiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceGroupPresentCapabilitiesKHR_pNext_offsetof)+")",
    presentMask: "u32["+(enums.NaN||1)+"]("+callof(V.VkDeviceGroupPresentCapabilitiesKHR_presentMask_offsetof)+")",
    modes: "u32("+callof(V.VkDeviceGroupPresentCapabilitiesKHR_modes_offsetof)+")",
}, callof(V.VkDeviceGroupPresentCapabilitiesKHR_sizeof));


const VkImageSwapchainCreateInfoKHR = new C.CStruct("VkImageSwapchainCreateInfoKHR", {
    sType: "u32("+callof(V.VkImageSwapchainCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageSwapchainCreateInfoKHR_pNext_offsetof)+")",
    swapchain: "u64("+callof(V.VkImageSwapchainCreateInfoKHR_swapchain_offsetof)+")",
}, callof(V.VkImageSwapchainCreateInfoKHR_sizeof));


const VkBindImageMemorySwapchainInfoKHR = new C.CStruct("VkBindImageMemorySwapchainInfoKHR", {
    sType: "u32("+callof(V.VkBindImageMemorySwapchainInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBindImageMemorySwapchainInfoKHR_pNext_offsetof)+")",
    swapchain: "u64("+callof(V.VkBindImageMemorySwapchainInfoKHR_swapchain_offsetof)+")",
    imageIndex: "u32("+callof(V.VkBindImageMemorySwapchainInfoKHR_imageIndex_offsetof)+")",
}, callof(V.VkBindImageMemorySwapchainInfoKHR_sizeof));


const VkAcquireNextImageInfoKHR = new C.CStruct("VkAcquireNextImageInfoKHR", {
    sType: "u32("+callof(V.VkAcquireNextImageInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAcquireNextImageInfoKHR_pNext_offsetof)+")",
    swapchain: "u64("+callof(V.VkAcquireNextImageInfoKHR_swapchain_offsetof)+")",
    timeout: "u64("+callof(V.VkAcquireNextImageInfoKHR_timeout_offsetof)+")",
    semaphore: "u64("+callof(V.VkAcquireNextImageInfoKHR_semaphore_offsetof)+")",
    fence: "u32("+callof(V.VkAcquireNextImageInfoKHR_fence_offsetof)+")",
    deviceMask: "u32("+callof(V.VkAcquireNextImageInfoKHR_deviceMask_offsetof)+")",
}, callof(V.VkAcquireNextImageInfoKHR_sizeof));


const VkDeviceGroupPresentInfoKHR = new C.CStruct("VkDeviceGroupPresentInfoKHR", {
    sType: "u32("+callof(V.VkDeviceGroupPresentInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceGroupPresentInfoKHR_pNext_offsetof)+")",
    swapchainCount: "u32("+callof(V.VkDeviceGroupPresentInfoKHR_swapchainCount_offsetof)+")",
    pDeviceMasks: "u64("+callof(V.VkDeviceGroupPresentInfoKHR_pDeviceMasks_offsetof)+")",
    mode: "u32("+callof(V.VkDeviceGroupPresentInfoKHR_mode_offsetof)+")",
}, callof(V.VkDeviceGroupPresentInfoKHR_sizeof));


const VkDeviceGroupDeviceCreateInfo = new C.CStruct("VkDeviceGroupDeviceCreateInfo", {
    sType: "u32("+callof(V.VkDeviceGroupDeviceCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceGroupDeviceCreateInfo_pNext_offsetof)+")",
    physicalDeviceCount: "u32("+callof(V.VkDeviceGroupDeviceCreateInfo_physicalDeviceCount_offsetof)+")",
    pPhysicalDevices: "u64("+callof(V.VkDeviceGroupDeviceCreateInfo_pPhysicalDevices_offsetof)+")",
}, callof(V.VkDeviceGroupDeviceCreateInfo_sizeof));


const VkDeviceGroupDeviceCreateInfoKHR = new C.CStruct("VkDeviceGroupDeviceCreateInfoKHR", {

}, callof(V.VkDeviceGroupDeviceCreateInfoKHR_sizeof));


const VkDeviceGroupSwapchainCreateInfoKHR = new C.CStruct("VkDeviceGroupSwapchainCreateInfoKHR", {
    sType: "u32("+callof(V.VkDeviceGroupSwapchainCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceGroupSwapchainCreateInfoKHR_pNext_offsetof)+")",
    modes: "u32("+callof(V.VkDeviceGroupSwapchainCreateInfoKHR_modes_offsetof)+")",
}, callof(V.VkDeviceGroupSwapchainCreateInfoKHR_sizeof));


const VkDescriptorUpdateTemplateEntry = new C.CStruct("VkDescriptorUpdateTemplateEntry", {
    dstBinding: "u32("+callof(V.VkDescriptorUpdateTemplateEntry_dstBinding_offsetof)+")",
    dstArrayElement: "u32("+callof(V.VkDescriptorUpdateTemplateEntry_dstArrayElement_offsetof)+")",
    descriptorCount: "u32("+callof(V.VkDescriptorUpdateTemplateEntry_descriptorCount_offsetof)+")",
    descriptorType: "u32("+callof(V.VkDescriptorUpdateTemplateEntry_descriptorType_offsetof)+")",
    offset: "u64("+callof(V.VkDescriptorUpdateTemplateEntry_offset_offsetof)+")",
    stride: "u64("+callof(V.VkDescriptorUpdateTemplateEntry_stride_offsetof)+")",
}, callof(V.VkDescriptorUpdateTemplateEntry_sizeof));


const VkDescriptorUpdateTemplateEntryKHR = new C.CStruct("VkDescriptorUpdateTemplateEntryKHR", {

}, callof(V.VkDescriptorUpdateTemplateEntryKHR_sizeof));


const VkDescriptorUpdateTemplateCreateInfo = new C.CStruct("VkDescriptorUpdateTemplateCreateInfo", {
    sType: "u32("+callof(V.VkDescriptorUpdateTemplateCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDescriptorUpdateTemplateCreateInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDescriptorUpdateTemplateCreateInfo_flags_offsetof)+")",
    descriptorUpdateEntryCount: "u32("+callof(V.VkDescriptorUpdateTemplateCreateInfo_descriptorUpdateEntryCount_offsetof)+")",
    pDescriptorUpdateEntries: "u64("+callof(V.VkDescriptorUpdateTemplateCreateInfo_pDescriptorUpdateEntries_offsetof)+")",
    templateType: "u32("+callof(V.VkDescriptorUpdateTemplateCreateInfo_templateType_offsetof)+")",
    descriptorSetLayout: "u32("+callof(V.VkDescriptorUpdateTemplateCreateInfo_descriptorSetLayout_offsetof)+")",
    pipelineBindPoint: "u32("+callof(V.VkDescriptorUpdateTemplateCreateInfo_pipelineBindPoint_offsetof)+")",
    pipelineLayout: "u64("+callof(V.VkDescriptorUpdateTemplateCreateInfo_pipelineLayout_offsetof)+")",
    set: "u32("+callof(V.VkDescriptorUpdateTemplateCreateInfo_set_offsetof)+")",
}, callof(V.VkDescriptorUpdateTemplateCreateInfo_sizeof));


const VkDescriptorUpdateTemplateCreateInfoKHR = new C.CStruct("VkDescriptorUpdateTemplateCreateInfoKHR", {

}, callof(V.VkDescriptorUpdateTemplateCreateInfoKHR_sizeof));


const VkXYColorEXT = new C.CStruct("VkXYColorEXT", {
    x: "f32("+callof(V.VkXYColorEXT_x_offsetof)+")",
    y: "f32("+callof(V.VkXYColorEXT_y_offsetof)+")",
}, callof(V.VkXYColorEXT_sizeof));


const VkPhysicalDevicePresentIdFeaturesKHR = new C.CStruct("VkPhysicalDevicePresentIdFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDevicePresentIdFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePresentIdFeaturesKHR_pNext_offsetof)+")",
    presentId: "u32("+callof(V.VkPhysicalDevicePresentIdFeaturesKHR_presentId_offsetof)+")",
}, callof(V.VkPhysicalDevicePresentIdFeaturesKHR_sizeof));


const VkPresentIdKHR = new C.CStruct("VkPresentIdKHR", {
    sType: "u32("+callof(V.VkPresentIdKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPresentIdKHR_pNext_offsetof)+")",
    swapchainCount: "u32("+callof(V.VkPresentIdKHR_swapchainCount_offsetof)+")",
    pPresentIds: "u64("+callof(V.VkPresentIdKHR_pPresentIds_offsetof)+")",
}, callof(V.VkPresentIdKHR_sizeof));


const VkPhysicalDevicePresentWaitFeaturesKHR = new C.CStruct("VkPhysicalDevicePresentWaitFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDevicePresentWaitFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePresentWaitFeaturesKHR_pNext_offsetof)+")",
    presentWait: "u32("+callof(V.VkPhysicalDevicePresentWaitFeaturesKHR_presentWait_offsetof)+")",
}, callof(V.VkPhysicalDevicePresentWaitFeaturesKHR_sizeof));


const VkHdrMetadataEXT = new C.CStruct("VkHdrMetadataEXT", {
    sType: "u32("+callof(V.VkHdrMetadataEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkHdrMetadataEXT_pNext_offsetof)+")",
    displayPrimaryRed: "u32("+callof(V.VkHdrMetadataEXT_displayPrimaryRed_offsetof)+")",
    displayPrimaryGreen: "u32("+callof(V.VkHdrMetadataEXT_displayPrimaryGreen_offsetof)+")",
    displayPrimaryBlue: "u32("+callof(V.VkHdrMetadataEXT_displayPrimaryBlue_offsetof)+")",
    whitePoint: "u32("+callof(V.VkHdrMetadataEXT_whitePoint_offsetof)+")",
    maxLuminance: "f32("+callof(V.VkHdrMetadataEXT_maxLuminance_offsetof)+")",
    minLuminance: "f32("+callof(V.VkHdrMetadataEXT_minLuminance_offsetof)+")",
    maxContentLightLevel: "f32("+callof(V.VkHdrMetadataEXT_maxContentLightLevel_offsetof)+")",
    maxFrameAverageLightLevel: "f32("+callof(V.VkHdrMetadataEXT_maxFrameAverageLightLevel_offsetof)+")",
}, callof(V.VkHdrMetadataEXT_sizeof));


const VkDisplayNativeHdrSurfaceCapabilitiesAMD = new C.CStruct("VkDisplayNativeHdrSurfaceCapabilitiesAMD", {
    sType: "u32("+callof(V.VkDisplayNativeHdrSurfaceCapabilitiesAMD_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDisplayNativeHdrSurfaceCapabilitiesAMD_pNext_offsetof)+")",
    localDimmingSupport: "u32("+callof(V.VkDisplayNativeHdrSurfaceCapabilitiesAMD_localDimmingSupport_offsetof)+")",
}, callof(V.VkDisplayNativeHdrSurfaceCapabilitiesAMD_sizeof));


const VkSwapchainDisplayNativeHdrCreateInfoAMD = new C.CStruct("VkSwapchainDisplayNativeHdrCreateInfoAMD", {
    sType: "u32("+callof(V.VkSwapchainDisplayNativeHdrCreateInfoAMD_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSwapchainDisplayNativeHdrCreateInfoAMD_pNext_offsetof)+")",
    localDimmingEnable: "u32("+callof(V.VkSwapchainDisplayNativeHdrCreateInfoAMD_localDimmingEnable_offsetof)+")",
}, callof(V.VkSwapchainDisplayNativeHdrCreateInfoAMD_sizeof));


const VkRefreshCycleDurationGOOGLE = new C.CStruct("VkRefreshCycleDurationGOOGLE", {
    refreshDuration: "u64("+callof(V.VkRefreshCycleDurationGOOGLE_refreshDuration_offsetof)+")",
}, callof(V.VkRefreshCycleDurationGOOGLE_sizeof));


const VkPastPresentationTimingGOOGLE = new C.CStruct("VkPastPresentationTimingGOOGLE", {
    presentID: "u32("+callof(V.VkPastPresentationTimingGOOGLE_presentID_offsetof)+")",
    desiredPresentTime: "u64("+callof(V.VkPastPresentationTimingGOOGLE_desiredPresentTime_offsetof)+")",
    actualPresentTime: "u64("+callof(V.VkPastPresentationTimingGOOGLE_actualPresentTime_offsetof)+")",
    earliestPresentTime: "u64("+callof(V.VkPastPresentationTimingGOOGLE_earliestPresentTime_offsetof)+")",
    presentMargin: "u64("+callof(V.VkPastPresentationTimingGOOGLE_presentMargin_offsetof)+")",
}, callof(V.VkPastPresentationTimingGOOGLE_sizeof));


const VkPresentTimesInfoGOOGLE = new C.CStruct("VkPresentTimesInfoGOOGLE", {
    sType: "u32("+callof(V.VkPresentTimesInfoGOOGLE_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPresentTimesInfoGOOGLE_pNext_offsetof)+")",
    swapchainCount: "u32("+callof(V.VkPresentTimesInfoGOOGLE_swapchainCount_offsetof)+")",
    pTimes: "u64("+callof(V.VkPresentTimesInfoGOOGLE_pTimes_offsetof)+")",
}, callof(V.VkPresentTimesInfoGOOGLE_sizeof));


const VkPresentTimeGOOGLE = new C.CStruct("VkPresentTimeGOOGLE", {
    presentID: "u32("+callof(V.VkPresentTimeGOOGLE_presentID_offsetof)+")",
    desiredPresentTime: "u64("+callof(V.VkPresentTimeGOOGLE_desiredPresentTime_offsetof)+")",
}, callof(V.VkPresentTimeGOOGLE_sizeof));


const VkIOSSurfaceCreateInfoMVK = new C.CStruct("VkIOSSurfaceCreateInfoMVK", {
    sType: "u32("+callof(V.VkIOSSurfaceCreateInfoMVK_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkIOSSurfaceCreateInfoMVK_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkIOSSurfaceCreateInfoMVK_flags_offsetof)+")",
    pView: "u64("+callof(V.VkIOSSurfaceCreateInfoMVK_pView_offsetof)+")",
}, callof(V.VkIOSSurfaceCreateInfoMVK_sizeof));


const VkMacOSSurfaceCreateInfoMVK = new C.CStruct("VkMacOSSurfaceCreateInfoMVK", {
    sType: "u32("+callof(V.VkMacOSSurfaceCreateInfoMVK_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMacOSSurfaceCreateInfoMVK_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkMacOSSurfaceCreateInfoMVK_flags_offsetof)+")",
    pView: "u64("+callof(V.VkMacOSSurfaceCreateInfoMVK_pView_offsetof)+")",
}, callof(V.VkMacOSSurfaceCreateInfoMVK_sizeof));


const VkMetalSurfaceCreateInfoEXT = new C.CStruct("VkMetalSurfaceCreateInfoEXT", {
    sType: "u32("+callof(V.VkMetalSurfaceCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMetalSurfaceCreateInfoEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkMetalSurfaceCreateInfoEXT_flags_offsetof)+")",
    pLayer: "u64("+callof(V.VkMetalSurfaceCreateInfoEXT_pLayer_offsetof)+")",
}, callof(V.VkMetalSurfaceCreateInfoEXT_sizeof));


const VkViewportWScalingNV = new C.CStruct("VkViewportWScalingNV", {
    xcoeff: "f32("+callof(V.VkViewportWScalingNV_xcoeff_offsetof)+")",
    ycoeff: "f32("+callof(V.VkViewportWScalingNV_ycoeff_offsetof)+")",
}, callof(V.VkViewportWScalingNV_sizeof));


const VkPipelineViewportWScalingStateCreateInfoNV = new C.CStruct("VkPipelineViewportWScalingStateCreateInfoNV", {
    sType: "u32("+callof(V.VkPipelineViewportWScalingStateCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineViewportWScalingStateCreateInfoNV_pNext_offsetof)+")",
    viewportWScalingEnable: "u32("+callof(V.VkPipelineViewportWScalingStateCreateInfoNV_viewportWScalingEnable_offsetof)+")",
    viewportCount: "u32("+callof(V.VkPipelineViewportWScalingStateCreateInfoNV_viewportCount_offsetof)+")",
    pViewportWScalings: "u64("+callof(V.VkPipelineViewportWScalingStateCreateInfoNV_pViewportWScalings_offsetof)+")",
}, callof(V.VkPipelineViewportWScalingStateCreateInfoNV_sizeof));


const VkViewportSwizzleNV = new C.CStruct("VkViewportSwizzleNV", {
    x: "u32("+callof(V.VkViewportSwizzleNV_x_offsetof)+")",
    y: "u32("+callof(V.VkViewportSwizzleNV_y_offsetof)+")",
    z: "u32("+callof(V.VkViewportSwizzleNV_z_offsetof)+")",
    w: "u32("+callof(V.VkViewportSwizzleNV_w_offsetof)+")",
}, callof(V.VkViewportSwizzleNV_sizeof));


const VkPipelineViewportSwizzleStateCreateInfoNV = new C.CStruct("VkPipelineViewportSwizzleStateCreateInfoNV", {
    sType: "u32("+callof(V.VkPipelineViewportSwizzleStateCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineViewportSwizzleStateCreateInfoNV_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineViewportSwizzleStateCreateInfoNV_flags_offsetof)+")",
    viewportCount: "u32("+callof(V.VkPipelineViewportSwizzleStateCreateInfoNV_viewportCount_offsetof)+")",
    pViewportSwizzles: "u64("+callof(V.VkPipelineViewportSwizzleStateCreateInfoNV_pViewportSwizzles_offsetof)+")",
}, callof(V.VkPipelineViewportSwizzleStateCreateInfoNV_sizeof));


const VkPhysicalDeviceDiscardRectanglePropertiesEXT = new C.CStruct("VkPhysicalDeviceDiscardRectanglePropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceDiscardRectanglePropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDiscardRectanglePropertiesEXT_pNext_offsetof)+")",
    maxDiscardRectangles: "u32("+callof(V.VkPhysicalDeviceDiscardRectanglePropertiesEXT_maxDiscardRectangles_offsetof)+")",
}, callof(V.VkPhysicalDeviceDiscardRectanglePropertiesEXT_sizeof));


const VkPipelineDiscardRectangleStateCreateInfoEXT = new C.CStruct("VkPipelineDiscardRectangleStateCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineDiscardRectangleStateCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineDiscardRectangleStateCreateInfoEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineDiscardRectangleStateCreateInfoEXT_flags_offsetof)+")",
    discardRectangleMode: "u32("+callof(V.VkPipelineDiscardRectangleStateCreateInfoEXT_discardRectangleMode_offsetof)+")",
    discardRectangleCount: "u32("+callof(V.VkPipelineDiscardRectangleStateCreateInfoEXT_discardRectangleCount_offsetof)+")",
    pDiscardRectangles: "u64("+callof(V.VkPipelineDiscardRectangleStateCreateInfoEXT_pDiscardRectangles_offsetof)+")",
}, callof(V.VkPipelineDiscardRectangleStateCreateInfoEXT_sizeof));


const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX = new C.CStruct("VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX", {
    sType: "u32("+callof(V.VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX_pNext_offsetof)+")",
    perViewPositionAllComponents: "u32("+callof(V.VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX_perViewPositionAllComponents_offsetof)+")",
}, callof(V.VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX_sizeof));


const VkInputAttachmentAspectReference = new C.CStruct("VkInputAttachmentAspectReference", {
    subpass: "u32("+callof(V.VkInputAttachmentAspectReference_subpass_offsetof)+")",
    inputAttachmentIndex: "u32("+callof(V.VkInputAttachmentAspectReference_inputAttachmentIndex_offsetof)+")",
    aspectMask: "u32("+callof(V.VkInputAttachmentAspectReference_aspectMask_offsetof)+")",
}, callof(V.VkInputAttachmentAspectReference_sizeof));


const VkInputAttachmentAspectReferenceKHR = new C.CStruct("VkInputAttachmentAspectReferenceKHR", {

}, callof(V.VkInputAttachmentAspectReferenceKHR_sizeof));


const VkRenderPassInputAttachmentAspectCreateInfo = new C.CStruct("VkRenderPassInputAttachmentAspectCreateInfo", {
    sType: "u32("+callof(V.VkRenderPassInputAttachmentAspectCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderPassInputAttachmentAspectCreateInfo_pNext_offsetof)+")",
    aspectReferenceCount: "u32("+callof(V.VkRenderPassInputAttachmentAspectCreateInfo_aspectReferenceCount_offsetof)+")",
    pAspectReferences: "u64("+callof(V.VkRenderPassInputAttachmentAspectCreateInfo_pAspectReferences_offsetof)+")",
}, callof(V.VkRenderPassInputAttachmentAspectCreateInfo_sizeof));


const VkRenderPassInputAttachmentAspectCreateInfoKHR = new C.CStruct("VkRenderPassInputAttachmentAspectCreateInfoKHR", {

}, callof(V.VkRenderPassInputAttachmentAspectCreateInfoKHR_sizeof));


const VkPhysicalDeviceSurfaceInfo2KHR = new C.CStruct("VkPhysicalDeviceSurfaceInfo2KHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceSurfaceInfo2KHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSurfaceInfo2KHR_pNext_offsetof)+")",
    surface: "u64("+callof(V.VkPhysicalDeviceSurfaceInfo2KHR_surface_offsetof)+")",
}, callof(V.VkPhysicalDeviceSurfaceInfo2KHR_sizeof));


const VkSurfaceCapabilities2KHR = new C.CStruct("VkSurfaceCapabilities2KHR", {
    sType: "u32("+callof(V.VkSurfaceCapabilities2KHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSurfaceCapabilities2KHR_pNext_offsetof)+")",
    surfaceCapabilities: "u32("+callof(V.VkSurfaceCapabilities2KHR_surfaceCapabilities_offsetof)+")",
}, callof(V.VkSurfaceCapabilities2KHR_sizeof));


const VkSurfaceFormat2KHR = new C.CStruct("VkSurfaceFormat2KHR", {
    sType: "u32("+callof(V.VkSurfaceFormat2KHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSurfaceFormat2KHR_pNext_offsetof)+")",
    surfaceFormat: "u32("+callof(V.VkSurfaceFormat2KHR_surfaceFormat_offsetof)+")",
}, callof(V.VkSurfaceFormat2KHR_sizeof));


const VkDisplayProperties2KHR = new C.CStruct("VkDisplayProperties2KHR", {
    sType: "u32("+callof(V.VkDisplayProperties2KHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDisplayProperties2KHR_pNext_offsetof)+")",
    displayProperties: "u32("+callof(V.VkDisplayProperties2KHR_displayProperties_offsetof)+")",
}, callof(V.VkDisplayProperties2KHR_sizeof));


const VkDisplayPlaneProperties2KHR = new C.CStruct("VkDisplayPlaneProperties2KHR", {
    sType: "u32("+callof(V.VkDisplayPlaneProperties2KHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDisplayPlaneProperties2KHR_pNext_offsetof)+")",
    displayPlaneProperties: "u32("+callof(V.VkDisplayPlaneProperties2KHR_displayPlaneProperties_offsetof)+")",
}, callof(V.VkDisplayPlaneProperties2KHR_sizeof));


const VkDisplayModeProperties2KHR = new C.CStruct("VkDisplayModeProperties2KHR", {
    sType: "u32("+callof(V.VkDisplayModeProperties2KHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDisplayModeProperties2KHR_pNext_offsetof)+")",
    displayModeProperties: "u32("+callof(V.VkDisplayModeProperties2KHR_displayModeProperties_offsetof)+")",
}, callof(V.VkDisplayModeProperties2KHR_sizeof));


const VkDisplayPlaneInfo2KHR = new C.CStruct("VkDisplayPlaneInfo2KHR", {
    sType: "u32("+callof(V.VkDisplayPlaneInfo2KHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDisplayPlaneInfo2KHR_pNext_offsetof)+")",
    mode: "u32("+callof(V.VkDisplayPlaneInfo2KHR_mode_offsetof)+")",
    planeIndex: "u32("+callof(V.VkDisplayPlaneInfo2KHR_planeIndex_offsetof)+")",
}, callof(V.VkDisplayPlaneInfo2KHR_sizeof));


const VkDisplayPlaneCapabilities2KHR = new C.CStruct("VkDisplayPlaneCapabilities2KHR", {
    sType: "u32("+callof(V.VkDisplayPlaneCapabilities2KHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDisplayPlaneCapabilities2KHR_pNext_offsetof)+")",
    capabilities: "u32("+callof(V.VkDisplayPlaneCapabilities2KHR_capabilities_offsetof)+")",
}, callof(V.VkDisplayPlaneCapabilities2KHR_sizeof));


const VkSharedPresentSurfaceCapabilitiesKHR = new C.CStruct("VkSharedPresentSurfaceCapabilitiesKHR", {
    sType: "u32("+callof(V.VkSharedPresentSurfaceCapabilitiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSharedPresentSurfaceCapabilitiesKHR_pNext_offsetof)+")",
    sharedPresentSupportedUsageFlags: "u32("+callof(V.VkSharedPresentSurfaceCapabilitiesKHR_sharedPresentSupportedUsageFlags_offsetof)+")",
}, callof(V.VkSharedPresentSurfaceCapabilitiesKHR_sizeof));


const VkPhysicalDevice16BitStorageFeatures = new C.CStruct("VkPhysicalDevice16BitStorageFeatures", {
    sType: "u32("+callof(V.VkPhysicalDevice16BitStorageFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevice16BitStorageFeatures_pNext_offsetof)+")",
    storageBuffer16BitAccess: "u32("+callof(V.VkPhysicalDevice16BitStorageFeatures_storageBuffer16BitAccess_offsetof)+")",
    uniformAndStorageBuffer16BitAccess: "u32("+callof(V.VkPhysicalDevice16BitStorageFeatures_uniformAndStorageBuffer16BitAccess_offsetof)+")",
    storagePushConstant16: "u32("+callof(V.VkPhysicalDevice16BitStorageFeatures_storagePushConstant16_offsetof)+")",
    storageInputOutput16: "u32("+callof(V.VkPhysicalDevice16BitStorageFeatures_storageInputOutput16_offsetof)+")",
}, callof(V.VkPhysicalDevice16BitStorageFeatures_sizeof));


const VkPhysicalDevice16BitStorageFeaturesKHR = new C.CStruct("VkPhysicalDevice16BitStorageFeaturesKHR", {

}, callof(V.VkPhysicalDevice16BitStorageFeaturesKHR_sizeof));


const VkPhysicalDeviceSubgroupProperties = new C.CStruct("VkPhysicalDeviceSubgroupProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceSubgroupProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSubgroupProperties_pNext_offsetof)+")",
    subgroupSize: "u32("+callof(V.VkPhysicalDeviceSubgroupProperties_subgroupSize_offsetof)+")",
    supportedStages: "u32("+callof(V.VkPhysicalDeviceSubgroupProperties_supportedStages_offsetof)+")",
    supportedOperations: "u32("+callof(V.VkPhysicalDeviceSubgroupProperties_supportedOperations_offsetof)+")",
    quadOperationsInAllStages: "u32("+callof(V.VkPhysicalDeviceSubgroupProperties_quadOperationsInAllStages_offsetof)+")",
}, callof(V.VkPhysicalDeviceSubgroupProperties_sizeof));


const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures = new C.CStruct("VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pNext_offsetof)+")",
    shaderSubgroupExtendedTypes: "u32("+callof(V.VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_shaderSubgroupExtendedTypes_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_sizeof));


const VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR = new C.CStruct("VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR", {

}, callof(V.VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR_sizeof));


const VkBufferMemoryRequirementsInfo2 = new C.CStruct("VkBufferMemoryRequirementsInfo2", {
    sType: "u32("+callof(V.VkBufferMemoryRequirementsInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferMemoryRequirementsInfo2_pNext_offsetof)+")",
    buffer: "u64("+callof(V.VkBufferMemoryRequirementsInfo2_buffer_offsetof)+")",
}, callof(V.VkBufferMemoryRequirementsInfo2_sizeof));


const VkBufferMemoryRequirementsInfo2KHR = new C.CStruct("VkBufferMemoryRequirementsInfo2KHR", {

}, callof(V.VkBufferMemoryRequirementsInfo2KHR_sizeof));


const VkDeviceBufferMemoryRequirements = new C.CStruct("VkDeviceBufferMemoryRequirements", {
    sType: "u32("+callof(V.VkDeviceBufferMemoryRequirements_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceBufferMemoryRequirements_pNext_offsetof)+")",
    pCreateInfo: "u64("+callof(V.VkDeviceBufferMemoryRequirements_pCreateInfo_offsetof)+")",
}, callof(V.VkDeviceBufferMemoryRequirements_sizeof));


const VkDeviceBufferMemoryRequirementsKHR = new C.CStruct("VkDeviceBufferMemoryRequirementsKHR", {

}, callof(V.VkDeviceBufferMemoryRequirementsKHR_sizeof));


const VkImageMemoryRequirementsInfo2 = new C.CStruct("VkImageMemoryRequirementsInfo2", {
    sType: "u32("+callof(V.VkImageMemoryRequirementsInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageMemoryRequirementsInfo2_pNext_offsetof)+")",
    image: "u64("+callof(V.VkImageMemoryRequirementsInfo2_image_offsetof)+")",
}, callof(V.VkImageMemoryRequirementsInfo2_sizeof));


const VkImageMemoryRequirementsInfo2KHR = new C.CStruct("VkImageMemoryRequirementsInfo2KHR", {

}, callof(V.VkImageMemoryRequirementsInfo2KHR_sizeof));


const VkImageSparseMemoryRequirementsInfo2 = new C.CStruct("VkImageSparseMemoryRequirementsInfo2", {
    sType: "u32("+callof(V.VkImageSparseMemoryRequirementsInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageSparseMemoryRequirementsInfo2_pNext_offsetof)+")",
    image: "u64("+callof(V.VkImageSparseMemoryRequirementsInfo2_image_offsetof)+")",
}, callof(V.VkImageSparseMemoryRequirementsInfo2_sizeof));


const VkImageSparseMemoryRequirementsInfo2KHR = new C.CStruct("VkImageSparseMemoryRequirementsInfo2KHR", {

}, callof(V.VkImageSparseMemoryRequirementsInfo2KHR_sizeof));


const VkDeviceImageMemoryRequirements = new C.CStruct("VkDeviceImageMemoryRequirements", {
    sType: "u32("+callof(V.VkDeviceImageMemoryRequirements_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceImageMemoryRequirements_pNext_offsetof)+")",
    pCreateInfo: "u64("+callof(V.VkDeviceImageMemoryRequirements_pCreateInfo_offsetof)+")",
    planeAspect: "u32("+callof(V.VkDeviceImageMemoryRequirements_planeAspect_offsetof)+")",
}, callof(V.VkDeviceImageMemoryRequirements_sizeof));


const VkDeviceImageMemoryRequirementsKHR = new C.CStruct("VkDeviceImageMemoryRequirementsKHR", {

}, callof(V.VkDeviceImageMemoryRequirementsKHR_sizeof));


const VkMemoryRequirements2 = new C.CStruct("VkMemoryRequirements2", {
    sType: "u32("+callof(V.VkMemoryRequirements2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryRequirements2_pNext_offsetof)+")",
    memoryRequirements: "u32("+callof(V.VkMemoryRequirements2_memoryRequirements_offsetof)+")",
}, callof(V.VkMemoryRequirements2_sizeof));


const VkMemoryRequirements2KHR = new C.CStruct("VkMemoryRequirements2KHR", {

}, callof(V.VkMemoryRequirements2KHR_sizeof));


const VkSparseImageMemoryRequirements2 = new C.CStruct("VkSparseImageMemoryRequirements2", {
    sType: "u32("+callof(V.VkSparseImageMemoryRequirements2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSparseImageMemoryRequirements2_pNext_offsetof)+")",
    memoryRequirements: "u32("+callof(V.VkSparseImageMemoryRequirements2_memoryRequirements_offsetof)+")",
}, callof(V.VkSparseImageMemoryRequirements2_sizeof));


const VkSparseImageMemoryRequirements2KHR = new C.CStruct("VkSparseImageMemoryRequirements2KHR", {

}, callof(V.VkSparseImageMemoryRequirements2KHR_sizeof));


const VkPhysicalDevicePointClippingProperties = new C.CStruct("VkPhysicalDevicePointClippingProperties", {
    sType: "u32("+callof(V.VkPhysicalDevicePointClippingProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePointClippingProperties_pNext_offsetof)+")",
    pointClippingBehavior: "u32("+callof(V.VkPhysicalDevicePointClippingProperties_pointClippingBehavior_offsetof)+")",
}, callof(V.VkPhysicalDevicePointClippingProperties_sizeof));


const VkPhysicalDevicePointClippingPropertiesKHR = new C.CStruct("VkPhysicalDevicePointClippingPropertiesKHR", {

}, callof(V.VkPhysicalDevicePointClippingPropertiesKHR_sizeof));


const VkMemoryDedicatedRequirements = new C.CStruct("VkMemoryDedicatedRequirements", {
    sType: "u32("+callof(V.VkMemoryDedicatedRequirements_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryDedicatedRequirements_pNext_offsetof)+")",
    prefersDedicatedAllocation: "u32("+callof(V.VkMemoryDedicatedRequirements_prefersDedicatedAllocation_offsetof)+")",
    requiresDedicatedAllocation: "u32("+callof(V.VkMemoryDedicatedRequirements_requiresDedicatedAllocation_offsetof)+")",
}, callof(V.VkMemoryDedicatedRequirements_sizeof));


const VkMemoryDedicatedRequirementsKHR = new C.CStruct("VkMemoryDedicatedRequirementsKHR", {

}, callof(V.VkMemoryDedicatedRequirementsKHR_sizeof));


const VkMemoryDedicatedAllocateInfo = new C.CStruct("VkMemoryDedicatedAllocateInfo", {
    sType: "u32("+callof(V.VkMemoryDedicatedAllocateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryDedicatedAllocateInfo_pNext_offsetof)+")",
    image: "u64("+callof(V.VkMemoryDedicatedAllocateInfo_image_offsetof)+")",
    buffer: "u64("+callof(V.VkMemoryDedicatedAllocateInfo_buffer_offsetof)+")",
}, callof(V.VkMemoryDedicatedAllocateInfo_sizeof));


const VkMemoryDedicatedAllocateInfoKHR = new C.CStruct("VkMemoryDedicatedAllocateInfoKHR", {

}, callof(V.VkMemoryDedicatedAllocateInfoKHR_sizeof));


const VkImageViewUsageCreateInfo = new C.CStruct("VkImageViewUsageCreateInfo", {
    sType: "u32("+callof(V.VkImageViewUsageCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageViewUsageCreateInfo_pNext_offsetof)+")",
    usage: "u32("+callof(V.VkImageViewUsageCreateInfo_usage_offsetof)+")",
}, callof(V.VkImageViewUsageCreateInfo_sizeof));


const VkImageViewUsageCreateInfoKHR = new C.CStruct("VkImageViewUsageCreateInfoKHR", {

}, callof(V.VkImageViewUsageCreateInfoKHR_sizeof));


const VkPipelineTessellationDomainOriginStateCreateInfo = new C.CStruct("VkPipelineTessellationDomainOriginStateCreateInfo", {
    sType: "u32("+callof(V.VkPipelineTessellationDomainOriginStateCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineTessellationDomainOriginStateCreateInfo_pNext_offsetof)+")",
    domainOrigin: "u32("+callof(V.VkPipelineTessellationDomainOriginStateCreateInfo_domainOrigin_offsetof)+")",
}, callof(V.VkPipelineTessellationDomainOriginStateCreateInfo_sizeof));


const VkPipelineTessellationDomainOriginStateCreateInfoKHR = new C.CStruct("VkPipelineTessellationDomainOriginStateCreateInfoKHR", {

}, callof(V.VkPipelineTessellationDomainOriginStateCreateInfoKHR_sizeof));


const VkSamplerYcbcrConversionInfo = new C.CStruct("VkSamplerYcbcrConversionInfo", {
    sType: "u32("+callof(V.VkSamplerYcbcrConversionInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSamplerYcbcrConversionInfo_pNext_offsetof)+")",
    conversion: "u32("+callof(V.VkSamplerYcbcrConversionInfo_conversion_offsetof)+")",
}, callof(V.VkSamplerYcbcrConversionInfo_sizeof));


const VkSamplerYcbcrConversionInfoKHR = new C.CStruct("VkSamplerYcbcrConversionInfoKHR", {

}, callof(V.VkSamplerYcbcrConversionInfoKHR_sizeof));


const VkSamplerYcbcrConversionCreateInfo = new C.CStruct("VkSamplerYcbcrConversionCreateInfo", {
    sType: "u32("+callof(V.VkSamplerYcbcrConversionCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSamplerYcbcrConversionCreateInfo_pNext_offsetof)+")",
    format: "u32("+callof(V.VkSamplerYcbcrConversionCreateInfo_format_offsetof)+")",
    ycbcrModel: "u32("+callof(V.VkSamplerYcbcrConversionCreateInfo_ycbcrModel_offsetof)+")",
    ycbcrRange: "u32("+callof(V.VkSamplerYcbcrConversionCreateInfo_ycbcrRange_offsetof)+")",
    components: "u32("+callof(V.VkSamplerYcbcrConversionCreateInfo_components_offsetof)+")",
    xChromaOffset: "u32("+callof(V.VkSamplerYcbcrConversionCreateInfo_xChromaOffset_offsetof)+")",
    yChromaOffset: "u32("+callof(V.VkSamplerYcbcrConversionCreateInfo_yChromaOffset_offsetof)+")",
    chromaFilter: "u32("+callof(V.VkSamplerYcbcrConversionCreateInfo_chromaFilter_offsetof)+")",
    forceExplicitReconstruction: "u32("+callof(V.VkSamplerYcbcrConversionCreateInfo_forceExplicitReconstruction_offsetof)+")",
}, callof(V.VkSamplerYcbcrConversionCreateInfo_sizeof));


const VkSamplerYcbcrConversionCreateInfoKHR = new C.CStruct("VkSamplerYcbcrConversionCreateInfoKHR", {

}, callof(V.VkSamplerYcbcrConversionCreateInfoKHR_sizeof));


const VkBindImagePlaneMemoryInfo = new C.CStruct("VkBindImagePlaneMemoryInfo", {
    sType: "u32("+callof(V.VkBindImagePlaneMemoryInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBindImagePlaneMemoryInfo_pNext_offsetof)+")",
    planeAspect: "u32("+callof(V.VkBindImagePlaneMemoryInfo_planeAspect_offsetof)+")",
}, callof(V.VkBindImagePlaneMemoryInfo_sizeof));


const VkBindImagePlaneMemoryInfoKHR = new C.CStruct("VkBindImagePlaneMemoryInfoKHR", {

}, callof(V.VkBindImagePlaneMemoryInfoKHR_sizeof));


const VkImagePlaneMemoryRequirementsInfo = new C.CStruct("VkImagePlaneMemoryRequirementsInfo", {
    sType: "u32("+callof(V.VkImagePlaneMemoryRequirementsInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImagePlaneMemoryRequirementsInfo_pNext_offsetof)+")",
    planeAspect: "u32("+callof(V.VkImagePlaneMemoryRequirementsInfo_planeAspect_offsetof)+")",
}, callof(V.VkImagePlaneMemoryRequirementsInfo_sizeof));


const VkImagePlaneMemoryRequirementsInfoKHR = new C.CStruct("VkImagePlaneMemoryRequirementsInfoKHR", {

}, callof(V.VkImagePlaneMemoryRequirementsInfoKHR_sizeof));


const VkPhysicalDeviceSamplerYcbcrConversionFeatures = new C.CStruct("VkPhysicalDeviceSamplerYcbcrConversionFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceSamplerYcbcrConversionFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSamplerYcbcrConversionFeatures_pNext_offsetof)+")",
    samplerYcbcrConversion: "u32("+callof(V.VkPhysicalDeviceSamplerYcbcrConversionFeatures_samplerYcbcrConversion_offsetof)+")",
}, callof(V.VkPhysicalDeviceSamplerYcbcrConversionFeatures_sizeof));


const VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR = new C.CStruct("VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR", {

}, callof(V.VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR_sizeof));


const VkSamplerYcbcrConversionImageFormatProperties = new C.CStruct("VkSamplerYcbcrConversionImageFormatProperties", {
    sType: "u32("+callof(V.VkSamplerYcbcrConversionImageFormatProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSamplerYcbcrConversionImageFormatProperties_pNext_offsetof)+")",
    combinedImageSamplerDescriptorCount: "u32("+callof(V.VkSamplerYcbcrConversionImageFormatProperties_combinedImageSamplerDescriptorCount_offsetof)+")",
}, callof(V.VkSamplerYcbcrConversionImageFormatProperties_sizeof));


const VkSamplerYcbcrConversionImageFormatPropertiesKHR = new C.CStruct("VkSamplerYcbcrConversionImageFormatPropertiesKHR", {

}, callof(V.VkSamplerYcbcrConversionImageFormatPropertiesKHR_sizeof));


const VkTextureLODGatherFormatPropertiesAMD = new C.CStruct("VkTextureLODGatherFormatPropertiesAMD", {
    sType: "u32("+callof(V.VkTextureLODGatherFormatPropertiesAMD_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkTextureLODGatherFormatPropertiesAMD_pNext_offsetof)+")",
    supportsTextureGatherLODBiasAMD: "u32("+callof(V.VkTextureLODGatherFormatPropertiesAMD_supportsTextureGatherLODBiasAMD_offsetof)+")",
}, callof(V.VkTextureLODGatherFormatPropertiesAMD_sizeof));


const VkConditionalRenderingBeginInfoEXT = new C.CStruct("VkConditionalRenderingBeginInfoEXT", {
    sType: "u32("+callof(V.VkConditionalRenderingBeginInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkConditionalRenderingBeginInfoEXT_pNext_offsetof)+")",
    buffer: "u64("+callof(V.VkConditionalRenderingBeginInfoEXT_buffer_offsetof)+")",
    offset: "u64("+callof(V.VkConditionalRenderingBeginInfoEXT_offset_offsetof)+")",
    flags: "u32("+callof(V.VkConditionalRenderingBeginInfoEXT_flags_offsetof)+")",
}, callof(V.VkConditionalRenderingBeginInfoEXT_sizeof));


const VkProtectedSubmitInfo = new C.CStruct("VkProtectedSubmitInfo", {
    sType: "u32("+callof(V.VkProtectedSubmitInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkProtectedSubmitInfo_pNext_offsetof)+")",
    protectedSubmit: "u32("+callof(V.VkProtectedSubmitInfo_protectedSubmit_offsetof)+")",
}, callof(V.VkProtectedSubmitInfo_sizeof));


const VkPhysicalDeviceProtectedMemoryFeatures = new C.CStruct("VkPhysicalDeviceProtectedMemoryFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceProtectedMemoryFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceProtectedMemoryFeatures_pNext_offsetof)+")",
    protectedMemory: "u32("+callof(V.VkPhysicalDeviceProtectedMemoryFeatures_protectedMemory_offsetof)+")",
}, callof(V.VkPhysicalDeviceProtectedMemoryFeatures_sizeof));


const VkPhysicalDeviceProtectedMemoryProperties = new C.CStruct("VkPhysicalDeviceProtectedMemoryProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceProtectedMemoryProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceProtectedMemoryProperties_pNext_offsetof)+")",
    protectedNoFault: "u32("+callof(V.VkPhysicalDeviceProtectedMemoryProperties_protectedNoFault_offsetof)+")",
}, callof(V.VkPhysicalDeviceProtectedMemoryProperties_sizeof));


const VkDeviceQueueInfo2 = new C.CStruct("VkDeviceQueueInfo2", {
    sType: "u32("+callof(V.VkDeviceQueueInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceQueueInfo2_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDeviceQueueInfo2_flags_offsetof)+")",
    queueFamilyIndex: "u32("+callof(V.VkDeviceQueueInfo2_queueFamilyIndex_offsetof)+")",
    queueIndex: "u32("+callof(V.VkDeviceQueueInfo2_queueIndex_offsetof)+")",
}, callof(V.VkDeviceQueueInfo2_sizeof));


const VkPipelineCoverageToColorStateCreateInfoNV = new C.CStruct("VkPipelineCoverageToColorStateCreateInfoNV", {
    sType: "u32("+callof(V.VkPipelineCoverageToColorStateCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineCoverageToColorStateCreateInfoNV_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineCoverageToColorStateCreateInfoNV_flags_offsetof)+")",
    coverageToColorEnable: "u32("+callof(V.VkPipelineCoverageToColorStateCreateInfoNV_coverageToColorEnable_offsetof)+")",
    coverageToColorLocation: "u32("+callof(V.VkPipelineCoverageToColorStateCreateInfoNV_coverageToColorLocation_offsetof)+")",
}, callof(V.VkPipelineCoverageToColorStateCreateInfoNV_sizeof));


const VkPhysicalDeviceSamplerFilterMinmaxProperties = new C.CStruct("VkPhysicalDeviceSamplerFilterMinmaxProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceSamplerFilterMinmaxProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSamplerFilterMinmaxProperties_pNext_offsetof)+")",
    filterMinmaxSingleComponentFormats: "u32("+callof(V.VkPhysicalDeviceSamplerFilterMinmaxProperties_filterMinmaxSingleComponentFormats_offsetof)+")",
    filterMinmaxImageComponentMapping: "u32("+callof(V.VkPhysicalDeviceSamplerFilterMinmaxProperties_filterMinmaxImageComponentMapping_offsetof)+")",
}, callof(V.VkPhysicalDeviceSamplerFilterMinmaxProperties_sizeof));


const VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT = new C.CStruct("VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT", {

}, callof(V.VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT_sizeof));


const VkSampleLocationEXT = new C.CStruct("VkSampleLocationEXT", {
    x: "f32("+callof(V.VkSampleLocationEXT_x_offsetof)+")",
    y: "f32("+callof(V.VkSampleLocationEXT_y_offsetof)+")",
}, callof(V.VkSampleLocationEXT_sizeof));


const VkSampleLocationsInfoEXT = new C.CStruct("VkSampleLocationsInfoEXT", {
    sType: "u32("+callof(V.VkSampleLocationsInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSampleLocationsInfoEXT_pNext_offsetof)+")",
    sampleLocationsPerPixel: "u32("+callof(V.VkSampleLocationsInfoEXT_sampleLocationsPerPixel_offsetof)+")",
    sampleLocationGridSize: "VkExtent2D("+callof(V.VkSampleLocationsInfoEXT_sampleLocationGridSize_offsetof)+")",
    sampleLocationsCount: "u32("+callof(V.VkSampleLocationsInfoEXT_sampleLocationsCount_offsetof)+")",
    pSampleLocations: "u64("+callof(V.VkSampleLocationsInfoEXT_pSampleLocations_offsetof)+")",
}, callof(V.VkSampleLocationsInfoEXT_sizeof));


const VkAttachmentSampleLocationsEXT = new C.CStruct("VkAttachmentSampleLocationsEXT", {
    attachmentIndex: "u32("+callof(V.VkAttachmentSampleLocationsEXT_attachmentIndex_offsetof)+")",
    sampleLocationsInfo: "u32("+callof(V.VkAttachmentSampleLocationsEXT_sampleLocationsInfo_offsetof)+")",
}, callof(V.VkAttachmentSampleLocationsEXT_sizeof));


const VkSubpassSampleLocationsEXT = new C.CStruct("VkSubpassSampleLocationsEXT", {
    subpassIndex: "u32("+callof(V.VkSubpassSampleLocationsEXT_subpassIndex_offsetof)+")",
    sampleLocationsInfo: "u32("+callof(V.VkSubpassSampleLocationsEXT_sampleLocationsInfo_offsetof)+")",
}, callof(V.VkSubpassSampleLocationsEXT_sizeof));


const VkRenderPassSampleLocationsBeginInfoEXT = new C.CStruct("VkRenderPassSampleLocationsBeginInfoEXT", {
    sType: "u32("+callof(V.VkRenderPassSampleLocationsBeginInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderPassSampleLocationsBeginInfoEXT_pNext_offsetof)+")",
    attachmentInitialSampleLocationsCount: "u32("+callof(V.VkRenderPassSampleLocationsBeginInfoEXT_attachmentInitialSampleLocationsCount_offsetof)+")",
    pAttachmentInitialSampleLocations: "u64("+callof(V.VkRenderPassSampleLocationsBeginInfoEXT_pAttachmentInitialSampleLocations_offsetof)+")",
    postSubpassSampleLocationsCount: "u32("+callof(V.VkRenderPassSampleLocationsBeginInfoEXT_postSubpassSampleLocationsCount_offsetof)+")",
    pPostSubpassSampleLocations: "u64("+callof(V.VkRenderPassSampleLocationsBeginInfoEXT_pPostSubpassSampleLocations_offsetof)+")",
}, callof(V.VkRenderPassSampleLocationsBeginInfoEXT_sizeof));


const VkPipelineSampleLocationsStateCreateInfoEXT = new C.CStruct("VkPipelineSampleLocationsStateCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineSampleLocationsStateCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineSampleLocationsStateCreateInfoEXT_pNext_offsetof)+")",
    sampleLocationsEnable: "u32("+callof(V.VkPipelineSampleLocationsStateCreateInfoEXT_sampleLocationsEnable_offsetof)+")",
    sampleLocationsInfo: "u32("+callof(V.VkPipelineSampleLocationsStateCreateInfoEXT_sampleLocationsInfo_offsetof)+")",
}, callof(V.VkPipelineSampleLocationsStateCreateInfoEXT_sizeof));


const VkPhysicalDeviceSampleLocationsPropertiesEXT = new C.CStruct("VkPhysicalDeviceSampleLocationsPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_pNext_offsetof)+")",
    sampleLocationSampleCounts: "u32("+callof(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_sampleLocationSampleCounts_offsetof)+")",
    maxSampleLocationGridSize: "VkExtent2D("+callof(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_maxSampleLocationGridSize_offsetof)+")",
    sampleLocationCoordinateRange: "f32[2]("+callof(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_sampleLocationCoordinateRange_offsetof)+")",
    sampleLocationSubPixelBits: "u32("+callof(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_sampleLocationSubPixelBits_offsetof)+")",
    variableSampleLocations: "u32("+callof(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_variableSampleLocations_offsetof)+")",
}, callof(V.VkPhysicalDeviceSampleLocationsPropertiesEXT_sizeof));


const VkMultisamplePropertiesEXT = new C.CStruct("VkMultisamplePropertiesEXT", {
    sType: "u32("+callof(V.VkMultisamplePropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMultisamplePropertiesEXT_pNext_offsetof)+")",
    maxSampleLocationGridSize: "VkExtent2D("+callof(V.VkMultisamplePropertiesEXT_maxSampleLocationGridSize_offsetof)+")",
}, callof(V.VkMultisamplePropertiesEXT_sizeof));


const VkSamplerReductionModeCreateInfo = new C.CStruct("VkSamplerReductionModeCreateInfo", {
    sType: "u32("+callof(V.VkSamplerReductionModeCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSamplerReductionModeCreateInfo_pNext_offsetof)+")",
    reductionMode: "u32("+callof(V.VkSamplerReductionModeCreateInfo_reductionMode_offsetof)+")",
}, callof(V.VkSamplerReductionModeCreateInfo_sizeof));


const VkSamplerReductionModeCreateInfoEXT = new C.CStruct("VkSamplerReductionModeCreateInfoEXT", {

}, callof(V.VkSamplerReductionModeCreateInfoEXT_sizeof));


const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT = new C.CStruct("VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT_pNext_offsetof)+")",
    advancedBlendCoherentOperations: "u32("+callof(V.VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT_advancedBlendCoherentOperations_offsetof)+")",
}, callof(V.VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT_sizeof));


const VkPhysicalDeviceMultiDrawFeaturesEXT = new C.CStruct("VkPhysicalDeviceMultiDrawFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceMultiDrawFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMultiDrawFeaturesEXT_pNext_offsetof)+")",
    multiDraw: "u32("+callof(V.VkPhysicalDeviceMultiDrawFeaturesEXT_multiDraw_offsetof)+")",
}, callof(V.VkPhysicalDeviceMultiDrawFeaturesEXT_sizeof));


const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT = new C.CStruct("VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_pNext_offsetof)+")",
    advancedBlendMaxColorAttachments: "u32("+callof(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_advancedBlendMaxColorAttachments_offsetof)+")",
    advancedBlendIndependentBlend: "u32("+callof(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_advancedBlendIndependentBlend_offsetof)+")",
    advancedBlendNonPremultipliedSrcColor: "u32("+callof(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_advancedBlendNonPremultipliedSrcColor_offsetof)+")",
    advancedBlendNonPremultipliedDstColor: "u32("+callof(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_advancedBlendNonPremultipliedDstColor_offsetof)+")",
    advancedBlendCorrelatedOverlap: "u32("+callof(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_advancedBlendCorrelatedOverlap_offsetof)+")",
    advancedBlendAllOperations: "u32("+callof(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_advancedBlendAllOperations_offsetof)+")",
}, callof(V.VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT_sizeof));


const VkPipelineColorBlendAdvancedStateCreateInfoEXT = new C.CStruct("VkPipelineColorBlendAdvancedStateCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineColorBlendAdvancedStateCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineColorBlendAdvancedStateCreateInfoEXT_pNext_offsetof)+")",
    srcPremultiplied: "u32("+callof(V.VkPipelineColorBlendAdvancedStateCreateInfoEXT_srcPremultiplied_offsetof)+")",
    dstPremultiplied: "u32("+callof(V.VkPipelineColorBlendAdvancedStateCreateInfoEXT_dstPremultiplied_offsetof)+")",
    blendOverlap: "u32("+callof(V.VkPipelineColorBlendAdvancedStateCreateInfoEXT_blendOverlap_offsetof)+")",
}, callof(V.VkPipelineColorBlendAdvancedStateCreateInfoEXT_sizeof));


const VkPhysicalDeviceInlineUniformBlockFeatures = new C.CStruct("VkPhysicalDeviceInlineUniformBlockFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceInlineUniformBlockFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceInlineUniformBlockFeatures_pNext_offsetof)+")",
    inlineUniformBlock: "u32("+callof(V.VkPhysicalDeviceInlineUniformBlockFeatures_inlineUniformBlock_offsetof)+")",
    descriptorBindingInlineUniformBlockUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceInlineUniformBlockFeatures_descriptorBindingInlineUniformBlockUpdateAfterBind_offsetof)+")",
}, callof(V.VkPhysicalDeviceInlineUniformBlockFeatures_sizeof));


const VkPhysicalDeviceInlineUniformBlockFeaturesEXT = new C.CStruct("VkPhysicalDeviceInlineUniformBlockFeaturesEXT", {

}, callof(V.VkPhysicalDeviceInlineUniformBlockFeaturesEXT_sizeof));


const VkPhysicalDeviceInlineUniformBlockProperties = new C.CStruct("VkPhysicalDeviceInlineUniformBlockProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceInlineUniformBlockProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceInlineUniformBlockProperties_pNext_offsetof)+")",
    maxInlineUniformBlockSize: "u32("+callof(V.VkPhysicalDeviceInlineUniformBlockProperties_maxInlineUniformBlockSize_offsetof)+")",
    maxPerStageDescriptorInlineUniformBlocks: "u32("+callof(V.VkPhysicalDeviceInlineUniformBlockProperties_maxPerStageDescriptorInlineUniformBlocks_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks: "u32("+callof(V.VkPhysicalDeviceInlineUniformBlockProperties_maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks_offsetof)+")",
    maxDescriptorSetInlineUniformBlocks: "u32("+callof(V.VkPhysicalDeviceInlineUniformBlockProperties_maxDescriptorSetInlineUniformBlocks_offsetof)+")",
    maxDescriptorSetUpdateAfterBindInlineUniformBlocks: "u32("+callof(V.VkPhysicalDeviceInlineUniformBlockProperties_maxDescriptorSetUpdateAfterBindInlineUniformBlocks_offsetof)+")",
}, callof(V.VkPhysicalDeviceInlineUniformBlockProperties_sizeof));


const VkPhysicalDeviceInlineUniformBlockPropertiesEXT = new C.CStruct("VkPhysicalDeviceInlineUniformBlockPropertiesEXT", {

}, callof(V.VkPhysicalDeviceInlineUniformBlockPropertiesEXT_sizeof));


const VkWriteDescriptorSetInlineUniformBlock = new C.CStruct("VkWriteDescriptorSetInlineUniformBlock", {
    sType: "u32("+callof(V.VkWriteDescriptorSetInlineUniformBlock_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkWriteDescriptorSetInlineUniformBlock_pNext_offsetof)+")",
    dataSize: "u32("+callof(V.VkWriteDescriptorSetInlineUniformBlock_dataSize_offsetof)+")",
    pData: "u64("+callof(V.VkWriteDescriptorSetInlineUniformBlock_pData_offsetof)+")",
}, callof(V.VkWriteDescriptorSetInlineUniformBlock_sizeof));


const VkWriteDescriptorSetInlineUniformBlockEXT = new C.CStruct("VkWriteDescriptorSetInlineUniformBlockEXT", {

}, callof(V.VkWriteDescriptorSetInlineUniformBlockEXT_sizeof));


const VkDescriptorPoolInlineUniformBlockCreateInfo = new C.CStruct("VkDescriptorPoolInlineUniformBlockCreateInfo", {
    sType: "u32("+callof(V.VkDescriptorPoolInlineUniformBlockCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDescriptorPoolInlineUniformBlockCreateInfo_pNext_offsetof)+")",
    maxInlineUniformBlockBindings: "u32("+callof(V.VkDescriptorPoolInlineUniformBlockCreateInfo_maxInlineUniformBlockBindings_offsetof)+")",
}, callof(V.VkDescriptorPoolInlineUniformBlockCreateInfo_sizeof));


const VkDescriptorPoolInlineUniformBlockCreateInfoEXT = new C.CStruct("VkDescriptorPoolInlineUniformBlockCreateInfoEXT", {

}, callof(V.VkDescriptorPoolInlineUniformBlockCreateInfoEXT_sizeof));


const VkPipelineCoverageModulationStateCreateInfoNV = new C.CStruct("VkPipelineCoverageModulationStateCreateInfoNV", {
    sType: "u32("+callof(V.VkPipelineCoverageModulationStateCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineCoverageModulationStateCreateInfoNV_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineCoverageModulationStateCreateInfoNV_flags_offsetof)+")",
    coverageModulationMode: "u32("+callof(V.VkPipelineCoverageModulationStateCreateInfoNV_coverageModulationMode_offsetof)+")",
    coverageModulationTableEnable: "u32("+callof(V.VkPipelineCoverageModulationStateCreateInfoNV_coverageModulationTableEnable_offsetof)+")",
    coverageModulationTableCount: "u32("+callof(V.VkPipelineCoverageModulationStateCreateInfoNV_coverageModulationTableCount_offsetof)+")",
    pCoverageModulationTable: "u64("+callof(V.VkPipelineCoverageModulationStateCreateInfoNV_pCoverageModulationTable_offsetof)+")",
}, callof(V.VkPipelineCoverageModulationStateCreateInfoNV_sizeof));


const VkImageFormatListCreateInfo = new C.CStruct("VkImageFormatListCreateInfo", {
    sType: "u32("+callof(V.VkImageFormatListCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageFormatListCreateInfo_pNext_offsetof)+")",
    viewFormatCount: "u32("+callof(V.VkImageFormatListCreateInfo_viewFormatCount_offsetof)+")",
    pViewFormats: "u64("+callof(V.VkImageFormatListCreateInfo_pViewFormats_offsetof)+")",
}, callof(V.VkImageFormatListCreateInfo_sizeof));


const VkImageFormatListCreateInfoKHR = new C.CStruct("VkImageFormatListCreateInfoKHR", {

}, callof(V.VkImageFormatListCreateInfoKHR_sizeof));


const VkValidationCacheCreateInfoEXT = new C.CStruct("VkValidationCacheCreateInfoEXT", {
    sType: "u32("+callof(V.VkValidationCacheCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkValidationCacheCreateInfoEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkValidationCacheCreateInfoEXT_flags_offsetof)+")",
    initialDataSize: "u64("+callof(V.VkValidationCacheCreateInfoEXT_initialDataSize_offsetof)+")",
    pInitialData: "u64("+callof(V.VkValidationCacheCreateInfoEXT_pInitialData_offsetof)+")",
}, callof(V.VkValidationCacheCreateInfoEXT_sizeof));


const VkShaderModuleValidationCacheCreateInfoEXT = new C.CStruct("VkShaderModuleValidationCacheCreateInfoEXT", {
    sType: "u32("+callof(V.VkShaderModuleValidationCacheCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkShaderModuleValidationCacheCreateInfoEXT_pNext_offsetof)+")",
    validationCache: "u32("+callof(V.VkShaderModuleValidationCacheCreateInfoEXT_validationCache_offsetof)+")",
}, callof(V.VkShaderModuleValidationCacheCreateInfoEXT_sizeof));


const VkPhysicalDeviceMaintenance3Properties = new C.CStruct("VkPhysicalDeviceMaintenance3Properties", {
    sType: "u32("+callof(V.VkPhysicalDeviceMaintenance3Properties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMaintenance3Properties_pNext_offsetof)+")",
    maxPerSetDescriptors: "u32("+callof(V.VkPhysicalDeviceMaintenance3Properties_maxPerSetDescriptors_offsetof)+")",
    maxMemoryAllocationSize: "u64("+callof(V.VkPhysicalDeviceMaintenance3Properties_maxMemoryAllocationSize_offsetof)+")",
}, callof(V.VkPhysicalDeviceMaintenance3Properties_sizeof));


const VkPhysicalDeviceMaintenance3PropertiesKHR = new C.CStruct("VkPhysicalDeviceMaintenance3PropertiesKHR", {

}, callof(V.VkPhysicalDeviceMaintenance3PropertiesKHR_sizeof));


const VkPhysicalDeviceMaintenance4Features = new C.CStruct("VkPhysicalDeviceMaintenance4Features", {
    sType: "u32("+callof(V.VkPhysicalDeviceMaintenance4Features_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMaintenance4Features_pNext_offsetof)+")",
    maintenance4: "u32("+callof(V.VkPhysicalDeviceMaintenance4Features_maintenance4_offsetof)+")",
}, callof(V.VkPhysicalDeviceMaintenance4Features_sizeof));


const VkPhysicalDeviceMaintenance4FeaturesKHR = new C.CStruct("VkPhysicalDeviceMaintenance4FeaturesKHR", {

}, callof(V.VkPhysicalDeviceMaintenance4FeaturesKHR_sizeof));


const VkPhysicalDeviceMaintenance4Properties = new C.CStruct("VkPhysicalDeviceMaintenance4Properties", {
    sType: "u32("+callof(V.VkPhysicalDeviceMaintenance4Properties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMaintenance4Properties_pNext_offsetof)+")",
    maxBufferSize: "u64("+callof(V.VkPhysicalDeviceMaintenance4Properties_maxBufferSize_offsetof)+")",
}, callof(V.VkPhysicalDeviceMaintenance4Properties_sizeof));


const VkPhysicalDeviceMaintenance4PropertiesKHR = new C.CStruct("VkPhysicalDeviceMaintenance4PropertiesKHR", {

}, callof(V.VkPhysicalDeviceMaintenance4PropertiesKHR_sizeof));


const VkDescriptorSetLayoutSupport = new C.CStruct("VkDescriptorSetLayoutSupport", {
    sType: "u32("+callof(V.VkDescriptorSetLayoutSupport_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDescriptorSetLayoutSupport_pNext_offsetof)+")",
    supported: "u32("+callof(V.VkDescriptorSetLayoutSupport_supported_offsetof)+")",
}, callof(V.VkDescriptorSetLayoutSupport_sizeof));


const VkDescriptorSetLayoutSupportKHR = new C.CStruct("VkDescriptorSetLayoutSupportKHR", {

}, callof(V.VkDescriptorSetLayoutSupportKHR_sizeof));


const VkPhysicalDeviceShaderDrawParametersFeatures = new C.CStruct("VkPhysicalDeviceShaderDrawParametersFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderDrawParametersFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderDrawParametersFeatures_pNext_offsetof)+")",
    shaderDrawParameters: "u32("+callof(V.VkPhysicalDeviceShaderDrawParametersFeatures_shaderDrawParameters_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderDrawParametersFeatures_sizeof));


const VkPhysicalDeviceShaderDrawParameterFeatures = new C.CStruct("VkPhysicalDeviceShaderDrawParameterFeatures", {

}, callof(V.VkPhysicalDeviceShaderDrawParameterFeatures_sizeof));


const VkPhysicalDeviceShaderFloat16Int8Features = new C.CStruct("VkPhysicalDeviceShaderFloat16Int8Features", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderFloat16Int8Features_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderFloat16Int8Features_pNext_offsetof)+")",
    shaderFloat16: "u32("+callof(V.VkPhysicalDeviceShaderFloat16Int8Features_shaderFloat16_offsetof)+")",
    shaderInt8: "u32("+callof(V.VkPhysicalDeviceShaderFloat16Int8Features_shaderInt8_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderFloat16Int8Features_sizeof));


const VkPhysicalDeviceShaderFloat16Int8FeaturesKHR = new C.CStruct("VkPhysicalDeviceShaderFloat16Int8FeaturesKHR", {

}, callof(V.VkPhysicalDeviceShaderFloat16Int8FeaturesKHR_sizeof));


const VkPhysicalDeviceFloat16Int8FeaturesKHR = new C.CStruct("VkPhysicalDeviceFloat16Int8FeaturesKHR", {

}, callof(V.VkPhysicalDeviceFloat16Int8FeaturesKHR_sizeof));


const VkPhysicalDeviceFloatControlsProperties = new C.CStruct("VkPhysicalDeviceFloatControlsProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFloatControlsProperties_pNext_offsetof)+")",
    denormBehaviorIndependence: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_denormBehaviorIndependence_offsetof)+")",
    roundingModeIndependence: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_roundingModeIndependence_offsetof)+")",
    shaderSignedZeroInfNanPreserveFloat16: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderSignedZeroInfNanPreserveFloat16_offsetof)+")",
    shaderSignedZeroInfNanPreserveFloat32: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderSignedZeroInfNanPreserveFloat32_offsetof)+")",
    shaderSignedZeroInfNanPreserveFloat64: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderSignedZeroInfNanPreserveFloat64_offsetof)+")",
    shaderDenormPreserveFloat16: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderDenormPreserveFloat16_offsetof)+")",
    shaderDenormPreserveFloat32: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderDenormPreserveFloat32_offsetof)+")",
    shaderDenormPreserveFloat64: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderDenormPreserveFloat64_offsetof)+")",
    shaderDenormFlushToZeroFloat16: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderDenormFlushToZeroFloat16_offsetof)+")",
    shaderDenormFlushToZeroFloat32: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderDenormFlushToZeroFloat32_offsetof)+")",
    shaderDenormFlushToZeroFloat64: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderDenormFlushToZeroFloat64_offsetof)+")",
    shaderRoundingModeRTEFloat16: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderRoundingModeRTEFloat16_offsetof)+")",
    shaderRoundingModeRTEFloat32: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderRoundingModeRTEFloat32_offsetof)+")",
    shaderRoundingModeRTEFloat64: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderRoundingModeRTEFloat64_offsetof)+")",
    shaderRoundingModeRTZFloat16: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderRoundingModeRTZFloat16_offsetof)+")",
    shaderRoundingModeRTZFloat32: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderRoundingModeRTZFloat32_offsetof)+")",
    shaderRoundingModeRTZFloat64: "u32("+callof(V.VkPhysicalDeviceFloatControlsProperties_shaderRoundingModeRTZFloat64_offsetof)+")",
}, callof(V.VkPhysicalDeviceFloatControlsProperties_sizeof));


const VkPhysicalDeviceFloatControlsPropertiesKHR = new C.CStruct("VkPhysicalDeviceFloatControlsPropertiesKHR", {

}, callof(V.VkPhysicalDeviceFloatControlsPropertiesKHR_sizeof));


const VkPhysicalDeviceHostQueryResetFeatures = new C.CStruct("VkPhysicalDeviceHostQueryResetFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceHostQueryResetFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceHostQueryResetFeatures_pNext_offsetof)+")",
    hostQueryReset: "u32("+callof(V.VkPhysicalDeviceHostQueryResetFeatures_hostQueryReset_offsetof)+")",
}, callof(V.VkPhysicalDeviceHostQueryResetFeatures_sizeof));


const VkPhysicalDeviceHostQueryResetFeaturesEXT = new C.CStruct("VkPhysicalDeviceHostQueryResetFeaturesEXT", {

}, callof(V.VkPhysicalDeviceHostQueryResetFeaturesEXT_sizeof));


const VkNativeBufferUsage2ANDROID = new C.CStruct("VkNativeBufferUsage2ANDROID", {
    consumer: "u64("+callof(V.VkNativeBufferUsage2ANDROID_consumer_offsetof)+")",
    producer: "u64("+callof(V.VkNativeBufferUsage2ANDROID_producer_offsetof)+")",
}, callof(V.VkNativeBufferUsage2ANDROID_sizeof));


const VkNativeBufferANDROID = new C.CStruct("VkNativeBufferANDROID", {
    sType: "u32("+callof(V.VkNativeBufferANDROID_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkNativeBufferANDROID_pNext_offsetof)+")",
    handle: "u64("+callof(V.VkNativeBufferANDROID_handle_offsetof)+")",
    stride: "u32("+callof(V.VkNativeBufferANDROID_stride_offsetof)+")",
    format: "u32("+callof(V.VkNativeBufferANDROID_format_offsetof)+")",
    usage: "u32("+callof(V.VkNativeBufferANDROID_usage_offsetof)+")",
    usage2: "u32("+callof(V.VkNativeBufferANDROID_usage2_offsetof)+")",
}, callof(V.VkNativeBufferANDROID_sizeof));


const VkSwapchainImageCreateInfoANDROID = new C.CStruct("VkSwapchainImageCreateInfoANDROID", {
    sType: "u32("+callof(V.VkSwapchainImageCreateInfoANDROID_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSwapchainImageCreateInfoANDROID_pNext_offsetof)+")",
    usage: "u32("+callof(V.VkSwapchainImageCreateInfoANDROID_usage_offsetof)+")",
}, callof(V.VkSwapchainImageCreateInfoANDROID_sizeof));


const VkPhysicalDevicePresentationPropertiesANDROID = new C.CStruct("VkPhysicalDevicePresentationPropertiesANDROID", {
    sType: "u32("+callof(V.VkPhysicalDevicePresentationPropertiesANDROID_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePresentationPropertiesANDROID_pNext_offsetof)+")",
    sharedImage: "u32("+callof(V.VkPhysicalDevicePresentationPropertiesANDROID_sharedImage_offsetof)+")",
}, callof(V.VkPhysicalDevicePresentationPropertiesANDROID_sizeof));


const VkShaderResourceUsageAMD = new C.CStruct("VkShaderResourceUsageAMD", {
    numUsedVgprs: "u32("+callof(V.VkShaderResourceUsageAMD_numUsedVgprs_offsetof)+")",
    numUsedSgprs: "u32("+callof(V.VkShaderResourceUsageAMD_numUsedSgprs_offsetof)+")",
    ldsSizePerLocalWorkGroup: "u32("+callof(V.VkShaderResourceUsageAMD_ldsSizePerLocalWorkGroup_offsetof)+")",
    ldsUsageSizeInBytes: "u64("+callof(V.VkShaderResourceUsageAMD_ldsUsageSizeInBytes_offsetof)+")",
    scratchMemUsageInBytes: "u64("+callof(V.VkShaderResourceUsageAMD_scratchMemUsageInBytes_offsetof)+")",
}, callof(V.VkShaderResourceUsageAMD_sizeof));


const VkShaderStatisticsInfoAMD = new C.CStruct("VkShaderStatisticsInfoAMD", {
    shaderStageMask: "u32("+callof(V.VkShaderStatisticsInfoAMD_shaderStageMask_offsetof)+")",
    resourceUsage: "u32("+callof(V.VkShaderStatisticsInfoAMD_resourceUsage_offsetof)+")",
    numPhysicalVgprs: "u32("+callof(V.VkShaderStatisticsInfoAMD_numPhysicalVgprs_offsetof)+")",
    numPhysicalSgprs: "u32("+callof(V.VkShaderStatisticsInfoAMD_numPhysicalSgprs_offsetof)+")",
    numAvailableVgprs: "u32("+callof(V.VkShaderStatisticsInfoAMD_numAvailableVgprs_offsetof)+")",
    numAvailableSgprs: "u32("+callof(V.VkShaderStatisticsInfoAMD_numAvailableSgprs_offsetof)+")",
    computeWorkGroupSize: "u32[3]("+callof(V.VkShaderStatisticsInfoAMD_computeWorkGroupSize_offsetof)+")",
}, callof(V.VkShaderStatisticsInfoAMD_sizeof));


const VkDeviceQueueGlobalPriorityCreateInfoKHR = new C.CStruct("VkDeviceQueueGlobalPriorityCreateInfoKHR", {
    sType: "u32("+callof(V.VkDeviceQueueGlobalPriorityCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceQueueGlobalPriorityCreateInfoKHR_pNext_offsetof)+")",
    globalPriority: "u32("+callof(V.VkDeviceQueueGlobalPriorityCreateInfoKHR_globalPriority_offsetof)+")",
}, callof(V.VkDeviceQueueGlobalPriorityCreateInfoKHR_sizeof));


const VkDeviceQueueGlobalPriorityCreateInfoEXT = new C.CStruct("VkDeviceQueueGlobalPriorityCreateInfoEXT", {

}, callof(V.VkDeviceQueueGlobalPriorityCreateInfoEXT_sizeof));


const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR = new C.CStruct("VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR_pNext_offsetof)+")",
    globalPriorityQuery: "u32("+callof(V.VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR_globalPriorityQuery_offsetof)+")",
}, callof(V.VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR_sizeof));


const VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT = new C.CStruct("VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT", {

}, callof(V.VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT_sizeof));


const VkQueueFamilyGlobalPriorityPropertiesKHR = new C.CStruct("VkQueueFamilyGlobalPriorityPropertiesKHR", {
    sType: "u32("+callof(V.VkQueueFamilyGlobalPriorityPropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkQueueFamilyGlobalPriorityPropertiesKHR_pNext_offsetof)+")",
    priorityCount: "u32("+callof(V.VkQueueFamilyGlobalPriorityPropertiesKHR_priorityCount_offsetof)+")",
    priorities: "u32["+(enums.NaN||1)+"]("+callof(V.VkQueueFamilyGlobalPriorityPropertiesKHR_priorities_offsetof)+")",
}, callof(V.VkQueueFamilyGlobalPriorityPropertiesKHR_sizeof));


const VkQueueFamilyGlobalPriorityPropertiesEXT = new C.CStruct("VkQueueFamilyGlobalPriorityPropertiesEXT", {

}, callof(V.VkQueueFamilyGlobalPriorityPropertiesEXT_sizeof));


const VkDebugUtilsObjectNameInfoEXT = new C.CStruct("VkDebugUtilsObjectNameInfoEXT", {
    sType: "u32("+callof(V.VkDebugUtilsObjectNameInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDebugUtilsObjectNameInfoEXT_pNext_offsetof)+")",
    objectType: "u32("+callof(V.VkDebugUtilsObjectNameInfoEXT_objectType_offsetof)+")",
    objectHandle: "u64("+callof(V.VkDebugUtilsObjectNameInfoEXT_objectHandle_offsetof)+")",
    pObjectName: "u64("+callof(V.VkDebugUtilsObjectNameInfoEXT_pObjectName_offsetof)+")",
}, callof(V.VkDebugUtilsObjectNameInfoEXT_sizeof));


const VkDebugUtilsObjectTagInfoEXT = new C.CStruct("VkDebugUtilsObjectTagInfoEXT", {
    sType: "u32("+callof(V.VkDebugUtilsObjectTagInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDebugUtilsObjectTagInfoEXT_pNext_offsetof)+")",
    objectType: "u32("+callof(V.VkDebugUtilsObjectTagInfoEXT_objectType_offsetof)+")",
    objectHandle: "u64("+callof(V.VkDebugUtilsObjectTagInfoEXT_objectHandle_offsetof)+")",
    tagName: "u64("+callof(V.VkDebugUtilsObjectTagInfoEXT_tagName_offsetof)+")",
    tagSize: "u64("+callof(V.VkDebugUtilsObjectTagInfoEXT_tagSize_offsetof)+")",
    pTag: "u64("+callof(V.VkDebugUtilsObjectTagInfoEXT_pTag_offsetof)+")",
}, callof(V.VkDebugUtilsObjectTagInfoEXT_sizeof));


const VkDebugUtilsLabelEXT = new C.CStruct("VkDebugUtilsLabelEXT", {
    sType: "u32("+callof(V.VkDebugUtilsLabelEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDebugUtilsLabelEXT_pNext_offsetof)+")",
    pLabelName: "u64("+callof(V.VkDebugUtilsLabelEXT_pLabelName_offsetof)+")",
    color: "f32[4]("+callof(V.VkDebugUtilsLabelEXT_color_offsetof)+")",
}, callof(V.VkDebugUtilsLabelEXT_sizeof));


const VkDebugUtilsMessengerCreateInfoEXT = new C.CStruct("VkDebugUtilsMessengerCreateInfoEXT", {
    sType: "u32("+callof(V.VkDebugUtilsMessengerCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDebugUtilsMessengerCreateInfoEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDebugUtilsMessengerCreateInfoEXT_flags_offsetof)+")",
    messageSeverity: "u32("+callof(V.VkDebugUtilsMessengerCreateInfoEXT_messageSeverity_offsetof)+")",
    messageType: "u32("+callof(V.VkDebugUtilsMessengerCreateInfoEXT_messageType_offsetof)+")",
    pfnUserCallback: "u32("+callof(V.VkDebugUtilsMessengerCreateInfoEXT_pfnUserCallback_offsetof)+")",
    pUserData: "u64("+callof(V.VkDebugUtilsMessengerCreateInfoEXT_pUserData_offsetof)+")",
}, callof(V.VkDebugUtilsMessengerCreateInfoEXT_sizeof));


const VkDebugUtilsMessengerCallbackDataEXT = new C.CStruct("VkDebugUtilsMessengerCallbackDataEXT", {
    sType: "u32("+callof(V.VkDebugUtilsMessengerCallbackDataEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDebugUtilsMessengerCallbackDataEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDebugUtilsMessengerCallbackDataEXT_flags_offsetof)+")",
    pMessageIdName: "u64("+callof(V.VkDebugUtilsMessengerCallbackDataEXT_pMessageIdName_offsetof)+")",
    messageIdNumber: "i32("+callof(V.VkDebugUtilsMessengerCallbackDataEXT_messageIdNumber_offsetof)+")",
    pMessage: "u64("+callof(V.VkDebugUtilsMessengerCallbackDataEXT_pMessage_offsetof)+")",
    queueLabelCount: "u32("+callof(V.VkDebugUtilsMessengerCallbackDataEXT_queueLabelCount_offsetof)+")",
    pQueueLabels: "u64("+callof(V.VkDebugUtilsMessengerCallbackDataEXT_pQueueLabels_offsetof)+")",
    cmdBufLabelCount: "u32("+callof(V.VkDebugUtilsMessengerCallbackDataEXT_cmdBufLabelCount_offsetof)+")",
    pCmdBufLabels: "u64("+callof(V.VkDebugUtilsMessengerCallbackDataEXT_pCmdBufLabels_offsetof)+")",
    objectCount: "u32("+callof(V.VkDebugUtilsMessengerCallbackDataEXT_objectCount_offsetof)+")",
    pObjects: "u64("+callof(V.VkDebugUtilsMessengerCallbackDataEXT_pObjects_offsetof)+")",
}, callof(V.VkDebugUtilsMessengerCallbackDataEXT_sizeof));


const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT = new C.CStruct("VkPhysicalDeviceDeviceMemoryReportFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceDeviceMemoryReportFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDeviceMemoryReportFeaturesEXT_pNext_offsetof)+")",
    deviceMemoryReport: "u32("+callof(V.VkPhysicalDeviceDeviceMemoryReportFeaturesEXT_deviceMemoryReport_offsetof)+")",
}, callof(V.VkPhysicalDeviceDeviceMemoryReportFeaturesEXT_sizeof));


const VkDeviceDeviceMemoryReportCreateInfoEXT = new C.CStruct("VkDeviceDeviceMemoryReportCreateInfoEXT", {
    sType: "u32("+callof(V.VkDeviceDeviceMemoryReportCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceDeviceMemoryReportCreateInfoEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDeviceDeviceMemoryReportCreateInfoEXT_flags_offsetof)+")",
    pfnUserCallback: "u32("+callof(V.VkDeviceDeviceMemoryReportCreateInfoEXT_pfnUserCallback_offsetof)+")",
    pUserData: "u64("+callof(V.VkDeviceDeviceMemoryReportCreateInfoEXT_pUserData_offsetof)+")",
}, callof(V.VkDeviceDeviceMemoryReportCreateInfoEXT_sizeof));


const VkDeviceMemoryReportCallbackDataEXT = new C.CStruct("VkDeviceMemoryReportCallbackDataEXT", {
    sType: "u32("+callof(V.VkDeviceMemoryReportCallbackDataEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceMemoryReportCallbackDataEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDeviceMemoryReportCallbackDataEXT_flags_offsetof)+")",
    type: "u32("+callof(V.VkDeviceMemoryReportCallbackDataEXT_type_offsetof)+")",
    memoryObjectId: "u64("+callof(V.VkDeviceMemoryReportCallbackDataEXT_memoryObjectId_offsetof)+")",
    size: "u64("+callof(V.VkDeviceMemoryReportCallbackDataEXT_size_offsetof)+")",
    objectType: "u32("+callof(V.VkDeviceMemoryReportCallbackDataEXT_objectType_offsetof)+")",
    objectHandle: "u64("+callof(V.VkDeviceMemoryReportCallbackDataEXT_objectHandle_offsetof)+")",
    heapIndex: "u32("+callof(V.VkDeviceMemoryReportCallbackDataEXT_heapIndex_offsetof)+")",
}, callof(V.VkDeviceMemoryReportCallbackDataEXT_sizeof));


const VkImportMemoryHostPointerInfoEXT = new C.CStruct("VkImportMemoryHostPointerInfoEXT", {
    sType: "u32("+callof(V.VkImportMemoryHostPointerInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportMemoryHostPointerInfoEXT_pNext_offsetof)+")",
    handleType: "u32("+callof(V.VkImportMemoryHostPointerInfoEXT_handleType_offsetof)+")",
    pHostPointer: "u64("+callof(V.VkImportMemoryHostPointerInfoEXT_pHostPointer_offsetof)+")",
}, callof(V.VkImportMemoryHostPointerInfoEXT_sizeof));


const VkMemoryHostPointerPropertiesEXT = new C.CStruct("VkMemoryHostPointerPropertiesEXT", {
    sType: "u32("+callof(V.VkMemoryHostPointerPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryHostPointerPropertiesEXT_pNext_offsetof)+")",
    memoryTypeBits: "u32("+callof(V.VkMemoryHostPointerPropertiesEXT_memoryTypeBits_offsetof)+")",
}, callof(V.VkMemoryHostPointerPropertiesEXT_sizeof));


const VkPhysicalDeviceExternalMemoryHostPropertiesEXT = new C.CStruct("VkPhysicalDeviceExternalMemoryHostPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceExternalMemoryHostPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceExternalMemoryHostPropertiesEXT_pNext_offsetof)+")",
    minImportedHostPointerAlignment: "u64("+callof(V.VkPhysicalDeviceExternalMemoryHostPropertiesEXT_minImportedHostPointerAlignment_offsetof)+")",
}, callof(V.VkPhysicalDeviceExternalMemoryHostPropertiesEXT_sizeof));


const VkPhysicalDeviceConservativeRasterizationPropertiesEXT = new C.CStruct("VkPhysicalDeviceConservativeRasterizationPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_pNext_offsetof)+")",
    primitiveOverestimationSize: "f32("+callof(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_primitiveOverestimationSize_offsetof)+")",
    maxExtraPrimitiveOverestimationSize: "f32("+callof(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_maxExtraPrimitiveOverestimationSize_offsetof)+")",
    extraPrimitiveOverestimationSizeGranularity: "f32("+callof(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_extraPrimitiveOverestimationSizeGranularity_offsetof)+")",
    primitiveUnderestimation: "u32("+callof(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_primitiveUnderestimation_offsetof)+")",
    conservativePointAndLineRasterization: "u32("+callof(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_conservativePointAndLineRasterization_offsetof)+")",
    degenerateTrianglesRasterized: "u32("+callof(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_degenerateTrianglesRasterized_offsetof)+")",
    degenerateLinesRasterized: "u32("+callof(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_degenerateLinesRasterized_offsetof)+")",
    fullyCoveredFragmentShaderInputVariable: "u32("+callof(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_fullyCoveredFragmentShaderInputVariable_offsetof)+")",
    conservativeRasterizationPostDepthCoverage: "u32("+callof(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_conservativeRasterizationPostDepthCoverage_offsetof)+")",
}, callof(V.VkPhysicalDeviceConservativeRasterizationPropertiesEXT_sizeof));


const VkCalibratedTimestampInfoEXT = new C.CStruct("VkCalibratedTimestampInfoEXT", {
    sType: "u32("+callof(V.VkCalibratedTimestampInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCalibratedTimestampInfoEXT_pNext_offsetof)+")",
    timeDomain: "u32("+callof(V.VkCalibratedTimestampInfoEXT_timeDomain_offsetof)+")",
}, callof(V.VkCalibratedTimestampInfoEXT_sizeof));


const VkPhysicalDeviceShaderCorePropertiesAMD = new C.CStruct("VkPhysicalDeviceShaderCorePropertiesAMD", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_pNext_offsetof)+")",
    shaderEngineCount: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_shaderEngineCount_offsetof)+")",
    shaderArraysPerEngineCount: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_shaderArraysPerEngineCount_offsetof)+")",
    computeUnitsPerShaderArray: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_computeUnitsPerShaderArray_offsetof)+")",
    simdPerComputeUnit: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_simdPerComputeUnit_offsetof)+")",
    wavefrontsPerSimd: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_wavefrontsPerSimd_offsetof)+")",
    wavefrontSize: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_wavefrontSize_offsetof)+")",
    sgprsPerSimd: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_sgprsPerSimd_offsetof)+")",
    minSgprAllocation: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_minSgprAllocation_offsetof)+")",
    maxSgprAllocation: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_maxSgprAllocation_offsetof)+")",
    sgprAllocationGranularity: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_sgprAllocationGranularity_offsetof)+")",
    vgprsPerSimd: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_vgprsPerSimd_offsetof)+")",
    minVgprAllocation: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_minVgprAllocation_offsetof)+")",
    maxVgprAllocation: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_maxVgprAllocation_offsetof)+")",
    vgprAllocationGranularity: "u32("+callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_vgprAllocationGranularity_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderCorePropertiesAMD_sizeof));


const VkPhysicalDeviceShaderCoreProperties2AMD = new C.CStruct("VkPhysicalDeviceShaderCoreProperties2AMD", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderCoreProperties2AMD_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderCoreProperties2AMD_pNext_offsetof)+")",
    shaderCoreFeatures: "u32("+callof(V.VkPhysicalDeviceShaderCoreProperties2AMD_shaderCoreFeatures_offsetof)+")",
    activeComputeUnitCount: "u32("+callof(V.VkPhysicalDeviceShaderCoreProperties2AMD_activeComputeUnitCount_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderCoreProperties2AMD_sizeof));


const VkPipelineRasterizationConservativeStateCreateInfoEXT = new C.CStruct("VkPipelineRasterizationConservativeStateCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineRasterizationConservativeStateCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineRasterizationConservativeStateCreateInfoEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineRasterizationConservativeStateCreateInfoEXT_flags_offsetof)+")",
    conservativeRasterizationMode: "u32("+callof(V.VkPipelineRasterizationConservativeStateCreateInfoEXT_conservativeRasterizationMode_offsetof)+")",
    extraPrimitiveOverestimationSize: "f32("+callof(V.VkPipelineRasterizationConservativeStateCreateInfoEXT_extraPrimitiveOverestimationSize_offsetof)+")",
}, callof(V.VkPipelineRasterizationConservativeStateCreateInfoEXT_sizeof));


const VkPhysicalDeviceDescriptorIndexingFeatures = new C.CStruct("VkPhysicalDeviceDescriptorIndexingFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_pNext_offsetof)+")",
    shaderInputAttachmentArrayDynamicIndexing: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderInputAttachmentArrayDynamicIndexing_offsetof)+")",
    shaderUniformTexelBufferArrayDynamicIndexing: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderUniformTexelBufferArrayDynamicIndexing_offsetof)+")",
    shaderStorageTexelBufferArrayDynamicIndexing: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderStorageTexelBufferArrayDynamicIndexing_offsetof)+")",
    shaderUniformBufferArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderUniformBufferArrayNonUniformIndexing_offsetof)+")",
    shaderSampledImageArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderSampledImageArrayNonUniformIndexing_offsetof)+")",
    shaderStorageBufferArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderStorageBufferArrayNonUniformIndexing_offsetof)+")",
    shaderStorageImageArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderStorageImageArrayNonUniformIndexing_offsetof)+")",
    shaderInputAttachmentArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderInputAttachmentArrayNonUniformIndexing_offsetof)+")",
    shaderUniformTexelBufferArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderUniformTexelBufferArrayNonUniformIndexing_offsetof)+")",
    shaderStorageTexelBufferArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_shaderStorageTexelBufferArrayNonUniformIndexing_offsetof)+")",
    descriptorBindingUniformBufferUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingUniformBufferUpdateAfterBind_offsetof)+")",
    descriptorBindingSampledImageUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingSampledImageUpdateAfterBind_offsetof)+")",
    descriptorBindingStorageImageUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingStorageImageUpdateAfterBind_offsetof)+")",
    descriptorBindingStorageBufferUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingStorageBufferUpdateAfterBind_offsetof)+")",
    descriptorBindingUniformTexelBufferUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingUniformTexelBufferUpdateAfterBind_offsetof)+")",
    descriptorBindingStorageTexelBufferUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingStorageTexelBufferUpdateAfterBind_offsetof)+")",
    descriptorBindingUpdateUnusedWhilePending: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingUpdateUnusedWhilePending_offsetof)+")",
    descriptorBindingPartiallyBound: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingPartiallyBound_offsetof)+")",
    descriptorBindingVariableDescriptorCount: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_descriptorBindingVariableDescriptorCount_offsetof)+")",
    runtimeDescriptorArray: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_runtimeDescriptorArray_offsetof)+")",
}, callof(V.VkPhysicalDeviceDescriptorIndexingFeatures_sizeof));


const VkPhysicalDeviceDescriptorIndexingFeaturesEXT = new C.CStruct("VkPhysicalDeviceDescriptorIndexingFeaturesEXT", {

}, callof(V.VkPhysicalDeviceDescriptorIndexingFeaturesEXT_sizeof));


const VkPhysicalDeviceDescriptorIndexingProperties = new C.CStruct("VkPhysicalDeviceDescriptorIndexingProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_pNext_offsetof)+")",
    maxUpdateAfterBindDescriptorsInAllPools: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxUpdateAfterBindDescriptorsInAllPools_offsetof)+")",
    shaderUniformBufferArrayNonUniformIndexingNative: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_shaderUniformBufferArrayNonUniformIndexingNative_offsetof)+")",
    shaderSampledImageArrayNonUniformIndexingNative: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_shaderSampledImageArrayNonUniformIndexingNative_offsetof)+")",
    shaderStorageBufferArrayNonUniformIndexingNative: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_shaderStorageBufferArrayNonUniformIndexingNative_offsetof)+")",
    shaderStorageImageArrayNonUniformIndexingNative: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_shaderStorageImageArrayNonUniformIndexingNative_offsetof)+")",
    shaderInputAttachmentArrayNonUniformIndexingNative: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_shaderInputAttachmentArrayNonUniformIndexingNative_offsetof)+")",
    robustBufferAccessUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_robustBufferAccessUpdateAfterBind_offsetof)+")",
    quadDivergentImplicitLod: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_quadDivergentImplicitLod_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindSamplers: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageDescriptorUpdateAfterBindSamplers_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindUniformBuffers: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageDescriptorUpdateAfterBindUniformBuffers_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindStorageBuffers: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageDescriptorUpdateAfterBindStorageBuffers_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindSampledImages: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageDescriptorUpdateAfterBindSampledImages_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindStorageImages: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageDescriptorUpdateAfterBindStorageImages_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindInputAttachments: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageDescriptorUpdateAfterBindInputAttachments_offsetof)+")",
    maxPerStageUpdateAfterBindResources: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxPerStageUpdateAfterBindResources_offsetof)+")",
    maxDescriptorSetUpdateAfterBindSamplers: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindSamplers_offsetof)+")",
    maxDescriptorSetUpdateAfterBindUniformBuffers: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindUniformBuffers_offsetof)+")",
    maxDescriptorSetUpdateAfterBindUniformBuffersDynamic: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindUniformBuffersDynamic_offsetof)+")",
    maxDescriptorSetUpdateAfterBindStorageBuffers: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindStorageBuffers_offsetof)+")",
    maxDescriptorSetUpdateAfterBindStorageBuffersDynamic: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindStorageBuffersDynamic_offsetof)+")",
    maxDescriptorSetUpdateAfterBindSampledImages: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindSampledImages_offsetof)+")",
    maxDescriptorSetUpdateAfterBindStorageImages: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindStorageImages_offsetof)+")",
    maxDescriptorSetUpdateAfterBindInputAttachments: "u32("+callof(V.VkPhysicalDeviceDescriptorIndexingProperties_maxDescriptorSetUpdateAfterBindInputAttachments_offsetof)+")",
}, callof(V.VkPhysicalDeviceDescriptorIndexingProperties_sizeof));


const VkPhysicalDeviceDescriptorIndexingPropertiesEXT = new C.CStruct("VkPhysicalDeviceDescriptorIndexingPropertiesEXT", {

}, callof(V.VkPhysicalDeviceDescriptorIndexingPropertiesEXT_sizeof));


const VkDescriptorSetLayoutBindingFlagsCreateInfo = new C.CStruct("VkDescriptorSetLayoutBindingFlagsCreateInfo", {
    sType: "u32("+callof(V.VkDescriptorSetLayoutBindingFlagsCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDescriptorSetLayoutBindingFlagsCreateInfo_pNext_offsetof)+")",
    bindingCount: "u32("+callof(V.VkDescriptorSetLayoutBindingFlagsCreateInfo_bindingCount_offsetof)+")",
    pBindingFlags: "u64("+callof(V.VkDescriptorSetLayoutBindingFlagsCreateInfo_pBindingFlags_offsetof)+")",
}, callof(V.VkDescriptorSetLayoutBindingFlagsCreateInfo_sizeof));


const VkDescriptorSetLayoutBindingFlagsCreateInfoEXT = new C.CStruct("VkDescriptorSetLayoutBindingFlagsCreateInfoEXT", {

}, callof(V.VkDescriptorSetLayoutBindingFlagsCreateInfoEXT_sizeof));


const VkDescriptorSetVariableDescriptorCountAllocateInfo = new C.CStruct("VkDescriptorSetVariableDescriptorCountAllocateInfo", {
    sType: "u32("+callof(V.VkDescriptorSetVariableDescriptorCountAllocateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDescriptorSetVariableDescriptorCountAllocateInfo_pNext_offsetof)+")",
    descriptorSetCount: "u32("+callof(V.VkDescriptorSetVariableDescriptorCountAllocateInfo_descriptorSetCount_offsetof)+")",
    pDescriptorCounts: "u64("+callof(V.VkDescriptorSetVariableDescriptorCountAllocateInfo_pDescriptorCounts_offsetof)+")",
}, callof(V.VkDescriptorSetVariableDescriptorCountAllocateInfo_sizeof));


const VkDescriptorSetVariableDescriptorCountAllocateInfoEXT = new C.CStruct("VkDescriptorSetVariableDescriptorCountAllocateInfoEXT", {

}, callof(V.VkDescriptorSetVariableDescriptorCountAllocateInfoEXT_sizeof));


const VkDescriptorSetVariableDescriptorCountLayoutSupport = new C.CStruct("VkDescriptorSetVariableDescriptorCountLayoutSupport", {
    sType: "u32("+callof(V.VkDescriptorSetVariableDescriptorCountLayoutSupport_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDescriptorSetVariableDescriptorCountLayoutSupport_pNext_offsetof)+")",
    maxVariableDescriptorCount: "u32("+callof(V.VkDescriptorSetVariableDescriptorCountLayoutSupport_maxVariableDescriptorCount_offsetof)+")",
}, callof(V.VkDescriptorSetVariableDescriptorCountLayoutSupport_sizeof));


const VkDescriptorSetVariableDescriptorCountLayoutSupportEXT = new C.CStruct("VkDescriptorSetVariableDescriptorCountLayoutSupportEXT", {

}, callof(V.VkDescriptorSetVariableDescriptorCountLayoutSupportEXT_sizeof));


const VkAttachmentDescription2 = new C.CStruct("VkAttachmentDescription2", {
    sType: "u32("+callof(V.VkAttachmentDescription2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAttachmentDescription2_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkAttachmentDescription2_flags_offsetof)+")",
    format: "u32("+callof(V.VkAttachmentDescription2_format_offsetof)+")",
    samples: "u32("+callof(V.VkAttachmentDescription2_samples_offsetof)+")",
    loadOp: "u32("+callof(V.VkAttachmentDescription2_loadOp_offsetof)+")",
    storeOp: "u32("+callof(V.VkAttachmentDescription2_storeOp_offsetof)+")",
    stencilLoadOp: "u32("+callof(V.VkAttachmentDescription2_stencilLoadOp_offsetof)+")",
    stencilStoreOp: "u32("+callof(V.VkAttachmentDescription2_stencilStoreOp_offsetof)+")",
    initialLayout: "u32("+callof(V.VkAttachmentDescription2_initialLayout_offsetof)+")",
    finalLayout: "u32("+callof(V.VkAttachmentDescription2_finalLayout_offsetof)+")",
}, callof(V.VkAttachmentDescription2_sizeof));


const VkAttachmentDescription2KHR = new C.CStruct("VkAttachmentDescription2KHR", {

}, callof(V.VkAttachmentDescription2KHR_sizeof));


const VkAttachmentReference2 = new C.CStruct("VkAttachmentReference2", {
    sType: "u32("+callof(V.VkAttachmentReference2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAttachmentReference2_pNext_offsetof)+")",
    attachment: "u32("+callof(V.VkAttachmentReference2_attachment_offsetof)+")",
    layout: "u32("+callof(V.VkAttachmentReference2_layout_offsetof)+")",
    aspectMask: "u32("+callof(V.VkAttachmentReference2_aspectMask_offsetof)+")",
}, callof(V.VkAttachmentReference2_sizeof));


const VkAttachmentReference2KHR = new C.CStruct("VkAttachmentReference2KHR", {

}, callof(V.VkAttachmentReference2KHR_sizeof));


const VkSubpassDescription2 = new C.CStruct("VkSubpassDescription2", {
    sType: "u32("+callof(V.VkSubpassDescription2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSubpassDescription2_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkSubpassDescription2_flags_offsetof)+")",
    pipelineBindPoint: "u32("+callof(V.VkSubpassDescription2_pipelineBindPoint_offsetof)+")",
    viewMask: "u32("+callof(V.VkSubpassDescription2_viewMask_offsetof)+")",
    inputAttachmentCount: "u32("+callof(V.VkSubpassDescription2_inputAttachmentCount_offsetof)+")",
    pInputAttachments: "u64("+callof(V.VkSubpassDescription2_pInputAttachments_offsetof)+")",
    colorAttachmentCount: "u32("+callof(V.VkSubpassDescription2_colorAttachmentCount_offsetof)+")",
    pColorAttachments: "u64("+callof(V.VkSubpassDescription2_pColorAttachments_offsetof)+")",
    pResolveAttachments: "u64("+callof(V.VkSubpassDescription2_pResolveAttachments_offsetof)+")",
    pDepthStencilAttachment: "u64("+callof(V.VkSubpassDescription2_pDepthStencilAttachment_offsetof)+")",
    preserveAttachmentCount: "u32("+callof(V.VkSubpassDescription2_preserveAttachmentCount_offsetof)+")",
    pPreserveAttachments: "u64("+callof(V.VkSubpassDescription2_pPreserveAttachments_offsetof)+")",
}, callof(V.VkSubpassDescription2_sizeof));


const VkSubpassDescription2KHR = new C.CStruct("VkSubpassDescription2KHR", {

}, callof(V.VkSubpassDescription2KHR_sizeof));


const VkSubpassDependency2 = new C.CStruct("VkSubpassDependency2", {
    sType: "u32("+callof(V.VkSubpassDependency2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSubpassDependency2_pNext_offsetof)+")",
    srcSubpass: "u32("+callof(V.VkSubpassDependency2_srcSubpass_offsetof)+")",
    dstSubpass: "u32("+callof(V.VkSubpassDependency2_dstSubpass_offsetof)+")",
    srcStageMask: "u32("+callof(V.VkSubpassDependency2_srcStageMask_offsetof)+")",
    dstStageMask: "u32("+callof(V.VkSubpassDependency2_dstStageMask_offsetof)+")",
    srcAccessMask: "u32("+callof(V.VkSubpassDependency2_srcAccessMask_offsetof)+")",
    dstAccessMask: "u32("+callof(V.VkSubpassDependency2_dstAccessMask_offsetof)+")",
    dependencyFlags: "u32("+callof(V.VkSubpassDependency2_dependencyFlags_offsetof)+")",
    viewOffset: "i32("+callof(V.VkSubpassDependency2_viewOffset_offsetof)+")",
}, callof(V.VkSubpassDependency2_sizeof));


const VkSubpassDependency2KHR = new C.CStruct("VkSubpassDependency2KHR", {

}, callof(V.VkSubpassDependency2KHR_sizeof));


const VkRenderPassCreateInfo2 = new C.CStruct("VkRenderPassCreateInfo2", {
    sType: "u32("+callof(V.VkRenderPassCreateInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderPassCreateInfo2_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkRenderPassCreateInfo2_flags_offsetof)+")",
    attachmentCount: "u32("+callof(V.VkRenderPassCreateInfo2_attachmentCount_offsetof)+")",
    pAttachments: "u64("+callof(V.VkRenderPassCreateInfo2_pAttachments_offsetof)+")",
    subpassCount: "u32("+callof(V.VkRenderPassCreateInfo2_subpassCount_offsetof)+")",
    pSubpasses: "u64("+callof(V.VkRenderPassCreateInfo2_pSubpasses_offsetof)+")",
    dependencyCount: "u32("+callof(V.VkRenderPassCreateInfo2_dependencyCount_offsetof)+")",
    pDependencies: "u64("+callof(V.VkRenderPassCreateInfo2_pDependencies_offsetof)+")",
    correlatedViewMaskCount: "u32("+callof(V.VkRenderPassCreateInfo2_correlatedViewMaskCount_offsetof)+")",
    pCorrelatedViewMasks: "u64("+callof(V.VkRenderPassCreateInfo2_pCorrelatedViewMasks_offsetof)+")",
}, callof(V.VkRenderPassCreateInfo2_sizeof));


const VkRenderPassCreateInfo2KHR = new C.CStruct("VkRenderPassCreateInfo2KHR", {

}, callof(V.VkRenderPassCreateInfo2KHR_sizeof));


const VkSubpassBeginInfo = new C.CStruct("VkSubpassBeginInfo", {
    sType: "u32("+callof(V.VkSubpassBeginInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSubpassBeginInfo_pNext_offsetof)+")",
    contents: "u32("+callof(V.VkSubpassBeginInfo_contents_offsetof)+")",
}, callof(V.VkSubpassBeginInfo_sizeof));


const VkSubpassBeginInfoKHR = new C.CStruct("VkSubpassBeginInfoKHR", {

}, callof(V.VkSubpassBeginInfoKHR_sizeof));


const VkSubpassEndInfo = new C.CStruct("VkSubpassEndInfo", {
    sType: "u32("+callof(V.VkSubpassEndInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSubpassEndInfo_pNext_offsetof)+")",
}, callof(V.VkSubpassEndInfo_sizeof));


const VkSubpassEndInfoKHR = new C.CStruct("VkSubpassEndInfoKHR", {

}, callof(V.VkSubpassEndInfoKHR_sizeof));


const VkPhysicalDeviceTimelineSemaphoreFeatures = new C.CStruct("VkPhysicalDeviceTimelineSemaphoreFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceTimelineSemaphoreFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceTimelineSemaphoreFeatures_pNext_offsetof)+")",
    timelineSemaphore: "u32("+callof(V.VkPhysicalDeviceTimelineSemaphoreFeatures_timelineSemaphore_offsetof)+")",
}, callof(V.VkPhysicalDeviceTimelineSemaphoreFeatures_sizeof));


const VkPhysicalDeviceTimelineSemaphoreFeaturesKHR = new C.CStruct("VkPhysicalDeviceTimelineSemaphoreFeaturesKHR", {

}, callof(V.VkPhysicalDeviceTimelineSemaphoreFeaturesKHR_sizeof));


const VkPhysicalDeviceTimelineSemaphoreProperties = new C.CStruct("VkPhysicalDeviceTimelineSemaphoreProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceTimelineSemaphoreProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceTimelineSemaphoreProperties_pNext_offsetof)+")",
    maxTimelineSemaphoreValueDifference: "u64("+callof(V.VkPhysicalDeviceTimelineSemaphoreProperties_maxTimelineSemaphoreValueDifference_offsetof)+")",
}, callof(V.VkPhysicalDeviceTimelineSemaphoreProperties_sizeof));


const VkPhysicalDeviceTimelineSemaphorePropertiesKHR = new C.CStruct("VkPhysicalDeviceTimelineSemaphorePropertiesKHR", {

}, callof(V.VkPhysicalDeviceTimelineSemaphorePropertiesKHR_sizeof));


const VkSemaphoreTypeCreateInfo = new C.CStruct("VkSemaphoreTypeCreateInfo", {
    sType: "u32("+callof(V.VkSemaphoreTypeCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSemaphoreTypeCreateInfo_pNext_offsetof)+")",
    semaphoreType: "u32("+callof(V.VkSemaphoreTypeCreateInfo_semaphoreType_offsetof)+")",
    initialValue: "u64("+callof(V.VkSemaphoreTypeCreateInfo_initialValue_offsetof)+")",
}, callof(V.VkSemaphoreTypeCreateInfo_sizeof));


const VkSemaphoreTypeCreateInfoKHR = new C.CStruct("VkSemaphoreTypeCreateInfoKHR", {

}, callof(V.VkSemaphoreTypeCreateInfoKHR_sizeof));


const VkTimelineSemaphoreSubmitInfo = new C.CStruct("VkTimelineSemaphoreSubmitInfo", {
    sType: "u32("+callof(V.VkTimelineSemaphoreSubmitInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkTimelineSemaphoreSubmitInfo_pNext_offsetof)+")",
    waitSemaphoreValueCount: "u32("+callof(V.VkTimelineSemaphoreSubmitInfo_waitSemaphoreValueCount_offsetof)+")",
    pWaitSemaphoreValues: "u64("+callof(V.VkTimelineSemaphoreSubmitInfo_pWaitSemaphoreValues_offsetof)+")",
    signalSemaphoreValueCount: "u32("+callof(V.VkTimelineSemaphoreSubmitInfo_signalSemaphoreValueCount_offsetof)+")",
    pSignalSemaphoreValues: "u64("+callof(V.VkTimelineSemaphoreSubmitInfo_pSignalSemaphoreValues_offsetof)+")",
}, callof(V.VkTimelineSemaphoreSubmitInfo_sizeof));


const VkTimelineSemaphoreSubmitInfoKHR = new C.CStruct("VkTimelineSemaphoreSubmitInfoKHR", {

}, callof(V.VkTimelineSemaphoreSubmitInfoKHR_sizeof));


const VkSemaphoreWaitInfo = new C.CStruct("VkSemaphoreWaitInfo", {
    sType: "u32("+callof(V.VkSemaphoreWaitInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSemaphoreWaitInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkSemaphoreWaitInfo_flags_offsetof)+")",
    semaphoreCount: "u32("+callof(V.VkSemaphoreWaitInfo_semaphoreCount_offsetof)+")",
    pSemaphores: "u64("+callof(V.VkSemaphoreWaitInfo_pSemaphores_offsetof)+")",
    pValues: "u64("+callof(V.VkSemaphoreWaitInfo_pValues_offsetof)+")",
}, callof(V.VkSemaphoreWaitInfo_sizeof));


const VkSemaphoreWaitInfoKHR = new C.CStruct("VkSemaphoreWaitInfoKHR", {

}, callof(V.VkSemaphoreWaitInfoKHR_sizeof));


const VkSemaphoreSignalInfo = new C.CStruct("VkSemaphoreSignalInfo", {
    sType: "u32("+callof(V.VkSemaphoreSignalInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSemaphoreSignalInfo_pNext_offsetof)+")",
    semaphore: "u64("+callof(V.VkSemaphoreSignalInfo_semaphore_offsetof)+")",
    value: "u64("+callof(V.VkSemaphoreSignalInfo_value_offsetof)+")",
}, callof(V.VkSemaphoreSignalInfo_sizeof));


const VkSemaphoreSignalInfoKHR = new C.CStruct("VkSemaphoreSignalInfoKHR", {

}, callof(V.VkSemaphoreSignalInfoKHR_sizeof));


const VkVertexInputBindingDivisorDescriptionEXT = new C.CStruct("VkVertexInputBindingDivisorDescriptionEXT", {
    binding: "u32("+callof(V.VkVertexInputBindingDivisorDescriptionEXT_binding_offsetof)+")",
    divisor: "u32("+callof(V.VkVertexInputBindingDivisorDescriptionEXT_divisor_offsetof)+")",
}, callof(V.VkVertexInputBindingDivisorDescriptionEXT_sizeof));


const VkPipelineVertexInputDivisorStateCreateInfoEXT = new C.CStruct("VkPipelineVertexInputDivisorStateCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineVertexInputDivisorStateCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineVertexInputDivisorStateCreateInfoEXT_pNext_offsetof)+")",
    vertexBindingDivisorCount: "u32("+callof(V.VkPipelineVertexInputDivisorStateCreateInfoEXT_vertexBindingDivisorCount_offsetof)+")",
    pVertexBindingDivisors: "u64("+callof(V.VkPipelineVertexInputDivisorStateCreateInfoEXT_pVertexBindingDivisors_offsetof)+")",
}, callof(V.VkPipelineVertexInputDivisorStateCreateInfoEXT_sizeof));


const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT = new C.CStruct("VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT_pNext_offsetof)+")",
    maxVertexAttribDivisor: "u32("+callof(V.VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT_maxVertexAttribDivisor_offsetof)+")",
}, callof(V.VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT_sizeof));


const VkPhysicalDevicePCIBusInfoPropertiesEXT = new C.CStruct("VkPhysicalDevicePCIBusInfoPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_pNext_offsetof)+")",
    pciDomain: "u32("+callof(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_pciDomain_offsetof)+")",
    pciBus: "u32("+callof(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_pciBus_offsetof)+")",
    pciDevice: "u32("+callof(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_pciDevice_offsetof)+")",
    pciFunction: "u32("+callof(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_pciFunction_offsetof)+")",
}, callof(V.VkPhysicalDevicePCIBusInfoPropertiesEXT_sizeof));


const VkImportAndroidHardwareBufferInfoANDROID = new C.CStruct("VkImportAndroidHardwareBufferInfoANDROID", {
    sType: "u32("+callof(V.VkImportAndroidHardwareBufferInfoANDROID_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportAndroidHardwareBufferInfoANDROID_pNext_offsetof)+")",
    buffer: "u64("+callof(V.VkImportAndroidHardwareBufferInfoANDROID_buffer_offsetof)+")",
}, callof(V.VkImportAndroidHardwareBufferInfoANDROID_sizeof));


const VkAndroidHardwareBufferUsageANDROID = new C.CStruct("VkAndroidHardwareBufferUsageANDROID", {
    sType: "u32("+callof(V.VkAndroidHardwareBufferUsageANDROID_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAndroidHardwareBufferUsageANDROID_pNext_offsetof)+")",
    androidHardwareBufferUsage: "u64("+callof(V.VkAndroidHardwareBufferUsageANDROID_androidHardwareBufferUsage_offsetof)+")",
}, callof(V.VkAndroidHardwareBufferUsageANDROID_sizeof));


const VkAndroidHardwareBufferPropertiesANDROID = new C.CStruct("VkAndroidHardwareBufferPropertiesANDROID", {
    sType: "u32("+callof(V.VkAndroidHardwareBufferPropertiesANDROID_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAndroidHardwareBufferPropertiesANDROID_pNext_offsetof)+")",
    allocationSize: "u64("+callof(V.VkAndroidHardwareBufferPropertiesANDROID_allocationSize_offsetof)+")",
    memoryTypeBits: "u32("+callof(V.VkAndroidHardwareBufferPropertiesANDROID_memoryTypeBits_offsetof)+")",
}, callof(V.VkAndroidHardwareBufferPropertiesANDROID_sizeof));


const VkMemoryGetAndroidHardwareBufferInfoANDROID = new C.CStruct("VkMemoryGetAndroidHardwareBufferInfoANDROID", {
    sType: "u32("+callof(V.VkMemoryGetAndroidHardwareBufferInfoANDROID_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryGetAndroidHardwareBufferInfoANDROID_pNext_offsetof)+")",
    memory: "u64("+callof(V.VkMemoryGetAndroidHardwareBufferInfoANDROID_memory_offsetof)+")",
}, callof(V.VkMemoryGetAndroidHardwareBufferInfoANDROID_sizeof));


const VkAndroidHardwareBufferFormatPropertiesANDROID = new C.CStruct("VkAndroidHardwareBufferFormatPropertiesANDROID", {
    sType: "u32("+callof(V.VkAndroidHardwareBufferFormatPropertiesANDROID_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAndroidHardwareBufferFormatPropertiesANDROID_pNext_offsetof)+")",
    format: "u32("+callof(V.VkAndroidHardwareBufferFormatPropertiesANDROID_format_offsetof)+")",
    externalFormat: "u64("+callof(V.VkAndroidHardwareBufferFormatPropertiesANDROID_externalFormat_offsetof)+")",
    formatFeatures: "u32("+callof(V.VkAndroidHardwareBufferFormatPropertiesANDROID_formatFeatures_offsetof)+")",
    samplerYcbcrConversionComponents: "u32("+callof(V.VkAndroidHardwareBufferFormatPropertiesANDROID_samplerYcbcrConversionComponents_offsetof)+")",
    suggestedYcbcrModel: "u32("+callof(V.VkAndroidHardwareBufferFormatPropertiesANDROID_suggestedYcbcrModel_offsetof)+")",
    suggestedYcbcrRange: "u32("+callof(V.VkAndroidHardwareBufferFormatPropertiesANDROID_suggestedYcbcrRange_offsetof)+")",
    suggestedXChromaOffset: "u32("+callof(V.VkAndroidHardwareBufferFormatPropertiesANDROID_suggestedXChromaOffset_offsetof)+")",
    suggestedYChromaOffset: "u32("+callof(V.VkAndroidHardwareBufferFormatPropertiesANDROID_suggestedYChromaOffset_offsetof)+")",
}, callof(V.VkAndroidHardwareBufferFormatPropertiesANDROID_sizeof));


const VkCommandBufferInheritanceConditionalRenderingInfoEXT = new C.CStruct("VkCommandBufferInheritanceConditionalRenderingInfoEXT", {
    sType: "u32("+callof(V.VkCommandBufferInheritanceConditionalRenderingInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCommandBufferInheritanceConditionalRenderingInfoEXT_pNext_offsetof)+")",
    conditionalRenderingEnable: "u32("+callof(V.VkCommandBufferInheritanceConditionalRenderingInfoEXT_conditionalRenderingEnable_offsetof)+")",
}, callof(V.VkCommandBufferInheritanceConditionalRenderingInfoEXT_sizeof));


const VkExternalFormatANDROID = new C.CStruct("VkExternalFormatANDROID", {
    sType: "u32("+callof(V.VkExternalFormatANDROID_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExternalFormatANDROID_pNext_offsetof)+")",
    externalFormat: "u64("+callof(V.VkExternalFormatANDROID_externalFormat_offsetof)+")",
}, callof(V.VkExternalFormatANDROID_sizeof));


const VkPhysicalDevice8BitStorageFeatures = new C.CStruct("VkPhysicalDevice8BitStorageFeatures", {
    sType: "u32("+callof(V.VkPhysicalDevice8BitStorageFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevice8BitStorageFeatures_pNext_offsetof)+")",
    storageBuffer8BitAccess: "u32("+callof(V.VkPhysicalDevice8BitStorageFeatures_storageBuffer8BitAccess_offsetof)+")",
    uniformAndStorageBuffer8BitAccess: "u32("+callof(V.VkPhysicalDevice8BitStorageFeatures_uniformAndStorageBuffer8BitAccess_offsetof)+")",
    storagePushConstant8: "u32("+callof(V.VkPhysicalDevice8BitStorageFeatures_storagePushConstant8_offsetof)+")",
}, callof(V.VkPhysicalDevice8BitStorageFeatures_sizeof));


const VkPhysicalDevice8BitStorageFeaturesKHR = new C.CStruct("VkPhysicalDevice8BitStorageFeaturesKHR", {

}, callof(V.VkPhysicalDevice8BitStorageFeaturesKHR_sizeof));


const VkPhysicalDeviceConditionalRenderingFeaturesEXT = new C.CStruct("VkPhysicalDeviceConditionalRenderingFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceConditionalRenderingFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceConditionalRenderingFeaturesEXT_pNext_offsetof)+")",
    conditionalRendering: "u32("+callof(V.VkPhysicalDeviceConditionalRenderingFeaturesEXT_conditionalRendering_offsetof)+")",
    inheritedConditionalRendering: "u32("+callof(V.VkPhysicalDeviceConditionalRenderingFeaturesEXT_inheritedConditionalRendering_offsetof)+")",
}, callof(V.VkPhysicalDeviceConditionalRenderingFeaturesEXT_sizeof));


const VkPhysicalDeviceVulkanMemoryModelFeatures = new C.CStruct("VkPhysicalDeviceVulkanMemoryModelFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceVulkanMemoryModelFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceVulkanMemoryModelFeatures_pNext_offsetof)+")",
    vulkanMemoryModel: "u32("+callof(V.VkPhysicalDeviceVulkanMemoryModelFeatures_vulkanMemoryModel_offsetof)+")",
    vulkanMemoryModelDeviceScope: "u32("+callof(V.VkPhysicalDeviceVulkanMemoryModelFeatures_vulkanMemoryModelDeviceScope_offsetof)+")",
    vulkanMemoryModelAvailabilityVisibilityChains: "u32("+callof(V.VkPhysicalDeviceVulkanMemoryModelFeatures_vulkanMemoryModelAvailabilityVisibilityChains_offsetof)+")",
}, callof(V.VkPhysicalDeviceVulkanMemoryModelFeatures_sizeof));


const VkPhysicalDeviceVulkanMemoryModelFeaturesKHR = new C.CStruct("VkPhysicalDeviceVulkanMemoryModelFeaturesKHR", {

}, callof(V.VkPhysicalDeviceVulkanMemoryModelFeaturesKHR_sizeof));


const VkPhysicalDeviceShaderAtomicInt64Features = new C.CStruct("VkPhysicalDeviceShaderAtomicInt64Features", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderAtomicInt64Features_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderAtomicInt64Features_pNext_offsetof)+")",
    shaderBufferInt64Atomics: "u32("+callof(V.VkPhysicalDeviceShaderAtomicInt64Features_shaderBufferInt64Atomics_offsetof)+")",
    shaderSharedInt64Atomics: "u32("+callof(V.VkPhysicalDeviceShaderAtomicInt64Features_shaderSharedInt64Atomics_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderAtomicInt64Features_sizeof));


const VkPhysicalDeviceShaderAtomicInt64FeaturesKHR = new C.CStruct("VkPhysicalDeviceShaderAtomicInt64FeaturesKHR", {

}, callof(V.VkPhysicalDeviceShaderAtomicInt64FeaturesKHR_sizeof));


const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT = new C.CStruct("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_pNext_offsetof)+")",
    shaderBufferFloat32Atomics: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderBufferFloat32Atomics_offsetof)+")",
    shaderBufferFloat32AtomicAdd: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderBufferFloat32AtomicAdd_offsetof)+")",
    shaderBufferFloat64Atomics: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderBufferFloat64Atomics_offsetof)+")",
    shaderBufferFloat64AtomicAdd: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderBufferFloat64AtomicAdd_offsetof)+")",
    shaderSharedFloat32Atomics: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderSharedFloat32Atomics_offsetof)+")",
    shaderSharedFloat32AtomicAdd: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderSharedFloat32AtomicAdd_offsetof)+")",
    shaderSharedFloat64Atomics: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderSharedFloat64Atomics_offsetof)+")",
    shaderSharedFloat64AtomicAdd: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderSharedFloat64AtomicAdd_offsetof)+")",
    shaderImageFloat32Atomics: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderImageFloat32Atomics_offsetof)+")",
    shaderImageFloat32AtomicAdd: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_shaderImageFloat32AtomicAdd_offsetof)+")",
    sparseImageFloat32Atomics: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_sparseImageFloat32Atomics_offsetof)+")",
    sparseImageFloat32AtomicAdd: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_sparseImageFloat32AtomicAdd_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderAtomicFloatFeaturesEXT_sizeof));


const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT = new C.CStruct("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_pNext_offsetof)+")",
    shaderBufferFloat16Atomics: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderBufferFloat16Atomics_offsetof)+")",
    shaderBufferFloat16AtomicAdd: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderBufferFloat16AtomicAdd_offsetof)+")",
    shaderBufferFloat16AtomicMinMax: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderBufferFloat16AtomicMinMax_offsetof)+")",
    shaderBufferFloat32AtomicMinMax: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderBufferFloat32AtomicMinMax_offsetof)+")",
    shaderBufferFloat64AtomicMinMax: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderBufferFloat64AtomicMinMax_offsetof)+")",
    shaderSharedFloat16Atomics: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderSharedFloat16Atomics_offsetof)+")",
    shaderSharedFloat16AtomicAdd: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderSharedFloat16AtomicAdd_offsetof)+")",
    shaderSharedFloat16AtomicMinMax: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderSharedFloat16AtomicMinMax_offsetof)+")",
    shaderSharedFloat32AtomicMinMax: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderSharedFloat32AtomicMinMax_offsetof)+")",
    shaderSharedFloat64AtomicMinMax: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderSharedFloat64AtomicMinMax_offsetof)+")",
    shaderImageFloat32AtomicMinMax: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_shaderImageFloat32AtomicMinMax_offsetof)+")",
    sparseImageFloat32AtomicMinMax: "u32("+callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_sparseImageFloat32AtomicMinMax_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT_sizeof));


const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT = new C.CStruct("VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT_pNext_offsetof)+")",
    vertexAttributeInstanceRateDivisor: "u32("+callof(V.VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT_vertexAttributeInstanceRateDivisor_offsetof)+")",
    vertexAttributeInstanceRateZeroDivisor: "u32("+callof(V.VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT_vertexAttributeInstanceRateZeroDivisor_offsetof)+")",
}, callof(V.VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT_sizeof));


const VkQueueFamilyCheckpointPropertiesNV = new C.CStruct("VkQueueFamilyCheckpointPropertiesNV", {
    sType: "u32("+callof(V.VkQueueFamilyCheckpointPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkQueueFamilyCheckpointPropertiesNV_pNext_offsetof)+")",
    checkpointExecutionStageMask: "u32("+callof(V.VkQueueFamilyCheckpointPropertiesNV_checkpointExecutionStageMask_offsetof)+")",
}, callof(V.VkQueueFamilyCheckpointPropertiesNV_sizeof));


const VkCheckpointDataNV = new C.CStruct("VkCheckpointDataNV", {
    sType: "u32("+callof(V.VkCheckpointDataNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCheckpointDataNV_pNext_offsetof)+")",
    stage: "u32("+callof(V.VkCheckpointDataNV_stage_offsetof)+")",
    pCheckpointMarker: "u64("+callof(V.VkCheckpointDataNV_pCheckpointMarker_offsetof)+")",
}, callof(V.VkCheckpointDataNV_sizeof));


const VkPhysicalDeviceDepthStencilResolveProperties = new C.CStruct("VkPhysicalDeviceDepthStencilResolveProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceDepthStencilResolveProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDepthStencilResolveProperties_pNext_offsetof)+")",
    supportedDepthResolveModes: "u32("+callof(V.VkPhysicalDeviceDepthStencilResolveProperties_supportedDepthResolveModes_offsetof)+")",
    supportedStencilResolveModes: "u32("+callof(V.VkPhysicalDeviceDepthStencilResolveProperties_supportedStencilResolveModes_offsetof)+")",
    independentResolveNone: "u32("+callof(V.VkPhysicalDeviceDepthStencilResolveProperties_independentResolveNone_offsetof)+")",
    independentResolve: "u32("+callof(V.VkPhysicalDeviceDepthStencilResolveProperties_independentResolve_offsetof)+")",
}, callof(V.VkPhysicalDeviceDepthStencilResolveProperties_sizeof));


const VkPhysicalDeviceDepthStencilResolvePropertiesKHR = new C.CStruct("VkPhysicalDeviceDepthStencilResolvePropertiesKHR", {

}, callof(V.VkPhysicalDeviceDepthStencilResolvePropertiesKHR_sizeof));


const VkSubpassDescriptionDepthStencilResolve = new C.CStruct("VkSubpassDescriptionDepthStencilResolve", {
    sType: "u32("+callof(V.VkSubpassDescriptionDepthStencilResolve_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSubpassDescriptionDepthStencilResolve_pNext_offsetof)+")",
    depthResolveMode: "u32("+callof(V.VkSubpassDescriptionDepthStencilResolve_depthResolveMode_offsetof)+")",
    stencilResolveMode: "u32("+callof(V.VkSubpassDescriptionDepthStencilResolve_stencilResolveMode_offsetof)+")",
    pDepthStencilResolveAttachment: "u64("+callof(V.VkSubpassDescriptionDepthStencilResolve_pDepthStencilResolveAttachment_offsetof)+")",
}, callof(V.VkSubpassDescriptionDepthStencilResolve_sizeof));


const VkSubpassDescriptionDepthStencilResolveKHR = new C.CStruct("VkSubpassDescriptionDepthStencilResolveKHR", {

}, callof(V.VkSubpassDescriptionDepthStencilResolveKHR_sizeof));


const VkImageViewASTCDecodeModeEXT = new C.CStruct("VkImageViewASTCDecodeModeEXT", {
    sType: "u32("+callof(V.VkImageViewASTCDecodeModeEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageViewASTCDecodeModeEXT_pNext_offsetof)+")",
    decodeMode: "u32("+callof(V.VkImageViewASTCDecodeModeEXT_decodeMode_offsetof)+")",
}, callof(V.VkImageViewASTCDecodeModeEXT_sizeof));


const VkPhysicalDeviceASTCDecodeFeaturesEXT = new C.CStruct("VkPhysicalDeviceASTCDecodeFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceASTCDecodeFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceASTCDecodeFeaturesEXT_pNext_offsetof)+")",
    decodeModeSharedExponent: "u32("+callof(V.VkPhysicalDeviceASTCDecodeFeaturesEXT_decodeModeSharedExponent_offsetof)+")",
}, callof(V.VkPhysicalDeviceASTCDecodeFeaturesEXT_sizeof));


const VkPhysicalDeviceTransformFeedbackFeaturesEXT = new C.CStruct("VkPhysicalDeviceTransformFeedbackFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceTransformFeedbackFeaturesEXT_pNext_offsetof)+")",
    transformFeedback: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackFeaturesEXT_transformFeedback_offsetof)+")",
    geometryStreams: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackFeaturesEXT_geometryStreams_offsetof)+")",
}, callof(V.VkPhysicalDeviceTransformFeedbackFeaturesEXT_sizeof));


const VkPhysicalDeviceTransformFeedbackPropertiesEXT = new C.CStruct("VkPhysicalDeviceTransformFeedbackPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_pNext_offsetof)+")",
    maxTransformFeedbackStreams: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_maxTransformFeedbackStreams_offsetof)+")",
    maxTransformFeedbackBuffers: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_maxTransformFeedbackBuffers_offsetof)+")",
    maxTransformFeedbackBufferSize: "u64("+callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_maxTransformFeedbackBufferSize_offsetof)+")",
    maxTransformFeedbackStreamDataSize: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_maxTransformFeedbackStreamDataSize_offsetof)+")",
    maxTransformFeedbackBufferDataSize: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_maxTransformFeedbackBufferDataSize_offsetof)+")",
    maxTransformFeedbackBufferDataStride: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_maxTransformFeedbackBufferDataStride_offsetof)+")",
    transformFeedbackQueries: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_transformFeedbackQueries_offsetof)+")",
    transformFeedbackStreamsLinesTriangles: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_transformFeedbackStreamsLinesTriangles_offsetof)+")",
    transformFeedbackRasterizationStreamSelect: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_transformFeedbackRasterizationStreamSelect_offsetof)+")",
    transformFeedbackDraw: "u32("+callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_transformFeedbackDraw_offsetof)+")",
}, callof(V.VkPhysicalDeviceTransformFeedbackPropertiesEXT_sizeof));


const VkPipelineRasterizationStateStreamCreateInfoEXT = new C.CStruct("VkPipelineRasterizationStateStreamCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineRasterizationStateStreamCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineRasterizationStateStreamCreateInfoEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineRasterizationStateStreamCreateInfoEXT_flags_offsetof)+")",
    rasterizationStream: "u32("+callof(V.VkPipelineRasterizationStateStreamCreateInfoEXT_rasterizationStream_offsetof)+")",
}, callof(V.VkPipelineRasterizationStateStreamCreateInfoEXT_sizeof));


const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV = new C.CStruct("VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV_pNext_offsetof)+")",
    representativeFragmentTest: "u32("+callof(V.VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV_representativeFragmentTest_offsetof)+")",
}, callof(V.VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV_sizeof));


const VkPipelineRepresentativeFragmentTestStateCreateInfoNV = new C.CStruct("VkPipelineRepresentativeFragmentTestStateCreateInfoNV", {
    sType: "u32("+callof(V.VkPipelineRepresentativeFragmentTestStateCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineRepresentativeFragmentTestStateCreateInfoNV_pNext_offsetof)+")",
    representativeFragmentTestEnable: "u32("+callof(V.VkPipelineRepresentativeFragmentTestStateCreateInfoNV_representativeFragmentTestEnable_offsetof)+")",
}, callof(V.VkPipelineRepresentativeFragmentTestStateCreateInfoNV_sizeof));


const VkPhysicalDeviceExclusiveScissorFeaturesNV = new C.CStruct("VkPhysicalDeviceExclusiveScissorFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceExclusiveScissorFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceExclusiveScissorFeaturesNV_pNext_offsetof)+")",
    exclusiveScissor: "u32("+callof(V.VkPhysicalDeviceExclusiveScissorFeaturesNV_exclusiveScissor_offsetof)+")",
}, callof(V.VkPhysicalDeviceExclusiveScissorFeaturesNV_sizeof));


const VkPipelineViewportExclusiveScissorStateCreateInfoNV = new C.CStruct("VkPipelineViewportExclusiveScissorStateCreateInfoNV", {
    sType: "u32("+callof(V.VkPipelineViewportExclusiveScissorStateCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineViewportExclusiveScissorStateCreateInfoNV_pNext_offsetof)+")",
    exclusiveScissorCount: "u32("+callof(V.VkPipelineViewportExclusiveScissorStateCreateInfoNV_exclusiveScissorCount_offsetof)+")",
    pExclusiveScissors: "u64("+callof(V.VkPipelineViewportExclusiveScissorStateCreateInfoNV_pExclusiveScissors_offsetof)+")",
}, callof(V.VkPipelineViewportExclusiveScissorStateCreateInfoNV_sizeof));


const VkPhysicalDeviceCornerSampledImageFeaturesNV = new C.CStruct("VkPhysicalDeviceCornerSampledImageFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceCornerSampledImageFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceCornerSampledImageFeaturesNV_pNext_offsetof)+")",
    cornerSampledImage: "u32("+callof(V.VkPhysicalDeviceCornerSampledImageFeaturesNV_cornerSampledImage_offsetof)+")",
}, callof(V.VkPhysicalDeviceCornerSampledImageFeaturesNV_sizeof));


const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV = new C.CStruct("VkPhysicalDeviceComputeShaderDerivativesFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceComputeShaderDerivativesFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceComputeShaderDerivativesFeaturesNV_pNext_offsetof)+")",
    computeDerivativeGroupQuads: "u32("+callof(V.VkPhysicalDeviceComputeShaderDerivativesFeaturesNV_computeDerivativeGroupQuads_offsetof)+")",
    computeDerivativeGroupLinear: "u32("+callof(V.VkPhysicalDeviceComputeShaderDerivativesFeaturesNV_computeDerivativeGroupLinear_offsetof)+")",
}, callof(V.VkPhysicalDeviceComputeShaderDerivativesFeaturesNV_sizeof));


const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV = new C.CStruct("VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV", {

}, callof(V.VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV_sizeof));


const VkPhysicalDeviceShaderImageFootprintFeaturesNV = new C.CStruct("VkPhysicalDeviceShaderImageFootprintFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderImageFootprintFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderImageFootprintFeaturesNV_pNext_offsetof)+")",
    imageFootprint: "u32("+callof(V.VkPhysicalDeviceShaderImageFootprintFeaturesNV_imageFootprint_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderImageFootprintFeaturesNV_sizeof));


const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV = new C.CStruct("VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV_pNext_offsetof)+")",
    dedicatedAllocationImageAliasing: "u32("+callof(V.VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV_dedicatedAllocationImageAliasing_offsetof)+")",
}, callof(V.VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV_sizeof));


const VkPhysicalDeviceCopyMemoryIndirectFeaturesNV = new C.CStruct("VkPhysicalDeviceCopyMemoryIndirectFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceCopyMemoryIndirectFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceCopyMemoryIndirectFeaturesNV_pNext_offsetof)+")",
    indirectCopy: "u32("+callof(V.VkPhysicalDeviceCopyMemoryIndirectFeaturesNV_indirectCopy_offsetof)+")",
}, callof(V.VkPhysicalDeviceCopyMemoryIndirectFeaturesNV_sizeof));


const VkPhysicalDeviceCopyMemoryIndirectPropertiesNV = new C.CStruct("VkPhysicalDeviceCopyMemoryIndirectPropertiesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceCopyMemoryIndirectPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceCopyMemoryIndirectPropertiesNV_pNext_offsetof)+")",
    supportedQueues: "u32("+callof(V.VkPhysicalDeviceCopyMemoryIndirectPropertiesNV_supportedQueues_offsetof)+")",
}, callof(V.VkPhysicalDeviceCopyMemoryIndirectPropertiesNV_sizeof));


const VkPhysicalDeviceMemoryDecompressionFeaturesNV = new C.CStruct("VkPhysicalDeviceMemoryDecompressionFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceMemoryDecompressionFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMemoryDecompressionFeaturesNV_pNext_offsetof)+")",
    memoryDecompression: "u32("+callof(V.VkPhysicalDeviceMemoryDecompressionFeaturesNV_memoryDecompression_offsetof)+")",
}, callof(V.VkPhysicalDeviceMemoryDecompressionFeaturesNV_sizeof));


const VkPhysicalDeviceMemoryDecompressionPropertiesNV = new C.CStruct("VkPhysicalDeviceMemoryDecompressionPropertiesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceMemoryDecompressionPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMemoryDecompressionPropertiesNV_pNext_offsetof)+")",
    decompressionMethods: "u32("+callof(V.VkPhysicalDeviceMemoryDecompressionPropertiesNV_decompressionMethods_offsetof)+")",
    maxDecompressionIndirectCount: "u64("+callof(V.VkPhysicalDeviceMemoryDecompressionPropertiesNV_maxDecompressionIndirectCount_offsetof)+")",
}, callof(V.VkPhysicalDeviceMemoryDecompressionPropertiesNV_sizeof));


const VkShadingRatePaletteNV = new C.CStruct("VkShadingRatePaletteNV", {
    shadingRatePaletteEntryCount: "u32("+callof(V.VkShadingRatePaletteNV_shadingRatePaletteEntryCount_offsetof)+")",
    pShadingRatePaletteEntries: "u64("+callof(V.VkShadingRatePaletteNV_pShadingRatePaletteEntries_offsetof)+")",
}, callof(V.VkShadingRatePaletteNV_sizeof));


const VkPipelineViewportShadingRateImageStateCreateInfoNV = new C.CStruct("VkPipelineViewportShadingRateImageStateCreateInfoNV", {
    sType: "u32("+callof(V.VkPipelineViewportShadingRateImageStateCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineViewportShadingRateImageStateCreateInfoNV_pNext_offsetof)+")",
    shadingRateImageEnable: "u32("+callof(V.VkPipelineViewportShadingRateImageStateCreateInfoNV_shadingRateImageEnable_offsetof)+")",
    viewportCount: "u32("+callof(V.VkPipelineViewportShadingRateImageStateCreateInfoNV_viewportCount_offsetof)+")",
    pShadingRatePalettes: "u64("+callof(V.VkPipelineViewportShadingRateImageStateCreateInfoNV_pShadingRatePalettes_offsetof)+")",
}, callof(V.VkPipelineViewportShadingRateImageStateCreateInfoNV_sizeof));


const VkPhysicalDeviceShadingRateImageFeaturesNV = new C.CStruct("VkPhysicalDeviceShadingRateImageFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceShadingRateImageFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShadingRateImageFeaturesNV_pNext_offsetof)+")",
    shadingRateImage: "u32("+callof(V.VkPhysicalDeviceShadingRateImageFeaturesNV_shadingRateImage_offsetof)+")",
    shadingRateCoarseSampleOrder: "u32("+callof(V.VkPhysicalDeviceShadingRateImageFeaturesNV_shadingRateCoarseSampleOrder_offsetof)+")",
}, callof(V.VkPhysicalDeviceShadingRateImageFeaturesNV_sizeof));


const VkPhysicalDeviceShadingRateImagePropertiesNV = new C.CStruct("VkPhysicalDeviceShadingRateImagePropertiesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceShadingRateImagePropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShadingRateImagePropertiesNV_pNext_offsetof)+")",
    shadingRateTexelSize: "VkExtent2D("+callof(V.VkPhysicalDeviceShadingRateImagePropertiesNV_shadingRateTexelSize_offsetof)+")",
    shadingRatePaletteSize: "u32("+callof(V.VkPhysicalDeviceShadingRateImagePropertiesNV_shadingRatePaletteSize_offsetof)+")",
    shadingRateMaxCoarseSamples: "u32("+callof(V.VkPhysicalDeviceShadingRateImagePropertiesNV_shadingRateMaxCoarseSamples_offsetof)+")",
}, callof(V.VkPhysicalDeviceShadingRateImagePropertiesNV_sizeof));


const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI = new C.CStruct("VkPhysicalDeviceInvocationMaskFeaturesHUAWEI", {
    sType: "u32("+callof(V.VkPhysicalDeviceInvocationMaskFeaturesHUAWEI_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceInvocationMaskFeaturesHUAWEI_pNext_offsetof)+")",
    invocationMask: "u32("+callof(V.VkPhysicalDeviceInvocationMaskFeaturesHUAWEI_invocationMask_offsetof)+")",
}, callof(V.VkPhysicalDeviceInvocationMaskFeaturesHUAWEI_sizeof));


const VkCoarseSampleLocationNV = new C.CStruct("VkCoarseSampleLocationNV", {
    pixelX: "u32("+callof(V.VkCoarseSampleLocationNV_pixelX_offsetof)+")",
    pixelY: "u32("+callof(V.VkCoarseSampleLocationNV_pixelY_offsetof)+")",
    sample: "u32("+callof(V.VkCoarseSampleLocationNV_sample_offsetof)+")",
}, callof(V.VkCoarseSampleLocationNV_sizeof));


const VkCoarseSampleOrderCustomNV = new C.CStruct("VkCoarseSampleOrderCustomNV", {
    shadingRate: "u32("+callof(V.VkCoarseSampleOrderCustomNV_shadingRate_offsetof)+")",
    sampleCount: "u32("+callof(V.VkCoarseSampleOrderCustomNV_sampleCount_offsetof)+")",
    sampleLocationCount: "u32("+callof(V.VkCoarseSampleOrderCustomNV_sampleLocationCount_offsetof)+")",
    pSampleLocations: "u64("+callof(V.VkCoarseSampleOrderCustomNV_pSampleLocations_offsetof)+")",
}, callof(V.VkCoarseSampleOrderCustomNV_sizeof));


const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV = new C.CStruct("VkPipelineViewportCoarseSampleOrderStateCreateInfoNV", {
    sType: "u32("+callof(V.VkPipelineViewportCoarseSampleOrderStateCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineViewportCoarseSampleOrderStateCreateInfoNV_pNext_offsetof)+")",
    sampleOrderType: "u32("+callof(V.VkPipelineViewportCoarseSampleOrderStateCreateInfoNV_sampleOrderType_offsetof)+")",
    customSampleOrderCount: "u32("+callof(V.VkPipelineViewportCoarseSampleOrderStateCreateInfoNV_customSampleOrderCount_offsetof)+")",
    pCustomSampleOrders: "u64("+callof(V.VkPipelineViewportCoarseSampleOrderStateCreateInfoNV_pCustomSampleOrders_offsetof)+")",
}, callof(V.VkPipelineViewportCoarseSampleOrderStateCreateInfoNV_sizeof));


const VkPhysicalDeviceMeshShaderFeaturesNV = new C.CStruct("VkPhysicalDeviceMeshShaderFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceMeshShaderFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMeshShaderFeaturesNV_pNext_offsetof)+")",
    taskShader: "u32("+callof(V.VkPhysicalDeviceMeshShaderFeaturesNV_taskShader_offsetof)+")",
    meshShader: "u32("+callof(V.VkPhysicalDeviceMeshShaderFeaturesNV_meshShader_offsetof)+")",
}, callof(V.VkPhysicalDeviceMeshShaderFeaturesNV_sizeof));


const VkPhysicalDeviceMeshShaderPropertiesNV = new C.CStruct("VkPhysicalDeviceMeshShaderPropertiesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_pNext_offsetof)+")",
    maxDrawMeshTasksCount: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxDrawMeshTasksCount_offsetof)+")",
    maxTaskWorkGroupInvocations: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxTaskWorkGroupInvocations_offsetof)+")",
    maxTaskWorkGroupSize: "u32[3]("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxTaskWorkGroupSize_offsetof)+")",
    maxTaskTotalMemorySize: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxTaskTotalMemorySize_offsetof)+")",
    maxTaskOutputCount: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxTaskOutputCount_offsetof)+")",
    maxMeshWorkGroupInvocations: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxMeshWorkGroupInvocations_offsetof)+")",
    maxMeshWorkGroupSize: "u32[3]("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxMeshWorkGroupSize_offsetof)+")",
    maxMeshTotalMemorySize: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxMeshTotalMemorySize_offsetof)+")",
    maxMeshOutputVertices: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxMeshOutputVertices_offsetof)+")",
    maxMeshOutputPrimitives: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxMeshOutputPrimitives_offsetof)+")",
    maxMeshMultiviewViewCount: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_maxMeshMultiviewViewCount_offsetof)+")",
    meshOutputPerVertexGranularity: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_meshOutputPerVertexGranularity_offsetof)+")",
    meshOutputPerPrimitiveGranularity: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_meshOutputPerPrimitiveGranularity_offsetof)+")",
}, callof(V.VkPhysicalDeviceMeshShaderPropertiesNV_sizeof));


const VkDrawMeshTasksIndirectCommandNV = new C.CStruct("VkDrawMeshTasksIndirectCommandNV", {
    taskCount: "u32("+callof(V.VkDrawMeshTasksIndirectCommandNV_taskCount_offsetof)+")",
    firstTask: "u32("+callof(V.VkDrawMeshTasksIndirectCommandNV_firstTask_offsetof)+")",
}, callof(V.VkDrawMeshTasksIndirectCommandNV_sizeof));


const VkPhysicalDeviceMeshShaderFeaturesEXT = new C.CStruct("VkPhysicalDeviceMeshShaderFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceMeshShaderFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMeshShaderFeaturesEXT_pNext_offsetof)+")",
    taskShader: "u32("+callof(V.VkPhysicalDeviceMeshShaderFeaturesEXT_taskShader_offsetof)+")",
    meshShader: "u32("+callof(V.VkPhysicalDeviceMeshShaderFeaturesEXT_meshShader_offsetof)+")",
    multiviewMeshShader: "u32("+callof(V.VkPhysicalDeviceMeshShaderFeaturesEXT_multiviewMeshShader_offsetof)+")",
    primitiveFragmentShadingRateMeshShader: "u32("+callof(V.VkPhysicalDeviceMeshShaderFeaturesEXT_primitiveFragmentShadingRateMeshShader_offsetof)+")",
    meshShaderQueries: "u32("+callof(V.VkPhysicalDeviceMeshShaderFeaturesEXT_meshShaderQueries_offsetof)+")",
}, callof(V.VkPhysicalDeviceMeshShaderFeaturesEXT_sizeof));


const VkPhysicalDeviceMeshShaderPropertiesEXT = new C.CStruct("VkPhysicalDeviceMeshShaderPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_pNext_offsetof)+")",
    maxTaskWorkGroupTotalCount: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskWorkGroupTotalCount_offsetof)+")",
    maxTaskWorkGroupCount: "u32[3]("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskWorkGroupCount_offsetof)+")",
    maxTaskWorkGroupInvocations: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskWorkGroupInvocations_offsetof)+")",
    maxTaskWorkGroupSize: "u32[3]("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskWorkGroupSize_offsetof)+")",
    maxTaskPayloadSize: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskPayloadSize_offsetof)+")",
    maxTaskSharedMemorySize: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskSharedMemorySize_offsetof)+")",
    maxTaskPayloadAndSharedMemorySize: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxTaskPayloadAndSharedMemorySize_offsetof)+")",
    maxMeshWorkGroupTotalCount: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshWorkGroupTotalCount_offsetof)+")",
    maxMeshWorkGroupCount: "u32[3]("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshWorkGroupCount_offsetof)+")",
    maxMeshWorkGroupInvocations: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshWorkGroupInvocations_offsetof)+")",
    maxMeshWorkGroupSize: "u32[3]("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshWorkGroupSize_offsetof)+")",
    maxMeshSharedMemorySize: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshSharedMemorySize_offsetof)+")",
    maxMeshPayloadAndSharedMemorySize: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshPayloadAndSharedMemorySize_offsetof)+")",
    maxMeshOutputMemorySize: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshOutputMemorySize_offsetof)+")",
    maxMeshPayloadAndOutputMemorySize: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshPayloadAndOutputMemorySize_offsetof)+")",
    maxMeshOutputComponents: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshOutputComponents_offsetof)+")",
    maxMeshOutputVertices: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshOutputVertices_offsetof)+")",
    maxMeshOutputPrimitives: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshOutputPrimitives_offsetof)+")",
    maxMeshOutputLayers: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshOutputLayers_offsetof)+")",
    maxMeshMultiviewViewCount: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxMeshMultiviewViewCount_offsetof)+")",
    meshOutputPerVertexGranularity: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_meshOutputPerVertexGranularity_offsetof)+")",
    meshOutputPerPrimitiveGranularity: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_meshOutputPerPrimitiveGranularity_offsetof)+")",
    maxPreferredTaskWorkGroupInvocations: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxPreferredTaskWorkGroupInvocations_offsetof)+")",
    maxPreferredMeshWorkGroupInvocations: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_maxPreferredMeshWorkGroupInvocations_offsetof)+")",
    prefersLocalInvocationVertexOutput: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_prefersLocalInvocationVertexOutput_offsetof)+")",
    prefersLocalInvocationPrimitiveOutput: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_prefersLocalInvocationPrimitiveOutput_offsetof)+")",
    prefersCompactVertexOutput: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_prefersCompactVertexOutput_offsetof)+")",
    prefersCompactPrimitiveOutput: "u32("+callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_prefersCompactPrimitiveOutput_offsetof)+")",
}, callof(V.VkPhysicalDeviceMeshShaderPropertiesEXT_sizeof));


const VkDrawMeshTasksIndirectCommandEXT = new C.CStruct("VkDrawMeshTasksIndirectCommandEXT", {
    groupCountX: "u32("+callof(V.VkDrawMeshTasksIndirectCommandEXT_groupCountX_offsetof)+")",
    groupCountY: "u32("+callof(V.VkDrawMeshTasksIndirectCommandEXT_groupCountY_offsetof)+")",
    groupCountZ: "u32("+callof(V.VkDrawMeshTasksIndirectCommandEXT_groupCountZ_offsetof)+")",
}, callof(V.VkDrawMeshTasksIndirectCommandEXT_sizeof));


const VkRayTracingShaderGroupCreateInfoNV = new C.CStruct("VkRayTracingShaderGroupCreateInfoNV", {
    sType: "u32("+callof(V.VkRayTracingShaderGroupCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRayTracingShaderGroupCreateInfoNV_pNext_offsetof)+")",
    type: "u32("+callof(V.VkRayTracingShaderGroupCreateInfoNV_type_offsetof)+")",
    generalShader: "u32("+callof(V.VkRayTracingShaderGroupCreateInfoNV_generalShader_offsetof)+")",
    closestHitShader: "u32("+callof(V.VkRayTracingShaderGroupCreateInfoNV_closestHitShader_offsetof)+")",
    anyHitShader: "u32("+callof(V.VkRayTracingShaderGroupCreateInfoNV_anyHitShader_offsetof)+")",
    intersectionShader: "u32("+callof(V.VkRayTracingShaderGroupCreateInfoNV_intersectionShader_offsetof)+")",
}, callof(V.VkRayTracingShaderGroupCreateInfoNV_sizeof));


const VkRayTracingShaderGroupCreateInfoKHR = new C.CStruct("VkRayTracingShaderGroupCreateInfoKHR", {
    sType: "u32("+callof(V.VkRayTracingShaderGroupCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRayTracingShaderGroupCreateInfoKHR_pNext_offsetof)+")",
    type: "u32("+callof(V.VkRayTracingShaderGroupCreateInfoKHR_type_offsetof)+")",
    generalShader: "u32("+callof(V.VkRayTracingShaderGroupCreateInfoKHR_generalShader_offsetof)+")",
    closestHitShader: "u32("+callof(V.VkRayTracingShaderGroupCreateInfoKHR_closestHitShader_offsetof)+")",
    anyHitShader: "u32("+callof(V.VkRayTracingShaderGroupCreateInfoKHR_anyHitShader_offsetof)+")",
    intersectionShader: "u32("+callof(V.VkRayTracingShaderGroupCreateInfoKHR_intersectionShader_offsetof)+")",
    pShaderGroupCaptureReplayHandle: "u64("+callof(V.VkRayTracingShaderGroupCreateInfoKHR_pShaderGroupCaptureReplayHandle_offsetof)+")",
}, callof(V.VkRayTracingShaderGroupCreateInfoKHR_sizeof));


const VkRayTracingPipelineCreateInfoNV = new C.CStruct("VkRayTracingPipelineCreateInfoNV", {
    sType: "u32("+callof(V.VkRayTracingPipelineCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRayTracingPipelineCreateInfoNV_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkRayTracingPipelineCreateInfoNV_flags_offsetof)+")",
    stageCount: "u32("+callof(V.VkRayTracingPipelineCreateInfoNV_stageCount_offsetof)+")",
    pStages: "u64("+callof(V.VkRayTracingPipelineCreateInfoNV_pStages_offsetof)+")",
    groupCount: "u32("+callof(V.VkRayTracingPipelineCreateInfoNV_groupCount_offsetof)+")",
    pGroups: "u64("+callof(V.VkRayTracingPipelineCreateInfoNV_pGroups_offsetof)+")",
    maxRecursionDepth: "u32("+callof(V.VkRayTracingPipelineCreateInfoNV_maxRecursionDepth_offsetof)+")",
    layout: "u64("+callof(V.VkRayTracingPipelineCreateInfoNV_layout_offsetof)+")",
    basePipelineHandle: "u64("+callof(V.VkRayTracingPipelineCreateInfoNV_basePipelineHandle_offsetof)+")",
    basePipelineIndex: "i32("+callof(V.VkRayTracingPipelineCreateInfoNV_basePipelineIndex_offsetof)+")",
}, callof(V.VkRayTracingPipelineCreateInfoNV_sizeof));


const VkRayTracingPipelineCreateInfoKHR = new C.CStruct("VkRayTracingPipelineCreateInfoKHR", {
    sType: "u32("+callof(V.VkRayTracingPipelineCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRayTracingPipelineCreateInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkRayTracingPipelineCreateInfoKHR_flags_offsetof)+")",
    stageCount: "u32("+callof(V.VkRayTracingPipelineCreateInfoKHR_stageCount_offsetof)+")",
    pStages: "u64("+callof(V.VkRayTracingPipelineCreateInfoKHR_pStages_offsetof)+")",
    groupCount: "u32("+callof(V.VkRayTracingPipelineCreateInfoKHR_groupCount_offsetof)+")",
    pGroups: "u64("+callof(V.VkRayTracingPipelineCreateInfoKHR_pGroups_offsetof)+")",
    maxPipelineRayRecursionDepth: "u32("+callof(V.VkRayTracingPipelineCreateInfoKHR_maxPipelineRayRecursionDepth_offsetof)+")",
    pLibraryInfo: "u64("+callof(V.VkRayTracingPipelineCreateInfoKHR_pLibraryInfo_offsetof)+")",
    pLibraryInterface: "u64("+callof(V.VkRayTracingPipelineCreateInfoKHR_pLibraryInterface_offsetof)+")",
    pDynamicState: "u64("+callof(V.VkRayTracingPipelineCreateInfoKHR_pDynamicState_offsetof)+")",
    layout: "u64("+callof(V.VkRayTracingPipelineCreateInfoKHR_layout_offsetof)+")",
    basePipelineHandle: "u64("+callof(V.VkRayTracingPipelineCreateInfoKHR_basePipelineHandle_offsetof)+")",
    basePipelineIndex: "i32("+callof(V.VkRayTracingPipelineCreateInfoKHR_basePipelineIndex_offsetof)+")",
}, callof(V.VkRayTracingPipelineCreateInfoKHR_sizeof));


const VkGeometryTrianglesNV = new C.CStruct("VkGeometryTrianglesNV", {
    sType: "u32("+callof(V.VkGeometryTrianglesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkGeometryTrianglesNV_pNext_offsetof)+")",
    vertexData: "u64("+callof(V.VkGeometryTrianglesNV_vertexData_offsetof)+")",
    vertexOffset: "u64("+callof(V.VkGeometryTrianglesNV_vertexOffset_offsetof)+")",
    vertexCount: "u32("+callof(V.VkGeometryTrianglesNV_vertexCount_offsetof)+")",
    vertexStride: "u64("+callof(V.VkGeometryTrianglesNV_vertexStride_offsetof)+")",
    vertexFormat: "u32("+callof(V.VkGeometryTrianglesNV_vertexFormat_offsetof)+")",
    indexData: "u64("+callof(V.VkGeometryTrianglesNV_indexData_offsetof)+")",
    indexOffset: "u64("+callof(V.VkGeometryTrianglesNV_indexOffset_offsetof)+")",
    indexCount: "u32("+callof(V.VkGeometryTrianglesNV_indexCount_offsetof)+")",
    indexType: "u32("+callof(V.VkGeometryTrianglesNV_indexType_offsetof)+")",
    transformData: "u64("+callof(V.VkGeometryTrianglesNV_transformData_offsetof)+")",
    transformOffset: "u64("+callof(V.VkGeometryTrianglesNV_transformOffset_offsetof)+")",
}, callof(V.VkGeometryTrianglesNV_sizeof));


const VkGeometryAABBNV = new C.CStruct("VkGeometryAABBNV", {
    sType: "u32("+callof(V.VkGeometryAABBNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkGeometryAABBNV_pNext_offsetof)+")",
    aabbData: "u64("+callof(V.VkGeometryAABBNV_aabbData_offsetof)+")",
    numAABBs: "u32("+callof(V.VkGeometryAABBNV_numAABBs_offsetof)+")",
    stride: "u32("+callof(V.VkGeometryAABBNV_stride_offsetof)+")",
    offset: "u64("+callof(V.VkGeometryAABBNV_offset_offsetof)+")",
}, callof(V.VkGeometryAABBNV_sizeof));


const VkGeometryDataNV = new C.CStruct("VkGeometryDataNV", {
    triangles: "u32("+callof(V.VkGeometryDataNV_triangles_offsetof)+")",
    aabbs: "u32("+callof(V.VkGeometryDataNV_aabbs_offsetof)+")",
}, callof(V.VkGeometryDataNV_sizeof));


const VkGeometryNV = new C.CStruct("VkGeometryNV", {
    sType: "u32("+callof(V.VkGeometryNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkGeometryNV_pNext_offsetof)+")",
    geometryType: "u32("+callof(V.VkGeometryNV_geometryType_offsetof)+")",
    geometry: "u32("+callof(V.VkGeometryNV_geometry_offsetof)+")",
    flags: "u32("+callof(V.VkGeometryNV_flags_offsetof)+")",
}, callof(V.VkGeometryNV_sizeof));


const VkAccelerationStructureInfoNV = new C.CStruct("VkAccelerationStructureInfoNV", {
    sType: "u32("+callof(V.VkAccelerationStructureInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureInfoNV_pNext_offsetof)+")",
    type: "u32("+callof(V.VkAccelerationStructureInfoNV_type_offsetof)+")",
    flags: "u32("+callof(V.VkAccelerationStructureInfoNV_flags_offsetof)+")",
    instanceCount: "u32("+callof(V.VkAccelerationStructureInfoNV_instanceCount_offsetof)+")",
    geometryCount: "u32("+callof(V.VkAccelerationStructureInfoNV_geometryCount_offsetof)+")",
    pGeometries: "u64("+callof(V.VkAccelerationStructureInfoNV_pGeometries_offsetof)+")",
}, callof(V.VkAccelerationStructureInfoNV_sizeof));


const VkAccelerationStructureCreateInfoNV = new C.CStruct("VkAccelerationStructureCreateInfoNV", {
    sType: "u32("+callof(V.VkAccelerationStructureCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureCreateInfoNV_pNext_offsetof)+")",
    compactedSize: "u64("+callof(V.VkAccelerationStructureCreateInfoNV_compactedSize_offsetof)+")",
    info: "u32("+callof(V.VkAccelerationStructureCreateInfoNV_info_offsetof)+")",
}, callof(V.VkAccelerationStructureCreateInfoNV_sizeof));


const VkBindAccelerationStructureMemoryInfoNV = new C.CStruct("VkBindAccelerationStructureMemoryInfoNV", {
    sType: "u32("+callof(V.VkBindAccelerationStructureMemoryInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBindAccelerationStructureMemoryInfoNV_pNext_offsetof)+")",
    accelerationStructure: "u32("+callof(V.VkBindAccelerationStructureMemoryInfoNV_accelerationStructure_offsetof)+")",
    memory: "u64("+callof(V.VkBindAccelerationStructureMemoryInfoNV_memory_offsetof)+")",
    memoryOffset: "u64("+callof(V.VkBindAccelerationStructureMemoryInfoNV_memoryOffset_offsetof)+")",
    deviceIndexCount: "u32("+callof(V.VkBindAccelerationStructureMemoryInfoNV_deviceIndexCount_offsetof)+")",
    pDeviceIndices: "u64("+callof(V.VkBindAccelerationStructureMemoryInfoNV_pDeviceIndices_offsetof)+")",
}, callof(V.VkBindAccelerationStructureMemoryInfoNV_sizeof));


const VkWriteDescriptorSetAccelerationStructureKHR = new C.CStruct("VkWriteDescriptorSetAccelerationStructureKHR", {
    sType: "u32("+callof(V.VkWriteDescriptorSetAccelerationStructureKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkWriteDescriptorSetAccelerationStructureKHR_pNext_offsetof)+")",
    accelerationStructureCount: "u32("+callof(V.VkWriteDescriptorSetAccelerationStructureKHR_accelerationStructureCount_offsetof)+")",
    pAccelerationStructures: "u64("+callof(V.VkWriteDescriptorSetAccelerationStructureKHR_pAccelerationStructures_offsetof)+")",
}, callof(V.VkWriteDescriptorSetAccelerationStructureKHR_sizeof));


const VkWriteDescriptorSetAccelerationStructureNV = new C.CStruct("VkWriteDescriptorSetAccelerationStructureNV", {
    sType: "u32("+callof(V.VkWriteDescriptorSetAccelerationStructureNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkWriteDescriptorSetAccelerationStructureNV_pNext_offsetof)+")",
    accelerationStructureCount: "u32("+callof(V.VkWriteDescriptorSetAccelerationStructureNV_accelerationStructureCount_offsetof)+")",
    pAccelerationStructures: "u64("+callof(V.VkWriteDescriptorSetAccelerationStructureNV_pAccelerationStructures_offsetof)+")",
}, callof(V.VkWriteDescriptorSetAccelerationStructureNV_sizeof));


const VkAccelerationStructureMemoryRequirementsInfoNV = new C.CStruct("VkAccelerationStructureMemoryRequirementsInfoNV", {
    sType: "u32("+callof(V.VkAccelerationStructureMemoryRequirementsInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureMemoryRequirementsInfoNV_pNext_offsetof)+")",
    type: "u32("+callof(V.VkAccelerationStructureMemoryRequirementsInfoNV_type_offsetof)+")",
    accelerationStructure: "u32("+callof(V.VkAccelerationStructureMemoryRequirementsInfoNV_accelerationStructure_offsetof)+")",
}, callof(V.VkAccelerationStructureMemoryRequirementsInfoNV_sizeof));


const VkPhysicalDeviceAccelerationStructureFeaturesKHR = new C.CStruct("VkPhysicalDeviceAccelerationStructureFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_pNext_offsetof)+")",
    accelerationStructure: "u32("+callof(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_accelerationStructure_offsetof)+")",
    accelerationStructureCaptureReplay: "u32("+callof(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_accelerationStructureCaptureReplay_offsetof)+")",
    accelerationStructureIndirectBuild: "u32("+callof(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_accelerationStructureIndirectBuild_offsetof)+")",
    accelerationStructureHostCommands: "u32("+callof(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_accelerationStructureHostCommands_offsetof)+")",
    descriptorBindingAccelerationStructureUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_descriptorBindingAccelerationStructureUpdateAfterBind_offsetof)+")",
}, callof(V.VkPhysicalDeviceAccelerationStructureFeaturesKHR_sizeof));


const VkPhysicalDeviceRayTracingPipelineFeaturesKHR = new C.CStruct("VkPhysicalDeviceRayTracingPipelineFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_pNext_offsetof)+")",
    rayTracingPipeline: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_rayTracingPipeline_offsetof)+")",
    rayTracingPipelineShaderGroupHandleCaptureReplay: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_rayTracingPipelineShaderGroupHandleCaptureReplay_offsetof)+")",
    rayTracingPipelineShaderGroupHandleCaptureReplayMixed: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_rayTracingPipelineShaderGroupHandleCaptureReplayMixed_offsetof)+")",
    rayTracingPipelineTraceRaysIndirect: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_rayTracingPipelineTraceRaysIndirect_offsetof)+")",
    rayTraversalPrimitiveCulling: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_rayTraversalPrimitiveCulling_offsetof)+")",
}, callof(V.VkPhysicalDeviceRayTracingPipelineFeaturesKHR_sizeof));


const VkPhysicalDeviceRayQueryFeaturesKHR = new C.CStruct("VkPhysicalDeviceRayQueryFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceRayQueryFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRayQueryFeaturesKHR_pNext_offsetof)+")",
    rayQuery: "u32("+callof(V.VkPhysicalDeviceRayQueryFeaturesKHR_rayQuery_offsetof)+")",
}, callof(V.VkPhysicalDeviceRayQueryFeaturesKHR_sizeof));


const VkPhysicalDeviceAccelerationStructurePropertiesKHR = new C.CStruct("VkPhysicalDeviceAccelerationStructurePropertiesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_pNext_offsetof)+")",
    maxGeometryCount: "u64("+callof(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxGeometryCount_offsetof)+")",
    maxInstanceCount: "u64("+callof(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxInstanceCount_offsetof)+")",
    maxPrimitiveCount: "u64("+callof(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxPrimitiveCount_offsetof)+")",
    maxPerStageDescriptorAccelerationStructures: "u32("+callof(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxPerStageDescriptorAccelerationStructures_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindAccelerationStructures: "u32("+callof(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxPerStageDescriptorUpdateAfterBindAccelerationStructures_offsetof)+")",
    maxDescriptorSetAccelerationStructures: "u32("+callof(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxDescriptorSetAccelerationStructures_offsetof)+")",
    maxDescriptorSetUpdateAfterBindAccelerationStructures: "u32("+callof(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_maxDescriptorSetUpdateAfterBindAccelerationStructures_offsetof)+")",
    minAccelerationStructureScratchOffsetAlignment: "u32("+callof(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_minAccelerationStructureScratchOffsetAlignment_offsetof)+")",
}, callof(V.VkPhysicalDeviceAccelerationStructurePropertiesKHR_sizeof));


const VkPhysicalDeviceRayTracingPipelinePropertiesKHR = new C.CStruct("VkPhysicalDeviceRayTracingPipelinePropertiesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_pNext_offsetof)+")",
    shaderGroupHandleSize: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_shaderGroupHandleSize_offsetof)+")",
    maxRayRecursionDepth: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_maxRayRecursionDepth_offsetof)+")",
    maxShaderGroupStride: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_maxShaderGroupStride_offsetof)+")",
    shaderGroupBaseAlignment: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_shaderGroupBaseAlignment_offsetof)+")",
    shaderGroupHandleCaptureReplaySize: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_shaderGroupHandleCaptureReplaySize_offsetof)+")",
    maxRayDispatchInvocationCount: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_maxRayDispatchInvocationCount_offsetof)+")",
    shaderGroupHandleAlignment: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_shaderGroupHandleAlignment_offsetof)+")",
    maxRayHitAttributeSize: "u32("+callof(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_maxRayHitAttributeSize_offsetof)+")",
}, callof(V.VkPhysicalDeviceRayTracingPipelinePropertiesKHR_sizeof));


const VkPhysicalDeviceRayTracingPropertiesNV = new C.CStruct("VkPhysicalDeviceRayTracingPropertiesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceRayTracingPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRayTracingPropertiesNV_pNext_offsetof)+")",
    shaderGroupHandleSize: "u32("+callof(V.VkPhysicalDeviceRayTracingPropertiesNV_shaderGroupHandleSize_offsetof)+")",
    maxRecursionDepth: "u32("+callof(V.VkPhysicalDeviceRayTracingPropertiesNV_maxRecursionDepth_offsetof)+")",
    maxShaderGroupStride: "u32("+callof(V.VkPhysicalDeviceRayTracingPropertiesNV_maxShaderGroupStride_offsetof)+")",
    shaderGroupBaseAlignment: "u32("+callof(V.VkPhysicalDeviceRayTracingPropertiesNV_shaderGroupBaseAlignment_offsetof)+")",
    maxGeometryCount: "u64("+callof(V.VkPhysicalDeviceRayTracingPropertiesNV_maxGeometryCount_offsetof)+")",
    maxInstanceCount: "u64("+callof(V.VkPhysicalDeviceRayTracingPropertiesNV_maxInstanceCount_offsetof)+")",
    maxTriangleCount: "u64("+callof(V.VkPhysicalDeviceRayTracingPropertiesNV_maxTriangleCount_offsetof)+")",
    maxDescriptorSetAccelerationStructures: "u32("+callof(V.VkPhysicalDeviceRayTracingPropertiesNV_maxDescriptorSetAccelerationStructures_offsetof)+")",
}, callof(V.VkPhysicalDeviceRayTracingPropertiesNV_sizeof));


const VkStridedDeviceAddressRegionKHR = new C.CStruct("VkStridedDeviceAddressRegionKHR", {
    deviceAddress: "u64("+callof(V.VkStridedDeviceAddressRegionKHR_deviceAddress_offsetof)+")",
    stride: "u64("+callof(V.VkStridedDeviceAddressRegionKHR_stride_offsetof)+")",
    size: "u64("+callof(V.VkStridedDeviceAddressRegionKHR_size_offsetof)+")",
}, callof(V.VkStridedDeviceAddressRegionKHR_sizeof));


const VkTraceRaysIndirectCommandKHR = new C.CStruct("VkTraceRaysIndirectCommandKHR", {
    width: "u32("+callof(V.VkTraceRaysIndirectCommandKHR_width_offsetof)+")",
    height: "u32("+callof(V.VkTraceRaysIndirectCommandKHR_height_offsetof)+")",
    depth: "u32("+callof(V.VkTraceRaysIndirectCommandKHR_depth_offsetof)+")",
}, callof(V.VkTraceRaysIndirectCommandKHR_sizeof));


const VkTraceRaysIndirectCommand2KHR = new C.CStruct("VkTraceRaysIndirectCommand2KHR", {
    raygenShaderRecordAddress: "u64("+callof(V.VkTraceRaysIndirectCommand2KHR_raygenShaderRecordAddress_offsetof)+")",
    raygenShaderRecordSize: "u64("+callof(V.VkTraceRaysIndirectCommand2KHR_raygenShaderRecordSize_offsetof)+")",
    missShaderBindingTableAddress: "u64("+callof(V.VkTraceRaysIndirectCommand2KHR_missShaderBindingTableAddress_offsetof)+")",
    missShaderBindingTableSize: "u64("+callof(V.VkTraceRaysIndirectCommand2KHR_missShaderBindingTableSize_offsetof)+")",
    missShaderBindingTableStride: "u64("+callof(V.VkTraceRaysIndirectCommand2KHR_missShaderBindingTableStride_offsetof)+")",
    hitShaderBindingTableAddress: "u64("+callof(V.VkTraceRaysIndirectCommand2KHR_hitShaderBindingTableAddress_offsetof)+")",
    hitShaderBindingTableSize: "u64("+callof(V.VkTraceRaysIndirectCommand2KHR_hitShaderBindingTableSize_offsetof)+")",
    hitShaderBindingTableStride: "u64("+callof(V.VkTraceRaysIndirectCommand2KHR_hitShaderBindingTableStride_offsetof)+")",
    callableShaderBindingTableAddress: "u64("+callof(V.VkTraceRaysIndirectCommand2KHR_callableShaderBindingTableAddress_offsetof)+")",
    callableShaderBindingTableSize: "u64("+callof(V.VkTraceRaysIndirectCommand2KHR_callableShaderBindingTableSize_offsetof)+")",
    callableShaderBindingTableStride: "u64("+callof(V.VkTraceRaysIndirectCommand2KHR_callableShaderBindingTableStride_offsetof)+")",
    width: "u32("+callof(V.VkTraceRaysIndirectCommand2KHR_width_offsetof)+")",
    height: "u32("+callof(V.VkTraceRaysIndirectCommand2KHR_height_offsetof)+")",
    depth: "u32("+callof(V.VkTraceRaysIndirectCommand2KHR_depth_offsetof)+")",
}, callof(V.VkTraceRaysIndirectCommand2KHR_sizeof));


const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR = new C.CStruct("VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR_pNext_offsetof)+")",
    rayTracingMaintenance1: "u32("+callof(V.VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR_rayTracingMaintenance1_offsetof)+")",
    rayTracingPipelineTraceRaysIndirect2: "u32("+callof(V.VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR_rayTracingPipelineTraceRaysIndirect2_offsetof)+")",
}, callof(V.VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR_sizeof));


const VkDrmFormatModifierPropertiesListEXT = new C.CStruct("VkDrmFormatModifierPropertiesListEXT", {
    sType: "u32("+callof(V.VkDrmFormatModifierPropertiesListEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDrmFormatModifierPropertiesListEXT_pNext_offsetof)+")",
    drmFormatModifierCount: "u32("+callof(V.VkDrmFormatModifierPropertiesListEXT_drmFormatModifierCount_offsetof)+")",
    pDrmFormatModifierProperties: "u64("+callof(V.VkDrmFormatModifierPropertiesListEXT_pDrmFormatModifierProperties_offsetof)+")",
}, callof(V.VkDrmFormatModifierPropertiesListEXT_sizeof));


const VkDrmFormatModifierPropertiesEXT = new C.CStruct("VkDrmFormatModifierPropertiesEXT", {
    drmFormatModifier: "u64("+callof(V.VkDrmFormatModifierPropertiesEXT_drmFormatModifier_offsetof)+")",
    drmFormatModifierPlaneCount: "u32("+callof(V.VkDrmFormatModifierPropertiesEXT_drmFormatModifierPlaneCount_offsetof)+")",
    drmFormatModifierTilingFeatures: "u32("+callof(V.VkDrmFormatModifierPropertiesEXT_drmFormatModifierTilingFeatures_offsetof)+")",
}, callof(V.VkDrmFormatModifierPropertiesEXT_sizeof));


const VkPhysicalDeviceImageDrmFormatModifierInfoEXT = new C.CStruct("VkPhysicalDeviceImageDrmFormatModifierInfoEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_pNext_offsetof)+")",
    drmFormatModifier: "u64("+callof(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_drmFormatModifier_offsetof)+")",
    sharingMode: "u32("+callof(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_sharingMode_offsetof)+")",
    queueFamilyIndexCount: "u32("+callof(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_queueFamilyIndexCount_offsetof)+")",
    pQueueFamilyIndices: "u64("+callof(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_pQueueFamilyIndices_offsetof)+")",
}, callof(V.VkPhysicalDeviceImageDrmFormatModifierInfoEXT_sizeof));


const VkImageDrmFormatModifierListCreateInfoEXT = new C.CStruct("VkImageDrmFormatModifierListCreateInfoEXT", {
    sType: "u32("+callof(V.VkImageDrmFormatModifierListCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageDrmFormatModifierListCreateInfoEXT_pNext_offsetof)+")",
    drmFormatModifierCount: "u32("+callof(V.VkImageDrmFormatModifierListCreateInfoEXT_drmFormatModifierCount_offsetof)+")",
    pDrmFormatModifiers: "u64("+callof(V.VkImageDrmFormatModifierListCreateInfoEXT_pDrmFormatModifiers_offsetof)+")",
}, callof(V.VkImageDrmFormatModifierListCreateInfoEXT_sizeof));


const VkImageDrmFormatModifierExplicitCreateInfoEXT = new C.CStruct("VkImageDrmFormatModifierExplicitCreateInfoEXT", {
    sType: "u32("+callof(V.VkImageDrmFormatModifierExplicitCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageDrmFormatModifierExplicitCreateInfoEXT_pNext_offsetof)+")",
    drmFormatModifier: "u64("+callof(V.VkImageDrmFormatModifierExplicitCreateInfoEXT_drmFormatModifier_offsetof)+")",
    drmFormatModifierPlaneCount: "u32("+callof(V.VkImageDrmFormatModifierExplicitCreateInfoEXT_drmFormatModifierPlaneCount_offsetof)+")",
    pPlaneLayouts: "u64("+callof(V.VkImageDrmFormatModifierExplicitCreateInfoEXT_pPlaneLayouts_offsetof)+")",
}, callof(V.VkImageDrmFormatModifierExplicitCreateInfoEXT_sizeof));


const VkImageDrmFormatModifierPropertiesEXT = new C.CStruct("VkImageDrmFormatModifierPropertiesEXT", {
    sType: "u32("+callof(V.VkImageDrmFormatModifierPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageDrmFormatModifierPropertiesEXT_pNext_offsetof)+")",
    drmFormatModifier: "u64("+callof(V.VkImageDrmFormatModifierPropertiesEXT_drmFormatModifier_offsetof)+")",
}, callof(V.VkImageDrmFormatModifierPropertiesEXT_sizeof));


const VkImageStencilUsageCreateInfo = new C.CStruct("VkImageStencilUsageCreateInfo", {
    sType: "u32("+callof(V.VkImageStencilUsageCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageStencilUsageCreateInfo_pNext_offsetof)+")",
    stencilUsage: "u32("+callof(V.VkImageStencilUsageCreateInfo_stencilUsage_offsetof)+")",
}, callof(V.VkImageStencilUsageCreateInfo_sizeof));


const VkImageStencilUsageCreateInfoEXT = new C.CStruct("VkImageStencilUsageCreateInfoEXT", {

}, callof(V.VkImageStencilUsageCreateInfoEXT_sizeof));


const VkDeviceMemoryOverallocationCreateInfoAMD = new C.CStruct("VkDeviceMemoryOverallocationCreateInfoAMD", {
    sType: "u32("+callof(V.VkDeviceMemoryOverallocationCreateInfoAMD_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceMemoryOverallocationCreateInfoAMD_pNext_offsetof)+")",
    overallocationBehavior: "u32("+callof(V.VkDeviceMemoryOverallocationCreateInfoAMD_overallocationBehavior_offsetof)+")",
}, callof(V.VkDeviceMemoryOverallocationCreateInfoAMD_sizeof));


const VkPhysicalDeviceFragmentDensityMapFeaturesEXT = new C.CStruct("VkPhysicalDeviceFragmentDensityMapFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMapFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentDensityMapFeaturesEXT_pNext_offsetof)+")",
    fragmentDensityMap: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMapFeaturesEXT_fragmentDensityMap_offsetof)+")",
    fragmentDensityMapDynamic: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMapFeaturesEXT_fragmentDensityMapDynamic_offsetof)+")",
    fragmentDensityMapNonSubsampledImages: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMapFeaturesEXT_fragmentDensityMapNonSubsampledImages_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentDensityMapFeaturesEXT_sizeof));


const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT = new C.CStruct("VkPhysicalDeviceFragmentDensityMap2FeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMap2FeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentDensityMap2FeaturesEXT_pNext_offsetof)+")",
    fragmentDensityMapDeferred: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMap2FeaturesEXT_fragmentDensityMapDeferred_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentDensityMap2FeaturesEXT_sizeof));


const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM = new C.CStruct("VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM_pNext_offsetof)+")",
    fragmentDensityMapOffset: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM_fragmentDensityMapOffset_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM_sizeof));


const VkPhysicalDeviceFragmentDensityMapPropertiesEXT = new C.CStruct("VkPhysicalDeviceFragmentDensityMapPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMapPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentDensityMapPropertiesEXT_pNext_offsetof)+")",
    minFragmentDensityTexelSize: "VkExtent2D("+callof(V.VkPhysicalDeviceFragmentDensityMapPropertiesEXT_minFragmentDensityTexelSize_offsetof)+")",
    maxFragmentDensityTexelSize: "VkExtent2D("+callof(V.VkPhysicalDeviceFragmentDensityMapPropertiesEXT_maxFragmentDensityTexelSize_offsetof)+")",
    fragmentDensityInvocations: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMapPropertiesEXT_fragmentDensityInvocations_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentDensityMapPropertiesEXT_sizeof));


const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT = new C.CStruct("VkPhysicalDeviceFragmentDensityMap2PropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_pNext_offsetof)+")",
    subsampledLoads: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_subsampledLoads_offsetof)+")",
    subsampledCoarseReconstructionEarlyAccess: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_subsampledCoarseReconstructionEarlyAccess_offsetof)+")",
    maxSubsampledArrayLayers: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_maxSubsampledArrayLayers_offsetof)+")",
    maxDescriptorSetSubsampledSamplers: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_maxDescriptorSetSubsampledSamplers_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentDensityMap2PropertiesEXT_sizeof));


const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM = new C.CStruct("VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM_pNext_offsetof)+")",
    fragmentDensityOffsetGranularity: "VkExtent2D("+callof(V.VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM_fragmentDensityOffsetGranularity_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM_sizeof));


const VkRenderPassFragmentDensityMapCreateInfoEXT = new C.CStruct("VkRenderPassFragmentDensityMapCreateInfoEXT", {
    sType: "u32("+callof(V.VkRenderPassFragmentDensityMapCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderPassFragmentDensityMapCreateInfoEXT_pNext_offsetof)+")",
    fragmentDensityMapAttachment: "u32("+callof(V.VkRenderPassFragmentDensityMapCreateInfoEXT_fragmentDensityMapAttachment_offsetof)+")",
}, callof(V.VkRenderPassFragmentDensityMapCreateInfoEXT_sizeof));


const VkSubpassFragmentDensityMapOffsetEndInfoQCOM = new C.CStruct("VkSubpassFragmentDensityMapOffsetEndInfoQCOM", {
    sType: "u32("+callof(V.VkSubpassFragmentDensityMapOffsetEndInfoQCOM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSubpassFragmentDensityMapOffsetEndInfoQCOM_pNext_offsetof)+")",
    fragmentDensityOffsetCount: "u32("+callof(V.VkSubpassFragmentDensityMapOffsetEndInfoQCOM_fragmentDensityOffsetCount_offsetof)+")",
    pFragmentDensityOffsets: "u64("+callof(V.VkSubpassFragmentDensityMapOffsetEndInfoQCOM_pFragmentDensityOffsets_offsetof)+")",
}, callof(V.VkSubpassFragmentDensityMapOffsetEndInfoQCOM_sizeof));


const VkPhysicalDeviceScalarBlockLayoutFeatures = new C.CStruct("VkPhysicalDeviceScalarBlockLayoutFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceScalarBlockLayoutFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceScalarBlockLayoutFeatures_pNext_offsetof)+")",
    scalarBlockLayout: "u32("+callof(V.VkPhysicalDeviceScalarBlockLayoutFeatures_scalarBlockLayout_offsetof)+")",
}, callof(V.VkPhysicalDeviceScalarBlockLayoutFeatures_sizeof));


const VkPhysicalDeviceScalarBlockLayoutFeaturesEXT = new C.CStruct("VkPhysicalDeviceScalarBlockLayoutFeaturesEXT", {

}, callof(V.VkPhysicalDeviceScalarBlockLayoutFeaturesEXT_sizeof));


const VkSurfaceProtectedCapabilitiesKHR = new C.CStruct("VkSurfaceProtectedCapabilitiesKHR", {
    sType: "u32("+callof(V.VkSurfaceProtectedCapabilitiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSurfaceProtectedCapabilitiesKHR_pNext_offsetof)+")",
    supportsProtected: "u32("+callof(V.VkSurfaceProtectedCapabilitiesKHR_supportsProtected_offsetof)+")",
}, callof(V.VkSurfaceProtectedCapabilitiesKHR_sizeof));


const VkPhysicalDeviceUniformBufferStandardLayoutFeatures = new C.CStruct("VkPhysicalDeviceUniformBufferStandardLayoutFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceUniformBufferStandardLayoutFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pNext_offsetof)+")",
    uniformBufferStandardLayout: "u32("+callof(V.VkPhysicalDeviceUniformBufferStandardLayoutFeatures_uniformBufferStandardLayout_offsetof)+")",
}, callof(V.VkPhysicalDeviceUniformBufferStandardLayoutFeatures_sizeof));


const VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR = new C.CStruct("VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR", {

}, callof(V.VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR_sizeof));


const VkPhysicalDeviceDepthClipEnableFeaturesEXT = new C.CStruct("VkPhysicalDeviceDepthClipEnableFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceDepthClipEnableFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDepthClipEnableFeaturesEXT_pNext_offsetof)+")",
    depthClipEnable: "u32("+callof(V.VkPhysicalDeviceDepthClipEnableFeaturesEXT_depthClipEnable_offsetof)+")",
}, callof(V.VkPhysicalDeviceDepthClipEnableFeaturesEXT_sizeof));


const VkPipelineRasterizationDepthClipStateCreateInfoEXT = new C.CStruct("VkPipelineRasterizationDepthClipStateCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineRasterizationDepthClipStateCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineRasterizationDepthClipStateCreateInfoEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineRasterizationDepthClipStateCreateInfoEXT_flags_offsetof)+")",
    depthClipEnable: "u32("+callof(V.VkPipelineRasterizationDepthClipStateCreateInfoEXT_depthClipEnable_offsetof)+")",
}, callof(V.VkPipelineRasterizationDepthClipStateCreateInfoEXT_sizeof));


const VkPhysicalDeviceMemoryBudgetPropertiesEXT = new C.CStruct("VkPhysicalDeviceMemoryBudgetPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceMemoryBudgetPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMemoryBudgetPropertiesEXT_pNext_offsetof)+")",
    heapBudget: "u64["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceMemoryBudgetPropertiesEXT_heapBudget_offsetof)+")",
    heapUsage: "u64["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceMemoryBudgetPropertiesEXT_heapUsage_offsetof)+")",
}, callof(V.VkPhysicalDeviceMemoryBudgetPropertiesEXT_sizeof));


const VkPhysicalDeviceMemoryPriorityFeaturesEXT = new C.CStruct("VkPhysicalDeviceMemoryPriorityFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceMemoryPriorityFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMemoryPriorityFeaturesEXT_pNext_offsetof)+")",
    memoryPriority: "u32("+callof(V.VkPhysicalDeviceMemoryPriorityFeaturesEXT_memoryPriority_offsetof)+")",
}, callof(V.VkPhysicalDeviceMemoryPriorityFeaturesEXT_sizeof));


const VkMemoryPriorityAllocateInfoEXT = new C.CStruct("VkMemoryPriorityAllocateInfoEXT", {
    sType: "u32("+callof(V.VkMemoryPriorityAllocateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryPriorityAllocateInfoEXT_pNext_offsetof)+")",
    priority: "f32("+callof(V.VkMemoryPriorityAllocateInfoEXT_priority_offsetof)+")",
}, callof(V.VkMemoryPriorityAllocateInfoEXT_sizeof));


const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT = new C.CStruct("VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT_pNext_offsetof)+")",
    pageableDeviceLocalMemory: "u32("+callof(V.VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT_pageableDeviceLocalMemory_offsetof)+")",
}, callof(V.VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT_sizeof));


const VkPhysicalDeviceBufferDeviceAddressFeatures = new C.CStruct("VkPhysicalDeviceBufferDeviceAddressFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceBufferDeviceAddressFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceBufferDeviceAddressFeatures_pNext_offsetof)+")",
    bufferDeviceAddress: "u32("+callof(V.VkPhysicalDeviceBufferDeviceAddressFeatures_bufferDeviceAddress_offsetof)+")",
    bufferDeviceAddressCaptureReplay: "u32("+callof(V.VkPhysicalDeviceBufferDeviceAddressFeatures_bufferDeviceAddressCaptureReplay_offsetof)+")",
    bufferDeviceAddressMultiDevice: "u32("+callof(V.VkPhysicalDeviceBufferDeviceAddressFeatures_bufferDeviceAddressMultiDevice_offsetof)+")",
}, callof(V.VkPhysicalDeviceBufferDeviceAddressFeatures_sizeof));


const VkPhysicalDeviceBufferDeviceAddressFeaturesKHR = new C.CStruct("VkPhysicalDeviceBufferDeviceAddressFeaturesKHR", {

}, callof(V.VkPhysicalDeviceBufferDeviceAddressFeaturesKHR_sizeof));


const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT = new C.CStruct("VkPhysicalDeviceBufferDeviceAddressFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceBufferDeviceAddressFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceBufferDeviceAddressFeaturesEXT_pNext_offsetof)+")",
    bufferDeviceAddress: "u32("+callof(V.VkPhysicalDeviceBufferDeviceAddressFeaturesEXT_bufferDeviceAddress_offsetof)+")",
    bufferDeviceAddressCaptureReplay: "u32("+callof(V.VkPhysicalDeviceBufferDeviceAddressFeaturesEXT_bufferDeviceAddressCaptureReplay_offsetof)+")",
    bufferDeviceAddressMultiDevice: "u32("+callof(V.VkPhysicalDeviceBufferDeviceAddressFeaturesEXT_bufferDeviceAddressMultiDevice_offsetof)+")",
}, callof(V.VkPhysicalDeviceBufferDeviceAddressFeaturesEXT_sizeof));


const VkPhysicalDeviceBufferAddressFeaturesEXT = new C.CStruct("VkPhysicalDeviceBufferAddressFeaturesEXT", {

}, callof(V.VkPhysicalDeviceBufferAddressFeaturesEXT_sizeof));


const VkBufferDeviceAddressInfo = new C.CStruct("VkBufferDeviceAddressInfo", {
    sType: "u32("+callof(V.VkBufferDeviceAddressInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferDeviceAddressInfo_pNext_offsetof)+")",
    buffer: "u64("+callof(V.VkBufferDeviceAddressInfo_buffer_offsetof)+")",
}, callof(V.VkBufferDeviceAddressInfo_sizeof));


const VkBufferDeviceAddressInfoKHR = new C.CStruct("VkBufferDeviceAddressInfoKHR", {

}, callof(V.VkBufferDeviceAddressInfoKHR_sizeof));


const VkBufferDeviceAddressInfoEXT = new C.CStruct("VkBufferDeviceAddressInfoEXT", {

}, callof(V.VkBufferDeviceAddressInfoEXT_sizeof));


const VkBufferOpaqueCaptureAddressCreateInfo = new C.CStruct("VkBufferOpaqueCaptureAddressCreateInfo", {
    sType: "u32("+callof(V.VkBufferOpaqueCaptureAddressCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferOpaqueCaptureAddressCreateInfo_pNext_offsetof)+")",
    opaqueCaptureAddress: "u64("+callof(V.VkBufferOpaqueCaptureAddressCreateInfo_opaqueCaptureAddress_offsetof)+")",
}, callof(V.VkBufferOpaqueCaptureAddressCreateInfo_sizeof));


const VkBufferOpaqueCaptureAddressCreateInfoKHR = new C.CStruct("VkBufferOpaqueCaptureAddressCreateInfoKHR", {

}, callof(V.VkBufferOpaqueCaptureAddressCreateInfoKHR_sizeof));


const VkBufferDeviceAddressCreateInfoEXT = new C.CStruct("VkBufferDeviceAddressCreateInfoEXT", {
    sType: "u32("+callof(V.VkBufferDeviceAddressCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferDeviceAddressCreateInfoEXT_pNext_offsetof)+")",
    deviceAddress: "u64("+callof(V.VkBufferDeviceAddressCreateInfoEXT_deviceAddress_offsetof)+")",
}, callof(V.VkBufferDeviceAddressCreateInfoEXT_sizeof));


const VkPhysicalDeviceImageViewImageFormatInfoEXT = new C.CStruct("VkPhysicalDeviceImageViewImageFormatInfoEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceImageViewImageFormatInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceImageViewImageFormatInfoEXT_pNext_offsetof)+")",
    imageViewType: "u32("+callof(V.VkPhysicalDeviceImageViewImageFormatInfoEXT_imageViewType_offsetof)+")",
}, callof(V.VkPhysicalDeviceImageViewImageFormatInfoEXT_sizeof));


const VkFilterCubicImageViewImageFormatPropertiesEXT = new C.CStruct("VkFilterCubicImageViewImageFormatPropertiesEXT", {
    sType: "u32("+callof(V.VkFilterCubicImageViewImageFormatPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkFilterCubicImageViewImageFormatPropertiesEXT_pNext_offsetof)+")",
    filterCubic: "u32("+callof(V.VkFilterCubicImageViewImageFormatPropertiesEXT_filterCubic_offsetof)+")",
    filterCubicMinmax: "u32("+callof(V.VkFilterCubicImageViewImageFormatPropertiesEXT_filterCubicMinmax_offsetof)+")",
}, callof(V.VkFilterCubicImageViewImageFormatPropertiesEXT_sizeof));


const VkPhysicalDeviceImagelessFramebufferFeatures = new C.CStruct("VkPhysicalDeviceImagelessFramebufferFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceImagelessFramebufferFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceImagelessFramebufferFeatures_pNext_offsetof)+")",
    imagelessFramebuffer: "u32("+callof(V.VkPhysicalDeviceImagelessFramebufferFeatures_imagelessFramebuffer_offsetof)+")",
}, callof(V.VkPhysicalDeviceImagelessFramebufferFeatures_sizeof));


const VkPhysicalDeviceImagelessFramebufferFeaturesKHR = new C.CStruct("VkPhysicalDeviceImagelessFramebufferFeaturesKHR", {

}, callof(V.VkPhysicalDeviceImagelessFramebufferFeaturesKHR_sizeof));


const VkFramebufferAttachmentsCreateInfo = new C.CStruct("VkFramebufferAttachmentsCreateInfo", {
    sType: "u32("+callof(V.VkFramebufferAttachmentsCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkFramebufferAttachmentsCreateInfo_pNext_offsetof)+")",
    attachmentImageInfoCount: "u32("+callof(V.VkFramebufferAttachmentsCreateInfo_attachmentImageInfoCount_offsetof)+")",
    pAttachmentImageInfos: "u64("+callof(V.VkFramebufferAttachmentsCreateInfo_pAttachmentImageInfos_offsetof)+")",
}, callof(V.VkFramebufferAttachmentsCreateInfo_sizeof));


const VkFramebufferAttachmentsCreateInfoKHR = new C.CStruct("VkFramebufferAttachmentsCreateInfoKHR", {

}, callof(V.VkFramebufferAttachmentsCreateInfoKHR_sizeof));


const VkFramebufferAttachmentImageInfo = new C.CStruct("VkFramebufferAttachmentImageInfo", {
    sType: "u32("+callof(V.VkFramebufferAttachmentImageInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkFramebufferAttachmentImageInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkFramebufferAttachmentImageInfo_flags_offsetof)+")",
    usage: "u32("+callof(V.VkFramebufferAttachmentImageInfo_usage_offsetof)+")",
    width: "u32("+callof(V.VkFramebufferAttachmentImageInfo_width_offsetof)+")",
    height: "u32("+callof(V.VkFramebufferAttachmentImageInfo_height_offsetof)+")",
    layerCount: "u32("+callof(V.VkFramebufferAttachmentImageInfo_layerCount_offsetof)+")",
    viewFormatCount: "u32("+callof(V.VkFramebufferAttachmentImageInfo_viewFormatCount_offsetof)+")",
    pViewFormats: "u64("+callof(V.VkFramebufferAttachmentImageInfo_pViewFormats_offsetof)+")",
}, callof(V.VkFramebufferAttachmentImageInfo_sizeof));


const VkFramebufferAttachmentImageInfoKHR = new C.CStruct("VkFramebufferAttachmentImageInfoKHR", {

}, callof(V.VkFramebufferAttachmentImageInfoKHR_sizeof));


const VkRenderPassAttachmentBeginInfo = new C.CStruct("VkRenderPassAttachmentBeginInfo", {
    sType: "u32("+callof(V.VkRenderPassAttachmentBeginInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderPassAttachmentBeginInfo_pNext_offsetof)+")",
    attachmentCount: "u32("+callof(V.VkRenderPassAttachmentBeginInfo_attachmentCount_offsetof)+")",
    pAttachments: "u64("+callof(V.VkRenderPassAttachmentBeginInfo_pAttachments_offsetof)+")",
}, callof(V.VkRenderPassAttachmentBeginInfo_sizeof));


const VkRenderPassAttachmentBeginInfoKHR = new C.CStruct("VkRenderPassAttachmentBeginInfoKHR", {

}, callof(V.VkRenderPassAttachmentBeginInfoKHR_sizeof));


const VkPhysicalDeviceTextureCompressionASTCHDRFeatures = new C.CStruct("VkPhysicalDeviceTextureCompressionASTCHDRFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceTextureCompressionASTCHDRFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceTextureCompressionASTCHDRFeatures_pNext_offsetof)+")",
    textureCompressionASTC_HDR: "u32("+callof(V.VkPhysicalDeviceTextureCompressionASTCHDRFeatures_textureCompressionASTC_HDR_offsetof)+")",
}, callof(V.VkPhysicalDeviceTextureCompressionASTCHDRFeatures_sizeof));


const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT = new C.CStruct("VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT", {

}, callof(V.VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT_sizeof));


const VkPhysicalDeviceCooperativeMatrixFeaturesNV = new C.CStruct("VkPhysicalDeviceCooperativeMatrixFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceCooperativeMatrixFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceCooperativeMatrixFeaturesNV_pNext_offsetof)+")",
    cooperativeMatrix: "u32("+callof(V.VkPhysicalDeviceCooperativeMatrixFeaturesNV_cooperativeMatrix_offsetof)+")",
    cooperativeMatrixRobustBufferAccess: "u32("+callof(V.VkPhysicalDeviceCooperativeMatrixFeaturesNV_cooperativeMatrixRobustBufferAccess_offsetof)+")",
}, callof(V.VkPhysicalDeviceCooperativeMatrixFeaturesNV_sizeof));


const VkPhysicalDeviceCooperativeMatrixPropertiesNV = new C.CStruct("VkPhysicalDeviceCooperativeMatrixPropertiesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceCooperativeMatrixPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceCooperativeMatrixPropertiesNV_pNext_offsetof)+")",
    cooperativeMatrixSupportedStages: "u32("+callof(V.VkPhysicalDeviceCooperativeMatrixPropertiesNV_cooperativeMatrixSupportedStages_offsetof)+")",
}, callof(V.VkPhysicalDeviceCooperativeMatrixPropertiesNV_sizeof));


const VkCooperativeMatrixPropertiesNV = new C.CStruct("VkCooperativeMatrixPropertiesNV", {
    sType: "u32("+callof(V.VkCooperativeMatrixPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCooperativeMatrixPropertiesNV_pNext_offsetof)+")",
    MSize: "u32("+callof(V.VkCooperativeMatrixPropertiesNV_MSize_offsetof)+")",
    NSize: "u32("+callof(V.VkCooperativeMatrixPropertiesNV_NSize_offsetof)+")",
    KSize: "u32("+callof(V.VkCooperativeMatrixPropertiesNV_KSize_offsetof)+")",
    AType: "u32("+callof(V.VkCooperativeMatrixPropertiesNV_AType_offsetof)+")",
    BType: "u32("+callof(V.VkCooperativeMatrixPropertiesNV_BType_offsetof)+")",
    CType: "u32("+callof(V.VkCooperativeMatrixPropertiesNV_CType_offsetof)+")",
    DType: "u32("+callof(V.VkCooperativeMatrixPropertiesNV_DType_offsetof)+")",
    scope: "u32("+callof(V.VkCooperativeMatrixPropertiesNV_scope_offsetof)+")",
}, callof(V.VkCooperativeMatrixPropertiesNV_sizeof));


const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT = new C.CStruct("VkPhysicalDeviceYcbcrImageArraysFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceYcbcrImageArraysFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceYcbcrImageArraysFeaturesEXT_pNext_offsetof)+")",
    ycbcrImageArrays: "u32("+callof(V.VkPhysicalDeviceYcbcrImageArraysFeaturesEXT_ycbcrImageArrays_offsetof)+")",
}, callof(V.VkPhysicalDeviceYcbcrImageArraysFeaturesEXT_sizeof));


const VkImageViewHandleInfoNVX = new C.CStruct("VkImageViewHandleInfoNVX", {
    sType: "u32("+callof(V.VkImageViewHandleInfoNVX_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageViewHandleInfoNVX_pNext_offsetof)+")",
    imageView: "u32("+callof(V.VkImageViewHandleInfoNVX_imageView_offsetof)+")",
    descriptorType: "u32("+callof(V.VkImageViewHandleInfoNVX_descriptorType_offsetof)+")",
    sampler: "u64("+callof(V.VkImageViewHandleInfoNVX_sampler_offsetof)+")",
}, callof(V.VkImageViewHandleInfoNVX_sizeof));


const VkImageViewAddressPropertiesNVX = new C.CStruct("VkImageViewAddressPropertiesNVX", {
    sType: "u32("+callof(V.VkImageViewAddressPropertiesNVX_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageViewAddressPropertiesNVX_pNext_offsetof)+")",
    deviceAddress: "u64("+callof(V.VkImageViewAddressPropertiesNVX_deviceAddress_offsetof)+")",
    size: "u64("+callof(V.VkImageViewAddressPropertiesNVX_size_offsetof)+")",
}, callof(V.VkImageViewAddressPropertiesNVX_sizeof));


const VkPresentFrameTokenGGP = new C.CStruct("VkPresentFrameTokenGGP", {
    sType: "u32("+callof(V.VkPresentFrameTokenGGP_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPresentFrameTokenGGP_pNext_offsetof)+")",
    frameToken: "u32("+callof(V.VkPresentFrameTokenGGP_frameToken_offsetof)+")",
}, callof(V.VkPresentFrameTokenGGP_sizeof));


const VkPipelineCreationFeedback = new C.CStruct("VkPipelineCreationFeedback", {
    flags: "u32("+callof(V.VkPipelineCreationFeedback_flags_offsetof)+")",
    duration: "u64("+callof(V.VkPipelineCreationFeedback_duration_offsetof)+")",
}, callof(V.VkPipelineCreationFeedback_sizeof));


const VkPipelineCreationFeedbackEXT = new C.CStruct("VkPipelineCreationFeedbackEXT", {

}, callof(V.VkPipelineCreationFeedbackEXT_sizeof));


const VkPipelineCreationFeedbackCreateInfo = new C.CStruct("VkPipelineCreationFeedbackCreateInfo", {
    sType: "u32("+callof(V.VkPipelineCreationFeedbackCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineCreationFeedbackCreateInfo_pNext_offsetof)+")",
    pPipelineCreationFeedback: "u64("+callof(V.VkPipelineCreationFeedbackCreateInfo_pPipelineCreationFeedback_offsetof)+")",
    pipelineStageCreationFeedbackCount: "u32("+callof(V.VkPipelineCreationFeedbackCreateInfo_pipelineStageCreationFeedbackCount_offsetof)+")",
    pPipelineStageCreationFeedbacks: "u64("+callof(V.VkPipelineCreationFeedbackCreateInfo_pPipelineStageCreationFeedbacks_offsetof)+")",
}, callof(V.VkPipelineCreationFeedbackCreateInfo_sizeof));


const VkPipelineCreationFeedbackCreateInfoEXT = new C.CStruct("VkPipelineCreationFeedbackCreateInfoEXT", {

}, callof(V.VkPipelineCreationFeedbackCreateInfoEXT_sizeof));


const VkSurfaceFullScreenExclusiveInfoEXT = new C.CStruct("VkSurfaceFullScreenExclusiveInfoEXT", {
    sType: "u32("+callof(V.VkSurfaceFullScreenExclusiveInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSurfaceFullScreenExclusiveInfoEXT_pNext_offsetof)+")",
    fullScreenExclusive: "u32("+callof(V.VkSurfaceFullScreenExclusiveInfoEXT_fullScreenExclusive_offsetof)+")",
}, callof(V.VkSurfaceFullScreenExclusiveInfoEXT_sizeof));


const VkSurfaceFullScreenExclusiveWin32InfoEXT = new C.CStruct("VkSurfaceFullScreenExclusiveWin32InfoEXT", {
    sType: "u32("+callof(V.VkSurfaceFullScreenExclusiveWin32InfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSurfaceFullScreenExclusiveWin32InfoEXT_pNext_offsetof)+")",
    hmonitor: "u32("+callof(V.VkSurfaceFullScreenExclusiveWin32InfoEXT_hmonitor_offsetof)+")",
}, callof(V.VkSurfaceFullScreenExclusiveWin32InfoEXT_sizeof));


const VkSurfaceCapabilitiesFullScreenExclusiveEXT = new C.CStruct("VkSurfaceCapabilitiesFullScreenExclusiveEXT", {
    sType: "u32("+callof(V.VkSurfaceCapabilitiesFullScreenExclusiveEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSurfaceCapabilitiesFullScreenExclusiveEXT_pNext_offsetof)+")",
    fullScreenExclusiveSupported: "u32("+callof(V.VkSurfaceCapabilitiesFullScreenExclusiveEXT_fullScreenExclusiveSupported_offsetof)+")",
}, callof(V.VkSurfaceCapabilitiesFullScreenExclusiveEXT_sizeof));


const VkPhysicalDevicePresentBarrierFeaturesNV = new C.CStruct("VkPhysicalDevicePresentBarrierFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDevicePresentBarrierFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePresentBarrierFeaturesNV_pNext_offsetof)+")",
    presentBarrier: "u32("+callof(V.VkPhysicalDevicePresentBarrierFeaturesNV_presentBarrier_offsetof)+")",
}, callof(V.VkPhysicalDevicePresentBarrierFeaturesNV_sizeof));


const VkSurfaceCapabilitiesPresentBarrierNV = new C.CStruct("VkSurfaceCapabilitiesPresentBarrierNV", {
    sType: "u32("+callof(V.VkSurfaceCapabilitiesPresentBarrierNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSurfaceCapabilitiesPresentBarrierNV_pNext_offsetof)+")",
    presentBarrierSupported: "u32("+callof(V.VkSurfaceCapabilitiesPresentBarrierNV_presentBarrierSupported_offsetof)+")",
}, callof(V.VkSurfaceCapabilitiesPresentBarrierNV_sizeof));


const VkSwapchainPresentBarrierCreateInfoNV = new C.CStruct("VkSwapchainPresentBarrierCreateInfoNV", {
    sType: "u32("+callof(V.VkSwapchainPresentBarrierCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSwapchainPresentBarrierCreateInfoNV_pNext_offsetof)+")",
    presentBarrierEnable: "u32("+callof(V.VkSwapchainPresentBarrierCreateInfoNV_presentBarrierEnable_offsetof)+")",
}, callof(V.VkSwapchainPresentBarrierCreateInfoNV_sizeof));


const VkPhysicalDevicePerformanceQueryFeaturesKHR = new C.CStruct("VkPhysicalDevicePerformanceQueryFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDevicePerformanceQueryFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePerformanceQueryFeaturesKHR_pNext_offsetof)+")",
    performanceCounterQueryPools: "u32("+callof(V.VkPhysicalDevicePerformanceQueryFeaturesKHR_performanceCounterQueryPools_offsetof)+")",
    performanceCounterMultipleQueryPools: "u32("+callof(V.VkPhysicalDevicePerformanceQueryFeaturesKHR_performanceCounterMultipleQueryPools_offsetof)+")",
}, callof(V.VkPhysicalDevicePerformanceQueryFeaturesKHR_sizeof));


const VkPhysicalDevicePerformanceQueryPropertiesKHR = new C.CStruct("VkPhysicalDevicePerformanceQueryPropertiesKHR", {
    sType: "u32("+callof(V.VkPhysicalDevicePerformanceQueryPropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePerformanceQueryPropertiesKHR_pNext_offsetof)+")",
    allowCommandBufferQueryCopies: "u32("+callof(V.VkPhysicalDevicePerformanceQueryPropertiesKHR_allowCommandBufferQueryCopies_offsetof)+")",
}, callof(V.VkPhysicalDevicePerformanceQueryPropertiesKHR_sizeof));


const VkPerformanceCounterKHR = new C.CStruct("VkPerformanceCounterKHR", {
    sType: "u32("+callof(V.VkPerformanceCounterKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPerformanceCounterKHR_pNext_offsetof)+")",
    unit: "u32("+callof(V.VkPerformanceCounterKHR_unit_offsetof)+")",
    scope: "u32("+callof(V.VkPerformanceCounterKHR_scope_offsetof)+")",
    storage: "u32("+callof(V.VkPerformanceCounterKHR_storage_offsetof)+")",
    uuid: "u8["+(enums.NaN||1)+"]("+callof(V.VkPerformanceCounterKHR_uuid_offsetof)+")",
}, callof(V.VkPerformanceCounterKHR_sizeof));


const VkPerformanceCounterDescriptionKHR = new C.CStruct("VkPerformanceCounterDescriptionKHR", {
    sType: "u32("+callof(V.VkPerformanceCounterDescriptionKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPerformanceCounterDescriptionKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPerformanceCounterDescriptionKHR_flags_offsetof)+")",
    name: "u8["+(enums.NaN||1)+"]("+callof(V.VkPerformanceCounterDescriptionKHR_name_offsetof)+")",
    category: "u8["+(enums.NaN||1)+"]("+callof(V.VkPerformanceCounterDescriptionKHR_category_offsetof)+")",
    description: "u8["+(enums.NaN||1)+"]("+callof(V.VkPerformanceCounterDescriptionKHR_description_offsetof)+")",
}, callof(V.VkPerformanceCounterDescriptionKHR_sizeof));


const VkQueryPoolPerformanceCreateInfoKHR = new C.CStruct("VkQueryPoolPerformanceCreateInfoKHR", {
    sType: "u32("+callof(V.VkQueryPoolPerformanceCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkQueryPoolPerformanceCreateInfoKHR_pNext_offsetof)+")",
    queueFamilyIndex: "u32("+callof(V.VkQueryPoolPerformanceCreateInfoKHR_queueFamilyIndex_offsetof)+")",
    counterIndexCount: "u32("+callof(V.VkQueryPoolPerformanceCreateInfoKHR_counterIndexCount_offsetof)+")",
    pCounterIndices: "u64("+callof(V.VkQueryPoolPerformanceCreateInfoKHR_pCounterIndices_offsetof)+")",
}, callof(V.VkQueryPoolPerformanceCreateInfoKHR_sizeof));


const VkAcquireProfilingLockInfoKHR = new C.CStruct("VkAcquireProfilingLockInfoKHR", {
    sType: "u32("+callof(V.VkAcquireProfilingLockInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAcquireProfilingLockInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkAcquireProfilingLockInfoKHR_flags_offsetof)+")",
    timeout: "u64("+callof(V.VkAcquireProfilingLockInfoKHR_timeout_offsetof)+")",
}, callof(V.VkAcquireProfilingLockInfoKHR_sizeof));


const VkPerformanceQuerySubmitInfoKHR = new C.CStruct("VkPerformanceQuerySubmitInfoKHR", {
    sType: "u32("+callof(V.VkPerformanceQuerySubmitInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPerformanceQuerySubmitInfoKHR_pNext_offsetof)+")",
    counterPassIndex: "u32("+callof(V.VkPerformanceQuerySubmitInfoKHR_counterPassIndex_offsetof)+")",
}, callof(V.VkPerformanceQuerySubmitInfoKHR_sizeof));


const VkHeadlessSurfaceCreateInfoEXT = new C.CStruct("VkHeadlessSurfaceCreateInfoEXT", {
    sType: "u32("+callof(V.VkHeadlessSurfaceCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkHeadlessSurfaceCreateInfoEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkHeadlessSurfaceCreateInfoEXT_flags_offsetof)+")",
}, callof(V.VkHeadlessSurfaceCreateInfoEXT_sizeof));


const VkPhysicalDeviceCoverageReductionModeFeaturesNV = new C.CStruct("VkPhysicalDeviceCoverageReductionModeFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceCoverageReductionModeFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceCoverageReductionModeFeaturesNV_pNext_offsetof)+")",
    coverageReductionMode: "u32("+callof(V.VkPhysicalDeviceCoverageReductionModeFeaturesNV_coverageReductionMode_offsetof)+")",
}, callof(V.VkPhysicalDeviceCoverageReductionModeFeaturesNV_sizeof));


const VkPipelineCoverageReductionStateCreateInfoNV = new C.CStruct("VkPipelineCoverageReductionStateCreateInfoNV", {
    sType: "u32("+callof(V.VkPipelineCoverageReductionStateCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineCoverageReductionStateCreateInfoNV_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkPipelineCoverageReductionStateCreateInfoNV_flags_offsetof)+")",
    coverageReductionMode: "u32("+callof(V.VkPipelineCoverageReductionStateCreateInfoNV_coverageReductionMode_offsetof)+")",
}, callof(V.VkPipelineCoverageReductionStateCreateInfoNV_sizeof));


const VkFramebufferMixedSamplesCombinationNV = new C.CStruct("VkFramebufferMixedSamplesCombinationNV", {
    sType: "u32("+callof(V.VkFramebufferMixedSamplesCombinationNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkFramebufferMixedSamplesCombinationNV_pNext_offsetof)+")",
    coverageReductionMode: "u32("+callof(V.VkFramebufferMixedSamplesCombinationNV_coverageReductionMode_offsetof)+")",
    rasterizationSamples: "u32("+callof(V.VkFramebufferMixedSamplesCombinationNV_rasterizationSamples_offsetof)+")",
    depthStencilSamples: "u32("+callof(V.VkFramebufferMixedSamplesCombinationNV_depthStencilSamples_offsetof)+")",
    colorSamples: "u32("+callof(V.VkFramebufferMixedSamplesCombinationNV_colorSamples_offsetof)+")",
}, callof(V.VkFramebufferMixedSamplesCombinationNV_sizeof));


const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL = new C.CStruct("VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL_pNext_offsetof)+")",
    shaderIntegerFunctions2: "u32("+callof(V.VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL_shaderIntegerFunctions2_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL_sizeof));


const VkPerformanceValueINTEL = new C.CStruct("VkPerformanceValueINTEL", {
    type: "u32("+callof(V.VkPerformanceValueINTEL_type_offsetof)+")",
    data: "u32("+callof(V.VkPerformanceValueINTEL_data_offsetof)+")",
}, callof(V.VkPerformanceValueINTEL_sizeof));


const VkInitializePerformanceApiInfoINTEL = new C.CStruct("VkInitializePerformanceApiInfoINTEL", {
    sType: "u32("+callof(V.VkInitializePerformanceApiInfoINTEL_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkInitializePerformanceApiInfoINTEL_pNext_offsetof)+")",
    pUserData: "u64("+callof(V.VkInitializePerformanceApiInfoINTEL_pUserData_offsetof)+")",
}, callof(V.VkInitializePerformanceApiInfoINTEL_sizeof));


const VkQueryPoolPerformanceQueryCreateInfoINTEL = new C.CStruct("VkQueryPoolPerformanceQueryCreateInfoINTEL", {
    sType: "u32("+callof(V.VkQueryPoolPerformanceQueryCreateInfoINTEL_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkQueryPoolPerformanceQueryCreateInfoINTEL_pNext_offsetof)+")",
    performanceCountersSampling: "u32("+callof(V.VkQueryPoolPerformanceQueryCreateInfoINTEL_performanceCountersSampling_offsetof)+")",
}, callof(V.VkQueryPoolPerformanceQueryCreateInfoINTEL_sizeof));


const VkQueryPoolCreateInfoINTEL = new C.CStruct("VkQueryPoolCreateInfoINTEL", {

}, callof(V.VkQueryPoolCreateInfoINTEL_sizeof));


const VkPerformanceMarkerInfoINTEL = new C.CStruct("VkPerformanceMarkerInfoINTEL", {
    sType: "u32("+callof(V.VkPerformanceMarkerInfoINTEL_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPerformanceMarkerInfoINTEL_pNext_offsetof)+")",
    marker: "u64("+callof(V.VkPerformanceMarkerInfoINTEL_marker_offsetof)+")",
}, callof(V.VkPerformanceMarkerInfoINTEL_sizeof));


const VkPerformanceStreamMarkerInfoINTEL = new C.CStruct("VkPerformanceStreamMarkerInfoINTEL", {
    sType: "u32("+callof(V.VkPerformanceStreamMarkerInfoINTEL_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPerformanceStreamMarkerInfoINTEL_pNext_offsetof)+")",
    marker: "u32("+callof(V.VkPerformanceStreamMarkerInfoINTEL_marker_offsetof)+")",
}, callof(V.VkPerformanceStreamMarkerInfoINTEL_sizeof));


const VkPerformanceOverrideInfoINTEL = new C.CStruct("VkPerformanceOverrideInfoINTEL", {
    sType: "u32("+callof(V.VkPerformanceOverrideInfoINTEL_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPerformanceOverrideInfoINTEL_pNext_offsetof)+")",
    type: "u32("+callof(V.VkPerformanceOverrideInfoINTEL_type_offsetof)+")",
    enable: "u32("+callof(V.VkPerformanceOverrideInfoINTEL_enable_offsetof)+")",
    parameter: "u64("+callof(V.VkPerformanceOverrideInfoINTEL_parameter_offsetof)+")",
}, callof(V.VkPerformanceOverrideInfoINTEL_sizeof));


const VkPerformanceConfigurationAcquireInfoINTEL = new C.CStruct("VkPerformanceConfigurationAcquireInfoINTEL", {
    sType: "u32("+callof(V.VkPerformanceConfigurationAcquireInfoINTEL_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPerformanceConfigurationAcquireInfoINTEL_pNext_offsetof)+")",
    type: "u32("+callof(V.VkPerformanceConfigurationAcquireInfoINTEL_type_offsetof)+")",
}, callof(V.VkPerformanceConfigurationAcquireInfoINTEL_sizeof));


const VkPhysicalDeviceShaderClockFeaturesKHR = new C.CStruct("VkPhysicalDeviceShaderClockFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderClockFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderClockFeaturesKHR_pNext_offsetof)+")",
    shaderSubgroupClock: "u32("+callof(V.VkPhysicalDeviceShaderClockFeaturesKHR_shaderSubgroupClock_offsetof)+")",
    shaderDeviceClock: "u32("+callof(V.VkPhysicalDeviceShaderClockFeaturesKHR_shaderDeviceClock_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderClockFeaturesKHR_sizeof));


const VkPhysicalDeviceIndexTypeUint8FeaturesEXT = new C.CStruct("VkPhysicalDeviceIndexTypeUint8FeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceIndexTypeUint8FeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceIndexTypeUint8FeaturesEXT_pNext_offsetof)+")",
    indexTypeUint8: "u32("+callof(V.VkPhysicalDeviceIndexTypeUint8FeaturesEXT_indexTypeUint8_offsetof)+")",
}, callof(V.VkPhysicalDeviceIndexTypeUint8FeaturesEXT_sizeof));


const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV = new C.CStruct("VkPhysicalDeviceShaderSMBuiltinsPropertiesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderSMBuiltinsPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderSMBuiltinsPropertiesNV_pNext_offsetof)+")",
    shaderSMCount: "u32("+callof(V.VkPhysicalDeviceShaderSMBuiltinsPropertiesNV_shaderSMCount_offsetof)+")",
    shaderWarpsPerSM: "u32("+callof(V.VkPhysicalDeviceShaderSMBuiltinsPropertiesNV_shaderWarpsPerSM_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderSMBuiltinsPropertiesNV_sizeof));


const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV = new C.CStruct("VkPhysicalDeviceShaderSMBuiltinsFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderSMBuiltinsFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderSMBuiltinsFeaturesNV_pNext_offsetof)+")",
    shaderSMBuiltins: "u32("+callof(V.VkPhysicalDeviceShaderSMBuiltinsFeaturesNV_shaderSMBuiltins_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderSMBuiltinsFeaturesNV_sizeof));


const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT = new C.CStruct("VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT_pNext_offsetof)+")",
    fragmentShaderSampleInterlock: "u32("+callof(V.VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT_fragmentShaderSampleInterlock_offsetof)+")",
    fragmentShaderPixelInterlock: "u32("+callof(V.VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT_fragmentShaderPixelInterlock_offsetof)+")",
    fragmentShaderShadingRateInterlock: "u32("+callof(V.VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT_fragmentShaderShadingRateInterlock_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT_sizeof));


const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures = new C.CStruct("VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pNext_offsetof)+")",
    separateDepthStencilLayouts: "u32("+callof(V.VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_separateDepthStencilLayouts_offsetof)+")",
}, callof(V.VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_sizeof));


const VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR = new C.CStruct("VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR", {

}, callof(V.VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR_sizeof));


const VkAttachmentReferenceStencilLayout = new C.CStruct("VkAttachmentReferenceStencilLayout", {
    sType: "u32("+callof(V.VkAttachmentReferenceStencilLayout_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAttachmentReferenceStencilLayout_pNext_offsetof)+")",
    stencilLayout: "u32("+callof(V.VkAttachmentReferenceStencilLayout_stencilLayout_offsetof)+")",
}, callof(V.VkAttachmentReferenceStencilLayout_sizeof));


const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT = new C.CStruct("VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT_pNext_offsetof)+")",
    primitiveTopologyListRestart: "u32("+callof(V.VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT_primitiveTopologyListRestart_offsetof)+")",
    primitiveTopologyPatchListRestart: "u32("+callof(V.VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT_primitiveTopologyPatchListRestart_offsetof)+")",
}, callof(V.VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT_sizeof));


const VkAttachmentReferenceStencilLayoutKHR = new C.CStruct("VkAttachmentReferenceStencilLayoutKHR", {

}, callof(V.VkAttachmentReferenceStencilLayoutKHR_sizeof));


const VkAttachmentDescriptionStencilLayout = new C.CStruct("VkAttachmentDescriptionStencilLayout", {
    sType: "u32("+callof(V.VkAttachmentDescriptionStencilLayout_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAttachmentDescriptionStencilLayout_pNext_offsetof)+")",
    stencilInitialLayout: "u32("+callof(V.VkAttachmentDescriptionStencilLayout_stencilInitialLayout_offsetof)+")",
    stencilFinalLayout: "u32("+callof(V.VkAttachmentDescriptionStencilLayout_stencilFinalLayout_offsetof)+")",
}, callof(V.VkAttachmentDescriptionStencilLayout_sizeof));


const VkAttachmentDescriptionStencilLayoutKHR = new C.CStruct("VkAttachmentDescriptionStencilLayoutKHR", {

}, callof(V.VkAttachmentDescriptionStencilLayoutKHR_sizeof));


const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR = new C.CStruct("VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR_pNext_offsetof)+")",
    pipelineExecutableInfo: "u32("+callof(V.VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR_pipelineExecutableInfo_offsetof)+")",
}, callof(V.VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR_sizeof));


const VkPipelineInfoKHR = new C.CStruct("VkPipelineInfoKHR", {
    sType: "u32("+callof(V.VkPipelineInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineInfoKHR_pNext_offsetof)+")",
    pipeline: "u64("+callof(V.VkPipelineInfoKHR_pipeline_offsetof)+")",
}, callof(V.VkPipelineInfoKHR_sizeof));


const VkPipelineInfoEXT = new C.CStruct("VkPipelineInfoEXT", {

}, callof(V.VkPipelineInfoEXT_sizeof));


const VkPipelineExecutablePropertiesKHR = new C.CStruct("VkPipelineExecutablePropertiesKHR", {
    sType: "u32("+callof(V.VkPipelineExecutablePropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineExecutablePropertiesKHR_pNext_offsetof)+")",
    stages: "u32("+callof(V.VkPipelineExecutablePropertiesKHR_stages_offsetof)+")",
    name: "u8["+(enums.NaN||1)+"]("+callof(V.VkPipelineExecutablePropertiesKHR_name_offsetof)+")",
    description: "u8["+(enums.NaN||1)+"]("+callof(V.VkPipelineExecutablePropertiesKHR_description_offsetof)+")",
    subgroupSize: "u32("+callof(V.VkPipelineExecutablePropertiesKHR_subgroupSize_offsetof)+")",
}, callof(V.VkPipelineExecutablePropertiesKHR_sizeof));


const VkPipelineExecutableInfoKHR = new C.CStruct("VkPipelineExecutableInfoKHR", {
    sType: "u32("+callof(V.VkPipelineExecutableInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineExecutableInfoKHR_pNext_offsetof)+")",
    pipeline: "u64("+callof(V.VkPipelineExecutableInfoKHR_pipeline_offsetof)+")",
    executableIndex: "u32("+callof(V.VkPipelineExecutableInfoKHR_executableIndex_offsetof)+")",
}, callof(V.VkPipelineExecutableInfoKHR_sizeof));


const VkPipelineExecutableStatisticKHR = new C.CStruct("VkPipelineExecutableStatisticKHR", {
    sType: "u32("+callof(V.VkPipelineExecutableStatisticKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineExecutableStatisticKHR_pNext_offsetof)+")",
    name: "u8["+(enums.NaN||1)+"]("+callof(V.VkPipelineExecutableStatisticKHR_name_offsetof)+")",
    description: "u8["+(enums.NaN||1)+"]("+callof(V.VkPipelineExecutableStatisticKHR_description_offsetof)+")",
    format: "u32("+callof(V.VkPipelineExecutableStatisticKHR_format_offsetof)+")",
    value: "u32("+callof(V.VkPipelineExecutableStatisticKHR_value_offsetof)+")",
}, callof(V.VkPipelineExecutableStatisticKHR_sizeof));


const VkPipelineExecutableInternalRepresentationKHR = new C.CStruct("VkPipelineExecutableInternalRepresentationKHR", {
    sType: "u32("+callof(V.VkPipelineExecutableInternalRepresentationKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineExecutableInternalRepresentationKHR_pNext_offsetof)+")",
    name: "u8["+(enums.NaN||1)+"]("+callof(V.VkPipelineExecutableInternalRepresentationKHR_name_offsetof)+")",
    description: "u8["+(enums.NaN||1)+"]("+callof(V.VkPipelineExecutableInternalRepresentationKHR_description_offsetof)+")",
    isText: "u32("+callof(V.VkPipelineExecutableInternalRepresentationKHR_isText_offsetof)+")",
    dataSize: "u64("+callof(V.VkPipelineExecutableInternalRepresentationKHR_dataSize_offsetof)+")",
    pData: "u64("+callof(V.VkPipelineExecutableInternalRepresentationKHR_pData_offsetof)+")",
}, callof(V.VkPipelineExecutableInternalRepresentationKHR_sizeof));


const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures = new C.CStruct("VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures_pNext_offsetof)+")",
    shaderDemoteToHelperInvocation: "u32("+callof(V.VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures_shaderDemoteToHelperInvocation_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures_sizeof));


const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT = new C.CStruct("VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT", {

}, callof(V.VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT_sizeof));


const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT = new C.CStruct("VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT_pNext_offsetof)+")",
    texelBufferAlignment: "u32("+callof(V.VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT_texelBufferAlignment_offsetof)+")",
}, callof(V.VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT_sizeof));


const VkPhysicalDeviceTexelBufferAlignmentProperties = new C.CStruct("VkPhysicalDeviceTexelBufferAlignmentProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceTexelBufferAlignmentProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceTexelBufferAlignmentProperties_pNext_offsetof)+")",
    storageTexelBufferOffsetAlignmentBytes: "u64("+callof(V.VkPhysicalDeviceTexelBufferAlignmentProperties_storageTexelBufferOffsetAlignmentBytes_offsetof)+")",
    storageTexelBufferOffsetSingleTexelAlignment: "u32("+callof(V.VkPhysicalDeviceTexelBufferAlignmentProperties_storageTexelBufferOffsetSingleTexelAlignment_offsetof)+")",
    uniformTexelBufferOffsetAlignmentBytes: "u64("+callof(V.VkPhysicalDeviceTexelBufferAlignmentProperties_uniformTexelBufferOffsetAlignmentBytes_offsetof)+")",
    uniformTexelBufferOffsetSingleTexelAlignment: "u32("+callof(V.VkPhysicalDeviceTexelBufferAlignmentProperties_uniformTexelBufferOffsetSingleTexelAlignment_offsetof)+")",
}, callof(V.VkPhysicalDeviceTexelBufferAlignmentProperties_sizeof));


const VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT = new C.CStruct("VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT", {

}, callof(V.VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT_sizeof));


const VkPhysicalDeviceSubgroupSizeControlFeatures = new C.CStruct("VkPhysicalDeviceSubgroupSizeControlFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceSubgroupSizeControlFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSubgroupSizeControlFeatures_pNext_offsetof)+")",
    subgroupSizeControl: "u32("+callof(V.VkPhysicalDeviceSubgroupSizeControlFeatures_subgroupSizeControl_offsetof)+")",
    computeFullSubgroups: "u32("+callof(V.VkPhysicalDeviceSubgroupSizeControlFeatures_computeFullSubgroups_offsetof)+")",
}, callof(V.VkPhysicalDeviceSubgroupSizeControlFeatures_sizeof));


const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT = new C.CStruct("VkPhysicalDeviceSubgroupSizeControlFeaturesEXT", {

}, callof(V.VkPhysicalDeviceSubgroupSizeControlFeaturesEXT_sizeof));


const VkPhysicalDeviceSubgroupSizeControlProperties = new C.CStruct("VkPhysicalDeviceSubgroupSizeControlProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceSubgroupSizeControlProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSubgroupSizeControlProperties_pNext_offsetof)+")",
    minSubgroupSize: "u32("+callof(V.VkPhysicalDeviceSubgroupSizeControlProperties_minSubgroupSize_offsetof)+")",
    maxSubgroupSize: "u32("+callof(V.VkPhysicalDeviceSubgroupSizeControlProperties_maxSubgroupSize_offsetof)+")",
    maxComputeWorkgroupSubgroups: "u32("+callof(V.VkPhysicalDeviceSubgroupSizeControlProperties_maxComputeWorkgroupSubgroups_offsetof)+")",
    requiredSubgroupSizeStages: "u32("+callof(V.VkPhysicalDeviceSubgroupSizeControlProperties_requiredSubgroupSizeStages_offsetof)+")",
}, callof(V.VkPhysicalDeviceSubgroupSizeControlProperties_sizeof));


const VkPhysicalDeviceSubgroupSizeControlPropertiesEXT = new C.CStruct("VkPhysicalDeviceSubgroupSizeControlPropertiesEXT", {

}, callof(V.VkPhysicalDeviceSubgroupSizeControlPropertiesEXT_sizeof));


const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo = new C.CStruct("VkPipelineShaderStageRequiredSubgroupSizeCreateInfo", {
    sType: "u32("+callof(V.VkPipelineShaderStageRequiredSubgroupSizeCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineShaderStageRequiredSubgroupSizeCreateInfo_pNext_offsetof)+")",
    requiredSubgroupSize: "u32("+callof(V.VkPipelineShaderStageRequiredSubgroupSizeCreateInfo_requiredSubgroupSize_offsetof)+")",
}, callof(V.VkPipelineShaderStageRequiredSubgroupSizeCreateInfo_sizeof));


const VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT = new C.CStruct("VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT", {

}, callof(V.VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT_sizeof));


const VkSubpassShadingPipelineCreateInfoHUAWEI = new C.CStruct("VkSubpassShadingPipelineCreateInfoHUAWEI", {
    sType: "u32("+callof(V.VkSubpassShadingPipelineCreateInfoHUAWEI_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSubpassShadingPipelineCreateInfoHUAWEI_pNext_offsetof)+")",
    renderPass: "u32("+callof(V.VkSubpassShadingPipelineCreateInfoHUAWEI_renderPass_offsetof)+")",
    subpass: "u32("+callof(V.VkSubpassShadingPipelineCreateInfoHUAWEI_subpass_offsetof)+")",
}, callof(V.VkSubpassShadingPipelineCreateInfoHUAWEI_sizeof));


const VkPhysicalDeviceSubpassShadingPropertiesHUAWEI = new C.CStruct("VkPhysicalDeviceSubpassShadingPropertiesHUAWEI", {
    sType: "u32("+callof(V.VkPhysicalDeviceSubpassShadingPropertiesHUAWEI_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSubpassShadingPropertiesHUAWEI_pNext_offsetof)+")",
    maxSubpassShadingWorkgroupSizeAspectRatio: "u32("+callof(V.VkPhysicalDeviceSubpassShadingPropertiesHUAWEI_maxSubpassShadingWorkgroupSizeAspectRatio_offsetof)+")",
}, callof(V.VkPhysicalDeviceSubpassShadingPropertiesHUAWEI_sizeof));


const VkMemoryOpaqueCaptureAddressAllocateInfo = new C.CStruct("VkMemoryOpaqueCaptureAddressAllocateInfo", {
    sType: "u32("+callof(V.VkMemoryOpaqueCaptureAddressAllocateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryOpaqueCaptureAddressAllocateInfo_pNext_offsetof)+")",
    opaqueCaptureAddress: "u64("+callof(V.VkMemoryOpaqueCaptureAddressAllocateInfo_opaqueCaptureAddress_offsetof)+")",
}, callof(V.VkMemoryOpaqueCaptureAddressAllocateInfo_sizeof));


const VkMemoryOpaqueCaptureAddressAllocateInfoKHR = new C.CStruct("VkMemoryOpaqueCaptureAddressAllocateInfoKHR", {

}, callof(V.VkMemoryOpaqueCaptureAddressAllocateInfoKHR_sizeof));


const VkDeviceMemoryOpaqueCaptureAddressInfo = new C.CStruct("VkDeviceMemoryOpaqueCaptureAddressInfo", {
    sType: "u32("+callof(V.VkDeviceMemoryOpaqueCaptureAddressInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceMemoryOpaqueCaptureAddressInfo_pNext_offsetof)+")",
    memory: "u64("+callof(V.VkDeviceMemoryOpaqueCaptureAddressInfo_memory_offsetof)+")",
}, callof(V.VkDeviceMemoryOpaqueCaptureAddressInfo_sizeof));


const VkDeviceMemoryOpaqueCaptureAddressInfoKHR = new C.CStruct("VkDeviceMemoryOpaqueCaptureAddressInfoKHR", {

}, callof(V.VkDeviceMemoryOpaqueCaptureAddressInfoKHR_sizeof));


const VkPhysicalDeviceLineRasterizationFeaturesEXT = new C.CStruct("VkPhysicalDeviceLineRasterizationFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_pNext_offsetof)+")",
    rectangularLines: "u32("+callof(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_rectangularLines_offsetof)+")",
    bresenhamLines: "u32("+callof(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_bresenhamLines_offsetof)+")",
    smoothLines: "u32("+callof(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_smoothLines_offsetof)+")",
    stippledRectangularLines: "u32("+callof(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_stippledRectangularLines_offsetof)+")",
    stippledBresenhamLines: "u32("+callof(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_stippledBresenhamLines_offsetof)+")",
    stippledSmoothLines: "u32("+callof(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_stippledSmoothLines_offsetof)+")",
}, callof(V.VkPhysicalDeviceLineRasterizationFeaturesEXT_sizeof));


const VkPhysicalDeviceLineRasterizationPropertiesEXT = new C.CStruct("VkPhysicalDeviceLineRasterizationPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceLineRasterizationPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceLineRasterizationPropertiesEXT_pNext_offsetof)+")",
    lineSubPixelPrecisionBits: "u32("+callof(V.VkPhysicalDeviceLineRasterizationPropertiesEXT_lineSubPixelPrecisionBits_offsetof)+")",
}, callof(V.VkPhysicalDeviceLineRasterizationPropertiesEXT_sizeof));


const VkPipelineRasterizationLineStateCreateInfoEXT = new C.CStruct("VkPipelineRasterizationLineStateCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineRasterizationLineStateCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineRasterizationLineStateCreateInfoEXT_pNext_offsetof)+")",
    lineRasterizationMode: "u32("+callof(V.VkPipelineRasterizationLineStateCreateInfoEXT_lineRasterizationMode_offsetof)+")",
    stippledLineEnable: "u32("+callof(V.VkPipelineRasterizationLineStateCreateInfoEXT_stippledLineEnable_offsetof)+")",
    lineStippleFactor: "u32("+callof(V.VkPipelineRasterizationLineStateCreateInfoEXT_lineStippleFactor_offsetof)+")",
    lineStipplePattern: "u16("+callof(V.VkPipelineRasterizationLineStateCreateInfoEXT_lineStipplePattern_offsetof)+")",
}, callof(V.VkPipelineRasterizationLineStateCreateInfoEXT_sizeof));


const VkPhysicalDevicePipelineCreationCacheControlFeatures = new C.CStruct("VkPhysicalDevicePipelineCreationCacheControlFeatures", {
    sType: "u32("+callof(V.VkPhysicalDevicePipelineCreationCacheControlFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePipelineCreationCacheControlFeatures_pNext_offsetof)+")",
    pipelineCreationCacheControl: "u32("+callof(V.VkPhysicalDevicePipelineCreationCacheControlFeatures_pipelineCreationCacheControl_offsetof)+")",
}, callof(V.VkPhysicalDevicePipelineCreationCacheControlFeatures_sizeof));


const VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT = new C.CStruct("VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT", {

}, callof(V.VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT_sizeof));


const VkPhysicalDeviceVulkan11Features = new C.CStruct("VkPhysicalDeviceVulkan11Features", {
    sType: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceVulkan11Features_pNext_offsetof)+")",
    storageBuffer16BitAccess: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_storageBuffer16BitAccess_offsetof)+")",
    uniformAndStorageBuffer16BitAccess: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_uniformAndStorageBuffer16BitAccess_offsetof)+")",
    storagePushConstant16: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_storagePushConstant16_offsetof)+")",
    storageInputOutput16: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_storageInputOutput16_offsetof)+")",
    multiview: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_multiview_offsetof)+")",
    multiviewGeometryShader: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_multiviewGeometryShader_offsetof)+")",
    multiviewTessellationShader: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_multiviewTessellationShader_offsetof)+")",
    variablePointersStorageBuffer: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_variablePointersStorageBuffer_offsetof)+")",
    variablePointers: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_variablePointers_offsetof)+")",
    protectedMemory: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_protectedMemory_offsetof)+")",
    samplerYcbcrConversion: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_samplerYcbcrConversion_offsetof)+")",
    shaderDrawParameters: "u32("+callof(V.VkPhysicalDeviceVulkan11Features_shaderDrawParameters_offsetof)+")",
}, callof(V.VkPhysicalDeviceVulkan11Features_sizeof));


const VkPhysicalDeviceVulkan11Properties = new C.CStruct("VkPhysicalDeviceVulkan11Properties", {
    sType: "u32("+callof(V.VkPhysicalDeviceVulkan11Properties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceVulkan11Properties_pNext_offsetof)+")",
    deviceUUID: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceVulkan11Properties_deviceUUID_offsetof)+")",
    driverUUID: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceVulkan11Properties_driverUUID_offsetof)+")",
    deviceLUID: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceVulkan11Properties_deviceLUID_offsetof)+")",
    deviceNodeMask: "u32("+callof(V.VkPhysicalDeviceVulkan11Properties_deviceNodeMask_offsetof)+")",
    deviceLUIDValid: "u32("+callof(V.VkPhysicalDeviceVulkan11Properties_deviceLUIDValid_offsetof)+")",
    subgroupSize: "u32("+callof(V.VkPhysicalDeviceVulkan11Properties_subgroupSize_offsetof)+")",
    subgroupSupportedStages: "u32("+callof(V.VkPhysicalDeviceVulkan11Properties_subgroupSupportedStages_offsetof)+")",
    subgroupSupportedOperations: "u32("+callof(V.VkPhysicalDeviceVulkan11Properties_subgroupSupportedOperations_offsetof)+")",
    subgroupQuadOperationsInAllStages: "u32("+callof(V.VkPhysicalDeviceVulkan11Properties_subgroupQuadOperationsInAllStages_offsetof)+")",
    pointClippingBehavior: "u32("+callof(V.VkPhysicalDeviceVulkan11Properties_pointClippingBehavior_offsetof)+")",
    maxMultiviewViewCount: "u32("+callof(V.VkPhysicalDeviceVulkan11Properties_maxMultiviewViewCount_offsetof)+")",
    maxMultiviewInstanceIndex: "u32("+callof(V.VkPhysicalDeviceVulkan11Properties_maxMultiviewInstanceIndex_offsetof)+")",
    protectedNoFault: "u32("+callof(V.VkPhysicalDeviceVulkan11Properties_protectedNoFault_offsetof)+")",
    maxPerSetDescriptors: "u32("+callof(V.VkPhysicalDeviceVulkan11Properties_maxPerSetDescriptors_offsetof)+")",
    maxMemoryAllocationSize: "u64("+callof(V.VkPhysicalDeviceVulkan11Properties_maxMemoryAllocationSize_offsetof)+")",
}, callof(V.VkPhysicalDeviceVulkan11Properties_sizeof));


const VkPhysicalDeviceVulkan12Features = new C.CStruct("VkPhysicalDeviceVulkan12Features", {
    sType: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceVulkan12Features_pNext_offsetof)+")",
    samplerMirrorClampToEdge: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_samplerMirrorClampToEdge_offsetof)+")",
    drawIndirectCount: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_drawIndirectCount_offsetof)+")",
    storageBuffer8BitAccess: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_storageBuffer8BitAccess_offsetof)+")",
    uniformAndStorageBuffer8BitAccess: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_uniformAndStorageBuffer8BitAccess_offsetof)+")",
    storagePushConstant8: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_storagePushConstant8_offsetof)+")",
    shaderBufferInt64Atomics: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderBufferInt64Atomics_offsetof)+")",
    shaderSharedInt64Atomics: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderSharedInt64Atomics_offsetof)+")",
    shaderFloat16: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderFloat16_offsetof)+")",
    shaderInt8: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderInt8_offsetof)+")",
    descriptorIndexing: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_descriptorIndexing_offsetof)+")",
    shaderInputAttachmentArrayDynamicIndexing: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderInputAttachmentArrayDynamicIndexing_offsetof)+")",
    shaderUniformTexelBufferArrayDynamicIndexing: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderUniformTexelBufferArrayDynamicIndexing_offsetof)+")",
    shaderStorageTexelBufferArrayDynamicIndexing: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderStorageTexelBufferArrayDynamicIndexing_offsetof)+")",
    shaderUniformBufferArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderUniformBufferArrayNonUniformIndexing_offsetof)+")",
    shaderSampledImageArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderSampledImageArrayNonUniformIndexing_offsetof)+")",
    shaderStorageBufferArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderStorageBufferArrayNonUniformIndexing_offsetof)+")",
    shaderStorageImageArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderStorageImageArrayNonUniformIndexing_offsetof)+")",
    shaderInputAttachmentArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderInputAttachmentArrayNonUniformIndexing_offsetof)+")",
    shaderUniformTexelBufferArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderUniformTexelBufferArrayNonUniformIndexing_offsetof)+")",
    shaderStorageTexelBufferArrayNonUniformIndexing: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderStorageTexelBufferArrayNonUniformIndexing_offsetof)+")",
    descriptorBindingUniformBufferUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_descriptorBindingUniformBufferUpdateAfterBind_offsetof)+")",
    descriptorBindingSampledImageUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_descriptorBindingSampledImageUpdateAfterBind_offsetof)+")",
    descriptorBindingStorageImageUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_descriptorBindingStorageImageUpdateAfterBind_offsetof)+")",
    descriptorBindingStorageBufferUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_descriptorBindingStorageBufferUpdateAfterBind_offsetof)+")",
    descriptorBindingUniformTexelBufferUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_descriptorBindingUniformTexelBufferUpdateAfterBind_offsetof)+")",
    descriptorBindingStorageTexelBufferUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_descriptorBindingStorageTexelBufferUpdateAfterBind_offsetof)+")",
    descriptorBindingUpdateUnusedWhilePending: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_descriptorBindingUpdateUnusedWhilePending_offsetof)+")",
    descriptorBindingPartiallyBound: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_descriptorBindingPartiallyBound_offsetof)+")",
    descriptorBindingVariableDescriptorCount: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_descriptorBindingVariableDescriptorCount_offsetof)+")",
    runtimeDescriptorArray: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_runtimeDescriptorArray_offsetof)+")",
    samplerFilterMinmax: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_samplerFilterMinmax_offsetof)+")",
    scalarBlockLayout: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_scalarBlockLayout_offsetof)+")",
    imagelessFramebuffer: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_imagelessFramebuffer_offsetof)+")",
    uniformBufferStandardLayout: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_uniformBufferStandardLayout_offsetof)+")",
    shaderSubgroupExtendedTypes: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderSubgroupExtendedTypes_offsetof)+")",
    separateDepthStencilLayouts: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_separateDepthStencilLayouts_offsetof)+")",
    hostQueryReset: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_hostQueryReset_offsetof)+")",
    timelineSemaphore: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_timelineSemaphore_offsetof)+")",
    bufferDeviceAddress: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_bufferDeviceAddress_offsetof)+")",
    bufferDeviceAddressCaptureReplay: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_bufferDeviceAddressCaptureReplay_offsetof)+")",
    bufferDeviceAddressMultiDevice: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_bufferDeviceAddressMultiDevice_offsetof)+")",
    vulkanMemoryModel: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_vulkanMemoryModel_offsetof)+")",
    vulkanMemoryModelDeviceScope: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_vulkanMemoryModelDeviceScope_offsetof)+")",
    vulkanMemoryModelAvailabilityVisibilityChains: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_vulkanMemoryModelAvailabilityVisibilityChains_offsetof)+")",
    shaderOutputViewportIndex: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderOutputViewportIndex_offsetof)+")",
    shaderOutputLayer: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_shaderOutputLayer_offsetof)+")",
    subgroupBroadcastDynamicId: "u32("+callof(V.VkPhysicalDeviceVulkan12Features_subgroupBroadcastDynamicId_offsetof)+")",
}, callof(V.VkPhysicalDeviceVulkan12Features_sizeof));


const VkPhysicalDeviceVulkan12Properties = new C.CStruct("VkPhysicalDeviceVulkan12Properties", {
    sType: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceVulkan12Properties_pNext_offsetof)+")",
    driverID: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_driverID_offsetof)+")",
    driverName: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceVulkan12Properties_driverName_offsetof)+")",
    driverInfo: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceVulkan12Properties_driverInfo_offsetof)+")",
    conformanceVersion: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_conformanceVersion_offsetof)+")",
    denormBehaviorIndependence: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_denormBehaviorIndependence_offsetof)+")",
    roundingModeIndependence: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_roundingModeIndependence_offsetof)+")",
    shaderSignedZeroInfNanPreserveFloat16: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderSignedZeroInfNanPreserveFloat16_offsetof)+")",
    shaderSignedZeroInfNanPreserveFloat32: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderSignedZeroInfNanPreserveFloat32_offsetof)+")",
    shaderSignedZeroInfNanPreserveFloat64: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderSignedZeroInfNanPreserveFloat64_offsetof)+")",
    shaderDenormPreserveFloat16: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderDenormPreserveFloat16_offsetof)+")",
    shaderDenormPreserveFloat32: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderDenormPreserveFloat32_offsetof)+")",
    shaderDenormPreserveFloat64: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderDenormPreserveFloat64_offsetof)+")",
    shaderDenormFlushToZeroFloat16: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderDenormFlushToZeroFloat16_offsetof)+")",
    shaderDenormFlushToZeroFloat32: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderDenormFlushToZeroFloat32_offsetof)+")",
    shaderDenormFlushToZeroFloat64: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderDenormFlushToZeroFloat64_offsetof)+")",
    shaderRoundingModeRTEFloat16: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderRoundingModeRTEFloat16_offsetof)+")",
    shaderRoundingModeRTEFloat32: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderRoundingModeRTEFloat32_offsetof)+")",
    shaderRoundingModeRTEFloat64: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderRoundingModeRTEFloat64_offsetof)+")",
    shaderRoundingModeRTZFloat16: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderRoundingModeRTZFloat16_offsetof)+")",
    shaderRoundingModeRTZFloat32: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderRoundingModeRTZFloat32_offsetof)+")",
    shaderRoundingModeRTZFloat64: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderRoundingModeRTZFloat64_offsetof)+")",
    maxUpdateAfterBindDescriptorsInAllPools: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxUpdateAfterBindDescriptorsInAllPools_offsetof)+")",
    shaderUniformBufferArrayNonUniformIndexingNative: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderUniformBufferArrayNonUniformIndexingNative_offsetof)+")",
    shaderSampledImageArrayNonUniformIndexingNative: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderSampledImageArrayNonUniformIndexingNative_offsetof)+")",
    shaderStorageBufferArrayNonUniformIndexingNative: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderStorageBufferArrayNonUniformIndexingNative_offsetof)+")",
    shaderStorageImageArrayNonUniformIndexingNative: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderStorageImageArrayNonUniformIndexingNative_offsetof)+")",
    shaderInputAttachmentArrayNonUniformIndexingNative: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_shaderInputAttachmentArrayNonUniformIndexingNative_offsetof)+")",
    robustBufferAccessUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_robustBufferAccessUpdateAfterBind_offsetof)+")",
    quadDivergentImplicitLod: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_quadDivergentImplicitLod_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindSamplers: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxPerStageDescriptorUpdateAfterBindSamplers_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindUniformBuffers: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxPerStageDescriptorUpdateAfterBindUniformBuffers_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindStorageBuffers: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxPerStageDescriptorUpdateAfterBindStorageBuffers_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindSampledImages: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxPerStageDescriptorUpdateAfterBindSampledImages_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindStorageImages: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxPerStageDescriptorUpdateAfterBindStorageImages_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindInputAttachments: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxPerStageDescriptorUpdateAfterBindInputAttachments_offsetof)+")",
    maxPerStageUpdateAfterBindResources: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxPerStageUpdateAfterBindResources_offsetof)+")",
    maxDescriptorSetUpdateAfterBindSamplers: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindSamplers_offsetof)+")",
    maxDescriptorSetUpdateAfterBindUniformBuffers: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindUniformBuffers_offsetof)+")",
    maxDescriptorSetUpdateAfterBindUniformBuffersDynamic: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindUniformBuffersDynamic_offsetof)+")",
    maxDescriptorSetUpdateAfterBindStorageBuffers: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindStorageBuffers_offsetof)+")",
    maxDescriptorSetUpdateAfterBindStorageBuffersDynamic: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindStorageBuffersDynamic_offsetof)+")",
    maxDescriptorSetUpdateAfterBindSampledImages: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindSampledImages_offsetof)+")",
    maxDescriptorSetUpdateAfterBindStorageImages: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindStorageImages_offsetof)+")",
    maxDescriptorSetUpdateAfterBindInputAttachments: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_maxDescriptorSetUpdateAfterBindInputAttachments_offsetof)+")",
    supportedDepthResolveModes: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_supportedDepthResolveModes_offsetof)+")",
    supportedStencilResolveModes: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_supportedStencilResolveModes_offsetof)+")",
    independentResolveNone: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_independentResolveNone_offsetof)+")",
    independentResolve: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_independentResolve_offsetof)+")",
    filterMinmaxSingleComponentFormats: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_filterMinmaxSingleComponentFormats_offsetof)+")",
    filterMinmaxImageComponentMapping: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_filterMinmaxImageComponentMapping_offsetof)+")",
    maxTimelineSemaphoreValueDifference: "u64("+callof(V.VkPhysicalDeviceVulkan12Properties_maxTimelineSemaphoreValueDifference_offsetof)+")",
    framebufferIntegerColorSampleCounts: "u32("+callof(V.VkPhysicalDeviceVulkan12Properties_framebufferIntegerColorSampleCounts_offsetof)+")",
}, callof(V.VkPhysicalDeviceVulkan12Properties_sizeof));


const VkPhysicalDeviceVulkan13Features = new C.CStruct("VkPhysicalDeviceVulkan13Features", {
    sType: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceVulkan13Features_pNext_offsetof)+")",
    robustImageAccess: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_robustImageAccess_offsetof)+")",
    inlineUniformBlock: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_inlineUniformBlock_offsetof)+")",
    descriptorBindingInlineUniformBlockUpdateAfterBind: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_descriptorBindingInlineUniformBlockUpdateAfterBind_offsetof)+")",
    pipelineCreationCacheControl: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_pipelineCreationCacheControl_offsetof)+")",
    privateData: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_privateData_offsetof)+")",
    shaderDemoteToHelperInvocation: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_shaderDemoteToHelperInvocation_offsetof)+")",
    shaderTerminateInvocation: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_shaderTerminateInvocation_offsetof)+")",
    subgroupSizeControl: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_subgroupSizeControl_offsetof)+")",
    computeFullSubgroups: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_computeFullSubgroups_offsetof)+")",
    synchronization2: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_synchronization2_offsetof)+")",
    textureCompressionASTC_HDR: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_textureCompressionASTC_HDR_offsetof)+")",
    shaderZeroInitializeWorkgroupMemory: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_shaderZeroInitializeWorkgroupMemory_offsetof)+")",
    dynamicRendering: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_dynamicRendering_offsetof)+")",
    shaderIntegerDotProduct: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_shaderIntegerDotProduct_offsetof)+")",
    maintenance4: "u32("+callof(V.VkPhysicalDeviceVulkan13Features_maintenance4_offsetof)+")",
}, callof(V.VkPhysicalDeviceVulkan13Features_sizeof));


const VkPhysicalDeviceVulkan13Properties = new C.CStruct("VkPhysicalDeviceVulkan13Properties", {
    sType: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceVulkan13Properties_pNext_offsetof)+")",
    minSubgroupSize: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_minSubgroupSize_offsetof)+")",
    maxSubgroupSize: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_maxSubgroupSize_offsetof)+")",
    maxComputeWorkgroupSubgroups: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_maxComputeWorkgroupSubgroups_offsetof)+")",
    requiredSubgroupSizeStages: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_requiredSubgroupSizeStages_offsetof)+")",
    maxInlineUniformBlockSize: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_maxInlineUniformBlockSize_offsetof)+")",
    maxPerStageDescriptorInlineUniformBlocks: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_maxPerStageDescriptorInlineUniformBlocks_offsetof)+")",
    maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks_offsetof)+")",
    maxDescriptorSetInlineUniformBlocks: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_maxDescriptorSetInlineUniformBlocks_offsetof)+")",
    maxDescriptorSetUpdateAfterBindInlineUniformBlocks: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_maxDescriptorSetUpdateAfterBindInlineUniformBlocks_offsetof)+")",
    maxInlineUniformTotalSize: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_maxInlineUniformTotalSize_offsetof)+")",
    integerDotProduct8BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct8BitUnsignedAccelerated_offsetof)+")",
    integerDotProduct8BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct8BitSignedAccelerated_offsetof)+")",
    integerDotProduct8BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct8BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProduct4x8BitPackedUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct4x8BitPackedUnsignedAccelerated_offsetof)+")",
    integerDotProduct4x8BitPackedSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct4x8BitPackedSignedAccelerated_offsetof)+")",
    integerDotProduct4x8BitPackedMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct4x8BitPackedMixedSignednessAccelerated_offsetof)+")",
    integerDotProduct16BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct16BitUnsignedAccelerated_offsetof)+")",
    integerDotProduct16BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct16BitSignedAccelerated_offsetof)+")",
    integerDotProduct16BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct16BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProduct32BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct32BitUnsignedAccelerated_offsetof)+")",
    integerDotProduct32BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct32BitSignedAccelerated_offsetof)+")",
    integerDotProduct32BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct32BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProduct64BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct64BitUnsignedAccelerated_offsetof)+")",
    integerDotProduct64BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct64BitSignedAccelerated_offsetof)+")",
    integerDotProduct64BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProduct64BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating8BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating8BitUnsignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating8BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating8BitSignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating16BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating16BitUnsignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating16BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating16BitSignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating32BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating32BitUnsignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating32BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating32BitSignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating64BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating64BitUnsignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating64BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating64BitSignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated_offsetof)+")",
    storageTexelBufferOffsetAlignmentBytes: "u64("+callof(V.VkPhysicalDeviceVulkan13Properties_storageTexelBufferOffsetAlignmentBytes_offsetof)+")",
    storageTexelBufferOffsetSingleTexelAlignment: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_storageTexelBufferOffsetSingleTexelAlignment_offsetof)+")",
    uniformTexelBufferOffsetAlignmentBytes: "u64("+callof(V.VkPhysicalDeviceVulkan13Properties_uniformTexelBufferOffsetAlignmentBytes_offsetof)+")",
    uniformTexelBufferOffsetSingleTexelAlignment: "u32("+callof(V.VkPhysicalDeviceVulkan13Properties_uniformTexelBufferOffsetSingleTexelAlignment_offsetof)+")",
    maxBufferSize: "u64("+callof(V.VkPhysicalDeviceVulkan13Properties_maxBufferSize_offsetof)+")",
}, callof(V.VkPhysicalDeviceVulkan13Properties_sizeof));


const VkPipelineCompilerControlCreateInfoAMD = new C.CStruct("VkPipelineCompilerControlCreateInfoAMD", {
    sType: "u32("+callof(V.VkPipelineCompilerControlCreateInfoAMD_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineCompilerControlCreateInfoAMD_pNext_offsetof)+")",
    compilerControlFlags: "u32("+callof(V.VkPipelineCompilerControlCreateInfoAMD_compilerControlFlags_offsetof)+")",
}, callof(V.VkPipelineCompilerControlCreateInfoAMD_sizeof));


const VkPhysicalDeviceCoherentMemoryFeaturesAMD = new C.CStruct("VkPhysicalDeviceCoherentMemoryFeaturesAMD", {
    sType: "u32("+callof(V.VkPhysicalDeviceCoherentMemoryFeaturesAMD_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceCoherentMemoryFeaturesAMD_pNext_offsetof)+")",
    deviceCoherentMemory: "u32("+callof(V.VkPhysicalDeviceCoherentMemoryFeaturesAMD_deviceCoherentMemory_offsetof)+")",
}, callof(V.VkPhysicalDeviceCoherentMemoryFeaturesAMD_sizeof));


const VkPhysicalDeviceToolProperties = new C.CStruct("VkPhysicalDeviceToolProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceToolProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceToolProperties_pNext_offsetof)+")",
    name: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceToolProperties_name_offsetof)+")",
    version: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceToolProperties_version_offsetof)+")",
    purposes: "u32("+callof(V.VkPhysicalDeviceToolProperties_purposes_offsetof)+")",
    description: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceToolProperties_description_offsetof)+")",
    layer: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceToolProperties_layer_offsetof)+")",
}, callof(V.VkPhysicalDeviceToolProperties_sizeof));


const VkPhysicalDeviceToolPropertiesEXT = new C.CStruct("VkPhysicalDeviceToolPropertiesEXT", {

}, callof(V.VkPhysicalDeviceToolPropertiesEXT_sizeof));


const VkSamplerCustomBorderColorCreateInfoEXT = new C.CStruct("VkSamplerCustomBorderColorCreateInfoEXT", {
    sType: "u32("+callof(V.VkSamplerCustomBorderColorCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSamplerCustomBorderColorCreateInfoEXT_pNext_offsetof)+")",
    customBorderColor: "u32("+callof(V.VkSamplerCustomBorderColorCreateInfoEXT_customBorderColor_offsetof)+")",
    format: "u32("+callof(V.VkSamplerCustomBorderColorCreateInfoEXT_format_offsetof)+")",
}, callof(V.VkSamplerCustomBorderColorCreateInfoEXT_sizeof));


const VkPhysicalDeviceCustomBorderColorPropertiesEXT = new C.CStruct("VkPhysicalDeviceCustomBorderColorPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceCustomBorderColorPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceCustomBorderColorPropertiesEXT_pNext_offsetof)+")",
    maxCustomBorderColorSamplers: "u32("+callof(V.VkPhysicalDeviceCustomBorderColorPropertiesEXT_maxCustomBorderColorSamplers_offsetof)+")",
}, callof(V.VkPhysicalDeviceCustomBorderColorPropertiesEXT_sizeof));


const VkPhysicalDeviceCustomBorderColorFeaturesEXT = new C.CStruct("VkPhysicalDeviceCustomBorderColorFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceCustomBorderColorFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceCustomBorderColorFeaturesEXT_pNext_offsetof)+")",
    customBorderColors: "u32("+callof(V.VkPhysicalDeviceCustomBorderColorFeaturesEXT_customBorderColors_offsetof)+")",
    customBorderColorWithoutFormat: "u32("+callof(V.VkPhysicalDeviceCustomBorderColorFeaturesEXT_customBorderColorWithoutFormat_offsetof)+")",
}, callof(V.VkPhysicalDeviceCustomBorderColorFeaturesEXT_sizeof));


const VkSamplerBorderColorComponentMappingCreateInfoEXT = new C.CStruct("VkSamplerBorderColorComponentMappingCreateInfoEXT", {
    sType: "u32("+callof(V.VkSamplerBorderColorComponentMappingCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSamplerBorderColorComponentMappingCreateInfoEXT_pNext_offsetof)+")",
    components: "u32("+callof(V.VkSamplerBorderColorComponentMappingCreateInfoEXT_components_offsetof)+")",
    srgb: "u32("+callof(V.VkSamplerBorderColorComponentMappingCreateInfoEXT_srgb_offsetof)+")",
}, callof(V.VkSamplerBorderColorComponentMappingCreateInfoEXT_sizeof));


const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT = new C.CStruct("VkPhysicalDeviceBorderColorSwizzleFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceBorderColorSwizzleFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceBorderColorSwizzleFeaturesEXT_pNext_offsetof)+")",
    borderColorSwizzle: "u32("+callof(V.VkPhysicalDeviceBorderColorSwizzleFeaturesEXT_borderColorSwizzle_offsetof)+")",
    borderColorSwizzleFromImage: "u32("+callof(V.VkPhysicalDeviceBorderColorSwizzleFeaturesEXT_borderColorSwizzleFromImage_offsetof)+")",
}, callof(V.VkPhysicalDeviceBorderColorSwizzleFeaturesEXT_sizeof));


const VkAccelerationStructureGeometryTrianglesDataKHR = new C.CStruct("VkAccelerationStructureGeometryTrianglesDataKHR", {
    sType: "u32("+callof(V.VkAccelerationStructureGeometryTrianglesDataKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureGeometryTrianglesDataKHR_pNext_offsetof)+")",
    vertexFormat: "u32("+callof(V.VkAccelerationStructureGeometryTrianglesDataKHR_vertexFormat_offsetof)+")",
    vertexData: "u32("+callof(V.VkAccelerationStructureGeometryTrianglesDataKHR_vertexData_offsetof)+")",
    vertexStride: "u64("+callof(V.VkAccelerationStructureGeometryTrianglesDataKHR_vertexStride_offsetof)+")",
    maxVertex: "u32("+callof(V.VkAccelerationStructureGeometryTrianglesDataKHR_maxVertex_offsetof)+")",
    indexType: "u32("+callof(V.VkAccelerationStructureGeometryTrianglesDataKHR_indexType_offsetof)+")",
    indexData: "u32("+callof(V.VkAccelerationStructureGeometryTrianglesDataKHR_indexData_offsetof)+")",
    transformData: "u32("+callof(V.VkAccelerationStructureGeometryTrianglesDataKHR_transformData_offsetof)+")",
}, callof(V.VkAccelerationStructureGeometryTrianglesDataKHR_sizeof));


const VkAccelerationStructureGeometryAabbsDataKHR = new C.CStruct("VkAccelerationStructureGeometryAabbsDataKHR", {
    sType: "u32("+callof(V.VkAccelerationStructureGeometryAabbsDataKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureGeometryAabbsDataKHR_pNext_offsetof)+")",
    data: "u32("+callof(V.VkAccelerationStructureGeometryAabbsDataKHR_data_offsetof)+")",
    stride: "u64("+callof(V.VkAccelerationStructureGeometryAabbsDataKHR_stride_offsetof)+")",
}, callof(V.VkAccelerationStructureGeometryAabbsDataKHR_sizeof));


const VkAccelerationStructureGeometryInstancesDataKHR = new C.CStruct("VkAccelerationStructureGeometryInstancesDataKHR", {
    sType: "u32("+callof(V.VkAccelerationStructureGeometryInstancesDataKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureGeometryInstancesDataKHR_pNext_offsetof)+")",
    arrayOfPointers: "u32("+callof(V.VkAccelerationStructureGeometryInstancesDataKHR_arrayOfPointers_offsetof)+")",
    data: "u32("+callof(V.VkAccelerationStructureGeometryInstancesDataKHR_data_offsetof)+")",
}, callof(V.VkAccelerationStructureGeometryInstancesDataKHR_sizeof));


const VkAccelerationStructureGeometryKHR = new C.CStruct("VkAccelerationStructureGeometryKHR", {
    sType: "u32("+callof(V.VkAccelerationStructureGeometryKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureGeometryKHR_pNext_offsetof)+")",
    geometryType: "u32("+callof(V.VkAccelerationStructureGeometryKHR_geometryType_offsetof)+")",
    geometry: "u32("+callof(V.VkAccelerationStructureGeometryKHR_geometry_offsetof)+")",
    flags: "u32("+callof(V.VkAccelerationStructureGeometryKHR_flags_offsetof)+")",
}, callof(V.VkAccelerationStructureGeometryKHR_sizeof));


const VkAccelerationStructureBuildGeometryInfoKHR = new C.CStruct("VkAccelerationStructureBuildGeometryInfoKHR", {
    sType: "u32("+callof(V.VkAccelerationStructureBuildGeometryInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureBuildGeometryInfoKHR_pNext_offsetof)+")",
    type: "u32("+callof(V.VkAccelerationStructureBuildGeometryInfoKHR_type_offsetof)+")",
    flags: "u32("+callof(V.VkAccelerationStructureBuildGeometryInfoKHR_flags_offsetof)+")",
    mode: "u32("+callof(V.VkAccelerationStructureBuildGeometryInfoKHR_mode_offsetof)+")",
    srcAccelerationStructure: "u64("+callof(V.VkAccelerationStructureBuildGeometryInfoKHR_srcAccelerationStructure_offsetof)+")",
    dstAccelerationStructure: "u64("+callof(V.VkAccelerationStructureBuildGeometryInfoKHR_dstAccelerationStructure_offsetof)+")",
    geometryCount: "u32("+callof(V.VkAccelerationStructureBuildGeometryInfoKHR_geometryCount_offsetof)+")",
    pGeometries: "u64("+callof(V.VkAccelerationStructureBuildGeometryInfoKHR_pGeometries_offsetof)+")",
    ppGeometries: "u64("+callof(V.VkAccelerationStructureBuildGeometryInfoKHR_ppGeometries_offsetof)+")",
    scratchData: "u64("+callof(V.VkAccelerationStructureBuildGeometryInfoKHR_scratchData_offsetof)+")",
}, callof(V.VkAccelerationStructureBuildGeometryInfoKHR_sizeof));


const VkAccelerationStructureBuildRangeInfoKHR = new C.CStruct("VkAccelerationStructureBuildRangeInfoKHR", {
    primitiveCount: "u32("+callof(V.VkAccelerationStructureBuildRangeInfoKHR_primitiveCount_offsetof)+")",
    primitiveOffset: "u32("+callof(V.VkAccelerationStructureBuildRangeInfoKHR_primitiveOffset_offsetof)+")",
    firstVertex: "u32("+callof(V.VkAccelerationStructureBuildRangeInfoKHR_firstVertex_offsetof)+")",
    transformOffset: "u32("+callof(V.VkAccelerationStructureBuildRangeInfoKHR_transformOffset_offsetof)+")",
}, callof(V.VkAccelerationStructureBuildRangeInfoKHR_sizeof));


const VkAccelerationStructureCreateInfoKHR = new C.CStruct("VkAccelerationStructureCreateInfoKHR", {
    sType: "u32("+callof(V.VkAccelerationStructureCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureCreateInfoKHR_pNext_offsetof)+")",
    createFlags: "u32("+callof(V.VkAccelerationStructureCreateInfoKHR_createFlags_offsetof)+")",
    buffer: "u64("+callof(V.VkAccelerationStructureCreateInfoKHR_buffer_offsetof)+")",
    offset: "u64("+callof(V.VkAccelerationStructureCreateInfoKHR_offset_offsetof)+")",
    size: "u64("+callof(V.VkAccelerationStructureCreateInfoKHR_size_offsetof)+")",
    type: "u32("+callof(V.VkAccelerationStructureCreateInfoKHR_type_offsetof)+")",
    deviceAddress: "u64("+callof(V.VkAccelerationStructureCreateInfoKHR_deviceAddress_offsetof)+")",
}, callof(V.VkAccelerationStructureCreateInfoKHR_sizeof));


const VkAabbPositionsKHR = new C.CStruct("VkAabbPositionsKHR", {
    minX: "f32("+callof(V.VkAabbPositionsKHR_minX_offsetof)+")",
    minY: "f32("+callof(V.VkAabbPositionsKHR_minY_offsetof)+")",
    minZ: "f32("+callof(V.VkAabbPositionsKHR_minZ_offsetof)+")",
    maxX: "f32("+callof(V.VkAabbPositionsKHR_maxX_offsetof)+")",
    maxY: "f32("+callof(V.VkAabbPositionsKHR_maxY_offsetof)+")",
    maxZ: "f32("+callof(V.VkAabbPositionsKHR_maxZ_offsetof)+")",
}, callof(V.VkAabbPositionsKHR_sizeof));


const VkAabbPositionsNV = new C.CStruct("VkAabbPositionsNV", {

}, callof(V.VkAabbPositionsNV_sizeof));


const VkTransformMatrixKHR = new C.CStruct("VkTransformMatrixKHR", {
    matrix: "u32(0)[12]",
}, callof(V.VkTransformMatrixKHR_sizeof));    


const VkTransformMatrixNV = new C.CStruct("VkTransformMatrixNV", {
    matrix: "u32(0)[12]",
}, callof(V.VkTransformMatrixNV_sizeof));    


const VkAccelerationStructureInstanceKHR = new C.CStruct("VkAccelerationStructureInstanceKHR", {
    transform: "VkTransformMatrixKHR("+callof(V.VkAccelerationStructureInstanceKHR_transform_offsetof)+")",
    instanceCustomIndex: "u24("+callof(V.VkAccelerationStructureInstanceKHR_instanceCustomIndex_offsetof)+")",
    mask: "u8("+callof(V.VkAccelerationStructureInstanceKHR_mask_offsetof)+")",
    instanceShaderBindingTableRecordOffset: "u24("+callof(V.VkAccelerationStructureInstanceKHR_instanceShaderBindingTableRecordOffset_offsetof)+")",
    flags: "u8("+callof(V.VkAccelerationStructureInstanceKHR_flags_offsetof)+")",
    accelerationStructureReference: "u64("+callof(V.VkAccelerationStructureInstanceKHR_accelerationStructureReference_offsetof)+")",
}, callof(V.VkAccelerationStructureInstanceKHR_sizeof));


const VkAccelerationStructureInstanceNV = new C.CStruct("VkAccelerationStructureInstanceNV", {

}, callof(V.VkAccelerationStructureInstanceNV_sizeof));


const VkAccelerationStructureDeviceAddressInfoKHR = new C.CStruct("VkAccelerationStructureDeviceAddressInfoKHR", {
    sType: "u32("+callof(V.VkAccelerationStructureDeviceAddressInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureDeviceAddressInfoKHR_pNext_offsetof)+")",
    accelerationStructure: "u64("+callof(V.VkAccelerationStructureDeviceAddressInfoKHR_accelerationStructure_offsetof)+")",
}, callof(V.VkAccelerationStructureDeviceAddressInfoKHR_sizeof));


const VkAccelerationStructureVersionInfoKHR = new C.CStruct("VkAccelerationStructureVersionInfoKHR", {
    sType: "u32("+callof(V.VkAccelerationStructureVersionInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureVersionInfoKHR_pNext_offsetof)+")",
    pVersionData: "u64("+callof(V.VkAccelerationStructureVersionInfoKHR_pVersionData_offsetof)+")",
}, callof(V.VkAccelerationStructureVersionInfoKHR_sizeof));


const VkCopyAccelerationStructureInfoKHR = new C.CStruct("VkCopyAccelerationStructureInfoKHR", {
    sType: "u32("+callof(V.VkCopyAccelerationStructureInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCopyAccelerationStructureInfoKHR_pNext_offsetof)+")",
    src: "u64("+callof(V.VkCopyAccelerationStructureInfoKHR_src_offsetof)+")",
    dst: "u64("+callof(V.VkCopyAccelerationStructureInfoKHR_dst_offsetof)+")",
    mode: "u32("+callof(V.VkCopyAccelerationStructureInfoKHR_mode_offsetof)+")",
}, callof(V.VkCopyAccelerationStructureInfoKHR_sizeof));


const VkCopyAccelerationStructureToMemoryInfoKHR = new C.CStruct("VkCopyAccelerationStructureToMemoryInfoKHR", {
    sType: "u32("+callof(V.VkCopyAccelerationStructureToMemoryInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCopyAccelerationStructureToMemoryInfoKHR_pNext_offsetof)+")",
    src: "u64("+callof(V.VkCopyAccelerationStructureToMemoryInfoKHR_src_offsetof)+")",
    dst: "u64("+callof(V.VkCopyAccelerationStructureToMemoryInfoKHR_dst_offsetof)+")",
    mode: "u32("+callof(V.VkCopyAccelerationStructureToMemoryInfoKHR_mode_offsetof)+")",
}, callof(V.VkCopyAccelerationStructureToMemoryInfoKHR_sizeof));


const VkCopyMemoryToAccelerationStructureInfoKHR = new C.CStruct("VkCopyMemoryToAccelerationStructureInfoKHR", {
    sType: "u32("+callof(V.VkCopyMemoryToAccelerationStructureInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCopyMemoryToAccelerationStructureInfoKHR_pNext_offsetof)+")",
    src: "u32("+callof(V.VkCopyMemoryToAccelerationStructureInfoKHR_src_offsetof)+")",
    dst: "u64("+callof(V.VkCopyMemoryToAccelerationStructureInfoKHR_dst_offsetof)+")",
    mode: "u32("+callof(V.VkCopyMemoryToAccelerationStructureInfoKHR_mode_offsetof)+")",
}, callof(V.VkCopyMemoryToAccelerationStructureInfoKHR_sizeof));


const VkRayTracingPipelineInterfaceCreateInfoKHR = new C.CStruct("VkRayTracingPipelineInterfaceCreateInfoKHR", {
    sType: "u32("+callof(V.VkRayTracingPipelineInterfaceCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRayTracingPipelineInterfaceCreateInfoKHR_pNext_offsetof)+")",
    maxPipelineRayPayloadSize: "u32("+callof(V.VkRayTracingPipelineInterfaceCreateInfoKHR_maxPipelineRayPayloadSize_offsetof)+")",
    maxPipelineRayHitAttributeSize: "u32("+callof(V.VkRayTracingPipelineInterfaceCreateInfoKHR_maxPipelineRayHitAttributeSize_offsetof)+")",
}, callof(V.VkRayTracingPipelineInterfaceCreateInfoKHR_sizeof));


const VkPipelineLibraryCreateInfoKHR = new C.CStruct("VkPipelineLibraryCreateInfoKHR", {
    sType: "u32("+callof(V.VkPipelineLibraryCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineLibraryCreateInfoKHR_pNext_offsetof)+")",
    libraryCount: "u32("+callof(V.VkPipelineLibraryCreateInfoKHR_libraryCount_offsetof)+")",
    pLibraries: "u64("+callof(V.VkPipelineLibraryCreateInfoKHR_pLibraries_offsetof)+")",
}, callof(V.VkPipelineLibraryCreateInfoKHR_sizeof));


const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT = new C.CStruct("VkPhysicalDeviceExtendedDynamicStateFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicStateFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceExtendedDynamicStateFeaturesEXT_pNext_offsetof)+")",
    extendedDynamicState: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicStateFeaturesEXT_extendedDynamicState_offsetof)+")",
}, callof(V.VkPhysicalDeviceExtendedDynamicStateFeaturesEXT_sizeof));


const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT = new C.CStruct("VkPhysicalDeviceExtendedDynamicState2FeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState2FeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceExtendedDynamicState2FeaturesEXT_pNext_offsetof)+")",
    extendedDynamicState2: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState2FeaturesEXT_extendedDynamicState2_offsetof)+")",
    extendedDynamicState2LogicOp: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState2FeaturesEXT_extendedDynamicState2LogicOp_offsetof)+")",
    extendedDynamicState2PatchControlPoints: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState2FeaturesEXT_extendedDynamicState2PatchControlPoints_offsetof)+")",
}, callof(V.VkPhysicalDeviceExtendedDynamicState2FeaturesEXT_sizeof));


const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT = new C.CStruct("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_pNext_offsetof)+")",
    extendedDynamicState3TessellationDomainOrigin: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3TessellationDomainOrigin_offsetof)+")",
    extendedDynamicState3DepthClampEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3DepthClampEnable_offsetof)+")",
    extendedDynamicState3PolygonMode: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3PolygonMode_offsetof)+")",
    extendedDynamicState3RasterizationSamples: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3RasterizationSamples_offsetof)+")",
    extendedDynamicState3SampleMask: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3SampleMask_offsetof)+")",
    extendedDynamicState3AlphaToCoverageEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3AlphaToCoverageEnable_offsetof)+")",
    extendedDynamicState3AlphaToOneEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3AlphaToOneEnable_offsetof)+")",
    extendedDynamicState3LogicOpEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3LogicOpEnable_offsetof)+")",
    extendedDynamicState3ColorBlendEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ColorBlendEnable_offsetof)+")",
    extendedDynamicState3ColorBlendEquation: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ColorBlendEquation_offsetof)+")",
    extendedDynamicState3ColorWriteMask: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ColorWriteMask_offsetof)+")",
    extendedDynamicState3RasterizationStream: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3RasterizationStream_offsetof)+")",
    extendedDynamicState3ConservativeRasterizationMode: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ConservativeRasterizationMode_offsetof)+")",
    extendedDynamicState3ExtraPrimitiveOverestimationSize: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ExtraPrimitiveOverestimationSize_offsetof)+")",
    extendedDynamicState3DepthClipEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3DepthClipEnable_offsetof)+")",
    extendedDynamicState3SampleLocationsEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3SampleLocationsEnable_offsetof)+")",
    extendedDynamicState3ColorBlendAdvanced: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ColorBlendAdvanced_offsetof)+")",
    extendedDynamicState3ProvokingVertexMode: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ProvokingVertexMode_offsetof)+")",
    extendedDynamicState3LineRasterizationMode: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3LineRasterizationMode_offsetof)+")",
    extendedDynamicState3LineStippleEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3LineStippleEnable_offsetof)+")",
    extendedDynamicState3DepthClipNegativeOneToOne: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3DepthClipNegativeOneToOne_offsetof)+")",
    extendedDynamicState3ViewportWScalingEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ViewportWScalingEnable_offsetof)+")",
    extendedDynamicState3ViewportSwizzle: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ViewportSwizzle_offsetof)+")",
    extendedDynamicState3CoverageToColorEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3CoverageToColorEnable_offsetof)+")",
    extendedDynamicState3CoverageToColorLocation: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3CoverageToColorLocation_offsetof)+")",
    extendedDynamicState3CoverageModulationMode: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3CoverageModulationMode_offsetof)+")",
    extendedDynamicState3CoverageModulationTableEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3CoverageModulationTableEnable_offsetof)+")",
    extendedDynamicState3CoverageModulationTable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3CoverageModulationTable_offsetof)+")",
    extendedDynamicState3CoverageReductionMode: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3CoverageReductionMode_offsetof)+")",
    extendedDynamicState3RepresentativeFragmentTestEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3RepresentativeFragmentTestEnable_offsetof)+")",
    extendedDynamicState3ShadingRateImageEnable: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_extendedDynamicState3ShadingRateImageEnable_offsetof)+")",
}, callof(V.VkPhysicalDeviceExtendedDynamicState3FeaturesEXT_sizeof));


const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT = new C.CStruct("VkPhysicalDeviceExtendedDynamicState3PropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3PropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceExtendedDynamicState3PropertiesEXT_pNext_offsetof)+")",
    dynamicPrimitiveTopologyUnrestricted: "u32("+callof(V.VkPhysicalDeviceExtendedDynamicState3PropertiesEXT_dynamicPrimitiveTopologyUnrestricted_offsetof)+")",
}, callof(V.VkPhysicalDeviceExtendedDynamicState3PropertiesEXT_sizeof));


const VkColorBlendEquationEXT = new C.CStruct("VkColorBlendEquationEXT", {
    srcColorBlendFactor: "u32("+callof(V.VkColorBlendEquationEXT_srcColorBlendFactor_offsetof)+")",
    dstColorBlendFactor: "u32("+callof(V.VkColorBlendEquationEXT_dstColorBlendFactor_offsetof)+")",
    colorBlendOp: "u32("+callof(V.VkColorBlendEquationEXT_colorBlendOp_offsetof)+")",
    srcAlphaBlendFactor: "u32("+callof(V.VkColorBlendEquationEXT_srcAlphaBlendFactor_offsetof)+")",
    dstAlphaBlendFactor: "u32("+callof(V.VkColorBlendEquationEXT_dstAlphaBlendFactor_offsetof)+")",
    alphaBlendOp: "u32("+callof(V.VkColorBlendEquationEXT_alphaBlendOp_offsetof)+")",
}, callof(V.VkColorBlendEquationEXT_sizeof));


const VkColorBlendAdvancedEXT = new C.CStruct("VkColorBlendAdvancedEXT", {
    advancedBlendOp: "u32("+callof(V.VkColorBlendAdvancedEXT_advancedBlendOp_offsetof)+")",
    srcPremultiplied: "u32("+callof(V.VkColorBlendAdvancedEXT_srcPremultiplied_offsetof)+")",
    dstPremultiplied: "u32("+callof(V.VkColorBlendAdvancedEXT_dstPremultiplied_offsetof)+")",
    blendOverlap: "u32("+callof(V.VkColorBlendAdvancedEXT_blendOverlap_offsetof)+")",
    clampResults: "u32("+callof(V.VkColorBlendAdvancedEXT_clampResults_offsetof)+")",
}, callof(V.VkColorBlendAdvancedEXT_sizeof));


const VkRenderPassTransformBeginInfoQCOM = new C.CStruct("VkRenderPassTransformBeginInfoQCOM", {
    sType: "u32("+callof(V.VkRenderPassTransformBeginInfoQCOM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderPassTransformBeginInfoQCOM_pNext_offsetof)+")",
    transform: "u32("+callof(V.VkRenderPassTransformBeginInfoQCOM_transform_offsetof)+")",
}, callof(V.VkRenderPassTransformBeginInfoQCOM_sizeof));


const VkCopyCommandTransformInfoQCOM = new C.CStruct("VkCopyCommandTransformInfoQCOM", {
    sType: "u32("+callof(V.VkCopyCommandTransformInfoQCOM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCopyCommandTransformInfoQCOM_pNext_offsetof)+")",
    transform: "u32("+callof(V.VkCopyCommandTransformInfoQCOM_transform_offsetof)+")",
}, callof(V.VkCopyCommandTransformInfoQCOM_sizeof));


const VkCommandBufferInheritanceRenderPassTransformInfoQCOM = new C.CStruct("VkCommandBufferInheritanceRenderPassTransformInfoQCOM", {
    sType: "u32("+callof(V.VkCommandBufferInheritanceRenderPassTransformInfoQCOM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCommandBufferInheritanceRenderPassTransformInfoQCOM_pNext_offsetof)+")",
    transform: "u32("+callof(V.VkCommandBufferInheritanceRenderPassTransformInfoQCOM_transform_offsetof)+")",
    renderArea: "VkRect2D("+callof(V.VkCommandBufferInheritanceRenderPassTransformInfoQCOM_renderArea_offsetof)+")",
}, callof(V.VkCommandBufferInheritanceRenderPassTransformInfoQCOM_sizeof));


const VkPhysicalDeviceDiagnosticsConfigFeaturesNV = new C.CStruct("VkPhysicalDeviceDiagnosticsConfigFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceDiagnosticsConfigFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDiagnosticsConfigFeaturesNV_pNext_offsetof)+")",
    diagnosticsConfig: "u32("+callof(V.VkPhysicalDeviceDiagnosticsConfigFeaturesNV_diagnosticsConfig_offsetof)+")",
}, callof(V.VkPhysicalDeviceDiagnosticsConfigFeaturesNV_sizeof));


const VkDeviceDiagnosticsConfigCreateInfoNV = new C.CStruct("VkDeviceDiagnosticsConfigCreateInfoNV", {
    sType: "u32("+callof(V.VkDeviceDiagnosticsConfigCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceDiagnosticsConfigCreateInfoNV_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDeviceDiagnosticsConfigCreateInfoNV_flags_offsetof)+")",
}, callof(V.VkDeviceDiagnosticsConfigCreateInfoNV_sizeof));


const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures = new C.CStruct("VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures_pNext_offsetof)+")",
    shaderZeroInitializeWorkgroupMemory: "u32("+callof(V.VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures_shaderZeroInitializeWorkgroupMemory_offsetof)+")",
}, callof(V.VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures_sizeof));


const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR = new C.CStruct("VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR", {

}, callof(V.VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR_sizeof));


const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR = new C.CStruct("VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR_pNext_offsetof)+")",
    shaderSubgroupUniformControlFlow: "u32("+callof(V.VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR_shaderSubgroupUniformControlFlow_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR_sizeof));


const VkPhysicalDeviceRobustness2FeaturesEXT = new C.CStruct("VkPhysicalDeviceRobustness2FeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceRobustness2FeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRobustness2FeaturesEXT_pNext_offsetof)+")",
    robustBufferAccess2: "u32("+callof(V.VkPhysicalDeviceRobustness2FeaturesEXT_robustBufferAccess2_offsetof)+")",
    robustImageAccess2: "u32("+callof(V.VkPhysicalDeviceRobustness2FeaturesEXT_robustImageAccess2_offsetof)+")",
    nullDescriptor: "u32("+callof(V.VkPhysicalDeviceRobustness2FeaturesEXT_nullDescriptor_offsetof)+")",
}, callof(V.VkPhysicalDeviceRobustness2FeaturesEXT_sizeof));


const VkPhysicalDeviceRobustness2PropertiesEXT = new C.CStruct("VkPhysicalDeviceRobustness2PropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceRobustness2PropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRobustness2PropertiesEXT_pNext_offsetof)+")",
    robustStorageBufferAccessSizeAlignment: "u64("+callof(V.VkPhysicalDeviceRobustness2PropertiesEXT_robustStorageBufferAccessSizeAlignment_offsetof)+")",
    robustUniformBufferAccessSizeAlignment: "u64("+callof(V.VkPhysicalDeviceRobustness2PropertiesEXT_robustUniformBufferAccessSizeAlignment_offsetof)+")",
}, callof(V.VkPhysicalDeviceRobustness2PropertiesEXT_sizeof));


const VkPhysicalDeviceImageRobustnessFeatures = new C.CStruct("VkPhysicalDeviceImageRobustnessFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceImageRobustnessFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceImageRobustnessFeatures_pNext_offsetof)+")",
    robustImageAccess: "u32("+callof(V.VkPhysicalDeviceImageRobustnessFeatures_robustImageAccess_offsetof)+")",
}, callof(V.VkPhysicalDeviceImageRobustnessFeatures_sizeof));


const VkPhysicalDeviceImageRobustnessFeaturesEXT = new C.CStruct("VkPhysicalDeviceImageRobustnessFeaturesEXT", {

}, callof(V.VkPhysicalDeviceImageRobustnessFeaturesEXT_sizeof));


const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR = new C.CStruct("VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_pNext_offsetof)+")",
    workgroupMemoryExplicitLayout: "u32("+callof(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_workgroupMemoryExplicitLayout_offsetof)+")",
    workgroupMemoryExplicitLayoutScalarBlockLayout: "u32("+callof(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_workgroupMemoryExplicitLayoutScalarBlockLayout_offsetof)+")",
    workgroupMemoryExplicitLayout8BitAccess: "u32("+callof(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_workgroupMemoryExplicitLayout8BitAccess_offsetof)+")",
    workgroupMemoryExplicitLayout16BitAccess: "u32("+callof(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_workgroupMemoryExplicitLayout16BitAccess_offsetof)+")",
}, callof(V.VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_sizeof));


const VkPhysicalDevicePortabilitySubsetFeaturesKHR = new C.CStruct("VkPhysicalDevicePortabilitySubsetFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_pNext_offsetof)+")",
    constantAlphaColorBlendFactors: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_constantAlphaColorBlendFactors_offsetof)+")",
    events: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_events_offsetof)+")",
    imageViewFormatReinterpretation: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_imageViewFormatReinterpretation_offsetof)+")",
    imageViewFormatSwizzle: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_imageViewFormatSwizzle_offsetof)+")",
    imageView2DOn3DImage: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_imageView2DOn3DImage_offsetof)+")",
    multisampleArrayImage: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_multisampleArrayImage_offsetof)+")",
    mutableComparisonSamplers: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_mutableComparisonSamplers_offsetof)+")",
    pointPolygons: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_pointPolygons_offsetof)+")",
    samplerMipLodBias: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_samplerMipLodBias_offsetof)+")",
    separateStencilMaskRef: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_separateStencilMaskRef_offsetof)+")",
    shaderSampleRateInterpolationFunctions: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_shaderSampleRateInterpolationFunctions_offsetof)+")",
    tessellationIsolines: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_tessellationIsolines_offsetof)+")",
    tessellationPointMode: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_tessellationPointMode_offsetof)+")",
    triangleFans: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_triangleFans_offsetof)+")",
    vertexAttributeAccessBeyondStride: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_vertexAttributeAccessBeyondStride_offsetof)+")",
}, callof(V.VkPhysicalDevicePortabilitySubsetFeaturesKHR_sizeof));


const VkPhysicalDevicePortabilitySubsetPropertiesKHR = new C.CStruct("VkPhysicalDevicePortabilitySubsetPropertiesKHR", {
    sType: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetPropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePortabilitySubsetPropertiesKHR_pNext_offsetof)+")",
    minVertexInputBindingStrideAlignment: "u32("+callof(V.VkPhysicalDevicePortabilitySubsetPropertiesKHR_minVertexInputBindingStrideAlignment_offsetof)+")",
}, callof(V.VkPhysicalDevicePortabilitySubsetPropertiesKHR_sizeof));


const VkPhysicalDevice4444FormatsFeaturesEXT = new C.CStruct("VkPhysicalDevice4444FormatsFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDevice4444FormatsFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevice4444FormatsFeaturesEXT_pNext_offsetof)+")",
    formatA4R4G4B4: "u32("+callof(V.VkPhysicalDevice4444FormatsFeaturesEXT_formatA4R4G4B4_offsetof)+")",
    formatA4B4G4R4: "u32("+callof(V.VkPhysicalDevice4444FormatsFeaturesEXT_formatA4B4G4R4_offsetof)+")",
}, callof(V.VkPhysicalDevice4444FormatsFeaturesEXT_sizeof));


const VkPhysicalDeviceSubpassShadingFeaturesHUAWEI = new C.CStruct("VkPhysicalDeviceSubpassShadingFeaturesHUAWEI", {
    sType: "u32("+callof(V.VkPhysicalDeviceSubpassShadingFeaturesHUAWEI_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSubpassShadingFeaturesHUAWEI_pNext_offsetof)+")",
    subpassShading: "u32("+callof(V.VkPhysicalDeviceSubpassShadingFeaturesHUAWEI_subpassShading_offsetof)+")",
}, callof(V.VkPhysicalDeviceSubpassShadingFeaturesHUAWEI_sizeof));


const VkBufferCopy2 = new C.CStruct("VkBufferCopy2", {
    sType: "u32("+callof(V.VkBufferCopy2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferCopy2_pNext_offsetof)+")",
    srcOffset: "u64("+callof(V.VkBufferCopy2_srcOffset_offsetof)+")",
    dstOffset: "u64("+callof(V.VkBufferCopy2_dstOffset_offsetof)+")",
    size: "u64("+callof(V.VkBufferCopy2_size_offsetof)+")",
}, callof(V.VkBufferCopy2_sizeof));


const VkBufferCopy2KHR = new C.CStruct("VkBufferCopy2KHR", {

}, callof(V.VkBufferCopy2KHR_sizeof));


const VkImageCopy2 = new C.CStruct("VkImageCopy2", {
    sType: "u32("+callof(V.VkImageCopy2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageCopy2_pNext_offsetof)+")",
    srcSubresource: "u32("+callof(V.VkImageCopy2_srcSubresource_offsetof)+")",
    srcOffset: "u32("+callof(V.VkImageCopy2_srcOffset_offsetof)+")",
    dstSubresource: "u32("+callof(V.VkImageCopy2_dstSubresource_offsetof)+")",
    dstOffset: "u32("+callof(V.VkImageCopy2_dstOffset_offsetof)+")",
    extent: "u32("+callof(V.VkImageCopy2_extent_offsetof)+")",
}, callof(V.VkImageCopy2_sizeof));


const VkImageCopy2KHR = new C.CStruct("VkImageCopy2KHR", {

}, callof(V.VkImageCopy2KHR_sizeof));


const VkImageBlit2 = new C.CStruct("VkImageBlit2", {
    sType: "u32("+callof(V.VkImageBlit2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageBlit2_pNext_offsetof)+")",
    srcSubresource: "u32("+callof(V.VkImageBlit2_srcSubresource_offsetof)+")",
    srcOffsets: "u32[2]("+callof(V.VkImageBlit2_srcOffsets_offsetof)+")",
    dstSubresource: "u32("+callof(V.VkImageBlit2_dstSubresource_offsetof)+")",
    dstOffsets: "u32[2]("+callof(V.VkImageBlit2_dstOffsets_offsetof)+")",
}, callof(V.VkImageBlit2_sizeof));


const VkImageBlit2KHR = new C.CStruct("VkImageBlit2KHR", {

}, callof(V.VkImageBlit2KHR_sizeof));


const VkBufferImageCopy2 = new C.CStruct("VkBufferImageCopy2", {
    sType: "u32("+callof(V.VkBufferImageCopy2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferImageCopy2_pNext_offsetof)+")",
    bufferOffset: "u64("+callof(V.VkBufferImageCopy2_bufferOffset_offsetof)+")",
    bufferRowLength: "u32("+callof(V.VkBufferImageCopy2_bufferRowLength_offsetof)+")",
    bufferImageHeight: "u32("+callof(V.VkBufferImageCopy2_bufferImageHeight_offsetof)+")",
    imageSubresource: "u32("+callof(V.VkBufferImageCopy2_imageSubresource_offsetof)+")",
    imageOffset: "u32("+callof(V.VkBufferImageCopy2_imageOffset_offsetof)+")",
    imageExtent: "u32("+callof(V.VkBufferImageCopy2_imageExtent_offsetof)+")",
}, callof(V.VkBufferImageCopy2_sizeof));


const VkBufferImageCopy2KHR = new C.CStruct("VkBufferImageCopy2KHR", {

}, callof(V.VkBufferImageCopy2KHR_sizeof));


const VkImageResolve2 = new C.CStruct("VkImageResolve2", {
    sType: "u32("+callof(V.VkImageResolve2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageResolve2_pNext_offsetof)+")",
    srcSubresource: "u32("+callof(V.VkImageResolve2_srcSubresource_offsetof)+")",
    srcOffset: "u32("+callof(V.VkImageResolve2_srcOffset_offsetof)+")",
    dstSubresource: "u32("+callof(V.VkImageResolve2_dstSubresource_offsetof)+")",
    dstOffset: "u32("+callof(V.VkImageResolve2_dstOffset_offsetof)+")",
    extent: "u32("+callof(V.VkImageResolve2_extent_offsetof)+")",
}, callof(V.VkImageResolve2_sizeof));


const VkImageResolve2KHR = new C.CStruct("VkImageResolve2KHR", {

}, callof(V.VkImageResolve2KHR_sizeof));


const VkCopyBufferInfo2 = new C.CStruct("VkCopyBufferInfo2", {
    sType: "u32("+callof(V.VkCopyBufferInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCopyBufferInfo2_pNext_offsetof)+")",
    srcBuffer: "u64("+callof(V.VkCopyBufferInfo2_srcBuffer_offsetof)+")",
    dstBuffer: "u64("+callof(V.VkCopyBufferInfo2_dstBuffer_offsetof)+")",
    regionCount: "u32("+callof(V.VkCopyBufferInfo2_regionCount_offsetof)+")",
    pRegions: "u64("+callof(V.VkCopyBufferInfo2_pRegions_offsetof)+")",
}, callof(V.VkCopyBufferInfo2_sizeof));


const VkCopyBufferInfo2KHR = new C.CStruct("VkCopyBufferInfo2KHR", {

}, callof(V.VkCopyBufferInfo2KHR_sizeof));


const VkCopyImageInfo2 = new C.CStruct("VkCopyImageInfo2", {
    sType: "u32("+callof(V.VkCopyImageInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCopyImageInfo2_pNext_offsetof)+")",
    srcImage: "u64("+callof(V.VkCopyImageInfo2_srcImage_offsetof)+")",
    srcImageLayout: "u32("+callof(V.VkCopyImageInfo2_srcImageLayout_offsetof)+")",
    dstImage: "u64("+callof(V.VkCopyImageInfo2_dstImage_offsetof)+")",
    dstImageLayout: "u32("+callof(V.VkCopyImageInfo2_dstImageLayout_offsetof)+")",
    regionCount: "u32("+callof(V.VkCopyImageInfo2_regionCount_offsetof)+")",
    pRegions: "u64("+callof(V.VkCopyImageInfo2_pRegions_offsetof)+")",
}, callof(V.VkCopyImageInfo2_sizeof));


const VkCopyImageInfo2KHR = new C.CStruct("VkCopyImageInfo2KHR", {

}, callof(V.VkCopyImageInfo2KHR_sizeof));


const VkBlitImageInfo2 = new C.CStruct("VkBlitImageInfo2", {
    sType: "u32("+callof(V.VkBlitImageInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBlitImageInfo2_pNext_offsetof)+")",
    srcImage: "u64("+callof(V.VkBlitImageInfo2_srcImage_offsetof)+")",
    srcImageLayout: "u32("+callof(V.VkBlitImageInfo2_srcImageLayout_offsetof)+")",
    dstImage: "u64("+callof(V.VkBlitImageInfo2_dstImage_offsetof)+")",
    dstImageLayout: "u32("+callof(V.VkBlitImageInfo2_dstImageLayout_offsetof)+")",
    regionCount: "u32("+callof(V.VkBlitImageInfo2_regionCount_offsetof)+")",
    pRegions: "u64("+callof(V.VkBlitImageInfo2_pRegions_offsetof)+")",
    filter: "u32("+callof(V.VkBlitImageInfo2_filter_offsetof)+")",
}, callof(V.VkBlitImageInfo2_sizeof));


const VkBlitImageInfo2KHR = new C.CStruct("VkBlitImageInfo2KHR", {

}, callof(V.VkBlitImageInfo2KHR_sizeof));


const VkCopyBufferToImageInfo2 = new C.CStruct("VkCopyBufferToImageInfo2", {
    sType: "u32("+callof(V.VkCopyBufferToImageInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCopyBufferToImageInfo2_pNext_offsetof)+")",
    srcBuffer: "u64("+callof(V.VkCopyBufferToImageInfo2_srcBuffer_offsetof)+")",
    dstImage: "u64("+callof(V.VkCopyBufferToImageInfo2_dstImage_offsetof)+")",
    dstImageLayout: "u32("+callof(V.VkCopyBufferToImageInfo2_dstImageLayout_offsetof)+")",
    regionCount: "u32("+callof(V.VkCopyBufferToImageInfo2_regionCount_offsetof)+")",
    pRegions: "u64("+callof(V.VkCopyBufferToImageInfo2_pRegions_offsetof)+")",
}, callof(V.VkCopyBufferToImageInfo2_sizeof));


const VkCopyBufferToImageInfo2KHR = new C.CStruct("VkCopyBufferToImageInfo2KHR", {

}, callof(V.VkCopyBufferToImageInfo2KHR_sizeof));


const VkCopyImageToBufferInfo2 = new C.CStruct("VkCopyImageToBufferInfo2", {
    sType: "u32("+callof(V.VkCopyImageToBufferInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCopyImageToBufferInfo2_pNext_offsetof)+")",
    srcImage: "u64("+callof(V.VkCopyImageToBufferInfo2_srcImage_offsetof)+")",
    srcImageLayout: "u32("+callof(V.VkCopyImageToBufferInfo2_srcImageLayout_offsetof)+")",
    dstBuffer: "u64("+callof(V.VkCopyImageToBufferInfo2_dstBuffer_offsetof)+")",
    regionCount: "u32("+callof(V.VkCopyImageToBufferInfo2_regionCount_offsetof)+")",
    pRegions: "u64("+callof(V.VkCopyImageToBufferInfo2_pRegions_offsetof)+")",
}, callof(V.VkCopyImageToBufferInfo2_sizeof));


const VkCopyImageToBufferInfo2KHR = new C.CStruct("VkCopyImageToBufferInfo2KHR", {

}, callof(V.VkCopyImageToBufferInfo2KHR_sizeof));


const VkResolveImageInfo2 = new C.CStruct("VkResolveImageInfo2", {
    sType: "u32("+callof(V.VkResolveImageInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkResolveImageInfo2_pNext_offsetof)+")",
    srcImage: "u64("+callof(V.VkResolveImageInfo2_srcImage_offsetof)+")",
    srcImageLayout: "u32("+callof(V.VkResolveImageInfo2_srcImageLayout_offsetof)+")",
    dstImage: "u64("+callof(V.VkResolveImageInfo2_dstImage_offsetof)+")",
    dstImageLayout: "u32("+callof(V.VkResolveImageInfo2_dstImageLayout_offsetof)+")",
    regionCount: "u32("+callof(V.VkResolveImageInfo2_regionCount_offsetof)+")",
    pRegions: "u64("+callof(V.VkResolveImageInfo2_pRegions_offsetof)+")",
}, callof(V.VkResolveImageInfo2_sizeof));


const VkResolveImageInfo2KHR = new C.CStruct("VkResolveImageInfo2KHR", {

}, callof(V.VkResolveImageInfo2KHR_sizeof));


const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT = new C.CStruct("VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT_pNext_offsetof)+")",
    shaderImageInt64Atomics: "u32("+callof(V.VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT_shaderImageInt64Atomics_offsetof)+")",
    sparseImageInt64Atomics: "u32("+callof(V.VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT_sparseImageInt64Atomics_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT_sizeof));


const VkFragmentShadingRateAttachmentInfoKHR = new C.CStruct("VkFragmentShadingRateAttachmentInfoKHR", {
    sType: "u32("+callof(V.VkFragmentShadingRateAttachmentInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkFragmentShadingRateAttachmentInfoKHR_pNext_offsetof)+")",
    pFragmentShadingRateAttachment: "u64("+callof(V.VkFragmentShadingRateAttachmentInfoKHR_pFragmentShadingRateAttachment_offsetof)+")",
    shadingRateAttachmentTexelSize: "VkExtent2D("+callof(V.VkFragmentShadingRateAttachmentInfoKHR_shadingRateAttachmentTexelSize_offsetof)+")",
}, callof(V.VkFragmentShadingRateAttachmentInfoKHR_sizeof));


const VkPipelineFragmentShadingRateStateCreateInfoKHR = new C.CStruct("VkPipelineFragmentShadingRateStateCreateInfoKHR", {
    sType: "u32("+callof(V.VkPipelineFragmentShadingRateStateCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineFragmentShadingRateStateCreateInfoKHR_pNext_offsetof)+")",
    fragmentSize: "VkExtent2D("+callof(V.VkPipelineFragmentShadingRateStateCreateInfoKHR_fragmentSize_offsetof)+")",
    combinerOps: "u32[2]("+callof(V.VkPipelineFragmentShadingRateStateCreateInfoKHR_combinerOps_offsetof)+")",
}, callof(V.VkPipelineFragmentShadingRateStateCreateInfoKHR_sizeof));


const VkPhysicalDeviceFragmentShadingRateFeaturesKHR = new C.CStruct("VkPhysicalDeviceFragmentShadingRateFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRateFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentShadingRateFeaturesKHR_pNext_offsetof)+")",
    pipelineFragmentShadingRate: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRateFeaturesKHR_pipelineFragmentShadingRate_offsetof)+")",
    primitiveFragmentShadingRate: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRateFeaturesKHR_primitiveFragmentShadingRate_offsetof)+")",
    attachmentFragmentShadingRate: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRateFeaturesKHR_attachmentFragmentShadingRate_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentShadingRateFeaturesKHR_sizeof));


const VkPhysicalDeviceFragmentShadingRatePropertiesKHR = new C.CStruct("VkPhysicalDeviceFragmentShadingRatePropertiesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_pNext_offsetof)+")",
    minFragmentShadingRateAttachmentTexelSize: "VkExtent2D("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_minFragmentShadingRateAttachmentTexelSize_offsetof)+")",
    maxFragmentShadingRateAttachmentTexelSize: "VkExtent2D("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_maxFragmentShadingRateAttachmentTexelSize_offsetof)+")",
    maxFragmentShadingRateAttachmentTexelSizeAspectRatio: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_maxFragmentShadingRateAttachmentTexelSizeAspectRatio_offsetof)+")",
    primitiveFragmentShadingRateWithMultipleViewports: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_primitiveFragmentShadingRateWithMultipleViewports_offsetof)+")",
    layeredShadingRateAttachments: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_layeredShadingRateAttachments_offsetof)+")",
    fragmentShadingRateNonTrivialCombinerOps: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateNonTrivialCombinerOps_offsetof)+")",
    maxFragmentSize: "VkExtent2D("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_maxFragmentSize_offsetof)+")",
    maxFragmentSizeAspectRatio: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_maxFragmentSizeAspectRatio_offsetof)+")",
    maxFragmentShadingRateCoverageSamples: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_maxFragmentShadingRateCoverageSamples_offsetof)+")",
    maxFragmentShadingRateRasterizationSamples: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_maxFragmentShadingRateRasterizationSamples_offsetof)+")",
    fragmentShadingRateWithShaderDepthStencilWrites: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateWithShaderDepthStencilWrites_offsetof)+")",
    fragmentShadingRateWithSampleMask: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateWithSampleMask_offsetof)+")",
    fragmentShadingRateWithShaderSampleMask: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateWithShaderSampleMask_offsetof)+")",
    fragmentShadingRateWithConservativeRasterization: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateWithConservativeRasterization_offsetof)+")",
    fragmentShadingRateWithFragmentShaderInterlock: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateWithFragmentShaderInterlock_offsetof)+")",
    fragmentShadingRateWithCustomSampleLocations: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateWithCustomSampleLocations_offsetof)+")",
    fragmentShadingRateStrictMultiplyCombiner: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_fragmentShadingRateStrictMultiplyCombiner_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentShadingRatePropertiesKHR_sizeof));


const VkPhysicalDeviceFragmentShadingRateKHR = new C.CStruct("VkPhysicalDeviceFragmentShadingRateKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRateKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentShadingRateKHR_pNext_offsetof)+")",
    sampleCounts: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRateKHR_sampleCounts_offsetof)+")",
    fragmentSize: "VkExtent2D("+callof(V.VkPhysicalDeviceFragmentShadingRateKHR_fragmentSize_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentShadingRateKHR_sizeof));


const VkPhysicalDeviceShaderTerminateInvocationFeatures = new C.CStruct("VkPhysicalDeviceShaderTerminateInvocationFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderTerminateInvocationFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderTerminateInvocationFeatures_pNext_offsetof)+")",
    shaderTerminateInvocation: "u32("+callof(V.VkPhysicalDeviceShaderTerminateInvocationFeatures_shaderTerminateInvocation_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderTerminateInvocationFeatures_sizeof));


const VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR = new C.CStruct("VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR", {

}, callof(V.VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR_sizeof));


const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV = new C.CStruct("VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_pNext_offsetof)+")",
    fragmentShadingRateEnums: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_fragmentShadingRateEnums_offsetof)+")",
    supersampleFragmentShadingRates: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_supersampleFragmentShadingRates_offsetof)+")",
    noInvocationFragmentShadingRates: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_noInvocationFragmentShadingRates_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_sizeof));


const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV = new C.CStruct("VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV_pNext_offsetof)+")",
    maxFragmentShadingRateInvocationCount: "u32("+callof(V.VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV_maxFragmentShadingRateInvocationCount_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV_sizeof));


const VkPipelineFragmentShadingRateEnumStateCreateInfoNV = new C.CStruct("VkPipelineFragmentShadingRateEnumStateCreateInfoNV", {
    sType: "u32("+callof(V.VkPipelineFragmentShadingRateEnumStateCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineFragmentShadingRateEnumStateCreateInfoNV_pNext_offsetof)+")",
    shadingRateType: "u32("+callof(V.VkPipelineFragmentShadingRateEnumStateCreateInfoNV_shadingRateType_offsetof)+")",
    shadingRate: "u32("+callof(V.VkPipelineFragmentShadingRateEnumStateCreateInfoNV_shadingRate_offsetof)+")",
    combinerOps: "u32[2]("+callof(V.VkPipelineFragmentShadingRateEnumStateCreateInfoNV_combinerOps_offsetof)+")",
}, callof(V.VkPipelineFragmentShadingRateEnumStateCreateInfoNV_sizeof));


const VkAccelerationStructureBuildSizesInfoKHR = new C.CStruct("VkAccelerationStructureBuildSizesInfoKHR", {
    sType: "u32("+callof(V.VkAccelerationStructureBuildSizesInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureBuildSizesInfoKHR_pNext_offsetof)+")",
    accelerationStructureSize: "u64("+callof(V.VkAccelerationStructureBuildSizesInfoKHR_accelerationStructureSize_offsetof)+")",
    updateScratchSize: "u64("+callof(V.VkAccelerationStructureBuildSizesInfoKHR_updateScratchSize_offsetof)+")",
    buildScratchSize: "u64("+callof(V.VkAccelerationStructureBuildSizesInfoKHR_buildScratchSize_offsetof)+")",
}, callof(V.VkAccelerationStructureBuildSizesInfoKHR_sizeof));


const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT = new C.CStruct("VkPhysicalDeviceImage2DViewOf3DFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceImage2DViewOf3DFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceImage2DViewOf3DFeaturesEXT_pNext_offsetof)+")",
    image2DViewOf3D: "u32("+callof(V.VkPhysicalDeviceImage2DViewOf3DFeaturesEXT_image2DViewOf3D_offsetof)+")",
    sampler2DViewOf3D: "u32("+callof(V.VkPhysicalDeviceImage2DViewOf3DFeaturesEXT_sampler2DViewOf3D_offsetof)+")",
}, callof(V.VkPhysicalDeviceImage2DViewOf3DFeaturesEXT_sizeof));


const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT = new C.CStruct("VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT_pNext_offsetof)+")",
    mutableDescriptorType: "u32("+callof(V.VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT_mutableDescriptorType_offsetof)+")",
}, callof(V.VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT_sizeof));


const VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE = new C.CStruct("VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE", {

}, callof(V.VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE_sizeof));


const VkMutableDescriptorTypeListEXT = new C.CStruct("VkMutableDescriptorTypeListEXT", {
    descriptorTypeCount: "u32("+callof(V.VkMutableDescriptorTypeListEXT_descriptorTypeCount_offsetof)+")",
    pDescriptorTypes: "u64("+callof(V.VkMutableDescriptorTypeListEXT_pDescriptorTypes_offsetof)+")",
}, callof(V.VkMutableDescriptorTypeListEXT_sizeof));


const VkMutableDescriptorTypeListVALVE = new C.CStruct("VkMutableDescriptorTypeListVALVE", {

}, callof(V.VkMutableDescriptorTypeListVALVE_sizeof));


const VkMutableDescriptorTypeCreateInfoEXT = new C.CStruct("VkMutableDescriptorTypeCreateInfoEXT", {
    sType: "u32("+callof(V.VkMutableDescriptorTypeCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMutableDescriptorTypeCreateInfoEXT_pNext_offsetof)+")",
    mutableDescriptorTypeListCount: "u32("+callof(V.VkMutableDescriptorTypeCreateInfoEXT_mutableDescriptorTypeListCount_offsetof)+")",
    pMutableDescriptorTypeLists: "u64("+callof(V.VkMutableDescriptorTypeCreateInfoEXT_pMutableDescriptorTypeLists_offsetof)+")",
}, callof(V.VkMutableDescriptorTypeCreateInfoEXT_sizeof));


const VkMutableDescriptorTypeCreateInfoVALVE = new C.CStruct("VkMutableDescriptorTypeCreateInfoVALVE", {

}, callof(V.VkMutableDescriptorTypeCreateInfoVALVE_sizeof));


const VkPhysicalDeviceDepthClipControlFeaturesEXT = new C.CStruct("VkPhysicalDeviceDepthClipControlFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceDepthClipControlFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDepthClipControlFeaturesEXT_pNext_offsetof)+")",
    depthClipControl: "u32("+callof(V.VkPhysicalDeviceDepthClipControlFeaturesEXT_depthClipControl_offsetof)+")",
}, callof(V.VkPhysicalDeviceDepthClipControlFeaturesEXT_sizeof));


const VkPipelineViewportDepthClipControlCreateInfoEXT = new C.CStruct("VkPipelineViewportDepthClipControlCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineViewportDepthClipControlCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineViewportDepthClipControlCreateInfoEXT_pNext_offsetof)+")",
    negativeOneToOne: "u32("+callof(V.VkPipelineViewportDepthClipControlCreateInfoEXT_negativeOneToOne_offsetof)+")",
}, callof(V.VkPipelineViewportDepthClipControlCreateInfoEXT_sizeof));


const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT = new C.CStruct("VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT_pNext_offsetof)+")",
    vertexInputDynamicState: "u32("+callof(V.VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT_vertexInputDynamicState_offsetof)+")",
}, callof(V.VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT_sizeof));


const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV = new C.CStruct("VkPhysicalDeviceExternalMemoryRDMAFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceExternalMemoryRDMAFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceExternalMemoryRDMAFeaturesNV_pNext_offsetof)+")",
    externalMemoryRDMA: "u32("+callof(V.VkPhysicalDeviceExternalMemoryRDMAFeaturesNV_externalMemoryRDMA_offsetof)+")",
}, callof(V.VkPhysicalDeviceExternalMemoryRDMAFeaturesNV_sizeof));


const VkVertexInputBindingDescription2EXT = new C.CStruct("VkVertexInputBindingDescription2EXT", {
    sType: "u32("+callof(V.VkVertexInputBindingDescription2EXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVertexInputBindingDescription2EXT_pNext_offsetof)+")",
    binding: "u32("+callof(V.VkVertexInputBindingDescription2EXT_binding_offsetof)+")",
    stride: "u32("+callof(V.VkVertexInputBindingDescription2EXT_stride_offsetof)+")",
    inputRate: "u32("+callof(V.VkVertexInputBindingDescription2EXT_inputRate_offsetof)+")",
    divisor: "u32("+callof(V.VkVertexInputBindingDescription2EXT_divisor_offsetof)+")",
}, callof(V.VkVertexInputBindingDescription2EXT_sizeof));


const VkVertexInputAttributeDescription2EXT = new C.CStruct("VkVertexInputAttributeDescription2EXT", {
    sType: "u32("+callof(V.VkVertexInputAttributeDescription2EXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVertexInputAttributeDescription2EXT_pNext_offsetof)+")",
    location: "u32("+callof(V.VkVertexInputAttributeDescription2EXT_location_offsetof)+")",
    binding: "u32("+callof(V.VkVertexInputAttributeDescription2EXT_binding_offsetof)+")",
    format: "u32("+callof(V.VkVertexInputAttributeDescription2EXT_format_offsetof)+")",
    offset: "u32("+callof(V.VkVertexInputAttributeDescription2EXT_offset_offsetof)+")",
}, callof(V.VkVertexInputAttributeDescription2EXT_sizeof));


const VkPhysicalDeviceColorWriteEnableFeaturesEXT = new C.CStruct("VkPhysicalDeviceColorWriteEnableFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceColorWriteEnableFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceColorWriteEnableFeaturesEXT_pNext_offsetof)+")",
    colorWriteEnable: "u32("+callof(V.VkPhysicalDeviceColorWriteEnableFeaturesEXT_colorWriteEnable_offsetof)+")",
}, callof(V.VkPhysicalDeviceColorWriteEnableFeaturesEXT_sizeof));


const VkPipelineColorWriteCreateInfoEXT = new C.CStruct("VkPipelineColorWriteCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineColorWriteCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineColorWriteCreateInfoEXT_pNext_offsetof)+")",
    attachmentCount: "u32("+callof(V.VkPipelineColorWriteCreateInfoEXT_attachmentCount_offsetof)+")",
    pColorWriteEnables: "u64("+callof(V.VkPipelineColorWriteCreateInfoEXT_pColorWriteEnables_offsetof)+")",
}, callof(V.VkPipelineColorWriteCreateInfoEXT_sizeof));


const VkMemoryBarrier2 = new C.CStruct("VkMemoryBarrier2", {
    sType: "u32("+callof(V.VkMemoryBarrier2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryBarrier2_pNext_offsetof)+")",
    srcStageMask: "u64("+callof(V.VkMemoryBarrier2_srcStageMask_offsetof)+")",
    srcAccessMask: "u64("+callof(V.VkMemoryBarrier2_srcAccessMask_offsetof)+")",
    dstStageMask: "u64("+callof(V.VkMemoryBarrier2_dstStageMask_offsetof)+")",
    dstAccessMask: "u64("+callof(V.VkMemoryBarrier2_dstAccessMask_offsetof)+")",
}, callof(V.VkMemoryBarrier2_sizeof));


const VkMemoryBarrier2KHR = new C.CStruct("VkMemoryBarrier2KHR", {

}, callof(V.VkMemoryBarrier2KHR_sizeof));


const VkImageMemoryBarrier2 = new C.CStruct("VkImageMemoryBarrier2", {
    sType: "u32("+callof(V.VkImageMemoryBarrier2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageMemoryBarrier2_pNext_offsetof)+")",
    srcStageMask: "u64("+callof(V.VkImageMemoryBarrier2_srcStageMask_offsetof)+")",
    srcAccessMask: "u64("+callof(V.VkImageMemoryBarrier2_srcAccessMask_offsetof)+")",
    dstStageMask: "u64("+callof(V.VkImageMemoryBarrier2_dstStageMask_offsetof)+")",
    dstAccessMask: "u64("+callof(V.VkImageMemoryBarrier2_dstAccessMask_offsetof)+")",
    oldLayout: "u32("+callof(V.VkImageMemoryBarrier2_oldLayout_offsetof)+")",
    newLayout: "u32("+callof(V.VkImageMemoryBarrier2_newLayout_offsetof)+")",
    srcQueueFamilyIndex: "u32("+callof(V.VkImageMemoryBarrier2_srcQueueFamilyIndex_offsetof)+")",
    dstQueueFamilyIndex: "u32("+callof(V.VkImageMemoryBarrier2_dstQueueFamilyIndex_offsetof)+")",
    image: "u64("+callof(V.VkImageMemoryBarrier2_image_offsetof)+")",
    subresourceRange: "u32("+callof(V.VkImageMemoryBarrier2_subresourceRange_offsetof)+")",
}, callof(V.VkImageMemoryBarrier2_sizeof));


const VkImageMemoryBarrier2KHR = new C.CStruct("VkImageMemoryBarrier2KHR", {

}, callof(V.VkImageMemoryBarrier2KHR_sizeof));


const VkBufferMemoryBarrier2 = new C.CStruct("VkBufferMemoryBarrier2", {
    sType: "u32("+callof(V.VkBufferMemoryBarrier2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferMemoryBarrier2_pNext_offsetof)+")",
    srcStageMask: "u64("+callof(V.VkBufferMemoryBarrier2_srcStageMask_offsetof)+")",
    srcAccessMask: "u64("+callof(V.VkBufferMemoryBarrier2_srcAccessMask_offsetof)+")",
    dstStageMask: "u64("+callof(V.VkBufferMemoryBarrier2_dstStageMask_offsetof)+")",
    dstAccessMask: "u64("+callof(V.VkBufferMemoryBarrier2_dstAccessMask_offsetof)+")",
    srcQueueFamilyIndex: "u32("+callof(V.VkBufferMemoryBarrier2_srcQueueFamilyIndex_offsetof)+")",
    dstQueueFamilyIndex: "u32("+callof(V.VkBufferMemoryBarrier2_dstQueueFamilyIndex_offsetof)+")",
    buffer: "u64("+callof(V.VkBufferMemoryBarrier2_buffer_offsetof)+")",
    offset: "u64("+callof(V.VkBufferMemoryBarrier2_offset_offsetof)+")",
    size: "u64("+callof(V.VkBufferMemoryBarrier2_size_offsetof)+")",
}, callof(V.VkBufferMemoryBarrier2_sizeof));


const VkBufferMemoryBarrier2KHR = new C.CStruct("VkBufferMemoryBarrier2KHR", {

}, callof(V.VkBufferMemoryBarrier2KHR_sizeof));


const VkDependencyInfo = new C.CStruct("VkDependencyInfo", {
    sType: "u32("+callof(V.VkDependencyInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDependencyInfo_pNext_offsetof)+")",
    dependencyFlags: "u32("+callof(V.VkDependencyInfo_dependencyFlags_offsetof)+")",
    memoryBarrierCount: "u32("+callof(V.VkDependencyInfo_memoryBarrierCount_offsetof)+")",
    pMemoryBarriers: "u64("+callof(V.VkDependencyInfo_pMemoryBarriers_offsetof)+")",
    bufferMemoryBarrierCount: "u32("+callof(V.VkDependencyInfo_bufferMemoryBarrierCount_offsetof)+")",
    pBufferMemoryBarriers: "u64("+callof(V.VkDependencyInfo_pBufferMemoryBarriers_offsetof)+")",
    imageMemoryBarrierCount: "u32("+callof(V.VkDependencyInfo_imageMemoryBarrierCount_offsetof)+")",
    pImageMemoryBarriers: "u64("+callof(V.VkDependencyInfo_pImageMemoryBarriers_offsetof)+")",
}, callof(V.VkDependencyInfo_sizeof));


const VkDependencyInfoKHR = new C.CStruct("VkDependencyInfoKHR", {

}, callof(V.VkDependencyInfoKHR_sizeof));


const VkSemaphoreSubmitInfo = new C.CStruct("VkSemaphoreSubmitInfo", {
    sType: "u32("+callof(V.VkSemaphoreSubmitInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSemaphoreSubmitInfo_pNext_offsetof)+")",
    semaphore: "u64("+callof(V.VkSemaphoreSubmitInfo_semaphore_offsetof)+")",
    value: "u64("+callof(V.VkSemaphoreSubmitInfo_value_offsetof)+")",
    stageMask: "u64("+callof(V.VkSemaphoreSubmitInfo_stageMask_offsetof)+")",
    deviceIndex: "u32("+callof(V.VkSemaphoreSubmitInfo_deviceIndex_offsetof)+")",
}, callof(V.VkSemaphoreSubmitInfo_sizeof));


const VkSemaphoreSubmitInfoKHR = new C.CStruct("VkSemaphoreSubmitInfoKHR", {

}, callof(V.VkSemaphoreSubmitInfoKHR_sizeof));


const VkCommandBufferSubmitInfo = new C.CStruct("VkCommandBufferSubmitInfo", {
    sType: "u32("+callof(V.VkCommandBufferSubmitInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCommandBufferSubmitInfo_pNext_offsetof)+")",
    commandBuffer: "u64("+callof(V.VkCommandBufferSubmitInfo_commandBuffer_offsetof)+")",
    deviceMask: "u32("+callof(V.VkCommandBufferSubmitInfo_deviceMask_offsetof)+")",
}, callof(V.VkCommandBufferSubmitInfo_sizeof));


const VkCommandBufferSubmitInfoKHR = new C.CStruct("VkCommandBufferSubmitInfoKHR", {

}, callof(V.VkCommandBufferSubmitInfoKHR_sizeof));


const VkSubmitInfo2 = new C.CStruct("VkSubmitInfo2", {
    sType: "u32("+callof(V.VkSubmitInfo2_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSubmitInfo2_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkSubmitInfo2_flags_offsetof)+")",
    waitSemaphoreInfoCount: "u32("+callof(V.VkSubmitInfo2_waitSemaphoreInfoCount_offsetof)+")",
    pWaitSemaphoreInfos: "u64("+callof(V.VkSubmitInfo2_pWaitSemaphoreInfos_offsetof)+")",
    commandBufferInfoCount: "u32("+callof(V.VkSubmitInfo2_commandBufferInfoCount_offsetof)+")",
    pCommandBufferInfos: "u64("+callof(V.VkSubmitInfo2_pCommandBufferInfos_offsetof)+")",
    signalSemaphoreInfoCount: "u32("+callof(V.VkSubmitInfo2_signalSemaphoreInfoCount_offsetof)+")",
    pSignalSemaphoreInfos: "u64("+callof(V.VkSubmitInfo2_pSignalSemaphoreInfos_offsetof)+")",
}, callof(V.VkSubmitInfo2_sizeof));


const VkSubmitInfo2KHR = new C.CStruct("VkSubmitInfo2KHR", {

}, callof(V.VkSubmitInfo2KHR_sizeof));


const VkQueueFamilyCheckpointProperties2NV = new C.CStruct("VkQueueFamilyCheckpointProperties2NV", {
    sType: "u32("+callof(V.VkQueueFamilyCheckpointProperties2NV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkQueueFamilyCheckpointProperties2NV_pNext_offsetof)+")",
    checkpointExecutionStageMask: "u64("+callof(V.VkQueueFamilyCheckpointProperties2NV_checkpointExecutionStageMask_offsetof)+")",
}, callof(V.VkQueueFamilyCheckpointProperties2NV_sizeof));


const VkCheckpointData2NV = new C.CStruct("VkCheckpointData2NV", {
    sType: "u32("+callof(V.VkCheckpointData2NV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCheckpointData2NV_pNext_offsetof)+")",
    stage: "u64("+callof(V.VkCheckpointData2NV_stage_offsetof)+")",
    pCheckpointMarker: "u64("+callof(V.VkCheckpointData2NV_pCheckpointMarker_offsetof)+")",
}, callof(V.VkCheckpointData2NV_sizeof));


const VkPhysicalDeviceSynchronization2Features = new C.CStruct("VkPhysicalDeviceSynchronization2Features", {
    sType: "u32("+callof(V.VkPhysicalDeviceSynchronization2Features_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSynchronization2Features_pNext_offsetof)+")",
    synchronization2: "u32("+callof(V.VkPhysicalDeviceSynchronization2Features_synchronization2_offsetof)+")",
}, callof(V.VkPhysicalDeviceSynchronization2Features_sizeof));


const VkPhysicalDeviceSynchronization2FeaturesKHR = new C.CStruct("VkPhysicalDeviceSynchronization2FeaturesKHR", {

}, callof(V.VkPhysicalDeviceSynchronization2FeaturesKHR_sizeof));


const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT = new C.CStruct("VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_pNext_offsetof)+")",
    primitivesGeneratedQuery: "u32("+callof(V.VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_primitivesGeneratedQuery_offsetof)+")",
    primitivesGeneratedQueryWithRasterizerDiscard: "u32("+callof(V.VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_primitivesGeneratedQueryWithRasterizerDiscard_offsetof)+")",
    primitivesGeneratedQueryWithNonZeroStreams: "u32("+callof(V.VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_primitivesGeneratedQueryWithNonZeroStreams_offsetof)+")",
}, callof(V.VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_sizeof));


const VkPhysicalDeviceLegacyDitheringFeaturesEXT = new C.CStruct("VkPhysicalDeviceLegacyDitheringFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceLegacyDitheringFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceLegacyDitheringFeaturesEXT_pNext_offsetof)+")",
    legacyDithering: "u32("+callof(V.VkPhysicalDeviceLegacyDitheringFeaturesEXT_legacyDithering_offsetof)+")",
}, callof(V.VkPhysicalDeviceLegacyDitheringFeaturesEXT_sizeof));


const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT = new C.CStruct("VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT_pNext_offsetof)+")",
    multisampledRenderToSingleSampled: "u32("+callof(V.VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT_multisampledRenderToSingleSampled_offsetof)+")",
}, callof(V.VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT_sizeof));


const VkSubpassResolvePerformanceQueryEXT = new C.CStruct("VkSubpassResolvePerformanceQueryEXT", {
    sType: "u32("+callof(V.VkSubpassResolvePerformanceQueryEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSubpassResolvePerformanceQueryEXT_pNext_offsetof)+")",
    optimal: "u32("+callof(V.VkSubpassResolvePerformanceQueryEXT_optimal_offsetof)+")",
}, callof(V.VkSubpassResolvePerformanceQueryEXT_sizeof));


const VkMultisampledRenderToSingleSampledInfoEXT = new C.CStruct("VkMultisampledRenderToSingleSampledInfoEXT", {
    sType: "u32("+callof(V.VkMultisampledRenderToSingleSampledInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMultisampledRenderToSingleSampledInfoEXT_pNext_offsetof)+")",
    multisampledRenderToSingleSampledEnable: "u32("+callof(V.VkMultisampledRenderToSingleSampledInfoEXT_multisampledRenderToSingleSampledEnable_offsetof)+")",
    rasterizationSamples: "u32("+callof(V.VkMultisampledRenderToSingleSampledInfoEXT_rasterizationSamples_offsetof)+")",
}, callof(V.VkMultisampledRenderToSingleSampledInfoEXT_sizeof));


const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT = new C.CStruct("VkPhysicalDevicePipelineProtectedAccessFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDevicePipelineProtectedAccessFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePipelineProtectedAccessFeaturesEXT_pNext_offsetof)+")",
    pipelineProtectedAccess: "u32("+callof(V.VkPhysicalDevicePipelineProtectedAccessFeaturesEXT_pipelineProtectedAccess_offsetof)+")",
}, callof(V.VkPhysicalDevicePipelineProtectedAccessFeaturesEXT_sizeof));


const VkQueueFamilyVideoPropertiesKHR = new C.CStruct("VkQueueFamilyVideoPropertiesKHR", {
    sType: "u32("+callof(V.VkQueueFamilyVideoPropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkQueueFamilyVideoPropertiesKHR_pNext_offsetof)+")",
    videoCodecOperations: "u32("+callof(V.VkQueueFamilyVideoPropertiesKHR_videoCodecOperations_offsetof)+")",
}, callof(V.VkQueueFamilyVideoPropertiesKHR_sizeof));


const VkQueueFamilyQueryResultStatusPropertiesKHR = new C.CStruct("VkQueueFamilyQueryResultStatusPropertiesKHR", {
    sType: "u32("+callof(V.VkQueueFamilyQueryResultStatusPropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkQueueFamilyQueryResultStatusPropertiesKHR_pNext_offsetof)+")",
    queryResultStatusSupport: "u32("+callof(V.VkQueueFamilyQueryResultStatusPropertiesKHR_queryResultStatusSupport_offsetof)+")",
}, callof(V.VkQueueFamilyQueryResultStatusPropertiesKHR_sizeof));


const VkVideoProfileListInfoKHR = new C.CStruct("VkVideoProfileListInfoKHR", {
    sType: "u32("+callof(V.VkVideoProfileListInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoProfileListInfoKHR_pNext_offsetof)+")",
    profileCount: "u32("+callof(V.VkVideoProfileListInfoKHR_profileCount_offsetof)+")",
    pProfiles: "u64("+callof(V.VkVideoProfileListInfoKHR_pProfiles_offsetof)+")",
}, callof(V.VkVideoProfileListInfoKHR_sizeof));


const VkPhysicalDeviceVideoFormatInfoKHR = new C.CStruct("VkPhysicalDeviceVideoFormatInfoKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceVideoFormatInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceVideoFormatInfoKHR_pNext_offsetof)+")",
    imageUsage: "u32("+callof(V.VkPhysicalDeviceVideoFormatInfoKHR_imageUsage_offsetof)+")",
}, callof(V.VkPhysicalDeviceVideoFormatInfoKHR_sizeof));


const VkVideoFormatPropertiesKHR = new C.CStruct("VkVideoFormatPropertiesKHR", {
    sType: "u32("+callof(V.VkVideoFormatPropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoFormatPropertiesKHR_pNext_offsetof)+")",
    format: "u32("+callof(V.VkVideoFormatPropertiesKHR_format_offsetof)+")",
    componentMapping: "u32("+callof(V.VkVideoFormatPropertiesKHR_componentMapping_offsetof)+")",
    imageCreateFlags: "u32("+callof(V.VkVideoFormatPropertiesKHR_imageCreateFlags_offsetof)+")",
    imageType: "u32("+callof(V.VkVideoFormatPropertiesKHR_imageType_offsetof)+")",
    imageTiling: "u32("+callof(V.VkVideoFormatPropertiesKHR_imageTiling_offsetof)+")",
    imageUsageFlags: "u32("+callof(V.VkVideoFormatPropertiesKHR_imageUsageFlags_offsetof)+")",
}, callof(V.VkVideoFormatPropertiesKHR_sizeof));


const VkVideoProfileInfoKHR = new C.CStruct("VkVideoProfileInfoKHR", {
    sType: "u32("+callof(V.VkVideoProfileInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoProfileInfoKHR_pNext_offsetof)+")",
    videoCodecOperation: "u32("+callof(V.VkVideoProfileInfoKHR_videoCodecOperation_offsetof)+")",
    chromaSubsampling: "u32("+callof(V.VkVideoProfileInfoKHR_chromaSubsampling_offsetof)+")",
    lumaBitDepth: "u32("+callof(V.VkVideoProfileInfoKHR_lumaBitDepth_offsetof)+")",
    chromaBitDepth: "u32("+callof(V.VkVideoProfileInfoKHR_chromaBitDepth_offsetof)+")",
}, callof(V.VkVideoProfileInfoKHR_sizeof));


const VkVideoCapabilitiesKHR = new C.CStruct("VkVideoCapabilitiesKHR", {
    sType: "u32("+callof(V.VkVideoCapabilitiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoCapabilitiesKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkVideoCapabilitiesKHR_flags_offsetof)+")",
    minBitstreamBufferOffsetAlignment: "u64("+callof(V.VkVideoCapabilitiesKHR_minBitstreamBufferOffsetAlignment_offsetof)+")",
    minBitstreamBufferSizeAlignment: "u64("+callof(V.VkVideoCapabilitiesKHR_minBitstreamBufferSizeAlignment_offsetof)+")",
    pictureAccessGranularity: "VkExtent2D("+callof(V.VkVideoCapabilitiesKHR_pictureAccessGranularity_offsetof)+")",
    minCodedExtent: "VkExtent2D("+callof(V.VkVideoCapabilitiesKHR_minCodedExtent_offsetof)+")",
    maxCodedExtent: "VkExtent2D("+callof(V.VkVideoCapabilitiesKHR_maxCodedExtent_offsetof)+")",
    maxDpbSlots: "u32("+callof(V.VkVideoCapabilitiesKHR_maxDpbSlots_offsetof)+")",
    maxActiveReferencePictures: "u32("+callof(V.VkVideoCapabilitiesKHR_maxActiveReferencePictures_offsetof)+")",
    stdHeaderVersion: "u32("+callof(V.VkVideoCapabilitiesKHR_stdHeaderVersion_offsetof)+")",
}, callof(V.VkVideoCapabilitiesKHR_sizeof));


const VkVideoSessionMemoryRequirementsKHR = new C.CStruct("VkVideoSessionMemoryRequirementsKHR", {
    sType: "u32("+callof(V.VkVideoSessionMemoryRequirementsKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoSessionMemoryRequirementsKHR_pNext_offsetof)+")",
    memoryBindIndex: "u32("+callof(V.VkVideoSessionMemoryRequirementsKHR_memoryBindIndex_offsetof)+")",
    memoryRequirements: "u32("+callof(V.VkVideoSessionMemoryRequirementsKHR_memoryRequirements_offsetof)+")",
}, callof(V.VkVideoSessionMemoryRequirementsKHR_sizeof));


const VkBindVideoSessionMemoryInfoKHR = new C.CStruct("VkBindVideoSessionMemoryInfoKHR", {
    sType: "u32("+callof(V.VkBindVideoSessionMemoryInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBindVideoSessionMemoryInfoKHR_pNext_offsetof)+")",
    memoryBindIndex: "u32("+callof(V.VkBindVideoSessionMemoryInfoKHR_memoryBindIndex_offsetof)+")",
    memory: "u64("+callof(V.VkBindVideoSessionMemoryInfoKHR_memory_offsetof)+")",
    memoryOffset: "u64("+callof(V.VkBindVideoSessionMemoryInfoKHR_memoryOffset_offsetof)+")",
    memorySize: "u64("+callof(V.VkBindVideoSessionMemoryInfoKHR_memorySize_offsetof)+")",
}, callof(V.VkBindVideoSessionMemoryInfoKHR_sizeof));


const VkVideoPictureResourceInfoKHR = new C.CStruct("VkVideoPictureResourceInfoKHR", {
    sType: "u32("+callof(V.VkVideoPictureResourceInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoPictureResourceInfoKHR_pNext_offsetof)+")",
    codedOffset: "VkOffset2D("+callof(V.VkVideoPictureResourceInfoKHR_codedOffset_offsetof)+")",
    codedExtent: "VkExtent2D("+callof(V.VkVideoPictureResourceInfoKHR_codedExtent_offsetof)+")",
    baseArrayLayer: "u32("+callof(V.VkVideoPictureResourceInfoKHR_baseArrayLayer_offsetof)+")",
    imageViewBinding: "u32("+callof(V.VkVideoPictureResourceInfoKHR_imageViewBinding_offsetof)+")",
}, callof(V.VkVideoPictureResourceInfoKHR_sizeof));


const VkVideoReferenceSlotInfoKHR = new C.CStruct("VkVideoReferenceSlotInfoKHR", {
    sType: "u32("+callof(V.VkVideoReferenceSlotInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoReferenceSlotInfoKHR_pNext_offsetof)+")",
    slotIndex: "i32("+callof(V.VkVideoReferenceSlotInfoKHR_slotIndex_offsetof)+")",
    pPictureResource: "u64("+callof(V.VkVideoReferenceSlotInfoKHR_pPictureResource_offsetof)+")",
}, callof(V.VkVideoReferenceSlotInfoKHR_sizeof));


const VkVideoDecodeCapabilitiesKHR = new C.CStruct("VkVideoDecodeCapabilitiesKHR", {
    sType: "u32("+callof(V.VkVideoDecodeCapabilitiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeCapabilitiesKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkVideoDecodeCapabilitiesKHR_flags_offsetof)+")",
}, callof(V.VkVideoDecodeCapabilitiesKHR_sizeof));


const VkVideoDecodeUsageInfoKHR = new C.CStruct("VkVideoDecodeUsageInfoKHR", {
    sType: "u32("+callof(V.VkVideoDecodeUsageInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeUsageInfoKHR_pNext_offsetof)+")",
    videoUsageHints: "u32("+callof(V.VkVideoDecodeUsageInfoKHR_videoUsageHints_offsetof)+")",
}, callof(V.VkVideoDecodeUsageInfoKHR_sizeof));


const VkVideoDecodeInfoKHR = new C.CStruct("VkVideoDecodeInfoKHR", {
    sType: "u32("+callof(V.VkVideoDecodeInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkVideoDecodeInfoKHR_flags_offsetof)+")",
    srcBuffer: "u64("+callof(V.VkVideoDecodeInfoKHR_srcBuffer_offsetof)+")",
    srcBufferOffset: "u64("+callof(V.VkVideoDecodeInfoKHR_srcBufferOffset_offsetof)+")",
    srcBufferRange: "u64("+callof(V.VkVideoDecodeInfoKHR_srcBufferRange_offsetof)+")",
    dstPictureResource: "u32("+callof(V.VkVideoDecodeInfoKHR_dstPictureResource_offsetof)+")",
    pSetupReferenceSlot: "u64("+callof(V.VkVideoDecodeInfoKHR_pSetupReferenceSlot_offsetof)+")",
    referenceSlotCount: "u32("+callof(V.VkVideoDecodeInfoKHR_referenceSlotCount_offsetof)+")",
    pReferenceSlots: "u64("+callof(V.VkVideoDecodeInfoKHR_pReferenceSlots_offsetof)+")",
}, callof(V.VkVideoDecodeInfoKHR_sizeof));


const VkVideoDecodeH264ProfileInfoEXT = new C.CStruct("VkVideoDecodeH264ProfileInfoEXT", {
    sType: "u32("+callof(V.VkVideoDecodeH264ProfileInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeH264ProfileInfoEXT_pNext_offsetof)+")",
    stdProfileIdc: "u32("+callof(V.VkVideoDecodeH264ProfileInfoEXT_stdProfileIdc_offsetof)+")",
    pictureLayout: "u32("+callof(V.VkVideoDecodeH264ProfileInfoEXT_pictureLayout_offsetof)+")",
}, callof(V.VkVideoDecodeH264ProfileInfoEXT_sizeof));


const VkVideoDecodeH264CapabilitiesEXT = new C.CStruct("VkVideoDecodeH264CapabilitiesEXT", {
    sType: "u32("+callof(V.VkVideoDecodeH264CapabilitiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeH264CapabilitiesEXT_pNext_offsetof)+")",
    maxLevelIdc: "u32("+callof(V.VkVideoDecodeH264CapabilitiesEXT_maxLevelIdc_offsetof)+")",
    fieldOffsetGranularity: "VkOffset2D("+callof(V.VkVideoDecodeH264CapabilitiesEXT_fieldOffsetGranularity_offsetof)+")",
}, callof(V.VkVideoDecodeH264CapabilitiesEXT_sizeof));


const VkVideoDecodeH264SessionParametersAddInfoEXT = new C.CStruct("VkVideoDecodeH264SessionParametersAddInfoEXT", {
    sType: "u32("+callof(V.VkVideoDecodeH264SessionParametersAddInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeH264SessionParametersAddInfoEXT_pNext_offsetof)+")",
    stdSPSCount: "u32("+callof(V.VkVideoDecodeH264SessionParametersAddInfoEXT_stdSPSCount_offsetof)+")",
    pStdSPSs: "u64("+callof(V.VkVideoDecodeH264SessionParametersAddInfoEXT_pStdSPSs_offsetof)+")",
    stdPPSCount: "u32("+callof(V.VkVideoDecodeH264SessionParametersAddInfoEXT_stdPPSCount_offsetof)+")",
    pStdPPSs: "u64("+callof(V.VkVideoDecodeH264SessionParametersAddInfoEXT_pStdPPSs_offsetof)+")",
}, callof(V.VkVideoDecodeH264SessionParametersAddInfoEXT_sizeof));


const VkVideoDecodeH264SessionParametersCreateInfoEXT = new C.CStruct("VkVideoDecodeH264SessionParametersCreateInfoEXT", {
    sType: "u32("+callof(V.VkVideoDecodeH264SessionParametersCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeH264SessionParametersCreateInfoEXT_pNext_offsetof)+")",
    maxStdSPSCount: "u32("+callof(V.VkVideoDecodeH264SessionParametersCreateInfoEXT_maxStdSPSCount_offsetof)+")",
    maxStdPPSCount: "u32("+callof(V.VkVideoDecodeH264SessionParametersCreateInfoEXT_maxStdPPSCount_offsetof)+")",
    pParametersAddInfo: "u64("+callof(V.VkVideoDecodeH264SessionParametersCreateInfoEXT_pParametersAddInfo_offsetof)+")",
}, callof(V.VkVideoDecodeH264SessionParametersCreateInfoEXT_sizeof));


const VkVideoDecodeH264PictureInfoEXT = new C.CStruct("VkVideoDecodeH264PictureInfoEXT", {
    sType: "u32("+callof(V.VkVideoDecodeH264PictureInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeH264PictureInfoEXT_pNext_offsetof)+")",
    pStdPictureInfo: "u64("+callof(V.VkVideoDecodeH264PictureInfoEXT_pStdPictureInfo_offsetof)+")",
    sliceCount: "u32("+callof(V.VkVideoDecodeH264PictureInfoEXT_sliceCount_offsetof)+")",
    pSliceOffsets: "u64("+callof(V.VkVideoDecodeH264PictureInfoEXT_pSliceOffsets_offsetof)+")",
}, callof(V.VkVideoDecodeH264PictureInfoEXT_sizeof));


const VkVideoDecodeH264DpbSlotInfoEXT = new C.CStruct("VkVideoDecodeH264DpbSlotInfoEXT", {
    sType: "u32("+callof(V.VkVideoDecodeH264DpbSlotInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeH264DpbSlotInfoEXT_pNext_offsetof)+")",
    pStdReferenceInfo: "u64("+callof(V.VkVideoDecodeH264DpbSlotInfoEXT_pStdReferenceInfo_offsetof)+")",
}, callof(V.VkVideoDecodeH264DpbSlotInfoEXT_sizeof));


const VkVideoDecodeH265ProfileInfoEXT = new C.CStruct("VkVideoDecodeH265ProfileInfoEXT", {
    sType: "u32("+callof(V.VkVideoDecodeH265ProfileInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeH265ProfileInfoEXT_pNext_offsetof)+")",
    stdProfileIdc: "u32("+callof(V.VkVideoDecodeH265ProfileInfoEXT_stdProfileIdc_offsetof)+")",
}, callof(V.VkVideoDecodeH265ProfileInfoEXT_sizeof));


const VkVideoDecodeH265CapabilitiesEXT = new C.CStruct("VkVideoDecodeH265CapabilitiesEXT", {
    sType: "u32("+callof(V.VkVideoDecodeH265CapabilitiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeH265CapabilitiesEXT_pNext_offsetof)+")",
    maxLevelIdc: "u32("+callof(V.VkVideoDecodeH265CapabilitiesEXT_maxLevelIdc_offsetof)+")",
}, callof(V.VkVideoDecodeH265CapabilitiesEXT_sizeof));


const VkVideoDecodeH265SessionParametersAddInfoEXT = new C.CStruct("VkVideoDecodeH265SessionParametersAddInfoEXT", {
    sType: "u32("+callof(V.VkVideoDecodeH265SessionParametersAddInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeH265SessionParametersAddInfoEXT_pNext_offsetof)+")",
    stdVPSCount: "u32("+callof(V.VkVideoDecodeH265SessionParametersAddInfoEXT_stdVPSCount_offsetof)+")",
    pStdVPSs: "u64("+callof(V.VkVideoDecodeH265SessionParametersAddInfoEXT_pStdVPSs_offsetof)+")",
    stdSPSCount: "u32("+callof(V.VkVideoDecodeH265SessionParametersAddInfoEXT_stdSPSCount_offsetof)+")",
    pStdSPSs: "u64("+callof(V.VkVideoDecodeH265SessionParametersAddInfoEXT_pStdSPSs_offsetof)+")",
    stdPPSCount: "u32("+callof(V.VkVideoDecodeH265SessionParametersAddInfoEXT_stdPPSCount_offsetof)+")",
    pStdPPSs: "u64("+callof(V.VkVideoDecodeH265SessionParametersAddInfoEXT_pStdPPSs_offsetof)+")",
}, callof(V.VkVideoDecodeH265SessionParametersAddInfoEXT_sizeof));


const VkVideoDecodeH265SessionParametersCreateInfoEXT = new C.CStruct("VkVideoDecodeH265SessionParametersCreateInfoEXT", {
    sType: "u32("+callof(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_pNext_offsetof)+")",
    maxStdVPSCount: "u32("+callof(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_maxStdVPSCount_offsetof)+")",
    maxStdSPSCount: "u32("+callof(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_maxStdSPSCount_offsetof)+")",
    maxStdPPSCount: "u32("+callof(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_maxStdPPSCount_offsetof)+")",
    pParametersAddInfo: "u64("+callof(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_pParametersAddInfo_offsetof)+")",
}, callof(V.VkVideoDecodeH265SessionParametersCreateInfoEXT_sizeof));


const VkVideoDecodeH265PictureInfoEXT = new C.CStruct("VkVideoDecodeH265PictureInfoEXT", {
    sType: "u32("+callof(V.VkVideoDecodeH265PictureInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeH265PictureInfoEXT_pNext_offsetof)+")",
    pStdPictureInfo: "u64("+callof(V.VkVideoDecodeH265PictureInfoEXT_pStdPictureInfo_offsetof)+")",
    sliceCount: "u32("+callof(V.VkVideoDecodeH265PictureInfoEXT_sliceCount_offsetof)+")",
    pSliceOffsets: "u64("+callof(V.VkVideoDecodeH265PictureInfoEXT_pSliceOffsets_offsetof)+")",
}, callof(V.VkVideoDecodeH265PictureInfoEXT_sizeof));


const VkVideoDecodeH265DpbSlotInfoEXT = new C.CStruct("VkVideoDecodeH265DpbSlotInfoEXT", {
    sType: "u32("+callof(V.VkVideoDecodeH265DpbSlotInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoDecodeH265DpbSlotInfoEXT_pNext_offsetof)+")",
    pStdReferenceInfo: "u64("+callof(V.VkVideoDecodeH265DpbSlotInfoEXT_pStdReferenceInfo_offsetof)+")",
}, callof(V.VkVideoDecodeH265DpbSlotInfoEXT_sizeof));


const VkVideoSessionCreateInfoKHR = new C.CStruct("VkVideoSessionCreateInfoKHR", {
    sType: "u32("+callof(V.VkVideoSessionCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoSessionCreateInfoKHR_pNext_offsetof)+")",
    queueFamilyIndex: "u32("+callof(V.VkVideoSessionCreateInfoKHR_queueFamilyIndex_offsetof)+")",
    flags: "u32("+callof(V.VkVideoSessionCreateInfoKHR_flags_offsetof)+")",
    pVideoProfile: "u64("+callof(V.VkVideoSessionCreateInfoKHR_pVideoProfile_offsetof)+")",
    pictureFormat: "u32("+callof(V.VkVideoSessionCreateInfoKHR_pictureFormat_offsetof)+")",
    maxCodedExtent: "VkExtent2D("+callof(V.VkVideoSessionCreateInfoKHR_maxCodedExtent_offsetof)+")",
    referencePictureFormat: "u32("+callof(V.VkVideoSessionCreateInfoKHR_referencePictureFormat_offsetof)+")",
    maxDpbSlots: "u32("+callof(V.VkVideoSessionCreateInfoKHR_maxDpbSlots_offsetof)+")",
    maxActiveReferencePictures: "u32("+callof(V.VkVideoSessionCreateInfoKHR_maxActiveReferencePictures_offsetof)+")",
    pStdHeaderVersion: "u64("+callof(V.VkVideoSessionCreateInfoKHR_pStdHeaderVersion_offsetof)+")",
}, callof(V.VkVideoSessionCreateInfoKHR_sizeof));


const VkVideoSessionParametersCreateInfoKHR = new C.CStruct("VkVideoSessionParametersCreateInfoKHR", {
    sType: "u32("+callof(V.VkVideoSessionParametersCreateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoSessionParametersCreateInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkVideoSessionParametersCreateInfoKHR_flags_offsetof)+")",
    videoSessionParametersTemplate: "u32("+callof(V.VkVideoSessionParametersCreateInfoKHR_videoSessionParametersTemplate_offsetof)+")",
    videoSession: "u32("+callof(V.VkVideoSessionParametersCreateInfoKHR_videoSession_offsetof)+")",
}, callof(V.VkVideoSessionParametersCreateInfoKHR_sizeof));


const VkVideoSessionParametersUpdateInfoKHR = new C.CStruct("VkVideoSessionParametersUpdateInfoKHR", {
    sType: "u32("+callof(V.VkVideoSessionParametersUpdateInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoSessionParametersUpdateInfoKHR_pNext_offsetof)+")",
    updateSequenceCount: "u32("+callof(V.VkVideoSessionParametersUpdateInfoKHR_updateSequenceCount_offsetof)+")",
}, callof(V.VkVideoSessionParametersUpdateInfoKHR_sizeof));


const VkVideoBeginCodingInfoKHR = new C.CStruct("VkVideoBeginCodingInfoKHR", {
    sType: "u32("+callof(V.VkVideoBeginCodingInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoBeginCodingInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkVideoBeginCodingInfoKHR_flags_offsetof)+")",
    videoSession: "u32("+callof(V.VkVideoBeginCodingInfoKHR_videoSession_offsetof)+")",
    videoSessionParameters: "u32("+callof(V.VkVideoBeginCodingInfoKHR_videoSessionParameters_offsetof)+")",
    referenceSlotCount: "u32("+callof(V.VkVideoBeginCodingInfoKHR_referenceSlotCount_offsetof)+")",
    pReferenceSlots: "u64("+callof(V.VkVideoBeginCodingInfoKHR_pReferenceSlots_offsetof)+")",
}, callof(V.VkVideoBeginCodingInfoKHR_sizeof));


const VkVideoEndCodingInfoKHR = new C.CStruct("VkVideoEndCodingInfoKHR", {
    sType: "u32("+callof(V.VkVideoEndCodingInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEndCodingInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkVideoEndCodingInfoKHR_flags_offsetof)+")",
}, callof(V.VkVideoEndCodingInfoKHR_sizeof));


const VkVideoCodingControlInfoKHR = new C.CStruct("VkVideoCodingControlInfoKHR", {
    sType: "u32("+callof(V.VkVideoCodingControlInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoCodingControlInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkVideoCodingControlInfoKHR_flags_offsetof)+")",
}, callof(V.VkVideoCodingControlInfoKHR_sizeof));


const VkVideoEncodeUsageInfoKHR = new C.CStruct("VkVideoEncodeUsageInfoKHR", {
    sType: "u32("+callof(V.VkVideoEncodeUsageInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeUsageInfoKHR_pNext_offsetof)+")",
    videoUsageHints: "u32("+callof(V.VkVideoEncodeUsageInfoKHR_videoUsageHints_offsetof)+")",
    videoContentHints: "u32("+callof(V.VkVideoEncodeUsageInfoKHR_videoContentHints_offsetof)+")",
    tuningMode: "u32("+callof(V.VkVideoEncodeUsageInfoKHR_tuningMode_offsetof)+")",
}, callof(V.VkVideoEncodeUsageInfoKHR_sizeof));


const VkVideoEncodeInfoKHR = new C.CStruct("VkVideoEncodeInfoKHR", {
    sType: "u32("+callof(V.VkVideoEncodeInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkVideoEncodeInfoKHR_flags_offsetof)+")",
    qualityLevel: "u32("+callof(V.VkVideoEncodeInfoKHR_qualityLevel_offsetof)+")",
    dstBitstreamBuffer: "u64("+callof(V.VkVideoEncodeInfoKHR_dstBitstreamBuffer_offsetof)+")",
    dstBitstreamBufferOffset: "u64("+callof(V.VkVideoEncodeInfoKHR_dstBitstreamBufferOffset_offsetof)+")",
    dstBitstreamBufferMaxRange: "u64("+callof(V.VkVideoEncodeInfoKHR_dstBitstreamBufferMaxRange_offsetof)+")",
    srcPictureResource: "u32("+callof(V.VkVideoEncodeInfoKHR_srcPictureResource_offsetof)+")",
    pSetupReferenceSlot: "u64("+callof(V.VkVideoEncodeInfoKHR_pSetupReferenceSlot_offsetof)+")",
    referenceSlotCount: "u32("+callof(V.VkVideoEncodeInfoKHR_referenceSlotCount_offsetof)+")",
    pReferenceSlots: "u64("+callof(V.VkVideoEncodeInfoKHR_pReferenceSlots_offsetof)+")",
    precedingExternallyEncodedBytes: "u32("+callof(V.VkVideoEncodeInfoKHR_precedingExternallyEncodedBytes_offsetof)+")",
}, callof(V.VkVideoEncodeInfoKHR_sizeof));


const VkVideoEncodeRateControlInfoKHR = new C.CStruct("VkVideoEncodeRateControlInfoKHR", {
    sType: "u32("+callof(V.VkVideoEncodeRateControlInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeRateControlInfoKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkVideoEncodeRateControlInfoKHR_flags_offsetof)+")",
    rateControlMode: "u32("+callof(V.VkVideoEncodeRateControlInfoKHR_rateControlMode_offsetof)+")",
    layerCount: "u8("+callof(V.VkVideoEncodeRateControlInfoKHR_layerCount_offsetof)+")",
    pLayerConfigs: "u64("+callof(V.VkVideoEncodeRateControlInfoKHR_pLayerConfigs_offsetof)+")",
}, callof(V.VkVideoEncodeRateControlInfoKHR_sizeof));


const VkVideoEncodeRateControlLayerInfoKHR = new C.CStruct("VkVideoEncodeRateControlLayerInfoKHR", {
    sType: "u32("+callof(V.VkVideoEncodeRateControlLayerInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeRateControlLayerInfoKHR_pNext_offsetof)+")",
    averageBitrate: "u32("+callof(V.VkVideoEncodeRateControlLayerInfoKHR_averageBitrate_offsetof)+")",
    maxBitrate: "u32("+callof(V.VkVideoEncodeRateControlLayerInfoKHR_maxBitrate_offsetof)+")",
    frameRateNumerator: "u32("+callof(V.VkVideoEncodeRateControlLayerInfoKHR_frameRateNumerator_offsetof)+")",
    frameRateDenominator: "u32("+callof(V.VkVideoEncodeRateControlLayerInfoKHR_frameRateDenominator_offsetof)+")",
    virtualBufferSizeInMs: "u32("+callof(V.VkVideoEncodeRateControlLayerInfoKHR_virtualBufferSizeInMs_offsetof)+")",
    initialVirtualBufferSizeInMs: "u32("+callof(V.VkVideoEncodeRateControlLayerInfoKHR_initialVirtualBufferSizeInMs_offsetof)+")",
}, callof(V.VkVideoEncodeRateControlLayerInfoKHR_sizeof));


const VkVideoEncodeCapabilitiesKHR = new C.CStruct("VkVideoEncodeCapabilitiesKHR", {
    sType: "u32("+callof(V.VkVideoEncodeCapabilitiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeCapabilitiesKHR_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkVideoEncodeCapabilitiesKHR_flags_offsetof)+")",
    rateControlModes: "u32("+callof(V.VkVideoEncodeCapabilitiesKHR_rateControlModes_offsetof)+")",
    rateControlLayerCount: "u8("+callof(V.VkVideoEncodeCapabilitiesKHR_rateControlLayerCount_offsetof)+")",
    qualityLevelCount: "u8("+callof(V.VkVideoEncodeCapabilitiesKHR_qualityLevelCount_offsetof)+")",
    inputImageDataFillAlignment: "VkExtent2D("+callof(V.VkVideoEncodeCapabilitiesKHR_inputImageDataFillAlignment_offsetof)+")",
}, callof(V.VkVideoEncodeCapabilitiesKHR_sizeof));


const VkVideoEncodeH264CapabilitiesEXT = new C.CStruct("VkVideoEncodeH264CapabilitiesEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH264CapabilitiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH264CapabilitiesEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkVideoEncodeH264CapabilitiesEXT_flags_offsetof)+")",
    inputModeFlags: "u32("+callof(V.VkVideoEncodeH264CapabilitiesEXT_inputModeFlags_offsetof)+")",
    outputModeFlags: "u32("+callof(V.VkVideoEncodeH264CapabilitiesEXT_outputModeFlags_offsetof)+")",
    maxPPictureL0ReferenceCount: "u8("+callof(V.VkVideoEncodeH264CapabilitiesEXT_maxPPictureL0ReferenceCount_offsetof)+")",
    maxBPictureL0ReferenceCount: "u8("+callof(V.VkVideoEncodeH264CapabilitiesEXT_maxBPictureL0ReferenceCount_offsetof)+")",
    maxL1ReferenceCount: "u8("+callof(V.VkVideoEncodeH264CapabilitiesEXT_maxL1ReferenceCount_offsetof)+")",
    motionVectorsOverPicBoundariesFlag: "u32("+callof(V.VkVideoEncodeH264CapabilitiesEXT_motionVectorsOverPicBoundariesFlag_offsetof)+")",
    maxBytesPerPicDenom: "u32("+callof(V.VkVideoEncodeH264CapabilitiesEXT_maxBytesPerPicDenom_offsetof)+")",
    maxBitsPerMbDenom: "u32("+callof(V.VkVideoEncodeH264CapabilitiesEXT_maxBitsPerMbDenom_offsetof)+")",
    log2MaxMvLengthHorizontal: "u32("+callof(V.VkVideoEncodeH264CapabilitiesEXT_log2MaxMvLengthHorizontal_offsetof)+")",
    log2MaxMvLengthVertical: "u32("+callof(V.VkVideoEncodeH264CapabilitiesEXT_log2MaxMvLengthVertical_offsetof)+")",
}, callof(V.VkVideoEncodeH264CapabilitiesEXT_sizeof));


const VkVideoEncodeH264SessionParametersAddInfoEXT = new C.CStruct("VkVideoEncodeH264SessionParametersAddInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH264SessionParametersAddInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH264SessionParametersAddInfoEXT_pNext_offsetof)+")",
    stdSPSCount: "u32("+callof(V.VkVideoEncodeH264SessionParametersAddInfoEXT_stdSPSCount_offsetof)+")",
    pStdSPSs: "u64("+callof(V.VkVideoEncodeH264SessionParametersAddInfoEXT_pStdSPSs_offsetof)+")",
    stdPPSCount: "u32("+callof(V.VkVideoEncodeH264SessionParametersAddInfoEXT_stdPPSCount_offsetof)+")",
    pStdPPSs: "u64("+callof(V.VkVideoEncodeH264SessionParametersAddInfoEXT_pStdPPSs_offsetof)+")",
}, callof(V.VkVideoEncodeH264SessionParametersAddInfoEXT_sizeof));


const VkVideoEncodeH264SessionParametersCreateInfoEXT = new C.CStruct("VkVideoEncodeH264SessionParametersCreateInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH264SessionParametersCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH264SessionParametersCreateInfoEXT_pNext_offsetof)+")",
    maxStdSPSCount: "u32("+callof(V.VkVideoEncodeH264SessionParametersCreateInfoEXT_maxStdSPSCount_offsetof)+")",
    maxStdPPSCount: "u32("+callof(V.VkVideoEncodeH264SessionParametersCreateInfoEXT_maxStdPPSCount_offsetof)+")",
    pParametersAddInfo: "u64("+callof(V.VkVideoEncodeH264SessionParametersCreateInfoEXT_pParametersAddInfo_offsetof)+")",
}, callof(V.VkVideoEncodeH264SessionParametersCreateInfoEXT_sizeof));


const VkVideoEncodeH264DpbSlotInfoEXT = new C.CStruct("VkVideoEncodeH264DpbSlotInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH264DpbSlotInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH264DpbSlotInfoEXT_pNext_offsetof)+")",
    slotIndex: "i8("+callof(V.VkVideoEncodeH264DpbSlotInfoEXT_slotIndex_offsetof)+")",
    pStdReferenceInfo: "u64("+callof(V.VkVideoEncodeH264DpbSlotInfoEXT_pStdReferenceInfo_offsetof)+")",
}, callof(V.VkVideoEncodeH264DpbSlotInfoEXT_sizeof));


const VkVideoEncodeH264VclFrameInfoEXT = new C.CStruct("VkVideoEncodeH264VclFrameInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH264VclFrameInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH264VclFrameInfoEXT_pNext_offsetof)+")",
    pReferenceFinalLists: "u64("+callof(V.VkVideoEncodeH264VclFrameInfoEXT_pReferenceFinalLists_offsetof)+")",
    naluSliceEntryCount: "u32("+callof(V.VkVideoEncodeH264VclFrameInfoEXT_naluSliceEntryCount_offsetof)+")",
    pNaluSliceEntries: "u64("+callof(V.VkVideoEncodeH264VclFrameInfoEXT_pNaluSliceEntries_offsetof)+")",
    pCurrentPictureInfo: "u64("+callof(V.VkVideoEncodeH264VclFrameInfoEXT_pCurrentPictureInfo_offsetof)+")",
}, callof(V.VkVideoEncodeH264VclFrameInfoEXT_sizeof));


const VkVideoEncodeH264ReferenceListsInfoEXT = new C.CStruct("VkVideoEncodeH264ReferenceListsInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH264ReferenceListsInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH264ReferenceListsInfoEXT_pNext_offsetof)+")",
    referenceList0EntryCount: "u8("+callof(V.VkVideoEncodeH264ReferenceListsInfoEXT_referenceList0EntryCount_offsetof)+")",
    pReferenceList0Entries: "u64("+callof(V.VkVideoEncodeH264ReferenceListsInfoEXT_pReferenceList0Entries_offsetof)+")",
    referenceList1EntryCount: "u8("+callof(V.VkVideoEncodeH264ReferenceListsInfoEXT_referenceList1EntryCount_offsetof)+")",
    pReferenceList1Entries: "u64("+callof(V.VkVideoEncodeH264ReferenceListsInfoEXT_pReferenceList1Entries_offsetof)+")",
    pMemMgmtCtrlOperations: "u64("+callof(V.VkVideoEncodeH264ReferenceListsInfoEXT_pMemMgmtCtrlOperations_offsetof)+")",
}, callof(V.VkVideoEncodeH264ReferenceListsInfoEXT_sizeof));


const VkVideoEncodeH264EmitPictureParametersInfoEXT = new C.CStruct("VkVideoEncodeH264EmitPictureParametersInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_pNext_offsetof)+")",
    spsId: "u8("+callof(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_spsId_offsetof)+")",
    emitSpsEnable: "u32("+callof(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_emitSpsEnable_offsetof)+")",
    ppsIdEntryCount: "u32("+callof(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_ppsIdEntryCount_offsetof)+")",
    ppsIdEntries: "u64("+callof(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_ppsIdEntries_offsetof)+")",
}, callof(V.VkVideoEncodeH264EmitPictureParametersInfoEXT_sizeof));


const VkVideoEncodeH264ProfileInfoEXT = new C.CStruct("VkVideoEncodeH264ProfileInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH264ProfileInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH264ProfileInfoEXT_pNext_offsetof)+")",
    stdProfileIdc: "u32("+callof(V.VkVideoEncodeH264ProfileInfoEXT_stdProfileIdc_offsetof)+")",
}, callof(V.VkVideoEncodeH264ProfileInfoEXT_sizeof));


const VkVideoEncodeH264NaluSliceInfoEXT = new C.CStruct("VkVideoEncodeH264NaluSliceInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH264NaluSliceInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH264NaluSliceInfoEXT_pNext_offsetof)+")",
    mbCount: "u32("+callof(V.VkVideoEncodeH264NaluSliceInfoEXT_mbCount_offsetof)+")",
    pReferenceFinalLists: "u64("+callof(V.VkVideoEncodeH264NaluSliceInfoEXT_pReferenceFinalLists_offsetof)+")",
    pSliceHeaderStd: "u64("+callof(V.VkVideoEncodeH264NaluSliceInfoEXT_pSliceHeaderStd_offsetof)+")",
}, callof(V.VkVideoEncodeH264NaluSliceInfoEXT_sizeof));


const VkVideoEncodeH264RateControlInfoEXT = new C.CStruct("VkVideoEncodeH264RateControlInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH264RateControlInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH264RateControlInfoEXT_pNext_offsetof)+")",
    gopFrameCount: "u32("+callof(V.VkVideoEncodeH264RateControlInfoEXT_gopFrameCount_offsetof)+")",
    idrPeriod: "u32("+callof(V.VkVideoEncodeH264RateControlInfoEXT_idrPeriod_offsetof)+")",
    consecutiveBFrameCount: "u32("+callof(V.VkVideoEncodeH264RateControlInfoEXT_consecutiveBFrameCount_offsetof)+")",
    rateControlStructure: "u32("+callof(V.VkVideoEncodeH264RateControlInfoEXT_rateControlStructure_offsetof)+")",
    temporalLayerCount: "u8("+callof(V.VkVideoEncodeH264RateControlInfoEXT_temporalLayerCount_offsetof)+")",
}, callof(V.VkVideoEncodeH264RateControlInfoEXT_sizeof));


const VkVideoEncodeH264QpEXT = new C.CStruct("VkVideoEncodeH264QpEXT", {
    qpI: "i32("+callof(V.VkVideoEncodeH264QpEXT_qpI_offsetof)+")",
    qpP: "i32("+callof(V.VkVideoEncodeH264QpEXT_qpP_offsetof)+")",
    qpB: "i32("+callof(V.VkVideoEncodeH264QpEXT_qpB_offsetof)+")",
}, callof(V.VkVideoEncodeH264QpEXT_sizeof));


const VkVideoEncodeH264FrameSizeEXT = new C.CStruct("VkVideoEncodeH264FrameSizeEXT", {
    frameISize: "u32("+callof(V.VkVideoEncodeH264FrameSizeEXT_frameISize_offsetof)+")",
    framePSize: "u32("+callof(V.VkVideoEncodeH264FrameSizeEXT_framePSize_offsetof)+")",
    frameBSize: "u32("+callof(V.VkVideoEncodeH264FrameSizeEXT_frameBSize_offsetof)+")",
}, callof(V.VkVideoEncodeH264FrameSizeEXT_sizeof));


const VkVideoEncodeH264RateControlLayerInfoEXT = new C.CStruct("VkVideoEncodeH264RateControlLayerInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH264RateControlLayerInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH264RateControlLayerInfoEXT_pNext_offsetof)+")",
    temporalLayerId: "u8("+callof(V.VkVideoEncodeH264RateControlLayerInfoEXT_temporalLayerId_offsetof)+")",
    useInitialRcQp: "u32("+callof(V.VkVideoEncodeH264RateControlLayerInfoEXT_useInitialRcQp_offsetof)+")",
    initialRcQp: "u32("+callof(V.VkVideoEncodeH264RateControlLayerInfoEXT_initialRcQp_offsetof)+")",
    useMinQp: "u32("+callof(V.VkVideoEncodeH264RateControlLayerInfoEXT_useMinQp_offsetof)+")",
    minQp: "u32("+callof(V.VkVideoEncodeH264RateControlLayerInfoEXT_minQp_offsetof)+")",
    useMaxQp: "u32("+callof(V.VkVideoEncodeH264RateControlLayerInfoEXT_useMaxQp_offsetof)+")",
    maxQp: "u32("+callof(V.VkVideoEncodeH264RateControlLayerInfoEXT_maxQp_offsetof)+")",
    useMaxFrameSize: "u32("+callof(V.VkVideoEncodeH264RateControlLayerInfoEXT_useMaxFrameSize_offsetof)+")",
    maxFrameSize: "u32("+callof(V.VkVideoEncodeH264RateControlLayerInfoEXT_maxFrameSize_offsetof)+")",
}, callof(V.VkVideoEncodeH264RateControlLayerInfoEXT_sizeof));


const VkVideoEncodeH265CapabilitiesEXT = new C.CStruct("VkVideoEncodeH265CapabilitiesEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH265CapabilitiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH265CapabilitiesEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkVideoEncodeH265CapabilitiesEXT_flags_offsetof)+")",
    inputModeFlags: "u32("+callof(V.VkVideoEncodeH265CapabilitiesEXT_inputModeFlags_offsetof)+")",
    outputModeFlags: "u32("+callof(V.VkVideoEncodeH265CapabilitiesEXT_outputModeFlags_offsetof)+")",
    ctbSizes: "u32("+callof(V.VkVideoEncodeH265CapabilitiesEXT_ctbSizes_offsetof)+")",
    transformBlockSizes: "u32("+callof(V.VkVideoEncodeH265CapabilitiesEXT_transformBlockSizes_offsetof)+")",
    maxPPictureL0ReferenceCount: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_maxPPictureL0ReferenceCount_offsetof)+")",
    maxBPictureL0ReferenceCount: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_maxBPictureL0ReferenceCount_offsetof)+")",
    maxL1ReferenceCount: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_maxL1ReferenceCount_offsetof)+")",
    maxSubLayersCount: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_maxSubLayersCount_offsetof)+")",
    minLog2MinLumaCodingBlockSizeMinus3: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_minLog2MinLumaCodingBlockSizeMinus3_offsetof)+")",
    maxLog2MinLumaCodingBlockSizeMinus3: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_maxLog2MinLumaCodingBlockSizeMinus3_offsetof)+")",
    minLog2MinLumaTransformBlockSizeMinus2: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_minLog2MinLumaTransformBlockSizeMinus2_offsetof)+")",
    maxLog2MinLumaTransformBlockSizeMinus2: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_maxLog2MinLumaTransformBlockSizeMinus2_offsetof)+")",
    minMaxTransformHierarchyDepthInter: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_minMaxTransformHierarchyDepthInter_offsetof)+")",
    maxMaxTransformHierarchyDepthInter: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_maxMaxTransformHierarchyDepthInter_offsetof)+")",
    minMaxTransformHierarchyDepthIntra: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_minMaxTransformHierarchyDepthIntra_offsetof)+")",
    maxMaxTransformHierarchyDepthIntra: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_maxMaxTransformHierarchyDepthIntra_offsetof)+")",
    maxDiffCuQpDeltaDepth: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_maxDiffCuQpDeltaDepth_offsetof)+")",
    minMaxNumMergeCand: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_minMaxNumMergeCand_offsetof)+")",
    maxMaxNumMergeCand: "u8("+callof(V.VkVideoEncodeH265CapabilitiesEXT_maxMaxNumMergeCand_offsetof)+")",
}, callof(V.VkVideoEncodeH265CapabilitiesEXT_sizeof));


const VkVideoEncodeH265SessionParametersAddInfoEXT = new C.CStruct("VkVideoEncodeH265SessionParametersAddInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH265SessionParametersAddInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH265SessionParametersAddInfoEXT_pNext_offsetof)+")",
    stdVPSCount: "u32("+callof(V.VkVideoEncodeH265SessionParametersAddInfoEXT_stdVPSCount_offsetof)+")",
    pStdVPSs: "u64("+callof(V.VkVideoEncodeH265SessionParametersAddInfoEXT_pStdVPSs_offsetof)+")",
    stdSPSCount: "u32("+callof(V.VkVideoEncodeH265SessionParametersAddInfoEXT_stdSPSCount_offsetof)+")",
    pStdSPSs: "u64("+callof(V.VkVideoEncodeH265SessionParametersAddInfoEXT_pStdSPSs_offsetof)+")",
    stdPPSCount: "u32("+callof(V.VkVideoEncodeH265SessionParametersAddInfoEXT_stdPPSCount_offsetof)+")",
    pStdPPSs: "u64("+callof(V.VkVideoEncodeH265SessionParametersAddInfoEXT_pStdPPSs_offsetof)+")",
}, callof(V.VkVideoEncodeH265SessionParametersAddInfoEXT_sizeof));


const VkVideoEncodeH265SessionParametersCreateInfoEXT = new C.CStruct("VkVideoEncodeH265SessionParametersCreateInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_pNext_offsetof)+")",
    maxStdVPSCount: "u32("+callof(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_maxStdVPSCount_offsetof)+")",
    maxStdSPSCount: "u32("+callof(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_maxStdSPSCount_offsetof)+")",
    maxStdPPSCount: "u32("+callof(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_maxStdPPSCount_offsetof)+")",
    pParametersAddInfo: "u64("+callof(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_pParametersAddInfo_offsetof)+")",
}, callof(V.VkVideoEncodeH265SessionParametersCreateInfoEXT_sizeof));


const VkVideoEncodeH265VclFrameInfoEXT = new C.CStruct("VkVideoEncodeH265VclFrameInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH265VclFrameInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH265VclFrameInfoEXT_pNext_offsetof)+")",
    pReferenceFinalLists: "u64("+callof(V.VkVideoEncodeH265VclFrameInfoEXT_pReferenceFinalLists_offsetof)+")",
    naluSliceSegmentEntryCount: "u32("+callof(V.VkVideoEncodeH265VclFrameInfoEXT_naluSliceSegmentEntryCount_offsetof)+")",
    pNaluSliceSegmentEntries: "u64("+callof(V.VkVideoEncodeH265VclFrameInfoEXT_pNaluSliceSegmentEntries_offsetof)+")",
    pCurrentPictureInfo: "u64("+callof(V.VkVideoEncodeH265VclFrameInfoEXT_pCurrentPictureInfo_offsetof)+")",
}, callof(V.VkVideoEncodeH265VclFrameInfoEXT_sizeof));


const VkVideoEncodeH265EmitPictureParametersInfoEXT = new C.CStruct("VkVideoEncodeH265EmitPictureParametersInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_pNext_offsetof)+")",
    vpsId: "u8("+callof(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_vpsId_offsetof)+")",
    spsId: "u8("+callof(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_spsId_offsetof)+")",
    emitVpsEnable: "u32("+callof(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_emitVpsEnable_offsetof)+")",
    emitSpsEnable: "u32("+callof(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_emitSpsEnable_offsetof)+")",
    ppsIdEntryCount: "u32("+callof(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_ppsIdEntryCount_offsetof)+")",
    ppsIdEntries: "u64("+callof(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_ppsIdEntries_offsetof)+")",
}, callof(V.VkVideoEncodeH265EmitPictureParametersInfoEXT_sizeof));


const VkVideoEncodeH265NaluSliceSegmentInfoEXT = new C.CStruct("VkVideoEncodeH265NaluSliceSegmentInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH265NaluSliceSegmentInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH265NaluSliceSegmentInfoEXT_pNext_offsetof)+")",
    ctbCount: "u32("+callof(V.VkVideoEncodeH265NaluSliceSegmentInfoEXT_ctbCount_offsetof)+")",
    pReferenceFinalLists: "u64("+callof(V.VkVideoEncodeH265NaluSliceSegmentInfoEXT_pReferenceFinalLists_offsetof)+")",
    pSliceSegmentHeaderStd: "u64("+callof(V.VkVideoEncodeH265NaluSliceSegmentInfoEXT_pSliceSegmentHeaderStd_offsetof)+")",
}, callof(V.VkVideoEncodeH265NaluSliceSegmentInfoEXT_sizeof));


const VkVideoEncodeH265RateControlInfoEXT = new C.CStruct("VkVideoEncodeH265RateControlInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH265RateControlInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH265RateControlInfoEXT_pNext_offsetof)+")",
    gopFrameCount: "u32("+callof(V.VkVideoEncodeH265RateControlInfoEXT_gopFrameCount_offsetof)+")",
    idrPeriod: "u32("+callof(V.VkVideoEncodeH265RateControlInfoEXT_idrPeriod_offsetof)+")",
    consecutiveBFrameCount: "u32("+callof(V.VkVideoEncodeH265RateControlInfoEXT_consecutiveBFrameCount_offsetof)+")",
    rateControlStructure: "u32("+callof(V.VkVideoEncodeH265RateControlInfoEXT_rateControlStructure_offsetof)+")",
    subLayerCount: "u8("+callof(V.VkVideoEncodeH265RateControlInfoEXT_subLayerCount_offsetof)+")",
}, callof(V.VkVideoEncodeH265RateControlInfoEXT_sizeof));


const VkVideoEncodeH265QpEXT = new C.CStruct("VkVideoEncodeH265QpEXT", {
    qpI: "i32("+callof(V.VkVideoEncodeH265QpEXT_qpI_offsetof)+")",
    qpP: "i32("+callof(V.VkVideoEncodeH265QpEXT_qpP_offsetof)+")",
    qpB: "i32("+callof(V.VkVideoEncodeH265QpEXT_qpB_offsetof)+")",
}, callof(V.VkVideoEncodeH265QpEXT_sizeof));


const VkVideoEncodeH265FrameSizeEXT = new C.CStruct("VkVideoEncodeH265FrameSizeEXT", {
    frameISize: "u32("+callof(V.VkVideoEncodeH265FrameSizeEXT_frameISize_offsetof)+")",
    framePSize: "u32("+callof(V.VkVideoEncodeH265FrameSizeEXT_framePSize_offsetof)+")",
    frameBSize: "u32("+callof(V.VkVideoEncodeH265FrameSizeEXT_frameBSize_offsetof)+")",
}, callof(V.VkVideoEncodeH265FrameSizeEXT_sizeof));


const VkVideoEncodeH265RateControlLayerInfoEXT = new C.CStruct("VkVideoEncodeH265RateControlLayerInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH265RateControlLayerInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH265RateControlLayerInfoEXT_pNext_offsetof)+")",
    temporalId: "u8("+callof(V.VkVideoEncodeH265RateControlLayerInfoEXT_temporalId_offsetof)+")",
    useInitialRcQp: "u32("+callof(V.VkVideoEncodeH265RateControlLayerInfoEXT_useInitialRcQp_offsetof)+")",
    initialRcQp: "u32("+callof(V.VkVideoEncodeH265RateControlLayerInfoEXT_initialRcQp_offsetof)+")",
    useMinQp: "u32("+callof(V.VkVideoEncodeH265RateControlLayerInfoEXT_useMinQp_offsetof)+")",
    minQp: "u32("+callof(V.VkVideoEncodeH265RateControlLayerInfoEXT_minQp_offsetof)+")",
    useMaxQp: "u32("+callof(V.VkVideoEncodeH265RateControlLayerInfoEXT_useMaxQp_offsetof)+")",
    maxQp: "u32("+callof(V.VkVideoEncodeH265RateControlLayerInfoEXT_maxQp_offsetof)+")",
    useMaxFrameSize: "u32("+callof(V.VkVideoEncodeH265RateControlLayerInfoEXT_useMaxFrameSize_offsetof)+")",
    maxFrameSize: "u32("+callof(V.VkVideoEncodeH265RateControlLayerInfoEXT_maxFrameSize_offsetof)+")",
}, callof(V.VkVideoEncodeH265RateControlLayerInfoEXT_sizeof));


const VkVideoEncodeH265ProfileInfoEXT = new C.CStruct("VkVideoEncodeH265ProfileInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH265ProfileInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH265ProfileInfoEXT_pNext_offsetof)+")",
    stdProfileIdc: "u32("+callof(V.VkVideoEncodeH265ProfileInfoEXT_stdProfileIdc_offsetof)+")",
}, callof(V.VkVideoEncodeH265ProfileInfoEXT_sizeof));


const VkVideoEncodeH265DpbSlotInfoEXT = new C.CStruct("VkVideoEncodeH265DpbSlotInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH265DpbSlotInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH265DpbSlotInfoEXT_pNext_offsetof)+")",
    slotIndex: "i8("+callof(V.VkVideoEncodeH265DpbSlotInfoEXT_slotIndex_offsetof)+")",
    pStdReferenceInfo: "u64("+callof(V.VkVideoEncodeH265DpbSlotInfoEXT_pStdReferenceInfo_offsetof)+")",
}, callof(V.VkVideoEncodeH265DpbSlotInfoEXT_sizeof));


const VkVideoEncodeH265ReferenceListsInfoEXT = new C.CStruct("VkVideoEncodeH265ReferenceListsInfoEXT", {
    sType: "u32("+callof(V.VkVideoEncodeH265ReferenceListsInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkVideoEncodeH265ReferenceListsInfoEXT_pNext_offsetof)+")",
    referenceList0EntryCount: "u8("+callof(V.VkVideoEncodeH265ReferenceListsInfoEXT_referenceList0EntryCount_offsetof)+")",
    pReferenceList0Entries: "u64("+callof(V.VkVideoEncodeH265ReferenceListsInfoEXT_pReferenceList0Entries_offsetof)+")",
    referenceList1EntryCount: "u8("+callof(V.VkVideoEncodeH265ReferenceListsInfoEXT_referenceList1EntryCount_offsetof)+")",
    pReferenceList1Entries: "u64("+callof(V.VkVideoEncodeH265ReferenceListsInfoEXT_pReferenceList1Entries_offsetof)+")",
    pReferenceModifications: "u64("+callof(V.VkVideoEncodeH265ReferenceListsInfoEXT_pReferenceModifications_offsetof)+")",
}, callof(V.VkVideoEncodeH265ReferenceListsInfoEXT_sizeof));


const VkPhysicalDeviceInheritedViewportScissorFeaturesNV = new C.CStruct("VkPhysicalDeviceInheritedViewportScissorFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceInheritedViewportScissorFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceInheritedViewportScissorFeaturesNV_pNext_offsetof)+")",
    inheritedViewportScissor2D: "u32("+callof(V.VkPhysicalDeviceInheritedViewportScissorFeaturesNV_inheritedViewportScissor2D_offsetof)+")",
}, callof(V.VkPhysicalDeviceInheritedViewportScissorFeaturesNV_sizeof));


const VkCommandBufferInheritanceViewportScissorInfoNV = new C.CStruct("VkCommandBufferInheritanceViewportScissorInfoNV", {
    sType: "u32("+callof(V.VkCommandBufferInheritanceViewportScissorInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCommandBufferInheritanceViewportScissorInfoNV_pNext_offsetof)+")",
    viewportScissor2D: "u32("+callof(V.VkCommandBufferInheritanceViewportScissorInfoNV_viewportScissor2D_offsetof)+")",
    viewportDepthCount: "u32("+callof(V.VkCommandBufferInheritanceViewportScissorInfoNV_viewportDepthCount_offsetof)+")",
    pViewportDepths: "u64("+callof(V.VkCommandBufferInheritanceViewportScissorInfoNV_pViewportDepths_offsetof)+")",
}, callof(V.VkCommandBufferInheritanceViewportScissorInfoNV_sizeof));


const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT = new C.CStruct("VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT_pNext_offsetof)+")",
    ycbcr2plane444Formats: "u32("+callof(V.VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT_ycbcr2plane444Formats_offsetof)+")",
}, callof(V.VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT_sizeof));


const VkPhysicalDeviceProvokingVertexFeaturesEXT = new C.CStruct("VkPhysicalDeviceProvokingVertexFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceProvokingVertexFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceProvokingVertexFeaturesEXT_pNext_offsetof)+")",
    provokingVertexLast: "u32("+callof(V.VkPhysicalDeviceProvokingVertexFeaturesEXT_provokingVertexLast_offsetof)+")",
    transformFeedbackPreservesProvokingVertex: "u32("+callof(V.VkPhysicalDeviceProvokingVertexFeaturesEXT_transformFeedbackPreservesProvokingVertex_offsetof)+")",
}, callof(V.VkPhysicalDeviceProvokingVertexFeaturesEXT_sizeof));


const VkPhysicalDeviceProvokingVertexPropertiesEXT = new C.CStruct("VkPhysicalDeviceProvokingVertexPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceProvokingVertexPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceProvokingVertexPropertiesEXT_pNext_offsetof)+")",
    provokingVertexModePerPipeline: "u32("+callof(V.VkPhysicalDeviceProvokingVertexPropertiesEXT_provokingVertexModePerPipeline_offsetof)+")",
    transformFeedbackPreservesTriangleFanProvokingVertex: "u32("+callof(V.VkPhysicalDeviceProvokingVertexPropertiesEXT_transformFeedbackPreservesTriangleFanProvokingVertex_offsetof)+")",
}, callof(V.VkPhysicalDeviceProvokingVertexPropertiesEXT_sizeof));


const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT = new C.CStruct("VkPipelineRasterizationProvokingVertexStateCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineRasterizationProvokingVertexStateCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineRasterizationProvokingVertexStateCreateInfoEXT_pNext_offsetof)+")",
    provokingVertexMode: "u32("+callof(V.VkPipelineRasterizationProvokingVertexStateCreateInfoEXT_provokingVertexMode_offsetof)+")",
}, callof(V.VkPipelineRasterizationProvokingVertexStateCreateInfoEXT_sizeof));


const VkCuModuleCreateInfoNVX = new C.CStruct("VkCuModuleCreateInfoNVX", {
    sType: "u32("+callof(V.VkCuModuleCreateInfoNVX_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCuModuleCreateInfoNVX_pNext_offsetof)+")",
    dataSize: "u64("+callof(V.VkCuModuleCreateInfoNVX_dataSize_offsetof)+")",
    pData: "u64("+callof(V.VkCuModuleCreateInfoNVX_pData_offsetof)+")",
}, callof(V.VkCuModuleCreateInfoNVX_sizeof));


const VkCuFunctionCreateInfoNVX = new C.CStruct("VkCuFunctionCreateInfoNVX", {
    sType: "u32("+callof(V.VkCuFunctionCreateInfoNVX_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCuFunctionCreateInfoNVX_pNext_offsetof)+")",
    module: "u32("+callof(V.VkCuFunctionCreateInfoNVX_module_offsetof)+")",
    pName: "u64("+callof(V.VkCuFunctionCreateInfoNVX_pName_offsetof)+")",
}, callof(V.VkCuFunctionCreateInfoNVX_sizeof));


const VkCuLaunchInfoNVX = new C.CStruct("VkCuLaunchInfoNVX", {
    sType: "u32("+callof(V.VkCuLaunchInfoNVX_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCuLaunchInfoNVX_pNext_offsetof)+")",
    function: "u32("+callof(V.VkCuLaunchInfoNVX_function_offsetof)+")",
    gridDimX: "u32("+callof(V.VkCuLaunchInfoNVX_gridDimX_offsetof)+")",
    gridDimY: "u32("+callof(V.VkCuLaunchInfoNVX_gridDimY_offsetof)+")",
    gridDimZ: "u32("+callof(V.VkCuLaunchInfoNVX_gridDimZ_offsetof)+")",
    blockDimX: "u32("+callof(V.VkCuLaunchInfoNVX_blockDimX_offsetof)+")",
    blockDimY: "u32("+callof(V.VkCuLaunchInfoNVX_blockDimY_offsetof)+")",
    blockDimZ: "u32("+callof(V.VkCuLaunchInfoNVX_blockDimZ_offsetof)+")",
    sharedMemBytes: "u32("+callof(V.VkCuLaunchInfoNVX_sharedMemBytes_offsetof)+")",
    paramCount: "u64("+callof(V.VkCuLaunchInfoNVX_paramCount_offsetof)+")",
    pParams: "u64("+callof(V.VkCuLaunchInfoNVX_pParams_offsetof)+")",
    extraCount: "u64("+callof(V.VkCuLaunchInfoNVX_extraCount_offsetof)+")",
    pExtras: "u64("+callof(V.VkCuLaunchInfoNVX_pExtras_offsetof)+")",
}, callof(V.VkCuLaunchInfoNVX_sizeof));


const VkPhysicalDeviceShaderIntegerDotProductFeatures = new C.CStruct("VkPhysicalDeviceShaderIntegerDotProductFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderIntegerDotProductFeatures_pNext_offsetof)+")",
    shaderIntegerDotProduct: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductFeatures_shaderIntegerDotProduct_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderIntegerDotProductFeatures_sizeof));


const VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR = new C.CStruct("VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR", {

}, callof(V.VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR_sizeof));


const VkPhysicalDeviceShaderIntegerDotProductProperties = new C.CStruct("VkPhysicalDeviceShaderIntegerDotProductProperties", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_pNext_offsetof)+")",
    integerDotProduct8BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct8BitUnsignedAccelerated_offsetof)+")",
    integerDotProduct8BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct8BitSignedAccelerated_offsetof)+")",
    integerDotProduct8BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct8BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProduct4x8BitPackedUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct4x8BitPackedUnsignedAccelerated_offsetof)+")",
    integerDotProduct4x8BitPackedSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct4x8BitPackedSignedAccelerated_offsetof)+")",
    integerDotProduct4x8BitPackedMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct4x8BitPackedMixedSignednessAccelerated_offsetof)+")",
    integerDotProduct16BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct16BitUnsignedAccelerated_offsetof)+")",
    integerDotProduct16BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct16BitSignedAccelerated_offsetof)+")",
    integerDotProduct16BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct16BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProduct32BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct32BitUnsignedAccelerated_offsetof)+")",
    integerDotProduct32BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct32BitSignedAccelerated_offsetof)+")",
    integerDotProduct32BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct32BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProduct64BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct64BitUnsignedAccelerated_offsetof)+")",
    integerDotProduct64BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct64BitSignedAccelerated_offsetof)+")",
    integerDotProduct64BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProduct64BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating8BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating8BitUnsignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating8BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating8BitSignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating16BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating16BitUnsignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating16BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating16BitSignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating32BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating32BitUnsignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating32BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating32BitSignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating64BitUnsignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating64BitUnsignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating64BitSignedAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating64BitSignedAccelerated_offsetof)+")",
    integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated: "u32("+callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderIntegerDotProductProperties_sizeof));


const VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR = new C.CStruct("VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR", {

}, callof(V.VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR_sizeof));


const VkPhysicalDeviceDrmPropertiesEXT = new C.CStruct("VkPhysicalDeviceDrmPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceDrmPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDrmPropertiesEXT_pNext_offsetof)+")",
    hasPrimary: "u32("+callof(V.VkPhysicalDeviceDrmPropertiesEXT_hasPrimary_offsetof)+")",
    hasRender: "u32("+callof(V.VkPhysicalDeviceDrmPropertiesEXT_hasRender_offsetof)+")",
    primaryMajor: "u64("+callof(V.VkPhysicalDeviceDrmPropertiesEXT_primaryMajor_offsetof)+")",
    primaryMinor: "u64("+callof(V.VkPhysicalDeviceDrmPropertiesEXT_primaryMinor_offsetof)+")",
    renderMajor: "u64("+callof(V.VkPhysicalDeviceDrmPropertiesEXT_renderMajor_offsetof)+")",
    renderMinor: "u64("+callof(V.VkPhysicalDeviceDrmPropertiesEXT_renderMinor_offsetof)+")",
}, callof(V.VkPhysicalDeviceDrmPropertiesEXT_sizeof));


const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR = new C.CStruct("VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR_pNext_offsetof)+")",
    fragmentShaderBarycentric: "u32("+callof(V.VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR_fragmentShaderBarycentric_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR_sizeof));


const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR = new C.CStruct("VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR", {
    sType: "u32("+callof(V.VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR_pNext_offsetof)+")",
    triStripVertexOrderIndependentOfProvokingVertex: "u32("+callof(V.VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR_triStripVertexOrderIndependentOfProvokingVertex_offsetof)+")",
}, callof(V.VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR_sizeof));


const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV = new C.CStruct("VkPhysicalDeviceRayTracingMotionBlurFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceRayTracingMotionBlurFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRayTracingMotionBlurFeaturesNV_pNext_offsetof)+")",
    rayTracingMotionBlur: "u32("+callof(V.VkPhysicalDeviceRayTracingMotionBlurFeaturesNV_rayTracingMotionBlur_offsetof)+")",
    rayTracingMotionBlurPipelineTraceRaysIndirect: "u32("+callof(V.VkPhysicalDeviceRayTracingMotionBlurFeaturesNV_rayTracingMotionBlurPipelineTraceRaysIndirect_offsetof)+")",
}, callof(V.VkPhysicalDeviceRayTracingMotionBlurFeaturesNV_sizeof));


const VkAccelerationStructureGeometryMotionTrianglesDataNV = new C.CStruct("VkAccelerationStructureGeometryMotionTrianglesDataNV", {
    sType: "u32("+callof(V.VkAccelerationStructureGeometryMotionTrianglesDataNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureGeometryMotionTrianglesDataNV_pNext_offsetof)+")",
    vertexData: "u32("+callof(V.VkAccelerationStructureGeometryMotionTrianglesDataNV_vertexData_offsetof)+")",
}, callof(V.VkAccelerationStructureGeometryMotionTrianglesDataNV_sizeof));


const VkAccelerationStructureMotionInfoNV = new C.CStruct("VkAccelerationStructureMotionInfoNV", {
    sType: "u32("+callof(V.VkAccelerationStructureMotionInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureMotionInfoNV_pNext_offsetof)+")",
    maxInstances: "u32("+callof(V.VkAccelerationStructureMotionInfoNV_maxInstances_offsetof)+")",
    flags: "u32("+callof(V.VkAccelerationStructureMotionInfoNV_flags_offsetof)+")",
}, callof(V.VkAccelerationStructureMotionInfoNV_sizeof));


const VkSRTDataNV = new C.CStruct("VkSRTDataNV", {
    sx: "f32("+callof(V.VkSRTDataNV_sx_offsetof)+")",
    a: "f32("+callof(V.VkSRTDataNV_a_offsetof)+")",
    b: "f32("+callof(V.VkSRTDataNV_b_offsetof)+")",
    pvx: "f32("+callof(V.VkSRTDataNV_pvx_offsetof)+")",
    sy: "f32("+callof(V.VkSRTDataNV_sy_offsetof)+")",
    c: "f32("+callof(V.VkSRTDataNV_c_offsetof)+")",
    pvy: "f32("+callof(V.VkSRTDataNV_pvy_offsetof)+")",
    sz: "f32("+callof(V.VkSRTDataNV_sz_offsetof)+")",
    pvz: "f32("+callof(V.VkSRTDataNV_pvz_offsetof)+")",
    qx: "f32("+callof(V.VkSRTDataNV_qx_offsetof)+")",
    qy: "f32("+callof(V.VkSRTDataNV_qy_offsetof)+")",
    qz: "f32("+callof(V.VkSRTDataNV_qz_offsetof)+")",
    qw: "f32("+callof(V.VkSRTDataNV_qw_offsetof)+")",
    tx: "f32("+callof(V.VkSRTDataNV_tx_offsetof)+")",
    ty: "f32("+callof(V.VkSRTDataNV_ty_offsetof)+")",
    tz: "f32("+callof(V.VkSRTDataNV_tz_offsetof)+")",
}, callof(V.VkSRTDataNV_sizeof));


const VkAccelerationStructureSRTMotionInstanceNV = new C.CStruct("VkAccelerationStructureSRTMotionInstanceNV", {
    transformT0: "u32("+callof(V.VkAccelerationStructureSRTMotionInstanceNV_transformT0_offsetof)+")",
    transformT1: "u32("+callof(V.VkAccelerationStructureSRTMotionInstanceNV_transformT1_offsetof)+")",
    instanceCustomIndex: "u24("+callof(V.VkAccelerationStructureSRTMotionInstanceNV_instanceCustomIndex_offsetof)+")",
    mask: "u8("+callof(V.VkAccelerationStructureSRTMotionInstanceNV_mask_offsetof)+")",
    instanceShaderBindingTableRecordOffset: "u24("+callof(V.VkAccelerationStructureSRTMotionInstanceNV_instanceShaderBindingTableRecordOffset_offsetof)+")",
    flags: "u8("+callof(V.VkAccelerationStructureSRTMotionInstanceNV_flags_offsetof)+")",
    accelerationStructureReference: "u64("+callof(V.VkAccelerationStructureSRTMotionInstanceNV_accelerationStructureReference_offsetof)+")",
}, callof(V.VkAccelerationStructureSRTMotionInstanceNV_sizeof));


const VkAccelerationStructureMatrixMotionInstanceNV = new C.CStruct("VkAccelerationStructureMatrixMotionInstanceNV", {
    transformT0: "VkTransformMatrixKHR("+callof(V.VkAccelerationStructureMatrixMotionInstanceNV_transformT0_offsetof)+")",
    transformT1: "VkTransformMatrixKHR("+callof(V.VkAccelerationStructureMatrixMotionInstanceNV_transformT1_offsetof)+")",
    instanceCustomIndex: "u24("+callof(V.VkAccelerationStructureMatrixMotionInstanceNV_instanceCustomIndex_offsetof)+")",
    mask: "u8("+callof(V.VkAccelerationStructureMatrixMotionInstanceNV_mask_offsetof)+")",
    instanceShaderBindingTableRecordOffset: "u24("+callof(V.VkAccelerationStructureMatrixMotionInstanceNV_instanceShaderBindingTableRecordOffset_offsetof)+")",
    flags: "u8("+callof(V.VkAccelerationStructureMatrixMotionInstanceNV_flags_offsetof)+")",
    accelerationStructureReference: "u64("+callof(V.VkAccelerationStructureMatrixMotionInstanceNV_accelerationStructureReference_offsetof)+")",
}, callof(V.VkAccelerationStructureMatrixMotionInstanceNV_sizeof));


const VkAccelerationStructureMotionInstanceNV = new C.CStruct("VkAccelerationStructureMotionInstanceNV", {
    type: "u32("+callof(V.VkAccelerationStructureMotionInstanceNV_type_offsetof)+")",
    flags: "u32("+callof(V.VkAccelerationStructureMotionInstanceNV_flags_offsetof)+")",
    data: "u32("+callof(V.VkAccelerationStructureMotionInstanceNV_data_offsetof)+")",
}, callof(V.VkAccelerationStructureMotionInstanceNV_sizeof));


const VkMemoryGetRemoteAddressInfoNV = new C.CStruct("VkMemoryGetRemoteAddressInfoNV", {
    sType: "u32("+callof(V.VkMemoryGetRemoteAddressInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMemoryGetRemoteAddressInfoNV_pNext_offsetof)+")",
    memory: "u64("+callof(V.VkMemoryGetRemoteAddressInfoNV_memory_offsetof)+")",
    handleType: "u32("+callof(V.VkMemoryGetRemoteAddressInfoNV_handleType_offsetof)+")",
}, callof(V.VkMemoryGetRemoteAddressInfoNV_sizeof));


const VkImportMemoryBufferCollectionFUCHSIA = new C.CStruct("VkImportMemoryBufferCollectionFUCHSIA", {
    sType: "u32("+callof(V.VkImportMemoryBufferCollectionFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportMemoryBufferCollectionFUCHSIA_pNext_offsetof)+")",
    collection: "u32("+callof(V.VkImportMemoryBufferCollectionFUCHSIA_collection_offsetof)+")",
    index: "u32("+callof(V.VkImportMemoryBufferCollectionFUCHSIA_index_offsetof)+")",
}, callof(V.VkImportMemoryBufferCollectionFUCHSIA_sizeof));


const VkBufferCollectionImageCreateInfoFUCHSIA = new C.CStruct("VkBufferCollectionImageCreateInfoFUCHSIA", {
    sType: "u32("+callof(V.VkBufferCollectionImageCreateInfoFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferCollectionImageCreateInfoFUCHSIA_pNext_offsetof)+")",
    collection: "u32("+callof(V.VkBufferCollectionImageCreateInfoFUCHSIA_collection_offsetof)+")",
    index: "u32("+callof(V.VkBufferCollectionImageCreateInfoFUCHSIA_index_offsetof)+")",
}, callof(V.VkBufferCollectionImageCreateInfoFUCHSIA_sizeof));


const VkBufferCollectionBufferCreateInfoFUCHSIA = new C.CStruct("VkBufferCollectionBufferCreateInfoFUCHSIA", {
    sType: "u32("+callof(V.VkBufferCollectionBufferCreateInfoFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferCollectionBufferCreateInfoFUCHSIA_pNext_offsetof)+")",
    collection: "u32("+callof(V.VkBufferCollectionBufferCreateInfoFUCHSIA_collection_offsetof)+")",
    index: "u32("+callof(V.VkBufferCollectionBufferCreateInfoFUCHSIA_index_offsetof)+")",
}, callof(V.VkBufferCollectionBufferCreateInfoFUCHSIA_sizeof));


const VkBufferCollectionCreateInfoFUCHSIA = new C.CStruct("VkBufferCollectionCreateInfoFUCHSIA", {
    sType: "u32("+callof(V.VkBufferCollectionCreateInfoFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferCollectionCreateInfoFUCHSIA_pNext_offsetof)+")",
    collectionToken: "u32("+callof(V.VkBufferCollectionCreateInfoFUCHSIA_collectionToken_offsetof)+")",
}, callof(V.VkBufferCollectionCreateInfoFUCHSIA_sizeof));


const VkBufferCollectionPropertiesFUCHSIA = new C.CStruct("VkBufferCollectionPropertiesFUCHSIA", {
    sType: "u32("+callof(V.VkBufferCollectionPropertiesFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferCollectionPropertiesFUCHSIA_pNext_offsetof)+")",
    memoryTypeBits: "u32("+callof(V.VkBufferCollectionPropertiesFUCHSIA_memoryTypeBits_offsetof)+")",
    bufferCount: "u32("+callof(V.VkBufferCollectionPropertiesFUCHSIA_bufferCount_offsetof)+")",
    createInfoIndex: "u32("+callof(V.VkBufferCollectionPropertiesFUCHSIA_createInfoIndex_offsetof)+")",
    sysmemPixelFormat: "u64("+callof(V.VkBufferCollectionPropertiesFUCHSIA_sysmemPixelFormat_offsetof)+")",
    formatFeatures: "u32("+callof(V.VkBufferCollectionPropertiesFUCHSIA_formatFeatures_offsetof)+")",
    sysmemColorSpaceIndex: "u32("+callof(V.VkBufferCollectionPropertiesFUCHSIA_sysmemColorSpaceIndex_offsetof)+")",
    samplerYcbcrConversionComponents: "u32("+callof(V.VkBufferCollectionPropertiesFUCHSIA_samplerYcbcrConversionComponents_offsetof)+")",
    suggestedYcbcrModel: "u32("+callof(V.VkBufferCollectionPropertiesFUCHSIA_suggestedYcbcrModel_offsetof)+")",
    suggestedYcbcrRange: "u32("+callof(V.VkBufferCollectionPropertiesFUCHSIA_suggestedYcbcrRange_offsetof)+")",
    suggestedXChromaOffset: "u32("+callof(V.VkBufferCollectionPropertiesFUCHSIA_suggestedXChromaOffset_offsetof)+")",
    suggestedYChromaOffset: "u32("+callof(V.VkBufferCollectionPropertiesFUCHSIA_suggestedYChromaOffset_offsetof)+")",
}, callof(V.VkBufferCollectionPropertiesFUCHSIA_sizeof));


const VkBufferConstraintsInfoFUCHSIA = new C.CStruct("VkBufferConstraintsInfoFUCHSIA", {
    sType: "u32("+callof(V.VkBufferConstraintsInfoFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferConstraintsInfoFUCHSIA_pNext_offsetof)+")",
    createInfo: "u32("+callof(V.VkBufferConstraintsInfoFUCHSIA_createInfo_offsetof)+")",
    requiredFormatFeatures: "u32("+callof(V.VkBufferConstraintsInfoFUCHSIA_requiredFormatFeatures_offsetof)+")",
    bufferCollectionConstraints: "u32("+callof(V.VkBufferConstraintsInfoFUCHSIA_bufferCollectionConstraints_offsetof)+")",
}, callof(V.VkBufferConstraintsInfoFUCHSIA_sizeof));


const VkSysmemColorSpaceFUCHSIA = new C.CStruct("VkSysmemColorSpaceFUCHSIA", {
    sType: "u32("+callof(V.VkSysmemColorSpaceFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSysmemColorSpaceFUCHSIA_pNext_offsetof)+")",
    colorSpace: "u32("+callof(V.VkSysmemColorSpaceFUCHSIA_colorSpace_offsetof)+")",
}, callof(V.VkSysmemColorSpaceFUCHSIA_sizeof));


const VkImageFormatConstraintsInfoFUCHSIA = new C.CStruct("VkImageFormatConstraintsInfoFUCHSIA", {
    sType: "u32("+callof(V.VkImageFormatConstraintsInfoFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageFormatConstraintsInfoFUCHSIA_pNext_offsetof)+")",
    imageCreateInfo: "u32("+callof(V.VkImageFormatConstraintsInfoFUCHSIA_imageCreateInfo_offsetof)+")",
    requiredFormatFeatures: "u32("+callof(V.VkImageFormatConstraintsInfoFUCHSIA_requiredFormatFeatures_offsetof)+")",
    flags: "u32("+callof(V.VkImageFormatConstraintsInfoFUCHSIA_flags_offsetof)+")",
    sysmemPixelFormat: "u64("+callof(V.VkImageFormatConstraintsInfoFUCHSIA_sysmemPixelFormat_offsetof)+")",
    colorSpaceCount: "u32("+callof(V.VkImageFormatConstraintsInfoFUCHSIA_colorSpaceCount_offsetof)+")",
    pColorSpaces: "u64("+callof(V.VkImageFormatConstraintsInfoFUCHSIA_pColorSpaces_offsetof)+")",
}, callof(V.VkImageFormatConstraintsInfoFUCHSIA_sizeof));


const VkImageConstraintsInfoFUCHSIA = new C.CStruct("VkImageConstraintsInfoFUCHSIA", {
    sType: "u32("+callof(V.VkImageConstraintsInfoFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageConstraintsInfoFUCHSIA_pNext_offsetof)+")",
    formatConstraintsCount: "u32("+callof(V.VkImageConstraintsInfoFUCHSIA_formatConstraintsCount_offsetof)+")",
    pFormatConstraints: "u64("+callof(V.VkImageConstraintsInfoFUCHSIA_pFormatConstraints_offsetof)+")",
    bufferCollectionConstraints: "u32("+callof(V.VkImageConstraintsInfoFUCHSIA_bufferCollectionConstraints_offsetof)+")",
    flags: "u32("+callof(V.VkImageConstraintsInfoFUCHSIA_flags_offsetof)+")",
}, callof(V.VkImageConstraintsInfoFUCHSIA_sizeof));


const VkBufferCollectionConstraintsInfoFUCHSIA = new C.CStruct("VkBufferCollectionConstraintsInfoFUCHSIA", {
    sType: "u32("+callof(V.VkBufferCollectionConstraintsInfoFUCHSIA_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkBufferCollectionConstraintsInfoFUCHSIA_pNext_offsetof)+")",
    minBufferCount: "u32("+callof(V.VkBufferCollectionConstraintsInfoFUCHSIA_minBufferCount_offsetof)+")",
    maxBufferCount: "u32("+callof(V.VkBufferCollectionConstraintsInfoFUCHSIA_maxBufferCount_offsetof)+")",
    minBufferCountForCamping: "u32("+callof(V.VkBufferCollectionConstraintsInfoFUCHSIA_minBufferCountForCamping_offsetof)+")",
    minBufferCountForDedicatedSlack: "u32("+callof(V.VkBufferCollectionConstraintsInfoFUCHSIA_minBufferCountForDedicatedSlack_offsetof)+")",
    minBufferCountForSharedSlack: "u32("+callof(V.VkBufferCollectionConstraintsInfoFUCHSIA_minBufferCountForSharedSlack_offsetof)+")",
}, callof(V.VkBufferCollectionConstraintsInfoFUCHSIA_sizeof));


const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT = new C.CStruct("VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT_pNext_offsetof)+")",
    formatRgba10x6WithoutYCbCrSampler: "u32("+callof(V.VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT_formatRgba10x6WithoutYCbCrSampler_offsetof)+")",
}, callof(V.VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT_sizeof));


const VkFormatProperties3 = new C.CStruct("VkFormatProperties3", {
    sType: "u32("+callof(V.VkFormatProperties3_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkFormatProperties3_pNext_offsetof)+")",
    linearTilingFeatures: "u64("+callof(V.VkFormatProperties3_linearTilingFeatures_offsetof)+")",
    optimalTilingFeatures: "u64("+callof(V.VkFormatProperties3_optimalTilingFeatures_offsetof)+")",
    bufferFeatures: "u64("+callof(V.VkFormatProperties3_bufferFeatures_offsetof)+")",
}, callof(V.VkFormatProperties3_sizeof));


const VkFormatProperties3KHR = new C.CStruct("VkFormatProperties3KHR", {

}, callof(V.VkFormatProperties3KHR_sizeof));


const VkDrmFormatModifierPropertiesList2EXT = new C.CStruct("VkDrmFormatModifierPropertiesList2EXT", {
    sType: "u32("+callof(V.VkDrmFormatModifierPropertiesList2EXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDrmFormatModifierPropertiesList2EXT_pNext_offsetof)+")",
    drmFormatModifierCount: "u32("+callof(V.VkDrmFormatModifierPropertiesList2EXT_drmFormatModifierCount_offsetof)+")",
    pDrmFormatModifierProperties: "u64("+callof(V.VkDrmFormatModifierPropertiesList2EXT_pDrmFormatModifierProperties_offsetof)+")",
}, callof(V.VkDrmFormatModifierPropertiesList2EXT_sizeof));


const VkDrmFormatModifierProperties2EXT = new C.CStruct("VkDrmFormatModifierProperties2EXT", {
    drmFormatModifier: "u64("+callof(V.VkDrmFormatModifierProperties2EXT_drmFormatModifier_offsetof)+")",
    drmFormatModifierPlaneCount: "u32("+callof(V.VkDrmFormatModifierProperties2EXT_drmFormatModifierPlaneCount_offsetof)+")",
    drmFormatModifierTilingFeatures: "u64("+callof(V.VkDrmFormatModifierProperties2EXT_drmFormatModifierTilingFeatures_offsetof)+")",
}, callof(V.VkDrmFormatModifierProperties2EXT_sizeof));


const VkAndroidHardwareBufferFormatProperties2ANDROID = new C.CStruct("VkAndroidHardwareBufferFormatProperties2ANDROID", {
    sType: "u32("+callof(V.VkAndroidHardwareBufferFormatProperties2ANDROID_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAndroidHardwareBufferFormatProperties2ANDROID_pNext_offsetof)+")",
    format: "u32("+callof(V.VkAndroidHardwareBufferFormatProperties2ANDROID_format_offsetof)+")",
    externalFormat: "u64("+callof(V.VkAndroidHardwareBufferFormatProperties2ANDROID_externalFormat_offsetof)+")",
    formatFeatures: "u64("+callof(V.VkAndroidHardwareBufferFormatProperties2ANDROID_formatFeatures_offsetof)+")",
    samplerYcbcrConversionComponents: "u32("+callof(V.VkAndroidHardwareBufferFormatProperties2ANDROID_samplerYcbcrConversionComponents_offsetof)+")",
    suggestedYcbcrModel: "u32("+callof(V.VkAndroidHardwareBufferFormatProperties2ANDROID_suggestedYcbcrModel_offsetof)+")",
    suggestedYcbcrRange: "u32("+callof(V.VkAndroidHardwareBufferFormatProperties2ANDROID_suggestedYcbcrRange_offsetof)+")",
    suggestedXChromaOffset: "u32("+callof(V.VkAndroidHardwareBufferFormatProperties2ANDROID_suggestedXChromaOffset_offsetof)+")",
    suggestedYChromaOffset: "u32("+callof(V.VkAndroidHardwareBufferFormatProperties2ANDROID_suggestedYChromaOffset_offsetof)+")",
}, callof(V.VkAndroidHardwareBufferFormatProperties2ANDROID_sizeof));


const VkPipelineRenderingCreateInfo = new C.CStruct("VkPipelineRenderingCreateInfo", {
    sType: "u32("+callof(V.VkPipelineRenderingCreateInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineRenderingCreateInfo_pNext_offsetof)+")",
    viewMask: "u32("+callof(V.VkPipelineRenderingCreateInfo_viewMask_offsetof)+")",
    colorAttachmentCount: "u32("+callof(V.VkPipelineRenderingCreateInfo_colorAttachmentCount_offsetof)+")",
    pColorAttachmentFormats: "u64("+callof(V.VkPipelineRenderingCreateInfo_pColorAttachmentFormats_offsetof)+")",
    depthAttachmentFormat: "u32("+callof(V.VkPipelineRenderingCreateInfo_depthAttachmentFormat_offsetof)+")",
    stencilAttachmentFormat: "u32("+callof(V.VkPipelineRenderingCreateInfo_stencilAttachmentFormat_offsetof)+")",
}, callof(V.VkPipelineRenderingCreateInfo_sizeof));


const VkPipelineRenderingCreateInfoKHR = new C.CStruct("VkPipelineRenderingCreateInfoKHR", {

}, callof(V.VkPipelineRenderingCreateInfoKHR_sizeof));


const VkRenderingInfo = new C.CStruct("VkRenderingInfo", {
    sType: "u32("+callof(V.VkRenderingInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderingInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkRenderingInfo_flags_offsetof)+")",
    renderArea: "VkRect2D("+callof(V.VkRenderingInfo_renderArea_offsetof)+")",
    layerCount: "u32("+callof(V.VkRenderingInfo_layerCount_offsetof)+")",
    viewMask: "u32("+callof(V.VkRenderingInfo_viewMask_offsetof)+")",
    colorAttachmentCount: "u32("+callof(V.VkRenderingInfo_colorAttachmentCount_offsetof)+")",
    pColorAttachments: "u64("+callof(V.VkRenderingInfo_pColorAttachments_offsetof)+")",
    pDepthAttachment: "u64("+callof(V.VkRenderingInfo_pDepthAttachment_offsetof)+")",
    pStencilAttachment: "u64("+callof(V.VkRenderingInfo_pStencilAttachment_offsetof)+")",
}, callof(V.VkRenderingInfo_sizeof));


const VkRenderingInfoKHR = new C.CStruct("VkRenderingInfoKHR", {

}, callof(V.VkRenderingInfoKHR_sizeof));


const VkRenderingAttachmentInfo = new C.CStruct("VkRenderingAttachmentInfo", {
    sType: "u32("+callof(V.VkRenderingAttachmentInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderingAttachmentInfo_pNext_offsetof)+")",
    imageView: "u32("+callof(V.VkRenderingAttachmentInfo_imageView_offsetof)+")",
    imageLayout: "u32("+callof(V.VkRenderingAttachmentInfo_imageLayout_offsetof)+")",
    resolveMode: "u32("+callof(V.VkRenderingAttachmentInfo_resolveMode_offsetof)+")",
    resolveImageView: "u32("+callof(V.VkRenderingAttachmentInfo_resolveImageView_offsetof)+")",
    resolveImageLayout: "u32("+callof(V.VkRenderingAttachmentInfo_resolveImageLayout_offsetof)+")",
    loadOp: "u32("+callof(V.VkRenderingAttachmentInfo_loadOp_offsetof)+")",
    storeOp: "u32("+callof(V.VkRenderingAttachmentInfo_storeOp_offsetof)+")",
    clearValue: "u32("+callof(V.VkRenderingAttachmentInfo_clearValue_offsetof)+")",
}, callof(V.VkRenderingAttachmentInfo_sizeof));


const VkRenderingAttachmentInfoKHR = new C.CStruct("VkRenderingAttachmentInfoKHR", {

}, callof(V.VkRenderingAttachmentInfoKHR_sizeof));


const VkRenderingFragmentShadingRateAttachmentInfoKHR = new C.CStruct("VkRenderingFragmentShadingRateAttachmentInfoKHR", {
    sType: "u32("+callof(V.VkRenderingFragmentShadingRateAttachmentInfoKHR_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderingFragmentShadingRateAttachmentInfoKHR_pNext_offsetof)+")",
    imageView: "u32("+callof(V.VkRenderingFragmentShadingRateAttachmentInfoKHR_imageView_offsetof)+")",
    imageLayout: "u32("+callof(V.VkRenderingFragmentShadingRateAttachmentInfoKHR_imageLayout_offsetof)+")",
    shadingRateAttachmentTexelSize: "VkExtent2D("+callof(V.VkRenderingFragmentShadingRateAttachmentInfoKHR_shadingRateAttachmentTexelSize_offsetof)+")",
}, callof(V.VkRenderingFragmentShadingRateAttachmentInfoKHR_sizeof));


const VkRenderingFragmentDensityMapAttachmentInfoEXT = new C.CStruct("VkRenderingFragmentDensityMapAttachmentInfoEXT", {
    sType: "u32("+callof(V.VkRenderingFragmentDensityMapAttachmentInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderingFragmentDensityMapAttachmentInfoEXT_pNext_offsetof)+")",
    imageView: "u32("+callof(V.VkRenderingFragmentDensityMapAttachmentInfoEXT_imageView_offsetof)+")",
    imageLayout: "u32("+callof(V.VkRenderingFragmentDensityMapAttachmentInfoEXT_imageLayout_offsetof)+")",
}, callof(V.VkRenderingFragmentDensityMapAttachmentInfoEXT_sizeof));


const VkPhysicalDeviceDynamicRenderingFeatures = new C.CStruct("VkPhysicalDeviceDynamicRenderingFeatures", {
    sType: "u32("+callof(V.VkPhysicalDeviceDynamicRenderingFeatures_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDynamicRenderingFeatures_pNext_offsetof)+")",
    dynamicRendering: "u32("+callof(V.VkPhysicalDeviceDynamicRenderingFeatures_dynamicRendering_offsetof)+")",
}, callof(V.VkPhysicalDeviceDynamicRenderingFeatures_sizeof));


const VkPhysicalDeviceDynamicRenderingFeaturesKHR = new C.CStruct("VkPhysicalDeviceDynamicRenderingFeaturesKHR", {

}, callof(V.VkPhysicalDeviceDynamicRenderingFeaturesKHR_sizeof));


const VkCommandBufferInheritanceRenderingInfo = new C.CStruct("VkCommandBufferInheritanceRenderingInfo", {
    sType: "u32("+callof(V.VkCommandBufferInheritanceRenderingInfo_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCommandBufferInheritanceRenderingInfo_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkCommandBufferInheritanceRenderingInfo_flags_offsetof)+")",
    viewMask: "u32("+callof(V.VkCommandBufferInheritanceRenderingInfo_viewMask_offsetof)+")",
    colorAttachmentCount: "u32("+callof(V.VkCommandBufferInheritanceRenderingInfo_colorAttachmentCount_offsetof)+")",
    pColorAttachmentFormats: "u64("+callof(V.VkCommandBufferInheritanceRenderingInfo_pColorAttachmentFormats_offsetof)+")",
    depthAttachmentFormat: "u32("+callof(V.VkCommandBufferInheritanceRenderingInfo_depthAttachmentFormat_offsetof)+")",
    stencilAttachmentFormat: "u32("+callof(V.VkCommandBufferInheritanceRenderingInfo_stencilAttachmentFormat_offsetof)+")",
    rasterizationSamples: "u32("+callof(V.VkCommandBufferInheritanceRenderingInfo_rasterizationSamples_offsetof)+")",
}, callof(V.VkCommandBufferInheritanceRenderingInfo_sizeof));


const VkCommandBufferInheritanceRenderingInfoKHR = new C.CStruct("VkCommandBufferInheritanceRenderingInfoKHR", {

}, callof(V.VkCommandBufferInheritanceRenderingInfoKHR_sizeof));


const VkAttachmentSampleCountInfoAMD = new C.CStruct("VkAttachmentSampleCountInfoAMD", {
    sType: "u32("+callof(V.VkAttachmentSampleCountInfoAMD_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAttachmentSampleCountInfoAMD_pNext_offsetof)+")",
    colorAttachmentCount: "u32("+callof(V.VkAttachmentSampleCountInfoAMD_colorAttachmentCount_offsetof)+")",
    pColorAttachmentSamples: "u64("+callof(V.VkAttachmentSampleCountInfoAMD_pColorAttachmentSamples_offsetof)+")",
    depthStencilAttachmentSamples: "u32("+callof(V.VkAttachmentSampleCountInfoAMD_depthStencilAttachmentSamples_offsetof)+")",
}, callof(V.VkAttachmentSampleCountInfoAMD_sizeof));


const VkAttachmentSampleCountInfoNV = new C.CStruct("VkAttachmentSampleCountInfoNV", {

}, callof(V.VkAttachmentSampleCountInfoNV_sizeof));


const VkMultiviewPerViewAttributesInfoNVX = new C.CStruct("VkMultiviewPerViewAttributesInfoNVX", {
    sType: "u32("+callof(V.VkMultiviewPerViewAttributesInfoNVX_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMultiviewPerViewAttributesInfoNVX_pNext_offsetof)+")",
    perViewAttributes: "u32("+callof(V.VkMultiviewPerViewAttributesInfoNVX_perViewAttributes_offsetof)+")",
    perViewAttributesPositionXOnly: "u32("+callof(V.VkMultiviewPerViewAttributesInfoNVX_perViewAttributesPositionXOnly_offsetof)+")",
}, callof(V.VkMultiviewPerViewAttributesInfoNVX_sizeof));


const VkPhysicalDeviceImageViewMinLodFeaturesEXT = new C.CStruct("VkPhysicalDeviceImageViewMinLodFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceImageViewMinLodFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceImageViewMinLodFeaturesEXT_pNext_offsetof)+")",
    minLod: "u32("+callof(V.VkPhysicalDeviceImageViewMinLodFeaturesEXT_minLod_offsetof)+")",
}, callof(V.VkPhysicalDeviceImageViewMinLodFeaturesEXT_sizeof));


const VkImageViewMinLodCreateInfoEXT = new C.CStruct("VkImageViewMinLodCreateInfoEXT", {
    sType: "u32("+callof(V.VkImageViewMinLodCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageViewMinLodCreateInfoEXT_pNext_offsetof)+")",
    minLod: "f32("+callof(V.VkImageViewMinLodCreateInfoEXT_minLod_offsetof)+")",
}, callof(V.VkImageViewMinLodCreateInfoEXT_sizeof));


const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT = new C.CStruct("VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_pNext_offsetof)+")",
    rasterizationOrderColorAttachmentAccess: "u32("+callof(V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_rasterizationOrderColorAttachmentAccess_offsetof)+")",
    rasterizationOrderDepthAttachmentAccess: "u32("+callof(V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_rasterizationOrderDepthAttachmentAccess_offsetof)+")",
    rasterizationOrderStencilAttachmentAccess: "u32("+callof(V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_rasterizationOrderStencilAttachmentAccess_offsetof)+")",
}, callof(V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_sizeof));


const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM = new C.CStruct("VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM", {

}, callof(V.VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM_sizeof));


const VkPhysicalDeviceLinearColorAttachmentFeaturesNV = new C.CStruct("VkPhysicalDeviceLinearColorAttachmentFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceLinearColorAttachmentFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceLinearColorAttachmentFeaturesNV_pNext_offsetof)+")",
    linearColorAttachment: "u32("+callof(V.VkPhysicalDeviceLinearColorAttachmentFeaturesNV_linearColorAttachment_offsetof)+")",
}, callof(V.VkPhysicalDeviceLinearColorAttachmentFeaturesNV_sizeof));


const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT = new C.CStruct("VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT_pNext_offsetof)+")",
    graphicsPipelineLibrary: "u32("+callof(V.VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT_graphicsPipelineLibrary_offsetof)+")",
}, callof(V.VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT_sizeof));


const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT = new C.CStruct("VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT_pNext_offsetof)+")",
    graphicsPipelineLibraryFastLinking: "u32("+callof(V.VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT_graphicsPipelineLibraryFastLinking_offsetof)+")",
    graphicsPipelineLibraryIndependentInterpolationDecoration: "u32("+callof(V.VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT_graphicsPipelineLibraryIndependentInterpolationDecoration_offsetof)+")",
}, callof(V.VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT_sizeof));


const VkGraphicsPipelineLibraryCreateInfoEXT = new C.CStruct("VkGraphicsPipelineLibraryCreateInfoEXT", {
    sType: "u32("+callof(V.VkGraphicsPipelineLibraryCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkGraphicsPipelineLibraryCreateInfoEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkGraphicsPipelineLibraryCreateInfoEXT_flags_offsetof)+")",
}, callof(V.VkGraphicsPipelineLibraryCreateInfoEXT_sizeof));


const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE = new C.CStruct("VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE", {
    sType: "u32("+callof(V.VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE_pNext_offsetof)+")",
    descriptorSetHostMapping: "u32("+callof(V.VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE_descriptorSetHostMapping_offsetof)+")",
}, callof(V.VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE_sizeof));


const VkDescriptorSetBindingReferenceVALVE = new C.CStruct("VkDescriptorSetBindingReferenceVALVE", {
    sType: "u32("+callof(V.VkDescriptorSetBindingReferenceVALVE_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDescriptorSetBindingReferenceVALVE_pNext_offsetof)+")",
    descriptorSetLayout: "u32("+callof(V.VkDescriptorSetBindingReferenceVALVE_descriptorSetLayout_offsetof)+")",
    binding: "u32("+callof(V.VkDescriptorSetBindingReferenceVALVE_binding_offsetof)+")",
}, callof(V.VkDescriptorSetBindingReferenceVALVE_sizeof));


const VkDescriptorSetLayoutHostMappingInfoVALVE = new C.CStruct("VkDescriptorSetLayoutHostMappingInfoVALVE", {
    sType: "u32("+callof(V.VkDescriptorSetLayoutHostMappingInfoVALVE_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDescriptorSetLayoutHostMappingInfoVALVE_pNext_offsetof)+")",
    descriptorOffset: "u64("+callof(V.VkDescriptorSetLayoutHostMappingInfoVALVE_descriptorOffset_offsetof)+")",
    descriptorSize: "u32("+callof(V.VkDescriptorSetLayoutHostMappingInfoVALVE_descriptorSize_offsetof)+")",
}, callof(V.VkDescriptorSetLayoutHostMappingInfoVALVE_sizeof));


const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT = new C.CStruct("VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT_pNext_offsetof)+")",
    shaderModuleIdentifier: "u32("+callof(V.VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT_shaderModuleIdentifier_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT_sizeof));


const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT = new C.CStruct("VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT_pNext_offsetof)+")",
    shaderModuleIdentifierAlgorithmUUID: "u8["+(enums.NaN||1)+"]("+callof(V.VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT_shaderModuleIdentifierAlgorithmUUID_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT_sizeof));


const VkPipelineShaderStageModuleIdentifierCreateInfoEXT = new C.CStruct("VkPipelineShaderStageModuleIdentifierCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineShaderStageModuleIdentifierCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineShaderStageModuleIdentifierCreateInfoEXT_pNext_offsetof)+")",
    identifierSize: "u32("+callof(V.VkPipelineShaderStageModuleIdentifierCreateInfoEXT_identifierSize_offsetof)+")",
    pIdentifier: "u64("+callof(V.VkPipelineShaderStageModuleIdentifierCreateInfoEXT_pIdentifier_offsetof)+")",
}, callof(V.VkPipelineShaderStageModuleIdentifierCreateInfoEXT_sizeof));


const VkShaderModuleIdentifierEXT = new C.CStruct("VkShaderModuleIdentifierEXT", {
    sType: "u32("+callof(V.VkShaderModuleIdentifierEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkShaderModuleIdentifierEXT_pNext_offsetof)+")",
    identifierSize: "u32("+callof(V.VkShaderModuleIdentifierEXT_identifierSize_offsetof)+")",
    identifier: "u8["+(enums.NaN||1)+"]("+callof(V.VkShaderModuleIdentifierEXT_identifier_offsetof)+")",
}, callof(V.VkShaderModuleIdentifierEXT_sizeof));


const VkImageCompressionControlEXT = new C.CStruct("VkImageCompressionControlEXT", {
    sType: "u32("+callof(V.VkImageCompressionControlEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageCompressionControlEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkImageCompressionControlEXT_flags_offsetof)+")",
    compressionControlPlaneCount: "u32("+callof(V.VkImageCompressionControlEXT_compressionControlPlaneCount_offsetof)+")",
    pFixedRateFlags: "u64("+callof(V.VkImageCompressionControlEXT_pFixedRateFlags_offsetof)+")",
}, callof(V.VkImageCompressionControlEXT_sizeof));


const VkPhysicalDeviceImageCompressionControlFeaturesEXT = new C.CStruct("VkPhysicalDeviceImageCompressionControlFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceImageCompressionControlFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceImageCompressionControlFeaturesEXT_pNext_offsetof)+")",
    imageCompressionControl: "u32("+callof(V.VkPhysicalDeviceImageCompressionControlFeaturesEXT_imageCompressionControl_offsetof)+")",
}, callof(V.VkPhysicalDeviceImageCompressionControlFeaturesEXT_sizeof));


const VkImageCompressionPropertiesEXT = new C.CStruct("VkImageCompressionPropertiesEXT", {
    sType: "u32("+callof(V.VkImageCompressionPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageCompressionPropertiesEXT_pNext_offsetof)+")",
    imageCompressionFlags: "u32("+callof(V.VkImageCompressionPropertiesEXT_imageCompressionFlags_offsetof)+")",
    imageCompressionFixedRateFlags: "u32("+callof(V.VkImageCompressionPropertiesEXT_imageCompressionFixedRateFlags_offsetof)+")",
}, callof(V.VkImageCompressionPropertiesEXT_sizeof));


const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT = new C.CStruct("VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT_pNext_offsetof)+")",
    imageCompressionControlSwapchain: "u32("+callof(V.VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT_imageCompressionControlSwapchain_offsetof)+")",
}, callof(V.VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT_sizeof));


const VkImageSubresource2EXT = new C.CStruct("VkImageSubresource2EXT", {
    sType: "u32("+callof(V.VkImageSubresource2EXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageSubresource2EXT_pNext_offsetof)+")",
    imageSubresource: "u32("+callof(V.VkImageSubresource2EXT_imageSubresource_offsetof)+")",
}, callof(V.VkImageSubresource2EXT_sizeof));


const VkSubresourceLayout2EXT = new C.CStruct("VkSubresourceLayout2EXT", {
    sType: "u32("+callof(V.VkSubresourceLayout2EXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkSubresourceLayout2EXT_pNext_offsetof)+")",
    subresourceLayout: "u32("+callof(V.VkSubresourceLayout2EXT_subresourceLayout_offsetof)+")",
}, callof(V.VkSubresourceLayout2EXT_sizeof));


const VkRenderPassCreationControlEXT = new C.CStruct("VkRenderPassCreationControlEXT", {
    sType: "u32("+callof(V.VkRenderPassCreationControlEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderPassCreationControlEXT_pNext_offsetof)+")",
    disallowMerging: "u32("+callof(V.VkRenderPassCreationControlEXT_disallowMerging_offsetof)+")",
}, callof(V.VkRenderPassCreationControlEXT_sizeof));


const VkRenderPassCreationFeedbackInfoEXT = new C.CStruct("VkRenderPassCreationFeedbackInfoEXT", {
    postMergeSubpassCount: "u32("+callof(V.VkRenderPassCreationFeedbackInfoEXT_postMergeSubpassCount_offsetof)+")",
}, callof(V.VkRenderPassCreationFeedbackInfoEXT_sizeof));


const VkRenderPassCreationFeedbackCreateInfoEXT = new C.CStruct("VkRenderPassCreationFeedbackCreateInfoEXT", {
    sType: "u32("+callof(V.VkRenderPassCreationFeedbackCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderPassCreationFeedbackCreateInfoEXT_pNext_offsetof)+")",
    pRenderPassFeedback: "u64("+callof(V.VkRenderPassCreationFeedbackCreateInfoEXT_pRenderPassFeedback_offsetof)+")",
}, callof(V.VkRenderPassCreationFeedbackCreateInfoEXT_sizeof));


const VkRenderPassSubpassFeedbackInfoEXT = new C.CStruct("VkRenderPassSubpassFeedbackInfoEXT", {
    subpassMergeStatus: "u32("+callof(V.VkRenderPassSubpassFeedbackInfoEXT_subpassMergeStatus_offsetof)+")",
    description: "u8["+(enums.NaN||1)+"]("+callof(V.VkRenderPassSubpassFeedbackInfoEXT_description_offsetof)+")",
    postMergeIndex: "u32("+callof(V.VkRenderPassSubpassFeedbackInfoEXT_postMergeIndex_offsetof)+")",
}, callof(V.VkRenderPassSubpassFeedbackInfoEXT_sizeof));


const VkRenderPassSubpassFeedbackCreateInfoEXT = new C.CStruct("VkRenderPassSubpassFeedbackCreateInfoEXT", {
    sType: "u32("+callof(V.VkRenderPassSubpassFeedbackCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkRenderPassSubpassFeedbackCreateInfoEXT_pNext_offsetof)+")",
    pSubpassFeedback: "u64("+callof(V.VkRenderPassSubpassFeedbackCreateInfoEXT_pSubpassFeedback_offsetof)+")",
}, callof(V.VkRenderPassSubpassFeedbackCreateInfoEXT_sizeof));


const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT = new C.CStruct("VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT_pNext_offsetof)+")",
    subpassMergeFeedback: "u32("+callof(V.VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT_subpassMergeFeedback_offsetof)+")",
}, callof(V.VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT_sizeof));


const VkMicromapBuildInfoEXT = new C.CStruct("VkMicromapBuildInfoEXT", {
    sType: "u32("+callof(V.VkMicromapBuildInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMicromapBuildInfoEXT_pNext_offsetof)+")",
    type: "u32("+callof(V.VkMicromapBuildInfoEXT_type_offsetof)+")",
    flags: "u32("+callof(V.VkMicromapBuildInfoEXT_flags_offsetof)+")",
    mode: "u32("+callof(V.VkMicromapBuildInfoEXT_mode_offsetof)+")",
    dstMicromap: "u32("+callof(V.VkMicromapBuildInfoEXT_dstMicromap_offsetof)+")",
    usageCountsCount: "u32("+callof(V.VkMicromapBuildInfoEXT_usageCountsCount_offsetof)+")",
    pUsageCounts: "u64("+callof(V.VkMicromapBuildInfoEXT_pUsageCounts_offsetof)+")",
    ppUsageCounts: "u64("+callof(V.VkMicromapBuildInfoEXT_ppUsageCounts_offsetof)+")",
    data: "u32("+callof(V.VkMicromapBuildInfoEXT_data_offsetof)+")",
    scratchData: "u64("+callof(V.VkMicromapBuildInfoEXT_scratchData_offsetof)+")",
    triangleArray: "u32("+callof(V.VkMicromapBuildInfoEXT_triangleArray_offsetof)+")",
    triangleArrayStride: "u64("+callof(V.VkMicromapBuildInfoEXT_triangleArrayStride_offsetof)+")",
}, callof(V.VkMicromapBuildInfoEXT_sizeof));


const VkMicromapCreateInfoEXT = new C.CStruct("VkMicromapCreateInfoEXT", {
    sType: "u32("+callof(V.VkMicromapCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMicromapCreateInfoEXT_pNext_offsetof)+")",
    createFlags: "u32("+callof(V.VkMicromapCreateInfoEXT_createFlags_offsetof)+")",
    buffer: "u64("+callof(V.VkMicromapCreateInfoEXT_buffer_offsetof)+")",
    offset: "u64("+callof(V.VkMicromapCreateInfoEXT_offset_offsetof)+")",
    size: "u64("+callof(V.VkMicromapCreateInfoEXT_size_offsetof)+")",
    type: "u32("+callof(V.VkMicromapCreateInfoEXT_type_offsetof)+")",
    deviceAddress: "u64("+callof(V.VkMicromapCreateInfoEXT_deviceAddress_offsetof)+")",
}, callof(V.VkMicromapCreateInfoEXT_sizeof));


const VkMicromapVersionInfoEXT = new C.CStruct("VkMicromapVersionInfoEXT", {
    sType: "u32("+callof(V.VkMicromapVersionInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMicromapVersionInfoEXT_pNext_offsetof)+")",
    pVersionData: "u64("+callof(V.VkMicromapVersionInfoEXT_pVersionData_offsetof)+")",
}, callof(V.VkMicromapVersionInfoEXT_sizeof));


const VkCopyMicromapInfoEXT = new C.CStruct("VkCopyMicromapInfoEXT", {
    sType: "u32("+callof(V.VkCopyMicromapInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCopyMicromapInfoEXT_pNext_offsetof)+")",
    src: "u32("+callof(V.VkCopyMicromapInfoEXT_src_offsetof)+")",
    dst: "u32("+callof(V.VkCopyMicromapInfoEXT_dst_offsetof)+")",
    mode: "u32("+callof(V.VkCopyMicromapInfoEXT_mode_offsetof)+")",
}, callof(V.VkCopyMicromapInfoEXT_sizeof));


const VkCopyMicromapToMemoryInfoEXT = new C.CStruct("VkCopyMicromapToMemoryInfoEXT", {
    sType: "u32("+callof(V.VkCopyMicromapToMemoryInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCopyMicromapToMemoryInfoEXT_pNext_offsetof)+")",
    src: "u32("+callof(V.VkCopyMicromapToMemoryInfoEXT_src_offsetof)+")",
    dst: "u64("+callof(V.VkCopyMicromapToMemoryInfoEXT_dst_offsetof)+")",
    mode: "u32("+callof(V.VkCopyMicromapToMemoryInfoEXT_mode_offsetof)+")",
}, callof(V.VkCopyMicromapToMemoryInfoEXT_sizeof));


const VkCopyMemoryToMicromapInfoEXT = new C.CStruct("VkCopyMemoryToMicromapInfoEXT", {
    sType: "u32("+callof(V.VkCopyMemoryToMicromapInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkCopyMemoryToMicromapInfoEXT_pNext_offsetof)+")",
    src: "u32("+callof(V.VkCopyMemoryToMicromapInfoEXT_src_offsetof)+")",
    dst: "u32("+callof(V.VkCopyMemoryToMicromapInfoEXT_dst_offsetof)+")",
    mode: "u32("+callof(V.VkCopyMemoryToMicromapInfoEXT_mode_offsetof)+")",
}, callof(V.VkCopyMemoryToMicromapInfoEXT_sizeof));


const VkMicromapBuildSizesInfoEXT = new C.CStruct("VkMicromapBuildSizesInfoEXT", {
    sType: "u32("+callof(V.VkMicromapBuildSizesInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkMicromapBuildSizesInfoEXT_pNext_offsetof)+")",
    micromapSize: "u64("+callof(V.VkMicromapBuildSizesInfoEXT_micromapSize_offsetof)+")",
    buildScratchSize: "u64("+callof(V.VkMicromapBuildSizesInfoEXT_buildScratchSize_offsetof)+")",
    discardable: "u32("+callof(V.VkMicromapBuildSizesInfoEXT_discardable_offsetof)+")",
}, callof(V.VkMicromapBuildSizesInfoEXT_sizeof));


const VkMicromapUsageEXT = new C.CStruct("VkMicromapUsageEXT", {
    count: "u32("+callof(V.VkMicromapUsageEXT_count_offsetof)+")",
    subdivisionLevel: "u32("+callof(V.VkMicromapUsageEXT_subdivisionLevel_offsetof)+")",
    format: "u32("+callof(V.VkMicromapUsageEXT_format_offsetof)+")",
}, callof(V.VkMicromapUsageEXT_sizeof));


const VkMicromapTriangleEXT = new C.CStruct("VkMicromapTriangleEXT", {
    dataOffset: "u32("+callof(V.VkMicromapTriangleEXT_dataOffset_offsetof)+")",
    subdivisionLevel: "u16("+callof(V.VkMicromapTriangleEXT_subdivisionLevel_offsetof)+")",
    format: "u16("+callof(V.VkMicromapTriangleEXT_format_offsetof)+")",
}, callof(V.VkMicromapTriangleEXT_sizeof));


const VkPhysicalDeviceOpacityMicromapFeaturesEXT = new C.CStruct("VkPhysicalDeviceOpacityMicromapFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceOpacityMicromapFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceOpacityMicromapFeaturesEXT_pNext_offsetof)+")",
    micromap: "u32("+callof(V.VkPhysicalDeviceOpacityMicromapFeaturesEXT_micromap_offsetof)+")",
    micromapCaptureReplay: "u32("+callof(V.VkPhysicalDeviceOpacityMicromapFeaturesEXT_micromapCaptureReplay_offsetof)+")",
    micromapHostCommands: "u32("+callof(V.VkPhysicalDeviceOpacityMicromapFeaturesEXT_micromapHostCommands_offsetof)+")",
}, callof(V.VkPhysicalDeviceOpacityMicromapFeaturesEXT_sizeof));


const VkPhysicalDeviceOpacityMicromapPropertiesEXT = new C.CStruct("VkPhysicalDeviceOpacityMicromapPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceOpacityMicromapPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceOpacityMicromapPropertiesEXT_pNext_offsetof)+")",
    maxOpacity2StateSubdivisionLevel: "u32("+callof(V.VkPhysicalDeviceOpacityMicromapPropertiesEXT_maxOpacity2StateSubdivisionLevel_offsetof)+")",
    maxOpacity4StateSubdivisionLevel: "u32("+callof(V.VkPhysicalDeviceOpacityMicromapPropertiesEXT_maxOpacity4StateSubdivisionLevel_offsetof)+")",
}, callof(V.VkPhysicalDeviceOpacityMicromapPropertiesEXT_sizeof));


const VkAccelerationStructureTrianglesOpacityMicromapEXT = new C.CStruct("VkAccelerationStructureTrianglesOpacityMicromapEXT", {
    sType: "u32("+callof(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_pNext_offsetof)+")",
    indexType: "u32("+callof(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_indexType_offsetof)+")",
    indexBuffer: "u32("+callof(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_indexBuffer_offsetof)+")",
    indexStride: "u64("+callof(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_indexStride_offsetof)+")",
    baseTriangle: "u32("+callof(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_baseTriangle_offsetof)+")",
    usageCountsCount: "u32("+callof(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_usageCountsCount_offsetof)+")",
    pUsageCounts: "u64("+callof(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_pUsageCounts_offsetof)+")",
    ppUsageCounts: "u64("+callof(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_ppUsageCounts_offsetof)+")",
    micromap: "u32("+callof(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_micromap_offsetof)+")",
}, callof(V.VkAccelerationStructureTrianglesOpacityMicromapEXT_sizeof));


const VkPipelinePropertiesIdentifierEXT = new C.CStruct("VkPipelinePropertiesIdentifierEXT", {
    sType: "u32("+callof(V.VkPipelinePropertiesIdentifierEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelinePropertiesIdentifierEXT_pNext_offsetof)+")",
    pipelineIdentifier: "u8["+(enums.NaN||1)+"]("+callof(V.VkPipelinePropertiesIdentifierEXT_pipelineIdentifier_offsetof)+")",
}, callof(V.VkPipelinePropertiesIdentifierEXT_sizeof));


const VkPhysicalDevicePipelinePropertiesFeaturesEXT = new C.CStruct("VkPhysicalDevicePipelinePropertiesFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDevicePipelinePropertiesFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePipelinePropertiesFeaturesEXT_pNext_offsetof)+")",
    pipelinePropertiesIdentifier: "u32("+callof(V.VkPhysicalDevicePipelinePropertiesFeaturesEXT_pipelinePropertiesIdentifier_offsetof)+")",
}, callof(V.VkPhysicalDevicePipelinePropertiesFeaturesEXT_sizeof));


const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD = new C.CStruct("VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD_pNext_offsetof)+")",
    shaderEarlyAndLateFragmentTests: "u32("+callof(V.VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD_shaderEarlyAndLateFragmentTests_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD_sizeof));


const VkExportMetalObjectCreateInfoEXT = new C.CStruct("VkExportMetalObjectCreateInfoEXT", {
    sType: "u32("+callof(V.VkExportMetalObjectCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportMetalObjectCreateInfoEXT_pNext_offsetof)+")",
    exportObjectType: "u32("+callof(V.VkExportMetalObjectCreateInfoEXT_exportObjectType_offsetof)+")",
}, callof(V.VkExportMetalObjectCreateInfoEXT_sizeof));


const VkExportMetalObjectsInfoEXT = new C.CStruct("VkExportMetalObjectsInfoEXT", {
    sType: "u32("+callof(V.VkExportMetalObjectsInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportMetalObjectsInfoEXT_pNext_offsetof)+")",
}, callof(V.VkExportMetalObjectsInfoEXT_sizeof));


const VkExportMetalDeviceInfoEXT = new C.CStruct("VkExportMetalDeviceInfoEXT", {
    sType: "u32("+callof(V.VkExportMetalDeviceInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportMetalDeviceInfoEXT_pNext_offsetof)+")",
    mtlDevice: "u32("+callof(V.VkExportMetalDeviceInfoEXT_mtlDevice_offsetof)+")",
}, callof(V.VkExportMetalDeviceInfoEXT_sizeof));


const VkExportMetalCommandQueueInfoEXT = new C.CStruct("VkExportMetalCommandQueueInfoEXT", {
    sType: "u32("+callof(V.VkExportMetalCommandQueueInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportMetalCommandQueueInfoEXT_pNext_offsetof)+")",
    queue: "u64("+callof(V.VkExportMetalCommandQueueInfoEXT_queue_offsetof)+")",
    mtlCommandQueue: "u32("+callof(V.VkExportMetalCommandQueueInfoEXT_mtlCommandQueue_offsetof)+")",
}, callof(V.VkExportMetalCommandQueueInfoEXT_sizeof));


const VkExportMetalBufferInfoEXT = new C.CStruct("VkExportMetalBufferInfoEXT", {
    sType: "u32("+callof(V.VkExportMetalBufferInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportMetalBufferInfoEXT_pNext_offsetof)+")",
    memory: "u64("+callof(V.VkExportMetalBufferInfoEXT_memory_offsetof)+")",
    mtlBuffer: "u32("+callof(V.VkExportMetalBufferInfoEXT_mtlBuffer_offsetof)+")",
}, callof(V.VkExportMetalBufferInfoEXT_sizeof));


const VkImportMetalBufferInfoEXT = new C.CStruct("VkImportMetalBufferInfoEXT", {
    sType: "u32("+callof(V.VkImportMetalBufferInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportMetalBufferInfoEXT_pNext_offsetof)+")",
    mtlBuffer: "u32("+callof(V.VkImportMetalBufferInfoEXT_mtlBuffer_offsetof)+")",
}, callof(V.VkImportMetalBufferInfoEXT_sizeof));


const VkExportMetalTextureInfoEXT = new C.CStruct("VkExportMetalTextureInfoEXT", {
    sType: "u32("+callof(V.VkExportMetalTextureInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportMetalTextureInfoEXT_pNext_offsetof)+")",
    image: "u64("+callof(V.VkExportMetalTextureInfoEXT_image_offsetof)+")",
    imageView: "u32("+callof(V.VkExportMetalTextureInfoEXT_imageView_offsetof)+")",
    bufferView: "u32("+callof(V.VkExportMetalTextureInfoEXT_bufferView_offsetof)+")",
    plane: "u32("+callof(V.VkExportMetalTextureInfoEXT_plane_offsetof)+")",
    mtlTexture: "u32("+callof(V.VkExportMetalTextureInfoEXT_mtlTexture_offsetof)+")",
}, callof(V.VkExportMetalTextureInfoEXT_sizeof));


const VkImportMetalTextureInfoEXT = new C.CStruct("VkImportMetalTextureInfoEXT", {
    sType: "u32("+callof(V.VkImportMetalTextureInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportMetalTextureInfoEXT_pNext_offsetof)+")",
    plane: "u32("+callof(V.VkImportMetalTextureInfoEXT_plane_offsetof)+")",
    mtlTexture: "u32("+callof(V.VkImportMetalTextureInfoEXT_mtlTexture_offsetof)+")",
}, callof(V.VkImportMetalTextureInfoEXT_sizeof));


const VkExportMetalIOSurfaceInfoEXT = new C.CStruct("VkExportMetalIOSurfaceInfoEXT", {
    sType: "u32("+callof(V.VkExportMetalIOSurfaceInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportMetalIOSurfaceInfoEXT_pNext_offsetof)+")",
    image: "u64("+callof(V.VkExportMetalIOSurfaceInfoEXT_image_offsetof)+")",
    ioSurface: "u32("+callof(V.VkExportMetalIOSurfaceInfoEXT_ioSurface_offsetof)+")",
}, callof(V.VkExportMetalIOSurfaceInfoEXT_sizeof));


const VkImportMetalIOSurfaceInfoEXT = new C.CStruct("VkImportMetalIOSurfaceInfoEXT", {
    sType: "u32("+callof(V.VkImportMetalIOSurfaceInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportMetalIOSurfaceInfoEXT_pNext_offsetof)+")",
    ioSurface: "u32("+callof(V.VkImportMetalIOSurfaceInfoEXT_ioSurface_offsetof)+")",
}, callof(V.VkImportMetalIOSurfaceInfoEXT_sizeof));


const VkExportMetalSharedEventInfoEXT = new C.CStruct("VkExportMetalSharedEventInfoEXT", {
    sType: "u32("+callof(V.VkExportMetalSharedEventInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkExportMetalSharedEventInfoEXT_pNext_offsetof)+")",
    semaphore: "u64("+callof(V.VkExportMetalSharedEventInfoEXT_semaphore_offsetof)+")",
    event: "u32("+callof(V.VkExportMetalSharedEventInfoEXT_event_offsetof)+")",
    mtlSharedEvent: "u32("+callof(V.VkExportMetalSharedEventInfoEXT_mtlSharedEvent_offsetof)+")",
}, callof(V.VkExportMetalSharedEventInfoEXT_sizeof));


const VkImportMetalSharedEventInfoEXT = new C.CStruct("VkImportMetalSharedEventInfoEXT", {
    sType: "u32("+callof(V.VkImportMetalSharedEventInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImportMetalSharedEventInfoEXT_pNext_offsetof)+")",
    mtlSharedEvent: "u32("+callof(V.VkImportMetalSharedEventInfoEXT_mtlSharedEvent_offsetof)+")",
}, callof(V.VkImportMetalSharedEventInfoEXT_sizeof));


const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT = new C.CStruct("VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT_pNext_offsetof)+")",
    nonSeamlessCubeMap: "u32("+callof(V.VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT_nonSeamlessCubeMap_offsetof)+")",
}, callof(V.VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT_sizeof));


const VkPhysicalDevicePipelineRobustnessFeaturesEXT = new C.CStruct("VkPhysicalDevicePipelineRobustnessFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDevicePipelineRobustnessFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePipelineRobustnessFeaturesEXT_pNext_offsetof)+")",
    pipelineRobustness: "u32("+callof(V.VkPhysicalDevicePipelineRobustnessFeaturesEXT_pipelineRobustness_offsetof)+")",
}, callof(V.VkPhysicalDevicePipelineRobustnessFeaturesEXT_sizeof));


const VkPipelineRobustnessCreateInfoEXT = new C.CStruct("VkPipelineRobustnessCreateInfoEXT", {
    sType: "u32("+callof(V.VkPipelineRobustnessCreateInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPipelineRobustnessCreateInfoEXT_pNext_offsetof)+")",
    storageBuffers: "u32("+callof(V.VkPipelineRobustnessCreateInfoEXT_storageBuffers_offsetof)+")",
    uniformBuffers: "u32("+callof(V.VkPipelineRobustnessCreateInfoEXT_uniformBuffers_offsetof)+")",
    vertexInputs: "u32("+callof(V.VkPipelineRobustnessCreateInfoEXT_vertexInputs_offsetof)+")",
    images: "u32("+callof(V.VkPipelineRobustnessCreateInfoEXT_images_offsetof)+")",
}, callof(V.VkPipelineRobustnessCreateInfoEXT_sizeof));


const VkPhysicalDevicePipelineRobustnessPropertiesEXT = new C.CStruct("VkPhysicalDevicePipelineRobustnessPropertiesEXT", {
    sType: "u32("+callof(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_pNext_offsetof)+")",
    defaultRobustnessStorageBuffers: "u32("+callof(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_defaultRobustnessStorageBuffers_offsetof)+")",
    defaultRobustnessUniformBuffers: "u32("+callof(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_defaultRobustnessUniformBuffers_offsetof)+")",
    defaultRobustnessVertexInputs: "u32("+callof(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_defaultRobustnessVertexInputs_offsetof)+")",
    defaultRobustnessImages: "u32("+callof(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_defaultRobustnessImages_offsetof)+")",
}, callof(V.VkPhysicalDevicePipelineRobustnessPropertiesEXT_sizeof));


const VkImageViewSampleWeightCreateInfoQCOM = new C.CStruct("VkImageViewSampleWeightCreateInfoQCOM", {
    sType: "u32("+callof(V.VkImageViewSampleWeightCreateInfoQCOM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkImageViewSampleWeightCreateInfoQCOM_pNext_offsetof)+")",
    filterCenter: "VkOffset2D("+callof(V.VkImageViewSampleWeightCreateInfoQCOM_filterCenter_offsetof)+")",
    filterSize: "VkExtent2D("+callof(V.VkImageViewSampleWeightCreateInfoQCOM_filterSize_offsetof)+")",
    numPhases: "u32("+callof(V.VkImageViewSampleWeightCreateInfoQCOM_numPhases_offsetof)+")",
}, callof(V.VkImageViewSampleWeightCreateInfoQCOM_sizeof));


const VkPhysicalDeviceImageProcessingFeaturesQCOM = new C.CStruct("VkPhysicalDeviceImageProcessingFeaturesQCOM", {
    sType: "u32("+callof(V.VkPhysicalDeviceImageProcessingFeaturesQCOM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceImageProcessingFeaturesQCOM_pNext_offsetof)+")",
    textureSampleWeighted: "u32("+callof(V.VkPhysicalDeviceImageProcessingFeaturesQCOM_textureSampleWeighted_offsetof)+")",
    textureBoxFilter: "u32("+callof(V.VkPhysicalDeviceImageProcessingFeaturesQCOM_textureBoxFilter_offsetof)+")",
    textureBlockMatch: "u32("+callof(V.VkPhysicalDeviceImageProcessingFeaturesQCOM_textureBlockMatch_offsetof)+")",
}, callof(V.VkPhysicalDeviceImageProcessingFeaturesQCOM_sizeof));


const VkPhysicalDeviceImageProcessingPropertiesQCOM = new C.CStruct("VkPhysicalDeviceImageProcessingPropertiesQCOM", {
    sType: "u32("+callof(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_pNext_offsetof)+")",
    maxWeightFilterPhases: "u32("+callof(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_maxWeightFilterPhases_offsetof)+")",
    maxWeightFilterDimension: "VkExtent2D("+callof(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_maxWeightFilterDimension_offsetof)+")",
    maxBlockMatchRegion: "VkExtent2D("+callof(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_maxBlockMatchRegion_offsetof)+")",
    maxBoxFilterBlockSize: "VkExtent2D("+callof(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_maxBoxFilterBlockSize_offsetof)+")",
}, callof(V.VkPhysicalDeviceImageProcessingPropertiesQCOM_sizeof));


const VkPhysicalDeviceTilePropertiesFeaturesQCOM = new C.CStruct("VkPhysicalDeviceTilePropertiesFeaturesQCOM", {
    sType: "u32("+callof(V.VkPhysicalDeviceTilePropertiesFeaturesQCOM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceTilePropertiesFeaturesQCOM_pNext_offsetof)+")",
    tileProperties: "u32("+callof(V.VkPhysicalDeviceTilePropertiesFeaturesQCOM_tileProperties_offsetof)+")",
}, callof(V.VkPhysicalDeviceTilePropertiesFeaturesQCOM_sizeof));


const VkTilePropertiesQCOM = new C.CStruct("VkTilePropertiesQCOM", {
    sType: "u32("+callof(V.VkTilePropertiesQCOM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkTilePropertiesQCOM_pNext_offsetof)+")",
    tileSize: "u32("+callof(V.VkTilePropertiesQCOM_tileSize_offsetof)+")",
    apronSize: "VkExtent2D("+callof(V.VkTilePropertiesQCOM_apronSize_offsetof)+")",
    origin: "VkOffset2D("+callof(V.VkTilePropertiesQCOM_origin_offsetof)+")",
}, callof(V.VkTilePropertiesQCOM_sizeof));


const VkPhysicalDeviceAmigoProfilingFeaturesSEC = new C.CStruct("VkPhysicalDeviceAmigoProfilingFeaturesSEC", {
    sType: "u32("+callof(V.VkPhysicalDeviceAmigoProfilingFeaturesSEC_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceAmigoProfilingFeaturesSEC_pNext_offsetof)+")",
    amigoProfiling: "u32("+callof(V.VkPhysicalDeviceAmigoProfilingFeaturesSEC_amigoProfiling_offsetof)+")",
}, callof(V.VkPhysicalDeviceAmigoProfilingFeaturesSEC_sizeof));


const VkAmigoProfilingSubmitInfoSEC = new C.CStruct("VkAmigoProfilingSubmitInfoSEC", {
    sType: "u32("+callof(V.VkAmigoProfilingSubmitInfoSEC_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkAmigoProfilingSubmitInfoSEC_pNext_offsetof)+")",
    firstDrawTimestamp: "u64("+callof(V.VkAmigoProfilingSubmitInfoSEC_firstDrawTimestamp_offsetof)+")",
    swapBufferTimestamp: "u64("+callof(V.VkAmigoProfilingSubmitInfoSEC_swapBufferTimestamp_offsetof)+")",
}, callof(V.VkAmigoProfilingSubmitInfoSEC_sizeof));


const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT = new C.CStruct("VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT_pNext_offsetof)+")",
    attachmentFeedbackLoopLayout: "u32("+callof(V.VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT_attachmentFeedbackLoopLayout_offsetof)+")",
}, callof(V.VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT_sizeof));


const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT = new C.CStruct("VkPhysicalDeviceDepthClampZeroOneFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceDepthClampZeroOneFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceDepthClampZeroOneFeaturesEXT_pNext_offsetof)+")",
    depthClampZeroOne: "u32("+callof(V.VkPhysicalDeviceDepthClampZeroOneFeaturesEXT_depthClampZeroOne_offsetof)+")",
}, callof(V.VkPhysicalDeviceDepthClampZeroOneFeaturesEXT_sizeof));


const VkPhysicalDeviceAddressBindingReportFeaturesEXT = new C.CStruct("VkPhysicalDeviceAddressBindingReportFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceAddressBindingReportFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceAddressBindingReportFeaturesEXT_pNext_offsetof)+")",
    reportAddressBinding: "u32("+callof(V.VkPhysicalDeviceAddressBindingReportFeaturesEXT_reportAddressBinding_offsetof)+")",
}, callof(V.VkPhysicalDeviceAddressBindingReportFeaturesEXT_sizeof));


const VkDeviceAddressBindingCallbackDataEXT = new C.CStruct("VkDeviceAddressBindingCallbackDataEXT", {
    sType: "u32("+callof(V.VkDeviceAddressBindingCallbackDataEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceAddressBindingCallbackDataEXT_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkDeviceAddressBindingCallbackDataEXT_flags_offsetof)+")",
    baseAddress: "u64("+callof(V.VkDeviceAddressBindingCallbackDataEXT_baseAddress_offsetof)+")",
    size: "u64("+callof(V.VkDeviceAddressBindingCallbackDataEXT_size_offsetof)+")",
    bindingType: "u32("+callof(V.VkDeviceAddressBindingCallbackDataEXT_bindingType_offsetof)+")",
}, callof(V.VkDeviceAddressBindingCallbackDataEXT_sizeof));


const VkPhysicalDeviceOpticalFlowFeaturesNV = new C.CStruct("VkPhysicalDeviceOpticalFlowFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceOpticalFlowFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceOpticalFlowFeaturesNV_pNext_offsetof)+")",
    opticalFlow: "u32("+callof(V.VkPhysicalDeviceOpticalFlowFeaturesNV_opticalFlow_offsetof)+")",
}, callof(V.VkPhysicalDeviceOpticalFlowFeaturesNV_sizeof));


const VkPhysicalDeviceOpticalFlowPropertiesNV = new C.CStruct("VkPhysicalDeviceOpticalFlowPropertiesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_pNext_offsetof)+")",
    supportedOutputGridSizes: "u32("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_supportedOutputGridSizes_offsetof)+")",
    supportedHintGridSizes: "u32("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_supportedHintGridSizes_offsetof)+")",
    hintSupported: "u32("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_hintSupported_offsetof)+")",
    costSupported: "u32("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_costSupported_offsetof)+")",
    bidirectionalFlowSupported: "u32("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_bidirectionalFlowSupported_offsetof)+")",
    globalFlowSupported: "u32("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_globalFlowSupported_offsetof)+")",
    minWidth: "u32("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_minWidth_offsetof)+")",
    minHeight: "u32("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_minHeight_offsetof)+")",
    maxWidth: "u32("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_maxWidth_offsetof)+")",
    maxHeight: "u32("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_maxHeight_offsetof)+")",
    maxNumRegionsOfInterest: "u32("+callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_maxNumRegionsOfInterest_offsetof)+")",
}, callof(V.VkPhysicalDeviceOpticalFlowPropertiesNV_sizeof));


const VkOpticalFlowImageFormatInfoNV = new C.CStruct("VkOpticalFlowImageFormatInfoNV", {
    sType: "u32("+callof(V.VkOpticalFlowImageFormatInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkOpticalFlowImageFormatInfoNV_pNext_offsetof)+")",
    usage: "u32("+callof(V.VkOpticalFlowImageFormatInfoNV_usage_offsetof)+")",
}, callof(V.VkOpticalFlowImageFormatInfoNV_sizeof));


const VkOpticalFlowImageFormatPropertiesNV = new C.CStruct("VkOpticalFlowImageFormatPropertiesNV", {
    sType: "u32("+callof(V.VkOpticalFlowImageFormatPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkOpticalFlowImageFormatPropertiesNV_pNext_offsetof)+")",
    format: "u32("+callof(V.VkOpticalFlowImageFormatPropertiesNV_format_offsetof)+")",
}, callof(V.VkOpticalFlowImageFormatPropertiesNV_sizeof));


const VkOpticalFlowSessionCreateInfoNV = new C.CStruct("VkOpticalFlowSessionCreateInfoNV", {
    sType: "u32("+callof(V.VkOpticalFlowSessionCreateInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkOpticalFlowSessionCreateInfoNV_pNext_offsetof)+")",
    width: "u32("+callof(V.VkOpticalFlowSessionCreateInfoNV_width_offsetof)+")",
    height: "u32("+callof(V.VkOpticalFlowSessionCreateInfoNV_height_offsetof)+")",
    imageFormat: "u32("+callof(V.VkOpticalFlowSessionCreateInfoNV_imageFormat_offsetof)+")",
    flowVectorFormat: "u32("+callof(V.VkOpticalFlowSessionCreateInfoNV_flowVectorFormat_offsetof)+")",
    costFormat: "u32("+callof(V.VkOpticalFlowSessionCreateInfoNV_costFormat_offsetof)+")",
    outputGridSize: "u32("+callof(V.VkOpticalFlowSessionCreateInfoNV_outputGridSize_offsetof)+")",
    hintGridSize: "u32("+callof(V.VkOpticalFlowSessionCreateInfoNV_hintGridSize_offsetof)+")",
    performanceLevel: "u32("+callof(V.VkOpticalFlowSessionCreateInfoNV_performanceLevel_offsetof)+")",
    flags: "u32("+callof(V.VkOpticalFlowSessionCreateInfoNV_flags_offsetof)+")",
}, callof(V.VkOpticalFlowSessionCreateInfoNV_sizeof));


const VkOpticalFlowSessionCreatePrivateDataInfoNV = new C.CStruct("VkOpticalFlowSessionCreatePrivateDataInfoNV", {
    sType: "u32("+callof(V.VkOpticalFlowSessionCreatePrivateDataInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkOpticalFlowSessionCreatePrivateDataInfoNV_pNext_offsetof)+")",
    id: "u32("+callof(V.VkOpticalFlowSessionCreatePrivateDataInfoNV_id_offsetof)+")",
    size: "u32("+callof(V.VkOpticalFlowSessionCreatePrivateDataInfoNV_size_offsetof)+")",
    pPrivateData: "u64("+callof(V.VkOpticalFlowSessionCreatePrivateDataInfoNV_pPrivateData_offsetof)+")",
}, callof(V.VkOpticalFlowSessionCreatePrivateDataInfoNV_sizeof));


const VkOpticalFlowExecuteInfoNV = new C.CStruct("VkOpticalFlowExecuteInfoNV", {
    sType: "u32("+callof(V.VkOpticalFlowExecuteInfoNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkOpticalFlowExecuteInfoNV_pNext_offsetof)+")",
    flags: "u32("+callof(V.VkOpticalFlowExecuteInfoNV_flags_offsetof)+")",
    regionCount: "u32("+callof(V.VkOpticalFlowExecuteInfoNV_regionCount_offsetof)+")",
    pRegions: "u64("+callof(V.VkOpticalFlowExecuteInfoNV_pRegions_offsetof)+")",
}, callof(V.VkOpticalFlowExecuteInfoNV_sizeof));


const VkPhysicalDeviceFaultFeaturesEXT = new C.CStruct("VkPhysicalDeviceFaultFeaturesEXT", {
    sType: "u32("+callof(V.VkPhysicalDeviceFaultFeaturesEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceFaultFeaturesEXT_pNext_offsetof)+")",
    deviceFault: "u32("+callof(V.VkPhysicalDeviceFaultFeaturesEXT_deviceFault_offsetof)+")",
    deviceFaultVendorBinary: "u32("+callof(V.VkPhysicalDeviceFaultFeaturesEXT_deviceFaultVendorBinary_offsetof)+")",
}, callof(V.VkPhysicalDeviceFaultFeaturesEXT_sizeof));


const VkDeviceFaultAddressInfoEXT = new C.CStruct("VkDeviceFaultAddressInfoEXT", {
    addressType: "u32("+callof(V.VkDeviceFaultAddressInfoEXT_addressType_offsetof)+")",
    reportedAddress: "u64("+callof(V.VkDeviceFaultAddressInfoEXT_reportedAddress_offsetof)+")",
    addressPrecision: "u64("+callof(V.VkDeviceFaultAddressInfoEXT_addressPrecision_offsetof)+")",
}, callof(V.VkDeviceFaultAddressInfoEXT_sizeof));


const VkDeviceFaultVendorInfoEXT = new C.CStruct("VkDeviceFaultVendorInfoEXT", {
    description: "u8["+(enums.NaN||1)+"]("+callof(V.VkDeviceFaultVendorInfoEXT_description_offsetof)+")",
    vendorFaultCode: "u64("+callof(V.VkDeviceFaultVendorInfoEXT_vendorFaultCode_offsetof)+")",
    vendorFaultData: "u64("+callof(V.VkDeviceFaultVendorInfoEXT_vendorFaultData_offsetof)+")",
}, callof(V.VkDeviceFaultVendorInfoEXT_sizeof));


const VkDeviceFaultCountsEXT = new C.CStruct("VkDeviceFaultCountsEXT", {
    sType: "u32("+callof(V.VkDeviceFaultCountsEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceFaultCountsEXT_pNext_offsetof)+")",
    addressInfoCount: "u32("+callof(V.VkDeviceFaultCountsEXT_addressInfoCount_offsetof)+")",
    vendorInfoCount: "u32("+callof(V.VkDeviceFaultCountsEXT_vendorInfoCount_offsetof)+")",
    vendorBinarySize: "u64("+callof(V.VkDeviceFaultCountsEXT_vendorBinarySize_offsetof)+")",
}, callof(V.VkDeviceFaultCountsEXT_sizeof));


const VkDeviceFaultInfoEXT = new C.CStruct("VkDeviceFaultInfoEXT", {
    sType: "u32("+callof(V.VkDeviceFaultInfoEXT_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkDeviceFaultInfoEXT_pNext_offsetof)+")",
    description: "u8["+(enums.NaN||1)+"]("+callof(V.VkDeviceFaultInfoEXT_description_offsetof)+")",
    pAddressInfos: "u64("+callof(V.VkDeviceFaultInfoEXT_pAddressInfos_offsetof)+")",
    pVendorInfos: "u64("+callof(V.VkDeviceFaultInfoEXT_pVendorInfos_offsetof)+")",
    pVendorBinaryData: "u64("+callof(V.VkDeviceFaultInfoEXT_pVendorBinaryData_offsetof)+")",
}, callof(V.VkDeviceFaultInfoEXT_sizeof));


const VkDeviceFaultVendorBinaryHeaderVersionOneEXT = new C.CStruct("VkDeviceFaultVendorBinaryHeaderVersionOneEXT", {
    headerSize: "u32("+callof(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_headerSize_offsetof)+")",
    headerVersion: "u32("+callof(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_headerVersion_offsetof)+")",
    vendorID: "u32("+callof(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_vendorID_offsetof)+")",
    deviceID: "u32("+callof(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_deviceID_offsetof)+")",
    driverVersion: "u32("+callof(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_driverVersion_offsetof)+")",
    pipelineCacheUUID: "u8["+(enums.NaN||1)+"]("+callof(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_pipelineCacheUUID_offsetof)+")",
    applicationNameOffset: "u32("+callof(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_applicationNameOffset_offsetof)+")",
    applicationVersion: "u32("+callof(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_applicationVersion_offsetof)+")",
    engineNameOffset: "u32("+callof(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_engineNameOffset_offsetof)+")",
}, callof(V.VkDeviceFaultVendorBinaryHeaderVersionOneEXT_sizeof));


const VkDecompressMemoryRegionNV = new C.CStruct("VkDecompressMemoryRegionNV", {
    srcAddress: "u64("+callof(V.VkDecompressMemoryRegionNV_srcAddress_offsetof)+")",
    dstAddress: "u64("+callof(V.VkDecompressMemoryRegionNV_dstAddress_offsetof)+")",
    compressedSize: "u64("+callof(V.VkDecompressMemoryRegionNV_compressedSize_offsetof)+")",
    decompressedSize: "u64("+callof(V.VkDecompressMemoryRegionNV_decompressedSize_offsetof)+")",
    decompressionMethod: "u32("+callof(V.VkDecompressMemoryRegionNV_decompressionMethod_offsetof)+")",
}, callof(V.VkDecompressMemoryRegionNV_sizeof));


const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM = new C.CStruct("VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM_pNext_offsetof)+")",
    shaderCoreMask: "u64("+callof(V.VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM_shaderCoreMask_offsetof)+")",
    shaderCoreCount: "u32("+callof(V.VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM_shaderCoreCount_offsetof)+")",
    shaderWarpsPerCore: "u32("+callof(V.VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM_shaderWarpsPerCore_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM_sizeof));


const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM = new C.CStruct("VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM", {
    sType: "u32("+callof(V.VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM_pNext_offsetof)+")",
    shaderCoreBuiltins: "u32("+callof(V.VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM_shaderCoreBuiltins_offsetof)+")",
}, callof(V.VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM_sizeof));


const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV = new C.CStruct("VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV_pNext_offsetof)+")",
    rayTracingInvocationReorder: "u32("+callof(V.VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV_rayTracingInvocationReorder_offsetof)+")",
}, callof(V.VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV_sizeof));


const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV = new C.CStruct("VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV", {
    sType: "u32("+callof(V.VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV_sType_offsetof)+")",
    pNext: "u64("+callof(V.VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV_pNext_offsetof)+")",
    rayTracingInvocationReorderReorderingHint: "u32("+callof(V.VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV_rayTracingInvocationReorderReorderingHint_offsetof)+")",
}, callof(V.VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV_sizeof));


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
