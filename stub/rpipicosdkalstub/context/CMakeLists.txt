#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(PACKAGE_NAME context)
set(PROJECT_NAME ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_STUB}_${PACKAGE_NAME})

project(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ContextStub.hpp

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/ContextStub.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${googletest_SOURCE_DIR}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${INCLUDE_DIR}
        ${INCLUDE_DIR_STUB}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_STUB}_gpio
        gmock)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
