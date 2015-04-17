
local ole=require('nyole')
local fsObj=ole.create_object('Scripting.FileSystemObject')
local folder=fsObj:GetFolder('.')
local f=folder:files()

for val in pairs(f) do
    print(val.name)
end
print("done")

--[[
for i=0,f.Count do
    local file=f:Item(i)
    print(file:Name())
end
]]--
