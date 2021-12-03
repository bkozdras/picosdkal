/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkalstub/gpio/ContextStub.hpp>

namespace rpipicosdkal
{
namespace gpio
{

ContextStub::ContextStub()
    : settingsControllerStub_(nullptr)
    , stateControllerStub_(nullptr)
{
    settingsControllerStub_ = GpioSettingsControllerStub::create();
    stateControllerStub_ = GpioStateControllerStub::create(*settingsControllerStub_);
}

ContextStub::~ContextStub()
{
    stateControllerStub_.reset();
    settingsControllerStub_.reset();
}

std::unique_ptr<ContextStub> ContextStub::create()
{
    return std::unique_ptr<ContextStub>(new ContextStub());
}

IGpioSettingsController& ContextStub::getSettingsController()
{
    return getSettingsControllerStub();
}

IGpioStateController& ContextStub::getStateController()
{
    return getStateControllerStub();
}

GpioSettingsControllerStub& ContextStub::getSettingsControllerStub()
{
    return *settingsControllerStub_;
}

GpioStateControllerStub& ContextStub::getStateControllerStub()
{
    return *stateControllerStub_;
}

}  // namespace gpio
}  // namespace rpipicosdkal
