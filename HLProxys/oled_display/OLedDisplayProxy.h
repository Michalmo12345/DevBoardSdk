

#ifndef OLEDDISPLAYPROXY_H
#define OLEDDISPLAYPROXY_H

#include "BaseHLProxy.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct OLEDProxy {
    BaseHLProxy base_proxy;
    // we can add more methods here, specific for OLED display
    void (*clear)();
    void (*update_display)();
    void (*draw_text)(char *text, uint8_t x, uint8_t y);
} OLEDProxy;

OLEDProxy CreateOLEDProxy(const char *name, I2c_t *i2c);

#endif // OLEDDISPLAYPROXY_H