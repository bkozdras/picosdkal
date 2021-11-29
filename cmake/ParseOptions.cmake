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
option(RPIPICOSDKAL_UNIT_TESTS_GENERATE_CODE_COVERAGE OFF, "Generate code coverage by UTs with the use of lcov")
option(RPIPICOSDKAL_UNIT_TESTS_USE_ADDRESS_SANITIZER OFF, "Use address sanitizer in UT running")

option(RPIPICOSDKAL_ENABLE_LOGGING OFF, "Enabled logging in library")

message(STATUS "Passed options:")
message(STATUS "RPIPICOSDKAL_BUILD_LIB_FOR_TARGET: " ${RPIPICOSDKAL_BUILD_LIB_FOR_TARGET})
message(STATUS "RPIPICOSDKAL_BUILD_LIB_FOR_HOST: " ${RPIPICOSDKAL_BUILD_LIB_FOR_HOST})
message(STATUS "RPIPICOSDKAL_BUILD_LIB_MOCKS_FOR_HOST: " ${RPIPICOSDKAL_BUILD_LIB_MOCKS_FOR_HOST})
message(STATUS "RPIPICOSDKAL_BUILD_LIB_STUBS_FOR_HOST: " ${RPIPICOSDKAL_BUILD_LIB_STUBS_FOR_HOST})
message(STATUS "RPIPICOSDKAL_BUILD_UNIT_TESTS: " ${RPIPICOSDKAL_BUILD_UNIT_TESTS})
message(STATUS "RPIPICOSDKAL_UNIT_TESTS_GENERATE_CODE_COVERAGE: " ${RPIPICOSDKAL_UNIT_TESTS_GENERATE_CODE_COVERAGE})
message(STATUS "RPIPICOSDKAL_UNIT_TESTS_USE_ADDRESS_SANITIZER: " ${RPIPICOSDKAL_UNIT_TESTS_USE_ADDRESS_SANITIZER})
message(STATUS "RPIPICOSDKAL_ENABLE_LOGGING: " ${RPIPICOSDKAL_ENABLE_LOGGING})

set(BUILD_LIB_FOR_TARGET OFF)
set(BUILD_LIB_FOR_HOST OFF)
set(BUILD_LIB_MOCKS_FOR_HOST OFF)
set(BUILD_LIB_STUBS_FOR_HOST OFF)
set(BUILD_UNIT_TESTS OFF)
set(UNIT_TESTS_GENERATE_CODE_COVERAGE OFF)
set(UNIT_TESTS_USE_ADDRESS_SANITIZER OFF)
set(ENABLE_SDK_LOGGING OFF)

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
        if (RPIPICOSDKAL_UNIT_TESTS_GENERATE_CODE_COVERAGE)
            set(UNIT_TESTS_GENERATE_CODE_COVERAGE ON)
        endif (RPIPICOSDKAL_UNIT_TESTS_GENERATE_CODE_COVERAGE)
        if (RPIPICOSDKAL_UNIT_TESTS_USE_ADDRESS_SANITIZER)
            set(UNIT_TESTS_USE_ADDRESS_SANITIZER ON)
        endif (RPIPICOSDKAL_UNIT_TESTS_USE_ADDRESS_SANITIZER)
    endif (RPIPICOSDKAL_BUILD_UNIT_TESTS)
endif (RPIPICOSDKAL_BUILD_LIB_FOR_TARGET)

if (RPIPICOSDKAL_ENABLE_LOGGING)
    set(ENABLE_SDK_LOGGING ON)
endif (RPIPICOSDKAL_ENABLE_LOGGING)

message(STATUS "BUILD_LIB_FOR_TARGET: " ${BUILD_LIB_FOR_TARGET})
message(STATUS "BUILD_LIB_FOR_HOST: " ${BUILD_LIB_FOR_HOST})
message(STATUS "BUILD_LIB_MOCKS_FOR_HOST: " ${BUILD_LIB_MOCKS_FOR_HOST})
message(STATUS "BUILD_LIB_STUBS_FOR_HOST: " ${BUILD_LIB_STUBS_FOR_HOST})
message(STATUS "BUILD_UNIT_TESTS: " ${BUILD_UNIT_TESTS})
message(STATUS "UNIT_TESTS_GENERATE_CODE_COVERAGE: " ${UNIT_TESTS_GENERATE_CODE_COVERAGE})
message(STATUS "UNIT_TESTS_USE_ADDRESS_SANITIZER: " ${UNIT_TESTS_USE_ADDRESS_SANITIZER})
message(STATUS "ENABLE_SDK_LOGGING: " ${ENABLE_SDK_LOGGING})
