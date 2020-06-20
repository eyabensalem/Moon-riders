#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"game.h"
#include"playm.h"
#include"playm2.h"
#include"play.h"
#include"play2.h"
#include"play3.h"
#include"settings2.h"
#include"credits.h"
#include"menu.h"
#include"menu2.h"
#include"menu3.h"
#include"quiz.h"
#include"exit.h"
#include"exit2.h"
#include"navg.h"


int main() {

	SDL_Init(SDL_INIT_EVERYTHING);

	TTF_Init();
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);

	Game game;
	GAME_Init(&game);


/*///////////////////////////animation logo/////////////////////////
SDL_Surface *img[168],*img2[135];
SDL_Rect imgp,imgp2;
imgp.x=imgp.y=0;
imgp.w=1366;
imgp.h=768;
imgp2.x=imgp2.y=0;
imgp2.w=1366;
imgp2.h=768;
char ch[50];
int i;
Mix_Music *son;
son = Mix_LoadMUS("logo.mp3");
Mix_Chunk *son2;
		son2 = Mix_LoadWAV("cursed.wav");

	

for(i=1;i<168;i++){

sprintf(ch,"LOGO/%d.png",i);
       img[i]=IMG_Load(ch);



}
for(i=1;i<136;i++){

sprintf(ch,"cursed/%d.png",i);

       img2[i]=IMG_Load(ch);
}
//////////animation intro//////////////
Mix_PlayMusic( son,1);

   for(i=1;i<167;i++)
    {

SDL_BlitSurface(img[i], NULL,game.screen,&imgp);
SDL_Flip(game.screen);
SDL_Delay(16);

    }
Mix_PauseMusic () ; 




Mix_PlayChannel(1, son2, 0);
  for(i=1;i<136;i++)

    {
SDL_BlitSurface(img2[i], NULL,game.screen,&imgp2);
SDL_Flip(game.screen);
SDL_Delay(16);
  }
////////////////////////////////////////////////////////////////////*/



	Quiz quiz;
	QUIZ_Init(&quiz,"questions.txt");

	Play play;
	PLAY_Init(&play);
	Play2 play2;
	PLAY2_Init(&play2);
	Play3 play3;
	PLAY3_Init(&play3);
	Playm playm;
	PLAYM_Init(&playm);
	Playm2 playm2;
	PLAYM2_Init(&playm2);

	Menu m;
	MENU_Init(&m, &game.screen);

	Menu2 m2;
	MENU2_Init(&m2, &game.screen);
	 
	Menu3 menu3;
	MENU3_Init(&menu3, &game.screen);

	Settings settings;
	SETTINGS_Init(&settings,&game.screen);

	Credits credits;
	CREDITS_Init(&credits);
	
	Navg navg;
	NAVG_Init(&navg,&game.screen);
	
	Exit exit ;
	EXIT_Init(&exit,&game.screen);
	Exit2 exit2 ;
	EXIT2_Init(&exit2,&game.screen);


	SDL_Event event;

	while(game.running){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				game.running = 0;
			}
			if(m2.enabled){
				MENU2_HandleEvent(&m2,&menu3,&playm,&event);
			}
			else if(menu3.enabled){
				MENU3_HandleEvent(&menu3,&play,&event);
			}
			else if(quiz.enabled){
				QUIZ_HandleEvent(&quiz,&play.enabled,&play2.enabled,&play3.enabled,&event);
			}
				
			else if(play3.enabled)
				PLAY3_HandleEvent(&play3, &exit ,&event);
			else if(play2.enabled)
				PLAY2_HandleEvent(&play2,&event);
			else if(play.enabled)
				PLAY_HandleEvent(&play,&exit2,&quiz,&event);
			else if(playm.enabled)
				PLAYM_HandleEvent(&playm,&exit2,&quiz,&event);
			else if(playm2.enabled)
				PLAYM2_HandleEvent(&playm2,&event);
			else if(navg.enabled)
				NAVG_HandleEvent(&navg,&event);
			else if(settings.enabled)
				SETTINGS_HandleEvent(&settings,&navg,&event);
			else if(exit.enabled)
				EXIT_HandleEvent(&exit,&game,&event);
			else if(exit2.enabled)
				EXIT2_HandleEvent(&exit2,&game,&event);
			else if(credits.enabled)
				CREDITS_HandleEvent(&credits,&event);
			
			else
				MENU_HandleEvent(&m,&m2,&game,&settings,&play,&credits,&exit,&event);
				
		}
		
		if(m2.enabled)
			MENU2_Render(&m2);
		else if(menu3.enabled)
			MENU3_Render(&menu3);
		else if(quiz.enabled)
			QUIZ_Render(&quiz,&game.screen);
	
		else if(play3.enabled)
			PLAY3_Render(&play3,&quiz,&game.screen);	
		else if(play2.enabled)
			PLAY2_Render(&play2,&quiz,&game.screen);	
		else if(play.enabled)
			PLAY_Render(&play,&play2,&play3,&quiz,&game.screen);
		else if(playm.enabled)
			PLAYM_Render(&playm,&playm2,&play3,&quiz,&game.screen);
		else if(playm2.enabled)
			PLAYM2_Render(&playm2,&quiz,&game.screen);
		else if(navg.enabled)
			NAVG_Render(&navg);	
		else if(settings.enabled)
			SETTINGS_Render(&settings);
		else if(exit.enabled)
			EXIT_Render(&exit);
		else if(exit2.enabled)
			EXIT2_Render(&exit2);	
		else if(credits.enabled)
			CREDITS_Render(&credits,&game.screen);
				
		else
			MENU_Render(&m);
		
		if(play.player.vie.hp <= 0){
			PLAY_Init(&play);
			PLAY2_Init(&play2);
			PLAY3_Init(&play3);
			
		}
		if(play2.player.vie.hp <= 0){
			PLAY_Init(&play);
			PLAY2_Init(&play2);
			PLAY3_Init(&play3);
		
		}
		if(play3.player.vie.hp <= 0){
			PLAY_Init(&play);
			PLAY2_Init(&play2);
			PLAY3_Init(&play3);
			
		}
		
		
		SDL_Flip(game.screen);
		SDL_Delay(16);
	}
	SDL_FreeSurface(game.screen); 

	SDL_Quit();
}
                            
