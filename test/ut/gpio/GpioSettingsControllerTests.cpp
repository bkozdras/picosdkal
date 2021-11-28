/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <algorithm>
#include <cstdint>
#include <utility>
#include <vector>

#include <gmock/gmock.h>

#include <rpipicosdkal/core/Types.hpp>
#include <rpipicosdkal/core/definitions/EOperationResult.hpp>
#include <rpipicosdkal/gpio/fwd.hpp>
#include <rpipicosdkal/gpio/GpioSettingsController.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDirection.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDriveStrength.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioFunction.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioPullUp.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioSlewRateLimiting.hpp>

#include <picosdkmock/hardware_gpio/GpioMock.hpp>
#include <testutil/SourceLocationPrinter.hpp>

namespace rpipicosdkal
{
namespace gpio
{

namespace
{

std::vector<std::pair<definitions::EGpioFunction, enum gpio_function>> generateAllGpioFunctions()
{
    std::vector<std::pair<definitions::EGpioFunction, enum gpio_function>> gpioFunctions =
    {
        std::make_pair(definitions::EGpioFunction::NotSet, GPIO_FUNC_NULL),
        std::make_pair(definitions::EGpioFunction::XIP, GPIO_FUNC_XIP),
        std::make_pair(definitions::EGpioFunction::SPI, GPIO_FUNC_SPI),
        std::make_pair(definitions::EGpioFunction::UART, GPIO_FUNC_UART),
        std::make_pair(definitions::EGpioFunction::I2C, GPIO_FUNC_I2C),
        std::make_pair(definitions::EGpioFunction::PWM, GPIO_FUNC_PWM),
        std::make_pair(definitions::EGpioFunction::SIO, GPIO_FUNC_SIO),
        std::make_pair(definitions::EGpioFunction::PIO0, GPIO_FUNC_PIO0),
        std::make_pair(definitions::EGpioFunction::PIO1, GPIO_FUNC_PIO1),
        std::make_pair(definitions::EGpioFunction::GPCK, GPIO_FUNC_GPCK),
        std::make_pair(definitions::EGpioFunction::USB, GPIO_FUNC_USB)
    };
    return gpioFunctions;
}

std::vector<std::pair<definitions::EGpioFunction, enum gpio_function>> generateAllGpioFunctionsExcept(
    const std::vector<definitions::EGpioFunction>& excludedGpioFunctions)
{
    auto gpioFunctions = generateAllGpioFunctions();
    for (const auto excludedGpioFunction : excludedGpioFunctions)
    {
        gpioFunctions.erase(std::remove_if(std::begin(gpioFunctions),
                std::end(gpioFunctions),
                [excludedGpioFunction](const auto& gpioFunction)
                {
                    return excludedGpioFunction == gpioFunction.first;
                }),
            std::end(gpioFunctions));
    }
    return gpioFunctions;
}

std::vector<std::pair<definitions::EGpioFunction, enum gpio_function>> generateAllGpioFunctionsExcept(
    const definitions::EGpioFunction excludedGpioFunction)
{
    return generateAllGpioFunctionsExcept(std::vector<definitions::EGpioFunction>{excludedGpioFunction});
}

std::vector<core::TGpioNumber> generateInvalidGpioNumbers()
{
    std::vector<core::TGpioNumber> invalidGpioNumbers = {23u, 24u, 25u};
    for (auto number = 29u; number <= 100u; ++number)
    {
        invalidGpioNumbers.push_back(number);
    }
    return invalidGpioNumbers;
}

}  // namespace

class GpioSettingsControllerShould : public ::testing::Test
{
protected:
    GpioSettingsControllerShould();

    IGpioSettingsControllerPtr createSut();

    void expectAllGpiosFunctionSetToSioInputOnCreation(
        const std::source_location& location = std::source_location::current());

    picosdkmock::hardware_gpio::GpioStrictMock picoGpioMock_;
    const uint8_t testedCorrectGpioNumber_;
};

GpioSettingsControllerShould::GpioSettingsControllerShould()
    : picoGpioMock_()
    , testedCorrectGpioNumber_(22u)
{
}

IGpioSettingsControllerPtr GpioSettingsControllerShould::createSut()
{
    return GpioSettingsController::create();
}

void GpioSettingsControllerShould::expectAllGpiosFunctionSetToSioInputOnCreation(
    const std::source_location& location)
{
    std::vector<core::TGpioNumber> allPicoGpioNumbers;
    for (auto gpioNumber = 0u; gpioNumber <= 22u; ++gpioNumber)
    {
        allPicoGpioNumbers.push_back(gpioNumber);
    }
    for (auto gpioNumber = 26u; gpioNumber <= 28u; ++gpioNumber)
    {
        allPicoGpioNumbers.push_back(gpioNumber);
    }
    for (const auto gpioNumber : allPicoGpioNumbers)
    {
        EXPECT_CALL(picoGpioMock_, gpio_set_function(gpioNumber, GPIO_FUNC_SIO))
            .Times(1u);
        EXPECT_CALL(picoGpioMock_, gpio_set_dir(gpioNumber, false))
            .Times(1u);
    }
}

TEST_F(GpioSettingsControllerShould, setAllGpiosToSioAndInput)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();
}

TEST_F(GpioSettingsControllerShould, returnNulloptForGetGpioDirectionAndInvalidGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto invalidGpioNumbers = generateInvalidGpioNumbers();
    for (const auto invalidGpioNumber : invalidGpioNumbers)
    {
        EXPECT_EQ(sut->getGpioDirection(invalidGpioNumber), std::nullopt)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNulloptForGetGpioDirectionAndNotSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto gpioFunctions = generateAllGpioFunctionsExcept(definitions::EGpioFunction::SIO);
    for (const auto& gpioFunction : gpioFunctions)
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(gpioFunction.second));
        EXPECT_EQ(sut->getGpioDirection(testedCorrectGpioNumber_), std::nullopt)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnCorrectGpioDirectionForSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_IN));
        const auto returnedGpioDirection = sut->getGpioDirection(testedCorrectGpioNumber_);
        ASSERT_NE(returnedGpioDirection, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(returnedGpioDirection.value(), definitions::EGpioDirection::Input)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        const auto returnedGpioDirection = sut->getGpioDirection(testedCorrectGpioNumber_);
        ASSERT_NE(returnedGpioDirection, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(returnedGpioDirection.value(), definitions::EGpioDirection::Output)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnInvalidArgumentForSetGpioDirectionAndInvalidGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto invalidGpioNumbers = generateInvalidGpioNumbers();
    for (const auto invalidGpioNumber : invalidGpioNumbers)
    {
        EXPECT_EQ(sut->setGpioDirection(invalidGpioNumber, definitions::EGpioDirection::Output),
                core::definitions::EOperationResult::InvalidArgument)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNotPossibleForSetGpioDirectionAndNotSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto gpioFunctions = generateAllGpioFunctionsExcept(definitions::EGpioFunction::SIO);
    for (const auto& gpioFunction : gpioFunctions)
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(gpioFunction.second));
        EXPECT_EQ(sut->setGpioDirection(testedCorrectGpioNumber_, definitions::EGpioDirection::Output),
                core::definitions::EOperationResult::NotPossible)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnSuccessOnSetGpioDirectionForSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_set_dir(testedCorrectGpioNumber_, GPIO_IN))
            .Times(1u);
        EXPECT_EQ(sut->setGpioDirection(testedCorrectGpioNumber_, definitions::EGpioDirection::Input),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_set_dir(testedCorrectGpioNumber_, GPIO_OUT))
            .Times(1u);
        EXPECT_CALL(picoGpioMock_, gpio_put(testedCorrectGpioNumber_, false))
            .Times(1u);
        EXPECT_CALL(picoGpioMock_, gpio_set_drive_strength(testedCorrectGpioNumber_, GPIO_DRIVE_STRENGTH_2MA))
            .Times(1u);
        EXPECT_CALL(picoGpioMock_, gpio_set_slew_rate(testedCorrectGpioNumber_, GPIO_SLEW_RATE_FAST))
            .Times(1u);
        EXPECT_EQ(sut->setGpioDirection(testedCorrectGpioNumber_, definitions::EGpioDirection::Output),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNulloptForGetGpioDriveStrengthAndInvalidGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto invalidGpioNumbers = generateInvalidGpioNumbers();
    for (const auto invalidGpioNumber : invalidGpioNumbers)
    {
        EXPECT_EQ(sut->getGpioDriveStrength(invalidGpioNumber), std::nullopt)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNulloptForGetGpioDriveStrengthAndNotSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto gpioFunctions = generateAllGpioFunctionsExcept(definitions::EGpioFunction::SIO);
    for (const auto& gpioFunction : gpioFunctions)
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(gpioFunction.second));
        EXPECT_EQ(sut->getGpioDriveStrength(testedCorrectGpioNumber_), std::nullopt)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNulloptForGetGpioDriveStrengthAndInputSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
        .WillOnce(::testing::Return(GPIO_FUNC_SIO));
    EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
        .WillOnce(::testing::Return(GPIO_IN));
    EXPECT_EQ(sut->getGpioDriveStrength(testedCorrectGpioNumber_), std::nullopt)
        << std::endl << testutil::source_location::toString();
}

TEST_F(GpioSettingsControllerShould, returnCorrectGpioDriveStrengthForOutputSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        EXPECT_CALL(picoGpioMock_, gpio_get_drive_strength(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_DRIVE_STRENGTH_2MA));
        const auto optionalReturnedValue = sut->getGpioDriveStrength(testedCorrectGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(optionalReturnedValue.value(), definitions::EGpioDriveStrength::_2mA)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        EXPECT_CALL(picoGpioMock_, gpio_get_drive_strength(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_DRIVE_STRENGTH_4MA));
        const auto optionalReturnedValue = sut->getGpioDriveStrength(testedCorrectGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(optionalReturnedValue.value(), definitions::EGpioDriveStrength::_4mA)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        EXPECT_CALL(picoGpioMock_, gpio_get_drive_strength(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_DRIVE_STRENGTH_8MA));
        const auto optionalReturnedValue = sut->getGpioDriveStrength(testedCorrectGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(optionalReturnedValue.value(), definitions::EGpioDriveStrength::_8mA)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        EXPECT_CALL(picoGpioMock_, gpio_get_drive_strength(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_DRIVE_STRENGTH_12MA));
        const auto optionalReturnedValue = sut->getGpioDriveStrength(testedCorrectGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(optionalReturnedValue.value(), definitions::EGpioDriveStrength::_12mA)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnInvalidArgumentForSetGpioDriveStrengthAndInvalidGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto invalidGpioNumbers = generateInvalidGpioNumbers();
    for (const auto invalidGpioNumber : invalidGpioNumbers)
    {
        EXPECT_EQ(sut->setGpioDriveStrength(invalidGpioNumber, definitions::EGpioDriveStrength::_2mA),
                core::definitions::EOperationResult::InvalidArgument)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNotPossibleForSetGpioDriveStrengthAndNotSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto gpioFunctions = generateAllGpioFunctionsExcept(definitions::EGpioFunction::SIO);
    for (const auto& gpioFunction : gpioFunctions)
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(gpioFunction.second));
        EXPECT_EQ(sut->setGpioDriveStrength(testedCorrectGpioNumber_, definitions::EGpioDriveStrength::_2mA),
                core::definitions::EOperationResult::NotPossible)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNotPossibleForSetGpioDriveStrengthAndSioInputGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
        .WillOnce(::testing::Return(GPIO_FUNC_SIO));
    EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
        .WillOnce(::testing::Return(GPIO_IN));
    EXPECT_EQ(sut->setGpioDriveStrength(testedCorrectGpioNumber_, definitions::EGpioDriveStrength::_2mA),
            core::definitions::EOperationResult::NotPossible)
        << std::endl << testutil::source_location::toString();
}

TEST_F(GpioSettingsControllerShould, returnSuccessOnSetGpioDriveStrengthForSioGpioOutput)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        EXPECT_CALL(picoGpioMock_, gpio_set_drive_strength(testedCorrectGpioNumber_, GPIO_DRIVE_STRENGTH_2MA))
            .Times(1u);
        EXPECT_EQ(sut->setGpioDriveStrength(testedCorrectGpioNumber_, definitions::EGpioDriveStrength::_2mA),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        EXPECT_CALL(picoGpioMock_, gpio_set_drive_strength(testedCorrectGpioNumber_, GPIO_DRIVE_STRENGTH_4MA))
            .Times(1u);
        EXPECT_EQ(sut->setGpioDriveStrength(testedCorrectGpioNumber_, definitions::EGpioDriveStrength::_4mA),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        EXPECT_CALL(picoGpioMock_, gpio_set_drive_strength(testedCorrectGpioNumber_, GPIO_DRIVE_STRENGTH_8MA))
            .Times(1u);
        EXPECT_EQ(sut->setGpioDriveStrength(testedCorrectGpioNumber_, definitions::EGpioDriveStrength::_8mA),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        EXPECT_CALL(picoGpioMock_, gpio_set_drive_strength(testedCorrectGpioNumber_, GPIO_DRIVE_STRENGTH_12MA))
            .Times(1u);
        EXPECT_EQ(sut->setGpioDriveStrength(testedCorrectGpioNumber_, definitions::EGpioDriveStrength::_12mA),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNulloptForGetGpioFunctionAndInvalidGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto invalidGpioNumbers = generateInvalidGpioNumbers();
    for (const auto invalidGpioNumber : invalidGpioNumbers)
    {
        EXPECT_EQ(sut->getGpioFunction(invalidGpioNumber), std::nullopt)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnCorrectGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto gpioFunctions = generateAllGpioFunctions();
    for (const auto& gpioFunction : gpioFunctions)
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(gpioFunction.second));
        const auto optionalReturnedValue = sut->getGpioFunction(testedCorrectGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(optionalReturnedValue.value(), gpioFunction.first)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnInvalidArgumentForSetGpioFunctionAndInvalidGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto invalidGpioNumbers = generateInvalidGpioNumbers();
    for (const auto invalidGpioNumber : invalidGpioNumbers)
    {
        EXPECT_EQ(sut->setGpioFunction(invalidGpioNumber, definitions::EGpioFunction::SIO),
                core::definitions::EOperationResult::InvalidArgument)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnSuccessForSetGpioFunctionAndCorrectGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto gpioFunctions = generateAllGpioFunctions();
    for (const auto& gpioFunction : gpioFunctions)
    {
        EXPECT_CALL(picoGpioMock_, gpio_set_function(testedCorrectGpioNumber_, gpioFunction.second))
            .Times(1u);
        EXPECT_EQ(sut->setGpioFunction(testedCorrectGpioNumber_, gpioFunction.first),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNulloptForGetGpioPullUpAndInvalidGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto invalidGpioNumbers = generateInvalidGpioNumbers();
    for (const auto invalidGpioNumber : invalidGpioNumbers)
    {
        EXPECT_EQ(sut->getGpioPullUp(invalidGpioNumber), std::nullopt)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnCorrectGpioPullUpForValidGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    {
        EXPECT_CALL(picoGpioMock_, gpio_is_pulled_down(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(false));
        EXPECT_CALL(picoGpioMock_, gpio_is_pulled_up(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(false));
        const auto optionalReturnedValue = sut->getGpioPullUp(testedCorrectGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(optionalReturnedValue.value(), definitions::EGpioPullUp::NotPulled)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_is_pulled_down(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(true));
        EXPECT_CALL(picoGpioMock_, gpio_is_pulled_up(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(false));
        const auto optionalReturnedValue = sut->getGpioPullUp(testedCorrectGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(optionalReturnedValue.value(), definitions::EGpioPullUp::Down)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_is_pulled_down(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(false));
        EXPECT_CALL(picoGpioMock_, gpio_is_pulled_up(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(true));
        const auto optionalReturnedValue = sut->getGpioPullUp(testedCorrectGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(optionalReturnedValue.value(), definitions::EGpioPullUp::Up)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_is_pulled_down(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(true));
        EXPECT_CALL(picoGpioMock_, gpio_is_pulled_up(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(true));
        const auto optionalReturnedValue = sut->getGpioPullUp(testedCorrectGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(optionalReturnedValue.value(), definitions::EGpioPullUp::BusKeep)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnInvalidArgumentForSetGpioPullUpAndInvalidGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto invalidGpioNumbers = generateInvalidGpioNumbers();
    for (const auto invalidGpioNumber : invalidGpioNumbers)
    {
        EXPECT_EQ(sut->setGpioPullUp(invalidGpioNumber, definitions::EGpioPullUp::Up),
                core::definitions::EOperationResult::InvalidArgument)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnSuccessForSetGpioPullUpAndValidGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    {
        EXPECT_CALL(picoGpioMock_, gpio_set_pulls(testedCorrectGpioNumber_, false, false));
        EXPECT_EQ(sut->setGpioPullUp(testedCorrectGpioNumber_, definitions::EGpioPullUp::NotPulled),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_set_pulls(testedCorrectGpioNumber_, false, true));
        EXPECT_EQ(sut->setGpioPullUp(testedCorrectGpioNumber_, definitions::EGpioPullUp::Down),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_set_pulls(testedCorrectGpioNumber_, true, false));
        EXPECT_EQ(sut->setGpioPullUp(testedCorrectGpioNumber_, definitions::EGpioPullUp::Up),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_set_pulls(testedCorrectGpioNumber_, true, true));
        EXPECT_EQ(sut->setGpioPullUp(testedCorrectGpioNumber_, definitions::EGpioPullUp::BusKeep),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNulloptForGetGpioSlewRateLimitingAndInvalidGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto invalidGpioNumbers = generateInvalidGpioNumbers();
    for (const auto invalidGpioNumber : invalidGpioNumbers)
    {
        EXPECT_EQ(sut->getGpioSlewRateLimiting(invalidGpioNumber), std::nullopt)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNulloptForGetGpioSlewRateLimitingAndNotSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto gpioFunctions = generateAllGpioFunctionsExcept(definitions::EGpioFunction::SIO);
    for (const auto& gpioFunction : gpioFunctions)
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(gpioFunction.second));
        EXPECT_EQ(sut->getGpioSlewRateLimiting(testedCorrectGpioNumber_), std::nullopt)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNulloptForGetGpioSlewRateLimitingAndInputSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
        .WillOnce(::testing::Return(GPIO_FUNC_SIO));
    EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
        .WillOnce(::testing::Return(GPIO_IN));
    EXPECT_EQ(sut->getGpioSlewRateLimiting(testedCorrectGpioNumber_), std::nullopt)
        << std::endl << testutil::source_location::toString();
}

TEST_F(GpioSettingsControllerShould, returnCorrectGpioSlewRateLimitingForOutputSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        EXPECT_CALL(picoGpioMock_, gpio_get_slew_rate(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_SLEW_RATE_SLOW));
        const auto optionalReturnedValue = sut->getGpioSlewRateLimiting(testedCorrectGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(optionalReturnedValue.value(), definitions::EGpioSlewRateLimiting::Enabled)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        EXPECT_CALL(picoGpioMock_, gpio_get_slew_rate(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_SLEW_RATE_FAST));
        const auto optionalReturnedValue = sut->getGpioSlewRateLimiting(testedCorrectGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt)
            << std::endl << testutil::source_location::toString();
        EXPECT_EQ(optionalReturnedValue.value(), definitions::EGpioSlewRateLimiting::Disabled)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnInvalidArgumentForSetGpioSlewRateLimitingAndInvalidGpioNumber)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto invalidGpioNumbers = generateInvalidGpioNumbers();
    for (const auto invalidGpioNumber : invalidGpioNumbers)
    {
        EXPECT_EQ(sut->setGpioSlewRateLimiting(invalidGpioNumber, definitions::EGpioSlewRateLimiting::Enabled),
                core::definitions::EOperationResult::InvalidArgument)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNotPossibleForSetGpioSlewRateLimitingAndNotSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    const auto gpioFunctions = generateAllGpioFunctionsExcept(definitions::EGpioFunction::SIO);
    for (const auto& gpioFunction : gpioFunctions)
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(gpioFunction.second));
        EXPECT_EQ(sut->setGpioSlewRateLimiting(testedCorrectGpioNumber_, definitions::EGpioSlewRateLimiting::Enabled),
                core::definitions::EOperationResult::NotPossible)
            << std::endl << testutil::source_location::toString();
    }
}

TEST_F(GpioSettingsControllerShould, returnNotPossibleForSetGpioSlewRateLimitingAndSioInputGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
        .WillOnce(::testing::Return(GPIO_FUNC_SIO));
    EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
        .WillOnce(::testing::Return(GPIO_IN));
    EXPECT_EQ(sut->setGpioSlewRateLimiting(testedCorrectGpioNumber_, definitions::EGpioSlewRateLimiting::Enabled),
            core::definitions::EOperationResult::NotPossible)
        << std::endl << testutil::source_location::toString();
}

TEST_F(GpioSettingsControllerShould, returnSuccessOnSetGpioSlewRateLimitingForSioGpioOutput)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        EXPECT_CALL(picoGpioMock_, gpio_set_slew_rate(testedCorrectGpioNumber_, GPIO_SLEW_RATE_SLOW))
            .Times(1u);
        EXPECT_EQ(sut->setGpioSlewRateLimiting(testedCorrectGpioNumber_, definitions::EGpioSlewRateLimiting::Enabled),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        EXPECT_CALL(picoGpioMock_, gpio_set_slew_rate(testedCorrectGpioNumber_, GPIO_SLEW_RATE_FAST))
            .Times(1u);
        EXPECT_EQ(sut->setGpioSlewRateLimiting(testedCorrectGpioNumber_, definitions::EGpioSlewRateLimiting::Disabled),
                core::definitions::EOperationResult::Success)
            << std::endl << testutil::source_location::toString();
    }
}

}  // namespace gpio
}  // namespace rpipicosdkal
