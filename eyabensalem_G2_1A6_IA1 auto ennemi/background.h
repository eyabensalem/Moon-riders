#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>
#include "defs.h"
/**
* @struct Background
* @brief struct for background
*/
struct Background
{
	SDL_Surface *background; /*<!image */
	SDL_Rect posback; //position /*<!position */
};
typedef struct Background Background;


int init_background(Background* B);
void display_background(Background B,SDL_Surface *screen);
void freeBackground(Background* B);
int loadBackground(Background* B);
void initBackgoundAttributes(Background *B);

#endif
