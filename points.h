#ifndef POINTS_H
#define POINTS_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include<string>
#include <sstream>


class point
{

    private:
    //The storage string
    std::stringstream strm_bande;
    std::stringstream strm_interrogation;
    std::stringstream strm_intuition;
    std::stringstream temp;





    public:
        void points_b_m();
        void points_i_m();
        void points_int_m();
        void points_b_p();
        void points_i_p();
        void points_int_p();
        void show_bande();
        void show_interrogation();
        void show_intuition();
};

typedef struct
{
    int bande;
    int interrogation;
    int intuition;

}skill;

extern skill skill_set;

extern SDL_Surface *break_ent;
extern SDL_Surface *interrogation;
extern SDL_Surface *intuition;

extern SDL_Color textColor_r;

#endif // POINTS_H
