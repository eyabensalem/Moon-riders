/**
* @file quiz.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 5, 2020
*
* integrated program for quiz
*
*/
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<time.h>
#include"quiz.h"
/**
* @brief To initialize the background b .
* @param b the background
* @param url the url of the image
* @return Nothing
*/
void QUIZ_Init(Quiz *q,const char* filename){
	q->bg = IMG_Load("quiz.png");
	q->bgpos.x=0;
	q->bgpos.y=150;
	q->enabled = 0;
	q->rouge.r = 217;
	q->rouge.g = 10;
	q->rouge.b = 4;

	q->gold.r = 251;
	q->gold.g = 208;
	q->gold.b = 119;	

	q->noire.r = q->noire.g = q->noire.b = 0;

	q->font = TTF_OpenFont("theme.ttf",30);

	q->f = fopen(filename,"r");
	for(int i = 0; i<5; i++){
		char buf[255];
		fgets(buf, sizeof(buf),q->f);
		strcpy(q->questions[i].question,buf);
		fgets(buf, sizeof(buf),q->f);
		strcpy(q->questions[i].reponse1,buf);
		fgets(buf, sizeof(buf),q->f);
		strcpy(q->questions[i].reponse2,buf);
		fgets(buf, sizeof(buf),q->f);
		strcpy(q->questions[i].reponse3,buf);
	}

	fclose(q->f);

	srand(time(NULL));
	q->qid = (int)(random()%5);
	q->choices[0] = 0;
	q->choices[1] = 1;
	q->choices[2] = 2;
	for(int i = 0; i<10; i++){
		int t = random()%3;
		int t2 = random()%3;
		int t3 = q->choices[t];
		q->choices[t] = q->choices[t2];
		q->choices[t2] = t3;
	}

	q->currentChoice = 0;
}

void QUIZ_NextQuestion(Quiz *q) {
	srand(time(NULL));
	q->qid = random()%5;
	for(int i = 0; i<10; i++){
		int t = random()%3;
		int t2 = random()%3;
		int t3 = q->choices[t];
		q->choices[t] = q->choices[t2];
		q->choices[t2] = t3;
	}
}

const char* QUIZ_GetQuestion(Question *t,int q){
	if(q==0)
		return t->reponse1;
	if(q==1)
		return t->reponse2;
	return t->reponse3;
}

void QUIZ_HandleEvent(Quiz *s,int *play_enabled, int *play2_enabled,int *play3_enabled, SDL_Event *event){
	if(event->type == SDL_KEYDOWN){
		if(event->key.keysym.sym == SDLK_UP){
			if(s->currentChoice == 0)
				s->currentChoice = 2;
			else
				s->currentChoice -= 1;
		}
		if(event->key.keysym.sym == SDLK_DOWN){
			if(s->currentChoice == 2)
				s->currentChoice = 0;
			else
				s->currentChoice += 1;
		}

		if(event->key.keysym.sym == SDLK_RETURN){
			if(s->choices[s->currentChoice] == 0) {
				s->enabled = 0;
			} else {
				s->enabled = 0;
				if(*play_enabled == 1){
					*play2_enabled = 1;
				}
				if(*play2_enabled == 1){
					*play_enabled = 0;
					*play2_enabled = 0;
					*play3_enabled = 1;
				}
				if(*play3_enabled == 1) {
					*play_enabled = 0;
					*play2_enabled = 0;
					*play3_enabled = 0;

				}
			}	
		}
		
	}
}

void QUIZ_RenderFont(Quiz *quiz, int x, int y, const char* text, int b, SDL_Surface **screen){
	SDL_Rect r;
	r.x = x;
	r.y = y;
	quiz->msg = TTF_RenderText_Solid(quiz->font,text,quiz->noire);
	SDL_BlitSurface(quiz->msg,NULL,*screen,&r);
	r.x -= 3;
	r.y += 3;
	if(!b)
		quiz->msg = TTF_RenderText_Solid(quiz->font,text,quiz->rouge);
	else 
		quiz->msg = TTF_RenderText_Solid(quiz->font,text,quiz->gold);
	SDL_BlitSurface(quiz->msg,NULL,*screen,&r);
}

void QUIZ_Render(Quiz *s,SDL_Surface **screen){
	SDL_BlitSurface(s->bg,NULL,*screen,&s->bgpos);
	QUIZ_RenderFont(s,100,160,s->questions[s->qid].question,0,screen);
	QUIZ_RenderFont(s,100,250,QUIZ_GetQuestion(&s->questions[s->qid],s->choices[0]),s->currentChoice == 0,screen);
	QUIZ_RenderFont(s,100,350,QUIZ_GetQuestion(&s->questions[s->qid],s->choices[1]),s->currentChoice == 1,screen);
	QUIZ_RenderFont(s,100,450,QUIZ_GetQuestion(&s->questions[s->qid],s->choices[2]),s->currentChoice == 2,screen);
}
