#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "collision_parfaite.h"

struct camera
{
	SDL_Surface* bg_lvl1;
	SDL_Surface* bg_collision;
	SDL_Rect pos_bg;
	SDL_Rect camera_scrolling;
	int sens,sensy;

	SDL_Surface* wind;
	SDL_Rect pos_wind;

	SDL_Surface* bird;
	SDL_Rect pos_bird;
	int frame_bird;
};
typedef struct camera camera; 

void init_background( camera* c);
void afficher_background( camera* c, SDL_Surface* screen);
void scrolling ( camera* c);
void free_bg( camera* c);
void position_wind(camera* c, SDL_Rect pos_perso);
void mouvement_bird(camera* c);
void change_bird_image( camera* c);
void init_background2( camera* c);
void mouvement_bird2(camera* c);
void resultat_collision(SDL_Rect* pos_abs, SDL_Rect* pos_perso, camera* c ,int left, int right,int up,int down, collision* col);
void vertical_scrolling ( camera* c);
int choix_hero(SDL_Surface* screen);
#endif // HERO_H_INCLUDED
