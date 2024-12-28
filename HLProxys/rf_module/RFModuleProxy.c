#include "RFModuleProxy.h"

void RFModuleProxy_initialize(BaseHLProxy *self)
{
    RFModuleProxy *rf_module_proxy = (RFModuleProxy *)self;
}

void RFModuleProxy_execute(BaseHLProxy *self, const char *action)
{
    RFModuleProxy *rf_module_proxy = (RFModuleProxy *)self;
    // actions to define later
}

void RFModuleProxy_shutdown(BaseHLProxy *self)
{
    RFModuleProxy *rf_module_proxy = (RFModuleProxy *)self;
}

void RFModuleProxy_read(uint8_t reg)
{
    // read from RF module
}

void RFModuleProxy_write(uint8_t reg, uint8_t data)
{
    // write to RF module
}

RFModuleProxy CreateRFModuleProxy(const char *name)
{
    RFModuleProxy rf_module_proxy;
    rf_module_proxy.base_proxy.name       = name;
    rf_module_proxy.base_proxy.initialize = RFModuleProxy_initialize;
    rf_module_proxy.base_proxy.execute    = RFModuleProxy_execute;
    rf_module_proxy.base_proxy.shutdown   = RFModuleProxy_shutdown;
    return rf_module_proxy;
}