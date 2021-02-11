#include <stdlib.h>
#include <memory.h>
#include "game_field.h"

int** gameField = NULL;

void gameFieldInit()
{
  gameField = (int**) malloc(sizeof(int*) * GAME_FIELD_HEIGHT);
  for(unsigned int i = 0; i < GAME_FIELD_HEIGHT; ++i)
    gameField[i] = (int*) malloc(sizeof(int*) * GAME_FIELD_WIDTH);
}

void gameFieldReset()
{
  for(unsigned int j = 0; j < GAME_FIELD_HEIGHT; ++j)
    for(unsigned int i = 0; i < GAME_FIELD_WIDTH; ++i)
      gameField[j][i] = 0;
}

void gameFieldDestroy()
{
  for(unsigned int i = 0; i < GAME_FIELD_HEIGHT; ++i)
    free(gameField[i]);
  free(gameField);
}

int gameFieldTryClearLine()
{
  int lineClearedStart = -1;
  int lineClearedEnd = -1;

  // clear lines
  for(unsigned int j = 0; j < GAME_FIELD_HEIGHT; ++j) {
    int clearLine = 1;
    for(unsigned int i = 0; i < GAME_FIELD_WIDTH; ++i) {
      if(gameField[j][i] != 2) {
        clearLine = 0;
        break;
      }
    }

    if(clearLine) {
      if(lineClearedStart >= 0)
        lineClearedEnd = j;
      else {
        lineClearedStart = j;
        lineClearedEnd = j;
      }

      for(unsigned int i = 0; i < GAME_FIELD_WIDTH; ++i)
        gameField[j][i] = 0;
    }
  }

  // occupy the empty spaces
  int linesCleared = lineClearedStart >= 0 ? lineClearedEnd  - lineClearedStart + 1 : 0;
  if(lineClearedStart >= 0) {
    while(lineClearedStart > 0) {
      memcpy(&gameField[lineClearedEnd][0], &gameField[lineClearedStart - 1][0], GAME_FIELD_WIDTH * sizeof(int));
      --lineClearedStart;
      --lineClearedEnd;
    }
  }

  return linesCleared;
}

void gameFieldSet(Tetrimino* tetrimino, int value)
{
  for(unsigned int i = 0; i < 4; ++i) {
    Vector2 p = tetrimino->block[i];

    if(p.x >= 0 && p.y >= 0)
      gameField[p.y][p.x] = value;
  }
}
