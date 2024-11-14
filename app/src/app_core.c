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
#include "Gpio.h"

Gpio dig_led1;
Gpio dig_led2;
Gpio dig_led3;
Gpio dig_led4;
Gpio dig_led5;

void init_gpios(void)
{

    dig_led1.port = DIG_LED1_GPIO_Port;
    dig_led1.pin = DIG_LED1_Pin;

    dig_led2.port = DIG_LED2_GPIO_Port;
    dig_led2.pin = DIG_LED2_Pin;

    dig_led3.port = DIG_LED3_GPIO_Port;
    dig_led3.pin = DIG_LED3_Pin;

    dig_led4.port = DIG_LED4_GPIO_Port;
    dig_led4.pin = DIG_LED4_Pin;

    dig_led5.port = DIG_LED5_GPIO_Port;
    dig_led5.pin = DIG_LED5_Pin;
}
void start()
{
    init_gpios();
    HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
    // just for tests

    while (1)
    {

        GPIO_PinState dip_switch_1_state;
        dip_switch_1_state = HAL_GPIO_ReadPin(SW_PC13_GPIO_Port, SW_PC13_Pin);

        // Włączanie lub wyłączanie diody LED w zależności od stanu switcha
        if (dip_switch_1_state == GPIO_PIN_SET)
        {
            HAL_GPIO_WritePin(DIG_LED3_GPIO_Port, DIG_LED3_Pin, GPIO_PIN_SET);
        }
        else
        {
            HAL_GPIO_WritePin(DIG_LED3_GPIO_Port, DIG_LED3_Pin, GPIO_PIN_RESET);
        }

        gpio_set_pin(&dig_led1);
        gpio_set_pin(&dig_led2);
        gpio_set_pin(&dig_led3);
        gpio_set_pin(&dig_led4);
        gpio_set_pin(&dig_led5);

                HAL_Delay(100);
    }
}