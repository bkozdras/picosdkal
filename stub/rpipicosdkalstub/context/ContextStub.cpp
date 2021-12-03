/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <rpipicosdkalstub/context/ContextStub.hpp>

namespace rpipicosdkal
{
namespace context
{

ContextStub::ContextStub()
    : gpioContextStub_()
{
    gpioContextStub_ = gpio::ContextStub::create();
}

ContextStub::~ContextStub()
{
    gpioContextStub_.reset();
}

std::unique_ptr<ContextStub> ContextStub::create()
{
    return std::unique_ptr<ContextStub>(new ContextStub());
}

gpio::IContext& ContextStub::gpio()
{
    return gpioStub();
}

gpio::ContextStub& ContextStub::gpioStub()
{
    return *gpioContextStub_;
}

}  // namespace context
}  // namespace rpipicosdkal
