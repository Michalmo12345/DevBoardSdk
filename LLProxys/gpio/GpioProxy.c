
/**
 * @file GpioProxy.c
 * @author Michał Mokrzycki
 * @brief ProxyFramework for Gpio
 * @date 2024-11-14

 *
 */

#include "GpioProxy.h"

#include "main.h"

static void gpio_configure(Gpio_t *self, GPIO_TypeDef *port, uint16_t pin)
{
    self->port = port;
    self->pin  = pin;
}

static int gpio_read(Gpio_t *self)
{
    int value = HAL_GPIO_ReadPin(self->port, self->pin);
    return value;
}

static void gpio_set(Gpio_t *self)
{
    HAL_GPIO_WritePin(self->port, self->pin, GPIO_PIN_SET);
}

static void gpio_reset(Gpio_t *self)
{
    HAL_GPIO_WritePin(self->port, self->pin, GPIO_PIN_RESET);
}

void gpio_init(Gpio_t *self)
{
    self->configure = gpio_configure;
    self->read      = gpio_read;
    self->set       = gpio_set;
    self->reset     = gpio_reset;
}
