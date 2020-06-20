/**
* @file exit2.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 2, 2020
*
* integrated program for exit2
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>
#include"game.h"
#include"exit2.h"
#include"save.h"
/**
* @brief initializate exit2 struct
* @param exit2
* @param screen 
* @return Nothing
*/

void EXIT2_Init(Exit2 *exit2, SDL_Surface **screen){
	exit2->screen = screen;
	exit2->bg = IMG_Load("exit2.png");
	exit2->bgpos.x=214;
	exit2->bgpos.y=96;
	exit2->font = TTF_OpenFont("theme.ttf",40);

	exit2->rouge.r = 217;
	exit2->rouge.g = 10;
	exit2->rouge.b = 4;

	exit2->gold.r = 251;
	exit2->gold.g = 208;
	exit2->gold.b = 119;	

	exit2->noire.r = exit2->noire.g = exit2->noire.b = 0;
	exit2->choixMenu = 0;
	exit2->enabled = 0;
}
/**
* @brief blit background and text
* @param exit2
* @return Nothing
*/
void EXIT2_Render(Exit2 *exit2){
	SDL_BlitSurface(exit2->bg, NULL, *exit2->screen, &exit2->bgpos);

	EXIT2_RenderFont(exit2,350,340,"SAVE",exit2->choixMenu == 1);
	EXIT2_RenderFont(exit2,850,340,"DON'T SAVE", exit2->choixMenu == 0);
	
}
/**
* @brief pour blitter le texte
* @param exit2
* @param x position 
* @param y position
* @param text a afficher
* @param b condition
* @return Nothing
*/
void EXIT2_RenderFont(Exit2 *exit2, int x, int y, const char* text, int b){
	SDL_Rect r;
	r.x = x;
	r.y = y;
	exit2->msg = TTF_RenderText_Solid(exit2->font,text,exit2->noire);
	SDL_BlitSurface(exit2->msg,NULL,*exit2->screen,&r);
	r.x -= 7;
	r.y += 7;
	if(!b)
		exit2->msg = TTF_RenderText_Solid(exit2->font,text,exit2->rouge);
	else 
		exit2->msg = TTF_RenderText_Solid(exit2->font,text,exit2->gold);
	SDL_BlitSurface(exit2->msg,NULL,*exit2->screen,&r);
}
/**
* @brief gestion son et touches avec souris et clavier
* @param exit 
* @param game screen
* @param event evenement
* @return Nothing
*/
void EXIT2_HandleEvent(Exit2 *exit2,Game *game,SDL_Event *event){
Mix_Chunk *son;
son = Mix_LoadWAV("bt3.wav");
			if(event->type == SDL_KEYDOWN){
				if(event->key.keysym.sym == SDLK_RIGHT){
					if(exit2->choixMenu != 1){
						exit2->choixMenu++;
						
						Mix_PlayChannel(1, son, 0);}
					else {
						exit2->choixMenu = 0;
						Mix_PlayChannel(1, son, 0);}
				}
				if(event->key.keysym.sym == SDLK_LEFT){
					if(exit2->choixMenu != 0){
						
						Mix_PlayChannel(1, son, 0);
						exit2->choixMenu--;}
					else {
						exit2->choixMenu = 1;
						Mix_PlayChannel(1, son, 0); }
				}

				if(event->key.keysym.sym == SDLK_RETURN){
					if(exit2->choixMenu == 1){
						
						exit2->enabled =0;

					}
					if(exit2->choixMenu == 0){
						exit2->enabled = 0;
						
					}
				}
				
			}

}
