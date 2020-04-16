#include<SDL/SDL.h>

#include<SDL/SDL_ttf.h>

#include"time.h"

int main()

{

SDL_Surface *screen;



	SDL_Init(SDL_INIT_EVERYTHING);

	TTF_Init();

	

	Time time;

	initializerTemps(&time);

	screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

	int running = 1;

	SDL_Event event;

	while(running){

		while(SDL_PollEvent(&event))

		{



			if(event.type==SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)){

				running = 0;

			}



		}



			SDL_FillRect(screen,NULL,0x000000);

			afficherTemps(&time,&screen);

			SDL_Flip(screen);

			SDL_Delay(16);

	}

	

	SDL_Quit();

}


