#ifndef BASEHLPROXY_H
#define BASEHLPROXY_H


#include <stdint.h>



typedef struct BaseHLProxy
{
    const char *name;
    void (*initialize)(struct BaseHLProxy *);
    void(*execute)(struct BaseHLProxy *, const char * action);
    void (*shutdown)(struct BaseHLProxy *);
} BaseHLProxy;

#endif // BASEHLPROXY_H