#pragma once
#include"player2.h"
#include"enemi.h"
#include"boundingbox.h"
#include"quiz.h"
#include"objet.h"
/**
* @struct playm
* @brief struct for playm
*/
typedef struct Playm2 {
	SDL_Surface *bg,*bg2;/*<!background*/
	int sx,sx2;
	int enabled;
	int restart;
	
	enemi enemi,enemi2,enemi3;/*<!les enemie*/
	Player2 player2;/*<!les joueurs*/
Objet o,o1,o2,o3,o4,o5;/*<!les objet*/
} Playm2;

void PLAYM2_Init(Playm2 *playm2);
void PLAYM2_Render(Playm2 *playm2,Quiz *quiz, SDL_Surface **screen);
void PLAYM2_HandleEvent(Playm2 *playm2,SDL_Event *event);
