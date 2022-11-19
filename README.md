# 🍵 Raw Node.JS Vulkan API bindings 🍵

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

## TODO

- [ ] User friendly interfaces as possible
- [ ] Protective proxies and classes for `typed.js` types
- [ ] More specific types (such as arrays, number accessors)
- [ ] Optimizations on JS side
- [ ] Variable type acception for API callables (such as typed arrays, array buffers, strings, etc.)
- [ ] Variable acceptors for JS types (for string, typed arrays, array buffers, native address, etc.)

## Test code

Currently, not for production use. 

```js
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
```

## Hydra.D2S

### ℹ️ [Info Center](https://github.com/hydra2s-info) ℹ️ 
### 💬 [Обсуждения/Discussions](https://github.com/hydra2s-info/about/discussions) 💬
### 🐞 [Баг-Репорты/Bug-Tracker](https://github.com/hydra2s-info/about/issues) 🐞

## Projects

### 📀 [vk-utils](https://github.com/hydra2s/vk-utils), our helpers for Vulkan API development 
### 🥀 [about](https://github.com/hydra2s-info/about), our idiology
### 🌋 [CopperRT](https://github.com/hydra2s/CopperRT), our renderer
### 🍵 [Node.JS Vulkan API](https://github.com/hydra2s/node-vulkan-api), our nodejs bindings (alike LWJGL)
### 🖥️ [LG-24UD58-EDID-FIX](https://github.com/hydra2s/LG-24UD58-EDID-FIX), EDID fix for our monitor
### 📻 [WS-Comlink](https://github.com/hydra2s/ws-comlink), our comlink JS protocol
