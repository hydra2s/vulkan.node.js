
import {default as enums} from "./vulkan-enums.js";
import * as T from "struct-buffer";
const C = T.default;
const uint24_t = C.uint8_t[3];//C.registerType("uint24_t", 3, false);
const  int24_t = C.uint8_t[3];//C.registerType(" int24_t", 3, false);

const VK_MAKE_API_VERSION = (variant, major, minor, patch) => {
    return ((((variant)) << 29) | (((major)) << 22) | (((minor)) << 12) | ((patch)));
};

//

const VkBaseOutStructure = new T.StructBuffer("VkBaseOutStructure", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
});


const VkBaseInStructure = new T.StructBuffer("VkBaseInStructure", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
});


const VkOffset2D = new T.StructBuffer("VkOffset2D", {
    x: C.int32_t,
    y: C.int32_t,
});


const VkOffset3D = new T.StructBuffer("VkOffset3D", {
    x: C.int32_t,
    y: C.int32_t,
    z: C.int32_t,
});


const VkExtent2D = new T.StructBuffer("VkExtent2D", {
    width: C.uint32_t,
    height: C.uint32_t,
});


const VkExtent3D = new T.StructBuffer("VkExtent3D", {
    width: C.uint32_t,
    height: C.uint32_t,
    depth: C.uint32_t,
});


const VkViewport = new T.StructBuffer("VkViewport", {
    x: C.float,
    y: C.float,
    width: C.float,
    height: C.float,
    minDepth: C.float,
    maxDepth: C.float,
});


const VkRect2D = new T.StructBuffer("VkRect2D", {
    offset: VkOffset2D,
    extent: VkExtent2D,
});


const VkClearRect = new T.StructBuffer("VkClearRect", {
    rect: VkRect2D,
    baseArrayLayer: C.uint32_t,
    layerCount: C.uint32_t,
});


const VkComponentMapping = new T.StructBuffer("VkComponentMapping", {
    r: C.uint32_t,
    g: C.uint32_t,
    b: C.uint32_t,
    a: C.uint32_t,
});


const VkPhysicalDeviceProperties = new T.StructBuffer("VkPhysicalDeviceProperties", {
    apiVersion: C.uint32_t,
    driverVersion: C.uint32_t,
    vendorID: C.uint32_t,
    deviceID: C.uint32_t,
    deviceType: C.uint32_t,
    deviceName: C.uint8_t[enums.VK_MAX_PHYSICAL_DEVICE_NAME_SIZE],
    pipelineCacheUUID: C.uint8_t[enums.VK_UUID_SIZE],
    limits: C.uint32_t,
    sparseProperties: C.uint32_t,
});


const VkExtensionProperties = new T.StructBuffer("VkExtensionProperties", {
    extensionName: C.uint8_t[enums.VK_MAX_EXTENSION_NAME_SIZE],
    specVersion: C.uint32_t,
});


const VkLayerProperties = new T.StructBuffer("VkLayerProperties", {
    layerName: C.uint8_t[enums.VK_MAX_EXTENSION_NAME_SIZE],
    specVersion: C.uint32_t,
    implementationVersion: C.uint32_t,
    description: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
});


const VkApplicationInfo = new T.StructBuffer("VkApplicationInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pApplicationName: C.uint64_t,
    applicationVersion: C.uint32_t,
    pEngineName: C.uint64_t,
    engineVersion: C.uint32_t,
    apiVersion: C.uint32_t,
});


const VkAllocationCallbacks = new T.StructBuffer("VkAllocationCallbacks", {
    pUserData: C.uint64_t,
    pfnAllocation: C.uint32_t,
    pfnReallocation: C.uint32_t,
    pfnFree: C.uint32_t,
    pfnInternalAllocation: C.uint32_t,
    pfnInternalFree: C.uint32_t,
});


const VkDeviceQueueCreateInfo = new T.StructBuffer("VkDeviceQueueCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    queueFamilyIndex: C.uint32_t,
    queueCount: C.uint32_t,
    pQueuePriorities: C.uint64_t,
});


const VkDeviceCreateInfo = new T.StructBuffer("VkDeviceCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    queueCreateInfoCount: C.uint32_t,
    pQueueCreateInfos: C.uint64_t,
    enabledLayerCount: C.uint32_t,
    ppEnabledLayerNames: C.uint64_t,
    enabledExtensionCount: C.uint32_t,
    ppEnabledExtensionNames: C.uint64_t,
    pEnabledFeatures: C.uint64_t,
});


const VkInstanceCreateInfo = new T.StructBuffer("VkInstanceCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    pApplicationInfo: C.uint64_t,
    enabledLayerCount: C.uint32_t,
    ppEnabledLayerNames: C.uint64_t,
    enabledExtensionCount: C.uint32_t,
    ppEnabledExtensionNames: C.uint64_t,
});


const VkQueueFamilyProperties = new T.StructBuffer("VkQueueFamilyProperties", {
    queueFlags: C.uint32_t,
    queueCount: C.uint32_t,
    timestampValidBits: C.uint32_t,
    minImageTransferGranularity: C.uint32_t,
});


const VkPhysicalDeviceMemoryProperties = new T.StructBuffer("VkPhysicalDeviceMemoryProperties", {
    memoryTypeCount: C.uint32_t,
    memoryTypes: C.uint32_t,
    memoryHeapCount: C.uint32_t,
    memoryHeaps: C.uint32_t,
});


const VkMemoryAllocateInfo = new T.StructBuffer("VkMemoryAllocateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    allocationSize: C.uint64_t,
    memoryTypeIndex: C.uint32_t,
});


const VkMemoryRequirements = new T.StructBuffer("VkMemoryRequirements", {
    size: C.uint64_t,
    alignment: C.uint64_t,
    memoryTypeBits: C.uint32_t,
});


const VkSparseImageFormatProperties = new T.StructBuffer("VkSparseImageFormatProperties", {
    aspectMask: C.uint32_t,
    imageGranularity: C.uint32_t,
    flags: C.uint32_t,
});


const VkSparseImageMemoryRequirements = new T.StructBuffer("VkSparseImageMemoryRequirements", {
    formatProperties: C.uint32_t,
    imageMipTailFirstLod: C.uint32_t,
    imageMipTailSize: C.uint64_t,
    imageMipTailOffset: C.uint64_t,
    imageMipTailStride: C.uint64_t,
});


const VkMemoryType = new T.StructBuffer("VkMemoryType", {
    propertyFlags: C.uint32_t,
    heapIndex: C.uint32_t,
});


const VkMemoryHeap = new T.StructBuffer("VkMemoryHeap", {
    size: C.uint64_t,
    flags: C.uint32_t,
});


const VkMappedMemoryRange = new T.StructBuffer("VkMappedMemoryRange", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memory: C.uint64_t,
    offset: C.uint64_t,
    size: C.uint64_t,
});


const VkFormatProperties = new T.StructBuffer("VkFormatProperties", {
    linearTilingFeatures: C.uint32_t,
    optimalTilingFeatures: C.uint32_t,
    bufferFeatures: C.uint32_t,
});


const VkImageFormatProperties = new T.StructBuffer("VkImageFormatProperties", {
    maxExtent: C.uint32_t,
    maxMipLevels: C.uint32_t,
    maxArrayLayers: C.uint32_t,
    sampleCounts: C.uint32_t,
    maxResourceSize: C.uint64_t,
});


const VkDescriptorBufferInfo = new T.StructBuffer("VkDescriptorBufferInfo", {
    buffer: C.uint64_t,
    offset: C.uint64_t,
    range: C.uint64_t,
});


const VkDescriptorImageInfo = new T.StructBuffer("VkDescriptorImageInfo", {
    sampler: C.uint32_t,
    imageView: C.uint32_t,
    imageLayout: C.uint32_t,
});


const VkWriteDescriptorSet = new T.StructBuffer("VkWriteDescriptorSet", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    dstSet: C.uint32_t,
    dstBinding: C.uint32_t,
    dstArrayElement: C.uint32_t,
    descriptorCount: C.uint32_t,
    descriptorType: C.uint32_t,
    pImageInfo: C.uint64_t,
    pBufferInfo: C.uint64_t,
    pTexelBufferView: C.uint64_t,
});


const VkCopyDescriptorSet = new T.StructBuffer("VkCopyDescriptorSet", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcSet: C.uint32_t,
    srcBinding: C.uint32_t,
    srcArrayElement: C.uint32_t,
    dstSet: C.uint32_t,
    dstBinding: C.uint32_t,
    dstArrayElement: C.uint32_t,
    descriptorCount: C.uint32_t,
});


const VkBufferCreateInfo = new T.StructBuffer("VkBufferCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    size: C.uint64_t,
    usage: C.uint32_t,
    sharingMode: C.uint32_t,
    queueFamilyIndexCount: C.uint32_t,
    pQueueFamilyIndices: C.uint64_t,
});


const VkBufferViewCreateInfo = new T.StructBuffer("VkBufferViewCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    buffer: C.uint64_t,
    format: C.uint32_t,
    offset: C.uint64_t,
    range: C.uint64_t,
});


const VkImageSubresource = new T.StructBuffer("VkImageSubresource", {
    aspectMask: C.uint32_t,
    mipLevel: C.uint32_t,
    arrayLayer: C.uint32_t,
});


const VkImageSubresourceLayers = new T.StructBuffer("VkImageSubresourceLayers", {
    aspectMask: C.uint32_t,
    mipLevel: C.uint32_t,
    baseArrayLayer: C.uint32_t,
    layerCount: C.uint32_t,
});


const VkImageSubresourceRange = new T.StructBuffer("VkImageSubresourceRange", {
    aspectMask: C.uint32_t,
    baseMipLevel: C.uint32_t,
    levelCount: C.uint32_t,
    baseArrayLayer: C.uint32_t,
    layerCount: C.uint32_t,
});


const VkMemoryBarrier = new T.StructBuffer("VkMemoryBarrier", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcAccessMask: C.uint32_t,
    dstAccessMask: C.uint32_t,
});


const VkBufferMemoryBarrier = new T.StructBuffer("VkBufferMemoryBarrier", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcAccessMask: C.uint32_t,
    dstAccessMask: C.uint32_t,
    srcQueueFamilyIndex: C.uint32_t,
    dstQueueFamilyIndex: C.uint32_t,
    buffer: C.uint64_t,
    offset: C.uint64_t,
    size: C.uint64_t,
});


const VkImageMemoryBarrier = new T.StructBuffer("VkImageMemoryBarrier", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcAccessMask: C.uint32_t,
    dstAccessMask: C.uint32_t,
    oldLayout: C.uint32_t,
    newLayout: C.uint32_t,
    srcQueueFamilyIndex: C.uint32_t,
    dstQueueFamilyIndex: C.uint32_t,
    image: C.uint64_t,
    subresourceRange: C.uint32_t,
});


const VkImageCreateInfo = new T.StructBuffer("VkImageCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    imageType: C.uint32_t,
    format: C.uint32_t,
    extent: C.uint32_t,
    mipLevels: C.uint32_t,
    arrayLayers: C.uint32_t,
    samples: C.uint32_t,
    tiling: C.uint32_t,
    usage: C.uint32_t,
    sharingMode: C.uint32_t,
    queueFamilyIndexCount: C.uint32_t,
    pQueueFamilyIndices: C.uint64_t,
    initialLayout: C.uint32_t,
});


const VkSubresourceLayout = new T.StructBuffer("VkSubresourceLayout", {
    offset: C.uint64_t,
    size: C.uint64_t,
    rowPitch: C.uint64_t,
    arrayPitch: C.uint64_t,
    depthPitch: C.uint64_t,
});


const VkImageViewCreateInfo = new T.StructBuffer("VkImageViewCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    image: C.uint64_t,
    viewType: C.uint32_t,
    format: C.uint32_t,
    components: C.uint32_t,
    subresourceRange: C.uint32_t,
});


const VkBufferCopy = new T.StructBuffer("VkBufferCopy", {
    srcOffset: C.uint64_t,
    dstOffset: C.uint64_t,
    size: C.uint64_t,
});


const VkSparseMemoryBind = new T.StructBuffer("VkSparseMemoryBind", {
    resourceOffset: C.uint64_t,
    size: C.uint64_t,
    memory: C.uint64_t,
    memoryOffset: C.uint64_t,
    flags: C.uint32_t,
});


const VkSparseImageMemoryBind = new T.StructBuffer("VkSparseImageMemoryBind", {
    subresource: C.uint32_t,
    offset: C.uint32_t,
    extent: C.uint32_t,
    memory: C.uint64_t,
    memoryOffset: C.uint64_t,
    flags: C.uint32_t,
});


const VkSparseBufferMemoryBindInfo = new T.StructBuffer("VkSparseBufferMemoryBindInfo", {
    buffer: C.uint64_t,
    bindCount: C.uint32_t,
    pBinds: C.uint64_t,
});


const VkSparseImageOpaqueMemoryBindInfo = new T.StructBuffer("VkSparseImageOpaqueMemoryBindInfo", {
    image: C.uint64_t,
    bindCount: C.uint32_t,
    pBinds: C.uint64_t,
});


const VkSparseImageMemoryBindInfo = new T.StructBuffer("VkSparseImageMemoryBindInfo", {
    image: C.uint64_t,
    bindCount: C.uint32_t,
    pBinds: C.uint64_t,
});


const VkBindSparseInfo = new T.StructBuffer("VkBindSparseInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    waitSemaphoreCount: C.uint32_t,
    pWaitSemaphores: C.uint64_t,
    bufferBindCount: C.uint32_t,
    pBufferBinds: C.uint64_t,
    imageOpaqueBindCount: C.uint32_t,
    pImageOpaqueBinds: C.uint64_t,
    imageBindCount: C.uint32_t,
    pImageBinds: C.uint64_t,
    signalSemaphoreCount: C.uint32_t,
    pSignalSemaphores: C.uint64_t,
});


const VkImageCopy = new T.StructBuffer("VkImageCopy", {
    srcSubresource: C.uint32_t,
    srcOffset: C.uint32_t,
    dstSubresource: C.uint32_t,
    dstOffset: C.uint32_t,
    extent: C.uint32_t,
});


const VkImageBlit = new T.StructBuffer("VkImageBlit", {
    srcSubresource: C.uint32_t,
    srcOffsets: C.uint32_t,
    dstSubresource: C.uint32_t,
    dstOffsets: C.uint32_t,
});


const VkBufferImageCopy = new T.StructBuffer("VkBufferImageCopy", {
    bufferOffset: C.uint64_t,
    bufferRowLength: C.uint32_t,
    bufferImageHeight: C.uint32_t,
    imageSubresource: C.uint32_t,
    imageOffset: C.uint32_t,
    imageExtent: C.uint32_t,
});


const VkCopyMemoryIndirectCommandNV = new T.StructBuffer("VkCopyMemoryIndirectCommandNV", {
    srcAddress: C.uint64_t,
    dstAddress: C.uint64_t,
    size: C.uint64_t,
});


const VkCopyMemoryToImageIndirectCommandNV = new T.StructBuffer("VkCopyMemoryToImageIndirectCommandNV", {
    srcAddress: C.uint64_t,
    bufferRowLength: C.uint32_t,
    bufferImageHeight: C.uint32_t,
    imageSubresource: C.uint32_t,
    imageOffset: C.uint32_t,
    imageExtent: C.uint32_t,
});


const VkImageResolve = new T.StructBuffer("VkImageResolve", {
    srcSubresource: C.uint32_t,
    srcOffset: C.uint32_t,
    dstSubresource: C.uint32_t,
    dstOffset: C.uint32_t,
    extent: C.uint32_t,
});


const VkShaderModuleCreateInfo = new T.StructBuffer("VkShaderModuleCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    codeSize: C.uint64_t,
    pCode: C.uint64_t,
});


const VkDescriptorSetLayoutBinding = new T.StructBuffer("VkDescriptorSetLayoutBinding", {
    binding: C.uint32_t,
    descriptorType: C.uint32_t,
    descriptorCount: C.uint32_t,
    stageFlags: C.uint32_t,
    pImmutableSamplers: C.uint64_t,
});


const VkDescriptorSetLayoutCreateInfo = new T.StructBuffer("VkDescriptorSetLayoutCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    bindingCount: C.uint32_t,
    pBindings: C.uint64_t,
});


const VkDescriptorPoolSize = new T.StructBuffer("VkDescriptorPoolSize", {
    type: C.uint32_t,
    descriptorCount: C.uint32_t,
});


const VkDescriptorPoolCreateInfo = new T.StructBuffer("VkDescriptorPoolCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    maxSets: C.uint32_t,
    poolSizeCount: C.uint32_t,
    pPoolSizes: C.uint64_t,
});


const VkDescriptorSetAllocateInfo = new T.StructBuffer("VkDescriptorSetAllocateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    descriptorPool: C.uint32_t,
    descriptorSetCount: C.uint32_t,
    pSetLayouts: C.uint64_t,
});


const VkSpecializationMapEntry = new T.StructBuffer("VkSpecializationMapEntry", {
    constantID: C.uint32_t,
    offset: C.uint32_t,
    size: C.uint64_t,
});


const VkSpecializationInfo = new T.StructBuffer("VkSpecializationInfo", {
    mapEntryCount: C.uint32_t,
    pMapEntries: C.uint64_t,
    dataSize: C.uint64_t,
    pData: C.uint64_t,
});


const VkPipelineShaderStageCreateInfo = new T.StructBuffer("VkPipelineShaderStageCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    stage: C.uint32_t,
    module: C.uint32_t,
    pName: C.uint64_t,
    pSpecializationInfo: C.uint64_t,
});


const VkComputePipelineCreateInfo = new T.StructBuffer("VkComputePipelineCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    stage: C.uint32_t,
    layout: C.uint32_t,
    basePipelineHandle: C.uint32_t,
    basePipelineIndex: C.int32_t,
});


const VkVertexInputBindingDescription = new T.StructBuffer("VkVertexInputBindingDescription", {
    binding: C.uint32_t,
    stride: C.uint32_t,
    inputRate: C.uint32_t,
});


const VkVertexInputAttributeDescription = new T.StructBuffer("VkVertexInputAttributeDescription", {
    location: C.uint32_t,
    binding: C.uint32_t,
    format: C.uint32_t,
    offset: C.uint32_t,
});


const VkPipelineVertexInputStateCreateInfo = new T.StructBuffer("VkPipelineVertexInputStateCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    vertexBindingDescriptionCount: C.uint32_t,
    pVertexBindingDescriptions: C.uint64_t,
    vertexAttributeDescriptionCount: C.uint32_t,
    pVertexAttributeDescriptions: C.uint64_t,
});


const VkPipelineInputAssemblyStateCreateInfo = new T.StructBuffer("VkPipelineInputAssemblyStateCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    topology: C.uint32_t,
    primitiveRestartEnable: C.uint32_t,
});


const VkPipelineTessellationStateCreateInfo = new T.StructBuffer("VkPipelineTessellationStateCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    patchControlPoints: C.uint32_t,
});


const VkPipelineViewportStateCreateInfo = new T.StructBuffer("VkPipelineViewportStateCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    viewportCount: C.uint32_t,
    pViewports: C.uint64_t,
    scissorCount: C.uint32_t,
    pScissors: C.uint64_t,
});


const VkPipelineRasterizationStateCreateInfo = new T.StructBuffer("VkPipelineRasterizationStateCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    depthClampEnable: C.uint32_t,
    rasterizerDiscardEnable: C.uint32_t,
    polygonMode: C.uint32_t,
    cullMode: C.uint32_t,
    frontFace: C.uint32_t,
    depthBiasEnable: C.uint32_t,
    depthBiasConstantFactor: C.float,
    depthBiasClamp: C.float,
    depthBiasSlopeFactor: C.float,
    lineWidth: C.float,
});


const VkPipelineMultisampleStateCreateInfo = new T.StructBuffer("VkPipelineMultisampleStateCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    rasterizationSamples: C.uint32_t,
    sampleShadingEnable: C.uint32_t,
    minSampleShading: C.float,
    pSampleMask: C.uint64_t,
    alphaToCoverageEnable: C.uint32_t,
    alphaToOneEnable: C.uint32_t,
});


const VkPipelineColorBlendAttachmentState = new T.StructBuffer("VkPipelineColorBlendAttachmentState", {
    blendEnable: C.uint32_t,
    srcColorBlendFactor: C.uint32_t,
    dstColorBlendFactor: C.uint32_t,
    colorBlendOp: C.uint32_t,
    srcAlphaBlendFactor: C.uint32_t,
    dstAlphaBlendFactor: C.uint32_t,
    alphaBlendOp: C.uint32_t,
    colorWriteMask: C.uint32_t,
});


const VkPipelineColorBlendStateCreateInfo = new T.StructBuffer("VkPipelineColorBlendStateCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    logicOpEnable: C.uint32_t,
    logicOp: C.uint32_t,
    attachmentCount: C.uint32_t,
    pAttachments: C.uint64_t,
    blendConstants: C.float[4],
});


const VkPipelineDynamicStateCreateInfo = new T.StructBuffer("VkPipelineDynamicStateCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    dynamicStateCount: C.uint32_t,
    pDynamicStates: C.uint64_t,
});


const VkStencilOpState = new T.StructBuffer("VkStencilOpState", {
    failOp: C.uint32_t,
    passOp: C.uint32_t,
    depthFailOp: C.uint32_t,
    compareOp: C.uint32_t,
    compareMask: C.uint32_t,
    writeMask: C.uint32_t,
    reference: C.uint32_t,
});


const VkPipelineDepthStencilStateCreateInfo = new T.StructBuffer("VkPipelineDepthStencilStateCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    depthTestEnable: C.uint32_t,
    depthWriteEnable: C.uint32_t,
    depthCompareOp: C.uint32_t,
    depthBoundsTestEnable: C.uint32_t,
    stencilTestEnable: C.uint32_t,
    front: C.uint32_t,
    back: C.uint32_t,
    minDepthBounds: C.float,
    maxDepthBounds: C.float,
});


const VkGraphicsPipelineCreateInfo = new T.StructBuffer("VkGraphicsPipelineCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    stageCount: C.uint32_t,
    pStages: C.uint64_t,
    pVertexInputState: C.uint64_t,
    pInputAssemblyState: C.uint64_t,
    pTessellationState: C.uint64_t,
    pViewportState: C.uint64_t,
    pRasterizationState: C.uint64_t,
    pMultisampleState: C.uint64_t,
    pDepthStencilState: C.uint64_t,
    pColorBlendState: C.uint64_t,
    pDynamicState: C.uint64_t,
    layout: C.uint32_t,
    renderPass: C.uint32_t,
    subpass: C.uint32_t,
    basePipelineHandle: C.uint32_t,
    basePipelineIndex: C.int32_t,
});


const VkPipelineCacheCreateInfo = new T.StructBuffer("VkPipelineCacheCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    initialDataSize: C.uint64_t,
    pInitialData: C.uint64_t,
});


const VkPipelineCacheHeaderVersionOne = new T.StructBuffer("VkPipelineCacheHeaderVersionOne", {
    headerSize: C.uint32_t,
    headerVersion: C.uint32_t,
    vendorID: C.uint32_t,
    deviceID: C.uint32_t,
    pipelineCacheUUID: C.uint8_t[enums.VK_UUID_SIZE],
});


const VkPushConstantRange = new T.StructBuffer("VkPushConstantRange", {
    stageFlags: C.uint32_t,
    offset: C.uint32_t,
    size: C.uint32_t,
});


const VkPipelineLayoutCreateInfo = new T.StructBuffer("VkPipelineLayoutCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    setLayoutCount: C.uint32_t,
    pSetLayouts: C.uint64_t,
    pushConstantRangeCount: C.uint32_t,
    pPushConstantRanges: C.uint64_t,
});


const VkSamplerCreateInfo = new T.StructBuffer("VkSamplerCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    magFilter: C.uint32_t,
    minFilter: C.uint32_t,
    mipmapMode: C.uint32_t,
    addressModeU: C.uint32_t,
    addressModeV: C.uint32_t,
    addressModeW: C.uint32_t,
    mipLodBias: C.float,
    anisotropyEnable: C.uint32_t,
    maxAnisotropy: C.float,
    compareEnable: C.uint32_t,
    compareOp: C.uint32_t,
    minLod: C.float,
    maxLod: C.float,
    borderColor: C.uint32_t,
    unnormalizedCoordinates: C.uint32_t,
});


const VkCommandPoolCreateInfo = new T.StructBuffer("VkCommandPoolCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    queueFamilyIndex: C.uint32_t,
});


const VkCommandBufferAllocateInfo = new T.StructBuffer("VkCommandBufferAllocateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    commandPool: C.uint32_t,
    level: C.uint32_t,
    commandBufferCount: C.uint32_t,
});


const VkCommandBufferInheritanceInfo = new T.StructBuffer("VkCommandBufferInheritanceInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    renderPass: C.uint32_t,
    subpass: C.uint32_t,
    framebuffer: C.uint32_t,
    occlusionQueryEnable: C.uint32_t,
    queryFlags: C.uint32_t,
    pipelineStatistics: C.uint32_t,
});


const VkCommandBufferBeginInfo = new T.StructBuffer("VkCommandBufferBeginInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    pInheritanceInfo: C.uint64_t,
});


const VkRenderPassBeginInfo = new T.StructBuffer("VkRenderPassBeginInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    renderPass: C.uint32_t,
    framebuffer: C.uint32_t,
    renderArea: VkRect2D,
    clearValueCount: C.uint32_t,
    pClearValues: C.uint64_t,
});


const VkClearDepthStencilValue = new T.StructBuffer("VkClearDepthStencilValue", {
    depth: C.float,
    stencil: C.uint32_t,
});


const VkClearAttachment = new T.StructBuffer("VkClearAttachment", {
    aspectMask: C.uint32_t,
    colorAttachment: C.uint32_t,
    clearValue: C.uint32_t,
});


const VkAttachmentDescription = new T.StructBuffer("VkAttachmentDescription", {
    flags: C.uint32_t,
    format: C.uint32_t,
    samples: C.uint32_t,
    loadOp: C.uint32_t,
    storeOp: C.uint32_t,
    stencilLoadOp: C.uint32_t,
    stencilStoreOp: C.uint32_t,
    initialLayout: C.uint32_t,
    finalLayout: C.uint32_t,
});


const VkAttachmentReference = new T.StructBuffer("VkAttachmentReference", {
    attachment: C.uint32_t,
    layout: C.uint32_t,
});


const VkSubpassDescription = new T.StructBuffer("VkSubpassDescription", {
    flags: C.uint32_t,
    pipelineBindPoint: C.uint32_t,
    inputAttachmentCount: C.uint32_t,
    pInputAttachments: C.uint64_t,
    colorAttachmentCount: C.uint32_t,
    pColorAttachments: C.uint64_t,
    pResolveAttachments: C.uint64_t,
    pDepthStencilAttachment: C.uint64_t,
    preserveAttachmentCount: C.uint32_t,
    pPreserveAttachments: C.uint64_t,
});


const VkSubpassDependency = new T.StructBuffer("VkSubpassDependency", {
    srcSubpass: C.uint32_t,
    dstSubpass: C.uint32_t,
    srcStageMask: C.uint32_t,
    dstStageMask: C.uint32_t,
    srcAccessMask: C.uint32_t,
    dstAccessMask: C.uint32_t,
    dependencyFlags: C.uint32_t,
});


const VkRenderPassCreateInfo = new T.StructBuffer("VkRenderPassCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    attachmentCount: C.uint32_t,
    pAttachments: C.uint64_t,
    subpassCount: C.uint32_t,
    pSubpasses: C.uint64_t,
    dependencyCount: C.uint32_t,
    pDependencies: C.uint64_t,
});


const VkEventCreateInfo = new T.StructBuffer("VkEventCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
});


const VkFenceCreateInfo = new T.StructBuffer("VkFenceCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
});


const VkPhysicalDeviceFeatures = new T.StructBuffer("VkPhysicalDeviceFeatures", {
    robustBufferAccess: C.uint32_t,
    fullDrawIndexUint32: C.uint32_t,
    imageCubeArray: C.uint32_t,
    independentBlend: C.uint32_t,
    geometryShader: C.uint32_t,
    tessellationShader: C.uint32_t,
    sampleRateShading: C.uint32_t,
    dualSrcBlend: C.uint32_t,
    logicOp: C.uint32_t,
    multiDrawIndirect: C.uint32_t,
    drawIndirectFirstInstance: C.uint32_t,
    depthClamp: C.uint32_t,
    depthBiasClamp: C.uint32_t,
    fillModeNonSolid: C.uint32_t,
    depthBounds: C.uint32_t,
    wideLines: C.uint32_t,
    largePoints: C.uint32_t,
    alphaToOne: C.uint32_t,
    multiViewport: C.uint32_t,
    samplerAnisotropy: C.uint32_t,
    textureCompressionETC2: C.uint32_t,
    textureCompressionASTC_LDR: C.uint32_t,
    textureCompressionBC: C.uint32_t,
    occlusionQueryPrecise: C.uint32_t,
    pipelineStatisticsQuery: C.uint32_t,
    vertexPipelineStoresAndAtomics: C.uint32_t,
    fragmentStoresAndAtomics: C.uint32_t,
    shaderTessellationAndGeometryPointSize: C.uint32_t,
    shaderImageGatherExtended: C.uint32_t,
    shaderStorageImageExtendedFormats: C.uint32_t,
    shaderStorageImageMultisample: C.uint32_t,
    shaderStorageImageReadWithoutFormat: C.uint32_t,
    shaderStorageImageWriteWithoutFormat: C.uint32_t,
    shaderUniformBufferArrayDynamicIndexing: C.uint32_t,
    shaderSampledImageArrayDynamicIndexing: C.uint32_t,
    shaderStorageBufferArrayDynamicIndexing: C.uint32_t,
    shaderStorageImageArrayDynamicIndexing: C.uint32_t,
    shaderClipDistance: C.uint32_t,
    shaderCullDistance: C.uint32_t,
    shaderFloat64: C.uint32_t,
    shaderInt64: C.uint32_t,
    shaderInt16: C.uint32_t,
    shaderResourceResidency: C.uint32_t,
    shaderResourceMinLod: C.uint32_t,
    sparseBinding: C.uint32_t,
    sparseResidencyBuffer: C.uint32_t,
    sparseResidencyImage2D: C.uint32_t,
    sparseResidencyImage3D: C.uint32_t,
    sparseResidency2Samples: C.uint32_t,
    sparseResidency4Samples: C.uint32_t,
    sparseResidency8Samples: C.uint32_t,
    sparseResidency16Samples: C.uint32_t,
    sparseResidencyAliased: C.uint32_t,
    variableMultisampleRate: C.uint32_t,
    inheritedQueries: C.uint32_t,
});


const VkPhysicalDeviceSparseProperties = new T.StructBuffer("VkPhysicalDeviceSparseProperties", {
    residencyStandard2DBlockShape: C.uint32_t,
    residencyStandard2DMultisampleBlockShape: C.uint32_t,
    residencyStandard3DBlockShape: C.uint32_t,
    residencyAlignedMipSize: C.uint32_t,
    residencyNonResidentStrict: C.uint32_t,
});


const VkPhysicalDeviceLimits = new T.StructBuffer("VkPhysicalDeviceLimits", {
    maxImageDimension1D: C.uint32_t,
    maxImageDimension2D: C.uint32_t,
    maxImageDimension3D: C.uint32_t,
    maxImageDimensionCube: C.uint32_t,
    maxImageArrayLayers: C.uint32_t,
    maxTexelBufferElements: C.uint32_t,
    maxUniformBufferRange: C.uint32_t,
    maxStorageBufferRange: C.uint32_t,
    maxPushConstantsSize: C.uint32_t,
    maxMemoryAllocationCount: C.uint32_t,
    maxSamplerAllocationCount: C.uint32_t,
    bufferImageGranularity: C.uint64_t,
    sparseAddressSpaceSize: C.uint64_t,
    maxBoundDescriptorSets: C.uint32_t,
    maxPerStageDescriptorSamplers: C.uint32_t,
    maxPerStageDescriptorUniformBuffers: C.uint32_t,
    maxPerStageDescriptorStorageBuffers: C.uint32_t,
    maxPerStageDescriptorSampledImages: C.uint32_t,
    maxPerStageDescriptorStorageImages: C.uint32_t,
    maxPerStageDescriptorInputAttachments: C.uint32_t,
    maxPerStageResources: C.uint32_t,
    maxDescriptorSetSamplers: C.uint32_t,
    maxDescriptorSetUniformBuffers: C.uint32_t,
    maxDescriptorSetUniformBuffersDynamic: C.uint32_t,
    maxDescriptorSetStorageBuffers: C.uint32_t,
    maxDescriptorSetStorageBuffersDynamic: C.uint32_t,
    maxDescriptorSetSampledImages: C.uint32_t,
    maxDescriptorSetStorageImages: C.uint32_t,
    maxDescriptorSetInputAttachments: C.uint32_t,
    maxVertexInputAttributes: C.uint32_t,
    maxVertexInputBindings: C.uint32_t,
    maxVertexInputAttributeOffset: C.uint32_t,
    maxVertexInputBindingStride: C.uint32_t,
    maxVertexOutputComponents: C.uint32_t,
    maxTessellationGenerationLevel: C.uint32_t,
    maxTessellationPatchSize: C.uint32_t,
    maxTessellationControlPerVertexInputComponents: C.uint32_t,
    maxTessellationControlPerVertexOutputComponents: C.uint32_t,
    maxTessellationControlPerPatchOutputComponents: C.uint32_t,
    maxTessellationControlTotalOutputComponents: C.uint32_t,
    maxTessellationEvaluationInputComponents: C.uint32_t,
    maxTessellationEvaluationOutputComponents: C.uint32_t,
    maxGeometryShaderInvocations: C.uint32_t,
    maxGeometryInputComponents: C.uint32_t,
    maxGeometryOutputComponents: C.uint32_t,
    maxGeometryOutputVertices: C.uint32_t,
    maxGeometryTotalOutputComponents: C.uint32_t,
    maxFragmentInputComponents: C.uint32_t,
    maxFragmentOutputAttachments: C.uint32_t,
    maxFragmentDualSrcAttachments: C.uint32_t,
    maxFragmentCombinedOutputResources: C.uint32_t,
    maxComputeSharedMemorySize: C.uint32_t,
    maxComputeWorkGroupCount: C.uint32_t[3],
    maxComputeWorkGroupInvocations: C.uint32_t,
    maxComputeWorkGroupSize: C.uint32_t[3],
    subPixelPrecisionBits: C.uint32_t,
    subTexelPrecisionBits: C.uint32_t,
    mipmapPrecisionBits: C.uint32_t,
    maxDrawIndexedIndexValue: C.uint32_t,
    maxDrawIndirectCount: C.uint32_t,
    maxSamplerLodBias: C.float,
    maxSamplerAnisotropy: C.float,
    maxViewports: C.uint32_t,
    maxViewportDimensions: C.uint32_t[2],
    viewportBoundsRange: C.float[2],
    viewportSubPixelBits: C.uint32_t,
    minMemoryMapAlignment: C.uint64_t,
    minTexelBufferOffsetAlignment: C.uint64_t,
    minUniformBufferOffsetAlignment: C.uint64_t,
    minStorageBufferOffsetAlignment: C.uint64_t,
    minTexelOffset: C.int32_t,
    maxTexelOffset: C.uint32_t,
    minTexelGatherOffset: C.int32_t,
    maxTexelGatherOffset: C.uint32_t,
    minInterpolationOffset: C.float,
    maxInterpolationOffset: C.float,
    subPixelInterpolationOffsetBits: C.uint32_t,
    maxFramebufferWidth: C.uint32_t,
    maxFramebufferHeight: C.uint32_t,
    maxFramebufferLayers: C.uint32_t,
    framebufferColorSampleCounts: C.uint32_t,
    framebufferDepthSampleCounts: C.uint32_t,
    framebufferStencilSampleCounts: C.uint32_t,
    framebufferNoAttachmentsSampleCounts: C.uint32_t,
    maxColorAttachments: C.uint32_t,
    sampledImageColorSampleCounts: C.uint32_t,
    sampledImageIntegerSampleCounts: C.uint32_t,
    sampledImageDepthSampleCounts: C.uint32_t,
    sampledImageStencilSampleCounts: C.uint32_t,
    storageImageSampleCounts: C.uint32_t,
    maxSampleMaskWords: C.uint32_t,
    timestampComputeAndGraphics: C.uint32_t,
    timestampPeriod: C.float,
    maxClipDistances: C.uint32_t,
    maxCullDistances: C.uint32_t,
    maxCombinedClipAndCullDistances: C.uint32_t,
    discreteQueuePriorities: C.uint32_t,
    pointSizeRange: C.float[2],
    lineWidthRange: C.float[2],
    pointSizeGranularity: C.float,
    lineWidthGranularity: C.float,
    strictLines: C.uint32_t,
    standardSampleLocations: C.uint32_t,
    optimalBufferCopyOffsetAlignment: C.uint64_t,
    optimalBufferCopyRowPitchAlignment: C.uint64_t,
    nonCoherentAtomSize: C.uint64_t,
});


const VkSemaphoreCreateInfo = new T.StructBuffer("VkSemaphoreCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
});


const VkQueryPoolCreateInfo = new T.StructBuffer("VkQueryPoolCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    queryType: C.uint32_t,
    queryCount: C.uint32_t,
    pipelineStatistics: C.uint32_t,
});


const VkFramebufferCreateInfo = new T.StructBuffer("VkFramebufferCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    renderPass: C.uint32_t,
    attachmentCount: C.uint32_t,
    pAttachments: C.uint64_t,
    width: C.uint32_t,
    height: C.uint32_t,
    layers: C.uint32_t,
});


const VkDrawIndirectCommand = new T.StructBuffer("VkDrawIndirectCommand", {
    vertexCount: C.uint32_t,
    instanceCount: C.uint32_t,
    firstVertex: C.uint32_t,
    firstInstance: C.uint32_t,
});


const VkDrawIndexedIndirectCommand = new T.StructBuffer("VkDrawIndexedIndirectCommand", {
    indexCount: C.uint32_t,
    instanceCount: C.uint32_t,
    firstIndex: C.uint32_t,
    vertexOffset: C.int32_t,
    firstInstance: C.uint32_t,
});


const VkDispatchIndirectCommand = new T.StructBuffer("VkDispatchIndirectCommand", {
    x: C.uint32_t,
    y: C.uint32_t,
    z: C.uint32_t,
});


const VkMultiDrawInfoEXT = new T.StructBuffer("VkMultiDrawInfoEXT", {
    firstVertex: C.uint32_t,
    vertexCount: C.uint32_t,
});


const VkMultiDrawIndexedInfoEXT = new T.StructBuffer("VkMultiDrawIndexedInfoEXT", {
    firstIndex: C.uint32_t,
    indexCount: C.uint32_t,
    vertexOffset: C.int32_t,
});


const VkSubmitInfo = new T.StructBuffer("VkSubmitInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    waitSemaphoreCount: C.uint32_t,
    pWaitSemaphores: C.uint64_t,
    pWaitDstStageMask: C.uint64_t,
    commandBufferCount: C.uint32_t,
    pCommandBuffers: C.uint64_t,
    signalSemaphoreCount: C.uint32_t,
    pSignalSemaphores: C.uint64_t,
});


const VkDisplayPropertiesKHR = new T.StructBuffer("VkDisplayPropertiesKHR", {
    display: C.uint32_t,
    displayName: C.uint64_t,
    physicalDimensions: VkExtent2D,
    physicalResolution: VkExtent2D,
    supportedTransforms: C.uint32_t,
    planeReorderPossible: C.uint32_t,
    persistentContent: C.uint32_t,
});


const VkDisplayPlanePropertiesKHR = new T.StructBuffer("VkDisplayPlanePropertiesKHR", {
    currentDisplay: C.uint32_t,
    currentStackIndex: C.uint32_t,
});


const VkDisplayModeParametersKHR = new T.StructBuffer("VkDisplayModeParametersKHR", {
    visibleRegion: VkExtent2D,
    refreshRate: C.uint32_t,
});


const VkDisplayModePropertiesKHR = new T.StructBuffer("VkDisplayModePropertiesKHR", {
    displayMode: C.uint32_t,
    parameters: C.uint32_t,
});


const VkDisplayModeCreateInfoKHR = new T.StructBuffer("VkDisplayModeCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    parameters: C.uint32_t,
});


const VkDisplayPlaneCapabilitiesKHR = new T.StructBuffer("VkDisplayPlaneCapabilitiesKHR", {
    supportedAlpha: C.uint32_t,
    minSrcPosition: VkOffset2D,
    maxSrcPosition: VkOffset2D,
    minSrcExtent: VkExtent2D,
    maxSrcExtent: VkExtent2D,
    minDstPosition: VkOffset2D,
    maxDstPosition: VkOffset2D,
    minDstExtent: VkExtent2D,
    maxDstExtent: VkExtent2D,
});


const VkDisplaySurfaceCreateInfoKHR = new T.StructBuffer("VkDisplaySurfaceCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    displayMode: C.uint32_t,
    planeIndex: C.uint32_t,
    planeStackIndex: C.uint32_t,
    transform: C.uint32_t,
    globalAlpha: C.float,
    alphaMode: C.uint32_t,
    imageExtent: VkExtent2D,
});


const VkDisplayPresentInfoKHR = new T.StructBuffer("VkDisplayPresentInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcRect: VkRect2D,
    dstRect: VkRect2D,
    persistent: C.uint32_t,
});


const VkSurfaceCapabilitiesKHR = new T.StructBuffer("VkSurfaceCapabilitiesKHR", {
    minImageCount: C.uint32_t,
    maxImageCount: C.uint32_t,
    currentExtent: VkExtent2D,
    minImageExtent: VkExtent2D,
    maxImageExtent: VkExtent2D,
    maxImageArrayLayers: C.uint32_t,
    supportedTransforms: C.uint32_t,
    currentTransform: C.uint32_t,
    supportedCompositeAlpha: C.uint32_t,
    supportedUsageFlags: C.uint32_t,
});


const VkAndroidSurfaceCreateInfoKHR = new T.StructBuffer("VkAndroidSurfaceCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    window: C.uint64_t,
});


const VkViSurfaceCreateInfoNN = new T.StructBuffer("VkViSurfaceCreateInfoNN", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    window: C.uint64_t,
});


const VkWaylandSurfaceCreateInfoKHR = new T.StructBuffer("VkWaylandSurfaceCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    display: C.uint64_t,
    surface: C.uint64_t,
});


const VkWin32SurfaceCreateInfoKHR = new T.StructBuffer("VkWin32SurfaceCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    hinstance: C.uint32_t,
    hwnd: C.uint32_t,
});


const VkXlibSurfaceCreateInfoKHR = new T.StructBuffer("VkXlibSurfaceCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    dpy: C.uint64_t,
    window: C.uint32_t,
});


const VkXcbSurfaceCreateInfoKHR = new T.StructBuffer("VkXcbSurfaceCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    connection: C.uint64_t,
    window: C.uint32_t,
});


const VkDirectFBSurfaceCreateInfoEXT = new T.StructBuffer("VkDirectFBSurfaceCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    dfb: C.uint64_t,
    surface: C.uint64_t,
});


const VkImagePipeSurfaceCreateInfoFUCHSIA = new T.StructBuffer("VkImagePipeSurfaceCreateInfoFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    imagePipeHandle: C.uint32_t,
});


const VkStreamDescriptorSurfaceCreateInfoGGP = new T.StructBuffer("VkStreamDescriptorSurfaceCreateInfoGGP", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    streamDescriptor: C.uint32_t,
});


const VkScreenSurfaceCreateInfoQNX = new T.StructBuffer("VkScreenSurfaceCreateInfoQNX", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    context: C.uint64_t,
    window: C.uint64_t,
});


const VkSurfaceFormatKHR = new T.StructBuffer("VkSurfaceFormatKHR", {
    format: C.uint32_t,
    colorSpace: C.uint32_t,
});


const VkSwapchainCreateInfoKHR = new T.StructBuffer("VkSwapchainCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    surface: C.uint32_t,
    minImageCount: C.uint32_t,
    imageFormat: C.uint32_t,
    imageColorSpace: C.uint32_t,
    imageExtent: VkExtent2D,
    imageArrayLayers: C.uint32_t,
    imageUsage: C.uint32_t,
    imageSharingMode: C.uint32_t,
    queueFamilyIndexCount: C.uint32_t,
    pQueueFamilyIndices: C.uint64_t,
    preTransform: C.uint32_t,
    compositeAlpha: C.uint32_t,
    presentMode: C.uint32_t,
    clipped: C.uint32_t,
    oldSwapchain: C.uint32_t,
});


const VkPresentInfoKHR = new T.StructBuffer("VkPresentInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    waitSemaphoreCount: C.uint32_t,
    pWaitSemaphores: C.uint64_t,
    swapchainCount: C.uint32_t,
    pSwapchains: C.uint64_t,
    pImageIndices: C.uint64_t,
    pResults: C.uint64_t,
});


const VkDebugReportCallbackCreateInfoEXT = new T.StructBuffer("VkDebugReportCallbackCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    pfnCallback: C.uint32_t,
    pUserData: C.uint64_t,
});


const VkValidationFlagsEXT = new T.StructBuffer("VkValidationFlagsEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    disabledValidationCheckCount: C.uint32_t,
    pDisabledValidationChecks: C.uint64_t,
});


const VkValidationFeaturesEXT = new T.StructBuffer("VkValidationFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    enabledValidationFeatureCount: C.uint32_t,
    pEnabledValidationFeatures: C.uint64_t,
    disabledValidationFeatureCount: C.uint32_t,
    pDisabledValidationFeatures: C.uint64_t,
});


const VkPipelineRasterizationStateRasterizationOrderAMD = new T.StructBuffer("VkPipelineRasterizationStateRasterizationOrderAMD", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    rasterizationOrder: C.uint32_t,
});


const VkDebugMarkerObjectNameInfoEXT = new T.StructBuffer("VkDebugMarkerObjectNameInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    objectType: C.uint32_t,
    object: C.uint64_t,
    pObjectName: C.uint64_t,
});


const VkDebugMarkerObjectTagInfoEXT = new T.StructBuffer("VkDebugMarkerObjectTagInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    objectType: C.uint32_t,
    object: C.uint64_t,
    tagName: C.uint64_t,
    tagSize: C.uint64_t,
    pTag: C.uint64_t,
});


const VkDebugMarkerMarkerInfoEXT = new T.StructBuffer("VkDebugMarkerMarkerInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pMarkerName: C.uint64_t,
    color: C.float[4],
});


const VkDedicatedAllocationImageCreateInfoNV = new T.StructBuffer("VkDedicatedAllocationImageCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    dedicatedAllocation: C.uint32_t,
});


const VkDedicatedAllocationBufferCreateInfoNV = new T.StructBuffer("VkDedicatedAllocationBufferCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    dedicatedAllocation: C.uint32_t,
});


const VkDedicatedAllocationMemoryAllocateInfoNV = new T.StructBuffer("VkDedicatedAllocationMemoryAllocateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    image: C.uint64_t,
    buffer: C.uint64_t,
});


const VkExternalImageFormatPropertiesNV = new T.StructBuffer("VkExternalImageFormatPropertiesNV", {
    imageFormatProperties: C.uint32_t,
    externalMemoryFeatures: C.uint32_t,
    exportFromImportedHandleTypes: C.uint32_t,
    compatibleHandleTypes: C.uint32_t,
});


const VkExternalMemoryImageCreateInfoNV = new T.StructBuffer("VkExternalMemoryImageCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleTypes: C.uint32_t,
});


const VkExportMemoryAllocateInfoNV = new T.StructBuffer("VkExportMemoryAllocateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleTypes: C.uint32_t,
});


const VkImportMemoryWin32HandleInfoNV = new T.StructBuffer("VkImportMemoryWin32HandleInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleType: C.uint32_t,
    handle: C.uint64_t,
});


const VkExportMemoryWin32HandleInfoNV = new T.StructBuffer("VkExportMemoryWin32HandleInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pAttributes: C.uint64_t,
    dwAccess: C.uint32_t,
});


const VkWin32KeyedMutexAcquireReleaseInfoNV = new T.StructBuffer("VkWin32KeyedMutexAcquireReleaseInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    acquireCount: C.uint32_t,
    pAcquireSyncs: C.uint64_t,
    pAcquireKeys: C.uint64_t,
    pAcquireTimeoutMilliseconds: C.uint64_t,
    releaseCount: C.uint32_t,
    pReleaseSyncs: C.uint64_t,
    pReleaseKeys: C.uint64_t,
});


const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV = new T.StructBuffer("VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceGeneratedCommands: C.uint32_t,
});


const VkDevicePrivateDataCreateInfo = new T.StructBuffer("VkDevicePrivateDataCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    privateDataSlotRequestCount: C.uint32_t,
});


const VkDevicePrivateDataCreateInfoEXT = new T.StructBuffer("VkDevicePrivateDataCreateInfoEXT", {

});


const VkPrivateDataSlotCreateInfo = new T.StructBuffer("VkPrivateDataSlotCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
});


const VkPrivateDataSlotCreateInfoEXT = new T.StructBuffer("VkPrivateDataSlotCreateInfoEXT", {

});


const VkPhysicalDevicePrivateDataFeatures = new T.StructBuffer("VkPhysicalDevicePrivateDataFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    privateData: C.uint32_t,
});


const VkPhysicalDevicePrivateDataFeaturesEXT = new T.StructBuffer("VkPhysicalDevicePrivateDataFeaturesEXT", {

});


const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV = new T.StructBuffer("VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxGraphicsShaderGroupCount: C.uint32_t,
    maxIndirectSequenceCount: C.uint32_t,
    maxIndirectCommandsTokenCount: C.uint32_t,
    maxIndirectCommandsStreamCount: C.uint32_t,
    maxIndirectCommandsTokenOffset: C.uint32_t,
    maxIndirectCommandsStreamStride: C.uint32_t,
    minSequencesCountBufferOffsetAlignment: C.uint32_t,
    minSequencesIndexBufferOffsetAlignment: C.uint32_t,
    minIndirectCommandsBufferOffsetAlignment: C.uint32_t,
});


const VkPhysicalDeviceMultiDrawPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceMultiDrawPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxMultiDrawCount: C.uint32_t,
});


const VkGraphicsShaderGroupCreateInfoNV = new T.StructBuffer("VkGraphicsShaderGroupCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stageCount: C.uint32_t,
    pStages: C.uint64_t,
    pVertexInputState: C.uint64_t,
    pTessellationState: C.uint64_t,
});


const VkGraphicsPipelineShaderGroupsCreateInfoNV = new T.StructBuffer("VkGraphicsPipelineShaderGroupsCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    groupCount: C.uint32_t,
    pGroups: C.uint64_t,
    pipelineCount: C.uint32_t,
    pPipelines: C.uint64_t,
});


const VkBindShaderGroupIndirectCommandNV = new T.StructBuffer("VkBindShaderGroupIndirectCommandNV", {
    groupIndex: C.uint32_t,
});


const VkBindIndexBufferIndirectCommandNV = new T.StructBuffer("VkBindIndexBufferIndirectCommandNV", {
    bufferAddress: C.uint64_t,
    size: C.uint32_t,
    indexType: C.uint32_t,
});


const VkBindVertexBufferIndirectCommandNV = new T.StructBuffer("VkBindVertexBufferIndirectCommandNV", {
    bufferAddress: C.uint64_t,
    size: C.uint32_t,
    stride: C.uint32_t,
});


const VkSetStateFlagsIndirectCommandNV = new T.StructBuffer("VkSetStateFlagsIndirectCommandNV", {
    data: C.uint32_t,
});


const VkIndirectCommandsStreamNV = new T.StructBuffer("VkIndirectCommandsStreamNV", {
    buffer: C.uint64_t,
    offset: C.uint64_t,
});


const VkIndirectCommandsLayoutTokenNV = new T.StructBuffer("VkIndirectCommandsLayoutTokenNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    tokenType: C.uint32_t,
    stream: C.uint32_t,
    offset: C.uint32_t,
    vertexBindingUnit: C.uint32_t,
    vertexDynamicStride: C.uint32_t,
    pushconstantPipelineLayout: C.uint32_t,
    pushconstantShaderStageFlags: C.uint32_t,
    pushconstantOffset: C.uint32_t,
    pushconstantSize: C.uint32_t,
    indirectStateFlags: C.uint32_t,
    indexTypeCount: C.uint32_t,
    pIndexTypes: C.uint64_t,
    pIndexTypeValues: C.uint64_t,
});


const VkIndirectCommandsLayoutCreateInfoNV = new T.StructBuffer("VkIndirectCommandsLayoutCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    pipelineBindPoint: C.uint32_t,
    tokenCount: C.uint32_t,
    pTokens: C.uint64_t,
    streamCount: C.uint32_t,
    pStreamStrides: C.uint64_t,
});


const VkGeneratedCommandsInfoNV = new T.StructBuffer("VkGeneratedCommandsInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pipelineBindPoint: C.uint32_t,
    pipeline: C.uint32_t,
    indirectCommandsLayout: C.uint32_t,
    streamCount: C.uint32_t,
    pStreams: C.uint64_t,
    sequencesCount: C.uint32_t,
    preprocessBuffer: C.uint64_t,
    preprocessOffset: C.uint64_t,
    preprocessSize: C.uint64_t,
    sequencesCountBuffer: C.uint64_t,
    sequencesCountOffset: C.uint64_t,
    sequencesIndexBuffer: C.uint64_t,
    sequencesIndexOffset: C.uint64_t,
});


const VkGeneratedCommandsMemoryRequirementsInfoNV = new T.StructBuffer("VkGeneratedCommandsMemoryRequirementsInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pipelineBindPoint: C.uint32_t,
    pipeline: C.uint32_t,
    indirectCommandsLayout: C.uint32_t,
    maxSequencesCount: C.uint32_t,
});


const VkPhysicalDeviceFeatures2 = new T.StructBuffer("VkPhysicalDeviceFeatures2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    features: C.uint32_t,
});


const VkPhysicalDeviceFeatures2KHR = new T.StructBuffer("VkPhysicalDeviceFeatures2KHR", {

});


const VkPhysicalDeviceProperties2 = new T.StructBuffer("VkPhysicalDeviceProperties2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    properties: C.uint32_t,
});


const VkPhysicalDeviceProperties2KHR = new T.StructBuffer("VkPhysicalDeviceProperties2KHR", {

});


const VkFormatProperties2 = new T.StructBuffer("VkFormatProperties2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    formatProperties: C.uint32_t,
});


const VkFormatProperties2KHR = new T.StructBuffer("VkFormatProperties2KHR", {

});


const VkImageFormatProperties2 = new T.StructBuffer("VkImageFormatProperties2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageFormatProperties: C.uint32_t,
});


const VkImageFormatProperties2KHR = new T.StructBuffer("VkImageFormatProperties2KHR", {

});


const VkPhysicalDeviceImageFormatInfo2 = new T.StructBuffer("VkPhysicalDeviceImageFormatInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    format: C.uint32_t,
    type: C.uint32_t,
    tiling: C.uint32_t,
    usage: C.uint32_t,
    flags: C.uint32_t,
});


const VkPhysicalDeviceImageFormatInfo2KHR = new T.StructBuffer("VkPhysicalDeviceImageFormatInfo2KHR", {

});


const VkQueueFamilyProperties2 = new T.StructBuffer("VkQueueFamilyProperties2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    queueFamilyProperties: C.uint32_t,
});


const VkQueueFamilyProperties2KHR = new T.StructBuffer("VkQueueFamilyProperties2KHR", {

});


const VkPhysicalDeviceMemoryProperties2 = new T.StructBuffer("VkPhysicalDeviceMemoryProperties2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memoryProperties: C.uint32_t,
});


const VkPhysicalDeviceMemoryProperties2KHR = new T.StructBuffer("VkPhysicalDeviceMemoryProperties2KHR", {

});


const VkSparseImageFormatProperties2 = new T.StructBuffer("VkSparseImageFormatProperties2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    properties: C.uint32_t,
});


const VkSparseImageFormatProperties2KHR = new T.StructBuffer("VkSparseImageFormatProperties2KHR", {

});


const VkPhysicalDeviceSparseImageFormatInfo2 = new T.StructBuffer("VkPhysicalDeviceSparseImageFormatInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    format: C.uint32_t,
    type: C.uint32_t,
    samples: C.uint32_t,
    usage: C.uint32_t,
    tiling: C.uint32_t,
});


const VkPhysicalDeviceSparseImageFormatInfo2KHR = new T.StructBuffer("VkPhysicalDeviceSparseImageFormatInfo2KHR", {

});


const VkPhysicalDevicePushDescriptorPropertiesKHR = new T.StructBuffer("VkPhysicalDevicePushDescriptorPropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxPushDescriptors: C.uint32_t,
});


const VkConformanceVersion = new T.StructBuffer("VkConformanceVersion", {
    major: C.uint8_t,
    minor: C.uint8_t,
    subminor: C.uint8_t,
    patch: C.uint8_t,
});


const VkConformanceVersionKHR = new T.StructBuffer("VkConformanceVersionKHR", {

});


const VkPhysicalDeviceDriverProperties = new T.StructBuffer("VkPhysicalDeviceDriverProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    driverID: C.uint32_t,
    driverName: C.uint8_t[enums.VK_MAX_DRIVER_NAME_SIZE],
    driverInfo: C.uint8_t[enums.VK_MAX_DRIVER_INFO_SIZE],
    conformanceVersion: C.uint32_t,
});


const VkPhysicalDeviceDriverPropertiesKHR = new T.StructBuffer("VkPhysicalDeviceDriverPropertiesKHR", {

});


const VkPresentRegionsKHR = new T.StructBuffer("VkPresentRegionsKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    swapchainCount: C.uint32_t,
    pRegions: C.uint64_t,
});


const VkPresentRegionKHR = new T.StructBuffer("VkPresentRegionKHR", {
    rectangleCount: C.uint32_t,
    pRectangles: C.uint64_t,
});


const VkRectLayerKHR = new T.StructBuffer("VkRectLayerKHR", {
    offset: VkOffset2D,
    extent: VkExtent2D,
    layer: C.uint32_t,
});


const VkPhysicalDeviceVariablePointersFeatures = new T.StructBuffer("VkPhysicalDeviceVariablePointersFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    variablePointersStorageBuffer: C.uint32_t,
    variablePointers: C.uint32_t,
});


const VkPhysicalDeviceVariablePointersFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceVariablePointersFeaturesKHR", {

});


const VkPhysicalDeviceVariablePointerFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceVariablePointerFeaturesKHR", {

});


const VkPhysicalDeviceVariablePointerFeatures = new T.StructBuffer("VkPhysicalDeviceVariablePointerFeatures", {

});


const VkExternalMemoryProperties = new T.StructBuffer("VkExternalMemoryProperties", {
    externalMemoryFeatures: C.uint32_t,
    exportFromImportedHandleTypes: C.uint32_t,
    compatibleHandleTypes: C.uint32_t,
});


const VkExternalMemoryPropertiesKHR = new T.StructBuffer("VkExternalMemoryPropertiesKHR", {

});


const VkPhysicalDeviceExternalImageFormatInfo = new T.StructBuffer("VkPhysicalDeviceExternalImageFormatInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleType: C.uint32_t,
});


const VkPhysicalDeviceExternalImageFormatInfoKHR = new T.StructBuffer("VkPhysicalDeviceExternalImageFormatInfoKHR", {

});


const VkExternalImageFormatProperties = new T.StructBuffer("VkExternalImageFormatProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    externalMemoryProperties: C.uint32_t,
});


const VkExternalImageFormatPropertiesKHR = new T.StructBuffer("VkExternalImageFormatPropertiesKHR", {

});


const VkPhysicalDeviceExternalBufferInfo = new T.StructBuffer("VkPhysicalDeviceExternalBufferInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    usage: C.uint32_t,
    handleType: C.uint32_t,
});


const VkPhysicalDeviceExternalBufferInfoKHR = new T.StructBuffer("VkPhysicalDeviceExternalBufferInfoKHR", {

});


const VkExternalBufferProperties = new T.StructBuffer("VkExternalBufferProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    externalMemoryProperties: C.uint32_t,
});


const VkExternalBufferPropertiesKHR = new T.StructBuffer("VkExternalBufferPropertiesKHR", {

});


const VkPhysicalDeviceIDProperties = new T.StructBuffer("VkPhysicalDeviceIDProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceUUID: C.uint8_t[enums.VK_UUID_SIZE],
    driverUUID: C.uint8_t[enums.VK_UUID_SIZE],
    deviceLUID: C.uint8_t[enums.VK_LUID_SIZE],
    deviceNodeMask: C.uint32_t,
    deviceLUIDValid: C.uint32_t,
});


const VkPhysicalDeviceIDPropertiesKHR = new T.StructBuffer("VkPhysicalDeviceIDPropertiesKHR", {

});


const VkExternalMemoryImageCreateInfo = new T.StructBuffer("VkExternalMemoryImageCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleTypes: C.uint32_t,
});


const VkExternalMemoryImageCreateInfoKHR = new T.StructBuffer("VkExternalMemoryImageCreateInfoKHR", {

});


const VkExternalMemoryBufferCreateInfo = new T.StructBuffer("VkExternalMemoryBufferCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleTypes: C.uint32_t,
});


const VkExternalMemoryBufferCreateInfoKHR = new T.StructBuffer("VkExternalMemoryBufferCreateInfoKHR", {

});


const VkExportMemoryAllocateInfo = new T.StructBuffer("VkExportMemoryAllocateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleTypes: C.uint32_t,
});


const VkExportMemoryAllocateInfoKHR = new T.StructBuffer("VkExportMemoryAllocateInfoKHR", {

});


const VkImportMemoryWin32HandleInfoKHR = new T.StructBuffer("VkImportMemoryWin32HandleInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleType: C.uint32_t,
    handle: C.uint64_t,
    name: C.uint32_t,
});


const VkExportMemoryWin32HandleInfoKHR = new T.StructBuffer("VkExportMemoryWin32HandleInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pAttributes: C.uint64_t,
    dwAccess: C.uint32_t,
    name: C.uint32_t,
});


const VkImportMemoryZirconHandleInfoFUCHSIA = new T.StructBuffer("VkImportMemoryZirconHandleInfoFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleType: C.uint32_t,
    handle: C.uint32_t,
});


const VkMemoryZirconHandlePropertiesFUCHSIA = new T.StructBuffer("VkMemoryZirconHandlePropertiesFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memoryTypeBits: C.uint32_t,
});


const VkMemoryGetZirconHandleInfoFUCHSIA = new T.StructBuffer("VkMemoryGetZirconHandleInfoFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memory: C.uint64_t,
    handleType: C.uint32_t,
});


const VkMemoryWin32HandlePropertiesKHR = new T.StructBuffer("VkMemoryWin32HandlePropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memoryTypeBits: C.uint32_t,
});


const VkMemoryGetWin32HandleInfoKHR = new T.StructBuffer("VkMemoryGetWin32HandleInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memory: C.uint64_t,
    handleType: C.uint32_t,
});


const VkImportMemoryFdInfoKHR = new T.StructBuffer("VkImportMemoryFdInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleType: C.uint32_t,
    fd: C.uint32_t,
});


const VkMemoryFdPropertiesKHR = new T.StructBuffer("VkMemoryFdPropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memoryTypeBits: C.uint32_t,
});


const VkMemoryGetFdInfoKHR = new T.StructBuffer("VkMemoryGetFdInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memory: C.uint64_t,
    handleType: C.uint32_t,
});


const VkWin32KeyedMutexAcquireReleaseInfoKHR = new T.StructBuffer("VkWin32KeyedMutexAcquireReleaseInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    acquireCount: C.uint32_t,
    pAcquireSyncs: C.uint64_t,
    pAcquireKeys: C.uint64_t,
    pAcquireTimeouts: C.uint64_t,
    releaseCount: C.uint32_t,
    pReleaseSyncs: C.uint64_t,
    pReleaseKeys: C.uint64_t,
});


const VkPhysicalDeviceExternalSemaphoreInfo = new T.StructBuffer("VkPhysicalDeviceExternalSemaphoreInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleType: C.uint32_t,
});


const VkPhysicalDeviceExternalSemaphoreInfoKHR = new T.StructBuffer("VkPhysicalDeviceExternalSemaphoreInfoKHR", {

});


const VkExternalSemaphoreProperties = new T.StructBuffer("VkExternalSemaphoreProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    exportFromImportedHandleTypes: C.uint32_t,
    compatibleHandleTypes: C.uint32_t,
    externalSemaphoreFeatures: C.uint32_t,
});


const VkExternalSemaphorePropertiesKHR = new T.StructBuffer("VkExternalSemaphorePropertiesKHR", {

});


const VkExportSemaphoreCreateInfo = new T.StructBuffer("VkExportSemaphoreCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleTypes: C.uint32_t,
});


const VkExportSemaphoreCreateInfoKHR = new T.StructBuffer("VkExportSemaphoreCreateInfoKHR", {

});


const VkImportSemaphoreWin32HandleInfoKHR = new T.StructBuffer("VkImportSemaphoreWin32HandleInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    semaphore: C.uint32_t,
    flags: C.uint32_t,
    handleType: C.uint32_t,
    handle: C.uint64_t,
    name: C.uint32_t,
});


const VkExportSemaphoreWin32HandleInfoKHR = new T.StructBuffer("VkExportSemaphoreWin32HandleInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pAttributes: C.uint64_t,
    dwAccess: C.uint32_t,
    name: C.uint32_t,
});


const VkD3D12FenceSubmitInfoKHR = new T.StructBuffer("VkD3D12FenceSubmitInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    waitSemaphoreValuesCount: C.uint32_t,
    pWaitSemaphoreValues: C.uint64_t,
    signalSemaphoreValuesCount: C.uint32_t,
    pSignalSemaphoreValues: C.uint64_t,
});


const VkSemaphoreGetWin32HandleInfoKHR = new T.StructBuffer("VkSemaphoreGetWin32HandleInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    semaphore: C.uint32_t,
    handleType: C.uint32_t,
});


const VkImportSemaphoreFdInfoKHR = new T.StructBuffer("VkImportSemaphoreFdInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    semaphore: C.uint32_t,
    flags: C.uint32_t,
    handleType: C.uint32_t,
    fd: C.uint32_t,
});


const VkSemaphoreGetFdInfoKHR = new T.StructBuffer("VkSemaphoreGetFdInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    semaphore: C.uint32_t,
    handleType: C.uint32_t,
});


const VkImportSemaphoreZirconHandleInfoFUCHSIA = new T.StructBuffer("VkImportSemaphoreZirconHandleInfoFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    semaphore: C.uint32_t,
    flags: C.uint32_t,
    handleType: C.uint32_t,
    zirconHandle: C.uint32_t,
});


const VkSemaphoreGetZirconHandleInfoFUCHSIA = new T.StructBuffer("VkSemaphoreGetZirconHandleInfoFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    semaphore: C.uint32_t,
    handleType: C.uint32_t,
});


const VkPhysicalDeviceExternalFenceInfo = new T.StructBuffer("VkPhysicalDeviceExternalFenceInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleType: C.uint32_t,
});


const VkPhysicalDeviceExternalFenceInfoKHR = new T.StructBuffer("VkPhysicalDeviceExternalFenceInfoKHR", {

});


const VkExternalFenceProperties = new T.StructBuffer("VkExternalFenceProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    exportFromImportedHandleTypes: C.uint32_t,
    compatibleHandleTypes: C.uint32_t,
    externalFenceFeatures: C.uint32_t,
});


const VkExternalFencePropertiesKHR = new T.StructBuffer("VkExternalFencePropertiesKHR", {

});


const VkExportFenceCreateInfo = new T.StructBuffer("VkExportFenceCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleTypes: C.uint32_t,
});


const VkExportFenceCreateInfoKHR = new T.StructBuffer("VkExportFenceCreateInfoKHR", {

});


const VkImportFenceWin32HandleInfoKHR = new T.StructBuffer("VkImportFenceWin32HandleInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fence: C.uint32_t,
    flags: C.uint32_t,
    handleType: C.uint32_t,
    handle: C.uint64_t,
    name: C.uint32_t,
});


const VkExportFenceWin32HandleInfoKHR = new T.StructBuffer("VkExportFenceWin32HandleInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pAttributes: C.uint64_t,
    dwAccess: C.uint32_t,
    name: C.uint32_t,
});


const VkFenceGetWin32HandleInfoKHR = new T.StructBuffer("VkFenceGetWin32HandleInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fence: C.uint32_t,
    handleType: C.uint32_t,
});


const VkImportFenceFdInfoKHR = new T.StructBuffer("VkImportFenceFdInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fence: C.uint32_t,
    flags: C.uint32_t,
    handleType: C.uint32_t,
    fd: C.uint32_t,
});


const VkFenceGetFdInfoKHR = new T.StructBuffer("VkFenceGetFdInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fence: C.uint32_t,
    handleType: C.uint32_t,
});


const VkPhysicalDeviceMultiviewFeatures = new T.StructBuffer("VkPhysicalDeviceMultiviewFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    multiview: C.uint32_t,
    multiviewGeometryShader: C.uint32_t,
    multiviewTessellationShader: C.uint32_t,
});


const VkPhysicalDeviceMultiviewFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceMultiviewFeaturesKHR", {

});


const VkPhysicalDeviceMultiviewProperties = new T.StructBuffer("VkPhysicalDeviceMultiviewProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxMultiviewViewCount: C.uint32_t,
    maxMultiviewInstanceIndex: C.uint32_t,
});


const VkPhysicalDeviceMultiviewPropertiesKHR = new T.StructBuffer("VkPhysicalDeviceMultiviewPropertiesKHR", {

});


const VkRenderPassMultiviewCreateInfo = new T.StructBuffer("VkRenderPassMultiviewCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    subpassCount: C.uint32_t,
    pViewMasks: C.uint64_t,
    dependencyCount: C.uint32_t,
    pViewOffsets: C.uint64_t,
    correlationMaskCount: C.uint32_t,
    pCorrelationMasks: C.uint64_t,
});


const VkRenderPassMultiviewCreateInfoKHR = new T.StructBuffer("VkRenderPassMultiviewCreateInfoKHR", {

});


const VkSurfaceCapabilities2EXT = new T.StructBuffer("VkSurfaceCapabilities2EXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    minImageCount: C.uint32_t,
    maxImageCount: C.uint32_t,
    currentExtent: VkExtent2D,
    minImageExtent: VkExtent2D,
    maxImageExtent: VkExtent2D,
    maxImageArrayLayers: C.uint32_t,
    supportedTransforms: C.uint32_t,
    currentTransform: C.uint32_t,
    supportedCompositeAlpha: C.uint32_t,
    supportedUsageFlags: C.uint32_t,
    supportedSurfaceCounters: C.uint32_t,
});


const VkDisplayPowerInfoEXT = new T.StructBuffer("VkDisplayPowerInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    powerState: C.uint32_t,
});


const VkDeviceEventInfoEXT = new T.StructBuffer("VkDeviceEventInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceEvent: C.uint32_t,
});


const VkDisplayEventInfoEXT = new T.StructBuffer("VkDisplayEventInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    displayEvent: C.uint32_t,
});


const VkSwapchainCounterCreateInfoEXT = new T.StructBuffer("VkSwapchainCounterCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    surfaceCounters: C.uint32_t,
});


const VkPhysicalDeviceGroupProperties = new T.StructBuffer("VkPhysicalDeviceGroupProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    physicalDeviceCount: C.uint32_t,
    physicalDevices: C.uint32_t,
    subsetAllocation: C.uint32_t,
});


const VkPhysicalDeviceGroupPropertiesKHR = new T.StructBuffer("VkPhysicalDeviceGroupPropertiesKHR", {

});


const VkMemoryAllocateFlagsInfo = new T.StructBuffer("VkMemoryAllocateFlagsInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    deviceMask: C.uint32_t,
});


const VkMemoryAllocateFlagsInfoKHR = new T.StructBuffer("VkMemoryAllocateFlagsInfoKHR", {

});


const VkBindBufferMemoryInfo = new T.StructBuffer("VkBindBufferMemoryInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    buffer: C.uint64_t,
    memory: C.uint64_t,
    memoryOffset: C.uint64_t,
});


const VkBindBufferMemoryInfoKHR = new T.StructBuffer("VkBindBufferMemoryInfoKHR", {

});


const VkBindBufferMemoryDeviceGroupInfo = new T.StructBuffer("VkBindBufferMemoryDeviceGroupInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceIndexCount: C.uint32_t,
    pDeviceIndices: C.uint64_t,
});


const VkBindBufferMemoryDeviceGroupInfoKHR = new T.StructBuffer("VkBindBufferMemoryDeviceGroupInfoKHR", {

});


const VkBindImageMemoryInfo = new T.StructBuffer("VkBindImageMemoryInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    image: C.uint64_t,
    memory: C.uint64_t,
    memoryOffset: C.uint64_t,
});


const VkBindImageMemoryInfoKHR = new T.StructBuffer("VkBindImageMemoryInfoKHR", {

});


const VkBindImageMemoryDeviceGroupInfo = new T.StructBuffer("VkBindImageMemoryDeviceGroupInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceIndexCount: C.uint32_t,
    pDeviceIndices: C.uint64_t,
    splitInstanceBindRegionCount: C.uint32_t,
    pSplitInstanceBindRegions: C.uint64_t,
});


const VkBindImageMemoryDeviceGroupInfoKHR = new T.StructBuffer("VkBindImageMemoryDeviceGroupInfoKHR", {

});


const VkDeviceGroupRenderPassBeginInfo = new T.StructBuffer("VkDeviceGroupRenderPassBeginInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceMask: C.uint32_t,
    deviceRenderAreaCount: C.uint32_t,
    pDeviceRenderAreas: C.uint64_t,
});


const VkDeviceGroupRenderPassBeginInfoKHR = new T.StructBuffer("VkDeviceGroupRenderPassBeginInfoKHR", {

});


const VkDeviceGroupCommandBufferBeginInfo = new T.StructBuffer("VkDeviceGroupCommandBufferBeginInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceMask: C.uint32_t,
});


const VkDeviceGroupCommandBufferBeginInfoKHR = new T.StructBuffer("VkDeviceGroupCommandBufferBeginInfoKHR", {

});


const VkDeviceGroupSubmitInfo = new T.StructBuffer("VkDeviceGroupSubmitInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    waitSemaphoreCount: C.uint32_t,
    pWaitSemaphoreDeviceIndices: C.uint64_t,
    commandBufferCount: C.uint32_t,
    pCommandBufferDeviceMasks: C.uint64_t,
    signalSemaphoreCount: C.uint32_t,
    pSignalSemaphoreDeviceIndices: C.uint64_t,
});


const VkDeviceGroupSubmitInfoKHR = new T.StructBuffer("VkDeviceGroupSubmitInfoKHR", {

});


const VkDeviceGroupBindSparseInfo = new T.StructBuffer("VkDeviceGroupBindSparseInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    resourceDeviceIndex: C.uint32_t,
    memoryDeviceIndex: C.uint32_t,
});


const VkDeviceGroupBindSparseInfoKHR = new T.StructBuffer("VkDeviceGroupBindSparseInfoKHR", {

});


const VkDeviceGroupPresentCapabilitiesKHR = new T.StructBuffer("VkDeviceGroupPresentCapabilitiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    presentMask: C.uint32_t[enums.VK_MAX_DEVICE_GROUP_SIZE],
    modes: C.uint32_t,
});


const VkImageSwapchainCreateInfoKHR = new T.StructBuffer("VkImageSwapchainCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    swapchain: C.uint32_t,
});


const VkBindImageMemorySwapchainInfoKHR = new T.StructBuffer("VkBindImageMemorySwapchainInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    swapchain: C.uint32_t,
    imageIndex: C.uint32_t,
});


const VkAcquireNextImageInfoKHR = new T.StructBuffer("VkAcquireNextImageInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    swapchain: C.uint32_t,
    timeout: C.uint64_t,
    semaphore: C.uint32_t,
    fence: C.uint32_t,
    deviceMask: C.uint32_t,
});


const VkDeviceGroupPresentInfoKHR = new T.StructBuffer("VkDeviceGroupPresentInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    swapchainCount: C.uint32_t,
    pDeviceMasks: C.uint64_t,
    mode: C.uint32_t,
});


const VkDeviceGroupDeviceCreateInfo = new T.StructBuffer("VkDeviceGroupDeviceCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    physicalDeviceCount: C.uint32_t,
    pPhysicalDevices: C.uint64_t,
});


const VkDeviceGroupDeviceCreateInfoKHR = new T.StructBuffer("VkDeviceGroupDeviceCreateInfoKHR", {

});


const VkDeviceGroupSwapchainCreateInfoKHR = new T.StructBuffer("VkDeviceGroupSwapchainCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    modes: C.uint32_t,
});


const VkDescriptorUpdateTemplateEntry = new T.StructBuffer("VkDescriptorUpdateTemplateEntry", {
    dstBinding: C.uint32_t,
    dstArrayElement: C.uint32_t,
    descriptorCount: C.uint32_t,
    descriptorType: C.uint32_t,
    offset: C.uint64_t,
    stride: C.uint64_t,
});


const VkDescriptorUpdateTemplateEntryKHR = new T.StructBuffer("VkDescriptorUpdateTemplateEntryKHR", {

});


const VkDescriptorUpdateTemplateCreateInfo = new T.StructBuffer("VkDescriptorUpdateTemplateCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    descriptorUpdateEntryCount: C.uint32_t,
    pDescriptorUpdateEntries: C.uint64_t,
    templateType: C.uint32_t,
    descriptorSetLayout: C.uint32_t,
    pipelineBindPoint: C.uint32_t,
    pipelineLayout: C.uint32_t,
    set: C.uint32_t,
});


const VkDescriptorUpdateTemplateCreateInfoKHR = new T.StructBuffer("VkDescriptorUpdateTemplateCreateInfoKHR", {

});


const VkXYColorEXT = new T.StructBuffer("VkXYColorEXT", {
    x: C.float,
    y: C.float,
});


const VkPhysicalDevicePresentIdFeaturesKHR = new T.StructBuffer("VkPhysicalDevicePresentIdFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    presentId: C.uint32_t,
});


const VkPresentIdKHR = new T.StructBuffer("VkPresentIdKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    swapchainCount: C.uint32_t,
    pPresentIds: C.uint64_t,
});


const VkPhysicalDevicePresentWaitFeaturesKHR = new T.StructBuffer("VkPhysicalDevicePresentWaitFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    presentWait: C.uint32_t,
});


const VkHdrMetadataEXT = new T.StructBuffer("VkHdrMetadataEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    displayPrimaryRed: C.uint32_t,
    displayPrimaryGreen: C.uint32_t,
    displayPrimaryBlue: C.uint32_t,
    whitePoint: C.uint32_t,
    maxLuminance: C.float,
    minLuminance: C.float,
    maxContentLightLevel: C.float,
    maxFrameAverageLightLevel: C.float,
});


const VkDisplayNativeHdrSurfaceCapabilitiesAMD = new T.StructBuffer("VkDisplayNativeHdrSurfaceCapabilitiesAMD", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    localDimmingSupport: C.uint32_t,
});


const VkSwapchainDisplayNativeHdrCreateInfoAMD = new T.StructBuffer("VkSwapchainDisplayNativeHdrCreateInfoAMD", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    localDimmingEnable: C.uint32_t,
});


const VkRefreshCycleDurationGOOGLE = new T.StructBuffer("VkRefreshCycleDurationGOOGLE", {
    refreshDuration: C.uint64_t,
});


const VkPastPresentationTimingGOOGLE = new T.StructBuffer("VkPastPresentationTimingGOOGLE", {
    presentID: C.uint32_t,
    desiredPresentTime: C.uint64_t,
    actualPresentTime: C.uint64_t,
    earliestPresentTime: C.uint64_t,
    presentMargin: C.uint64_t,
});


const VkPresentTimesInfoGOOGLE = new T.StructBuffer("VkPresentTimesInfoGOOGLE", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    swapchainCount: C.uint32_t,
    pTimes: C.uint64_t,
});


const VkPresentTimeGOOGLE = new T.StructBuffer("VkPresentTimeGOOGLE", {
    presentID: C.uint32_t,
    desiredPresentTime: C.uint64_t,
});


const VkIOSSurfaceCreateInfoMVK = new T.StructBuffer("VkIOSSurfaceCreateInfoMVK", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    pView: C.uint64_t,
});


const VkMacOSSurfaceCreateInfoMVK = new T.StructBuffer("VkMacOSSurfaceCreateInfoMVK", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    pView: C.uint64_t,
});


const VkMetalSurfaceCreateInfoEXT = new T.StructBuffer("VkMetalSurfaceCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    pLayer: C.uint64_t,
});


const VkViewportWScalingNV = new T.StructBuffer("VkViewportWScalingNV", {
    xcoeff: C.float,
    ycoeff: C.float,
});


const VkPipelineViewportWScalingStateCreateInfoNV = new T.StructBuffer("VkPipelineViewportWScalingStateCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    viewportWScalingEnable: C.uint32_t,
    viewportCount: C.uint32_t,
    pViewportWScalings: C.uint64_t,
});


const VkViewportSwizzleNV = new T.StructBuffer("VkViewportSwizzleNV", {
    x: C.uint32_t,
    y: C.uint32_t,
    z: C.uint32_t,
    w: C.uint32_t,
});


const VkPipelineViewportSwizzleStateCreateInfoNV = new T.StructBuffer("VkPipelineViewportSwizzleStateCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    viewportCount: C.uint32_t,
    pViewportSwizzles: C.uint64_t,
});


const VkPhysicalDeviceDiscardRectanglePropertiesEXT = new T.StructBuffer("VkPhysicalDeviceDiscardRectanglePropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxDiscardRectangles: C.uint32_t,
});


const VkPipelineDiscardRectangleStateCreateInfoEXT = new T.StructBuffer("VkPipelineDiscardRectangleStateCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    discardRectangleMode: C.uint32_t,
    discardRectangleCount: C.uint32_t,
    pDiscardRectangles: C.uint64_t,
});


const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX = new T.StructBuffer("VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    perViewPositionAllComponents: C.uint32_t,
});


const VkInputAttachmentAspectReference = new T.StructBuffer("VkInputAttachmentAspectReference", {
    subpass: C.uint32_t,
    inputAttachmentIndex: C.uint32_t,
    aspectMask: C.uint32_t,
});


const VkInputAttachmentAspectReferenceKHR = new T.StructBuffer("VkInputAttachmentAspectReferenceKHR", {

});


const VkRenderPassInputAttachmentAspectCreateInfo = new T.StructBuffer("VkRenderPassInputAttachmentAspectCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    aspectReferenceCount: C.uint32_t,
    pAspectReferences: C.uint64_t,
});


const VkRenderPassInputAttachmentAspectCreateInfoKHR = new T.StructBuffer("VkRenderPassInputAttachmentAspectCreateInfoKHR", {

});


const VkPhysicalDeviceSurfaceInfo2KHR = new T.StructBuffer("VkPhysicalDeviceSurfaceInfo2KHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    surface: C.uint32_t,
});


const VkSurfaceCapabilities2KHR = new T.StructBuffer("VkSurfaceCapabilities2KHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    surfaceCapabilities: C.uint32_t,
});


const VkSurfaceFormat2KHR = new T.StructBuffer("VkSurfaceFormat2KHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    surfaceFormat: C.uint32_t,
});


const VkDisplayProperties2KHR = new T.StructBuffer("VkDisplayProperties2KHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    displayProperties: C.uint32_t,
});


const VkDisplayPlaneProperties2KHR = new T.StructBuffer("VkDisplayPlaneProperties2KHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    displayPlaneProperties: C.uint32_t,
});


const VkDisplayModeProperties2KHR = new T.StructBuffer("VkDisplayModeProperties2KHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    displayModeProperties: C.uint32_t,
});


const VkDisplayPlaneInfo2KHR = new T.StructBuffer("VkDisplayPlaneInfo2KHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    mode: C.uint32_t,
    planeIndex: C.uint32_t,
});


const VkDisplayPlaneCapabilities2KHR = new T.StructBuffer("VkDisplayPlaneCapabilities2KHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    capabilities: C.uint32_t,
});


const VkSharedPresentSurfaceCapabilitiesKHR = new T.StructBuffer("VkSharedPresentSurfaceCapabilitiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    sharedPresentSupportedUsageFlags: C.uint32_t,
});


const VkPhysicalDevice16BitStorageFeatures = new T.StructBuffer("VkPhysicalDevice16BitStorageFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    storageBuffer16BitAccess: C.uint32_t,
    uniformAndStorageBuffer16BitAccess: C.uint32_t,
    storagePushConstant16: C.uint32_t,
    storageInputOutput16: C.uint32_t,
});


const VkPhysicalDevice16BitStorageFeaturesKHR = new T.StructBuffer("VkPhysicalDevice16BitStorageFeaturesKHR", {

});


const VkPhysicalDeviceSubgroupProperties = new T.StructBuffer("VkPhysicalDeviceSubgroupProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    subgroupSize: C.uint32_t,
    supportedStages: C.uint32_t,
    supportedOperations: C.uint32_t,
    quadOperationsInAllStages: C.uint32_t,
});


const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures = new T.StructBuffer("VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderSubgroupExtendedTypes: C.uint32_t,
});


const VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR", {

});


const VkBufferMemoryRequirementsInfo2 = new T.StructBuffer("VkBufferMemoryRequirementsInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    buffer: C.uint64_t,
});


const VkBufferMemoryRequirementsInfo2KHR = new T.StructBuffer("VkBufferMemoryRequirementsInfo2KHR", {

});


const VkDeviceBufferMemoryRequirements = new T.StructBuffer("VkDeviceBufferMemoryRequirements", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pCreateInfo: C.uint64_t,
});


const VkDeviceBufferMemoryRequirementsKHR = new T.StructBuffer("VkDeviceBufferMemoryRequirementsKHR", {

});


const VkImageMemoryRequirementsInfo2 = new T.StructBuffer("VkImageMemoryRequirementsInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    image: C.uint64_t,
});


const VkImageMemoryRequirementsInfo2KHR = new T.StructBuffer("VkImageMemoryRequirementsInfo2KHR", {

});


const VkImageSparseMemoryRequirementsInfo2 = new T.StructBuffer("VkImageSparseMemoryRequirementsInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    image: C.uint64_t,
});


const VkImageSparseMemoryRequirementsInfo2KHR = new T.StructBuffer("VkImageSparseMemoryRequirementsInfo2KHR", {

});


const VkDeviceImageMemoryRequirements = new T.StructBuffer("VkDeviceImageMemoryRequirements", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pCreateInfo: C.uint64_t,
    planeAspect: C.uint32_t,
});


const VkDeviceImageMemoryRequirementsKHR = new T.StructBuffer("VkDeviceImageMemoryRequirementsKHR", {

});


const VkMemoryRequirements2 = new T.StructBuffer("VkMemoryRequirements2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memoryRequirements: C.uint32_t,
});


const VkMemoryRequirements2KHR = new T.StructBuffer("VkMemoryRequirements2KHR", {

});


const VkSparseImageMemoryRequirements2 = new T.StructBuffer("VkSparseImageMemoryRequirements2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memoryRequirements: C.uint32_t,
});


const VkSparseImageMemoryRequirements2KHR = new T.StructBuffer("VkSparseImageMemoryRequirements2KHR", {

});


const VkPhysicalDevicePointClippingProperties = new T.StructBuffer("VkPhysicalDevicePointClippingProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pointClippingBehavior: C.uint32_t,
});


const VkPhysicalDevicePointClippingPropertiesKHR = new T.StructBuffer("VkPhysicalDevicePointClippingPropertiesKHR", {

});


const VkMemoryDedicatedRequirements = new T.StructBuffer("VkMemoryDedicatedRequirements", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    prefersDedicatedAllocation: C.uint32_t,
    requiresDedicatedAllocation: C.uint32_t,
});


const VkMemoryDedicatedRequirementsKHR = new T.StructBuffer("VkMemoryDedicatedRequirementsKHR", {

});


const VkMemoryDedicatedAllocateInfo = new T.StructBuffer("VkMemoryDedicatedAllocateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    image: C.uint64_t,
    buffer: C.uint64_t,
});


const VkMemoryDedicatedAllocateInfoKHR = new T.StructBuffer("VkMemoryDedicatedAllocateInfoKHR", {

});


const VkImageViewUsageCreateInfo = new T.StructBuffer("VkImageViewUsageCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    usage: C.uint32_t,
});


const VkImageViewUsageCreateInfoKHR = new T.StructBuffer("VkImageViewUsageCreateInfoKHR", {

});


const VkPipelineTessellationDomainOriginStateCreateInfo = new T.StructBuffer("VkPipelineTessellationDomainOriginStateCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    domainOrigin: C.uint32_t,
});


const VkPipelineTessellationDomainOriginStateCreateInfoKHR = new T.StructBuffer("VkPipelineTessellationDomainOriginStateCreateInfoKHR", {

});


const VkSamplerYcbcrConversionInfo = new T.StructBuffer("VkSamplerYcbcrConversionInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    conversion: C.uint32_t,
});


const VkSamplerYcbcrConversionInfoKHR = new T.StructBuffer("VkSamplerYcbcrConversionInfoKHR", {

});


const VkSamplerYcbcrConversionCreateInfo = new T.StructBuffer("VkSamplerYcbcrConversionCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    format: C.uint32_t,
    ycbcrModel: C.uint32_t,
    ycbcrRange: C.uint32_t,
    components: C.uint32_t,
    xChromaOffset: C.uint32_t,
    yChromaOffset: C.uint32_t,
    chromaFilter: C.uint32_t,
    forceExplicitReconstruction: C.uint32_t,
});


const VkSamplerYcbcrConversionCreateInfoKHR = new T.StructBuffer("VkSamplerYcbcrConversionCreateInfoKHR", {

});


const VkBindImagePlaneMemoryInfo = new T.StructBuffer("VkBindImagePlaneMemoryInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    planeAspect: C.uint32_t,
});


const VkBindImagePlaneMemoryInfoKHR = new T.StructBuffer("VkBindImagePlaneMemoryInfoKHR", {

});


const VkImagePlaneMemoryRequirementsInfo = new T.StructBuffer("VkImagePlaneMemoryRequirementsInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    planeAspect: C.uint32_t,
});


const VkImagePlaneMemoryRequirementsInfoKHR = new T.StructBuffer("VkImagePlaneMemoryRequirementsInfoKHR", {

});


const VkPhysicalDeviceSamplerYcbcrConversionFeatures = new T.StructBuffer("VkPhysicalDeviceSamplerYcbcrConversionFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    samplerYcbcrConversion: C.uint32_t,
});


const VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR", {

});


const VkSamplerYcbcrConversionImageFormatProperties = new T.StructBuffer("VkSamplerYcbcrConversionImageFormatProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    combinedImageSamplerDescriptorCount: C.uint32_t,
});


const VkSamplerYcbcrConversionImageFormatPropertiesKHR = new T.StructBuffer("VkSamplerYcbcrConversionImageFormatPropertiesKHR", {

});


const VkTextureLODGatherFormatPropertiesAMD = new T.StructBuffer("VkTextureLODGatherFormatPropertiesAMD", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    supportsTextureGatherLODBiasAMD: C.uint32_t,
});


const VkConditionalRenderingBeginInfoEXT = new T.StructBuffer("VkConditionalRenderingBeginInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    buffer: C.uint64_t,
    offset: C.uint64_t,
    flags: C.uint32_t,
});


const VkProtectedSubmitInfo = new T.StructBuffer("VkProtectedSubmitInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    protectedSubmit: C.uint32_t,
});


const VkPhysicalDeviceProtectedMemoryFeatures = new T.StructBuffer("VkPhysicalDeviceProtectedMemoryFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    protectedMemory: C.uint32_t,
});


const VkPhysicalDeviceProtectedMemoryProperties = new T.StructBuffer("VkPhysicalDeviceProtectedMemoryProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    protectedNoFault: C.uint32_t,
});


const VkDeviceQueueInfo2 = new T.StructBuffer("VkDeviceQueueInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    queueFamilyIndex: C.uint32_t,
    queueIndex: C.uint32_t,
});


const VkPipelineCoverageToColorStateCreateInfoNV = new T.StructBuffer("VkPipelineCoverageToColorStateCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    coverageToColorEnable: C.uint32_t,
    coverageToColorLocation: C.uint32_t,
});


const VkPhysicalDeviceSamplerFilterMinmaxProperties = new T.StructBuffer("VkPhysicalDeviceSamplerFilterMinmaxProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    filterMinmaxSingleComponentFormats: C.uint32_t,
    filterMinmaxImageComponentMapping: C.uint32_t,
});


const VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT", {

});


const VkSampleLocationEXT = new T.StructBuffer("VkSampleLocationEXT", {
    x: C.float,
    y: C.float,
});


const VkSampleLocationsInfoEXT = new T.StructBuffer("VkSampleLocationsInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    sampleLocationsPerPixel: C.uint32_t,
    sampleLocationGridSize: VkExtent2D,
    sampleLocationsCount: C.uint32_t,
    pSampleLocations: C.uint64_t,
});


const VkAttachmentSampleLocationsEXT = new T.StructBuffer("VkAttachmentSampleLocationsEXT", {
    attachmentIndex: C.uint32_t,
    sampleLocationsInfo: C.uint32_t,
});


const VkSubpassSampleLocationsEXT = new T.StructBuffer("VkSubpassSampleLocationsEXT", {
    subpassIndex: C.uint32_t,
    sampleLocationsInfo: C.uint32_t,
});


const VkRenderPassSampleLocationsBeginInfoEXT = new T.StructBuffer("VkRenderPassSampleLocationsBeginInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    attachmentInitialSampleLocationsCount: C.uint32_t,
    pAttachmentInitialSampleLocations: C.uint64_t,
    postSubpassSampleLocationsCount: C.uint32_t,
    pPostSubpassSampleLocations: C.uint64_t,
});


const VkPipelineSampleLocationsStateCreateInfoEXT = new T.StructBuffer("VkPipelineSampleLocationsStateCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    sampleLocationsEnable: C.uint32_t,
    sampleLocationsInfo: C.uint32_t,
});


const VkPhysicalDeviceSampleLocationsPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceSampleLocationsPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    sampleLocationSampleCounts: C.uint32_t,
    maxSampleLocationGridSize: VkExtent2D,
    sampleLocationCoordinateRange: C.float[2],
    sampleLocationSubPixelBits: C.uint32_t,
    variableSampleLocations: C.uint32_t,
});


const VkMultisamplePropertiesEXT = new T.StructBuffer("VkMultisamplePropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxSampleLocationGridSize: VkExtent2D,
});


const VkSamplerReductionModeCreateInfo = new T.StructBuffer("VkSamplerReductionModeCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    reductionMode: C.uint32_t,
});


const VkSamplerReductionModeCreateInfoEXT = new T.StructBuffer("VkSamplerReductionModeCreateInfoEXT", {

});


const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    advancedBlendCoherentOperations: C.uint32_t,
});


const VkPhysicalDeviceMultiDrawFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceMultiDrawFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    multiDraw: C.uint32_t,
});


const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    advancedBlendMaxColorAttachments: C.uint32_t,
    advancedBlendIndependentBlend: C.uint32_t,
    advancedBlendNonPremultipliedSrcColor: C.uint32_t,
    advancedBlendNonPremultipliedDstColor: C.uint32_t,
    advancedBlendCorrelatedOverlap: C.uint32_t,
    advancedBlendAllOperations: C.uint32_t,
});


const VkPipelineColorBlendAdvancedStateCreateInfoEXT = new T.StructBuffer("VkPipelineColorBlendAdvancedStateCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcPremultiplied: C.uint32_t,
    dstPremultiplied: C.uint32_t,
    blendOverlap: C.uint32_t,
});


const VkPhysicalDeviceInlineUniformBlockFeatures = new T.StructBuffer("VkPhysicalDeviceInlineUniformBlockFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    inlineUniformBlock: C.uint32_t,
    descriptorBindingInlineUniformBlockUpdateAfterBind: C.uint32_t,
});


const VkPhysicalDeviceInlineUniformBlockFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceInlineUniformBlockFeaturesEXT", {

});


const VkPhysicalDeviceInlineUniformBlockProperties = new T.StructBuffer("VkPhysicalDeviceInlineUniformBlockProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxInlineUniformBlockSize: C.uint32_t,
    maxPerStageDescriptorInlineUniformBlocks: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks: C.uint32_t,
    maxDescriptorSetInlineUniformBlocks: C.uint32_t,
    maxDescriptorSetUpdateAfterBindInlineUniformBlocks: C.uint32_t,
});


const VkPhysicalDeviceInlineUniformBlockPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceInlineUniformBlockPropertiesEXT", {

});


const VkWriteDescriptorSetInlineUniformBlock = new T.StructBuffer("VkWriteDescriptorSetInlineUniformBlock", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    dataSize: C.uint32_t,
    pData: C.uint64_t,
});


const VkWriteDescriptorSetInlineUniformBlockEXT = new T.StructBuffer("VkWriteDescriptorSetInlineUniformBlockEXT", {

});


const VkDescriptorPoolInlineUniformBlockCreateInfo = new T.StructBuffer("VkDescriptorPoolInlineUniformBlockCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxInlineUniformBlockBindings: C.uint32_t,
});


const VkDescriptorPoolInlineUniformBlockCreateInfoEXT = new T.StructBuffer("VkDescriptorPoolInlineUniformBlockCreateInfoEXT", {

});


const VkPipelineCoverageModulationStateCreateInfoNV = new T.StructBuffer("VkPipelineCoverageModulationStateCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    coverageModulationMode: C.uint32_t,
    coverageModulationTableEnable: C.uint32_t,
    coverageModulationTableCount: C.uint32_t,
    pCoverageModulationTable: C.uint64_t,
});


const VkImageFormatListCreateInfo = new T.StructBuffer("VkImageFormatListCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    viewFormatCount: C.uint32_t,
    pViewFormats: C.uint64_t,
});


const VkImageFormatListCreateInfoKHR = new T.StructBuffer("VkImageFormatListCreateInfoKHR", {

});


const VkValidationCacheCreateInfoEXT = new T.StructBuffer("VkValidationCacheCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    initialDataSize: C.uint64_t,
    pInitialData: C.uint64_t,
});


const VkShaderModuleValidationCacheCreateInfoEXT = new T.StructBuffer("VkShaderModuleValidationCacheCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    validationCache: C.uint32_t,
});


const VkPhysicalDeviceMaintenance3Properties = new T.StructBuffer("VkPhysicalDeviceMaintenance3Properties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxPerSetDescriptors: C.uint32_t,
    maxMemoryAllocationSize: C.uint64_t,
});


const VkPhysicalDeviceMaintenance3PropertiesKHR = new T.StructBuffer("VkPhysicalDeviceMaintenance3PropertiesKHR", {

});


const VkPhysicalDeviceMaintenance4Features = new T.StructBuffer("VkPhysicalDeviceMaintenance4Features", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maintenance4: C.uint32_t,
});


const VkPhysicalDeviceMaintenance4FeaturesKHR = new T.StructBuffer("VkPhysicalDeviceMaintenance4FeaturesKHR", {

});


const VkPhysicalDeviceMaintenance4Properties = new T.StructBuffer("VkPhysicalDeviceMaintenance4Properties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxBufferSize: C.uint64_t,
});


const VkPhysicalDeviceMaintenance4PropertiesKHR = new T.StructBuffer("VkPhysicalDeviceMaintenance4PropertiesKHR", {

});


const VkDescriptorSetLayoutSupport = new T.StructBuffer("VkDescriptorSetLayoutSupport", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    supported: C.uint32_t,
});


const VkDescriptorSetLayoutSupportKHR = new T.StructBuffer("VkDescriptorSetLayoutSupportKHR", {

});


const VkPhysicalDeviceShaderDrawParametersFeatures = new T.StructBuffer("VkPhysicalDeviceShaderDrawParametersFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderDrawParameters: C.uint32_t,
});


const VkPhysicalDeviceShaderDrawParameterFeatures = new T.StructBuffer("VkPhysicalDeviceShaderDrawParameterFeatures", {

});


const VkPhysicalDeviceShaderFloat16Int8Features = new T.StructBuffer("VkPhysicalDeviceShaderFloat16Int8Features", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderFloat16: C.uint32_t,
    shaderInt8: C.uint32_t,
});


const VkPhysicalDeviceShaderFloat16Int8FeaturesKHR = new T.StructBuffer("VkPhysicalDeviceShaderFloat16Int8FeaturesKHR", {

});


const VkPhysicalDeviceFloat16Int8FeaturesKHR = new T.StructBuffer("VkPhysicalDeviceFloat16Int8FeaturesKHR", {

});


const VkPhysicalDeviceFloatControlsProperties = new T.StructBuffer("VkPhysicalDeviceFloatControlsProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    denormBehaviorIndependence: C.uint32_t,
    roundingModeIndependence: C.uint32_t,
    shaderSignedZeroInfNanPreserveFloat16: C.uint32_t,
    shaderSignedZeroInfNanPreserveFloat32: C.uint32_t,
    shaderSignedZeroInfNanPreserveFloat64: C.uint32_t,
    shaderDenormPreserveFloat16: C.uint32_t,
    shaderDenormPreserveFloat32: C.uint32_t,
    shaderDenormPreserveFloat64: C.uint32_t,
    shaderDenormFlushToZeroFloat16: C.uint32_t,
    shaderDenormFlushToZeroFloat32: C.uint32_t,
    shaderDenormFlushToZeroFloat64: C.uint32_t,
    shaderRoundingModeRTEFloat16: C.uint32_t,
    shaderRoundingModeRTEFloat32: C.uint32_t,
    shaderRoundingModeRTEFloat64: C.uint32_t,
    shaderRoundingModeRTZFloat16: C.uint32_t,
    shaderRoundingModeRTZFloat32: C.uint32_t,
    shaderRoundingModeRTZFloat64: C.uint32_t,
});


const VkPhysicalDeviceFloatControlsPropertiesKHR = new T.StructBuffer("VkPhysicalDeviceFloatControlsPropertiesKHR", {

});


const VkPhysicalDeviceHostQueryResetFeatures = new T.StructBuffer("VkPhysicalDeviceHostQueryResetFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    hostQueryReset: C.uint32_t,
});


const VkPhysicalDeviceHostQueryResetFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceHostQueryResetFeaturesEXT", {

});


const VkNativeBufferUsage2ANDROID = new T.StructBuffer("VkNativeBufferUsage2ANDROID", {
    consumer: C.uint64_t,
    producer: C.uint64_t,
});


const VkNativeBufferANDROID = new T.StructBuffer("VkNativeBufferANDROID", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handle: C.uint64_t,
    stride: C.uint32_t,
    format: C.uint32_t,
    usage: C.uint32_t,
    usage2: C.uint32_t,
});


const VkSwapchainImageCreateInfoANDROID = new T.StructBuffer("VkSwapchainImageCreateInfoANDROID", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    usage: C.uint32_t,
});


const VkPhysicalDevicePresentationPropertiesANDROID = new T.StructBuffer("VkPhysicalDevicePresentationPropertiesANDROID", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    sharedImage: C.uint32_t,
});


const VkShaderResourceUsageAMD = new T.StructBuffer("VkShaderResourceUsageAMD", {
    numUsedVgprs: C.uint32_t,
    numUsedSgprs: C.uint32_t,
    ldsSizePerLocalWorkGroup: C.uint32_t,
    ldsUsageSizeInBytes: C.uint64_t,
    scratchMemUsageInBytes: C.uint64_t,
});


const VkShaderStatisticsInfoAMD = new T.StructBuffer("VkShaderStatisticsInfoAMD", {
    shaderStageMask: C.uint32_t,
    resourceUsage: C.uint32_t,
    numPhysicalVgprs: C.uint32_t,
    numPhysicalSgprs: C.uint32_t,
    numAvailableVgprs: C.uint32_t,
    numAvailableSgprs: C.uint32_t,
    computeWorkGroupSize: C.uint32_t[3],
});


const VkDeviceQueueGlobalPriorityCreateInfoKHR = new T.StructBuffer("VkDeviceQueueGlobalPriorityCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    globalPriority: C.uint32_t,
});


const VkDeviceQueueGlobalPriorityCreateInfoEXT = new T.StructBuffer("VkDeviceQueueGlobalPriorityCreateInfoEXT", {

});


const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    globalPriorityQuery: C.uint32_t,
});


const VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT", {

});


const VkQueueFamilyGlobalPriorityPropertiesKHR = new T.StructBuffer("VkQueueFamilyGlobalPriorityPropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    priorityCount: C.uint32_t,
    priorities: C.uint32_t,
});


const VkQueueFamilyGlobalPriorityPropertiesEXT = new T.StructBuffer("VkQueueFamilyGlobalPriorityPropertiesEXT", {

});


const VkDebugUtilsObjectNameInfoEXT = new T.StructBuffer("VkDebugUtilsObjectNameInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    objectType: C.uint32_t,
    objectHandle: C.uint64_t,
    pObjectName: C.uint64_t,
});


const VkDebugUtilsObjectTagInfoEXT = new T.StructBuffer("VkDebugUtilsObjectTagInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    objectType: C.uint32_t,
    objectHandle: C.uint64_t,
    tagName: C.uint64_t,
    tagSize: C.uint64_t,
    pTag: C.uint64_t,
});


const VkDebugUtilsLabelEXT = new T.StructBuffer("VkDebugUtilsLabelEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pLabelName: C.uint64_t,
    color: C.float[4],
});


const VkDebugUtilsMessengerCreateInfoEXT = new T.StructBuffer("VkDebugUtilsMessengerCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    messageSeverity: C.uint32_t,
    messageType: C.uint32_t,
    pfnUserCallback: C.uint32_t,
    pUserData: C.uint64_t,
});


const VkDebugUtilsMessengerCallbackDataEXT = new T.StructBuffer("VkDebugUtilsMessengerCallbackDataEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    pMessageIdName: C.uint64_t,
    messageIdNumber: C.int32_t,
    pMessage: C.uint64_t,
    queueLabelCount: C.uint32_t,
    pQueueLabels: C.uint64_t,
    cmdBufLabelCount: C.uint32_t,
    pCmdBufLabels: C.uint64_t,
    objectCount: C.uint32_t,
    pObjects: C.uint64_t,
});


const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceDeviceMemoryReportFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceMemoryReport: C.uint32_t,
});


const VkDeviceDeviceMemoryReportCreateInfoEXT = new T.StructBuffer("VkDeviceDeviceMemoryReportCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    pfnUserCallback: C.uint32_t,
    pUserData: C.uint64_t,
});


const VkDeviceMemoryReportCallbackDataEXT = new T.StructBuffer("VkDeviceMemoryReportCallbackDataEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    type: C.uint32_t,
    memoryObjectId: C.uint64_t,
    size: C.uint64_t,
    objectType: C.uint32_t,
    objectHandle: C.uint64_t,
    heapIndex: C.uint32_t,
});


const VkImportMemoryHostPointerInfoEXT = new T.StructBuffer("VkImportMemoryHostPointerInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    handleType: C.uint32_t,
    pHostPointer: C.uint64_t,
});


const VkMemoryHostPointerPropertiesEXT = new T.StructBuffer("VkMemoryHostPointerPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memoryTypeBits: C.uint32_t,
});


const VkPhysicalDeviceExternalMemoryHostPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceExternalMemoryHostPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    minImportedHostPointerAlignment: C.uint64_t,
});


const VkPhysicalDeviceConservativeRasterizationPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceConservativeRasterizationPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    primitiveOverestimationSize: C.float,
    maxExtraPrimitiveOverestimationSize: C.float,
    extraPrimitiveOverestimationSizeGranularity: C.float,
    primitiveUnderestimation: C.uint32_t,
    conservativePointAndLineRasterization: C.uint32_t,
    degenerateTrianglesRasterized: C.uint32_t,
    degenerateLinesRasterized: C.uint32_t,
    fullyCoveredFragmentShaderInputVariable: C.uint32_t,
    conservativeRasterizationPostDepthCoverage: C.uint32_t,
});


const VkCalibratedTimestampInfoEXT = new T.StructBuffer("VkCalibratedTimestampInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    timeDomain: C.uint32_t,
});


const VkPhysicalDeviceShaderCorePropertiesAMD = new T.StructBuffer("VkPhysicalDeviceShaderCorePropertiesAMD", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderEngineCount: C.uint32_t,
    shaderArraysPerEngineCount: C.uint32_t,
    computeUnitsPerShaderArray: C.uint32_t,
    simdPerComputeUnit: C.uint32_t,
    wavefrontsPerSimd: C.uint32_t,
    wavefrontSize: C.uint32_t,
    sgprsPerSimd: C.uint32_t,
    minSgprAllocation: C.uint32_t,
    maxSgprAllocation: C.uint32_t,
    sgprAllocationGranularity: C.uint32_t,
    vgprsPerSimd: C.uint32_t,
    minVgprAllocation: C.uint32_t,
    maxVgprAllocation: C.uint32_t,
    vgprAllocationGranularity: C.uint32_t,
});


const VkPhysicalDeviceShaderCoreProperties2AMD = new T.StructBuffer("VkPhysicalDeviceShaderCoreProperties2AMD", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderCoreFeatures: C.uint32_t,
    activeComputeUnitCount: C.uint32_t,
});


const VkPipelineRasterizationConservativeStateCreateInfoEXT = new T.StructBuffer("VkPipelineRasterizationConservativeStateCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    conservativeRasterizationMode: C.uint32_t,
    extraPrimitiveOverestimationSize: C.float,
});


const VkPhysicalDeviceDescriptorIndexingFeatures = new T.StructBuffer("VkPhysicalDeviceDescriptorIndexingFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderInputAttachmentArrayDynamicIndexing: C.uint32_t,
    shaderUniformTexelBufferArrayDynamicIndexing: C.uint32_t,
    shaderStorageTexelBufferArrayDynamicIndexing: C.uint32_t,
    shaderUniformBufferArrayNonUniformIndexing: C.uint32_t,
    shaderSampledImageArrayNonUniformIndexing: C.uint32_t,
    shaderStorageBufferArrayNonUniformIndexing: C.uint32_t,
    shaderStorageImageArrayNonUniformIndexing: C.uint32_t,
    shaderInputAttachmentArrayNonUniformIndexing: C.uint32_t,
    shaderUniformTexelBufferArrayNonUniformIndexing: C.uint32_t,
    shaderStorageTexelBufferArrayNonUniformIndexing: C.uint32_t,
    descriptorBindingUniformBufferUpdateAfterBind: C.uint32_t,
    descriptorBindingSampledImageUpdateAfterBind: C.uint32_t,
    descriptorBindingStorageImageUpdateAfterBind: C.uint32_t,
    descriptorBindingStorageBufferUpdateAfterBind: C.uint32_t,
    descriptorBindingUniformTexelBufferUpdateAfterBind: C.uint32_t,
    descriptorBindingStorageTexelBufferUpdateAfterBind: C.uint32_t,
    descriptorBindingUpdateUnusedWhilePending: C.uint32_t,
    descriptorBindingPartiallyBound: C.uint32_t,
    descriptorBindingVariableDescriptorCount: C.uint32_t,
    runtimeDescriptorArray: C.uint32_t,
});


const VkPhysicalDeviceDescriptorIndexingFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceDescriptorIndexingFeaturesEXT", {

});


const VkPhysicalDeviceDescriptorIndexingProperties = new T.StructBuffer("VkPhysicalDeviceDescriptorIndexingProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxUpdateAfterBindDescriptorsInAllPools: C.uint32_t,
    shaderUniformBufferArrayNonUniformIndexingNative: C.uint32_t,
    shaderSampledImageArrayNonUniformIndexingNative: C.uint32_t,
    shaderStorageBufferArrayNonUniformIndexingNative: C.uint32_t,
    shaderStorageImageArrayNonUniformIndexingNative: C.uint32_t,
    shaderInputAttachmentArrayNonUniformIndexingNative: C.uint32_t,
    robustBufferAccessUpdateAfterBind: C.uint32_t,
    quadDivergentImplicitLod: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindSamplers: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindUniformBuffers: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindStorageBuffers: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindSampledImages: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindStorageImages: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindInputAttachments: C.uint32_t,
    maxPerStageUpdateAfterBindResources: C.uint32_t,
    maxDescriptorSetUpdateAfterBindSamplers: C.uint32_t,
    maxDescriptorSetUpdateAfterBindUniformBuffers: C.uint32_t,
    maxDescriptorSetUpdateAfterBindUniformBuffersDynamic: C.uint32_t,
    maxDescriptorSetUpdateAfterBindStorageBuffers: C.uint32_t,
    maxDescriptorSetUpdateAfterBindStorageBuffersDynamic: C.uint32_t,
    maxDescriptorSetUpdateAfterBindSampledImages: C.uint32_t,
    maxDescriptorSetUpdateAfterBindStorageImages: C.uint32_t,
    maxDescriptorSetUpdateAfterBindInputAttachments: C.uint32_t,
});


const VkPhysicalDeviceDescriptorIndexingPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceDescriptorIndexingPropertiesEXT", {

});


const VkDescriptorSetLayoutBindingFlagsCreateInfo = new T.StructBuffer("VkDescriptorSetLayoutBindingFlagsCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    bindingCount: C.uint32_t,
    pBindingFlags: C.uint64_t,
});


const VkDescriptorSetLayoutBindingFlagsCreateInfoEXT = new T.StructBuffer("VkDescriptorSetLayoutBindingFlagsCreateInfoEXT", {

});


const VkDescriptorSetVariableDescriptorCountAllocateInfo = new T.StructBuffer("VkDescriptorSetVariableDescriptorCountAllocateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    descriptorSetCount: C.uint32_t,
    pDescriptorCounts: C.uint64_t,
});


const VkDescriptorSetVariableDescriptorCountAllocateInfoEXT = new T.StructBuffer("VkDescriptorSetVariableDescriptorCountAllocateInfoEXT", {

});


const VkDescriptorSetVariableDescriptorCountLayoutSupport = new T.StructBuffer("VkDescriptorSetVariableDescriptorCountLayoutSupport", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxVariableDescriptorCount: C.uint32_t,
});


const VkDescriptorSetVariableDescriptorCountLayoutSupportEXT = new T.StructBuffer("VkDescriptorSetVariableDescriptorCountLayoutSupportEXT", {

});


const VkAttachmentDescription2 = new T.StructBuffer("VkAttachmentDescription2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    format: C.uint32_t,
    samples: C.uint32_t,
    loadOp: C.uint32_t,
    storeOp: C.uint32_t,
    stencilLoadOp: C.uint32_t,
    stencilStoreOp: C.uint32_t,
    initialLayout: C.uint32_t,
    finalLayout: C.uint32_t,
});


const VkAttachmentDescription2KHR = new T.StructBuffer("VkAttachmentDescription2KHR", {

});


const VkAttachmentReference2 = new T.StructBuffer("VkAttachmentReference2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    attachment: C.uint32_t,
    layout: C.uint32_t,
    aspectMask: C.uint32_t,
});


const VkAttachmentReference2KHR = new T.StructBuffer("VkAttachmentReference2KHR", {

});


const VkSubpassDescription2 = new T.StructBuffer("VkSubpassDescription2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    pipelineBindPoint: C.uint32_t,
    viewMask: C.uint32_t,
    inputAttachmentCount: C.uint32_t,
    pInputAttachments: C.uint64_t,
    colorAttachmentCount: C.uint32_t,
    pColorAttachments: C.uint64_t,
    pResolveAttachments: C.uint64_t,
    pDepthStencilAttachment: C.uint64_t,
    preserveAttachmentCount: C.uint32_t,
    pPreserveAttachments: C.uint64_t,
});


const VkSubpassDescription2KHR = new T.StructBuffer("VkSubpassDescription2KHR", {

});


const VkSubpassDependency2 = new T.StructBuffer("VkSubpassDependency2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcSubpass: C.uint32_t,
    dstSubpass: C.uint32_t,
    srcStageMask: C.uint32_t,
    dstStageMask: C.uint32_t,
    srcAccessMask: C.uint32_t,
    dstAccessMask: C.uint32_t,
    dependencyFlags: C.uint32_t,
    viewOffset: C.int32_t,
});


const VkSubpassDependency2KHR = new T.StructBuffer("VkSubpassDependency2KHR", {

});


const VkRenderPassCreateInfo2 = new T.StructBuffer("VkRenderPassCreateInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    attachmentCount: C.uint32_t,
    pAttachments: C.uint64_t,
    subpassCount: C.uint32_t,
    pSubpasses: C.uint64_t,
    dependencyCount: C.uint32_t,
    pDependencies: C.uint64_t,
    correlatedViewMaskCount: C.uint32_t,
    pCorrelatedViewMasks: C.uint64_t,
});


const VkRenderPassCreateInfo2KHR = new T.StructBuffer("VkRenderPassCreateInfo2KHR", {

});


const VkSubpassBeginInfo = new T.StructBuffer("VkSubpassBeginInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    contents: C.uint32_t,
});


const VkSubpassBeginInfoKHR = new T.StructBuffer("VkSubpassBeginInfoKHR", {

});


const VkSubpassEndInfo = new T.StructBuffer("VkSubpassEndInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
});


const VkSubpassEndInfoKHR = new T.StructBuffer("VkSubpassEndInfoKHR", {

});


const VkPhysicalDeviceTimelineSemaphoreFeatures = new T.StructBuffer("VkPhysicalDeviceTimelineSemaphoreFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    timelineSemaphore: C.uint32_t,
});


const VkPhysicalDeviceTimelineSemaphoreFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceTimelineSemaphoreFeaturesKHR", {

});


const VkPhysicalDeviceTimelineSemaphoreProperties = new T.StructBuffer("VkPhysicalDeviceTimelineSemaphoreProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxTimelineSemaphoreValueDifference: C.uint64_t,
});


const VkPhysicalDeviceTimelineSemaphorePropertiesKHR = new T.StructBuffer("VkPhysicalDeviceTimelineSemaphorePropertiesKHR", {

});


const VkSemaphoreTypeCreateInfo = new T.StructBuffer("VkSemaphoreTypeCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    semaphoreType: C.uint32_t,
    initialValue: C.uint64_t,
});


const VkSemaphoreTypeCreateInfoKHR = new T.StructBuffer("VkSemaphoreTypeCreateInfoKHR", {

});


const VkTimelineSemaphoreSubmitInfo = new T.StructBuffer("VkTimelineSemaphoreSubmitInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    waitSemaphoreValueCount: C.uint32_t,
    pWaitSemaphoreValues: C.uint64_t,
    signalSemaphoreValueCount: C.uint32_t,
    pSignalSemaphoreValues: C.uint64_t,
});


const VkTimelineSemaphoreSubmitInfoKHR = new T.StructBuffer("VkTimelineSemaphoreSubmitInfoKHR", {

});


const VkSemaphoreWaitInfo = new T.StructBuffer("VkSemaphoreWaitInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    semaphoreCount: C.uint32_t,
    pSemaphores: C.uint64_t,
    pValues: C.uint64_t,
});


const VkSemaphoreWaitInfoKHR = new T.StructBuffer("VkSemaphoreWaitInfoKHR", {

});


const VkSemaphoreSignalInfo = new T.StructBuffer("VkSemaphoreSignalInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    semaphore: C.uint32_t,
    value: C.uint64_t,
});


const VkSemaphoreSignalInfoKHR = new T.StructBuffer("VkSemaphoreSignalInfoKHR", {

});


const VkVertexInputBindingDivisorDescriptionEXT = new T.StructBuffer("VkVertexInputBindingDivisorDescriptionEXT", {
    binding: C.uint32_t,
    divisor: C.uint32_t,
});


const VkPipelineVertexInputDivisorStateCreateInfoEXT = new T.StructBuffer("VkPipelineVertexInputDivisorStateCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    vertexBindingDivisorCount: C.uint32_t,
    pVertexBindingDivisors: C.uint64_t,
});


const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxVertexAttribDivisor: C.uint32_t,
});


const VkPhysicalDevicePCIBusInfoPropertiesEXT = new T.StructBuffer("VkPhysicalDevicePCIBusInfoPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pciDomain: C.uint32_t,
    pciBus: C.uint32_t,
    pciDevice: C.uint32_t,
    pciFunction: C.uint32_t,
});


const VkImportAndroidHardwareBufferInfoANDROID = new T.StructBuffer("VkImportAndroidHardwareBufferInfoANDROID", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    buffer: C.uint64_t,
});


const VkAndroidHardwareBufferUsageANDROID = new T.StructBuffer("VkAndroidHardwareBufferUsageANDROID", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    androidHardwareBufferUsage: C.uint64_t,
});


const VkAndroidHardwareBufferPropertiesANDROID = new T.StructBuffer("VkAndroidHardwareBufferPropertiesANDROID", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    allocationSize: C.uint64_t,
    memoryTypeBits: C.uint32_t,
});


const VkMemoryGetAndroidHardwareBufferInfoANDROID = new T.StructBuffer("VkMemoryGetAndroidHardwareBufferInfoANDROID", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memory: C.uint64_t,
});


const VkAndroidHardwareBufferFormatPropertiesANDROID = new T.StructBuffer("VkAndroidHardwareBufferFormatPropertiesANDROID", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    format: C.uint32_t,
    externalFormat: C.uint64_t,
    formatFeatures: C.uint32_t,
    samplerYcbcrConversionComponents: C.uint32_t,
    suggestedYcbcrModel: C.uint32_t,
    suggestedYcbcrRange: C.uint32_t,
    suggestedXChromaOffset: C.uint32_t,
    suggestedYChromaOffset: C.uint32_t,
});


const VkCommandBufferInheritanceConditionalRenderingInfoEXT = new T.StructBuffer("VkCommandBufferInheritanceConditionalRenderingInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    conditionalRenderingEnable: C.uint32_t,
});


const VkExternalFormatANDROID = new T.StructBuffer("VkExternalFormatANDROID", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    externalFormat: C.uint64_t,
});


const VkPhysicalDevice8BitStorageFeatures = new T.StructBuffer("VkPhysicalDevice8BitStorageFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    storageBuffer8BitAccess: C.uint32_t,
    uniformAndStorageBuffer8BitAccess: C.uint32_t,
    storagePushConstant8: C.uint32_t,
});


const VkPhysicalDevice8BitStorageFeaturesKHR = new T.StructBuffer("VkPhysicalDevice8BitStorageFeaturesKHR", {

});


const VkPhysicalDeviceConditionalRenderingFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceConditionalRenderingFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    conditionalRendering: C.uint32_t,
    inheritedConditionalRendering: C.uint32_t,
});


const VkPhysicalDeviceVulkanMemoryModelFeatures = new T.StructBuffer("VkPhysicalDeviceVulkanMemoryModelFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    vulkanMemoryModel: C.uint32_t,
    vulkanMemoryModelDeviceScope: C.uint32_t,
    vulkanMemoryModelAvailabilityVisibilityChains: C.uint32_t,
});


const VkPhysicalDeviceVulkanMemoryModelFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceVulkanMemoryModelFeaturesKHR", {

});


const VkPhysicalDeviceShaderAtomicInt64Features = new T.StructBuffer("VkPhysicalDeviceShaderAtomicInt64Features", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderBufferInt64Atomics: C.uint32_t,
    shaderSharedInt64Atomics: C.uint32_t,
});


const VkPhysicalDeviceShaderAtomicInt64FeaturesKHR = new T.StructBuffer("VkPhysicalDeviceShaderAtomicInt64FeaturesKHR", {

});


const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderBufferFloat32Atomics: C.uint32_t,
    shaderBufferFloat32AtomicAdd: C.uint32_t,
    shaderBufferFloat64Atomics: C.uint32_t,
    shaderBufferFloat64AtomicAdd: C.uint32_t,
    shaderSharedFloat32Atomics: C.uint32_t,
    shaderSharedFloat32AtomicAdd: C.uint32_t,
    shaderSharedFloat64Atomics: C.uint32_t,
    shaderSharedFloat64AtomicAdd: C.uint32_t,
    shaderImageFloat32Atomics: C.uint32_t,
    shaderImageFloat32AtomicAdd: C.uint32_t,
    sparseImageFloat32Atomics: C.uint32_t,
    sparseImageFloat32AtomicAdd: C.uint32_t,
});


const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT = new T.StructBuffer("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderBufferFloat16Atomics: C.uint32_t,
    shaderBufferFloat16AtomicAdd: C.uint32_t,
    shaderBufferFloat16AtomicMinMax: C.uint32_t,
    shaderBufferFloat32AtomicMinMax: C.uint32_t,
    shaderBufferFloat64AtomicMinMax: C.uint32_t,
    shaderSharedFloat16Atomics: C.uint32_t,
    shaderSharedFloat16AtomicAdd: C.uint32_t,
    shaderSharedFloat16AtomicMinMax: C.uint32_t,
    shaderSharedFloat32AtomicMinMax: C.uint32_t,
    shaderSharedFloat64AtomicMinMax: C.uint32_t,
    shaderImageFloat32AtomicMinMax: C.uint32_t,
    sparseImageFloat32AtomicMinMax: C.uint32_t,
});


const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    vertexAttributeInstanceRateDivisor: C.uint32_t,
    vertexAttributeInstanceRateZeroDivisor: C.uint32_t,
});


const VkQueueFamilyCheckpointPropertiesNV = new T.StructBuffer("VkQueueFamilyCheckpointPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    checkpointExecutionStageMask: C.uint32_t,
});


const VkCheckpointDataNV = new T.StructBuffer("VkCheckpointDataNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stage: C.uint32_t,
    pCheckpointMarker: C.uint64_t,
});


const VkPhysicalDeviceDepthStencilResolveProperties = new T.StructBuffer("VkPhysicalDeviceDepthStencilResolveProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    supportedDepthResolveModes: C.uint32_t,
    supportedStencilResolveModes: C.uint32_t,
    independentResolveNone: C.uint32_t,
    independentResolve: C.uint32_t,
});


const VkPhysicalDeviceDepthStencilResolvePropertiesKHR = new T.StructBuffer("VkPhysicalDeviceDepthStencilResolvePropertiesKHR", {

});


const VkSubpassDescriptionDepthStencilResolve = new T.StructBuffer("VkSubpassDescriptionDepthStencilResolve", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    depthResolveMode: C.uint32_t,
    stencilResolveMode: C.uint32_t,
    pDepthStencilResolveAttachment: C.uint64_t,
});


const VkSubpassDescriptionDepthStencilResolveKHR = new T.StructBuffer("VkSubpassDescriptionDepthStencilResolveKHR", {

});


const VkImageViewASTCDecodeModeEXT = new T.StructBuffer("VkImageViewASTCDecodeModeEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    decodeMode: C.uint32_t,
});


const VkPhysicalDeviceASTCDecodeFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceASTCDecodeFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    decodeModeSharedExponent: C.uint32_t,
});


const VkPhysicalDeviceTransformFeedbackFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceTransformFeedbackFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    transformFeedback: C.uint32_t,
    geometryStreams: C.uint32_t,
});


const VkPhysicalDeviceTransformFeedbackPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceTransformFeedbackPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxTransformFeedbackStreams: C.uint32_t,
    maxTransformFeedbackBuffers: C.uint32_t,
    maxTransformFeedbackBufferSize: C.uint64_t,
    maxTransformFeedbackStreamDataSize: C.uint32_t,
    maxTransformFeedbackBufferDataSize: C.uint32_t,
    maxTransformFeedbackBufferDataStride: C.uint32_t,
    transformFeedbackQueries: C.uint32_t,
    transformFeedbackStreamsLinesTriangles: C.uint32_t,
    transformFeedbackRasterizationStreamSelect: C.uint32_t,
    transformFeedbackDraw: C.uint32_t,
});


const VkPipelineRasterizationStateStreamCreateInfoEXT = new T.StructBuffer("VkPipelineRasterizationStateStreamCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    rasterizationStream: C.uint32_t,
});


const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV = new T.StructBuffer("VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    representativeFragmentTest: C.uint32_t,
});


const VkPipelineRepresentativeFragmentTestStateCreateInfoNV = new T.StructBuffer("VkPipelineRepresentativeFragmentTestStateCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    representativeFragmentTestEnable: C.uint32_t,
});


const VkPhysicalDeviceExclusiveScissorFeaturesNV = new T.StructBuffer("VkPhysicalDeviceExclusiveScissorFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    exclusiveScissor: C.uint32_t,
});


const VkPipelineViewportExclusiveScissorStateCreateInfoNV = new T.StructBuffer("VkPipelineViewportExclusiveScissorStateCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    exclusiveScissorCount: C.uint32_t,
    pExclusiveScissors: C.uint64_t,
});


const VkPhysicalDeviceCornerSampledImageFeaturesNV = new T.StructBuffer("VkPhysicalDeviceCornerSampledImageFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    cornerSampledImage: C.uint32_t,
});


const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV = new T.StructBuffer("VkPhysicalDeviceComputeShaderDerivativesFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    computeDerivativeGroupQuads: C.uint32_t,
    computeDerivativeGroupLinear: C.uint32_t,
});


const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV = new T.StructBuffer("VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV", {

});


const VkPhysicalDeviceShaderImageFootprintFeaturesNV = new T.StructBuffer("VkPhysicalDeviceShaderImageFootprintFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageFootprint: C.uint32_t,
});


const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV = new T.StructBuffer("VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    dedicatedAllocationImageAliasing: C.uint32_t,
});


const VkPhysicalDeviceCopyMemoryIndirectFeaturesNV = new T.StructBuffer("VkPhysicalDeviceCopyMemoryIndirectFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    indirectCopy: C.uint32_t,
});


const VkPhysicalDeviceCopyMemoryIndirectPropertiesNV = new T.StructBuffer("VkPhysicalDeviceCopyMemoryIndirectPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    supportedQueues: C.uint32_t,
});


const VkPhysicalDeviceMemoryDecompressionFeaturesNV = new T.StructBuffer("VkPhysicalDeviceMemoryDecompressionFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memoryDecompression: C.uint32_t,
});


const VkPhysicalDeviceMemoryDecompressionPropertiesNV = new T.StructBuffer("VkPhysicalDeviceMemoryDecompressionPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    decompressionMethods: C.uint32_t,
    maxDecompressionIndirectCount: C.uint64_t,
});


const VkShadingRatePaletteNV = new T.StructBuffer("VkShadingRatePaletteNV", {
    shadingRatePaletteEntryCount: C.uint32_t,
    pShadingRatePaletteEntries: C.uint64_t,
});


const VkPipelineViewportShadingRateImageStateCreateInfoNV = new T.StructBuffer("VkPipelineViewportShadingRateImageStateCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shadingRateImageEnable: C.uint32_t,
    viewportCount: C.uint32_t,
    pShadingRatePalettes: C.uint64_t,
});


const VkPhysicalDeviceShadingRateImageFeaturesNV = new T.StructBuffer("VkPhysicalDeviceShadingRateImageFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shadingRateImage: C.uint32_t,
    shadingRateCoarseSampleOrder: C.uint32_t,
});


const VkPhysicalDeviceShadingRateImagePropertiesNV = new T.StructBuffer("VkPhysicalDeviceShadingRateImagePropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shadingRateTexelSize: VkExtent2D,
    shadingRatePaletteSize: C.uint32_t,
    shadingRateMaxCoarseSamples: C.uint32_t,
});


const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI = new T.StructBuffer("VkPhysicalDeviceInvocationMaskFeaturesHUAWEI", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    invocationMask: C.uint32_t,
});


const VkCoarseSampleLocationNV = new T.StructBuffer("VkCoarseSampleLocationNV", {
    pixelX: C.uint32_t,
    pixelY: C.uint32_t,
    sample: C.uint32_t,
});


const VkCoarseSampleOrderCustomNV = new T.StructBuffer("VkCoarseSampleOrderCustomNV", {
    shadingRate: C.uint32_t,
    sampleCount: C.uint32_t,
    sampleLocationCount: C.uint32_t,
    pSampleLocations: C.uint64_t,
});


const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV = new T.StructBuffer("VkPipelineViewportCoarseSampleOrderStateCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    sampleOrderType: C.uint32_t,
    customSampleOrderCount: C.uint32_t,
    pCustomSampleOrders: C.uint64_t,
});


const VkPhysicalDeviceMeshShaderFeaturesNV = new T.StructBuffer("VkPhysicalDeviceMeshShaderFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    taskShader: C.uint32_t,
    meshShader: C.uint32_t,
});


const VkPhysicalDeviceMeshShaderPropertiesNV = new T.StructBuffer("VkPhysicalDeviceMeshShaderPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxDrawMeshTasksCount: C.uint32_t,
    maxTaskWorkGroupInvocations: C.uint32_t,
    maxTaskWorkGroupSize: C.uint32_t[3],
    maxTaskTotalMemorySize: C.uint32_t,
    maxTaskOutputCount: C.uint32_t,
    maxMeshWorkGroupInvocations: C.uint32_t,
    maxMeshWorkGroupSize: C.uint32_t[3],
    maxMeshTotalMemorySize: C.uint32_t,
    maxMeshOutputVertices: C.uint32_t,
    maxMeshOutputPrimitives: C.uint32_t,
    maxMeshMultiviewViewCount: C.uint32_t,
    meshOutputPerVertexGranularity: C.uint32_t,
    meshOutputPerPrimitiveGranularity: C.uint32_t,
});


const VkDrawMeshTasksIndirectCommandNV = new T.StructBuffer("VkDrawMeshTasksIndirectCommandNV", {
    taskCount: C.uint32_t,
    firstTask: C.uint32_t,
});


const VkPhysicalDeviceMeshShaderFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceMeshShaderFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    taskShader: C.uint32_t,
    meshShader: C.uint32_t,
    multiviewMeshShader: C.uint32_t,
    primitiveFragmentShadingRateMeshShader: C.uint32_t,
    meshShaderQueries: C.uint32_t,
});


const VkPhysicalDeviceMeshShaderPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceMeshShaderPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxTaskWorkGroupTotalCount: C.uint32_t,
    maxTaskWorkGroupCount: C.uint32_t[3],
    maxTaskWorkGroupInvocations: C.uint32_t,
    maxTaskWorkGroupSize: C.uint32_t[3],
    maxTaskPayloadSize: C.uint32_t,
    maxTaskSharedMemorySize: C.uint32_t,
    maxTaskPayloadAndSharedMemorySize: C.uint32_t,
    maxMeshWorkGroupTotalCount: C.uint32_t,
    maxMeshWorkGroupCount: C.uint32_t[3],
    maxMeshWorkGroupInvocations: C.uint32_t,
    maxMeshWorkGroupSize: C.uint32_t[3],
    maxMeshSharedMemorySize: C.uint32_t,
    maxMeshPayloadAndSharedMemorySize: C.uint32_t,
    maxMeshOutputMemorySize: C.uint32_t,
    maxMeshPayloadAndOutputMemorySize: C.uint32_t,
    maxMeshOutputComponents: C.uint32_t,
    maxMeshOutputVertices: C.uint32_t,
    maxMeshOutputPrimitives: C.uint32_t,
    maxMeshOutputLayers: C.uint32_t,
    maxMeshMultiviewViewCount: C.uint32_t,
    meshOutputPerVertexGranularity: C.uint32_t,
    meshOutputPerPrimitiveGranularity: C.uint32_t,
    maxPreferredTaskWorkGroupInvocations: C.uint32_t,
    maxPreferredMeshWorkGroupInvocations: C.uint32_t,
    prefersLocalInvocationVertexOutput: C.uint32_t,
    prefersLocalInvocationPrimitiveOutput: C.uint32_t,
    prefersCompactVertexOutput: C.uint32_t,
    prefersCompactPrimitiveOutput: C.uint32_t,
});


const VkDrawMeshTasksIndirectCommandEXT = new T.StructBuffer("VkDrawMeshTasksIndirectCommandEXT", {
    groupCountX: C.uint32_t,
    groupCountY: C.uint32_t,
    groupCountZ: C.uint32_t,
});


const VkRayTracingShaderGroupCreateInfoNV = new T.StructBuffer("VkRayTracingShaderGroupCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    type: C.uint32_t,
    generalShader: C.uint32_t,
    closestHitShader: C.uint32_t,
    anyHitShader: C.uint32_t,
    intersectionShader: C.uint32_t,
});


const VkRayTracingShaderGroupCreateInfoKHR = new T.StructBuffer("VkRayTracingShaderGroupCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    type: C.uint32_t,
    generalShader: C.uint32_t,
    closestHitShader: C.uint32_t,
    anyHitShader: C.uint32_t,
    intersectionShader: C.uint32_t,
    pShaderGroupCaptureReplayHandle: C.uint64_t,
});


const VkRayTracingPipelineCreateInfoNV = new T.StructBuffer("VkRayTracingPipelineCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    stageCount: C.uint32_t,
    pStages: C.uint64_t,
    groupCount: C.uint32_t,
    pGroups: C.uint64_t,
    maxRecursionDepth: C.uint32_t,
    layout: C.uint32_t,
    basePipelineHandle: C.uint32_t,
    basePipelineIndex: C.int32_t,
});


const VkRayTracingPipelineCreateInfoKHR = new T.StructBuffer("VkRayTracingPipelineCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    stageCount: C.uint32_t,
    pStages: C.uint64_t,
    groupCount: C.uint32_t,
    pGroups: C.uint64_t,
    maxPipelineRayRecursionDepth: C.uint32_t,
    pLibraryInfo: C.uint64_t,
    pLibraryInterface: C.uint64_t,
    pDynamicState: C.uint64_t,
    layout: C.uint32_t,
    basePipelineHandle: C.uint32_t,
    basePipelineIndex: C.int32_t,
});


const VkGeometryTrianglesNV = new T.StructBuffer("VkGeometryTrianglesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    vertexData: C.uint64_t,
    vertexOffset: C.uint64_t,
    vertexCount: C.uint32_t,
    vertexStride: C.uint64_t,
    vertexFormat: C.uint32_t,
    indexData: C.uint64_t,
    indexOffset: C.uint64_t,
    indexCount: C.uint32_t,
    indexType: C.uint32_t,
    transformData: C.uint64_t,
    transformOffset: C.uint64_t,
});


const VkGeometryAABBNV = new T.StructBuffer("VkGeometryAABBNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    aabbData: C.uint64_t,
    numAABBs: C.uint32_t,
    stride: C.uint32_t,
    offset: C.uint64_t,
});


const VkGeometryDataNV = new T.StructBuffer("VkGeometryDataNV", {
    triangles: C.uint32_t,
    aabbs: C.uint32_t,
});


const VkGeometryNV = new T.StructBuffer("VkGeometryNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    geometryType: C.uint32_t,
    geometry: C.uint32_t,
    flags: C.uint32_t,
});


const VkAccelerationStructureInfoNV = new T.StructBuffer("VkAccelerationStructureInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    type: C.uint32_t,
    flags: C.uint32_t,
    instanceCount: C.uint32_t,
    geometryCount: C.uint32_t,
    pGeometries: C.uint64_t,
});


const VkAccelerationStructureCreateInfoNV = new T.StructBuffer("VkAccelerationStructureCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    compactedSize: C.uint64_t,
    info: C.uint32_t,
});


const VkBindAccelerationStructureMemoryInfoNV = new T.StructBuffer("VkBindAccelerationStructureMemoryInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    accelerationStructure: C.uint32_t,
    memory: C.uint64_t,
    memoryOffset: C.uint64_t,
    deviceIndexCount: C.uint32_t,
    pDeviceIndices: C.uint64_t,
});


const VkWriteDescriptorSetAccelerationStructureKHR = new T.StructBuffer("VkWriteDescriptorSetAccelerationStructureKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    accelerationStructureCount: C.uint32_t,
    pAccelerationStructures: C.uint64_t,
});


const VkWriteDescriptorSetAccelerationStructureNV = new T.StructBuffer("VkWriteDescriptorSetAccelerationStructureNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    accelerationStructureCount: C.uint32_t,
    pAccelerationStructures: C.uint64_t,
});


const VkAccelerationStructureMemoryRequirementsInfoNV = new T.StructBuffer("VkAccelerationStructureMemoryRequirementsInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    type: C.uint32_t,
    accelerationStructure: C.uint32_t,
});


const VkPhysicalDeviceAccelerationStructureFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceAccelerationStructureFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    accelerationStructure: C.uint32_t,
    accelerationStructureCaptureReplay: C.uint32_t,
    accelerationStructureIndirectBuild: C.uint32_t,
    accelerationStructureHostCommands: C.uint32_t,
    descriptorBindingAccelerationStructureUpdateAfterBind: C.uint32_t,
});


const VkPhysicalDeviceRayTracingPipelineFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceRayTracingPipelineFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    rayTracingPipeline: C.uint32_t,
    rayTracingPipelineShaderGroupHandleCaptureReplay: C.uint32_t,
    rayTracingPipelineShaderGroupHandleCaptureReplayMixed: C.uint32_t,
    rayTracingPipelineTraceRaysIndirect: C.uint32_t,
    rayTraversalPrimitiveCulling: C.uint32_t,
});


const VkPhysicalDeviceRayQueryFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceRayQueryFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    rayQuery: C.uint32_t,
});


const VkPhysicalDeviceAccelerationStructurePropertiesKHR = new T.StructBuffer("VkPhysicalDeviceAccelerationStructurePropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxGeometryCount: C.uint64_t,
    maxInstanceCount: C.uint64_t,
    maxPrimitiveCount: C.uint64_t,
    maxPerStageDescriptorAccelerationStructures: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindAccelerationStructures: C.uint32_t,
    maxDescriptorSetAccelerationStructures: C.uint32_t,
    maxDescriptorSetUpdateAfterBindAccelerationStructures: C.uint32_t,
    minAccelerationStructureScratchOffsetAlignment: C.uint32_t,
});


const VkPhysicalDeviceRayTracingPipelinePropertiesKHR = new T.StructBuffer("VkPhysicalDeviceRayTracingPipelinePropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderGroupHandleSize: C.uint32_t,
    maxRayRecursionDepth: C.uint32_t,
    maxShaderGroupStride: C.uint32_t,
    shaderGroupBaseAlignment: C.uint32_t,
    shaderGroupHandleCaptureReplaySize: C.uint32_t,
    maxRayDispatchInvocationCount: C.uint32_t,
    shaderGroupHandleAlignment: C.uint32_t,
    maxRayHitAttributeSize: C.uint32_t,
});


const VkPhysicalDeviceRayTracingPropertiesNV = new T.StructBuffer("VkPhysicalDeviceRayTracingPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderGroupHandleSize: C.uint32_t,
    maxRecursionDepth: C.uint32_t,
    maxShaderGroupStride: C.uint32_t,
    shaderGroupBaseAlignment: C.uint32_t,
    maxGeometryCount: C.uint64_t,
    maxInstanceCount: C.uint64_t,
    maxTriangleCount: C.uint64_t,
    maxDescriptorSetAccelerationStructures: C.uint32_t,
});


const VkStridedDeviceAddressRegionKHR = new T.StructBuffer("VkStridedDeviceAddressRegionKHR", {
    deviceAddress: C.uint64_t,
    stride: C.uint64_t,
    size: C.uint64_t,
});


const VkTraceRaysIndirectCommandKHR = new T.StructBuffer("VkTraceRaysIndirectCommandKHR", {
    width: C.uint32_t,
    height: C.uint32_t,
    depth: C.uint32_t,
});


const VkTraceRaysIndirectCommand2KHR = new T.StructBuffer("VkTraceRaysIndirectCommand2KHR", {
    raygenShaderRecordAddress: C.uint64_t,
    raygenShaderRecordSize: C.uint64_t,
    missShaderBindingTableAddress: C.uint64_t,
    missShaderBindingTableSize: C.uint64_t,
    missShaderBindingTableStride: C.uint64_t,
    hitShaderBindingTableAddress: C.uint64_t,
    hitShaderBindingTableSize: C.uint64_t,
    hitShaderBindingTableStride: C.uint64_t,
    callableShaderBindingTableAddress: C.uint64_t,
    callableShaderBindingTableSize: C.uint64_t,
    callableShaderBindingTableStride: C.uint64_t,
    width: C.uint32_t,
    height: C.uint32_t,
    depth: C.uint32_t,
});


const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR = new T.StructBuffer("VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    rayTracingMaintenance1: C.uint32_t,
    rayTracingPipelineTraceRaysIndirect2: C.uint32_t,
});


const VkDrmFormatModifierPropertiesListEXT = new T.StructBuffer("VkDrmFormatModifierPropertiesListEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    drmFormatModifierCount: C.uint32_t,
    pDrmFormatModifierProperties: C.uint64_t,
});


const VkDrmFormatModifierPropertiesEXT = new T.StructBuffer("VkDrmFormatModifierPropertiesEXT", {
    drmFormatModifier: C.uint64_t,
    drmFormatModifierPlaneCount: C.uint32_t,
    drmFormatModifierTilingFeatures: C.uint32_t,
});


const VkPhysicalDeviceImageDrmFormatModifierInfoEXT = new T.StructBuffer("VkPhysicalDeviceImageDrmFormatModifierInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    drmFormatModifier: C.uint64_t,
    sharingMode: C.uint32_t,
    queueFamilyIndexCount: C.uint32_t,
    pQueueFamilyIndices: C.uint64_t,
});


const VkImageDrmFormatModifierListCreateInfoEXT = new T.StructBuffer("VkImageDrmFormatModifierListCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    drmFormatModifierCount: C.uint32_t,
    pDrmFormatModifiers: C.uint64_t,
});


const VkImageDrmFormatModifierExplicitCreateInfoEXT = new T.StructBuffer("VkImageDrmFormatModifierExplicitCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    drmFormatModifier: C.uint64_t,
    drmFormatModifierPlaneCount: C.uint32_t,
    pPlaneLayouts: C.uint64_t,
});


const VkImageDrmFormatModifierPropertiesEXT = new T.StructBuffer("VkImageDrmFormatModifierPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    drmFormatModifier: C.uint64_t,
});


const VkImageStencilUsageCreateInfo = new T.StructBuffer("VkImageStencilUsageCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stencilUsage: C.uint32_t,
});


const VkImageStencilUsageCreateInfoEXT = new T.StructBuffer("VkImageStencilUsageCreateInfoEXT", {

});


const VkDeviceMemoryOverallocationCreateInfoAMD = new T.StructBuffer("VkDeviceMemoryOverallocationCreateInfoAMD", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    overallocationBehavior: C.uint32_t,
});


const VkPhysicalDeviceFragmentDensityMapFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceFragmentDensityMapFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fragmentDensityMap: C.uint32_t,
    fragmentDensityMapDynamic: C.uint32_t,
    fragmentDensityMapNonSubsampledImages: C.uint32_t,
});


const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT = new T.StructBuffer("VkPhysicalDeviceFragmentDensityMap2FeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fragmentDensityMapDeferred: C.uint32_t,
});


const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM = new T.StructBuffer("VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fragmentDensityMapOffset: C.uint32_t,
});


const VkPhysicalDeviceFragmentDensityMapPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceFragmentDensityMapPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    minFragmentDensityTexelSize: VkExtent2D,
    maxFragmentDensityTexelSize: VkExtent2D,
    fragmentDensityInvocations: C.uint32_t,
});


const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT = new T.StructBuffer("VkPhysicalDeviceFragmentDensityMap2PropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    subsampledLoads: C.uint32_t,
    subsampledCoarseReconstructionEarlyAccess: C.uint32_t,
    maxSubsampledArrayLayers: C.uint32_t,
    maxDescriptorSetSubsampledSamplers: C.uint32_t,
});


const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM = new T.StructBuffer("VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fragmentDensityOffsetGranularity: VkExtent2D,
});


const VkRenderPassFragmentDensityMapCreateInfoEXT = new T.StructBuffer("VkRenderPassFragmentDensityMapCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fragmentDensityMapAttachment: C.uint32_t,
});


const VkSubpassFragmentDensityMapOffsetEndInfoQCOM = new T.StructBuffer("VkSubpassFragmentDensityMapOffsetEndInfoQCOM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fragmentDensityOffsetCount: C.uint32_t,
    pFragmentDensityOffsets: C.uint64_t,
});


const VkPhysicalDeviceScalarBlockLayoutFeatures = new T.StructBuffer("VkPhysicalDeviceScalarBlockLayoutFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    scalarBlockLayout: C.uint32_t,
});


const VkPhysicalDeviceScalarBlockLayoutFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceScalarBlockLayoutFeaturesEXT", {

});


const VkSurfaceProtectedCapabilitiesKHR = new T.StructBuffer("VkSurfaceProtectedCapabilitiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    supportsProtected: C.uint32_t,
});


const VkPhysicalDeviceUniformBufferStandardLayoutFeatures = new T.StructBuffer("VkPhysicalDeviceUniformBufferStandardLayoutFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    uniformBufferStandardLayout: C.uint32_t,
});


const VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR", {

});


const VkPhysicalDeviceDepthClipEnableFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceDepthClipEnableFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    depthClipEnable: C.uint32_t,
});


const VkPipelineRasterizationDepthClipStateCreateInfoEXT = new T.StructBuffer("VkPipelineRasterizationDepthClipStateCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    depthClipEnable: C.uint32_t,
});


const VkPhysicalDeviceMemoryBudgetPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceMemoryBudgetPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    heapBudget: C.uint64_t[enums.VK_MAX_MEMORY_HEAPS],
    heapUsage: C.uint64_t[enums.VK_MAX_MEMORY_HEAPS],
});


const VkPhysicalDeviceMemoryPriorityFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceMemoryPriorityFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memoryPriority: C.uint32_t,
});


const VkMemoryPriorityAllocateInfoEXT = new T.StructBuffer("VkMemoryPriorityAllocateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    priority: C.float,
});


const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT = new T.StructBuffer("VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pageableDeviceLocalMemory: C.uint32_t,
});


const VkPhysicalDeviceBufferDeviceAddressFeatures = new T.StructBuffer("VkPhysicalDeviceBufferDeviceAddressFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    bufferDeviceAddress: C.uint32_t,
    bufferDeviceAddressCaptureReplay: C.uint32_t,
    bufferDeviceAddressMultiDevice: C.uint32_t,
});


const VkPhysicalDeviceBufferDeviceAddressFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceBufferDeviceAddressFeaturesKHR", {

});


const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceBufferDeviceAddressFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    bufferDeviceAddress: C.uint32_t,
    bufferDeviceAddressCaptureReplay: C.uint32_t,
    bufferDeviceAddressMultiDevice: C.uint32_t,
});


const VkPhysicalDeviceBufferAddressFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceBufferAddressFeaturesEXT", {

});


const VkBufferDeviceAddressInfo = new T.StructBuffer("VkBufferDeviceAddressInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    buffer: C.uint64_t,
});


const VkBufferDeviceAddressInfoKHR = new T.StructBuffer("VkBufferDeviceAddressInfoKHR", {

});


const VkBufferDeviceAddressInfoEXT = new T.StructBuffer("VkBufferDeviceAddressInfoEXT", {

});


const VkBufferOpaqueCaptureAddressCreateInfo = new T.StructBuffer("VkBufferOpaqueCaptureAddressCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    opaqueCaptureAddress: C.uint64_t,
});


const VkBufferOpaqueCaptureAddressCreateInfoKHR = new T.StructBuffer("VkBufferOpaqueCaptureAddressCreateInfoKHR", {

});


const VkBufferDeviceAddressCreateInfoEXT = new T.StructBuffer("VkBufferDeviceAddressCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceAddress: C.uint64_t,
});


const VkPhysicalDeviceImageViewImageFormatInfoEXT = new T.StructBuffer("VkPhysicalDeviceImageViewImageFormatInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageViewType: C.uint32_t,
});


const VkFilterCubicImageViewImageFormatPropertiesEXT = new T.StructBuffer("VkFilterCubicImageViewImageFormatPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    filterCubic: C.uint32_t,
    filterCubicMinmax: C.uint32_t,
});


const VkPhysicalDeviceImagelessFramebufferFeatures = new T.StructBuffer("VkPhysicalDeviceImagelessFramebufferFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imagelessFramebuffer: C.uint32_t,
});


const VkPhysicalDeviceImagelessFramebufferFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceImagelessFramebufferFeaturesKHR", {

});


const VkFramebufferAttachmentsCreateInfo = new T.StructBuffer("VkFramebufferAttachmentsCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    attachmentImageInfoCount: C.uint32_t,
    pAttachmentImageInfos: C.uint64_t,
});


const VkFramebufferAttachmentsCreateInfoKHR = new T.StructBuffer("VkFramebufferAttachmentsCreateInfoKHR", {

});


const VkFramebufferAttachmentImageInfo = new T.StructBuffer("VkFramebufferAttachmentImageInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    usage: C.uint32_t,
    width: C.uint32_t,
    height: C.uint32_t,
    layerCount: C.uint32_t,
    viewFormatCount: C.uint32_t,
    pViewFormats: C.uint64_t,
});


const VkFramebufferAttachmentImageInfoKHR = new T.StructBuffer("VkFramebufferAttachmentImageInfoKHR", {

});


const VkRenderPassAttachmentBeginInfo = new T.StructBuffer("VkRenderPassAttachmentBeginInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    attachmentCount: C.uint32_t,
    pAttachments: C.uint64_t,
});


const VkRenderPassAttachmentBeginInfoKHR = new T.StructBuffer("VkRenderPassAttachmentBeginInfoKHR", {

});


const VkPhysicalDeviceTextureCompressionASTCHDRFeatures = new T.StructBuffer("VkPhysicalDeviceTextureCompressionASTCHDRFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    textureCompressionASTC_HDR: C.uint32_t,
});


const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT", {

});


const VkPhysicalDeviceCooperativeMatrixFeaturesNV = new T.StructBuffer("VkPhysicalDeviceCooperativeMatrixFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    cooperativeMatrix: C.uint32_t,
    cooperativeMatrixRobustBufferAccess: C.uint32_t,
});


const VkPhysicalDeviceCooperativeMatrixPropertiesNV = new T.StructBuffer("VkPhysicalDeviceCooperativeMatrixPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    cooperativeMatrixSupportedStages: C.uint32_t,
});


const VkCooperativeMatrixPropertiesNV = new T.StructBuffer("VkCooperativeMatrixPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    MSize: C.uint32_t,
    NSize: C.uint32_t,
    KSize: C.uint32_t,
    AType: C.uint32_t,
    BType: C.uint32_t,
    CType: C.uint32_t,
    DType: C.uint32_t,
    scope: C.uint32_t,
});


const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceYcbcrImageArraysFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    ycbcrImageArrays: C.uint32_t,
});


const VkImageViewHandleInfoNVX = new T.StructBuffer("VkImageViewHandleInfoNVX", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageView: C.uint32_t,
    descriptorType: C.uint32_t,
    sampler: C.uint32_t,
});


const VkImageViewAddressPropertiesNVX = new T.StructBuffer("VkImageViewAddressPropertiesNVX", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceAddress: C.uint64_t,
    size: C.uint64_t,
});


const VkPresentFrameTokenGGP = new T.StructBuffer("VkPresentFrameTokenGGP", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    frameToken: C.uint32_t,
});


const VkPipelineCreationFeedback = new T.StructBuffer("VkPipelineCreationFeedback", {
    flags: C.uint32_t,
    duration: C.uint64_t,
});


const VkPipelineCreationFeedbackEXT = new T.StructBuffer("VkPipelineCreationFeedbackEXT", {

});


const VkPipelineCreationFeedbackCreateInfo = new T.StructBuffer("VkPipelineCreationFeedbackCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pPipelineCreationFeedback: C.uint64_t,
    pipelineStageCreationFeedbackCount: C.uint32_t,
    pPipelineStageCreationFeedbacks: C.uint64_t,
});


const VkPipelineCreationFeedbackCreateInfoEXT = new T.StructBuffer("VkPipelineCreationFeedbackCreateInfoEXT", {

});


const VkSurfaceFullScreenExclusiveInfoEXT = new T.StructBuffer("VkSurfaceFullScreenExclusiveInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fullScreenExclusive: C.uint32_t,
});


const VkSurfaceFullScreenExclusiveWin32InfoEXT = new T.StructBuffer("VkSurfaceFullScreenExclusiveWin32InfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    hmonitor: C.uint32_t,
});


const VkSurfaceCapabilitiesFullScreenExclusiveEXT = new T.StructBuffer("VkSurfaceCapabilitiesFullScreenExclusiveEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fullScreenExclusiveSupported: C.uint32_t,
});


const VkPhysicalDevicePresentBarrierFeaturesNV = new T.StructBuffer("VkPhysicalDevicePresentBarrierFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    presentBarrier: C.uint32_t,
});


const VkSurfaceCapabilitiesPresentBarrierNV = new T.StructBuffer("VkSurfaceCapabilitiesPresentBarrierNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    presentBarrierSupported: C.uint32_t,
});


const VkSwapchainPresentBarrierCreateInfoNV = new T.StructBuffer("VkSwapchainPresentBarrierCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    presentBarrierEnable: C.uint32_t,
});


const VkPhysicalDevicePerformanceQueryFeaturesKHR = new T.StructBuffer("VkPhysicalDevicePerformanceQueryFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    performanceCounterQueryPools: C.uint32_t,
    performanceCounterMultipleQueryPools: C.uint32_t,
});


const VkPhysicalDevicePerformanceQueryPropertiesKHR = new T.StructBuffer("VkPhysicalDevicePerformanceQueryPropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    allowCommandBufferQueryCopies: C.uint32_t,
});


const VkPerformanceCounterKHR = new T.StructBuffer("VkPerformanceCounterKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    unit: C.uint32_t,
    scope: C.uint32_t,
    storage: C.uint32_t,
    uuid: C.uint8_t[enums.VK_UUID_SIZE],
});


const VkPerformanceCounterDescriptionKHR = new T.StructBuffer("VkPerformanceCounterDescriptionKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    name: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
    category: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
    description: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
});


const VkQueryPoolPerformanceCreateInfoKHR = new T.StructBuffer("VkQueryPoolPerformanceCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    queueFamilyIndex: C.uint32_t,
    counterIndexCount: C.uint32_t,
    pCounterIndices: C.uint64_t,
});


const VkAcquireProfilingLockInfoKHR = new T.StructBuffer("VkAcquireProfilingLockInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    timeout: C.uint64_t,
});


const VkPerformanceQuerySubmitInfoKHR = new T.StructBuffer("VkPerformanceQuerySubmitInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    counterPassIndex: C.uint32_t,
});


const VkHeadlessSurfaceCreateInfoEXT = new T.StructBuffer("VkHeadlessSurfaceCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
});


const VkPhysicalDeviceCoverageReductionModeFeaturesNV = new T.StructBuffer("VkPhysicalDeviceCoverageReductionModeFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    coverageReductionMode: C.uint32_t,
});


const VkPipelineCoverageReductionStateCreateInfoNV = new T.StructBuffer("VkPipelineCoverageReductionStateCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    coverageReductionMode: C.uint32_t,
});


const VkFramebufferMixedSamplesCombinationNV = new T.StructBuffer("VkFramebufferMixedSamplesCombinationNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    coverageReductionMode: C.uint32_t,
    rasterizationSamples: C.uint32_t,
    depthStencilSamples: C.uint32_t,
    colorSamples: C.uint32_t,
});


const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL = new T.StructBuffer("VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderIntegerFunctions2: C.uint32_t,
});


const VkPerformanceValueINTEL = new T.StructBuffer("VkPerformanceValueINTEL", {
    type: C.uint32_t,
    data: C.uint32_t,
});


const VkInitializePerformanceApiInfoINTEL = new T.StructBuffer("VkInitializePerformanceApiInfoINTEL", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pUserData: C.uint64_t,
});


const VkQueryPoolPerformanceQueryCreateInfoINTEL = new T.StructBuffer("VkQueryPoolPerformanceQueryCreateInfoINTEL", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    performanceCountersSampling: C.uint32_t,
});


const VkQueryPoolCreateInfoINTEL = new T.StructBuffer("VkQueryPoolCreateInfoINTEL", {

});


const VkPerformanceMarkerInfoINTEL = new T.StructBuffer("VkPerformanceMarkerInfoINTEL", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    marker: C.uint64_t,
});


const VkPerformanceStreamMarkerInfoINTEL = new T.StructBuffer("VkPerformanceStreamMarkerInfoINTEL", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    marker: C.uint32_t,
});


const VkPerformanceOverrideInfoINTEL = new T.StructBuffer("VkPerformanceOverrideInfoINTEL", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    type: C.uint32_t,
    enable: C.uint32_t,
    parameter: C.uint64_t,
});


const VkPerformanceConfigurationAcquireInfoINTEL = new T.StructBuffer("VkPerformanceConfigurationAcquireInfoINTEL", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    type: C.uint32_t,
});


const VkPhysicalDeviceShaderClockFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceShaderClockFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderSubgroupClock: C.uint32_t,
    shaderDeviceClock: C.uint32_t,
});


const VkPhysicalDeviceIndexTypeUint8FeaturesEXT = new T.StructBuffer("VkPhysicalDeviceIndexTypeUint8FeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    indexTypeUint8: C.uint32_t,
});


const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV = new T.StructBuffer("VkPhysicalDeviceShaderSMBuiltinsPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderSMCount: C.uint32_t,
    shaderWarpsPerSM: C.uint32_t,
});


const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV = new T.StructBuffer("VkPhysicalDeviceShaderSMBuiltinsFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderSMBuiltins: C.uint32_t,
});


const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fragmentShaderSampleInterlock: C.uint32_t,
    fragmentShaderPixelInterlock: C.uint32_t,
    fragmentShaderShadingRateInterlock: C.uint32_t,
});


const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures = new T.StructBuffer("VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    separateDepthStencilLayouts: C.uint32_t,
});


const VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR", {

});


const VkAttachmentReferenceStencilLayout = new T.StructBuffer("VkAttachmentReferenceStencilLayout", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stencilLayout: C.uint32_t,
});


const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT = new T.StructBuffer("VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    primitiveTopologyListRestart: C.uint32_t,
    primitiveTopologyPatchListRestart: C.uint32_t,
});


const VkAttachmentReferenceStencilLayoutKHR = new T.StructBuffer("VkAttachmentReferenceStencilLayoutKHR", {

});


const VkAttachmentDescriptionStencilLayout = new T.StructBuffer("VkAttachmentDescriptionStencilLayout", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stencilInitialLayout: C.uint32_t,
    stencilFinalLayout: C.uint32_t,
});


const VkAttachmentDescriptionStencilLayoutKHR = new T.StructBuffer("VkAttachmentDescriptionStencilLayoutKHR", {

});


const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR = new T.StructBuffer("VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pipelineExecutableInfo: C.uint32_t,
});


const VkPipelineInfoKHR = new T.StructBuffer("VkPipelineInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pipeline: C.uint32_t,
});


const VkPipelineInfoEXT = new T.StructBuffer("VkPipelineInfoEXT", {

});


const VkPipelineExecutablePropertiesKHR = new T.StructBuffer("VkPipelineExecutablePropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stages: C.uint32_t,
    name: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
    description: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
    subgroupSize: C.uint32_t,
});


const VkPipelineExecutableInfoKHR = new T.StructBuffer("VkPipelineExecutableInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pipeline: C.uint32_t,
    executableIndex: C.uint32_t,
});


const VkPipelineExecutableStatisticKHR = new T.StructBuffer("VkPipelineExecutableStatisticKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    name: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
    description: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
    format: C.uint32_t,
    value: C.uint32_t,
});


const VkPipelineExecutableInternalRepresentationKHR = new T.StructBuffer("VkPipelineExecutableInternalRepresentationKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    name: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
    description: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
    isText: C.uint32_t,
    dataSize: C.uint64_t,
    pData: C.uint64_t,
});


const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures = new T.StructBuffer("VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderDemoteToHelperInvocation: C.uint32_t,
});


const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT", {

});


const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    texelBufferAlignment: C.uint32_t,
});


const VkPhysicalDeviceTexelBufferAlignmentProperties = new T.StructBuffer("VkPhysicalDeviceTexelBufferAlignmentProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    storageTexelBufferOffsetAlignmentBytes: C.uint64_t,
    storageTexelBufferOffsetSingleTexelAlignment: C.uint32_t,
    uniformTexelBufferOffsetAlignmentBytes: C.uint64_t,
    uniformTexelBufferOffsetSingleTexelAlignment: C.uint32_t,
});


const VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT", {

});


const VkPhysicalDeviceSubgroupSizeControlFeatures = new T.StructBuffer("VkPhysicalDeviceSubgroupSizeControlFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    subgroupSizeControl: C.uint32_t,
    computeFullSubgroups: C.uint32_t,
});


const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceSubgroupSizeControlFeaturesEXT", {

});


const VkPhysicalDeviceSubgroupSizeControlProperties = new T.StructBuffer("VkPhysicalDeviceSubgroupSizeControlProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    minSubgroupSize: C.uint32_t,
    maxSubgroupSize: C.uint32_t,
    maxComputeWorkgroupSubgroups: C.uint32_t,
    requiredSubgroupSizeStages: C.uint32_t,
});


const VkPhysicalDeviceSubgroupSizeControlPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceSubgroupSizeControlPropertiesEXT", {

});


const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo = new T.StructBuffer("VkPipelineShaderStageRequiredSubgroupSizeCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    requiredSubgroupSize: C.uint32_t,
});


const VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT = new T.StructBuffer("VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT", {

});


const VkSubpassShadingPipelineCreateInfoHUAWEI = new T.StructBuffer("VkSubpassShadingPipelineCreateInfoHUAWEI", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    renderPass: C.uint32_t,
    subpass: C.uint32_t,
});


const VkPhysicalDeviceSubpassShadingPropertiesHUAWEI = new T.StructBuffer("VkPhysicalDeviceSubpassShadingPropertiesHUAWEI", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxSubpassShadingWorkgroupSizeAspectRatio: C.uint32_t,
});


const VkMemoryOpaqueCaptureAddressAllocateInfo = new T.StructBuffer("VkMemoryOpaqueCaptureAddressAllocateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    opaqueCaptureAddress: C.uint64_t,
});


const VkMemoryOpaqueCaptureAddressAllocateInfoKHR = new T.StructBuffer("VkMemoryOpaqueCaptureAddressAllocateInfoKHR", {

});


const VkDeviceMemoryOpaqueCaptureAddressInfo = new T.StructBuffer("VkDeviceMemoryOpaqueCaptureAddressInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memory: C.uint64_t,
});


const VkDeviceMemoryOpaqueCaptureAddressInfoKHR = new T.StructBuffer("VkDeviceMemoryOpaqueCaptureAddressInfoKHR", {

});


const VkPhysicalDeviceLineRasterizationFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceLineRasterizationFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    rectangularLines: C.uint32_t,
    bresenhamLines: C.uint32_t,
    smoothLines: C.uint32_t,
    stippledRectangularLines: C.uint32_t,
    stippledBresenhamLines: C.uint32_t,
    stippledSmoothLines: C.uint32_t,
});


const VkPhysicalDeviceLineRasterizationPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceLineRasterizationPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    lineSubPixelPrecisionBits: C.uint32_t,
});


const VkPipelineRasterizationLineStateCreateInfoEXT = new T.StructBuffer("VkPipelineRasterizationLineStateCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    lineRasterizationMode: C.uint32_t,
    stippledLineEnable: C.uint32_t,
    lineStippleFactor: C.uint32_t,
    lineStipplePattern: C.uint16_t,
});


const VkPhysicalDevicePipelineCreationCacheControlFeatures = new T.StructBuffer("VkPhysicalDevicePipelineCreationCacheControlFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pipelineCreationCacheControl: C.uint32_t,
});


const VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT = new T.StructBuffer("VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT", {

});


const VkPhysicalDeviceVulkan11Features = new T.StructBuffer("VkPhysicalDeviceVulkan11Features", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    storageBuffer16BitAccess: C.uint32_t,
    uniformAndStorageBuffer16BitAccess: C.uint32_t,
    storagePushConstant16: C.uint32_t,
    storageInputOutput16: C.uint32_t,
    multiview: C.uint32_t,
    multiviewGeometryShader: C.uint32_t,
    multiviewTessellationShader: C.uint32_t,
    variablePointersStorageBuffer: C.uint32_t,
    variablePointers: C.uint32_t,
    protectedMemory: C.uint32_t,
    samplerYcbcrConversion: C.uint32_t,
    shaderDrawParameters: C.uint32_t,
});


const VkPhysicalDeviceVulkan11Properties = new T.StructBuffer("VkPhysicalDeviceVulkan11Properties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceUUID: C.uint8_t[enums.VK_UUID_SIZE],
    driverUUID: C.uint8_t[enums.VK_UUID_SIZE],
    deviceLUID: C.uint8_t[enums.VK_LUID_SIZE],
    deviceNodeMask: C.uint32_t,
    deviceLUIDValid: C.uint32_t,
    subgroupSize: C.uint32_t,
    subgroupSupportedStages: C.uint32_t,
    subgroupSupportedOperations: C.uint32_t,
    subgroupQuadOperationsInAllStages: C.uint32_t,
    pointClippingBehavior: C.uint32_t,
    maxMultiviewViewCount: C.uint32_t,
    maxMultiviewInstanceIndex: C.uint32_t,
    protectedNoFault: C.uint32_t,
    maxPerSetDescriptors: C.uint32_t,
    maxMemoryAllocationSize: C.uint64_t,
});


const VkPhysicalDeviceVulkan12Features = new T.StructBuffer("VkPhysicalDeviceVulkan12Features", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    samplerMirrorClampToEdge: C.uint32_t,
    drawIndirectCount: C.uint32_t,
    storageBuffer8BitAccess: C.uint32_t,
    uniformAndStorageBuffer8BitAccess: C.uint32_t,
    storagePushConstant8: C.uint32_t,
    shaderBufferInt64Atomics: C.uint32_t,
    shaderSharedInt64Atomics: C.uint32_t,
    shaderFloat16: C.uint32_t,
    shaderInt8: C.uint32_t,
    descriptorIndexing: C.uint32_t,
    shaderInputAttachmentArrayDynamicIndexing: C.uint32_t,
    shaderUniformTexelBufferArrayDynamicIndexing: C.uint32_t,
    shaderStorageTexelBufferArrayDynamicIndexing: C.uint32_t,
    shaderUniformBufferArrayNonUniformIndexing: C.uint32_t,
    shaderSampledImageArrayNonUniformIndexing: C.uint32_t,
    shaderStorageBufferArrayNonUniformIndexing: C.uint32_t,
    shaderStorageImageArrayNonUniformIndexing: C.uint32_t,
    shaderInputAttachmentArrayNonUniformIndexing: C.uint32_t,
    shaderUniformTexelBufferArrayNonUniformIndexing: C.uint32_t,
    shaderStorageTexelBufferArrayNonUniformIndexing: C.uint32_t,
    descriptorBindingUniformBufferUpdateAfterBind: C.uint32_t,
    descriptorBindingSampledImageUpdateAfterBind: C.uint32_t,
    descriptorBindingStorageImageUpdateAfterBind: C.uint32_t,
    descriptorBindingStorageBufferUpdateAfterBind: C.uint32_t,
    descriptorBindingUniformTexelBufferUpdateAfterBind: C.uint32_t,
    descriptorBindingStorageTexelBufferUpdateAfterBind: C.uint32_t,
    descriptorBindingUpdateUnusedWhilePending: C.uint32_t,
    descriptorBindingPartiallyBound: C.uint32_t,
    descriptorBindingVariableDescriptorCount: C.uint32_t,
    runtimeDescriptorArray: C.uint32_t,
    samplerFilterMinmax: C.uint32_t,
    scalarBlockLayout: C.uint32_t,
    imagelessFramebuffer: C.uint32_t,
    uniformBufferStandardLayout: C.uint32_t,
    shaderSubgroupExtendedTypes: C.uint32_t,
    separateDepthStencilLayouts: C.uint32_t,
    hostQueryReset: C.uint32_t,
    timelineSemaphore: C.uint32_t,
    bufferDeviceAddress: C.uint32_t,
    bufferDeviceAddressCaptureReplay: C.uint32_t,
    bufferDeviceAddressMultiDevice: C.uint32_t,
    vulkanMemoryModel: C.uint32_t,
    vulkanMemoryModelDeviceScope: C.uint32_t,
    vulkanMemoryModelAvailabilityVisibilityChains: C.uint32_t,
    shaderOutputViewportIndex: C.uint32_t,
    shaderOutputLayer: C.uint32_t,
    subgroupBroadcastDynamicId: C.uint32_t,
});


const VkPhysicalDeviceVulkan12Properties = new T.StructBuffer("VkPhysicalDeviceVulkan12Properties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    driverID: C.uint32_t,
    driverName: C.uint8_t[enums.VK_MAX_DRIVER_NAME_SIZE],
    driverInfo: C.uint8_t[enums.VK_MAX_DRIVER_INFO_SIZE],
    conformanceVersion: C.uint32_t,
    denormBehaviorIndependence: C.uint32_t,
    roundingModeIndependence: C.uint32_t,
    shaderSignedZeroInfNanPreserveFloat16: C.uint32_t,
    shaderSignedZeroInfNanPreserveFloat32: C.uint32_t,
    shaderSignedZeroInfNanPreserveFloat64: C.uint32_t,
    shaderDenormPreserveFloat16: C.uint32_t,
    shaderDenormPreserveFloat32: C.uint32_t,
    shaderDenormPreserveFloat64: C.uint32_t,
    shaderDenormFlushToZeroFloat16: C.uint32_t,
    shaderDenormFlushToZeroFloat32: C.uint32_t,
    shaderDenormFlushToZeroFloat64: C.uint32_t,
    shaderRoundingModeRTEFloat16: C.uint32_t,
    shaderRoundingModeRTEFloat32: C.uint32_t,
    shaderRoundingModeRTEFloat64: C.uint32_t,
    shaderRoundingModeRTZFloat16: C.uint32_t,
    shaderRoundingModeRTZFloat32: C.uint32_t,
    shaderRoundingModeRTZFloat64: C.uint32_t,
    maxUpdateAfterBindDescriptorsInAllPools: C.uint32_t,
    shaderUniformBufferArrayNonUniformIndexingNative: C.uint32_t,
    shaderSampledImageArrayNonUniformIndexingNative: C.uint32_t,
    shaderStorageBufferArrayNonUniformIndexingNative: C.uint32_t,
    shaderStorageImageArrayNonUniformIndexingNative: C.uint32_t,
    shaderInputAttachmentArrayNonUniformIndexingNative: C.uint32_t,
    robustBufferAccessUpdateAfterBind: C.uint32_t,
    quadDivergentImplicitLod: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindSamplers: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindUniformBuffers: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindStorageBuffers: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindSampledImages: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindStorageImages: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindInputAttachments: C.uint32_t,
    maxPerStageUpdateAfterBindResources: C.uint32_t,
    maxDescriptorSetUpdateAfterBindSamplers: C.uint32_t,
    maxDescriptorSetUpdateAfterBindUniformBuffers: C.uint32_t,
    maxDescriptorSetUpdateAfterBindUniformBuffersDynamic: C.uint32_t,
    maxDescriptorSetUpdateAfterBindStorageBuffers: C.uint32_t,
    maxDescriptorSetUpdateAfterBindStorageBuffersDynamic: C.uint32_t,
    maxDescriptorSetUpdateAfterBindSampledImages: C.uint32_t,
    maxDescriptorSetUpdateAfterBindStorageImages: C.uint32_t,
    maxDescriptorSetUpdateAfterBindInputAttachments: C.uint32_t,
    supportedDepthResolveModes: C.uint32_t,
    supportedStencilResolveModes: C.uint32_t,
    independentResolveNone: C.uint32_t,
    independentResolve: C.uint32_t,
    filterMinmaxSingleComponentFormats: C.uint32_t,
    filterMinmaxImageComponentMapping: C.uint32_t,
    maxTimelineSemaphoreValueDifference: C.uint64_t,
    framebufferIntegerColorSampleCounts: C.uint32_t,
});


const VkPhysicalDeviceVulkan13Features = new T.StructBuffer("VkPhysicalDeviceVulkan13Features", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    robustImageAccess: C.uint32_t,
    inlineUniformBlock: C.uint32_t,
    descriptorBindingInlineUniformBlockUpdateAfterBind: C.uint32_t,
    pipelineCreationCacheControl: C.uint32_t,
    privateData: C.uint32_t,
    shaderDemoteToHelperInvocation: C.uint32_t,
    shaderTerminateInvocation: C.uint32_t,
    subgroupSizeControl: C.uint32_t,
    computeFullSubgroups: C.uint32_t,
    synchronization2: C.uint32_t,
    textureCompressionASTC_HDR: C.uint32_t,
    shaderZeroInitializeWorkgroupMemory: C.uint32_t,
    dynamicRendering: C.uint32_t,
    shaderIntegerDotProduct: C.uint32_t,
    maintenance4: C.uint32_t,
});


const VkPhysicalDeviceVulkan13Properties = new T.StructBuffer("VkPhysicalDeviceVulkan13Properties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    minSubgroupSize: C.uint32_t,
    maxSubgroupSize: C.uint32_t,
    maxComputeWorkgroupSubgroups: C.uint32_t,
    requiredSubgroupSizeStages: C.uint32_t,
    maxInlineUniformBlockSize: C.uint32_t,
    maxPerStageDescriptorInlineUniformBlocks: C.uint32_t,
    maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks: C.uint32_t,
    maxDescriptorSetInlineUniformBlocks: C.uint32_t,
    maxDescriptorSetUpdateAfterBindInlineUniformBlocks: C.uint32_t,
    maxInlineUniformTotalSize: C.uint32_t,
    integerDotProduct8BitUnsignedAccelerated: C.uint32_t,
    integerDotProduct8BitSignedAccelerated: C.uint32_t,
    integerDotProduct8BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProduct4x8BitPackedUnsignedAccelerated: C.uint32_t,
    integerDotProduct4x8BitPackedSignedAccelerated: C.uint32_t,
    integerDotProduct4x8BitPackedMixedSignednessAccelerated: C.uint32_t,
    integerDotProduct16BitUnsignedAccelerated: C.uint32_t,
    integerDotProduct16BitSignedAccelerated: C.uint32_t,
    integerDotProduct16BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProduct32BitUnsignedAccelerated: C.uint32_t,
    integerDotProduct32BitSignedAccelerated: C.uint32_t,
    integerDotProduct32BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProduct64BitUnsignedAccelerated: C.uint32_t,
    integerDotProduct64BitSignedAccelerated: C.uint32_t,
    integerDotProduct64BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating8BitUnsignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating8BitSignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating16BitUnsignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating16BitSignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating32BitUnsignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating32BitSignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating64BitUnsignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating64BitSignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated: C.uint32_t,
    storageTexelBufferOffsetAlignmentBytes: C.uint64_t,
    storageTexelBufferOffsetSingleTexelAlignment: C.uint32_t,
    uniformTexelBufferOffsetAlignmentBytes: C.uint64_t,
    uniformTexelBufferOffsetSingleTexelAlignment: C.uint32_t,
    maxBufferSize: C.uint64_t,
});


const VkPipelineCompilerControlCreateInfoAMD = new T.StructBuffer("VkPipelineCompilerControlCreateInfoAMD", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    compilerControlFlags: C.uint32_t,
});


const VkPhysicalDeviceCoherentMemoryFeaturesAMD = new T.StructBuffer("VkPhysicalDeviceCoherentMemoryFeaturesAMD", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceCoherentMemory: C.uint32_t,
});


const VkPhysicalDeviceToolProperties = new T.StructBuffer("VkPhysicalDeviceToolProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    name: C.uint8_t[enums.VK_MAX_EXTENSION_NAME_SIZE],
    version: C.uint8_t[enums.VK_MAX_EXTENSION_NAME_SIZE],
    purposes: C.uint32_t,
    description: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
    layer: C.uint8_t[enums.VK_MAX_EXTENSION_NAME_SIZE],
});


const VkPhysicalDeviceToolPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceToolPropertiesEXT", {

});


const VkSamplerCustomBorderColorCreateInfoEXT = new T.StructBuffer("VkSamplerCustomBorderColorCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    customBorderColor: C.uint32_t,
    format: C.uint32_t,
});


const VkPhysicalDeviceCustomBorderColorPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceCustomBorderColorPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxCustomBorderColorSamplers: C.uint32_t,
});


const VkPhysicalDeviceCustomBorderColorFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceCustomBorderColorFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    customBorderColors: C.uint32_t,
    customBorderColorWithoutFormat: C.uint32_t,
});


const VkSamplerBorderColorComponentMappingCreateInfoEXT = new T.StructBuffer("VkSamplerBorderColorComponentMappingCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    components: C.uint32_t,
    srgb: C.uint32_t,
});


const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceBorderColorSwizzleFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    borderColorSwizzle: C.uint32_t,
    borderColorSwizzleFromImage: C.uint32_t,
});


const VkAccelerationStructureGeometryTrianglesDataKHR = new T.StructBuffer("VkAccelerationStructureGeometryTrianglesDataKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    vertexFormat: C.uint32_t,
    vertexData: C.uint32_t,
    vertexStride: C.uint64_t,
    maxVertex: C.uint32_t,
    indexType: C.uint32_t,
    indexData: C.uint32_t,
    transformData: C.uint32_t,
});


const VkAccelerationStructureGeometryAabbsDataKHR = new T.StructBuffer("VkAccelerationStructureGeometryAabbsDataKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    data: C.uint32_t,
    stride: C.uint64_t,
});


const VkAccelerationStructureGeometryInstancesDataKHR = new T.StructBuffer("VkAccelerationStructureGeometryInstancesDataKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    arrayOfPointers: C.uint32_t,
    data: C.uint32_t,
});


const VkAccelerationStructureGeometryKHR = new T.StructBuffer("VkAccelerationStructureGeometryKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    geometryType: C.uint32_t,
    geometry: C.uint32_t,
    flags: C.uint32_t,
});


const VkAccelerationStructureBuildGeometryInfoKHR = new T.StructBuffer("VkAccelerationStructureBuildGeometryInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    type: C.uint32_t,
    flags: C.uint32_t,
    mode: C.uint32_t,
    srcAccelerationStructure: C.uint64_t,
    dstAccelerationStructure: C.uint64_t,
    geometryCount: C.uint32_t,
    pGeometries: C.uint64_t,
    ppGeometries: C.uint64_t,
    scratchData: C.uint64_t,
});


const VkAccelerationStructureBuildRangeInfoKHR = new T.StructBuffer("VkAccelerationStructureBuildRangeInfoKHR", {
    primitiveCount: C.uint32_t,
    primitiveOffset: C.uint32_t,
    firstVertex: C.uint32_t,
    transformOffset: C.uint32_t,
});


const VkAccelerationStructureCreateInfoKHR = new T.StructBuffer("VkAccelerationStructureCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    createFlags: C.uint32_t,
    buffer: C.uint64_t,
    offset: C.uint64_t,
    size: C.uint64_t,
    type: C.uint32_t,
    deviceAddress: C.uint64_t,
});


const VkAabbPositionsKHR = new T.StructBuffer("VkAabbPositionsKHR", {
    minX: C.float,
    minY: C.float,
    minZ: C.float,
    maxX: C.float,
    maxY: C.float,
    maxZ: C.float,
});


const VkAabbPositionsNV = new T.StructBuffer("VkAabbPositionsNV", {

});


const VkTransformMatrixKHR = new T.StructBuffer("VkTransformMatrixKHR", {
    matrix: C.float[3][4],
});    


const VkTransformMatrixNV = new T.StructBuffer("VkTransformMatrixNV", {
    matrix: C.float[3][4],
});    


const VkAccelerationStructureInstanceKHR = new T.StructBuffer("VkAccelerationStructureInstanceKHR", {
    transform: VkTransformMatrixKHR,
    instanceCustomIndex: uint24_t,
    mask: C.uint8_t,
    instanceShaderBindingTableRecordOffset: uint24_t,
    flags: C.uint8_t,
    accelerationStructureReference: C.uint64_t,
});


const VkAccelerationStructureInstanceNV = new T.StructBuffer("VkAccelerationStructureInstanceNV", {
    transform: VkTransformMatrixKHR,
    instanceCustomIndex: uint24_t,
    mask: C.uint8_t,
    instanceShaderBindingTableRecordOffset: uint24_t,
    flags: C.uint8_t,
    accelerationStructureReference: C.uint64_t,
});


const VkAccelerationStructureDeviceAddressInfoKHR = new T.StructBuffer("VkAccelerationStructureDeviceAddressInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    accelerationStructure: C.uint64_t,
});


const VkAccelerationStructureVersionInfoKHR = new T.StructBuffer("VkAccelerationStructureVersionInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pVersionData: C.uint64_t,
});


const VkCopyAccelerationStructureInfoKHR = new T.StructBuffer("VkCopyAccelerationStructureInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    src: C.uint64_t,
    dst: C.uint64_t,
    mode: C.uint32_t,
});


const VkCopyAccelerationStructureToMemoryInfoKHR = new T.StructBuffer("VkCopyAccelerationStructureToMemoryInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    src: C.uint64_t,
    dst: C.uint64_t,
    mode: C.uint32_t,
});


const VkCopyMemoryToAccelerationStructureInfoKHR = new T.StructBuffer("VkCopyMemoryToAccelerationStructureInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    src: C.uint32_t,
    dst: C.uint64_t,
    mode: C.uint32_t,
});


const VkRayTracingPipelineInterfaceCreateInfoKHR = new T.StructBuffer("VkRayTracingPipelineInterfaceCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxPipelineRayPayloadSize: C.uint32_t,
    maxPipelineRayHitAttributeSize: C.uint32_t,
});


const VkPipelineLibraryCreateInfoKHR = new T.StructBuffer("VkPipelineLibraryCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    libraryCount: C.uint32_t,
    pLibraries: C.uint64_t,
});


const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceExtendedDynamicStateFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    extendedDynamicState: C.uint32_t,
});


const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT = new T.StructBuffer("VkPhysicalDeviceExtendedDynamicState2FeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    extendedDynamicState2: C.uint32_t,
    extendedDynamicState2LogicOp: C.uint32_t,
    extendedDynamicState2PatchControlPoints: C.uint32_t,
});


const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT = new T.StructBuffer("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    extendedDynamicState3TessellationDomainOrigin: C.uint32_t,
    extendedDynamicState3DepthClampEnable: C.uint32_t,
    extendedDynamicState3PolygonMode: C.uint32_t,
    extendedDynamicState3RasterizationSamples: C.uint32_t,
    extendedDynamicState3SampleMask: C.uint32_t,
    extendedDynamicState3AlphaToCoverageEnable: C.uint32_t,
    extendedDynamicState3AlphaToOneEnable: C.uint32_t,
    extendedDynamicState3LogicOpEnable: C.uint32_t,
    extendedDynamicState3ColorBlendEnable: C.uint32_t,
    extendedDynamicState3ColorBlendEquation: C.uint32_t,
    extendedDynamicState3ColorWriteMask: C.uint32_t,
    extendedDynamicState3RasterizationStream: C.uint32_t,
    extendedDynamicState3ConservativeRasterizationMode: C.uint32_t,
    extendedDynamicState3ExtraPrimitiveOverestimationSize: C.uint32_t,
    extendedDynamicState3DepthClipEnable: C.uint32_t,
    extendedDynamicState3SampleLocationsEnable: C.uint32_t,
    extendedDynamicState3ColorBlendAdvanced: C.uint32_t,
    extendedDynamicState3ProvokingVertexMode: C.uint32_t,
    extendedDynamicState3LineRasterizationMode: C.uint32_t,
    extendedDynamicState3LineStippleEnable: C.uint32_t,
    extendedDynamicState3DepthClipNegativeOneToOne: C.uint32_t,
    extendedDynamicState3ViewportWScalingEnable: C.uint32_t,
    extendedDynamicState3ViewportSwizzle: C.uint32_t,
    extendedDynamicState3CoverageToColorEnable: C.uint32_t,
    extendedDynamicState3CoverageToColorLocation: C.uint32_t,
    extendedDynamicState3CoverageModulationMode: C.uint32_t,
    extendedDynamicState3CoverageModulationTableEnable: C.uint32_t,
    extendedDynamicState3CoverageModulationTable: C.uint32_t,
    extendedDynamicState3CoverageReductionMode: C.uint32_t,
    extendedDynamicState3RepresentativeFragmentTestEnable: C.uint32_t,
    extendedDynamicState3ShadingRateImageEnable: C.uint32_t,
});


const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT = new T.StructBuffer("VkPhysicalDeviceExtendedDynamicState3PropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    dynamicPrimitiveTopologyUnrestricted: C.uint32_t,
});


const VkColorBlendEquationEXT = new T.StructBuffer("VkColorBlendEquationEXT", {
    srcColorBlendFactor: C.uint32_t,
    dstColorBlendFactor: C.uint32_t,
    colorBlendOp: C.uint32_t,
    srcAlphaBlendFactor: C.uint32_t,
    dstAlphaBlendFactor: C.uint32_t,
    alphaBlendOp: C.uint32_t,
});


const VkColorBlendAdvancedEXT = new T.StructBuffer("VkColorBlendAdvancedEXT", {
    advancedBlendOp: C.uint32_t,
    srcPremultiplied: C.uint32_t,
    dstPremultiplied: C.uint32_t,
    blendOverlap: C.uint32_t,
    clampResults: C.uint32_t,
});


const VkRenderPassTransformBeginInfoQCOM = new T.StructBuffer("VkRenderPassTransformBeginInfoQCOM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    transform: C.uint32_t,
});


const VkCopyCommandTransformInfoQCOM = new T.StructBuffer("VkCopyCommandTransformInfoQCOM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    transform: C.uint32_t,
});


const VkCommandBufferInheritanceRenderPassTransformInfoQCOM = new T.StructBuffer("VkCommandBufferInheritanceRenderPassTransformInfoQCOM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    transform: C.uint32_t,
    renderArea: VkRect2D,
});


const VkPhysicalDeviceDiagnosticsConfigFeaturesNV = new T.StructBuffer("VkPhysicalDeviceDiagnosticsConfigFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    diagnosticsConfig: C.uint32_t,
});


const VkDeviceDiagnosticsConfigCreateInfoNV = new T.StructBuffer("VkDeviceDiagnosticsConfigCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
});


const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures = new T.StructBuffer("VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderZeroInitializeWorkgroupMemory: C.uint32_t,
});


const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR", {

});


const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderSubgroupUniformControlFlow: C.uint32_t,
});


const VkPhysicalDeviceRobustness2FeaturesEXT = new T.StructBuffer("VkPhysicalDeviceRobustness2FeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    robustBufferAccess2: C.uint32_t,
    robustImageAccess2: C.uint32_t,
    nullDescriptor: C.uint32_t,
});


const VkPhysicalDeviceRobustness2PropertiesEXT = new T.StructBuffer("VkPhysicalDeviceRobustness2PropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    robustStorageBufferAccessSizeAlignment: C.uint64_t,
    robustUniformBufferAccessSizeAlignment: C.uint64_t,
});


const VkPhysicalDeviceImageRobustnessFeatures = new T.StructBuffer("VkPhysicalDeviceImageRobustnessFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    robustImageAccess: C.uint32_t,
});


const VkPhysicalDeviceImageRobustnessFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceImageRobustnessFeaturesEXT", {

});


const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    workgroupMemoryExplicitLayout: C.uint32_t,
    workgroupMemoryExplicitLayoutScalarBlockLayout: C.uint32_t,
    workgroupMemoryExplicitLayout8BitAccess: C.uint32_t,
    workgroupMemoryExplicitLayout16BitAccess: C.uint32_t,
});


const VkPhysicalDevicePortabilitySubsetFeaturesKHR = new T.StructBuffer("VkPhysicalDevicePortabilitySubsetFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    constantAlphaColorBlendFactors: C.uint32_t,
    events: C.uint32_t,
    imageViewFormatReinterpretation: C.uint32_t,
    imageViewFormatSwizzle: C.uint32_t,
    imageView2DOn3DImage: C.uint32_t,
    multisampleArrayImage: C.uint32_t,
    mutableComparisonSamplers: C.uint32_t,
    pointPolygons: C.uint32_t,
    samplerMipLodBias: C.uint32_t,
    separateStencilMaskRef: C.uint32_t,
    shaderSampleRateInterpolationFunctions: C.uint32_t,
    tessellationIsolines: C.uint32_t,
    tessellationPointMode: C.uint32_t,
    triangleFans: C.uint32_t,
    vertexAttributeAccessBeyondStride: C.uint32_t,
});


const VkPhysicalDevicePortabilitySubsetPropertiesKHR = new T.StructBuffer("VkPhysicalDevicePortabilitySubsetPropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    minVertexInputBindingStrideAlignment: C.uint32_t,
});


const VkPhysicalDevice4444FormatsFeaturesEXT = new T.StructBuffer("VkPhysicalDevice4444FormatsFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    formatA4R4G4B4: C.uint32_t,
    formatA4B4G4R4: C.uint32_t,
});


const VkPhysicalDeviceSubpassShadingFeaturesHUAWEI = new T.StructBuffer("VkPhysicalDeviceSubpassShadingFeaturesHUAWEI", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    subpassShading: C.uint32_t,
});


const VkBufferCopy2 = new T.StructBuffer("VkBufferCopy2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcOffset: C.uint64_t,
    dstOffset: C.uint64_t,
    size: C.uint64_t,
});


const VkBufferCopy2KHR = new T.StructBuffer("VkBufferCopy2KHR", {

});


const VkImageCopy2 = new T.StructBuffer("VkImageCopy2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcSubresource: C.uint32_t,
    srcOffset: C.uint32_t,
    dstSubresource: C.uint32_t,
    dstOffset: C.uint32_t,
    extent: C.uint32_t,
});


const VkImageCopy2KHR = new T.StructBuffer("VkImageCopy2KHR", {

});


const VkImageBlit2 = new T.StructBuffer("VkImageBlit2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcSubresource: C.uint32_t,
    srcOffsets: C.uint32_t,
    dstSubresource: C.uint32_t,
    dstOffsets: C.uint32_t,
});


const VkImageBlit2KHR = new T.StructBuffer("VkImageBlit2KHR", {

});


const VkBufferImageCopy2 = new T.StructBuffer("VkBufferImageCopy2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    bufferOffset: C.uint64_t,
    bufferRowLength: C.uint32_t,
    bufferImageHeight: C.uint32_t,
    imageSubresource: C.uint32_t,
    imageOffset: C.uint32_t,
    imageExtent: C.uint32_t,
});


const VkBufferImageCopy2KHR = new T.StructBuffer("VkBufferImageCopy2KHR", {

});


const VkImageResolve2 = new T.StructBuffer("VkImageResolve2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcSubresource: C.uint32_t,
    srcOffset: C.uint32_t,
    dstSubresource: C.uint32_t,
    dstOffset: C.uint32_t,
    extent: C.uint32_t,
});


const VkImageResolve2KHR = new T.StructBuffer("VkImageResolve2KHR", {

});


const VkCopyBufferInfo2 = new T.StructBuffer("VkCopyBufferInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcBuffer: C.uint64_t,
    dstBuffer: C.uint64_t,
    regionCount: C.uint32_t,
    pRegions: C.uint64_t,
});


const VkCopyBufferInfo2KHR = new T.StructBuffer("VkCopyBufferInfo2KHR", {

});


const VkCopyImageInfo2 = new T.StructBuffer("VkCopyImageInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcImage: C.uint64_t,
    srcImageLayout: C.uint32_t,
    dstImage: C.uint64_t,
    dstImageLayout: C.uint32_t,
    regionCount: C.uint32_t,
    pRegions: C.uint64_t,
});


const VkCopyImageInfo2KHR = new T.StructBuffer("VkCopyImageInfo2KHR", {

});


const VkBlitImageInfo2 = new T.StructBuffer("VkBlitImageInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcImage: C.uint64_t,
    srcImageLayout: C.uint32_t,
    dstImage: C.uint64_t,
    dstImageLayout: C.uint32_t,
    regionCount: C.uint32_t,
    pRegions: C.uint64_t,
    filter: C.uint32_t,
});


const VkBlitImageInfo2KHR = new T.StructBuffer("VkBlitImageInfo2KHR", {

});


const VkCopyBufferToImageInfo2 = new T.StructBuffer("VkCopyBufferToImageInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcBuffer: C.uint64_t,
    dstImage: C.uint64_t,
    dstImageLayout: C.uint32_t,
    regionCount: C.uint32_t,
    pRegions: C.uint64_t,
});


const VkCopyBufferToImageInfo2KHR = new T.StructBuffer("VkCopyBufferToImageInfo2KHR", {

});


const VkCopyImageToBufferInfo2 = new T.StructBuffer("VkCopyImageToBufferInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcImage: C.uint64_t,
    srcImageLayout: C.uint32_t,
    dstBuffer: C.uint64_t,
    regionCount: C.uint32_t,
    pRegions: C.uint64_t,
});


const VkCopyImageToBufferInfo2KHR = new T.StructBuffer("VkCopyImageToBufferInfo2KHR", {

});


const VkResolveImageInfo2 = new T.StructBuffer("VkResolveImageInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcImage: C.uint64_t,
    srcImageLayout: C.uint32_t,
    dstImage: C.uint64_t,
    dstImageLayout: C.uint32_t,
    regionCount: C.uint32_t,
    pRegions: C.uint64_t,
});


const VkResolveImageInfo2KHR = new T.StructBuffer("VkResolveImageInfo2KHR", {

});


const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT = new T.StructBuffer("VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderImageInt64Atomics: C.uint32_t,
    sparseImageInt64Atomics: C.uint32_t,
});


const VkFragmentShadingRateAttachmentInfoKHR = new T.StructBuffer("VkFragmentShadingRateAttachmentInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pFragmentShadingRateAttachment: C.uint64_t,
    shadingRateAttachmentTexelSize: VkExtent2D,
});


const VkPipelineFragmentShadingRateStateCreateInfoKHR = new T.StructBuffer("VkPipelineFragmentShadingRateStateCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fragmentSize: VkExtent2D,
    combinerOps: C.uint32_t,
});


const VkPhysicalDeviceFragmentShadingRateFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceFragmentShadingRateFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pipelineFragmentShadingRate: C.uint32_t,
    primitiveFragmentShadingRate: C.uint32_t,
    attachmentFragmentShadingRate: C.uint32_t,
});


const VkPhysicalDeviceFragmentShadingRatePropertiesKHR = new T.StructBuffer("VkPhysicalDeviceFragmentShadingRatePropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    minFragmentShadingRateAttachmentTexelSize: VkExtent2D,
    maxFragmentShadingRateAttachmentTexelSize: VkExtent2D,
    maxFragmentShadingRateAttachmentTexelSizeAspectRatio: C.uint32_t,
    primitiveFragmentShadingRateWithMultipleViewports: C.uint32_t,
    layeredShadingRateAttachments: C.uint32_t,
    fragmentShadingRateNonTrivialCombinerOps: C.uint32_t,
    maxFragmentSize: VkExtent2D,
    maxFragmentSizeAspectRatio: C.uint32_t,
    maxFragmentShadingRateCoverageSamples: C.uint32_t,
    maxFragmentShadingRateRasterizationSamples: C.uint32_t,
    fragmentShadingRateWithShaderDepthStencilWrites: C.uint32_t,
    fragmentShadingRateWithSampleMask: C.uint32_t,
    fragmentShadingRateWithShaderSampleMask: C.uint32_t,
    fragmentShadingRateWithConservativeRasterization: C.uint32_t,
    fragmentShadingRateWithFragmentShaderInterlock: C.uint32_t,
    fragmentShadingRateWithCustomSampleLocations: C.uint32_t,
    fragmentShadingRateStrictMultiplyCombiner: C.uint32_t,
});


const VkPhysicalDeviceFragmentShadingRateKHR = new T.StructBuffer("VkPhysicalDeviceFragmentShadingRateKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    sampleCounts: C.uint32_t,
    fragmentSize: VkExtent2D,
});


const VkPhysicalDeviceShaderTerminateInvocationFeatures = new T.StructBuffer("VkPhysicalDeviceShaderTerminateInvocationFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderTerminateInvocation: C.uint32_t,
});


const VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR", {

});


const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV = new T.StructBuffer("VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fragmentShadingRateEnums: C.uint32_t,
    supersampleFragmentShadingRates: C.uint32_t,
    noInvocationFragmentShadingRates: C.uint32_t,
});


const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV = new T.StructBuffer("VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxFragmentShadingRateInvocationCount: C.uint32_t,
});


const VkPipelineFragmentShadingRateEnumStateCreateInfoNV = new T.StructBuffer("VkPipelineFragmentShadingRateEnumStateCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shadingRateType: C.uint32_t,
    shadingRate: C.uint32_t,
    combinerOps: C.uint32_t,
});


const VkAccelerationStructureBuildSizesInfoKHR = new T.StructBuffer("VkAccelerationStructureBuildSizesInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    accelerationStructureSize: C.uint64_t,
    updateScratchSize: C.uint64_t,
    buildScratchSize: C.uint64_t,
});


const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceImage2DViewOf3DFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    image2DViewOf3D: C.uint32_t,
    sampler2DViewOf3D: C.uint32_t,
});


const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    mutableDescriptorType: C.uint32_t,
});


const VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE = new T.StructBuffer("VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE", {

});


const VkMutableDescriptorTypeListEXT = new T.StructBuffer("VkMutableDescriptorTypeListEXT", {
    descriptorTypeCount: C.uint32_t,
    pDescriptorTypes: C.uint64_t,
});


const VkMutableDescriptorTypeListVALVE = new T.StructBuffer("VkMutableDescriptorTypeListVALVE", {

});


const VkMutableDescriptorTypeCreateInfoEXT = new T.StructBuffer("VkMutableDescriptorTypeCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    mutableDescriptorTypeListCount: C.uint32_t,
    pMutableDescriptorTypeLists: C.uint64_t,
});


const VkMutableDescriptorTypeCreateInfoVALVE = new T.StructBuffer("VkMutableDescriptorTypeCreateInfoVALVE", {

});


const VkPhysicalDeviceDepthClipControlFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceDepthClipControlFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    depthClipControl: C.uint32_t,
});


const VkPipelineViewportDepthClipControlCreateInfoEXT = new T.StructBuffer("VkPipelineViewportDepthClipControlCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    negativeOneToOne: C.uint32_t,
});


const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    vertexInputDynamicState: C.uint32_t,
});


const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV = new T.StructBuffer("VkPhysicalDeviceExternalMemoryRDMAFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    externalMemoryRDMA: C.uint32_t,
});


const VkVertexInputBindingDescription2EXT = new T.StructBuffer("VkVertexInputBindingDescription2EXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    binding: C.uint32_t,
    stride: C.uint32_t,
    inputRate: C.uint32_t,
    divisor: C.uint32_t,
});


const VkVertexInputAttributeDescription2EXT = new T.StructBuffer("VkVertexInputAttributeDescription2EXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    location: C.uint32_t,
    binding: C.uint32_t,
    format: C.uint32_t,
    offset: C.uint32_t,
});


const VkPhysicalDeviceColorWriteEnableFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceColorWriteEnableFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    colorWriteEnable: C.uint32_t,
});


const VkPipelineColorWriteCreateInfoEXT = new T.StructBuffer("VkPipelineColorWriteCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    attachmentCount: C.uint32_t,
    pColorWriteEnables: C.uint64_t,
});


const VkMemoryBarrier2 = new T.StructBuffer("VkMemoryBarrier2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcStageMask: C.uint64_t,
    srcAccessMask: C.uint64_t,
    dstStageMask: C.uint64_t,
    dstAccessMask: C.uint64_t,
});


const VkMemoryBarrier2KHR = new T.StructBuffer("VkMemoryBarrier2KHR", {

});


const VkImageMemoryBarrier2 = new T.StructBuffer("VkImageMemoryBarrier2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcStageMask: C.uint64_t,
    srcAccessMask: C.uint64_t,
    dstStageMask: C.uint64_t,
    dstAccessMask: C.uint64_t,
    oldLayout: C.uint32_t,
    newLayout: C.uint32_t,
    srcQueueFamilyIndex: C.uint32_t,
    dstQueueFamilyIndex: C.uint32_t,
    image: C.uint64_t,
    subresourceRange: C.uint32_t,
});


const VkImageMemoryBarrier2KHR = new T.StructBuffer("VkImageMemoryBarrier2KHR", {

});


const VkBufferMemoryBarrier2 = new T.StructBuffer("VkBufferMemoryBarrier2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    srcStageMask: C.uint64_t,
    srcAccessMask: C.uint64_t,
    dstStageMask: C.uint64_t,
    dstAccessMask: C.uint64_t,
    srcQueueFamilyIndex: C.uint32_t,
    dstQueueFamilyIndex: C.uint32_t,
    buffer: C.uint64_t,
    offset: C.uint64_t,
    size: C.uint64_t,
});


const VkBufferMemoryBarrier2KHR = new T.StructBuffer("VkBufferMemoryBarrier2KHR", {

});


const VkDependencyInfo = new T.StructBuffer("VkDependencyInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    dependencyFlags: C.uint32_t,
    memoryBarrierCount: C.uint32_t,
    pMemoryBarriers: C.uint64_t,
    bufferMemoryBarrierCount: C.uint32_t,
    pBufferMemoryBarriers: C.uint64_t,
    imageMemoryBarrierCount: C.uint32_t,
    pImageMemoryBarriers: C.uint64_t,
});


const VkDependencyInfoKHR = new T.StructBuffer("VkDependencyInfoKHR", {

});


const VkSemaphoreSubmitInfo = new T.StructBuffer("VkSemaphoreSubmitInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    semaphore: C.uint32_t,
    value: C.uint64_t,
    stageMask: C.uint64_t,
    deviceIndex: C.uint32_t,
});


const VkSemaphoreSubmitInfoKHR = new T.StructBuffer("VkSemaphoreSubmitInfoKHR", {

});


const VkCommandBufferSubmitInfo = new T.StructBuffer("VkCommandBufferSubmitInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    commandBuffer: C.uint32_t,
    deviceMask: C.uint32_t,
});


const VkCommandBufferSubmitInfoKHR = new T.StructBuffer("VkCommandBufferSubmitInfoKHR", {

});


const VkSubmitInfo2 = new T.StructBuffer("VkSubmitInfo2", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    waitSemaphoreInfoCount: C.uint32_t,
    pWaitSemaphoreInfos: C.uint64_t,
    commandBufferInfoCount: C.uint32_t,
    pCommandBufferInfos: C.uint64_t,
    signalSemaphoreInfoCount: C.uint32_t,
    pSignalSemaphoreInfos: C.uint64_t,
});


const VkSubmitInfo2KHR = new T.StructBuffer("VkSubmitInfo2KHR", {

});


const VkQueueFamilyCheckpointProperties2NV = new T.StructBuffer("VkQueueFamilyCheckpointProperties2NV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    checkpointExecutionStageMask: C.uint64_t,
});


const VkCheckpointData2NV = new T.StructBuffer("VkCheckpointData2NV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stage: C.uint64_t,
    pCheckpointMarker: C.uint64_t,
});


const VkPhysicalDeviceSynchronization2Features = new T.StructBuffer("VkPhysicalDeviceSynchronization2Features", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    synchronization2: C.uint32_t,
});


const VkPhysicalDeviceSynchronization2FeaturesKHR = new T.StructBuffer("VkPhysicalDeviceSynchronization2FeaturesKHR", {

});


const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT = new T.StructBuffer("VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    primitivesGeneratedQuery: C.uint32_t,
    primitivesGeneratedQueryWithRasterizerDiscard: C.uint32_t,
    primitivesGeneratedQueryWithNonZeroStreams: C.uint32_t,
});


const VkPhysicalDeviceLegacyDitheringFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceLegacyDitheringFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    legacyDithering: C.uint32_t,
});


const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    multisampledRenderToSingleSampled: C.uint32_t,
});


const VkSubpassResolvePerformanceQueryEXT = new T.StructBuffer("VkSubpassResolvePerformanceQueryEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    optimal: C.uint32_t,
});


const VkMultisampledRenderToSingleSampledInfoEXT = new T.StructBuffer("VkMultisampledRenderToSingleSampledInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    multisampledRenderToSingleSampledEnable: C.uint32_t,
    rasterizationSamples: C.uint32_t,
});


const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT = new T.StructBuffer("VkPhysicalDevicePipelineProtectedAccessFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pipelineProtectedAccess: C.uint32_t,
});


const VkQueueFamilyVideoPropertiesKHR = new T.StructBuffer("VkQueueFamilyVideoPropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    videoCodecOperations: C.uint32_t,
});


const VkQueueFamilyQueryResultStatusPropertiesKHR = new T.StructBuffer("VkQueueFamilyQueryResultStatusPropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    queryResultStatusSupport: C.uint32_t,
});


const VkVideoProfileListInfoKHR = new T.StructBuffer("VkVideoProfileListInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    profileCount: C.uint32_t,
    pProfiles: C.uint64_t,
});


const VkPhysicalDeviceVideoFormatInfoKHR = new T.StructBuffer("VkPhysicalDeviceVideoFormatInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageUsage: C.uint32_t,
});


const VkVideoFormatPropertiesKHR = new T.StructBuffer("VkVideoFormatPropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    format: C.uint32_t,
    componentMapping: C.uint32_t,
    imageCreateFlags: C.uint32_t,
    imageType: C.uint32_t,
    imageTiling: C.uint32_t,
    imageUsageFlags: C.uint32_t,
});


const VkVideoProfileInfoKHR = new T.StructBuffer("VkVideoProfileInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    videoCodecOperation: C.uint32_t,
    chromaSubsampling: C.uint32_t,
    lumaBitDepth: C.uint32_t,
    chromaBitDepth: C.uint32_t,
});


const VkVideoCapabilitiesKHR = new T.StructBuffer("VkVideoCapabilitiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    minBitstreamBufferOffsetAlignment: C.uint64_t,
    minBitstreamBufferSizeAlignment: C.uint64_t,
    pictureAccessGranularity: VkExtent2D,
    minCodedExtent: VkExtent2D,
    maxCodedExtent: VkExtent2D,
    maxDpbSlots: C.uint32_t,
    maxActiveReferencePictures: C.uint32_t,
    stdHeaderVersion: C.uint32_t,
});


const VkVideoSessionMemoryRequirementsKHR = new T.StructBuffer("VkVideoSessionMemoryRequirementsKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memoryBindIndex: C.uint32_t,
    memoryRequirements: C.uint32_t,
});


const VkBindVideoSessionMemoryInfoKHR = new T.StructBuffer("VkBindVideoSessionMemoryInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memoryBindIndex: C.uint32_t,
    memory: C.uint64_t,
    memoryOffset: C.uint64_t,
    memorySize: C.uint64_t,
});


const VkVideoPictureResourceInfoKHR = new T.StructBuffer("VkVideoPictureResourceInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    codedOffset: VkOffset2D,
    codedExtent: VkExtent2D,
    baseArrayLayer: C.uint32_t,
    imageViewBinding: C.uint32_t,
});


const VkVideoReferenceSlotInfoKHR = new T.StructBuffer("VkVideoReferenceSlotInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    slotIndex: C.int32_t,
    pPictureResource: C.uint64_t,
});


const VkVideoDecodeCapabilitiesKHR = new T.StructBuffer("VkVideoDecodeCapabilitiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
});


const VkVideoDecodeUsageInfoKHR = new T.StructBuffer("VkVideoDecodeUsageInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    videoUsageHints: C.uint32_t,
});


const VkVideoDecodeInfoKHR = new T.StructBuffer("VkVideoDecodeInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    srcBuffer: C.uint64_t,
    srcBufferOffset: C.uint64_t,
    srcBufferRange: C.uint64_t,
    dstPictureResource: C.uint32_t,
    pSetupReferenceSlot: C.uint64_t,
    referenceSlotCount: C.uint32_t,
    pReferenceSlots: C.uint64_t,
});


const VkVideoDecodeH264ProfileInfoEXT = new T.StructBuffer("VkVideoDecodeH264ProfileInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stdProfileIdc: C.uint32_t,
    pictureLayout: C.uint32_t,
});


const VkVideoDecodeH264CapabilitiesEXT = new T.StructBuffer("VkVideoDecodeH264CapabilitiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxLevelIdc: C.uint32_t,
    fieldOffsetGranularity: VkOffset2D,
});


const VkVideoDecodeH264SessionParametersAddInfoEXT = new T.StructBuffer("VkVideoDecodeH264SessionParametersAddInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stdSPSCount: C.uint32_t,
    pStdSPSs: C.uint64_t,
    stdPPSCount: C.uint32_t,
    pStdPPSs: C.uint64_t,
});


const VkVideoDecodeH264SessionParametersCreateInfoEXT = new T.StructBuffer("VkVideoDecodeH264SessionParametersCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxStdSPSCount: C.uint32_t,
    maxStdPPSCount: C.uint32_t,
    pParametersAddInfo: C.uint64_t,
});


const VkVideoDecodeH264PictureInfoEXT = new T.StructBuffer("VkVideoDecodeH264PictureInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pStdPictureInfo: C.uint64_t,
    sliceCount: C.uint32_t,
    pSliceOffsets: C.uint64_t,
});


const VkVideoDecodeH264DpbSlotInfoEXT = new T.StructBuffer("VkVideoDecodeH264DpbSlotInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pStdReferenceInfo: C.uint64_t,
});


const VkVideoDecodeH265ProfileInfoEXT = new T.StructBuffer("VkVideoDecodeH265ProfileInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stdProfileIdc: C.uint32_t,
});


const VkVideoDecodeH265CapabilitiesEXT = new T.StructBuffer("VkVideoDecodeH265CapabilitiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxLevelIdc: C.uint32_t,
});


const VkVideoDecodeH265SessionParametersAddInfoEXT = new T.StructBuffer("VkVideoDecodeH265SessionParametersAddInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stdVPSCount: C.uint32_t,
    pStdVPSs: C.uint64_t,
    stdSPSCount: C.uint32_t,
    pStdSPSs: C.uint64_t,
    stdPPSCount: C.uint32_t,
    pStdPPSs: C.uint64_t,
});


const VkVideoDecodeH265SessionParametersCreateInfoEXT = new T.StructBuffer("VkVideoDecodeH265SessionParametersCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxStdVPSCount: C.uint32_t,
    maxStdSPSCount: C.uint32_t,
    maxStdPPSCount: C.uint32_t,
    pParametersAddInfo: C.uint64_t,
});


const VkVideoDecodeH265PictureInfoEXT = new T.StructBuffer("VkVideoDecodeH265PictureInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pStdPictureInfo: C.uint64_t,
    sliceCount: C.uint32_t,
    pSliceOffsets: C.uint64_t,
});


const VkVideoDecodeH265DpbSlotInfoEXT = new T.StructBuffer("VkVideoDecodeH265DpbSlotInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pStdReferenceInfo: C.uint64_t,
});


const VkVideoSessionCreateInfoKHR = new T.StructBuffer("VkVideoSessionCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    queueFamilyIndex: C.uint32_t,
    flags: C.uint32_t,
    pVideoProfile: C.uint64_t,
    pictureFormat: C.uint32_t,
    maxCodedExtent: VkExtent2D,
    referencePictureFormat: C.uint32_t,
    maxDpbSlots: C.uint32_t,
    maxActiveReferencePictures: C.uint32_t,
    pStdHeaderVersion: C.uint64_t,
});


const VkVideoSessionParametersCreateInfoKHR = new T.StructBuffer("VkVideoSessionParametersCreateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    videoSessionParametersTemplate: C.uint32_t,
    videoSession: C.uint32_t,
});


const VkVideoSessionParametersUpdateInfoKHR = new T.StructBuffer("VkVideoSessionParametersUpdateInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    updateSequenceCount: C.uint32_t,
});


const VkVideoBeginCodingInfoKHR = new T.StructBuffer("VkVideoBeginCodingInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    videoSession: C.uint32_t,
    videoSessionParameters: C.uint32_t,
    referenceSlotCount: C.uint32_t,
    pReferenceSlots: C.uint64_t,
});


const VkVideoEndCodingInfoKHR = new T.StructBuffer("VkVideoEndCodingInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
});


const VkVideoCodingControlInfoKHR = new T.StructBuffer("VkVideoCodingControlInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
});


const VkVideoEncodeUsageInfoKHR = new T.StructBuffer("VkVideoEncodeUsageInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    videoUsageHints: C.uint32_t,
    videoContentHints: C.uint32_t,
    tuningMode: C.uint32_t,
});


const VkVideoEncodeInfoKHR = new T.StructBuffer("VkVideoEncodeInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    qualityLevel: C.uint32_t,
    dstBitstreamBuffer: C.uint64_t,
    dstBitstreamBufferOffset: C.uint64_t,
    dstBitstreamBufferMaxRange: C.uint64_t,
    srcPictureResource: C.uint32_t,
    pSetupReferenceSlot: C.uint64_t,
    referenceSlotCount: C.uint32_t,
    pReferenceSlots: C.uint64_t,
    precedingExternallyEncodedBytes: C.uint32_t,
});


const VkVideoEncodeRateControlInfoKHR = new T.StructBuffer("VkVideoEncodeRateControlInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    rateControlMode: C.uint32_t,
    layerCount: C.uint8_t,
    pLayerConfigs: C.uint64_t,
});


const VkVideoEncodeRateControlLayerInfoKHR = new T.StructBuffer("VkVideoEncodeRateControlLayerInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    averageBitrate: C.uint32_t,
    maxBitrate: C.uint32_t,
    frameRateNumerator: C.uint32_t,
    frameRateDenominator: C.uint32_t,
    virtualBufferSizeInMs: C.uint32_t,
    initialVirtualBufferSizeInMs: C.uint32_t,
});


const VkVideoEncodeCapabilitiesKHR = new T.StructBuffer("VkVideoEncodeCapabilitiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    rateControlModes: C.uint32_t,
    rateControlLayerCount: C.uint8_t,
    qualityLevelCount: C.uint8_t,
    inputImageDataFillAlignment: VkExtent2D,
});


const VkVideoEncodeH264CapabilitiesEXT = new T.StructBuffer("VkVideoEncodeH264CapabilitiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    inputModeFlags: C.uint32_t,
    outputModeFlags: C.uint32_t,
    maxPPictureL0ReferenceCount: C.uint8_t,
    maxBPictureL0ReferenceCount: C.uint8_t,
    maxL1ReferenceCount: C.uint8_t,
    motionVectorsOverPicBoundariesFlag: C.uint32_t,
    maxBytesPerPicDenom: C.uint32_t,
    maxBitsPerMbDenom: C.uint32_t,
    log2MaxMvLengthHorizontal: C.uint32_t,
    log2MaxMvLengthVertical: C.uint32_t,
});


const VkVideoEncodeH264SessionParametersAddInfoEXT = new T.StructBuffer("VkVideoEncodeH264SessionParametersAddInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stdSPSCount: C.uint32_t,
    pStdSPSs: C.uint64_t,
    stdPPSCount: C.uint32_t,
    pStdPPSs: C.uint64_t,
});


const VkVideoEncodeH264SessionParametersCreateInfoEXT = new T.StructBuffer("VkVideoEncodeH264SessionParametersCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxStdSPSCount: C.uint32_t,
    maxStdPPSCount: C.uint32_t,
    pParametersAddInfo: C.uint64_t,
});


const VkVideoEncodeH264DpbSlotInfoEXT = new T.StructBuffer("VkVideoEncodeH264DpbSlotInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    slotIndex: C.int8_t,
    pStdReferenceInfo: C.uint64_t,
});


const VkVideoEncodeH264VclFrameInfoEXT = new T.StructBuffer("VkVideoEncodeH264VclFrameInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pReferenceFinalLists: C.uint64_t,
    naluSliceEntryCount: C.uint32_t,
    pNaluSliceEntries: C.uint64_t,
    pCurrentPictureInfo: C.uint64_t,
});


const VkVideoEncodeH264ReferenceListsInfoEXT = new T.StructBuffer("VkVideoEncodeH264ReferenceListsInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    referenceList0EntryCount: C.uint8_t,
    pReferenceList0Entries: C.uint64_t,
    referenceList1EntryCount: C.uint8_t,
    pReferenceList1Entries: C.uint64_t,
    pMemMgmtCtrlOperations: C.uint64_t,
});


const VkVideoEncodeH264EmitPictureParametersInfoEXT = new T.StructBuffer("VkVideoEncodeH264EmitPictureParametersInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    spsId: C.uint8_t,
    emitSpsEnable: C.uint32_t,
    ppsIdEntryCount: C.uint32_t,
    ppsIdEntries: C.uint64_t,
});


const VkVideoEncodeH264ProfileInfoEXT = new T.StructBuffer("VkVideoEncodeH264ProfileInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stdProfileIdc: C.uint32_t,
});


const VkVideoEncodeH264NaluSliceInfoEXT = new T.StructBuffer("VkVideoEncodeH264NaluSliceInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    mbCount: C.uint32_t,
    pReferenceFinalLists: C.uint64_t,
    pSliceHeaderStd: C.uint64_t,
});


const VkVideoEncodeH264RateControlInfoEXT = new T.StructBuffer("VkVideoEncodeH264RateControlInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    gopFrameCount: C.uint32_t,
    idrPeriod: C.uint32_t,
    consecutiveBFrameCount: C.uint32_t,
    rateControlStructure: C.uint32_t,
    temporalLayerCount: C.uint8_t,
});


const VkVideoEncodeH264QpEXT = new T.StructBuffer("VkVideoEncodeH264QpEXT", {
    qpI: C.int32_t,
    qpP: C.int32_t,
    qpB: C.int32_t,
});


const VkVideoEncodeH264FrameSizeEXT = new T.StructBuffer("VkVideoEncodeH264FrameSizeEXT", {
    frameISize: C.uint32_t,
    framePSize: C.uint32_t,
    frameBSize: C.uint32_t,
});


const VkVideoEncodeH264RateControlLayerInfoEXT = new T.StructBuffer("VkVideoEncodeH264RateControlLayerInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    temporalLayerId: C.uint8_t,
    useInitialRcQp: C.uint32_t,
    initialRcQp: C.uint32_t,
    useMinQp: C.uint32_t,
    minQp: C.uint32_t,
    useMaxQp: C.uint32_t,
    maxQp: C.uint32_t,
    useMaxFrameSize: C.uint32_t,
    maxFrameSize: C.uint32_t,
});


const VkVideoEncodeH265CapabilitiesEXT = new T.StructBuffer("VkVideoEncodeH265CapabilitiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    inputModeFlags: C.uint32_t,
    outputModeFlags: C.uint32_t,
    ctbSizes: C.uint32_t,
    transformBlockSizes: C.uint32_t,
    maxPPictureL0ReferenceCount: C.uint8_t,
    maxBPictureL0ReferenceCount: C.uint8_t,
    maxL1ReferenceCount: C.uint8_t,
    maxSubLayersCount: C.uint8_t,
    minLog2MinLumaCodingBlockSizeMinus3: C.uint8_t,
    maxLog2MinLumaCodingBlockSizeMinus3: C.uint8_t,
    minLog2MinLumaTransformBlockSizeMinus2: C.uint8_t,
    maxLog2MinLumaTransformBlockSizeMinus2: C.uint8_t,
    minMaxTransformHierarchyDepthInter: C.uint8_t,
    maxMaxTransformHierarchyDepthInter: C.uint8_t,
    minMaxTransformHierarchyDepthIntra: C.uint8_t,
    maxMaxTransformHierarchyDepthIntra: C.uint8_t,
    maxDiffCuQpDeltaDepth: C.uint8_t,
    minMaxNumMergeCand: C.uint8_t,
    maxMaxNumMergeCand: C.uint8_t,
});


const VkVideoEncodeH265SessionParametersAddInfoEXT = new T.StructBuffer("VkVideoEncodeH265SessionParametersAddInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stdVPSCount: C.uint32_t,
    pStdVPSs: C.uint64_t,
    stdSPSCount: C.uint32_t,
    pStdSPSs: C.uint64_t,
    stdPPSCount: C.uint32_t,
    pStdPPSs: C.uint64_t,
});


const VkVideoEncodeH265SessionParametersCreateInfoEXT = new T.StructBuffer("VkVideoEncodeH265SessionParametersCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxStdVPSCount: C.uint32_t,
    maxStdSPSCount: C.uint32_t,
    maxStdPPSCount: C.uint32_t,
    pParametersAddInfo: C.uint64_t,
});


const VkVideoEncodeH265VclFrameInfoEXT = new T.StructBuffer("VkVideoEncodeH265VclFrameInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pReferenceFinalLists: C.uint64_t,
    naluSliceSegmentEntryCount: C.uint32_t,
    pNaluSliceSegmentEntries: C.uint64_t,
    pCurrentPictureInfo: C.uint64_t,
});


const VkVideoEncodeH265EmitPictureParametersInfoEXT = new T.StructBuffer("VkVideoEncodeH265EmitPictureParametersInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    vpsId: C.uint8_t,
    spsId: C.uint8_t,
    emitVpsEnable: C.uint32_t,
    emitSpsEnable: C.uint32_t,
    ppsIdEntryCount: C.uint32_t,
    ppsIdEntries: C.uint64_t,
});


const VkVideoEncodeH265NaluSliceSegmentInfoEXT = new T.StructBuffer("VkVideoEncodeH265NaluSliceSegmentInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    ctbCount: C.uint32_t,
    pReferenceFinalLists: C.uint64_t,
    pSliceSegmentHeaderStd: C.uint64_t,
});


const VkVideoEncodeH265RateControlInfoEXT = new T.StructBuffer("VkVideoEncodeH265RateControlInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    gopFrameCount: C.uint32_t,
    idrPeriod: C.uint32_t,
    consecutiveBFrameCount: C.uint32_t,
    rateControlStructure: C.uint32_t,
    subLayerCount: C.uint8_t,
});


const VkVideoEncodeH265QpEXT = new T.StructBuffer("VkVideoEncodeH265QpEXT", {
    qpI: C.int32_t,
    qpP: C.int32_t,
    qpB: C.int32_t,
});


const VkVideoEncodeH265FrameSizeEXT = new T.StructBuffer("VkVideoEncodeH265FrameSizeEXT", {
    frameISize: C.uint32_t,
    framePSize: C.uint32_t,
    frameBSize: C.uint32_t,
});


const VkVideoEncodeH265RateControlLayerInfoEXT = new T.StructBuffer("VkVideoEncodeH265RateControlLayerInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    temporalId: C.uint8_t,
    useInitialRcQp: C.uint32_t,
    initialRcQp: C.uint32_t,
    useMinQp: C.uint32_t,
    minQp: C.uint32_t,
    useMaxQp: C.uint32_t,
    maxQp: C.uint32_t,
    useMaxFrameSize: C.uint32_t,
    maxFrameSize: C.uint32_t,
});


const VkVideoEncodeH265ProfileInfoEXT = new T.StructBuffer("VkVideoEncodeH265ProfileInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    stdProfileIdc: C.uint32_t,
});


const VkVideoEncodeH265DpbSlotInfoEXT = new T.StructBuffer("VkVideoEncodeH265DpbSlotInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    slotIndex: C.int8_t,
    pStdReferenceInfo: C.uint64_t,
});


const VkVideoEncodeH265ReferenceListsInfoEXT = new T.StructBuffer("VkVideoEncodeH265ReferenceListsInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    referenceList0EntryCount: C.uint8_t,
    pReferenceList0Entries: C.uint64_t,
    referenceList1EntryCount: C.uint8_t,
    pReferenceList1Entries: C.uint64_t,
    pReferenceModifications: C.uint64_t,
});


const VkPhysicalDeviceInheritedViewportScissorFeaturesNV = new T.StructBuffer("VkPhysicalDeviceInheritedViewportScissorFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    inheritedViewportScissor2D: C.uint32_t,
});


const VkCommandBufferInheritanceViewportScissorInfoNV = new T.StructBuffer("VkCommandBufferInheritanceViewportScissorInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    viewportScissor2D: C.uint32_t,
    viewportDepthCount: C.uint32_t,
    pViewportDepths: C.uint64_t,
});


const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    ycbcr2plane444Formats: C.uint32_t,
});


const VkPhysicalDeviceProvokingVertexFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceProvokingVertexFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    provokingVertexLast: C.uint32_t,
    transformFeedbackPreservesProvokingVertex: C.uint32_t,
});


const VkPhysicalDeviceProvokingVertexPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceProvokingVertexPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    provokingVertexModePerPipeline: C.uint32_t,
    transformFeedbackPreservesTriangleFanProvokingVertex: C.uint32_t,
});


const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT = new T.StructBuffer("VkPipelineRasterizationProvokingVertexStateCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    provokingVertexMode: C.uint32_t,
});


const VkCuModuleCreateInfoNVX = new T.StructBuffer("VkCuModuleCreateInfoNVX", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    dataSize: C.uint64_t,
    pData: C.uint64_t,
});


const VkCuFunctionCreateInfoNVX = new T.StructBuffer("VkCuFunctionCreateInfoNVX", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    module: C.uint32_t,
    pName: C.uint64_t,
});


const VkCuLaunchInfoNVX = new T.StructBuffer("VkCuLaunchInfoNVX", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    function: C.uint32_t,
    gridDimX: C.uint32_t,
    gridDimY: C.uint32_t,
    gridDimZ: C.uint32_t,
    blockDimX: C.uint32_t,
    blockDimY: C.uint32_t,
    blockDimZ: C.uint32_t,
    sharedMemBytes: C.uint32_t,
    paramCount: C.uint64_t,
    pParams: C.uint64_t,
    extraCount: C.uint64_t,
    pExtras: C.uint64_t,
});


const VkPhysicalDeviceShaderIntegerDotProductFeatures = new T.StructBuffer("VkPhysicalDeviceShaderIntegerDotProductFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderIntegerDotProduct: C.uint32_t,
});


const VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR", {

});


const VkPhysicalDeviceShaderIntegerDotProductProperties = new T.StructBuffer("VkPhysicalDeviceShaderIntegerDotProductProperties", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    integerDotProduct8BitUnsignedAccelerated: C.uint32_t,
    integerDotProduct8BitSignedAccelerated: C.uint32_t,
    integerDotProduct8BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProduct4x8BitPackedUnsignedAccelerated: C.uint32_t,
    integerDotProduct4x8BitPackedSignedAccelerated: C.uint32_t,
    integerDotProduct4x8BitPackedMixedSignednessAccelerated: C.uint32_t,
    integerDotProduct16BitUnsignedAccelerated: C.uint32_t,
    integerDotProduct16BitSignedAccelerated: C.uint32_t,
    integerDotProduct16BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProduct32BitUnsignedAccelerated: C.uint32_t,
    integerDotProduct32BitSignedAccelerated: C.uint32_t,
    integerDotProduct32BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProduct64BitUnsignedAccelerated: C.uint32_t,
    integerDotProduct64BitSignedAccelerated: C.uint32_t,
    integerDotProduct64BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating8BitUnsignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating8BitSignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating16BitUnsignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating16BitSignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating32BitUnsignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating32BitSignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating64BitUnsignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating64BitSignedAccelerated: C.uint32_t,
    integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated: C.uint32_t,
});


const VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR = new T.StructBuffer("VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR", {

});


const VkPhysicalDeviceDrmPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceDrmPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    hasPrimary: C.uint32_t,
    hasRender: C.uint32_t,
    primaryMajor: C.uint64_t,
    primaryMinor: C.uint64_t,
    renderMajor: C.uint64_t,
    renderMinor: C.uint64_t,
});


const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    fragmentShaderBarycentric: C.uint32_t,
});


const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR = new T.StructBuffer("VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    triStripVertexOrderIndependentOfProvokingVertex: C.uint32_t,
});


const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV = new T.StructBuffer("VkPhysicalDeviceRayTracingMotionBlurFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    rayTracingMotionBlur: C.uint32_t,
    rayTracingMotionBlurPipelineTraceRaysIndirect: C.uint32_t,
});


const VkAccelerationStructureGeometryMotionTrianglesDataNV = new T.StructBuffer("VkAccelerationStructureGeometryMotionTrianglesDataNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    vertexData: C.uint32_t,
});


const VkAccelerationStructureMotionInfoNV = new T.StructBuffer("VkAccelerationStructureMotionInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxInstances: C.uint32_t,
    flags: C.uint32_t,
});


const VkSRTDataNV = new T.StructBuffer("VkSRTDataNV", {
    sx: C.float,
    a: C.float,
    b: C.float,
    pvx: C.float,
    sy: C.float,
    c: C.float,
    pvy: C.float,
    sz: C.float,
    pvz: C.float,
    qx: C.float,
    qy: C.float,
    qz: C.float,
    qw: C.float,
    tx: C.float,
    ty: C.float,
    tz: C.float,
});


const VkAccelerationStructureSRTMotionInstanceNV = new T.StructBuffer("VkAccelerationStructureSRTMotionInstanceNV", {
    transformT0: C.uint32_t,
    transformT1: C.uint32_t,
    instanceCustomIndex: uint24_t,
    mask: C.uint8_t,
    instanceShaderBindingTableRecordOffset: uint24_t,
    flags: C.uint8_t,
    accelerationStructureReference: C.uint64_t,
});


const VkAccelerationStructureMatrixMotionInstanceNV = new T.StructBuffer("VkAccelerationStructureMatrixMotionInstanceNV", {
    transformT0: VkTransformMatrixKHR,
    transformT1: VkTransformMatrixKHR,
    instanceCustomIndex: uint24_t,
    mask: C.uint8_t,
    instanceShaderBindingTableRecordOffset: uint24_t,
    flags: C.uint8_t,
    accelerationStructureReference: C.uint64_t,
});


const VkAccelerationStructureMotionInstanceNV = new T.StructBuffer("VkAccelerationStructureMotionInstanceNV", {
    type: C.uint32_t,
    flags: C.uint32_t,
    data: C.uint32_t,
});


const VkMemoryGetRemoteAddressInfoNV = new T.StructBuffer("VkMemoryGetRemoteAddressInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memory: C.uint64_t,
    handleType: C.uint32_t,
});


const VkImportMemoryBufferCollectionFUCHSIA = new T.StructBuffer("VkImportMemoryBufferCollectionFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    collection: C.uint32_t,
    index: C.uint32_t,
});


const VkBufferCollectionImageCreateInfoFUCHSIA = new T.StructBuffer("VkBufferCollectionImageCreateInfoFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    collection: C.uint32_t,
    index: C.uint32_t,
});


const VkBufferCollectionBufferCreateInfoFUCHSIA = new T.StructBuffer("VkBufferCollectionBufferCreateInfoFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    collection: C.uint32_t,
    index: C.uint32_t,
});


const VkBufferCollectionCreateInfoFUCHSIA = new T.StructBuffer("VkBufferCollectionCreateInfoFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    collectionToken: C.uint32_t,
});


const VkBufferCollectionPropertiesFUCHSIA = new T.StructBuffer("VkBufferCollectionPropertiesFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memoryTypeBits: C.uint32_t,
    bufferCount: C.uint32_t,
    createInfoIndex: C.uint32_t,
    sysmemPixelFormat: C.uint64_t,
    formatFeatures: C.uint32_t,
    sysmemColorSpaceIndex: C.uint32_t,
    samplerYcbcrConversionComponents: C.uint32_t,
    suggestedYcbcrModel: C.uint32_t,
    suggestedYcbcrRange: C.uint32_t,
    suggestedXChromaOffset: C.uint32_t,
    suggestedYChromaOffset: C.uint32_t,
});


const VkBufferConstraintsInfoFUCHSIA = new T.StructBuffer("VkBufferConstraintsInfoFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    createInfo: C.uint32_t,
    requiredFormatFeatures: C.uint32_t,
    bufferCollectionConstraints: C.uint32_t,
});


const VkSysmemColorSpaceFUCHSIA = new T.StructBuffer("VkSysmemColorSpaceFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    colorSpace: C.uint32_t,
});


const VkImageFormatConstraintsInfoFUCHSIA = new T.StructBuffer("VkImageFormatConstraintsInfoFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageCreateInfo: C.uint32_t,
    requiredFormatFeatures: C.uint32_t,
    flags: C.uint32_t,
    sysmemPixelFormat: C.uint64_t,
    colorSpaceCount: C.uint32_t,
    pColorSpaces: C.uint64_t,
});


const VkImageConstraintsInfoFUCHSIA = new T.StructBuffer("VkImageConstraintsInfoFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    formatConstraintsCount: C.uint32_t,
    pFormatConstraints: C.uint64_t,
    bufferCollectionConstraints: C.uint32_t,
    flags: C.uint32_t,
});


const VkBufferCollectionConstraintsInfoFUCHSIA = new T.StructBuffer("VkBufferCollectionConstraintsInfoFUCHSIA", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    minBufferCount: C.uint32_t,
    maxBufferCount: C.uint32_t,
    minBufferCountForCamping: C.uint32_t,
    minBufferCountForDedicatedSlack: C.uint32_t,
    minBufferCountForSharedSlack: C.uint32_t,
});


const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    formatRgba10x6WithoutYCbCrSampler: C.uint32_t,
});


const VkFormatProperties3 = new T.StructBuffer("VkFormatProperties3", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    linearTilingFeatures: C.uint64_t,
    optimalTilingFeatures: C.uint64_t,
    bufferFeatures: C.uint64_t,
});


const VkFormatProperties3KHR = new T.StructBuffer("VkFormatProperties3KHR", {

});


const VkDrmFormatModifierPropertiesList2EXT = new T.StructBuffer("VkDrmFormatModifierPropertiesList2EXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    drmFormatModifierCount: C.uint32_t,
    pDrmFormatModifierProperties: C.uint64_t,
});


const VkDrmFormatModifierProperties2EXT = new T.StructBuffer("VkDrmFormatModifierProperties2EXT", {
    drmFormatModifier: C.uint64_t,
    drmFormatModifierPlaneCount: C.uint32_t,
    drmFormatModifierTilingFeatures: C.uint64_t,
});


const VkAndroidHardwareBufferFormatProperties2ANDROID = new T.StructBuffer("VkAndroidHardwareBufferFormatProperties2ANDROID", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    format: C.uint32_t,
    externalFormat: C.uint64_t,
    formatFeatures: C.uint64_t,
    samplerYcbcrConversionComponents: C.uint32_t,
    suggestedYcbcrModel: C.uint32_t,
    suggestedYcbcrRange: C.uint32_t,
    suggestedXChromaOffset: C.uint32_t,
    suggestedYChromaOffset: C.uint32_t,
});


const VkPipelineRenderingCreateInfo = new T.StructBuffer("VkPipelineRenderingCreateInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    viewMask: C.uint32_t,
    colorAttachmentCount: C.uint32_t,
    pColorAttachmentFormats: C.uint64_t,
    depthAttachmentFormat: C.uint32_t,
    stencilAttachmentFormat: C.uint32_t,
});


const VkPipelineRenderingCreateInfoKHR = new T.StructBuffer("VkPipelineRenderingCreateInfoKHR", {

});


const VkRenderingInfo = new T.StructBuffer("VkRenderingInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    renderArea: VkRect2D,
    layerCount: C.uint32_t,
    viewMask: C.uint32_t,
    colorAttachmentCount: C.uint32_t,
    pColorAttachments: C.uint64_t,
    pDepthAttachment: C.uint64_t,
    pStencilAttachment: C.uint64_t,
});


const VkRenderingInfoKHR = new T.StructBuffer("VkRenderingInfoKHR", {

});


const VkRenderingAttachmentInfo = new T.StructBuffer("VkRenderingAttachmentInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageView: C.uint32_t,
    imageLayout: C.uint32_t,
    resolveMode: C.uint32_t,
    resolveImageView: C.uint32_t,
    resolveImageLayout: C.uint32_t,
    loadOp: C.uint32_t,
    storeOp: C.uint32_t,
    clearValue: C.uint32_t,
});


const VkRenderingAttachmentInfoKHR = new T.StructBuffer("VkRenderingAttachmentInfoKHR", {

});


const VkRenderingFragmentShadingRateAttachmentInfoKHR = new T.StructBuffer("VkRenderingFragmentShadingRateAttachmentInfoKHR", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageView: C.uint32_t,
    imageLayout: C.uint32_t,
    shadingRateAttachmentTexelSize: VkExtent2D,
});


const VkRenderingFragmentDensityMapAttachmentInfoEXT = new T.StructBuffer("VkRenderingFragmentDensityMapAttachmentInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageView: C.uint32_t,
    imageLayout: C.uint32_t,
});


const VkPhysicalDeviceDynamicRenderingFeatures = new T.StructBuffer("VkPhysicalDeviceDynamicRenderingFeatures", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    dynamicRendering: C.uint32_t,
});


const VkPhysicalDeviceDynamicRenderingFeaturesKHR = new T.StructBuffer("VkPhysicalDeviceDynamicRenderingFeaturesKHR", {

});


const VkCommandBufferInheritanceRenderingInfo = new T.StructBuffer("VkCommandBufferInheritanceRenderingInfo", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    viewMask: C.uint32_t,
    colorAttachmentCount: C.uint32_t,
    pColorAttachmentFormats: C.uint64_t,
    depthAttachmentFormat: C.uint32_t,
    stencilAttachmentFormat: C.uint32_t,
    rasterizationSamples: C.uint32_t,
});


const VkCommandBufferInheritanceRenderingInfoKHR = new T.StructBuffer("VkCommandBufferInheritanceRenderingInfoKHR", {

});


const VkAttachmentSampleCountInfoAMD = new T.StructBuffer("VkAttachmentSampleCountInfoAMD", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    colorAttachmentCount: C.uint32_t,
    pColorAttachmentSamples: C.uint64_t,
    depthStencilAttachmentSamples: C.uint32_t,
});


const VkAttachmentSampleCountInfoNV = new T.StructBuffer("VkAttachmentSampleCountInfoNV", {

});


const VkMultiviewPerViewAttributesInfoNVX = new T.StructBuffer("VkMultiviewPerViewAttributesInfoNVX", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    perViewAttributes: C.uint32_t,
    perViewAttributesPositionXOnly: C.uint32_t,
});


const VkPhysicalDeviceImageViewMinLodFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceImageViewMinLodFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    minLod: C.uint32_t,
});


const VkImageViewMinLodCreateInfoEXT = new T.StructBuffer("VkImageViewMinLodCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    minLod: C.float,
});


const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    rasterizationOrderColorAttachmentAccess: C.uint32_t,
    rasterizationOrderDepthAttachmentAccess: C.uint32_t,
    rasterizationOrderStencilAttachmentAccess: C.uint32_t,
});


const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM = new T.StructBuffer("VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM", {

});


const VkPhysicalDeviceLinearColorAttachmentFeaturesNV = new T.StructBuffer("VkPhysicalDeviceLinearColorAttachmentFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    linearColorAttachment: C.uint32_t,
});


const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    graphicsPipelineLibrary: C.uint32_t,
});


const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    graphicsPipelineLibraryFastLinking: C.uint32_t,
    graphicsPipelineLibraryIndependentInterpolationDecoration: C.uint32_t,
});


const VkGraphicsPipelineLibraryCreateInfoEXT = new T.StructBuffer("VkGraphicsPipelineLibraryCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
});


const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE = new T.StructBuffer("VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    descriptorSetHostMapping: C.uint32_t,
});


const VkDescriptorSetBindingReferenceVALVE = new T.StructBuffer("VkDescriptorSetBindingReferenceVALVE", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    descriptorSetLayout: C.uint32_t,
    binding: C.uint32_t,
});


const VkDescriptorSetLayoutHostMappingInfoVALVE = new T.StructBuffer("VkDescriptorSetLayoutHostMappingInfoVALVE", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    descriptorOffset: C.uint64_t,
    descriptorSize: C.uint32_t,
});


const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderModuleIdentifier: C.uint32_t,
});


const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderModuleIdentifierAlgorithmUUID: C.uint8_t[enums.VK_UUID_SIZE],
});


const VkPipelineShaderStageModuleIdentifierCreateInfoEXT = new T.StructBuffer("VkPipelineShaderStageModuleIdentifierCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    identifierSize: C.uint32_t,
    pIdentifier: C.uint64_t,
});


const VkShaderModuleIdentifierEXT = new T.StructBuffer("VkShaderModuleIdentifierEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    identifierSize: C.uint32_t,
    identifier: C.uint8_t[enums.VK_MAX_SHADER_MODULE_IDENTIFIER_SIZE_EXT],
});


const VkImageCompressionControlEXT = new T.StructBuffer("VkImageCompressionControlEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    compressionControlPlaneCount: C.uint32_t,
    pFixedRateFlags: C.uint64_t,
});


const VkPhysicalDeviceImageCompressionControlFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceImageCompressionControlFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageCompressionControl: C.uint32_t,
});


const VkImageCompressionPropertiesEXT = new T.StructBuffer("VkImageCompressionPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageCompressionFlags: C.uint32_t,
    imageCompressionFixedRateFlags: C.uint32_t,
});


const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageCompressionControlSwapchain: C.uint32_t,
});


const VkImageSubresource2EXT = new T.StructBuffer("VkImageSubresource2EXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    imageSubresource: C.uint32_t,
});


const VkSubresourceLayout2EXT = new T.StructBuffer("VkSubresourceLayout2EXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    subresourceLayout: C.uint32_t,
});


const VkRenderPassCreationControlEXT = new T.StructBuffer("VkRenderPassCreationControlEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    disallowMerging: C.uint32_t,
});


const VkRenderPassCreationFeedbackInfoEXT = new T.StructBuffer("VkRenderPassCreationFeedbackInfoEXT", {
    postMergeSubpassCount: C.uint32_t,
});


const VkRenderPassCreationFeedbackCreateInfoEXT = new T.StructBuffer("VkRenderPassCreationFeedbackCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pRenderPassFeedback: C.uint64_t,
});


const VkRenderPassSubpassFeedbackInfoEXT = new T.StructBuffer("VkRenderPassSubpassFeedbackInfoEXT", {
    subpassMergeStatus: C.uint32_t,
    description: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
    postMergeIndex: C.uint32_t,
});


const VkRenderPassSubpassFeedbackCreateInfoEXT = new T.StructBuffer("VkRenderPassSubpassFeedbackCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pSubpassFeedback: C.uint64_t,
});


const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    subpassMergeFeedback: C.uint32_t,
});


const VkMicromapBuildInfoEXT = new T.StructBuffer("VkMicromapBuildInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    type: C.uint32_t,
    flags: C.uint32_t,
    mode: C.uint32_t,
    dstMicromap: C.uint32_t,
    usageCountsCount: C.uint32_t,
    pUsageCounts: C.uint64_t,
    ppUsageCounts: C.uint64_t,
    data: C.uint32_t,
    scratchData: C.uint64_t,
    triangleArray: C.uint32_t,
    triangleArrayStride: C.uint64_t,
});


const VkMicromapCreateInfoEXT = new T.StructBuffer("VkMicromapCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    createFlags: C.uint32_t,
    buffer: C.uint64_t,
    offset: C.uint64_t,
    size: C.uint64_t,
    type: C.uint32_t,
    deviceAddress: C.uint64_t,
});


const VkMicromapVersionInfoEXT = new T.StructBuffer("VkMicromapVersionInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pVersionData: C.uint64_t,
});


const VkCopyMicromapInfoEXT = new T.StructBuffer("VkCopyMicromapInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    src: C.uint32_t,
    dst: C.uint32_t,
    mode: C.uint32_t,
});


const VkCopyMicromapToMemoryInfoEXT = new T.StructBuffer("VkCopyMicromapToMemoryInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    src: C.uint32_t,
    dst: C.uint64_t,
    mode: C.uint32_t,
});


const VkCopyMemoryToMicromapInfoEXT = new T.StructBuffer("VkCopyMemoryToMicromapInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    src: C.uint32_t,
    dst: C.uint32_t,
    mode: C.uint32_t,
});


const VkMicromapBuildSizesInfoEXT = new T.StructBuffer("VkMicromapBuildSizesInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    micromapSize: C.uint64_t,
    buildScratchSize: C.uint64_t,
    discardable: C.uint32_t,
});


const VkMicromapUsageEXT = new T.StructBuffer("VkMicromapUsageEXT", {
    count: C.uint32_t,
    subdivisionLevel: C.uint32_t,
    format: C.uint32_t,
});


const VkMicromapTriangleEXT = new T.StructBuffer("VkMicromapTriangleEXT", {
    dataOffset: C.uint32_t,
    subdivisionLevel: C.uint16_t,
    format: C.uint16_t,
});


const VkPhysicalDeviceOpacityMicromapFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceOpacityMicromapFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    micromap: C.uint32_t,
    micromapCaptureReplay: C.uint32_t,
    micromapHostCommands: C.uint32_t,
});


const VkPhysicalDeviceOpacityMicromapPropertiesEXT = new T.StructBuffer("VkPhysicalDeviceOpacityMicromapPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxOpacity2StateSubdivisionLevel: C.uint32_t,
    maxOpacity4StateSubdivisionLevel: C.uint32_t,
});


const VkAccelerationStructureTrianglesOpacityMicromapEXT = new T.StructBuffer("VkAccelerationStructureTrianglesOpacityMicromapEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    indexType: C.uint32_t,
    indexBuffer: C.uint32_t,
    indexStride: C.uint64_t,
    baseTriangle: C.uint32_t,
    usageCountsCount: C.uint32_t,
    pUsageCounts: C.uint64_t,
    ppUsageCounts: C.uint64_t,
    micromap: C.uint32_t,
});


const VkPipelinePropertiesIdentifierEXT = new T.StructBuffer("VkPipelinePropertiesIdentifierEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pipelineIdentifier: C.uint8_t[enums.VK_UUID_SIZE],
});


const VkPhysicalDevicePipelinePropertiesFeaturesEXT = new T.StructBuffer("VkPhysicalDevicePipelinePropertiesFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pipelinePropertiesIdentifier: C.uint32_t,
});


const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD = new T.StructBuffer("VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderEarlyAndLateFragmentTests: C.uint32_t,
});


const VkExportMetalObjectCreateInfoEXT = new T.StructBuffer("VkExportMetalObjectCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    exportObjectType: C.uint32_t,
});


const VkExportMetalObjectsInfoEXT = new T.StructBuffer("VkExportMetalObjectsInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
});


const VkExportMetalDeviceInfoEXT = new T.StructBuffer("VkExportMetalDeviceInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    mtlDevice: C.uint32_t,
});


const VkExportMetalCommandQueueInfoEXT = new T.StructBuffer("VkExportMetalCommandQueueInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    queue: C.uint64_t,
    mtlCommandQueue: C.uint32_t,
});


const VkExportMetalBufferInfoEXT = new T.StructBuffer("VkExportMetalBufferInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    memory: C.uint64_t,
    mtlBuffer: C.uint32_t,
});


const VkImportMetalBufferInfoEXT = new T.StructBuffer("VkImportMetalBufferInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    mtlBuffer: C.uint32_t,
});


const VkExportMetalTextureInfoEXT = new T.StructBuffer("VkExportMetalTextureInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    image: C.uint64_t,
    imageView: C.uint32_t,
    bufferView: C.uint32_t,
    plane: C.uint32_t,
    mtlTexture: C.uint32_t,
});


const VkImportMetalTextureInfoEXT = new T.StructBuffer("VkImportMetalTextureInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    plane: C.uint32_t,
    mtlTexture: C.uint32_t,
});


const VkExportMetalIOSurfaceInfoEXT = new T.StructBuffer("VkExportMetalIOSurfaceInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    image: C.uint64_t,
    ioSurface: C.uint32_t,
});


const VkImportMetalIOSurfaceInfoEXT = new T.StructBuffer("VkImportMetalIOSurfaceInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    ioSurface: C.uint32_t,
});


const VkExportMetalSharedEventInfoEXT = new T.StructBuffer("VkExportMetalSharedEventInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    semaphore: C.uint32_t,
    event: C.uint32_t,
    mtlSharedEvent: C.uint32_t,
});


const VkImportMetalSharedEventInfoEXT = new T.StructBuffer("VkImportMetalSharedEventInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    mtlSharedEvent: C.uint32_t,
});


const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    nonSeamlessCubeMap: C.uint32_t,
});


const VkPhysicalDevicePipelineRobustnessFeaturesEXT = new T.StructBuffer("VkPhysicalDevicePipelineRobustnessFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    pipelineRobustness: C.uint32_t,
});


const VkPipelineRobustnessCreateInfoEXT = new T.StructBuffer("VkPipelineRobustnessCreateInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    storageBuffers: C.uint32_t,
    uniformBuffers: C.uint32_t,
    vertexInputs: C.uint32_t,
    images: C.uint32_t,
});


const VkPhysicalDevicePipelineRobustnessPropertiesEXT = new T.StructBuffer("VkPhysicalDevicePipelineRobustnessPropertiesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    defaultRobustnessStorageBuffers: C.uint32_t,
    defaultRobustnessUniformBuffers: C.uint32_t,
    defaultRobustnessVertexInputs: C.uint32_t,
    defaultRobustnessImages: C.uint32_t,
});


const VkImageViewSampleWeightCreateInfoQCOM = new T.StructBuffer("VkImageViewSampleWeightCreateInfoQCOM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    filterCenter: VkOffset2D,
    filterSize: VkExtent2D,
    numPhases: C.uint32_t,
});


const VkPhysicalDeviceImageProcessingFeaturesQCOM = new T.StructBuffer("VkPhysicalDeviceImageProcessingFeaturesQCOM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    textureSampleWeighted: C.uint32_t,
    textureBoxFilter: C.uint32_t,
    textureBlockMatch: C.uint32_t,
});


const VkPhysicalDeviceImageProcessingPropertiesQCOM = new T.StructBuffer("VkPhysicalDeviceImageProcessingPropertiesQCOM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    maxWeightFilterPhases: C.uint32_t,
    maxWeightFilterDimension: VkExtent2D,
    maxBlockMatchRegion: VkExtent2D,
    maxBoxFilterBlockSize: VkExtent2D,
});


const VkPhysicalDeviceTilePropertiesFeaturesQCOM = new T.StructBuffer("VkPhysicalDeviceTilePropertiesFeaturesQCOM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    tileProperties: C.uint32_t,
});


const VkTilePropertiesQCOM = new T.StructBuffer("VkTilePropertiesQCOM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    tileSize: C.uint32_t,
    apronSize: VkExtent2D,
    origin: VkOffset2D,
});


const VkPhysicalDeviceAmigoProfilingFeaturesSEC = new T.StructBuffer("VkPhysicalDeviceAmigoProfilingFeaturesSEC", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    amigoProfiling: C.uint32_t,
});


const VkAmigoProfilingSubmitInfoSEC = new T.StructBuffer("VkAmigoProfilingSubmitInfoSEC", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    firstDrawTimestamp: C.uint64_t,
    swapBufferTimestamp: C.uint64_t,
});


const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    attachmentFeedbackLoopLayout: C.uint32_t,
});


const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceDepthClampZeroOneFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    depthClampZeroOne: C.uint32_t,
});


const VkPhysicalDeviceAddressBindingReportFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceAddressBindingReportFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    reportAddressBinding: C.uint32_t,
});


const VkDeviceAddressBindingCallbackDataEXT = new T.StructBuffer("VkDeviceAddressBindingCallbackDataEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    baseAddress: C.uint64_t,
    size: C.uint64_t,
    bindingType: C.uint32_t,
});


const VkPhysicalDeviceOpticalFlowFeaturesNV = new T.StructBuffer("VkPhysicalDeviceOpticalFlowFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    opticalFlow: C.uint32_t,
});


const VkPhysicalDeviceOpticalFlowPropertiesNV = new T.StructBuffer("VkPhysicalDeviceOpticalFlowPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    supportedOutputGridSizes: C.uint32_t,
    supportedHintGridSizes: C.uint32_t,
    hintSupported: C.uint32_t,
    costSupported: C.uint32_t,
    bidirectionalFlowSupported: C.uint32_t,
    globalFlowSupported: C.uint32_t,
    minWidth: C.uint32_t,
    minHeight: C.uint32_t,
    maxWidth: C.uint32_t,
    maxHeight: C.uint32_t,
    maxNumRegionsOfInterest: C.uint32_t,
});


const VkOpticalFlowImageFormatInfoNV = new T.StructBuffer("VkOpticalFlowImageFormatInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    usage: C.uint32_t,
});


const VkOpticalFlowImageFormatPropertiesNV = new T.StructBuffer("VkOpticalFlowImageFormatPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    format: C.uint32_t,
});


const VkOpticalFlowSessionCreateInfoNV = new T.StructBuffer("VkOpticalFlowSessionCreateInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    width: C.uint32_t,
    height: C.uint32_t,
    imageFormat: C.uint32_t,
    flowVectorFormat: C.uint32_t,
    costFormat: C.uint32_t,
    outputGridSize: C.uint32_t,
    hintGridSize: C.uint32_t,
    performanceLevel: C.uint32_t,
    flags: C.uint32_t,
});


const VkOpticalFlowSessionCreatePrivateDataInfoNV = new T.StructBuffer("VkOpticalFlowSessionCreatePrivateDataInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    id: C.uint32_t,
    size: C.uint32_t,
    pPrivateData: C.uint64_t,
});


const VkOpticalFlowExecuteInfoNV = new T.StructBuffer("VkOpticalFlowExecuteInfoNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    flags: C.uint32_t,
    regionCount: C.uint32_t,
    pRegions: C.uint64_t,
});


const VkPhysicalDeviceFaultFeaturesEXT = new T.StructBuffer("VkPhysicalDeviceFaultFeaturesEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    deviceFault: C.uint32_t,
    deviceFaultVendorBinary: C.uint32_t,
});


const VkDeviceFaultAddressInfoEXT = new T.StructBuffer("VkDeviceFaultAddressInfoEXT", {
    addressType: C.uint32_t,
    reportedAddress: C.uint64_t,
    addressPrecision: C.uint64_t,
});


const VkDeviceFaultVendorInfoEXT = new T.StructBuffer("VkDeviceFaultVendorInfoEXT", {
    description: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
    vendorFaultCode: C.uint64_t,
    vendorFaultData: C.uint64_t,
});


const VkDeviceFaultCountsEXT = new T.StructBuffer("VkDeviceFaultCountsEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    addressInfoCount: C.uint32_t,
    vendorInfoCount: C.uint32_t,
    vendorBinarySize: C.uint64_t,
});


const VkDeviceFaultInfoEXT = new T.StructBuffer("VkDeviceFaultInfoEXT", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    description: C.uint8_t[enums.VK_MAX_DESCRIPTION_SIZE],
    pAddressInfos: C.uint64_t,
    pVendorInfos: C.uint64_t,
    pVendorBinaryData: C.uint64_t,
});


const VkDeviceFaultVendorBinaryHeaderVersionOneEXT = new T.StructBuffer("VkDeviceFaultVendorBinaryHeaderVersionOneEXT", {
    headerSize: C.uint32_t,
    headerVersion: C.uint32_t,
    vendorID: C.uint32_t,
    deviceID: C.uint32_t,
    driverVersion: C.uint32_t,
    pipelineCacheUUID: C.uint8_t[enums.VK_UUID_SIZE],
    applicationNameOffset: C.uint32_t,
    applicationVersion: C.uint32_t,
    engineNameOffset: C.uint32_t,
});


const VkDecompressMemoryRegionNV = new T.StructBuffer("VkDecompressMemoryRegionNV", {
    srcAddress: C.uint64_t,
    dstAddress: C.uint64_t,
    compressedSize: C.uint64_t,
    decompressedSize: C.uint64_t,
    decompressionMethod: C.uint32_t,
});


const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM = new T.StructBuffer("VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderCoreMask: C.uint64_t,
    shaderCoreCount: C.uint32_t,
    shaderWarpsPerCore: C.uint32_t,
});


const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM = new T.StructBuffer("VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    shaderCoreBuiltins: C.uint32_t,
});


const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV = new T.StructBuffer("VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    rayTracingInvocationReorder: C.uint32_t,
});


const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV = new T.StructBuffer("VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV", {
    sType: C.uint32_t,
    pNext: C.uint64_t,
    rayTracingInvocationReorderReorderingHint: C.uint32_t,
});


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
