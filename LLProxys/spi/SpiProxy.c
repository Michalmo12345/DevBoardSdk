
/**
 * @file SpiProxy.h
 * @author  Michał Mokrzycki
 * @brief ProxyFramework for Spi
 * @date 2024-12-09
 */

#include "SpiProxy.h"

#include "main.h"

static void spi_configure(Spi_t *self, SPI_HandleTypeDef *spi_handle,
                          GPIO_TypeDef *csPort, uint16_t csPin)
{
    self->spi_handle = spi_handle;
    self->csPort     = csPort;
    self->csPin      = csPin;
}

static void spi_transmit(Spi_t *self, uint8_t *data, size_t size)
{
    HAL_GPIO_WritePin(self->csPort, self->csPin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(self->spi_handle, data, size, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(self->csPort, self->csPin, GPIO_PIN_SET);
}

static void spi_receive(Spi_t *self, uint8_t *data, size_t size)
{
    HAL_GPIO_WritePin(self->csPort, self->csPin, GPIO_PIN_RESET);
    HAL_SPI_Receive(self->spi_handle, data, size, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(self->csPort, self->csPin, GPIO_PIN_SET);
}

static void spi_select(Spi_t *self, uint16_t state)
{
    if (state == 0)
        HAL_GPIO_WritePin(self->csPort, self->csPin, GPIO_PIN_RESET);
    else
        HAL_GPIO_WritePin(self->csPort, self->csPin, GPIO_PIN_SET);
}

static void spi_transmit_receive(Spi_t *self, uint8_t *txData, uint8_t *rxData,
                                 size_t size)
{
    HAL_GPIO_WritePin(self->csPort, self->csPin, GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(self->spi_handle, txData, rxData, size,
                            HAL_MAX_DELAY);
    HAL_GPIO_WritePin(self->csPort, self->csPin, GPIO_PIN_SET);
}

void spi_init(Spi_t *self)
{
    self->configure        = spi_configure;
    self->transmit         = spi_transmit;
    self->receive          = spi_receive;
    self->set_cs           = spi_select;
    self->transmit_receive = spi_transmit_receive;

    self->spi_handle = NULL;
    self->csPort     = NULL;
    self->csPin      = 0;
}
