/**
* @file game.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date juillet 04 2020
*
* integrated program for game
*
*/
#include<SDL/SDL.h>
#include"game.h"

void GAME_Init(Game *game){
	game->running = 1;
        game->screen = SDL_SetVideoMode(1366,768,32,SDL_HWSURFACE|SDL_FULLSCREEN |SDL_DOUBLEBUF);
}
