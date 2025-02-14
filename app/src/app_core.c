/**
 * @file app_core.c
 * @author Michał Mokrzycki 01178234@pw.edu.pl
 * @brief Main application statrup file
 * @date 2024-11-09
 *

 *
 */

#include "app_core.h"

#include "AdcProxy.h"
#include "BaseHLProxy.h"
#include "EEPROMProxy.h"
#include "FreeRTOS.h"
#include "GpioProxy.h"
#include "I2CProxy.h"
#include "LedMatrixProxy.h"
#include "LightSensorProxy.h"
#include "Mediator.h"
#include "OLedDisplayProxy.h"
#include "RFModuleProxy.h"
#include "SpiProxy.h"
#include "TofSensorProxy.h"
#include "main.h"
#include "proxy_actions.h"
#include "queue.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "stdio.h"
#include "stm_headers.h"
#include "task.h"

#include HAL_SPI
#include HAL_UART
#include HAL_GPIO
#include OLED_DRIVER
#include HAL_I2C

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
            mediator->notify(mediator, EXECUTE, "rf_module_proxy");
        }
        vTaskDelay(pdMS_TO_TICKS(500)); // Delay for 500 ms
    }
}

void start()
{
    extern ADC_HandleTypeDef hadc1;

    extern SPI_HandleTypeDef hspi1;
    extern SPI_HandleTypeDef hspi3;

    extern I2C_HandleTypeDef hi2c1;
    extern I2C_HandleTypeDef hi2c3;

    // extern UART_HandleTypeDef huart4;

    Adc_t adc1;
    adc_init(&adc1);
    adc1.configure(&adc1, &hadc1);

    Spi_t spi1;
    spi_init(&spi1);
    spi1.configure(&spi1, &hspi1, SPI1_CS_GPIO_Port, SPI1_CS_Pin);

    Spi_t spi3;
    spi_init(&spi3);
    spi3.configure(&spi3, &hspi3, SPI3_CS_GPIO_Port, SPI3_CS_Pin);

    I2c_t i2c1;
    i2c_init(&i2c1);
    i2c1.configure(&i2c1, &hi2c1);

    I2c_t i2c3;
    i2c_init(&i2c3);
    i2c3.configure(&i2c3, &hi2c3);

    Gpio_t gpio1;
    gpio_init(&gpio1);
    gpio1.configure(&gpio1, DIG_B1_GPIO_Port, DIG_B1_Pin);

    Gpio_t rfm_rst_gpio;
    gpio_init(&rfm_rst_gpio);
    rfm_rst_gpio.configure(&rfm_rst_gpio, RFM_RST_GPIO_Port, RFM_RST_Pin);

    Gpio_t tof_xshut_gpio;
    gpio_init(&tof_xshut_gpio);
    tof_xshut_gpio.configure(&tof_xshut_gpio, TOF_XSHUT_GPIO_Port,
                             TOF_XSHUT_Pin);

    OLEDProxy oled_proxy = CreateOLEDProxy("oled_proxy", &i2c1);
    // oled_proxy.base_proxy.initialize(&oled_proxy.base_proxy, &spi1, &i2c1,
    //                                  &gpio1, NULL);
    // oled_proxy.base_proxy.initialize(&oled_proxy.base_proxy, &spi1, &i2c1,
    //                                  &gpio1, NULL);

    Mediator mediator;
    mediator_init(&mediator, &oled_proxy);

    RFModuleProxy rf_module_proxy =
        CreateRFModuleProxy("rf_module_proxy", &spi1, &rfm_rst_gpio);
    // rf_module_proxy.base_proxy.initialize(&rf_module_proxy.base_proxy, &spi1,
    //                                       NULL, &rfm_rst_gpio, NULL);

    EEPROMProxy eeprom_proxy = CreateEEPROMProxy("eeprom_proxy", &i2c1);
    // eeprom_proxy.base_proxy.initialize(&eeprom_proxy.base_proxy, NULL, &i2c1,
    //                                    NULL, NULL);

    LightSensorProxy light_sensor_proxy =
        CreateLightSensorProxy("light_sensor_proxy", &adc1);
    // light_sensor_proxy.base_proxy.initialize(&light_sensor_proxy.base_proxy,
    //                                          NULL, NULL, NULL, &adc1);

    TofSensorProxy tof_sensor_proxy =
        CreateTofSensorProxy("tof_sensor_proxy", &tof_xshut_gpio, &i2c1);

    mediator.register_proxy(&mediator, &rf_module_proxy.base_proxy);
    mediator.register_proxy(&mediator, &eeprom_proxy.base_proxy);
    mediator.register_proxy(&mediator, &light_sensor_proxy.base_proxy);
    mediator.register_proxy(&mediator, &tof_sensor_proxy.base_proxy);

    TaskParams lcdTaskParams      = {&oled_proxy, &mediator, NULL};
    TaskParams mediatorTaskParams = {NULL, &mediator, &rf_module_proxy};

    mediator.notify(&mediator, EXECUTE, "rf_module_proxy");

    HAL_Delay(2000);

    mediator.notify(&mediator, EXECUTE, "eeprom_proxy");

    HAL_Delay(2000);

    mediator.notify(&mediator, EXECUTE, "light_sensor_proxy");

    HAL_Delay(2000);

    mediator.notify(&mediator, EXECUTE, "tof_sensor_proxy");

    HAL_Delay(2000);

    // for (size_t i = 0; i < 10; i++) {
    //     oled_proxy.clear();
    //     char buffer[32];
    //     snprintf(buffer, sizeof(buffer), "%lu",
    //              light_sensor_proxy.readValue(&light_sensor_proxy));
    //     oled_proxy.draw_text(buffer, 0, 0);
    //     oled_proxy.update_display();
    //     HAL_Delay(500);
    // }
    
    // TEST UART SENDING
    // uint8_t Test[] = "Hello World !!!\r\n";
    // HAL_UART_Transmit(&huart4, Test, sizeof(Test), 10);
    // HAL_Delay(1000);

    // freertos
    // uncoment to further work
    // xTaskCreate(lcdTask, "LCD Task", 256, &lcdTaskParams, 2, &lcdTaskHandle);
    // xTaskCreate(mediatorTask, "Mediator Task", 256, &mediatorTaskParams, 1,
    //             &mediatorTaskHandle);

    // vTaskStartScheduler();
}