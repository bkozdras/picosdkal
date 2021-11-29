/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKALMOCK_GPIO_IGPIOSTATECONTROLLERMOCK_HPP_
#define RPIPICOSDKALMOCK_GPIO_IGPIOSTATECONTROLLERMOCK_HPP_

#include <memory>
#include <optional>

#include <gmock/gmock.h>

#include <rpipicosdkal/core/Types.hpp>
#include <rpipicosdkal/core/definitions/EOperationResult.hpp>
#include <rpipicosdkal/gpio/IGpioStateController.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioState.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class IGpioStateControllerMock;
using IGpioStateControllerMockPtr = std::unique_ptr<IGpioStateControllerMock>;

using IGpioStateControllerNiceMock = ::testing::NiceMock<IGpioStateControllerMock>;
using IGpioStateControllerNiceMockPtr = std::unique_ptr<IGpioStateControllerNiceMock>;

using IGpioStateControllerStrictMock = ::testing::StrictMock<IGpioStateControllerMock>;
using IGpioStateControllerStrictMockPtr = std::unique_ptr<IGpioStateControllerStrictMock>;

class IGpioStateControllerMock : public IGpioStateController
{
public:
    IGpioStateControllerMock() = default;
    ~IGpioStateControllerMock() = default;

    static IGpioStateControllerMockPtr create();
    static IGpioStateControllerNiceMockPtr createNice();
    static IGpioStateControllerStrictMockPtr createStrict();

    MOCK_METHOD1(getInputLevel, std::optional<definitions::EGpioState>(const core::TGpioNumber));
    MOCK_METHOD1(getOutputLevel, std::optional<definitions::EGpioState>(const core::TGpioNumber));
    MOCK_METHOD2(setOutputLevel, core::definitions::EOperationResult(const core::TGpioNumber, const definitions::EGpioState));
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKALMOCK_GPIO_IGPIOSTATECONTROLLERMOCK_HPP_
