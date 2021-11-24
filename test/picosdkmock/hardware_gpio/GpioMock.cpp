/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <picosdkmock/hardware_gpio/GpioMock.hpp>

#include <cassert>

static picosdkmock::hardware_gpio::GpioMock* mockInstance = nullptr;

#define ASSERT_ON_NULL_MOCK() assert(mockInstance != nullptr && "GpioMock instance is not created!")

namespace picosdkmock
{
namespace hardware_gpio
{

GpioMock::GpioMock()
{
    assert(mockInstance == nullptr && "Only one instance of GpioMock can be created!");
    mockInstance = this;
}

GpioMock::~GpioMock()
{
    mockInstance = nullptr;
}

}  // namespace hardware_gpio
}  // namespace picosdkmock

static void gpio_set_function_impl(uint gpio, enum gpio_function fn)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_function(gpio, fn);
}

static enum gpio_function gpio_get_function_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    return mockInstance->gpio_get_function(gpio);
}

static void gpio_set_pulls_impl(uint gpio, bool up, bool down)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_pulls(gpio, up, down);
}

static void gpio_pull_up_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_pull_up(gpio);
}

static bool gpio_is_pulled_up_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    return mockInstance->gpio_is_pulled_up(gpio);
}

static void gpio_pull_down_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_pull_down(gpio);
}

static bool gpio_is_pulled_down_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    return mockInstance->gpio_is_pulled_down(gpio);
}

static void gpio_disable_pulls_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_disable_pulls(gpio);
}

static void gpio_set_irqover_impl(uint gpio, uint value)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_irqover(gpio, value);
}

static void gpio_set_outover_impl(uint gpio, uint value)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_outover(gpio, value);
}

static void gpio_set_inover_impl(uint gpio, uint value)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_inover(gpio, value);
}

static void gpio_set_oeover_impl(uint gpio, uint value)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_oeover(gpio, value);
}

static void gpio_set_input_enabled_impl(uint gpio, bool enabled)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_input_enabled(gpio, enabled);
}

static void gpio_set_input_hysteresis_enabled_impl(uint gpio, bool enabled)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_input_hysteresis_enabled(gpio, enabled);
}

static bool gpio_is_input_hysteresis_enabled_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    return mockInstance->gpio_is_input_hysteresis_enabled(gpio);
}

static void gpio_set_slew_rate_impl(uint gpio, enum gpio_slew_rate slew)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_slew_rate(gpio, slew);
}

static enum gpio_slew_rate gpio_get_slew_rate_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    return mockInstance->gpio_get_slew_rate(gpio);
}

static void gpio_set_drive_strength_impl(uint gpio, enum gpio_drive_strength drive)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_drive_strength(gpio, drive);
}

static enum gpio_drive_strength gpio_get_drive_strength_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    return mockInstance->gpio_get_drive_strength(gpio);
}

static void gpio_set_irq_enabled_impl(uint gpio, uint32_t events, bool enabled)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_irq_enabled(gpio, events, enabled);
}

static void gpio_set_irq_enabled_with_callback_impl(uint gpio, uint32_t events, bool enabled, gpio_irq_callback_t callback)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_irq_enabled_with_callback(gpio, events, enabled, callback);
}

static void gpio_set_dormant_irq_enabled_impl(uint gpio, uint32_t events, bool enabled)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_dormant_irq_enabled(gpio, events, enabled);
}

static void gpio_acknowledge_irq_impl(uint gpio, uint32_t events)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_acknowledge_irq(gpio, events);
}

static void gpio_init_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_init(gpio);
}

static void gpio_init_mask_impl(uint gpio_mask)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_init_mask(gpio_mask);
}

static bool gpio_get_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    return mockInstance->gpio_get(gpio);
}

static uint32_t gpio_get_all_impl()
{
    ASSERT_ON_NULL_MOCK();
    return mockInstance->gpio_get_all();
}

static void gpio_set_mask_impl(uint32_t mask)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_mask(mask);
}

static void gpio_clr_mask_impl(uint32_t mask)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_clr_mask(mask);
}

static void gpio_xor_mask_impl(uint32_t mask)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_xor_mask(mask);
}

static void gpio_put_masked_impl(uint32_t mask, uint32_t value)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_put_masked(mask, value);
}

static void gpio_put_all_impl(uint32_t value)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_put_all(value);
}

static void gpio_put_impl(uint gpio, bool value)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_put(gpio, value);
}

static bool gpio_get_out_level_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    return mockInstance->gpio_get_out_level(gpio);
}

static void gpio_set_dir_out_masked_impl(uint32_t mask)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_dir_out_masked(mask);
}

static void gpio_set_dir_in_masked_impl(uint32_t mask)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_dir_in_masked(mask);
}

static void gpio_set_dir_masked_impl(uint32_t mask, uint32_t value)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_dir_masked(mask, value);
}

static void gpio_set_dir_all_bits_impl(uint32_t values)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_dir_all_bits(values);
}

static void gpio_set_dir_impl(uint gpio, bool out)
{
    ASSERT_ON_NULL_MOCK();
    mockInstance->gpio_set_dir(gpio, out);
}

static bool gpio_is_dir_out_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    return mockInstance->gpio_is_dir_out(gpio);
}

static uint gpio_get_dir_impl(uint gpio)
{
    ASSERT_ON_NULL_MOCK();
    return mockInstance->gpio_get_dir(gpio);
}

extern "C"
{

void gpio_set_function(uint gpio, enum gpio_function fn)
{
    gpio_set_function_impl(gpio, fn);
}

enum gpio_function gpio_get_function(uint gpio)
{
    return gpio_get_function_impl(gpio);
}

void gpio_set_pulls(uint gpio, bool up, bool down)
{
    gpio_set_pulls_impl(gpio, up, down);
}

void gpio_pull_up(uint gpio)
{
    gpio_pull_up_impl(gpio);
}

bool gpio_is_pulled_up(uint gpio)
{
    return gpio_is_pulled_up_impl(gpio);
}

void gpio_pull_down(uint gpio)
{
    gpio_pull_down_impl(gpio);
}

bool gpio_is_pulled_down(uint gpio)
{
    return gpio_is_pulled_down_impl(gpio);
}

void gpio_disable_pulls(uint gpio)
{
    gpio_disable_pulls_impl(gpio);
}

void gpio_set_irqover(uint gpio, uint value)
{
    gpio_set_irqover_impl(gpio, value);
}

void gpio_set_outover(uint gpio, uint value)
{
    gpio_set_outover_impl(gpio, value);
}

void gpio_set_inover(uint gpio, uint value)
{
    gpio_set_inover_impl(gpio, value);
}

void gpio_set_oeover(uint gpio, uint value)
{
    gpio_set_oeover_impl(gpio, value);
}

void gpio_set_input_enabled(uint gpio, bool enable)
{
    gpio_set_input_enabled_impl(gpio, enable);
}

void gpio_set_input_hysteresis_enabled(uint gpio, bool enabled)
{
    gpio_set_input_hysteresis_enabled_impl(gpio, enabled);
}

bool gpio_is_input_hysteresis_enabled(uint gpio)
{
    return gpio_is_input_hysteresis_enabled_impl(gpio);
}

void gpio_set_slew_rate(uint gpio, enum gpio_slew_rate slew)
{
    gpio_set_slew_rate_impl(gpio, slew);
}

enum gpio_slew_rate gpio_get_slew_rate(uint gpio)
{
    return gpio_get_slew_rate_impl(gpio);
}

void gpio_set_drive_strength(uint gpio, enum gpio_drive_strength drive)
{
    gpio_set_drive_strength_impl(gpio, drive);
}

enum gpio_drive_strength gpio_get_drive_strength(uint gpio)
{
    return gpio_get_drive_strength_impl(gpio);
}

void gpio_set_irq_enabled(uint gpio, uint32_t events, bool enable)
{
    gpio_set_irq_enabled_impl(gpio, events, enable);
}

void gpio_set_irq_enabled_with_callback(uint gpio, uint32_t events, bool enabled, gpio_irq_callback_t callback)
{
    gpio_set_irq_enabled_with_callback_impl(gpio, events, enabled, callback);
}

void gpio_set_dormant_irq_enabled(uint gpio, uint32_t events, bool enabled)
{
    gpio_set_dormant_irq_enabled_impl(gpio, events, enabled);
}

void gpio_acknowledge_irq(uint gpio, uint32_t events)
{
    gpio_acknowledge_irq_impl(gpio, events);
}

void gpio_init(uint gpio)
{
    gpio_init_impl(gpio);
}

void gpio_init_mask(uint gpio_mask)
{
    gpio_init_mask_impl(gpio_mask);
}

bool gpio_get(uint gpio)
{
    return gpio_get_impl(gpio);
}

uint32_t gpio_get_all()
{
    return gpio_get_all_impl();
}

void gpio_set_mask(uint32_t mask)
{
    gpio_set_mask_impl(mask);
}

void gpio_clr_mask(uint32_t mask)
{
    gpio_clr_mask_impl(mask);
}

void gpio_xor_mask(uint32_t mask)
{
    gpio_xor_mask_impl(mask);
}

void gpio_put_masked(uint32_t mask, uint32_t value)
{
    gpio_put_masked_impl(mask, value);
}

void gpio_put_all(uint32_t value)
{
    gpio_put_all_impl(value);
}

void gpio_put(uint gpio, bool value)
{
    gpio_put_impl(gpio, value);
}

bool gpio_get_out_level(uint gpio)
{
    return gpio_get_out_level_impl(gpio);
}

void gpio_set_dir_out_masked(uint32_t mask)
{
    gpio_set_dir_out_masked_impl(mask);
}

void gpio_set_dir_in_masked(uint32_t mask)
{
    gpio_set_dir_in_masked_impl(mask);
}

void gpio_set_dir_masked(uint32_t mask, uint32_t value)
{
    gpio_set_dir_masked_impl(mask, value);
}

void gpio_set_dir_all_bits(uint32_t value)
{
    gpio_set_dir_all_bits_impl(value);
}

void gpio_set_dir(uint gpio, bool out)
{
    gpio_set_dir_impl(gpio, out);
}

bool gpio_is_dir_out(uint gpio)
{
    return gpio_is_dir_out_impl(gpio);
}

}  // extern "C"
