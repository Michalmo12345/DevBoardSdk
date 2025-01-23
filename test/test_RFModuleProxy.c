// #include "BaseHLProxyMock.h"
// #include "GpioProxyMock.h"
// #include "RFModuleProxy.h"
// #include "SpiProxyMock.h"
// #include "mock_BaseHLProxy.h"
// #include "mock_OLedDisplayProxy.h"
// #include "proxy_actions.h"
// #include "unity.h"
// void test_CreateRFModuleProxy_initialization(void)
// {

//     Spi_t mock_spi   = {0};
//     Gpio_t mock_gpio = {0};

//     RFModuleProxy rf_module =
//         CreateRFModuleProxy("TestRFModule", &mock_spi, &mock_gpio);

//     TEST_ASSERT_EQUAL_STRING("TestRFModule", rf_module.base_proxy.name);
//     TEST_ASSERT_EQUAL_PTR(&mock_spi, rf_module.base_proxy.spi);
//     TEST_ASSERT_EQUAL_PTR(&mock_gpio, rf_module.base_proxy.gpio);
//     TEST_ASSERT_NOT_NULL(rf_module.base_proxy.execute);
//     TEST_ASSERT_NOT_NULL(rf_module.base_proxy.shutdown);
//     TEST_ASSERT_NOT_NULL(rf_module.read);
//     TEST_ASSERT_NOT_NULL(rf_module.write);
// }
// void test_RFModuleProxy_execute_sets_and_resets_gpio(void)
// {
//     // Arrange
//     Spi_t spi;
//     spi_mock_init(&spi);
//     void *dummy_spi_handle = (void *)0x12345678;
//     void *dummy_csPort     = (void *)0x87654321;
//     uint16_t dummy_csPin   = 42;
//     Gpio_t gpio;
//     gpio_mock_init(&gpio);
//     void *dummy_port   = (void *)0x12345678;
//     uint16_t dummy_pin = 42;

//     gpio.configure(&gpio, dummy_port, dummy_pin);

//     spi.configure(&spi, dummy_spi_handle, dummy_csPort, dummy_csPin);

//     uint8_t dummy_data[] = {0x01, 0x02, 0x03};
//     size_t dummy_size    = sizeof(dummy_data);

//     // Initialize RFModuleProxy
//     RFModuleProxy rf_module = CreateRFModuleProxy("TestRFModule", &spi,
//     &gpio);

//     // Act: execute the RFModuleProxy function
//     bool success =
//         rf_module.base_proxy.execute((BaseHLProxy *)&rf_module, EXECUTE);

//     // Assert: Check if the GPIO was set and reset correctly
//     TEST_ASSERT_TRUE(!success); // Check if the execution was successful
//     TEST_ASSERT_EQUAL_UINT16(42,
//                              mock_csPin); // Check if GPIO was set to low
//                              (set)
// }