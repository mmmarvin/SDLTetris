#ifndef CLOCK_H
#define CLOCK_H

#include <inttypes.h>

typedef struct
{
  int32_t startTime;
} Clock;

void clockRestart(Clock* clock);
int32_t clockElapsed(Clock* clock);

#endif // CLOCK_H
