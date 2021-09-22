set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

file(GLOB all_SRCS
        "src/ljumptab.h"
        "src/lopnames.h"
        "src/*.c"
        )
list(FILTER all_SRCS EXCLUDE REGEX ".*lua?.c$")

message(">>>>" ${all_SRCS})

add_library(lua STATIC ${all_SRCS})

if (CMAKE_SYSTEM_NAME STREQUAL Linux)
    target_compile_definitions(lua PUBLIC LUA_USE_LINUX LUA_USE_LONGJMP)
endif()

target_compile_options(lua PRIVATE -fPIC)
target_link_libraries(lua -Wl,-E -ldl)

set(LUA_LIBRARIES ${CMAKE_BINARY_DIR}/build/bin PARENT_SCOPE)
set(LUA_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src PARENT_SCOPE)
