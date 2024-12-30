/**
 * @file app_core.c
 * @author Michał Mokrzycki 01178234@pw.edu.pl
 * @brief Main application statrup file
 * @date 2024-11-09
 *

 *
 */

#include "app_core.h"

#include "BaseHLProxy.h"
#include "FreeRTOS.h"
#include "GpioProxy.h"
#include "LedMatrixProxy.h"
#include "Mediator.h"
#include "OLedDisplayProxy.h"
#include "RFModuleProxy.h"
#include "SpiProxy.h"
#include "main.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "stdio.h"
#include "stm_headers.h"

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

    Gpio gpio1;
    gpio_init(&gpio1);
    gpio1.configure(&gpio1, DIG_B1_GPIO_Port, DIG_B1_Pin);

    OLEDProxy oled_proxy = CreateOLEDProxy("oled_proxy", &spi1, &gpio1);
    oled_proxy.base_proxy.initialize(&oled_proxy.base_proxy, &spi1, &gpio1);

    Mediator mediator;
    mediator_init(&mediator, &oled_proxy);

    RFModuleProxy rf_module_proxy =
        CreateRFModuleProxy("rf_module_proxy", &spi1, &gpio1);
    rf_module_proxy.base_proxy.initialize(&rf_module_proxy.base_proxy, &spi1,
                                          &gpio1);

    mediator.register_proxy(&mediator, &rf_module_proxy.base_proxy);
    while (1) {

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