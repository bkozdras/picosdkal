/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/gpio/detail/PrinterBase.hpp>

#include <sstream>

#include <rpipicosdkal/core/InternalSdkLogger.hpp>

namespace rpipicosdkal
{
namespace gpio
{
namespace detail
{

PrinterBase::PrinterBase(const std::string& loggerPrefix)
    : loggerPrefix_(loggerPrefix)
{
}

core::definitions::EOperationResult PrinterBase::printMessageAndReturnOperationResult(
    const std::string& functionName,
    const core::definitions::EOperationResult operationResult,
    const std::string& message)
{
    if (operationResult == core::definitions::EOperationResult::Success)
    {
        SDK_LOG_DEBUG(loggerPrefix_)
            << "(" << functionName << ") "
            << message
            << ". Result: " << core::definitions::toString(operationResult);
    }
    else
    {
        SDK_LOG_WARNING(loggerPrefix_)
            << "(" << functionName << ") "
            << message
            << ". Result: " << core::definitions::toString(operationResult);
    }
    return operationResult;
}

core::definitions::EOperationResult PrinterBase::printNotValidGpioDirectionAndReturnOperationResult(
    const std::string& functionName,
    const core::TGpioNumber gpioNumber,
    const std::optional<definitions::EGpioDirection>& optionalGpioDirection,
    const core::definitions::EOperationResult operationResult)
{
    std::ostringstream message;
    message
        << "Not valid GPIO "
        << std::to_string(gpioNumber)
        << " direction: "
        << (optionalGpioDirection == std::nullopt
            ? std::string("N/A")
            : definitions::toString(optionalGpioDirection.value()));
    return printMessageAndReturnOperationResult(functionName, operationResult, message.str());
}

core::definitions::EOperationResult PrinterBase::printNotValidGpioFunctionAndReturnOperationResult(
    const std::string& functionName,
    const core::TGpioNumber gpioNumber,
    const std::optional<definitions::EGpioFunction>& optionalGpioFunction,
    const core::definitions::EOperationResult operationResult)
{
    std::ostringstream message;
    message
        << "Not valid GPIO "
        << std::to_string(gpioNumber)
        << " function: "
        << (optionalGpioFunction == std::nullopt
            ? std::string("N/A")
            : definitions::toString(optionalGpioFunction.value()));
    return printMessageAndReturnOperationResult(functionName, operationResult, message.str());
}

core::definitions::EOperationResult PrinterBase::printNotValidGpioNumberAndReturnOperationResult(
    const std::string& functionName,
    const core::TGpioNumber gpioNumber,
    const core::definitions::EOperationResult operationResult)
{
    std::ostringstream message;
    message
        << "Not valid GPIO " << std::to_string(gpioNumber)
        << " passed: "
        << std::to_string(gpioNumber);
    return printMessageAndReturnOperationResult(functionName, operationResult, message.str());
}

void PrinterBase::printNotValidGpioDirection(
    const std::string& functionName,
    const core::TGpioNumber gpioNumber,
    const std::optional<definitions::EGpioDirection>& optionalGpioDirection)
{
    SDK_LOG_ERROR(loggerPrefix_)
        << "(" << functionName << ") "
        << "Not valid GPIO "
        << std::to_string(gpioNumber)
        << " direction: "
        << (optionalGpioDirection == std::nullopt
            ? std::string("N/A")
            : definitions::toString(optionalGpioDirection.value()));
}

void PrinterBase::printNotValidGpioFunction(
    const std::string& functionName,
    const core::TGpioNumber gpioNumber,
    const std::optional<definitions::EGpioFunction>& optionalGpioFunction)
{
    SDK_LOG_ERROR(loggerPrefix_)
        << "(" << functionName << ") "
        << "Not valid GPIO "
        << std::to_string(gpioNumber)
        << " function: "
        << (optionalGpioFunction == std::nullopt
            ? std::string("N/A")
            : definitions::toString(optionalGpioFunction.value()));
}

void PrinterBase::printNotValidGpioNumber(
    const std::string& functionName,
    const core::TGpioNumber gpioNumber)
{
    SDK_LOG_ERROR(loggerPrefix_)
        << "(" << functionName << ") "
        << "Not valid GPIO " << std::to_string(gpioNumber)
        << " passed: "
        << std::to_string(gpioNumber);
}

}  // namespace detail
}  // namespace gpio
}  // namespace rpipicosdkal
