#include "RFModuleProxy.h"

void RFModuleProxy_initialize(BaseHLProxy *self, Spi *spi, Gpio *gpio)
{
    RFModuleProxy *rf_module_proxy = (RFModuleProxy *)self;
    if (spi != NULL) {
        self->spi = spi;
    }

    // if (i2c != NULL) {
    //     rf_module_proxy->i2c = i2c;
    // }

    if (gpio != NULL) {
        self->gpio = gpio;
    }
}

void RFModuleProxy_execute(BaseHLProxy *self, const char *action)
{
    RFModuleProxy *proxy = (RFModuleProxy *)self;

    uint8_t test_reg   = SX1276_REG_OP_MODE;
    uint8_t test_value = 0x55;
    uint8_t read_value = 0;

    proxy->write(test_reg, test_value);

    uint8_t tx_buffer[2] = {test_reg & 0x7F, 0x00};
    uint8_t rx_buffer[2] = {0};
    Spi *spi             = proxy->base_proxy.spi;

    spi->transmit_receive(spi, tx_buffer, rx_buffer, 2);
    read_value = rx_buffer[1];

    // wyświetlanie czegoiś na ekranie  lcd
    if (read_value == test_value) {
    } else {
    }
}

void RFModuleProxy_shutdown(BaseHLProxy *self)
{
    RFModuleProxy *rf_module_proxy = (RFModuleProxy *)self;
}

static void RFModuleProxy_Read(RFModuleProxy *proxy, uint8_t reg)
{

    uint8_t tx_buffer[2] = {reg & 0x7F, 0x00}; // MSB ustawiony na 0 dla odczytu
    uint8_t rx_buffer[2] = {0};

    Spi *spi = proxy->base_proxy.spi;
    spi->transmit_receive(spi, tx_buffer, rx_buffer, 2);
}

static void RFModuleProxy_Write(RFModuleProxy *proxy, uint8_t reg, uint8_t data)
{
    uint8_t tx_buffer[2] = {reg | 0x80, data}; // MSB ustawiony na 1 dla zapisu

    Spi *spi = proxy->base_proxy.spi;
    spi->transmit(spi, tx_buffer, 2);
}

RFModuleProxy CreateRFModuleProxy(const char *name, Spi *spi, Gpio *gpio)
{
    RFModuleProxy rf_module_proxy;
    rf_module_proxy.base_proxy.name       = name;
    rf_module_proxy.base_proxy.initialize = RFModuleProxy_initialize;
    rf_module_proxy.base_proxy.execute    = RFModuleProxy_execute;
    rf_module_proxy.base_proxy.shutdown   = RFModuleProxy_shutdown;
    rf_module_proxy.base_proxy.spi        = spi;
    rf_module_proxy.base_proxy.gpio       = gpio;
    // add pointer for i2c later
    return rf_module_proxy;
}