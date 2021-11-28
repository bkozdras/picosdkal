/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_IGPIOSETTINGSCONTROLLER_HPP_
#define RPIPICOSDKAL_GPIO_IGPIOSETTINGSCONTROLLER_HPP_

#include <memory>
#include <optional>

#include <rpipicosdkal/core/Types.hpp>
#include <rpipicosdkal/core/definitions/EOperationResult.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDirection.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDriveStrength.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioFunction.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioPullUp.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioSlewRateLimiting.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class IGpioSettingsController
{
public:
    virtual ~IGpioSettingsController() = default;

    virtual std::optional<definitions::EGpioDirection> getGpioDirection(
        const core::TGpioNumber gpioNumber) = 0;
    virtual core::definitions::EOperationResult setGpioDirection(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioDirection gpioDirection) = 0;

    virtual std::optional<definitions::EGpioDriveStrength> getGpioDriveStrength(
        const core::TGpioNumber gpioNumber) = 0;
    virtual core::definitions::EOperationResult setGpioDriveStrength(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioDriveStrength gpioDriveStrength) = 0;

    virtual std::optional<definitions::EGpioFunction> getGpioFunction(
        const core::TGpioNumber gpioNumber) = 0;
    virtual core::definitions::EOperationResult setGpioFunction(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioFunction gpioFunction) = 0;

    virtual std::optional<definitions::EGpioPullUp> getGpioPullUp(
        const core::TGpioNumber gpioNumber) = 0;
    virtual core::definitions::EOperationResult setGpioPullUp(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioPullUp gpioPullUp) = 0;

    virtual std::optional<definitions::EGpioSlewRateLimiting> getGpioSlewRateLimiting(
        const core::TGpioNumber gpioNumber) = 0;
    virtual core::definitions::EOperationResult setGpioSlewRateLimiting(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioSlewRateLimiting gpioSlewRateLimiting) = 0;
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_IGPIOSETTINGSCONTROLLER_HPP_
