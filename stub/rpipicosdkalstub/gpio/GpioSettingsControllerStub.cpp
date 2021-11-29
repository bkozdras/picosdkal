/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkalstub/gpio/GpioSettingsControllerStub.hpp>

#include <vector>

namespace rpipicosdkal
{
namespace gpio
{

namespace
{

std::vector<core::TGpioNumber> getAllGpioNumbers()
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
    return allPicoGpioNumbers;
}

bool isGpioNumberCorrect(const core::TGpioNumber gpioNumber)
{
    if (gpioNumber <= 22u)
    {
        return true;
    }
    if (gpioNumber >= 26u && gpioNumber <= 28u)
    {
        return true;
    }
    return false;
}

}  // namespace

GpioSettingsControllerStub::GpioSettingsControllerStub()
    : gpioToDirection_()
    , gpioToDriveStrength_()
    , gpioToFunction_()
    , gpioToPullUp_()
    , gpioToSlewRateLimiting_()
{
    const auto allGpios = getAllGpioNumbers();
    for (const auto gpio : allGpios)
    {
        gpioToDriveStrength_.emplace(std::make_pair(gpio, definitions::EGpioDriveStrength::_2mA));
        gpioToDirection_.emplace(std::make_pair(gpio, definitions::EGpioDirection::Input));
        gpioToFunction_.emplace(std::make_pair(gpio, definitions::EGpioFunction::SIO));
        gpioToPullUp_.emplace(std::make_pair(gpio, definitions::EGpioPullUp::NotPulled));
        gpioToSlewRateLimiting_.emplace(std::make_pair(gpio, definitions::EGpioSlewRateLimiting::Disabled));
    }
}

std::optional<definitions::EGpioDirection> GpioSettingsControllerStub::getGpioDirection(
    const core::TGpioNumber gpioNumber)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return std::nullopt;
    }
    const auto gpioFunction = gpioToFunction_.at(gpioNumber);
    if (gpioFunction != definitions::EGpioFunction::SIO)
    {
        return std::nullopt;
    }
    return gpioToDirection_.at(gpioNumber);
}

core::definitions::EOperationResult GpioSettingsControllerStub::setGpioDirection(
    const core::TGpioNumber gpioNumber,
    const definitions::EGpioDirection gpioDirection)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return core::definitions::EOperationResult::InvalidArgument;
    }
    const auto gpioFunction = gpioToFunction_.at(gpioNumber);
    if (gpioFunction != definitions::EGpioFunction::SIO)
    {
        return core::definitions::EOperationResult::NotPossible;
    }
    gpioToDirection_[gpioNumber] = gpioDirection;
    return core::definitions::EOperationResult::Success;
}

std::optional<definitions::EGpioDriveStrength> GpioSettingsControllerStub::getGpioDriveStrength(
    const core::TGpioNumber gpioNumber)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return std::nullopt;
    }
    const auto optionalGpioDirection = getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Output)
    {
        return std::nullopt;
    }
    return gpioToDriveStrength_.at(gpioNumber);
}

core::definitions::EOperationResult GpioSettingsControllerStub::setGpioDriveStrength(
    const core::TGpioNumber gpioNumber,
    const definitions::EGpioDriveStrength gpioDriveStrength)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return core::definitions::EOperationResult::InvalidArgument;
    }
    const auto optionalGpioDirection = getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Output)
    {
        return core::definitions::EOperationResult::NotPossible;
    }
    gpioToDriveStrength_[gpioNumber] = gpioDriveStrength;
    return core::definitions::EOperationResult::Success;
}

std::optional<definitions::EGpioFunction> GpioSettingsControllerStub::getGpioFunction(
    const core::TGpioNumber gpioNumber)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return std::nullopt;
    }
    return gpioToFunction_.at(gpioNumber);
}

core::definitions::EOperationResult GpioSettingsControllerStub::setGpioFunction(
    const core::TGpioNumber gpioNumber,
    const definitions::EGpioFunction gpioFunction)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return core::definitions::EOperationResult::InvalidArgument;
    }
    gpioToFunction_[gpioNumber] = gpioFunction;
    return core::definitions::EOperationResult::Success;
}

std::optional<definitions::EGpioPullUp> GpioSettingsControllerStub::getGpioPullUp(
    const core::TGpioNumber gpioNumber)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return std::nullopt;
    }
    return gpioToPullUp_.at(gpioNumber);
}

core::definitions::EOperationResult GpioSettingsControllerStub::setGpioPullUp(
    const core::TGpioNumber gpioNumber,
    const definitions::EGpioPullUp gpioPullUp)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return core::definitions::EOperationResult::InvalidArgument;
    }
    gpioToPullUp_[gpioNumber] = gpioPullUp;
    return core::definitions::EOperationResult::Success;
}

std::optional<definitions::EGpioSlewRateLimiting> GpioSettingsControllerStub::getGpioSlewRateLimiting(
    const core::TGpioNumber gpioNumber)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return std::nullopt;
    }
    const auto optionalGpioDirection = getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Output)
    {
        return std::nullopt;
    }
    return gpioToSlewRateLimiting_.at(gpioNumber);
}

core::definitions::EOperationResult GpioSettingsControllerStub::setGpioSlewRateLimiting(
    const core::TGpioNumber gpioNumber,
    const definitions::EGpioSlewRateLimiting gpioSlewRateLimiting)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return core::definitions::EOperationResult::InvalidArgument;
    }
    const auto optionalGpioDirection = getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Output)
    {
        return core::definitions::EOperationResult::NotPossible;
    }
    gpioToSlewRateLimiting_[gpioNumber] = gpioSlewRateLimiting;
    return core::definitions::EOperationResult::Success;
}

}  // namespace gpio
}  // namespace rpipicosdkal
