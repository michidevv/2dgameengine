#include "Map.h"
#include "Game.h"
#include "EntityManager.h"

Map::Map(std::string textureId, int scale, int tileSize) : textureId(textureId), scale(scale), tileSize(tileSize) {

}

Map::~Map() {

}

void Map::LoadMap(std::string filePath, int mapSizeX, int mapSizeY) {
  // Read the map definitions from .map file
}

void Map::AddTile(int sourceX, int sourceY, int x, int y) {
  // Add a new tile entity in the game scene
}
