#include <stdio.h>

extern "C"{
#  include "lua.h"
#  include "lualib.h"
#  include "lauxlib.h"
}

// #define DBG(s) (s)
#define DBG(s)

extern int com_create_object( lua_State *L );
extern int com_create_object_utf8( lua_State *L );
extern int com_get_active_object( lua_State *L );
extern int com_get_active_object_utf8( lua_State *L );
extern int com_const_load( lua_State *L );

extern "C" int luaopen_nyole(lua_State *L)
{
    lua_newtable(L);
    lua_pushcfunction(L,com_create_object);
    lua_setfield(L,-2,"create_object");
    lua_pushcfunction(L,com_create_object_utf8);
    lua_setfield(L,-2,"create_object_utf8");
    lua_pushcfunction(L,com_get_active_object);
    lua_setfield(L,-2,"get_active_object");
    lua_pushcfunction(L,com_get_active_object_utf8);
    lua_setfield(L,-2,"get_active_object_utf8");
    lua_pushcfunction(L,com_const_load);
    lua_setfield(L,-2,"const_load");
    return 1;
}
