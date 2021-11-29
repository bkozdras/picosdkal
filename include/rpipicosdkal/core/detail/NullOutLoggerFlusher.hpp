/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_CORE_DETAIL_NULLOUTLOGGERFLUSHER_HPP_
#define RPIPICOSDKAL_CORE_DETAIL_NULLOUTLOGGERFLUSHER_HPP_

#include <sstream>
#include <string>

#include <rpipicosdkal/core/definitions/ELogSeverity.hpp>

namespace rpipicosdkal
{
namespace core
{
namespace detail
{

class NullOutLoggerFlusher final
{
public:
    explicit NullOutLoggerFlusher(const definitions::ELogSeverity,
        const std::string&,
        const bool);
    ~NullOutLoggerFlusher() = default;

    template <typename Type>
    NullOutLoggerFlusher& operator<<(const Type&)
    {
        return *this;
    }
};

}  // namespace detail
}  // namespace core
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_CORE_DETAIL_NULLOUTLOGGERFLUSHER_HPP_
