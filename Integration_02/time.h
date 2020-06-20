#pragma once
#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>

/**
* @struct time
* @brief struct for time
*/
typedef struct Time {
	SDL_Surface *msg,*txt;/*<!text*/
	TTF_Font *font;/*<!font*/
	int time,score;/*<!time et scor*/
	SDL_Rect r;/*<!position*/
	char timeString[10],scoreString[10];/*<!text a afficher*/

} Time;

void initializerTemps(Time *time);
void afficherTemps(Time *time,SDL_Surface **screen);
