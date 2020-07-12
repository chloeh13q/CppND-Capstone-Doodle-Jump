#ifndef TextureManager_h
#define TextureManager_h

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Game.hpp"
#include "Camera.hpp"

class TextureManager {
    
public:
    static TextureManager* GetInstance() { return instance = (instance != nullptr)? instance : new TextureManager(); }
    SDL_Texture* LoadTexture(const char* fileName, std::string id);
    void Drop(std::string id);
    
    void Render(std::string id, int x, int y, int w, int h, SDL_RendererFlip f = SDL_FLIP_NONE);
    void DrawTile(std::string tileID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip);
    void RenderText(std::string id, int x, int y, int w, int h, SDL_RendererFlip f);
    void RenderScore(int score, int x, int y, int w, int h, SDL_RendererFlip f);
    void LoadFont(const char* filePath);
    TTF_Font* GetFont() { return font; }
    
private:
    TextureManager() {}
    static TextureManager* instance;
    std::map<std::string, SDL_Texture*> textureMap;
    TTF_Font* font;
};

#endif /* TextureManager_h */
