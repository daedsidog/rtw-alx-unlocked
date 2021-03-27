CC=clang
CFLAGS=-m32 -static -shared
STEAM_FLAGS=-DSTEAM
DEBUG_FLAGS=-DDEBUG -g
RELEASE_FLAGS=-O3

rtw-alx-unlocked_all:
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) dllmain.cpp */*.cpp -o ../rtw-alx-unlocked.dll
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) dllmain.cpp */*.cpp -o ../rtw-alx-unlocked_d.dll
	$(CC) $(CFLAGS) $(STEAM_FLAGS) $(RELEASE_FLAGS) dllmain.cpp */*.cpp -o ../rtw-alx-unlocked_steam.dll
	$(CC) $(CFLAGS) $(STEAM_FLAGS) $(DEBUG_FLAGS) dllmain.cpp */*.cpp -o ../rtw-alx-unlocked_steam.dll

