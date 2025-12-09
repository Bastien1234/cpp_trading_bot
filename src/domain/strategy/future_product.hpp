#pragma once

#include "../ports/market_data_port.hpp"

#include <string>

class FutureProduct {
private:
    const std::string name;
    unsigned int state{0};
    std::vector<Price> priceHistory;

    // Reference to ports
    MarketDataPort& marketDataPort;
public:
    // Constructors / Destructors
    FutureProduct(std::string _name, MarketDataPort& port);
    ~FutureProduct();

    // Getters / Setters
    bool GetState() const;
    std::string GetName() const;

    // Calling ports
    Price GetPrices() const;

    // Strategy
    void RangeIsBigEnough();
    void PriceHasRetraced();
};