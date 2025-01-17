#include "LightSensorProxy.h"


void LightSensorProxy_initialize(BaseHLProxy *self, Adc_t *adc)
{
    LightSensorProxy *light_sensor_proxy = (LightSensorProxy *)self;
    if (adc != NULL) {
        self->adc = adc;
    }
}

void LightSensorProxy_shutdown(BaseHLProxy *self)
{
    LightSensorProxy *light_sensor_proxy = (LightSensorProxy *)self;
}

void LightSensorProxy_execute(BaseHLProxy *self, ActionType action)
{
    LightSensorProxy *proxy = (LightSensorProxy *)self;
    Adc_t *adc              = proxy->base_proxy.adc;

    if (adc == NULL || adc->get_value == NULL) {
        // obsługa błędu
        return;
    }

    // Odczyt wartości z czujnika w dwóch próbkach
    uint32_t value1 = adc->get_value(adc);
    HAL_Delay(50); 
    uint32_t value2 = adc->get_value(adc);


    // Sprawdzenie różnicy pomiędzy próbkami
    int32_t diff = (int32_t)value2 - (int32_t)value1;

    // Warunek testu
    return abs(diff) > 1; // 10 jako próg wykrywalnej zmiany
     
}

uint32_t LightSensorProxy_readValue(BaseHLProxy *self)
{
    if (self == NULL) {
        // Obsługa błędu, np. zwrócenie specjalnej wartości
        return 0xFFFFFFFF; // Możesz użyć tej wartości jako oznaczenia błędu
    }

    // Rzutowanie wskaźnika do właściwego typu
    LightSensorProxy *proxy = (LightSensorProxy *)self;

    // Sprawdzenie, czy ADC i funkcja get_value są prawidłowo ustawione
    if (proxy->base_proxy.adc == NULL ||
        proxy->base_proxy.adc->get_value == NULL) {
        // Obsługa błędu
        return 0xFFFFFFFE; // Zwrot wartości błędu
    }

    // Pobranie wartości z ADC
    return proxy->base_proxy.adc->get_value(proxy->base_proxy.adc);
}


LightSensorProxy CreateLightSensorProxy(const char *name, Adc_t *adc)
{
    LightSensorProxy light_sensor_proxy;
    light_sensor_proxy.base_proxy.name       = name;
    light_sensor_proxy.base_proxy.adc        = adc;
    light_sensor_proxy.base_proxy.initialize = LightSensorProxy_initialize;
    light_sensor_proxy.base_proxy.execute    = LightSensorProxy_execute;
    light_sensor_proxy.base_proxy.shutdown   = LightSensorProxy_shutdown;
    light_sensor_proxy.readValue  = LightSensorProxy_readValue;
    return light_sensor_proxy;
}