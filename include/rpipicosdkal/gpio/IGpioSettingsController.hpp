/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_IGPIOSETTINGSCONTROLLER_HPP_
#define RPIPICOSDKAL_GPIO_IGPIOSETTINGSCONTROLLER_HPP_

#include <cstdint>
#include <memory>

#include <rpipicosdkal/gpio/core/Types.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDirection.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioPullUp.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class IGpioStateController
{
public:
    virtual ~IGpioStateController() = default;

    virtual void setGpioDirection(const core::TGpioNumber gpioNumber, const EGpioDirection gpioDirection) = 0;
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_IGPIOSETTINGSCONTROLLER_HPP_
