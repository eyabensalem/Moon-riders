/**
* @file playm2.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 05 2020
*
* integrated program for playm2
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"enemi.h"
#include"vie.h"
#include"playm2.h"
#include"play3.h"
#include"objet.h"
#include <SDL/SDL_mixer.h>

/**
* @brief initializate playm struct
* @param playm
* @return Nothing
*/

void PLAYM2_Init(Playm2 *playm2){
	playm2->enabled = 0;
	playm2->restart = 0;
	playm2->bg = IMG_Load("map2.png");
	playm2->sx = 0;
	
	PLAYER2_Init(&playm2->player2);

	enemi_Init(&playm2->enemi,1800,720-128);
	enemi_Init(&playm2->enemi2,3000,720-128);
	enemi_Init(&playm2->enemi3,4600,720-128);
	
	OBJET_Init(&playm2->o,1100,720-129,"chouk.png");
	OBJET_Init(&playm2->o1,2500,720-129,"chouk.png");
	OBJET_Init(&playm2->o2,6500,720-129,"chouk.png");
	OBJET_Init(&playm2->o3,3500,720-154,"heart.png");
	
}
/**
* @brief gestion de song a chaque fois  
* @param player
* @return Nothing
*/
void PLAYM2_Render(Playm2 *playm2,Quiz *quiz, SDL_Surface **screen){
		Mix_Chunk *son,*son2,*son3;
		son = Mix_LoadWAV("scream.wav");
		son3 = Mix_LoadWAV("yahoo.wav");
		son2 = Mix_LoadWAV("exp.wav");
	SDL_Rect r = {playm2->sx,0,1366,768};
	
	SDL_BlitSurface(playm2->bg,&r,*screen,NULL);
	

	playm2->sx = playm2->player2.position.x-(1366/2);
	if(playm2->sx < 0)
		playm2->sx = 0;
	if(playm2->sx >= 7560 - 1366){
		playm2->sx = 7560 - 1366;
		playm2->sx2 = 7560 - 1366;
	}
	
	if(playm2->player2.position.x>=7400)
	{
		playm2->player2.position.x=7400;
		}
	 if(playm2->player2.position.x<=0)
		{
			playm2->player2.position.x=0;
			}
	

	

	enemi_Render(&playm2->enemi,r,screen);
	enemi_Render(&playm2->enemi2,r,screen);
	enemi_Render(&playm2->enemi3,r,screen);
	

	PLAYER2_Render(&playm2->player2,r,screen);



	OBJET_Render(&playm2->o,r,screen);
	OBJET_Render(&playm2->o1,r,screen);
	OBJET_Render(&playm2->o2,r,screen);
	OBJET_Render(&playm2->o3,r,screen);
	
	SDL_Rect r1 = {playm2->sx,-568,1366,768};
	SDL_BlitSurface(playm2->bg2,&r1,*screen,NULL);


	SDL_Rect rc = {playm2->enemi.x, playm2->enemi.y,112,128};
	SDL_Rect rp = {playm2->player2.position.x, playm2->player2.position.y,110,210};
	if(collision(rp,rc)){
         	
		VIE_ReduireHp(&playm2->player2.vie,1);
		if(playm2->enemi.x >= playm2->player2.position.x){
		playm2->player2.position.x -=5;
			}
		else {
			playm2->player2.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);
	}
	SDL_Rect rc2 = {playm2->enemi2.x, playm2->enemi2.y,112,128};
	if(collision(rp,rc2)){
		VIE_ReduireHp(&playm2->player2.vie,1);
		if(playm2->enemi2.x >= playm2->player2.position.x){
		playm2->player2.position.x -=5;
			}
		else {
			playm2->player2.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);

	}

	SDL_Rect rc3 = {playm2->enemi3.x, playm2->enemi3.y,112,128};
	if(collision(rp,rc3)){
		VIE_ReduireHp(&playm2->player2.vie,1);
		if(playm2->enemi3.x >= playm2->player2.position.x){
		playm2->player2.position.x -=5;
			}
		else {
			playm2->player2.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);
	}

	SDL_Rect ro = {playm2->o.x,playm2->o.y,129,playm2->o.sprite->h};
	if(collision(rp,ro)){
	
			playm2->player2.position.y = ro.y-rp.h-2;
			if(playm2->o.sprite->h == 129){
				Mix_PlayChannel(1, son2, 0);
				VIE_ReduireHp(&playm2->player2.vie,30);
				playm2->o.sprite = IMG_Load("box.png");
				playm2->o.y =633;
			}
	}

	SDL_Rect ro1 = {playm2->o1.x,playm2->o1.y,129,playm2->o1.sprite->h};
	if(collision(rp,ro1)){
			Mix_PlayChannel(1, son2, 0);
			playm2->player2.position.y = ro1.y-rp.h-2;
			if(playm2->o1.sprite->h == 129){
				VIE_ReduireHp(&playm2->player2.vie,30);
				playm2->o1.sprite = IMG_Load("box.png");
				playm2->o1.y =633;
			}
	}
	
	SDL_Rect ro2 = {playm2->o2.x,playm2->o2.y,playm2->o2.sprite->w,playm2->o2.sprite->h};
	if(collision(rp,ro2)){		
			Mix_PlayChannel(1, son2, 0);
			playm2->player2.position.y = ro2.y-rp.h-2;	
			if(playm2->o2.sprite->h == 129){
				VIE_ReduireHp(&playm2->player2.vie,30);
				playm2->o2.sprite=IMG_Load("box.png");
				playm2->o2.y =633;
			}
			
	}

	SDL_Rect ro3 = {playm2->o3.x,playm2->o3.y,playm2->o3.sprite->w,playm2->o3.sprite->h};
	if(collision(rp,ro3)){
			if(playm2->o3.sprite->h == 154){
				playm2->o3.sprite = IMG_Load("box.png");
				playm2->o3.y =634;
				VIE_AjouterHp(&playm2->player2.vie, 1000);
				Mix_PlayChannel(1, son3, 0);
			}
			playm2->player2.position.y = ro3.y-rp.h-2;
	}
	
	SDL_Rect rend = {playm2->bg->w - 200, 0,100,768};
	
	if(collision(rp,rend)){
		playm2->enabled = 0;
		
		QUIZ_Init(quiz,"questions2.txt");
		QUIZ_NextQuestion(quiz);
		quiz->enabled = 0;
	}


	if(playm2->restart) {
		playm2->enabled = 0;
		PLAYM2_Init(playm2);
	}
}
/**
* @brief gestion de clavier et souris 
* @param player
* @return Nothing
*/
void PLAYM2_HandleEvent(Playm2 *playm2, SDL_Event* event){
Mix_Chunk *son;
son = Mix_LoadWAV("yahoo.wav");
	if(event->type == SDL_KEYDOWN){
		if(event->key.keysym.sym==SDLK_RIGHT)
			playm2->player2.vx = 15;
		if(event->key.keysym.sym==SDLK_LEFT)
			playm2->player2.vx = -15;
		if(event->key.keysym.sym==SDLK_UP){
			if(playm2->player2.position.y==510){
			playm2->player2.vy = -20;
			Mix_PlayChannel(1, son, 0);}
}
		if(event->key.keysym.sym==SDLK_DOWN)
			VIE_ReduireHp(&playm2->player2.vie,10);
		if(event->key.keysym.sym == SDLK_ESCAPE){
			playm2->enabled = 0;
		}
	}
	if(event->type == SDL_KEYUP){
		if(event->key.keysym.sym==SDLK_RIGHT)
			playm2->player2.vx = 0;
		if(event->key.keysym.sym==SDLK_LEFT)
			playm2->player2.vx = 0;

	}
}
