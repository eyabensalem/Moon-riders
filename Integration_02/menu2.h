#pragma once
#include"menu3.h"
#include"playm.h"
/**
* @struct menu2
* @brief struct for menu2
*/
typedef struct Menu2 {
	SDL_Surface **screen, *bg, *msg;/*<!a afficher */
	SDL_Color rouge,noire,gold;/*<!les couleur du police*/
	TTF_Font *font;/*<!font*/
	Mix_Music *bgm;/*<!music*/
	int choixMenu;/*choix dans menu*/
	int enabled;
} Menu2;

void MENU2_Init(Menu2 *menu2, SDL_Surface **screen);
void MENU2_Render(Menu2 *menu2);
void MENU2_RenderFont(Menu2 *menu2, int x, int y, const char* text, int b);
void MENU2_HandleEvent(Menu2 *menu2, Menu3 *menu3,Playm *playm, SDL_Event *event);
