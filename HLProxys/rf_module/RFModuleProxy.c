#include "RFModuleProxy.h"

void RFModuleProxy_initialize(BaseHLProxy *self) {}

void RFModuleProxy_execute(BaseHLProxy *self, const char *action) {}

void RFModuleProxy_shutdown(BaseHLProxy *self) {}

RFModuleProxy CreateRFModuleProxy(const char *name)
{
    RFModuleProxy rf_module_proxy;
    rf_module_proxy.base_proxy.name       = name;
    rf_module_proxy.base_proxy.initialize = RFModuleProxy_initialize;
    rf_module_proxy.base_proxy.execute    = RFModuleProxy_execute;
    rf_module_proxy.base_proxy.shutdown   = RFModuleProxy_shutdown;
    return rf_module_proxy;
}