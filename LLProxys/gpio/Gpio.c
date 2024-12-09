
/**
 * @file Gpio.c
 * @author Michał Mokrzycki
 * @brief Framework for Gpio
 * @date 2024-11-14

 *
 */

#include "Gpio.h"
#include "main.h"

void gpio_initialize(Gpio *gpio, void *port, uint16_t pin)
{
    gpio->port = port;
    gpio->pin = pin;
}

// Configure a GPIO pin
void gpio_configure(Gpio *gpio, void *port, uint16_t pin)
{
    gpio->port = port;
    gpio->pin = pin;
}

// uint8_t gpio_access(Gpio *gpio)
// {
//     return HAL_GPIO_ReadPin(gpio->port, gpio->pin);
// }

// void gpio_set_pin(Gpio *gpio)
// {
//     HAL_GPIO_WritePin(gpio->port, gpio->pin, GPIO_PIN_SET);
// }

// void gpio_reset_pin(Gpio *gpio)
// {
//     HAL_GPIO_WritePin(gpio->port, gpio->pin, GPIO_PIN_RESET);
// }

// void gpio_toggle_pin(Gpio *gpio)
// {
//     HAL_GPIO_TogglePin(gpio->port, gpio->pin);
// }
