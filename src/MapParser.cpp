#include "MapParser.hpp"

MapParser* MapParser::instance = nullptr;

bool MapParser::Load() {
    return Parse("map", "../assets/map1.tmx");
}

void MapParser::Clean() {
    std::map<std::string, GameMap*>::iterator it;
    for (it = maps.begin(); it != maps.end(); it++) {
        it->second = nullptr;
    }
    maps.clear();
}

bool MapParser::Parse(std::string id, std::string source) {
    TiXmlDocument xml;
    xml.LoadFile(source);
    
    if (xml.Error()) {
        std::cerr << "Failed to load " << source << std::endl;
        return false;
    }
    
    TiXmlElement* root = xml.RootElement();
    int rowcount, colcount, tilesize;
    root->Attribute("width", &colcount);
    root->Attribute("height", &rowcount);
    root->Attribute("tilewidth", &tilesize);
    
    // Parse tilesets
    TilesetList tilesets;
    for (TiXmlElement* e = root->FirstChildElement(); e!= nullptr; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("tileset")) {
            tilesets.push_back(ParseTileset(e));
        }
    }
    
    // Parse layers
    GameMap* gamemap = new GameMap();
    for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("layer")) {
            TileLayer* tilelayer = ParseTileLayer(e, tilesets, tilesize, rowcount, colcount);
            gamemap->mapLayers.push_back(tilelayer);
        }
    }
    
    maps[id] = gamemap;
    return true;
}

Tileset MapParser::ParseTileset(TiXmlElement *xmlTileset) {
    Tileset tileset;
    
    tileset.name = xmlTileset->Attribute("name");
    xmlTileset->Attribute("firstgid", &tileset.firstID);
    xmlTileset->Attribute("tilecount", &tileset.tileCount);
    tileset.lastID = tileset.firstID + tileset.tileCount - 1;
    xmlTileset->Attribute("columns", &tileset.colCount);
    tileset.rowCount = tileset.tileCount / tileset.colCount;
    xmlTileset->Attribute("tilewidth", &tileset.tileSize);
    
    TiXmlElement* image  = xmlTileset->FirstChildElement();
    tileset.source = image->Attribute("source");
    
    return tileset;
}

TileLayer* MapParser::ParseTileLayer(TiXmlElement *xmlLayer, TilesetList tsets, int tsize, int rows, int cols) {
    
    TiXmlElement* data;
    for (TiXmlElement* e = xmlLayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("data")) {
            data = e;
            break;
        }
    }
    
    std::string matrix(data->GetText());
    std::istringstream iss(matrix);
    std::string id;
    
    TileMap tilemap(rows, std::vector<int>(cols, 0));
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            getline(iss, id, ',');
            std::stringstream converter(id);
            converter >> tilemap[r][c];
            
            if (!iss.good()) {
                break;
            }
        }
    }
    
    return (new TileLayer(tsize, rows, cols, tilemap, tsets));
}

