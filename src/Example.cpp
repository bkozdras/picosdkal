#include <rpipicosdkal/Example.hpp>

#include <iostream>

namespace rpipicosdkal
{

Example::Example()
{
    std::cout << "C-tor called" << std::endl;
}

IExamplePtr Example::create()
{
    return IExamplePtr(new Example());
}

Example::~Example()
{
    std::cout << "D-tor called" << std::endl;
}

uint32_t Example::foo()
{
    std::cout << "Foo called" << std::endl;
    return 42u;
}

}  // namespace rpipicosdkal
