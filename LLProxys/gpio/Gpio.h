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

// #include "stm_headers.h"
//  #include HAL_GPIO
#include "stm32l4xx.h"
#include "stm32l4xx_hal_def.h"

typedef struct
{
    GPIO_TypeDef *port;
    uint16_t pin;
} Gpio;

void gpio_initialize(Gpio *gpio, GPIO_TypeDef *port, uint16_t pin);
void gpio_configure(Gpio *gpio, GPIO_TypeDef *port, uint16_t pin);
uint8_t gpio_access(Gpio *gpio);
void gpio_set_pin(Gpio *gpio);
void gpio_reset_pin(Gpio *gpio);
void gpio_toggle_pin(Gpio *gpio);
