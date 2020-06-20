/**
* @file collisionc.c
* @brief integrated program
* @author abdladhim ben abdladhim
* @version 0.1
* @date July 04 2020
*
* integrated program for collision
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<SDL/SDL.h>

#include"collisionc.h"

float lerp(float a,float b, float t)
{
	return a + t * (b - a);// interpolation lineaire (lisser le deplacement)
}

int collisionc(SDL_Rect a,float ra, SDL_Rect b, float rb){
	float ax = a.x + a.w / 2.0f;//calcule abcisse et largeur de c1
	float ay = a.y + a.h / 2.0f;//calcule ordonne et longueur de c1	
	float bx = b.x + b.w / 2.0f;//calcule abcisse et largeur de c2	
	float by = b.y + b.h / 2.0f;//calcule ordonne et longueur de c2	

	if(sqrt(abs(ax-bx)*abs(ax-bx) + abs(ay-by)*abs(ay-by)) < rb + ra)//comparaison des rayon par rapport a la distance 
{
		return 1;
	}

	return 0;
}
