#include <iostream>
#include "../lib/glm/glm.hpp"
#include "Constants.h"
#include "Game.h"
#include "EntityManager.h"
#include "Component.h"
#include "./Components/TransformComponent.h";

EntityManager manager;
SDL_Renderer *Game::renderer;

Game::Game() {
  isRunning = false;
}

Game::~Game() {

}

bool Game::IsRunning() const {
  return isRunning;
}

void Game::LoadLevel(int levelNumber) {
  // Add more entities with components.
  Entity& newEntity(manager.AddEntity("projectile"));

  newEntity.AddComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);
  newEntity.AddComponent<TransformComponent>(
    WINDOW_WIDTH - 16,
    WINDOW_HEIGHT - 16,
    -20,
    -20,
    16,
    16,
    1
    );

    Entity& circleEnity = manager.AddEntity("circle_projectile");
    circleEnity.AddComponent<TransformComponent>(
      WINDOW_WIDTH / 2 - 32,
      WINDOW_HEIGHT / 2 - 32,
      15,
      -15,
      32,
      32,
      1
    );

    manager.LogEntitiesAndComponents();
}

void Game::Initialize(int width, int height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Error initialising SDL." << std::endl;
    return;
  }

  this->window = SDL_CreateWindow(
    NULL,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    width,
    height,
    SDL_WINDOW_SHOWN
  );

  if (!window) {
    std::cerr << "Error creating SDL window." << std::endl;
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    std::cerr << "Error creating SDL renderer." << std::endl;
    return;
  }

  LoadLevel(0);

  isRunning = true;
}

void Game::ProcessInput() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    isRunning = false;
    break;
  case SDL_KEYDOWN:
    if (event.key.keysym.sym == SDLK_ESCAPE) {
      isRunning = false;
    }
  default:
    break;
  }
}

void Game::Update() {
  // Wait until 16ms has ellapsed since the last frame
  // while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TARGET_TIME));
  int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);
  if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) {
    SDL_Delay(timeToWait);
  }

  // Delta time is the difference in ticks from last frame converted to seconds
  float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

  // Clamp delta time to a maximum value
  deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

  // Sets the new ticks for the current frame to be used in the next pass
  ticksLastFrame = SDL_GetTicks();

  manager.Update(deltaTime);
}

void Game::Render() {
  SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
  SDL_RenderClear(renderer);

  if (manager.HasNoEntities()) {
    return;
  }

  manager.Render();

  SDL_RenderPresent(renderer);
}

void Game::Destroy() {
  std::cout << "Destroy" << std::endl;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}


