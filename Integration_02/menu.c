/**
* @file menu.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 04 2020
*
* integrated program for menu
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>
#include"settings2.h"
#include"credits.h"
#include"play.h"
#include"game.h"
#include"menu.h"
#include"menu2.h"

/**
* @brief initializate menu struct
* @param menu
* @param screen 
* @return Nothing
*/
void MENU_Init(Menu *menu, SDL_Surface **screen){
	menu->screen = screen;
	menu->bg = IMG_Load("back.png");
	menu->font = TTF_OpenFont("theme.ttf",86);

	menu->rouge.r = 217;
	menu->rouge.g = 10;
	menu->rouge.b = 4;

	menu->gold.r = 251;
	menu->gold.g = 208;
	menu->gold.b = 119;	

	menu->noire.r = menu->noire.g = menu->noire.b = 0;

	menu->bgm = Mix_LoadMUS("bg.mp3");
	Mix_PlayMusic(menu->bgm,-1);

	menu->choixMenu = -1;
}
/**
* @brief appel au fonct ecrir play settings ...
* @param menu
* @param screen 
* @return Nothing
*/
void MENU_Render(Menu *menu){
	SDL_BlitSurface(menu->bg, NULL, *menu->screen, NULL);

	MENU_RenderFont(menu,1018,200+0,"PLAY",menu->choixMenu == 0);
	MENU_RenderFont(menu,1018-127,200+100,"SETTINGS", menu->choixMenu == 1);
	MENU_RenderFont(menu,1018-86,200+200,"CREDITS", menu->choixMenu == 2);
	MENU_RenderFont(menu,1018,200+300,"EXIT", menu->choixMenu == 3);
	
	
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
void MENU_RenderFont(Menu *menu, int x, int y, const char* text, int b){
	SDL_Rect r;
	r.x = x;
	r.y = y;
	menu->msg = TTF_RenderText_Solid(menu->font,text,menu->noire);
	SDL_BlitSurface(menu->msg,NULL,*menu->screen,&r);
	r.x -= 7;
	r.y += 7;
	if(!b)
		menu->msg = TTF_RenderText_Solid(menu->font,text,menu->rouge);
	else 
		menu->msg = TTF_RenderText_Solid(menu->font,text,menu->gold);
	SDL_BlitSurface(menu->msg,NULL,*menu->screen,&r);
}
/**
* @brief gestion son et touches avec souris et clavier
* @param menu 
* @param game screen
* @param event evenement
* @return Nothing
*/
void MENU_HandleEvent(Menu *menu,Menu2 *menu2, Game* game, Settings *settings,Play *play,Credits *credits,Exit *exit,SDL_Event *event){
Mix_Chunk *son;
SDL_Rect position;
son = Mix_LoadWAV("bt3.wav");
			if(event->type == SDL_KEYDOWN){
				
				if(event->key.keysym.sym == SDLK_DOWN){
					if(menu->choixMenu != 3){
						menu->choixMenu++;
						
						Mix_PlayChannel(1, son, 0);}
					else {
						menu->choixMenu = 0;
						Mix_PlayChannel(1, son, 0);}
				}
				if(event->key.keysym.sym == SDLK_UP){
					if(menu->choixMenu != 0){
						
						Mix_PlayChannel(1, son, 0);
						menu->choixMenu--;}
					else {
						menu->choixMenu = 3;
						Mix_PlayChannel(1, son, 0); }
				}

				if(event->key.keysym.sym == SDLK_RETURN){
					if(menu->choixMenu == 3)
						exit->enabled =1;
					if(menu->choixMenu == 2)
						credits->enabled = 1;
					if(menu->choixMenu == 1)
						settings->enabled = 1;
					if(menu->choixMenu == 0)
						menu2->enabled = 1;
				}
			}
			if(event->type  == SDL_MOUSEMOTION){
					position.x=1018;
					position.y=200;
				if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+150)&&(event->motion.y<=position.y+80))	{
						menu->choixMenu=0;
					Mix_PlayChannel(1, son, 0);}
			
					position.x=1018-127;
					position.y=300;
				 		if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+300)&&(event->motion.y<=position.y+80))	{
						menu->choixMenu=1;
					Mix_PlayChannel(1, son, 0);}

					position.x=1018-86;
					position.y=400;
						if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+250)&&(event->motion.y<=position.y+80))	{
						menu->choixMenu=2;
					Mix_PlayChannel(1, son, 0);}
					
					position.x=1018;
					position.y=500;
						if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+150)&&(event->motion.y<=position.y+80))	{
						menu->choixMenu=3;
					Mix_PlayChannel(1, son, 0);}
				
				

			

			}
if(event->type ==SDL_MOUSEBUTTONDOWN)
				{
				if(event->button.button==SDL_BUTTON_LEFT){
					if(menu->choixMenu == 3)
						exit->enabled =1;
					if(menu->choixMenu == 2)
						credits->enabled = 1;
					if(menu->choixMenu == 1)
						settings->enabled = 1;
					if(menu->choixMenu == 0)
						menu2->enabled = 1;
				}}
		


}
