#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "zgl.h"
#include <generated/autoconf.h>
#include "juicegl.h"
#include "libsdl.h"
libsdl_pdev tmp_sd_pdev;
void juice_fb_draw_rgb_set(uint16_t x,uint16_t y,uint8_t r,uint8_t g,uint8_t b) {

	juicevm_pdev_fb_draw_rgb_noly_set(&tmp_sd_pdev, x, y, r, g, b);
	// *((unsigned char *)(pdev_fb0_write_x_H_addr)) = (x >> 8) & 0xff;
	// *((unsigned char *)(pdev_fb0_write_x_L_addr)) = x & 0xff;
	// *((unsigned char *)(pdev_fb0_write_y_H_addr)) = (y >> 8) & 0xff;
	// *((unsigned char *)(pdev_fb0_write_y_L_addr)) = y & 0xff;

	// *((unsigned char *)(pdev_fb0_write_r_addr)) = r;
	// *((unsigned char *)(pdev_fb0_write_g_addr)) = g;
	// *((unsigned char *)(pdev_fb0_write_b_addr)) = b;

	// *((unsigned char *)(pdev_fb0_write_set_addr)) = 1;
}

void juice_fb_draw(void) {
	juicevm_pdev_fb_render(&tmp_sd_pdev);
	// *((unsigned char *)(pdev_fb0_write_render_addr)) = 1;
}

int main(int argc, char **argv){

    printf("fb draw test\r\n");
    printf("fb draw test %d %d\r\n",CONFIG_FB_SDL_WIDTH,CONFIG_FB_SDL_HEIGHT);
	// for(int tmp_y = 0;tmp_y < CONFIG_FB_SDL_HEIGHT;tmp_y++){
	// 	for(int tmp_x = 0;tmp_x < CONFIG_FB_SDL_WIDTH;tmp_x++){
	// 		juice_fb_draw_rgb_set(tmp_x,tmp_y,255,0,0);
	// 	}
	// 	juice_fb_draw();
	// }
	
    tmp_sd_pdev.title = "juicevm_tinygl_sdl_test";
    tmp_sd_pdev.height = CONFIG_FB_SDL_HEIGHT;
    tmp_sd_pdev.width = CONFIG_FB_SDL_WIDTH;
    juicevm_pdev_fb_new(&tmp_sd_pdev);
	printf("juice_fb_draw_rgb end\r\n");
	printf("juicevm_mem_init end\r\n");
	juicegl_init();
	printf("juicegl_init end\r\n");
	init();
	printf("init end\r\n");
  	reshape(CONFIG_FB_SDL_WIDTH, CONFIG_FB_SDL_HEIGHT);
	printf("reshape end\r\n");
	while(1) {
		// key(0, 0);
		// printf("idle\r\n");fflush(stdout);
		idle();
		// printf("idle end\r\n");fflush(stdout);
		juice_fb0_update();
		// printf("juice_fb0_update end\r\n");fflush(stdout);
		unsigned char *tmp_fb = juice_fb0_getfb();
		// printf("juice_fb0_getfb end %p\r\n",tmp_fb);fflush(stdout);
		// GLContext *gl_context;
		// gl_context=gl_get_context();
		for(int tmp_y = 0;tmp_y < CONFIG_FB_SDL_HEIGHT;tmp_y++){
			for(int tmp_x = 0;tmp_x < CONFIG_FB_SDL_WIDTH;tmp_x++){
				unsigned char r,g,b;
				r = (*tmp_fb++);
				g = *tmp_fb++;
				b = *tmp_fb++;
				// printf("x:%d y:%d r:%d g:%d b:%d\r\n",tmp_x,tmp_y,r,g,b);fflush(stdout);
				juice_fb_draw_rgb_set(tmp_x,tmp_y,r,g,b);
			}
		}
		juice_fb_draw();
		SDL_Event sdl_event;
		SDL_PollEvent(&sdl_event);
		switch(sdl_event.type){
			case SDL_QUIT:
				exit(0);
			break;
		}
		// SDL_Delay(100); 
		// printf("show end\r\n");fflush(stdout);
	}
	return 0;
    
}