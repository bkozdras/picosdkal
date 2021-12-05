/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/system/Runner.hpp>

#include <pico/platform.h>

#include <rpipicosdkal/context/Context.hpp>
#include <rpipicosdkal/system/IApplication.hpp>

namespace rpipicosdkal
{
namespace system
{

void run(IApplicationPtr&& application)
{
    auto context = context::Context::create();
    application->setup(*context);
    for (;;)
    {
        tight_loop_contents();
    }
}

}  // namespace system
}  // namespace rpipicosdkal
