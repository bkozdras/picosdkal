/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/core/Logger.hpp>

#include <rpipicosdkal/core/definitions/ELogSeverity.hpp>

namespace rpipicosdkal
{
namespace core
{
namespace logger
{

namespace
{

static bool isLoggingEnabled = false;

}  // namespace

detail::StdOutLoggerFlusher debug(const std::string& prefix)
{
    return detail::StdOutLoggerFlusher(definitions::ELogSeverity::Debug, prefix, isLoggingEnabled);
}

detail::StdOutLoggerFlusher info(const std::string& prefix)
{
    return detail::StdOutLoggerFlusher(definitions::ELogSeverity::Info, prefix, isLoggingEnabled);
}

detail::StdOutLoggerFlusher warning(const std::string& prefix)
{
    return detail::StdOutLoggerFlusher(definitions::ELogSeverity::Warning, prefix, isLoggingEnabled);
}

detail::StdOutLoggerFlusher error(const std::string& prefix)
{
    return detail::StdOutLoggerFlusher(definitions::ELogSeverity::Error, prefix, isLoggingEnabled);
}

void disableLogging()
{
    isLoggingEnabled = false;
}

void enableLogging()
{
    isLoggingEnabled = true;
}

}  // namespace logger
}  // namespace core
}  // namespace rpipicosdkal
