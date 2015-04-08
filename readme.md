Nihongo Yet another OLE for lua
===============================

Sample
------

    local ole=require('nyole')
    local objShell = ole.create_object("WScript.Shell")
    print(objShell.SpecialFolders("Desktop"):Item(0))

- `create_object` is the function for ANSI-String on the current codepage.
- For utf8, use `create_object_utf8`

Required Software to build
--------------------------

- [Lua 5.3](http://www.lua.org/)
- [tdm-cc](http://tdm-gcc.tdragon.net/)

### To build:

    mingw32-make LUA53=(PATH\TO\LUA-5.3.0)
