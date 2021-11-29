/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/GpioStateController.hpp>

#include <sstream>

#include <hardware/gpio.h>

#include <rpipicosdkal/gpio/IGpioSettingsController.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDirection.hpp>

namespace rpipicosdkal
{
namespace gpio
{

GpioStateController::GpioStateController(IGpioSettingsController& gpioSettingsController)
    : detail::PrinterBase("GPIO/StateController")
    , gpioSettingsController_(gpioSettingsController)
{
}

IGpioStateControllerPtr GpioStateController::create(IGpioSettingsController& gpioSettingsController)
{
    return IGpioStateControllerPtr(new GpioStateController(gpioSettingsController));
}

std::optional<definitions::EGpioState> GpioStateController::getInputLevel(
    const core::TGpioNumber gpioNumber)
{
    const auto optionalGpioDirection = gpioSettingsController_.getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Input)
    {
        detail::PrinterBase::printNotValidGpioDirection(__FUNCTION__, gpioNumber, optionalGpioDirection);
        return std::nullopt;
    }
    const auto isHighLevel = ::gpio_get(gpioNumber);
    if (isHighLevel)
    {
        return definitions::EGpioState::High;
    }
    return definitions::EGpioState::Low;
}

std::optional<definitions::EGpioState> GpioStateController::getOutputLevel(
    const core::TGpioNumber gpioNumber)
{
    const auto optionalGpioDirection = gpioSettingsController_.getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Output)
    {
        detail::PrinterBase::printNotValidGpioDirection(__FUNCTION__, gpioNumber, optionalGpioDirection);
        return std::nullopt;
    }
    const auto isHighLevel = ::gpio_get(gpioNumber);
    if (isHighLevel)
    {
        return definitions::EGpioState::High;
    }
    return definitions::EGpioState::Low;
}

core::definitions::EOperationResult GpioStateController::setOutputLevel(
    const core::TGpioNumber gpioNumber,
    const definitions::EGpioState gpioState)
{
    const auto optionalGpioDirection = gpioSettingsController_.getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Output)
    {
        return detail::PrinterBase::printNotValidGpioDirectionAndReturnOperationResult(__FUNCTION__,
            gpioNumber,
            optionalGpioDirection,
            core::definitions::EOperationResult::NotPossible);
    }
    if (gpioState == definitions::EGpioState::Low)
    {
        ::gpio_put(gpioNumber, false);
    }
    else
    {
        ::gpio_put(gpioNumber, true);
    }
    std::ostringstream message;
    message
        << "Set GPIO " << std::to_string(gpioNumber)
        << " state to: " << definitions::toString(gpioState);
    return detail::PrinterBase::printMessageAndReturnOperationResult(__FUNCTION__,
        core::definitions::EOperationResult::Success,
        message.str());
}

}  // namespace gpio
}  // namespace rpipicosdkal
