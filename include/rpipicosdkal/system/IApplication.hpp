/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef RPIPICOSDKAL_SYSTEM_IAPPLICATION_HPP_
#define RPIPICOSDKAL_SYSTEM_IAPPLICATION_HPP_

#include <rpipicosdkal/context/fwd.hpp>

namespace rpipicosdkal
{
namespace system
{

class IApplication
{
public:
    virtual ~IApplication() = default;

    virtual void setup(context::IContext& context) = 0;
};

}  // namespace system
}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_SYSTEM_IAPPLICATION_HPP_
