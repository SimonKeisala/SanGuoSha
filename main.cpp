//#include "functions.h"
//#include <iostream>
//#include <string>
#include <stdexcept>
#include "SGS.h"

using namespace std;

int main(int argc, char* argv[])
{
	// Variabler i starten
	const int SCREEN_WIDTH  = 1024;
	const int SCREEN_HEIGHT = 768;
	const int SCREEN_BPP    = 32;
	try
	{
	// Initialize	
	Surface screen;
	cout << "skapa skreen" << endl;
	screen = Init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
	cout << "screen skapad" << endl;
	// Start av main	
	cout << "mainMenu skapas" << endl;
	Menu mainMenu(screen);  //Skapa mainMenu och länka det till skärmen
	cout << "bakgrundsbilden laddas" << endl;
	mainMenu.load_background("Images/Gui/background.png");
	cout << "en button skapas" << endl;
	mainMenu.make_button("New Game",300,100,"make_new_game");
	mainMenu.make_button("Options", 300,200,"options");
	mainMenu.make_button("Exit", 300,400,"exit"); 
	cout << "mainMenu startas" << endl;
	
	for(int i = 0; i < argc ; ++i)
	{
		cout << "argument " << i << ": " << argv[i] << endl;
	}
	
		mainMenu.run(); //startar programmet
	}
	catch(runtime_error re)
	{
		cout << re.what() << endl;
	}
	catch(logic_error le)
	{
		cout << le.what() << endl;
	}
	catch(exception e)
	{
		cout << e.what() << endl;
	}
	catch(...)
	{
		cout << "an error occured" << endl;
	}
	
	//avslut, ta bort alla surfaces som skapas (enbart screen just nu) och avsluta TTF, SDL och musiken
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
	
	cout << "exit OK!" << endl;
	return 0;
}
