#ifndef RPIPICOSDKALSTUB_EXAMPLESTUB_HPP_
#define RPIPICOSDKALMOCK_EXAMPLESTUB_HPP_

#include <memory>

#include <rpipicosdkal/IExample.hpp>

namespace rpipicosdkal
{

class ExampleStub : public IExample
{
public:
    ExampleStub() = default;
    ~ExampleStub() = default;

    uint32_t foo() override;
};

}  // namespace rpipicosdkal

#endif  // RPIPICOSDKALMOCK_EXAMPLESTUB_HPP_
