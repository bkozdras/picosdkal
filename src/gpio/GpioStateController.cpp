/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/GpioStateController.hpp>

#include <hardware/gpio.h>

namespace rpipicosdkal
{
namespace gpio
{

GpioStateController::GpioStateController() = default;

IGpioStateControllerPtr GpioStateController::create()
{
    return IGpioStateControllerPtr(new GpioStateController());
}

definitions::EGpioState GpioStateController::getInputLevel(const uint8_t gpio)
{
    const auto isHighLevel = ::gpio_get(gpio);
    if (isHighLevel)
    {
        return definitions::EGpioState::High;
    }
    return definitions::EGpioState::Low;
}

definitions::EGpioState GpioStateController::getOutputLevel(const uint8_t gpio)
{
    const auto isHighLevel = ::gpio_get(gpio);
    if (isHighLevel)
    {
        return definitions::EGpioState::High;
    }
    return definitions::EGpioState::Low;
}

bool GpioStateController::setOutputLevel(const uint8_t gpio, const definitions::EGpioState gpioState)
{
    if (gpioState == definitions::EGpioState::Low)
    {
        ::gpio_put(gpio, 0);
        return true;
    }
    ::gpio_put(gpio, 1);
    return true;
}

}  // namespace gpio
}  // namespace rpipicosdkal
