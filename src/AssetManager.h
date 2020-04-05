#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <string>
#include "EntityManager.h"

class AssetManager
{
  private:
    EntityManager* manager;
    std::map<std::string, SDL_Texture*> textures;
};

#endif
