#include "CollisionHandler.hpp"
#include "Game.hpp"
#include "TileLayer.hpp"

CollisionHandler* CollisionHandler::instance = nullptr;

CollisionHandler::CollisionHandler() {
    collisionLayer = (TileLayer*)Game::GetInstance()->GetMap()->GetMapLayers().front();
    collisionTileMap = collisionLayer->GetTileMap();
}

bool CollisionHandler::MapCollision(SDL_Rect a) {
    int tileSize = 16;
    int rowCount = 400;
    int colCount = 50;
    
    int left_tile = a.x / tileSize;
    int right_tile = (a.x + a.w) / tileSize;
    int top_tile = a.y / tileSize;
    int bottom_tile = (a.y + a.h) / tileSize;
    
    if (left_tile < 0) left_tile = 0;
    if (right_tile > colCount) right_tile = colCount;
    if (top_tile < 0) top_tile = 0;
    if (bottom_tile > rowCount) bottom_tile = rowCount;
    
    for (int i = left_tile; i <= right_tile; i++) {
        for (int j = top_tile; j <= bottom_tile; j++) {
            if (collisionTileMap[j][i] > 0) {
                return true;
            }
        }
    }
    return false;
}

void CollisionHandler::Clean() {
    free(instance);
}
