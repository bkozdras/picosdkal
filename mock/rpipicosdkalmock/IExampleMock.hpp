#ifndef RPIPICOSDKALMOCK_IEXAMPLEMOCK_HPP_
#define RPIPICOSDKALMOCK_IEXAMPLEMOCK_HPP_

#include <memory>

#include <gmock/gmock.h>

#include <rpipicosdkal/IExample.hpp>

namespace rpipicosdkal
{

class IExampleMock;
using IExampleMockPtr = std::unique_ptr<IExampleMock>;

using IExampleNiceMock = ::testing::NiceMock<IExampleMock>;
using IExampleNiceMockPtr = std::unique_ptr<IExampleNiceMock>;

using IExampleStrictMock = ::testing::StrictMock<IExampleMock>;
using IExampleStrictMockPtr = std::unique_ptr<IExampleStrictMock>;

class IExampleMock : public IExample
{
public:
    IExampleMock() = default;
    ~IExampleMock() = default;

    static IExampleMockPtr create();
    static IExampleNiceMockPtr createNice();
    static IExampleStrictMockPtr createStrict();

    MOCK_METHOD0(foo, uint32_t());
};

}  // namespace rpipicosdkal

#endif  // RPIPICOSDKALMOCK_IEXAMPLEMOCK_HPP_
