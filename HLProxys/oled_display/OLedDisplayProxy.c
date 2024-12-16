#include "OLedDisplayProxy.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void OLEDProxy_initialize(BaseHLProxy *self)
{

}

void OLEDProxy_execute(BaseHLProxy *self, const char *action)
{
    
}

void OLEDProxy_shutdown(BaseHLProxy *self)
{

}


OLEDProxy *CreateOLEDProxy(const char *name) {
    OLEDProxy *proxy = (OLEDProxy *)malloc(sizeof(OLEDProxy));
    proxy->base_proxy.name = name;
    proxy->base_proxy.initialize = OLEDProxy_initialize;
    proxy->base_proxy.execute = OLEDProxy_execute;
    proxy->base_proxy.shutdown = OLEDProxy_shutdown;
    return proxy;
}