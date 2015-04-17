local ole=require('nyole')
local fsObj=ole.create_object('Scripting.FileSystemObject')
local folder=fsObj:GetFolder('.')
local files=folder:files()

for val in files:__iter__() do
    print(val.name)
end
print("done")
