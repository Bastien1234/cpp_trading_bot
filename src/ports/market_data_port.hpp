#pragma once
#include <string>

#include "../domain/models/price.hpp"

class MarketDataPort {
public:
    virtual ~MarketDataPort() = default;

    virtual Price GetPrices(const std::string& productName) = 0;
};

// For mock purposes only
class NullMarketDataPort : public MarketDataPort {
public:
    Price GetPrices(const std::string&) override {
        return Price{}; // safe default
    }
};
