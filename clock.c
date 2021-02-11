#include <SDL2/SDL.h>
#include "clock.h"

void clockRestart(Clock* clock)
{
  clock->startTime = SDL_GetTicks();
}

int32_t clockElapsed(Clock* clock)
{
  return SDL_GetTicks() - clock->startTime;
}
