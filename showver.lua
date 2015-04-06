local ole=require("nyole")
local fsObj=ole.create_object("Scripting.FileSystemObject")
for i=1,#arg do
    local ver = fsObj:GetFileVersion(arg[i])
    print(ver)
end
