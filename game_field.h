#ifndef GAME_BLOCKS_H
#define GAME_BLOCKS_H

#include "tetrimino.h"

static const unsigned int GAME_FIELD_WIDTH = 10;
static const unsigned int GAME_FIELD_HEIGHT = 20;

extern int** gameField;

void gameFieldInit();
void gameFieldReset();
void gameFieldDestroy();

int gameFieldTryClearLine();
void gameFieldSet(Tetrimino* tetrimino, int value);

#endif // GAME_BLOCKS_H
