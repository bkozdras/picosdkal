/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/core/InternalSdkLogger.hpp>

#include <rpipicosdkal/core/definitions/ELogSeverity.hpp>

namespace rpipicosdkal
{
namespace core
{
namespace internalsdklogger
{

namespace
{

static bool isLoggingEnabled = false;

}  // namespace

SDK_LOGGER_FLUSHER debug(const std::string& prefix)
{
    return SDK_LOGGER_FLUSHER(definitions::ELogSeverity::Debug, prefix, isLoggingEnabled);
}

SDK_LOGGER_FLUSHER info(const std::string& prefix)
{
    return SDK_LOGGER_FLUSHER(definitions::ELogSeverity::Info, prefix, isLoggingEnabled);
}

SDK_LOGGER_FLUSHER warning(const std::string& prefix)
{
    return SDK_LOGGER_FLUSHER(definitions::ELogSeverity::Warning, prefix, isLoggingEnabled);
}

SDK_LOGGER_FLUSHER error(const std::string& prefix)
{
    return SDK_LOGGER_FLUSHER(definitions::ELogSeverity::Error, prefix, isLoggingEnabled);
}

void disableLogging()
{
    isLoggingEnabled = false;
}

void enableLogging()
{
    isLoggingEnabled = true;
}

}  // namespace internalsdklogger
}  // namespace core
}  // namespace rpipicosdkal
