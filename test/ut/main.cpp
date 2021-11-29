/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <utility>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <rpipicosdkal/core/InternalSdkLogger.hpp>

int main(int argc, char** argv)
{
    ::testing::InitGoogleMock(&argc, argv);

    if (std::getenv("TEST_STDOUT_ENABLED") == nullptr)
    {
        rpipicosdkal::core::internalsdklogger::disableLogging();
    }
    else
    {
        rpipicosdkal::core::internalsdklogger::enableLogging();
    }

    const int result = RUN_ALL_TESTS();

    return result;
}
