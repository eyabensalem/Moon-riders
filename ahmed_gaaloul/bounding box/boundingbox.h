#ifndef BOUNDINGBOX_H

#define BOUNDINGBOX_H

#include "SDL/SDL.h"

#include "SDL/SDL_mixer.h"



#define BOTTOM 1

#define TOP 2

#define LEFT 3

#define RIGHT 4

SDL_Surface * initEcran(char * titre, char * icone, int largeur, int hauteur);
void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect *position);

#endif // BOUNDINGBOX_H


