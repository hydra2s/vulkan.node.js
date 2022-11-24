(async()=>{

    //
    const V = (await import("../../index.js")).default;
    const fs = await import("fs");
    
    //
    console.log("Vulkan is supported: " + V.glfwVulkanSupported());

    //
    const IExt64 = V.glfwGetRequiredInstanceExtensions();
    const IExtensionOpen = new Array(IExt64.length).fill("").map((_, i)=>{ return String.fromAddress(IExt64[i]); });

    //
    let vertices = new Float32Array([
        0.0, -0.5,
        0.5,  0.5,
       -0.5,  0.5 
    ]);

    //
    let posVertexBindingDescr = new V.VkVertexInputBindingDescription({
        binding: 0, 
        stride: 2 * vertices.BYTES_PER_ELEMENT,
        inputRate: V.VK_VERTEX_INPUT_RATE_VERTEX
    });

    //
    let posVertexAttrDescr = new V.VkVertexInputAttributeDescription({
        location: 0,
        binding: 0,
        format: V.VK_FORMAT_R32G32_SFLOAT,
        offset: 0
    });

    //
    const createShaderModule = (device, shaderSrc) => {
        let shaderModuleInfo = new V.VkShaderModuleCreateInfo({
            pCode: shaderSrc,
            codeSize: shaderSrc.byteLength
        });
        const shaderModule = new BigUint64Array(1);
        V.vkCreateShaderModule(device, shaderModuleInfo, null, shaderModule);
        return shaderModule[0];
    }

    //
    const getMemoryTypeIndex = (physicalDevice, typeFilter, propertyFlag) => {
        let memoryProperties = new V.VkPhysicalDeviceMemoryProperties();
        V.vkGetPhysicalDeviceMemoryProperties(physicalDevice, memoryProperties);
        for (let I = 0; I < memoryProperties.memoryTypeCount; ++I) {
          if (
            (typeFilter & (1 << I)) &&
            (memoryProperties.memoryTypes[I].propertyFlags & propertyFlag) === propertyFlag
          ) {
            return I;
          }
        };
        return -1;
    };

    //
    const createShaderModuleInfo = (module, stage, pName = "main")=>{
        return new V.VkPipelineShaderStageCreateInfo({
            flags: 0, stage, module, pName, pSpecializationInfo: null
        });
    }


    //
    const createTypedBuffer = (device, usage, byteSize, PTR = null) => {
        //
        const bufferInfo = new V.VkBufferCreateInfo({
            size: byteSize,
            usage: usage,
            sharingMode: V.VK_SHARING_MODE_EXCLUSIVE,
            queueFamilyIndexCount: 0,
            pQueueFamilyIndices: null
        });

        //
        const buffer = new BigUint64Array(1);
        V.vkCreateBuffer(device, bufferInfo, null, buffer);

        //
        const memoryRequirements = new V.VkMemoryRequirements();
        V.vkGetBufferMemoryRequirements(device, buffer[0], memoryRequirements);

        //
        const propertyFlag = PTR ? (
            V.VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
            V.VK_MEMORY_PROPERTY_HOST_COHERENT_BIT
        ) : V.VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;

        //
        const memAllocFlags = new V.VkMemoryAllocateFlagsInfo({
            flags: V.VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT_KHR
        });

        //
        const memAllocInfo = new V.VkMemoryAllocateInfo({
            pNext: memAllocFlags,
            allocationSize: memoryRequirements.size,
            memoryTypeIndex: getMemoryTypeIndex(physicalDevice, memoryRequirements.memoryTypeBits, propertyFlag)
        });

        //
        const bufferMemory = new BigUint64Array(1);
        V.vkAllocateMemory(device, memAllocInfo, null, bufferMemory);
        V.vkBindBufferMemory(device, buffer[0], bufferMemory[0], 0n);

        //
        if (PTR) {
            //
            const dataPtr = new BigUint64Array(1);
            V.vkMapMemory(device, bufferMemory[0], 0n, bufferInfo.size, 0, dataPtr);

            // gigant spider
            ArrayBuffer.fromAddress(dataPtr[0], bufferInfo.size).set(ArrayBuffer.fromAddress(PTR, bufferInfo.size));
            V.vkUnmapMemory(device, bufferMemory[0]);
        }

        return buffer[0];
    }

    //
    const createVertexBuffer = (device, vertices) => {
        return createTypedBuffer(device, V.VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | V.VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT | V.VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR, vertices.byteLength, vertices);
    }

    //
    const createInstanceBuffer = (device, instances) => {
        return createTypedBuffer(device, V.VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR | V.VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT | V.VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR, instances.byteLength, instances);
    }

    //
    const getBufferDeviceAddress = (device, $buffer)=>{
        return V.vkGetBufferDeviceAddress(device, new V.VkBufferDeviceAddressInfo({ $buffer })); // conflict-less
    }

    //
    const getAcceelerationStructureAddress = (device, accelerationStructure)=>{
        return V.vkGetAccelerationStructureDeviceAddressKHR(device, new V.VkAccelerationStructureDeviceAddressInfoKHR({ accelerationStructure }));
    }


    

    //
    const appInfo = new V.VkApplicationInfo({
        pNext: null,
        pApplicationName: "NVAPI TEST",
        applicationVersion: V.VK_MAKE_API_VERSION(0, 1, 3, 234),
        pEngineName: "NVAPI",
        engineVersion: V.VK_MAKE_API_VERSION(0, 1, 3, 234),
        apiVersion: V.VK_MAKE_API_VERSION(0, 1, 3, 234)
    });

    //
    const extensions = [].concat(IExtensionOpen);
    const layers = ["VK_LAYER_KHRONOS_validation"];

    //
    const amountOfLayers = new Uint32Array(1);
    V.vkEnumerateInstanceLayerProperties(amountOfLayers, null);
    const availableLayers = new V.VkLayerProperties(amountOfLayers[0]);
    V.vkEnumerateInstanceLayerProperties(amountOfLayers, availableLayers);

    //
    let pInfo = new V.VkInstanceCreateInfo({
        pNext: null,
        flags: 0,
        pApplicationInfo: appInfo,
        enabledLayerCount: layers.length,
        ppEnabledLayerNames: layers,
        enabledExtensionCount: extensions.length,
        ppEnabledExtensionNames: extensions
    });

    // 
    const instance = new BigUint64Array(1);
    //const instanceU32 = instance.as("u32[2]");
    V.vkCreateInstance(pInfo, null, instance);
    //console.log(instanceU32);

    //
    console.log("GLFW Window creation...");
    V.glfwWindowHint(V.GLFW_RESIZABLE, V.GLFW_FALSE);
    const window = V.glfwCreateWindow(1280, 720, "Hello Triangle", null, null);

    // make shared GLFW surface between two versions of GLFW
    const surface = new BigUint64Array(1);
    V.glfwCreateWindowSurface(instance[0], window, null, surface);

    //
    const deviceCount = new Uint32Array(1);
    let result = V.vkEnumeratePhysicalDevices(instance[0], deviceCount, null);
    //console.log(deviceCount);

    //
    if (deviceCount[0] <= 0) console.error("Error: No render devices available!");
    const devices = new BigUint64Array(deviceCount[0]);
    result = V.vkEnumeratePhysicalDevices(instance[0], deviceCount, devices);
    const physicalDevice = devices[0];
    //console.log(devices);

    //
    console.log("Physical Device Presentation Support: " + V.glfwGetPhysicalDevicePresentationSupport(instance[0], physicalDevice, 0));

    //
    const dExtensionCount = new Uint32Array(1);
    V.vkEnumerateDeviceExtensionProperties(physicalDevice, V.AsBigInt(""), dExtensionCount, null);
    const dExtensions = new V.VkExtensionProperties(dExtensionCount[0]);
    V.vkEnumerateDeviceExtensionProperties(physicalDevice, V.AsBigInt(""), dExtensionCount, dExtensions);

    // TODO: add extensions and extension filtering
    //for (let I=0;I<dExtensionCount[0];I++) {
        //console.log(String.fromAddress(dExtensions[I].extensionName));
    //}

    //
    const queueFamilyCount = new Uint32Array(1);
    V.vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, queueFamilyCount, null);
    const queueFamilyProperties = new V.VkQueueFamilyProperties(queueFamilyCount[0])
    V.vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, queueFamilyCount, queueFamilyProperties);

    //
    let queueIndex = -1;
    for (let I=0;I<queueFamilyCount[0];I++) {
        if (queueFamilyProperties[I].queueFlags & V.VK_QUEUE_GRAPHICS_BIT) {
            queueIndex = I; break;
        }
    }

    //
    const deviceRayQueryFeatures = new V.VkPhysicalDeviceRayQueryFeaturesKHR();
    const deviceAccelerationStructureFeaturs = new V.VkPhysicalDeviceAccelerationStructureFeaturesKHR({pNext: deviceRayQueryFeatures});
    const deviceFeatures11 = new V.VkPhysicalDeviceVulkan11Features({pNext: deviceAccelerationStructureFeaturs});
    const deviceFeatures12 = new V.VkPhysicalDeviceVulkan12Features({pNext: deviceFeatures11});
    const deviceFeatures13 = new V.VkPhysicalDeviceVulkan13Features({pNext: deviceFeatures12});
    const deviceFeatures = new V.VkPhysicalDeviceFeatures2({pNext: deviceFeatures13});
    const deviceProperties = new V.VkPhysicalDeviceProperties2();

    //
    V.vkGetPhysicalDeviceProperties2(physicalDevice, deviceProperties);
    V.vkGetPhysicalDeviceFeatures2(physicalDevice, deviceFeatures);

    //
    //console.log(deviceFeatures.features);

    // you can also hack and typecast members (californium bullets)
    //console.log(deviceFeatures.as("VkPhysicalDeviceFeatures", "features"));
    //console.log(deviceFeatures.as(V.VkPhysicalDeviceFeatures, "features"));

    // also, you can set or get uint32 values
    //console.log(deviceFeatures.as("u32[arr]")[0]);

    // or only to get uint32
    //console.log(deviceFeatures.as("u32"));

    // you construct struct from address
    //console.log(V.VkPhysicalDeviceFeatures.fromAddress(deviceFeatures.address()));

    //
    let presentModeCount = new Uint32Array(1);
    V.vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface[0], presentModeCount, null);
    let presentModes = new Int32Array(presentModeCount[0]);
    V.vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface[0], presentModeCount, presentModes);

    //
    const deviceQueueInfo = new V.VkDeviceQueueCreateInfo({
        queueFamilyIndex: 0,
        queueCount: 1,
        pQueuePriorities: new Float32Array([1.0, 1.0, 1.0, 1.0])
    });

    //
    const deviceLayers = [];
    const deviceExtensions = ["VK_KHR_swapchain", "VK_KHR_acceleration_structure", "VK_KHR_deferred_host_operations", "VK_KHR_ray_query"];
    const deviceInfo = new V.VkDeviceCreateInfo({
        pNext: deviceFeatures,
        queueCreateInfoCount: deviceQueueInfo.length,
        pQueueCreateInfos: deviceQueueInfo,
        enabledExtensionCount: deviceExtensions.length,
        ppEnabledExtensionNames: deviceExtensions
    });

    //
    const queue = new BigUint64Array(1);
    const device = new BigUint64Array(1);
    V.vkCreateDevice(physicalDevice, deviceInfo, null, device);
    V.vkGetDeviceQueue(device[0], 0, 0, queue);

    //
    const surfaceSupport = new Uint32Array([0]);
    V.vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, 0, surface[0], surfaceSupport);
    console.log("Surface Support By Physical Device: " + surfaceSupport);

    // TODO: native pointers support for GLFW
    let windowSize = new Uint32Array(2);
    V.glfwGetWindowSize(window, windowSize);

    //
    let swapchainInfo = new V.VkSwapchainCreateInfoKHR({
        sType: V.VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
        surface: surface[0],
        minImageCount: 3,
        imageFormat: V.VK_FORMAT_B8G8R8A8_UNORM,
        imageColorSpace: V.VK_COLOR_SPACE_SRGB_NONLINEAR_KHR,
        ["imageExtent:u32[2]"]: windowSize,
        imageArrayLayers: 1,
        imageUsage: V.VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | V.VK_IMAGE_USAGE_STORAGE_BIT,
        imageSharingMode: V.VK_SHARING_MODE_EXCLUSIVE,
        queueFamilyIndexCount: 1,
        pQueueFamilyIndices: new Uint32Array([0]),
        preTransform: V.VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR,
        compositeAlpha: V.VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
        presentMode: V.VK_PRESENT_MODE_FIFO_KHR,
        clipped: V.VK_TRUE,
        oldSwapchain: null,
    });

    //
    const imagePoolSize = new V.VkDescriptorPoolSize([{
        type: V.VK_DESCRIPTOR_TYPE_STORAGE_IMAGE,
        descriptorCount: 6
    }]);

    //
    const poolInfo = new V.VkDescriptorPoolCreateInfo({
        poolSizeCount: imagePoolSize.length,
        pPoolSizes: imagePoolSize,
        maxSets: 4
    });

    //
    const descriptorPool = new BigUint64Array(1);
    V.vkCreateDescriptorPool(device[0], poolInfo, null, descriptorPool);

    //
    const swapchain = new BigUint64Array(1);
    V.vkCreateSwapchainKHR(device[0], swapchainInfo, null, swapchain);

    //
    const amountOfImagesInSwapchain = new Uint32Array(1);
    V.vkGetSwapchainImagesKHR(device[0], swapchain[0], amountOfImagesInSwapchain, null);
    const swapchainImages = new BigUint64Array(amountOfImagesInSwapchain[0]);
    V.vkGetSwapchainImagesKHR(device[0], swapchain[0], amountOfImagesInSwapchain, swapchainImages);

    //
    let imageViewInfo = new V.VkImageViewCreateInfo({
        sType : V.VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
        viewType : V.VK_IMAGE_VIEW_TYPE_2D,
        format : V.VK_FORMAT_B8G8R8A8_UNORM,
        subresourceRange: { aspectMask: V.VK_IMAGE_ASPECT_COLOR_BIT, baseMipLevel: 0, levelCount: 1, baseArrayLayer: 0, layerCount: 1 },
    });

    // moooo, korovka...
    // use can use `set` operation for re-assign some structure parts
    // TODO: resolve address indexing problems
    const imageViews = new BigUint64Array(amountOfImagesInSwapchain[0]);
    for (let I=0;I<amountOfImagesInSwapchain[0];I++) {
        V.vkCreateImageView(device[0], imageViewInfo.set({image: swapchainImages[I]}), null, imageViews.addressOffsetOf(I)); // bit-tricky by device address
    }




    //
    const descriptorSetBindings = new V.VkDescriptorSetLayoutBinding([{
        binding: 0,
        descriptorType: V.VK_DESCRIPTOR_TYPE_STORAGE_IMAGE,
        descriptorCount: imageViews.length,
        stageFlags: V.VK_SHADER_STAGE_COMPUTE_BIT,
    }]);

    //
    const descriptorSetLayoutCreateInfo = new V.VkDescriptorSetLayoutCreateInfo({ bindingCount: 1, pBindings: descriptorSetBindings });
    const descriptorLayout = new BigUint64Array(1);
    V.vkCreateDescriptorSetLayout(device[0], descriptorSetLayoutCreateInfo, null, descriptorLayout);

    //
    const pConstRange = new V.VkPushConstantRange({ stageFlags: V.VK_SHADER_STAGE_COMPUTE_BIT, offset: 0, size: 16 });
    const pipelineLayoutInfo = new V.VkPipelineLayoutCreateInfo({
        setLayoutCount: descriptorLayout.length,
        pSetLayouts: descriptorLayout,
        pushConstantRangeCount: pConstRange.length,
        pPushConstantRanges: pConstRange
    });
    const pipelineLayout = new BigUint64Array(1);
    V.vkCreatePipelineLayout(device[0], pipelineLayoutInfo, null, pipelineLayout);

    // 
    const shaderStages = createShaderModuleInfo(createShaderModule(device[0], await fs.promises.readFile("shaders/triangle.comp.spv")), V.VK_SHADER_STAGE_COMPUTE_BIT);
    const computeCInfo = new V.VkComputePipelineCreateInfo({ stage: shaderStages, layout: pipelineLayout[0] });
    const computeShader = new BigUint64Array(1);
    V.vkCreateComputePipelines(device[0], 0n, computeCInfo.length, computeCInfo, null, computeShader);

    // 
    const allocInfo = new V.VkDescriptorSetAllocateInfo({
        descriptorPool: descriptorPool[0],
        descriptorSetCount: 1, 
        pSetLayouts: descriptorLayout
    });
    const descriptorSets = new BigUint64Array(1);
    V.vkAllocateDescriptorSets(device[0], allocInfo, descriptorSets);

    //
    const imageBinding = new V.VkDescriptorImageInfo(new Array(imageViews.length).fill({}).map((_, I)=>({
        imageView: imageViews[I],
        imageLayout: V.VK_IMAGE_LAYOUT_GENERAL
    })));

    //
    const writeDescriptorInfo = new V.VkWriteDescriptorSet({
        dstBinding: 0,
        dstSet: descriptorSets[0],
        descriptorCount: imageBinding.length,
        descriptorType: V.VK_DESCRIPTOR_TYPE_STORAGE_IMAGE,
        pImageInfo: imageBinding
    });

    //
    V.vkUpdateDescriptorSets(device[0], 1, writeDescriptorInfo, 0, null);

    //
    const viewport = new V.VkViewport({});
    viewport[":f32[6]"] = [0, 0, windowSize[0], windowSize[1], 0.0, 1.0];

    //
    const scissor = new V.VkRect2D({
        ["offset:u32[2]"]: [0,0],
        ["extent:u32[2]"]: windowSize
    });


    //
    const imageTransitionBarrierForPresent = new V.VkImageMemoryBarrier2(imageViews.length);
    const imageTransitionBarrierForGeneral = new V.VkImageMemoryBarrier2(imageViews.length);
    const imageTransitionBarrierFromUndefined = new V.VkImageMemoryBarrier2(imageViews.length);

    //
    for (let I=0;I<imageViews.length;I++) {
        //
        imageTransitionBarrierFromUndefined[I] = {
            srcStageMask: V.VK_PIPELINE_STAGE_2_NONE,
            srcAccessMask: V.VK_ACCESS_2_NONE,
            dstStageMask: V.VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
            dstAccessMask: V.VK_ACCESS_2_MEMORY_READ_BIT | V.VK_ACCESS_2_MEMORY_WRITE_BIT,
            oldLayout: V.VK_IMAGE_LAYOUT_UNDEFINED,
            newLayout: V.VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
            image: swapchainImages[I],
            subresourceRange: { aspectMask: V.VK_IMAGE_ASPECT_COLOR_BIT, baseMipLevel: 0, levelCount: 1, baseArrayLayer: 0, layerCount: 1 }
        };

        //
        imageTransitionBarrierForGeneral[I] = {
            srcStageMask: V.VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
            srcAccessMask: V.VK_ACCESS_2_MEMORY_READ_BIT | V.VK_ACCESS_2_MEMORY_WRITE_BIT,
            dstStageMask: V.VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
            dstAccessMask: V.VK_ACCESS_2_SHADER_WRITE_BIT | V.VK_ACCESS_2_SHADER_READ_BIT,
            oldLayout: V.VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
            newLayout: V.VK_IMAGE_LAYOUT_GENERAL,
            image: swapchainImages[I],
            subresourceRange: { aspectMask: V.VK_IMAGE_ASPECT_COLOR_BIT, baseMipLevel: 0, levelCount: 1, baseArrayLayer: 0, layerCount: 1 }
        };

        //
        imageTransitionBarrierForPresent[I] = {
            srcStageMask: V.VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
            srcAccessMask: V.VK_ACCESS_2_SHADER_WRITE_BIT | V.VK_ACCESS_2_SHADER_READ_BIT,
            dstStageMask: V.VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
            dstAccessMask: V.VK_ACCESS_2_MEMORY_READ_BIT | V.VK_ACCESS_2_MEMORY_WRITE_BIT,
            oldLayout: V.VK_IMAGE_LAYOUT_GENERAL,
            newLayout: V.VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
            image: swapchainImages[I],
            subresourceRange: { aspectMask: V.VK_IMAGE_ASPECT_COLOR_BIT, baseMipLevel: 0, levelCount: 1, baseArrayLayer: 0, layerCount: 1 }
        };
    }

    //
    const cmdPool = new BigUint64Array(1);
    V.vkCreateCommandPool(device[0], new V.VkCommandPoolCreateInfo({
        pNext: null,
        queueFamilyIndex: 0
    }), null, cmdPool);

    //
    const bottomLevelAS = new BigUint64Array(1);
    const topLevelAS = new BigUint64Array(1);

    //
    const cmdBufferAllocInfo = new V.VkCommandBufferAllocateInfo({
        commandPool: cmdPool[0],
        level: V.VK_COMMAND_BUFFER_LEVEL_PRIMARY,
        commandBufferCount: amountOfImagesInSwapchain[0]
    });

    //
    const vertexBuffer = createVertexBuffer(device[0], vertices);
    const lwAsGeometryInfo = new V.VkAccelerationStructureGeometryKHR({
        flags: V.VK_GEOMETRY_OPAQUE_BIT_KHR,
        geometryType: V.VK_GEOMETRY_TYPE_TRIANGLES_KHR,
        ["geometry:VkAccelerationStructureGeometryTrianglesDataKHR"]: {
            sType: V.VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR,
            vertexData: getBufferDeviceAddress(device[0], vertexBuffer),
            indexData: 0n,
            vertexFormat: V.VK_FORMAT_R32G32_SFLOAT,
            maxVertex: 3,
            vertexStride: 8,
            indexType: V.VK_INDEX_TYPE_NONE_KHR,
        }
    });

    //
    const asBuildSizeGeometryInfo = new V.VkAccelerationStructureBuildGeometryInfoKHR({
        type: V.VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR,
        flags: V.VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR,
        geometryCount: 1,
        pGeometries: lwAsGeometryInfo
    });

    // 
    const primitiveCount = new Uint32Array([1]);
    const asBuildSizesInfo = new V.VkAccelerationStructureBuildSizesInfoKHR({});
    V.vkGetAccelerationStructureBuildSizesKHR(device[0], V.VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR, asBuildSizeGeometryInfo, primitiveCount, asBuildSizesInfo);
    
    //
    const lwBuffer = createTypedBuffer(device[0], V.VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR | V.VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT, asBuildSizesInfo.accelerationStructureSize);
    const lwBufferBarrier = new V.VkBufferMemoryBarrier2({
        srcStageMask: V.VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
        srcAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR,
        dstStageMask: V.VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
        dstAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR | V.VK_ACCESS_2_SHADER_READ_BIT,
        srcQueueFamilyIndex: 0,
        dstQueueFamilyIndex: 0,
        $buffer: lwBuffer,
        offset: 0,
        size: asBuildSizesInfo.accelerationStructureSize
    });

    //
    V.vkCreateAccelerationStructureKHR(device[0], new V.VkAccelerationStructureCreateInfoKHR({
        $buffer: lwBuffer,
        size: asBuildSizesInfo.accelerationStructureSize,
        type: V.VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR
    }), null, bottomLevelAS);

    //
    const lwScratchMemory = createTypedBuffer(device[0], V.VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | V.VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR | V.VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT, asBuildSizesInfo.buildScratchSize);
    const lwScratchBarrier = new V.VkBufferMemoryBarrier2({
        srcStageMask: V.VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
        srcAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR,
        dstStageMask: V.VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT | V.VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
        dstAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR | V.VK_ACCESS_2_SHADER_READ_BIT | V.VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR,
        srcQueueFamilyIndex: 0,
        dstQueueFamilyIndex: 0,
        $buffer: lwScratchMemory,
        offset: 0,
        size: asBuildSizesInfo.buildScratchSize
    });

    //
    const instances = new V.VkAccelerationStructureInstanceKHR(1);
    instances[0] = {
        instanceCustomIndex: 0,
        mask: 0xFF,
        instanceShaderBindingTableRecordOffset: 0,
        flags: 0,
        accelerationStructureReference: getAcceelerationStructureAddress(device[0], bottomLevelAS[0])
    };

    //
    const instanceBuffer = createInstanceBuffer(device[0], instances);
    const tpAsInstanceInfo = new V.VkAccelerationStructureGeometryKHR({
        flags: V.VK_GEOMETRY_OPAQUE_BIT_KHR,
        geometryType: V.VK_GEOMETRY_TYPE_INSTANCES_KHR,
        ["geometry:VkAccelerationStructureGeometryInstancesDataKHR"]: {
            sType: V.VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR,
            arrayOfPointers: false,
            data: getBufferDeviceAddress(device[0], instanceBuffer)
        }
    });

    //
    asBuildSizeGeometryInfo[""] = {
        type: V.VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR,
        flags: V.VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR,
        geometryCount: 1,
        pGeometries: tpAsInstanceInfo
    };

    // 
    V.vkGetAccelerationStructureBuildSizesKHR(device[0], V.VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR, asBuildSizeGeometryInfo, primitiveCount, asBuildSizesInfo);

    //
    const tpBuffer = createTypedBuffer(device[0], V.VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR | V.VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT, asBuildSizesInfo.accelerationStructureSize);
    const tpBufferBarrier = new V.VkBufferMemoryBarrier2({
        srcStageMask: V.VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
        srcAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR | V.VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR,
        dstStageMask: V.VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
        dstAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR | V.VK_ACCESS_2_SHADER_READ_BIT,
        srcQueueFamilyIndex: 0,
        dstQueueFamilyIndex: 0,
        $buffer: tpBuffer,
        offset: 0,
        size: asBuildSizesInfo.accelerationStructureSize
    });

    //
    V.vkCreateAccelerationStructureKHR(device[0], new V.VkAccelerationStructureCreateInfoKHR({
        $buffer: tpBuffer,
        size: asBuildSizesInfo.accelerationStructureSize,
        type: V.VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR
    }), null, topLevelAS);

    //
    const tpScratchMemory = createTypedBuffer(device[0], V.VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | V.VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR | V.VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT, asBuildSizesInfo.buildScratchSize);
    const tpScratchBarrier = new V.VkBufferMemoryBarrier2({
        srcStageMask: V.VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
        srcAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR,
        dstStageMask: V.VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
        dstAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR | V.VK_ACCESS_2_SHADER_READ_BIT,
        srcQueueFamilyIndex: 0,
        dstQueueFamilyIndex: 0,
        $buffer: tpScratchMemory,
        offset: 0,
        size: asBuildSizesInfo.buildScratchSize
    });

    //
    const lwBufferBarriers = new V.VkBufferMemoryBarrier2(2);
    const tpBufferBarriers = new V.VkBufferMemoryBarrier2(2);
    lwBufferBarriers[0] = lwBufferBarrier;
    lwBufferBarriers[1] = lwScratchBarrier;
    tpBufferBarriers[0] = tpBufferBarrier;
    tpBufferBarriers[1] = tpScratchBarrier;


    //
    const lwAsBuildGeometryInfo = new V.VkAccelerationStructureBuildGeometryInfoKHR({
        type: V.VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR,
        flags: V.VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR,
        mode: V.VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR,
        dstAccelerationStructure: bottomLevelAS[0],
        geometryCount: 1,
        pGeometries: lwAsGeometryInfo,
        scratchData: getBufferDeviceAddress(device[0], lwScratchMemory)
    });

    //
    const lwAsBuildRangeInfo = new V.VkAccelerationStructureBuildRangeInfoKHR([{
        primitiveCount: 1,
        primitiveOffset: 0,
        firstVertex: 0,
        transformOffset: 0
    }]);

    //
    const tpAsBuildGeometryInfo = new V.VkAccelerationStructureBuildGeometryInfoKHR({
        type: V.VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR,
        flags: V.VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR,
        mode: V.VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR,
        dstAccelerationStructure: topLevelAS[0],
        geometryCount: 1,
        pGeometries: tpAsInstanceInfo,
        scratchData: getBufferDeviceAddress(device[0], tpScratchMemory)
    });

    //
    const tpAsBuildRangeInfo = new V.VkAccelerationStructureBuildRangeInfoKHR([{
        primitiveCount: 1,
        primitiveOffset: 0,
        firstVertex: 0,
        transformOffset: 0
    }]);

    //
    const lwAsBuildRangeInfoPtr = new BigUint64Array([ lwAsBuildRangeInfo.address() ]);
    const tpAsBuildRangeInfoPtr = new BigUint64Array([ tpAsBuildRangeInfo.address() ]);

    // single time command
    let cmdBuf = new BigUint64Array(1);
    V.vkAllocateCommandBuffers(device[0], new V.VkCommandBufferAllocateInfo({ commandPool: cmdPool[0], level: V.VK_COMMAND_BUFFER_LEVEL_PRIMARY, commandBufferCount: cmdBuf.length }), cmdBuf);
    V.vkBeginCommandBuffer(cmdBuf[0], new V.VkCommandBufferBeginInfo({ flags: V.VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT }));
    V.vkCmdBuildAccelerationStructuresKHR(cmdBuf[0], 1, lwAsBuildGeometryInfo, lwAsBuildRangeInfoPtr);
    V.vkCmdPipelineBarrier2(cmdBuf[0], new V.VkDependencyInfoKHR({ bufferMemoryBarrierCount: lwBufferBarriers.length, pBufferMemoryBarriers: lwBufferBarriers }));
    V.vkCmdBuildAccelerationStructuresKHR(cmdBuf[0], 1, tpAsBuildGeometryInfo, tpAsBuildRangeInfoPtr);
    V.vkCmdPipelineBarrier2(cmdBuf[0], new V.VkDependencyInfoKHR({ bufferMemoryBarrierCount: tpBufferBarriers.length, pBufferMemoryBarriers: tpBufferBarriers }));
    V.vkCmdPipelineBarrier2(cmdBuf[0], new V.VkDependencyInfoKHR({ imageMemoryBarrierCount: imageTransitionBarrierFromUndefined.length, pImageMemoryBarriers: imageTransitionBarrierFromUndefined }));
    V.vkEndCommandBuffer(cmdBuf[0]);
    V.vkQueueSubmit(queue[0], 1, new V.VkSubmitInfo({ commandBufferCount: cmdBuf.length, pCommandBuffers: cmdBuf }), 0n);

    //
    const cmdBuffers = new BigUint64Array(amountOfImagesInSwapchain[0]);
    V.vkAllocateCommandBuffers(device[0], cmdBufferAllocInfo, cmdBuffers);

    //
    for (let I = 0; I < cmdBuffers.length; ++I) {
        const AB = new ArrayBuffer(16);
        const U64 = new BigUint64Array(AB, 0, 1);
        const U32 = new Uint32Array(AB, 8, 1);

        U64[0] = getAcceelerationStructureAddress(device[0], topLevelAS[0]);
        U32[0] = I;

        const cmdBuffer = cmdBuffers[I];
        V.vkBeginCommandBuffer(cmdBuffer, new V.VkCommandBufferBeginInfo({ flags: V.VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT }));
        V.vkCmdPipelineBarrier2(cmdBuffer, new V.VkDependencyInfoKHR({ imageMemoryBarrierCount: 1, pImageMemoryBarriers: imageTransitionBarrierForGeneral.addressOffsetOf(I) }));
        V.vkCmdPushConstants(cmdBuffer, pipelineLayout[0], V.VK_SHADER_STAGE_COMPUTE_BIT, 0, 16, AB);
        V.vkCmdBindDescriptorSets(cmdBuffer, V.VK_PIPELINE_BIND_POINT_COMPUTE, pipelineLayout[0], 0, descriptorSets.length, descriptorSets, 0, 0n);
        V.vkCmdBindPipeline(cmdBuffer, V.VK_PIPELINE_BIND_POINT_COMPUTE, computeShader[0]);
        V.vkCmdDispatch(cmdBuffer, 1280/32, 720/4, 1);
        V.vkCmdPipelineBarrier2(cmdBuffer, new V.VkDependencyInfoKHR({ imageMemoryBarrierCount: 1, pImageMemoryBarriers: imageTransitionBarrierForPresent.addressOffsetOf(I) }));
        V.vkEndCommandBuffer(cmdBuffer);
    };

    //
    const semaphoreInfo = new V.VkSemaphoreCreateInfo({});
    const semaphoreImageAvailable = new BigUint64Array(1); 
    const semaphoreRenderingAvailable = new BigUint64Array(1);
    const fence = new BigUint64Array(amountOfImagesInSwapchain[0]);

    //
    for (let I=0;I<amountOfImagesInSwapchain[0];I++) {
        V.vkCreateFence(device[0], new V.VkFenceCreateInfo({ flags: V.VK_FENCE_CREATE_SIGNALED_BIT }), null, fence.addressOffsetOf(I));
    }
    V.vkCreateSemaphore(device[0], semaphoreInfo, null, semaphoreImageAvailable);
    V.vkCreateSemaphore(device[0], semaphoreInfo, null, semaphoreRenderingAvailable);

    //
    let terminated = false;

    // 
    const waitStageMask = new Int32Array([ V.VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT ]);
    const imageIndex = new Uint32Array(1);

    //
    const awaitTick = ()=> new Promise(setImmediate);
    const makeState = (promise)=>{
        const state_ = { status: 'pending' };
        promise.then(()=>{state_.status="ready"; return awaitTick();});
        promise.catch(()=>{state_.status="reject"; });
        return new Proxy(promise, {
            get(target, prop) {
                if (target instanceof Promise) {
                    if (prop == "status") {
                        return state_[prop];
                    } else {
                        return target[prop].bind(target);
                    }
                }
            }
        });
    }

    // await fence while async ops
    //const awaitFenceAsync = async(device, fence) => {
    const awaitFenceAsync = async function*(device, fence) {
        let status = V.VK_NOT_READY;
        do {
            await awaitTick(); yield status;
            if (status == V.VK_ERROR_DEVICE_LOST) { throw Error("Vulkan Device Lost"); break; };
            if (status != V.VK_NOT_READY) break;
        } while((status = V.vkGetFenceStatus(device, fence)) != V.VK_SUCCESS);
        return status;
    };

    // async are NOT trivially terminatable!
    // generators can be simply terminated...
    //const renderGen = async() => {
    const renderGen = async function*() {
        V.vkAcquireNextImageKHR(device[0], swapchain[0], BigInt(Number.MAX_SAFE_INTEGER), semaphoreImageAvailable[0], 0n, imageIndex);

        // await fence before rendering (and poll events)
        //await awaitFenceAsync(device[0], fence[imageIndex[0]]);
        for await (let R of awaitFenceAsync(device[0], fence[imageIndex[0]])) { yield R; };

        //
        const submitInfo = new V.VkSubmitInfo({
            waitSemaphoreCount: 1,
            pWaitSemaphores: semaphoreImageAvailable,
            pWaitDstStageMask: waitStageMask,
            commandBufferCount: 1,
            pCommandBuffers: cmdBuffers.addressOffsetOf(imageIndex[0]),
            signalSemaphoreCount: 1,
            pSignalSemaphores: semaphoreRenderingAvailable,
        });

        //
        V.vkResetFences(device[0], 1, fence.addressOffsetOf(imageIndex[0]));
        V.vkQueueSubmit(queue[0], 1, submitInfo, fence[imageIndex[0]]);
        V.vkQueuePresentKHR(queue[0], new V.VkPresentInfoKHR({
            waitSemaphoreCount: 1,
            pWaitSemaphores: semaphoreRenderingAvailable,
            swapchainCount: 1,
            pSwapchains: swapchain,
            pImageIndices: imageIndex,
            pResults: null,
        }));

        //
        //console.log("Is Rendering!");

        //
        return V.VK_SUCCESS;
    }

    //
    let renderer = null, iterator = null;
    let status = V.VK_NOT_READY;

    //
    console.log("Begin rendering...");
    while (!V.glfwWindowShouldClose(window) && !terminated) {
        V.glfwPollEvents();
        //await awaitTick(); // crap, it's needed for async!

        // as you can see, async isn't so async
        //if (!renderer || renderer.status == "ready") { renderer = makeState(renderGen()); };
        if (!renderer || iterator.done) { renderer = renderGen(); };
        iterator = await renderer.next();
    };

    // 
    V.glfwTerminate();

})();
