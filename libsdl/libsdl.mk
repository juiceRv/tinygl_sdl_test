install:
	sudo apt-get install libsdl2-dev
all:
	gcc ./libsdl.c -D__juicevm_libsdl_test_ -lSDL2 -o libsdl_test.out
SDL2_PATH = SDL2-2.0.16/
win:
	x86_64-w64-mingw32-gcc-posix -D__juicevm_libsdl_test_ -DSDL_MAIN_HANDLED ./libsdl.c -I$(SDL2_PATH)/x86_64-w64-mingw32/include -L$(SDL2_PATH)/x86_64-w64-mingw32/lib -lSDL2 -o libsdl_test.exe