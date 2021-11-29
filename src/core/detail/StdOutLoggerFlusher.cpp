/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/core/detail/StdOutLoggerFlusher.hpp>

#include <iostream>

namespace rpipicosdkal
{
namespace core
{
namespace detail
{

StdOutLoggerFlusher::StdOutLoggerFlusher(const definitions::ELogSeverity logSeverity,
        const std::string& prefix,
        const bool isOutputEnabled)
    : isOutputEnabled_(isOutputEnabled)
    , outStr_()
{
    outStr_ << "["
        << definitions::toString(logSeverity)
        << "]["
        << prefix
        << "]: ";
}

StdOutLoggerFlusher::~StdOutLoggerFlusher()
{
    if (isOutputEnabled_)
    {
        std::cout << outStr_.str() << std::endl;
    }
}

}  // namespace detail
}  // namespace core
}  // namespace rpipicosdkal
