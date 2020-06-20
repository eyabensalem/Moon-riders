#pragma once
/**
* @struct ennemie
* @brief struct for ennemie
*/
typedef struct enemi {
	SDL_Surface *sprite,*sprite2;
	int x,y;
	int dx,cx;
	SDL_Rect clips[7];
	SDL_Rect clips2[7];
	float frame;
	int time;
} enemi;

void enemi_Init(enemi *c, int x, int y);
void enemi_Render(enemi *c, SDL_Rect r, SDL_Surface **screen);

