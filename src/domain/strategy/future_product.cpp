#include "future_product.hpp"
#include "../models/price.hpp"

#include <string>

FutureProduct::FutureProduct(std::string _name, MarketDataPort& port) 
: name(_name), marketDataPort(port)
{
    this->priceHistory = std::vector<Price>(100);
};

FutureProduct::~FutureProduct() {};

bool FutureProduct::GetState() const
{
    return true;
}

std::string FutureProduct::GetName() const
{
    return this->name;
}

Price FutureProduct::GetPrices() const 
{
    return marketDataPort.GetPrices(name);
}