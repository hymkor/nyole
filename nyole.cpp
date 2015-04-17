#include <stdio.h>
#include <windows.h>

extern "C"{
#  include "lua.h"
#  include "lualib.h"
#  include "lauxlib.h"
}

// #define DBG(s) (s)
#define DBG(s)

static wchar_t modulePath[ _MAX_PATH ];
static char modulePathAnsi[ _MAX_PATH ];
static char modulePathUtf8[ _MAX_PATH ];

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
    lua_pushstring(L,modulePathAnsi);
    lua_setfield(L,-2,"dll");
    lua_pushstring(L,modulePathUtf8);
    lua_setfield(L,-2,"dll_utf8");
    return 1;
}


BOOL APIENTRY DllMain (HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    GetModuleFileNameW((HMODULE) hModule,
            modulePath,
            sizeof(modulePath)/sizeof(wchar_t));
    WideCharToMultiByte(CP_ACP,0,modulePath,-1,modulePathAnsi,sizeof(modulePathAnsi)/sizeof(char)-1,NULL,NULL);
    WideCharToMultiByte(CP_UTF8,0,modulePath,-1,modulePathUtf8,sizeof(modulePathUtf8)/sizeof(char)-1,NULL,NULL);

    return TRUE;
}
