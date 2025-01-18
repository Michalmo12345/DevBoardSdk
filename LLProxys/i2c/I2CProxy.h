/**
 * @file I2CProxy.h
 * @author  Karol Pieczka
 * @brief ProxyFramework for I2C
 * @date 2024-12-09
 */

#ifndef I2CPROXY_H
#define I2CPROXY_H

#include "stm32l4xx.h"
#include "stm32l4xx_hal_def.h"

#include <stddef.h>
#include <stdint.h>

typedef struct {
    I2C_HandleTypeDef *i2c_handle;

    void (*configure)(void *self, I2C_HandleTypeDef *i2c_handle);
    void (*transmit)(void *self, uint8_t *data, size_t size,
                     uint16_t device_address);
    void (*receive)(void *self, uint8_t *data, size_t size,
                    uint16_t device_address);
    void (*transmit_receive)(void *self, uint8_t *txData, uint8_t *rxData,
                             size_t size, uint16_t device_address);
} I2c_t; //zmiana nazwy na _t

void i2c_init(I2c_t *i2c);

#endif // I2CPROXY_H
