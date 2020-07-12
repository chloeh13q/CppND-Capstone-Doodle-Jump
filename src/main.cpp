#include "Game.hpp"
#include "Timer.hpp"

Game *game = nullptr;

int main(int argc, const char * argv[]) {
    
    constexpr std::size_t kFramesPerSecond{60}; // close to the refresh rate of standard monitors
    constexpr std::size_t kFrameDelay{1000 / kFramesPerSecond}; // max time between frames
    constexpr std::size_t kScreenWidth{800};
    constexpr std::size_t kScreenHeight{800};
    
    Uint32 frameStart;
    int frameTime;
    
    Game::GetInstance()->Init("Doodle Jump", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, kScreenWidth, kScreenHeight, false);
    
    while (Game::GetInstance()->Running()) {
        frameStart = SDL_GetTicks();
        Timer::GetInstance()->Tick();
        Game::GetInstance()->HandleEvents();
        Game::GetInstance()->Update();
        Game::GetInstance()->Render();
        
        
        frameTime = SDL_GetTicks() - frameStart;

        if (kFrameDelay > frameTime)
        {
            SDL_Delay(kFrameDelay - frameTime);
        }
    }
    
    Game::GetInstance()->Clean();
    
    return 0;
}
