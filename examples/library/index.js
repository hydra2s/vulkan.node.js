//
import { default as V } from "../../index.js"
import fs from "fs";

//
const createShaderModule = (device, shaderSrc) => {
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
    for (let I = 0; I < memoryProperties.memoryTypeCount; ++I) {
        if (
        (typeFilter & (1 << I)) &&
        (memoryProperties.memoryTypes[I].propertyFlags & propertyFlag) === propertyFlag
        ) {
        return I;
        }
    };
    return -1;
};

//
const createShaderModuleInfo = (module, stage, pName = "main")=>{
    return new V.VkPipelineShaderStageCreateInfo({
        flags: 0, stage, module, pName, pSpecializationInfo: null
    });
}


//
const createTypedBuffer = (physicalDevice, device, usage, byteSize, PTR = null) => {
    //
    const bufferInfo = new V.VkBufferCreateInfo({
        size: byteSize,
        usage: usage | V.VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT | V.VK_BUFFER_USAGE_TRANSFER_SRC_BIT | V.VK_BUFFER_USAGE_TRANSFER_DST_BIT,
        sharingMode: V.VK_SHARING_MODE_EXCLUSIVE,
        queueFamilyIndexCount: 0,
        pQueueFamilyIndices: null
    });

    //
    const buffer = new BigUint64Array(1);
    V.vkCreateBuffer(device, bufferInfo, null, buffer);

    //
    const memoryRequirements = new V.VkMemoryRequirements();
    V.vkGetBufferMemoryRequirements(device, buffer[0], memoryRequirements);

    //
    const propertyFlag = PTR ? (
        V.VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
        V.VK_MEMORY_PROPERTY_HOST_COHERENT_BIT
    ) : V.VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;

    //
    const memAllocFlags = new V.VkMemoryAllocateFlagsInfo({
        flags: V.VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT_KHR
    });

    //
    const memAllocInfo = new V.VkMemoryAllocateInfo({
        pNext: memAllocFlags,
        allocationSize: memoryRequirements.size,
        memoryTypeIndex: getMemoryTypeIndex(physicalDevice, memoryRequirements.memoryTypeBits, propertyFlag)
    });

    //
    const bufferMemory = new BigUint64Array(1);
    V.vkAllocateMemory(device, memAllocInfo, null, bufferMemory);
    V.vkBindBufferMemory(device, buffer[0], bufferMemory[0], 0n);

    //
    if (PTR) {
        //
        const dataPtr = new BigUint64Array(1);
        V.vkMapMemory(device, bufferMemory[0], 0n, bufferInfo.size, 0, dataPtr);

        // gigant spider
        ArrayBuffer.fromAddress(dataPtr[0], bufferInfo.size).set(ArrayBuffer.fromAddress(PTR, bufferInfo.size));
        V.vkUnmapMemory(device, bufferMemory[0]);
    }

    return buffer[0];
}

//
const createVertexBuffer = (physicalDevice, device, vertices) => {
    return createTypedBuffer(physicalDevice, device, V.VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | V.VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR, vertices.byteLength, vertices);
}

//
const createInstanceBuffer = (physicalDevice, device, instances) => {
    return createTypedBuffer(physicalDevice, device, V.VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR | V.VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR, instances.byteLength, instances);
}

//
const getBufferDeviceAddress = (device, $buffer)=>{
    return V.vkGetBufferDeviceAddress(device, new V.VkBufferDeviceAddressInfo({ $buffer })); // conflict-less
}

//
const getAcceelerationStructureAddress = (device, accelerationStructure)=>{
    return V.vkGetAccelerationStructureDeviceAddressKHR(device, new V.VkAccelerationStructureDeviceAddressInfoKHR({ accelerationStructure }));
}



// TODO: user-define opaque flags support
class AccelerationStructure {
    constructor(physicalDevice, device, asLevel, options) {
        this.physicalDevice = physicalDevice;
        this.device = device;
        this.asLevel = asLevel;
        this.asGeometryInfo = this.asLevel == V.VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR ? new V.VkAccelerationStructureGeometryKHR({
            flags: (options.opaque ? V.VK_GEOMETRY_OPAQUE_BIT_KHR : 0),
            geometryType: V.VK_GEOMETRY_TYPE_INSTANCES_KHR,
            ["geometry:VkAccelerationStructureGeometryInstancesDataKHR"]: {
                sType: V.VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR,
                arrayOfPointers: false,
                ...options.instanced
            }
        }) : new V.VkAccelerationStructureGeometryKHR(new Array(options.geometries.length).fill({}).map((_, I)=>({
            flags: (options.geometries[I].opaque ? V.VK_GEOMETRY_OPAQUE_BIT_KHR : 0),
            geometryType: V.VK_GEOMETRY_TYPE_TRIANGLES_KHR,
            ["geometry:VkAccelerationStructureGeometryTrianglesDataKHR"]: {
                sType: V.VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR,
                vertexFormat: V.VK_FORMAT_R32G32_SFLOAT,
                vertexData: 0n,
                vertexStride: 8,
                maxVertex: 3,
                indexType: V.VK_INDEX_TYPE_NONE_KHR,
                indexData: 0n,
                ...options.geometries[I].geometry
            }
        })));

        //
        const asBuildSizeGeometryInfo = new V.VkAccelerationStructureBuildGeometryInfoKHR({
            type: this.asLevel,
            flags: V.VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR,
            geometryCount: this.asGeometryInfo.length,
            pGeometries: this.asGeometryInfo
        });

        // 
        const asPrimitiveCount = new Uint32Array(this.asLevel == V.VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR ? [options.primitiveCount] : new Array(options.geometries.length).fill({}).map((_, I)=>(options.geometries[I].primitiveCount)));
        const asBuildSizesInfo = new V.VkAccelerationStructureBuildSizesInfoKHR({});
        V.vkGetAccelerationStructureBuildSizesKHR(this.device, V.VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR, asBuildSizeGeometryInfo, asPrimitiveCount, asBuildSizesInfo);

        //
        this.buffer = createTypedBuffer(this.physicalDevice, this.device, V.VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR | V.VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT, asBuildSizesInfo.accelerationStructureSize);
        this.bufferBarrier = this.asLevel == V.VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR ? new V.VkBufferMemoryBarrier2({
            srcStageMask: V.VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
            srcAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR,
            dstStageMask: V.VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
            dstAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR | V.VK_ACCESS_2_SHADER_READ_BIT,
            srcQueueFamilyIndex: 0,
            dstQueueFamilyIndex: 0,
            $buffer: this.buffer,
            offset: 0,
            size: asBuildSizesInfo.accelerationStructureSize
        }) : new V.VkBufferMemoryBarrier2({
            srcStageMask: V.VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
            srcAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR | V.VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR,
            dstStageMask: V.VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
            dstAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR | V.VK_ACCESS_2_SHADER_READ_BIT,
            srcQueueFamilyIndex: 0,
            dstQueueFamilyIndex: 0,
            $buffer: this.buffer,
            offset: 0,
            size: asBuildSizesInfo.accelerationStructureSize
        });

        //
        this.AS = new BigUint64Array(1);
        V.vkCreateAccelerationStructureKHR(this.device, new V.VkAccelerationStructureCreateInfoKHR({
            $buffer: this.buffer,
            size: asBuildSizesInfo.accelerationStructureSize,
            type: this.asLevel
        }), null, this.AS);

        //
        this.scratchMemory = createTypedBuffer(this.physicalDevice, this.device, V.VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | V.VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR | V.VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT, asBuildSizesInfo.buildScratchSize);
        this.scratchBarrier = new V.VkBufferMemoryBarrier2({
            srcStageMask: V.VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
            srcAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR,
            dstStageMask: V.VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT | V.VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
            dstAccessMask: V.VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR | V.VK_ACCESS_2_SHADER_READ_BIT | V.VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR,
            srcQueueFamilyIndex: 0,
            dstQueueFamilyIndex: 0,
            $buffer: this.scratchMemory,
            offset: 0,
            size: asBuildSizesInfo.buildScratchSize
        });
    }

    getDeviceAddress() {
        return getAcceelerationStructureAddress(this.device, this.AS[0]);
    }

    cmdBuild(cmdBuf, geometries) {
        const asBufferBarriers = new V.VkBufferMemoryBarrier2([this.bufferBarrier, this.scratchBarrier]);
        const asBuildGeometryInfo = new V.VkAccelerationStructureBuildGeometryInfoKHR({
            type: this.asLevel,
            flags: V.VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR,
            mode: V.VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR,
            dstAccelerationStructure: this.AS[0],
            geometryCount: this.asGeometryInfo.length,
            pGeometries: this.asGeometryInfo,
            scratchData: getBufferDeviceAddress(this.device, this.scratchMemory)
        });
        const asBuildRangeInfo = new V.VkAccelerationStructureBuildRangeInfoKHR(new Array(geometries.length).fill({}).map((_, I)=>({
            primitiveCount: 1,
            primitiveOffset: 0,
            firstVertex: 0,
            transformOffset: 0,
            ...geometries[I]
        })));

        // TODO: multiple bottom levels support
        const asBuildRangeInfoPtr = new BigUint64Array([ asBuildRangeInfo.address() ]);
        V.vkCmdBuildAccelerationStructuresKHR(cmdBuf, 1, asBuildGeometryInfo, asBuildRangeInfoPtr);
        V.vkCmdPipelineBarrier2(cmdBuf, new V.VkDependencyInfoKHR({ bufferMemoryBarrierCount: asBufferBarriers.length, pBufferMemoryBarriers: asBufferBarriers }));
    }
};

//
class TopLevelAccelerationStructure extends AccelerationStructure {
    constructor(physicalDevice, device, options) {
        super(physicalDevice, device, V.VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR, {
            opaque: options.opaque,
            instanced: options.instanced?.length ? {} : options.instanced,
            primitiveCount: options.instanced?.length || options.primitiveCount
        });
        this.instanced = options.instanced?.length ? new V.VkAccelerationStructureInstanceKHR(options.instanced) : null;
        this.instanceBuffer = createInstanceBuffer(this.physicalDevice, this.device, this.instanced);
        this.asGeometryInfo["geometry:VkAccelerationStructureGeometryInstancesDataKHR"].data = getBufferDeviceAddress(this.device, this.instanceBuffer);
    }

    // TODO: support for upload instance data
    uploadInstanceData() {
        
    }
};

//
class BottomLevelAccelerationStructure extends AccelerationStructure {
    constructor(physicalDevice, device, options) {
        super(physicalDevice, device, V.VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR, options);
    }
};

//
const awaitTick = ()=> new Promise(setImmediate);
const awaitFenceAsync = async function*(device, fence) {
    let status = V.VK_NOT_READY;
    do {
        await awaitTick(); yield status;
        if (status == V.VK_ERROR_DEVICE_LOST) { throw Error("Vulkan Device Lost"); break; };
        if (status != V.VK_NOT_READY) break;
    } while((status = V.vkGetFenceStatus(device, fence)) != V.VK_SUCCESS);
    return status;
}

//
const makeState = (promise)=>{
    const state_ = { status: 'pending' };
    promise.then(()=>{state_.status="ready"; return awaitTick();});
    promise.catch(()=>{state_.status="reject"; });
    return new Proxy(promise, {
        get(target, prop) {
            if (target instanceof Promise) {
                if (prop == "status") {
                    return state_[prop];
                } else {
                    return target[prop].bind(target);
                }
            }
        }
    });
}

export default {
    makeState,
    awaitTick,
    awaitFenceAsync,
    createShaderModule,
    getMemoryTypeIndex,
    createShaderModuleInfo,
    createTypedBuffer,
    createVertexBuffer,
    createInstanceBuffer,
    getBufferDeviceAddress,
    getAcceelerationStructureAddress,
    AccelerationStructure,
    TopLevelAccelerationStructure,
    BottomLevelAccelerationStructure
}