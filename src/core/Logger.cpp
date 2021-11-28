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

detail::LoggerFlusher debug(const std::string& prefix)
{
    return detail::LoggerFlusher(definitions::ELogSeverity::Debug, prefix);
}

detail::LoggerFlusher info(const std::string& prefix)
{
    return detail::LoggerFlusher(definitions::ELogSeverity::Info, prefix);
}

detail::LoggerFlusher warning(const std::string& prefix)
{
    return detail::LoggerFlusher(definitions::ELogSeverity::Warning, prefix);
}

detail::LoggerFlusher error(const std::string& prefix)
{
    return detail::LoggerFlusher(definitions::ELogSeverity::Error, prefix);
}

}  // namespace logger
}  // namespace core
}  // namespace rpipicosdkal
