#include <rpipicosdkalmock/IExampleMock.hpp>

namespace rpipicosdkal
{

IExampleMockPtr IExampleMock::create()
{
    return IExampleMockPtr(new IExampleMock());
}

IExampleNiceMockPtr IExampleMock::createNice()
{
    return IExampleNiceMockPtr(new IExampleNiceMock());
}

IExampleStrictMockPtr IExampleMock::createStrict()
{
    return IExampleStrictMockPtr(new IExampleStrictMock());
}

}  // namespace rpipicosdkal
