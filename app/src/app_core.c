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

void Test_SPI_Communication(Gpio *led1, Gpio *led2, Gpio *led3, Gpio *csPinSpi1)
{
    extern SPI_HandleTypeDef hspi1;

    uint8_t txData = 0xAA;
    uint8_t rxData = 0x00;

    HAL_SPI_Transmit(&hspi1, &txData, 1, HAL_MAX_DELAY);

    HAL_SPI_Receive(&hspi1, &rxData, 1, HAL_MAX_DELAY);
    if (HAL_SPI_Transmit(&hspi1, &txData, 1, HAL_MAX_DELAY) != HAL_OK)
    {
        led2->set(&led2);
    }
    if (HAL_SPI_Receive(&hspi1, &rxData, 1, HAL_MAX_DELAY) != HAL_OK)
    {
        led3->set(&led3);
    }
    if (rxData == txData)
    {
        led1->set(&led1);
    }
    else
    {
        led1->reset(&led1);
    }
}

void start()
{

    // just tests
    Gpio led1;
    Gpio led2;
    Gpio led3;

    Gpio csPinSpi1;

    gpio_init(&led1);
    gpio_init(&led2);
    gpio_init(&led3);
    gpio_init(&csPinSpi1);

    led1.configure(&led1, DIG_LED1_GPIO_Port, DIG_LED1_Pin);
    led2.configure(&led2, DIG_LED2_GPIO_Port, DIG_LED2_Pin);
    led3.configure(&led3, DIG_LED3_GPIO_Port, DIG_LED3_Pin);

    csPinSpi1.configure(&csPinSpi1, SPI1_CS_GPIO_Port, SPI1_CS_Pin);

    led1.reset(&led1);
    led2.reset(&led2);
    led3.reset(&led3);

    csPinSpi1.reset(&csPinSpi1);

    while (1)
    {
        Test_SPI_Communication(&led1, &led2, &led3, &csPinSpi1);
        HAL_Delay(500);
    }
}