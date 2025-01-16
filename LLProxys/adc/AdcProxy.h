/**
 * @file I2CProxy.h
 * @author  Karol Pieczka
 * @brief ProxyFramework for ADC
 * @date 2024-12-09
 */

#ifndef I2CPROXY_H
#define I2CPROXY_H

#include "stm32l4xx.h"
#include "stm32l4xx_hal_def.h"

#include <stddef.h>
#include <stdint.h>


typedef struct {
    ADC_HandleTypeDef *adc_handle;
    uint32_t channel;

    void (*configure)(void *self, ADC_HandleTypeDef *adc_handle);
    void (*start_conversion)(void *self);
    void (*get_value)(void *self);
    void (*stop_conversion)(void *self);
} Adc_t;

#endif // I2CPROXY_H