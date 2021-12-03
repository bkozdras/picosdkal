#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(UT_BINARY_NAME ${PROJECT_NAME_PREFIX}_UT_system)

add_executable(${UT_BINARY_NAME})

target_sources(${UT_BINARY_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/EventQueueTests.cpp
)

target_link_libraries(${UT_BINARY_NAME}
    PUBLIC
        ${PROJECT_NAME_PREFIX}_UT_main
)

target_include_directories(${UT_BINARY_NAME}
    PUBLIC
        ${INCLUDE_DIR}
        ${INCLUDE_DIR_TEST}
        ${googletest_SOURCE_DIR}
)

add_test(NAME ${UT_BINARY_NAME}
    COMMAND ${UT_BINARY_NAME})
