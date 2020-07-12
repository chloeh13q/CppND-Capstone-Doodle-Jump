#ifndef MapParser_hpp
#define MapParser_hpp

#include <map>
#include <string>
#include "TileLayer.hpp"
#include "GameMap.h"
#include "vendors/tinyxml/tinyxml.h"

class MapParser {
public:
    inline static MapParser* GetInstance() { return instance = (instance != nullptr)? instance : new MapParser(); }
    bool Load();
    void Clean();
    
    inline GameMap* GetMap(std::string id) { return maps[id]; }
    bool Parse(std::string id, std::string source);
    
private:
    MapParser() {}
    static MapParser* instance;
    std::map<std::string, GameMap*> maps;
    
    Tileset ParseTileset(TiXmlElement* xmlTileset);
    TileLayer* ParseTileLayer(TiXmlElement* xmlLayer, TilesetList tsets, int tsize, int rows, int cols);
};

#endif /* MapParser_hpp */
