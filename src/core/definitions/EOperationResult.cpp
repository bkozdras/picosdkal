/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/core/definitions/EOperationResult.hpp>

#include <cstdint>

namespace rpipicosdkal
{
namespace core
{
namespace definitions
{

std::string toString(const EOperationResult operationResult)
{
    switch (operationResult)
    {
        case EOperationResult::Success: return "Success";
        case EOperationResult::UndefinedError: return "UndefinedError";
        case EOperationResult::InvalidArgument: return "InvalidArgument";
        case EOperationResult::NotPossible: return "NotPossible";
    }
    return std::to_string(static_cast<uint8_t>(operationResult));
}

}  // namespace definitions
}  // namespace core
}  // namespace rpipicosdkal
