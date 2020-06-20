#ifndef Ennemi_H
#define Ennemi_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "defs.h"
#include "background.h"


typedef enum STATE STATE;
enum STATE {WAITING, FOLLOWING,ATTACKING};
/**
* @struct ennemi
* @brief struct for ennemi
*/
struct Ennemi
{
        SDL_Surface * image; /*<!image */
	SDL_Rect positionAnimation [SPRITE_ENNEMI_NbL][SPRITE_ENNEMI_NbCol]; /*<!posAnimation */
	FRAME Frame; /*<!frame */
	SDL_Rect positionAbsolue; /*<!posAbsolue */
	int Direction; /*<!direction */
	STATE State; /*<!state */
};
typedef struct Ennemi Ennemi;

int init_ennemi(Ennemi* E);
void update_ennemi(Ennemi* E, SDL_Rect posHero);

void display_ennemi(Ennemi E, SDL_Surface* screen);
void freeEnnemi(Ennemi* E);

int loadEnnemiImages(Ennemi* E);
void initEnnemiAttributes(Ennemi* E);

void animateEnnemi(Ennemi* E);
void moveEnnemi(Ennemi* E, SDL_Rect posHero);
void updateEnnemiState(Ennemi* E, int distEH);


#endif
