#ifndef STRING_SDL_H
#define STRING_SDL_H
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include<string>


//The key press interpreter
class StringInput
{
    private:
    //The storage string
    std::string str;

    //The text surface
    SDL_Surface *text;

    public:
    //Initializes variables
    StringInput();

    //Does clean up
    ~StringInput();

    //Handles input
    void handle_input();

    //Shows the message on screen
    void show_centered();


};

//The event structure
extern SDL_Event event_string;

//The color of the font
extern SDL_Color textColors;


#endif // STRING_SDL_H
