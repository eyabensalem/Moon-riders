/**
* @file player.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 04 2020
*
* integrated program for player
*
*/
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player.h"
#include "time.h"
/**
* @brief initializate player struct
* @param player
* @return Nothing
*/
void PLAYER_Init(Player *p){
	p->image = IMG_Load("ahmed1.png");
	p->image2 = IMG_Load("ahmed2.png");
	p->position.x = 100;
	p->position.y = 100;
	p->vx=p->vy = 0;
	int clip_x=110;
	p->time.time=0;
	p->time.score=0;
	
	for (int i = 0; i < 9; i++ ){
		p->clips[i].x = i*(clip_x+3);
		p->clips[i].y = 0;
		p->clips[i].w = clip_x;
		p->clips[i].h =p->image->h;
	}
	for (int i = 0; i < 9; i++ ){
		p->clips2[i].x = p->image2->w-(clip_x+15) -i*clip_x;
		p->clips2[i].y = 0;
		p->clips2[i].w =clip_x;
		p->clips2[i].h = p->image2->h;
	}
	
	p->frame = 0;

	VIE_Init(&p->vie);
	initializerTemps(&p->time);
}

void PLAYER_Render(Player *p,SDL_Rect r, SDL_Surface **screen){
	SDL_Rect r2 = {p->position.x - r.x, p->position.y};
	if(p->vx >=0){
		SDL_BlitSurface(p->image,&p->clips[(int) p->frame],*screen,&r2);
	}else{
		SDL_BlitSurface(p->image2,&p->clips2[(int) p->frame],*screen,&r2);

	}

	if(p->vx != 0){
		p->frame += 0.3f;
		if(p->frame >9) p->frame = 1;
		p->position.x += p->vx;
	}else{
		p->frame = 0;
	}
	p->vy += 1;
	p->position.y += p->vy;
		
	if(p->position.y + 210 > 720){
		p->position.y = 720-210;
		p->vy = 0;
	}
	
	VIE_Render(&p->vie, screen);	
	afficherTemps(&p->time,screen);
}
