#include "perso.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<stdio.h>
#include<stdlib.h>

SDL_Surface *LOAD_IMG(char fileName[20])
{
    SDL_Surface *img=NULL;
    img=IMG_Load(fileName);
    if(img==NULL)
        printf("ERROR /> %s\n",SDL_GetError());
    return img;
}

void Init_Map(Perso *map)
{
    map->img=LOAD_IMG("back.png");
    map->posMap.x=0;
    map->posMap.y=0;
    map->posMap.w=1422;
    map->posMap.h=258;
}

void Draw_MiniMap(Perso map,SDL_Surface *Screen)
{
    SDL_BlitSurface(map.img,NULL,Screen,&map.posMap);
}


int collisionBB(SDL_Rect *perso,SDL_Rect bloc)
{
    if(perso->x + perso->w > bloc.x && perso->x < bloc.x + bloc.w && perso->y + perso->h > bloc.y && perso->y < bloc.y + bloc.h)
    {
        printf("collision detected\n");
        return 1;
    }

    else
    {
        printf("no collision detected\n");
        return 0;
    }
}

void gravity(SDL_Rect *perso, SDL_Rect bloc, int direction)
{
    if(collisionBB(perso,bloc)!=1)
    {
        //printf("famma gravity\n");
        perso->y=perso->y+40;
    }
}


void animperso (int *i ,Perso *p)
{
 char ch[20];
    
   (*i)++;
   if(*i>2)*i=1;
   sprintf(ch,"b%d.png",*i);
   p->sprite = IMG_Load(ch);
                
}

void animpersoleft (int *i ,Perso *p)
{
 char ch[20];
    
   (*i)++;
   if(*i>2)*i=1;
   sprintf(ch,"c%d.png",*i);
   p->sprite = IMG_Load(ch);
                
}

void animpersojump(int *i ,Perso *p)
{
   p->sprite = IMG_Load("d1.png");
   
}



