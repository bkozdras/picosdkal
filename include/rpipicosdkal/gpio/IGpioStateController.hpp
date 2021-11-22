/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_IGPIOSTATECONTROLLER_HPP_
#define RPIPICOSDKAL_GPIO_IGPIOSTATECONTROLLER_HPP_

#include <cstdint>
#include <memory>

#include <rpipicosdkal/gpio/definitions/EGpioState.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class IGpioStateController
{
public:
    virtual ~IGpioStateController() = default;

    virtual definitions::EGpioState getInputLevel(const uint8_t gpio) = 0;
    virtual definitions::EGpioState getOutputLevel(const uint8_t gpio) = 0;
    virtual bool setOutputLevel(const uint8_t gpio, const definitions::EGpioState gpioState) = 0;
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_IGPIOSTATECONTROLLER_HPP_
