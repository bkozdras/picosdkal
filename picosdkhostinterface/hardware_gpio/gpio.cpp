/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <hardware/gpio.h>

extern "C"
{

void gpio_set_function(uint gpio, enum gpio_function fn)
{
}

enum gpio_function gpio_get_function(uint gpio)
{
    return GPIO_FUNC_SIO;
}

void gpio_set_pulls(uint gpio, bool up, bool down)
{
}

void gpio_pull_up(uint gpio)
{
}

bool gpio_is_pulled_up(uint gpio)
{
    return true;
}

void gpio_pull_down(uint gpio)
{
}

bool gpio_is_pulled_down(uint gpio)
{
    return false;
}

void gpio_disable_pulls(uint gpio)
{
}

void gpio_set_irqover(uint gpio, uint value)
{
}

void gpio_set_outover(uint gpio, uint value)
{
}

void gpio_set_inover(uint gpio, uint value)
{
}

void gpio_set_oeover(uint gpio, uint value)
{
}

void gpio_set_input_enabled(uint gpio, bool enable)
{
}

void gpio_set_input_hysteresis_enabled(uint gpio, bool enabled)
{
}

bool gpio_is_input_hysteresis_enabled(uint gpio)
{
    return true;
}

void gpio_set_slew_rate(uint gpio, enum gpio_slew_rate slew)
{
}

enum gpio_slew_rate gpio_get_slew_rate(uint gpio)
{
    return GPIO_SLEW_RATE_FAST;
}

void gpio_set_drive_strength(uint gpio, enum gpio_drive_strength drive)
{
}

enum gpio_drive_strength gpio_get_drive_strength(uint gpio)
{
    return GPIO_DRIVE_STRENGTH_4MA;
}


void gpio_set_irq_enabled(uint gpio, uint32_t events, bool enable)
{
}

void gpio_set_irq_enabled_with_callback(uint gpio, uint32_t events, bool enabled, gpio_irq_callback_t callback)
{
}

void gpio_set_dormant_irq_enabled(uint gpio, uint32_t events, bool enabled)
{
}

void gpio_acknowledge_irq(uint gpio, uint32_t events)
{
}

void gpio_init(uint gpio)
{
}

void gpio_init_mask(uint gpio_mask)
{
}

bool gpio_get(uint gpio)
{
    return false;
}

uint32_t gpio_get_all()
{
    return 0u;
}

void gpio_set_mask(uint32_t mask)
{
}

void gpio_clr_mask(uint32_t mask)
{
}

void gpio_xor_mask(uint32_t mask)
{
}

void gpio_put_masked(uint32_t mask, uint32_t value)
{
}

void gpio_put_all(uint32_t value)
{
}

void gpio_put(uint gpio, bool value)
{
}

bool gpio_get_out_level(uint gpio)
{
    return true;
}

void gpio_set_dir_out_masked(uint32_t mask)
{
}

void gpio_set_dir_in_masked(uint32_t mask)
{
}

void gpio_set_dir_masked(uint32_t mask, uint32_t value)
{
}

void gpio_set_dir_all_bits(uint32_t value)
{
}

void gpio_set_dir(uint gpio, bool out)
{
}

bool gpio_is_dir_out(uint gpio)
{
    return true;
}

}  // extern "C"
