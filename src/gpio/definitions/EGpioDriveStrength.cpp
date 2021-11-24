/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/definitions/EGpioDriveStrength.hpp>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

std::string toString(const EGpioDriveStrength gpioDriveStrength)
{
    switch (gpioDriveStrength)
    {
        case EGpioDriveStrength::_2mA: return "2mA";
        case EGpioDriveStrength::_4mA: return "4mA";
        case EGpioDriveStrength::_8mA: return "8mA";
        case EGpioDriveStrength::_12mA: return "12mA";
    }
    return std::to_string(static_cast<uint8_t>(gpioDriveStrength));
}

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal
