(async ()=>{
    let reader = await (await (await import("./reader.js")).default());
    let writer = await (await (await import("./writer.js")).default());

    writer.writeCodes(await reader.parseDocs());
})();