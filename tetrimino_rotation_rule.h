#ifndef TETRIMINO_ROTATION_RULE_H
#define TETRIMINO_ROTATION_RULE_H

#include "tetrimino.h"

struct TetriminoRotationRule
{
  Tetrimino*    rotation;
  unsigned int  numberOfRotations;
};

extern struct TetriminoRotationRule TETRIMINO_I_ROTATION;
extern struct TetriminoRotationRule TETRIMINO_J_ROTATION;
extern struct TetriminoRotationRule TETRIMINO_L_ROTATION;
extern struct TetriminoRotationRule TETRIMINO_O_ROTATION;
extern struct TetriminoRotationRule TETRIMINO_S_ROTATION;
extern struct TetriminoRotationRule TETRIMINO_T_ROTATION;
extern struct TetriminoRotationRule TETRIMINO_Z_ROTATION;

void tetriminoRulesInitialize();
void tetriminoRulesDestroy();

#endif // TETRIMINO_ROTATION_RULE_H
