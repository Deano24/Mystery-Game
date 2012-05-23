#include "Salon_questioning.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include <sqlite3.h>
#include "Time_show.h"
#include "load.h"
#include "text_colors.h"

bool husband;

void apply_surface_salon( int x, int y, SDL_Surface* source, SDL_Surface* destination,SDL_Rect* clip = NULL)
{
    //Holds offsets
    SDL_Rect offset;


    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool question_1_2_3()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    Time_show show_time;
    name_message = TTF_RenderText_Solid(comic,"Detective: What can you tell me about her?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Manager: She is a hard working person, good stylist and a flirt",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while (quit == false)
    {
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }
    return quit;
}

bool question_1_2()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    Time_show show_time;
    name_message = TTF_RenderText_Solid(comic,"Detective: Where can I find her husband?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Manager: Uhm last I heard he had a place off greens boulevard,",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"180 greens boulevard",textColor_r);
    apply_surface_salon(20,50,name_message,screen);
    SDL_Flip(screen);

    husband = true;

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"What can you tell me about her?",textColor_r);
    apply_surface_salon(10,210,name_message,screen);
    apply_surface_salon(290,210,select_button,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while (quit == false)
    {
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;


                    if((x>290)&&(x<290+91)&&(y>210)&&(y<210+23))
                    {
                        quit = question_1_2_3();
                    }

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }
    return quit;
}

bool question_1_3_2()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    Time_show show_time;
    name_message = TTF_RenderText_Solid(comic,"Detective: Where can I find her husband?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Manager: Uhm last I heard he had a place off greens boulevard,",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"180 greens boulevard",textColor_r);
    apply_surface_salon(20,50,name_message,screen);
    SDL_Flip(screen);

    husband = true;

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while (quit == false)
    {
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }
    return quit;
}

bool question_1_3()
{
     bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    Time_show show_time;
    name_message = TTF_RenderText_Solid(comic,"Detective: What can you tell me about her?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Manager: She is a hard working person, good stylist and a flirt",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"What can you tell me about her?",textColor_r);
    apply_surface_salon(10,180,name_message,screen);
    apply_surface_salon(290,180,select_button,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while (quit == false)
    {
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;


                    if((x>290)&&(x<290+91)&&(y>180)&&(y<180+23))
                    {
                        quit = question_1_3_2();
                    }

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }
    return quit;
}


bool question_1()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    Time_show show_time;
    name_message = TTF_RenderText_Solid(comic,"Detective: When was the last time you saw her?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Manager: I think a couple of days ago, it was the last time she came to work",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Where can i find her husband?",textColor_r);
    apply_surface_salon(10,180,name_message,screen);
    apply_surface_salon(290,180,select_button,screen);
    name_message = TTF_RenderText_Solid(comic,"What can you tell me about her?",textColor_r);
    apply_surface_salon(10,210,name_message,screen);
    apply_surface_salon(290,210,select_button,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while (quit == false)
    {
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;


                    if((x>290)&&(x<290+91)&&(y>180)&&(y<180+23))
                    {
                        quit = question_1_2();
                    }

                    if((x>290)&&(x<290+91)&&(y>210)&&(y<210+23))
                    {
                        quit = question_1_3();
                    }

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }
    return quit;
}


bool question_2_1_3()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    SDL_Flip(screen);

    Time_show show_time;

    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"What can you tell me about her?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);
    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Manager: She is a hard working person, good stylist and a flirt",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type==SDL_QUIT)
           {
               quit=true;
           }
        }
    }
    return quit;
}


bool question_2_1()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    SDL_Flip(screen);

    Time_show show_time;

    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"When was the last time you saw her?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);
    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Manager: I think a couple of days ago, it was the last time she came to work",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(700);
    name_message = TTF_RenderText_Solid(comic,"What can you tell me about her?",textColor_r);
    apply_surface_salon(10,210,name_message,screen);
    apply_surface_salon(290,210,select_button,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>290)&&(x<290+91)&&(y>210)&&(y<210+23))
                    {
                        quit = question_2_1_3();
                    }

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type==SDL_QUIT)
           {
               quit=true;
           }
        }
    }
    return quit;
}

bool question_2_3_1()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    SDL_Flip(screen);

    Time_show show_time;

    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"When was the last time you saw her?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);
    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Manager: I think a couple of days ago, it was the last time she came to work",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type==SDL_QUIT)
           {
               quit=true;
           }
        }
    }
    return quit;
}

bool question_2_3()
{
     bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    SDL_Flip(screen);

    Time_show show_time;

    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"What can you tell me about her?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);
    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Manager: She is a hard working person, good stylist and a flirt",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(700);

    name_message = TTF_RenderText_Solid(comic,"When was the last time you saw her?",textColor_r);
    apply_surface_salon(10,150,name_message,screen);
    apply_surface_salon(290,150,select_button,screen);
    SDL_Flip(screen);

    SDL_Delay(600);

    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>290)&&(x<290+91)&&(y>150)&&(y<150+23))
                    {
                        quit = question_2_3_1();
                    }

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type==SDL_QUIT)
           {
               quit=true;
           }
        }
    }
    return quit;
}

bool question_2()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    SDL_Flip(screen);

    Time_show show_time;

    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Where can i find her husband?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);
    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Manager: Uhm last I heard he had a place off greens boulevard,",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"180 greens boulevard",textColor_r);
    apply_surface_salon(20,60,name_message,screen);
    SDL_Flip(screen);

    husband = true;

    SDL_Delay(700);

    name_message = TTF_RenderText_Solid(comic,"When was the last time you saw her?",textColor_r);
    apply_surface_salon(10,150,name_message,screen);
    apply_surface_salon(290,150,select_button,screen);
    name_message = TTF_RenderText_Solid(comic,"What can you tell me about her?",textColor_r);
    apply_surface_salon(10,210,name_message,screen);
    apply_surface_salon(290,210,select_button,screen);
    SDL_Flip(screen);

    SDL_Delay(600);

    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>290)&&(x<290+91)&&(y>150)&&(y<150+23))
                    {
                        quit = question_2_1();
                    }


                    if((x>290)&&(x<290+91)&&(y>210)&&(y<210+23))
                    {
                        quit = question_2_3();
                    }

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type==SDL_QUIT)
           {
               quit=true;
           }
        }
    }
    return quit;
}


bool question_3_1_2()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    SDL_Flip(screen);

    Time_show show_time;

    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Where can i find her husband?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);
    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Manager: Uhm last I heard he had a place off greens boulevard,",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"180 greens boulevard",textColor_r);
    apply_surface_salon(20,60,name_message,screen);
    SDL_Flip(screen);

    husband = true;

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type==SDL_QUIT)
           {
               quit=true;
           }
        }
    }
    return quit;
}

bool question_3_1()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    SDL_Flip(screen);

    Time_show show_time;

    SDL_Delay(800);
    name_message = TTF_RenderText_Solid(comic,"When was the last time you saw her?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);
    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Manager: I think a couple of days ago, it was the last time she came to work",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(700);
    name_message = TTF_RenderText_Solid(comic,"Where can i find her husband?",textColor_r);
    apply_surface_salon(10,180,name_message,screen);
    apply_surface_salon(290,180,select_button,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>290)&&(x<290+91)&&(y>180)&&(y<180+23))
                    {
                        quit = question_3_1_2();
                    }

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type==SDL_QUIT)
           {
               quit=true;
           }
        }
    }
    return quit;
}

bool question_3_2_1()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    SDL_Flip(screen);

    Time_show show_time;

    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"When was the last time you saw her?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);
    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Manager: I think a couple of days ago, it was the last time she came to work",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type==SDL_QUIT)
           {
               quit=true;
           }
        }
    }
    return quit;
}

bool question_3_2()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    SDL_Flip(screen);

    Time_show show_time;

    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Where can i find her husband?",textColor_r);
    apply_surface_salon(10,20,name_message,screen);
    SDL_Flip(screen);
    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Manager: Uhm last I heard he had a place off greens boulevard,",textColor_r);
    apply_surface_salon(10,40,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"180 greens boulevard",textColor_r);
    apply_surface_salon(20,60,name_message,screen);
    SDL_Flip(screen);

    husband = true;

    SDL_Delay(700);
    name_message = TTF_RenderText_Solid(comic,"When was the last time you saw her?",textColor_r);
    apply_surface_salon(10,150,name_message,screen);
    apply_surface_salon(290,150,select_button,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>290)&&(x<290+91)&&(y>150)&&(y<150+23))
                    {
                        quit = question_3_2_1();
                    }

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type==SDL_QUIT)
           {
               quit=true;
           }
        }
    }
    return quit;
}

bool question_3()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    SDL_Flip(screen);

    Time_show show_time;

    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"What can you tell me about her?",textColor_r);
    apply_surface_salon(10,50,name_message,screen);
    SDL_Flip(screen);
    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Manager: She is a hard working person, good stylist and a flirt",textColor_r);
    apply_surface_salon(10,70,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(700);

    name_message = TTF_RenderText_Solid(comic,"When was the last time you saw her?",textColor_r);
    apply_surface_salon(10,150,name_message,screen);
    apply_surface_salon(290,150,select_button,screen);
    name_message = TTF_RenderText_Solid(comic,"Where can i find her husband?",textColor_r);
    apply_surface_salon(10,180,name_message,screen);
    apply_surface_salon(290,180,select_button,screen);
    SDL_Flip(screen);

    SDL_Delay(600);
    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>290)&&(x<290+91)&&(y>150)&&(y<150+23))
                    {
                        quit = question_3_1();
                    }

                    if((x>290)&&(x<290+91)&&(y>180)&&(y<180+23))
                    {
                        quit = question_3_2();
                    }

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type==SDL_QUIT)
           {
               quit=true;
           }
        }
    }
    return quit;
}


Salon_questioning::Salon_questioning()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface_salon(0,0,hair_salon,screen);
    SDL_Flip(screen);

    Time_show show_time;

    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Good Day Sir how may I help you",textColor_r);
    apply_surface_salon(10,50,name_message,screen);
    SDL_Flip(screen);
    SDL_Delay(800);

    name_message = TTF_RenderText_Solid(comic,"Good Day, I am investigating the murder of Mrs. Smith and would like to ask you",textColor_r);
    apply_surface_salon(10,70,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"a few questions.",textColor_r);
    apply_surface_salon(20,85,name_message,screen);
    SDL_Flip(screen);

    SDL_Delay(700);

    name_message = TTF_RenderText_Solid(comic,"When was the last time you saw her?",textColor_r);
    apply_surface_salon(10,150,name_message,screen);
    apply_surface_salon(290,150,select_button,screen);
    name_message = TTF_RenderText_Solid(comic,"Where can i find her husband?",textColor_r);
    apply_surface_salon(10,180,name_message,screen);
    apply_surface_salon(290,180,select_button,screen);
    name_message = TTF_RenderText_Solid(comic,"What can you tell me about her?",textColor_r);
    apply_surface_salon(10,210,name_message,screen);
    apply_surface_salon(290,210,select_button,screen);
    SDL_Flip(screen);

    SDL_Delay(600);

    name_message = TTF_RenderText_Solid(comic,"Leave",textColor_r);
    apply_surface_salon(400,400,name_message,screen);
    SDL_Flip(screen);

    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>290)&&(x<290+91)&&(y>150)&&(y<150+23))
                    {
                        quit = question_1();
                    }

                    if((x>290)&&(x<290+91)&&(y>180)&&(y<180+23))
                    {
                        quit = question_2();
                    }

                    if((x>290)&&(x<290+91)&&(y>210)&&(y<210+23))
                    {
                        quit = question_3();
                    }

                    if((x>400)&&(x<400+40)&&(y>400)&&(y<400+24))
                    {
                       quit = true;
                    }
                }
            }
            if(event.type==SDL_QUIT)
           {
               quit=true;
           }
        }
    }
}
