local ole = require('nyole')
local fsObj = ole.create_object("Scripting.FileSystemObject")
local fd = fsObj:OpenTextFile(arg[0])
if fd then
    while not fd.AtEndOfStream do
        local line = fd:ReadLine()
        print(line)
    end
    fd:Close()
end
