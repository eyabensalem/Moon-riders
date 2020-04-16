#include <stdio.h>

#include <stdlib.h>

#include "boundingbox.h"

#include "SDL/SDL.h"

#include "SDL/SDL_image.h"

#include "SDL/SDL_mixer.h"

#include "SDL/SDL_ttf.h"

#define LARGEURECRAN 640

#define HAUTEURECRAN 480

#define TITREECRAN "Collision bounding box SDL"

#define ICONE "pomme.png"



int direction = 0;

int speed = 0;



int collision(SDL_Rect a, SDL_Rect b)

{

	if(!(a.x > b.x+b.w || a.y > b.y+b.h || a.x+a.w < b.x || a.y+a.h < b.y)){

	return 1;

}

	return 0;

}



int main(int argc, char *argv[])

{

    SDL_Surface *ecran = NULL, *msg = NULL;

    TTF_Init();

    TTF_Font *font;

    font = TTF_OpenFont("theme.ttf",20);

    SDL_Color textColor = {0,0,0};

    msg = TTF_RenderText_Solid(font,"TEST",textColor);

    SDL_Rect textRect= {280,300};

    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);

    Mix_Music *music;

    music = Mix_LoadMUS("test.wav");

    SDL_Rect positionImg1={150,240},positionImg2={320,240};

    int continuer = 1;

    SDL_Event event;

    ecran = initEcran(TITREECRAN, ICONE,LARGEURECRAN , HAUTEURECRAN);

    int color = 0x000000;

    while(continuer)

    {

        SDL_PollEvent(&event);

	speed = 0;	

	if(event.type == SDL_QUIT) 

		continuer = 0;

	if(event.type == SDL_KEYDOWN)

	{

		if(event.key.keysym.sym == SDLK_ESCAPE){

			continuer = 0;

		}

		if(event.key.keysym.sym == SDLK_RIGHT){

			direction = 2;

			speed = 1;

		}

		if(event.key.keysym.sym == SDLK_LEFT){

			direction = 0;

			speed = 1;

		}

		if(event.key.keysym.sym == SDLK_UP){

			direction = 1;

			speed = 1;

		}

		if(event.key.keysym.sym == SDLK_DOWN){

			direction = 3;

			speed = 1;

		}

	}

	SDL_FillRect(ecran,&ecran->clip_rect,color);



        blitImageSurSurface(ecran, "pomme.png", &positionImg2);

        blitImageSurSurface(ecran, "pomme.png", &positionImg1);



	if(collision(positionImg1,positionImg2))

	{

		color = 0xffffff;

		if(direction == 0)

			positionImg1.x += 2;

		if(direction == 1)

			positionImg1.y += 2;

		if(direction == 2)

			positionImg1.x -= 2;

		if(direction == 3)

			positionImg1.y -= 2;

		Mix_PlayMusic(music,1);

	}

	else

	{

		color = 0x000000;

	}



	if(direction == 2)

	{

		positionImg1.x += speed;

	}

	if(direction == 0)

	{

		positionImg1.x -= speed;

	}

	if(direction == 1)

	{

		positionImg1.y -= speed;

	}

	if(direction == 3)

	{

		positionImg1.y += speed;

	}



	SDL_BlitSurface(msg,NULL,ecran,&textRect);

        SDL_Flip(ecran);

	SDL_Delay(16);

    }

    SDL_Quit();

    return 0;

}


