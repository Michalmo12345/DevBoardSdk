/**
 * @file I2CProxy.h
 * @author  Karol Pieczka
 * @brief ProxyFramework for I2C
 * @date 2024-12-09
 */

#ifndef I2CPROXY_H
#define I2CPROXY_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    void *i2c_handle;         // Uchwyt I2C (np. I2C_HandleTypeDef w HAL)
    uint16_t device_address;  // Adres urządzenia I2C

    void (*configure)(void *self, void *i2c_handle, uint16_t device_address);
    void (*transmit)(void *self, uint8_t *data, size_t size);
    void (*receive)(void *self, uint8_t *data, size_t size);
    void (*transmit_receive)(void *self, uint8_t *txData, uint8_t *rxData, size_t size);
} I2c;

void i2c_init(I2c *i2c);

#endif // I2CPROXY_H
