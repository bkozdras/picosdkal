/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKALSTUB_GPIO_GPIOSTATECONTROLLERSTUB_HPP_
#define RPIPICOSDKALSTUB_GPIO_GPIOSTATECONTROLLERSTUB_HPP_

#include <map>
#include <memory>

#include <rpipicosdkal/gpio/IGpioStateController.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioState.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class GpioStateControllerStub;
using GpioStateControllerStubPtr = std::unique_ptr<GpioStateControllerStub>;

class GpioStateControllerStub : public IGpioStateController
{
public:
    static GpioStateControllerStubPtr create();
    ~GpioStateControllerStub() = default;

    definitions::EGpioState getInputLevel(const uint8_t gpio) override;
    definitions::EGpioState getOutputLevel(const uint8_t gpio) override;
    bool setOutputLevel(const uint8_t gpio, const definitions::EGpioState gpioState) override;

    void simulateGpioStateChange(const uint8_t gpio, const definitions::EGpioState gpioState);

private:
    GpioStateControllerStub();

    std::map<uint8_t /*GPIO*/, definitions::EGpioState> gpioToState_;
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKALSTUB_GPIO_GPIOSTATECONTROLLERSTUB_HPP_
