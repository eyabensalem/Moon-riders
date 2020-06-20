/**
* @file playm.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 05 2020
*
* integrated program for playm
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"enemi.h"
#include"vie.h"
#include"playm.h"
//#include"playm2.h"
#include"objet.h"
#include <SDL/SDL_mixer.h>

Objet tayara;
/**
* @brief initializate playm struct
* @param playm
* @return Nothing
*/
void PLAYM_Init(Playm *playm){
	playm->enabled = 0;
	playm->restart = 0;
	playm->bg = IMG_Load("city.png");
	playm->sx = 0;

	enemi_Init(&playm->enemi,1800,720-128);
	enemi_Init(&playm->enemi2,3000,720-128);
	enemi_Init(&playm->enemi3,4600,720-128);
	
	OBJET_Init(&playm->o,1100,720-129,"chouk.png");
	OBJET_Init(&playm->o1,2100,720-129,"chouk.png");
	OBJET_Init(&playm->o2,4800,720-155,"eat.png");
	OBJET_Init(&playm->o3,3600,720-154,"heart.png");
	OBJET_Init(&playm->o4,5500,720-96,"obstacle1.png");
	OBJET_Init(&playm->o5,5780,720-89,"obstacle2.png");	
	

	PLAYER_Init(&playm->player);	
	OBJET_Init(&tayara,5800,30,"tayara.png");
	OBJET_Init(&playm->o6,6300,720-350,"me.png");
}
/**
* @brief initializate wronganswer struct
* @param player
* @return Nothing
*/
void PLAYM_WrongAnswer(Playm *playm, Playm2 *playm2) {
	PLAYM_Init(playm);
	playm2->enabled = 0;
}
/**
* @brief gestion de song a chaque fois  
* @param player
* @return Nothing
*/
void PLAYM_Render(Playm *playm, Playm2 *playm2,Play3 *play3,Quiz *quiz, SDL_Surface **screen){
		Mix_Chunk *son ,*son2,*son3,*son4;
		son = Mix_LoadWAV("scream.wav");
		son2 = Mix_LoadWAV("exp.wav");
		son3 = Mix_LoadWAV("yahoo.wav");
		son4 = Mix_LoadWAV("burp.wav");
	SDL_Rect r = {playm->sx,0,1366,768};
	SDL_BlitSurface(playm->bg,&r,*screen,NULL);
	playm->sx = playm->player.position.x-(1366/3);
	if(playm->sx < 0)
		playm->sx = 0;
	if(playm->sx >= 7500 - 1366){
		playm->sx = 7500 - 1366;
	}
	if(playm->player.position.x>=7500)
	{
		playm->player.position.x=7500;
		}
	 if(playm->player.position.x<=0)
		{
			playm->player.position.x=0;
			}
	
/////////////// intel_artificiel///////////////
	
	
		if (playm->player.position.x>=1100){
       	enemi_Render(&playm->enemi,r,screen);	
			}
		if (playm->player.position.x>=2100){
       	enemi_Render(&playm->enemi2,r,screen);
			}
		if (playm->player.position.x>=3500){
       	enemi_Render(&playm->enemi3,r,screen);
			}
		
	OBJET_Render(&playm->o,r,screen);
	OBJET_Render(&playm->o1,r,screen);
	OBJET_Render(&playm->o2,r,screen);
	OBJET_Render(&playm->o3,r,screen);
	OBJET_Render(&playm->o4,r,screen);
	OBJET_Render(&playm->o5,r,screen);
	
	PLAYER_Render(&playm->player,r,screen);
	OBJET_Render(&tayara,r,screen);
	OBJET_Render(&playm->o6,r,screen);
		
	

	SDL_Rect rc = {playm->enemi.x, playm->enemi.y,100,128};
	SDL_Rect rp = {playm->player.position.x, playm->player.position.y,110,210};
	if(collision(rp,rc)){
         	
		VIE_ReduireHp(&playm->player.vie,1);
		if(playm->enemi.x >= playm->player.position.x){
		playm->player.position.x -=5;
			}
		else {
			playm->player.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);
	}
	SDL_Rect rc2 = {playm->enemi2.x, playm->enemi2.y,100,128};
	if(collision(rp,rc2)){
		VIE_ReduireHp(&playm->player.vie,1);
		if(playm->enemi2.x >= playm->player.position.x){
		playm->player.position.x -=5;
			}
		else {
			playm->player.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);

	}

	SDL_Rect rc3 = {playm->enemi3.x, playm->enemi3.y,100,128};
	if(collision(rp,rc3)){
		VIE_ReduireHp(&playm->player.vie,1);
		if(playm->enemi3.x >= playm->player.position.x){
		playm->player.position.x -=5;
			}
		else {
			playm->player.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);
	}

	SDL_Rect ro = {playm->o.x,playm->o.y,playm->o.sprite->w,playm->o.sprite->h};
	if(collision(rp,ro)){
			
			playm->player.position.y = ro.y-rp.h-2;
			if(playm->o.sprite->h == 129){
				Mix_PlayChannel(1, son2, 0);
				VIE_ReduireHp(&playm->player.vie,100);
				playm->o.sprite = IMG_Load("box.png");
				playm->o.y = 633;

			}
	}
	SDL_Rect ro1 = {playm->o1.x,playm->o1.y,playm->o1.sprite->w,playm->o1.sprite->h};
	if(collision(rp,ro1)){
			
			playm->player.position.y = ro1.y-rp.h-2;
			if(playm->o1.sprite->h == 129){
				Mix_PlayChannel(1, son2, 0);
				VIE_ReduireHp(&playm->player.vie,50);
				playm->o1.sprite = IMG_Load("box.png");
				playm->o1.y = 633;

			}
	}


	SDL_Rect ro2 = {playm->o2.x,playm->o2.y,playm->o2.sprite->w,playm->o2.sprite->h};
	if(collision(rp,ro2)){
			if(playm->o2.sprite->h == 155){
				Mix_PlayChannel(1, son4, 0);
				playm->o2.sprite=IMG_Load("box.png");
				playm->o2.y =635;
				VIE_ReduireHp(&playm->player.vie,50);
				
			}
			playm->player.position.y = ro2.y-rp.h-2;
				
	}

	SDL_Rect ro3 = {playm->o3.x,playm->o3.y,playm->o3.sprite->w,playm->o3.sprite->h};
	if(collision(rp,ro3)){
			if(playm->o3.sprite->h == 154){
				Mix_PlayChannel(1, son3, 0);
				playm->o3.sprite = IMG_Load("box.png");
				playm->o3.y =634;
				VIE_AjouterHp(&playm->player.vie, 1000);
			}
			playm->player.position.y = ro3.y-rp.h-2;
			
	}
SDL_Rect ro4 = {playm->o4.x,playm->o4.y,playm->o4.sprite->w,playm->o4.sprite->h};
	if(collision(rp,ro4)){
		
		playm->player.position.y = ro4.y-rp.h-2	;
	}
SDL_Rect ro5 = {playm->o5.x,playm->o5.y,playm->o5.sprite->w,playm->o5.sprite->h};
	if(collision(rp,ro5)){
		
		playm->player.position.y = ro5.y-rp.h-2;
	}


	SDL_Rect r_tayara = {tayara.x+500,tayara.y,10,tayara.sprite->h};
	if(collision(rp,r_tayara)){
		playm->player.position.x += 200;
		playm->player.vx = 0;
		playm->enabled = 0;
		playm2->enabled = 1;
		QUIZ_NextQuestion(quiz);
		quiz->enabled = 1;
	}

	SDL_Rect rend = {playm->bg->w - 100, 0,100,768};
	if(collision(rp,rend)){
		
		playm->enabled = 0;
		playm2->enabled=0;
		play3->enabled = 1;
		QUIZ_Init(quiz,"questions3.txt");
		QUIZ_NextQuestion(quiz);
		quiz->enabled = 1;
	}


	if(playm->restart) {
		PLAYM_Init(playm);
		playm->enabled = 1;
		playm2->enabled = 0;
	}
}


void PLAYM_HandleEvent(Playm *playm, Exit2 *exit2,Quiz *quiz, SDL_Event* event){
Mix_Chunk *son;
son = Mix_LoadWAV("yahoo.wav");
	if(event->type == SDL_KEYDOWN){
		if(event->key.keysym.sym==SDLK_q) {
			QUIZ_NextQuestion(quiz);
			quiz->enabled = 1;
		}
		if(event->key.keysym.sym==SDLK_RIGHT){
			playm->player.vx = 15;
				
			}
		if(event->key.keysym.sym==SDLK_SPACE){
				playm->player.vx += 30 ;
			}	
		if(event->key.keysym.sym==SDLK_LEFT){
			if(playm->player.position.x < 7500)
				playm->player.vx = -15;
		}
		if(event->key.keysym.sym==SDLK_UP){
			
			if(playm->player.position.y==510){
			Mix_PlayChannel(1, son, 0);
			playm->player.vy = -20;
				}
		
			}
		
		if(event->key.keysym.sym == SDLK_ESCAPE){
			playm->enabled = 0;
			exit2->enabled = 1;	
		}
	}
	if(event->type == SDL_KEYUP){
		if(event->key.keysym.sym==SDLK_RIGHT)
			playm->player.vx = 0;
		if(event->key.keysym.sym==SDLK_LEFT)
			playm->player.vx = 0;
		if(event->key.keysym.sym==SDLK_SPACE)
			playm->player.vx = 0;

	}
}
