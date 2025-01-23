#ifndef DELAY_MANAGER_H
#define DELAY_MANAGER_H

#include <stdint.h>

typedef void (*DelayFunction)(uint32_t ms);

void Delay(uint32_t ms);

void SetDelayFunction(DelayFunction delay_func);

#endif // DELAY_MANAGER_H