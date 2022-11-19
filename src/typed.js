//
const defaultDataConstruct = (...ags) => new DataView(...ags);
const defaultArrayGetter = (dv, offset)=>{ return dv; };
const defaultArraySetter = (dv, offset, value)=>{ dv.set(value, offset); };

//
const isAbv = (value) => {
    return value && value.byteLength != undefined && (value instanceof ArrayBuffer);
}

// TODO: special array and arrays support
const asBigInt = (value)=>{
    if (typeof value == "bigint" || typeof value == "number") {
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
    if (typeof value == "string") {
        return value.charAddress();
    } else 
    if (typeof value == "object" && value.address) {
        return value.address();
    }
    return BigInt(value);
}

//
const types = {};

//
class NumberAccessor {
    constructor(name, byteLength, getter, setter, construct = defaultDataConstruct, bigEndian = false) {
        types[name] = this;
        this.type = name;
        this.bigEndian = bigEndian;
        this.getter = getter;
        this.setter = setter;
        this.byteLength = byteLength;
        this.construct = construct;
    }
}

//
class ArrayAccessor {
    constructor(name, byteLength, getter, setter, construct, bigEndian = false) {
        types[name+"[arr]"] = this;
        this.type = name+"[arr]";
        this.bigEndian = bigEndian;
        this.getter = getter;
        this.setter = setter;
        this.byteLength = byteLength;
        this.construct = construct;
    }
}

// default accessor types
new NumberAccessor("u8", 1, (dv, offset)=>{ return dv.getUint8(offset, true); }, (dv, offset, value)=>{ dv.setUint8(offset, parseInt(value), true); }, defaultDataConstruct);
new NumberAccessor("i8", 1, (dv, offset)=>{ return dv.getInt8(offset, true); }, (dv, offset, value)=>{ dv.setInt8(offset, parseInt(value), true); }, defaultDataConstruct);
new NumberAccessor("u16", 2, (dv, offset)=>{ return dv.getUint16(offset, true); }, (dv, offset, value)=>{ dv.setUint16(offset, parseInt(value), true); }, defaultDataConstruct);
new NumberAccessor("i16", 2, (dv, offset)=>{ return dv.getInt16(offset, true); }, (dv, offset, value)=>{ dv.setInt16(offset, parseInt(value), true); }, defaultDataConstruct);
new NumberAccessor("f32", 4, (dv, offset)=>{ return dv.getFloat32(offset, true); }, (dv, offset, value)=>{ dv.setFloat32(offset, parseFloat(value), true); }, defaultDataConstruct);
new NumberAccessor("u32", 4, (dv, offset)=>{ return dv.getUint32(offset, true); }, (dv, offset, value)=>{ dv.setUint32(offset, parseInt(value), true); }, defaultDataConstruct);
new NumberAccessor("i32", 4, (dv, offset)=>{ return dv.getInt32(offset, true); }, (dv, offset, value)=>{ dv.setInt32(offset, parseInt(value), true); }, defaultDataConstruct);
new NumberAccessor("f64", 8, (dv, offset)=>{ return dv.getFloat64(offset, true); }, (dv, offset, value)=>{ dv.setFloat64(offset, parseFloat(value), true); }, defaultDataConstruct);
new NumberAccessor("u64", 8, (dv, offset)=>{ return dv.getBigUint64(offset, true); }, (dv, offset, value)=>{ dv.setBigUint64(offset, asBigInt(value), true); }, defaultDataConstruct);
new NumberAccessor("i64", 8, (dv, offset)=>{ return dv.getBigInt64(offset, true); }, (dv, offset, value)=>{ dv.setBigInt64(offset, asBigInt(value), true); }, defaultDataConstruct);
new NumberAccessor("u24", 3, 
(dv, offset)=>{ return (dv.getUint8(offset, true)|(dv.getUint8(offset+1, true)<<8)|(dv.getUint8(offset+2, true)<<16)); }, 
(dv, offset, value)=>{ dv.setUint8(offset, (parseInt(value) & 0xFF), true); dv.setUint8(offset+1, (parseInt(value) >> 8) & 0xFF, true); dv.setUint8(offset+2, (parseInt(value) >> 16) & 0xFF, true); }, 
defaultDataConstruct);

// default array types
new ArrayAccessor("u8", 1, defaultArrayGetter, defaultArraySetter, (...ags) => new Uint8Array(...ags));
new ArrayAccessor("i8", 1, defaultArrayGetter, defaultArraySetter, (...ags) => new Int8Array(...ags));
new ArrayAccessor("u16", 2, defaultArrayGetter, defaultArraySetter, (...ags) => new Uint16Array(...ags));
new ArrayAccessor("i16", 2, defaultArrayGetter, defaultArraySetter, (...ags) => new Int16Array(...ags));
new ArrayAccessor("f32", 4, defaultArrayGetter, defaultArraySetter, (...ags) => new Float32Array(...ags));
new ArrayAccessor("u32", 4, defaultArrayGetter, defaultArraySetter, (...ags) => new Uint32Array(...ags));
new ArrayAccessor("i32", 4, defaultArrayGetter, defaultArraySetter, (...ags) => new Int32Array(...ags));
new ArrayAccessor("f64", 8, defaultArrayGetter, defaultArraySetter, (...ags) => new Float64Array(...ags));
new ArrayAccessor("u64", 8, defaultArrayGetter, defaultArraySetter, (...ags) => new BigUint64Array(...ags));
new ArrayAccessor("i64", 8, defaultArrayGetter, defaultArraySetter, (...ags) => new BigInt64Array(...ags));

//
class CStructView {
    constructor(buffer, byteOffset = 0, byteLength = 0, struct = null) {
        this.buffer = buffer;
        this.byteOffset = byteOffset  + struct.byteOffset;
        this.byteLength = byteLength || struct.byteLength;
        this.getter = struct.getter; // copy getter
        this.setter = struct.setter; // copy setter
        this.type = struct.type;
        this.parent = null;
        
        //
        (this.struct = struct).types.forEach((tp)=>{
            const t = tp.type;
            const array = t.construct(this.buffer, this.byteOffset + tp.byteOffset, tp.byteLength);
            array.parent = this; // prefer to have parent node
            Object.defineProperties(this, {
                [tp.name]: {
                    set: (v)=>{ t.setter(array, 0, v); },
                    get: ()=>{ return t.getter(array, 0); }
                }
            });
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

        return types[tname+(length>1?"[arr]":"")]?.construct(this.buffer, this.byteOffset + offset + this.offsetof(mname));
    }

    // member utils
    offsetof(name) { return this.struct.offsetof(name); };
    bufferOffsetOf(name) { return this.byteOffset + this.offsetof(name); };
    addressOffsetOf(name) { return this.address() + this.offsetof(name); };

    construct(buffer, byteOffset = 0, byteLength = 0) {
        if (isAbv(buffer ? (buffer.buffer || buffer) : null)) {
            return new CStructView(buffer.buffer || buffer, this.byteOffset + (buffer.byteOffset||0) + byteOffset, byteLength || this.byteLength, this.struct);
        } else 
        if (typeof buffer == "number") {
            return new CStructView(new ArrayBuffer(buffer), this.byteOffset + (buffer.byteOffset||0), buffer || this.byteLength, this.struct);
        } else 
        if (typeof buffer == "object") {
            let structed = new CStructView(new ArrayBuffer(this.byteLength), 0, this.byteLength, this.struct);
            //for (let k in buffer) { if (this.types.find((t)=>(t.name == k))) { structed[k] = buffer[k]; }; }; // reduce the some time
            for (let t of this.types) { let k = t.name; if (k in buffer) { structed[k] = buffer[k]; }; }; // supports correct order
            return structed;
        } else
        {
            return new CStructView(new ArrayBuffer(this.byteLength), 0, this.byteLength, this.struct);
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
        if (!(name in types)) { types[name] = this; };

        //
        this.address = this.address.bind(this);

        //
        let prev = undefined;
        for (let name in struct) {
            let length = 1;
            let offset = 0;
            let tname = null;

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
            } else 
            if (typeof struct[name] == "array") {
                length = struct[name][2] || 1;
                offset = struct[name][1] || 0;
                tname = struct[name][0];
            }

            // correctify offset, if not defined
            if (!offset && prev != undefined) { offset = this.types[prev].byteOffset + this.types[prev].byteLength; }; 
            let type = types[tname+(length>1?"[arr]":"")];
            prev = this.types.length; this.types.push({type, name, length, byteOffset: offset, byteLength: type?.byteLength || 1 });

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

        //
        this.getter = (dv, offset)=>{ return (offset ? new CStructView(dv.buffer, dv.byteOffset + offset, dv.byteLength, this) : dv); };

        // offset isn't supported
        this.setter = (dv, offset, value)=>{
            if (typeof value == "object") { for (let t of this.types) { let k = t.name; if (k in value) { dv[k] = value[k]; }; }; }
        };
    }

    offsetof(name) {
        return this.types.find((e)=>(e.name==name))?.byteOffset || 0;
    }

    construct(buffer, byteOffset = 0, byteLength = 0) {
        if (isAbv(buffer ? (buffer.buffer || buffer) : null)) {
            return new CStructView(buffer.buffer || buffer, (buffer.byteOffset||0) + byteOffset, byteLength || this.byteLength, this);
        } else 
        if (typeof buffer == "number") {
            return new CStructView(new ArrayBuffer(buffer || this.byteLength), (buffer.byteOffset||0), buffer || this.byteLength, this);
        } else 
        if (typeof buffer == "object") {
            let structed = new CStructView(new ArrayBuffer(byteLength || this.byteLength), 0, this.byteLength, this);
            //for (let k in buffer) { if (this.types.find((t)=>(t.name == k))) { structed[k] = buffer[k]; }; }; // reduce the some time
            for (let t of this.types) { let k = t.name; if (k in buffer) { structed[k] = buffer[k]; }; }; // supports correct order
            return structed;
        } else
        {
            return new CStructView(new ArrayBuffer(this.byteLength), 0, this.byteLength, this);
        }
    }

    address() {
        return this.buffer.address() + BigInt(this.byteOffset);
    }
}

//
export default { CStruct, CStructView };
