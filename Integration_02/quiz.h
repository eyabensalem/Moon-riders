#pragma once
#include<SDL/SDL_ttf.h>
/**
* @struct question
* @brief struct for question
*/
typedef struct Question {
	char question[255];/*<!question*/
	char reponse1[255];/*<!proposition 1*/
	char reponse2[255];/*<!proposition 2*/
	char reponse3[255];/*<!proposition 3*/
} Question;
/**
* @struct quiz
* @brief struct for quiz
*/
typedef struct Quiz {
	SDL_Surface **screen, *bg, *msg;/*<:!screen image message*/
	SDL_Rect bgpos;/*<!position background*/
	SDL_Color rouge,noire,gold;/*<!couleyr*/
	int enabled;
	Question questions[5];/*<!nembre des question dans un fichier*/
	FILE *f;/*<!fichier*/
	TTF_Font *font;/*<!fpnt*/
	int qid;
	int choices[3];
	int currentChoice;
} Quiz;

void QUIZ_Init(Quiz *s,const char* filename);
void QUIZ_Render(Quiz *s, SDL_Surface **screen);
void QUIZ_HandleEvent(Quiz *s,int *play_enabled, int *play2_enabled, int *play3_enabled, SDL_Event *event);
void QUIZ_NextQuestion(Quiz *s);
const char* QUIZ_GetQuestion(Question *t,int q);
