

#ifndef OLEDDISPLAYPROXY_H
#define OLEDDISPLAYPROXY_H

#include "BaseHLProxy.h"
#include "ssd1306.h"


typedef struct OLEDProxy {
    BaseHLProxy base_proxy;    
} OLEDProxy;

OLEDProxy *CreateOLEDProxy(const char *name);


#endif // OLEDDISPLAYPROXY_H