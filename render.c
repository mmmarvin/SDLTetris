#include "render.h"

SDL_Window*   gameRendererWindow = NULL;
SDL_Renderer* gameRenderer = NULL;

int renderWindowInit(int windowWidth, int windowHeight)
{
  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("Cannot init SDL");
    return 1;
  }

  gameRendererWindow = SDL_CreateWindow("SDL Tetris",
                                      100,
                                      100,
                                      windowWidth,
                                      windowHeight,
                                      SDL_WINDOW_SHOWN);
  if(gameRendererWindow == NULL) {
    printf("Cannot create SDL Window");
    renderWindowClose();
    return 1;
  }

  gameRenderer = SDL_CreateRenderer(gameRendererWindow,
                                    -1,
                                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(gameRenderer == NULL) {
    printf("Cannot create SDL Renderer");
    renderWindowClose();
    return 1;
  }

  return 0;
}

void renderWindowClose()
{
  if(gameRendererWindow)
    SDL_DestroyWindow(gameRendererWindow);
  SDL_Quit();

  gameRendererWindow = NULL;
  gameRenderer = NULL;
}
