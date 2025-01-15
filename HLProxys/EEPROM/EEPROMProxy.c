#include "EEPROMProxy.h"

void EEPROMProxy_initialize(BaseHLProxy *self, Spi_t *spi, I2c *i2c,
                            Gpio_t *gpio) // wyzerować nieużywane wskaźniki
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

bool EEPROMProxy_execute(BaseHLProxy *self,
                         ActionType action) // dodać drugie sprawdzenie
{
    EEPROMProxy *proxy = (EEPROMProxy *)self;

    uint8_t test_value = 0x55;
    uint8_t read_value = 0;

    I2c *i2c = proxy->base_proxy.i2c;

    // Zapis wartości do rejestru EEPROM
    uint8_t txData[2] = {TEST_REG, test_value};
    i2c->transmit(i2c, txData, sizeof(txData), EEPROM_ADDRESS << 1);

    // Czekaj na zapis
    HAL_Delay(5); // Czas w milisekundach

    // Odczyt wartości z rejestru EEPROM
    uint8_t regAddress = TEST_REG;
    i2c->transmit(i2c, &regAddress, 1, EEPROM_ADDRESS << 1);
    i2c->receive(i2c, &read_value, 1, EEPROM_ADDRESS << 1);

    // Porównaj odczytaną wartość z zapisaną
    return (read_value == test_value);
}

EEPROMProxy CreateEEPROMProxy(const char *name, I2c *i2c)
{
    EEPROMProxy eeprom_proxy;
    eeprom_proxy.base_proxy.name       = name;
    eeprom_proxy.base_proxy.i2c        = i2c;
    eeprom_proxy.base_proxy.initialize = EEPROMProxy_initialize;
    eeprom_proxy.base_proxy.execute    = EEPROMProxy_execute;
    eeprom_proxy.base_proxy.shutdown   = EEPROMProxy_shutdown;
    return eeprom_proxy;
}