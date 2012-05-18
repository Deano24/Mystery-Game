#include "Office_Class.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "load.h"
#include "deceased_stuff.h"


void apply_surface_class( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

Office_Class::Office_Class()
{
    apply_surface_class(0,0,office_back,screen);
    name_message = TTF_RenderText_Solid(sketch_2,"OFFICE",textColors);
    apply_surface_class(200,10,name_message,screen);
    SDL_Flip(screen);
    SDL_FreeSurface(welcome_message);
    welcome_message = TTF_RenderText_Solid(comic,"Case",textColor_b);
    apply_surface_class(100,130,welcome_message,screen);
    apply_surface_class(100,150,file,screen);
    welcome_message = TTF_RenderText_Solid(comic,"Map",textColor_b);
    apply_surface_class(360,130,welcome_message,screen);
    apply_surface_class(360,150,globe,screen);
    apply_surface_class(400,400,exit_pic,screen);
    SDL_Flip(screen);
}
