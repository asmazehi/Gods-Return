#include "camera.h"
#include "collision_parfaite.h"

void init_col( collision* c)
{
    c->x1 = 0;
    c->y1 = 0;
    c->x2 = 0;
    c->y2 = 0;
    c->x3 = 0;
    c->y3 = 0;
    c->x4 = 0;
    c->y4 = 0;
    c->x5 = 0;
    c->y5 = 0;
    c->x6 = 0;
    c->y6 = 0;
    c->x7 = 0;
    c->y7 = 0;
    c->x8 = 0;
    c->y8 = 0;
    c->color1.r= 0;
    c->color1.g=0;
    c->color1.b=0;

    c->color2.r= 0;
    c->color2.g=0;
    c->color2.b=0;

    c->color3.r= 0;
    c->color3.g=0;
    c->color3.b=0;

    c->color4.r= 0;
    c->color4.g=0;
    c->color4.b=0;

    c->color5.r= 0;
    c->color5.g=0;
    c->color5.b=0;

    c->color6.r= 0;
    c->color6.g=0;
    c->color6.b=0;

    c->color7.r= 0;
    c->color7.g=0;
    c->color7.b=0;

    c->color8.r= 0;
    c->color8.g=0;
    c->color8.b=0;

}

SDL_Color GetPixel (SDL_Surface *bg, int x, int y)
{

    SDL_Color color ;
    Uint32 col=0; // entier a 32 bit
    char* pPosition = (char*)bg->pixels ; // prendre la pixel initiale de position (0, 0 ) sure notre background
    pPosition += (bg->pitch * y); // ajoutr notre position .y de notre hero a la position de note pPosition = (0,0 );
    pPosition += (bg->format->BytesPerPixel * x); // ajouter notre position .x de l'hero a la position du pixel pPosition = .y + .x
    memcpy(&col, pPosition, bg->format->BytesPerPixel); // copier les couleur dans notre variable colq
    SDL_GetRGB(col,bg->format, &color.r, &color.g,&color.b ); // deplacer les valeurs RGB vers notre variable color de notre variable col

    return (color) ;

}


void update_points_de_collision(collision* c,  SDL_Rect *pos_perso)
{

    c->x1=pos_perso->x + pos_perso->w ;
    c->y1=pos_perso->y ;

    c->x2=pos_perso->x + pos_perso->w ;
    c->y2= pos_perso->y + 70  ;

    c->x3=  pos_perso->x + 100;
    c->y3= pos_perso->y + 100;


    c->x4=pos_perso->x ;
    c->y4= pos_perso->y ;


    c->x5=pos_perso->x ;
    c->y5= pos_perso->y + pos_perso->h/2  ;

    c->x6=pos_perso->x ;
    c->y6= pos_perso->y + pos_perso->h  ;


    c->x7=pos_perso->x + pos_perso->w/2 ;
    c->y7= pos_perso->y  ;

    c->x8=pos_perso->x + pos_perso->w/2 ;
    c->y8= pos_perso->y + pos_perso->h  ;

}

