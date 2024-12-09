add_library(HLProxys )

target_sources(LLProxys  PRIVATE
    led_matrix/LedMatrixProxy.c
    )

target_include_directories(HLProxys  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lcd
    ${CMAKE_CURRENT_SOURCE_DIR}/hall_sensor
    ${CMAKE_CURRENT_SOURCE_DIR}/led_matrix
    )

    target_link_libraries(HLProxys PUBLIC stm32cubemx)

