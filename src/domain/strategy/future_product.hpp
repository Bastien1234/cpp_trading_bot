#pragma once

#include "../../ports/market_data_port.hpp"

#include <string>
#include <vector>
#include <chrono>

enum SIDE_BREAKING {
    HIGH,
    LOW,
};

class FutureProduct {
private:
    const std::string name;
    // State is store as an array of bits
    unsigned int state{0};
    // Last computed time
    // Keep it as a variable to avoir reallocating memory for new variables
    std::chrono::high_resolution_clock lastComputedTime;
    
    // update with GetPrices()
    SIDE_BREAKING currentSideBreaking;
    std::vector<Price> priceHistory;

    // Reference to ports
    MarketDataPort& marketDataPort;
    
    // Calling ports
    Price GetPrices();
    void GetGraph(); // TO DO: not void
    
    // Strategy from graph
    void RangeIsBigEnough();
    void PriceHasRetraced();
    
    // Strategy from dom
    void DynamicPush();
    void DynamicBack(); // After push
    void IsDomFull();
    public:
    // Constructors / Destructors
    FutureProduct(std::string _name, MarketDataPort& port);
    ~FutureProduct();
    
    // Getters / Setters
    bool GetState() const;
    std::string GetName() const;
    
    // Run
    // calls all the methods is the right order
    void Run();
};