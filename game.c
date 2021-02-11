#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "clock.h"
#include "color.h"
#include "game.h"
#include "game_field.h"
#include "define.h"
#include "render.h"
#include "tetrimino.h"
#include "tetrimino_rotation_rule.h"

bool          gameOver = false;
bool          gameIsRunning = true;

Clock         gameClock;

int           gameLevel = 1;
int           gameSpeed = STARTING_GAME_SPEED;

unsigned int  gameScore = 0;

static void render()
{
  SDL_Rect rect;

  for(unsigned int j = 0; j < GAME_FIELD_HEIGHT; ++j) {
    for(unsigned i = 0; i < GAME_FIELD_WIDTH; ++i) {
      rect.x = (i * BLOCK_WIDTH) + 1;
      rect.y = (j * BLOCK_HEIGHT) + 1;
      rect.w = BLOCK_WIDTH - 2;
      rect.h = BLOCK_HEIGHT - 2;

      int gameFieldData = gameField[j][i];
      if(gameFieldData > 0) {
        if(gameFieldData == 1) {
          switch(currentTetrimino.type) {
          case Tetrimino_I:
            SDL_SetRenderDrawColor(gameRenderer, COLOR_CYAN.r, COLOR_CYAN.g, COLOR_CYAN.b, 255);
            break;
          case Tetrimino_J:
            SDL_SetRenderDrawColor(gameRenderer, COLOR_BLUE.r, COLOR_BLUE.g, COLOR_BLUE.b, 255);
            break;
          case Tetrimino_L:
            SDL_SetRenderDrawColor(gameRenderer, COLOR_ORANGE.r, COLOR_ORANGE.g, COLOR_ORANGE.b, 255);
            break;
          case Tetrimino_O:
            SDL_SetRenderDrawColor(gameRenderer, COLOR_YELLOW.r, COLOR_YELLOW.g, COLOR_YELLOW.b, 255);
            break;
          case Tetrimino_S:
            SDL_SetRenderDrawColor(gameRenderer, COLOR_GREEN.r, COLOR_GREEN.g, COLOR_GREEN.b, 255);
            break;
          case Tetrimino_T:
            SDL_SetRenderDrawColor(gameRenderer, COLOR_PURPLE.r, COLOR_PURPLE.g, COLOR_PURPLE.b, 255);
            break;
          case Tetrimino_Z:
            SDL_SetRenderDrawColor(gameRenderer, COLOR_RED.r, COLOR_RED.g, COLOR_RED.b, 255);
            break;
          }
        } else
          SDL_SetRenderDrawColor(gameRenderer, COLOR_GRAY.r, COLOR_GRAY.g, COLOR_GRAY.b, COLOR_WHITE.a);
        SDL_RenderFillRect(gameRenderer, &rect);
      }
    }
  }

  rect.x = (GAME_FIELD_WIDTH * BLOCK_WIDTH) + 1;
  rect.y = 0;
  rect.w = 1;
  rect.h = GAME_FIELD_HEIGHT * BLOCK_HEIGHT;

  SDL_SetRenderDrawColor(gameRenderer, 200, 200, 200, 255);
  SDL_RenderFillRect(gameRenderer, &rect);

  rect.x += 1;
  rect.w = (BLOCK_WIDTH * 4) + 25;

  SDL_SetRenderDrawColor(gameRenderer, 100, 100, 100, 255);
  SDL_RenderFillRect(gameRenderer, &rect);

  rect.x += 10;
  rect.y = 10;
  rect.w = BLOCK_WIDTH * 4;
  rect.h = BLOCK_HEIGHT * 4;
  SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 255);
  SDL_RenderFillRect(gameRenderer, &rect);

  SDL_SetRenderDrawColor(gameRenderer, COLOR_WHITE.r, COLOR_WHITE.g, COLOR_WHITE.b, COLOR_WHITE.a);
  unsigned int nextBlockWidth = (BLOCK_WIDTH /*/ 2*/);
  unsigned int nextBlockHeight = (BLOCK_HEIGHT /*/ 2*/);
  rect.w = nextBlockWidth  - 2;
  rect.h = nextBlockHeight - 2;

  switch(nextTetrimino.type) {
  case Tetrimino_I: {
    SDL_SetRenderDrawColor(gameRenderer, COLOR_CYAN.r, COLOR_CYAN.g, COLOR_CYAN.b, 255);
    rect.x = (GAME_FIELD_WIDTH * BLOCK_WIDTH) + 13;
    rect.y = 12 + (BLOCK_HEIGHT * 4) - (BLOCK_HEIGHT * 2) - BLOCK_HEIGHT;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x += nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x += nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x += nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);
    break;
  }
  case Tetrimino_J: {
    SDL_SetRenderDrawColor(gameRenderer, COLOR_BLUE.r, COLOR_BLUE.g, COLOR_BLUE.b, 255);
    rect.x = (GAME_FIELD_WIDTH * BLOCK_WIDTH) + 11 + (BLOCK_WIDTH * 4) - (BLOCK_WIDTH * 3) - (BLOCK_WIDTH / 2);
    rect.y = 12 + (BLOCK_HEIGHT * 4) - (BLOCK_HEIGHT * 2) - BLOCK_HEIGHT;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x += nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x += nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.y += nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);
    break;
  }
  case Tetrimino_L: {
    SDL_SetRenderDrawColor(gameRenderer, COLOR_ORANGE.r, COLOR_ORANGE.g, COLOR_ORANGE.b, 255);
    rect.x = (GAME_FIELD_WIDTH * BLOCK_WIDTH) + 11 + (BLOCK_WIDTH * 4) - (BLOCK_WIDTH * 3) - (BLOCK_WIDTH / 2);
    rect.y = 12 + (BLOCK_HEIGHT * 4) - (BLOCK_HEIGHT * 2) - BLOCK_HEIGHT;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x += nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x += nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x -= nextBlockWidth * 2;
    rect.y += nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);
    break;
  }
  case Tetrimino_O: {
    SDL_SetRenderDrawColor(gameRenderer, COLOR_YELLOW.r, COLOR_YELLOW.g, COLOR_YELLOW.b, 255);
    rect.x = (GAME_FIELD_WIDTH * BLOCK_WIDTH) + 11 + (BLOCK_WIDTH * 4) - (BLOCK_WIDTH * 2) - BLOCK_WIDTH;
    rect.y = 12 + (BLOCK_HEIGHT * 4) - (BLOCK_HEIGHT * 2) - BLOCK_HEIGHT;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x += nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.y += nextBlockHeight;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x -= nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);

    break;
  }
  case Tetrimino_S: {
    SDL_SetRenderDrawColor(gameRenderer, COLOR_GREEN.r, COLOR_GREEN.g, COLOR_GREEN.b, 255);
    rect.x = (GAME_FIELD_WIDTH * BLOCK_WIDTH) + 11 + (BLOCK_WIDTH * 4) - BLOCK_WIDTH - (BLOCK_WIDTH / 2);
    rect.y = 12 + (BLOCK_HEIGHT * 4) - (BLOCK_HEIGHT * 2) - BLOCK_HEIGHT;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x -= nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.y += nextBlockHeight;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x -= nextBlockWidth;
    SDL_RenderFillRect(gameRenderer, &rect);

    break;
  }
  case Tetrimino_T: {
    SDL_SetRenderDrawColor(gameRenderer, COLOR_PURPLE.r, COLOR_PURPLE.g, COLOR_PURPLE.b, 255);
    rect.x = (GAME_FIELD_WIDTH * BLOCK_WIDTH) + 11 + (BLOCK_WIDTH * 4) - BLOCK_WIDTH - (BLOCK_WIDTH / 2);
    rect.y = 12 + (BLOCK_HEIGHT * 4) - (BLOCK_HEIGHT * 2) - BLOCK_HEIGHT;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x -= BLOCK_WIDTH;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x -= BLOCK_WIDTH;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x += BLOCK_WIDTH;
    rect.y += BLOCK_HEIGHT;
    SDL_RenderFillRect(gameRenderer, &rect);

    break;
  }
  case Tetrimino_Z: {
    SDL_SetRenderDrawColor(gameRenderer, COLOR_RED.r, COLOR_RED.g, COLOR_RED.b, 255);
    rect.x = (GAME_FIELD_WIDTH * BLOCK_WIDTH) + 11 + (BLOCK_WIDTH * 4) - (BLOCK_WIDTH * 3) - (BLOCK_WIDTH / 2);
    rect.y = 12 + (BLOCK_HEIGHT * 4) - (BLOCK_HEIGHT * 2) - BLOCK_HEIGHT;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x += BLOCK_WIDTH;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.y += BLOCK_HEIGHT;
    SDL_RenderFillRect(gameRenderer, &rect);

    rect.x += BLOCK_WIDTH;
    SDL_RenderFillRect(gameRenderer, &rect);

    break;
  }
  }
}

static void renderScore(TTF_Font* scoreFont)
{
  char scoreChar[255];
  sprintf(&scoreChar[0], "%d", gameScore);

  char levelChar[255];
  sprintf(&levelChar[0], "%d", gameLevel);

  SDL_Surface* levelText = TTF_RenderText_Blended(scoreFont, &levelChar[0], COLOR_BLACK);
  SDL_Texture* levelTextTexture = SDL_CreateTextureFromSurface(gameRenderer, levelText);

  SDL_Surface* scoreText = TTF_RenderText_Blended(scoreFont, &scoreChar[0], COLOR_BLACK);
  SDL_Texture* scoreTextTexture = SDL_CreateTextureFromSurface(gameRenderer, scoreText);

  SDL_Rect scoreTextRect;
  scoreTextRect.x = (GAME_FIELD_WIDTH * BLOCK_WIDTH) + 11;
  scoreTextRect.y = 10 + BLOCK_HEIGHT * 4 + 10;
  scoreTextRect.w = 100;
  scoreTextRect.h = 100;

  SDL_RenderCopy(gameRenderer, levelTextTexture, NULL, &scoreTextRect);

  scoreTextRect.x = (GAME_FIELD_WIDTH * BLOCK_WIDTH) + 11;
  scoreTextRect.y = 10 + BLOCK_HEIGHT * 4 + 10 + 100;
  scoreTextRect.w = 100;
  scoreTextRect.h = 100;
  SDL_RenderCopy(gameRenderer, scoreTextTexture, NULL, &scoreTextRect);

  SDL_DestroyTexture(scoreTextTexture);
  SDL_DestroyTexture(levelTextTexture);
}

static void update()
{
  if(!gameOver) {
    if(clockElapsed(&gameClock) >= gameSpeed) {
      bool collision = false;
      Vector2* block = &currentTetrimino.block[0];
      for(unsigned int i = 0; i < 4; ++i) {
        int nx = block[i].x;
        int ny = block[i].y + 1;

        if((ny < GAME_FIELD_HEIGHT && gameField[ny][nx] == 2) ||
           ny == GAME_FIELD_HEIGHT) {
          collision = true;
          break;
        }
      }

      if(!collision) {
        gameFieldSet(&currentTetrimino, 0);
        tetriminoTranslate(&currentTetrimino, 0, 1);
        gameFieldSet(&currentTetrimino, 1);
      } else {
        for(unsigned int i = 0; i < 4; ++i) {
          if(block[i].y < 0) {
            gameOver = true;
            return;
          }
        }

        gameFieldSet(&currentTetrimino, 0);
        gameFieldSet(&currentTetrimino, 2);

//        int linesCleared = gameFieldTryClearLine();
//        if(linesCleared > 0) {
//          if(linesCleared < 4)
//            gameScore += (4 * 100);
//          else
//            gameScore += 800;

//          if(gameScore % 1000 > 0) {
//            gameLevel += 1;
//            gameSpeed -= GAME_SPEED_INCREASE;
//            gameSpeed = gameSpeed > 0 ? gameSpeed : 1;
//          }
//        }

        tetriminoCopy(&currentTetrimino, &nextTetrimino);
        tetriminoCreate();
      }

      clockRestart(&gameClock);
    }

    int linesCleared = gameFieldTryClearLine();
    if(linesCleared > 0) {
      if(linesCleared < 4)
        gameScore += (4 * 100);
      else
        gameScore += 800;

      if(gameScore % 1000 > 0) {
        gameLevel += 1;
        gameSpeed -= GAME_SPEED_INCREASE;
        gameSpeed = gameSpeed > 0 ? gameSpeed : 1;
      }
    }
  }
}

static void handleInput()
{
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
    case SDL_QUIT:
      gameIsRunning = 0;

      break;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym) {
      case SDLK_DOWN: {
        Tetrimino temp;
        tetriminoCopy(&temp, &currentTetrimino);
        tetriminoRotate(&temp);

        bool collision = false;
        for(unsigned int i = 0; i < 4; ++i) {
          int x = temp.block[i].x;
          int y = temp.block[i].y;

          if(x < 0 || x >= GAME_FIELD_WIDTH ||
             (y >= 0 && y < GAME_FIELD_HEIGHT && x >= 0 && x < GAME_FIELD_WIDTH && gameField[y][x] == 2))
            collision = true;
        }

        if(!collision) {
          gameFieldSet(&currentTetrimino, 0);
          tetriminoCopy(&currentTetrimino, &temp);
          gameFieldSet(&currentTetrimino, 1);
        }

        break;
      }
      case SDLK_LEFT: {
        bool canMove = true;
        for(unsigned int i = 0; i < 4; ++i) {
          int x = currentTetrimino.block[i].x - 1;
          int y = currentTetrimino.block[i].y;
          if(x < 0 ||
             (x >= 0 && y >= 0 && gameField[y][x] == 2)) {
            canMove = false;
            break;
          }
        }

        if(canMove) {
          gameFieldSet(&currentTetrimino, 0);
          tetriminoTranslate(&currentTetrimino, -1, 0);
          gameFieldSet(&currentTetrimino, 1);
        }

        break;
      }
      case SDLK_RIGHT: {
        bool canMove = true;
        for(unsigned int i = 0; i < 4; ++i) {
          int x = currentTetrimino.block[i].x + 1;
          int y = currentTetrimino.block[i].y;
          if(x >= GAME_FIELD_WIDTH ||
             (x < GAME_FIELD_WIDTH && y >= 0 && gameField[y][x] == 2)) {
            canMove = false;
            break;
          }
        }

        if(canMove) {
          gameFieldSet(&currentTetrimino, 0);
          tetriminoTranslate(&currentTetrimino, 1, 0);
          gameFieldSet(&currentTetrimino, 1);
        }

        break;
      }
      case SDLK_SPACE:
        if(gameOver) {
          gameFieldReset();
          gameSpeed = STARTING_GAME_SPEED;
          gameOver = false;

          gameLevel = 1;
          gameScore = 0;
        } else {
          Vector2* block = &currentTetrimino.block[0];
          int y = GAME_FIELD_HEIGHT;

          for(unsigned int i = 0; i < 4; ++i) {
            int nx = block[i].x;
            int ny = block[i].y + 1;

            for(unsigned int j = ny; j <= GAME_FIELD_HEIGHT; ++j) {
              if((j < GAME_FIELD_HEIGHT && gameField[j][nx] == 2) ||
                 j == GAME_FIELD_HEIGHT) {
                int my = j - ny;

                if(my < y)
                  y = my;
              }
            }
          }

          gameFieldSet(&currentTetrimino, 0);
          for(unsigned int i = 0; i < 4; ++i) {
            block[i].y += y;
          }
          gameFieldSet(&currentTetrimino, 2);
        }

        break;
      }
    }
  }
}

void gameRunLoop()
{
  srand(time(NULL));
  tetriminoRulesInitialize();

  TTF_Init();
  TTF_Font* scoreFont = TTF_OpenFont("DejaVuSans.ttf", 12);

  gameFieldInit();
  gameFieldReset();

  tetriminoCreate();
  tetriminoCopy(&currentTetrimino, &nextTetrimino);
  tetriminoCreate();

  gameFieldSet(&currentTetrimino, 1);

  clockRestart(&gameClock);

  Clock timeStepClock;
  clockRestart(&timeStepClock);

  int accumulator = 0;
  while(gameIsRunning) {
    int elapsed = clockElapsed(&timeStepClock);
    clockRestart(&timeStepClock);

    // Fixed time step implementation from Glenn Fiedler
    // https://gafferongames.com/
    accumulator += elapsed;
    while(accumulator >= 17) {
      update();
      handleInput();
      accumulator -= elapsed;
    }

    SDL_SetRenderDrawColor(gameRenderer, COLOR_BLACK.r, COLOR_BLACK.g, COLOR_BLACK.b, COLOR_BLACK.a);
    SDL_RenderClear(gameRenderer);
    render();
    renderScore(scoreFont);
    SDL_RenderPresent(gameRenderer);
  }

  TTF_Quit();

  gameFieldDestroy();
  tetriminoRulesDestroy();
}
