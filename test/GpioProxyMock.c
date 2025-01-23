#include "GpioProxyMock.h"

#include <stdio.h>

uint8_t mock_pin_state = 0;
void *mock_port        = NULL;
uint16_t mock_pin      = 0;

static void mock_gpio_configure(void *self, void *port, uint16_t pin)
{
    mock_port = port;
    mock_pin  = pin;
}

static uint8_t mock_gpio_read(void *self) { return mock_pin_state; }

static void mock_gpio_set(void *self) { mock_pin_state = 1; }

static void mock_gpio_reset(void *self) { mock_pin_state = 0; }

void gpio_mock_init(Gpio_t *gpio)
{
    gpio->configure = mock_gpio_configure;
    gpio->read      = mock_gpio_read;
    gpio->set       = mock_gpio_set;
    gpio->reset     = mock_gpio_reset;
}