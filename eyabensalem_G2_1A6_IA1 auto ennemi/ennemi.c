/**
* @file ennemi.c
* @brief Testing Program.
* @author Ben salem Eya 
* @version 0.1
* @date july 14,2020
*
* Testing program for ennemi
*
*/
#include "ennemi.h"

/**
* @brief To initialize the ennemi E
* @param E ennemi
* @return ok
*/
int init_ennemi(Ennemi* E)
{
	int OK;

	OK = loadEnnemiImages(E); //chargement de l'image
	if (OK != -1)
	{
		initEnnemiAttributes(E); //attribuer les positions
	}
	
	return OK;
}

/**
* @brief Load picture
* @param E ennemi
* @return 0 if loaded else -1
*/
int loadEnnemiImages(Ennemi * E)
{
	E->image = IMG_Load("ennemi_spr.png");

	if(E->image == NULL) {
		printf("Unable to load Ennemi png:%s\n", SDL_GetError());
		return (-1);
	}
	return (0);
}

/**
* @brief To initialize position ennemi E
* @param E ennemi
* @return nothing
*/
void initEnnemiAttributes(Ennemi* E)
{	
	int i, j;	

	E->positionAbsolue.x = 0.5 * BACKGND_W;
	E->positionAbsolue.y = 0.8 * BACKGND_H - Ennemi_HEIGHT;
	E->positionAbsolue.w = Ennemi_WIDTH;
	E->positionAbsolue.h = Ennemi_HEIGHT;
	
	E->Frame.i = 1;
	E->Frame.j = 0;
	
        // Faire le calcul des SDL_Rect des positions de toutes 
	// les imagettes une seule fois à l'initialisation
	for (i = 0; i < SPRITE_ENNEMI_NbL; i++)
	{	for(j = 0; j < SPRITE_ENNEMI_NbCol; j++)
		{	
			E->positionAnimation[i][j].x = j * Ennemi_WIDTH;
			E->positionAnimation[i][j].y = i * Ennemi_HEIGHT;
			E->positionAnimation[i][j].w = Ennemi_WIDTH;  
			E->positionAnimation[i][j].h = Ennemi_HEIGHT;
		}
	}
	E->Direction = 1;
	E->State = WAITING;
	
}
/**
* @brief To blit
* @param E ennemi
* @param screen where to display
* @return nothing
*/
void display_ennemi(Ennemi E, SDL_Surface* screen) //coller l'image
{
	SDL_BlitSurface(E.image, &E.positionAnimation[E.Frame.i][E.Frame.j], screen, &E.positionAbsolue);
}
/**
* @brief To animate the ennemi E in every state
* @param E ennemi
* @return nothing
*/
void animateEnnemi(Ennemi* E)
{


	// mise a jour du numero de ligne de l'imagette 
	// si l'ennemi n'est pas en train d'attaquer --> ligne = 1

	/* Completer le code ici */
	switch(E->State)
	{
			case WAITING :
			{ E->Frame.i = 1;
				break ;
      	}
			case FOLLOWING :
				{ E->Frame.i = 1;

				  break;
				}

			case ATTACKING :
				{  E->Frame.i = 3;
                                   break ;
					}
	}
	// si l'ennemi est  en train d'attaquer --> ligne = 3
		 
	// mise a jour du numero de colonne de l'imagette pour avoir l'effet de l'animation
	E->Frame.j ++;    
	if (E->Frame.j == SPRITE_ENNEMI_NbCol)   
		 E->Frame.j = 0;  
	SDL_Delay(50);	
}

/**
* @brief To move ennemi
* @param E ennemi
* @param poshero position de hero
* @return nothing
*/
void moveEnnemi(Ennemi *E, SDL_Rect posHero)
{
	if (posHero.x<E->positionAbsolue.x) //hero à gauche de l'ennemi
	{
        	E->positionAbsolue.x -= 8; 
	}
}
/**
* @brief To animate and move switch state
* @param E ennemi
* @param poshero positionhero
* @return ok
*/
void update_ennemi(Ennemi* E, SDL_Rect posHero)
{
	int distEH = E->positionAbsolue.x - (posHero.x + Hero_WIDTH);
	printf("distEH = %d\t E->State = %d\n", distEH,E->State);
    	switch(E->State)
    	{
        	case WAITING :
        	{
            		animateEnnemi(E);
            		break;
        	}

        	case FOLLOWING :
        	{
            		animateEnnemi(E);
            		moveEnnemi(E,posHero);
            		break;
        	}

        	case ATTACKING :
        	{
			// Attaque en se déplaçant vers l'ennemi
		    	animateEnnemi(E);
			moveEnnemi(E,posHero);
			break;
        	}       
    	}

	updateEnnemiState(E, distEH);	
}

/**
* @brief To update state
* @param E ennemi
* @param disteh distance ennemi hero
* @return ok
*/
void updateEnnemiState(Ennemi* E, int distEH)
{
	// Selon l'état courant de l'ennemi, implementer les transitions t2, t4 et t6
   	

	/* Completer le code ici */
	switch (E->State)
      {
      case WAITING:
        if ((distEH>400)&&(distEH<=600)) {
            E->State=FOLLOWING;
            }

      case FOLLOWING:

        if ((0<distEH) && (distEH<=200)) {
             E->State=ATTACKING;
                }
      case ATTACKING:

           if (distEH<=0) {
             E->State=WAITING;
                }

      }
}

/**
* @brief To free memory
* @param E ennemi
* @return nothing
*/
void freeEnnemi(Ennemi *E)
{
	SDL_FreeSurface(E->image);
}
