/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_CORE_DEFINITIONS_ELOGSEVERITY_HPP_
#define RPIPICOSDKAL_CORE_DEFINITIONS_ELOGSEVERITY_HPP_

#include <string>

namespace rpipicosdkal
{
namespace core
{
namespace definitions
{

enum class ELogSeverity
{
    Debug = 0u,
    Info = 1u,
    Warning = 2u,
    Error = 3u
};

std::string toString(const ELogSeverity logSeverity);

}  // namespace definitions
}  // namespace core
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_CORE_DEFINITIONS_ELOGSEVERITY_HPP_
