/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/GpioStateController.hpp>

#include <hardware/gpio.h>

#include <rpipicosdkal/core/InternalSdkLogger.hpp>
#include <rpipicosdkal/gpio/IGpioSettingsController.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDirection.hpp>

namespace rpipicosdkal
{
namespace gpio
{

const std::string GpioStateController::loggerPrefix_ = "GPIO/StateController";

GpioStateController::GpioStateController(IGpioSettingsController& gpioSettingsController)
    : gpioSettingsController_(gpioSettingsController)
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
        SDK_LOG_WARNING(loggerPrefix_)
            << "(getInputLevel) Not valid GPIO "
            << std::to_string(gpioNumber)
            << " direction: "
            << (optionalGpioDirection == std::nullopt
                ? std::string("N/A")
                : definitions::toString(optionalGpioDirection.value()));
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
        SDK_LOG_WARNING(loggerPrefix_)
            << "(getOutputLevel) Not valid GPIO "
            << std::to_string(gpioNumber)
            << " direction: "
            << (optionalGpioDirection == std::nullopt
                ? std::string("N/A")
                : definitions::toString(optionalGpioDirection.value()));
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
        SDK_LOG_WARNING(loggerPrefix_)
            << "(setOutputLevel) Not valid GPIO "
            << std::to_string(gpioNumber)
            << " direction: "
            << (optionalGpioDirection == std::nullopt
                ? std::string("N/A")
                : definitions::toString(optionalGpioDirection.value()));
        return core::definitions::EOperationResult::NotPossible;
    }
    if (gpioState == definitions::EGpioState::Low)
    {
        ::gpio_put(gpioNumber, false);
    }
    else
    {
        ::gpio_put(gpioNumber, true);
    }
    SDK_LOG_DEBUG(loggerPrefix_)
        << "Set GPIO " << std::to_string(gpioNumber)
        << " state to: " << definitions::toString(gpioState);
    return core::definitions::EOperationResult::Success;
}

}  // namespace gpio
}  // namespace rpipicosdkal
