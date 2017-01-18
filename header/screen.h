#ifndef SCREEN_H
#define SCREEN_H


#include <SDL2/SDL.h>

#define SCREEN_WIDTH 360
#define SCREEN_HEIGHT 500
#define FPS 12

Uint32 start;
SDL_Window *window=NULL;
SDL_Renderer *screen=NULL;

void setScreen(const char* title){
SDL_Init(SDL_INIT_VIDEO);
window=SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,0);
screen=SDL_CreateRenderer(window,1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	SDL_SetRenderDrawBlendMode(screen, SDL_BLENDMODE_BLEND);
}

void update(){
	//update screen
	SDL_RenderPresent(screen);
//clean screen and color it black
SDL_SetRenderDrawColor(screen,0,0,0,255);
SDL_RenderClear( screen );


if(1000.0/FPS>(SDL_GetTicks()-start)){
	SDL_Delay(1000.0/FPS-(SDL_GetTicks()-start));
}
}
#endif
