/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_CORE_LOGGER_HPP_
#define RPIPICOSDKAL_CORE_LOGGER_HPP_

#include <string>

#include <rpipicosdkal/core/detail/LoggerFlusher.hpp>

#ifdef LOGGER_DISABLED
#else
    #define LOG_DEBUG(prefix) rpipicosdkal::core::logger::debug(prefix)
    #define LOG_INFO(prefix) rpipicosdkal::core::logger::info(prefix)
    #define LOG_WARNING(prefix) rpipicosdkal::core::logger::warning(prefix)
    #define LOG_ERROR(prefix) rpipicosdkal::core::logger::error(prefix)
#endif

namespace rpipicosdkal
{
namespace core
{
namespace logger
{

detail::LoggerFlusher debug(const std::string& prefix);
detail::LoggerFlusher info(const std::string& prefix);
detail::LoggerFlusher warning(const std::string& prefix);
detail::LoggerFlusher error(const std::string& prefix);

}  // namespace logger
}  // namespace core
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_CORE_LOGGER_HPP_
