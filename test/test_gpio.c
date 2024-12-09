#include "unity.h"
#include "mock_Gpio.h"
// #include "stmheaders.h"
// #include "Gpio.h"

void test_initialize_should_set_port_and_pin(void)
{
    Gpio gpio;
    GPIO_TypeDef dummy_port;

    initialize(&gpio, &dummy_port, 42);

    TEST_ASSERT_EQUAL_PTR(&dummy_port, gpio.port);
    TEST_ASSERT_EQUAL_UINT16(42, gpio.pin);
}
