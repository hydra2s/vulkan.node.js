(async()=>{
    let vulkan = (await import("./vulkan-API.js")).default;
    let structs = (await import("./vulkan-structs.js")).default;
    
    let VK_MAKE_API_VERSION = (variant, major, minor, patch) => {
        return ((((variant)) << 29) | (((major)) << 22) | (((minor)) << 12) | ((patch)));
    };

    let appInfo = structs.VkApplicationInfo.encode({
        sType: 0,
        pNext: 0n,
        pApplicationName: 0n,
        applicationVersion: VK_MAKE_API_VERSION(0, 1, 3, 234),
        pEngineName: 0n,
        engineVersion: VK_MAKE_API_VERSION(0, 1, 3, 234),
        apiVersion: VK_MAKE_API_VERSION(0, 1, 3, 234)
    });

    console.log(appInfo);

    let pInfo = structs.VkInstanceCreateInfo.encode({
        sType: 1,
        pNext: 0n,
        pApplicationInfo: appInfo.buffer.address(),
        enabledLayerCount: 0,
        ppEnabledLayerNames: 0n,
        enabledExtensionCount: 0,
        ppEnabledExtensionNames: 0n
    });

    let handle = new BigUint64Array(1);
    vulkan.vkCreateInstance(pInfo.buffer.address(), 0n, handle.address());
    
    console.log(handle[0]);

    console.log(vulkan.vkGetStructureSizeBySType(1));
    
})();
