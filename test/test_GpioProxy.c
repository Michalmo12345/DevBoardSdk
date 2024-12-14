#include "unity.h"
#include "mock_GpioProxy.h"

// #include "stmheaders.h"
#include "GpioProxy.h"
#include "GpioProxyMock.h"


void setUp(void)
{
    // mock_GpioProxy_Init();
}

void tearDown(void)
{
    // mock_GpioProxy_Destroy();
}

void test_gpio_configure_should_set_port_and_pin(void)
{

    Gpio gpio;
    gpio_mock_init(&gpio);
    void *dummy_port = (void *)0x12345678;
    uint16_t dummy_pin = 42;

    // Act
    gpio.configure(&gpio, dummy_port, dummy_pin);

    // Assert
    TEST_ASSERT_EQUAL_PTR(dummy_port, mock_port);
    TEST_ASSERT_EQUAL_UINT16(dummy_pin, mock_pin);
}

void test_gpio_set_should_set_mock_pin_state_to_high(void)
{
    // Arrange
    Gpio gpio;
    gpio_mock_init(&gpio);

    mock_pin_state = 0;

    // Act
    gpio.set(&gpio);

    // Assert
    TEST_ASSERT_EQUAL_UINT8(1, mock_pin_state);
}

void test_gpio_reset_should_set_mock_pin_state_to_low(void)
{
    // Arrange
    Gpio gpio;
    gpio_mock_init(&gpio);

    mock_pin_state = 1;

    // Act
    gpio.reset(&gpio);

    // Assert
    TEST_ASSERT_EQUAL_UINT8(0, mock_pin_state);
}

void test_gpio_read_should_return_mock_pin_state(void)
{
    // Arrange
    Gpio gpio;
    gpio_mock_init(&gpio);

    mock_pin_state = 1;

    // Act
    uint8_t state = gpio.read(&gpio);

    // Assert
    TEST_ASSERT_EQUAL_UINT8(1, state);
}