/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <cstdint>

#include <gmock/gmock.h>

#include <rpipicosdkal/gpio/fwd.hpp>
#include <rpipicosdkal/gpio/GpioStateController.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioState.hpp>

#include <picosdkmock/hardware_gpio/GpioMock.hpp>

namespace rpipicosdkal
{
namespace gpio
{

class GpioStateControllerShould : public ::testing::Test
{
protected:
    GpioStateControllerShould();

    picosdkmock::hardware_gpio::GpioStrictMock picoGpioMock_;
    const uint8_t testedGpioNumber_;

    IGpioStateControllerPtr sut_;
};

GpioStateControllerShould::GpioStateControllerShould()
    : picoGpioMock_()
    , testedGpioNumber_(22u)
    , sut_(GpioStateController::create())
{
}

TEST_F(GpioStateControllerShould, returnCorrectInputLevel)
{
    {
        EXPECT_CALL(picoGpioMock_, gpio_get(testedGpioNumber_))
            .WillOnce(::testing::Return(true));
        ASSERT_EQ(sut_->getInputLevel(testedGpioNumber_), definitions::EGpioState::High);
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get(testedGpioNumber_))
            .WillOnce(::testing::Return(false));
        ASSERT_EQ(sut_->getInputLevel(testedGpioNumber_), definitions::EGpioState::Low);
    }
}

TEST_F(GpioStateControllerShould, returnCorrectOutputLevel)
{
    {
        EXPECT_CALL(picoGpioMock_, gpio_get(testedGpioNumber_))
            .WillOnce(::testing::Return(true));
        ASSERT_EQ(sut_->getOutputLevel(testedGpioNumber_), definitions::EGpioState::High);
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_get(testedGpioNumber_))
            .WillOnce(::testing::Return(false));
        ASSERT_EQ(sut_->getOutputLevel(testedGpioNumber_), definitions::EGpioState::Low);
    }
}

TEST_F(GpioStateControllerShould, setCorrectGpioLevel)
{
    {
        EXPECT_CALL(picoGpioMock_, gpio_put(testedGpioNumber_, 1))
            .Times(1u);
        sut_->setOutputLevel(testedGpioNumber_, definitions::EGpioState::High);
    }
    {
        EXPECT_CALL(picoGpioMock_, gpio_put(testedGpioNumber_, 0))
            .Times(1u);
        sut_->setOutputLevel(testedGpioNumber_, definitions::EGpioState::Low);
    }
}

}  // namespace gpio
}  // namespace rpipicosdkal
