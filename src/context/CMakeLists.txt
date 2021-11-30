#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(LOCAL_HEADERS_DIR ${HEADERS_DIR})
set(PACKAGE_NAME_LOCAL library_context)
set(PROJECT_NAME ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_LOCAL})

project(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${LOCAL_HEADERS_DIR}/context/fwd.hpp
        ${LOCAL_HEADERS_DIR}/context/IContext.hpp
        ${LOCAL_HEADERS_DIR}/context/ConfigurableContext.hpp
        ${LOCAL_HEADERS_DIR}/context/Context.hpp

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/ConfigurableContext.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Context.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${INCLUDE_DIR}
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
