#ifndef CURRENT_TETRIMINO_H
#define CURRENT_TETRIMINO_H

#include "vector2.h"

struct TetriminoRotationRule;
typedef struct TetriminoRotationRule* tetrimino_rot_rule_ptr_t;

typedef struct
{
  Vector2                   block[4];
  int                       type;

  tetrimino_rot_rule_ptr_t  rotationRule;
  unsigned int              rotationIndex;
} Tetrimino;

extern Tetrimino currentTetrimino;
extern Tetrimino nextTetrimino;

enum {
  Tetrimino_I = 0,
  Tetrimino_J,
  Tetrimino_L,
  Tetrimino_O,
  Tetrimino_S,
  Tetrimino_T,
  Tetrimino_Z,
  TetriminoCount
};

void tetriminoCreate();
void tetriminoCopy(Tetrimino* t1, Tetrimino* t2);

void tetriminoTranslate(Tetrimino* tetrimino, int x, int y);
void tetriminoRotate(Tetrimino* tetrimino);

#endif // CURRENT_TETRIMINO_H
