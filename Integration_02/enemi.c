#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"enemi.h"


void enemi_Init(enemi *c, int x, int y){
	c->sprite = IMG_Load("2.png");
	c->sprite2 = IMG_Load("1.png");
	c->x = x;
	c->y = y;
	c->dx = 0;
	c->cx = 0;
	int clips = 128;
	c->frame = 0;
	c->time = 0;

	for(int i=0;i<7;i++) {
		c->clips[i].w = clips;
		c->clips2[i].w = clips;
		c->clips[i].h = clips;
		c->clips2[i].h = clips;
		c->clips[i].x = i*clips;
		c->clips2[i].x = c->sprite->w - (i+1)*clips;
		c->clips[i].y = 0;
		c->clips2[i].y = 0;
	}
}

void enemi_Render(enemi *c, SDL_Rect r, SDL_Surface **screen){
	SDL_Rect r2 = {c->x - r.x, c->y};
	if(c->dx){
		c->x +=15;
		SDL_BlitSurface(c->sprite2,&c->clips[(int) c->frame],*screen, &r2);
	}else{
		SDL_BlitSurface(c->sprite,&c->clips2[(int) c->frame],*screen, &r2);
		c->x -= 15;

	}

	c->cx++;
	if(c->cx % 30 == 0)
		c->dx = !c->dx;
	c->frame += 0.2f;
	if(c->frame >= 6)
		c->frame = 0;
}
