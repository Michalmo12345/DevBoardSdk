/**
 * @file app_core.h
 * @author Michał Mokrzycki 01178234@pw.edu.pl
 * @brief Header file for main application statrup file
 * @date 2024-11-09
 *
 *
 */

#pragma once

#include "stm32l4xx.h"
#include "stm32l4xx_hal_def.h"
#include "stm32l4xx_hal_gpio.h"
// need to wrap it up later so it would be reusable for different platforms, developing in framework stm_headers.h

void start();