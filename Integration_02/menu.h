#pragma once

#include"menu2.h"
#include"exit.h"
/**
* @struct menu
* @brief struct for menu
*/
typedef struct Menu {
	SDL_Surface **screen, *bg, *msg;
	SDL_Color rouge,noire,gold;
	TTF_Font *font;
	Mix_Music *bgm;
	int choixMenu;
} Menu;

void MENU_Init(Menu *menu, SDL_Surface **screen);
void MENU_Render(Menu *menu);
void MENU_RenderFont(Menu *menu, int x, int y, const char* text, int b);
void MENU_HandleEvent(Menu *menu,Menu2 *menu2, Game *game,Settings *settings,Play *play,Credits *credits,Exit *exit, SDL_Event *event);
