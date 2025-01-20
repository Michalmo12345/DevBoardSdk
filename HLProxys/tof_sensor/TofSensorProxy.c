#include "TofSensorProxy.h"

#include "proxy_actions.h"

static bool TofSensorProxy_execute(BaseHLProxy *self, ActionType action)
{
    TofSensorProxy *proxy     = (TofSensorProxy *)self;
    uint32_t expected_value_1 = 0xEA; // Model_ID register value
    uint32_t expected_value_2 = 0xAA; // Module_Type register value
    uint32_t read_value_1     = 0;
    uint32_t read_value_2     = 0;

    I2c_t *i2c = proxy->base_proxy.i2c;

    uint8_t regAddress1[2] = {(uint8_t)(MODEL_ID_REGISTER >> 8),
                              (uint8_t)(MODEL_ID_REGISTER & 0xFF)};
    uint8_t rxData1[4]     = {0};

    i2c->transmit(i2c, regAddress1, sizeof(regAddress1),
                  TOF_SENSOR_ADDRESS << 1);
    i2c->receive(i2c, rxData1, sizeof(rxData1), TOF_SENSOR_ADDRESS << 1);

    read_value_1 = (rxData1[0] << 24) | (rxData1[1] << 16) | (rxData1[2] << 8) |
                   rxData1[3];

    if (read_value_1 != expected_value_1) {
        return false;
    }

    uint8_t regAddress2[2] = {(uint8_t)(MODULE_TYPE_REGISTER >> 8),
                              (uint8_t)(MODULE_TYPE_REGISTER & 0xFF)};
    uint8_t rxData2[4]     = {0};

    i2c->transmit(i2c, regAddress2, sizeof(regAddress2),
                  TOF_SENSOR_ADDRESS << 1);
    i2c->receive(i2c, rxData2, sizeof(rxData2), TOF_SENSOR_ADDRESS << 1);

    read_value_2 = (rxData2[0] << 24) | (rxData2[1] << 16) | (rxData2[2] << 8) |
                   rxData2[3];

    if (read_value_2 != expected_value_2) {
        return false;
    }

    return true;
}
TofSensorProxy CreateTofSensorProxy(const char *name, Gpio_t *gpio, I2c_t *i2c)
{
    TofSensorProxy tof_sensor_proxy;
    memset(&tof_sensor_proxy, 0, sizeof(TofSensorProxy));
    tof_sensor_proxy.base_proxy.name    = name;
    tof_sensor_proxy.base_proxy.gpio    = gpio;
    tof_sensor_proxy.base_proxy.i2c     = i2c;
    tof_sensor_proxy.base_proxy.execute = TofSensorProxy_execute;
    // tof_sensor_proxy.readRegister       = readRegister;

    return tof_sensor_proxy;
}