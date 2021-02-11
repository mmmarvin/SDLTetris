#include <memory.h>
#include <stdlib.h>

#include "game_field.h"
#include "tetrimino.h"
#include "tetrimino_rotation_rule.h"
#include "vector2.h"

Tetrimino currentTetrimino;
Tetrimino nextTetrimino;

void tetriminoCreate()
{
  int t = rand() % TetriminoCount;
//  int t = Tetrimino_L;
  nextTetrimino.type = t;

  switch(t) {
  case Tetrimino_I: {
    Vector2 vec;
    vec.x = GAME_FIELD_WIDTH / 2;
    vec.y = -2;

    vec.x -= 1;
    vec.y -= 1;
    nextTetrimino.block[0] = vec;

    vec.x += 1;
    nextTetrimino.block[1] = vec;

    vec.x += 1;
    nextTetrimino.block[2] = vec;

    vec.x += 1;
    nextTetrimino.block[3] = vec;

    nextTetrimino.rotationRule = &TETRIMINO_I_ROTATION;
    nextTetrimino.rotationIndex = 0;
    break;
  }
  case Tetrimino_J: {
    Vector2 vec;
    vec.x = GAME_FIELD_WIDTH / 2;
    vec.y = -1;

    vec.x -= 1;
    vec.y -= -1;
    nextTetrimino.block[0] = vec;

    vec.x += 1;
    nextTetrimino.block[1] = vec;

    vec.x += 1;
    nextTetrimino.block[2] = vec;

    vec.y += 1;
    nextTetrimino.block[3] = vec;

    nextTetrimino.rotationRule = &TETRIMINO_J_ROTATION;
    nextTetrimino.rotationIndex = 0;
    break;
  }
  case Tetrimino_L: {
    Vector2 vec;
    vec.x = GAME_FIELD_WIDTH / 2;
    vec.y = -1;

    vec.x += 1;
    vec.y -= 1;
    nextTetrimino.block[0] = vec;

    vec.x -= 1;
    nextTetrimino.block[1] = vec;

    vec.x -= 1;
    nextTetrimino.block[2] = vec;

    vec.y += 1;
    nextTetrimino.block[3] = vec;

    nextTetrimino.rotationRule = &TETRIMINO_L_ROTATION;
    nextTetrimino.rotationIndex = 0;
    break;
  }
  case Tetrimino_O: {
    Vector2 vec;
    vec.x = GAME_FIELD_WIDTH / 2;
    vec.y = -1;

    vec.x -= 1;
    vec.y -= 1;
    nextTetrimino.block[0] = vec;

    vec.x += 1;
    nextTetrimino.block[1] = vec;

    vec.y += 1;
    nextTetrimino.block[2] = vec;

    vec.x -= 1;
    nextTetrimino.block[3] = vec;

    nextTetrimino.rotationRule = &TETRIMINO_O_ROTATION;
    nextTetrimino.rotationIndex = 0;
    break;
  }
  case Tetrimino_S: {
    Vector2 vec;
    vec.x = GAME_FIELD_WIDTH / 2;
    vec.y = -1;

    vec.x += 1;
    vec.y -= 1;
    nextTetrimino.block[0] = vec;

    vec.x -= 1;
    nextTetrimino.block[1] = vec;

    vec.y += 1;
    nextTetrimino.block[2] = vec;

    vec.x -= 1;
    nextTetrimino.block[3] = vec;

    nextTetrimino.rotationRule = &TETRIMINO_S_ROTATION;
    nextTetrimino.rotationIndex = 0;
    break;
  }
  case Tetrimino_T: {
    Vector2 vec;
    vec.x = GAME_FIELD_WIDTH / 2;
    vec.y = -1;

    vec.x -= 1;
    vec.y -= 1;
    nextTetrimino.block[0] = vec;

    vec.x += 1;
    nextTetrimino.block[1] = vec;

    vec.x += 1;
    nextTetrimino.block[2] = vec;

    vec.x -= 1;
    vec.y += 1;
    nextTetrimino.block[3] = vec;

    nextTetrimino.rotationRule = &TETRIMINO_T_ROTATION;
    nextTetrimino.rotationIndex = 0;
    break;
  }
  case Tetrimino_Z: {
      Vector2 vec;
      vec.x = GAME_FIELD_WIDTH / 2;
      vec.y = -1;

      vec.x -= 1;
      vec.y -= 1;
      nextTetrimino.block[0] = vec;

      vec.x += 1;
      nextTetrimino.block[1] = vec;

      vec.y += 1;
      nextTetrimino.block[2] = vec;

      vec.x += 1;
      nextTetrimino.block[3] = vec;

      nextTetrimino.rotationRule = &TETRIMINO_Z_ROTATION;
      nextTetrimino.rotationIndex = 0;
      break;
    }
  }
}

void tetriminoCopy(Tetrimino* t1, Tetrimino* t2)
{
  memcpy(&t1->block[0], &t2->block[0], sizeof(Vector2) * 4);

  t1->rotationRule = t2->rotationRule;
  t1->rotationIndex = t2->rotationIndex;
  t1->type = t2->type;
}

void tetriminoTranslate(Tetrimino* tetrimino, int x, int y)
{
  for(unsigned int i = 0; i < 4; ++i) {
    tetrimino->block[i].x += x;
    tetrimino->block[i].y += y;
  }
}

void tetriminoRotate(Tetrimino* tetrimino)
{
  unsigned int numberOfRotations = tetrimino->rotationRule->numberOfRotations;

  if(numberOfRotations) {
    tetrimino->rotationIndex = (tetrimino->rotationIndex + 1) % numberOfRotations;
    Tetrimino* rotationRule = &tetrimino->rotationRule->rotation[tetrimino->rotationIndex];

    for(unsigned int i = 0; i < 4; ++i) {
      tetrimino->block[i].x += rotationRule->block[i].x;
      tetrimino->block[i].y += rotationRule->block[i].y;
    }
  }
}
