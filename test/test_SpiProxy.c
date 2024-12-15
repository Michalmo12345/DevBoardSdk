#include "unity.h"

#include "SpiProxyMock.h"
#include "stdio.h"
#include <string.h>

extern size_t mock_size;
extern uint16_t mock_data[1024];

void setUp(void)
{
    // 
}

void tearDown(void)
{
    // maybe function to reset mock values
}


void test_spi_configure_should_set_spi_handle_csPort_and_csPin(void)
{
    Spi spi;
    spi_mock_init(&spi);
    void *dummy_spi_handle = (void *)0x12345678;
    void *dummy_csPort = (void *)0x87654321;
    uint16_t dummy_csPin = 42;

    spi.configure(&spi, dummy_spi_handle, dummy_csPort, dummy_csPin);

    TEST_ASSERT_EQUAL_PTR(dummy_spi_handle, mock_spi_handle);
    TEST_ASSERT_EQUAL_PTR(dummy_csPort, mock_csPort);
    TEST_ASSERT_EQUAL_UINT16(dummy_csPin, mock_csPin);
}

void test_spi_select_should_set_csPin_state_to_low(void)
{
    Spi spi;
    spi_mock_init(&spi);

    mock_csPin = 1;

    spi.set_cs(&spi, 0);

    TEST_ASSERT_EQUAL_UINT16(0, mock_csPin);
}

void test_spi_deselect_should_set_csPin_state_to_high(void)
{
    Spi spi;
    spi_mock_init(&spi);

    mock_csPin = 0;

    spi.set_cs(&spi, 1);

    TEST_ASSERT_EQUAL_UINT16(1, mock_csPin);
}

void test_spi_should_transmit_data(void)
{
    Spi spi;
    spi_mock_init(&spi);

    uint8_t dummy_data[] = {0x01, 0x02, 0x03};
    size_t dummy_size = sizeof(dummy_data);

    spi.transmit(&spi, dummy_data, dummy_size);

    TEST_ASSERT_EQUAL_UINT8(0x01, mock_data[0]);
    TEST_ASSERT_EQUAL_UINT8(0x02, mock_data[1]);
    TEST_ASSERT_EQUAL_UINT8(0x03, mock_data[2]);
    TEST_ASSERT_EQUAL_UINT8(dummy_size, mock_size);


}

