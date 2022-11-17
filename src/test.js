(async()=>{
    console.log("Bedrock");
    
    //const delay = ms => new Promise(resolve => setTimeout(resolve, ms))
    //await delay(10000) /// waiting 1 second.
    
    let vulkan = await import("./vulkan-API.js");
    console.log(vulkan);
})();
