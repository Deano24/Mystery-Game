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

void point::show_images()
{
    SDL_FreeSurface(welcome_message);
    welcome_message = TTF_RenderText_Solid(sketch_2,"This is the point allocation page",textColor);
    apply_surface_cal(80,2,welcome_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"You are being awarded 15 points please allocate them.",textColor_r);
    apply_surface_cal(10,50,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"You have 3 ares: Breaking and Entering, Interrogation and",textColor_r);
    apply_surface_cal(10,100,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Intuition. Go to your office once you are finished.",textColor_r);
    apply_surface_cal(50,120,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Breaking and Entering: The higher the skill level the better the",textColor_r);
    apply_surface_cal(10,160,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"chance of success for breaking into someones residence.",textColor_r);
    apply_surface_cal(50,180,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Interrogation: The higher the skill the more questions you can",textColor_r);
    apply_surface_cal(10,220,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"ask a suspect/individual.",textColor_r);
    apply_surface_cal(50,240,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Intution: The higher the skill the more chance you will have to",textColor_r);
    apply_surface_cal(10,280,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"sense if something is not right.",textColor_r);
    apply_surface_cal(50,300,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Breaking and Entering",textColor_r);
    apply_surface_cal(10,340,name_message,screen);
    apply_surface_cal(300,340,pluss,screen);
    apply_surface_cal(330,340,minuss,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Interrogation",textColor_r);
    apply_surface_cal(10,380,name_message,screen);
    apply_surface_cal(300,380,pluss,screen);
    apply_surface_cal(330,380,minuss,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Intuition",textColor_r);
    apply_surface_cal(10,420,name_message,screen);
    apply_surface_cal(300,420,pluss,screen);
    apply_surface_cal(330,420,minuss,screen);
    apply_surface_cal(420,420,office_b,screen);
    SDL_Flip(screen);
}
