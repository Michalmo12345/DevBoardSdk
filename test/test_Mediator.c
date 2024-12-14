#include "unity.h"
#include "BaseHLProxyMock.h"
#include "Mediator.h"


#define INIT_HL_PROXIES_COUNT 10

Mediator test_mediator;

void setUp(void)
{
    mediator_init(&test_mediator);
}

void tearDown(void)
{
    mediator_shutdown(&test_mediator);
}

void test_mediator_init(void)
{
    TEST_ASSERT_NOT_NULL(test_mediator.hlProxies);
    TEST_ASSERT_EQUAL(0, test_mediator.hlProxiesCount);
    TEST_ASSERT_NOT_NULL(test_mediator.register_proxy);
    TEST_ASSERT_NOT_NULL(test_mediator.notify);
    TEST_ASSERT_NOT_NULL(test_mediator.shutdown);
}

void test_median_register_proxy(void)
{
    BaseHLProxy test_proxy;
    mock_BaseHLProxy_init(&test_proxy);

    test_mediator.register_proxy(&test_mediator, &test_proxy);

    TEST_ASSERT_EQUAL(1, test_mediator.hlProxiesCount);
    TEST_ASSERT_EQUAL_PTR(&test_proxy, test_mediator.hlProxies[0]);
}


void test_mediator_notify(void)
{
    BaseHLProxy test_proxy;
    mock_BaseHLProxy_init(&test_proxy);

    test_mediator.register_proxy(&test_mediator, &test_proxy);

    test_mediator.notify(&test_mediator, "test_action", "default_name");

    TEST_ASSERT_EQUAL(1, test_mediator.hlProxiesCount);
}

void test_mediator_shutdown(void)
{
    BaseHLProxy test_proxy;
    mock_BaseHLProxy_init(&test_proxy);

    test_mediator.register_proxy(&test_mediator, &test_proxy);
    
    TEST_ASSERT_EQUAL(1, test_mediator.hlProxiesCount);

    test_mediator.shutdown(&test_mediator);

    TEST_ASSERT_EQUAL(0, test_mediator.hlProxiesCount);
    TEST_ASSERT_NULL(test_mediator.hlProxies);
}
