/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkalstub/gpio/GpioStateControllerStub.hpp>

namespace rpipicosdkal
{
namespace gpio
{

GpioStateControllerStub::GpioStateControllerStub()
    : gpioToState_()
{
}

std::optional<definitions::EGpioState> GpioStateControllerStub::getInputLevel(const core::TGpioNumber gpio)
{
    const auto iter = gpioToState_.find(gpio);
    if (iter == std::end(gpioToState_))
    {
        return std::nullopt;
    }
    return iter->second;
}

std::optional<definitions::EGpioState> GpioStateControllerStub::getOutputLevel(const core::TGpioNumber gpio)
{
    const auto iter = gpioToState_.find(gpio);
    if (iter == std::end(gpioToState_))
    {
        return std::nullopt;
    }
    return iter->second;
}

core::definitions::EOperationResult GpioStateControllerStub::setOutputLevel(const core::TGpioNumber gpio,
    const definitions::EGpioState gpioState)
{
    auto iter = gpioToState_.find(gpio);
    if (iter == std::end(gpioToState_))
    {
        iter = gpioToState_.emplace(std::pair<uint8_t, definitions::EGpioState>(
            gpio, definitions::EGpioState::Low)).first;
    }
    iter->second = gpioState;
    return core::definitions::EOperationResult::Success;
}

void GpioStateControllerStub::simulateGpioStateChange(const core::TGpioNumber gpio,
    const definitions::EGpioState gpioState)
{
    auto iter = gpioToState_.find(gpio);
    if (iter == std::end(gpioToState_))
    {
        iter = gpioToState_.emplace(std::pair<core::TGpioNumber, definitions::EGpioState>(
            gpio, definitions::EGpioState::Low)).first;
    }
    iter->second = gpioState;
}

}  // namespace gpio
}  // namespace rpipicosdkal
