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
#include "SpiProxy.h"
#include "LedMatrixProxy.h"
#include "stm_headers.h"
#include "Mediator.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include HAL_SPI


void start()
{

    extern SPI_HandleTypeDef hspi1;
    extern SPI_HandleTypeDef hspi3;
    // just tests
    // Gpio led1;
    // Gpio led2;
    // Gpio led3;

    // Gpio csPinSpi1;

    // gpio_init(&led1);
    // gpio_init(&led2);
    // gpio_init(&led3);
    // gpio_init(&csPinSpi1);

    // led1.configure(&led1, DIG_LED1_GPIO_Port, DIG_LED1_Pin);
    // led2.configure(&led2, DIG_LED2_GPIO_Port, DIG_LED2_Pin);
    // led3.configure(&led3, DIG_LED3_GPIO_Port, DIG_LED3_Pin);

    // csPinSpi1.configure(&csPinSpi1, SPI1_CS_GPIO_Port, SPI1_CS_Pin);

    // led1.reset(&led1);
    // led2.reset(&led2);
    // led3.reset(&led3);

    // csPinSpi1.reset(&csPinSpi1);


    // //  mediator test

    // Mediator mediator;
    // mediator.init(&mediator);

    // mediator.shutdown(&mediator);
    
    Spi spi1;
    spi_init(&spi1);
    spi1.configure(&spi1, &hspi1, SPI1_CS_GPIO_Port, SPI1_CS_Pin);


    Spi spi3;
    spi_init(&spi3);
    spi3.configure(&spi3, &hspi3, SPI3_CS_GPIO_Port, SPI3_CS_Pin);


    uint8_t txData[] = {0xAA, 0xBB, 0xCC};
    uint8_t rxData[3] = {0};

    spi1.transmit_receive(&spi3, txData, rxData, 3);
    
    while (1)
    {

        char displayBuffer[32];
        snprintf(displayBuffer, sizeof(displayBuffer), "%02X %02X %02X", rxData[0], rxData[1], rxData[2]);

        ssd1306_Fill(Black);

        ssd1306_SetCursor(2, 2); 
        ssd1306_WriteString(displayBuffer, Font_11x18, White);

        ssd1306_UpdateScreen();
        // ssd1306_Fill(Black);
        // ssd1306_SetCursor(2, 2);
        // ssd1306_WriteString("Hello", Font_11x18, White);
        // ssd1306_UpdateScreen();
        // HAL_Delay(500);
        // ssd1306_Fill(White);
        // ssd1306_SetCursor(2, 2);
        // ssd1306_WriteString("World",Font_11x18, Black);
        // ssd1306_UpdateScreen();
        // HAL_Delay(500);
    }
}