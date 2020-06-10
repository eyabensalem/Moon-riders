 #include "structs.h"


void initSpriteshet(Spritesheet *sph, const char* fic, int nbimgx, int nbimgy,Uint16 R, Uint16 G, Uint16 B)
{
   sph->nbimgx = nbimgx;
   sph->nbimgy = nbimgy;
   sph->sheet = Loadimage(fic);
   SDL_SetColorKey(sph->sheet, SDL_SRCCOLORKEY, SDL_MapRGB((sph->sheet)->format, 255, 0, 0));
   sph->imgw = sph->sheet->w / sph->nbimgx;
   sph->imgh = sph->sheet->h / sph->nbimgy;
}



void rectangleSprite(Spritesheet* sph, SDL_Rect *src, int image)
{
    src->w = (Uint16)sph->imgw;
    src->h = (Uint16)sph->imgh;
    src->x = (Uint16)((image % sph->nbimgx) * sph->imgw);
    src->y = (Uint16)((image / sph->nbimgx) * sph->imgh);
}

void initAnimation(Animation *a, int imagedepart, int nbimage, int delay)
{
   a->imagedepart = imagedepart;
   a->nbimage = nbimage;
   a->delay = delay;
}

int mouvementanim(Animation *a)
{
  return a->imagedepart + (SDL_GetTicks()/a->delay) % a->nbimage;
}

void InitVie(Vie *v)
{
  v->vie =6;
  v->vies[1] =IMG_Load("vie/0.png");
  v->vies[2] =IMG_Load("vie/1.png");
  v->vies[3] =IMG_Load("vie/2.png");
  v->vies[4] =IMG_Load("vie/3.png");
  v->vies[5] =IMG_Load("vie/4.png");
  v->vies[6] =IMG_Load("vie/5.png");
  v->BarreA= v->vies[6];
  v->pos_v.x = 20;
  v->pos_v.y = 0;
}
void nbvie(Vie* v)
{  
	  int life;
     
      if(v->vie >0)
       {
        (v->vie)--;
        life = v->vie;
        printf("vie=%d\n",v->vie);
        v->BarreA = v->vies[life];
       }
}

void affichervie(SDL_Surface* ecran,Vie* v)
{  
   SDL_BlitSurface(v->vies[v->vie],NULL,ecran, &v->pos_v);  
}


void initSprite(Sprite* s,Spritesheet* sph,int posx,int posy,int imagedepart)
{
	s->v_y = s->v_x = 0;
   	s->posx = posx;
  	s->posy = posy;
   	s->sph = *sph;
   	s->sens = SENS_HAUT;
  	s->statut = SOL;
   	initAnimation(&s->a, imagedepart, 1, 1);
}

void afficherSprite(SDL_Surface* ecran, Sprite* s, Map* m)
{  
    int image;
    SDL_Rect src, dest;
    image = mouvementanim(&s->a);
    rectangleSprite(&s->sph, &src,image);
    dest = src;
    dest.x = s->posx - m->xscroll + m->debut;
    dest.y = s->posy - m->yscroll;
	SDL_BlitSurface(s->sph.sheet, &src ,ecran, &dest);
}

void movesprite(Input* in, Sprite* s, int speed, int num, Map *m)
{
	int move = 0, impulsion = 4, i=0, j=0;
	int delay = 120;
	double gravite = 0.08;
	int direction[2][3] = {{SDLK_LEFT,SDLK_RIGHT, SDLK_SPACE},{SDLK_j,SDLK_k,SDLK_l}};
	

  if(in->key[direction[num][0]])
	{
		move = 1;
        s->sens = SENS_GAUCHE;
        s->posx -= speed;
	}
	if(in->key[direction[num][1]])
	{
		move = 1;
		s->sens = SENS_DROIT;
		s->posx += speed;
	}
  if(s->sens == SENS_GAUCHE && s->posx < 0)
    s->posx += speed;
  /*else if(s->sens == SENS_DROIT && (s->posx ) > m->image->w)
    s->posx -= speed;*/
	if(move)
	{
		initAnimation(&s->a, s->sens * s->sph.nbimgx, 4, delay);
	}	

	if(in->key[direction[num][2]] && s->statut != AIR)
	{ 
		s->v_y = -impulsion;
		s->statut = AIR;		
	}

	if(move && s->statut != AIR)
		s->statut = SOL;

	s->v_y += gravite;	
	s->posy += (Sint16)s->v_y;
	if(s->posy > 520)
	{
		s->posy -= (Sint16)s->v_y;
		s->statut = SOL;
		s->v_y = 0;	
	}	
	//limite deplacement joueur
	

	if(s->statut == SOL && !move)
	{
		initAnimation(&s->a, s->a.imagedepart, 1, 1);
	}	
}


