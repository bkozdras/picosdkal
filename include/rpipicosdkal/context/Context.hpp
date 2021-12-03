/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_CONTEXT_CONTEXT_HPP_
#define RPIPICOSDKAL_CONTEXT_CONTEXT_HPP_

#include <rpipicosdkal/context/fwd.hpp>
#include <rpipicosdkal/context/IContext.hpp>
#include <rpipicosdkal/gpio/fwd.hpp>

namespace rpipicosdkal
{
namespace context
{

class Context final : public IContext
{
public:
    static IContextPtr create();
    ~Context();

    gpio::IContext& gpio() override;

private:
    Context();

    gpio::IContextPtr gpio_;
};

}  // namespace context
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_CONTEXT_CONTEXT_HPP_
