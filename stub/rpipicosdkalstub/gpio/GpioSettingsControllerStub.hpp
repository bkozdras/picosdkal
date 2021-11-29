/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKALSTUB_GPIO_GPIOSETTINGSCONTROLLERSTUB_HPP_
#define RPIPICOSDKALSTUB_GPIO_GPIOSETTINGSCONTROLLERSTUB_HPP_

#include <map>
#include <memory>
#include <optional>

#include <rpipicosdkal/core/Types.hpp>
#include <rpipicosdkal/core/definitions/EOperationResult.hpp>
#include <rpipicosdkal/gpio/IGpioSettingsController.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDirection.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDriveStrength.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioFunction.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioPullUp.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioSlewRateLimiting.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class GpioSettingsControllerStub;
using GpioSettingsControllerStubPtr = std::unique_ptr<GpioSettingsControllerStub>;

class GpioSettingsControllerStub : public IGpioSettingsController
{
public:
    static GpioSettingsControllerStubPtr create();
    ~GpioSettingsControllerStub() = default;

    std::optional<definitions::EGpioDirection> getGpioDirection(
        const core::TGpioNumber gpioNumber) override;
    core::definitions::EOperationResult setGpioDirection(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioDirection gpioDirection) override;

    std::optional<definitions::EGpioDriveStrength> getGpioDriveStrength(
        const core::TGpioNumber) override;
    core::definitions::EOperationResult setGpioDriveStrength(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioDriveStrength gpioDriveStrength) override;

    std::optional<definitions::EGpioFunction> getGpioFunction(
        const core::TGpioNumber gpioNumber) override;
    core::definitions::EOperationResult setGpioFunction(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioFunction gpioFunction) override;

    std::optional<definitions::EGpioPullUp> getGpioPullUp(
        const core::TGpioNumber gpioNumber) override;
    core::definitions::EOperationResult setGpioPullUp(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioPullUp gpioPullUp) override;

    std::optional<definitions::EGpioSlewRateLimiting> getGpioSlewRateLimiting(
        const core::TGpioNumber gpioNumber) override;
    core::definitions::EOperationResult setGpioSlewRateLimiting(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioSlewRateLimiting gpioSlewRateLimiting) override;

private:
    GpioSettingsControllerStub();

    std::map<core::TGpioNumber /*GPIO*/, definitions::EGpioDirection> gpioToDirection_;
    std::map<core::TGpioNumber /*GPIO*/, definitions::EGpioDriveStrength> gpioToDriveStrength_;
    std::map<core::TGpioNumber /*GPIO*/, definitions::EGpioFunction> gpioToFunction_;
    std::map<core::TGpioNumber /*GPIO*/, definitions::EGpioPullUp> gpioToPullUp_;
    std::map<core::TGpioNumber /*GPIO*/, definitions::EGpioSlewRateLimiting> gpioToSlewRateLimiting_;
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKALSTUB_GPIO_GPIOSETTINGSCONTROLLERSTUB_HPP_
