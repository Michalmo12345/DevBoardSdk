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