#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(PACKAGE_NAME_STUB stub)
set(PROJECT_NAME ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_STUB})

project(${PROJECT_NAME})

add_subdirectory(rpipicosdkalstub)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-field-initializers -Wnon-virtual-dtor -Wsign-compare -Woverloaded-virtual -Wunused-function")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og -fno-inline -ggdb3")

add_library(${PROJECT_NAME} STATIC)

target_link_libraries(${PROJECT_NAME}
    ${PROJECT_NAME}_context
    ${PROJECT_NAME}_gpio
)
