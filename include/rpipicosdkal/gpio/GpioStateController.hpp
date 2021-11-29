/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_GPIOSTATECONTROLLER_HPP_
#define RPIPICOSDKAL_GPIO_GPIOSTATECONTROLLER_HPP_

#include <cstdint>
#include <memory>
#include <string>

#include <rpipicosdkal/core/Types.hpp>
#include <rpipicosdkal/core/definitions/EOperationResult.hpp>
#include <rpipicosdkal/gpio/fwd.hpp>
#include <rpipicosdkal/gpio/IGpioStateController.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class GpioStateController final : public IGpioStateController
{
public:
    static IGpioStateControllerPtr create(IGpioSettingsController& gpioSettingsController);
    ~GpioStateController() = default;

    std::optional<definitions::EGpioState> getInputLevel(
        const core::TGpioNumber gpioNumber) override;
    std::optional<definitions::EGpioState> getOutputLevel(
        const core::TGpioNumber gpioNumber) override;
    core::definitions::EOperationResult setOutputLevel(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioState gpioState) override;

private:
    explicit GpioStateController(IGpioSettingsController& gpioSettingsController);

    static const std::string loggerPrefix_;
    IGpioSettingsController& gpioSettingsController_;
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_GPIOSTATECONTROLLER_HPP_
