/**
* @file entity.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/
#include"entity.h"
/**
* @brief To initialize the entity .
* @param ennemi enemy 
* @return Nothing
*/
void init_Entity(Entity *ennemi)
{
    //init spritesheet :

    ennemi->Spritesheet=IMG_Load("ennemi transparent-02.png");
    

    //initialisation de la position de l'ennemi : 

    ennemi->position.x=400;
    ennemi->position.y=350;
    ennemi->position.w=172;
    ennemi->position.h=183;

    //animation position :

    ennemi->animation.x=0;
    ennemi->animation.y=0;
    ennemi->animation.w=172;
    ennemi->animation.h=183;

    //init ennemi direction :

    ennemi->direction=1;     
}

/**
* @brief To existance collision
* @param SDL_Rect
* @param ennemi
* @return 1 ou 0
*/
int collisionBBe(Entity *ennemi, SDL_Rect *hero)
{
    if(ennemi->position.x+ennemi->position.w > hero->x && ennemi->position.x < hero->x+hero->w && ennemi->position.y+ennemi->position.h > hero->y && ennemi->position.y < hero->y+hero->h)
        return 1;
    else
        return 0;
}
/**
* @brief To deplacer ennemi
* @param SDL_Rect p
* @param ennemi
* @return Nothing
*/
void movment(Entity *ennemie,SDL_Rect p)
{
    if(ennemie->direction == 1)
    {
        ennemie->position.x +=10;
        if(ennemie->position.x + ennemie->position.w > 1200)
            ennemie->direction=0;
    }

    if(ennemie->direction==0)
    {
       ennemie->position.x-=10;
        if (ennemie->position.x <400 && p.x<100)
            ennemie->direction=1;
        
    }
}
/**
* @brief To afficher ennemi
* @param screen
* @param ennemi
* @param backg
* @return Nothing
*/
void afficher_ennemi(SDL_Surface *Screen, Entity ennemi,SDL_Surface *backg)
{
   SDL_BlitSurface(ennemi.Spritesheet,&ennemi.animation,Screen,&ennemi.position);
}
/**
* @brief To animer ennemi
* @param ennemi
* @return Nothing
*/
void annimation( Entity *ennemi)
{
        if(ennemi->direction==1)
        {
            ennemi->animation.y=0;
            ennemi->animation.x+=172;
            if(ennemi->animation.x>860)
                ennemi->animation.x=0;
        }

        if(ennemi->direction==0)    
        {
            ennemi->animation.y=183;
            ennemi->animation.x+=172;
            if(ennemi->animation.x>860)
                ennemi->animation.x=0;
        }
        
    
}
/**
* @brief To following player
* @param ennemi
* @param SDL_Rect
* @return Nothing
*/
void deplacerIA(Entity *e,SDL_Rect p)
{
	if (p.x<e->position.x) //hero à gauche de l'ennemi
	{
		e->direction=0;
		movment(e,p);
	}

	if (p.x>e->position.x) // hero a droite
	{
		e->direction=1;
		movment(e,p);
	}
}






//
