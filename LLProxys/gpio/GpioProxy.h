/**
 * @file Gpio.h
 * @author Michał Mokrzycki
 * @brief Framework for Gpio
 * @version 0.1
 * @date 2024-11-14
 *
 *
 */

#ifndef GPIOPROXY_H
#define GPIOPROXY_H

#include <stdint.h>

typedef struct {
    void *port;
    uint16_t pin;

    void (*configure)(void *self, void *port, uint16_t pin);
    int (*read)(void *self);
    void (*set)(void *self);
    void (*reset)(void *self);
} Gpio;

void gpio_init(Gpio *gpio);

#endif // GPIO_H