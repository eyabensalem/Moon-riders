#pragma once
#include"player.h"
#include"enemi.h"
#include"boundingbox.h"
#include"play2.h"
#include"play3.h"
#include"quiz.h"
#include"objet.h"
#include"exit2.h"

/**
* @struct play
* @brief struct for play
*/
typedef struct Play {
	SDL_Surface *bg;/*<!background*/
	int sx;
	int enabled;
	int restart;
	
	enemi enemi,enemi2,enemi3;/*<!les enemies*/

	Player player;/*<!joueur */
	Objet o,o1,o2,o3,o4,o5;/*<!les objets*/
} Play;

void PLAY_Init(Play *play);
void PLAY_Render(Play *play, Play2 *play2, Play3 *play3 ,Quiz *quiz, SDL_Surface **screen);
void PLAY_HandleEvent(Play *play,Exit2 *exit2,Quiz *quiz,SDL_Event *event);
void PLAY_WrongAnswer(Play *play, Play2 *play2);
