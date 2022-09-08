cmake_minimum_required (VERSION 3.10)
cmake_policy(SET CMP0015 NEW)
project (wasm-lua)

#add_definitions(-std=c++14)
#set(CMAKE_C_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build.emscripten)


add_subdirectory(lib/lua-5.4.3)


find_package(Lua REQUIRED)
include_directories(${LUA_INCLUDE_DIR})
#include_directories(/usr/local/include ${LUA_INCLUDE_DIR})


set(SOURCE_FILES app.cpp)
##
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} lua)

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-s WASM=1 -s MODULARIZE=1 -s EXPORT_NAME=liblua -s ENVIRONMENT=web -s FILESYSTEM=0 -s DEMANGLE_SUPPORT=1 -s STANDALONE_WASM --bind --no-entry")