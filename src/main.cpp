#include <iostream>
#include "domain/strategy/future_product.hpp"
#include "ports/market_data_port.hpp"

using namespace std;

int main(void)
{
    std::cout << "Hello !!!!!" << std::endl;

    NullMarketDataPort nmdp;
    auto fPtr = new FutureProduct("ES", nmdp);

    std::cout << fPtr->GetState() << std::endl;

    delete fPtr;

};