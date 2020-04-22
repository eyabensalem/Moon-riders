 #include "structs.h"


void initInput(Input *in)
{
  memset(in, 0, sizeof(Input));
}

void updateEvent(Input* in)
{
   SDL_Event event;
   in->mousebutton[SDL_BUTTON_WHEELUP]=0;
   in->mousebutton[SDL_BUTTON_WHEELDOWN]=0;

	while(SDL_PollEvent(&event))
  	{
  		switch(event.type)
    	{
     	case SDL_QUIT:
     		in->quit = 1;
     		break;
      	case SDL_KEYDOWN :
      		in-> key[event.key.keysym.sym]=1;
      		break;
      	case SDL_KEYUP : 
      		in->key[event.key.keysym.sym]=0;
      		break;
      	case SDL_MOUSEMOTION : 
      		in->mousex = event.motion.x;
      		in->mousey = event.motion.y;
      		break;
      	case SDL_MOUSEBUTTONDOWN :
      		in->mousebutton[event.button.button]=1;
      		break;
      	case SDL_MOUSEBUTTONUP :
     		if(!in->mousebutton[SDL_BUTTON_WHEELUP] || !in->mousebutton[SDL_BUTTON_WHEELDOWN])
     			in->mousebutton[event.button.button]=0;
      		break; 
    	}
    }
}