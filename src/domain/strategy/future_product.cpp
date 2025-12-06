#include "future_product.hpp"

#include <string>

FutureProduct::FutureProduct(std::string name) 
: name(name) 
{};

FutureProduct::~FutureProduct() {};

bool FutureProduct::GetState() const
{
    return true;
}

std::string FutureProduct::GetName() const
{
    return this->name;
}