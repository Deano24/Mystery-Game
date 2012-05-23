#include "Victims_house.h"

Victims_house::Victims_house()
{
    //ctor
}

//shows victim kitchen
bool Victims_kitchen()
{
    bool exit = false;
    int x = 0, y = 0;
    Victim_house show_house;

    show_house.show_kitchen();
    Time_show show_time;
    name_message = TTF_RenderText_Solid(comic,"Living Room",textColor);
    apply_surface(400,400,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"Bedroom",textColor);
    apply_surface(300,0,name_message,screen);
    SDL_Flip(screen);

    while(exit==false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button==SDL_BUTTON_LEFT)
                    {
                        x = event.button.x;
                        y = event.button.y;

                        if((x>400)&&(x<400+70)&&(y>400)&&(y<400+50))
                            {
                                exit = true;
                                Victims_living();
                            }

                            if((x>50)&&(x<300+300)&&(y>50)&&(y<100+300))
                            {
                                name_message = TTF_RenderText_Solid(comic,"Look like I found the crime scene",textColor);
                                apply_surface(200,200,name_message,screen);
                                SDL_Flip(screen);

                                SDL_Delay(3000);
                                show_house.show_kitchen();
                                Time_show show_time;
                                name_message = TTF_RenderText_Solid(comic,"Living Room",textColor);
                                apply_surface(400,400,name_message,screen);
                                name_message = TTF_RenderText_Solid(comic,"Bedroom",textColor);
                                apply_surface(300,0,name_message,screen);
                                SDL_Flip(screen);
                            }

                        if((x>300)&&(x<300+70)&&(y>0)&&(y<0+30))
                            {
                                exit = Victims_bedroom();
                            }

                    }
            }
            if(event.type==SDL_QUIT)
           {
               exit=true;
           }
        }
    }
    return exit;
}

//shows victim living room
bool Victims_living()
{
    bool leave = false;
    int x = 0, y = 0;
    Victim_house show_house;

    show_house.show_living();
    Time_show show_time;
    name_message = TTF_RenderText_Solid(comic,"Entrance",textColor);
    apply_surface(400,400,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"Kitchen",textColor);
    apply_surface(20,150,name_message,screen);
    apply_surface(330,180,small_note,screen);
    SDL_Flip(screen);

    while(leave==false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>400)&&(x<400+70)&&(y>400)&&(y<400+30))
                    {
                        leave=true;
                        Victims_house();
                    }

                    if((x>27)&&(x<27+23)&&(y>150)&&(y<150+180))
                    {
                        leave = Victims_kitchen();
                    }

                    if((x>330)&&(x<330+36)&&(y>180)&&(y<180+36))
                    {
                        name_message = TTF_RenderText_Solid(comic,"I love you too much and if I cant have you no one can",textColor_b);
                        apply_surface(100,200,name_message,screen);
                        name_message = TTF_RenderText_Solid(comic,"Sincerely Allimore",textColor_b);
                        apply_surface(100,240,name_message,screen);
                        SDL_Flip(screen);

                        list_clues[0].information_clues<<"I love you too much and if I cant have you no one can";
                        list_clues[0].person_name_first<<"Jacob";
                        list_clues[0].person_name_first<<"Allimore";
                        list_clues[0].location<<"Victim's residence - Living room";
                        SDL_Delay(5000);
                        show_house.show_living();
                        Time_show show_time;
                        name_message = TTF_RenderText_Solid(comic,"Entrance",textColor);
                        apply_surface(400,400,name_message,screen);
                        name_message = TTF_RenderText_Solid(comic,"Kitchen",textColor);
                        apply_surface(20,150,name_message,screen);
                        apply_surface(330,180,small_note,screen);
                        SDL_Flip(screen);
                    }
                }
            }
            if(event.type==SDL_QUIT)
           {
               leave=true;
           }
        }
    }
    return leave;
}

//shows victim bedroom
bool Victims_bedroom()
{
    bool quit = false;
    int x = 0, y = 0;
    Victim_house show_house;

    show_house.show_bedroom();
    name_message = TTF_RenderText_Solid(comic,"Kitchen",textColor);
    apply_surface(400,400,name_message,screen);
    apply_surface(550,350,packed_suitcase,screen);
    SDL_Flip(screen);
    Time_show show_time;

    while(quit==false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                    if((x>400)&&(x<400+70)&&(y>400)&&(y<400+30))
                    {
                        quit=true;
                        Victims_kitchen();
                    }

                    if((x>550)&&(x<550+100)&&(y>350)&&(y<350+100))
                    {
                        name_message = TTF_RenderText_Solid(comic,"Seems someone wanted to leave in a hurry",textColor_b);
                        apply_surface(200,200,name_message,screen);
                        SDL_Flip(screen);

                        list_clues[1].information_clues<<"Packed Suitcases";
                        list_clues[1].person_name_first<<"unknown";
                        list_clues[1].person_name_last<<"unknown";
                        list_clues[1].location<<"Victim's residence - Bedroom";

                        SDL_Delay(3000);
                        show_house.show_bedroom();
                        name_message = TTF_RenderText_Solid(comic,"Kitchen",textColor);
                        apply_surface(400,400,name_message,screen);
                        apply_surface(550,350,packed_suitcase,screen);
                        SDL_Flip(screen);
                        Time_show show_time;
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

//shows victim entrance
bool Victims_house()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface(0,0,v_entrance,screen);
    apply_surface(400,400,office_b,screen);
    apply_surface(100,400,globe,screen);
    SDL_Flip(screen);
    Time_show show_time;

    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;

                        if((x>240)&&(x<240+160)&&(y>230)&&(y<230+150))
                        {
                            quit = Victims_living();

                        }
                        if((x>100)&&(x<100+50)&&(y>400)&&(y<400+50))
                        {
                            quit = true;
                            map_home(2);
                        }
                        if((x>400)&&(x<400+160)&&(y>400)&&(y<400+45))
                        {
                            quit = true;
                            game_time.time_mf+=3;
                            office();
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
