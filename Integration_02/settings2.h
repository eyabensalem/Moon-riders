#pragma once
#include"navg.h"
/**
* @struct settings
* @brief struct for settings
*/
typedef struct Settings {
	SDL_Surface **screen, *bg, *msg; /*<!affichage background et message*/
	SDL_Color rouge,noire,gold; /*<!les couleur*/
	TTF_Font *font;/*<!font*/
	Mix_Music *bgm;/*<!son*/
	int choixMenu;/*!<choix dans le menu*/
	int enabled;
} Settings;

void SETTINGS_Init(Settings *settings, SDL_Surface **screen);
void SETTINGS_Render(Settings *settings);
void SETTINGS_RenderFont(Settings *settings, int x, int y, const char* text, int b);
void SETTINGS_HandleEvent(Settings *settings,Navg *navg, SDL_Event *event);
