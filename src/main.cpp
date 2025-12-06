#include <iostream>
#include "domain/strategy/future_product.hpp"

using namespace std;

int main(void)
{
    std::cout << "Hello !!!!!" << std::endl;

    auto fPtr = new FutureProduct("ES");

    std::cout << fPtr->GetState() << std::endl;

    delete fPtr;

};