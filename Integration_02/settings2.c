/**
* @file settings2.c
* @brief integrated program
* @author hadir maaroufi
* @version 0.1
* @date July 5, 2020
*
* integrated program for settings2
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>
#include"play.h"
#include"settings2.h"
#include"navg.h"
/**
* @brief initializate settings struct
* @param settings struct
* @param screen 
* @return Nothing
*/
void SETTINGS_Init(Settings *settings, SDL_Surface **screen){
	settings->screen = screen;
	settings->bg = IMG_Load("menu2.png");
	settings->font = TTF_OpenFont("theme.ttf",86);

	settings->rouge.r = 217;
	settings->rouge.g = 10;
	settings->rouge.b = 4;

	settings->gold.r = 251;
	settings->gold.g = 208;
	settings->gold.b = 119;	

	settings->noire.r = settings->noire.g = settings->noire.b = 0;
	settings->choixMenu = 0;
	settings->enabled = 0;
}
/**
* @brief blit background and text
* @param settings
* @return Nothing
*/
void SETTINGS_Render(Settings *settings){
	SDL_BlitSurface(settings->bg, NULL, *settings->screen, NULL);


	SETTINGS_RenderFont(settings,550,250,"AUDIO",settings->choixMenu == 0);
	SETTINGS_RenderFont(settings,275,420,"NAVIGATION MODE", settings->choixMenu == 1);
	
}
/**
* @brief pour blitter le texte
* @param settings
* @param x position 
* @param y position
* @param text a afficher
* @param b condition
* @return Nothing
*/
void SETTINGS_RenderFont(Settings *settings, int x, int y, const char* text, int b){
	SDL_Rect r;
	r.x = x;
	r.y = y;
	settings->msg = TTF_RenderText_Solid(settings->font,text,settings->noire);
	SDL_BlitSurface(settings->msg,NULL,*settings->screen,&r);
	r.x -= 7;
	r.y += 7;
	if(!b)
		settings->msg = TTF_RenderText_Solid(settings->font,text,settings->rouge);
	else 
		settings->msg = TTF_RenderText_Solid(settings->font,text,settings->gold);
	SDL_BlitSurface(settings->msg,NULL,*settings->screen,&r);
}
/**
* @brief gestion son et touches avec souris et clavier
* @param settings 
* @param navg struct
* @param event evenement
* @return Nothing
*/
void SETTINGS_HandleEvent(Settings *settings,Navg *navg,SDL_Event *event){
SDL_Rect position;
Mix_Chunk *son;
son = Mix_LoadWAV("bt3.wav");
			if(event->type == SDL_KEYDOWN){
				if(event->key.keysym.sym == SDLK_DOWN){
					if(settings->choixMenu != 1){
						settings->choixMenu++;
						
						Mix_PlayChannel(1, son, 0);}
					else {
						settings->choixMenu = 0;
						Mix_PlayChannel(1, son, 0);}
				}
				if(event->key.keysym.sym == SDLK_UP){
					if(settings->choixMenu != 0){
						
						Mix_PlayChannel(1, son, 0);
						settings->choixMenu--;}
					else {
						settings->choixMenu = 1;
						Mix_PlayChannel(1, son, 0); }
				}

				if(event->key.keysym.sym == SDLK_RETURN){
					if(settings->choixMenu == 1){
						navg->enabled =1 ;
						
					}
					
				}
				if(event->key.keysym.sym == SDLK_ESCAPE){
					settings->enabled = 0;
				}
			}
		if(event->type  == SDL_MOUSEMOTION){
					position.x=550	;
					position.y=250;
				if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+250)&&(event->motion.y<=position.y+80))	{
						settings->choixMenu=0;
					Mix_PlayChannel(1, son, 0);}
			
					position.x=275;
					position.y=420;
				 		if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+800)&&(event->motion.y<=position.y+80))	{
						settings->choixMenu=1;
					Mix_PlayChannel(1, son, 0);}

					
				
				

			

			}
if(event->type ==SDL_MOUSEBUTTONDOWN)
				{
				if(event->button.button==SDL_BUTTON_LEFT){
					
					if(settings->choixMenu == 1){
						navg->enabled =1;
						}
					if(settings->choixMenu == 0){
						}
				}}
}

