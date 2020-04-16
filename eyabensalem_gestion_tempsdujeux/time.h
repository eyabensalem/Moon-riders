#pragma once

#include<SDL/SDL.h>

#include<SDL/SDL_ttf.h>





typedef struct Time {

	SDL_Surface *msg;

	TTF_Font *font;

	int time;

	char timeString[10];

} Time;



void initializerTemps(Time *time);

void afficherTemps(Time *time,SDL_Surface **screen);


