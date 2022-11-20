//
const isAbv = (value) => {
    return value && value.byteLength != undefined && (value instanceof ArrayBuffer);
}

//
const IsNumber = (index) => {
    return typeof index == "number" || typeof index == "bigint" || Number.isInteger(index) || typeof index == "string" && /^\+?\d+$/.test(index.trim());
}

// 
const asBigInt = (value)=>{
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
    if (typeof value == "string") {
        return value.charAddress();
    } else 
    if (typeof value == "object" && value.address) {
        return value.address();
    }
    return BigInt(value);
}

//
const Types = {};

// 
class ConstructProxy {
    constructor(target) {
        this.target = target;
    }
    construct(_stub, args) {
        new _stub(...args);
        let classed = null;
        if (typeof this.target == "string") {
            classed = Types[this.target].construct(...args);
        } else {
            classed = this.target.construct(...args);
        }
        return classed;
    }
}

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
        if (["byteLength"].indexOf(index) >= 0) {
            return this[index];
        }
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
    }

    get(Target, index) {
        if (!isConstructor(Target)) {
            if (IsNumber(index)) {
                return this._get(Target, parseInt(index));
            } else 
            if (["byteLength", "byteOffset", "length"].indexOf(index) >= 0) {
                return Target[index];
            } else 
            if (["address", "set"].indexOf(index) >= 0) {
                return Target[index].bind(Target);
            }
        }
        return null;
    }

    set(Target, index, value) {
        if (!isConstructor(Target)) {
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
    return target[index];
}

//
const getBigInt = (Target, index = 0) => {
    return target[index];
}

//
const getFloat = (Target, index = 0) => {
    return target[index];
}

//
const setFloat = (Target, index = 0, value = 0) => {
    target[index] = parseFloat(value);
}

//
const setInt = (Target, index = 0, value = 0) => {
    target[index] = parseInt(value);
}

//
const setBigInt = (Target, index = 0, value = 0n) => {
    target[index] = asBigInt(value);
}

// default accessor types
new NumberAccessor("u8", 1, (dv, offset)=>{ return dv.getUint8(parseInt(offset), true); }, (dv, offset, value)=>{ dv.setUint8(parseInt(offset), parseInt(value), true); });
new NumberAccessor("i8", 1, (dv, offset)=>{ return dv.getInt8(parseInt(offset), true); }, (dv, offset, value)=>{ dv.setInt8(parseInt(offset), parseInt(value), true); });
new NumberAccessor("u16", 2, (dv, offset)=>{ return dv.getUint16(parseInt(offset), true); }, (dv, offset, value)=>{ dv.setUint16(parseInt(offset), parseInt(value), true); });
new NumberAccessor("i16", 2, (dv, offset)=>{ return dv.getInt16(parseInt(offset), true); }, (dv, offset, value)=>{ dv.setInt16(parseInt(offset), parseInt(value), true); });
new NumberAccessor("f32", 4, (dv, offset)=>{ return dv.getFloat32(parseInt(offset), true); }, (dv, offset, value)=>{ dv.setFloat32(parseInt(offset), parseFloat(value), true); });
new NumberAccessor("u32", 4, (dv, offset)=>{ return dv.getUint32(parseInt(offset), true); }, (dv, offset, value)=>{ dv.setUint32(parseInt(offset), parseInt(value), true); });
new NumberAccessor("i32", 4, (dv, offset)=>{ return dv.getInt32(parseInt(offset), true); }, (dv, offset, value)=>{ dv.setInt32(parseInt(offset), parseInt(value), true); });
new NumberAccessor("f64", 8, (dv, offset)=>{ return dv.getFloat64(parseInt(offset), true); }, (dv, offset, value)=>{ dv.setFloat64(parseInt(offset), parseFloat(value), true); });
new NumberAccessor("u64", 8, (dv, offset)=>{ return dv.getBigUint64(parseInt(offset), true); }, (dv, offset, value)=>{ dv.setBigUint64(parseInt(offset), asBigInt(value), true); });
new NumberAccessor("i64", 8, (dv, offset)=>{ return dv.getBigInt64(parseInt(offset), true); }, (dv, offset, value)=>{ dv.setBigInt64(parseInt(offset), asBigInt(value), true); });
new NumberAccessor("u24", 3, 
(dv, offset)=>{ return (dv.getUint8(parseInt(offset), true)|(dv.getUint8(parseInt(offset)+1, true)<<8)|(dv.getUint8(parseInt(offset)+2, true)<<16)); }, 
(dv, offset, value)=>{ dv.setUint8(parseInt(offset), (parseInt(value) & 0xFF), true); dv.setUint8(parseInt(offset)+1, (parseInt(value) >> 8) & 0xFF, true); dv.setUint8(parseInt(offset)+2, (parseInt(value) >> 16) & 0xFF, true); });

//
const re64 = (args)=>{
    if (typeof args[0] == "array" || Array.isArray(args[0])) { return [args[0].map(asBigInt)] };
    return args;
}

//
const rei = (args)=>{
    return args;
}

//
const ref = (args)=>{
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
    constructor(buffer, byteOffset = 0, byteLength = 0, struct = null) {
        this.buffer = buffer;
        this.byteOffset = byteOffset  + struct.byteOffset;
        this.byteLength = byteLength || struct.byteLength;
        this.type = struct.type;
        this.parent = null;
        
        //
        (this.struct = struct).types.forEach((tp)=>{
            const t = tp.type;
            const array = new t(this.buffer, this.byteOffset + tp.byteOffset, tp.byteLength);
            
            //array.parent = this; // prefer to have parent node
            Object.defineProperties(this, {
                [tp.name]: {
                    set: (v)=>{ array[0] = v; },
                    get: ()=>{ return array[0]; }
                }
            });

            //
            if (tp.dfv != undefined && tp.dfv !== null) { 
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

        if (typeof tname == "string") {
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

        return Types[tname+(length>1?"[arr]":"")]?.construct(this.buffer, this.byteOffset + offset + this.offsetof(mname));
    }

    // member utils
    offsetof(name) { return this.struct.offsetof(name); };
    bufferOffsetOf(name) { return this.byteOffset + this.offsetof(name); };
    addressOffsetOf(name) { return this.address() + this.offsetof(name); };

    set(buffer, offset = 0) {
        if (typeof buffer == "object") {
            let structed = this;
            //for (let k in buffer) { if (this.types.find((t)=>(t.name == k))) { structed[k] = buffer[k]; }; }; // reduce the some time
            for (let t of this.struct.types) { let k = t.name; if (k in buffer) { structed[k] = buffer[k]; }; }; // supports correct order
            return structed;
        }
        return this;
    }

    construct(Target, args) {
        let [buffer, byteOffset, byteLength] = args; byteOffset ||= 0, byteLength ||= 0; // NEW syntax!
        if (isAbv(buffer ? (buffer.buffer || buffer) : null)) {
            return new Proxy(new CStructView(buffer.buffer || buffer, this.byteOffset + (buffer.byteOffset||0) + byteOffset, byteLength || this.byteLength || 0, this.struct), this);
        } else 
        if (typeof buffer == "number") {
            return new Proxy(new CStructView(new ArrayBuffer(buffer), this.byteOffset + (buffer.byteOffset||0), buffer || this.byteLength, this.struct), this);
        } else 
        if (typeof buffer == "object") {
            return new Proxy(new CStructView(new ArrayBuffer(this.byteLength), 0, this.byteLength, this.struct).set(buffer), this);
        } else
        {
            return new Proxy(new CStructView(new ArrayBuffer(this.byteLength), 0, this.byteLength, this.struct), this);
        }
    }

    address() {
        return this.buffer.address() + BigInt(this.byteOffset);
    }
}

// 
class CStruct {
    constructor(name, struct, byteLength) {
        this.types = [];
        this.type = name;
        this.byteOffset = 0;
        this.byteLength = byteLength;
        this.isStruct = true;
        if (!(name in Types)) { Types[name] = new Proxy(CStructView, this); };
        //if (!(name in Types)) { Types[name] = new Proxy(function(...args){}, this); };

        //
        this.address = this.address.bind(this);

        //
        let prev = undefined;
        for (let name in struct) {
            let length = 1;
            let offset = 0;
            let tname = null;
            let type = null;
            let dfv = null;

            if (typeof struct[name] == "object" && struct[name].type) {
                type = struct[name];
            } else
            if (typeof struct[name] == "string") {
                tname = struct[name];
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
                if (tname.indexOf(":") >= 0) {
                    let names = tname.split(":");
                    tname = names[0];
                    dfv = names[1];
                }
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
            if (!type) { type = Types[tname+(length>1?"[arr]":"")]; };

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
        };
    }

    get(Target, index) {
        if (!isConstructor(Target)) {
            if (Target.struct.types.find((t)=>(t.name==index))) {
                return Target[index];
            } else
            if (["length", "byteOffset", "byteLength"].indexOf(index) >= 0) {
                return Target[index];
            } else 
            if (["set", "address", "as", "offsetof", "bufferOffsetOf", "addressOffsetOf"].indexOf(index) >= 0) {
                return Target[index].bind(Target);
            }
        }
        return null;
    }

    set(Target, index, value) {
        if (!isConstructor(Target)) {
            if (Target.struct.types.find((t)=>(t.name==index))) {
                Target[index] = value;
                return true;
            }
        }
    }

    offsetof(name) {
        return this.types.find((e)=>(e.name==name))?.byteOffset || 0;
    }

    // TODO: make as constructor for Proxy
    construct(Target, args) {
        let [buffer, byteOffset, byteLength] = args; byteOffset ||= 0, byteLength ||= 0; // NEW syntax!
        if (isAbv(buffer ? (buffer.buffer || buffer) : null)) {
            return new Proxy(new CStructView(buffer.buffer || buffer, (buffer.byteOffset||0) + byteOffset, byteLength || this.byteLength || 1, this), this);
        } else 
        if (typeof buffer == "number") {
            return new Proxy(new CStructView(new ArrayBuffer(buffer || this.byteLength), (buffer.byteOffset||0), buffer || this.byteLength || 1, this), this);
        } else 
        if (typeof buffer == "object") {
            return new Proxy(new CStructView(new ArrayBuffer(byteLength || this.byteLength), 0, this.byteLength, this).set(buffer), this);
        } else
        {
            return new Proxy(new CStructView(new ArrayBuffer(this.byteLength), 0, this.byteLength, this), this);
        }
    }

    address() {
        return this.buffer.address() + BigInt(this.byteOffset);
    }
}

//
export default { CStruct, CStructView, Types, ConstructProxy };
