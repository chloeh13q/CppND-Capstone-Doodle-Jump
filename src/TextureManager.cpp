#include "TextureManager.h"
#include "Menu.hpp"
#include <iostream>

TextureManager* TextureManager::instance = nullptr;

SDL_Texture* TextureManager::LoadTexture(const char* fileName, std::string id) {
    SDL_Surface* tmpSurface = IMG_Load(fileName);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    textureMap[id] = tex;
    
    return tex;
}

void TextureManager::Render(std::string id, int x, int y, int w, int h, SDL_RendererFlip f) {
    SDL_Rect srcRect = {0, 0, w, h};
    SDL_Rect destRect = {x, y, w, h};
    SDL_RenderCopyEx(Game::renderer, textureMap[id], &srcRect, &destRect, 0, nullptr, f);
}

void TextureManager::DrawTile(std::string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip) {
    SDL_Rect srcRect = {tileSize * frame, tileSize * row, tileSize, tileSize};
    Vector2D cam = Camera::GetInstance()->GetPosition();
    
    SDL_Rect destRect = {x - cam.x, y - cam.y, tileSize, tileSize};
    SDL_RenderCopyEx(Game::renderer, textureMap[tilesetID], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::RenderText(std::string id, int x, int y, int w, int h, SDL_RendererFlip f) {
    SDL_Texture* menuTexture = SDL_CreateTextureFromSurface(Game::renderer, Menu::GetInstance()->GetMenu(id)->menu);
    if (menuTexture == NULL) {
        std::cout << "Failed to create texture from rendered text!" << std::endl;
    }
    SDL_Rect srcRect = {0, 0, w, h};
    SDL_Rect destRect = {x, y, w, h};
    SDL_RenderCopyEx(Game::renderer, menuTexture, &srcRect, &destRect, 0, 0, f);
}

void TextureManager::LoadFont(const char *filePath) {
    if (TTF_Init() == -1) {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
    } else {
        font = TTF_OpenFont(filePath, 20);
        if (font == NULL) {
            printf("TTF_OpenFont: %s\n", TTF_GetError());
            std::cout << "Failed to load font!" << std::endl;
        }
    }
}

void TextureManager::RenderScore(int score, int x, int y, int w, int h, SDL_RendererFlip f) {
    std::string display;
    display = "Score: " + std::to_string(score);
    SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, display.c_str(), {0, 0, 0});
    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(Game::renderer, scoreSurface);
    if (scoreTexture == NULL) {
        std::cout << "Failed to create texture from rendered text!" << std::endl;
    }
    SDL_FreeSurface(scoreSurface);
    
    SDL_Rect srcRect = {0, 0, w, h};
    SDL_Rect destRect = {x, y, w, h};
    SDL_RenderCopyEx(Game::renderer, scoreTexture, &srcRect, &destRect, 0, 0, f);
}
