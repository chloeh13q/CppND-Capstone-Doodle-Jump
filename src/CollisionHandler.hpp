#ifndef CollisionHandler_hpp
#define CollisionHandler_hpp

#include <SDL2/SDL.h>
// #include "TileLayer.hpp"
#include "GameMap.h"

class Tileset;
using TileMap = std::vector<std::vector<int> >;
class TileLayer;

class CollisionHandler {
public:
    inline static CollisionHandler* GetInstance() { return instance = (instance != nullptr)? instance : new CollisionHandler; }
    // bool CheckCollision(SDL_Rect a, SDL_Rect B);
    bool MapCollision(SDL_Rect a);
    void Clean();
    
private:
    static CollisionHandler* instance;
    CollisionHandler();
    TileMap collisionTileMap;
    TileLayer* collisionLayer;
};

#endif /* CollisionHandler_hpp */
