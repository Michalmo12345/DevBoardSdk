
/**
 * @file SpiProxy.h
 * @author  Michał Mokrzycki
 * @brief ProxyFramework for Spi
 * @date 2024-12-09
 */

#include "SpiProxy.h"
#include "main.h"


static void spi_configure(void *self, void *spi_handle, void *csPort, uint16_t csPin)
{
    Spi *spi = (Spi *)self;
    spi->spi_handle = spi_handle;
    spi->csPort = csPort;
    spi->csPin = csPin;
}

static void spi_transmit(void *self, uint8_t *data, uint16_t size)
{


}

static void spi_receive(void *self, uint8_t *data, uint16_t size)
{
}

static void spi_transmit_receive(void *self, uint8_t *txData, uint8_t *rxData, uint16_t size)
{
}

void spi_init(Spi *spi)
{
    spi->configure = spi_configure;
    spi->transmit = spi_transmit;
    spi->receive = spi_receive;
    spi->transmit_receive = spi_transmit_receive;

}