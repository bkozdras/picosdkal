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

definitions::EGpioState GpioStateControllerStub::getInputLevel(const uint8_t gpio)
{
    const auto iter = gpioToState_.find(gpio);
    if (iter == std::end(gpioToState_))
    {
        return definitions::EGpioState::Low;
    }
    return iter->second;
}

definitions::EGpioState GpioStateControllerStub::getOutputLevel(const uint8_t gpio)
{
    const auto iter = gpioToState_.find(gpio);
    if (iter == std::end(gpioToState_))
    {
        return definitions::EGpioState::Low;
    }
    return iter->second;
}

bool GpioStateControllerStub::setOutputLevel(const uint8_t gpio, const definitions::EGpioState gpioState)
{
    auto iter = gpioToState_.find(gpio);
    if (iter == std::end(gpioToState_))
    {
        iter = gpioToState_.emplace(std::pair<uint8_t, definitions::EGpioState>(
            gpio, definitions::EGpioState::Low)).first;
    }
    iter->second = gpioState;
    return true;
}

void GpioStateControllerStub::simulateGpioStateChange(const uint8_t gpio, const definitions::EGpioState gpioState)
{
    auto iter = gpioToState_.find(gpio);
    if (iter == std::end(gpioToState_))
    {
        iter = gpioToState_.emplace(std::pair<uint8_t, definitions::EGpioState>(
            gpio, definitions::EGpioState::Low)).first;
    }
    iter->second = gpioState;
}

}  // namespace gpio
}  // namespace rpipicosdkal
