#include "BaseHLProxyMock.h"
#include "FreeRTOS.h"
#include "GpioProxyMock.h"
#include "RFModuleProxy.h"
#include "SpiProxyMock.h"
#include "mock_OLedDisplayProxy.h"
#include "proxy_actions.h"
#include "task.h"
#include "unity.h"
void test_CreateRFModuleProxy_initialization(void)
{

    Spi_t mock_spi   = {0};
    Gpio_t mock_gpio = {0};

    RFModuleProxy rf_module =
        CreateRFModuleProxy("TestRFModule", &mock_spi, &mock_gpio);

    // TEST_ASSERT_EQUAL_STRING("TestRFModule", rf_module.base_proxy.name);
    // TEST_ASSERT_EQUAL_PTR(&mock_spi, rf_module.base_proxy.spi);
    // TEST_ASSERT_EQUAL_PTR(&mock_gpio, rf_module.base_proxy.gpio);
    // TEST_ASSERT_NOT_NULL(rf_module.base_proxy.execute);
    // TEST_ASSERT_NOT_NULL(rf_module.base_proxy.shutdown);
    // TEST_ASSERT_NOT_NULL(rf_module.read);
    // TEST_ASSERT_NOT_NULL(rf_module.write);
}