#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(PACKAGE_NAME common)
set(PROJECT_NAME ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_STUB}_${PACKAGE_NAME})

project(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${HEADERS_DIR_STUB}/ExampleStub.hpp

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/ExampleStub.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${INCLUDE_DIR}
        ${INCLUDE_DIR_STUB}
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
