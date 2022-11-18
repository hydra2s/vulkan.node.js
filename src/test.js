(async()=>{
    let vulkan = (await import("./vulkan-API.js")).default;
    let structs = (await import("./vulkan-structs.js")).default;
    let enums = (await import("./vulkan-enums.js")).default;

    let appInfo = structs.VkApplicationInfo.encode({
        sType: enums.VK_STRUCTURE_TYPE_APPLICATION_INFO,
        pNext: 0n,
        pApplicationName: "NVAPI TEST".charAddress(),
        applicationVersion: structs.VK_MAKE_API_VERSION(0, 1, 3, 234),
        pEngineName: "NVAPI".charAddress(),
        engineVersion: structs.VK_MAKE_API_VERSION(0, 1, 3, 234),
        apiVersion: structs.VK_MAKE_API_VERSION(0, 1, 3, 234)
    });

    console.log(appInfo);

    let pInfo = structs.VkInstanceCreateInfo.encode({
        sType: enums.VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        pNext: 0n,
        pApplicationInfo: appInfo.address(),
        enabledLayerCount: 0,
        ppEnabledLayerNames: 0n,
        enabledExtensionCount: 0,
        ppEnabledExtensionNames: 0n
    });

    let handle = new BigUint64Array(1);
    vulkan.vkCreateInstance(pInfo.address(), 0n, handle.address());
    
    console.log(handle[0]);

    console.log(vulkan.vkGetStructureSizeBySType(1));
    
})();
