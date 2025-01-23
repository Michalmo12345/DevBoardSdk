#include "BaseHLProxyMock.h"
#include "Mediator.h"
#include "mock_OLedDisplayProxy.h"
#include "proxy_actions.h"
#include "unity.h"
#define MAX_HL_PROXIES_COUNT 10

void setUp(void) {}

void tearDown(void) {}

void test_mediator_init(void)
{

    Mediator test_mediator;
    OLEDProxy mock_oled_proxy;

    mediator_init(&test_mediator, &mock_oled_proxy);

    TEST_ASSERT_NOT_NULL(test_mediator.hlProxies);
    TEST_ASSERT_EQUAL(0, test_mediator.hlProxiesCount);
    TEST_ASSERT_NOT_NULL(test_mediator.register_proxy);
    TEST_ASSERT_NOT_NULL(test_mediator.notify);
    TEST_ASSERT_NOT_NULL(test_mediator.shutdown);
}

void test_mediator_register_proxy(void)
{

    Mediator test_mediator;
    OLEDProxy mock_oled_proxy;
    mediator_init(&test_mediator, &mock_oled_proxy);

    BaseHLProxy test_proxy;
    mock_BaseHLProxy_init(&test_proxy);

    test_mediator.register_proxy(&test_mediator, &test_proxy);

    TEST_ASSERT_EQUAL(1, test_mediator.hlProxiesCount);
    TEST_ASSERT_EQUAL_PTR(&test_proxy, test_mediator.hlProxies[0]);
}

void test_mediator_shutdown(void)
{

    Mediator test_mediator;
    OLEDProxy mock_oled_proxy;
    mediator_init(&test_mediator, &mock_oled_proxy);

    BaseHLProxy test_proxy;
    mock_BaseHLProxy_init(&test_proxy);

    test_mediator.register_proxy(&test_mediator, &test_proxy);

    TEST_ASSERT_EQUAL(1, test_mediator.hlProxiesCount);

    test_mediator.shutdown(&test_mediator);
    for (size_t i = 0; i < MAX_HL_PROXIES_COUNT; i++) {
        TEST_ASSERT_NULL(test_mediator.hlProxies[i]);
    }
    TEST_ASSERT_EQUAL(0, test_mediator.hlProxiesCount);
}