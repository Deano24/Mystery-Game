#ifndef TIME_SHOW_H
#define TIME_SHOW_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"


class Time_show
{
    public:
        Time_show();
};

typedef struct{
    int time_h;
    int time_mf;
    int time_ml;
}time_part;

extern time_part game_time;

extern SDL_Surface *time_showing;
extern SDL_Color textColor_blue;

#endif // TIME_SHOW_H
