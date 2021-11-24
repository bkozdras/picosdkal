/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOFUNCTION_HPP_
#define RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOFUNCTION_HPP_

#include <string>

namespace rpipicosdkal
{
namespace gpio
{
namespace definitions
{

enum class EGpioFunction
{
    NotSet = 0u,
    XIP = 1u,
    SPI = 2u,
    UART = 3u,
    I2C = 4u,
    PWM = 5u,
    SIO = 6u,
    PIO0 = 7u,
    PIO1 = 8u,
    GPCK = 9u,
    USB = 10u,
};

std::string toString(const EGpioFunction gpioFunction);

}  // namespace definitions
}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_DEFINITIONS_EGPIOFUNCTION_HPP_
