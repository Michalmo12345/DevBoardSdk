cmake_minimum_required(VERSION 3.22)
project(${FRAMEWORK_LIB})

set(FRAMEWORK_DIRS
tools
)

set(FRAMEWORK_LIBS ${FRAMEWORK_DIRS})

foreach(dir IN LISTS FRAMEWORK_DIRS)
    add_subdirectory(${dir})
endforeach()

add_library(${PROJECT_NAME} INTERFACE)

target_link_libraries(${PROJECT_NAME} INTERFACE ${FRAMEWORK_LIBS})


