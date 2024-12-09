
/**
 * @file Gpio.c
 * @author Michał Mokrzycki
 * @brief Framework for Gpio
 * @date 2024-11-14

 *
 */

#include "GpioProxy.h"
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

int gpio_read(Gpio *gpio)
{
    return HAL_GPIO_ReadPin(gpio->port, gpio->pin); // Użycie HAL do odczytu stanu pinu
}

void gpio_set(Gpio *gpio, int value)
{
    HAL_GPIO_WritePin(gpio->port, gpio->pin, value);
}

void gpio_reset_pin(Gpio *gpio, int value)
{
    HAL_GPIO_WritePin(gpio->port, gpio->pin, value);
}
