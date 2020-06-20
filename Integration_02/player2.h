#pragma once

#include"vie.h"
#include"time.h"
/**
* @struct player2
* @brief struct for player2
*/
typedef struct Player2{

	int x,y,vx,vy;
	SDL_Surface **screen,*image, *image2;
	SDL_Rect position;
	SDL_Rect clips[5];
	SDL_Rect clips2[5];
	float frame;
	Time time;
	Vie vie;
} Player2;

void PLAYER2_Init(Player2 *p);
void PLAYER2_Render(Player2 *p,SDL_Rect r, SDL_Surface **screen);

