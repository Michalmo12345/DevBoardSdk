/**
 * @file Mediator.c
 * @author Michał Mokrzycki
 * @brief Mediator  (manager) class for communciation between HLProxies and main
 application
 * @date 2024-12-15

 */

#include "Mediator.h"

#include <stdio.h>
static void mediator_register_proxy(Mediator *mediator, BaseHLProxy *proxy)
{
    if (mediator->hlProxiesCount >= MAX_HL_PROXIES_COUNT) {
        mediator->oled_proxy->clear();
        mediator->oled_proxy->draw_text("Cannot add proxy", 0, 0);
        mediator->oled_proxy->update_display();
        return;
    }
    mediator->hlProxies[mediator->hlProxiesCount] = proxy;
    mediator->hlProxiesCount++;
}

static void mediator_notify(Mediator *mediator, ActionType action,
                            const char *proxy_name)
{
    for (size_t i = 0; i < mediator->hlProxiesCount; i++) {
        BaseHLProxy *proxy = mediator->hlProxies[i];

        OLEDProxy *oledProxy = mediator->oled_proxy;

        if (proxy && proxy->execute && strcmp(proxy->name, proxy_name) == 0) {
            bool success = proxy->execute(proxy, action);
            oledProxy->clear();

            char response_text1[100];
            snprintf(response_text1, sizeof(response_text1), "Proxy: %s",
                     proxy->name);
            oledProxy->draw_text(response_text1, 0, 0);

            // TODO dobrać parametry w draw text by wyświetlało się w drugiej
            // linii
            char response_text2[100];
            snprintf(response_text2, sizeof(response_text2), "%s",
                     success ? "Responds" : "Not responding");
            oledProxy->draw_text(response_text2, 0, 10);
            oledProxy->update_display();
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