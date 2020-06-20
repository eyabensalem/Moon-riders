/**
* @file save.c
* @brief integrated program
* @author eya ben salem
* @version 0.1
* @date July 04 2020
*
* integrated program for save
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "save.h"
/**
* @brief pour sauvgarger x , y et k dans le fichier
* @param menu
* @param x  
* @param y 
* @param k 
* @return Nothing
*/
void fichier(char nomfichier[],short int *x, short  int *y ,short int *k )
{
FILE*f=NULL;

f=fopen(nomfichier,"a");

                    
        
            fprintf(f,"%hd | %hd | %hd\n",*x,*y,*k);
             
            
        
fclose(f);
        }
/**
* @brief pour lire x , y et k dans le fichier
* @param menu
* @param x  
* @param y 
* @param k 
* @return Nothing
*/
 void extraire(char nomfichier[],short int *x,short int *y,short int *k ) 
 {
 FILE*f=NULL;

f=fopen(nomfichier,"r");
if(f!=NULL)
{
fscanf(f,"%hd | %hd |%hd", x , y ,k ) ; 

} 
fclose(f);
 }
