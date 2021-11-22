/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOSTATE_HPP_
#define RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOSTATE_HPP_

#include <cstdint>
#include <string>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

enum class EGpioState : uint8_t
{
    Low = 0u,
    High = 1u
};

std::string toString(const EGpioState gpioState);

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOSTATE_HPP_
