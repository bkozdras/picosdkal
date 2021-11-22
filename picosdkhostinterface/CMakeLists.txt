#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(PACKAGE_NAME_LOCAL picosdkhostinterface)
set(PROJECT_NAME ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_LOCAL})

project(${PROJECT_NAME})

add_subdirectory(hardware_gpio)

add_library(${PROJECT_NAME}_only_headers INTERFACE)

target_link_libraries(${PROJECT_NAME}_only_headers INTERFACE
    ${PROJECT_NAME}_hardware_gpio_only_headers)

add_library(${PROJECT_NAME}_headers_and_impl INTERFACE)

target_link_libraries(${PROJECT_NAME}_headers_and_impl INTERFACE
    ${PROJECT_NAME}_hardware_gpio_headers_and_impl)
