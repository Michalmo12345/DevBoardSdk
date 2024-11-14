
/**
 * @file Gpio.c
 * @author Michał Mokrzycki
 * @brief Framework for Gpio
 * @date 2024-11-14

 *
 */

#include "Gpio.h"
#include "main.h"

void gpio_set_pin(Gpio *gpio)
{
    HAL_GPIO_WritePin(gpio->port, gpio->pin, GPIO_PIN_SET);
}

void gpio_reset_pin(Gpio *gpio)
{
    HAL_GPIO_WritePin(gpio->port, gpio->pin, GPIO_PIN_RESET);
}

void gpio_toggle_pin(Gpio *gpio)
{
    HAL_GPIO_TogglePin(gpio->port, gpio->pin);
}

Gpio builtin_led;

void init_builtin_led(void)
{

    builtin_led.port = LD2_GPIO_Port;
    builtin_led.pin = LD2_Pin;
}

void toggle_builtin_led(void)
{
    gpio_toggle_pin(&builtin_led);
}