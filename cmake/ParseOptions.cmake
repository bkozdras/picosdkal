#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

option(RPIPICOSDKAL_BUILD_LIB_FOR_TARGET OFF, "Build Raspberry Pi PICO SDK Abstract Library static for target")
option(RPIPICOSDKAL_BUILD_LIB_FOR_HOST OFF, "Build Raspberry Pi PICO SDK Abstract Library static for host")

option(RPIPICOSDKAL_BUILD_LIB_MOCKS_FOR_HOST OFF, "Build Raspberry Pi PICO SDK Abstract Library mocks")
option(RPIPICOSDKAL_BUILD_LIB_STUBS_FOR_HOST OFF, "Build Raspberry Pi PICO SDK Abstract Library stubs")

option(RPIPICOSDKAL_BUILD_UNIT_TESTS OFF, "Build Raspberry Pi PICO SDK Abstract Library unit tests")

message(STATUS "Passed options:")
message(STATUS "RPIPICOSDKAL_BUILD_LIB_FOR_TARGET: " ${RPIPICOSDKAL_BUILD_LIB_FOR_TARGET})
message(STATUS "RPIPICOSDKAL_BUILD_LIB_FOR_HOST: " ${RPIPICOSDKAL_BUILD_LIB_FOR_HOST})
message(STATUS "RPIPICOSDKAL_BUILD_LIB_MOCKS_FOR_HOST: " ${RPIPICOSDKAL_BUILD_LIB_MOCKS_FOR_HOST})
message(STATUS "RPIPICOSDKAL_BUILD_LIB_STUBS_FOR_HOST: " ${RPIPICOSDKAL_BUILD_LIB_STUBS_FOR_HOST})
message(STATUS "RPIPICOSDKAL_BUILD_UNIT_TESTS: " ${RPIPICOSDKAL_BUILD_UNIT_TESTS})

set(BUILD_LIB_FOR_TARGET OFF)
set(BUILD_LIB_FOR_HOST OFF)
set(BUILD_LIB_MOCKS_FOR_HOST OFF)
set(BUILD_LIB_STUBS_FOR_HOST OFF)
set(BUILD_UNIT_TESTS OFF)

if (RPIPICOSDKAL_BUILD_LIB_FOR_TARGET)
    set(BUILD_LIB_FOR_TARGET ON)
    set(BUILD_LIB_FOR_HOST OFF)
    set(BUILD_LIB_MOCKS_FOR_HOST OFF)
    set(BUILD_LIB_STUBS_FOR_HOST OFF)
    set(BUILD_UNIT_TESTS OFF)
else ()
    set(BUILD_LIB_FOR_TARGET OFF)
    if (RPIPICOSDKAL_BUILD_LIB_FOR_HOST)
        set(BUILD_LIB_FOR_HOST ON)
    endif (RPIPICOSDKAL_BUILD_LIB_FOR_HOST)
    if (RPIPICOSDKAL_BUILD_LIB_MOCKS_FOR_HOST)
        set(BUILD_LIB_MOCKS_FOR_HOST ON)
    endif (RPIPICOSDKAL_BUILD_LIB_MOCKS_FOR_HOST)
    if (RPIPICOSDKAL_BUILD_LIB_STUBS_FOR_HOST)
        set(BUILD_LIB_STUBS_FOR_HOST ON)
    endif (RPIPICOSDKAL_BUILD_LIB_STUBS_FOR_HOST)
    if (RPIPICOSDKAL_BUILD_UNIT_TESTS)
        set(BUILD_UNIT_TESTS ON)
        set(BUILD_LIB_FOR_HOST ON)
        set(BUILD_LIB_MOCKS_FOR_HOST ON)
    endif (RPIPICOSDKAL_BUILD_UNIT_TESTS)
endif (RPIPICOSDKAL_BUILD_LIB_FOR_TARGET)

message(STATUS "BUILD_LIB_FOR_TARGET: " ${BUILD_LIB_FOR_TARGET})
message(STATUS "BUILD_LIB_FOR_HOST: " ${BUILD_LIB_FOR_HOST})
message(STATUS "BUILD_LIB_MOCKS_FOR_HOST: " ${BUILD_LIB_MOCKS_FOR_HOST})
message(STATUS "BUILD_LIB_STUBS_FOR_HOST: " ${BUILD_LIB_STUBS_FOR_HOST})
message(STATUS "BUILD_UNIT_TESTS: " ${BUILD_UNIT_TESTS})
