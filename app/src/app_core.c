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
#include "stm_headers.h"
#include HAL_SPI

void Test_SPI_Communication(void)
{
    extern SPI_HandleTypeDef hspi1;

    uint8_t txData = 0xAA;
    uint8_t rxData = 0x00;

    HAL_SPI_Transmit(&hspi1, &txData, 1, HAL_MAX_DELAY);

    HAL_SPI_Receive(&hspi1, &rxData, 1, HAL_MAX_DELAY);
    if (rxData == txData)
    {
    }
    else
    {
    }
    HAL_Delay(100);
}

void start()
{

    // just tests
    // Gpio led1;
    // Gpio led2;
    // Gpio led3;

    // gpio_initialize(&led1, DIG_LED1_GPIO_Port, DIG_LED1_Pin);
    // gpio_initialize(&led2, DIG_LED2_GPIO_Port, DIG_LED2_Pin);
    // gpio_initialize(&led3, DIG_LED3_GPIO_Port, DIG_LED3_Pin);

        while (1)
    {

        HAL_Delay(100);
    }
}