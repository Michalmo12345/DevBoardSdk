add_library(framework)

target_sources(framework PRIVATE
    gpio/Gpio.c)

target_include_directories(framework PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/gpio
    ${CMAKE_CURRENT_SOURCE_DIR}/tools)

    target_link_libraries(framework PUBLIC stm32cubemx)