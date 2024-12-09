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

#include <stdint.h>
// #include "stm_headers.h"
//  #include HAL_GPIO
// #include "stm32l4xx.h"
// #include "stm32l4xx_hal_def.h"

typedef struct
{
    void *port;
    uint16_t pin;
} Gpio;

void gpio_initialize(Gpio *gpio, void *port, uint16_t pin);
void gpio_configure(Gpio *gpio, void *port, uint16_t pin);
int gpio_read(Gpio *gpio);
void gpio_set(Gpio *gpio, int value);
void gpio_reset_pin(Gpio *gpio, int value);
