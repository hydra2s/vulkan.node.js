
#include <napi.h>

Napi::String Method(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "world");
}

Napi::BigInt Dealloc(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    delete (void*)address;
    return Napi::BigInt::New(env, 0ull);
}

Napi::BigInt GetAddress(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    uint64_t address = 0ull;
    if (info[0].IsString()) {
        auto STR = info[0].As<Napi::String>().Utf8Value();
        auto ptr = Napi::Uint8Array::New(env, STR.length()); // you can't use directly c_str, it should to be context visible
        memcpy(ptr.Data(), STR.c_str(), STR.size());
        address = uint64_t(ptr.Data());
    }
    if (info[0].IsTypedArray()) {
        auto TA = info[0].As<Napi::TypedArray>();
        auto AB = TA.ArrayBuffer();
        address = uint64_t(AB.Data()) + TA.ByteOffset();
    }
    if (info[0].IsDataView()) {
        auto TA = info[0].As<Napi::DataView>();
        auto AB = TA.ArrayBuffer();
        address = uint64_t(AB.Data()) + TA.ByteOffset();
    }
    if (info[0].IsArrayBuffer()) {
        auto AB = info[0].As<Napi::ArrayBuffer>();
        address = uint64_t(AB.Data());
    }
    if (info[0].IsExternal()) {
        auto AB = info[0].As<Napi::External<void>>();
        address = uint64_t(AB.Data());
    }

    return Napi::BigInt::New(env, address);
}


Napi::ArrayBuffer WrapArrayBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    bool lossless = true;
    if (info[0].IsBigInt()) {
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    size_t byteLength = 0ull;
    if (info[1].IsBigInt()) { byteLength = info[1].As<Napi::BigInt>().Uint64Value(&lossless); }
    if (info[1].IsNumber()) { byteLength = info[1].As<Napi::Number>().Uint32Value(); }
    return Napi::ArrayBuffer::New(env, (void*)address, byteLength);
}


Napi::Number DebugUint8(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    return Napi::Number::New(env, *((uint8_t*)address));
}

Napi::Number DebugUint16(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    return Napi::Number::New(env, *((uint16_t*)address));
}

Napi::Number DebugUint32(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    return Napi::Number::New(env, *((uint32_t*)address));
}

Napi::BigInt DebugUint64(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    return Napi::BigInt::New(env, *((uint64_t*)address));
}


Napi::Number DebugFloat32(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    return Napi::Number::New(env, *((float*)address));
}

Napi::Number DebugFloat64(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    uint64_t address = 0ull;
    if (info[0].IsBigInt()) {
        bool lossless = true;
        address = info[0].As<Napi::BigInt>().Uint64Value(&lossless);
    }
    return Napi::Number::New(env, *((double*)address));
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Method));
    exports.Set(Napi::String::New(env, "uint8"), Napi::Function::New(env, DebugUint8));
    exports.Set(Napi::String::New(env, "uint16"), Napi::Function::New(env, DebugUint16));
    exports.Set(Napi::String::New(env, "uint32"), Napi::Function::New(env, DebugUint32));
    exports.Set(Napi::String::New(env, "uint64"), Napi::Function::New(env, DebugUint64));
    exports.Set(Napi::String::New(env, "float32"), Napi::Function::New(env, DebugFloat32));
    exports.Set(Napi::String::New(env, "float64"), Napi::Function::New(env, DebugFloat64));
    exports.Set(Napi::String::New(env, "nativeAddress"), Napi::Function::New(env, GetAddress));
    exports.Set(Napi::String::New(env, "arrayBuffer"), Napi::Function::New(env, WrapArrayBuffer));
    return exports;
}

NODE_API_MODULE(native, Init)
