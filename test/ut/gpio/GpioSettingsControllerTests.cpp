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

    IGpioSettingsControllerPtr sut_;
};

GpioSettingsControllerShould::GpioSettingsControllerShould()
    : picoGpioMock_()
    , testedCorrectGpioNumber_(22u)
    , sut_(nullptr)
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

TEST_F(GpioSettingsControllerShould, DISABLED_returnCorrectGpioDirectionForSioGpioFunction)
{
    expectAllGpiosFunctionSetToSioInputOnCreation();
    auto sut = createSut();

    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_IN));
        const auto returnedGpioDirection = sut_->getGpioDirection(testedCorrectGpioNumber_);
        ASSERT_NE(returnedGpioDirection, std::nullopt)
            << std::endl << testutil::source_location::toString();
        ASSERT_EQ(returnedGpioDirection.value(), definitions::EGpioDirection::Input)
            << std::endl << testutil::source_location::toString();
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get_function(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_FUNC_SIO));
        EXPECT_CALL(picoGpioMock_, gpio_get_dir(testedCorrectGpioNumber_))
            .WillOnce(::testing::Return(GPIO_OUT));
        const auto returnedGpioDirection = sut_->getGpioDirection(testedCorrectGpioNumber_);
        ASSERT_NE(returnedGpioDirection, std::nullopt)
            << std::endl << testutil::source_location::toString();
        ASSERT_EQ(returnedGpioDirection.value(), definitions::EGpioDirection::Output)
            << std::endl << testutil::source_location::toString();
    }
}

}  // namespace gpio
}  // namespace rpipicosdkal
