#include <stdio.h>
#include "libsdl.h"

void juicevm_pdev_fb_new(libsdl_pdev *sdl_p){
    SDL_Init(SDL_INIT_VIDEO);
    // uint32_t flags = SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS;
    uint32_t flags = SDL_WINDOW_SHOWN;
    // sdl_p->window = SDL_CreateWindow(sdl_p->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sdl_p->width, sdl_p->height, flags);
    sdl_p->window = SDL_CreateWindow(sdl_p->title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sdl_p->width, sdl_p->height, flags);
    if(!sdl_p->window)
	{
		return;
	}
    // sdl_p->screen = SDL_GetWindowSurface(sdl_p->window);
    // if(!sdl_p->screen)
	// {
	// 	if(sdl_p->window){
	// 		SDL_DestroyWindow(sdl_p->window);
    //     }
	// 	return;
	// }
    // SDL_GetWindowSize(sdl_p->window, &sdl_p->width, &sdl_p->height);

    /* 为窗口中创建 renderer */
    sdl_p->renderer = SDL_CreateRenderer(sdl_p->window, -1, SDL_RENDERER_SOFTWARE);
    if(!sdl_p->renderer)
	{
		if(sdl_p->window){
			SDL_DestroyWindow(sdl_p->window);
        }
		return;
	}
    // /* 将 renderer 清空成白色 */
    // SDL_SetRenderDrawColor(sdl_p->renderer, 255, 255, 255, 255);
    // SDL_RenderClear(sdl_p->renderer);
    // SDL_RenderPresent(sdl_p->renderer);

}

void juicevm_pdev_fb_destroy(libsdl_pdev *sdl_p)
{

	if(!sdl_p){
		return;
    }
	if(sdl_p->window){
        SDL_DestroyWindow(sdl_p->window);
    }
	
	// if(sdl_p->screen){
    //     SDL_FreeSurface(sdl_p->screen);
    // }

    if(sdl_p->renderer){
        SDL_DestroyRenderer(sdl_p->renderer);
    }
    SDL_Quit();
}

void juicevm_pdev_fb_draw_rgba(libsdl_pdev *sdl_p,int x,int y,int r,int g,int b,int a){
    if(!sdl_p){
		return;
    }
    SDL_SetRenderDrawColor(sdl_p->renderer, r, g, b, a);
    SDL_RenderDrawPoint(sdl_p->renderer, x, y);
    SDL_RenderPresent(sdl_p->renderer);
}

void juicevm_pdev_fb_draw_rgb(libsdl_pdev *sdl_p,int x,int y,int r,int g,int b){
    if(!sdl_p){
		return;
    }
    SDL_SetRenderDrawColor(sdl_p->renderer, r, g, b, 255);
    SDL_RenderDrawPoint(sdl_p->renderer, x, y);
    SDL_RenderPresent(sdl_p->renderer);
}

void juicevm_pdev_fb_draw_rgb_noly_set(libsdl_pdev *sdl_p,int x,int y,int r,int g,int b){
    if(!sdl_p){
		return;
    }
    SDL_SetRenderDrawColor(sdl_p->renderer, r, g, b, 255);
    SDL_RenderDrawPoint(sdl_p->renderer, x, y);
    
}
void juicevm_pdev_fb_render(libsdl_pdev *sdl_p) {
    if(!sdl_p){
		return;
    }
    SDL_RenderPresent(sdl_p->renderer);
}


#ifdef __juicevm_libsdl_test_
int main(int argc, char const *argv[])
{
    libsdl_pdev tmp_sd_pdev;
    tmp_sd_pdev.title = "juicevm";
    tmp_sd_pdev.height = 300;
    tmp_sd_pdev.width = 600;
    juicevm_pdev_fb_new(&tmp_sd_pdev);
    juicevm_pdev_fb_draw_rgb(&tmp_sd_pdev, 0, 0, 255, 0, 0);
    // while(1){
        SDL_Delay(3000); 
    // }
    juicevm_pdev_fb_destroy(&tmp_sd_pdev);
}
#endif