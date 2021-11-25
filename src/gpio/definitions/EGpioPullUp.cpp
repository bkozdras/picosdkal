/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/definitions/EGpioPullUp.hpp>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

std::string toString(const EGpioPullUp gpioPullUp)
{
    switch (gpioPullUp)
    {
        case EGpioPullUp::NotPulled: return "NotPulled";
        case EGpioPullUp::Up: return "Up";
        case EGpioPullUp::Down: return "Down";
        case EGpioPullUp::BusKeep: return "BusKeep";
    }
    return std::to_string(static_cast<uint8_t>(gpioPullUp));
}

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal
