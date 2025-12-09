#pragma once
#include <vector>
#include <string>

#include "../models/price.hpp"

class MarketDataPort {
public:
    virtual ~MarketDataPort() = default;

    virtual Price GetPrices(const std::string& productName) = 0;
};
