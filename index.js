import { default as S } from "./src/vulkan-structs.js";
import { default as E } from "./src/vulkan-enums.js";
import { default as V } from "./src/native.js";
import { default as T } from "./deps/typed.js/index.js";

export default {...S, ...E, ...V, ...T};
