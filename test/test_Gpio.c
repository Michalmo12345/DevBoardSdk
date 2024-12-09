#include "unity.h"
#include "mock_GpioProxy.h"

// #include "stmheaders.h"
#include "GpioProxy.h"

void setUp(void)
{
    mock_GpioProxy_Init();
}

void tearDown(void)
{
    mock_GpioProxy_Destroy();
}

void test_gpio_configure_should_set_port_and_pin(void)
{
    // Arrange
    Gpio gpio;
    gpio_init(&gpio);

    void *dummy_port = (void *)0x12345678;
    uint16_t dummy_pin = 42;

    // Act
    gpio.configure(&gpio, dummy_port, dummy_pin);

    // Assert
    TEST_ASSERT_EQUAL_PTR(dummy_port, gpio.port);
    TEST_ASSERT_EQUAL_UINT16(dummy_pin, gpio.pin);
}