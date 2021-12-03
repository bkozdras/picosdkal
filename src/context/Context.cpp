/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkal/context/Context.hpp>

#include <rpipicosdkal/gpio/Context.hpp>
#include <rpipicosdkal/gpio/IContext.hpp>

namespace rpipicosdkal
{
namespace context
{

Context::Context()
    : gpio_(nullptr)
{
    gpio_ = gpio::Context::create();
}

Context::~Context()
{
    gpio_.reset();
}

IContextPtr Context::create()
{
    return IContextPtr(new Context());
}

gpio::IContext& Context::gpio()
{
    return *gpio_;
}

}  // namespace context
}  // namespace rpipicosdkal
