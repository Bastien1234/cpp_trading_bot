#include "future_product.hpp"
#include "../models/price.hpp"

#include <string>
#include <exception>
#include <chrono>

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

Price FutureProduct::GetPrices()
{
    Price p;
    try {
        p = marketDataPort.GetPrices(name);
    }
    catch (const std::exception &e) {
        throw;
    }

    if ( (p.ask.at(0) < p.ask.at(1)) && (p.bid.at(0) < p.bid.at(1)) )
    {
        currentSideBreaking = SIDE_BREAKING::LOW;
    } 
    else if ( (p.ask.at(0) > p.ask.at(1)) && (p.bid.at(0) > p.bid.at(1)) )
    {
        currentSideBreaking = SIDE_BREAKING::HIGH;
    }

    return p;
}

// Strategy from graph

// Strategy from dom

void DynamicPush()
{
    // TO DO: variable for time elapsed on dynamics

    // Breaking the lows (but never breaking the law)


}