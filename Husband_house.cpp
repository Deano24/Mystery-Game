#include "Husband_house.h"

#include <sstream>
#include <windows.h>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include <sqlite3.h>

#include "load.h"
#include "String_SDL.h"
#include "points.h"
#include "Time_show.h"
#include "data.h"

void apply_surface_husband(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(source, clip, destination, &offset);
}

void Husband_house::Husband_houses()
{
    bool quit = false;

    apply_surface_husband(0,0,husband_living,screen);
    SDL_Flip(screen);

    while (quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                quit = true;
            }
        }
    }
}

void Husband_house::question()
{

}
