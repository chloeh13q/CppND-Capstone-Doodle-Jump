#ifndef GameMap_h
#define GameMap_h

#include <vector>
#include "Layer.hpp"

class GameMap {
public:
    void Render() {
        for (unsigned int i = 0; i < mapLayers.size(); i++) {
            mapLayers[i]->Render();
        }
    }
    
    void Update() {
        for (unsigned int i = 0; i < mapLayers.size(); i++) {
            mapLayers[i]->Update();
        }
    }
    
    std::vector<Layer*> GetMapLayers() { return mapLayers; }
    
private:
    friend class MapParser;
    std::vector<Layer*> mapLayers;
};

#endif /* GameMap_h */
