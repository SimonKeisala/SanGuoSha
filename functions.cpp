#include "functions.h"
#include <string>

using namespace std;


SDL_Surface* load_image(const string& filename)
{
	//Temporary storage for the image that's loaded
	SDL_Surface* loadedImage = nullptr;
	
	//The optimized image that will be used
	SDL_Surface* optimizedImage = nullptr;
	
	loadedImage = IMG_Load( filename.c_str() );
	
	if(loadedImage != nullptr)
	{
		//create an optimized image
		optimizedImage = SDL_DisplayFormat( loadedImage );
		
		//free the old image
		SDL_FreeSurface( loadedImage );
	}
	return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
	SDL_Rect offset;
	
	offset.x = x;
	offset.y = y;
	
	SDL_BlitSurface( source, clip, destination, &offset );
}

SDL_Surface* Init(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const int& SCREEN_BPP)
{

	SDL_Surface* screen;
	//Initialize all SDL subsystems
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1)
	{
		return nullptr;
	}
	
	//Set up the screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	
	//If there was an error in setting up the screen
	if (screen == nullptr)
	{
		return nullptr;
	}
	
	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		return nullptr;
	}
	
	//Set the window caption
	SDL_WM_SetCaption( "TTF Test", nullptr);
	
	//If everything is ok
	return screen;
}

void clean_up(initializer_list<SDL_Surface*> clean_surface, initializer_list<TTF_Font*> clean_font)
{
	for(auto it = clean_surface.begin(); it != clean_surface.end(); ++it)
		SDL_FreeSurface(*it);
	
	for(auto it = clean_font.begin(); it != clean_font.end(); ++it)
		TTF_CloseFont(*it);

	//Quit SDL_ttf
	TTF_Quit();
		
	//Quit SDL
	SDL_Quit();
}