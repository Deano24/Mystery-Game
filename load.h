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


//The event structure
extern SDL_Event event;

//The font that's going to be used
extern TTF_Font *font;

extern TTF_Font *sketch;
extern TTF_Font *sketch_2;
extern TTF_Font *juice_b;

//The color of the font
extern SDL_Color textColor;



#endif // LOAD_H