/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/GpioSettingsController.hpp>

#include <sstream>
#include <string>
#include <vector>

#include <hardware/gpio.h>

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

definitions::EGpioDriveStrength toPicoSdkAlGpioDriveStrength(
    const enum gpio_drive_strength gpioDriveStrength)
{
    switch (gpioDriveStrength)
    {
        case GPIO_DRIVE_STRENGTH_2MA: return definitions::EGpioDriveStrength::_2mA;
        case GPIO_DRIVE_STRENGTH_4MA: return definitions::EGpioDriveStrength::_4mA;
        case GPIO_DRIVE_STRENGTH_8MA: return definitions::EGpioDriveStrength::_8mA;
        case GPIO_DRIVE_STRENGTH_12MA: return definitions::EGpioDriveStrength::_12mA;
    }
    return definitions::EGpioDriveStrength::_2mA;
}

enum gpio_drive_strength toPicoSdkGpioDriveStrength(
    const definitions::EGpioDriveStrength gpioDriveStrength)
{
    switch (gpioDriveStrength)
    {
        case definitions::EGpioDriveStrength::_2mA: return GPIO_DRIVE_STRENGTH_2MA;
        case definitions::EGpioDriveStrength::_4mA: return GPIO_DRIVE_STRENGTH_4MA;
        case definitions::EGpioDriveStrength::_8mA: return GPIO_DRIVE_STRENGTH_8MA;
        case definitions::EGpioDriveStrength::_12mA: return GPIO_DRIVE_STRENGTH_12MA;
    }
    return GPIO_DRIVE_STRENGTH_2MA;
}

definitions::EGpioFunction toPicoSdkAlGpioFunction(
    const enum gpio_function gpioFunction)
{
    switch (gpioFunction)
    {
        case GPIO_FUNC_NULL: return definitions::EGpioFunction::NotSet;
        case GPIO_FUNC_XIP: return definitions::EGpioFunction::XIP;
        case GPIO_FUNC_SPI: return definitions::EGpioFunction::SPI;
        case GPIO_FUNC_UART: return definitions::EGpioFunction::UART;
        case GPIO_FUNC_I2C: return definitions::EGpioFunction::I2C;
        case GPIO_FUNC_PWM: return definitions::EGpioFunction::PWM;
        case GPIO_FUNC_SIO: return definitions::EGpioFunction::SIO;
        case GPIO_FUNC_PIO0: return definitions::EGpioFunction::PIO0;
        case GPIO_FUNC_PIO1: return definitions::EGpioFunction::PIO1;
        case GPIO_FUNC_GPCK: return definitions::EGpioFunction::GPCK;
        case GPIO_FUNC_USB: return definitions::EGpioFunction::USB;
    }
    return definitions::EGpioFunction::NotSet;
}

enum gpio_function toPicoSdkGpioFunction(
    const definitions::EGpioFunction gpioFunction)
{
    switch (gpioFunction)
    {
        case definitions::EGpioFunction::NotSet: return GPIO_FUNC_NULL;
        case definitions::EGpioFunction::XIP: return GPIO_FUNC_XIP;
        case definitions::EGpioFunction::SPI: return GPIO_FUNC_SPI;
        case definitions::EGpioFunction::UART: return GPIO_FUNC_UART;
        case definitions::EGpioFunction::I2C: return GPIO_FUNC_I2C;
        case definitions::EGpioFunction::PWM: return GPIO_FUNC_PWM;
        case definitions::EGpioFunction::SIO: return GPIO_FUNC_SIO;
        case definitions::EGpioFunction::PIO0: return GPIO_FUNC_PIO0;
        case definitions::EGpioFunction::PIO1: return GPIO_FUNC_PIO1;
        case definitions::EGpioFunction::GPCK: return GPIO_FUNC_GPCK;
        case definitions::EGpioFunction::USB: return GPIO_FUNC_USB;
    }
    return GPIO_FUNC_NULL;
}

definitions::EGpioSlewRateLimiting toPicoSdkAlGpioSlewRateLimitating(
    const enum gpio_slew_rate gpioSlewRate)
{
    switch (gpioSlewRate)
    {
        case GPIO_SLEW_RATE_SLOW: return definitions::EGpioSlewRateLimiting::Enabled;
        case GPIO_SLEW_RATE_FAST: return definitions::EGpioSlewRateLimiting::Disabled;
    }
    return definitions::EGpioSlewRateLimiting::Disabled;
}

enum gpio_slew_rate toPicoSdkGpioSlewRate(
    const definitions::EGpioSlewRateLimiting gpioSlewRateLimiting)
{
    switch (gpioSlewRateLimiting)
    {
        case definitions::EGpioSlewRateLimiting::Enabled: return GPIO_SLEW_RATE_SLOW;
        case definitions::EGpioSlewRateLimiting::Disabled: return GPIO_SLEW_RATE_FAST;
    }
    return GPIO_SLEW_RATE_FAST;
}

}  // namespace

GpioSettingsController::GpioSettingsController()
    : detail::PrinterBase("GPIO/SettingsController")
{
    const auto allPicoGpioNumbers = getAllGpioNumbers();
    for (const auto gpioNumber : allPicoGpioNumbers)
    {
        ::gpio_set_function(static_cast<uint>(gpioNumber), GPIO_FUNC_SIO);
        ::gpio_set_dir(static_cast<uint>(gpioNumber), GPIO_IN);
    }
}

IGpioSettingsControllerPtr GpioSettingsController::create()
{
    return IGpioSettingsControllerPtr(new GpioSettingsController());
}

std::optional<definitions::EGpioDirection> GpioSettingsController::getGpioDirection(
    const core::TGpioNumber gpioNumber)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        detail::PrinterBase::printNotValidGpioNumber(__FUNCTION__, gpioNumber);
        return std::nullopt;
    }
    const auto optionalGpioFunction = getGpioFunction(gpioNumber);
    if (optionalGpioFunction == std::nullopt
        || optionalGpioFunction.value() != definitions::EGpioFunction::SIO)
    {
        detail::PrinterBase::printNotValidGpioFunction(__FUNCTION__, gpioNumber, optionalGpioFunction);
        return std::nullopt;
    }
    if (::gpio_get_dir(static_cast<uint>(gpioNumber)) == GPIO_OUT)
    {
        return definitions::EGpioDirection::Output;
    }
    return definitions::EGpioDirection::Input;
}

core::definitions::EOperationResult GpioSettingsController::setGpioDirection(
    const core::TGpioNumber gpioNumber,
    const definitions::EGpioDirection gpioDirection)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return detail::PrinterBase::printNotValidGpioNumberAndReturnOperationResult(__FUNCTION__,
            gpioNumber,
            core::definitions::EOperationResult::InvalidArgument);
    }
    const auto optionalGpioFunction = getGpioFunction(gpioNumber);
    if (optionalGpioFunction == std::nullopt
        || optionalGpioFunction.value() != definitions::EGpioFunction::SIO)
    {
        return detail::PrinterBase::printNotValidGpioFunctionAndReturnOperationResult(__FUNCTION__,
            gpioNumber,
            optionalGpioFunction,
            core::definitions::EOperationResult::NotPossible);
    }
    if (gpioDirection == definitions::EGpioDirection::Input)
    {
        ::gpio_set_dir(static_cast<uint>(gpioNumber), GPIO_IN);
    }
    else
    {
        ::gpio_set_dir(static_cast<uint>(gpioNumber), GPIO_OUT);
        ::gpio_put(static_cast<uint>(gpioNumber), false);
        ::gpio_set_drive_strength(static_cast<uint>(gpioNumber), GPIO_DRIVE_STRENGTH_2MA);
        ::gpio_set_slew_rate(static_cast<uint>(gpioNumber), GPIO_SLEW_RATE_FAST);
    }
    std::ostringstream message;
    message
        << "Set GPIO " << std::to_string(gpioNumber)
        << " direction to: " << definitions::toString(gpioDirection);
    return detail::PrinterBase::printMessageAndReturnOperationResult(__FUNCTION__,
        core::definitions::EOperationResult::Success,
        message.str());
}

std::optional<definitions::EGpioDriveStrength> GpioSettingsController::getGpioDriveStrength(
    const core::TGpioNumber gpioNumber)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        detail::PrinterBase::printNotValidGpioNumber(__FUNCTION__, gpioNumber);
        return std::nullopt;
    }
    const auto optionalGpioDirection = getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Output)
    {
        detail::PrinterBase::printNotValidGpioDirection(__FUNCTION__, gpioNumber, optionalGpioDirection);
        return std::nullopt;
    }
    const auto gpioDriveStrength = ::gpio_get_drive_strength(static_cast<uint>(gpioNumber));
    return toPicoSdkAlGpioDriveStrength(gpioDriveStrength);
}

core::definitions::EOperationResult GpioSettingsController::setGpioDriveStrength(
    const core::TGpioNumber gpioNumber,
    const definitions::EGpioDriveStrength gpioDriveStrength)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return detail::PrinterBase::printNotValidGpioNumberAndReturnOperationResult(__FUNCTION__,
            gpioNumber,
            core::definitions::EOperationResult::InvalidArgument);
    }
    const auto optionalGpioDirection = getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Output)
    {
        return detail::PrinterBase::printNotValidGpioDirectionAndReturnOperationResult(__FUNCTION__,
            gpioNumber,
            optionalGpioDirection,
            core::definitions::EOperationResult::NotPossible);
    }
    ::gpio_set_drive_strength(static_cast<uint>(gpioNumber), toPicoSdkGpioDriveStrength(gpioDriveStrength));
    std::ostringstream message;
    message
        << "Set GPIO " << std::to_string(gpioNumber)
        << " drive strength to: " << definitions::toString(gpioDriveStrength);
    return detail::PrinterBase::printMessageAndReturnOperationResult(__FUNCTION__,
        core::definitions::EOperationResult::Success,
        message.str());
}

std::optional<definitions::EGpioFunction> GpioSettingsController::getGpioFunction(
    const core::TGpioNumber gpioNumber)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        detail::PrinterBase::printNotValidGpioNumber(__FUNCTION__, gpioNumber);
        return std::nullopt;
    }
    return toPicoSdkAlGpioFunction(::gpio_get_function(static_cast<uint>(gpioNumber)));
}

core::definitions::EOperationResult GpioSettingsController::setGpioFunction(
    const core::TGpioNumber gpioNumber,
    const definitions::EGpioFunction gpioFunction)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return detail::PrinterBase::printNotValidGpioNumberAndReturnOperationResult(__FUNCTION__,
            gpioNumber,
            core::definitions::EOperationResult::InvalidArgument);
    }
    ::gpio_set_function(static_cast<uint>(gpioNumber),
        toPicoSdkGpioFunction(gpioFunction));
    std::ostringstream message;
    message
        << "Set GPIO " << std::to_string(gpioNumber)
        << " function to: " << definitions::toString(gpioFunction);
    return detail::PrinterBase::printMessageAndReturnOperationResult(__FUNCTION__,
        core::definitions::EOperationResult::Success,
        message.str());
}

std::optional<definitions::EGpioPullUp> GpioSettingsController::getGpioPullUp(
    const core::TGpioNumber gpioNumber)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        detail::PrinterBase::printNotValidGpioNumber(__FUNCTION__, gpioNumber);
        return std::nullopt;
    }
    const auto isPulledDown = ::gpio_is_pulled_down(static_cast<uint8_t>(gpioNumber));
    const auto isPulledUp = ::gpio_is_pulled_up(static_cast<uint8_t>(gpioNumber));
    if (isPulledUp && isPulledDown)
    {
        return definitions::EGpioPullUp::BusKeep;
    }
    if (isPulledUp)
    {
        return definitions::EGpioPullUp::Up;
    }
    if (isPulledDown)
    {
        return definitions::EGpioPullUp::Down;
    }
    return definitions::EGpioPullUp::NotPulled;
}

core::definitions::EOperationResult GpioSettingsController::setGpioPullUp(
    const core::TGpioNumber gpioNumber,
    const definitions::EGpioPullUp gpioPullUp)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return detail::PrinterBase::printNotValidGpioNumberAndReturnOperationResult(__FUNCTION__,
            gpioNumber,
            core::definitions::EOperationResult::InvalidArgument);
    }
    switch (gpioPullUp)
    {
        case definitions::EGpioPullUp::BusKeep:
        {
            ::gpio_set_pulls(static_cast<uint>(gpioNumber), true, true);
            break;
        }
        case definitions::EGpioPullUp::Down:
        {
            ::gpio_set_pulls(static_cast<uint>(gpioNumber), false, true);
            break;
        }
        case definitions::EGpioPullUp::Up:
        {
            ::gpio_set_pulls(static_cast<uint>(gpioNumber), true, false);
            break;
        }
        case definitions::EGpioPullUp::NotPulled:
        {
            ::gpio_set_pulls(static_cast<uint>(gpioNumber), false, false);
            break;
        }
    }
    std::ostringstream message;
    message
        << "Set GPIO " << std::to_string(gpioNumber)
        << " pull-up to: " << definitions::toString(gpioPullUp);
    return detail::PrinterBase::printMessageAndReturnOperationResult(__FUNCTION__,
        core::definitions::EOperationResult::Success,
        message.str());
}

std::optional<definitions::EGpioSlewRateLimiting> GpioSettingsController::getGpioSlewRateLimiting(
    const core::TGpioNumber gpioNumber)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        detail::PrinterBase::printNotValidGpioNumber(__FUNCTION__, gpioNumber);
        return std::nullopt;
    }
    const auto optionalGpioDirection = getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Output)
    {
        detail::PrinterBase::printNotValidGpioDirection(__FUNCTION__, gpioNumber, optionalGpioDirection);
        return std::nullopt;
    }
    return toPicoSdkAlGpioSlewRateLimitating(::gpio_get_slew_rate(static_cast<uint>(gpioNumber)));
}

core::definitions::EOperationResult GpioSettingsController::setGpioSlewRateLimiting(
    const core::TGpioNumber gpioNumber,
    const definitions::EGpioSlewRateLimiting gpioSlewRateLimiting)
{
    if (not isGpioNumberCorrect(gpioNumber))
    {
        return detail::PrinterBase::printNotValidGpioNumberAndReturnOperationResult(__FUNCTION__,
            gpioNumber,
            core::definitions::EOperationResult::InvalidArgument);
    }
    const auto optionalGpioDirection = getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Output)
    {
        return detail::PrinterBase::printNotValidGpioDirectionAndReturnOperationResult(__FUNCTION__,
            gpioNumber,
            optionalGpioDirection,
            core::definitions::EOperationResult::NotPossible);
    }
    ::gpio_set_slew_rate(static_cast<uint>(gpioNumber), toPicoSdkGpioSlewRate(gpioSlewRateLimiting));
    std::ostringstream message;
    message
        << "Set GPIO " << std::to_string(gpioNumber)
        << " slew rate: " << definitions::toString(gpioSlewRateLimiting);
    return detail::PrinterBase::printMessageAndReturnOperationResult(__FUNCTION__,
        core::definitions::EOperationResult::Success,
        message.str());
}

}  // namespace gpio
}  // namespace rpipicosdkal
