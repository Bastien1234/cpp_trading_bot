#pragma once

#include <string>

class FutureProduct {
private:
    const std::string name;
    unsigned int state{0};
public:
    // Constructors / Destructors
    FutureProduct(std::string name);
    ~FutureProduct();

    // Getters / Setters
    bool GetState() const;
    std::string GetName() const;
};