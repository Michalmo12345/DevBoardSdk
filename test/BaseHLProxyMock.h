#ifndef BASEHLPROXYMOCK_H
#define BASEHLPROXYMOCK_H

#include "BaseHLProxy.h"
#include "proxy_actions.h"

#include <stdint.h>

void mock_BaseHLProxy_init(BaseHLProxy *proxy);
void mock_execute(BaseHLProxy *proxy, ActionType action);
void mock_shutdown(BaseHLProxy *proxy);

#endif // BASEHLPROXYMOCK_H