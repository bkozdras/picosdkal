/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <gmock/gmock.h>

#include <rpipicosdkal/core/Types.hpp>
#include <rpipicosdkal/core/definitions/EOperationResult.hpp>
#include <rpipicosdkal/gpio/fwd.hpp>
#include <rpipicosdkal/gpio/GpioStateController.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDirection.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioState.hpp>

#include <rpipicosdkalmock/gpio/IGpioSettingsControllerMock.hpp>
#include <picosdkmock/hardware_gpio/GpioMock.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class GpioStateControllerShould : public ::testing::Test
{
protected:
    GpioStateControllerShould();

    IGpioSettingsControllerStrictMock gpioSettingsControllerMock_;
    picosdkmock::hardware_gpio::GpioStrictMock picoGpioMock_;
    const core::TGpioNumber testedGpioNumber_;

    IGpioStateControllerPtr sut_;
};

GpioStateControllerShould::GpioStateControllerShould()
    : gpioSettingsControllerMock_()
    , picoGpioMock_()
    , testedGpioNumber_(22u)
    , sut_(GpioStateController::create(gpioSettingsControllerMock_))
{
}

TEST_F(GpioStateControllerShould, returnNullOptOnGetInputLevelAndNullOptDirection)
{
    EXPECT_CALL(gpioSettingsControllerMock_, getGpioDirection(testedGpioNumber_))
        .WillOnce(::testing::Return(std::nullopt));
    EXPECT_EQ(sut_->getInputLevel(testedGpioNumber_), std::nullopt);
}

TEST_F(GpioStateControllerShould, returnNullOptOnGetInputLevelAndOutputDirection)
{
    EXPECT_CALL(gpioSettingsControllerMock_, getGpioDirection(testedGpioNumber_))
        .WillOnce(::testing::Return(std::optional(definitions::EGpioDirection::Output)));
    EXPECT_EQ(sut_->getInputLevel(testedGpioNumber_), std::nullopt);
}

TEST_F(GpioStateControllerShould, returnCorrectInputLevel)
{
    {
        EXPECT_CALL(gpioSettingsControllerMock_, getGpioDirection(testedGpioNumber_))
            .WillOnce(::testing::Return(std::optional(definitions::EGpioDirection::Input)));
        EXPECT_CALL(picoGpioMock_, gpio_get(testedGpioNumber_))
            .WillOnce(::testing::Return(true));
        const auto optionalReturnedValue = sut_->getInputLevel(testedGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt);
        EXPECT_EQ(optionalReturnedValue, definitions::EGpioState::High);
    }
    {
        EXPECT_CALL(gpioSettingsControllerMock_, getGpioDirection(testedGpioNumber_))
            .WillOnce(::testing::Return(std::optional(definitions::EGpioDirection::Input)));
        EXPECT_CALL(picoGpioMock_, gpio_get(testedGpioNumber_))
            .WillOnce(::testing::Return(false));
        const auto optionalReturnedValue = sut_->getInputLevel(testedGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt);
        EXPECT_EQ(optionalReturnedValue, definitions::EGpioState::Low);
    }
}

TEST_F(GpioStateControllerShould, returnNullOptOnGetOutputLevelAndNullOptDirection)
{
    EXPECT_CALL(gpioSettingsControllerMock_, getGpioDirection(testedGpioNumber_))
        .WillOnce(::testing::Return(std::nullopt));
    EXPECT_EQ(sut_->getOutputLevel(testedGpioNumber_), std::nullopt);
}

TEST_F(GpioStateControllerShould, returnNullOptOnGetOutputLevelAndInputDirection)
{
    EXPECT_CALL(gpioSettingsControllerMock_, getGpioDirection(testedGpioNumber_))
        .WillOnce(::testing::Return(std::optional(definitions::EGpioDirection::Input)));
    EXPECT_EQ(sut_->getOutputLevel(testedGpioNumber_), std::nullopt);
}

TEST_F(GpioStateControllerShould, returnCorrectOutputLevel)
{
    {
        EXPECT_CALL(gpioSettingsControllerMock_, getGpioDirection(testedGpioNumber_))
            .WillOnce(::testing::Return(std::optional(definitions::EGpioDirection::Output)));
        EXPECT_CALL(picoGpioMock_, gpio_get(testedGpioNumber_))
            .WillOnce(::testing::Return(true));
        const auto optionalReturnedValue = sut_->getOutputLevel(testedGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt);
        EXPECT_EQ(optionalReturnedValue, definitions::EGpioState::High);
    }
    {
        EXPECT_CALL(gpioSettingsControllerMock_, getGpioDirection(testedGpioNumber_))
            .WillOnce(::testing::Return(std::optional(definitions::EGpioDirection::Output)));
        EXPECT_CALL(picoGpioMock_, gpio_get(testedGpioNumber_))
            .WillOnce(::testing::Return(false));
        const auto optionalReturnedValue = sut_->getOutputLevel(testedGpioNumber_);
        ASSERT_NE(optionalReturnedValue, std::nullopt);
        EXPECT_EQ(optionalReturnedValue, definitions::EGpioState::Low);
    }
}

TEST_F(GpioStateControllerShould, returnNotPossibleOnSetOutputLevelAndNullOptDirection)
{
    EXPECT_CALL(gpioSettingsControllerMock_, getGpioDirection(testedGpioNumber_))
        .WillOnce(::testing::Return(std::nullopt));
    EXPECT_EQ(sut_->setOutputLevel(testedGpioNumber_, definitions::EGpioState::High),
        core::definitions::EOperationResult::NotPossible);
}

TEST_F(GpioStateControllerShould, returnNotPossibleOnSetOutputLevelAndInputDirection)
{
    EXPECT_CALL(gpioSettingsControllerMock_, getGpioDirection(testedGpioNumber_))
        .WillOnce(::testing::Return(std::optional(definitions::EGpioDirection::Input)));
    EXPECT_EQ(sut_->setOutputLevel(testedGpioNumber_, definitions::EGpioState::High),
        core::definitions::EOperationResult::NotPossible);
}

TEST_F(GpioStateControllerShould, setCorrectGpioLevel)
{
    {
        EXPECT_CALL(gpioSettingsControllerMock_, getGpioDirection(testedGpioNumber_))
            .WillOnce(::testing::Return(std::optional(definitions::EGpioDirection::Output)));
        EXPECT_CALL(picoGpioMock_, gpio_put(testedGpioNumber_, true))
            .Times(1u);
        EXPECT_EQ(sut_->setOutputLevel(testedGpioNumber_, definitions::EGpioState::High),
            core::definitions::EOperationResult::Success);
    }
    {
        EXPECT_CALL(gpioSettingsControllerMock_, getGpioDirection(testedGpioNumber_))
            .WillOnce(::testing::Return(std::optional(definitions::EGpioDirection::Output)));
        EXPECT_CALL(picoGpioMock_, gpio_put(testedGpioNumber_, false))
            .Times(1u);
        EXPECT_EQ(sut_->setOutputLevel(testedGpioNumber_, definitions::EGpioState::Low),
            core::definitions::EOperationResult::Success);
    }
}

}  // namespace gpio
}  // namespace rpipicosdkal
