#include<SDL/SDL.h>
#include"main.h"
#include"pixelperfectcollision.h"


int main(){
	pos.x = pos.y = 50;
	pos2.x = pos2.y = 100;
	SDL_Init(SDL_INIT_EVERYTHING);

	screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
	rect = SDL_CreateRGBSurface(0,32,32,32,0,0,0,0);
	SDL_FillRect(rect,NULL,0xffffff);

	int running = 1;
	SDL_Event event;
	while(running){
		while(SDL_PollEvent(&event)){

			if(event.type==SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)){
				running = 0;
			}

			if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT){
				pos.x += 10;
			}

			if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN){
				pos.y += 10;
			}

			if(collision(rect,pos,rect,pos2)){
				running = 0;
			}

			SDL_FillRect(screen,NULL,0x000000);
			SDL_BlitSurface(rect,NULL,screen,&pos);
			SDL_BlitSurface(rect,NULL,screen,&pos2);
			SDL_Flip(screen);
		}
	}
	
	SDL_Quit();
}
