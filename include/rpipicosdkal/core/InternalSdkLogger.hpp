/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_CORE_INTERNALSDKLOGGER_HPP_
#define RPIPICOSDKAL_CORE_INTERNALSDKLOGGER_HPP_

#include <string>

#if defined(USE_SDK_LOGGING)
    #include <rpipicosdkal/core/detail/StdOutLoggerFlusher.hpp>
#else
    #include <rpipicosdkal/core/detail/NullOutLoggerFlusher.hpp>
#endif  // USE_SDK_LOGGING

#define SDK_LOG_DEBUG(prefix) rpipicosdkal::core::internalsdklogger::debug(prefix)
#define SDK_LOG_INFO(prefix) rpipicosdkal::core::internalsdklogger::info(prefix)
#define SDK_LOG_WARNING(prefix) rpipicosdkal::core::internalsdklogger::warning(prefix)
#define SDK_LOG_ERROR(prefix) rpipicosdkal::core::internalsdklogger::error(prefix)

#if defined(USE_SDK_LOGGING)
    #define SDK_LOGGER_FLUSHER detail::StdOutLoggerFlusher
#else
    #define SDK_LOGGER_FLUSHER detail::NullOutLoggerFlusher
#endif  // USE_SDK_LOGGING

namespace rpipicosdkal
{
namespace core
{
namespace internalsdklogger
{

SDK_LOGGER_FLUSHER debug(const std::string& prefix);
SDK_LOGGER_FLUSHER info(const std::string& prefix);
SDK_LOGGER_FLUSHER warning(const std::string& prefix);
SDK_LOGGER_FLUSHER error(const std::string& prefix);

void disableLogging();
void enableLogging();  // enabled by default

}  // namespace internalsdklogger
}  // namespace core
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_CORE_INTERNALSDKLOGGER_HPP_
