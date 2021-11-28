/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/core/definitions/ELogSeverity.hpp>

#include <cstdint>

namespace rpipicosdkal
{
namespace core
{
namespace definitions
{

std::string toString(const ELogSeverity logSeverity)
{
    switch (logSeverity)
    {
        case ELogSeverity::Debug: return "Debug";
        case ELogSeverity::Info: return "Info";
        case ELogSeverity::Warning: return "Warning";
        case ELogSeverity::Error: return "Error";
    }
    return std::to_string(static_cast<uint8_t>(logSeverity));
}

}  // namespace definitions
}  // namespace core
}  // namespace rpipicosdkal
