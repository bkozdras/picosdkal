/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/core/detail/LoggerFlusher.hpp>

#include <iostream>

namespace rpipicosdkal
{
namespace core
{
namespace detail
{

LoggerFlusher::LoggerFlusher(const definitions::ELogSeverity logSeverity,
        const std::string& prefix)
    : outStr_()
{
    outStr_ << "["
        << definitions::toString(logSeverity)
        << "]["
        << prefix
        << "]: ";
}

LoggerFlusher::~LoggerFlusher()
{
    std::cout << outStr_.str() << std::endl;
}

}  // namespace detail
}  // namespace core
}  // namespace rpipicosdkal
