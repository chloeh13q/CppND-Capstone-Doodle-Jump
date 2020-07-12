#include "Timer.hpp"

Timer* Timer::instance = nullptr;

void Timer::Tick() {
    deltaTime = (SDL_GetTicks() - lastTime) * (TARGET_FPS / 1000.0f);
    
    if (deltaTime > TARGET_DELTATIME) {
        deltaTime = 1.5f;
    }
    lastTime = SDL_GetTicks();
}

void Timer::Clean() {
    free(instance);
}
