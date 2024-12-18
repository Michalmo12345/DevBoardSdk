/**
 * @file Mediator.c
 * @author Michał Mokrzycki
 * @brief Mediator  (manager) class for communciation between HLProxies and main
 application
 * @date 2024-12-15

 */

#include "Mediator.h"

void mediator_init(Mediator *mediator)
{
    mediator->hlProxies =
        (BaseHLProxy **)malloc(INIT_HL_PROXIES_COUNT * sizeof(BaseHLProxy *));

    if (mediator->hlProxies == NULL) {
        // handle error
    }

    mediator->hlProxiesCount = 0;

    mediator->register_proxy = mediator_register_proxy;
    mediator->notify         = mediator_notify;
    mediator->shutdown       = mediator_shutdown;
}

void mediator_register_proxy(Mediator *mediator, BaseHLProxy *proxy)
{
    if (mediator->hlProxiesCount >= INIT_HL_PROXIES_COUNT) {
        mediator->hlProxies = (BaseHLProxy **)realloc(
            mediator->hlProxies,
            (mediator->hlProxiesCount + 1) * sizeof(BaseHLProxy *));
        if (mediator->hlProxies == NULL) {
            // handle error
            return;
        }
    }

    mediator->hlProxies[mediator->hlProxiesCount] = proxy;
    mediator->hlProxiesCount++;
}

void mediator_notify(Mediator *mediator, const char *action,
                     const char *proxy_name)
{
    for (size_t i = 0; i < mediator->hlProxiesCount; i++) {
        BaseHLProxy *proxy = mediator->hlProxies[i];

        if (proxy && proxy->execute && proxy->name == proxy_name) {
            proxy->execute(proxy, action);
        }
    }
}

void mediator_shutdown(Mediator *mediator)
{
    for (size_t i = 0; i < mediator->hlProxiesCount; i++) {
        BaseHLProxy *proxy = mediator->hlProxies[i];

        if (proxy && proxy->shutdown) {
            proxy->shutdown(proxy);
        }
    }

    free(mediator->hlProxies);
    mediator->hlProxies = NULL;

    mediator->hlProxiesCount = 0;
}