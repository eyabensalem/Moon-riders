#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#define HAUT	0
#define DROITE	1
#define BAS	2
#define GAUCHE	3
#define AUCUNE_DIRECTION	0
#define DIRECTION_HAUT		1
#define DIRECTION_DROITE	2
#define DIRECTION_BAS		4
#define DIRECTION_GAUCHE	8
#define LARGEUR_ECRAN 600
#define HAUTEUR_ECRAN 800

typedef struct
{	
	SDL_Surface *image;
	SDL_Rect source;
	SDL_Rect dest;
	int largeur;
	int hauteur;
	int direction;
	int vitesse;
	int anim;
	int orientation;
	int anim_courante;
	int temps_anim;
	int temps_anim_courante;
	int total_anims;

}Sprite;

SDL_Surface *loadBmp(const char *fichier)
{
	SDL_Surface *image;
	image = SDL_LoadBMP(fichier); //charger le fichier d image
	if ( image == NULL )
	{
		fprintf(stderr, "Echec de chargement du fichier %s : %s.\n", fichier, SDL_GetError());
		return NULL;
	}
		
	return image;
}

int charger_entiter( Sprite *sprite, const char *image )
{
	sprite->image = loadBmp(image);
	if ( !sprite->image )
		return 0;
	SDL_SetColorKey( sprite->image, SDL_SRCCOLORKEY, SDL_MapRGB( sprite->image->format, 255, 255, 255) );
        
	sprite->anim = 0;
	sprite->anim_courante = 0;// pre anim
	sprite->total_anims = 4;
	sprite->orientation = BAS;

	// chaque animation dure 5 affichages
	sprite->temps_anim = 8;

	// Le temps qu'il reste à afficher l'animation courante
	sprite->temps_anim_courante = 0;

	// On definit ensuite les dimentions du sprite.
	sprite->largeur = 32 ;
	sprite->hauteur = 32;
	
	sprite->source.x = sprite->anim_courante * sprite->largeur;
	sprite->source.y = sprite->orientation * sprite->hauteur;
	sprite->source.w = sprite->largeur;
	sprite->source.h = sprite->hauteur;

	sprite->dest.x = 0;
	sprite->dest.y = 0;
	sprite->dest.w = sprite->largeur;
	sprite->dest.h = sprite->hauteur ;
	
	// on definit enfin la vitesse et la direction du sprite
	sprite->vitesse = 2;
	sprite->direction = AUCUNE_DIRECTION;
	
	return 1;
}

void supprimerSprite( Sprite *sprite )
{
	SDL_FreeSurface( sprite->image );
}

void fixerDirectionSprite( Sprite *sprite, int direction )
{
	// On affecte la direction au sprite
	sprite->direction = direction;
	
	// on affecte l'animation correcpondant à la direction au sprite
	if (direction != AUCUNE_DIRECTION)
	{
		sprite->anim = 1;
		switch (direction)
		{
		case DIRECTION_HAUT:
			sprite->orientation = HAUT;
			break;
			
		case DIRECTION_DROITE:
			sprite->orientation = DROITE;
			break;

		case DIRECTION_BAS:
			sprite->orientation = BAS;
			break;

		case DIRECTION_GAUCHE:
			sprite->orientation = GAUCHE;
			break;

		default:
			;
		}
	}
	else
		// si le sprite est areté, on ne l'anime pas
		sprite->anim = 0;

	// on met la première animation
	sprite->anim_courante = 0;
	sprite->temps_anim_courante = 0;

	// on regle la source de l'image à copier
	sprite->source.y = sprite->orientation * sprite->hauteur;
	sprite->source.x = sprite->anim_courante * sprite->largeur;
}

void miseAJourSprite( Sprite *sprite )
{
	// le sprite vas vers le haut
	if (sprite->direction & DIRECTION_HAUT)
	{
		// on monte et on faut attention a ne pas sortie de l'ecran
		sprite->dest.y -= sprite->vitesse;
		if (sprite->dest.y < 0)
			sprite->dest.y = 0;
	}
	else if (sprite->direction & DIRECTION_DROITE)
	{
		// on va à droite et on fait attention a ne pas sortie de l'ecran
		sprite->dest.x += sprite->vitesse;	
		if (sprite->dest.x + sprite->largeur > LARGEUR_ECRAN)	
			sprite->dest.x = LARGEUR_ECRAN - sprite->largeur;
	}
	else if (sprite->direction & DIRECTION_BAS)
	{
		// on descend et on faut attention a ne pas sortie de l'ecran
		sprite->dest.y += sprite->vitesse;	
		if (sprite->dest.y + sprite->hauteur > HAUTEUR_ECRAN)
			sprite->dest.y = HAUTEUR_ECRAN - sprite->hauteur;
	}
	else if (sprite->direction & DIRECTION_GAUCHE)
	{
		// on va à gauche et on fait attention a ne pas sortie de l'ecran
		sprite->dest.x -= sprite->vitesse;	
		if (sprite->dest.x < 0)
			sprite->dest.x = 0;
	}
}

void dessinerSprite( Sprite *sprite, SDL_Surface *destination )
{
	/* si le sprite est animé, on gere l'animation */
	if (sprite->anim)
	{
		// on decremente le temps restant à l'animation courante
		sprite->temps_anim_courante--;
		// et on regarde s'il est temps de changer d'animation
		if ( sprite->temps_anim_courante <= 0 )
		{
			// s'il faut changer, on passe à l'animation suivante
			sprite->anim_courante++;
			// si on était à la dernière animation, on repasse à la première
			if (sprite->anim_courante >= sprite->total_anims)
				sprite->anim_courante = 0;
			
			// on regle la source à copier
			sprite->source.x = sprite->largeur * sprite->anim_courante;
			sprite->temps_anim_courante = sprite->temps_anim;
		}
	}
	
	// enfin, on dessine le sprite à l'ecran
	SDL_BlitSurface( sprite->image, &sprite->source, destination, &sprite->dest );
}

int main()
{

	SDL_Surface *ecran;
	SDL_Event event;
	int bFin = 0;
	Uint32 temps_courant, prochain_rendu = 0;
	
	/* On déclare trois sprites, un que l'on controlera
	   et deux qui se déplacerons tout seul */
	Sprite spAutonome1, spAutonome2;
	
	/* on declare des variables qui signalerons quand
	   il sera temps aux sprites autonomes de changer de direction */
	int changement_direction1, changement_direction2;
	
	/* initialisation de SDL_Video */
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		fprintf(stderr, "Echec d'initialisation de SDL.\n");
		return 1;
	}
	printf("Bonjour le monde, SDL est initialisé avec succès.\n");
	
	ecran = SDL_SetVideoMode(800,600, 16, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_NOFRAME);
	if ( ecran == NULL )
	{
		fprintf(stderr, "Echec de changement du mode video : %s.\n", SDL_GetError());
		return 1;
	}
	if ( !charger_entiter( &spAutonome1, "witch.bmp" ) )
	{
		SDL_Quit();
		return 1;
	}
	if ( !charger_entiter( &spAutonome2, "horce.bmp" ) )
	{
		supprimerSprite( &spAutonome1 );
		SDL_Quit();
		return 1;
	}

	// on place les sprites à l'écran
	spAutonome1.dest.x = 160;
	spAutonome1.dest.y = 160;
	
	spAutonome2.dest.x = 480;
	spAutonome2.dest.y = 320;

	srand( (unsigned)time(NULL) );
	// on lance un deplacement aléatoire pour les sprites autonomes
	// on genere un nombre entre 1, 2, 4 et 8 pour chaque sprite
	fixerDirectionSprite( &spAutonome1 , 1 << (rand()%4) );
	fixerDirectionSprite( &spAutonome2 , 1 << (rand()%4) );

	// on fixe dans combien de temps les sprites changerons de direction
	changement_direction1 = rand()%100 + 50;
	changement_direction2 = rand()%100 + 50;
	while (!bFin)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					bFin = 1;
					break;
				}
				break;
			
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					bFin = 0;
					break;
				}
				break;

			case SDL_QUIT:
				bFin = 1;
				break;
			
			default:
				;
			}
		}
		
		/* On recupère le temps écoulé en mili-secondes */
		temps_courant = SDL_GetTicks();
		
		/* On regarde s'il est temps d'effectuer le prochain rendu */
		if (temps_courant > prochain_rendu)
		{
			/* un rendu toutes les 20 milli-secondes = 50 images par secondes */
			prochain_rendu = temps_courant + 20;
			
			/* on met à jour le "jeu" */
			
			// d'abords les directions des sprites autonomes
			changement_direction1--;
			if (changement_direction1 == 0)
			{
				fixerDirectionSprite( &spAutonome1 , 1 << (rand()%4) );
				changement_direction1 = rand()%100 + 50;
			}
			
			changement_direction2--;
			if (changement_direction2 == 0)
			{
				fixerDirectionSprite( &spAutonome2 , 1 << (rand()%4) );
				changement_direction2 = rand()%100 + 50;
			}
			
			// puis les positions des sprites
			//miseAJourSprite( &spControlable );
			miseAJourSprite( &spAutonome1 );
			miseAJourSprite( &spAutonome2 );
		
			/* On dessine la scene */
			
			/* On efface l'écran */
			SDL_FillRect(ecran, NULL, 0);

			/* On dessine les sprites à l'écran */
			//dessinerSprite( &spControlable, ecran );
			dessinerSprite( &spAutonome1, ecran );
			dessinerSprite( &spAutonome2, ecran );
						
			/* On met à jour de la zone d'affichage de la fenetre */
			SDL_UpdateRect(ecran, 0, 0, 0, 0);
		}
		
	}

	supprimerSprite( &spAutonome1 );
	supprimerSprite( &spAutonome2 );
	SDL_Quit();
	return 0;
}
