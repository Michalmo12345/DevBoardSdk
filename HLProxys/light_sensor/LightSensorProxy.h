/**
 * @file I2CProxy.h
 * @author  Karol Pieczka
 * @brief ProxyFramework for I2C
 * @date 2024-12-09
 */

#ifndef LIGHTSENSORPROXY_H
#define LIGHTSENSORPROXY_H

#include "BaseHLProxy.h"
#include "AdcProxy.h"

typedef struct {
    BaseHLProxy base_proxy;
    uint32_t (*readValue)(struct LightSensorProxy *proxy);
} LightSensorProxy;

LightSensorProxy CreateLightSensorProxy(const char *name, Adc_t *adc);

#endif // LIGHTSENSORPROXY_H