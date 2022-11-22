
import { default as ffi } from 'ffi-napi'
import { default as ref } from 'ref-napi'
import { default as StructDi } from 'ref-struct-di'


import {
    C,
    // Config,
    DModel as M,
    DStruct as DS,
    DTypes as W,
    // K,
    U,
} from 'win32-api' // as local

import { Kernel32, User32 } from 'win32-api/promise'

// Fragment Shader (https://github.com/SaschaWillems/Vulkan/data/shaders/triangle/triangle.frag)
/*
#version 450
layout (location = 0) in vec3 inColor;
layout (location = 0) out vec4 outFragColor;
void main() 
{
    outFragColor = vec4(inColor, 1.0);
}
*/
const frag_shader_spv = new Uint8Array([
    0x03,0x02,0x23,0x07,0x00,0x00,0x01,0x00,0x07,0x00,0x08,0x00,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x11,0x00,0x02,0x00,
    0x01,0x00,0x00,0x00,0x0b,0x00,0x06,0x00,0x01,0x00,0x00,0x00,0x47,0x4c,0x53,0x4c,0x2e,0x73,0x74,0x64,0x2e,0x34,0x35,0x30,
    0x00,0x00,0x00,0x00,0x0e,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x0f,0x00,0x07,0x00,0x04,0x00,0x00,0x00,
    0x04,0x00,0x00,0x00,0x6d,0x61,0x69,0x6e,0x00,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x10,0x00,0x03,0x00,
    0x04,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x02,0x00,0x00,0x00,0xc2,0x01,0x00,0x00,0x05,0x00,0x04,0x00,
    0x04,0x00,0x00,0x00,0x6d,0x61,0x69,0x6e,0x00,0x00,0x00,0x00,0x05,0x00,0x06,0x00,0x09,0x00,0x00,0x00,0x6f,0x75,0x74,0x46,
    0x72,0x61,0x67,0x43,0x6f,0x6c,0x6f,0x72,0x00,0x00,0x00,0x00,0x05,0x00,0x04,0x00,0x0c,0x00,0x00,0x00,0x69,0x6e,0x43,0x6f,
    0x6c,0x6f,0x72,0x00,0x47,0x00,0x04,0x00,0x09,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x47,0x00,0x04,0x00,
    0x0c,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x00,0x02,0x00,0x02,0x00,0x00,0x00,0x21,0x00,0x03,0x00,
    0x03,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x16,0x00,0x03,0x00,0x06,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x17,0x00,0x04,0x00,
    0x07,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x20,0x00,0x04,0x00,0x08,0x00,0x00,0x00,0x03,0x00,0x00,0x00,
    0x07,0x00,0x00,0x00,0x3b,0x00,0x04,0x00,0x08,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x17,0x00,0x04,0x00,
    0x0a,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x20,0x00,0x04,0x00,0x0b,0x00,0x00,0x00,0x01,0x00,0x00,0x00,
    0x0a,0x00,0x00,0x00,0x3b,0x00,0x04,0x00,0x0b,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x2b,0x00,0x04,0x00,
    0x06,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x80,0x3f,0x36,0x00,0x05,0x00,0x02,0x00,0x00,0x00,0x04,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0xf8,0x00,0x02,0x00,0x05,0x00,0x00,0x00,0x3d,0x00,0x04,0x00,0x0a,0x00,0x00,0x00,
    0x0d,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x51,0x00,0x05,0x00,0x06,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x0d,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x51,0x00,0x05,0x00,0x06,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x0d,0x00,0x00,0x00,0x01,0x00,0x00,0x00,
    0x51,0x00,0x05,0x00,0x06,0x00,0x00,0x00,0x11,0x00,0x00,0x00,0x0d,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x50,0x00,0x07,0x00,
    0x07,0x00,0x00,0x00,0x12,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x11,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,
    0x3e,0x00,0x03,0x00,0x09,0x00,0x00,0x00,0x12,0x00,0x00,0x00,0xfd,0x00,0x01,0x00,0x38,0x00,0x01,0x00,
]);

// Vertex Shader (https://github.com/SaschaWillems/Vulkan/data/shaders/triangle/triangle.vert)
/*
#version 450
layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inColor;
layout (binding = 0) uniform UBO 
{
    mat4 projectionMatrix;
    mat4 modelMatrix;
    mat4 viewMatrix;
} ubo;
layout (location = 0) out vec3 outColor;
out gl_PerVertex 
{
    vec4 gl_Position;   
};
void main() 
{
    outColor = inColor;
    gl_Position = ubo.projectionMatrix * ubo.viewMatrix * ubo.modelMatrix * vec4(inPos.xyz, 1.0);
}
*/
const vert_shader_spv = new Uint8Array([
    0x03,0x02,0x23,0x07,0x00,0x00,0x01,0x00,0x07,0x00,0x08,0x00,0x2c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x11,0x00,0x02,0x00,
    0x01,0x00,0x00,0x00,0x0b,0x00,0x06,0x00,0x01,0x00,0x00,0x00,0x47,0x4c,0x53,0x4c,0x2e,0x73,0x74,0x64,0x2e,0x34,0x35,0x30,
    0x00,0x00,0x00,0x00,0x0e,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x0f,0x00,0x09,0x00,0x00,0x00,0x00,0x00,
    0x04,0x00,0x00,0x00,0x6d,0x61,0x69,0x6e,0x00,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x0b,0x00,0x00,0x00,0x10,0x00,0x00,0x00,
    0x22,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x02,0x00,0x00,0x00,0xc2,0x01,0x00,0x00,0x05,0x00,0x04,0x00,0x04,0x00,0x00,0x00,
    0x6d,0x61,0x69,0x6e,0x00,0x00,0x00,0x00,0x05,0x00,0x05,0x00,0x09,0x00,0x00,0x00,0x6f,0x75,0x74,0x43,0x6f,0x6c,0x6f,0x72,
    0x00,0x00,0x00,0x00,0x05,0x00,0x04,0x00,0x0b,0x00,0x00,0x00,0x69,0x6e,0x43,0x6f,0x6c,0x6f,0x72,0x00,0x05,0x00,0x06,0x00,
    0x0e,0x00,0x00,0x00,0x67,0x6c,0x5f,0x50,0x65,0x72,0x56,0x65,0x72,0x74,0x65,0x78,0x00,0x00,0x00,0x00,0x06,0x00,0x06,0x00,
    0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x00,0x05,0x00,0x03,0x00,
    0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0x03,0x00,0x14,0x00,0x00,0x00,0x55,0x42,0x4f,0x00,0x06,0x00,0x08,0x00,
    0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x72,0x6f,0x6a,0x65,0x63,0x74,0x69,0x6f,0x6e,0x4d,0x61,0x74,0x72,0x69,0x78,
    0x00,0x00,0x00,0x00,0x06,0x00,0x06,0x00,0x14,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x6d,0x6f,0x64,0x65,0x6c,0x4d,0x61,0x74,
    0x72,0x69,0x78,0x00,0x06,0x00,0x06,0x00,0x14,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x76,0x69,0x65,0x77,0x4d,0x61,0x74,0x72,
    0x69,0x78,0x00,0x00,0x05,0x00,0x03,0x00,0x16,0x00,0x00,0x00,0x75,0x62,0x6f,0x00,0x05,0x00,0x04,0x00,0x22,0x00,0x00,0x00,
    0x69,0x6e,0x50,0x6f,0x73,0x00,0x00,0x00,0x47,0x00,0x04,0x00,0x09,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x47,0x00,0x04,0x00,0x0b,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x48,0x00,0x05,0x00,0x0e,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x0b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x47,0x00,0x03,0x00,0x0e,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
    0x48,0x00,0x04,0x00,0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x48,0x00,0x05,0x00,0x14,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0x00,0x05,0x00,0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x07,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x48,0x00,0x04,0x00,0x14,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x05,0x00,0x00,0x00,
    0x48,0x00,0x05,0x00,0x14,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x23,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x48,0x00,0x05,0x00,
    0x14,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x48,0x00,0x04,0x00,0x14,0x00,0x00,0x00,
    0x02,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x48,0x00,0x05,0x00,0x14,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x23,0x00,0x00,0x00,
    0x80,0x00,0x00,0x00,0x48,0x00,0x05,0x00,0x14,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x10,0x00,0x00,0x00,
    0x47,0x00,0x03,0x00,0x14,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x47,0x00,0x04,0x00,0x16,0x00,0x00,0x00,0x22,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x47,0x00,0x04,0x00,0x16,0x00,0x00,0x00,0x21,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x47,0x00,0x04,0x00,
    0x22,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x00,0x02,0x00,0x02,0x00,0x00,0x00,0x21,0x00,0x03,0x00,
    0x03,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x16,0x00,0x03,0x00,0x06,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x17,0x00,0x04,0x00,
    0x07,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x20,0x00,0x04,0x00,0x08,0x00,0x00,0x00,0x03,0x00,0x00,0x00,
    0x07,0x00,0x00,0x00,0x3b,0x00,0x04,0x00,0x08,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x20,0x00,0x04,0x00,
    0x0a,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x3b,0x00,0x04,0x00,0x0a,0x00,0x00,0x00,0x0b,0x00,0x00,0x00,
    0x01,0x00,0x00,0x00,0x17,0x00,0x04,0x00,0x0d,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x1e,0x00,0x03,0x00,
    0x0e,0x00,0x00,0x00,0x0d,0x00,0x00,0x00,0x20,0x00,0x04,0x00,0x0f,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,
    0x3b,0x00,0x04,0x00,0x0f,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x15,0x00,0x04,0x00,0x11,0x00,0x00,0x00,
    0x20,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x2b,0x00,0x04,0x00,0x11,0x00,0x00,0x00,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x18,0x00,0x04,0x00,0x13,0x00,0x00,0x00,0x0d,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x1e,0x00,0x05,0x00,0x14,0x00,0x00,0x00,
    0x13,0x00,0x00,0x00,0x13,0x00,0x00,0x00,0x13,0x00,0x00,0x00,0x20,0x00,0x04,0x00,0x15,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
    0x14,0x00,0x00,0x00,0x3b,0x00,0x04,0x00,0x15,0x00,0x00,0x00,0x16,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x20,0x00,0x04,0x00,
    0x17,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x13,0x00,0x00,0x00,0x2b,0x00,0x04,0x00,0x11,0x00,0x00,0x00,0x1a,0x00,0x00,0x00,
    0x02,0x00,0x00,0x00,0x2b,0x00,0x04,0x00,0x11,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x3b,0x00,0x04,0x00,
    0x0a,0x00,0x00,0x00,0x22,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x2b,0x00,0x04,0x00,0x06,0x00,0x00,0x00,0x24,0x00,0x00,0x00,
    0x00,0x00,0x80,0x3f,0x20,0x00,0x04,0x00,0x2a,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x0d,0x00,0x00,0x00,0x36,0x00,0x05,0x00,
    0x02,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0xf8,0x00,0x02,0x00,0x05,0x00,0x00,0x00,
    0x3d,0x00,0x04,0x00,0x07,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x0b,0x00,0x00,0x00,0x3e,0x00,0x03,0x00,0x09,0x00,0x00,0x00,
    0x0c,0x00,0x00,0x00,0x41,0x00,0x05,0x00,0x17,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x16,0x00,0x00,0x00,0x12,0x00,0x00,0x00,
    0x3d,0x00,0x04,0x00,0x13,0x00,0x00,0x00,0x19,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x41,0x00,0x05,0x00,0x17,0x00,0x00,0x00,
    0x1b,0x00,0x00,0x00,0x16,0x00,0x00,0x00,0x1a,0x00,0x00,0x00,0x3d,0x00,0x04,0x00,0x13,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,
    0x1b,0x00,0x00,0x00,0x92,0x00,0x05,0x00,0x13,0x00,0x00,0x00,0x1d,0x00,0x00,0x00,0x19,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,
    0x41,0x00,0x05,0x00,0x17,0x00,0x00,0x00,0x1f,0x00,0x00,0x00,0x16,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x3d,0x00,0x04,0x00,
    0x13,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x1f,0x00,0x00,0x00,0x92,0x00,0x05,0x00,0x13,0x00,0x00,0x00,0x21,0x00,0x00,0x00,
    0x1d,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x3d,0x00,0x04,0x00,0x07,0x00,0x00,0x00,0x23,0x00,0x00,0x00,0x22,0x00,0x00,0x00,
    0x51,0x00,0x05,0x00,0x06,0x00,0x00,0x00,0x25,0x00,0x00,0x00,0x23,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x51,0x00,0x05,0x00,
    0x06,0x00,0x00,0x00,0x26,0x00,0x00,0x00,0x23,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x51,0x00,0x05,0x00,0x06,0x00,0x00,0x00,
    0x27,0x00,0x00,0x00,0x23,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x50,0x00,0x07,0x00,0x0d,0x00,0x00,0x00,0x28,0x00,0x00,0x00,
    0x25,0x00,0x00,0x00,0x26,0x00,0x00,0x00,0x27,0x00,0x00,0x00,0x24,0x00,0x00,0x00,0x91,0x00,0x05,0x00,0x0d,0x00,0x00,0x00,
    0x29,0x00,0x00,0x00,0x21,0x00,0x00,0x00,0x28,0x00,0x00,0x00,0x41,0x00,0x05,0x00,0x2a,0x00,0x00,0x00,0x2b,0x00,0x00,0x00,
    0x10,0x00,0x00,0x00,0x12,0x00,0x00,0x00,0x3e,0x00,0x03,0x00,0x2b,0x00,0x00,0x00,0x29,0x00,0x00,0x00,0xfd,0x00,0x01,0x00,
    0x38,0x00,0x01,0x00,
]);

(async()=>{

    //
    const V = (await import("./index.js")).default;

    //
    console.log(V.glfwVulkanSupported());

    //
    const IExt64 = V.glfwGetRequiredInstanceExtensions();
    const IExtensionOpen = new Array(IExt64.length).fill("").map((_, i)=>{ return String.fromAddress(IExt64[i]); });
    console.log(IExtensionOpen);

    //
    let vertices = new Float32Array([
        0.0, -0.5,
        0.5,  0.5,
       -0.5,  0.5 
    ]);

    //
    let vertexBuffer = new BigUint64Array(1);
    let vertexBufferMemory = new BigUint64Array(1);

    //
    let posVertexBindingDescr = new V.VkVertexInputBindingDescription({
        binding: 0, 
        stride: 2 * vertices.BYTES_PER_ELEMENT,
        inputRate: V.VK_VERTEX_INPUT_RATE_VERTEX
    });

    //
    let posVertexAttrDescr = new V.VkVertexInputAttributeDescription({
        location: 0,
        binding: 0,
        format: V.VK_FORMAT_R32G32_SFLOAT,
        offset: 0
    });

    //
    const createShaderModule = (shaderSrc) => {
        let shaderModuleInfo = new V.VkShaderModuleCreateInfo({
            pCode: shaderSrc,
            codeSize: shaderSrc.byteLength
        });
        const shaderModule = new BigUint64Array(1);
        V.vkCreateShaderModule(device, shaderModuleInfo, null, shaderModule);
        return shaderModule[0];
    }

    //
    const getMemoryTypeIndex = (physicalDevice, typeFilter, propertyFlag) => {
        let memoryProperties = new V.VkPhysicalDeviceMemoryProperties();
        V.vkGetPhysicalDeviceMemoryProperties(physicalDevice, memoryProperties);
        for (let ii = 0; ii < memoryProperties.memoryTypeCount; ++ii) {
          if (
            (typeFilter & (1 << ii)) &&
            (memoryProperties.memoryTypes[ii].propertyFlags & propertyFlag) === propertyFlag
          ) {
            return ii;
          }
        };
        return -1;
    };

    //
    const createVertexBuffer = (device, byteLength) => {
        //
        let bufferInfo = new V.VkBufferCreateInfo({
            size: byteLength,
            usage: V.VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
            sharingMode: V.VK_SHARING_MODE_EXCLUSIVE,
            queueFamilyIndexCount: 0,
            pQueueFamilyIndices: null
        });

        //
        const buffer = new BigUint64Array(1);
        V.vkCreateBuffer(device, bufferInfo, null, buffer);

        //
        let memoryRequirements = new V.VkMemoryRequirements();
        V.vkGetBufferMemoryRequirements(device, buffer[0], memoryRequirements);

        //
        let propertyFlag = (
              VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
              VK_MEMORY_PROPERTY_HOST_COHERENT_BIT
        );

        //
        let memAllocInfo = new V.VkMemoryAllocateInfo({
            allocationSize: memoryRequirements.size,
            memoryTypeIndex: getMemoryTypeIndex(memoryRequirements.memoryTypeBits, propertyFlag)
        });

        //
        let bufferMemory = new BigUint64Array(1);
        V.vkAllocateMemory(device, memAllocInfo, null, bufferMemory);
        V.vkBindBufferMemory(device, buffer[0], bufferMemory[0], null);

        //
        let dataPtr = new BigUint64Array(1);
        V.vkMapMemory(device, bufferMemory[0], null, bufferInfo.size, 0, dataPtr);

        // gigant spider
        Uint8Array.fromAddress(dataPtr[0], bufferInfo.size).set(vertices);
        V.vkUnmapMemory(device, bufferMemory);
      };


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
    const extensions = [].concat(IExtensionOpen);
    const layers = ["VK_LAYER_KHRONOS_validation"];

    //
    const amountOfLayers = new Uint32Array(1);
    V.vkEnumerateInstanceLayerProperties(amountOfLayers, null);
    const availableLayers = new V.VkLayerProperties(amountOfLayers[0]);
    V.vkEnumerateInstanceLayerProperties(amountOfLayers, availableLayers);

    //
    let pInfo = new V.VkInstanceCreateInfo({
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

    //
    const GLFWwindow = V.glfwCreateWindow(1280, 720, "Hello Triangle", null, null);

    // make shared GLFW surface between two versions of GLFW
    const surface = new BigUint64Array(1);
    V.glfwCreateWindowSurface(instance[0], GLFWwindow, null, surface);

    

    //
    //const 

    // // // // // // // // // // // // // // // //
    // TODO: support for Surface and Win32 handlers
    // // // // // // // // // // // // // // // //



    //
    const deviceCount = new Uint32Array(1);
    let result = V.vkEnumeratePhysicalDevices(instance[0], deviceCount, null);
    //console.log(deviceCount);

    //
    if (deviceCount[0] <= 0) console.error("Error: No render devices available!");
    const devices = new BigUint64Array(deviceCount[0]);
    result = V.vkEnumeratePhysicalDevices(instance[0], deviceCount, devices);
    //console.log(devices);

    //
    console.log(V.glfwGetPhysicalDevicePresentationSupport(instance[0], devices[0], 0));

    //
    const dExtensionCount = new Uint32Array(1);
    V.vkEnumerateDeviceExtensionProperties(devices[0], "", dExtensionCount, null);
    const dExtensions = new V.VkExtensionProperties(dExtensionCount[0]);
    V.vkEnumerateDeviceExtensionProperties(devices[0], "", dExtensionCount, dExtensions);

    //
    for (let I=0;I<dExtensionCount[0];I++) {
        console.log(String.fromAddress(dExtensions[I].extensionName));
    }

    //
    const queueFamilyCount = new Uint32Array(1);
    V.vkGetPhysicalDeviceQueueFamilyProperties(devices[0], queueFamilyCount, null);
    const queueFamilyProperties = new V.VkQueueFamilyProperties(queueFamilyCount[0])
    V.vkGetPhysicalDeviceQueueFamilyProperties(devices[0], queueFamilyCount, queueFamilyProperties);

    //
    let queueIndex = -1;
    for (let I=0;I<queueFamilyCount[0];I++) {
        if (queueFamilyProperties[I].queueFlags & parseInt(V.VK_QUEUE_GRAPHICS_BIT)) {
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

})();
