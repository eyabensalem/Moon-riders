/**
* @file navg.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 2, 2020
*
* integrated program for navg
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>
#include"navg.h"
/**
* @brief initializate navg struct
* @param navg
* @param screen 
* @return Nothing
*/
void NAVG_Init(Navg *navg, SDL_Surface **screen){
	navg->screen = screen;
	navg->bg = IMG_Load("navg.png");
	navg->font = TTF_OpenFont("theme.ttf",50);

	navg->rouge.r = 217;
	navg->rouge.g = 10;
	navg->rouge.b = 4;

	navg->gold.r = 251;
	navg->gold.g = 208;
	navg->gold.b = 119;	

	navg->noire.r = navg->noire.g = navg->noire.b = 0;
	navg->choixMenu = 0;
	navg->enabled = 0;
}
/**
* @brief blit background and text
* @param navg
* @return Nothing
*/
void NAVG_Render(Navg *navg){
	SDL_BlitSurface(navg->bg, NULL, *navg->screen, NULL);


	//NAVG_RenderFont(navg,110,500,"JOYSTICK",navg->choixMenu == 0);
	NAVG_RenderFont(navg,570,500,"KEYBOARD", navg->choixMenu == 1);
	NAVG_RenderFont(navg,1050,500,"MOUSE", navg->choixMenu == 2);
	
}
/**
* @brief pour blitter le texte
* @param navg
* @param x position 
* @param y position
* @param text a afficher
* @param b condition
* @return Nothing
*/
void NAVG_RenderFont(Navg *navg, int x, int y, const char* text, int b){
	SDL_Rect r;
	r.x = x;
	r.y = y;
	navg->msg = TTF_RenderText_Solid(navg->font,text,navg->noire);
	SDL_BlitSurface(navg->msg,NULL,*navg->screen,&r);
	r.x -= 7;
	r.y += 7;
	if(!b)
		navg->msg = TTF_RenderText_Solid(navg->font,text,navg->rouge);
	else 
		navg->msg = TTF_RenderText_Solid(navg->font,text,navg->gold);
	SDL_BlitSurface(navg->msg,NULL,*navg->screen,&r);
}
/**
* @brief gestion son et touches avec souris et clavier
* @param navg 
* @param event evenement
* @return Nothing
*/
void NAVG_HandleEvent(Navg *navg,SDL_Event *event){
SDL_Rect position;
Mix_Chunk *son;
son = Mix_LoadWAV("bt3.wav");
			if(event->type == SDL_KEYDOWN){
				if(event->key.keysym.sym == SDLK_RIGHT){
					if(navg->choixMenu != 2){
						navg->choixMenu++;
						
						Mix_PlayChannel(1, son, 0);}
					/*else {
						navg->choixMenu = 0;
						Mix_PlayChannel(1, son, 0);}*/
				}
				if(event->key.keysym.sym == SDLK_LEFT){
					if(navg->choixMenu != 0){
						
						Mix_PlayChannel(1, son, 0);
						navg->choixMenu--;}
					else {
						navg->choixMenu = 2;
						Mix_PlayChannel(1, son, 0); }
				}

				if(event->key.keysym.sym == SDLK_RETURN){
					if(navg->choixMenu == 1){
						navg->enabled =0 ;}
					/*if(navg->choixMenu == 2){
						navg->enabled =0 ;}*/
					if(navg->choixMenu == 0){
						navg->enabled =0 ;}
						
					
					
				}
				if(event->key.keysym.sym == SDLK_ESCAPE){
					navg->enabled = 0;
				}
			}
		if(event->type  == SDL_MOUSEMOTION){
					position.x=100	;
					position.y=500;
				/*if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+150)&&(event->motion.y<=position.y+50))	{
						navg->choixMenu=0;
					Mix_PlayChannel(1, son, 0);}
			
					position.x=570;
					position.y=500;*/
				 		if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+200)&&(event->motion.y<=position.y+80))	{
						navg->choixMenu=1;
					Mix_PlayChannel(1, son, 0);}
					
					position.x=1050;
					position.y=500;
				 		if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+150)&&(event->motion.y<=position.y+80))	{
						navg->choixMenu=2;
					Mix_PlayChannel(1, son, 0);}

					
				
				

			

			}
}

