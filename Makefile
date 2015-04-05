LUA53=lua-5.3.0

nyaole.dll : nyaole.o lua32com.o win32com.o nyaole.def
	g++ -shared -o $@ $^ -s -lole32 -loleaut32 -luuid -llua53 -L$(LUA53)\src

nyaole.o : nyaole.cpp
lua32com.o : lua32com.cpp
win32com.o : win32com.cpp win32com.h

.cpp.o :
	g++ -c $< -I$(LUA53)\src -o $@

clean :
	rm *.o
