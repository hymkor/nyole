#include <stdio.h>

extern "C"{
#  include "lua.h"
#  include "lualib.h"
#  include "lauxlib.h"
}

// #define DBG(s) (s)
#define DBG(s)

extern int com_create_object( lua_State *L );
extern int com_get_active_object( lua_State *L );
extern int com_const_load( lua_State *L );

extern "C" int luaopen_nyaole(lua_State *L)
{
    DBG( puts("STEP-1") );
    lua_newtable(L);
    DBG( puts("STEP-2") );
    lua_pushcfunction(L,com_create_object);
    DBG( puts("STEP-3") );
    lua_setfield(L,-2,"create_object");
    DBG( puts("STEP-4") );
    lua_pushcfunction(L,com_get_active_object);
    DBG( puts("STEP-5") );
    lua_setfield(L,-2,"get_active_object");
    DBG( puts("STEP-6") );
    lua_pushcfunction(L,com_const_load);
    DBG( puts("STEP-7") );
    lua_setfield(L,-2,"const_load");
    DBG( puts("STEP-8") );
    return 1;
}
