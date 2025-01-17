/**
 * @file I2CProxy.h
 * @author  Karol Pieczka
 * @brief ProxyFramework for ADC
 * @date 2024-12-09
 */

#include "AdcProxy.h"

static void configure(void *self, ADC_HandleTypeDef *adc_handle)
{
    Adc_t *adc = (Adc_t *)self;
    adc->adc_handle = adc_handle;
}

static void start_conversion(void *self)
{
    Adc_t *adc = (Adc_t *)self;
    HAL_ADC_Start(adc->adc_handle);
}

static uint32_t get_value(void *self)
{
    Adc_t *adc = (Adc_t *)self;
    HAL_ADC_PollForConversion(adc->adc_handle, 100);
    uint32_t value = HAL_ADC_GetValue(adc->adc_handle);
    return value;
}

static void stop_conversion(void *self)
{
    Adc_t *adc = (Adc_t *)self;
    HAL_ADC_Stop(adc->adc_handle);
}


void adc_init(Adc_t *adc)
{
    adc->configure = configure;
    adc->start_conversion = start_conversion;
    adc->get_value = get_value;
    adc->stop_conversion = stop_conversion;

    adc->adc_handle = NULL;
}