/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkalmock/gpio/IGpioSettingsControllerMock.hpp>

namespace rpipicosdkal
{
namespace gpio
{

IGpioSettingsControllerMockPtr IGpioSettingsControllerMock::create()
{
    return IGpioSettingsControllerMockPtr(new IGpioSettingsControllerMock());
}

IGpioSettingsControllerNiceMockPtr IGpioSettingsControllerMock::createNice()
{
    return IGpioSettingsControllerNiceMockPtr(new IGpioSettingsControllerNiceMock());
}

IGpioSettingsControllerStrictMockPtr IGpioSettingsControllerMock::createStrict()
{
    return IGpioSettingsControllerStrictMockPtr(new IGpioSettingsControllerStrictMock());
}

}  // namespace gpio
}  // namespace rpipicosdkal
