import { default as V } from "./index.js";

(async()=>{

    //
    let rect2D = new V.VkRect2D();

    //
    let appInfo = new V.VkApplicationInfo({
        sType: V.VK_STRUCTURE_TYPE_APPLICATION_INFO,
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
        sType: V.VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        pNext: 0n,
        flags: 0,
        pApplicationInfo: appInfo,
        enabledLayerCount: layers.length,
        ppEnabledLayerNames: layers,
        enabledExtensionCount: extensions.length,
        ppEnabledExtensionNames: extensions
    });

    let handle = new BigUint64Array(1);
    V.vkCreateInstance(pInfo, 0n, handle);

    console.log(handle);
})();
