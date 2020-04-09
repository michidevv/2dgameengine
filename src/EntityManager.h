#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include "Entity.h"
#include "Component.h"

class EntityManager
{
  private:
    std::vector<Entity *> entities;
  public:
    void ClearData();
    void Update(float deltaTime);
    void Render();
    bool HasNoEntities();
    Entity& AddEntity(std::string entityName);
    std::vector<Entity*> GetEntities() const;
    void LogEntities() const ;
    void LogEntitiesAndComponents() const;
    unsigned int GetEntityCount();
};

#endif
