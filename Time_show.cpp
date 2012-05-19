#include "Time_show.h"
#include <sstream>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "load.h"
#include <string.h>

using namespace std;



time_part game_time = {8,0,0};

void apply_surface_time(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, clip, destination, &offset );
}

Time_show::Time_show()
{
    stringstream showing_time;

     if((game_time.time_mf-6)==0)
      {
                               game_time.time_h+=1;
                               game_time.time_mf=0;
      }
      else if ((game_time.time_mf-6)>0)
      {
           game_time.time_h+=1;
           game_time.time_mf=game_time.time_mf-6;
       }
    else{
        }


     if(game_time.time_h<12)
     {
         showing_time<<game_time.time_h;
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" am";
     }

     if(game_time.time_h==12)
     {
         showing_time<<game_time.time_h;
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

     if(game_time.time_h==13)
     {
         showing_time<<(game_time.time_h-12);
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

     if(game_time.time_h==14)
     {
         showing_time<<(game_time.time_h-12);
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

     if(game_time.time_h==15)
     {
         showing_time<<(game_time.time_h-12);
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

     if(game_time.time_h==16)
     {
         showing_time<<(game_time.time_h-12);
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

     if(game_time.time_h==17)
     {
         showing_time<<(game_time.time_h-12);
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

     if(game_time.time_h==18)
     {
         showing_time<<(game_time.time_h-12);
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

     if(game_time.time_h==19)
     {
         showing_time<<(game_time.time_h-12);
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

     if(game_time.time_h==20)
     {
         showing_time<<(game_time.time_h-12);
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

     if(game_time.time_h==21)
     {
         showing_time<<(game_time.time_h-12);
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

     if(game_time.time_h==22)
     {
         showing_time<<(game_time.time_h-12);
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

     if(game_time.time_h==23)
     {
         showing_time<<(game_time.time_h-12);
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

     if(game_time.time_h==24)
     {
         showing_time<<(game_time.time_h-12);
         showing_time<<":";
         showing_time<<game_time.time_mf;
         showing_time<<game_time.time_ml;
         showing_time<<" pm";
     }

    time_showing = TTF_RenderText_Solid(comic,showing_time.str().c_str(),textColor_blue);
    showing_time.str("");
    apply_surface_time(0,0,time_showing,screen);
    SDL_Flip(screen);
}
