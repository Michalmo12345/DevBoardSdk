
/**
 * @file RFModuleProxy.c
 * @author Michał Mokrzycki
 * @brief Implementation of RFModuleProxy
 * @date 2025-01-01
 */

#include "RFModuleProxy.h"

#include "OLedDisplayProxy.h"
#include "delay_manager.h"
#include "proxy_actions.h"

// void RFModuleProxy_initialize(BaseHLProxy *self, Spi_t *spi, I2c_t *i2c,
//                               Gpio_t *gpio)
// {
//     RFModuleProxy *rf_module_proxy = (RFModuleProxy *)self;
//     if (spi != NULL) {
//         self->spi = spi;
//     }

//     if (i2c != NULL) {
//         self->i2c = i2c;
//     }

//     if (gpio != NULL) {
//         self->gpio = gpio;
//     }
// }

static bool RFModuleProxy_execute(BaseHLProxy *self, ActionType action)
{
    if (action == EXECUTE) {

        RFModuleProxy *proxy = (RFModuleProxy *)self;

        uint8_t test_reg   = SX1276_REG;
        uint8_t test_value = 0x55;
        uint8_t read_value = 0;

        Gpio_t *gpio = proxy->base_proxy.gpio;
        gpio->set(gpio);

        //
        proxy->write(proxy, test_reg, test_value);
        Spi_t *spi                = proxy->base_proxy.spi;
        uint8_t tx_read_buffer[2] = {test_reg & 0x7F, 0x00};
        uint8_t rx_read_buffer[2] = {0};
        spi->transmit_receive(spi, tx_read_buffer, rx_read_buffer, 2);
        // check if it works without delay
        Delay(500);

        read_value = rx_read_buffer[1];
        gpio->reset(gpio);
        return (read_value == test_value);
    } else {
        return false;
    }
}

static void RFModuleProxy_shutdown(BaseHLProxy *self)
{
    (void)self;
    // RFModuleProxy *rf_module_proxy = (RFModuleProxy *)self;
    //
}

static void RFModuleProxy_Read(RFModuleProxy *proxy, uint8_t reg)
{

    uint8_t tx_buffer[2] = {reg & 0x7F, 0x00}; // MSB ustawiony na 0 dla odczytu
    uint8_t rx_buffer[2] = {0};

    Spi_t *spi = proxy->base_proxy.spi;
    spi->transmit_receive(spi, tx_buffer, rx_buffer, 2);
}

static void RFModuleProxy_Write(RFModuleProxy *proxy, uint8_t reg, uint8_t data)
{

    uint8_t tx_buffer[2] = {reg | 0x80, data}; // MSB ustawiony na 1 dla zapisu

    Spi_t *spi = proxy->base_proxy.spi;
    spi->transmit(spi, tx_buffer, 2);
}

RFModuleProxy CreateRFModuleProxy(const char *name, Spi_t *spi, Gpio_t *gpio)
{
    RFModuleProxy rf_module_proxy;
    memset(&rf_module_proxy, 0, sizeof(RFModuleProxy));
    rf_module_proxy.base_proxy.name = name;
    // rf_module_proxy.base_proxy.initialize = RFModuleProxy_initialize;
    rf_module_proxy.base_proxy.execute  = RFModuleProxy_execute;
    rf_module_proxy.base_proxy.shutdown = RFModuleProxy_shutdown;
    rf_module_proxy.read                = RFModuleProxy_Read;
    rf_module_proxy.write               = RFModuleProxy_Write;

    rf_module_proxy.base_proxy.spi  = spi;
    rf_module_proxy.base_proxy.gpio = gpio;

    // add pointer for i2c later
    return rf_module_proxy;
}