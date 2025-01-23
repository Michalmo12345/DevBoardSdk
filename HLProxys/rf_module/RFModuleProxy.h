/**
 * @file RFModuleProxy.h
 * @author Michał Mokrzycki
 * @brief ProxyFramework for RFModule
 * @date 2025-01-01
 *
 */

#ifndef RFMODULEPROXY_H
#define RFMODULEPROXY_H

#define SX1276_REG_FIFO 0x00
#define SX1276_REG_OP_MODE 0x01
#define SX1276_REG_BITRATE_MSB 0x02
#define SX1276_REG_BITRATE_LSB 0x03
#define SX1276_REG_FDEV_MSB 0x04
#define SX1276_REG_FDEV_LSB 0x05
#define SX1276_REG_FRF_MSB 0x06
#define SX1276_REG 0x28

#include "BaseHLProxy.h"
#include "OLedDisplayProxy.h"
#include "SpiProxy.h"

#include <string.h>
typedef struct RFModuleProxy {
    BaseHLProxy base_proxy;
    void (*read)(struct RFModuleProxy *proxy, uint8_t reg);
    void (*write)(struct RFModuleProxy *proxy, uint8_t reg, uint8_t data);
} RFModuleProxy;

RFModuleProxy CreateRFModuleProxy(const char *name, Spi_t *spi, Gpio_t *gpio);

#endif // RFMODULEPROXY_H