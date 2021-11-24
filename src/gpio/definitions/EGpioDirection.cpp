/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/definitions/EGpioDirection.hpp>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

std::string toString(const EGpioDirection gpioDirection)
{
    switch (gpioDirection)
    {
        case EGpioDirection::Input: return "Input";
        case EGpioDirection::Output: return "Output";
    }
    return std::to_string(static_cast<uint8_t>(gpioDirection));
}

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal
