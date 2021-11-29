/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_CORE_LOGGER_HPP_
#define RPIPICOSDKAL_CORE_LOGGER_HPP_

#include <string>

#include <rpipicosdkal/core/detail/StdOutLoggerFlusher.hpp>

#define LOG_DEBUG(prefix) rpipicosdkal::core::logger::debug(prefix)
#define LOG_INFO(prefix) rpipicosdkal::core::logger::info(prefix)
#define LOG_WARNING(prefix) rpipicosdkal::core::logger::warning(prefix)
#define LOG_ERROR(prefix) rpipicosdkal::core::logger::error(prefix)

namespace rpipicosdkal
{
namespace core
{
namespace logger
{

detail::StdOutLoggerFlusher debug(const std::string& prefix);
detail::StdOutLoggerFlusher info(const std::string& prefix);
detail::StdOutLoggerFlusher warning(const std::string& prefix);
detail::StdOutLoggerFlusher error(const std::string& prefix);

void disableLogging();
void enableLogging();  // enabled by default

}  // namespace logger
}  // namespace core
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_CORE_LOGGER_HPP_
