cmake_minimum_required(VERSION 3.20)
project(native)
set(PROJECT_NAME native)

#
MACRO(ADD_MSVC_PRECOMPILED_HEADER PrecompiledHeader PrecompiledSource SourcesVar)
  IF(MSVC)
    GET_FILENAME_COMPONENT(PrecompiledBasename ${PrecompiledHeader} NAME_WE)
    SET(PrecompiledBinary "${CMAKE_CURRENT_BINARY_DIR}/${PrecompiledBasename}.pch")
    SET(Sources ${${SourcesVar}})

    SET_SOURCE_FILES_PROPERTIES(${PrecompiledSource}
                                PROPERTIES COMPILE_FLAGS "/Yc\"${PrecompiledHeader}\" /Fp\"${PrecompiledBinary}\""
                                           OBJECT_OUTPUTS "${PrecompiledBinary}")
    SET_SOURCE_FILES_PROPERTIES(${Sources}
                                PROPERTIES COMPILE_FLAGS "/Yu\"${PrecompiledHeader}\" /FI\"${PrecompiledHeader}\" /Fp\"${PrecompiledBinary}\""
                                           OBJECT_DEPENDS "${PrecompiledBinary}")  
    # Add precompiled header to SourcesVar
    LIST(APPEND ${SourcesVar} ${PrecompiledSource})
  ENDIF(MSVC)
ENDMACRO(ADD_MSVC_PRECOMPILED_HEADER)

# 
IF (WIN32)
  IF(NOT DEFINED VCPKG_PATH OR NOT DEFINED ${VCPKG_PATH})
    set (VCPKG_PATH "C:/vcpkg/")
  ENDIF()

  # trying load GLFW3 from VCPKG in Windows
  IF(NOT DEFINED CMAKE_TOOLCHAIN_FILE OR NOT DEFINED ${CMAKE_TOOLCHAIN_FILE})
    set (CMAKE_TOOLCHAIN_FILE "${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake")
  ENDIF()

  IF(NOT DEFINED CMAKE_MODULE_PATH OR NOT DEFINED ${CMAKE_MODULE_PATH})
    set (CMAKE_MODULE_PATH "${VCPKG_PATH}/installed/x64-windows")
  ENDIF()
  
  IF(NOT DEFINED glfw3_DIR OR NOT DEFINED ${glfw3_DIR})
    set (glfw3_DIR "${CMAKE_MODULE_PATH}/share/glfw3")
  ENDIF()
ENDIF()

# 
find_package(Vulkan REQUIRED)

#
set(CMAKE_JS_VERSION 8)
set(napi_build_version 8)
add_definitions(-DNAPI_VERSION=${napi_build_version})
add_definitions(-DNAPI_EXPERIMENTAL)
add_definitions(-DCMAKE_JS_VERSION=${napi_build_version})
cmake_policy(SET CMP0091 NEW)
cmake_policy(SET CMP0042 NEW)

# 
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)
set(_src_root_path "${PROJECT_SOURCE_DIR}/")
file(GLOB_RECURSE _source_list 
  LIST_DIRECTORIES false
  "${_src_root_path}/src/*.c"
  "${_src_root_path}/src/*.cpp"
  "${_src_root_path}/src/*.h"
  "${_src_root_path}/src/*.hpp"
  "${_src_root_path}/volk/volk.h"
  "${_src_root_path}/volk/volk.c"
  "${CMAKE_JS_SRC}"
)

# Generate node.lib
if(MSVC AND CMAKE_JS_NODELIB_DEF AND CMAKE_JS_NODELIB_TARGET)
  execute_process(COMMAND ${CMAKE_AR}  /def:NAPI_EXPERIMENTAL /def:${CMAKE_JS_NODELIB_DEF} /out:${CMAKE_JS_NODELIB_TARGET} ${CMAKE_STATIC_LINKER_FLAGS})
endif()

# 
add_library(${PROJECT_NAME} SHARED ${_source_list})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(${PROJECT_NAME} ${Vulkan_LIBRARIES} ${CMAKE_JS_LIB})
target_link_directories(${PROJECT_NAME} PUBLIC )
target_compile_definitions(${PROJECT_NAME} PUBLIC USE_CMAKE_PCH NAPI_VERSION=${napi_build_version} NAPI_EXPERIMENTAL)
target_include_directories(${PROJECT_NAME} PUBLIC 
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/*/include 
  ${PROJECT_SOURCE_DIR}/glm/glm
  ${PROJECT_SOURCE_DIR}/glm
  ${PROJECT_SOURCE_DIR}/volk
  ${PROJECT_SOURCE_DIR}/node_modules/node-api-headers/include
  ${PROJECT_SOURCE_DIR}/node_modules/node-addon-api/
  ${PROJECT_SOURCE_DIR}/../*
  ${PROJECT_SOURCE_DIR}/../*/include
  ${PROJECT_SOURCE_DIR}/../*/vulkan
  ${PROJECT_SOURCE_DIR}/../*/vma
  ${Vulkan_INCLUDE_DIR}/volk
  ${Vulkan_INCLUDE_DIR}/vma
  ${Vulkan_INCLUDE_DIR}/vulkan
  ${Vulkan_INCLUDE_DIR}
  ${Vulkan_INCLUDE_DIRS}
  ${CMAKE_JS_INC}
)

#
ADD_MSVC_PRECOMPILED_HEADER(
  "${PROJECT_SOURCE_DIR}/cmake_pch.hpp" 
  "${PROJECT_SOURCE_DIR}/cmake_pch.cpp" 
  HSOURCES)

# 
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

# 
foreach(_source IN ITEMS ${_source_list})
    get_filename_component(_source_path "${_source}" PATH)
    file(RELATIVE_PATH _source_path_rel "${_src_root_path}" "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()