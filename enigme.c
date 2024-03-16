/**
* @file enigme.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for enigme image
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "enigme.h"
/**
* @brief to give a random int  .
* @param nomfichier le nom de fichier
* @return Nothing
*/
int random_enigme(char *nomfichier)
{
    srand(time(NULL));
    return (rand() % 4);
}

void initEnigme(enigme *e, char *nomfichier)
{   
    e->num_question = random_enigme(nomfichier);

    

    e->won= IMG_Load("You-win.png");
    e->lost= IMG_Load("wrong.png");
    char path[150];
    int numquestion;
    e->rep_joueur = -1;
	FILE *f = NULL;
    f = fopen(nomfichier, "r");int ff;
    if (f != NULL)
    {
        do
        {
            ff=fscanf(f, "%d %s %d\n", &numquestion, path, &e->rep_vrai);
        } while ((numquestion != e->num_question) && (ff != EOF));
    }
    fclose(f);
 e->background = IMG_Load(path);

    e->pos_back.x = 0;
    e->pos_back.y = 0;

    e->pos_wonlose.x = 0;
    e->pos_wonlose.y = 0;

    e->pos_clock.x=0;
    e->pos_clock.y=0;
    e->frame=1;
    e->clock=IMG_Load("Clock1.png");
    e->lastTime=0;

}
void afficherEnigme(enigme *e, SDL_Surface *s)
{
    SDL_BlitSurface(e->background, NULL, s, &e->pos_back);
    SDL_BlitSurface(e->clock,NULL,s,&e->pos_clock);
}

void animer (enigme *e){
	e->currentTime = SDL_GetTicks();
	if (e->currentTime > e->lastTime +1000) {
		char path[50];
		sprintf(path,"Clock%d.png",e->frame);
SDL_FreeSurface(e->clock);
		e->clock=IMG_Load(path);
		//printf("%s\n",path);
		e->frame++;
		if(e->frame==5){
		e->frame=1;}		
    		e->lastTime = e->currentTime;
  	}}
int enigme_integration1(SDL_Surface *ecran){
SDL_Event event;
    ecran = SDL_SetVideoMode(600, 900, 32, SDL_HWSURFACE);
    int continuer = 1;
    enigme eng;
    char nomfichier[200] = "enigmefile";
    
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",Mix_GetError());
	}
     Mix_Chunk * son;
     son= Mix_LoadWAV("Jackpot Sound Effect HD.wav");
     Mix_Chunk * son1;
     son1= Mix_LoadWAV("Buzzer Wrong Answer - Gaming Sound Effect (HD).wav");

    initEnigme(&eng, nomfichier);
    
    while (continuer)
    {
	animer(&eng);
        afficherEnigme(&eng, ecran);
      
         SDL_PollEvent(&event);
          SDL_GetMouseState(&(eng.x), &(eng.y));
         switch (event.type)
    {
    case SDL_QUIT:
        continuer = 0;
            break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_a:
           eng.rep_joueur = 1;
            break;
        case SDLK_b:
           eng.rep_joueur = 2;
            break;
        case SDLK_c:
           eng.rep_joueur = 3;
            break;
        }
    case SDL_MOUSEBUTTONUP:
	
	if(event.motion.x>=131 && event.motion.x<=131+148 && event.motion.y>=278 && event.motion.y<=278+147)
	{
	   eng.rep_joueur = 1;
	}

        else if(event.motion.x>=131 && event.motion.x<=133+152 && event.motion.y>=460 && event.motion.y<=460+152)
	{
	   eng.rep_joueur = 2;
	}
	
        else if(event.motion.x>=131 && event.motion.x<=133+156 && event.motion.y>=655 && event.motion.y<=655+144)
	{
	   eng.rep_joueur = 3;
	}
	
	//cas enigme 4
	if(event.motion.x>=194 && event.motion.x<=194+65 && event.motion.y>=43 && event.motion.y<=43+37)
	{
	   eng.rep_joueur = 1;
	}

        else if(event.motion.x>=236 && event.motion.x<=236+51 && event.motion.y>=85 && event.motion.y<=85+72)
	{
	   eng.rep_joueur = 2;
	}
	
        else if(event.motion.x>=343 && event.motion.x<=343+54 && event.motion.y>=86 && event.motion.y<=86+71)
	{
	   eng.rep_joueur = 3;
	}

        break;
    }
    
      if (eng.rep_joueur != -1)
     {
        if (eng.rep_joueur == eng.rep_vrai)
        {
            SDL_BlitSurface(eng.won, NULL, ecran, &eng.pos_wonlose);
	    Mix_PlayChannel(-1, son, 0);
            eng.score_enigme = 1;
        }
        else if(eng.rep_joueur != eng.rep_vrai)
        {
            SDL_BlitSurface(eng.lost, NULL, ecran, &eng.pos_wonlose);
	    Mix_PlayChannel(-1, son1, 0);
            eng.score_enigme = 0;
        }
     }SDL_Flip(ecran);        if ((eng.rep_joueur != -1))
        {
            SDL_Delay(2000);
            return eng.score_enigme;
        }
   }
 
        

    Mix_FreeChunk(son);
    Mix_FreeChunk(son1);
    }




