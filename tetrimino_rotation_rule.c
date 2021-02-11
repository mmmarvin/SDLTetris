#include <assert.h>
#include <stdlib.h>
#include "tetrimino_rotation_rule.h"

struct TetriminoRotationRule initializeTetriminoRule(int type)
{
  // Create rotation rule based on TGM Rotation System / Arika Rotation System
  // https://tetris.wiki/Arika_Rotation_System
  struct TetriminoRotationRule ret;
  ret.rotation = NULL;
  ret.numberOfRotations = 0;

  assert(type == Tetrimino_I ||
         type == Tetrimino_J ||
         type == Tetrimino_L ||
         type == Tetrimino_O ||
         type == Tetrimino_S ||
         type == Tetrimino_T ||
         type == Tetrimino_Z);

  if(type == Tetrimino_I) {
    ret.rotation = (Tetrimino*) malloc(sizeof(Tetrimino) * 2);
    ret.numberOfRotations = 2;

    // rotation 1
    ret.rotation[0].block[0].x = -2;
    ret.rotation[0].block[0].y = 1;

    ret.rotation[0].block[1].x = -1;
    ret.rotation[0].block[1].y = 0;

    ret.rotation[0].block[2].x = 0;
    ret.rotation[0].block[2].y = -1;

    ret.rotation[0].block[3].x = 1;
    ret.rotation[0].block[3].y = -2;

    // rotation 2
    ret.rotation[1].block[0].x = 2;
    ret.rotation[1].block[0].y = -1;

    ret.rotation[1].block[1].x = 1;
    ret.rotation[1].block[1].y = 0;

    ret.rotation[1].block[2].x = 0;
    ret.rotation[1].block[2].y = 1;

    ret.rotation[1].block[3].x = -1;
    ret.rotation[1].block[3].y = 2;
  } else if(type == Tetrimino_J) {
    ret.rotation = (Tetrimino*) malloc(sizeof(Tetrimino) * 4);
    ret.numberOfRotations = 4;

    // rotation 1
    ret.rotation[0].block[0].x = -1;
    ret.rotation[0].block[0].y = -1;

    ret.rotation[0].block[1].x = 0;
    ret.rotation[0].block[1].y = 0;

    ret.rotation[0].block[2].x = 1;
    ret.rotation[0].block[2].y = 1;

    ret.rotation[0].block[3].x = 0;
    ret.rotation[0].block[3].y = 2;

    // rotation 2
    ret.rotation[1].block[0].x = 1;
    ret.rotation[1].block[0].y = -1;

    ret.rotation[1].block[1].x = 0;
    ret.rotation[1].block[1].y = 0;

    ret.rotation[1].block[2].x = -1;
    ret.rotation[1].block[2].y = 1;

    ret.rotation[1].block[3].x = -2;
    ret.rotation[1].block[3].y = 0;

    // rotation 3
    ret.rotation[2].block[0].x = 1;
    ret.rotation[2].block[0].y = 2;

    ret.rotation[2].block[1].x = 0;
    ret.rotation[2].block[1].y = 1;

    ret.rotation[2].block[2].x = -1;
    ret.rotation[2].block[2].y = 0;

    ret.rotation[2].block[3].x = 0;
    ret.rotation[2].block[3].y = -1;

    // rotation 4
    ret.rotation[3].block[0].x = -1;
    ret.rotation[3].block[0].y = 0;

    ret.rotation[3].block[1].x = 0;
    ret.rotation[3].block[1].y = -1;

    ret.rotation[3].block[2].x = 1;
    ret.rotation[3].block[2].y = -2;

    ret.rotation[3].block[3].x = 2;
    ret.rotation[3].block[3].y = -1;
  } else if(type == Tetrimino_L) {
    ret.rotation = (Tetrimino*) malloc(sizeof(Tetrimino) * 4);
    ret.numberOfRotations = 4;

    // rotation 1
    ret.rotation[0].block[0].x = 1;
    ret.rotation[0].block[0].y = 1;

    ret.rotation[0].block[1].x = 0;
    ret.rotation[0].block[1].y = 0;

    ret.rotation[0].block[2].x = -1;
    ret.rotation[0].block[2].y = -1;

    ret.rotation[0].block[3].x = -2;
    ret.rotation[0].block[3].y = 0;

    // rotation 2
    ret.rotation[1].block[0].x = -1;
    ret.rotation[1].block[0].y = 1;

    ret.rotation[1].block[1].x = 0;
    ret.rotation[1].block[1].y = 0;

    ret.rotation[1].block[2].x = 1;
    ret.rotation[1].block[2].y = -1;

    ret.rotation[1].block[3].x = 0;
    ret.rotation[1].block[3].y = -2;

    // rotation 3
    ret.rotation[2].block[0].x = -1;
    ret.rotation[2].block[0].y = 0;

    ret.rotation[2].block[1].x = 0;
    ret.rotation[2].block[1].y = 1;

    ret.rotation[2].block[2].x = 1;
    ret.rotation[2].block[2].y = 2;

    ret.rotation[2].block[3].x = 2;
    ret.rotation[2].block[3].y = 1;

    // rotation 4
    ret.rotation[3].block[0].x = 1;
    ret.rotation[3].block[0].y = -2;

    ret.rotation[3].block[1].x = 0;
    ret.rotation[3].block[1].y = -1;

    ret.rotation[3].block[2].x = -1;
    ret.rotation[3].block[2].y = 0;

    ret.rotation[3].block[3].x = 0;
    ret.rotation[3].block[3].y = 1;
  } else if(type == Tetrimino_S) {
    ret.rotation = (Tetrimino*) malloc(sizeof(Tetrimino) * 2);
    ret.numberOfRotations = 2;

    // rotation 1
    ret.rotation[0].block[0].x = 1;
    ret.rotation[0].block[0].y = -1;

    ret.rotation[0].block[1].x = 0;
    ret.rotation[0].block[1].y = 0;

    ret.rotation[0].block[2].x = 1;
    ret.rotation[0].block[2].y = 1;

    ret.rotation[0].block[3].x = 0;
    ret.rotation[0].block[3].y = 2;

    // rotation 2
    ret.rotation[1].block[0].x = -1;
    ret.rotation[1].block[0].y = 1;

    ret.rotation[1].block[1].x = 0;
    ret.rotation[1].block[1].y = 0;

    ret.rotation[1].block[2].x = -1;
    ret.rotation[1].block[2].y = -1;

    ret.rotation[1].block[3].x = 0;
    ret.rotation[1].block[3].y = -2;
  } else if(type == Tetrimino_T) {
    ret.rotation = (Tetrimino*) malloc(sizeof(Tetrimino) * 4);
    ret.numberOfRotations = 4;

    // rotation 1
    ret.rotation[0].block[0].x = -1;
    ret.rotation[0].block[0].y = -1;

    ret.rotation[0].block[1].x = 0;
    ret.rotation[0].block[1].y = 0;

    ret.rotation[0].block[2].x = 1;
    ret.rotation[0].block[2].y = 1;

    ret.rotation[0].block[3].x = -1;
    ret.rotation[0].block[3].y = 1;

    // rotation 2
    ret.rotation[1].block[0].x = 1;
    ret.rotation[1].block[0].y = -1;

    ret.rotation[1].block[1].x = 0;
    ret.rotation[1].block[1].y = 0;

    ret.rotation[1].block[2].x = -1;
    ret.rotation[1].block[2].y = 1;

    ret.rotation[1].block[3].x = -1;
    ret.rotation[1].block[3].y = -1;

    // rotation 3
    ret.rotation[2].block[0].x = 1;
    ret.rotation[2].block[0].y = 2;

    ret.rotation[2].block[1].x = 0;
    ret.rotation[2].block[1].y = 1;

    ret.rotation[2].block[2].x = -1;
    ret.rotation[2].block[2].y = 0;

    ret.rotation[2].block[3].x = 1;
    ret.rotation[2].block[3].y = 0;

    // rotation 4
    ret.rotation[3].block[0].x = -1;
    ret.rotation[3].block[0].y = 0;

    ret.rotation[3].block[1].x = 0;
    ret.rotation[3].block[1].y = -1;

    ret.rotation[3].block[2].x = 1;
    ret.rotation[3].block[2].y = -2;

    ret.rotation[3].block[3].x = 1;
    ret.rotation[3].block[3].y = 0;
  } else if(type == Tetrimino_Z) {
    ret.rotation = (Tetrimino*) malloc(sizeof(Tetrimino) * 2);
    ret.numberOfRotations = 2;

    // rotation 1
    ret.rotation[0].block[0].x = -1;
    ret.rotation[0].block[0].y = -1;

    ret.rotation[0].block[1].x = 0;
    ret.rotation[0].block[1].y = 0;

    ret.rotation[0].block[2].x = -1;
    ret.rotation[0].block[2].y = 1;

    ret.rotation[0].block[3].x = 0;
    ret.rotation[0].block[3].y = 2;

    // rotation 2
    ret.rotation[1].block[0].x = 1;
    ret.rotation[1].block[0].y = 1;

    ret.rotation[1].block[1].x = 0;
    ret.rotation[1].block[1].y = 0;

    ret.rotation[1].block[2].x = 1;
    ret.rotation[1].block[2].y = -1;

    ret.rotation[1].block[3].x = 0;
    ret.rotation[1].block[3].y = -2;
  }

  return ret;
}

// do not modify
struct TetriminoRotationRule TETRIMINO_I_ROTATION;
struct TetriminoRotationRule TETRIMINO_J_ROTATION;
struct TetriminoRotationRule TETRIMINO_L_ROTATION;
struct TetriminoRotationRule TETRIMINO_O_ROTATION;
struct TetriminoRotationRule TETRIMINO_S_ROTATION;
struct TetriminoRotationRule TETRIMINO_T_ROTATION;
struct TetriminoRotationRule TETRIMINO_Z_ROTATION;

void tetriminoRulesInitialize()
{
  TETRIMINO_I_ROTATION = initializeTetriminoRule(Tetrimino_I);
  TETRIMINO_J_ROTATION = initializeTetriminoRule(Tetrimino_J);
  TETRIMINO_L_ROTATION = initializeTetriminoRule(Tetrimino_L);
  TETRIMINO_O_ROTATION = initializeTetriminoRule(Tetrimino_O);
  TETRIMINO_S_ROTATION = initializeTetriminoRule(Tetrimino_S);
  TETRIMINO_T_ROTATION = initializeTetriminoRule(Tetrimino_T);
  TETRIMINO_Z_ROTATION = initializeTetriminoRule(Tetrimino_Z);
}

void tetriminoRulesDestroy()
{
  free(TETRIMINO_I_ROTATION.rotation);
  free(TETRIMINO_J_ROTATION.rotation);
  free(TETRIMINO_L_ROTATION.rotation);
  free(TETRIMINO_O_ROTATION.rotation);
  free(TETRIMINO_S_ROTATION.rotation);
  free(TETRIMINO_T_ROTATION.rotation);
  free(TETRIMINO_Z_ROTATION.rotation);
}
