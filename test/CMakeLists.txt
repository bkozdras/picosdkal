#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-field-initializers -Woverloaded-virtual -Wignored-qualifiers -Wnon-virtual-dtor -Wsign-compare")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og -fno-inline -ggdb3")

add_subdirectory(ut)
