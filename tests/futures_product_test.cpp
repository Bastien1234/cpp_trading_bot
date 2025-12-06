#include <gtest/gtest.h>
#include "../src/domain/strategy/future_product.hpp"

TEST(FutureProductTests, NameIsCorrect)
{
    FutureProduct product("ES_FUTURE");
    EXPECT_EQ(product.GetName(), "ES_FUTURE");
}

TEST(FutureProductTests, StateIsTrue)
{
    FutureProduct product("NQ_FUTURE");
    EXPECT_TRUE(product.GetState());
}
