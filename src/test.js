(async()=>{
    let vulkan = (await import("./vulkan-API.js")).default;
    
    console.log(vulkan.vkGetStructureSizeBySType(1));
    
})();
