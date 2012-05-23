#ifndef LOAD_H
#define LOAD_H
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"


class load
{
    public:
        bool load_files();
        bool init();
        void clean_up();
};



//The surfaces
extern SDL_Surface *background ;
extern SDL_Surface *message;
extern SDL_Surface *screen;
extern SDL_Surface *button;
extern SDL_Surface *welcome_message;
extern SDL_Surface *name_message;
extern SDL_Surface *points;
extern SDL_Surface *pluss;
extern SDL_Surface *minuss;
extern SDL_Surface *office_b;
extern SDL_Surface *office_back;
extern SDL_Surface *globe;
extern SDL_Surface *file;
extern SDL_Surface *exit_pic;
extern SDL_Surface *city_street;
extern SDL_Surface *star;
extern SDL_Surface *v_bedroom;
extern SDL_Surface *v_living;
extern SDL_Surface *v_entrance;
extern SDL_Surface *v_kitchen;
extern SDL_Surface *hair_salon;
extern SDL_Surface *packed_suitcase;
extern SDL_Surface *small_note;
extern SDL_Surface *select_button;
extern SDL_Surface *husband_house;
extern SDL_Surface *husband_living;



//The event structure
extern SDL_Event event;

//The font that's going to be used
extern TTF_Font *font;

extern TTF_Font *sketch;
extern TTF_Font *sketch_2;
extern TTF_Font *juice_b;
extern TTF_Font *comic;

//The color of the font
extern SDL_Color textColor;



#endif // LOAD_H
