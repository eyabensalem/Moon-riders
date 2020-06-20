#pragma once
/**
* @struct menu3 
* @brief struct for menu3
*/
typedef struct Menu3 {
	SDL_Surface **screen, *bg, *msg;/*<!a afficher*/
	SDL_Color rouge,noire,gold;/*<!les couleur du police*/
	TTF_Font *font;/*<!font*/
	Mix_Music *bgm;/*<!music*/
	int choixMenu;/*<!coix dans le menu*/
	int enabled;
} Menu3;

void MENU3_Init(Menu3 *menu3, SDL_Surface **screen);
void MENU3_Render(Menu3 *menu3);
void MENU3_RenderFont(Menu3 *menu3, int x, int y, const char* text, int b);
void MENU3_HandleEvent(Menu3 *menu3, Play *play, SDL_Event *event);
