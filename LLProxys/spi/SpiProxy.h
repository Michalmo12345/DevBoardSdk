/**
 * @file SpiProxy.h
 * @author  Michał Mokrzycki
 * @brief ProxyFramework for Spi
 * @date 2024-12-09
 */

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    void *spi_handle;
} SpiProxy;