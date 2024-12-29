/**
 * @file Mediator.h
 * @author Michał Mokrzycki
 * @brief Mediator  (manager) class for communciation between HLProxies and main
 * application
 * @date 2024-12-15
 */

#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "BaseHLProxy.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define MAX_HL_PROXIES_COUNT 10

typedef struct Mediator {
    BaseHLProxy *hlProxies[MAX_HL_PROXIES_COUNT];
    size_t hlProxiesCount;
    void (*init)(struct Mediator *);
    void (*register_proxy)(struct Mediator *, BaseHLProxy *);
    void (*notify)(struct Mediator *, const char *, const char *);
    void (*shutdown)(struct Mediator *);
} Mediator;

void mediator_init(Mediator *mediator);
// void mediator_register_proxy(Mediator *mediator, BaseHLProxy *proxy);
// void mediator_notify(Mediator *mediator, const char *action,
//                      const char *proxy_name);
// void mediator_shutdown(Mediator *mediator);

#endif // MEDIATOR_H
