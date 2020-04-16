#include"quiz.h"



void QUIZ_Init(Quiz *q, char* filename) {

	q->f = fopen(filename,"r"); //ouvrir en mode lecture

	for(int i = 0; i<5; i++){ //copier les questions et reponses 

		char buf[255];

		fgets(buf, sizeof(buf),q->f); //lire 1e ligne

		strcpy(q->questions[i].question,buf); 

		fgets(buf, sizeof(buf),q->f);

		strcpy(q->questions[i].reponse1,buf);

		fgets(buf, sizeof(buf),q->f);

		strcpy(q->questions[i].reponse2,buf);

		fgets(buf, sizeof(buf),q->f);

		strcpy(q->questions[i].reponse3,buf);

	}



	fclose(q->f);

}




