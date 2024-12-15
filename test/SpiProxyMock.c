/**
 * @file SpiProxyMock.c
 * @author Michał Mokrzycki
 * @brief Mock for SpiProxy - source file
 * @date 2024-12-15
 */


#include "SpiProxyMock.h"
#include <stdio.h>

void *mock_spi_handle = NULL;
void *mock_csPort = NULL;
uint16_t mock_csPin = 0;

// extern size_t mock_size;
// extern uint8_t mock_data[256];
size_t mock_size = 0;    
uint8_t mock_data[256];  


static void mock_spi_configure(void *self, void *spi_handle, void *csPort, uint16_t csPin)
{
    mock_spi_handle = spi_handle;
    mock_csPort = csPort;
    mock_csPin = csPin;
}

static void mock_spi_transmit(void *self, uint8_t *data, size_t size)
{
    mock_size = size;

    for (size_t i = 0; i < size; ++i) {
        mock_data[i] = data[i];
    }

}

static void mock_spi_receive(void *self, uint8_t *data, size_t size)
{
    mock_size = size;

    for (size_t i = 0; i < size; ++i) {
        data[i] = mock_data[i];
    }
}

static void mock_spi_transmit_receive(void *self, uint8_t *txData, uint8_t *rxData, size_t size)
{
    mock_size = size;

    for (size_t i = 0; i < size; ++i) {
        mock_data[i] = txData[i];
        rxData[i] = txData[i];
    }
}

static void mock_spi_set_cs(void *self, uint16_t state)
{
    mock_csPin = state;
}

void spi_mock_init(Spi *spi)
{
    spi->configure = mock_spi_configure;
    spi->transmit = mock_spi_transmit;
    spi->receive = mock_spi_receive;
    spi->set_cs = mock_spi_set_cs;
    spi->transmit_receive = mock_spi_transmit_receive;
}