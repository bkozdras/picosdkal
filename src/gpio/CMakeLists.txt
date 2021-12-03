#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(LOCAL_HEADERS_DIR ${HEADERS_DIR})
set(PACKAGE_NAME_LOCAL library_gpio)
set(PROJECT_NAME ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_LOCAL})

project(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${LOCAL_HEADERS_DIR}/gpio/fwd.hpp
        ${LOCAL_HEADERS_DIR}/gpio/IGpioInterruptController.hpp
        ${LOCAL_HEADERS_DIR}/gpio/IGpioSettingsController.hpp
        ${LOCAL_HEADERS_DIR}/gpio/IGpioStateController.hpp
        ${LOCAL_HEADERS_DIR}/gpio/GpioInterruptController.hpp
        ${LOCAL_HEADERS_DIR}/gpio/GpioSettingsController.hpp
        ${LOCAL_HEADERS_DIR}/gpio/GpioStateController.hpp
        ${LOCAL_HEADERS_DIR}/gpio/definitions/fwd.hpp
        ${LOCAL_HEADERS_DIR}/gpio/definitions/EGpioDirection.hpp
        ${LOCAL_HEADERS_DIR}/gpio/definitions/EGpioDriveStrength.hpp
        ${LOCAL_HEADERS_DIR}/gpio/definitions/EGpioFunction.hpp
        ${LOCAL_HEADERS_DIR}/gpio/definitions/EGpioPullUp.hpp
        ${LOCAL_HEADERS_DIR}/gpio/definitions/EGpioSlewRateLimiting.hpp
        ${LOCAL_HEADERS_DIR}/gpio/definitions/EGpioState.hpp

    PRIVATE
        ${LOCAL_HEADERS_DIR}/gpio/detail/PrinterBase.hpp

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Context.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/GpioInterruptController.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/GpioSettingsController.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/GpioStateController.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/definitions/EGpioDirection.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/definitions/EGpioDriveStrength.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/definitions/EGpioFunction.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/definitions/EGpioPullUp.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/definitions/EGpioSlewRateLimiting.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/definitions/EGpioState.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/detail/PrinterBase.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    ${PROJECT_NAME_PREFIX}_library_core
)

if (BUILD_LIB_FOR_TARGET)
    add_pico_sdk_include_directories(${PROJECT_NAME})
    target_link_libraries(${PROJECT_NAME_PREFIX}_picosdklibrary
        INTERFACE
            pico_stdlib
            hardware_gpio
            hardware_irq
    )
else ()
    if (BUILD_UNIT_TESTS)
        target_link_libraries(${PROJECT_NAME}
            ${PROJECT_NAME_PREFIX}_picosdkhostinterface_hardware_gpio_only_headers
        )
    else ()
        target_link_libraries(${PROJECT_NAME}
            ${PROJECT_NAME_PREFIX}_picosdkhostinterface_hardware_gpio_headers_and_impl
        )
    endif (BUILD_UNIT_TESTS)
endif (BUILD_LIB_FOR_TARGET)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
