/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/core/Logger.hpp>
#include <rpipicosdkal/core/Types.hpp>
#include <rpipicosdkal/gpio/GpioSettingsController.hpp>
#include <rpipicosdkal/gpio/GpioStateController.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDirection.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioFunction.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioPullUp.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioState.hpp>

#include <string>

int main()
{
    const rpipicosdkal::core::TGpioNumber gpioNumber = 19u;
    LOG_INFO("Main") << "It is dummy main!";
    auto gpioSettingsController = rpipicosdkal::gpio::GpioSettingsController::create();
    auto gpioStateController = rpipicosdkal::gpio::GpioStateController::create(*gpioSettingsController);
    gpioSettingsController->setGpioFunction(gpioNumber,
        rpipicosdkal::gpio::definitions::EGpioFunction::SIO);
    gpioSettingsController->setGpioDirection(gpioNumber,
        rpipicosdkal::gpio::definitions::EGpioDirection::Output);
    gpioSettingsController->setGpioPullUp(gpioNumber,
        rpipicosdkal::gpio::definitions::EGpioPullUp::Up);
    gpioStateController->setOutputLevel(gpioNumber,
        rpipicosdkal::gpio::definitions::EGpioState::High);
    return 0;
}
