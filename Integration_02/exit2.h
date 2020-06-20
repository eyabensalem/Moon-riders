#pragma once
#include"game.h"
/**
* @struct Exit2
* @brief struct for exit2
*/
typedef struct Exit2 {
	SDL_Surface **screen, *bg, *msg;/*<! position background*/
	SDL_Color rouge,noire,gold;/*<!a afficher */
	SDL_Rect bgpos;/*<!couleurs */
	TTF_Font *font;
	//Mix_Music *bgm;
	int choixMenu;/*<!choixmenu */
	int enabled;
} Exit2;

void EXIT2_Init(Exit2 *exit2, SDL_Surface **screen);
void EXIT2_Render(Exit2 *exit2);
void EXIT2_RenderFont(Exit2 *exit2, int x, int y, const char* text, int b);
void EXIT2_HandleEvent(Exit2 *exit2, Game *game, SDL_Event *event);
