/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOPULLUP_HPP_
#define RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOPULLUP_HPP_

#include <string>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

enum class EGpioPullUp
{
    NotPulled = 0u,
    Up = 1u,
    Down = 2u,
    BusKeep = 3u
};

std::string toString(const EGpioPullUp gpioPullUp);

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOPULLUP_HPP_
