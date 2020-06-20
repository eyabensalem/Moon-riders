/**
* @file play.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 4, 2020
*
* integrated program for play
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"enemi.h"
#include"collisionc.h"
#include"vie.h"
#include"play.h"
#include"objet.h"
#include"save.h"
#include <SDL/SDL_mixer.h>


Objet tayara;
/**
* @brief To initialize pictures.
* @param play struct
* @return Nothing
*/
void PLAY_Init(Play *play){
	//int HE_collision = 0; //initialement pas de collision hero/ennemi
	//int  ie = 0;	
	play->enabled = 0;
	play->restart = 0;
	play->bg = IMG_Load("city.png");
	play->sx = 0;
	//ie = init_ennemi(&E);
	enemi_Init(&play->enemi,1800,720-128);
	enemi_Init(&play->enemi2,3000,720-128);
	enemi_Init(&play->enemi3,4600,720-128);
	PLAYER_Init(&play->player);
	OBJET_Init(&play->o,1100,720-129,"chouk.png");
	OBJET_Init(&play->o1,2100,720-129,"chouk.png");
	OBJET_Init(&play->o2,4800,720-155,"eat.png");
	OBJET_Init(&play->o3,3600,720-154,"heart.png");
	OBJET_Init(&play->o4,5500,720-96,"obstacle1.png");
	OBJET_Init(&play->o5,5780,720-89,"obstacle2.png");
	

	OBJET_Init(&tayara,5800,30,"tayara.png");
	
}
/**
* @brief verification
* @param play struct 
* @param play2 struct
* @return Nothing
*/
void PLAY_WrongAnswer(Play *play, Play2 *play2) {
	PLAY_Init(play);
	play2->enabled = 0;
}
/**
* @brief charger son,blitter bg,les collisions et gestion du vie selon poshero
* @param play struct 
* @param play2 struct
* @param play3 struct
* @param quiz struct
* @param screen where to display
* @return Nothing
*/
void PLAY_Render(Play *play, Play2 *play2,Play3 *play3,Quiz *quiz, SDL_Surface **screen){
		Mix_Chunk *son ,*son2,*son3,*son4;
		son = Mix_LoadWAV("scream.wav");
		son2 = Mix_LoadWAV("exp.wav");
		son3 = Mix_LoadWAV("yahoo.wav");
		son4 = Mix_LoadWAV("burp.wav");
	SDL_Rect r = {play->sx,0,1366,768};
	SDL_BlitSurface(play->bg,&r,*screen,NULL);
	play->sx = play->player.position.x-(1366/3);
	if(play->sx < 0)
		play->sx = 0;
	if(play->sx >= 7560 - 1366){
		play->sx = 7560 - 1366;
	}
	if(play->player.position.x>=7500)
	{
		play->player.position.x=7500;
		}
	 if(play->player.position.x<=0)
		{
			play->player.position.x=0;
			}
	
/////////////// intel_artificiel///////////////
	
	
		if (play->player.position.x>=1100){
       	enemi_Render(&play->enemi,r,screen);	
			}
		if (play->player.position.x>=2100){
       	enemi_Render(&play->enemi2,r,screen);
			}
		if (play->player.position.x>=3500){
       	enemi_Render(&play->enemi3,r,screen);
			}
		PLAYER_Render(&play->player,r,screen);
	OBJET_Render(&play->o,r,screen);
	OBJET_Render(&play->o1,r,screen);
	OBJET_Render(&play->o2,r,screen);
	OBJET_Render(&play->o3,r,screen);
	OBJET_Render(&play->o4,r,screen);
	OBJET_Render(&play->o5,r,screen);
	OBJET_Render(&tayara,r,screen);
			//HE_collision = 	((Player->position.x ) >= E.positionAbsolue.x) &&(Player->position.x <= (E.positionAbsolue.x + Ennemi_WIDTH));		
//update_ennemi(&E, Player->position);

	SDL_Rect rc = {play->enemi.x, play->enemi.y,100,128};
	SDL_Rect rp = {play->player.position.x, play->player.position.y,110,210};
	if(collisionc(rp,80,rc,80)){
         	
		VIE_ReduireHp(&play->player.vie,1);
		if(play->enemi.x >= play->player.position.x){
		play->player.position.x -=5;
			}
		else {
			play->player.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);
	}
	SDL_Rect rc2 = {play->enemi2.x, play->enemi2.y,100,128};
	if(collision(rp,rc2)){
		VIE_ReduireHp(&play->player.vie,1);
		if(play->enemi2.x >= play->player.position.x){
		play->player.position.x -=5;
			}
		else {
			play->player.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);

	}

	SDL_Rect rc3 = {play->enemi3.x, play->enemi3.y,100,128};
	if(collision(rp,rc3)){
		VIE_ReduireHp(&play->player.vie,1);
		if(play->enemi3.x >= play->player.position.x){
		play->player.position.x -=5;
			}
		else {
			play->player.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);
	}

	SDL_Rect ro = {play->o.x,play->o.y,play->o.sprite->w,play->o.sprite->h};
	if(collisionc(rp,80,ro,80)){
			
			play->player.position.y = ro.y-rp.h-2;
			if(play->o.sprite->h == 129){
				Mix_PlayChannel(1, son2, 0);
				VIE_ReduireHp(&play->player.vie,100);
				play->o.sprite = IMG_Load("box.png");
				play->o.y += 42;

			}
	}

	SDL_Rect ro1 = {play->o1.x,play->o1.y,play->o1.sprite->w,play->o1.sprite->h};
	if(collision(rp,ro1)){
			play->player.position.y = ro1.y-rp.h-2;
			if(play->o1.sprite->h == 129){
				Mix_PlayChannel(1, son2, 0);
				VIE_ReduireHp(&play->player.vie,100);
				play->o1.sprite = IMG_Load("box.png");
				play->o1.y =633;

			}
	}

	SDL_Rect ro2 = {play->o2.x,play->o2.y,play->o2.sprite->w,play->o2.sprite->h};
	if(collision(rp,ro2)){
			if(play->o2.sprite->h == 155){
				Mix_PlayChannel(1, son4, 0);
				play->o2.sprite=IMG_Load("box.png");
				play->o2.y =635;
				VIE_AjouterHp(&play->player.vie, 30);
			}
			play->player.position.y = ro2.y-rp.h-2;
				
	}

	SDL_Rect ro3 = {play->o3.x,play->o3.y,play->o3.sprite->w,play->o3.sprite->h};
	if(collision(rp,ro3)){
			if(play->o3.sprite->h == 154){
				Mix_PlayChannel(1, son3, 0);
				play->o3.sprite = IMG_Load("box.png");
				play->o3.y =634;
				VIE_AjouterHp(&play->player.vie, 1000);
			}
			play->player.position.y = ro3.y-rp.h-2;
			
	}
SDL_Rect ro4 = {play->o4.x,play->o4.y,play->o4.sprite->w,play->o4.sprite->h};
	if(collision(rp,ro4)){
		
		play->player.position.y = ro4.y-rp.h-2	;
	}
SDL_Rect ro5 = {play->o5.x,play->o5.y,play->o5.sprite->w,play->o5.sprite->h};
	if(collision(rp,ro5)){
		
		play->player.position.y = ro5.y-rp.h-2;
	}


	SDL_Rect r_tayara = {tayara.x+500,tayara.y,10,tayara.sprite->h};
	if(collision(rp,r_tayara)){
		play->player.position.x += 100;
		play->player.vx = 0;
		play2->enabled = 1;
		QUIZ_NextQuestion(quiz);
		quiz->enabled = 1;
	}

	SDL_Rect rend = {play->bg->w - 100, 0,100,768};
	if(collision(rp,rend)){
		
		play->enabled = 0;
		play2->enabled=0;
		play3->enabled = 1;
		QUIZ_Init(quiz,"questions3.txt");
		QUIZ_NextQuestion(quiz);
		quiz->enabled = 1;
	}


	if(play->restart) {
		PLAY_Init(play);
		play->enabled = 1;
		play2->enabled = 0;
	}
}

/**
* @brief gestion clavier,souris et changement positions player et affiche quiz
* @param play struct
* @param exit2 struct
* @param quiz struct 
* @param event
* @return Nothing
*/
void PLAY_HandleEvent(Play *play, Exit2 *exit2,Quiz *quiz, SDL_Event* event){
Mix_Chunk *son;
son = Mix_LoadWAV("yahoo.wav");
int mouseX =play->player.vx;
	int mouseY = play->player.vy;
	if(event->type==SDL_MOUSEBUTTONDOWN)
		{
			play->player.vx=15;}
	if(event->type == SDL_KEYDOWN){
		if(event->key.keysym.sym==SDLK_q) {
			QUIZ_NextQuestion(quiz);
			quiz->enabled = 1;
		}
		if(event->key.keysym.sym==SDLK_RIGHT){
			play->player.vx = 15;	
			}
		else if(event->type == SDL_MOUSEBUTTONDOWN){
			SDL_GetMouseState(&mouseX,&mouseY);
		play->player.vx = 15;}}
		if(event->key.keysym.sym==SDLK_SPACE){
				play->player.vx += 30 ;
			}	
		if(event->key.keysym.sym==SDLK_LEFT){
			if(play->player.position.x < 7500)
				play->player.vx = -15;
		}
		
		if(event->key.keysym.sym==SDLK_UP){
			
			if(play->player.position.y==510){
			Mix_PlayChannel(1, son, 0);
			play->player.vy = -20;
				}
		
			}
		
		if(event->key.keysym.sym == SDLK_ESCAPE){
			play->enabled = 0;
			exit2->enabled = 1;
			fichier("save.txt",&play->player.position.x,&play->player.position.y,&play->o.x );	
		}
		if(event->type == SDL_MOUSEBUTTONDOWN){
			SDL_GetMouseState(&mouseX,&mouseY);
		play->player.vx = 0;
	}
/*if(event->type==SDL_MOUSEBUTTONDOWN)
			play->player.vx = 0;
	if(event->type == SDL_KEYUP){
		if(event->key.keysym.sym==SDLK_RIGHT)
			play->player.vx = 0;
		
		if(event->key.keysym.sym==SDLK_LEFT)
			play->player.vx = 0;
		if(event->key.keysym.sym==SDLK_SPACE)
			play->player.vx = 0;*/
	
		/*if(event->type == SDL_MOUSEBUTTONDOWN){
			SDL_GetMouseState(&mouseX,&mouseY);
		play->player.vx = 15;*/
	//play->player.vy = (int) lerp(playerRect.y,mouseY,0.2);

}	

