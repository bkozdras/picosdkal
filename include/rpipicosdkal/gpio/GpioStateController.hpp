/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_GPIOSTATECONTROLLER_HPP_
#define RPIPICOSDKAL_GPIO_GPIOSTATECONTROLLER_HPP_

#include <cstdint>
#include <memory>

#include <rpipicosdkal/gpio/fwd.hpp>
#include <rpipicosdkal/gpio/IGpioStateController.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class GpioStateController final : public IGpioStateController
{
public:
    static IGpioStateControllerPtr create();
    ~GpioStateController() = default;

    definitions::EGpioState getInputLevel(const uint8_t gpio) override;
    definitions::EGpioState getOutputLevel(const uint8_t gpio) override;
    bool setOutputLevel(const uint8_t gpio, const definitions::EGpioState gpioState) override;

private:
    GpioStateController();
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_GPIOSTATECONTROLLER_HPP_
