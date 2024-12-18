/**
 * @file BaseHLProxy.h
 * @author Michał  Mokrzycki
 * @brief Base class for HLProxys, further class may be implemented from this
 class as polymorphic objects
 * @date 2024-12-14

 *
 */
#ifndef BASEHLPROXY_H
#define BASEHLPROXY_H

#include <stdint.h>

typedef struct BaseHLProxy {
    const char *name;
    void (*initialize)(struct BaseHLProxy *);
    void (*execute)(struct BaseHLProxy *, const char *action);
    void (*shutdown)(struct BaseHLProxy *);
} BaseHLProxy;

#endif // BASEHLPROXY_H