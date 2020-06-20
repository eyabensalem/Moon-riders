/**
* @file main.c
* @brief integrated Program.
* @author Ben Salem Eya
* @version 0.1
* @date July 1,2020
*
* integrated program for rotozoom
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
#include "rotozoom.h"
#include <SDL/SDL_image.h>

int main(int argc, char *argv[])
{

 rotozoom();


 SDL_Quit();

return 0;
}

