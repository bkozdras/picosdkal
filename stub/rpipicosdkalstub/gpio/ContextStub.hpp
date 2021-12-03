/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKALSTUB_GPIO_CONTEXT_HPP_
#define RPIPICOSDKALSTUB_GPIO_CONTEXT_HPP_

#include <rpipicosdkal/gpio/IContext.hpp>

#include <rpipicosdkalstub/gpio/GpioInterruptControllerStub.hpp>
#include <rpipicosdkalstub/gpio/GpioSettingsControllerStub.hpp>
#include <rpipicosdkalstub/gpio/GpioStateControllerStub.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class ContextStub final : public IContext
{
public:
    static std::unique_ptr<ContextStub> create();
    ~ContextStub();

    IGpioSettingsController& getSettingsController() override;
    IGpioStateController& getStateController() override;

    GpioSettingsControllerStub& getSettingsControllerStub();
    GpioStateControllerStub& getStateControllerStub();

private:
    ContextStub();

    std::unique_ptr<GpioSettingsControllerStub> settingsControllerStub_;
    std::unique_ptr<GpioStateControllerStub> stateControllerStub_;
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKALSTUB_GPIO_CONTEXT_HPP_
