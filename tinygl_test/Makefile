.PHONY:all clean

CC 		:= x86_64-w64-mingw32-gcc-posix
PRJ_NAME := tinygl_sdl_test.exe
SDL2_PATH = ../libsdl/SDL2-2.0.16/
LDFLAGS		:=  -L$(SDL2_PATH)/x86_64-w64-mingw32/lib -lm -lSDL2

CFLAGS      := -I ../
CFLAGS      += -I .
CFLAGS      += -I ../libsdl/
CFLAGS      += -I ../TinyGL/include
CFLAGS      += -I ../TinyGL/src
CFLAGS      += -I ../include -DSDL_MAIN_HANDLED
CFLAGS      += -I$(SDL2_PATH)/x86_64-w64-mingw32/include
CFLAGS      += -w

SRCS       := main.c
SRCS       += juicegl.c
SRCS       += gears.c
SRCS       += ../libsdl/libsdl.c

SRCS       += ../TinyGL/src/api.c
SRCS       += ../TinyGL/src/list.c
SRCS       += ../TinyGL/src/vertex.c
SRCS       += ../TinyGL/src/init.c
SRCS       += ../TinyGL/src/matrix.c
SRCS       += ../TinyGL/src/texture.c
SRCS       += ../TinyGL/src/misc.c
SRCS       += ../TinyGL/src/clear.c
SRCS       += ../TinyGL/src/light.c
SRCS       += ../TinyGL/src/clip.c
SRCS       += ../TinyGL/src/select.c
SRCS       += ../TinyGL/src/get.c
SRCS       += ../TinyGL/src/error.c
SRCS       += ../TinyGL/src/zbuffer.c
SRCS       += ../TinyGL/src/zline.c
SRCS       += ../TinyGL/src/zdither.c
SRCS       += ../TinyGL/src/ztriangle.c
SRCS       += ../TinyGL/src/zmath.c
SRCS       += ../TinyGL/src/image_util.c
SRCS       += ../TinyGL/src/oscontext.c
SRCS       += ../TinyGL/src/msghandling.c
SRCS       += ../TinyGL/src/arrays.c
SRCS       += ../TinyGL/src/specbuf.c
SRCS       += ../TinyGL/src/memory.c


# DPEND := $(SRCS:.c=.c.d)

# -include $(PRJ_NAME).d

all: $(PRJ_NAME)

$(PRJ_NAME): $(SRCS) 
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean:
	rm $(PRJ_NAME).d $(PRJ_NAME)


# juicevm_gcc_embed_toolchains build arg:./configure --prefix=/mnt/ssd_prj/juicevm_gcc_embed_toolchains --with-arch=rv64ima --with-abi=lp64 --disable-linux --with-cmodel=medany && make -j

# [core]
#         repositoryformatversion = 0
#         filemode = false
#         bare = false
#         logallrefupdates = true
#         sshCommand = "ssh -i ~/.ssh/juiceRv "
# [remote "origin"]
#         url = git@github.com:juiceRv/juicevm_gcc_embed_toolchains.git
#         fetch = +refs/heads/*:refs/remotes/origin/*