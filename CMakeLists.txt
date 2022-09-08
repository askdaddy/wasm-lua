cmake_minimum_required (VERSION 3.10)
cmake_policy(SET CMP0015 NEW)
project (wasm-lua)

# -DCMAKE_TOOLCHAIN_FILE=/Users/seven/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake
if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    message(FATAL_ERROR "请务必先配置emsdk环境，并设置cmake toolchain file" )
endif ()

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build.emscripten)

#add_subdirectory(lib/lua-5.4.3)
#find_package(Lua REQUIRED)
#include_directories(${LUA_INCLUDE_DIR})


set(SOURCE_FILES app.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
#target_link_libraries(${PROJECT_NAME} lua)

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS
        "-s EXPORT_NAME=MIF -s EXPORTED_RUNTIME_METHODS='[\"cwrap\",\"ccall\"]' -s ALLOW_MEMORY_GROWTH=1 -s MODULARIZE=1 -s ENVIRONMENT=web -s NO_FILESYSTEM=1 -s DEMANGLE_SUPPORT=1 --bind")