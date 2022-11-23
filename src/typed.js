//
const isAbv = (value) => {
    return value && value.byteLength != undefined && (value instanceof ArrayBuffer);
}

//
const IsNumber = (index) => {
    return typeof index == "number" || typeof index == "bigint" || Number.isInteger(index) || typeof index == "string" && index.trim() != "" && /^\+?\d+$/.test(index.trim());
}

//
const EncoderUTF8 = new TextEncoder(); //U8Cache

//
String.prototype.vsplit = function(symbol){
    if (this != "") {
        return (this.startsWith(symbol) ? ["", ...this.substring(1).vsplit()] : this.split(symbol))||[this];
    }
    return [this];
}

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

//
class TypePrototype {
    // for conversion struct or member
    as(Target, tname, mname = "") {
        let length = 1;
        let offset = 0;
        let dfv = null;
        let type = null;

        if ((typeof tname == "object" || typeof tname == "function") && tname.type) {
            type = tname;
        } else

        if (typeof tname == "string") {
            if (tname.indexOf(";") >= 0) {
                [tname, dfv] = tname.vsplit(";");
                if (dfv == "undefined") dfv = null;
            };
            if (tname.indexOf("[") >= 0 && tname.indexOf("]") >= 0) {
                let match = tname.match(/\[(-?\d+)\]/);
                length = (match ? parseIntFix(match[1]) : 1) || 1;
                tname = tname.replace(/\[\d+\]/g, "");
            };
            if (tname.indexOf("(") >= 0 && tname.indexOf(")") >= 0) {
                let match = tname.match(/\((-?\d+)\)/);
                offset = (match ? parseIntFix(match[1]) : 0) || 0;
                tname = tname.replace(/\(\d+\)/g, "");
            };
        } else 

        if (typeof tname == "array") {
            length = tname[2] || 1;
            offset = tname[1] || 0;
            tname = tname[0];
        }

        if (!type) { type = Types[tname+(length>1?"[arr]":"")] || Types[tname]; };
        return new type(Target.buffer, Target.byteOffset + offset + (Target.offsetof(mname)||0), (length||1))[""];
    }

    get(Target, index) {
        if (index == "BYTES_PER_ELEMENT") { return Target[index]; }
        if (!isConstructor(Target)) {
            if (index == "") {
                return this._get ? this._get(Target) : new Proxy(Target, this);
                //return new Proxy(Target, this);
            } else
            if (IsNumber(index)) {
                return this._get ? this._get(Target, parseIntFix(index)) : Target[parseIntFix(index)];
            } else
            if (["byteLength", "byteOffset", "length", "_class"].indexOf(index) >= 0) {
                return Target[index];
            } else
            if (["address", "set", "offsetof"].indexOf(index) >= 0) {
                return Target[index].bind(Target);
            } else 
            if (typeof index == "string") {
                let type = null; [index, type] = index.vsplit(":");
                return type ? Target.as(type, index)[""] : Target[index];
            } else {
                return this._get ? this._get(Target, index) : Target[index];
            }
        } else {
            if (index == "prototype") { return Target.prototype; };
            if (index == "type") { return this.type; };
            if (index == "fromAddress") { return Target[index].bind(Target); }
            if (index == "byteLength") { return this.byteLength; };
        }
        return null;
    }

    set(Target, index, value) {
        //console.log(index, value, Target.set, Target);
        if (!isConstructor(Target)) {
            if (index == "") {
                if (Target.set) {
                    Target.set(value);
                }
                return this._set ? this._set(Target, "", value) : (Target[""] = value);
            } else
            if (IsNumber(index)) {
                return this._set ? this._set(Target, parseIntFix(index), value) : (Target[parseIntFix(index)] = value);
            } else
            if (typeof index == "string" && index != "") {
                let type = null; [index, type] = index.vsplit(":");
                if (type) 
                    { Target.as(type, index)[""] = value; } else
                    { Target[index] = value; }
                return true;
            } else {
                return this._set ? this._set(Target, index, value) : (Target[index] = value);
            }
        }
    }
}

//
class TypeView {
    // for conversion struct or member
    as(...args) {
        return this._class.as(this, ...args);
    }
}

// Black Jack
Object.assign(DataView.prototype, TypeView.prototype);
Object.assign(Uint8Array.prototype, TypeView.prototype);
Object.assign(Uint16Array.prototype, TypeView.prototype);
Object.assign(Uint32Array.prototype, TypeView.prototype);
Object.assign(BigUint64Array.prototype, TypeView.prototype);
Object.assign(Int8Array.prototype, TypeView.prototype);
Object.assign(Int16Array.prototype, TypeView.prototype);
Object.assign(Int32Array.prototype, TypeView.prototype);
Object.assign(BigInt64Array.prototype, TypeView.prototype);
Object.assign(Float32Array.prototype, TypeView.prototype);
Object.assign(Float64Array.prototype, TypeView.prototype);

//
class ConstructProxy extends TypePrototype {
    constructor(target) {
        super();
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
class NumberAccessor extends TypePrototype {
    constructor(name, byteLength, get, set, construct = DataView, bigEndian = false) {
        super();

        if (!(name in Types)) { Types[name] = new Proxy(this._class = construct, this); };
        this.type = name;
        this.bigEndian = bigEndian;
        this._get = get;//.bind(this);
        this._set = set;//.bind(this);
        this.byteLength = byteLength;
    }

    get(Target, index) {
        if (index == "BYTES_PER_ELEMENT") { return 1; } else
        if (index == "length") { return 1; } else
        { return super.get(Target, index); }
    }

    set(Target, index, value) {
        return super.set(Target, index, value);
    }

    construct(Target, args) {
        if (args.length >= 3) { args[2] = (args[2]||1) * this.byteLength; } else if (args.length >= 2) { args.push(this.byteLength); } else if (args.length >= 1) { args.push(0); args.push(this.byteLength); };
        return new Proxy(new Target(...args), this);
    }
}

// 
class ArrayAccessor extends TypePrototype {
    constructor(name, byteLength, get, set, construct, handler, bigEndian = false) {
        super();

        if (!((name+"[arr]") in Types)) { Types[name+"[arr]"] = new Proxy(this._class = construct, this); };
        this.type = name+"[arr]";
        this.bigEndian = bigEndian;
        this._get = (...args) => { return IsNumber(args[1]) ? get.bind(this)(...args) : new Proxy(args[0], this); }
        this._set = (...args) => { return set.bind(this)(...args); /*return new Proxy(args[0], this);*/ }
        this.byteLength = byteLength;
        this.handler = handler;
        this.isArray = true;
    }

    get(Target, index) {
        return super.get(Target, index);
    }

    set(Target, index, value) {
        return super.set(Target, index, value);
    }

    construct(Target, args) {
        return new Proxy(new Target(...this.handler(args)), this);
    }
}

//
const parseIntFix = (index) => {
    return IsNumber(index) ? parseInt(index) : 0;
}

//
const parseFloatFix = (index) => {
    return IsNumber(index) ? parseFloat(index) : 0;
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
    Target[index] = parseFloatFix(value); return true;
}

//
const setInt = (Target, index = 0, value = 0) => {
    Target[index] = parseIntFix(value); return true;
}

//
const setBigInt = (Target, index = 0, value = 0n) => {
    Target[index] = AsBigInt(value); return true;
}

// default accessor types
new NumberAccessor("u8", 1, (dv, offset=0)=>{ return dv.getUint8(parseIntFix(offset)||0, true); }, (dv, offset, value)=>{ dv.setUint8(parseIntFix(offset)||0, parseIntFix(value), true); return true; });
new NumberAccessor("i8", 1, (dv, offset=0)=>{ return dv.getInt8(parseIntFix(offset)||0, true); }, (dv, offset, value)=>{ dv.setInt8(parseIntFix(offset)||0, parseIntFix(value), true); return true; });
new NumberAccessor("u16", 2, (dv, offset=0)=>{ return dv.getUint16(parseIntFix(offset)||0, true); }, (dv, offset, value)=>{ dv.setUint16(parseIntFix(offset)||0, parseIntFix(value), true); return true; });
new NumberAccessor("i16", 2, (dv, offset=0)=>{ return dv.getInt16(parseIntFix(offset)||0, true); }, (dv, offset, value)=>{ dv.setInt16(parseIntFix(offset)||0, parseIntFix(value), true); return true; });
new NumberAccessor("f32", 4, (dv, offset=0)=>{ return dv.getFloat32(parseIntFix(offset)||0, true); }, (dv, offset, value)=>{ dv.setFloat32(parseIntFix(offset)||0, parseFloatFix(value), true); return true; });
new NumberAccessor("u32", 4, (dv, offset=0)=>{ return dv.getUint32(parseIntFix(offset)||0, true); }, (dv, offset, value)=>{ dv.setUint32(parseIntFix(offset)||0, parseIntFix(value), true); return true; });
new NumberAccessor("i32", 4, (dv, offset=0)=>{ return dv.getInt32(parseIntFix(offset)||0, true); }, (dv, offset, value)=>{ dv.setInt32(parseIntFix(offset)||0, parseIntFix(value), true); return true; });
new NumberAccessor("f64", 8, (dv, offset=0)=>{ return dv.getFloat64(parseIntFix(offset)||0, true); }, (dv, offset, value)=>{ dv.setFloat64(parseIntFix(offset)||0, parseFloatFix(value), true); return true; });
new NumberAccessor("u64", 8, (dv, offset=0)=>{ return dv.getBigUint64(parseIntFix(offset)||0, true); }, (dv, offset, value)=>{ dv.setBigUint64(parseIntFix(offset)||0, AsBigInt(value), true); return true; });
new NumberAccessor("i64", 8, (dv, offset=0)=>{ return dv.getBigInt64(parseIntFix(offset)||0, true); }, (dv, offset, value)=>{ dv.setBigInt64(parseIntFix(offset)||0, AsBigInt(value), true); return true; });
new NumberAccessor("u24", 3, 
(dv, offset=0)=>{ return (dv.getUint8(parseIntFix(offset)||0, true)|(dv.getUint8((parseIntFix(offset)||0)+1, true)<<8)|(dv.getUint8((parseIntFix(offset)||0)+2, true)<<16)); }, 
(dv, offset, value)=>{ dv.setUint8(parseIntFix(offset)||0, (parseIntFix(value) & 0xFF), true); dv.setUint8((parseIntFix(offset)||0)+1, (parseIntFix(value) >> 8) & 0xFF, true); dv.setUint8((parseIntFix(offset)||0)+2, (parseIntFix(value) >> 16) & 0xFF, true); });

//
const re64 = (args)=>{
    if (typeof args[0] == "array" || Array.isArray(args[0])) { return [args[0].map(AsBigInt)] };
    if (IsNumber(args[0])) { return [parseIntFix(args[0])]; };
    if (isAbv(args[0]?.buffer || args[0])) { // PMV
        if (args.length < 2) { args.push(0); };
        if (args.length < 3) { args.push(1); };
        return args;
    }
    return args;
}

//
const rei = (args)=>{
    if (IsNumber(args[0])) { return [parseIntFix(args[0])]; };
    if (isAbv(args[0]?.buffer || args[0])) { // PMV
        if (args.length < 2) { args.push(0); };
        if (args.length < 3) { args.push(1); };
        return args;
    }
    return args;
}

//
const ref = (args)=>{
    if (IsNumber(args[0])) { return [parseIntFix(args[0])]; };
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
class CStructView extends TypeView {
    constructor(buffer, byteOffset = 0, length = 0, struct = null) {
        super();

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
                get: ()=>{ return new Proxy(this, this._class)[""]; }
            }
        });

        //
        (this._class = struct).types.forEach((tp)=>{
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

    

    // fix extra vars problems, make as object and read-only de-facto
    serialize() {
        let obj = {};
        for (let t of this._class.types) { 
            obj[t.name] = typeof this[t.name].serialize == "function" ? this[t.name].serialize() : this[t.name];
        };
        return obj;
    }

    // member utils
    lengthof(name) { return this._class.lengthof(name); };
    offsetof(name) { return this._class.offsetof(name); };
    bufferOffsetOf(name) { return this.byteOffset + this.offsetof(name); };
    addressOffsetOf(name) { return this.address() + this.offsetof(name); };

    //
    set(buffer, offset = 0) {
        if (typeof buffer == "object") {
            // serialization are required for avoid keys conflicts
            let types = [], raws = [];
            let keys = Object.keys(typeof buffer.serialize == "function" ? buffer.serialize() : buffer).map((k,i)=>{ 
                raws.push(k); let names = k.vsplit(":");
                types.push(names[1]); return names[0];
            });

            // prefer a proxy
            let structed = new Proxy(this, this._class);

            // needs votes and feedback!
            // supports correct order
            for (let t of this._class.types) { 
                let k = t.name, f = keys.indexOf(k), type = types[f];
                //if (f >= 0) structed[raws[f]] = (buffer[k] || buffer[raws[f]]); // may to assign as is
                if (f >= 0) structed[raws[f]] = (buffer[raws[f]] || buffer[k]); // may to typecast when getting firstly
            };
            return structed;
        }
        return this;
    }

    address() {
        return this.buffer.address() + BigInt(this.byteOffset);
    }
}

// 
class CStruct extends TypePrototype {
    constructor(name, struct, byteLength) {
        super();

        this.struct = struct;
        this.type = name;
        this.byteOffset = 0;
        this.byteLength = byteLength || 0;
        this.isStruct = true;
        if (!(name in Types)) { this._class = Types[name] = new Proxy(CStructView, this); };
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
                        let names = tname.vsplit(";");
                        tname = names[0];
                        if (names.length >= 2 && names[1] && names[1] != "undefined") {
                            dfv = JSON.parse(names[1]);//JSON.parse(`{"_stub":${names[1]||0}}`)["_stub"];
                        }
                    };
                    if (tname.indexOf("[") >= 0 && tname.indexOf("]") >= 0) {
                        let match = tname.match(/\[(-?\d+)\]/);
                        length = (match ? parseIntFix(match[1]) : 1) || 1;
                        tname = tname.replace(/\[\d+\]/g, "");
                    };
                    if (tname.indexOf("(") >= 0 && tname.indexOf(")") >= 0) {
                        let match = tname.match(/\((-?\d+)\)/);
                        offset = (match ? parseIntFix(match[1]) : 0) || 0;
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
            if (index != "" && ["bufferOffsetOf", "addressOffsetOf", "serialize"].indexOf(index) >= 0) { return Target[index].bind(Target); }
            if (IsNumber(index)) {
                return new this._class(Target.buffer, Target.byteOffset + this.byteLength * parseIntFix(index), (Target.length||1) - parseIntFix(index))[""];
            } else 
            if (typeof index == "string" && index != "") {
                let type = null; [index, type] = index.vsplit(":");
                if (index == "" || Target._class.types.find((t)=>(t.name==index))) {
                    return type ? Target.as(type, index)[""] : Target[index];
                }
            }
        } else {
            this.gerenateTypeTable();
        }
        return super.get(Target, index);
    }

    set(Target, index, value) {
        if (!isConstructor(Target)) {
            if (IsNumber(index)) {
                new this._class(Target.buffer, Target.byteOffset + this.byteLength * parseIntFix(index), (Target.length||1) - parseIntFix(index))[""] = value;
                return true;
            } else
            if (typeof index == "string" && index != "") {
                let type = null; [index, type] = index.vsplit(":");
                if (index == "" || Target._class.types.find((t)=>(t.name==index))) {
                    if (type) 
                        { Target.as(type, index)[""] = value; } else
                        { Target[index] = value; }
                }
                return true;
            }
        }
        return super.set(Target, index, value);
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
        this.gerenateTypeTable();

        //
        let [buffer, byteOffset, length] = args; byteOffset ||= 0, length ||= 1; // NEW syntax!
        let cargs = [];
        if (isAbv(buffer ? (buffer.buffer || buffer) : null)) {
            cargs = [buffer.buffer || buffer, (buffer.byteOffset||0) + byteOffset, length || 1];
        } else 
        if (typeof buffer == "number") {
            cargs = [new ArrayBuffer((this.byteLength * buffer) || 1), 0, buffer || 1];
        } else 
        if (typeof buffer == "object") {
            cargs = [new ArrayBuffer(this.byteLength || 1), 0, 1];
        } else {
            cargs = [new ArrayBuffer(this.byteLength || 1), 0, 1];
        }
        const result = new Proxy(new CStructView(...cargs, this), this);
        if (typeof buffer == "object") { result.set(buffer); };
        return result;
    }
}

//
export default { CStruct, CStructView, Types, ConstructProxy, AsBigInt, EncoderUTF8 };
