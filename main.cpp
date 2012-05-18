#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include <windows.h>
#include "load.h"
#include "String_SDL.h"
#include "points.h"
#include <sstream>


using namespace std;



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


SDL_Event event;
SDL_Event event_string;

TTF_Font *font = NULL;
TTF_Font *sketch = NULL;
TTF_Font *sketch_2 = NULL;
TTF_Font *juice_b = NULL;

SDL_Color textColor = { 255, 255, 255 };
SDL_Color textColors = { 0xFF, 0xFF, 0xFF };
SDL_Color textColor_r = {255 ,	000 ,	000};



void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}


    //to set screen back to black SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );

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


    apply_surface( 0, 0, points, screen );
    SDL_FreeSurface(welcome_message);
    welcome_message = TTF_RenderText_Solid(sketch_2,"This is the point allocation page",textColor);
    apply_surface(80,2,welcome_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"You are being awarded 15 points please allocate them.",textColor_r);
    apply_surface(10,50,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"You have 3 ares: Breaking and Entering, Interrogation and",textColor_r);
    apply_surface(10,100,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Intuition. Go to your office once you are finished.",textColor_r);
    apply_surface(50,120,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Breaking and Entering: The higher the skill level the better the",textColor_r);
    apply_surface(10,160,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"chance of success for breaking into someones residence.",textColor_r);
    apply_surface(50,180,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Interrogation: The higher the skill the more questions you can",textColor_r);
    apply_surface(10,220,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"ask a suspect/individual.",textColor_r);
    apply_surface(50,240,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Intution: The higher the skill the more chance you will have to",textColor_r);
    apply_surface(10,280,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"sense if something is not right.",textColor_r);
    apply_surface(50,300,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Breaking and Entering",textColor_r);
    apply_surface(10,340,name_message,screen);
    apply_surface(300,340,pluss,screen);
    apply_surface(330,340,minuss,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Interrogation",textColor_r);
    apply_surface(10,380,name_message,screen);
    apply_surface(300,380,pluss,screen);
    apply_surface(330,380,minuss,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Intuition",textColor_r);
    apply_surface(10,420,name_message,screen);
    apply_surface(300,420,pluss,screen);
    apply_surface(330,420,minuss,screen);
    apply_surface(420,420,office_b,screen);
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
    welcome_message = TTF_RenderText_Solid(sketch_2,"This is the point allocation page",textColor);
    apply_surface(80,2,welcome_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"You are being awarded 15 points please allocate them.",textColor_r);
    apply_surface(10,50,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"You have 3 ares: Breaking and Entering, Interrogation and",textColor_r);
    apply_surface(10,100,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Intuition. Go to your office once you are finished.",textColor_r);
    apply_surface(50,120,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Breaking and Entering: The higher the skill level the better the",textColor_r);
    apply_surface(10,160,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"chance of success for breaking into someones residence.",textColor_r);
    apply_surface(50,180,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Interrogation: The higher the skill the more questions you can",textColor_r);
    apply_surface(10,220,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"ask a suspect/individual.",textColor_r);
    apply_surface(50,240,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Intution: The higher the skill the more chance you will have to",textColor_r);
    apply_surface(10,280,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"sense if something is not right.",textColor_r);
    apply_surface(50,300,name_message,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Breaking and Entering",textColor_r);
    apply_surface(10,340,name_message,screen);
    apply_surface(300,340,pluss,screen);
    apply_surface(330,340,minuss,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Interrogation",textColor_r);
    apply_surface(10,380,name_message,screen);
    apply_surface(300,380,pluss,screen);
    apply_surface(330,380,minuss,screen);
    name_message = TTF_RenderText_Solid(juice_b,"Intuition",textColor_r);
    apply_surface(10,420,name_message,screen);
    apply_surface(300,420,pluss,screen);
    apply_surface(330,420,minuss,screen);
    apply_surface(420,420,office_b,screen);
    SDL_Flip(screen);
    }
}

void office()
{
    apply_surface(0,0,office_back,screen);
    name_message = TTF_RenderText_Solid(sketch_2,"THIS IS YOUR OFFICE",textColors);
    apply_surface(140,200,name_message,screen);
    SDL_Flip(screen);
    // kenrick was here
    SDL_FreeSurface(welcome_message);
    welcome_message = TTF_RenderText_Solid(sketch,"CASE",textColor);
    apply_surface (200,260,welcome_message,screen);
    SDL_Flip(screen);

}


int main( int argc, char* args[] )
{
    load start;

    bool quit = false;

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

    welcome_screen();
    SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );
    point_allocation();
    SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );
    office();

    Sleep(5000);
    name_message = TTF_RenderText_Solid(sketch,"Press Q to exit",textColor);
    apply_surface(250,250,name_message,screen);
    SDL_Flip(screen);


     //While the user hasn't quit
    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            if(event.type==SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_q:
                                quit=true;
                    break;
                    default:;
                }
            }
            //if( event.type == SDL_MOUSEBUTTONDOWN )
                //{

                   // button_event();

               // }

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
    }
    //Free surfaces and font then quit SDL_ttf and SDL
    start.clean_up();

    return 0;
}

