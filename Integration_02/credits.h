#pragma once
/**
* @struct credits
* @brief struct for credits
*/
typedef struct Credits {
	SDL_Surface *bg;
	int enabled;
} Credits;

void CREDITS_Init(Credits *s);
void CREDITS_Render(Credits *s, SDL_Surface **screen);
void CREDITS_HandleEvent(Credits *s, SDL_Event *event);
