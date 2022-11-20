(async()=>{
    //
    const V = (await import("./index.js")).default;

    //
    let rect2D = new V.VkRect2D();

    //
    let appInfo = new V.VkApplicationInfo({
        pNext: 0n,
        pApplicationName: "NVAPI TEST",
        applicationVersion: V.VK_MAKE_API_VERSION(0, 1, 3, 234),
        pEngineName: "NVAPI",
        engineVersion: V.VK_MAKE_API_VERSION(0, 1, 3, 234),
        apiVersion: V.VK_MAKE_API_VERSION(0, 1, 3, 234)
    });

    //
    let extensions = [];
    let layers = ["VK_LAYER_KHRONOS_validation"];

    //
    let pInfo = new V.VkInstanceCreateInfo({
        pNext: 0n,
        flags: 0,
        pApplicationInfo: appInfo,
        enabledLayerCount: layers.length,
        ppEnabledLayerNames: layers,
        enabledExtensionCount: extensions.length,
        ppEnabledExtensionNames: extensions
    });

    let instance = new BigUint64Array(1);
    V.vkCreateInstance(pInfo, 0n, instance);

    //console.log(instance);
    
    //await new Promise((r)=>{ setTimeout(r, 10000); });
    
    let deviceCount = new Uint32Array(1);
    let result = V.vkEnumeratePhysicalDevices(instance[0], deviceCount, 0n);
    //console.log(deviceCount);
    
    if (deviceCount <= 0) console.error("Error: No render devices available!");
    let devices = new BigUint64Array(deviceCount[0]);
    result = V.vkEnumeratePhysicalDevices(instance[0], deviceCount, devices);
    //console.log(devices);

    //
    let dExtensionCount = new Uint32Array(1);
    V.vkEnumerateDeviceExtensionProperties(devices[0], "", dExtensionCount, 0n);
    
    let dExtensions = new Uint8Array(dExtensionCount[0]*V.VkExtensionProperties.sizeof);
    V.vkEnumerateDeviceExtensionProperties(devices[0], "", dExtensionCount, dExtensions);

    for (let I=0;I<dExtensionCount[0];I++) {
        let property = new V.VkExtensionProperties(dExtensions, I*V.VkExtensionProperties.sizeof, V.VkExtensionProperties.sizeof);
        let string = String.fromAddress(property.extensionName);
        console.log(string);
    }
    
})();
