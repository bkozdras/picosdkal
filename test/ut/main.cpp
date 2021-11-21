#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

int main(int argc, char** argv)
{
    std::cout << "MY MAIN!" << std::endl;

    ::testing::InitGoogleMock(&argc, argv);

    const int result = RUN_ALL_TESTS();

    return result;
}
