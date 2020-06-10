#ifndef SCROLLING_H_INCLUDED
#define SCROLLING_H_INCLUDED

#include "input.h"

typedef struct 
{
 int xscroll, yscroll, wscroll, hscroll;
 SDL_Surface *image;	
}Map;


SDL_Surface* Loadimage(const char* fich);
void initMap(Map* m, const char* fich, int w, int h);
void moveMap(Map* m, int move, Input* in);
void afficher(Map* m);


#endif // SCROLLING_H_INCLUDED