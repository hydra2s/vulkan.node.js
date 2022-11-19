//
let types = {
    u8: { byteLength: 1, length: 1, bigEndian: false, type: "u8", getter: (dv, offset)=>{ return dv.getUint8(offset, true); }, setter: (dv, offset, value)=>{ dv.setUint8(offset, parseInt(value), true); }, construct:(...ags) => new DataView(...ags) },
    i8: { byteLength: 1, length: 1, bbigEndian: false, type: "i8", getter: (dv, offset)=>{ return dv.getInt8 (offset, true); }, setter: (dv, offset, value)=>{ dv.setInt8 (offset, parseInt(value), true); }, construct:(...ags) => new DataView(...ags) },

    u16: { byteLength: 2, length: 1, bbigEndian: false, type: "u16", getter: (dv, offset)=>{ return dv.getUint16(offset, true); }, setter: (dv, offset, value)=>{ dv.setUint16(offset, parseInt(value), true); }, construct: (...ags) => new DataView(...ags) },
    i16: { byteLength: 2, length: 1, bbigEndian: false, type: "i16", getter: (dv, offset)=>{ return dv.getInt16 (offset, true); }, setter: (dv, offset, value)=>{ dv.setInt16 (offset, parseInt(value), true); }, construct:(...ags) => new DataView(...ags) },

    u24: { byteLength: 3, length: 1, bbigEndian: false, type: "u24", 
        getter: (dv, offset)=>{ return (dv.getUint8(offset, true)|(dv.getUint8(offset+1, true)<<8)|(dv.getUint8(offset+2, true)<<16)); }, 
        setter: (dv, offset, value)=>{ dv.setUint8(offset, (parseInt(value) & 0xFF), true); dv.setUint8(offset+1, (parseInt(value) >> 8) & 0xFF, true); dv.setUint8(offset+2, (parseInt(value) >> 16) & 0xFF, true); }, 
        construct:(...ags) => new DataView(...ags) },

    u32: { byteLength: 4, length: 1, bbigEndian: false, type: "u32", getter: (dv, offset)=>{ return dv.getUint32 (offset, true); }, setter: (dv, offset, value)=>{ dv.setUint32 (offset, parseInt(value), true); }, construct:(...ags) => new DataView(...ags) },
    i32: { byteLength: 4, length: 1, bbigEndian: false, type: "i32", getter: (dv, offset)=>{ return dv.getInt32  (offset, true); }, setter: (dv, offset, value)=>{ dv.setInt32  (offset, parseInt(value), true); }, construct:(...ags) => new DataView(...ags) },
    f32: { byteLength: 4, length: 1, bbigEndian: false, type: "f32", getter: (dv, offset)=>{ return dv.getFloat32(offset, true); }, setter: (dv, offset, value)=>{ dv.setFloat32(offset, parseFloat(value), true); }, construct:(...ags) => new DataView(...ags) },

    u64: { byteLength: 8, length: 1, bbigEndian: false, type: "u64", getter: (dv, offset)=>{ return dv.getBigUint64 (offset, true); }, setter: (dv, offset, value)=>{ dv.setBigUint64 (offset, BigInt(value), true); }, construct:(...ags) => new DataView(...ags) },
    i64: { byteLength: 8, length: 1, bbigEndian: false, type: "i64", getter: (dv, offset)=>{ return dv.getBigInt64  (offset, true); }, setter: (dv, offset, value)=>{ dv.setBigInt64  (offset, BigInt(value), true); }, construct:(...ags) => new DataView(...ags) },
    f64: { byteLength: 8, length: 1, bbigEndian: false, type: "f64", getter: (dv, offset)=>{ return dv.getFloat64(offset, true); }, setter: (dv, offset, value)=>{ dv.setFloat64(offset, parseFloat(value), true); }, construct:(...ags) => new DataView(...ags) },

    u8arr: { byteLength: 1, length: 1, bigEndian: false, type: "u8arr", getter: (dv, offset)=>{ return dv; }, setter: (dv, offset, value)=>{ dv.set(value, offset); }, construct: (...ags)=> new Uint8Array(...ags) },
    i8arr: { byteLength: 1, length: 1, bbigEndian: false, type: "i8arr", getter: (dv, offset)=>{ return dv; }, setter: (dv, offset, value)=>{ dv.set(value, offset); }, construct: (...ags)=> new  Int8Array(...ags) }, 

    u16arr: { byteLength: 2, length: 1, bbigEndian: false, type: "u16arr", getter: (dv, offset)=>{ return dv; }, setter: (dv, offset, value)=>{ dv.set(value, offset); }, construct: (...ags)=> new Uint16Array(...ags) },
    i16arr: { byteLength: 2, length: 1, bbigEndian: false, type: "i16arr", getter: (dv, offset)=>{ return dv; }, setter: (dv, offset, value)=>{ dv.set(value, offset); }, construct: (...ags)=> new Int16Array(...ags) },

    u32arr: { byteLength: 4, length: 1, bbigEndian: false, type: "u32arr", getter: (dv, offset)=>{ return dv; }, setter: (dv, offset, value)=>{ dv.set(value, offset); }, construct: (...ags)=> new Uint32Array(...ags) },
    i32arr: { byteLength: 4, length: 1, bbigEndian: false, type: "i32arr", getter: (dv, offset)=>{ return dv; }, setter: (dv, offset, value)=>{ dv.set(value, offset); }, construct: (...ags)=> new Int32Array(...ags) },
    f32arr: { byteLength: 4, length: 1, bbigEndian: false, type: "f32arr", getter: (dv, offset)=>{ return dv; }, setter: (dv, offset, value)=>{ dv.set(value, offset); }, construct: (...ags)=> new Float32Array(...ags) },

    u64arr: { byteLength: 8, length: 1, bbigEndian: false, type: "u64arr", getter: (dv, offset)=>{ return dv; }, setter: (dv, offset, value)=>{ dv.set(value, offset); }, construct: (...ags)=> new BigUint64Array(...ags)  },
    i64arr: { byteLength: 8, length: 1, bbigEndian: false, type: "i64arr", getter: (dv, offset)=>{ return dv; }, setter: (dv, offset, value)=>{ dv.set(value, offset); }, construct: (...ags)=> new BigInt64Array(...ags) },
    f64arr: { byteLength: 8, length: 1, bbigEndian: false, type: "f64arr", getter: (dv, offset)=>{ return dv; }, setter: (dv, offset, value)=>{ dv.set(value, offset); }, construct: (...ags)=> new Float64Array(...ags) }
}

//
function isAbv(value) {
    return value && value.byteLength != undefined && (value instanceof ArrayBuffer);
}

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
            if (t.type && t.type.indexOf("arr") >= 0) {
                let array = t.construct(this.buffer, this.byteOffset + tp.byteOffset, t.length); 
                array.parent = this; // prefer to have parent node
                Object.defineProperties(this, {
                    [tp.name]: {
                        set: (v)=>{ t.setter(array, 0, v); },
                        get: ()=>{ return t.getter(array, 0); }
                    }
                });
            } else {
                let array = t.construct(this.buffer, this.byteOffset + tp.byteOffset, tp.byteLength);
                array.parent = this; // prefer to have parent node
                Object.defineProperties(this, {
                    [tp.name]: {
                        set: (v)=>{ t.setter(array, 0, v); },
                        get: ()=>{ return t.getter(array, 0); }
                    }
                });
            }
        });
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
        let prev = undefined;
        for (let name in struct) {
            let length = 1;
            let offset = 0;
            if (typeof struct[name] == "string") {
                let tname = struct[name];
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

                // correctify offset, if not defined
                if (!offset && prev != undefined) { offset = this.types[prev].offset + this.types[prev].byteLength; }; 

                let type = types[tname+(length>1?"arr":"")];
                prev = this.types.length; this.types.push({type, name, length, byteOffset: offset, byteLength: type?.byteLength || 1 });
            } else 
            if (typeof struct[name] == "array") {
                let tname = types[struct[name]][0];
                length = struct[name][2] || 1;
                offset = struct[name][1] || 0;

                // correctify offset, if not defined
                if (!offset && prev != undefined) { offset = this.types[prev].offset + this.types[prev].byteLength; }; 

                let type = types[tname+(length>1?"arr":"")];
                if (!type) { console.log(tname+(length>1?"arr":"")); };
                prev = this.types.length; this.types.push({type, name, length, byteOffset: offset, byteLength: type?.byteLength || 1 });
            }
        }

        // if length is not defined
        if (!this.byteLength && this.types.length >= 1) { 
            this.byteLength = this.types[this.types.length-1].offset + this.types[this.types.length-1].byteLength; 
        };

        //
        this.getter = (dv, offset)=>{ return new CStructView(dv.buffer, dv.byteOffset + offset, dv.byteLength, this); };

        // offset isn't supported
        this.setter = (dv, offset, value)=>{
            if (typeof value == "object") { for (let t of this.types) { let k = t.name; if (k in value) { dv[k] = value[k]; }; }; }
        };
    }

    offsetof(name) {
        return this.types.find((e)=>(e.name==name))?.byteOffset || 0;
    }

    u8(name, byteOffset = 0, length = 1) { this.types.push({type: types["u8"+(length>1?"arr":"")], name, byteOffset, length}); }
    i8(name, byteOffset = 0, length = 1) { this.types.push({type: types["i8"+(length>1?"arr":"")], name, byteOffset, length}); }

    u16(name, byteOffset = 0, length = 1) { this.types.push({type: types["u16"+(length>1?"arr":"")], name, byteOffset, length}); }
    i16(name, byteOffset = 0, length = 1) { this.types.push({type: types["i16"+(length>1?"arr":"")], name, byteOffset, length}); }

    u32(name, byteOffset = 0, length = 1) { this.types.push({type: types["u32"+(length>1?"arr":"")], name, byteOffset, length}); }
    i32(name, byteOffset = 0, length = 1) { this.types.push({type: types["i32"+(length>1?"arr":"")], name, byteOffset, length}); }
    f32(name, byteOffset = 0, length = 1) { this.types.push({type: types["f32"+(length>1?"arr":"")], name, byteOffset, length}); }

    u64(name, byteOffset = 0, length = 1) { this.types.push({type: types["u64"+(length>1?"arr":"")], name, byteOffset, length}); }
    i64(name, byteOffset = 0, length = 1) { this.types.push({type: types["i64"+(length>1?"arr":"")], name, byteOffset, length}); }
    f64(name, byteOffset = 0, length = 1) { this.types.push({type: types["f64"+(length>1?"arr":"")], name, byteOffset, length}); }

    construct(buffer, byteOffset = 0, byteLength = 0) {
        if (isAbv(buffer ? (buffer.buffer || buffer) : null)) {
            return new CStructView(buffer.buffer || buffer, (buffer.byteOffset||0) + byteOffset, byteLength || this.byteLength, this);
        } else 
        if (typeof buffer == "number") {
            return new CStructView(new ArrayBuffer(buffer), (buffer.byteOffset||0), buffer || this.byteLength, this);
        } else 
        if (typeof buffer == "object") {
            let structed = new CStructView(new ArrayBuffer(this.byteLength), 0, this.byteLength, this);
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
