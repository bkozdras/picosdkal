/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_SYSTEM_FWD_HPP_
#define RPIPICOSDKAL_SYSTEM_FWD_HPP_

#include <memory>

namespace rpipicosdkal
{
namespace system
{

class IApplication;
using IApplicationPtr = std::unique_ptr<IApplication>;

}  // namespace system
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_SYSTEM_FWD_HPP_
