#ifndef RPIPICOSDKAL_EXAMPLE_HPP_
#define RPIPICOSDKAL_EXAMPLE_HPP_

#include <cstdint>

#include <rpipicosdkal/fwd.hpp>
#include <rpipicosdkal/IExample.hpp>

namespace rpipicosdkal
{

class Example final : public IExample
{
public:
    static IExamplePtr create();
    ~Example();

    uint32_t foo() override;

private:
    Example();
};

}  // namespace rpipicosdkal

#endif  // RPIPICOSDKAL_EXAMPLE_HPP_
