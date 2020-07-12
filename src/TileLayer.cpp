#include "TileLayer.hpp"

TileLayer::TileLayer(int size, int rows, int cols, TileMap tmap, TilesetList tslist) : tileSize{size}, rowCount{rows}, colCount{cols}, tileMap{tmap}, tileSets{tslist} {
    for (unsigned int i = 0; i < tileSets.size(); i++) {
        TextureManager::GetInstance()->LoadTexture(("assets/" + tileSets[i].source).c_str(), tileSets[i].name);
    }
}

void TileLayer::Render() {
    for (unsigned int i = 0; i < rowCount; i++) {
        for (unsigned int j = 0; j < colCount; j++) {
            
            int tileID = tileMap[i][j];
            
            if (tileID == 0) {
                continue;
            } else {
                int tilesetIndex = 0;
                if (tileSets.size() > 1) {
                    // need to convert tile ID's
                    for (unsigned int k = 1; k < tileSets.size(); k++) {
                        if (tileID >= tileSets[k].firstID && tileID <= tileSets[k].lastID) {
                            tileID = tileID - tileSets[k].firstID + 1;
                            tilesetIndex = k;
                            break;
                        }
                       
                    }

                }
                Tileset ts = tileSets[tilesetIndex];
                int tileRow = tileID / ts.colCount;
                int tileCol = tileID - tileRow * ts.colCount - 1;
                
                if (tileID % ts.colCount == 0) {
                    tileRow--;
                    tileCol = ts.colCount - 1;
                }

                TextureManager::GetInstance()->DrawTile(ts.name, ts.tileSize, j * ts.tileSize, i * ts.tileSize, tileRow, tileCol, SDL_FLIP_NONE);
                
            }
        }
    }
}

void TileLayer::Update() {
    
}
