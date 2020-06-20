#pragma once
/**
* @struct objet
* @brief struct for objet
*/
typedef struct Objet {
	SDL_Surface *sprite;/*<!image*/
	int x,y;/*<!position*/
} Objet;

void OBJET_Init(Objet *c, int x, int y,const char* path);
void OBJET_Render(Objet *c, SDL_Rect r, SDL_Surface **screen);
