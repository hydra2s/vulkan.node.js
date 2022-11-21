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
- Better error handling (with additional info)

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
    const rect2D = new V.VkRect2D();

    //
    const appInfo = new V.VkApplicationInfo({
        pNext: null,
        pApplicationName: "NVAPI TEST",
        applicationVersion: V.VK_MAKE_API_VERSION(0, 1, 3, 234),
        pEngineName: "NVAPI",
        engineVersion: V.VK_MAKE_API_VERSION(0, 1, 3, 234),
        apiVersion: V.VK_MAKE_API_VERSION(0, 1, 3, 234)
    });

    //
    const extensions = [];
    const layers = ["VK_LAYER_KHRONOS_validation"];

	//
	const amountOfLayers = new Uint32Array(1);
	V.vkEnumerateInstanceLayerProperties(amountOfLayers, null);
	const availableLayers = new Uint8Array(V.VkLayerProperties.sizeof * amountOfLayers[0]);
	V.vkEnumerateInstanceLayerProperties(amountOfLayers, availableLayers);

    //
    const pInfo = new V.VkInstanceCreateInfo({
        pNext: null,
        flags: 0,
        pApplicationInfo: appInfo,
        enabledLayerCount: layers.length,
        ppEnabledLayerNames: layers,
        enabledExtensionCount: extensions.length,
        ppEnabledExtensionNames: extensions
    });

	// 
    const instance = new BigUint64Array(1);
    V.vkCreateInstance(pInfo, null, instance);
})();
```

But continue, currently, not so fair. Needs sizeof de-facto. But now looks better.

```js
	//
    const deviceCount = new Uint32Array(1);
    let result = V.vkEnumeratePhysicalDevices(instance[0], deviceCount, null);
    //console.log(deviceCount);

	//
    if (deviceCount[0] <= 0) console.error("Error: No render devices available!");
    let devices = new BigUint64Array(deviceCount[0]);
    result = V.vkEnumeratePhysicalDevices(instance[0], deviceCount, devices);
    //console.log(devices);

    //
    const dExtensionCount = new Uint32Array(1);
    V.vkEnumerateDeviceExtensionProperties(devices[0], "", dExtensionCount, null);
    const dExtensions = new Uint8Array(dExtensionCount[0]*V.VkExtensionProperties.sizeof);
    V.vkEnumerateDeviceExtensionProperties(devices[0], "", dExtensionCount, dExtensions);

	//
	let property = new V.VkExtensionProperties(dExtensions, 0, dExtensionCount[0]);
    for (let I=0;I<dExtensionCount[0];I++) {
        console.log(String.fromAddress(property[I].extensionName));
    }

    //
    const queueFamilyCount = new Uint32Array(1);
    V.vkGetPhysicalDeviceQueueFamilyProperties(devices[0], queueFamilyCount, null);
    const queueFamilyProperties = new Uint8Array(V.VkQueueFamilyProperties.sizeof * queueFamilyCount[0]);
    V.vkGetPhysicalDeviceQueueFamilyProperties(devices[0], queueFamilyCount, queueFamilyProperties);

    //
    let queueIndex = -1;
	property = new V.VkQueueFamilyProperties(queueFamilyProperties, 0, queueFamilyCount[0]);
    for (let I=0;I<queueFamilyCount[0];I++) {
        if (property[I].queueFlags & parseInt(V.VK_QUEUE_GRAPHICS_BIT)) {
            queueIndex = I; break;
        }
    }

	//
    const deviceFeatures = new V.VkPhysicalDeviceFeatures2();
	const deviceProperties = new V.VkPhysicalDeviceProperties2();

	//
	V.vkGetPhysicalDeviceProperties2(devices[0], deviceProperties);
	V.vkGetPhysicalDeviceFeatures2(devices[0], deviceFeatures);

	//
	//console.log(deviceFeatures.features);

	// you can also hack and typecast members (californium bullets)
	//console.log(deviceFeatures.as("VkPhysicalDeviceFeatures", "features"));
	console.log(deviceFeatures.as(V.VkPhysicalDeviceFeatures, "features"));

	// also, you can set or get uint32 values
	//console.log(deviceFeatures.as("u32[arr]")[0]);

	// or only to get uint32
	//console.log(deviceFeatures.as("u32"));

	// you construct struct from address
	//console.log(V.VkPhysicalDeviceFeatures.fromAddress(deviceFeatures.address()));
```

## Projects

### 📀 [vk-utils](https://github.com/hydra2s/vk-utils), our helpers for Vulkan API development 
### 🥀 [about](https://github.com/hydra2s-info/about), our idiology
### 🌋 [CopperRT](https://github.com/hydra2s/CopperRT), our renderer
### 🍵 [Node.JS Vulkan API](https://github.com/hydra2s/node-vulkan-api), our nodejs bindings (alike LWJGL)
### 🖥️ [LG-24UD58-EDID-FIX](https://github.com/hydra2s/LG-24UD58-EDID-FIX), EDID fix for our monitor
### 📻 [WS-Comlink](https://github.com/hydra2s/ws-comlink), our comlink JS protocol
