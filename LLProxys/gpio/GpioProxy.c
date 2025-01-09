
/**
 * @file GpioProxy.c
 * @author Michał Mokrzycki
 * @brief ProxyFramework for Gpio
 * @date 2024-11-14

 *
 */

#include "GpioProxy.h"

#include "main.h"

static void gpio_configure(void *self, void *port, uint16_t pin)
{
    Gpio *gpio = (Gpio *)self;
    gpio->port = port;
    gpio->pin  = pin;
}

static int gpio_read(void *self)
{
    Gpio *gpio = (Gpio *)self;
    int value  = HAL_GPIO_ReadPin(gpio->port, gpio->pin);
    return value;
}

static void gpio_set(void *self)
{
    Gpio *gpio = (Gpio *)self;
    HAL_GPIO_WritePin(gpio->port, gpio->pin, GPIO_PIN_SET);
}

static void gpio_reset(void *self)
{
    Gpio *gpio = (Gpio *)self;
    HAL_GPIO_WritePin(gpio->port, gpio->pin, GPIO_PIN_RESET);
}

void gpio_init(Gpio *gpio)
{
    gpio->configure = gpio_configure;
    gpio->read      = gpio_read;
    gpio->set       = gpio_set;
    gpio->reset     = gpio_reset;
}