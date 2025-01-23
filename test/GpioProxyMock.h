#pragma once

#include "GpioProxy.h"

extern void *mock_port;
extern uint16_t mock_pin;
extern uint8_t mock_pin_state;

void gpio_mock_init(Gpio_t *gpio);
