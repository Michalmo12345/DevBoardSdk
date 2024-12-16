cmake_minimum_required(VERSION 3.10)
project(app)

include_directories(include)


add_library(app_core 
src/app_core.c
src/Mediator.c)


target_include_directories(app_core PUBLIC include)

target_link_libraries(app_core PUBLIC 
    stm32cubemx 
    LLProxys 
    HLProxys
)