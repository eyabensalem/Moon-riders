/**
* @file vie.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 05 2020
*
* integrated program for vie
*
*/
#include"vie.h"
/**
* @brief pour initialiser vie
* @param vie
* @return Nothing
*/
void VIE_Init(Vie *v){
	v->hp = 200;
	v->r.x = 25;
	v->r.y = 15;
	v->r.w = 225;
	v->r.h = 30;

	v->bar = SDL_CreateRGBSurface(0,225,30,32,0,0,0,0);
	SDL_FillRect(v->bar, NULL, 0x00ff00);
}
/**
* @brief pour diminuer vie
* @param vie
* @param degat
* @return Nothing
*/
void VIE_ReduireHp(Vie *v, int degat){
	v->hp =v->hp - degat;
	v->r.w = v->hp;
}
/**
* @brief pour augmenter vie
* @param menu
* @param degat
*/
void VIE_AjouterHp(Vie *v, int degat){
	v->hp += degat;
	if(v->hp > 200){
		v->hp = 200;
	}
	v->r.w = v->hp;
}
/**
* @brief pour blitter le niveau de vie
* @param vie
* @param screen
*@return nothing
*/
void VIE_Render(Vie *v, SDL_Surface **screen){
	SDL_BlitSurface(v->bar,&v->r,*screen,&v->r);
}
/**
* @brief pour aufmenter le score
* @param vie
* @param score
* @return Nothing
*/
void VIE_AjouterScore(Vie *v, int score){
v->score += score;
}
