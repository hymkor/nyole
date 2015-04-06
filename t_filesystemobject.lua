
function typefile(fsObj)
    local fd = fsObj:OpenTextFile(arg[0])
    if fd then
        while not fd.AtEndOfStream do
            local line = fd:ReadLine()
            print(line)
        end
        fd:Close()
    end
end

local ole = require('nyole')
print("Try with ANSI")
typefile(ole.create_object("Scripting.FileSystemObject"))
print("Try with UTF8")
typefile(ole.create_object_utf8("Scripting.FileSystemObject"))
