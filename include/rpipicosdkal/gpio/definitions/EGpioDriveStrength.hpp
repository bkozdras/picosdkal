/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIODRIVESTRENGTH_HPP_
#define RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIODRIVESTRENGTH_HPP_

#include <string>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

enum class EGpioDriveStrength
{
    _2mA = 0u,
    _4mA = 1u,
    _8mA = 2u,
    _12mA = 3u
};

std::string toString(const EGpioDriveStrength gpioDriveStrength);

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIODRIVESTRENGTH_HPP_
