import { default as C } from "struct-buffer";
import { default as S } from "./vulkan-structs.js";
import { default as E } from "./vulkan-enums.js";
import { default as V } from "./vulkan-API.js";
import { default as M } from "./typed.js";

(async()=>{
    
    let rect2D = S.VkRect2D.construct();

    //
    let appInfo = S.VkApplicationInfo.construct({
        sType: E.VK_STRUCTURE_TYPE_APPLICATION_INFO,
        pNext: 0n,
        pApplicationName: "NVAPI TEST",
        applicationVersion: S.VK_MAKE_API_VERSION(0, 1, 3, 234),
        pEngineName: "NVAPI",
        engineVersion: S.VK_MAKE_API_VERSION(0, 1, 3, 234),
        apiVersion: S.VK_MAKE_API_VERSION(0, 1, 3, 234)
    });

    //
    let layer = "VK_LAYER_KHRONOS_validation";
    let extensions = new BigUint64Array([  ]);
    let layers = new BigUint64Array([ layer.charAddress() ]);

    let pInfo = S.VkInstanceCreateInfo.construct({
        sType: E.VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        pNext: 0n,
        flags: 0,
        pApplicationInfo: appInfo,
        enabledLayerCount: layers.length,
        ppEnabledLayerNames: layers,
        enabledExtensionCount: 0,
        ppEnabledExtensionNames: 0n
    });

    let handle = new BigUint64Array(1);
    V.vkCreateInstance(pInfo, 0n, handle);
    
    console.log(handle);
})();
