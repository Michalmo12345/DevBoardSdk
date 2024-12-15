/**
 * @file SpiProxyMock.h
 * @author Michał Mokrzycki
 * @brief Mock for SpiProxy - header file
 * @date 2024-12-15

 * 
 */

#pragma once

#include "SpiProxy.h"

#include <string.h>


extern void *mock_spi_handle;
extern void *mock_csPort;
extern uint16_t mock_csPin;

extern size_t mock_size;
extern uint16_t mock_data[1024];

void spi_mock_init(Spi *spi);