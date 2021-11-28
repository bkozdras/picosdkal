/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_CORE_DETAIL_LOGGERFLUSHER_HPP_
#define RPIPICOSDKAL_CORE_DETAIL_LOGGERFLUSHER_HPP_

#include <sstream>
#include <string>

#include <rpipicosdkal/core/definitions/ELogSeverity.hpp>

namespace rpipicosdkal
{
namespace core
{
namespace detail
{

class LoggerFlusher final
{
public:
    explicit LoggerFlusher(const definitions::ELogSeverity logSeverity,
        const std::string& prefix);
    ~LoggerFlusher();

    template <typename Type>
    LoggerFlusher& operator<<(const Type& data)
    {
        outStr_ << data;
        return *this;
    }

private:
    std::ostringstream outStr_;
};

}  // namespace detail
}  // namespace core
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_CORE_DETAIL_LOGGERFLUSHER_HPP_
