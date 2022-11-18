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

    //
    let appInfo = S.VkApplicationInfo.construct();
    appInfo.sType = enums.VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pNext = 0n;
    appInfo.pApplicationName = "NVAPI TEST".charAddress();
    appInfo.applicationVersion = structs.VK_MAKE_API_VERSION(0, 1, 3, 234);
    appInfo.pEngineName = "NVAPI".charAddress();
    appInfo.engineVersion = structs.VK_MAKE_API_VERSION(0, 1, 3, 234);
    appInfo.apiVersion = structs.VK_MAKE_API_VERSION(0, 1, 3, 234);

    //
    let layer = "VK_LAYER_KHRONOS_validation";
    let extensions = new BigUint64Array([  ]);
    let layers = new BigUint64Array([ layer.charAddress() ]);

    let pInfo = S.VkInstanceCreateInfo.construct();
    pInfo.sType = enums.VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    pInfo.pNext = 0n;
    pInfo.flags = 0;
    pInfo.pApplicationInfo = appInfo.address();
    pInfo.enabledLayerCount = layers.length;
    pInfo.ppEnabledLayerNames = layers.address();
    pInfo.enabledExtensionCount = 0;
    pInfo.ppEnabledExtensionNames = 0n;

    /*
    //
    let pInfo = Buffer.alloc(vulkan.vkGetStructureSizeBySType(enums.VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO));
    pInfo.writeUInt32LE(enums.VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO, vulkan["VkInstanceCreateInfo_sType_offsetof"]());
    pInfo.writeBigUInt64LE(0n, vulkan["VkInstanceCreateInfo_pNext_offsetof"]());
    pInfo.writeBigUInt64LE(appInfo.address(), vulkan["VkInstanceCreateInfo_pApplicationInfo_offsetof"]());
    pInfo.writeUInt32LE(layers.length, vulkan["VkInstanceCreateInfo_enabledLayerCount_offsetof"]());
    pInfo.writeBigUInt64LE(layers.address(), vulkan["VkInstanceCreateInfo_ppEnabledLayerNames_offsetof"]());
    pInfo.writeUInt32LE(0, vulkan["VkInstanceCreateInfo_enabledExtensionCount_offsetof"]());
    pInfo.writeBigUInt64LE(0n, vulkan["VkInstanceCreateInfo_ppEnabledExtensionNames_offsetof"]());
*/

    let handle = new BigUint64Array(1);
    vulkan.vkCreateInstance(pInfo.address(), 0n, handle.address());
    
    console.log(handle[0]);
})();
