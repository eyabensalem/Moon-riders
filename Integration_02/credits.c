/**
*@file credits.c
*@brief Integrated Program
*@author eya ben salem
*@version 2.0
*@date july 4, 2020
*
*Integrated Program for credits
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"credits.h"
/**
*@brief To load picture
*@param s credits
*@return Nothing
*/
void CREDITS_Init(Credits *s){
	s->bg = IMG_Load("credits.png");
	s->enabled = 0;
}
/**
*@brief to blit the picture in the screen
*@param s credits 
*@param screen 
*@return Nothing
*/
void CREDITS_Render(Credits *s,SDL_Surface **screen){
	SDL_BlitSurface(s->bg,NULL,*screen,NULL);
}
/**
*@brief to return to main menu
*@param s the credits 
*@param event
*@return Nothing
*/
void CREDITS_HandleEvent(Credits *s, SDL_Event *event){
	if(event->type == SDL_KEYDOWN){
		if(event->key.keysym.sym == SDLK_ESCAPE){
			s->enabled = 0;
		}
	}
}
