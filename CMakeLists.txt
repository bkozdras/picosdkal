#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

include(cmake/ParseOptions.cmake)
include(cmake/SdkVersion.cmake)

# It has to be called before project setting
# as Pico SDK initializes compilers types
if (BUILD_LIB_FOR_TARGET OR BUILD_LIB_FOR_HOST)
    if (BUILD_LIB_FOR_HOST)
        set(PICO_PLATFORM "host")
    endif (BUILD_LIB_FOR_HOST)
    set(PICO_SDK_FETCH_FROM_GIT ON)
    include(cmake/FetchAndInitializePicoSdk.cmake)
    set(PICO_EXTRAS_FETCH_FROM_GIT ON)
    include(cmake/FetchAndInitializePicoSdkExtras.cmake)
    include(cmake/CopyPicoSdk.cmake)
    include(cmake/CopyPicoSdkExtras.cmake)
endif (BUILD_LIB_FOR_TARGET OR BUILD_LIB_FOR_HOST)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(INCLUDE_DIR_MOCK ${CMAKE_CURRENT_SOURCE_DIR}/mock)
set(INCLUDE_DIR_STUB ${CMAKE_CURRENT_SOURCE_DIR}/stub)
set(HEADERS_DIR ${INCLUDE_DIR}/rpipicosdkal)
set(HEADERS_DIR_MOCK ${INCLUDE_DIR_MOCK}/rpipicosdkalmock)
set(HEADERS_DIR_STUB ${INCLUDE_DIR_STUB}/rpipicosdkalstub)
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(PROJECT_NAME_PREFIX RPiPicoSdkAl)
project(${PROJECT_NAME_PREFIX} VERSION 1.0)

message(STATUS "Project name: ${PROJECT_NAME}")
message(STATUS "Target architecture: ARM32-CortexM0+")
execute_process(COMMAND uname -m
    COMMAND tr -d '\n'
    OUTPUT_VARIABLE THIS_ARCH)
message(STATUS "This architecture \(used for tests only\): ${THIS_ARCH}")

enable_language(C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# CMakes setup

if (BUILD_LIB_FOR_TARGET OR BUILD_LIB_FOR_HOST)
    message(STATUS "Initializing pico-sdk...")
    pico_sdk_init()
endif (BUILD_LIB_FOR_TARGET OR BUILD_LIB_FOR_HOST)

message(STATUS "CMAKE_C_COMPILER = ${CMAKE_C_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_ASM_COMPILER = ${CMAKE_ASM_COMPILER}")

include_directories(include)

if (BUILD_LIB_MOCKS_FOR_HOST OR BUILD_UNIT_TESTS)
    include(cmake/FetchAndInitializeGTest.cmake)
endif (BUILD_LIB_MOCKS_FOR_HOST OR BUILD_UNIT_TESTS)

if (BUILD_LIB_FOR_TARGET OR BUILD_LIB_FOR_HOST)
    add_subdirectory(src)
endif (BUILD_LIB_FOR_TARGET OR BUILD_LIB_FOR_HOST)

if (BUILD_LIB_MOCKS_FOR_HOST)
    include_directories(mock)
    add_subdirectory(mock)
endif (BUILD_LIB_MOCKS_FOR_HOST)

if (BUILD_LIB_STUBS_FOR_HOST)
    include_directories(stub)
    add_subdirectory(stub)
endif (BUILD_LIB_STUBS_FOR_HOST)

if (BUILD_UNIT_TESTS)
    enable_testing()
    add_subdirectory(test)
endif (BUILD_UNIT_TESTS)
