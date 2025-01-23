#include "delay_manager.h"

#include "stm_headers.h"

static DelayFunction GlobalDelayFunction = HAL_Delay;

void Delay(uint32_t ms)
{
    if (GlobalDelayFunction != NULL) {
        GlobalDelayFunction(ms);
    }
}

void SetDelayFunction(DelayFunction delay_func)
{
    if (delay_func != NULL) {
        GlobalDelayFunction = delay_func;
    }
}