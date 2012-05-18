#include "apply_surface.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"

apply_surface::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination)

{
    //Holds offsets
    SDL_Rect offset;
    SDL_Rect*clip=NULL;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
