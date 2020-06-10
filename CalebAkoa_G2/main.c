 //#include "scrolling.h"
  #include "structs.h"

int main(int argc, char *argv[])
{
   
  SDL_Surface *ecran=NULL;
  int i, nbplayer = 2;
  Map* m = malloc(nbplayer * sizeof(Map));  
  Input in;
  Sprite* s;
  Spritesheet sph[2];
  SDL_Init(SDL_INIT_VIDEO );
  
  ecran = SDL_SetVideoMode(HAUTEUR_ECRAN, LARGEUR_ECRAN, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  SDL_WM_SetCaption("Caleb Essaie !", NULL);
  

  initSpriteshet(&sph[0], "pecheur.bmp", 4, 4, 255, 127, 0);
  initSpriteshet(&sph[1], "pecheur.bmp", 4, 4, 255, 127, 0);
 
 
  initInput(&in);

  initMap(&m[0], "Back0.png", 400, 600, 0);
  if(nbplayer == 2)
    initMap(&m[1], "Back0.png", 400, 600, 400);

  initSprite(&s[0], &sph[0], 100, 100, 0);
  initSprite(&s[1] , &sph[1], 100, 100, 1);
  while(!in.quit && !in.key[SDLK_ESCAPE])
  {
    updateEvent(&in);
    if(scrollcenter(&s[0], &m[0]))
      moveMap(&m[0],1,&in, 0);
    if(nbplayer == 2)
    {
      if(scrollcenter(&s[1] , &m[1]))
         moveMap(&m[1],1,&in, 1);
      movesprite(&in, &s[1] , 1, 1, &m[1]);   
      afficher(&m[1]);
    }
    movesprite(&in, &s[0], 1, 0, &m[1]);
    afficher(&m[0]);

    afficherSprite(ecran,&s[0] ,&m[0]);
    afficherSprite(ecran,&s[1] ,&m[1]);
    SDL_Flip(ecran);                 
  }
  SDL_Quit();
}