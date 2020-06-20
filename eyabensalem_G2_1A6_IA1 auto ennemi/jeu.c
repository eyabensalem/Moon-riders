#include "jeu.h"

void get_input(int Tab_input[], SDL_Event event)
{
	switch (event.type) 
	{
		case SDL_KEYDOWN:
			Tab_input[event.key.keysym.sym] = 1;	
			break;

		case SDL_KEYUP:
			Tab_input[event.key.keysym.sym] = 0;
			break;
	}

}

int jouer(SDL_Surface * screen)
{
	

	int continuer = 1;
	SDL_Event event;
	int Tab_input[323] = {0}; // everything will be initialized to false	

	Hero hero;
	Ennemi E;
	Background B;
	Text txt;
	
	TTF_Font *police = NULL;
	

	int HE_collision = 0; //initialement pas de collision hero/ennemi
	int ib = 0, ih = 0, ie = 0, it = 0;

	/*********************** INITIALIZE ************************/
	
	ib = init_background(&B);
	ih = init_hero(&hero);
	ie = init_ennemi(&E);
	it = init_text(&txt);

	if(ib == -1 || ih == -1 || ie == -1 || it == -1)
	{
		continuer = 0;	
	}

	//Appui continu sur les touches
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);

	// GAME LOOP
	while(continuer) 
	{
		/*********************** INPUT ************************/
		if (SDL_PollEvent(&event)) 
		{				
			get_input(Tab_input, event);
		}

	 
		/*********************** UPDATE ************************/
		// update continuer pour sortir de la boucle si
		// l'utilisateur appuie sur echaper ou sur la croix
		continuer = !(Tab_input[SDLK_ESCAPE] || event.type == SDL_QUIT);
		
		//update l'etat de collision hero/ennemi,
		// cas deplacement horizontal, hero à gauche de l'ennemi
		HE_collision = 	((hero.positionAbsolue.x + Hero_WIDTH) >= E.positionAbsolue.x) &&(hero.positionAbsolue.x <= (E.positionAbsolue.x + Ennemi_WIDTH));		

		//update les composantes du jeu
		update_hero(&hero, Tab_input, HE_collision);
		update_ennemi(&E, hero.positionAbsolue);
		update_txt(&txt,hero.vies);
// 		update_background(...); // en cas de scrolling



		/*********************** DISPLAY ************************/
		display_background(B,screen);
		displayText(txt,screen);
		display_ennemi(E,screen);
		display_hero(hero,screen);

		SDL_Flip(screen);
		
	}
        freeText(&txt);
	freeHero(&hero);
	freeEnnemi(&E);
	freeBackground(&B);
	
	return(0);
}
