/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_CONTEXT_FWD_HPP_
#define RPIPICOSDKAL_CONTEXT_FWD_HPP_

#include <memory>

namespace rpipicosdkal
{
namespace context
{

class IContext;
using IContextPtr = std::unique_ptr<IContext>;

}  // namespace context
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_CONTEXT_FWD_HPP_
