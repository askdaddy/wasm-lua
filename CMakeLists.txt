cmake_minimum_required (VERSION 3.10)
project (wasm-lua)

find_package(Lua REQUIRED)
include_directories(/usr/local/include ${LUA_INCLUDE_DIR})


set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES runlua.cpp)
#
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${LUA_LIBRARIES})