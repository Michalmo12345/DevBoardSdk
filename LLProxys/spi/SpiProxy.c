
/**
 * @file SpiProxy.h
 * @author  Michał Mokrzycki
 * @brief ProxyFramework for Spi
 * @date 2024-12-09
 */

#include "SpiProxy.h"

#include "main.h"

static void spi_configure(void *self, void *spi_handle, void *csPort,
                          uint16_t csPin)
{
    Spi *spi        = (Spi *)self;
    spi->spi_handle = spi_handle;
    spi->csPort     = csPort;
    spi->csPin      = csPin;
}

static void spi_transmit(void *self, uint8_t *data, size_t size)
{
    Spi *spi = (Spi *)self;

    HAL_GPIO_WritePin((GPIO_TypeDef *)spi->csPort, spi->csPin, GPIO_PIN_RESET);
    HAL_SPI_Transmit((SPI_HandleTypeDef *)self, data, size, HAL_MAX_DELAY);
    HAL_GPIO_WritePin((GPIO_TypeDef *)spi->csPort, spi->csPin, GPIO_PIN_SET);
}

static void spi_receive(void *self, uint8_t *data, size_t size)
{

    Spi *spi = (Spi *)self;
    HAL_GPIO_WritePin((GPIO_TypeDef *)spi->csPort, spi->csPin, GPIO_PIN_RESET);
    HAL_SPI_Receive((SPI_HandleTypeDef *)self, data, size, HAL_MAX_DELAY);
    HAL_GPIO_WritePin((GPIO_TypeDef *)spi->csPort, spi->csPin, GPIO_PIN_SET);
}

static void spi_select(void *self, uint16_t state)
{
    Spi *spi = (Spi *)self;
    if (state == 0)
        HAL_GPIO_WritePin((GPIO_TypeDef *)spi->csPort, spi->csPin,
                          GPIO_PIN_RESET);
    else
        HAL_GPIO_WritePin((GPIO_TypeDef *)spi->csPort, spi->csPin,
                          GPIO_PIN_SET);
}

static void spi_transmit_receive(void *self, uint8_t *txData, uint8_t *rxData,
                                 size_t size)
{
    Spi *spi = (Spi *)self;
    HAL_GPIO_WritePin((GPIO_TypeDef *)spi->csPort, spi->csPin, GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive((SPI_HandleTypeDef *)self, txData, rxData, size,
                            HAL_MAX_DELAY);
    HAL_GPIO_WritePin((GPIO_TypeDef *)spi->csPort, spi->csPin, GPIO_PIN_SET);
}

void spi_init(Spi *spi)
{
    spi->configure        = spi_configure;
    spi->transmit         = spi_transmit;
    spi->receive          = spi_receive;
    spi->set_cs           = spi_select;
    spi->transmit_receive = spi_transmit_receive;

    spi->spi_handle = NULL;
    spi->csPort     = NULL;
    spi->csPin      = 0;
}