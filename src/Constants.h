#ifndef CONSTANTS_H
#define CONSTANTS_H

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

const unsigned int FPS = 60;
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;

enum LayerType
{
  TILEMAP_LAYER = 0,
  VEGETATION_LAYER,
  ENEMY_LAYER,
  PLAYER_LAYER,
  PROJECTIVE_LAYER,
  UI_LAYER
};

const unsigned int NUM_LAYER = 6;

#endif
