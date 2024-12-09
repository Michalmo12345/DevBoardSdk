#include "unity.h"
#include "mock_Gpio.h"

// #include "stmheaders.h"
#include "Gpio.h"

void setUp(void)
{
    mock_Gpio_Init();
}

void tearDown(void)
{
    mock_Gpio_Destroy();
}

// void setUp(void)
// {
//     mock_hal_Init();
// }

// void tearDown(void)
// {
//     mock_hal_Destroy();
// }

void test_initialize_should_set_port_and_pin(void)
{
    Gpio gpio;
    void *dummy_port = (void *)0x12345678;

    // Oczekujemy wywołania funkcji gpio_initialize z odpowiednimi parametrami.
    gpio_initialize_Expect(&gpio, dummy_port, 42);

    // Wywołanie funkcji mockowanej.
    gpio_initialize(&gpio, dummy_port, 42);

    // Weryfikacja czy mock zadziałał poprawnie.
    mock_Gpio_Verify();
}
// void test_gpio_set_should_call_HAL_GPIO_WritePin(void)
// {
//     Gpio gpio;
//     gpio_initialize(&gpio, (void *)0x12345678, 42);

//     HAL_GPIO_WritePin_Expect(gpio.port, gpio.pin, 1);

//     gpio_set(&gpio, 1);

//     mock_hal_Verify();
// }

// void test_gpio_read_should_call_HAL_GPIO_ReadPin(void)
// {
//     Gpio gpio;
//     gpio_initialize(&gpio, (void *)0x12345678, 42);

//     HAL_GPIO_ReadPin_ExpectAndReturn(gpio.port, gpio.pin, 1);

//     int value = gpio_read(&gpio);

//     TEST_ASSERT_EQUAL(1, value);

//     mock_hal_Verify();
// }