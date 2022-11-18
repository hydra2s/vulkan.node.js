
import { createRequire } from 'module';
const require = createRequire(import.meta.url);
const native = require('bindings')('native');
const sharedStructs = require('shared-structs');
const fs = require('fs');
const path = require('path');

// get native address for Vulkan API 'const char*'
String.prototype.charAddress = function (isUtf16 = false) {
    return native.nativeAddress(this.toString(), isUtf16);
};

//
String.fromAddress = native.string;
String.fromAddressUtf16 = native.stringUtf16;

// 
Buffer.prototype.address = function () { return native.nativeAddress(this); }
Uint8Array.prototype.address = function () { return native.nativeAddress(this); }
Uint16Array.prototype.address = function () { return native.nativeAddress(this); }
Uint32Array.prototype.address = function () { return native.nativeAddress(this); }
BigInt64Array.prototype.address = function () { return native.nativeAddress(this); }
Int8Array.prototype.address = function () { return native.nativeAddress(this); }
Int16Array.prototype.address = function () { return native.nativeAddress(this); }
Int32Array.prototype.address = function () { return native.nativeAddress(this); }
BigUint64Array.prototype.address = function () { return native.nativeAddress(this); }
Float32Array.prototype.address = function () { return native.nativeAddress(this); }
Float64Array.prototype.address = function () { return native.nativeAddress(this); }
ArrayBuffer.prototype.address = function () { return native.nativeAddress(this); }
SharedArrayBuffer.prototype.address = function () { return native.nativeAddress(this); }
DataView.prototype.address = function () { return (native.nativeAddress(this.buffer) + BigInt(this.byteOffset)); }

// 
Buffer.fromAddress = native.buffer;
ArrayBuffer.fromAddress = native.arrayBuffer;
SharedArrayBuffer.fromAddress = native.arrayBuffer;

//
if (typeof exports != "undefined") { exports.nativeAddress = native.nativeAddress; }

//
export default native;
