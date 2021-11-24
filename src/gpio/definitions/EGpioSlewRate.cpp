/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/definitions/EGpioSlewRate.hpp>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

std::string toString(const EGpioSlewRate gpioSlewRate)
{
    switch (gpioSlewRate)
    {
        case EGpioSlewRate::Slow: return "Slow";
        case EGpioSlewRate::Fast: return "Fast";
    }
    return std::to_string(static_cast<uint8_t>(gpioSlewRate));
}

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal
