{
  "targets": [
    {
      "target_name": "native",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "./src/native.cpp", "./volk/volk.c" ],
      "include_dirs": [
        "./"
        "<!@(node -p \"require('node-addon-api').include\")",
        ""
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS', 'NAPI_EXPERIMENTAL', "NAPI_VERSION=8" ],
    }
  ]
}
