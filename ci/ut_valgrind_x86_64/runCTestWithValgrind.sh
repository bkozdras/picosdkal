#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

#!/bin/bash

if ! valgrind --version &> /dev/null
then
    echo "Valgrind is not found!"
    exit -1
fi
echo "Valgrind version: $(valgrind --version)"

THIS_DIR_NAME=${PWD##*/}
if [ "$THIS_DIR_NAME" != "build_ut_valgrind_x86_64" ]
then
    echo "ERROR: CI pipeline issue! This script (runCTestWithValgrind.sh) should be executed from build_ut_valgrind_x86_64 directory!"
    echo "This directory: $THIS_DIR_NAME"
    exit -1
fi

valgrind --leak-check=full --track-origins=yes \
    ctest -j$(nproc --all) --output-on-failure

if [ $? -ne 0 ]
then
    echo "Failure in ctest. Cleaning up directory..."
    rm -r -f *
    exit -1
fi

exit 0
