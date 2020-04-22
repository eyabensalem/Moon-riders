 #include "structs.h"


void afficher(Map* m)
{
  SDL_Rect Rdest, pos;

  pos.x = m->xscroll;
  pos.y = m->yscroll;

  Rdest.x = Rdest.y  = 0;

  Rdest.w = pos.w =  m->wscroll;
  Rdest.h = pos.h =  m->hscroll;

 SDL_BlitSurface(m->image, &pos, SDL_GetVideoSurface(), &Rdest);
}

SDL_Surface* Loadimage(const char* fich)
{
   SDL_Surface *image32, *imagesimple;

   imagesimple= IMG_Load(fich);
   if(imagesimple==NULL)
   {
   printf("Load image error \n");
   exit(EXIT_FAILURE);

   }
   image32 = SDL_DisplayFormat(imagesimple);
   SDL_FreeSurface(imagesimple);
   return image32;
}

void initMap(Map* m, const char* fich, int w, int h)
{
  m->image = Loadimage(fich);
  m->xscroll = 0;
  m->yscroll = 0;
  m->wscroll = w;
  m->hscroll = h;
}

int scrollcenter(Sprite* s, Map* m)
{
  if((s->posx + s->sph.imgw / 2) >
     (m->xscroll + m->wscroll / 2) - s->sph.imgw / 2)
    return 1;
  return 0;
}


void clampMap(Map* m)
{
  if(m->xscroll < 0)
    m->xscroll = 0;
  if(m->xscroll > m->image->w - m->wscroll)
    m->xscroll = m->image->w - m->wscroll;
}



void moveMap(Map* m, int move, Input* in)
{
  if(in->key[SDLK_LEFT])
    m->xscroll -= move;
  if(in->key[SDLK_RIGHT])
    m->xscroll += move;
  clampMap(m);
}


