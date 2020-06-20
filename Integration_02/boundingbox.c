/**
*@file boundingbox.c
*@brief Integrated Program
*@author gaaloul ahmed
*@version 2.0
*@date july 4, 2020
*
*Integrated Program for bounding box collision
*
*/
#include"boundingbox.h"
/**
*@brief To detect the Collision
*@param a the player 
*@param b the object or the ennemy
*@return 1 if collision 0 if nothing happened
*/
int collision(SDL_Rect a, SDL_Rect b)
{
	if(!(a.x > b.x+b.w || a.y > b.y+b.h || a.x+a.w < b.x || a.y+a.h < b.y)){
		return 1;
	}
	return 0;
}
