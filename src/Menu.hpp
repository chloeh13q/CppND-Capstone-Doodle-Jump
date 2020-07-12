#ifndef Menu_hpp
#define Menu_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Camera.hpp"
#include <map>
#include <string>

struct MenuItem {
    const char* label;
    SDL_Surface* menu;
    bool selected = false;
    SDL_Rect pos;
};

class Menu {
public:
    inline static Menu* GetInstance() { return instance = (instance != nullptr)? instance : new Menu; }
    void Clean();
    void SelectMenu(int x, int y);
    void Click(int x, int y);
    MenuItem* GetMenu(std::string id) { return menuMap[id]; }
    
private:
    static Menu* instance;
    Menu();
    TTF_Font* font;
    int numItems = 1;
    std::map<std::string, MenuItem*> menuMap;
//    SDL_Color colors[2];
};

#endif /* Menu_hpp */
