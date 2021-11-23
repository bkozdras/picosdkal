#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Purpose: To build and run unit tests for Raspberry Pi Pico SDK Abstract Layer.   #
#          Unit tests code coverage for system under test is generated.            #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

#!/bin/bash

if [[ "$RASPBERRY_PI_PICO_BUILD_ENVIRONMENT_CONTAINER" != "1" ]]
then
    echo "This script should be called from docker container - see dockerimage submodule!"
    exit -1
fi

if ! cmake --version &> /dev/null
then
    echo "CMake is not found!"
    exit -1
fi

if ! make --version &> /dev/null
then
    echo "Make is not found!"
    exit -1
fi

THIS_DIR=$(pwd)
EXPECTED_DIR=$(git rev-parse --show-toplevel)

if [[ "$THIS_DIR" != "$EXPECTED_DIR" ]]
then
    echo "This script should be called from git repo root directory!"
    exit -1
fi

mkdir -p build
cd build

THIS_ARCH=$(uname -m | tr -d '\n')
BUILD_DIR=local_ut_lcov_$THIS_ARCH

mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_C_COMPILER=gcc-$GCC_VERSION \
    -DCMAKE_CXX_COMPILER=g++-$GCC_VERSION \
    -DRPIPICOSDKAL_UNIT_TESTS_GENERATE_CODE_COVERAGE=ON \
    -DRPIPICOSDKAL_BUILD_UNIT_TESTS=ON ../.. \
    && make -j$(nproc --all) \
    && make -j$(nproc --all) ut-with-code-coverage

exit 0