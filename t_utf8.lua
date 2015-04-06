local ole = require('nyole')
local fsObj = assert(ole.create_object_utf8("Scripting.FileSystemObject"))
assert( fsObj )
-- CreateTextFile can make utf16-data, but can not make utf8-data. --
local fd = assert(fsObj:CreateTextFile(utf8.char(0x262D)..".txt",true,true))
if fd then
    -- print("WriteLine")
    fd:WriteLine("HOGEHOGE")
    fd:WriteLine(utf8.char(0x262D).."DATA")
    -- print("Close")
    fd:Close()
end
