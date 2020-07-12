#include "Game.hpp"
#include "MapParser.hpp"
#include <string>
#include "Camera.hpp"
#include "Timer.hpp"
#include "Menu.hpp"

Game* Game::instance = nullptr;
Properties* props;
SDL_Renderer* Game::renderer = nullptr;
Score* Score::instance = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::Init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
//        std::cout << "Subsystems initialized successfully..." << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
//        if (window) {
//            std::cout << "Window created successfully..." << std::endl;
//        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//            std::cout << "Renderer created successfully..." << std::endl;
        }
        
        isRunning = true;
    }
    
//    if (!MapParser::GetInstance()->Load()) {
//        std::cout << "Failed to load map" << std::endl;
//    }
    MapParser::GetInstance()->Load();
    map = MapParser::GetInstance()->GetMap("map");
    
    props = new Properties("../assets/doodle.png", 0, 0, 80, 80);
    doodle = new Doodle(props);
    TextureManager::GetInstance()->LoadTexture("../assets/doodle.png", "doodle");
    TextureManager::GetInstance()->LoadTexture("../assets/background.png", "background");
    Camera::GetInstance()->SetTarget(doodle->GetOrigin());
    TextureManager::GetInstance()->LoadFont("../assets/DoodleJump.ttf");
}

void Game::HandleEvents() {
    Input::GetInstance()->Listen();
}

void Game::Update() {
    //float dt = Timer::GetInstance()->GetDeltaTime();
    if (loadGame) {
        //Score::GetInstance()->IncreaseScore(1);
        map->Update();
        doodle->Update(0.5);
        Camera::GetInstance()->Update(0.5);
    }
}

void Game::Render() {
    SDL_RenderClear(renderer);
    TextureManager::GetInstance()->Render("background", 0, 0, 800, 800);
    TextureManager::GetInstance()->RenderText("Play", 200, 300, 400, 200, SDL_FLIP_NONE);
    if (loadGame) {
        map->Render();
        TextureManager::GetInstance()->RenderScore(Score::GetInstance()->GetScore(), 550, 0, 200, 100, SDL_FLIP_NONE);
        doodle->Render();
    }
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderPresent(renderer);
}

void Game::Quit() {
    isRunning = false;
}

void Game::Clean() {
    doodle->Clean();
    free(props);
    free(doodle);
    
    MapParser::GetInstance()->Clean();
    Input::GetInstance()->Clean();
    Camera::GetInstance()->Clean();
    CollisionHandler::GetInstance()->Clean();
    Timer::GetInstance()->Clean();
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}
