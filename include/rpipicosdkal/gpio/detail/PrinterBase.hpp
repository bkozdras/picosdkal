/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_GPIO_DETAIL_PRINTERBASE_HPP_
#define RPIPICOSDKAL_GPIO_DETAIL_PRINTERBASE_HPP_

#include <optional>
#include <string>

#include <rpipicosdkal/core/Types.hpp>
#include <rpipicosdkal/core/definitions/EOperationResult.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioDirection.hpp>
#include <rpipicosdkal/gpio/definitions/EGpioFunction.hpp>

namespace rpipicosdkal
{
namespace gpio
{
namespace detail
{

class PrinterBase
{
protected:
    explicit PrinterBase(const std::string& loggerPrefix);

    core::definitions::EOperationResult printMessageAndReturnOperationResult(
        const std::string& functionName,
        const core::definitions::EOperationResult operationResult,
        const std::string& message);
    core::definitions::EOperationResult printNotValidGpioDirectionAndReturnOperationResult(
        const std::string& functionName,
        const core::TGpioNumber gpioNumber,
        const std::optional<definitions::EGpioDirection>& optionalGpioDirection,
        const core::definitions::EOperationResult operationResult);
    core::definitions::EOperationResult printNotValidGpioFunctionAndReturnOperationResult(
        const std::string& functionName,
        const core::TGpioNumber gpioNumber,
        const std::optional<definitions::EGpioFunction>& optionalGpioFunction,
        const core::definitions::EOperationResult operationResult);
    core::definitions::EOperationResult printNotValidGpioNumberAndReturnOperationResult(
        const std::string& functionName,
        const core::TGpioNumber gpioNumber,
        const core::definitions::EOperationResult operationResult);
    void printNotValidGpioDirection(
        const std::string& functionName,
        const core::TGpioNumber gpioNumber,
        const std::optional<definitions::EGpioDirection>& optionalGpioDirection);
    void printNotValidGpioFunction(
        const std::string& functionName,
        const core::TGpioNumber gpioNumber,
        const std::optional<definitions::EGpioFunction>& optionalGpioFunction);
    void printNotValidGpioNumber(
        const std::string& functionName,
        const core::TGpioNumber gpioNumber);

    const std::string loggerPrefix_;
};

}  // namespace detail
}  // namespace gpio
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_GPIO_DETAIL_PRINTERBASE_HPP_
