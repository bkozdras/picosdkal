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
    include(cmake/AddPicoSdkIncludeDirectories.cmake)
    include(cmake/LinkPicoSdkLibraries.cmake)
endif (BUILD_LIB_FOR_TARGET OR BUILD_LIB_FOR_HOST)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(INCLUDE_DIR_MOCK ${CMAKE_CURRENT_SOURCE_DIR}/mock)
set(INCLUDE_DIR_PICOSDKHOSTINERFACE ${CMAKE_CURRENT_SOURCE_DIR}/picosdkhostinterface)
set(INCLUDE_DIR_STUB ${CMAKE_CURRENT_SOURCE_DIR}/stub)
set(INCLUDE_DIR_TEST ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(HEADERS_DIR ${INCLUDE_DIR}/rpipicosdkal)
set(HEADERS_DIR_MOCK ${INCLUDE_DIR_MOCK}/rpipicosdkalmock)
set(HEADERS_DIR_STUB ${INCLUDE_DIR_STUB}/rpipicosdkalstub)
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(PROJECT_NAME_PREFIX RASPBERRY_PI_PICO_SDK_ABSTRACT_LAYER)
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

if (UNIT_TESTS_GENERATE_CODE_COVERAGE)
    include(cmake/CodeCoverage.cmake)
    append_coverage_compiler_flags()
    add_compile_options(-O0)
endif (UNIT_TESTS_GENERATE_CODE_COVERAGE)

if (UNIT_TESTS_USE_ADDRESS_SANITIZER)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-omit-frame-pointer -fsanitize=address -fsanitize=leak -g")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address -fsanitize=leak")
    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address -fsanitize=leak")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address -fsanitize=leak")
endif (UNIT_TESTS_USE_ADDRESS_SANITIZER)

if (BUILD_LIB_MOCKS_FOR_HOST OR BUILD_LIB_STUBS_FOR_HOST OR BUILD_UNIT_TESTS)
    include(cmake/FetchAndInitializeGTest.cmake)
endif (BUILD_LIB_MOCKS_FOR_HOST OR BUILD_LIB_STUBS_FOR_HOST OR BUILD_UNIT_TESTS)

if (BUILD_LIB_FOR_HOST)
    include_directories(picosdkhostinterface)
    add_subdirectory(picosdkhostinterface)
endif (BUILD_LIB_FOR_HOST)

if (BUILD_LIB_FOR_TARGET OR BUILD_LIB_FOR_HOST)
    if (ENABLE_SDK_LOGGING)
        add_definitions(-DUSE_SDK_LOGGING)
    endif (ENABLE_SDK_LOGGING)
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
    include_directories(test)
    add_subdirectory(test)
endif (BUILD_UNIT_TESTS)
