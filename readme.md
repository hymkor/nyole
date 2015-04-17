Nihongo Yet another OLE for lua
===============================

Sample
------

### Create OLE Object

    local ole=require('nyole')
    local objShell = ole.create_object("WScript.Shell")
    print(objShell.SpecialFolders("Desktop"):Item(0))

- `create_object` is the function for ANSI-String on the current codepage.
- For utf8, use `create_object_utf8`

### Iterator

    local ole=require('nyole')
    local fsObj=ole.create_object('Scripting.FileSystemObject')
    local folder=fsObj:GetFolder('.')
    local files=folder:files()

    for val in files:__iter__() do
        print(val.name)
    end
    print("done")

Required Software to build
--------------------------

- [Lua 5.3](http://www.lua.org/)
- [tdm-cc](http://tdm-gcc.tdragon.net/)

### To build:

    mingw32-make LUA53=(PATH\TO\LUA-5.3.0)
