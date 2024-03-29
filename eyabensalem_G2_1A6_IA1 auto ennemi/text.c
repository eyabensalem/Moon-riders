/**
* @file text.c
* @brief Testing Program.
* @author Ben salem Eya 
* @version 0.1
* @date july 14,2020
*
* Testing program for text
*
*/
#include "text.h"
/**
* @brief init text
* @param t text
* @return Nothing
*/
int init_text(Text* T)
{
	int OK;
	
	OK = loadFont(T);
	if (OK != -1) 
	{
		initTextAttributes(T);
	}
	return OK;
}


int loadFont(Text* T)
{
	TTF_Font* police = NULL;

	if(TTF_Init() == -1) {
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return -1;
	}
	police = TTF_OpenFont("Ubuntu-title.ttf", 20);
	if (police == NULL) {
		printf("Unable to load Font: %s\n", SDL_GetError());
		return (-1);
	}
	
	T->police = police;
	return (0);
}

void initTextAttributes(Text* T)
{	
	T->couleurTxt.r = 0; 
	T->couleurTxt.g = 0; 
	T->couleurTxt.b = 0;

	T->couleurShadow.r = 255; 
	T->couleurShadow.g = 255; 
	T->couleurShadow.b = 255;

	strcpy(T->txt, "");
	T->positionText.x = 200;
	T->positionText.y = 50;	
}

void update_txt(Text* T, int viesHero)
{
	sprintf(T->txt,"*** VIES = %d  ***",viesHero);
}
/**
* @brief 
* @param t text
* @return Nothing
*/
void displayText(Text T,SDL_Surface *screen)
{
	
	SDL_Surface* textSurface = NULL;	
	
	textSurface = TTF_RenderText_Shaded(T.police,T.txt,T.couleurTxt, T.couleurShadow);
	SDL_SetColorKey(textSurface, SDL_SRCCOLORKEY, SDL_MapRGB(textSurface->format, 255, 255, 255));
	SDL_BlitSurface(textSurface,NULL,screen,&(T.positionText));

}
/**
* @brief free text
* @param t text
* @return Nothing
*/
void freeText(Text* T)
{
	TTF_CloseFont(T->police); 
        TTF_Quit();	
}
