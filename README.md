# 🍵 Raw Node.JS Vulkan API bindings 🍵

### ℹ️ [Info Center](https://github.com/hydra2s-info) ℹ️ 
### 💬 [Обсуждения/Discussions](https://github.com/hydra2s-info/about/discussions) 💬
### 🐞 [Баг-Репорты/Bug-Tracker](https://github.com/hydra2s-info/about/issues) 🐞

Our Node.JS bindings for Vulkan API support (latest version, as possible). Currently, still in development. 

## Made for...

- Geeks
- Hackers
- Programmers
- Coders
- Professionals
- NOT newbies (JS and Vulkan)
- NOT weak persons

## Features

- Using raw pointers and typed structures
- Low abstraction levels (and there is no Vulkan-HPP)
- Pre-computing of enums and struct classes
- JS generator from Vulkan XML, with C++ supplements
- Some handmade fixes (such as bitfield structures)
- Planned support for glMatrix fully
- Planned support for WebAssembly bindings and memory
- Error and exception handling support
- Some syntax sugar for user-friendly

## TODO

- [ ] More type casting
- [ ] Support `set` operation for everything
- [ ] WebAssembly and AssemblyScript support
- [ ] Fix common bugs and issues

## Test code

Currently, not for production use. 

```js
import { default as V } from "./index.js";

(async()=>{

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

    let handle = new BigUint64Array(1);
    V.vkCreateInstance(pInfo, 0n, handle);

    console.log(handle);
})();
```

But continue, currently, not so fair. Needs sizeof de-facto.

```js
    let deviceCount = new Uint32Array(1);
    let result = V.vkEnumeratePhysicalDevices(instance[0], deviceCount, 0n);
    //console.log(deviceCount);
    
    if (deviceCount[0] <= 0) console.error("Error: No render devices available!");
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
```

## Projects

### 📀 [vk-utils](https://github.com/hydra2s/vk-utils), our helpers for Vulkan API development 
### 🥀 [about](https://github.com/hydra2s-info/about), our idiology
### 🌋 [CopperRT](https://github.com/hydra2s/CopperRT), our renderer
### 🍵 [Node.JS Vulkan API](https://github.com/hydra2s/node-vulkan-api), our nodejs bindings (alike LWJGL)
### 🖥️ [LG-24UD58-EDID-FIX](https://github.com/hydra2s/LG-24UD58-EDID-FIX), EDID fix for our monitor
### 📻 [WS-Comlink](https://github.com/hydra2s/ws-comlink), our comlink JS protocol
