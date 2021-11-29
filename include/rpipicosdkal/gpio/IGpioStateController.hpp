/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_IGPIOSTATECONTROLLER_HPP_
#define RPIPICOSDKAL_GPIO_IGPIOSTATECONTROLLER_HPP_

#include <memory>
#include <optional>

#include <rpipicosdkal/core/Types.hpp>
#include <rpipicosdkal/core/definitions/EOperationResult.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioState.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class IGpioStateController
{
public:
    virtual ~IGpioStateController() = default;

    virtual std::optional<definitions::EGpioState> getInputLevel(
        const core::TGpioNumber gpioNumber) = 0;
    virtual std::optional<definitions::EGpioState> getOutputLevel(
        const core::TGpioNumber gpioNumber) = 0;
    virtual core::definitions::EOperationResult setOutputLevel(
        const core::TGpioNumber gpioNumber,
        const definitions::EGpioState gpioState) = 0;
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_IGPIOSTATECONTROLLER_HPP_
