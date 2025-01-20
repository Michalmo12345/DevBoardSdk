/**
 * @file I2CProxy.h
 * @author  Karol Pieczka
 * @brief ProxyFramework for ADC
 * @date 2024-12-09
 */

#ifndef ADCPROXY_H
#define ADCPROXY_H

#include "stm32l4xx.h"
#include "stm32l4xx_hal_def.h"

typedef struct Adc_t {
    ADC_HandleTypeDef *adc_handle;
    uint32_t channel;

    void (*configure)(struct Adc_t *self, ADC_HandleTypeDef *adc_handle);
    void (*start_conversion)(struct Adc_t *self);
    uint32_t (*get_value)(struct Adc_t *self);
    void (*stop_conversion)(struct Adc_t *self);
} Adc_t;

void adc_init(Adc_t *adc);

#endif // I2CPROXY_H