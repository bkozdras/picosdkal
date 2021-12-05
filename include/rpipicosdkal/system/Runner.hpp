/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_SYSTEM_RUNNER_HPP_
#define RPIPICOSDKAL_SYSTEM_RUNNER_HPP_

#include <rpipicosdkal/system/fwd.hpp>

namespace rpipicosdkal
{
namespace system
{

void run(IApplicationPtr&& application);

}  // namespace system
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_SYSTEM_RUNNER_HPP_
