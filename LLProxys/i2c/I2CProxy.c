/**
 * @file I2CProxy.h
 * @author  Karol Pieczka
 * @brief ProxyFramework for I2C
 * @date 2024-12-09
 */

#include "I2CProxy.h"

#include "main.h"

static void i2c_configure(void *self, void *i2c_handle)
{
    I2c *i2c        = (I2c *)self;
    i2c->i2c_handle = i2c_handle;
}

static void i2c_transmit(void *self, uint8_t *data, size_t size,
                         uint16_t device_address)
{
    I2c *i2c = (I2c *)self;
    HAL_I2C_Master_Transmit((I2C_HandleTypeDef *)i2c->i2c_handle,
                            device_address, data, size, HAL_MAX_DELAY);
}

static void i2c_receive(void *self, uint8_t *data, size_t size,
                        uint16_t device_address)
{
    I2c *i2c = (I2c *)self;
    HAL_I2C_Master_Receive((I2C_HandleTypeDef *)i2c->i2c_handle, device_address,
                           data, size, HAL_MAX_DELAY);
}

static void i2c_transmit_receive(void *self, uint8_t *txData, uint8_t *rxData,
                                 size_t size, uint16_t device_address)
{
    I2c *i2c = (I2c *)self;
    HAL_I2C_Mem_Read((I2C_HandleTypeDef *)i2c->i2c_handle, device_address,
                     txData[0], I2C_MEMADD_SIZE_8BIT, rxData, size,
                     HAL_MAX_DELAY);
}

void i2c_init(I2c *i2c)
{
    i2c->configure        = i2c_configure;
    i2c->transmit         = i2c_transmit;
    i2c->receive          = i2c_receive;
    i2c->transmit_receive = i2c_transmit_receive;

    i2c->i2c_handle     = NULL;
    i2c->device_address = 0;
}
