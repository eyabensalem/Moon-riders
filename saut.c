#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main ( int argc, char** argv )
{
    //Init de la SDL
    SDL_Init( SDL_INIT_VIDEO );

    // On crée une fenêtre
    SDL_Surface* ecran = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);

    // On charge le fond
    SDL_Surface* fond = IMG_Load("fond.png");

    //On charge Mario
    SDL_Surface* mario = IMG_Load("mario.png");

    // La position du fond
    SDL_Rect posFond;
    posFond.x = 0;
    posFond.y = 0;

    // La position absolue de Mario
    SDL_Rect posMarioAbs;
    posMarioAbs.x = 200;
    posMarioAbs.y = 300-(mario->h);

    // La position relative de Mario
    SDL_Rect posMarioRel;
    posMarioRel.x = 0;
    posMarioRel.y = 0;

    //Variables méthode 2:
    const double g = 9.81;
    const double pi = 3.14;
    int v_init = 2;
    int angle_init = pi/3;
    int t = 0;
    double v_x = cos(angle_init)*v_init;
    double v_y = sin(angle_init)*v_init;

    // Boucle principale
    int fin = 0;
    while (!fin)
    {
        // Gestion des evenements
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                fin = 1;
                break;

            case SDL_KEYDOWN:
                {
                    // ECHAP
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        fin = 1;
                    break;
                }
            }
        }

        // EVOLUTION

            //On met à "0" les pos abs:

            posMarioAbs.x = 200;
            posMarioAbs.y = 300-(mario->h);

            //On calcule la valeur relative de y:
            posMarioRel.x=(int)(v_x*t);
            posMarioRel.y=(int)((v_y*t)-((g*t*t)/2000));

            //On calcule maintenant les valeurs absolues

            posMarioAbs.x = posMarioAbs.x + posMarioRel.x;
            posMarioAbs.y = posMarioAbs.y - posMarioRel.y;

        //Intervalle de 10ms

        t+=10;

        // FIN EVOLUTION
        //Avec en bonus une petite mise a 0 des coordonnees lorsque mario s'en va trop loin :)
        if((posMarioAbs.y+(mario->h))<=(100))
        {
            t=0;
        }

        // DESSIN

        // Effacement de l'ecran
        SDL_FillRect(ecran, 0, SDL_MapRGB(ecran->format, 0, 0, 0));

        // Dessin des images
        SDL_BlitSurface(fond, 0, ecran, &posFond);
        SDL_BlitSurface(mario, 0, ecran, &posMarioAbs);

        // FIN DESSIN

        // Et n'oublions pas...
        SDL_Flip(ecran);
    }

    // Et on soulage la mémoire !
    SDL_FreeSurface(fond);
    SDL_FreeSurface(mario);

    SDL_Quit();

    return 0;
}
