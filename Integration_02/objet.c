/**
*@file objet.c
*@brief Integrated Program
*@author eya ben salem
*@version 2.0
*@date july 04, 2020
*
*Integrated Program for object 
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"objet.h"

/**
*@brief To inisialize the object
*@param c the object structure
*@param path the path where exists the object's image to load it
*@param x object position on X
*@param y object position on Y
*@return Nothing
*/  
void OBJET_Init(Objet *c, int x, int y, const char* path){
	c->sprite = IMG_Load(path);
	c->x = x;
	c->y = y;
}
/**
*@brief To display the object
*@param c the object structure
*@param r Render
*@param screen the screen where the object is displayed
*@return Nothing
*/
void OBJET_Render(Objet *c, SDL_Rect r, SDL_Surface **screen){
	SDL_Rect r2 = {c->x - r.x, c->y};
	SDL_BlitSurface(c->sprite,NULL,*screen, &r2);
}
