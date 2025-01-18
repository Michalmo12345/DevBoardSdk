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
#include "AdcProxy.h"
#include "proxy_actions.h"

#include <stdint.h>

typedef struct BaseHLProxy {
    const char *name;

    // Pointers to different peripherals
    Spi_t *spi;
    I2c_t *i2c;
    Gpio_t *gpio;
    Adc_t *adc;

    void (*initialize)(struct BaseHLProxy *, Spi_t *spi, I2c_t *i2c,
                       Gpio_t *gpio, Adc_t *adc);
    bool (*execute)(struct BaseHLProxy *, ActionType action);
    void (*shutdown)(struct BaseHLProxy *);
} BaseHLProxy;

#endif // BASEHLPROXY_H