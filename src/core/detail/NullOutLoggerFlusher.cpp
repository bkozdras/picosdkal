/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/core/detail/NullOutLoggerFlusher.hpp>

#include <iostream>

namespace rpipicosdkal
{
namespace core
{
namespace detail
{

NullOutLoggerFlusher::NullOutLoggerFlusher(const definitions::ELogSeverity,
    const std::string&,
    const bool)
{
}

}  // namespace detail
}  // namespace core
}  // namespace rpipicosdkal
