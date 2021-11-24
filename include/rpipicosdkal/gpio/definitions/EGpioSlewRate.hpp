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

enum class EGpioSlewRate
{
    Slow = 0u,
    Fast = 1u
};

std::string toString(const EGpioSlewRate gpioSlewRate);

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOSLEWRATE_HPP_
