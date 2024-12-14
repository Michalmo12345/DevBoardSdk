#ifndef MEDIATOR_H
#define MEDIATOR_H


#include <stdint.h>
#include "BaseHLProxy.h"




typedef struct Mediator
{
    BaseHLProxy** hlProxies;
    size_t hlProxiesCount;
    void (*register_proxy)(struct Mediator* , BaseHLProxy*);
    void (*notify)(struct Mediator*, const char*, const char*);
    void (*shutdown)(struct Mediator* );
} Mediator;


#endif // MEDIATOR_H
