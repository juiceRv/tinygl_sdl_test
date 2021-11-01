#ifndef __LIBSDL_
#define __LIBSDL_
#include <SDL2/SDL.h>
typedef struct
{
    SDL_Window * window;
    // SDL_Surface * screen;
    SDL_Renderer *renderer;
    char * title;
	int width;
	int height;
}libsdl_pdev;
void juicevm_pdev_fb_new(libsdl_pdev *sdl_p);
void juicevm_pdev_fb_destroy(libsdl_pdev *sdl_p);
void juicevm_pdev_fb_draw_rgba(libsdl_pdev *sdl_p,int x,int y,int r,int g,int b,int a);
void juicevm_pdev_fb_draw_rgb(libsdl_pdev *sdl_p,int x,int y,int r,int g,int b);
void juicevm_pdev_fb_draw_rgb_noly_set(libsdl_pdev *sdl_p,int x,int y,int r,int g,int b);
void juicevm_pdev_fb_render(libsdl_pdev *sdl_p);

#endif // __LIBSDL_