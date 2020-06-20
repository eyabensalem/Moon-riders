#pragma once
/**
* @struct navg
* @brief struct for navg
*/
typedef struct Navg {
	SDL_Surface **screen, *bg, *msg;/*<!les images*/
	SDL_Color rouge,noire,gold;/*<!les couleur du polices*/
	TTF_Font *font;/*<!font*/
	Mix_Music *bgm;/*<!music*/
	int choixMenu;/*choix dans le menu*/
	int enabled;
} Navg;

void NAVG_Init(Navg *navg, SDL_Surface **screen);
void NAVG_Render(Navg *navg);
void NAVG_RenderFont(Navg *navg, int x, int y, const char* text, int b);
void NAVG_HandleEvent(Navg *navg, SDL_Event *event);
