#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include "Doodle.hpp"
#include "GameMap.h"
#include "Score.hpp"

class Input;
class Doodle;

class Game {
public:
    Game();
    ~Game();
    
    static Game* GetInstance() {
           return instance = (instance != nullptr)? instance : new Game();
       }
    
    void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Quit();
    void Clean();
    
    void LoadGame() { loadGame = true; }
    bool GameOn() { return loadGame; } // used to load game after menu
    
    bool Running() { return isRunning; } // used for launching game system
    
    inline GameMap* GetMap() { return map; }
    
    static SDL_Renderer* renderer;
    static SDL_Event event;

private:
    bool isRunning = false;
    bool loadGame = false;
    SDL_Window* window;
    static Game* instance;
    Doodle* doodle;
    GameMap* map;
    int score = 0;
};
#endif /* Game_hpp */
