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

    MOCK_METHOD2(gpio_set_function, void(uint, enum gpio_function));
    MOCK_METHOD1(gpio_get_function, enum gpio_function(uint));
    MOCK_METHOD3(gpio_set_pulls, void(uint, bool, bool));
    MOCK_METHOD1(gpio_pull_up, void(uint));
    MOCK_METHOD1(gpio_is_pulled_up, bool(uint));
    MOCK_METHOD1(gpio_pull_down, void(uint));
    MOCK_METHOD1(gpio_is_pulled_down, bool(uint));
    MOCK_METHOD1(gpio_disable_pulls, void(uint));
    MOCK_METHOD2(gpio_set_irqover, void(uint, uint));
    MOCK_METHOD2(gpio_set_outover, void(uint, uint));
    MOCK_METHOD2(gpio_set_inover, void(uint, uint));
    MOCK_METHOD2(gpio_set_oeover, void(uint, uint));
    MOCK_METHOD2(gpio_set_input_enabled, void(uint, uint));
    MOCK_METHOD2(gpio_set_input_hysteresis_enabled, void(uint, bool));
    MOCK_METHOD1(gpio_is_input_hysteresis_enabled, bool(uint));
    MOCK_METHOD2(gpio_set_slew_rate, void(uint, enum gpio_slew_rate));
    MOCK_METHOD1(gpio_get_slew_rate, enum gpio_slew_rate(uint));
    MOCK_METHOD2(gpio_set_drive_strength, void(uint, enum gpio_drive_strength));
    MOCK_METHOD1(gpio_get_drive_strength, enum gpio_drive_strength(uint));
    MOCK_METHOD3(gpio_set_irq_enabled, void(uint, uint32_t, bool));
    MOCK_METHOD4(gpio_set_irq_enabled_with_callback, void(uint, uint32_t, bool, gpio_irq_callback_t));
    MOCK_METHOD3(gpio_set_dormant_irq_enabled, void(uint, uint32_t, bool));
    MOCK_METHOD2(gpio_acknowledge_irq, void(uint, uint32_t));
    MOCK_METHOD1(gpio_init, void(uint));
    MOCK_METHOD1(gpio_init_mask, void(uint));
    MOCK_METHOD1(gpio_get, bool(uint));
    MOCK_METHOD0(gpio_get_all, uint32_t());
    MOCK_METHOD1(gpio_set_mask, void(uint32_t));
    MOCK_METHOD1(gpio_clr_mask, void(uint32_t));
    MOCK_METHOD1(gpio_xor_mask, void(uint32_t));
    MOCK_METHOD2(gpio_put_masked, void(uint32_t, uint32_t));
    MOCK_METHOD1(gpio_put_all, void(uint32_t));
    MOCK_METHOD2(gpio_put, void(uint, bool));
    MOCK_METHOD1(gpio_get_out_level, bool(uint));
    MOCK_METHOD1(gpio_set_dir_out_masked, void(uint32_t));
    MOCK_METHOD1(gpio_set_dir_in_masked, void(uint32_t));
    MOCK_METHOD2(gpio_set_dir_masked, void(uint32_t, uint32_t));
    MOCK_METHOD1(gpio_set_dir_all_bits, void(uint32_t));
    MOCK_METHOD2(gpio_set_dir, void(uint, bool));
    MOCK_METHOD1(gpio_is_dir_out, bool(uint));
    MOCK_METHOD1(gpio_get_dir, uint(uint));
};

}  // namespace hardware_gpio
}  // namespace picosdkmock

#endif  // PICOSDKMOCK_HARDWARE_GPIO_GPIOMOCK_HPP_
