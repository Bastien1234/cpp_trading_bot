#include <gtest/gtest.h>
#include "../src/domain/strategy/future_product.hpp"
#include "../src/ports/market_data_port.hpp"

// Mock data port
NullMarketDataPort nmdp;

TEST(FutureProductTests, NameIsCorrect)
{
    FutureProduct product = FutureProduct("ES_FUTURE", nmdp);
    EXPECT_EQ(product.GetName(), "ES_FUTURE");
}

TEST(FutureProductTests, StateIsTrue)
{
    FutureProduct product("NQ_FUTURE", nmdp);
    EXPECT_TRUE(product.GetState());
}
