#include "perso.h"
#include "camera.h"
#include "collision_parfaite.h"
#include "fonctions.h"
#include "gestiontemp.h"
#include "SDL_rotozoom.h"
#include "entity.h"
#include "enigme.h"
#include "en.h"

#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{

    SDL_Surface *Screen;
    SDL_Event Event;
	srand(time(NULL));
    SDL_Rect player, ground,posMarioRel;
    Perso map,p;
    int loop=1, direction=0,i=0;

    SDL_Init(SDL_INIT_AUDIO||SDL_INIT_VIDEO||SDL_INIT_TIMER);
    //Screen=SDL_SetVideoMode(1200,901,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
//6394
int right=0,left=0,up=0,down=0;
    p.sprite = IMG_Load("b1.png");
    player.x=32;
    player.y=200;
player.w=100;
player.h=100;
    ground.x=0;
    ground.y=730;
    ground.w=6394;
    ground.h=901;
   
 
    posMarioRel.x = -50;
    posMarioRel.y = 0;
printf("1:mode normal\n2:partage d'écran\nChoix:");
  int partage;scanf("%d",&partage);
    Init_Map(&map);
    
    Screen=SDL_SetVideoMode(1000,650, 32,SDL_HWSURFACE| SDL_DOUBLEBUF);
    SDL_WM_SetCaption("GODS' RETURN",NULL);
//code louta nahih ml commentaire  
  /*int hero_choice_left = choix_hero(Screen);
	SDL_Delay(50);
    int hero_choice_right = choix_hero(Screen);
*/
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    Mix_Music *musique=NULL;
    musique=Mix_LoadMUS("music.mp3");
    Mix_PlayMusic(musique,-1);
SDL_Color c1,c2;
    camera c,cc;
    init_background(&c);
init_background(&cc);
init_background2(&cc);
	SDL_Rect pos_abs;
	pos_abs.x = player.x ;
	pos_abs.y =590 ;
	pos_abs.w = player.w ;
	pos_abs.h = player.h ;
    collision col;
int colli=1;
    init_col(&col);
minimap  mp;
temps t;
SDL_Surface *x;
init_minimap(&mp);
    char temps[200]="";
char sc[200]="";
    TTF_Init();
    SDL_Color couleurblanche = {255, 255, 255};
    inittemps(&t);
    t.tempsActuel=SDL_GetTicks();
score score;
initscore(&score);
Entity ennemi;
init_Entity(&ennemi);SDL_EnableKeyRepeat(60,60);
score.scorecount+=10*enigme_integration1(Screen);
Screen=SDL_SetVideoMode(1000,650, 32,SDL_HWSURFACE| SDL_DOUBLEBUF);
    do
    {
        //gravity(&player,ground,direction);
                                    
        Draw_MiniMap(map,Screen);
	afficher_background(&c,Screen);
if(partage==2)afficher_background(&cc,Screen);
if(player.x<60)player.x=60;
if(player.x>750)player.x=750;
player.x+=c.camera_scrolling.x;
do{
c1=GetPixel(c.bg_collision,player.x+200,player.y+460);
if(c1.r==255) player.y-=10;}while(c1.r==255);
do{
c1=GetPixel(c.bg_collision,player.x+50,player.y+460);
if(c1.r==255) player.y-=10;}while(c1.r==255);
do{
c1=GetPixel(c.bg_collision,player.x+100,player.y+460);
if(c1.r==255) player.y-=10;}while(c1.r==255);
c1=GetPixel(c.bg_collision,player.x+200,player.y+449);
c2=GetPixel(c.bg_collision,player.x+50,player.y+449);
if(c1.r!=255)if(c2.r!=255)player.y+=10;
player.x-=c.camera_scrolling.x;
	position_wind(&c,player);
blit_minimap(&mp,Screen);updatetemps(&t);
affichage_temps(&t,temps);blitTemps(&t,Screen);
afficher_ennemi(Screen,ennemi,x);
 affichage_score(&score,sc);blitscore(&score,Screen);
dep_mini_hero (&player,&mp ,c.camera_scrolling,20,1,20);
annimation(&ennemi);
movment(&ennemi,player);//printf("%d\n",collisionBBe(&ennemi,&player));

deplacerIA(&ennemi,player);
if(c.camera_scrolling.x>3950)
if(colli)
{
score.scorecount+=10*enigme_final2(Screen);colli=0;
Screen=SDL_SetVideoMode(1000,650, 32,SDL_HWSURFACE| SDL_DOUBLEBUF);}
	change_bird_image(&c);if(partage==2)change_bird_image(&cc);
	mouvement_bird(&c);if(partage==2)mouvement_bird2(&cc);
        SDL_BlitSurface(p.sprite,NULL,Screen,&player);
        SDL_Flip(Screen);
       up=0;down=0;right=0;left=0;
        while (SDL_PollEvent(&Event))
        {
            switch (Event.type)
            {
                case SDL_QUIT:
                    loop=0;
                    break;
                case SDL_KEYDOWN:
                    switch (Event.key.keysym.sym)
                    {
                    case SDLK_z:
                        direction=1;
up=1;
                         posMarioRel.x=posMarioRel.x+10;

			    if(posMarioRel.x<50)
			    {
				posMarioRel.x=50;
			    }
                             
                             player.y = 500;//1100-(p.sprite->h);
                             posMarioRel.y=(-0.04*(posMarioRel.x*posMarioRel.x)+500);

			    //On calcule maintenant les valeurs 
			    player.x = player.x + posMarioRel.x+30;
			    player.y = player.y - posMarioRel.y;
                            
                            animpersojump(&i ,&p);

			   //Intervalle de 10ms
			   //SDL_Delay(10);
			   SDL_Flip(Screen);
                        break;

                        case SDLK_d:
                  right=1;c.sens=0;scrolling (&c);
                            direction=3;
                            player.x+=20;
                            animperso(&i,&p);
                            SDL_Flip(Screen);                          
                        break;

                        case SDLK_q:
left=1;c.sens=1;scrolling (&c);
                            direction=4;
                            player.x-=20;
                            animpersoleft(&i ,&p);
                            SDL_Flip(Screen);
                            break;
                    }
                break;
            }
        }
        
        
    } while (loop!=0);
        SDL_FreeSurface(Screen);
        SDL_FreeSurface(map.img);
        SDL_FreeSurface(p.sprite);
free_minimap(&mp);
free_temps(&t);
    return 0;
}
