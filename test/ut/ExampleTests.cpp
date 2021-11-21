#include <cstdint>

#include <gmock/gmock.h>

#include <rpipicosdkal/fwd.hpp>
#include <rpipicosdkal/Example.hpp>

namespace rpipicosdkal
{

class ExampleShould : public ::testing::Test
{
protected:
    ExampleShould();

    IExamplePtr sut_;
};

ExampleShould::ExampleShould()
{
    sut_ = Example::create();
}

TEST_F(ExampleShould, return42OnFoo)
{
    EXPECT_EQ(sut_->foo(), 42u);
}

}  // namespace rpipicosdkal
