#include "EEPROMProxy.h"

void EEPROMProxy_initialize(BaseHLProxy *self, Spi_t *spi, I2c_t *i2c,
                            Gpio_t *gpio, Adc_t *adc)
{
    EEPROMProxy *eeprom_proxy = (EEPROMProxy *)self;
    if (spi != NULL) {
        self->spi = spi;
    }

    if (i2c != NULL) {
        self->i2c = i2c;
    }

    if (gpio != NULL) {
        self->gpio = gpio;
    }
}
void EEPROMProxy_shutdown(BaseHLProxy *self)
{
    EEPROMProxy *eeprom_proxy = (EEPROMProxy *)self;
}

bool EEPROMProxy_execute(BaseHLProxy *self, ActionType action)
{
    EEPROMProxy *proxy = (EEPROMProxy *)self;

    uint8_t test_value_1 = 0x55;
    uint8_t test_value_2 = 0xAA;
    uint8_t read_value_1 = 0;
    uint8_t read_value_2 = 0;

    I2c_t *i2c = proxy->base_proxy.i2c;

    // Pierwszy test
    uint8_t txData1[2] = {TEST_REG, test_value_1};
    i2c->transmit(i2c, txData1, sizeof(txData1), EEPROM_ADDRESS << 1);

    // Czekaj na zapis
    HAL_Delay(5);

    uint8_t regAddress = TEST_REG;
    i2c->transmit(i2c, &regAddress, 1, EEPROM_ADDRESS << 1);
    i2c->receive(i2c, &read_value_1, 1, EEPROM_ADDRESS << 1);

    if (read_value_1 != test_value_1) {
        return false;
    }

    // Drugi test
    uint8_t txData2[2] = {TEST_REG, test_value_2};
    i2c->transmit(i2c, txData2, sizeof(txData2), EEPROM_ADDRESS << 1);

    // Czekaj na zapis
    HAL_Delay(5);

    // Odczyt wartości
    i2c->transmit(i2c, &regAddress, 1, EEPROM_ADDRESS << 1);
    i2c->receive(i2c, &read_value_2, 1, EEPROM_ADDRESS << 1);

    if (read_value_2 != test_value_2) {
        return false;
    }

    return true;
}

EEPROMProxy CreateEEPROMProxy(const char *name, I2c_t *i2c)
{
    EEPROMProxy eeprom_proxy;
    eeprom_proxy.base_proxy.name       = name;
    eeprom_proxy.base_proxy.i2c        = i2c;
    eeprom_proxy.base_proxy.initialize = EEPROMProxy_initialize;
    eeprom_proxy.base_proxy.execute    = EEPROMProxy_execute;
    eeprom_proxy.base_proxy.shutdown   = EEPROMProxy_shutdown;
    return eeprom_proxy;
}