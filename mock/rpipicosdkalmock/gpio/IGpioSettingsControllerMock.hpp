/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKALMOCK_GPIO_IGPIOSETTINGSCONTROLLERMOCK_HPP_
#define RPIPICOSDKALMOCK_GPIO_IGPIOSETTINGSCONTROLLERMOCK_HPP_

#include <memory>

#include <gmock/gmock.h>

#include <rpipicosdkal/core/Types.hpp>
#include <rpipicosdkal/core/definitions/EOperationResult.hpp>
#include <rpipicosdkal/gpio/IGpioSettingsController.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDirection.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDriveStrength.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioFunction.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioPullUp.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioSlewRateLimiting.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class IGpioSettingsControllerMock;
using IGpioSettingsControllerMockPtr = std::unique_ptr<IGpioSettingsControllerMock>;

using IGpioSettingsControllerNiceMock = ::testing::NiceMock<IGpioSettingsControllerMock>;
using IGpioSettingsControllerNiceMockPtr = std::unique_ptr<IGpioSettingsControllerNiceMock>;

using IGpioSettingsControllerStrictMock = ::testing::StrictMock<IGpioSettingsControllerMock>;
using IGpioSettingsControllerStrictMockPtr = std::unique_ptr<IGpioSettingsControllerStrictMock>;

class IGpioSettingsControllerMock : public IGpioSettingsController
{
public:
    IGpioSettingsControllerMock() = default;
    ~IGpioSettingsControllerMock() = default;

    static IGpioSettingsControllerMockPtr create();
    static IGpioSettingsControllerNiceMockPtr createNice();
    static IGpioSettingsControllerStrictMockPtr createStrict();

    MOCK_METHOD1(getGpioDirection, std::optional<definitions::EGpioDirection>(const core::TGpioNumber));
    MOCK_METHOD2(setGpioDirection,
        core::definitions::EOperationResult(const core::TGpioNumber, const definitions::EGpioDirection));

    MOCK_METHOD1(getGpioDriveStrength, std::optional<definitions::EGpioDriveStrength>(const core::TGpioNumber));
    MOCK_METHOD2(setGpioDriveStrength,
        core::definitions::EOperationResult(const core::TGpioNumber, const definitions::EGpioDriveStrength));

    MOCK_METHOD1(getGpioFunction, definitions::EGpioFunction(const core::TGpioNumber));
    MOCK_METHOD2(setGpioFunction,
        core::definitions::EOperationResult(const core::TGpioNumber, const definitions::EGpioFunction));

    MOCK_METHOD1(getGpioPullUp, definitions::EGpioPullUp(const core::TGpioNumber));
    MOCK_METHOD2(setGpioPullUp,
        core::definitions::EOperationResult(const core::TGpioNumber, const definitions::EGpioPullUp));

    MOCK_METHOD1(getGpioSlewRateLimiting, std::optional<definitions::EGpioSlewRateLimiting>(const core::TGpioNumber));
    MOCK_METHOD2(setGpioSlewRateLimiting,
        core::definitions::EOperationResult(const core::TGpioNumber, const definitions::EGpioSlewRateLimiting));
};

}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKALMOCK_GPIO_IGPIOSETTINGSCONTROLLERMOCK_HPP_
