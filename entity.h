#ifndef ENTITY_H
#define ENTIT_H
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<stdio.h>
#include<stdlib.h>
#include "perso.h"
/**
* @struct Entity
* @brief struct for entity
*/
typedef struct
{
    SDL_Surface *Spritesheet;
    SDL_Rect animation,position;
    int direction;
    float timeFrame,curentTime,PrevTime,deltaT;
}Entity;

void init_Entity(Entity *ennemi);
void afficher_ennemi(SDL_Surface *Screen, Entity ennemi,SDL_Surface *backg);
int collisionBBe(Entity *ennemi, SDL_Rect *hero);
void movment(Entity *ennemie,SDL_Rect p);
void annimation( Entity *ennemi);
void deplacerIA(Entity *e,SDL_Rect p);
#endif 
