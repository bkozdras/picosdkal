#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

#!/bin/bash

if ! cmake --version &> /dev/null
then
    echo "CMake is not found!"
    exit -1
fi

THIS_DIR_NAME=${PWD##*/}
if [ "$THIS_DIR_NAME" != "build_lib_stubs" ]
then
    echo "ERROR: CI pipeline issue! This script (runCMake.sh) should be executed from build_lib_stubs directory!"
    echo "This directory: $THIS_DIR_NAME"
    exit -1
fi

cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_C_COMPILER=gcc-$GCC_VERSION \
    -DCMAKE_CXX_COMPILER=g++-$GCC_VERSION \
    -DRPIPICOSDKAL_BUILD_LIB_STUBS_FOR_HOST=ON ..

if [ $? -ne 0 ]
then
    echo "Failure in cmake. Cleaning up directory..."
    rm -r -f *
    exit -1
fi

exit 0
