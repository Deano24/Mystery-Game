#include "String_SDL.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include<string>
#include "load.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;


StringInput::StringInput()
{
    //Initialize the string
    str = "";

    //Initialize the surface
    text = NULL;

    //Enable Unicode
    SDL_EnableUNICODE( SDL_ENABLE );
}

StringInput::~StringInput()
{
    //Free text surface
    SDL_FreeSurface( text );

    //Disable Unicode
    SDL_EnableUNICODE( SDL_DISABLE );
}

void StringInput::handle_input()
{
    //If a key was pressed
    if( event_string.type == SDL_KEYDOWN )
    {
        //Keep a copy of the current version of the string
        std::string temp = str;

        //If the string less than maximum size
        if( str.length() <= 20 )
        {
            //If the key is a space
            if( event_string.key.keysym.unicode == (Uint16)' ' )
            {
                //Append the character
                str += (char)event_string.key.keysym.unicode;
            }
            //If the key is a number
            else if( ( event_string.key.keysym.unicode >= (Uint16)'0' ) && ( event_string.key.keysym.unicode <= (Uint16)'9' ) )
            {
                //Append the character
                str += (char)event_string.key.keysym.unicode;
            }
            //If the key is a uppercase letter
            else if( ( event_string.key.keysym.unicode >= (Uint16)'A' ) && ( event_string.key.keysym.unicode <= (Uint16)'Z' ) )
            {
                //Append the character
                str += (char)event_string.key.keysym.unicode;
            }
            //If the key is a lowercase letter
            else if( ( event_string.key.keysym.unicode >= (Uint16)'a' ) && ( event_string.key.keysym.unicode <= (Uint16)'z' ) )
            {
                //Append the character
                str += (char)event_string.key.keysym.unicode;
            }
        }

        //If backspace was pressed and the string isn't blank
        if( ( event_string.key.keysym.sym == SDLK_BACKSPACE ) && ( str.length() != 0 ) )
        {
            //Remove a character from the end
            str.erase( str.length() - 1 );
        }

        //If the string was changed
        if( str != temp )
        {
            //Free the old surface
            SDL_FreeSurface(text);

            //Render a new text surface
            text = TTF_RenderText_Solid( sketch, str.c_str(), textColors );
        }
    }
}

void apply_surface_string( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}


void StringInput::show_centered()
{
    //If the surface isn't blank
    if( text != NULL )
    {
        //Show the name
        apply_surface_string( ( SCREEN_WIDTH - text->w ) / 2, ( SCREEN_HEIGHT - text->h ) / 2, text, screen );
    }
}
