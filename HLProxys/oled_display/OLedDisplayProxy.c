#include "OLedDisplayProxy.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OLEDProxy_initialize(BaseHLProxy *self)
{
    OLEDProxy *oledProxy = (OLEDProxy *)self;
    ssd1306_Init();
    oledProxy->clear(oledProxy);
    oledProxy->update_display(oledProxy);
}

void OLEDProxy_execute(BaseHLProxy *self, const char *action)
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

OLEDProxy CreateOLEDProxy(const char *name)
{
    OLEDProxy proxy; // now it just creates object on the stack
    proxy.base_proxy.name       = name;
    proxy.base_proxy.initialize = OLEDProxy_initialize;
    proxy.base_proxy.execute    = OLEDProxy_execute;
    proxy.base_proxy.shutdown   = OLEDProxy_shutdown;
    proxy.clear                 = OLEDProxy_clear;
    return proxy;
}