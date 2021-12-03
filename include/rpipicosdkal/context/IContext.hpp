/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_CONTEXT_ICONTEXT_HPP_
#define RPIPICOSDKAL_CONTEXT_ICONTEXT_HPP_

#include <rpipicosdkal/context/fwd.hpp>
#include <rpipicosdkal/gpio/fwd.hpp>

namespace rpipicosdkal
{
namespace context
{

class IContext
{
public:
    virtual ~IContext() = default;

    virtual gpio::IContext& gpio() = 0;
};

}  // namespace context
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_CONTEXT_ICONTEXT_HPP_
