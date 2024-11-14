/**
 * @file Gpio.h
 * @author Michał Mokrzycki
 * @brief Framework for Gpio
 * @version 0.1
 * @date 2024-11-14
 *
 *
 */

#pragma once

#include "stm_headers.h"
#include HAL_GPIO

typedef struct
{
    GPIO_TypeDef *port;
    uint16_t pin;
} Gpio;

void gpio_set_pin(Gpio *gpio);
void gpio_reset_pin(Gpio *gpio);
void gpio_toggle_pin(Gpio *gpio);
void init_builtin_led(void);
// test function used for toggling nucleo led
void toggle_builtin_led(void);