

#ifndef RFMODULEPROXY_H
#define RFMODULEPROXY_H

#include "BaseHLProxy.h"

typedef struct RFModuleProxy {
    BaseHLProxy base_proxy;
} RFModuleProxy;

RFModuleProxy CreateRFModuleProxy(const char *name);

#endif // RFMODULEPROXY_H