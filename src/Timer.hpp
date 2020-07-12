#ifndef Timer_hpp
#define Timer_hpp

#include <SDL2/SDL.h>

const int TARGET_FPS = 60;
const float TARGET_DELTATIME = 1.5f;

class Timer {
public:
    inline static Timer* GetInstance() { return instance = (instance != nullptr)? instance : new Timer(); }
    void Tick();
    inline float GetDeltaTime() { return deltaTime; }
    void Clean();
    
private:
    Timer() {}
    static Timer* instance;
    float deltaTime;
    float lastTime;
};

#endif /* Timer_hpp */
