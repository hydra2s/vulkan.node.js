//
let types = {
    u8: { byteLength: 1, length: 1, bigEndian: false, type: "u8", getter: (dv, offset)=>{ return dv.getUint8(offset); }, setter: (dv, offset, value)=>{ dv.setUint8(offset, value); }, construct: DataView },
    i8: { byteLength: 1, length: 1, bbigEndian: false, type: "i8", getter: (dv, offset)=>{ return dv.getInt8 (offset); }, setter: (dv, offset, value)=>{ dv.setInt8 (offset, value); }, construct: DataView },

    u16: { byteLength: 2, length: 1, bbigEndian: false, type: "u16", getter: (dv, offset)=>{ return dv.getUint16(offset); }, setter: (dv, offset, value)=>{ dv.setUint16(offset, value); }, construct: DataView },
    i16: { byteLength: 2, length: 1, bbigEndian: false, type: "i16", getter: (dv, offset)=>{ return dv.getInt16 (offset); }, setter: (dv, offset, value)=>{ dv.setInt16 (offset, value); }, construct: DataView },

    u32: { byteLength: 4, length: 1, bbigEndian: false, type: "u32", getter: (dv, offset)=>{ return dv.getUint32 (offset); }, setter: (dv, offset, value)=>{ dv.setUint32 (offset, value); }, construct: DataView },
    i32: { byteLength: 4, length: 1, bbigEndian: false, type: "i32", getter: (dv, offset)=>{ return dv.getInt32  (offset); }, setter: (dv, offset, value)=>{ dv.setInt32  (offset, value); }, construct: DataView },
    f32: { byteLength: 4, length: 1, bbigEndian: false, type: "f32", getter: (dv, offset)=>{ return dv.getFloat32(offset); }, setter: (dv, offset, value)=>{ dv.setFloat32(offset, value); }, construct: DataView },

    u64: { byteLength: 8, length: 1, bbigEndian: false, type: "u64", getter: (dv, offset)=>{ return dv.getBigUint64 (offset); }, setter: (dv, offset, value)=>{ dv.setBigUint64 (offset, value); }, construct: DataView },
    i64: { byteLength: 8, length: 1, bbigEndian: false, type: "i64", getter: (dv, offset)=>{ return dv.getBigInt64  (offset); }, setter: (dv, offset, value)=>{ dv.setBigInt64  (offset, value); }, construct: DataView },
    f64: { byteLength: 8, length: 1, bbigEndian: false, type: "f64", getter: (dv, offset)=>{ return dv.getFloat64(offset); }, setter: (dv, offset, value)=>{ dv.setFloat64(offset, value); }, construct: DataView },

    u8arr: { byteLength: 1, length: 1, bigEndian: false, type: "u8", getter: (dv, offset)=>{ return dv; }, construct: Uint8Array },
    i8arr: { byteLength: 1, length: 1, bbigEndian: false, type: "i8", getter: (dv, offset)=>{ return dv; }, construct: Int8Array }, 

    u16arr: { byteLength: 2, length: 1, bbigEndian: false, type: "u16", getter: (dv, offset)=>{ return dv; }, construct: Uint16Array },
    i16arr: { byteLength: 2, length: 1, bbigEndian: false, type: "i16", getter: (dv, offset)=>{ return dv }, construct: Int16Array },

    u32arr: { byteLength: 4, length: 1, bbigEndian: false, type: "u32", getter: (dv, offset)=>{ return dv; }, construct: Uint32Array },
    i32arr: { byteLength: 4, length: 1, bbigEndian: false, type: "i32", getter: (dv, offset)=>{ return dv; }, construct: Int32Array },
    f32arr: { byteLength: 4, length: 1, bbigEndian: false, type: "f32", getter: (dv, offset)=>{ return dv; }, construct: Float32Array },

    u64arr: { byteLength: 8, length: 1, bbigEndian: false, type: "u64", getter: (dv, offset)=>{ return dv; }, construct: BigUint64Array  },
    i64arr: { byteLength: 8, length: 1, bbigEndian: false, type: "i64", getter: (dv, offset)=>{ return dv; }, construct: BigInt64Array },
    f64arr: { byteLength: 8, length: 1, bbigEndian: false, type: "f64", getter: (dv, offset)=>{ return dv; }, construct: Float64Array }

}

//
class CStructView {
    consturctor(buffer, byteOffset = 0, byteLength = 1, struct = null) {
        this.buffer = buffer;
        this.byteOffset = byteOffset;
        this.byteLength = byteLength;
        this.getter = struct.getter;
        this.setter = struct.setter;

        (this.struct = struct).types.forEach((t)=>{
            if (t.name.indexOf("arr") >= 0) {
                let array = new t.construct(this.dataView.buffer, this.dataView.byteOffset + t.byteOffset, t.length);
                Object.defineProperties(this, {
                    [t.name]: { get: ()=>{ t.getter(array, 0); } }
                });
            } else {
                let array = new t.construct(this.dataView.buffer, this.dataView.byteOffset + t.byteOffset, t.byteLength);
                Object.defineProperties(this, {
                    [t.name]: {
                        set: (v)=>{ t.setter(array, 0, v); },
                        get: ()=>{ return t.getter(array, 0); }
                    }
                });
            }
        });
    }
}

// 
class CStruct {
    constructor(name, struct, byteLength) {
        this.types = [];
        for (let name in struct) {
            this.types.push({name, ...types[struct[name]]});
        }
        this.byteLength = byteLength;
        this.getter = (dv, offset)=>{ return new CStructView(dv.buffer, dv.byteOffset + offset, dv.byteLength, this); };
        this.setter = (dv, offset, value)=>{ this.types.forEach((p)=>p.setter(dv,offset+p.byteOffset,value)); };
        if (!(name in types)) { types[name] = this; };
    }

    u8(name, byteOffset = 0) { this.struct.push({...types.u8, byteOffset, name}); }
    i8(name, byteOffset = 0) { this.struct.push({...types.i8, byteOffset, name}); }

    u16(name, byteOffset = 0) { this.struct.push({...types.u16, byteOffset, name}); }
    i16(name, byteOffset = 0) { this.struct.push({...types.i16, byteOffset, name}); }

    u32(name, byteOffset = 0) { this.struct.push({...types.u32, byteOffset, name}); }
    i32(name, byteOffset = 0) { this.struct.push({...types.i32, byteOffset, name}); }
    f32(name, byteOffset = 0) { this.struct.push({...types.f32, byteOffset, name}); }

    u64(name, byteOffset = 0) { this.struct.push({...types.u64, byteOffset, name}); }
    i64(name, byteOffset = 0) { this.struct.push({...types.i64, byteOffset, name}); }
    f64(name, byteOffset = 0) { this.struct.push({...types.f64, byteOffset, name}); }

    u8arr(name, length = 1, byteOffset = 0) { this.struct.push({...types.u8arr, length, byteOffset, name}); }
    i8arr(name, length = 1, byteOffset = 0) { this.struct.push({...types.i8arr, length, byteOffset, name}); }

    u16arr(name, length = 1, byteOffset = 0) { this.struct.push({...types.u16arr, length, byteOffset, name}); }
    i16arr(name, length = 1, byteOffset = 0) { this.struct.push({...types.i16arr, length, byteOffset, name}); }

    u32arr(name, length = 1, byteOffset = 0) { this.struct.push({...types.u32arr, length, byteOffset, name}); }
    i32arr(name, length = 1, byteOffset = 0) { this.struct.push({...types.i32arr, length, byteOffset, name}); }
    f32arr(name, length = 1, byteOffset = 0) { this.struct.push({...types.f32arr, length, byteOffset, name}); }

    u64arr(name, length = 1, byteOffset = 0) { this.struct.push({...types.u64arr, length, byteOffset, name}); }
    i64arr(name, length = 1, byteOffset = 0) { this.struct.push({...types.i64arr, length, byteOffset, name}); }
    f64arr(name, length = 1, byteOffset = 0) { this.struct.push({...types.f64arr, length, byteOffset, name}); }

    construct(buffer, byteOffset = 0, byteLength = 0) {
        return new CStructView(buffer, byteOffset, byteLength || this.byteLength, this);
    }
}
