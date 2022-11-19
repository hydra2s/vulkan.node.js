#pragma once
//
#include <napi.h>

//
static Napi::Value Dealloc(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    delete (void*)address;
    return Napi::BigInt::New(env, (uint64_t)0ull);
}

static Napi::Value GetAddress(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();

    uint64_t address = 0ull;
    if (info_[0].IsString()) {
        decltype(auto) STR = info_[0].As<Napi::String>().Utf8Value();
        decltype(auto) ptr = Napi::Uint8Array::New(env, STR.length()); // you can't use directly c_str, it should to be context visible
        memcpy(ptr.Data(), STR.c_str(), STR.size());
        address = uint64_t(ptr.Data());
    }
    if (info_[0].IsTypedArray()) {
        decltype(auto) TA = info_[0].As<Napi::TypedArray>();
        decltype(auto) AB = TA.ArrayBuffer();
        address = uint64_t(AB.Data()) + TA.ByteOffset();
    }
    if (info_[0].IsDataView()) {
        decltype(auto) TA = info_[0].As<Napi::DataView>();
        decltype(auto) AB = TA.ArrayBuffer();
        address = uint64_t(AB.Data()) + TA.ByteOffset();
    }
    if (info_[0].IsArrayBuffer()) {
        decltype(auto) AB = info_[0].As<Napi::ArrayBuffer>();
        address = uint64_t(AB.Data());
    }
    if (info_[0].IsBuffer()) {
        decltype(auto) AB = info_[0].As<Napi::Buffer<uint8_t>>();
        address = uint64_t(AB.Data());
    }
    if (info_[0].IsExternal()) {
        decltype(auto) AB = info_[0].As<Napi::External<void>>();
        address = uint64_t(AB.Data());
    }

    return Napi::BigInt::New(env, (uint64_t)address);
}

static Napi::ArrayBuffer WrapArrayBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    bool lossless = true;
    if (info_[0].IsBigInt()) {
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    size_t byteLength = 0ull;
    if (info_[0].IsBigInt()) { byteLength = info_[0].As<Napi::BigInt>().Uint64Value(&lossless); }
    if (info_[1].IsNumber()) { byteLength = info_[1].As<Napi::Number>().Uint32Value(); }
    return Napi::ArrayBuffer::New(env, (void*)address, byteLength);
}

static Napi::Buffer<uint8_t> WrapBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    bool lossless = true;
    if (info_[0].IsBigInt()) {
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    size_t byteLength = 0ull;
    if (info_[0].IsBigInt()) { byteLength = info_[0].As<Napi::BigInt>().Uint64Value(&lossless); }
    if (info_[1].IsNumber()) { byteLength = info_[1].As<Napi::Number>().Uint32Value(); }
    return Napi::Buffer<uint8_t>::New(env, (uint8_t*)address, byteLength);
}

static Napi::Value WrapString(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    bool lossless = true;
    if (info_[0].IsBigInt()) {
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }

    size_t length = 0ull;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    if (info_[0].IsBigInt()) { length = info_[0].As<Napi::BigInt>().Uint64Value(&lossless); }
    if (info_.Length() == 2) {
        if (info_[1].IsNumber()) { length = info_[1].As<Napi::Number>().Uint32Value(); }
    }

    //
    if (length) {
        return Napi::String::New(env, (char*)address, length);
    } else {
        return Napi::String::New(env, (char*)address);
    }
}

static Napi::Value WrapStringUTF16(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    bool lossless = true;
    if (info_[0].IsBigInt()) {
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    
    size_t length = 0ull;
    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    if (info_[0].IsBigInt()) { length = info_[0].As<Napi::BigInt>().Uint64Value(&lossless); }
    if (info_.Length() == 2) {
        if (info_[1].IsNumber()) { length = info_[1].As<Napi::Number>().Uint32Value(); }
    }

    //
    if (length) {
        return Napi::String::New(env, (char16_t*)address, length);
    } else {
        return Napi::String::New(env, (char16_t*)address);
    }
}

static Napi::Number DebugUint8(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((uint8_t*)address));
}

static Napi::Number DebugUint16(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((uint16_t*)address));
}

static Napi::Number DebugUint32(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((uint32_t*)address));
}

static Napi::Value DebugUint64(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::BigInt::New(env, (uint64_t)address);
}

static Napi::Number DebugFloat32(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((float*)address));
}

static Napi::Number DebugFloat64(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t address = 0ull;
    if (info_[0].IsBigInt()) {
        bool lossless = true;
        address = info_[0].As<Napi::BigInt>().Uint64Value(&lossless);;
    }
    return Napi::Number::New(env, *((double*)address));
}

