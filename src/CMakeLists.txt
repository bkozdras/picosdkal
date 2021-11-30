#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(LOCAL_HEADERS_DIR ${HEADERS_DIR})
set(PACKAGE_NAME_LOCAL library)
set(PROJECT_NAME ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_LOCAL})

project(${PROJECT_NAME})

add_subdirectory(context)
add_subdirectory(core)
add_subdirectory(gpio)
add_subdirectory(system)

add_library(${PROJECT_NAME} STATIC)

target_link_libraries(${PROJECT_NAME}
    ${PROJECT_NAME}_context
    ${PROJECT_NAME}_core
    ${PROJECT_NAME}_gpio
    ${PROJECT_NAME}_system
)

if (BUILD_LIB_FOR_TARGET)
    link_pico_sdk_libraries(${PROJECT_NAME})
endif (BUILD_LIB_FOR_TARGET)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
