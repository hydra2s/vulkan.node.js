//
const isAbv = (value) => {
    return value && value.byteLength != undefined && (value instanceof ArrayBuffer);
}

//
const IsNumber = (index) => {
    return typeof index == "number" || typeof index == "bigint" || Number.isInteger(index) || typeof index == "string" && /^\+?\d+$/.test(index.trim());
}

//
const EncoderUTF8 = new TextEncoder(); //U8Cache

// 
const AsBigInt = (value)=>{
    if (!value) {
        return 0n;
    } else
    if (IsNumber(value)) {
        return BigInt(value);
    } else
    if (ArrayBuffer.isView(value)) {
        return value.address();
    } else 
    if (value instanceof ArrayBuffer || value instanceof SharedArrayBuffer) {
        return value.address();
    } else 
    if (value instanceof Buffer) {
        return value.address();
    } else
    if (value instanceof Array || Array.isArray(value)) {
        return (new Types["u64[arr]"](value)).address(); // present as u64 array
    } else
    if (typeof value == "string") { // LTE - лучший тибетский интернет!
        const arrayBuffer = new ArrayBuffer(value.length);
        EncoderUTF8.encodeInto(value, new Uint8Array(arrayBuffer, 0, value.length));
        return arrayBuffer.address();
    } else 
    if (typeof value == "object" && value.address) {
        return value.address();
    }
    return BigInt(value);
}

//
const Types = {};

// TODO: add getters and methods support, from alias
class ConstructProxy {
    constructor(target) {
        this.target = target;
    }
    construct(_stub, args) {
        //new _stub(...args);
        let classed = null;
        if (typeof this.target == "string") {
            classed = new Types[this.target](...args);
        } else {
            classed = new this.target(...args);
        }
        return classed;
    }
}

//
function isConstructor(obj) {
    return !!obj.prototype && !!obj.prototype.constructor.name;
}

// 
class NumberAccessor {
    constructor(name, byteLength, get, set, construct = DataView, bigEndian = false) {
        if (!(name in Types)) { Types[name] = new Proxy(this._class = construct, this); };
        this.type = name;
        this.bigEndian = bigEndian;
        this._get = get;//.bind(this);
        this._set = set;//.bind(this);
        this.byteLength = byteLength;
    }

    get(Target, index) {
        if (index == "type") { return this.type; };
        if (index == "BYTES_PER_ELEMENT") { return 1; }
        if (["byteLength"].indexOf(index) >= 0) {
            return this[index];
        } else
        if (index == "length") {
            return 1;
        } else
        if (!isConstructor(Target)) {
            return this._get(Target, index);
        }
        return null;
    }

    set(Target, index, value) {
        if (!isConstructor(Target)) {
            this._set(Target, index, value);
            return true;
        }
    }

    construct(Target, args) {
        if (args.length >= 3) { args[2] = (args[2]||1) * this.byteLength; } else if (args.length >= 2) { args.push(this.byteLength); } else if (args.length >= 1) { args.push(0); args.push(this.byteLength); };
        return new Proxy(new Target(...args), this);
    }
}

// 
class ArrayAccessor {
    constructor(name, byteLength, get, set, construct, handler, bigEndian = false) {
        if (!((name+"[arr]") in Types)) { Types[name+"[arr]"] = new Proxy(this._class = construct, this); };
        this.type = name+"[arr]";
        this.bigEndian = bigEndian;
        this._get = get;
        this._set = set;
        this.byteLength = byteLength;
        this.handler = handler;
        this.isArray = true;
    }

    get(Target, index) {
        if (index == "type") { return this.type; };
        if (index == "BYTES_PER_ELEMENT") { return Target[index]; }
        if (index == "fromAddress") { return Target[index].bind(Target); }
        if (index == "isArray") { return true; };
        if (!isConstructor(Target)) {
            if (index == "") {
                return new Proxy(Target, this);
            } else
            if (IsNumber(index)) {
                return this._get(Target, parseInt(index));
            } else 
            if (["byteLength", "byteOffset", "length"].indexOf(index) >= 0) {
                return Target[index];
            } else 
            if (["address", "set"].indexOf(index) >= 0) {
                return Target[index].bind(Target);
            }
        } else {
            if (index == "byteLength") { return this.byteLength; };
        }
        return null;
    }

    set(Target, index, value) {
        if (!isConstructor(Target)) {
            if (index == "") {
                Target.set(value);
                return true;
            } else
            if (IsNumber(index)) {
                this._set(Target, index, value);
                return true;
            }
        }
    }

    construct(Target, args) {
        return new Proxy(new Target(...this.handler(args)), this);
    }
}

//
const getInt = (Target, index = 0) => {
    return Target[index];
}

//
const getBigInt = (Target, index = 0) => {
    return Target[index];
}

//
const getFloat = (Target, index = 0) => {
    return Target[index];
}

//
const setFloat = (Target, index = 0, value = 0) => {
    Target[index] = parseFloat(value);
}

//
const setInt = (Target, index = 0, value = 0) => {
    Target[index] = parseInt(value);
}

//
const setBigInt = (Target, index = 0, value = 0n) => {
    Target[index] = AsBigInt(value);
}

// default accessor types
new NumberAccessor("u8", 1, (dv, offset)=>{ return dv.getUint8(parseInt(offset)||0, true); }, (dv, offset, value)=>{ dv.setUint8(parseInt(offset)||0, parseInt(value), true); });
new NumberAccessor("i8", 1, (dv, offset)=>{ return dv.getInt8(parseInt(offset)||0, true); }, (dv, offset, value)=>{ dv.setInt8(parseInt(offset)||0, parseInt(value), true); });
new NumberAccessor("u16", 2, (dv, offset)=>{ return dv.getUint16(parseInt(offset)||0, true); }, (dv, offset, value)=>{ dv.setUint16(parseInt(offset)||0, parseInt(value), true); });
new NumberAccessor("i16", 2, (dv, offset)=>{ return dv.getInt16(parseInt(offset)||0, true); }, (dv, offset, value)=>{ dv.setInt16(parseInt(offset)||0, parseInt(value), true); });
new NumberAccessor("f32", 4, (dv, offset)=>{ return dv.getFloat32(parseInt(offset)||0, true); }, (dv, offset, value)=>{ dv.setFloat32(parseInt(offset)||0, parseFloat(value), true); });
new NumberAccessor("u32", 4, (dv, offset)=>{ return dv.getUint32(parseInt(offset)||0, true); }, (dv, offset, value)=>{ dv.setUint32(parseInt(offset)||0, parseInt(value), true); });
new NumberAccessor("i32", 4, (dv, offset)=>{ return dv.getInt32(parseInt(offset)||0, true); }, (dv, offset, value)=>{ dv.setInt32(parseInt(offset)||0, parseInt(value), true); });
new NumberAccessor("f64", 8, (dv, offset)=>{ return dv.getFloat64(parseInt(offset)||0, true); }, (dv, offset, value)=>{ dv.setFloat64(parseInt(offset)||0, parseFloat(value), true); });
new NumberAccessor("u64", 8, (dv, offset)=>{ return dv.getBigUint64(parseInt(offset)||0, true); }, (dv, offset, value)=>{ dv.setBigUint64(parseInt(offset)||0, AsBigInt(value), true); });
new NumberAccessor("i64", 8, (dv, offset)=>{ return dv.getBigInt64(parseInt(offset)||0, true); }, (dv, offset, value)=>{ dv.setBigInt64(parseInt(offset)||0, AsBigInt(value), true); });
new NumberAccessor("u24", 3, 
(dv, offset)=>{ return (dv.getUint8(parseInt(offset)||0, true)|(dv.getUint8((parseInt(offset)||0)+1, true)<<8)|(dv.getUint8((parseInt(offset)||0)+2, true)<<16)); }, 
(dv, offset, value)=>{ dv.setUint8(parseInt(offset)||0, (parseInt(value) & 0xFF), true); dv.setUint8((parseInt(offset)||0)+1, (parseInt(value) >> 8) & 0xFF, true); dv.setUint8((parseInt(offset)||0)+2, (parseInt(value) >> 16) & 0xFF, true); });

//
const re64 = (args)=>{
    if (typeof args[0] == "array" || Array.isArray(args[0])) { return [args[0].map(AsBigInt)] };
    if (IsNumber(args[0])) { return [parseInt(args[0])]; };
    if (isAbv(args[0]?.buffer || args[0])) { // PMV
        if (args.length < 2) { args.push(0); };
        if (args.length < 3) { args.push(1); };
        return args;
    }
    return args;
}

//
const rei = (args)=>{
    if (IsNumber(args[0])) { return [parseInt(args[0])]; };
    if (isAbv(args[0]?.buffer || args[0])) { // PMV
        if (args.length < 2) { args.push(0); };
        if (args.length < 3) { args.push(1); };
        return args;
    }
    return args;
}

//
const ref = (args)=>{
    if (IsNumber(args[0])) { return [parseInt(args[0])]; };
    if (isAbv(args[0]?.buffer || args[0])) { // PMV
        if (args.length < 2) { args.push(0); };
        if (args.length < 3) { args.push(1); };
        return args;
    }
    return args;
}

// default array types
new ArrayAccessor("u8", 1, getInt, setInt, Uint8Array, rei);
new ArrayAccessor("i8", 1, getInt, setInt, Int8Array, rei);
new ArrayAccessor("u16", 2, getInt, setInt, Uint16Array, rei);
new ArrayAccessor("i16", 2, getInt, setInt, Int16Array, rei);
new ArrayAccessor("f32", 4, getFloat, setFloat, Float32Array, ref);
new ArrayAccessor("u32", 4, getInt, setInt, Uint32Array, rei);
new ArrayAccessor("i32", 4, getInt, setInt, Int32Array, rei);
new ArrayAccessor("f64", 8, getFloat, setFloat, Float64Array, ref);
new ArrayAccessor("u64", 8, getBigInt, setBigInt, BigUint64Array, re64);
new ArrayAccessor("i64", 8, getBigInt, setBigInt, BigInt64Array, re64);

// 
class CStructView {
    constructor(buffer, byteOffset = 0, length = 0, struct = null) {
        this.buffer = buffer;
        this.byteOffset = byteOffset + struct.byteOffset;
        this.byteLength =     length * struct.byteLength;
        this.type = struct.type;
        this.parent = null;
        this.length = length;

        // implicit support for type-casting and setting
        Object.defineProperties(this, {
            [""]: {
                set: (v)=>{ this.set(v); },
                get: ()=>{ return new Proxy(this, this.struct)[""]; }
            }
        });

        //
        (this.struct = struct).types.forEach((tp)=>{
            // use F32 fallback for Vulkan API types
            const array = new (tp.type || Types[length > 1 ? "u32[arr]" : "u32"])(this.buffer, this.byteOffset + tp.byteOffset, tp.length);
            
            //array.parent = this; // prefer to have parent node
            Object.defineProperties(this, {
                [tp.name]: {
                    set: (v)=>{ array[""] = v; },
                    get: ()=>{ return array[""]; }
                }
            });

            // if has default value, but not set already
            if (tp.dfv != undefined && tp.dfv !== null && !this[tp.name]) { 
                this[tp.name] = tp.dfv;
            };
        });

        // re-bind for native
        this.address = this.address.bind(this);
    }

    // for conversion struct or member
    as(tname, mname = "") {
        let length = 1;
        let offset = 0;
        let dfv = null;
        let type = null;

        if ((typeof tname == "object" || typeof tname == "function") && tname.type) {
            type = tname;
        } else

        if (typeof tname == "string") {
            if (tname.indexOf(";") >= 0) {
                let names = tname.split(";");
                tname = names[0];
                if (names.length >= 2 && names[1] && names[1] != "undefined") {
                    dfv = JSON.parse(names[1]);//JSON.parse(`{"_stub":${names[1]||0}}`)["_stub"];
                }
            };
            if (tname.indexOf("[") >= 0 && tname.indexOf("]") >= 0) {
                let match = tname.match(/\[(-?\d+)\]/);
                length = (match ? parseInt(match[1]) : 1) || 1;
                tname = tname.replace(/\[\d+\]/g, "");
            };
            if (tname.indexOf("(") >= 0 && tname.indexOf(")") >= 0) {
                let match = tname.match(/\((-?\d+)\)/);
                offset = (match ? parseInt(match[1]) : 0) || 0;
                tname = tname.replace(/\(\d+\)/g, "");
            };
        } else 

        if (typeof tname == "array") {
            length = tname[2] || 1;
            offset = tname[1] || 0;
            tname = tname[0];
        }

        if (!type) { type = Types[tname+(length>1?"[arr]":"")] || Types[tname]; };
        return new type(this.buffer, this.byteOffset + offset + (this.offsetof(mname)||0), (length||1))[""];
    }

    // fix extra vars problems, make as object and read-only de-facto
    serialize() {
        let obj = {};
        for (let t of this.struct.types) { 
            obj[t.name] = typeof this[t.name].serialize == "function" ? this[t.name].serialize() : this[t.name];
        };
        return obj;
    }

    // member utils
    lengthof(name) { return this.struct.lengthof(name); };
    offsetof(name) { return this.struct.offsetof(name); };
    bufferOffsetOf(name) { return this.byteOffset + this.offsetof(name); };
    addressOffsetOf(name) { return this.address() + this.offsetof(name); };

    //
    set(buffer, offset = 0) {
        if (typeof buffer == "object") {
            //let structed = this;
            //for (let k in buffer) { if (this.types.find((t)=>(t.name == k))) { structed[k] = buffer[k]; }; }; // reduce the some time
            //for (let t of this.struct.types) { let k = t.name; if (k in buffer) { structed[k] = buffer[k]; }; }; // supports correct order
            //return structed;

            // serialization are required for avoid keys conflicts
            buffer = typeof buffer.serialize == "function" ? buffer.serialize() : buffer;

            //
            let types = [], raws = [];
            let keys = Object.keys(buffer).map((k,i)=>{
                let names = k.split(":")||[];
                types.push(names[1]), raws.push(k);
                return names[0]||k;
            });

            let structed = this;
            //for (let k in buffer) { if (this.struct.types.find((t)=>(t.name == k))) { structed[k] = buffer[k]; }; }; // reduce the some time

            for (let t of this.struct.types) { 
                let k = t.name, f = keys.indexOf(k), type = types[f];
                if (f >= 0) 
                    if (type) 
                        { structed.as(type, k)[""] = (buffer[k] || buffer[raws[f]]); } else 
                        { structed[k] = (buffer[k] || buffer[raws[f]]); }
            }; // supports correct order
            return structed;
        }
        return this;
    }

    address() {
        return this.buffer.address() + BigInt(this.byteOffset);
    }
}

// 
class CStruct {
    constructor(name, struct, byteLength) {
        this.struct = struct;
        this.type = name;
        this.byteOffset = 0;
        this.byteLength = byteLength || 0;
        this.isStruct = true;
        if (!(name in Types)) { this._class = Types[name] = new Proxy(CStructView, this); };
        this.address = this.address.bind(this);
    }

    gerenateTypeTable() {
        if (!this.types) { this.types = [];
            const name = this.type, struct = this.struct, byteLength = this.byteLength;
            
            let prev = undefined;
            for (let name in struct) {
                let length = 1;
                let offset = 0;
                let tname = null;
                let type = null;
                let dfv = null;

                if ((typeof struct[name] == "object" || typeof struct[name] == "function") && struct[name].type) {
                    type = struct[name];
                } else
                if (typeof struct[name] == "string") {
                    tname = struct[name];

                    if (tname.indexOf(";") >= 0) {
                        let names = tname.split(";");
                        tname = names[0];
                        if (names.length >= 2 && names[1] && names[1] != "undefined") {
                            dfv = JSON.parse(names[1]);//JSON.parse(`{"_stub":${names[1]||0}}`)["_stub"];
                        }
                    };
                    if (tname.indexOf("[") >= 0 && tname.indexOf("]") >= 0) {
                        let match = tname.match(/\[(-?\d+)\]/);
                        length = (match ? parseInt(match[1]) : 1) || 1;
                        tname = tname.replace(/\[\d+\]/g, "");
                    };
                    if (tname.indexOf("(") >= 0 && tname.indexOf(")") >= 0) {
                        let match = tname.match(/\((-?\d+)\)/);
                        offset = (match ? parseInt(match[1]) : 0) || 0;
                        tname = tname.replace(/\(\d+\)/g, "");
                    };
                    
                } else 
                if (typeof struct[name] == "array") {
                    length = struct[name][2] || 1;
                    offset = struct[name][1] || 0;
                    if (typeof struct[name] == "object" && struct[name].type) {
                        type = struct[name][0];
                    } else {
                        tname = struct[name][0];
                    }
                }

                // correctify offset, if not defined
                if (!offset && prev != undefined) { offset = this.types[prev].byteOffset + this.types[prev].byteLength; }; 
                if (!type) { type = Types[tname+(length>1?"[arr]":"")] || Types[tname]; }; // fallback by not-arrayed

                //
                prev = this.types.length; this.types.push({type, dfv, name, length, byteOffset: offset, byteLength: (type?.byteLength || 1) * length });

                //
                this.types = this.types.sort(function(a, b) {
                    if (a.byteOffset < b.byteOffset) return -1;
                    if (a.byteOffset > b.byteOffset) return 1;
                    return 0;
                });
            }

            // if length is not defined
            if (!this.byteLength && this.types.length >= 1) { 
                this.byteLength = this.types[this.types.length-1].byteOffset + this.types[this.types.length-1].byteLength; 
            }
        }
        
    }

    fromAddress(address, length=1) {
        return new this._class(ArrayBuffer.fromAddress(AsBigInt(address), length * this.byteLength), 0, length * this.byteLength);
    }

    get(Target, index) {
        if (!isConstructor(Target)) {
            if (index == "") {
                return new Proxy(Target, this);
            } else
            if (IsNumber(index)) {
                index = parseInt(index);
                return new this._class(Target.buffer, Target.byteOffset + this.byteLength * index, Target.byteLength - this.byteLength * index)[""];
            } else 
            if (["length", "byteOffset", "byteLength"].indexOf(index) >= 0) {
                return Target[index];
            } else 
            if (["set", "address", "as", "offsetof", "bufferOffsetOf", "addressOffsetOf", "serialize"].indexOf(index) >= 0) {
                return Target[index].bind(Target);
            } else 
            if (typeof index == "string") {
                // TODO: make function for splitting index string
                let names = (index.startsWith(":") ? ["", index.substring(1)] : index.split(":"))||[]; if (index.startsWith(":")) index = ""; index = names[0]||index; let type = names[1];
                if (Target.struct.types.find((t)=>(t.name==index)) || index == "") {
                    return type ? Target.as(type, index)[""] : Target[index];
                }
            }
        } else {
            this.gerenateTypeTable();
            if (index == "fromAddress") { return this.fromAddress.bind(this); };
            if (index == "type") { return this.type; };
            if (index == "sizeof") { return this.byteLength; };
            if (index == "byteLength") { return this.byteLength; };
            if (index == "BYTES_PER_ELEMENT") { return this.byteLength; };
        }
        return null;
    }

    set(Target, index, value) {
        if (!isConstructor(Target)) {
            if (index == "") {
                Target.set(value);
                return true;
            } else
            if (IsNumber(index)) {
                index = parseInt(index);
                new this._class(Target.buffer, Target.byteOffset + this.byteLength * index, (Target.length||1) - index)[""] = value;
                return true;
            } else 
            if (typeof index == "string") {
                // TODO: make function for splitting index string
                let names = (index.startsWith(":") ? ["", index.substring(1)] : index.split(":"))||[]; if (index.startsWith(":")) index = ""; index = names[0]||index; let type = names[1];
                if (Target.struct.types.find((t)=>(t.name==index)) || index == "") {
                    if (type) 
                        { Target.as(type, index)[""] = value; } else
                        { Target[index] = value; }
                    return true;
                }
            }
        }
    }

    lengthof(name) {
        this.gerenateTypeTable();
        let type = this.types.find((e)=>(e.name==name)) || this;
        return (type?.byteLength || 1) / (type?.BYTES_PER_ELEMENT || 1);
    }

    offsetof(name) {
        this.gerenateTypeTable();
        return (this.types.find((e)=>(e.name==name)) || this)?.byteOffset || 0;
    }

    // 
    construct(Target, args) {
        //
        this.gerenateTypeTable();

        //
        let [buffer, byteOffset, length] = args; byteOffset ||= 0, length ||= 1; // NEW syntax!
        if (isAbv(buffer ? (buffer.buffer || buffer) : null)) {
            return new Proxy(new CStructView(buffer.buffer || buffer, (buffer.byteOffset||0) + byteOffset, length || 1, this), this);
        } else 
        if (typeof buffer == "number") {
            return new Proxy(new CStructView(new ArrayBuffer((this.byteLength * buffer) || 1), 0, buffer || 1, this), this);
        } else 
        if (typeof buffer == "object") {
            return new Proxy(new CStructView(new ArrayBuffer(this.byteLength || 1), 0, 1, this).set(buffer), this);
        } else
        {
            return new Proxy(new CStructView(new ArrayBuffer(this.byteLength || 1), 0, 1, this), this);
        }
    }

    address() {
        return this.buffer.address() + BigInt(this.byteOffset);
    }
}

//
export default { CStruct, CStructView, Types, ConstructProxy, AsBigInt, EncoderUTF8 };
