/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef PICOSDKMOCK_HARDWARE_GPIO_GPIOMOCK_HPP_
#define PICOSDKMOCK_HARDWARE_GPIO_GPIOMOCK_HPP_

#include <cstdint>

#include <gmock/gmock.h>

#include <hardware/gpio.h>

namespace picosdkmock
{
namespace hardware_gpio
{

class GpioMock;
using GpioNiceMock = ::testing::NiceMock<GpioMock>;
using GpioStrictMock = ::testing::StrictMock<GpioMock>;

class GpioMock
{
public:
    GpioMock();
    ~GpioMock();

    MOCK_METHOD1(gpio_get, bool(uint));
    MOCK_METHOD2(gpio_put, void(uint, int));
};

}  // namespace hardware_gpio
}  // namespace picosdkmock

#endif  // PICOSDKMOCK_HARDWARE_GPIO_GPIOMOCK_HPP_
