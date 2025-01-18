add_library(HLProxys)

target_sources(LLProxys PRIVATE
    BaseHLProxy.c
    led_matrix/LedMatrixProxy.c
    oled_display/OLedDisplayProxy.c
    rf_module/RFModuleProxy.c
    EEPROM/EEPROMProxy.c
    light_sensor/LightSensorProxy.c
    )

target_include_directories(HLProxys  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/hall_sensor
    ${CMAKE_CURRENT_SOURCE_DIR}/led_matrix
    ${CMAKE_CURRENT_SOURCE_DIR}/oled_display
    ${CMAKE_CURRENT_SOURCE_DIR}/rf_module
    ${CMAKE_CURRENT_SOURCE_DIR}/light_sensor
    ${CMAKE_CURRENT_SOURCE_DIR}/EEPROM
    )

target_link_libraries(HLProxys PUBLIC stm32cubemx)

