#include"pixelperfectcollision.h"

int collision(SDL_Surface *a, SDL_Rect pos_a, SDL_Surface *b, SDL_Rect pos_b){
	for(int xa = pos_a.x; xa < pos_a.x + a->w; xa++){
		for(int ya = pos_a.y; ya < pos_a.y + a->h; ya++){
			for(int xb = pos_b.x; xb < pos_b.x + b->w; xb++){
				for(int yb = pos_b.y; yb < pos_b.y + b->h; yb++){
					if(xa == xb && ya == yb)
						return 1;
				}
			}
			
		}
	}
	return 0;
}
