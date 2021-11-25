/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/definitions/EGpioSlewRateLimiting.hpp>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

std::string toString(const EGpioSlewRateLimiting gpioSlewRateLimiting)
{
    switch (gpioSlewRateLimiting)
    {
        case EGpioSlewRateLimiting::Disabled: return "Disabled";
        case EGpioSlewRateLimiting::Enabled: return "Enabled";
    }
    return std::to_string(static_cast<uint8_t>(gpioSlewRateLimiting));
}

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal
