#pragma once

//
#include <napi.h>
#include <string>
#include <sstream>

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

static uint64_t GetAddress(Napi::Env env, Napi::Value const& value_) {
    bool lossless = true;
    uint64_t address = 0ull;
    
    if (value_.IsNull()) { /* Skip, it's null... */ } else
    if (value_.IsNumber()) {
        address = value_.As<Napi::Number>().Int64Value();
    } else
    if (value_.IsBigInt()) {
        address = value_.As<Napi::BigInt>().Uint64Value(&lossless);
    } else
    //if (value_.IsString()) {
        // Broken address, and have broken Null termination issues.
        //decltype(auto) STR = value_.As<Napi::String>().Utf8Value();
        //decltype(auto) ptr = Napi::Uint8Array::New(env, STR.size()+1);
        //memcpy(ptr.Data(), STR.c_str(), STR.size());
        //address = uint64_t(ptr.Data());
    //} else
    if (value_.IsTypedArray()) {
        decltype(auto) TA = value_.As<Napi::TypedArray>();
        decltype(auto) AB = TA.ArrayBuffer();
        address = uint64_t(AB.Data()) + TA.ByteOffset();
    } else
    if (value_.IsDataView()) {
        decltype(auto) TA = value_.As<Napi::DataView>();
        decltype(auto) AB = TA.ArrayBuffer();
        address = uint64_t(AB.Data()) + TA.ByteOffset();
    } else
    if (value_.IsArrayBuffer()) {
        decltype(auto) AB = value_.As<Napi::ArrayBuffer>();
        address = uint64_t(AB.Data());
    } else
    if (value_.IsBuffer()) {
        decltype(auto) AB = value_.As<Napi::Buffer<uint8_t>>();
        address = uint64_t(AB.Data());
    } else
    if (value_.IsExternal()) {
        decltype(auto) AB = value_.As<Napi::External<void>>();
        address = uint64_t(AB.Data());
    } else
    if (value_.IsObject()) {
        decltype(auto) OBJ = value_.As<Napi::Object>();
        if (OBJ.Has("address")) {
            decltype(auto) MTD = OBJ.Get("address");
            if (MTD.IsFunction()) {
                address = MTD.As<Napi::Function>().Call(std::vector<napi_value>{}).As<Napi::BigInt>().Uint64Value(&lossless);
            }
        }
    } else {
        Napi::TypeError::New(env, "Wrong type, needs BigInt (pointer of pointers) at ${I} argument (${param.name})").ThrowAsJavaScriptException(); return address;
    }

    return address;
}

static Napi::Value GetAddressJS(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    return Napi::BigInt::New(env, GetAddress(env, info_[0]));
}

static Napi::Value WrapArrayBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;

    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint64_t address = GetAddress(env, info_[0]);
    size_t byteLength = 0ull;
    if (info_[1].IsBigInt()) { byteLength = info_[1].As<Napi::BigInt>().Uint64Value(&lossless); } else
    if (info_[1].IsNumber()) { byteLength = info_[1].As<Napi::Number>().Uint32Value(); }
    return Napi::ArrayBuffer::New(env, (void*)address, byteLength);
}

static Napi::Value WrapBuffer(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;

    if (info_.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint64_t address = GetAddress(env, info_[0]);
    size_t byteLength = 0ull;
    if (info_[1].IsBigInt()) { byteLength = info_[1].As<Napi::BigInt>().Uint64Value(&lossless); } else
    if (info_[1].IsNumber()) { byteLength = info_[1].As<Napi::Number>().Uint32Value(); }
    return Napi::Buffer<uint8_t>::New(env, (uint8_t*)address, byteLength);
}

static Napi::Value WrapString(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    bool lossless = true;

    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint64_t address = GetAddress(env, info_[0]);
    size_t length = 0ull;
    if (info_.Length() == 2) {
        if (info_[1].IsBigInt()) { length = info_[1].As<Napi::BigInt>().Uint64Value(&lossless); } else
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
    bool lossless = true;

    if (info_.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    uint64_t address = GetAddress(env, info_[0]);

    size_t length = 0ull;
    if (info_.Length() == 2) {
        if (info_[1].IsBigInt()) { length = info_[1].As<Napi::BigInt>().Uint64Value(&lossless); } else
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

static Napi::BigInt Memcpy(const Napi::CallbackInfo& info_) {
    Napi::Env env = info_.Env();
    uint64_t dst = GetAddress(env, info_[0]);
    uint64_t src = GetAddress(env, info_[1]);

    bool lossless = true;
    size_t byteLength = 0ull;
    if (info_[2].IsBigInt()) { byteLength = info_[2].As<Napi::BigInt>().Uint64Value(&lossless); } else
    if (info_[2].IsNumber()) { byteLength = info_[2].As<Napi::Number>().Uint32Value(); }
    memcpy((void*)dst, (void*)src, byteLength);

    return Napi::BigInt::New(env, dst);
}