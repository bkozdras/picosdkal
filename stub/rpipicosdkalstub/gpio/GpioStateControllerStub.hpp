/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKALSTUB_GPIO_GPIOSTATECONTROLLERSTUB_HPP_
#define RPIPICOSDKALSTUB_GPIO_GPIOSTATECONTROLLERSTUB_HPP_

#include <map>
#include <memory>
#include <optional>

#include <rpipicosdkal/core/Types.hpp>
#include <rpipicosdkal/core/definitions/EOperationResult.hpp>
#include <rpipicosdkal/gpio/IGpioStateController.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioState.hpp>

#include <rpipicosdkalstub/gpio/GpioSettingsControllerStub.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class GpioStateControllerStub;
using GpioStateControllerStubPtr = std::unique_ptr<GpioStateControllerStub>;

class GpioStateControllerStub : public IGpioStateController
{
public:
    static GpioStateControllerStubPtr create(GpioSettingsControllerStub& gpioSettingsControllerStub);
    ~GpioStateControllerStub() = default;

    std::optional<definitions::EGpioState> getInputLevel(
        const core::TGpioNumber gpioNumber) override;
    std::optional<definitions::EGpioState> getOutputLevel(
        const core::TGpioNumber gpioNumber) override;
    core::definitions::EOperationResult setOutputLevel(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioState gpioState) override;

    void simulateGpioStateChange(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioState gpioState);

private:
    explicit GpioStateControllerStub(GpioSettingsControllerStub& gpioSettingsControllerStub);

    GpioSettingsControllerStub& gpioSettingsControllerStub_;
    std::map<core::TGpioNumber /*GPIO*/, definitions::EGpioState> gpioToState_;
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKALSTUB_GPIO_GPIOSTATECONTROLLERSTUB_HPP_
