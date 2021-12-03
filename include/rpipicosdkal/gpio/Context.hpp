/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_CONTEXT_HPP_
#define RPIPICOSDKAL_GPIO_CONTEXT_HPP_

#include <rpipicosdkal/gpio/fwd.hpp>
#include <rpipicosdkal/gpio/IContext.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class Context final : public IContext
{
public:
    static IContextPtr create();
    ~Context();

    // IGpioInterruptController& getInterruptController() override;
    IGpioSettingsController& getSettingsController() override;
    IGpioStateController& getStateController() override;

private:
    Context();

    IGpioSettingsControllerPtr settingsController_;
    IGpioStateControllerPtr stateController_;
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_CONTEXT_HPP_
