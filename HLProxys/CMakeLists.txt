add_library(HLProxys)

target_sources(LLProxys PRIVATE
    led_matrix/LedMatrixProxy.c
    BaseHLProxy.c
    oled_display/OLedDisplayProxy.c
    )

target_include_directories(HLProxys  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/hall_sensor
    ${CMAKE_CURRENT_SOURCE_DIR}/led_matrix
    ${CMAKE_CURRENT_SOURCE_DIR}/oled_display
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

target_link_libraries(HLProxys PUBLIC stm32cubemx)

