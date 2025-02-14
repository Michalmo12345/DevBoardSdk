#include "OLedDisplayProxy.h"

#include "oled_drivers.h"

// void OLEDProxy_initialize(BaseHLProxy *self, Spi_t *spi, I2c_t *i2c,
//                           Gpio_t *gpio)
// {
//     OLEDProxy *oledProxy = (OLEDProxy *)self;

//     ssd1306_Init();
//     oledProxy->clear(oledProxy);
//     oledProxy->update_display(oledProxy);
// }

static bool OLEDProxy_execute(BaseHLProxy *self, ActionType action)
{
    (void)self;   // Mark 'self' as unused
    (void)action; // Mark 'action' as unused
    // OLEDProxy *oledProxy = (OLEDProxy *)self;

    // actions to define later
    return true;
}

static void OLEDProxy_shutdown(BaseHLProxy *self)
{
    OLEDProxy *oledProxy = (OLEDProxy *)self;
    ssd1306_Fill(Black);
    oledProxy->update_display(oledProxy);
}

static void OLEDProxy_clear()
{
    ssd1306_Fill(Black);
    ssd1306_UpdateScreen();
}

static void OLEDProxy_update_display() { ssd1306_UpdateScreen(); }

static void OLEDProxy_draw_text(char *text, uint8_t x, uint8_t y)
{
    ssd1306_SetCursor(x, y);
    ssd1306_WriteString(text, Font_7x10, White);
    ssd1306_UpdateScreen();
}
OLEDProxy CreateOLEDProxy(const char *name, I2c_t *i2c)
{
    OLEDProxy oled_proxy;
    memset(&oled_proxy, 0, sizeof(OLEDProxy));
    ssd1306_Init();
    oled_proxy.base_proxy.name = name;
    // oled_proxy.base_proxy.initialize = OLEDProxy_initialize;
    oled_proxy.base_proxy.execute  = OLEDProxy_execute;
    oled_proxy.base_proxy.shutdown = OLEDProxy_shutdown;
    oled_proxy.draw_text           = OLEDProxy_draw_text;
    oled_proxy.clear               = OLEDProxy_clear;
    oled_proxy.update_display      = OLEDProxy_update_display;
    oled_proxy.base_proxy.i2c      = i2c;

    oled_proxy.clear();
    oled_proxy.update_display();

    return oled_proxy;
}