#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(UT_COMMON_LIBRARY ${PROJECT_NAME_PREFIX}_UT_main)

add_library(${UT_COMMON_LIBRARY} STATIC)

target_sources(${UT_COMMON_LIBRARY}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_include_directories(${UT_COMMON_LIBRARY}
    PUBLIC
        ${googletest_SOURCE_DIR}
)

target_link_libraries(${UT_COMMON_LIBRARY}
    PUBLIC
        ${PROJECT_NAME_PREFIX}_library
        ${PROJECT_NAME_PREFIX}_test_picosdkmock
        gmock
        pthread
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-field-initializers -Wnon-virtual-dtor -Wsign-compare -Woverloaded-virtual -Wunused-function")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og -fno-inline -ggdb3")

add_subdirectory(gpio)
