/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/Context.hpp>

#include <rpipicosdkal/gpio/GpioInterruptController.hpp>
#include <rpipicosdkal/gpio/GpioSettingsController.hpp>
#include <rpipicosdkal/gpio/GpioStateController.hpp>

namespace rpipicosdkal
{
namespace gpio
{

Context::Context()
    : settingsController_(nullptr)
    , stateController_(nullptr)
{
    settingsController_ = GpioSettingsController::create();
    stateController_ = GpioStateController::create(*settingsController_);
}

Context::~Context()
{
    stateController_.reset();
    settingsController_.reset();
}

IContextPtr Context::create()
{
    return IContextPtr(new Context());
}

IGpioSettingsController& Context::getSettingsController()
{
    return *settingsController_;
}

IGpioStateController& Context::getStateController()
{
    return *stateController_;
}

}  // namespace gpio
}  // namespace rpipicosdkal
