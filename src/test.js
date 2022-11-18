import * as T from "struct-buffer";
const C = T.default;
(async()=>{
    
    let vulkan = (await import("./vulkan-API.js")).default;
    let structs = (await import("./vulkan-structs.js")).default;
    let enums = (await import("./vulkan-enums.js")).default;

    //
    let appInfo = Buffer.alloc(vulkan.vkGetStructureSizeBySType(enums.VK_STRUCTURE_TYPE_APPLICATION_INFO));
    appInfo.writeUInt32LE(enums.VK_STRUCTURE_TYPE_APPLICATION_INFO, vulkan["VkApplicationInfo_sType_offsetof"]());
    appInfo.writeBigUInt64LE(0n, vulkan["VkApplicationInfo_pNext_offsetof"]());
    appInfo.writeBigUInt64LE("NVAPI TEST".charAddress(), vulkan["VkApplicationInfo_pApplicationName_offsetof"]());
    appInfo.writeUInt32LE(structs.VK_MAKE_API_VERSION(0, 1, 3, 234), vulkan["VkApplicationInfo_applicationVersion_offsetof"]());
    appInfo.writeBigUInt64LE("NVAPI".charAddress(), vulkan["VkApplicationInfo_pEngineName_offsetof"]());
    appInfo.writeUInt32LE(structs.VK_MAKE_API_VERSION(0, 1, 3, 234), vulkan["VkApplicationInfo_engineVersion_offsetof"]());
    appInfo.writeUInt32LE(structs.VK_MAKE_API_VERSION(0, 1, 3, 234), vulkan["VkApplicationInfo_apiVersion_offsetof"]());

    //
    let layer = "VK_LAYER_KHRONOS_validation";
    let extensions = new BigUint64Array([  ]);
    let layers = new BigUint64Array([ layer.charAddress() ]);

    //
    let pInfo = Buffer.alloc(vulkan.vkGetStructureSizeBySType(enums.VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO));
    pInfo.writeUInt32LE(enums.VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO, vulkan["VkInstanceCreateInfo_sType_offsetof"]());
    pInfo.writeBigUInt64LE(0n, vulkan["VkInstanceCreateInfo_pNext_offsetof"]());
    pInfo.writeBigUInt64LE(appInfo.address(), vulkan["VkInstanceCreateInfo_pApplicationInfo_offsetof"]());
    pInfo.writeUInt32LE(layers.length, vulkan["VkInstanceCreateInfo_enabledLayerCount_offsetof"]());
    pInfo.writeBigUInt64LE(layers.address(), vulkan["VkInstanceCreateInfo_ppEnabledLayerNames_offsetof"]());
    pInfo.writeUInt32LE(0, vulkan["VkInstanceCreateInfo_enabledExtensionCount_offsetof"]());
    pInfo.writeBigUInt64LE(0n, vulkan["VkInstanceCreateInfo_ppEnabledExtensionNames_offsetof"]());

    let handle = new BigUint64Array(1);
    vulkan.vkCreateInstance(pInfo.address(), 0n, handle.address());
    
    console.log(handle[0]);
})();
