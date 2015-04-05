local ole=require('nyole')
local objShell = ole.create_object("WScript.Shell")
print(objShell.SpecialFolders("Desktop"):Item(0))

