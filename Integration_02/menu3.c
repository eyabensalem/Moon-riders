/**
* @file menu3.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 04 2020
*
* integrated program for menu3
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>
#include"play.h"
#include"save.h"
#include"menu3.h"
/**
* @brief initializate menu3 struct
* @param menu
* @param screen 
* @return Nothing
*/
void MENU3_Init(Menu3 *menu3, SDL_Surface **screen){
	menu3->screen = screen;
	menu3->bg = IMG_Load("menu2.png");
	menu3->font = TTF_OpenFont("theme.ttf",86);

	menu3->rouge.r = 217;
	menu3->rouge.g = 10;
	menu3->rouge.b = 4;

	menu3->gold.r = 251;
	menu3->gold.g = 208;
	menu3->gold.b = 119;	

	menu3->noire.r = menu3->noire.g = menu3->noire.b = 0;
	menu3->choixMenu = -1;
	menu3->enabled = 0;
}
/**
* @brief initializate menu3 struct
* @param menu3
* @param screen 
* @return Nothing
*/
void MENU3_Render(Menu3 *menu3){
	SDL_BlitSurface(menu3->bg, NULL, *menu3->screen, NULL);

	MENU3_RenderFont(menu3,430,250,"NEW GAME",menu3->choixMenu == 0);
MENU3_RenderFont(menu3,430,370,"LOAD GAME", menu3->choixMenu == 1);
	
}
/**
* @brief pour blitter le texte
* @param menu3
* @param x position 
* @param y position
* @param text a afficher
* @param b condition
* @return Nothing
*/
void MENU3_RenderFont(Menu3 *menu3, int x, int y, const char* text, int b){
	SDL_Rect r;
	r.x = x;
	r.y = y;
	menu3->msg = TTF_RenderText_Solid(menu3->font,text,menu3->noire);
	SDL_BlitSurface(menu3->msg,NULL,*menu3->screen,&r);
	r.x -= 7;
	r.y += 7;
	if(!b)
		menu3->msg = TTF_RenderText_Solid(menu3->font,text,menu3->rouge);
	else 
		menu3->msg = TTF_RenderText_Solid(menu3->font,text,menu3->gold);
	SDL_BlitSurface(menu3->msg,NULL,*menu3->screen,&r);
}
/**
* @brief gestion son et touches avec souris et clavier
* @param menu3 
* @param game screen
* @param event evenement
* @return Nothing
*/
void MENU3_HandleEvent(Menu3 *menu3,Play *play,SDL_Event *event){
SDL_Rect position;
Mix_Chunk *son;
son = Mix_LoadWAV("bt3.wav");
			if(event->type == SDL_KEYDOWN){
				if(event->key.keysym.sym == SDLK_DOWN){
					if(menu3->choixMenu != 1){
						menu3->choixMenu++;
						
						Mix_PlayChannel(1, son, 0);}
					else {
						menu3->choixMenu = 0;
						Mix_PlayChannel(1, son, 0);}
				}
				if(event->key.keysym.sym == SDLK_UP){
					if(menu3->choixMenu != 0){
						
						Mix_PlayChannel(1, son, 0);
						menu3->choixMenu--;}
					else {
						menu3->choixMenu = 1;
						Mix_PlayChannel(1, son, 0); }
				}

				if(event->key.keysym.sym == SDLK_RETURN){
					if(menu3->choixMenu == 1){
						//extraire("save.txt",*x,*y );
extraire("save.txt",&play->player.position.x,&play->player.position.y,&play->o.x ) ;
						menu3->enabled = 0;
						play->enabled = 1;
					}
					if(menu3->choixMenu == 0){
						menu3->enabled = 0;
						PLAY_Init(play);
						play->enabled = 1;
					}
				}
				if(event->key.keysym.sym == SDLK_ESCAPE){
					menu3->enabled = 0;
				}
			}
			if(event->type  == SDL_MOUSEMOTION){
					position.x=430;
					position.y=250;
				if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+300)&&(event->motion.y<=position.y+80))	{
						menu3->choixMenu=0;
					Mix_PlayChannel(1, son, 0);}
			
					position.x=430;
					position.y=370;
				 		if((event->motion.x>=position.x) && (event->motion.y >=position.y)&&(event->motion.x<=position.x+300)&&(event->motion.y<=position.y+80))	{
						menu3->choixMenu=1;
					Mix_PlayChannel(1, son, 0);}

					
				
				

			

			}
if(event->type ==SDL_MOUSEBUTTONDOWN)
				{
				if(event->button.button==SDL_BUTTON_LEFT){
					
					if(menu3->choixMenu == 1)
						menu3->enabled = 0;
						play->enabled = 1;
					if(menu3->choixMenu == 0)
						menu3->enabled = 0;
						PLAY_Init(play);
						play->enabled = 1;
				}}

}
