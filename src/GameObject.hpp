#ifndef GameObject_hpp
#define GameObject_hpp

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "Vector2D.h"
#include <string>

struct Properties {
    
public:
    int X, Y;
    int width, height;
    std::string textureID;
    SDL_RendererFlip flip;
    
    Properties(std::string tID, int x, int y, int w, int h, SDL_RendererFlip f = SDL_FLIP_NONE) {
        X = x;
        Y = y;
        width = w;
        height = h;
        textureID = tID;
        flip = f;
    }
};

class GameObject {
    
public:
    GameObject(Properties* props) : textureID(props->textureID), width(props->width), height(props->height), flip(props->flip) {
        transform = new Transform(props->X, props->Y);
        

    }
    
    //~GameObject();
    
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    // virtual void Clean() = 0;
    
private:
    Transform* transform;
    int width, height;
    std::string textureID;
    SDL_RendererFlip flip;
};

#endif /* GameObject_hpp */
