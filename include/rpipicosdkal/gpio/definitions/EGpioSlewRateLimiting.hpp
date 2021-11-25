/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOSLEWRATE_HPP_
#define RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOSLEWRATE_HPP_

#include <string>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

enum class EGpioSlewRateLimiting
{
    Disabled = 0u,
    Enabled = 1u
};

std::string toString(const EGpioSlewRateLimiting gpioSlewRateLimiting);

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOSLEWRATE_HPP_
