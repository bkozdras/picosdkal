#ifndef RPIPICOSDKAL_IEXAMPLE_HPP_
#define RPIPICOSDKAL_IEXAMPLE_HPP_

#include <cstdint>

namespace rpipicosdkal
{

class IExample
{
public:
    virtual ~IExample() = default;

    virtual uint32_t foo() = 0;
};

}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_IEXAMPLE_HPP_
