#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(LOCAL_HEADERS_DIR ${HEADERS_DIR})
set(PACKAGE_NAME_LOCAL library_system)
set(PROJECT_NAME ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_LOCAL})

project(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${LOCAL_HEADERS_DIR}/system/fwd.hpp
        ${LOCAL_HEADERS_DIR}/system/IApplication.hpp
        ${LOCAL_HEADERS_DIR}/system/EventQueue.hpp
        ${LOCAL_HEADERS_DIR}/system/Runner.hpp

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/EventQueue.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Runner.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_NAME_PREFIX}_library_context)

if (BUILD_LIB_FOR_TARGET)
    add_pico_sdk_include_directories(${PROJECT_NAME})
    target_link_libraries(${PROJECT_NAME_PREFIX}_picosdklibrary
        INTERFACE
            pico_stdlib
            pico_platform
    )
else ()
    target_link_libraries(${PROJECT_NAME} INTERFACE
        pico_base_headers
    )
endif (BUILD_LIB_FOR_TARGET)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
