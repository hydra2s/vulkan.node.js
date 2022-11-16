var native = require('bindings')('native');

// get native address for Vulkan API 'const char*'
String.prototype.charAddress = function (isUtf16 = false) {
    return native.nativeAddress(this.toString(), isUtf16);
};

// 
DataView.prototype.address = 
Uint8Array.prototype.address = 
Uint16Array.prototype.address = 
Uint32Array.prototype.address = 
BigUint64Array.prototype.address = 
Int8Array.prototype.address = 
Int16Array.prototype.address = 
Int32Array.prototype.address = 
BigInt64Array.prototype.address = 
Float32Array.prototype.address = 
Float64Array.prototype.address = 
ArrayBuffer.prototype.address = 
SharedArrayBuffer.prototype.address = 
function () { return native.nativeAddress(this); }

if (typeof exports != "undefined") { exports.nativeAddress = native.nativeAddress; }

//export function nativeAddress(...args){
//    return native.nativeAddress(...args);
//}
