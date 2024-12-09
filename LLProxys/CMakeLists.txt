add_library(LLProxys )

target_sources(LLProxys  PRIVATE
    gpio/GpioProxy.c
    spi/SpiProxy.c)

target_include_directories(LLProxys  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/gpio
    ${CMAKE_CURRENT_SOURCE_DIR}/spi
    ${CMAKE_CURRENT_SOURCE_DIR}/tools)

    target_link_libraries(LLProxys PUBLIC stm32cubemx)

