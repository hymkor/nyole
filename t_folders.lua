
local ole=require('nyole')
local fsObj=ole.create_object('Scripting.FileSystemObject')
local folder=fsObj:GetFolder('.')

for f in pairs(folder:files()) do
    print(f.Name)
end
