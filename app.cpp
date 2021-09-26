//
// Created by Seven on 2021/9/22.
//
#ifdef __cplusplus

# include "lua.hpp"

#else
# include "lua.h"
# include "lualib.h"
# include "lauxlib.h"
#endif

#include "app.h"

void print_error(lua_State *state) {
    // The error message is on top of the stack. Fetch it, print it and then pop
    // it off the stack.
    const char *message = lua_tostring(state, -1);
    puts(message);
    lua_pop(state, 1);
}

App::~App() {
    if (L) lua_close(L);
}

std::string App::doString(std::string codes) {
    if (!L) {
        L = luaL_newstate();
        // Make standard libraries available in the Lua state
        luaL_openlibs(L);
    }

    int result;

    // Load the program; this supports both source code and bytecode files.
    result = luaL_dostring(L, codes.c_str());


    size_t len = 0;
    const char* ret = lua_tolstring(L, lua_gettop(L), &len);
    printf("%s\n",ret);
    std::string s(ret);
    return s;
}


