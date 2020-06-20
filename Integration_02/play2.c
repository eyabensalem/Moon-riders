/**
* @file play2.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 4, 2020
*
* integrated program for play2.c
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"enemi.h"
#include"vie.h"
#include"play2.h"
#include"play3.h"
#include"objet.h"
#include"quizdyn.h"
#include <SDL/SDL_mixer.h>
/**
* @brief To initialize pictures.
* @param play2 struct
* @return Nothing
*/
void PLAY2_Init(Play2 *play2){
	play2->enabled = 0;
	play2->restart = 0;
	play2->bg = IMG_Load("map2.png");
	//play2->bg2 = IMG_Load("map2_louta.png");
	play2->sx = 0;
	
	PLAYER_Init(&play2->player);
	//play2->bg2 = IMG_Load("map2_louta.png");

	enemi_Init(&play2->enemi,1500,720-128);
	enemi_Init(&play2->enemi2,3000,720-128);
	enemi_Init(&play2->enemi3,4500,720-128);
	
	OBJET_Init(&play2->o,1000,720-129,"chouk.png");
	OBJET_Init(&play2->o1,2500,720-129,"chouk.png");
	OBJET_Init(&play2->o2,6500,720-129,"chouk.png");
	OBJET_Init(&play2->o3,3500,720-154,"heart.png");
	
}
/**
* @brief charger son,blitter bg,les collisions et gestion du vie selon poshero
* @param play2 struct
* @param quiz struct
* @param screen where to display
* @return Nothing
*/
void PLAY2_Render(Play2 *play2,Quiz *quiz, SDL_Surface **screen){
		Mix_Chunk *son,*son2,*son3;
		son = Mix_LoadWAV("scream.wav");
		son3 = Mix_LoadWAV("yahoo.wav");
		son2 = Mix_LoadWAV("exp.wav");
		
	SDL_Rect r = {play2->sx,0,1366,768};
	
	SDL_BlitSurface(play2->bg,&r,*screen,NULL);
	

	play2->sx = play2->player.position.x-(1366/2);
	if(play2->sx < 0)
		play2->sx = 0;
	if(play2->sx >= 7560 - 1366){
		play2->sx = 7560 - 1366;
	}
	if(play2->sx2 >= 7224 - 1366){
		play2->sx2 = 7224 - 1366;
	}
	if(play2->player.position.x>=7400)
	{
		play2->player.position.x=7400;
		}
	 if(play2->player.position.x<=0)
		{
			play2->player.position.x=0;
			}
	

	

	enemi_Render(&play2->enemi,r,screen);
	enemi_Render(&play2->enemi2,r,screen);
	enemi_Render(&play2->enemi3,r,screen);
	

	PLAYER_Render(&play2->player,r,screen);



	OBJET_Render(&play2->o,r,screen);
	OBJET_Render(&play2->o1,r,screen);
	OBJET_Render(&play2->o2,r,screen);
	OBJET_Render(&play2->o3,r,screen);
	
	SDL_Rect r1 = {play2->sx,-568,1366,768};
	SDL_BlitSurface(play2->bg2,&r1,*screen,NULL);


	SDL_Rect rc = {play2->enemi.x, play2->enemi.y,112,128};
	SDL_Rect rp = {play2->player.position.x, play2->player.position.y,110,210};
	if(collision(rp,rc)){
         	
		VIE_ReduireHp(&play2->player.vie,1);
		if(play2->enemi.x >= play2->player.position.x){
		play2->player.position.x -=5;
			}
		else {
			play2->player.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);
	}
	SDL_Rect rc2 = {play2->enemi2.x, play2->enemi2.y,112,128};
	if(collision(rp,rc2)){
		VIE_ReduireHp(&play2->player.vie,1);
		if(play2->enemi2.x >= play2->player.position.x){
		play2->player.position.x -=5;
			}
		else {
			play2->player.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);

	}

	SDL_Rect rc3 = {play2->enemi3.x, play2->enemi3.y,112,128};
	if(collision(rp,rc3)){
		VIE_ReduireHp(&play2->player.vie,1);
		if(play2->enemi3.x >= play2->player.position.x){
		play2->player.position.x -=5;
			}
		else {
			play2->player.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);
	}

	SDL_Rect ro = {play2->o.x,play2->o.y,129,play2->o.sprite->h};
	if(collision(rp,ro)){
	
			play2->player.position.y = ro.y-rp.h-2;
			if(play2->o.sprite->h == 129){
				Mix_PlayChannel(1, son2, 0);
				VIE_ReduireHp(&play2->player.vie,30);
				play2->o.sprite = IMG_Load("box.png");
				play2->o.y =633;
			}
	}

	SDL_Rect ro1 = {play2->o1.x,play2->o1.y,129,play2->o1.sprite->h};
	if(collision(rp,ro1)){
			Mix_PlayChannel(1, son2, 0);
			play2->player.position.y = ro1.y-rp.h-2;
			if(play2->o1.sprite->h == 129){
				VIE_ReduireHp(&play2->player.vie,30);
				play2->o1.sprite = IMG_Load("box.png");
				play2->o1.y =633;
			}
	}
	
	SDL_Rect ro2 = {play2->o2.x,play2->o2.y,play2->o2.sprite->w,play2->o2.sprite->h};
	if(collision(rp,ro2)){		
			Mix_PlayChannel(1, son2, 0);
			play2->player.position.y = ro2.y-rp.h-2;	
			if(play2->o2.sprite->h == 129){
				VIE_ReduireHp(&play2->player.vie,30);
				play2->o2.sprite=IMG_Load("box.png");
				play2->o2.y =633;
			}
			
	}

	SDL_Rect ro3 = {play2->o3.x,play2->o3.y,play2->o3.sprite->w,play2->o3.sprite->h};
	if(collision(rp,ro3)){
			if(play2->o3.sprite->h == 154){
				play2->o3.sprite = IMG_Load("box.png");
				play2->o3.y =634;
				VIE_AjouterHp(&play2->player.vie, 1000);
				Mix_PlayChannel(1, son3, 0);
			}
			play2->player.position.y = ro3.y-rp.h-2;
	}
	
	SDL_Rect rend = {play2->bg->w - 200, 0,100,768};
	
	if(collision(rp,rend)){
		play2->enabled = 0;
/*QUIZ_Init(quiz,"QuizFile");		
void afficherAlea (SDL_Surface * screen  , char image [],quiz *q,int *alea)
quizdyn->enabled;*/
		QUIZ_Init(quiz,"questions.txt");
		QUIZ_NextQuestion(quiz);
		quiz->enabled = 0;
	}


	if(play2->restart) {
		play2->enabled = 0;
		PLAY2_Init(play2);
	}
}
/**
* @brief gestion clavier et changement positions player et vie 
* @param play2 struct
* @param event
* @return Nothing
*/
void PLAY2_HandleEvent(Play2 *play2, SDL_Event* event){
Mix_Chunk *son;
son = Mix_LoadWAV("yahoo.wav");
	if(event->type == SDL_KEYDOWN){
		if(event->key.keysym.sym==SDLK_RIGHT)
			play2->player.vx = 15;
		if(event->key.keysym.sym==SDLK_LEFT)
			play2->player.vx = -15;
		if(event->key.keysym.sym==SDLK_SPACE)
			play2->player.vx += 30;
		if(event->key.keysym.sym==SDLK_UP){
			if(play2->player.position.y==510){
			play2->player.vy = -24;
			Mix_PlayChannel(1, son, 0);}
}
		if(event->key.keysym.sym==SDLK_DOWN)
			VIE_ReduireHp(&play2->player.vie,10);
		if(event->key.keysym.sym == SDLK_ESCAPE){
			play2->enabled = 0;
		}
	}
	if(event->type == SDL_KEYUP){
		if(event->key.keysym.sym==SDLK_RIGHT)
			play2->player.vx = 0;
		if(event->key.keysym.sym==SDLK_LEFT)
			play2->player.vx = 0;

	}
}
