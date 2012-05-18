#include "load.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include <string>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;


SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

bool load::init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Mystery Game", NULL );

    //If everything initialized fine
    return true;
}

bool load::load_files()
{
    //Load the background image
    background = load_image( "background.png" );
    pluss = load_image( "plus.png" );
    minuss = load_image( "minus.gif" );
    button = SDL_LoadBMP("button.bmp");
    points = load_image("points.jpg");
    office_b = SDL_LoadBMP("Office button.bmp");
    office_back = load_image("detective_office.jpg");

    //Open the font
    font = TTF_OpenFont( "lazy.ttf", 28 );
    sketch = TTF_OpenFont("!sketchytimes-b.ttf",24);
    sketch_2 = TTF_OpenFont("!sketchytimes-b.ttf",48);
    juice_b = TTF_OpenFont("juice bold.ttf",18);

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

    //If there was an error in loading the font
    if( font == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void load::clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( message );
    SDL_FreeSurface(button);
    SDL_FreeSurface(welcome_message);
    SDL_FreeSurface(name_message);

    //Close the font that was used
    TTF_CloseFont( font );
    TTF_CloseFont(sketch);

    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}
