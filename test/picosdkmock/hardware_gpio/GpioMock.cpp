/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <picosdkmock/hardware_gpio/GpioMock.hpp>

#include <cassert>

static picosdkmock::hardware_gpio::GpioMock* globalInstance = nullptr;

namespace picosdkmock
{
namespace hardware_gpio
{

GpioMock::GpioMock()
{
    assert(globalInstance == nullptr && "Only one instance of GpioMock can be created!");
    globalInstance = this;
}

GpioMock::~GpioMock()
{
    globalInstance = nullptr;
}

}  // namespace hardware_gpio
}  // namespace picosdkmock

static void gpio_put_impl(uint gpio, int value)
{
    assert(globalInstance != nullptr && "GpioMock instance is not created!");
    globalInstance->gpio_put(gpio, value);
}

static bool gpio_get_impl(uint gpio)
{
    assert(globalInstance != nullptr && "GpioMock instance is not created!");
    return globalInstance->gpio_get(gpio);
}

extern "C"
{

void gpio_put(uint gpio, int value)
{
    gpio_put_impl(gpio, value);
}

bool gpio_get(uint gpio)
{
    return gpio_get_impl(gpio);
}

}  // extern "C"
