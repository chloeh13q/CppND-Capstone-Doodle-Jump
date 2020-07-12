#ifndef TileLayer_hpp
#define TileLayer_hpp

#include "Layer.hpp"
#include <string>
#include <vector>
#include "TextureManager.h"

struct Tileset {
    int firstID, lastID;
    int rowCount, colCount;
    int tileCount, tileSize;
    std::string name, source;
};

using TilesetList = std::vector<Tileset>;
using TileMap = std::vector<std::vector<int> >;

class TileLayer : public Layer {
public:
    TileLayer(int size, int rows, int cols, TileMap tmap, TilesetList tslist);
    void Render();
    void Update();
    inline TileMap GetTileMap() { return tileMap; }
    
private:
    int tileSize;
    int rowCount, colCount;
    
    TileMap tileMap;
    TilesetList tileSets;
};

#endif /* TileLayer_hpp */
