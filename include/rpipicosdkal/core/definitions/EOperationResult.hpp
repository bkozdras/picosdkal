/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_CORE_DEFINITIONS_EOPERATIONRESULT_HPP_
#define RPIPICOSDKAL_CORE_DEFINITIONS_EOPERATIONRESULT_HPP_

#include <string>

namespace rpipicosdkal
{
namespace core
{
namespace definitions
{

enum class EOperationResult
{
    Success = 0u,
    UndefinedError = 1u,
    InvalidArgument = 2u,
    NotPossible = 3u
};

std::string toString(const EOperationResult operationResult);

}  // namespace definitions
}  // namespace core
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_CORE_DEFINITIONS_EOPERATIONRESULT_HPP_
