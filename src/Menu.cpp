#include "Menu.hpp"
#include "Game.hpp"
#include <iostream>

Menu* Menu::instance = nullptr;

Menu::Menu() {
//    int mouse_x, mouse_y;
//    const char* labels[numItems] = {"Start", "Quit"};
//    SDL_Surface* menus[numItems];
//    bool selected[numItems] = {0, 0};
//    SDL_Color colors[2] = {{255, 255, 255}, {255, 0, 0}};
    if (TTF_Init() == -1) {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
    } else {
        font = TTF_OpenFont("../assets/DoodleJump.ttf", 20);
        if (font == NULL) {
            printf("TTF_OpenFont: %s\n", TTF_GetError());
            std::cout << "Failed to load font!" << std::endl;
        }
    }
    
    MenuItem* contMenu;
    contMenu = new MenuItem;
//    contMenu.color = {255, 255, 255};
    contMenu->label = "Play";
    contMenu->menu = TTF_RenderText_Solid(font, contMenu->label, {0, 0, 0});
    if (contMenu->menu == NULL) {
        std::cout << "Failed to render text surface!" << std::endl;
    }
    contMenu->pos.x = SCREEN_WIDTH / 2;
    contMenu->pos.y = SCREEN_HEIGHT / 2;
    contMenu->pos.w = 100;
    contMenu->pos.h = 30;
    menuMap[contMenu->label] = contMenu;
    
    
}

void Menu::SelectMenu(int x, int y) {
    if (!Game::GetInstance()->GameOn()) {
        std::map<std::string, MenuItem*>::iterator it;
        for (it = menuMap.begin(); it != menuMap.end(); it++) {
            if (x >= it->second->pos.x && x <= it->second->pos.x + it->second->pos.w && y >= it->second->pos.y && y <= it->second->pos.y + it->second->pos.h) {
                if (!it->second->selected) {
                    it->second->selected = true;
                    SDL_FreeSurface(it->second->menu);
                    it->second->menu = TTF_RenderText_Solid(font, it->second->label, {255, 0, 0});
                }
            } else {
                if (it->second->selected) {
                    it->second->selected = false;
                    SDL_FreeSurface(it->second->menu);
                    it->second->menu = TTF_RenderText_Solid(font, it->second->label, {0, 0, 0});
                    
                }
                
            }
        }
    }
}

void Menu::Click(int x, int y) {
    if (!Game::GetInstance()->GameOn()) {
        std::map<std::string, MenuItem*>::iterator it;
           for (it = menuMap.begin(); it != menuMap.end(); it++) {
               if (x >= it->second->pos.x && x <= it->second->pos.x + it->second->pos.w && y >= it->second->pos.y && y <= it->second->pos.y + it->second->pos.h) {
                   Game::GetInstance()->LoadGame();
                   SDL_FreeSurface(it->second->menu);
                   it->second->menu = TTF_RenderText_Solid(font, " ", {255, 255, 255});
                   
               }
           }
    }
   
}

void Menu::Clean() {
    free(instance);
}
