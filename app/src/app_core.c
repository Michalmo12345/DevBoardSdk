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

void start()
{
    HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
    // just for tests

    // testing led array
    HAL_GPIO_WritePin(DIG_LED1_GPIO_Port, DIG_LED1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DIG_LED2_GPIO_Port, DIG_LED2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DIG_LED3_GPIO_Port, DIG_LED3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DIG_LED4_GPIO_Port, DIG_LED4_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DIG_LED5_GPIO_Port, DIG_LED5_Pin, GPIO_PIN_SET);
}