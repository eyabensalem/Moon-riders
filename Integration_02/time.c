/**
* @file time.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 2, 2020
*
* integrated program for time
*
*/
#include"time.h"
/**
* @brief To initialize time and score
* @param time
* @return Nothing
*/
void initializerTemps(Time *time){
	time->font = TTF_OpenFont("theme.ttf", 32);
	
	sprintf(time->timeString,"TIME: 00:00:00");
	sprintf(time->scoreString,"SCORE: 0000");
	SDL_Color color = {255,255,255};
	SDL_Color color2 = {255,255,255};
	time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
	time->txt = TTF_RenderText_Solid(time->font,time->scoreString,color);
}
/**
* @brief display time and score
* @param time struct
* @param screen where it displays
* @return Nothing
*/
void afficherTemps(Time *time, SDL_Surface **screen){
	SDL_Color color = {255,255,255};
	SDL_Color color2 = {255,208,119};
	SDL_Rect r,r1;
	r.x=580;
	r.y=5;
	r1.x=1100;
	r1.y=5;		
	time->time+=100;
	time->score+=2;
	if(time->time % 60 == 0){
		sprintf(time->timeString,"TIME: %02d:%02d:%02d\n",time->time/60/60/60,time->time/60/60,(time->time/60)%100);
		time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
		if((time->time /60/60 %5)==0)
		{
			
			sprintf(time->scoreString,"SCORE: %02d%02d\n",time->score/100,time->score%100);
		time->txt = TTF_RenderText_Solid(time->font,time->scoreString,color2);
	}}
	SDL_BlitSurface(time->msg,NULL,*screen,&r);
	SDL_BlitSurface(time->txt,NULL,*screen,&r1);
}
