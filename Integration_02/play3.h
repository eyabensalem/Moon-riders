#pragma once
#include"player.h"
#include"enemi.h"
#include"boundingbox.h"

#include"quiz.h"
#include"objet.h"
#include"game.h"
#include"exit.h"

/**
* @struct play3
* @brief struct for play3
*/
typedef struct Play3 {
	SDL_Surface *bg;/*<!background*/
	int sx;
	int enabled;
	int restart;
	
	enemi enemi,enemi2,enemi3;/*<!les enemies*/
	Player player;/*<!joueur */
Objet o,o1,o2,o3,o4,o5;/*<!les objets*/
} Play3;

void PLAY3_Init(Play3 *play3);
void PLAY3_Render(Play3 *play3,Quiz *quiz, SDL_Surface **screen);
void PLAY3_HandleEvent(Play3 *play3,Exit *exit,SDL_Event *event);
