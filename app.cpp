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

void App::doString(std::string codes) {
    lua_State* L = luaL_newstate();

    // Make standard libraries available in the Lua state
    luaL_openlibs(L);

    int result;

    // Load the program; this supports both source code and bytecode files.
    puts(codes.c_str());
    result = luaL_dostring(L, codes.c_str());
    if (result != LUA_OK) {
        print_error(L);
        return;
    }

    // Finally, execute the program by calling into it. You may have to change
    // the lua_pcall arguments if you're not running vanilla Lua code.
    result = lua_pcall(L, 0, LUA_MULTRET, 0);
    if ( result != LUA_OK ) {
    print_error(L);
        return;
    }

}

