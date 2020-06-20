#pragma once
#include"player.h"
#include"enemi.h"
#include"boundingbox.h"
#include"playm2.h"
#include"play3.h"
#include"quiz.h"
#include"objet.h"
#include"exit2.h"
/**
* @struct playm
* @brief struct for playm
*/
typedef struct Playm {
	SDL_Surface *bg;/*<!background*/
	int sx;
	int enabled;
	int restart;
	
	enemi enemi,enemi2,enemi3;/*<!les enemie*/
	Player player;/*<!les joueurs*/
	Objet o,o1,o2,o3,o4,o5,o6;/*<!les objet*/
} Playm;

void PLAYM_Init(Playm *playm);
void PLAYM_Render(Playm *playm, Playm2 *playm2, Play3 *play3 ,Quiz *quiz, SDL_Surface **screen);
void PLAYM_HandleEvent(Playm *playm,Exit2 *exit2,Quiz *quiz,SDL_Event *event);
void PLAYM_WrongAnswer(Playm *playm, Playm2 *playm2);
