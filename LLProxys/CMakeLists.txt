add_library(LLProxys )

target_sources(LLProxys  PRIVATE
    gpio/GpioProxy.c
    i2c/I2CProxy.c
    spi/SpiProxy.c
    adc/AdcProxy.c
    delay_manager/delay_manager.c)

target_include_directories(LLProxys  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/gpio
    ${CMAKE_CURRENT_SOURCE_DIR}/adc
    ${CMAKE_CURRENT_SOURCE_DIR}/i2c
    ${CMAKE_CURRENT_SOURCE_DIR}/spi
    ${CMAKE_CURRENT_SOURCE_DIR}/delay_manager
    ${CMAKE_CURRENT_SOURCE_DIR}/tools)

target_link_libraries(LLProxys PUBLIC stm32cubemx)

