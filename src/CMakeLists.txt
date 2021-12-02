#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(LOCAL_HEADERS_DIR ${HEADERS_DIR})
set(PACKAGE_NAME_LOCAL library)
set(PROJECT_NAME ${PROJECT_NAME_PREFIX}_${PACKAGE_NAME_LOCAL})

if (BUILD_LIB_FOR_TARGET)
    add_library(${PROJECT_NAME_PREFIX}_picosdklibrary INTERFACE)
endif (BUILD_LIB_FOR_TARGET)

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

if (BUILD_LIB_FOR_TARGET AND BUILD_DUMMY_EXECUTABLE)
    add_executable(dummybinary
        ${CMAKE_CURRENT_SOURCE_DIR}/dummymain.cpp)
    target_link_libraries(dummybinary
        ${PROJECT_NAME}
        ${PROJECT_NAME_PREFIX}_picosdklibrary)
    pico_add_extra_outputs(dummybinary)
endif (BUILD_LIB_FOR_TARGET AND BUILD_DUMMY_EXECUTABLE)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
