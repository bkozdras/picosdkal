/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_ICONTEXT_HPP_
#define RPIPICOSDKAL_GPIO_ICONTEXT_HPP_

#include <rpipicosdkal/gpio/fwd.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class IContext
{
public:
    virtual ~IContext() = default;

    // virtual GpioInterruptController& getInterruptController() = 0;
    virtual IGpioSettingsController& getSettingsController() = 0;
    virtual IGpioStateController& getStateController() = 0;
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_ICONTEXT_HPP_
