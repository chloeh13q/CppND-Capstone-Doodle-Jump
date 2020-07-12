#include "Inputs.hpp"
#include "Game.hpp"
#include "Menu.hpp"

Input* Input::instance = nullptr;

Input::Input() {
    keyStates = SDL_GetKeyboardState(nullptr);
}

void Input::Listen() {
    
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT: Game::GetInstance()->Quit(); break;
            case SDL_KEYDOWN: KeyDown(); break;
            case SDL_KEYUP: KeyUp(); break;
            case SDL_MOUSEMOTION: Menu::GetInstance()->SelectMenu(event.motion.x, event.motion.y); break;
            case SDL_MOUSEBUTTONDOWN: Menu::GetInstance()->Click(event.button.x, event.button.y); break;
        }
    }
}

bool Input::GetKeyDown(SDL_Scancode key) {
    if (keyStates[key] == 1) {
        return true;
    }
    return false;
}

void Input::KeyUp() {
    keyStates = SDL_GetKeyboardState(nullptr);
}

void Input::KeyDown() {
    keyStates = SDL_GetKeyboardState(nullptr);
}

void Input::Clean() {
    free(instance);
}
