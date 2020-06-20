/**
* @file menu2.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 04 2020
*
* integrated program for menu2
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>
#include"play.h"
#include"menu2.h"
#include"menu3.h"
#include"playm.h"
/**
* @brief initializate menu2 struct
* @param menu2
* @param screen 
* @return Nothing
*/
void MENU2_Init(Menu2 *menu2, SDL_Surface **screen){
	menu2->screen = screen;
	menu2->bg = IMG_Load("menu2.png");
	menu2->font = TTF_OpenFont("theme.ttf",86);

	menu2->rouge.r = 217;
	menu2->rouge.g = 10;
	menu2->rouge.b = 4;

	menu2->gold.r = 251;
	menu2->gold.g = 208;
	menu2->gold.b = 119;	

	menu2->noire.r = menu2->noire.g = menu2->noire.b = 0;
	menu2->choixMenu = -1;
	menu2->enabled = 0;
}
/**
* @brief initializate menu2 struct
* @param menu2
* @param screen 
* @return Nothing
*/
void MENU2_Render(Menu2 *menu2){
	SDL_BlitSurface(menu2->bg, NULL, *menu2->screen, NULL);

	MENU2_RenderFont(menu2,560,250,"SOLO",menu2->choixMenu == 0);
	MENU2_RenderFont(menu2,420,370,"MULTIPLAYER", menu2->choixMenu == 1);
	
}
/**
* @brief pour blitter le texte
* @param menu
* @param x position 
* @param y position
* @param text a afficher
* @param b condition
* @return Nothing
*/
void MENU2_RenderFont(Menu2 *menu2, int x, int y, const char* text, int b){
	SDL_Rect r;
	r.x = x;
	r.y = y;
	menu2->msg = TTF_RenderText_Solid(menu2->font,text,menu2->noire);
	SDL_BlitSurface(menu2->msg,NULL,*menu2->screen,&r);
	r.x -= 7;
	r.y += 7;
	if(!b)
		menu2->msg = TTF_RenderText_Solid(menu2->font,text,menu2->rouge);
	else 
		menu2->msg = TTF_RenderText_Solid(menu2->font,text,menu2->gold);
	SDL_BlitSurface(menu2->msg,NULL,*menu2->screen,&r);
}
/**
* @brief gestion son et touches avec souris et clavier
* @param menu 
* @param game screen
* @param event evenement
* @return Nothing
*/
void MENU2_HandleEvent(Menu2 *menu2,Menu3 *menu3,Playm *playm,SDL_Event *event){
Mix_Chunk *son;
SDL_Rect position;
son = Mix_LoadWAV("bt3.wav");
			if(event->type == SDL_KEYDOWN){
				if(event->key.keysym.sym == SDLK_DOWN){
					if(menu2->choixMenu != 1){
						menu2->choixMenu++;
						
						Mix_PlayChannel(1, son, 0);}
					else {
						menu2->choixMenu = 0;
						Mix_PlayChannel(1, son, 0);}
				}
				if(event->key.keysym.sym == SDLK_UP){
					if(menu2->choixMenu != 0){
						
						Mix_PlayChannel(1, son, 0);
						menu2->choixMenu--;}
					else {
						menu2->choixMenu = 1;
						Mix_PlayChannel(1, son, 0); }
				}

				if(event->key.keysym.sym == SDLK_RETURN){
					if(menu2->choixMenu == 1){
						menu2->enabled = 0;
						playm->enabled = 1;
						
					}
					if(menu2->choixMenu == 0){
						menu2->enabled = 0;
						menu3->enabled = 1;
					}
				}
				if(event->key.keysym.sym == SDLK_ESCAPE){
					menu2->enabled = 0;
				}
			}

			if(event->type  == SDL_MOUSEMOTION){
					position.x=560;
					position.y=250;
				if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+150)&&(event->motion.y<=position.y+80))	{
						menu2->choixMenu=0;
					Mix_PlayChannel(1, son, 0);}
			
					position.x=420;
					position.y=370;
				 		if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+500)&&(event->motion.y<=position.y+80))	{
						menu2->choixMenu=1;
					Mix_PlayChannel(1, son, 0);}

					
				
				

			

			}
if(event->type ==SDL_MOUSEBUTTONDOWN)
				{
				if(event->button.button==SDL_BUTTON_LEFT){
					
					if(menu2->choixMenu == 1){
						menu2->enabled = 0;
						playm->enabled = 1;}
					if(menu2->choixMenu == 0){
						menu2->enabled = 0;
						menu3->enabled = 1;}
				}}
}


