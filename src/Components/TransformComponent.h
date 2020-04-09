#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include <string>
#include "../EntityManager.h"
#include "../../lib/glm/glm.hpp"
#include "../Game.h"

class TransformComponent: public Component
{
  public:
    glm::vec2 position;
    glm::vec2 velocity;
    int width;
    int height;
    int scale;

    TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s) : Component("TransformComponent") {
      position = glm::vec2(posX, posY);
      velocity = glm::vec2(velX, velY);
      width = w;
      height = h;
      scale = s;
    }

    void Initialize() override {

    }

    void Update(float deltaTime) override {
      position.x += velocity.x * deltaTime;
      position.y += velocity.y * deltaTime;
    }

    void Render() override {

    }
};

#endif
