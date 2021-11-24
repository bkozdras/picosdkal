/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIODIRECTION_HPP_
#define RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIODIRECTION_HPP_

#include <string>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

enum class EGpioDirection
{
    Input = 0u,
    Output = 1u
};

std::string toString(const EGpioDirection gpioDirection);

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIODIRECTION_HPP_
