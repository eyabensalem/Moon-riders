#include <stdio.h>

#include <stdlib.h>

#include "SDL/SDL.h"

#include "SDL/SDL_image.h"

#include "SDL/SDL_ttf.h"

#include "SDL/SDL_mixer.h"

#include "boundingbox.h"





SDL_Surface * initEcran(char * titre, char * icone,int largeur, int hauteur)

{

    SDL_Surface *ecran = NULL;

    SDL_Init(SDL_INIT_VIDEO);



    SDL_WM_SetIcon(IMG_Load("pomme.png"), NULL);

    ecran = SDL_SetVideoMode(largeur, hauteur, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    if (ecran == NULL)

    {

        printf("Impossible de charger le mode vidéo : %s\n", 			SDL_GetError());

        exit(EXIT_FAILURE);

    }

    SDL_WM_SetCaption("Collision Bounding Box", NULL);



    return ecran;

}

void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage,  SDL_Rect *position)

{

    SDL_Surface* loadedImage = NULL;

    loadedImage = IMG_Load("pomme.png");

    SDL_BlitSurface(loadedImage, NULL, surfaceBlit, position);

    SDL_FreeSurface(loadedImage);

}


