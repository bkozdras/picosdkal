/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkalstub/gpio/GpioStateControllerStub.hpp>

#include <vector>

namespace rpipicosdkal
{
namespace gpio
{

namespace
{

std::vector<core::TGpioNumber> getAllGpioNumbers()
{
    std::vector<core::TGpioNumber> allPicoGpioNumbers;
    for (auto gpioNumber = 0u; gpioNumber <= 22u; ++gpioNumber)
    {
        allPicoGpioNumbers.push_back(gpioNumber);
    }
    for (auto gpioNumber = 26u; gpioNumber <= 28u; ++gpioNumber)
    {
        allPicoGpioNumbers.push_back(gpioNumber);
    }
    return allPicoGpioNumbers;
}

}  // namespace

GpioStateControllerStub::GpioStateControllerStub(
        GpioSettingsControllerStub& gpioSettingsControllerStub)
    : gpioSettingsControllerStub_(gpioSettingsControllerStub)
    , gpioToState_()
{
    const auto allGpios = getAllGpioNumbers();
    for (const auto gpio : allGpios)
    {
        gpioToState_.emplace(std::make_pair(gpio, definitions::EGpioState::Low));
    }
}

GpioStateControllerStubPtr GpioStateControllerStub::create(
    GpioSettingsControllerStub& gpioSettingsControllerStub)
{
    return GpioStateControllerStubPtr(new GpioStateControllerStub(gpioSettingsControllerStub));
}

std::optional<definitions::EGpioState> GpioStateControllerStub::getInputLevel(
    const core::TGpioNumber gpioNumber)
{
    const auto optionalGpioDirection = gpioSettingsControllerStub_.getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Input)
    {
        return std::nullopt;
    }
    return gpioToState_.at(gpioNumber);
}

std::optional<definitions::EGpioState> GpioStateControllerStub::getOutputLevel(
    const core::TGpioNumber gpioNumber)
{
    const auto optionalGpioDirection = gpioSettingsControllerStub_.getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Output)
    {
        return std::nullopt;
    }
    return gpioToState_.at(gpioNumber);
}

core::definitions::EOperationResult GpioStateControllerStub::setOutputLevel(
    const core::TGpioNumber gpioNumber,
    const definitions::EGpioState gpioState)
{
    const auto optionalGpioDirection = gpioSettingsControllerStub_.getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Output)
    {
        return core::definitions::EOperationResult::NotPossible;
    }
    gpioToState_[gpioNumber] = gpioState;
    return core::definitions::EOperationResult::Success;
}

void GpioStateControllerStub::simulateGpioStateChange(const core::TGpioNumber gpioNumber,
    const definitions::EGpioState gpioState)
{
    const auto optionalGpioDirection = gpioSettingsControllerStub_.getGpioDirection(gpioNumber);
    if (optionalGpioDirection == std::nullopt
        || optionalGpioDirection.value() != definitions::EGpioDirection::Input)
    {
        return;
    }
    gpioToState_[gpioNumber] = gpioState;
}

}  // namespace gpio
}  // namespace rpipicosdkal
