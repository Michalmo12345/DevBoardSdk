

#ifndef OLEDDISPLAYPROXY_H
#define OLEDDISPLAYPROXY_H

#include "BaseHLProxy.h"
#include "oled_drivers.h"


typedef struct OLEDProxy {
    BaseHLProxy base_proxy;    
    // we can add more methods here, specific for OLED display
    void (*clear)();
    void (*update_display)();
} OLEDProxy;

OLEDProxy *CreateOLEDProxy(const char *name);


#endif // OLEDDISPLAYPROXY_H