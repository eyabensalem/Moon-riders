#pragma once
#include"player.h"
#include"enemi.h"
#include"boundingbox.h"
#include"quiz.h"
#include"objet.h"
/**
* @struct play2
* @brief struct for play2
*/
typedef struct Play2 {
	SDL_Surface *bg,*bg2;/*<!background*/
	int sx,sx2;
	int enabled;
	int restart;
	
	enemi enemi,enemi2,enemi3/*<!les enemis*/;
	Player player;/*<!joueur*/
Objet o,o1,o2,o3,o4,o5;/*<!les objet*/
} Play2;

void PLAY2_Init(Play2 *play2);
void PLAY2_Render(Play2 *play2,Quiz *quiz, SDL_Surface **screen);
void PLAY2_HandleEvent(Play2 *play2,SDL_Event *event);
