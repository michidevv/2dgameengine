#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include "Entity.h"
#include "Component.h"
#include "Constants.h"

class EntityManager
{
  private:
    std::vector<Entity *> entities;
  public:
    void ClearData();
    void Update(float deltaTime);
    void Render();
    bool HasNoEntities();
    Entity& AddEntity(std::string entityName, LayerType layer);
    std::vector<Entity*> GetEntities() const;
    std::vector<Entity*> GetEntitiesByLayer(LayerType layer) const;
    void LogEntities() const ;
    void LogEntitiesAndComponents() const;
    unsigned int GetEntityCount();
};

#endif
