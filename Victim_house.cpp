#include "Victim_house.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "load.h"

void apply_surface_house( int x, int y, SDL_Surface* source, SDL_Surface* destination,SDL_Rect* clip = NULL)
{
    //Holds offsets
    SDL_Rect offset;


    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

void Victim_house::show_bedroom()
{
    apply_surface_house(0,0,v_bedroom,screen);
    SDL_Flip(screen);
}

void Victim_house::show_living()
{
    apply_surface_house(0,0,v_living,screen);
    SDL_Flip(screen);
}


void Victim_house::show_kitchen()
{
    apply_surface_house(0,0,v_kitchen,screen);
    SDL_Flip(screen);
}

