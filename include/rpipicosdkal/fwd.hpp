#ifndef RPIPICOSDKAL_FWD_HPP_
#define RPIPICOSDKAL_FWD_HPP_

#include <memory>

namespace rpipicosdkal
{

class IExample;
using IExamplePtr = std::unique_ptr<IExample>;

}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_FWD_HPP_
