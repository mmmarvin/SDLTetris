#include "game.h"
#include "game_field.h"
#include "define.h"
#include "render.h"

int main()
{
  if(renderWindowInit((GAME_FIELD_WIDTH * BLOCK_WIDTH) + (BLOCK_WIDTH * 4) + 25,
                      GAME_FIELD_HEIGHT * BLOCK_HEIGHT))
    return 1;
  gameRunLoop();

  renderWindowClose();
  return 0;
}
