#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "zgl.h"
#include <generated/autoconf.h>
// GLContext *gl_context;
ZBuffer *zb;
unsigned int palette[ZB_NB_COLORS];
unsigned char color_indexes[ZB_NB_COLORS];
int i,xsize,ysize;
xsize = CONFIG_FB_SDL_WIDTH;
ysize = CONFIG_FB_SDL_HEIGHT;
unsigned char *framebuffer;
int bytes_per_line;

#define printf(...)
#define fflush(...)

static int juicegl_resize_viewport(GLContext *c,
                               int *xsize_ptr,
                               int *ysize_ptr) {
    int xsize;
    int ysize;

    xsize = *xsize_ptr;
    ysize = *ysize_ptr;

    /* we ensure that xsize and ysize are multiples of 2 for the zbuffer.
       TODO: find a better solution */
    xsize &= ~3;
    ysize &= ~3;

    if (xsize == 0 || ysize == 0)
        return -1;

    *xsize_ptr = xsize;
    *ysize_ptr = ysize;

    /* resize the Z buffer */
    ZB_resize(c->zb, framebuffer, xsize, ysize);
    return 0;
}
void juicegl_init(void){
    bytes_per_line = xsize * 3;
    framebuffer=gl_malloc(ysize * bytes_per_line);
    printf("framebuffer %p\n",framebuffer);
    /* Open the Z Buffer - 256 colors */
    // zb=ZB_open(xsize,ysize,ZB_MODE_INDEX,ZB_NB_COLORS,color_indexes,palette,NULL);
    zb = ZB_open(xsize, ysize, ZB_MODE_RGB24, 0, NULL, NULL, framebuffer);
    if (zb == NULL) {
        printf("Error while initializing Z buffer\n");
        // exit(1);
    }

    /* initialisation of the TinyGL interpreter */
    glInit(zb);
    
	GLContext *gl_context;
	gl_context=gl_get_context();
    gl_context->gl_resize_viewport=juicegl_resize_viewport;
	gl_context->viewport.xsize=-1;
    gl_context->viewport.ysize=-1;
	// glViewport(0, 0, CONFIG_FB_SDL_WIDTH, CONFIG_FB_SDL_HEIGHT);
    glViewport(0, 0, xsize, ysize);
}

void juice_fb0_update(void) {
    GLContext *gl_context;
    gl_context=gl_get_context();
    // ZB_copyFrameBuffer(gl_context->zb,framebuffer,CONFIG_FB_SDL_WIDTH);
}

unsigned char *juice_fb0_getfb(void) {
    return framebuffer;
}

void juice_fb0_destroy(void) {
    glClose();

}