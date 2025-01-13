#ifndef EEPROMPROXY_H
#define EEPROMPROXY_H


#define EEPROM_ADDRESS 0x50 
#define TEST_REG 0x00

#include "BaseHLProxy.h"
#include "I2CProxy.h"

typedef struct EEPROMProxy {
    BaseHLProxy base_proxy;
    void (*read)(uint8_t reg);
    void (*write)(uint8_t reg, uint8_t data);
} EEPROMProxy;

EEPROMProxy CreateEEPROMProxy(const char *name, I2c *i2c);

#endif // EEPROMPROXY_H