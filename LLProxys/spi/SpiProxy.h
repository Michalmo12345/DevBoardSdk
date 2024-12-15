/**
 * @file SpiProxy.h
 * @author  Michał Mokrzycki
 * @brief ProxyFramework for Spi
 * @date 2024-12-09
 */

#ifndef SPIPROXY_H
#define SPIPROXY_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    void *spi_handle;
    void *csPort;
    uint16_t csPin;

    void (*configure)(void *self, void *spi_handle, void *csPort, uint16_t csPin);

    void (*transmit)(void *self, uint8_t *data, size_t size);
    void (*receive)(void *self, uint8_t *data, size_t size);
    void (*set_cs)(void *self, uint16_t state);
    void (*transmit_receive)(void *self, uint8_t *txData, uint8_t *rxData, size_t size);

} Spi;

void spi_init(Spi *spi);
#endif // SPIPROXY_H