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
#include "queue.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "stdio.h"
#include "stm_headers.h"
#include "task.h"

#include HAL_SPI
#include HAL_UART
TaskHandle_t lcdTaskHandle;
TaskHandle_t mediatorTaskHandle;

typedef struct {
    OLEDProxy *oled_proxy;
    Mediator *mediator;
    RFModuleProxy *rf_module_proxy;
} TaskParams;

void lcdTask(void *params)
{
    TaskParams *taskParams = (TaskParams *)params;
    OLEDProxy *oled_proxy  = taskParams->oled_proxy;

    while (1) {
        if (oled_proxy) {
            oled_proxy->clear();
            oled_proxy->draw_text("Break from testing", 0, 0);
        }
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void mediatorTask(void *params)
{
    TaskParams *taskParams         = (TaskParams *)params;
    Mediator *mediator             = taskParams->mediator;
    RFModuleProxy *rf_module_proxy = taskParams->rf_module_proxy;

    while (1) {
        if (mediator && rf_module_proxy) {
            mediator->notify(&mediator, "execute", "rf_module_proxy");
        }
        vTaskDelay(pdMS_TO_TICKS(500)); // Delay for 500 ms
    }
}

void start()
{

    extern SPI_HandleTypeDef hspi1;
    extern SPI_HandleTypeDef hspi3;

    extern I2C_HandleTypeDef hi2c1;
    extern I2C_HandleTypeDef hi2c3;

    extern UART_HandleTypeDef huart4;

    Spi_t spi1;
    spi_init(&spi1);
    spi1.configure(&spi1, &hspi1, SPI1_CS_GPIO_Port, SPI1_CS_Pin);

    Spi_t spi3;
    spi_init(&spi3);
    spi3.configure(&spi3, &hspi3, SPI3_CS_GPIO_Port, SPI3_CS_Pin);

    I2c i2c1;
    i2c_init(&i2c1);
    i2c1.configure(&i2c1, &hi2c1);

    I2c i2c3;
    i2c_init(&i2c3);
    i2c3.configure(&i2c3, &hi2c3);

    Gpio_t gpio1;
    gpio_init(&gpio1);
    gpio1.configure(&gpio1, DIG_B1_GPIO_Port, DIG_B1_Pin);

    Gpio_t rfm_rst_gpio;
    gpio_init(&rfm_rst_gpio);
    rfm_rst_gpio.configure(&rfm_rst_gpio, RFM_RST_GPIO_Port, RFM_RST_Pin);

    OLEDProxy oled_proxy = CreateOLEDProxy("oled_proxy", &spi1, &i2c1, &gpio1);
    oled_proxy.base_proxy.initialize(&oled_proxy.base_proxy, &spi1, &i2c1,
                                     &gpio1);

    Mediator mediator;
    mediator_init(&mediator, &oled_proxy);

    RFModuleProxy rf_module_proxy =
        CreateRFModuleProxy("rf_module_proxy", &spi1, &rfm_rst_gpio);
    rf_module_proxy.base_proxy.initialize(&rf_module_proxy.base_proxy, &spi1,
                                          &i2c1, &rfm_rst_gpio);

    mediator.register_proxy(&mediator, &rf_module_proxy.base_proxy);

    TaskParams lcdTaskParams      = {&oled_proxy, &mediator, NULL};
    TaskParams mediatorTaskParams = {NULL, &mediator, &rf_module_proxy};

    mediator.notify(&mediator, "execute", "rf_module_proxy");

    // TEST UART SENDING
    // uint8_t Test[] = "Hello World !!!\r\n";
    // HAL_UART_Transmit(&huart4, Test, sizeof(Test), 10);
    // HAL_Delay(1000);

    // freertos
    // xTaskCreate(lcdTask, "LCD Task", 256, &lcdTaskParams, 2, &lcdTaskHandle);
    // xTaskCreate(mediatorTask, "Mediator Task", 256, &mediatorTaskParams, 1,
    //             &mediatorTaskHandle);

    // vTaskStartScheduler();
}