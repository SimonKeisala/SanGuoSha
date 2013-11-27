#ifndef WINDOW_H
#define WINDOW_H

#include "../functions.h"
#include "Button.h"
#include "Slider.h"
#include "Textbox.h"
#include "Objects.h"
#include <vector>
#include "../StringInput.h"

namespace Object
{
  class Window : public ActiveObject
  {
  private:
    SDL_Surface* background = nullptr;
    SDL_Rect box;
    std::vector<Object*> objects;
    StringInput inp;
    
  public:
    //notera att  f�nstret b�r vara minst 10x10 pixlar stort
    Window(const int& x, const int& y, const int& w, const int& h)
      {
	//ladda background och borders
	box.x = x;
	box.y = y;
	box.w = w;
	box.h = h;
	background = loadImage("Images/Gui/Window/background.png", false);
	SDL_Surface* tmp_bg;
	
	//�vre ramen
	tmp_bg = loadImage("Images/Gui//window/tb.png",true);
	applySurface(0,0, tmp_bg, background, nullptr);
	cleanUp({tmp_bg});
	//v�nstra ramen
	tmp_bg = loadImage("Images/Gui/window/lb.png",true);
	applySurface(0,0, tmp_bg, background, nullptr);
	cleanUp({tmp_bg});
	//nedre ramen
	tmp_bg = loadImage("Images/Gui/window/bb.png",true);
	applySurface(0,h - tmp_bg->h, tmp_bg, background, nullptr);
	cleanUp({tmp_bg});
	//h�gra ramen
	tmp_bg = loadImage("Images/Gui/window/rb.png",true);
	applySurface(w - tmp_bg->w,0, tmp_bg, background, nullptr);
	cleanUp({tmp_bg});
	//�vre v�nstra h�rnet
	tmp_bg = loadImage("Images/Gui/window/ltc.png",true);
	applySurface(0,0, tmp_bg, background, nullptr);
	cleanUp({tmp_bg});
	//�vre h�gra h�rnet
	tmp_bg = loadImage("Images/Gui/window/rtc.png",true);
	applySurface(w - tmp_bg->w,0, tmp_bg, background, nullptr);
	cleanUp({tmp_bg});
	//nedre v�nstra h�rnet
	tmp_bg = loadImage("Images/Gui/window/lbc.png",true);
	applySurface(0,h - tmp_bg->h, tmp_bg, background, nullptr);
	cleanUp({tmp_bg});
	//nedre h�gra h�rnet
	tmp_bg = loadImage("Images/Gui/window/rbc.png",true);
	applySurface(w - tmp_bg->w, h - tmp_bg->h, tmp_bg, background, nullptr);
	cleanUp({tmp_bg});
	
      }
    ~Window();
    std::string handleEvent(const SDL_Event&);
    void makeButton(const std::string& text, const int& x_pos, const int& y_pos, const std::string& command = "",
					const std::string& image = "Images/Gui/cleanButton2.png", const unsigned& size = 20);
    bool makeSlider(const int& x_pos, const int& y_pos, const std::string& command, const int& value);
    //void make_checkbox(/*konstruktor argument f�r checkBox*/){}
    bool makeTextbox(const std::string& text, const int& x, const int& y, const int& w, const int& h,
					  const SDL_Color &col = {255,255,255,0}, const std::string& font = "Fonts/LHANDW.TTF", const unsigned& size = 13);
    void paint(SDL_Surface* screen);
    void setText(const int& where, const std::string& what_text);
  };  
}//namnrymd
#endif
