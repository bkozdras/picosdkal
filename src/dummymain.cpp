/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <string>
#include <utility>

#include <hardware/uart.h>
#include <pico/stdio_uart.h>
#include <pico/stdlib.h>

#include <rpipicosdkal/core/InternalSdkLogger.hpp>
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
        {
            // Initialize logger on UART0 and TX GP0 - temporary
            stdio_uart_init_full(uart0, 115200u, 0, -1);
            rpipicosdkal::core::logger::enableLogging();
            rpipicosdkal::core::internalsdklogger::enableLogging();
        }
        LOG_INFO(loggerPrefix_) << "Setup ongoing...";
        auto& gpioSettingsController = context.gpio().getSettingsController();
        auto& gpioStateController = context.gpio().getStateController();
        const rpipicosdkal::core::TGpioNumber gpioNumber = 25u;
        gpioSettingsController.setGpioFunction(gpioNumber,
            rpipicosdkal::gpio::definitions::EGpioFunction::SIO);
        gpioSettingsController.setGpioDirection(gpioNumber,
            rpipicosdkal::gpio::definitions::EGpioDirection::Output);
        gpioStateController.setOutputLevel(gpioNumber,
            rpipicosdkal::gpio::definitions::EGpioState::High);
        LOG_INFO(loggerPrefix_) << "Setup done...";
        while (true)
        {
            LOG_INFO(loggerPrefix_) << "I'm alive!";
            if (gpioStateController.getOutputLevel(gpioNumber)
                == rpipicosdkal::gpio::definitions::EGpioState::High)
            {
                gpioStateController.setOutputLevel(gpioNumber,
                    rpipicosdkal::gpio::definitions::EGpioState::Low);
            }
            else
            {
                gpioStateController.setOutputLevel(gpioNumber,
                    rpipicosdkal::gpio::definitions::EGpioState::High);
            }
            sleep_ms(1000);
        }
    }

private:
    DummyApplication()
        : loggerPrefix_("DummyApplication")
    {
    }

    const std::string loggerPrefix_;
};

int main()
{
    auto application = DummyApplication::create();
    rpipicosdkal::system::run(std::move(application));
    return 0;
}
