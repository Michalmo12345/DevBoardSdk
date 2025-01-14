/**
 * @file Mediator.c
 * @author Michał Mokrzycki
 * @brief Mediator  (manager) class for communciation between HLProxies and main
 application
 * @date 2024-12-15

 */

#include "Mediator.h"

static void mediator_register_proxy(Mediator *mediator, BaseHLProxy *proxy)
{
    if (mediator->hlProxiesCount >= MAX_HL_PROXIES_COUNT) {
        // handle error: exceeded maximum number of proxies
        return;
    }
    mediator->hlProxies[mediator->hlProxiesCount] = proxy;
    mediator->hlProxiesCount++;
}

static void mediator_notify(Mediator *mediator,
                            const char *action, // zmeinić na enuma
                            const char *proxy_name)
{
    for (size_t i = 0; i < mediator->hlProxiesCount; i++) {
        BaseHLProxy *proxy = mediator->hlProxies[i];

        OLEDProxy *oledProxy = mediator->oled_proxy;

        if (proxy && proxy->execute && proxy->name == proxy_name) {
            bool success = proxy->execute(proxy, action);
            if (success) {

                oledProxy->clear();
                oledProxy->draw_text("Responds", 0, 0);
                oledProxy->update_display();
            } else {

                oledProxy->clear();
                oledProxy->draw_text("Doesnt respond", 0, 0);
                oledProxy->update_display();
            }
        }
    }
}

static void mediator_shutdown(Mediator *mediator)
{
    for (size_t i = 0; i < mediator->hlProxiesCount; i++) {
        BaseHLProxy *proxy = mediator->hlProxies[i];

        if (proxy && proxy->shutdown) {
            proxy->shutdown(proxy);
        }

        mediator->hlProxies[i] = NULL;
    }

    mediator->hlProxiesCount = 0;
}

void mediator_init(Mediator *mediator, OLEDProxy *oled_proxy)
{

    if (!mediator)
        return;

    memset(mediator->hlProxies, 0, sizeof(mediator->hlProxies));
    mediator->hlProxiesCount = 0;

    mediator->oled_proxy     = oled_proxy;
    mediator->register_proxy = mediator_register_proxy;
    mediator->notify         = mediator_notify;
    mediator->shutdown       = mediator_shutdown;
}