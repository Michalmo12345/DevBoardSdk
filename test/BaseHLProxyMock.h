#ifndef BASEHLPROXYMOCK_H
#define BASEHLPROXYMOCK_H

#include <stdint.h>

#include "BaseHLProxy.h"  


void mock_BaseHLProxy_init(BaseHLProxy* proxy);
void mock_execute(BaseHLProxy* proxy, const char* action);
void mock_shutdown(BaseHLProxy* proxy);

#endif // BASEHLPROXYMOCK_H