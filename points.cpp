#include "points.h"
#include "load.h"
#include<string>
#include<sstream>

skill skill_set;


void apply_surface_cal( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

void point::points_b_m()
{
    temp <<skill_set.bande;

     skill_set.bande--;
     if(skill_set.bande<0)
     {
         skill_set.bande=0;
     }
     strm_bande<<skill_set.bande;
     break_ent = TTF_RenderText_Solid (juice_b,strm_bande.str().c_str(),textColor_r);
     strm_bande.str("");
     apply_surface_cal(280,340,break_ent,screen);
}

void point::points_i_m()
{
    skill_set.intuition--;
    if(skill_set.intuition<0)
    {
        skill_set.intuition=0;
    }
    strm_intuition<<skill_set.intuition;
    intuition = TTF_RenderText_Solid (juice_b,strm_intuition.str().c_str(),textColor_r);
    strm_intuition.str("");
    apply_surface_cal(280,420,intuition,screen);
}


void point::points_int_m()
{
    skill_set.interrogation--;
    if(skill_set.interrogation<0)
    {
        skill_set.interrogation=0;
    }
    strm_interrogation<<skill_set.interrogation;
    interrogation = TTF_RenderText_Solid (juice_b,strm_interrogation.str().c_str(),textColor_r);
    strm_interrogation.str("");
    apply_surface_cal(280,380,interrogation,screen);
}

void point::points_b_p()
{

    skill_set.bande++;
    strm_bande<<skill_set.bande;
    break_ent = TTF_RenderText_Solid (juice_b,strm_bande.str().c_str(),textColor_r);
    strm_bande.str("");
    apply_surface_cal(280,340,break_ent,screen);
}

void point::points_i_p()
{
    skill_set.intuition++;
    strm_intuition<<skill_set.intuition;
    intuition = TTF_RenderText_Solid (juice_b,strm_intuition.str().c_str(),textColor_r);
    strm_intuition.str("");
    apply_surface_cal(280,420,intuition,screen);
}


void point::points_int_p()
{
    skill_set.interrogation++;
    strm_interrogation<<skill_set.interrogation;
    interrogation = TTF_RenderText_Solid (juice_b,strm_interrogation.str().c_str(),textColor_r);
    strm_interrogation.str("");
    apply_surface_cal(280,380,interrogation,screen);
}

void point::show_bande()
{
    apply_surface_cal(280,380,interrogation,screen);
    apply_surface_cal(280,420,intuition,screen);

}

void point::show_interrogation()
{
    apply_surface_cal(280,420,intuition,screen);
    apply_surface_cal(280,340,break_ent,screen);

}

void point::show_intuition()
{
    apply_surface_cal(280,380,interrogation,screen);
    apply_surface_cal(280,340,break_ent,screen);

}
