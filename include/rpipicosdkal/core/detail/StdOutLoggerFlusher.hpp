/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_CORE_DETAIL_STDOUTLOGGERFLUSHER_HPP_
#define RPIPICOSDKAL_CORE_DETAIL_STDOUTLOGGERFLUSHER_HPP_

#include <sstream>
#include <string>

#include <rpipicosdkal/core/definitions/ELogSeverity.hpp>

namespace rpipicosdkal
{
namespace core
{
namespace detail
{

class StdOutLoggerFlusher final
{
public:
    explicit StdOutLoggerFlusher(const definitions::ELogSeverity logSeverity,
        const std::string& prefix,
        const bool isOutputEnabled);
    ~StdOutLoggerFlusher();

    template <typename Type>
    StdOutLoggerFlusher& operator<<(const Type& data)
    {
        outStr_ << data;
        return *this;
    }

private:
    const bool isOutputEnabled_;
    std::ostringstream outStr_;
};

}  // namespace detail
}  // namespace core
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_CORE_DETAIL_STDOUTLOGGERFLUSHER_HPP_
