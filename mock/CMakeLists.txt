#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(PACKAGE_NAME_MOCK mock)
set(PROJECT_NAME ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_MOCK})

project(${PROJECT_NAME})

add_subdirectory(rpipicosdkalmock)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-field-initializers -Wnon-virtual-dtor -Wsign-compare -Woverloaded-virtual -Wunused-function")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og -fno-inline -ggdb3")

add_library(${PROJECT_NAME} STATIC)

target_link_libraries(${PROJECT_NAME}
    ${PROJECT_NAME}_core
    ${PROJECT_NAME}_gpio
)
