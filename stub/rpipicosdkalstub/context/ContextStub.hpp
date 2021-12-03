/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKALSTUB_CONTEXT_CONTEXT_HPP_
#define RPIPICOSDKALSTUB_CONTEXT_CONTEXT_HPP_

#include <rpipicosdkal/context/IContext.hpp>

#include <rpipicosdkalstub/gpio/ContextStub.hpp>

namespace rpipicosdkal
{
namespace context
{

class ContextStub final : public IContext
{
public:
    static std::unique_ptr<ContextStub> create();
    ~ContextStub();

    gpio::IContext& gpio() override;

    gpio::ContextStub& gpioStub();

private:
    ContextStub();

    std::unique_ptr<gpio::ContextStub> gpioContextStub_;
};

}  // namespace context
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKALSTUB_CONTEXT_CONTEXT_HPP_
