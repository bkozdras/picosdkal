/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkalmock/gpio/IGpioStateControllerMock.hpp>

namespace rpipicosdkal
{
namespace gpio
{

IGpioStateControllerMockPtr IGpioStateControllerMock::create()
{
    return IGpioStateControllerMockPtr(new IGpioStateControllerMock());
}

IGpioStateControllerNiceMockPtr IGpioStateControllerMock::createNice()
{
    return IGpioStateControllerNiceMockPtr(new IGpioStateControllerNiceMock());
}

IGpioStateControllerStrictMockPtr IGpioStateControllerMock::createStrict()
{
    return IGpioStateControllerStrictMockPtr(new IGpioStateControllerStrictMock());
}

}  // namespace gpio
}  // namespace rpipicosdkal
