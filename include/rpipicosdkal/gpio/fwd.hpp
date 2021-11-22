/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_FWD_HPP_
#define RPIPICOSDKAL_GPIO_FWD_HPP_

#include <memory>

namespace rpipicosdkal
{
namespace gpio
{

class IGpioInterruptController;
using IGpioInterruptControllerPtr = std::unique_ptr<IGpioInterruptController>;

class IGpioSettingsController;
using IGpioSettingsControllerPtr = std::unique_ptr<IGpioSettingsController>;

class IGpioStateController;
using IGpioStateControllerPtr = std::unique_ptr<IGpioStateController>;

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_FWD_HPP_
