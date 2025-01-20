/**
 * @file TofSensorProxy.h
 * @author Michał Mokrzycki
 * @brief ProxyFramework for TOF sensor
 * @date 2025-01-20

 *
 */

#ifndef TOFSENSORPROXY_H
#define TOFSENSORPROXY_H

#include "BaseHLProxy.h"

#include <stdint.h>
#include <string.h>

typedef struct TofSensorProxy {
    BaseHLProxy base_proxy;
    uint32_t (*readValue)(struct TofSensorProxy *proxy);
} TofSensorProxy;

TofSensorProxy CreateTofSensorProxy(const char *name, Gpio_t *gpio, I2c_t *i2c);

#endif // TOFSENSORPROXY_H