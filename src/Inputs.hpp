#ifndef Inputs_hpp
#define Inputs_hpp

#include <SDL2/SDL.h>

class Input {
    
public:
    static Input* GetInstance() {
        return instance = (instance != nullptr)? instance : new Input();
    }
    
    void Listen();
    bool GetKeyDown(SDL_Scancode key);
    void Clean();
    
private:
    static Input* instance;
    Input();
    void KeyUp();
    void KeyDown();

    const Uint8* keyStates;
};

#endif /* Inputs_hpp */
