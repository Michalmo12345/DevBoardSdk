#include "OLedDisplayProxy.h"

#include "oled_drivers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OLEDProxy_initialize(BaseHLProxy *self, Spi_t *spi, I2c_t *i2c, Gpio_t *gpio)
{
    OLEDProxy *oledProxy = (OLEDProxy *)self;

    ssd1306_Init();
    oledProxy->clear(oledProxy);
    oledProxy->update_display(oledProxy);
}

bool OLEDProxy_execute(BaseHLProxy *self, ActionType action)
{
    OLEDProxy *oledProxy = (OLEDProxy *)self;
    // actions to define later
}

void OLEDProxy_shutdown(BaseHLProxy *self)
{
    OLEDProxy *oledProxy = (OLEDProxy *)self;
    ssd1306_Fill(Black);
    oledProxy->update_display(oledProxy);
}

void OLEDProxy_clear()
{
    ssd1306_Fill(Black);
    ssd1306_UpdateScreen();
}

void OLEDProxy_update_display() { ssd1306_UpdateScreen(); }

void OLEDProxy_draw_text(const char *text, uint8_t x, uint8_t y)
{
    ssd1306_SetCursor(x, y);
    ssd1306_WriteString(text, Font_7x10, White);
    ssd1306_UpdateScreen();
}
OLEDProxy CreateOLEDProxy(const char *name, Spi_t *spi, I2c_t *i2c, Gpio_t *gpio)
{
    OLEDProxy oled_proxy;
    oled_proxy.base_proxy.name       = name;
    oled_proxy.base_proxy.initialize = OLEDProxy_initialize;
    oled_proxy.base_proxy.execute    = OLEDProxy_execute;
    oled_proxy.base_proxy.shutdown   = OLEDProxy_shutdown;
    oled_proxy.draw_text             = OLEDProxy_draw_text;
    oled_proxy.clear                 = OLEDProxy_clear;
    oled_proxy.update_display        = OLEDProxy_update_display;
    oled_proxy.base_proxy.spi        = spi;
    oled_proxy.base_proxy.gpio       = gpio;
    oled_proxy.base_proxy.i2c        = i2c;
    return oled_proxy;
}