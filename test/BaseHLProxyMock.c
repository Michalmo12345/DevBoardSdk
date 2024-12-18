#include "BaseHLProxyMock.h"

int mock_execute_call_count = 0;
int mock_shutdown_call_count = 0;


void mock_BaseHLProxy_init(BaseHLProxy* proxy) {
    proxy->name = "default_name";  
    proxy->execute = mock_execute;
    proxy->shutdown = mock_shutdown;
}


void mock_execute(BaseHLProxy* proxy, const char* action) {
    mock_execute_call_count++;
}


void mock_shutdown(BaseHLProxy* proxy) {
    mock_shutdown_call_count++;
}