/**
 * @file SpiProxy.h
 * @author
 * @brief ProxyFramework for Spi
 * @date 2024-12-09
 */

#ifndef SPIPROXY_H
#define SPIPROXY_H

#include "stm32l4xx.h"
#include "stm32l4xx_hal_def.h"
#include "stm32l4xx_hal_spi.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// typedef struct Spi_t Spi_t;

typedef struct Spi_t {
    SPI_HandleTypeDef *spi_handle;
    GPIO_TypeDef *csPort;
    uint16_t csPin;

    void (*configure)(struct Spi_t *self, SPI_HandleTypeDef *spi_handle,
                      GPIO_TypeDef *csPort, uint16_t csPin);
    void (*transmit)(struct Spi_t *self, uint8_t *data, size_t size);
    void (*receive)(struct Spi_t *self, uint8_t *data, size_t size);
    void (*set_cs)(struct Spi_t *self, uint16_t state);
    void (*transmit_receive)(struct Spi_t *self, uint8_t *txData,
                             uint8_t *rxData, size_t size);
} Spi_t;

void spi_init(Spi_t *spi);
#endif // SPIPROXY_H