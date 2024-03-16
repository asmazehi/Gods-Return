#include "camera.h"
#include "collision_parfaite.h"


void init_background( camera* c)
{
    c->bg_collision = IMG_Load("bg_col.png");
    c->bg_lvl1 = IMG_Load("bg_level1.png");
    c->pos_bg.x=0;
    c->pos_bg.y=0;
    c->camera_scrolling.x = 0;
    c->camera_scrolling.y = 150;
    c->camera_scrolling.w = 1000;
    c->camera_scrolling.h = 650;
    c->sens = 2;
    c->sensy = 2;


    c->bird = IMG_Load("anim1.png");
    c->pos_bird.x=-50;
    c->pos_bird.y=30;
    c->frame_bird = 1;

    c->wind = IMG_Load("wind.png");
    c->pos_wind.x=123;
    c->pos_wind.y=450;
}
void init_background2( camera* c)
{
    c->pos_bg.x=500;
}
void position_wind(camera* c, SDL_Rect pos_perso){

    c->pos_wind.x=pos_perso.x;
    c->pos_wind.y=pos_perso.y+200;

}

void change_bird_image( camera* c){

	c->frame_bird++;

	if ( c->frame_bird > 12 ){
		c->frame_bird = 1;
	}


	if ( c->frame_bird == 1 ){
	    	c->bird = IMG_Load("anim1.png");
	}else if ( c->frame_bird == 2 ){
	    	c->bird = IMG_Load("anim2.png");
	}else if ( c->frame_bird == 3 ){
		c->bird = IMG_Load("anim3.png");
	}else if ( c->frame_bird == 4 ){
		c->bird = IMG_Load("anim4.png");
	}else if ( c->frame_bird == 5 ){
		c->bird = IMG_Load("anim5.png");
	}else if ( c->frame_bird == 6 ){
		c->bird = IMG_Load("anim6.png");
	}else if ( c->frame_bird == 7 ){
		c->bird = IMG_Load("anim7.png");
	}else if ( c->frame_bird == 8 ){
		c->bird = IMG_Load("anim8.png");
	}else if ( c->frame_bird == 9 ){
		c->bird = IMG_Load("anim9.png");
	}else if ( c->frame_bird == 10 ){
		c->bird = IMG_Load("anim10.png");
	}else if ( c->frame_bird == 11 ){
		c->bird = IMG_Load("anim11.png");
	}else if ( c->frame_bird == 12 ){
		c->bird = IMG_Load("anim12.png");
	}
}


void mouvement_bird(camera* c){


	if ( c->pos_bird.x < 1000 ){
		c->pos_bird.x+=20;
	}else{
		c->pos_bird.x = -50;
	}

}


void afficher_background( camera* c, SDL_Surface* screen)
{

    SDL_BlitSurface(c->bg_lvl1, &c->camera_scrolling, screen, &c->pos_bg );
    	SDL_BlitSurface(c->wind,NULL, screen, &c->pos_wind );
    SDL_BlitSurface(c->bird,NULL, screen, &c->pos_bird );
    //if ( c->sens != 2 || c->sensy != 2 )

}

void scrolling ( camera* c)
{
    if ( c->sens == 0 ) // scrolling ymin
    {
        if ( c->camera_scrolling.x < 5000 - 1000 ) // camera_scrolling.x = 4998
        {
            c->camera_scrolling.x +=10; // camera_scrolling.x = 5008
            if ( c->camera_scrolling.x > 3990 )
            {
    		c->bg_lvl1 = IMG_Load("bg_level1_open.png");
                c->camera_scrolling.x =4000; // rajaany lel 5000
            }
        }
    }
    if ( c->sens == 1 ) // scrolling ysar
    {
        if ( c->camera_scrolling.x > 0 ) // camera_scrolling.x = 6
        {
            c->camera_scrolling.x -=10; // camera_scrolling.x = -4
            if ( c->camera_scrolling.x < 0 )
            {
                c->camera_scrolling.x =0; // rajaaheli lel 0
            }
        }
    }
}

void mouvement_bird2(camera* c){


	if ( c->pos_bird.x < 900 ){
		c->pos_bird.x+=20;
	}else{
		c->pos_bird.x = 500;
	}

}
void vertical_scrolling ( camera* c)
{
    
    if ( c->sensy == 0 ) // scrolling fou
    {
        if ( c->camera_scrolling.y > 0 ) // camera_scrolling.x = 6
        {
            c->camera_scrolling.y -=10; // camera_scrolling.x = -4
            if ( c->camera_scrolling.y < 0 )
            {
                c->camera_scrolling.y =0; // rajaaheli lel 0
            }
        }
    }
    if ( c->sensy == 1 ) // scrolling louta
    {
        if ( c->camera_scrolling.y < 150 ) // camera_scrolling.x = 6
        {
            c->camera_scrolling.y +=10; // camera_scrolling.x = -4
            if ( c->camera_scrolling.y > 150 )
            {
                c->camera_scrolling.y =150; // rajaaheli lel 0
            }
        }
    }
}


void free_bg( camera* c)
{
    SDL_FreeSurface(c->bg_lvl1);
    SDL_FreeSurface(c->bg_collision);
    SDL_FreeSurface(c->bird);
    SDL_FreeSurface(c->wind);
	
}



void resultat_collision(SDL_Rect* pos_abs, SDL_Rect* pos_perso, camera* c ,int left, int right,int up,int down, collision* col)
{
    if ( left == 1 )
    {
        if( !(col->color4.r==255  &&  col->color4.g==0 &&  col->color4.b==0) && !(col->color5.r==255  &&  col->color5.g==0 &&  col->color5.b==0) || !(col->color6.r==255  &&  col->color6.g==0 &&  col->color6.b==0) && !(col->color5.r==255  &&  col->color5.g==0 &&  col->color5.b==0) )
        {
            scrolling (c);
	    pos_abs->x -=10;
        }
    }
     if ( right == 1 )
    {
        if( !(col->color1.r==255  &&  col->color1.g==0 &&  col->color1.b==0) && !(col->color2.r==255  &&  col->color2.g==0 &&  col->color2.b==0) || !(col->color3.r==255  &&  col->color3.g==0 &&  col->color3.b==0) && !(col->color2.r==255  &&  col->color2.g==0 &&  col->color2.b==0) )
        {
            scrolling (c);
	    pos_abs->x +=10;
        }
    }
     if ( up == 1 )
    {
        if( (col->color7.r==255  &&  col->color7.g==0 &&  col->color7.b==0) && (col->color4.r==255  &&  col->color4.g==0 &&  col->color4.b==0) || (col->color1.r==255  &&  col->color1.g==0 &&  col->color1.b==0) && (col->color7.r==255  &&  col->color7.g==0 &&  col->color7.b==0) )
        {
            pos_perso->y +=10;
        }else{
	vertical_scrolling(c);
		if ( pos_perso->y > 10 )
			pos_abs->y -=20;
	}
    }
     if ( down == 1 )
    {
        if( (col->color8.r==255  && col->color8.g==0 &&  col->color8.b==0) && (col->color6.r==255  &&  col->color6.g==0 &&  col->color6.b==0) || (col->color3.r==255  &&  col->color3.g==0 &&  col->color3.b==0) && (col->color8.r==255  &&  col->color8.g==0 &&  col->color8.b==0) )
        {
            	pos_perso->y -=10;
        }else{
	vertical_scrolling(c);
		if ( pos_abs->y < 600 )
			pos_abs->y +=20;
	}
    }

}
int choix_hero(SDL_Surface* screen)
{

	SDL_Surface* choice = IMG_Load("choose_hero.png");
	SDL_Rect pos_choice;
	pos_choice.x =0;
	pos_choice.y = 0;

	
   SDL_Event event;
    int continuer=1;
 while(continuer == 1)
    {
        
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;

            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE://pour quitter
                continuer=0;
		return 1;
                break;
           
            }
        break;

	case SDL_MOUSEBUTTONDOWN:
        {
            switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:
            {
               
		if ( event.button.x>50 && event.button.x<150 && event.button.y>140 && event.button.y<340)//left
                {
                    return 2;
                }
		if ( event.button.x>250 && event.button.x<450 && event.button.y>140 && event.button.y<340)//right
                {
                    return 1;
                }

            }
            break; 
            }
        }
        break;


        }// taskiret switch event


	SDL_BlitSurface(choice,NULL,screen,&pos_choice);
        SDL_Flip(screen);
    }
	SDL_FreeSurface(choice);

}

