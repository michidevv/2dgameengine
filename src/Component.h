#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Entity;

class Component
{
  private:
    std::string name;
  public:
    Entity* owner;
    Component(std::string name) : name(name) {}
    virtual ~Component() {}
    virtual std::string GetName() { return name; }
    virtual void Initialize() {}
    virtual void Update(float deltaTime) {}
    virtual void Render() {}
};

#endif
