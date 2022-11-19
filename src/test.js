import * as T from "struct-buffer";
import { default as S } from "./vulkan-structs.js";
import { default as V } from "./vulkan-API.js";
 //V.VkRect2D_extent_offsetof

import { default as M } from "./typed.js";
const C = T.default;
(async()=>{
    
    let rect2D = S.VkRect2D.construct();

    let vulkan = (await import("./vulkan-API.js")).default;
    let structs = (await import("./vulkan-structs.js")).default;
    let enums = (await import("./vulkan-enums.js")).default;

    console.log(String.fromAddress("NVAPI TEST".charAddress()));

    //
    let appInfo = S.VkApplicationInfo.construct({
        sType: enums.VK_STRUCTURE_TYPE_APPLICATION_INFO,
        pNext: 0n,
        pApplicationName: "NVAPI TEST".charAddress(),
        applicationVersion: structs.VK_MAKE_API_VERSION(0, 1, 3, 234),
        pEngineName: "NVAPI".charAddress(),
        engineVersion: structs.VK_MAKE_API_VERSION(0, 1, 3, 234),
        apiVersion: structs.VK_MAKE_API_VERSION(0, 1, 3, 234)
    });

    //
    let layer = "VK_LAYER_KHRONOS_validation";
    let extensions = new BigUint64Array([  ]);
    let layers = new BigUint64Array([ layer.charAddress() ]);

    let pInfo = S.VkInstanceCreateInfo.construct({
        sType: enums.VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        pNext: 0n,
        flags: 0,
        pApplicationInfo: appInfo.address(),
        enabledLayerCount: layers.length,
        ppEnabledLayerNames: layers.address(),
        enabledExtensionCount: 0,
        ppEnabledExtensionNames: 0n
    });

    let handle = new BigUint64Array(1);
    vulkan.vkCreateInstance(pInfo, 0n, handle);
    
    console.log(handle);
})();
