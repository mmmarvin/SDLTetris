#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>

extern SDL_Window*    gameRendererWindow;
extern SDL_Renderer*  gameRenderer;

int renderWindowInit(int windowWidth, int windowHeight);
void renderWindowClose();

#endif // RENDER_H
