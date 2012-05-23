//All header files used

//all compiler header files
#include <sstream>
#include <windows.h>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include <sqlite3.h>

//header files that deal with the program - these are created
#include "load.h"
#include "String_SDL.h"
#include "points.h"
#include "Time_show.h"
#include "data.h"

//header files that deal with the mystery - these are created
#include "Office_Class.h"
#include "apply_surface.h"
#include "deceased_stuff.h"
#include "Salon_questioning.h"
//for the victim house
#include "Victim_house.h"

//for the husband's house
#include "Husband_house.h"

//allows for the use of the stream
using namespace std;

//START OFF
void office(void);
void welcome_screen(void);
void point_allocation(void);

//MAP
bool map_home(int);

//THE DECASED MYSTERY INFORMATION
bool deceased(void);

//SALON FOR DECEASED MYSTERY
bool Salon(void);

//ALL ASPECTS OF VICTIMS HOUSE
bool Victims_house(void);
bool Victims_kitchen(void);
bool Victims_living(void);
bool Victims_bedroom(void);

//ALL ASPECT OF HUSBANDS HOUSE
bool Husbands_house(void);


//List of all Surfaces
SDL_Surface *background = NULL;
SDL_Surface *message = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *button = NULL;
SDL_Surface *welcome_message = NULL;
SDL_Surface *name_message = NULL;
SDL_Surface *points = NULL;
SDL_Surface *pluss = NULL;
SDL_Surface *minuss = NULL;
SDL_Surface *break_ent = NULL;
SDL_Surface *interrogation = NULL;
SDL_Surface *intuition = NULL;
SDL_Surface *office_b = NULL;
SDL_Surface *office_back = NULL;
SDL_Surface *globe = NULL;
SDL_Surface *file = NULL;
SDL_Surface *exit_pic = NULL;
SDL_Surface *city_street = NULL;
SDL_Surface *star = NULL;
SDL_Surface *v_bedroom = NULL;
SDL_Surface *v_living = NULL;
SDL_Surface *v_entrance = NULL;
SDL_Surface *v_kitchen = NULL;
SDL_Surface *time_showing = NULL;
SDL_Surface *hair_salon = NULL;
SDL_Surface *packed_suitcase = NULL;
SDL_Surface *small_note = NULL;
SDL_Surface *select_button = NULL;
SDL_Surface *husband_house = NULL;
SDL_Surface *husband_living = NULL;

//event handlers
SDL_Event event;
SDL_Event event_string;

//creates an array to store all the clues
clues list_clues [30];

//List of all fonts
TTF_Font *font = NULL;
TTF_Font *sketch = NULL;
TTF_Font *sketch_2 = NULL;
TTF_Font *juice_b = NULL;
TTF_Font *comic = NULL;


//function designed to apply the surfaxes to the screen
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination,SDL_Rect* clip = NULL)
{
    //Holds offsets
    SDL_Rect offset;


    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

//Welcome Screen
void welcome_screen()
{
    bool quit = false;
    bool nameEntered = false;
    StringInput name;

        while(quit==false)
        {
                //While there's events to handle
                while( SDL_PollEvent( &event_string ) )
                    {
                        if(nameEntered==false)
                        {
                            //Get user input
                            name.handle_input();

                                //If the enter key was pressed
                                if( ( event_string.type == SDL_KEYDOWN ) && ( event_string.key.keysym.sym == SDLK_RETURN ) )
                                    {
                                    //Change the flag
                                    nameEntered = true;
                                    quit = true;
                                    }
                        }
                        if(event.type==SDL_QUIT)
                        {
                            quit=true;
                        }
                    }
        //Show the name on the screen
        apply_surface( 20, 0, background, screen );
        name.show_centered();
        welcome_message = TTF_RenderText_Solid( sketch, "Welcome to Mystery A La'Carte", textColor );
        apply_surface(200,150,welcome_message,screen);
        name_message = TTF_RenderText_Solid( sketch, "Enter Your name:", textColor );
        apply_surface(60,225,name_message,screen);
        SDL_Flip( screen );
    }
}

//Function to allow user to allocate points
void point_allocation()
{
    bool quit = false;
    int x = 0, y = 0;
    stringstream strm2;
    point calculate;

    calculate.show_images();
    apply_surface( 0, 0, points, screen );

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

                        if((x>300)&&(x<300+22)&&(y>340)&&(y<340+21))
                        {
                            if(skill_set.bande+skill_set.interrogation+skill_set.intuition!=15)
                            {
                                apply_surface( 0, 0, points, screen );
                                calculate.points_b_p();
                                calculate.show_bande();
                                SDL_Flip(screen);
                            }
                        }

                        if((x>330)&&(x<330+22)&&(y>340)&&(y<340+21))
                        {
                                apply_surface( 0, 0, points, screen );
                                calculate.points_b_m();
                                calculate.show_bande();
                                SDL_Flip(screen);
                        }
                        if((x>300)&&(x<300+22)&&(y>380)&&(y<380+21))
                        {
                            if(skill_set.bande+skill_set.interrogation+skill_set.intuition!=15)
                            {
                                apply_surface( 0, 0, points, screen );
                                calculate.points_int_p();
                                calculate.show_interrogation();
                                SDL_Flip(screen);
                            }
                        }
                        if((x>330)&&(x<330+22)&&(y>380)&&(y<380+21))
                        {

                                apply_surface( 0, 0, points, screen );
                                calculate.points_int_m();
                                calculate.show_interrogation();
                        }
                        if((x>300)&&(x<300+22)&&(y>420)&&(y<420+21))
                        {
                            if(skill_set.bande+skill_set.interrogation+skill_set.intuition!=15)
                            {
                                apply_surface( 0, 0, points, screen );
                                calculate.points_i_p();
                                calculate.show_intuition();
                                SDL_Flip(screen);
                            }
                        }
                        if((x>330)&&(x<330+22)&&(y>420)&&(y<420+21))
                        {
                                apply_surface( 0, 0, points, screen );
                                calculate.points_i_m();
                                calculate.show_intuition();
                                SDL_Flip(screen);
                        }

                        if((x>420)&&(x<420+160)&&(y>420)&&(y<420+45))
                        {
                            if(skill_set.bande+skill_set.interrogation+skill_set.intuition==15)
                            {
                                quit=true;

                            }

                        }

                }
            }
            if(event.type==SDL_QUIT)
           {
               quit=true;
           }
        }
    SDL_FreeSurface(welcome_message);
    strm2<<skill_set.bande+skill_set.interrogation+skill_set.intuition;
    strm2<<"/15";
    name_message = TTF_RenderText_Solid (juice_b,strm2.str().c_str(),textColor_r);
    apply_surface(470,400,name_message,screen);
    strm2.str("");
    calculate.show_images();
    }
}

//function to show user information on deceased case
bool deceased()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface(0,0,office_back, screen);
    Time_show show_time;
    name_message = TTF_RenderText_Solid(comic,"Victim: Mrs. Mary-Ann Smith",textColor_b);
    apply_surface(10,20,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"Cause of death: Hacked to death",textColor_b);
    apply_surface(10,45,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"Weapon: Machete",textColor_b);
    apply_surface(10,80,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"Brief summary: Mrs. Smith age 28 lived with her husban Mr. Smith ",textColor_b);
    apply_surface(10,120,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"at a Condo in Haledale, she was a hair stylist ",textColor_b);
    apply_surface(30,140,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"Suspects are: Mr. Drake Allimore (Victim's Gardener), ",textColor_b);
    apply_surface(30,180,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"Mr. Kevin Jenkins(Doorman for the Condominium) ",textColor_b);
    apply_surface(30,200,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"and Mr. Jahnoi Smith (Victim's Husband). ",textColor_b);
    apply_surface(30,220,name_message,screen);
    apply_surface(400,400,office_b,screen);
    SDL_Flip(screen);

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

                    if((x>400)&&(x<400+160)&&(y>400)&&(y<400+45))
                        {
                            quit=true;
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

//shows the map
bool map_home(int location)
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface(0,0,city_street,screen);
    Time_show show_time;
    apply_surface(400,400,office_b,screen);
    name_message = TTF_RenderText_Solid(comic,"Victim's House",textColor);
    apply_surface(50,20,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"Salon",textColor);
    apply_surface(100,80,name_message,screen);
    apply_surface(25,20,star,screen);
    apply_surface(75,80,star,screen);

    if(husband==true)
    {
        name_message = TTF_RenderText_Solid(comic,"Husband's House",textColor);
        apply_surface(200,40,name_message,screen);
        apply_surface(175,40,star,screen);
    }


    SDL_Flip(screen);

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

                        if((x>25)&&(x<25+20)&&(y>20)&&(y<20+18))
                           {
                               if(location==2)
                               {

                               }

                               else
                               {
                                   game_time.time_mf+=3;
                               }
                               quit = Victims_house();
                           }

                        if((x>175)&&(x<175+20)&&(y>40)&&(y<40+18))
                           {
                               if(location==4)
                               {

                               }

                               else
                               {
                                   game_time.time_mf+=3;
                               }
                               quit = Husbands_house();
                           }

                        if((x>75)&&(x<75+20)&&(y>80)&&(y<80+18))
                           {
                               if(location==3)
                               {

                               }
                               else
                               {
                                   game_time.time_mf+=3;
                               }
                                quit = Salon();
                           }

                        if((x>400)&&(x<400+160)&&(y>400)&&(y<400+45))
                        {
                            if(location==1)
                            {

                            }
                            else
                            {
                            game_time.time_mf+=3;
                            }
                            quit = true;
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

//shows salon
bool Salon()
{
    bool quit = false;
    int x = 0, y = 0;


    apply_surface(0,0,hair_salon,screen);
    apply_surface(400,400,office_b,screen);
    apply_surface(100,400,globe,screen);
    name_message = TTF_RenderText_Solid(comic,"Talk to Owner",textColor);
    apply_surface(400,100,name_message,screen);
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

                        if((x>400)&&(x<400+100)&&(y>100)&&(y<100+20))
                        {
                            Salon_questioning question;
                            apply_surface(0,0,hair_salon,screen);
                            apply_surface(400,400,office_b,screen);
                            apply_surface(100,400,globe,screen);
                            name_message = TTF_RenderText_Solid(comic,"Talk to Owner",textColor);
                            apply_surface(400,100,name_message,screen);
                            SDL_Flip(screen);
                            Time_show show_time;
                        }

                        if((x>100)&&(x<100+50)&&(y>400)&&(y<400+50))
                        {
                            quit = true;
                            map_home(3);
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

//husbands house entrance
bool Husbands_house()
{
    bool quit;
    int x = 0, y = 0;
    Husband_house enter;

    apply_surface(0,0,husband_house,screen);
    Time_show show_time;
    apply_surface(400,400,office_b,screen);
    apply_surface(100,400,globe,screen);
    SDL_Flip(screen);

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

                        if((x>100)&&(x<100+50)&&(y>400)&&(y<400+50))
                        {
                            quit = true;
                            map_home(4);
                        }

                        if((x>232)&&(x<232+43)&&(y>248)&&(y<248+162))
                        {
                            quit = true;
                            enter.Husband_houses();
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

//shows the users office
void office()
{
    bool quit = false;
    int x = 0, y = 0;

    Office_Class office_image;
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
                        if((x>100)&&(x<100+50)&&(y>150)&&(y<150+50))
                        {
                            quit = deceased();
                        }

                        if((x>360)&&(x<360+50)&&(y>150)&&(y<150+50))
                        {
                            SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );
                            quit = map_home(1);
                        }

                        if((x>400)&&(x<400+40)&&(y>400)&&(y<400+38))
                        {
                            quit=true;
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

//main function
int main( int argc, char* args[] )
{
    load start;

    if( start.init() == false )
    {
        return 1;
    }
    if( start.load_files() == false )
    {
        return 1;
    }

    apply_surface( 20, 0, background, screen );

    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }

    //welcome_screen();
    //SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );
    //point_allocation();
    //SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );
    //office();

    Husbands_house();

    //Free surfaces and font then quit SDL_ttf and SDL
    start.clean_up();

    return 0;
}

