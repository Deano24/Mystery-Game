#include <iostream>
#include <sstream>
#include <windows.h>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"

#include "load.h"
#include "String_SDL.h"
#include "points.h"

#include "Office_Class.h"
#include "apply_surface.h"
#include "deceased_stuff.h"
#include "Victim_house.h"


using namespace std;

void office(void);
void welcome_screen(void);
void deceased(void);
void point_allocation(void);
void map_home(void);
void Victims_house(void);
void Salon(void);
void Victims_kitchen(void);
void Victims_living(void);
void Victims_bedroom(void);


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



SDL_Event event;
SDL_Event event_string;

TTF_Font *font = NULL;
TTF_Font *sketch = NULL;
TTF_Font *sketch_2 = NULL;
TTF_Font *juice_b = NULL;
TTF_Font *comic = NULL;

SDL_Color textColor = { 255,255,255 };
SDL_Color textColors = { 0xFF,0xFF,0xFF };
SDL_Color textColor_r = {255,000,000};
SDL_Color textColor_b = {000,000,000};

    //to set screen back to black SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );


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

bool button_event()
{
    int x=0, y=0;
    bool quit;

    //If a mouse button was pressed
        if(event.button.button==SDL_BUTTON_LEFT)
        {
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;

            //If the mouse is over the button
           if( ( x > 0) && ( x < 100 + 223 ) && ( y > 0 ) && ( y < 100 + 31 ) )
            {
                    //Render the text
                    quit=true;

            }
        }
        return quit;
}

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

void deceased()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface(0,0,office_back, screen);
    name_message = TTF_RenderText_Solid(comic,"Victim: Mrs. Mary-Ann Smith",textColor_b);
    apply_surface(10,10,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"Cause of death: Hacked to death",textColor_b);
    apply_surface(10,40,name_message,screen);
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
        }
    }

}

void map_home()
{
    bool quit = false;
    int x = 0, y = 0;
    apply_surface(0,0,city_street,screen);
    apply_surface(400,400,office_b,screen);
    name_message = TTF_RenderText_Solid(comic,"Victim's House",textColor);
    apply_surface(50,20,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"Salon",textColor);
    apply_surface(100,80,name_message,screen);
    apply_surface(25,20,star,screen);
    apply_surface(75,80,star,screen);
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
                               Victims_house();
                           }
                        if((x>75)&&(x<75+20)&&(y>80)&&(y<80+18))
                           {
                               Salon();
                           }

                        if((x>400)&&(x<400+160)&&(y>400)&&(y<400+45))
                        {
                            quit = true;
                            office();
                        }

                }
            }
        }
    }

}

void Victims_kitchen()
{
    bool exit = false;
    int x = 0, y = 0;
    Victim_house show_house;

    show_house.show_kitchen();
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

                        if((x>300)&&(x<300+70)&&(y>0)&&(y<0+30))
                            {
                                Victims_bedroom();
                            }

                    }
            }
        }
    }
}

void Victims_living()
{
    bool leave = false;
    int x = 0, y = 0;
    Victim_house show_house;

    show_house.show_living();
    name_message = TTF_RenderText_Solid(comic,"Entrance",textColor);
    apply_surface(400,400,name_message,screen);
    name_message = TTF_RenderText_Solid(comic,"Kitchen",textColor);
    apply_surface(20,150,name_message,screen);
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
                        Victims_kitchen();
                    }
                }
            }
        }
    }

}

void Victims_bedroom()
{
    bool quit = false;
    int x = 0, y = 0;
    Victim_house show_house;

    show_house.show_bedroom();
    name_message = TTF_RenderText_Solid(comic,"Kitchen",textColor);
    apply_surface(400,400,name_message,screen);
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

                    if((x>400)&&(x<400+70)&&(y>400)&&(y<400+30))
                    {
                        quit=true;
                        Victims_kitchen();
                    }
                }
            }
        }
    }

}

void Victims_house()
{
    bool quit = false;
    int x = 0, y = 0;

    apply_surface(0,0,v_entrance,screen);
    apply_surface(400,400,office_b,screen);
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

                        if((x>240)&&(x<240+160)&&(y>230)&&(y<230+150))
                        {
                            Victims_living();

                        }
                        if((x>400)&&(x<400+160)&&(y>400)&&(y<400+45))
                        {
                            quit = true;
                            office();
                        }
                }
            }
        }
    }
}

void Salon()
{

}

void office()
{
    bool quit = false;
    int x = 0, y = 0;

    Office_Class office_image;

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
                            deceased();
                        }

                        if((x>360)&&(x<360+50)&&(y>150)&&(y<150+50))
                        {
                            SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );
                            map_home();
                        }

                        if((x>400)&&(x<400+40)&&(y>400)&&(y<400+38))
                        {
                            quit=true;
                        }
               }

           }
        }
    }

}

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
    office();

    //Free surfaces and font then quit SDL_ttf and SDL
    start.clean_up();

    return 0;
}

