#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(PACKAGE_NAME gpio)
set(PROJECT_NAME ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_MOCK}_${PACKAGE_NAME})

project(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/IGpioInterruptControllerMock.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/IGpioSettingsControllerMock.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/IGpioStateControllerMock.hpp

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/IGpioInterruptControllerMock.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/IGpioSettingsControllerMock.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/IGpioStateControllerMock.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${googletest_SOURCE_DIR}
        ${INCLUDE_DIR}
        ${INCLUDE_DIR_MOCK}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        gmock
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
