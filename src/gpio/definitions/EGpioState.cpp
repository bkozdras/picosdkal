/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/definitions/EGpioState.hpp>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

std::string toString(const EGpioState gpioState)
{
    switch (gpioState)
    {
        case EGpioState::Low: return "Low";
        case EGpioState::High: return "High";
    }
    return std::to_string(static_cast<uint8_t>(gpioState));
}

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal
