/**
 * @file Gpio.h
 * @author
 * @brief Framework for Gpio
 * @version 0.1
 * @date 2024-11-14
 *
 *
 */

#ifndef GPIOPROXY_H
#define GPIOPROXY_H

#include "stm32l4xx.h"
#include "stm32l4xx_hal_def.h"
#include "stm32l4xx_hal_gpio.h"

#include <stdint.h>
typedef struct Gpio_t {
    GPIO_TypeDef *port;
    uint16_t pin;

    void (*configure)(struct Gpio_t *self, GPIO_TypeDef *port, uint16_t pin);
    int (*read)(struct Gpio_t *self);
    void (*set)(struct Gpio_t *self);
    void (*reset)(struct Gpio_t *self);
} Gpio_t;

void gpio_init(Gpio_t *gpio);

#endif // GPIOPROXY_H