# Makefile for nmake

TARGET=nyole.dll 
! ifndef LUA53
LUA53=lua-5.3.0
! endif

$(TARGET): nyole.o lua32com.o win32com.o nyole.def nyole.syso
	g++ -shared -o $@ $** -s -lole32 -loleaut32 -luuid -llua53 -L. -L$(LUA53)\src

nyole.o : nyole.cpp
lua32com.o : lua32com.cpp
win32com.o : win32com.cpp win32com.h
nyole.syso : nyole.rc
	windres.exe --output-format=coff -o nyole.syso nyole.rc

.cpp.o :
	g++ -c $< -I$(LUA53)\src -o $@

clean :
	rm *.o $(TARGET)

package :
	for /F %%I in ('lua showver.lua $(TARGET)') do zip -9 nyole-%%I.zip $(TARGET) readme.md *.lua
