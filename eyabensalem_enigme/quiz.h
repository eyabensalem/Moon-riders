#pragma once

#include<string.h>

#include<stdio.h>

#include<stdlib.h>



typedef struct Question {

	char question[255];

	char reponse1[255];

	char reponse2[255];

	char reponse3[255];

} Question;



typedef struct Quiz {

	FILE *f;

	Question questions[5];

} Quiz;



void QUIZ_Init(Quiz *q,char* filename);






