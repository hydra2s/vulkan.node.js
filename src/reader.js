let getReader = async()=>{
    const { parseXml } = (await import('@rgrove/parse-xml'));
    const fs = await import('fs');
    const JSON5  = (await import('json5')).default;
    const JSON6  = (await import('json-6')).default;
    const {JSOX}  = (await import('jsox'));

    // 
    let getDocs = async (path = "../../Vulkan-Docs/xml/vk.xml") => {
        return parseXml((await fs.promises.readFile(path,"utf8")).replace(/\r?\n|\r/g, " ").replace(/\s+/g,' ').trim());
    };

    //
    let noSpaces = (xml)=>{
        let text = xml.text ? xml.text.trim() : "";
        if (text) { xml.text = text; };
        return xml.type == "text" ? !!text : true;
    };

    // unlock assign and trim operations
    let cloneObj = (obj)=>{
        //return JSON5.parse(JSON5.stringify(obj));
        return Array.isArray(obj) ? [...obj] : {...obj};
    };

    //
    let filterNoSpaced = (xml)=>{ let xmc = xml; if (xmc.children && xmc.children.length > 0) { xmc.children = xmc.children.filter(noSpaces).map(filterNoSpaced); } else { delete xmc.children; }; return xmc; };
    let structsOnly = (s)=>{ return s.attributes["category"] == "struct"; };

    //
    let getLength = (txt, I=0)=>{
        let M = txt.match(/\d+/g);
        return M ? M[I] : 1;//.join("");
    };

    //
    let parseParam = (e)=>{
        let parts = [];
        let parsed = { name: "", type: "void", isPointer: false, isConst: false, isPointerSet: false };
        
        if (e) {
            e.forEach((p)=>{
                if (p.type == "text" && p.text.indexOf("[") >= 0 && p.text.indexOf("]") >= 0) { if (parsed.isPointer || parsed.isFixedArray) { parsed.isPointer = true; parsed.isPointerSet = true; parsed.isFixedArray = true; }; parsed.isFixedArray = true; parsed.length = getLength(p.text); };
                if (p.type == "text" && p.text.match(/\*/gi)?.length == 1) { if (parsed.isPointer) {parsed.isPointerSet = true;}; parsed.isPointer = true; };
                if (p.type == "text" && p.text.match(/\*/gi)?.length == 2) { parsed.isPointerSet = true; parsed.isPointer = true; };
                if (p.type == "text" && p.text.indexOf("const") >= 0) { parsed.isConst = true; };
                if (p.type == "text" && p.text.indexOf(":") >= 0) { parsed.isBitfield = true; };
                if (p.type == "element" && p.name == "type") { parsed.type = p.children[0].text; };
                if (p.type == "element" && p.name == "name") { parsed.name = p.children[0].text; };
                
                //
                if (p.name != "comment") {
                    if (p.type == "text" && p.text.indexOf(":") < 0) { parts.push(p.text); };
                    if (p.type == "element") { parts.push(p.children[0].text); };
                };
            });
        }

        parsed.text = parts.join(" ");
        parsed.parts = parts;

        return parsed;
    }

    // 
    let parseStructs = (types)=>{
        let tick = 0;
        return types.filter(structsOnly).map((T)=>{
            let parsed = {};
            parsed.name = T.attributes["name"];
            parsed.params = [];

            if (T.children) {
                T.children.forEach((d)=>{
                    let param = {};
                    if (d.type == "element" && d.name == "member" && d.attributes["values"]) { param.value = d.attributes["values"]; };
                    parsed.params.push({...param, ...parseParam(d.children)});
                });
            };

            parsed.params = parsed.params.filter((p)=>!!p.name);

            return parsed;
        }).filter((obj)=>(Object.keys(obj).length > 0));
    };

    //
    let parseRequirements = (types)=>{
        let requirements = {};
        types.map((T)=>{
            
            if (T.attributes["name"] && T.attributes["requires"]) {
                requirements[T.attributes["name"]] = T.attributes["requires"];
            };

        });
        return requirements;
    };

    // TODO: more details
    let parseTypes = (types)=>{
        return types.map((T)=>{
            let parsed = {};
            if (T.children) {
                T.children.forEach((d)=>{
                    if (d.type == "element" && d.name == "type") { parsed.type = d.children[0].text; };
                    if (d.type == "element" && d.name == "name") { parsed.name = d.children[0].text; };
                });
            };
            return parsed;
        }).filter((obj)=>(Object.keys(obj).length > 0));
    };

    // 
    let getComponents = (doc)=>{
        let registry = filterNoSpaced(JSON5.parse(JSON5.stringify(doc.children.find((e,i)=>{ return e.type == "element" && e.name == "registry"; }))));
        let types = filterNoSpaced(registry.children.find((e,i)=>{ return e.type == "element" && e.name == "types"; }));
        let structs = types.children.filter((e,i)=>{ return e.type == "element" && e.name == "type" && e.attributes["category"] == "struct"; }).map(filterNoSpaced).filter(noSpaces);
        let extensions = filterNoSpaced(registry.children.find((e,i)=>{ return e.type == "element" && e.name == "extensions"; }));
        let commands = registry.children.filter((e,i)=>{ return e.type == "element" && e.name == "commands"; }).map(filterNoSpaced);
        return { registry, types, structs, extensions, commands };
    };

    

    //
    let extractChildren = (e)=>{
        return e.children;
    }

    //
    let commandParse = (command)=>{
        let cmds = [...(command.children||[])];
        let proto = parseParam(cmds.shift()?.children||[]);
        let params = cmds.map(extractChildren).map(parseParam);
        return { proto, params: params.filter((p)=>!!p.name) };
    };

    //
    let parseCommands = (commands)=>{
        return commands.map(commandParse).filter((cmd)=>!!cmd.proto.name);
    }

    // 
    let extract = (ec)=>{
        return ec.children.find((en,ind)=>{ return en.type=="text"; }).text;
    };

    // 
    let memberByName = (e,name)=>{
        return e.children ? e.children.find((em,im)=>{
            if (em.type == "element" && em.name == "member") {

                return !!em.children.find((ec,ic)=>{ 
                    return ec.type=="element" && ec.name=="name" && extract(ec).includes(name);
                });

            };
            return false;
        }) : null;
    };

    // 
    let filterSType = (structs)=>{
        return structs.filter((e,i)=>{ 
            return !!memberByName(e,"sType");
        });
    };

    // 
    let formSTypeMap = (hasSType)=>{
        let sTypeMap = {};
        hasSType.map((e,i)=>{
            let sType = memberByName(e,"sType");
            let defVal = sType.attributes["values"];
            if (defVal) {
                sTypeMap[defVal] = e.attributes["name"];
            };
        });
        return sTypeMap;
    };

    // 
    let formExtensionTypeMap = (extensions)=>{
        let usedBy = {};
        extensions.children.filter((e,i)=>{
            return e.type == "element" && e.name == "extension";
        }).map((e,i)=>{
            let extName = e.attributes["name"];
            e.children.filter((ec,ic)=>{  return ec.type == "element" && ec.name == "require"; }).map((ec,ic)=>{
                ec.children.filter((em,im)=>{ return em.type == "element" && !!em.name; }).map((em,im)=>{
                    usedBy[em.attributes["name"]] = extName;
                });
            });
        });
        return usedBy;
    };

    // 
    let parseDocs = async (path = "../../Vulkan-Docs/xml/vk.xml")=>{
        let docs = await getDocs(path); await fs.promises.writeFile("vulkan.json", JSON.stringify(filterNoSpaced(JSON5.parse(JSON5.stringify(docs))), null, 2).trim(), "utf8");
        let loaded = getComponents(docs); 
        await fs.promises.writeFile("commands.json", JSON.stringify(loaded.commands, null, 2).trim(), "utf8");
        await fs.promises.writeFile("types.json", JSON.stringify(loaded.types, null, 2).trim(), "utf8");
        
        //
        let parsed = parseCommands(loaded.commands[0].children);
        await fs.promises.writeFile("parsed-commands.json", JSON.stringify(parsed, null, 2).trim(), "utf8");

        let parsedStructs = parseStructs(loaded.types.children);
        let parsedTypes = parseTypes(loaded.types.children);
        let parsedRequirements = parseRequirements(loaded.types.children);
        await fs.promises.writeFile("parsed-types.json", JSON.stringify(parsedTypes, null, 2).trim(), "utf8");
        await fs.promises.writeFile("parsed-requirements.json", JSON.stringify(parsedRequirements, null, 2).trim(), "utf8");
        await fs.promises.writeFile("parsed-structs.json", JSON.stringify(parsedStructs, null, 2).trim(), "utf8");

        //
        let usedBy = formExtensionTypeMap(loaded.extensions);
        let sTypeMap = formSTypeMap(filterSType(loaded.structs));
        await fs.promises.writeFile("used-by.json", JSON.stringify(usedBy, null, 2).trim(), "utf8");
        return {usedBy, sTypeMap, parsed, parsedStructs, parsedRequirements, parsedTypes};
    };

    return {
        getComponents, 
        getDocs,
        parseDocs
    };
};

export default getReader;