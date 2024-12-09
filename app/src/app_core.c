/**
 * @file app_core.c
 * @author Michał Mokrzycki 01178234@pw.edu.pl
 * @brief Main application statrup file
 * @date 2024-11-09
 *

 *
 */

#include "app_core.h"
#include "FreeRTOS.h"
#include "main.h"
#include "GpioProxy.h"
#include "LedMatrixProxy.h"

void start()
{
    while (1)
    {

        GPIO_PinState dip_switch_1_state;
        dip_switch_1_state = HAL_GPIO_ReadPin(SW_PC13_GPIO_Port, SW_PC13_Pin);

        if (dip_switch_1_state == GPIO_PIN_SET)
        {
            HAL_GPIO_WritePin(DIG_LED3_GPIO_Port, DIG_LED3_Pin, GPIO_PIN_SET);
        }
        else
        {
            HAL_GPIO_WritePin(DIG_LED3_GPIO_Port, DIG_LED3_Pin, GPIO_PIN_RESET);
        }

        HAL_Delay(100);
    }
}