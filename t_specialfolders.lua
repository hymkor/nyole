local ole=require('nyole')
local objShell = ole.create_object("WScript.Shell")
print("ANSI:",objShell.SpecialFolders("Desktop"):Item(0))

objShell = ole.create_object_utf8("WScript.Shell")
print("UTF8:",objShell.SpecialFolders("Desktop"):Item(0))
