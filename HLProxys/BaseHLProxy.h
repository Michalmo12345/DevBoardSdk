/**
 * @file BaseHLProxy.h
 * @author Michał  Mokrzycki
 * @brief Base class for HLProxys, further class may be implemented from this
 class as polymorphic objects
 * @date 2024-12-14

 *
 */
#ifndef BASEHLPROXY_H
#define BASEHLPROXY_H

#include "GpioProxy.h"
#include "I2CProxy.h"
#include "SpiProxy.h"

#include <stdint.h>

typedef struct BaseHLProxy {
    const char *name;

    // Pointers to different peripherals
    Spi *spi;
    I2c *i2c;
    Gpio *gpio;

    void (*initialize)(struct BaseHLProxy *, Spi *spi, I2c *i2c, Gpio *gpio);
    bool (*execute)(struct BaseHLProxy *, const char *action);
    void (*shutdown)(struct BaseHLProxy *);
} BaseHLProxy;

#endif // BASEHLPROXY_H