#include "TofSensorProxy.h"

#include "proxy_actions.h"
static uint32_t readValue(TofSensorProxy *self)
{
    (void)self;
    return 0;
}

TofSensorProxy CreateTofSensorProxy(const char *name, Gpio_t *gpio, I2c_t *i2c)
{
    TofSensorProxy tof_sensor_proxy;
    memset(&tof_sensor_proxy, 0, sizeof(TofSensorProxy));
    tof_sensor_proxy.base_proxy.name = name;
    tof_sensor_proxy.base_proxy.gpio = gpio;
    tof_sensor_proxy.base_proxy.i2c  = i2c;
    tof_sensor_proxy.readValue       = readValue;

    return tof_sensor_proxy;
}