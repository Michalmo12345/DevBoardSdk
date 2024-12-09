/**
 * @file stm_headers.h
 * @author Michał Mokrzycki
 * @brief include headers
 * @date 2024-11-09

 *
 */

#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

// #if defined STM32L476xx
#include "stm32l4xx.h"
#include "stm32l4xx_hal_def.h"

#define HAL_GPIO "stm32l4xx_hal_gpio.h"
#define HAL_SPI "stm32l4xx_hal_spi.h"

// define other peripherial headers
// #else
// #error "Unsupported platform"
// #endif
#pragma GCC diagnostic pop