TARGET=nyole.dll 
LUA53=lua-5.3.0
OBJECTS=nyole.o lua32com.o win32com.o nyole.def nyole.syso

$(TARGET): $(OBJECTS)
	g++ -shared -o $@ $(OBJECTS) -s -lole32 -loleaut32 -luuid -llua53 -L. -L$(LUA53)\src

nyole.o : nyole.cpp
lua32com.o : lua32com.cpp
win32com.o : win32com.cpp win32com.h
nyole.syso : nyole.rc
	windres.exe --output-format=coff -o nyole.syso nyole.rc

.cpp.o :
	g++ -c $< -I.\include -I$(LUA53)\src -o $@

clean :
	cmd.exe /c "del *.o $(TARGET)"

status:
	lua showver.lua nyole.dll

package :
	for /F %%I in ('cscript //nologo showver.js $(TARGET)') do zip -9 nyole-%%I.zip $(TARGET) readme.md *.lua

test:
	lua showver.lua "$(TARGET)"
