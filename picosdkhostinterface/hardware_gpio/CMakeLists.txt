#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(PACKAGE_NAME_LOCAL picosdkhostinterface_hardware_gpio)
set(PROJECT_NAME ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_LOCAL})

project(${PROJECT_NAME})

add_library(${PROJECT_NAME}_only_headers INTERFACE)

target_include_directories(${PROJECT_NAME}_only_headers INTERFACE .)

target_link_libraries(${PROJECT_NAME}_only_headers INTERFACE
    pico_base_headers
)

add_library(${PROJECT_NAME}_headers_and_impl INTERFACE)

target_include_directories(${PROJECT_NAME}_headers_and_impl INTERFACE .)

target_sources(${PROJECT_NAME}_headers_and_impl INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/gpio.cpp
)

target_link_libraries(${PROJECT_NAME}_headers_and_impl INTERFACE
    pico_base_headers
)
