/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/definitions/EGpioFunction.hpp>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

std::string toString(const EGpioFunction gpioFunction)
{
    switch (gpioFunction)
    {
        case EGpioFunction::NotSet: return "NotSet";
        case EGpioFunction::XIP: return "XIP";
        case EGpioFunction::SPI: return "SPI";
        case EGpioFunction::UART: return "UART";
        case EGpioFunction::I2C: return "I2C";
        case EGpioFunction::PWM: return "PWM";
        case EGpioFunction::SIO: return "SIO";
        case EGpioFunction::PIO0: return "PIO0";
        case EGpioFunction::PIO1: return "PIO1";
        case EGpioFunction::GPCK: return "GPCK";
        case EGpioFunction::USB: return "USB";
    }
    return std::to_string(static_cast<uint8_t>(gpioFunction));
}

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal
