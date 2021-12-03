/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <string>
#include <utility>

#include <rpipicosdkal/core/Logger.hpp>
#include <rpipicosdkal/core/Types.hpp>
#include <rpipicosdkal/context/IContext.hpp>
#include <rpipicosdkal/gpio/IContext.hpp>
#include <rpipicosdkal/gpio/IGpioSettingsController.hpp>
#include <rpipicosdkal/gpio/IGpioStateController.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDirection.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioFunction.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioPullUp.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioState.hpp>
#include <rpipicosdkal/system/fwd.hpp>
#include <rpipicosdkal/system/IApplication.hpp>
#include <rpipicosdkal/system/Runner.hpp>

class DummyApplication final : public rpipicosdkal::system::IApplication
{
public:
    static rpipicosdkal::system::IApplicationPtr create()
    {
        return rpipicosdkal::system::IApplicationPtr(new DummyApplication());
    }

    void setup(rpipicosdkal::context::IContext& context)
    {
        LOG_INFO("DummyApplication") << "Setup ongoing...";
        auto& gpioSettingsController = context.gpio().getSettingsController();
        auto& gpioStateController = context.gpio().getStateController();
        const rpipicosdkal::core::TGpioNumber gpioNumber = 19u;
        gpioSettingsController.setGpioFunction(gpioNumber,
            rpipicosdkal::gpio::definitions::EGpioFunction::SIO);
        gpioSettingsController.setGpioDirection(gpioNumber,
            rpipicosdkal::gpio::definitions::EGpioDirection::Output);
        gpioSettingsController.setGpioPullUp(gpioNumber,
            rpipicosdkal::gpio::definitions::EGpioPullUp::Up);
        gpioStateController.setOutputLevel(gpioNumber,
            rpipicosdkal::gpio::definitions::EGpioState::High);
        LOG_INFO("DummyApplication") << "Setup done...";
    }

private:
    DummyApplication()
    {
    }
};

int main()
{
    auto application = DummyApplication::create();
    rpipicosdkal::system::runSystem(std::move(application));
    return 0;
}
