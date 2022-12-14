(async()=>{

    //
    const V = (await import("../../index.js")).default;
    const L = (await import("../library/index.js")).default;
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
    const deviceFeatures11 = new V.VkPhysicalDeviceVulkan11Features();
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
    const deviceExtensions = ["VK_KHR_swapchain"];
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
        imageUsage: V.VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
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

    // TODO: better construction!!
    const shaderStages = new V.VkPipelineShaderStageCreateInfo(2);
    shaderStages[0] = L.createShaderModuleInfo(L.createShaderModule(device[0], await fs.promises.readFile("shaders/triangle.vert.spv")), V.VK_SHADER_STAGE_VERTEX_BIT);
    shaderStages[1] = L.createShaderModuleInfo(L.createShaderModule(device[0], await fs.promises.readFile("shaders/triangle.frag.spv")), V.VK_SHADER_STAGE_FRAGMENT_BIT);

    //
    const vertexInputInfo = new V.VkPipelineVertexInputStateCreateInfo({
        vertexBindingDescriptionCount: 1,
        pVertexBindingDescriptions: posVertexBindingDescr,
        vertexAttributeDescriptionCount: 1,
        pVertexAttributeDescriptions: posVertexAttrDescr
    });

    //
    const inputAssemblyStateInfo = new V.VkPipelineInputAssemblyStateCreateInfo({
        topology: V.VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,
        primitiveRestartEnable: false
    });

    //
    const viewport = new V.VkViewport({
        //x: 0, y: 0, width: windowSize[0], height: windowSize[1], minDepth: 0.0, maxDepth: 1.0
    });
    viewport[":f32[6]"] = [0, 0, windowSize[0], windowSize[1], 0.0, 1.0];

    //
    const scissor = new V.VkRect2D({
        ["offset:u32[2]"]: [0,0],
        ["extent:u32[2]"]: windowSize
    });

    //
    const viewportStateInfo = new V.VkPipelineViewportStateCreateInfo({
        viewportCount: 1,
        pViewports: viewport,
        scissorCount: 1,
        pScissors: scissor
    });

    //
    const rasterizationInfo = new V.VkPipelineRasterizationStateCreateInfo({
        depthClampEnable: false,
        rasterizerDiscardEnable: false,
        polygonMode: V.VK_POLYGON_MODE_FILL,
        cullMode: V.VK_CULL_MODE_NONE ,
        frontFace: V.VK_FRONT_FACE_CLOCKWISE,
        depthBiasEnable: false,
        depthBiasConstantFactor: 0.0,
        depthBiasClamp: 0.0,
        depthBiasSlopeFactor: 0.0,
        lineWidth: 1.0,
    });

    //
    const multisampleInfo = new V.VkPipelineMultisampleStateCreateInfo({
        rasterizationSamples: V.VK_SAMPLE_COUNT_1_BIT,
        minSampleShading: 1.0,
        pSampleMask: null,
        alphaToCoverageEnable: false,
        alphaToOneEnable: false,
    });

    //
    const colorBlendAttachment = new V.VkPipelineColorBlendAttachmentState({
        blendEnable: true,
        srcColorBlendFactor: V.VK_BLEND_FACTOR_SRC_ALPHA,
        dstColorBlendFactor: V.VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
        colorBlendOp: V.VK_BLEND_OP_ADD,
        srcAlphaBlendFactor: V.VK_BLEND_FACTOR_ONE,
        dstAlphaBlendFactor: V.VK_BLEND_FACTOR_ZERO,
        alphaBlendOp: V.VK_BLEND_OP_ADD,
        colorWriteMask: (
            V.VK_COLOR_COMPONENT_R_BIT |
            V.VK_COLOR_COMPONENT_G_BIT |
            V.VK_COLOR_COMPONENT_B_BIT |
            V.VK_COLOR_COMPONENT_A_BIT
        )
    });

    //
    const colorBlendInfo = new V.VkPipelineColorBlendStateCreateInfo({
        logicOpEnable: false,
        logicOp: V.VK_LOGIC_OP_NO_OP,
        attachmentCount: 1,
        pAttachments: colorBlendAttachment,
        blendConstants: [0.0, 0.0, 0.0, 0.0]
    });

    //
    const pipelineLayoutInfo = new V.VkPipelineLayoutCreateInfo({
        setLayoutCount: 0,
        pushConstantRangeCount: 0
    });

    //
    const pipelineLayout = new BigUint64Array(1);
    V.vkCreatePipelineLayout(device[0], pipelineLayoutInfo, null, pipelineLayout);

    //
    const attachmentFormats = new Uint32Array([V.VK_FORMAT_B8G8R8A8_UNORM]);
    const dynamicRenderingPipelineInfo = new V.VkPipelineRenderingCreateInfoKHR({
        colorAttachmentCount: attachmentFormats.length,
        pColorAttachmentFormats: attachmentFormats
    });

    //
    const graphicsPipelineInfo = new V.VkGraphicsPipelineCreateInfo({
        pNext: dynamicRenderingPipelineInfo,
        stageCount: shaderStages.length,
        pStages: shaderStages,
        pVertexInputState: vertexInputInfo,
        pInputAssemblyState: inputAssemblyStateInfo,
        pTessellationState: null,
        pViewportState: viewportStateInfo,
        pRasterizationState: rasterizationInfo,
        pMultisampleState: multisampleInfo,
        pDepthStencilState: null,
        pColorBlendState: colorBlendInfo,
        pDynamicState: null,
        layout: pipelineLayout[0],
        subpass: 0,
        basePipelineHandle: null,
        basePipelineIndex: -1,
    });

    //
    const pipeline = new BigUint64Array(1);
    V.vkCreateGraphicsPipelines(device[0], 0n, 1, graphicsPipelineInfo, null, pipeline);

    //
    const imageTransitionBarrierForPresent = new V.VkImageMemoryBarrier2(imageViews.length);
    const imageTransitionBarrierForGeneral = new V.VkImageMemoryBarrier2(imageViews.length);
    const imageTransitionBarrierFromUndefined = new V.VkImageMemoryBarrier2(imageViews.length);

    //
    const dynamicRenderingInfo = new V.VkRenderingAttachmentInfo(imageViews.length);
    for (let I=0;I<imageViews.length;I++) {
        // I remember you: we assign partially!
        dynamicRenderingInfo[I] = {
            imageView: imageViews[I],
            imageLayout: V.VK_IMAGE_LAYOUT_GENERAL,
            loadOp: V.VK_ATTACHMENT_LOAD_OP_CLEAR,
            storeOp: V.VK_ATTACHMENT_STORE_OP_STORE,
            "clearValue:f32[4]": [0.0, 0.0, 0.0, 0.0] 
        };

        //
        imageTransitionBarrierFromUndefined[I] = {
            srcStageMask: V.VK_PIPELINE_STAGE_2_NONE,
            srcAccessMask: V.VK_ACCESS_2_NONE,
            dstStageMask: V.VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT,
            dstAccessMask: V.VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT | V.VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT,
            oldLayout: V.VK_IMAGE_LAYOUT_UNDEFINED,
            newLayout: V.VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
            image: swapchainImages[I],
            subresourceRange: { aspectMask: V.VK_IMAGE_ASPECT_COLOR_BIT, baseMipLevel: 0, levelCount: 1, baseArrayLayer: 0, layerCount: 1 }
        };

        //
        imageTransitionBarrierForGeneral[I] = {
            srcStageMask: V.VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT,
            srcAccessMask: V.VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT | V.VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT,
            dstStageMask: V.VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT,
            dstAccessMask: V.VK_ACCESS_2_SHADER_WRITE_BIT | V.VK_ACCESS_2_SHADER_READ_BIT,
            oldLayout: V.VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
            newLayout: V.VK_IMAGE_LAYOUT_GENERAL,
            image: swapchainImages[I],
            subresourceRange: { aspectMask: V.VK_IMAGE_ASPECT_COLOR_BIT, baseMipLevel: 0, levelCount: 1, baseArrayLayer: 0, layerCount: 1 }
        };

        //
        imageTransitionBarrierForPresent[I] = {
            srcStageMask: V.VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT,
            srcAccessMask: V.VK_ACCESS_2_SHADER_WRITE_BIT | V.VK_ACCESS_2_SHADER_READ_BIT,
            dstStageMask: V.VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT,
            dstAccessMask: V.VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT | V.VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT,
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

    // single time command
    let cmdBuf = new BigUint64Array(1);
    V.vkAllocateCommandBuffers(device[0], new V.VkCommandBufferAllocateInfo({ commandPool: cmdPool[0], level: V.VK_COMMAND_BUFFER_LEVEL_PRIMARY, commandBufferCount: cmdBuf.length }), cmdBuf);
    V.vkBeginCommandBuffer(cmdBuf[0], new V.VkCommandBufferBeginInfo({ flags: V.VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT }));
    V.vkCmdPipelineBarrier2(cmdBuf[0], new V.VkDependencyInfoKHR({ imageMemoryBarrierCount: imageTransitionBarrierFromUndefined.length, pImageMemoryBarriers: imageTransitionBarrierFromUndefined }));
    V.vkEndCommandBuffer(cmdBuf[0]);
    V.vkQueueSubmit(queue[0], 1, new V.VkSubmitInfo({ commandBufferCount: cmdBuf.length, pCommandBuffers: cmdBuf }), 0n);

    //
    const cmdBufferAllocInfo = new V.VkCommandBufferAllocateInfo({
        commandPool: cmdPool[0],
        level: V.VK_COMMAND_BUFFER_LEVEL_PRIMARY,
        commandBufferCount: amountOfImagesInSwapchain[0]
    });

    //
    const cmdBuffers = new BigUint64Array(amountOfImagesInSwapchain[0]);
    const vertexBuffer = L.createVertexBuffer(physicalDevice, device[0], vertices);
    V.vkAllocateCommandBuffers(device[0], cmdBufferAllocInfo, cmdBuffers);

    //
    for (let I = 0; I < cmdBuffers.length; ++I) {
        const cmdBuffer = cmdBuffers[I];
        V.vkBeginCommandBuffer(cmdBuffer, new V.VkCommandBufferBeginInfo({ flags: V.VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT }));
        V.vkCmdPipelineBarrier2(cmdBuffer, new V.VkDependencyInfoKHR({ imageMemoryBarrierCount: 1, pImageMemoryBarriers: imageTransitionBarrierForGeneral.addressOffsetOf(I) }));
        V.vkCmdBeginRendering(cmdBuffer, new V.VkRenderingInfoKHR({ renderArea: { ["offset:u32[2]"]: [0,0], ["extent:u32[2]"]: windowSize }, layerCount: 1, viewMask: 0x0, colorAttachmentCount: 1, pColorAttachments: dynamicRenderingInfo.addressOffsetOf(I) }));
        V.vkCmdBindPipeline(cmdBuffer, V.VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline[0]);
        V.vkCmdBindVertexBuffers(cmdBuffer, 0, 1, new BigUint64Array([vertexBuffer]), new BigUint64Array([0n]));
        V.vkCmdDraw(cmdBuffer, 3, 1, 0, 0);
        V.vkCmdEndRendering(cmdBuffer);
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

    // await fence while async ops
    //const awaitFenceAsync = async(device, fence) => {
    

    // async are NOT trivially terminatable!
    // generators can be simply terminated...
    //const renderGen = async() => {
    const renderGen = async function*() {
        V.vkAcquireNextImageKHR(device[0], swapchain[0], BigInt(Number.MAX_SAFE_INTEGER), semaphoreImageAvailable[0], 0n, imageIndex);

        // await fence before rendering (and poll events)
        //await awaitFenceAsync(device[0], fence[imageIndex[0]]);
        for await (let R of L.awaitFenceAsync(device[0], fence[imageIndex[0]])) { yield R; };

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
