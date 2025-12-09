#pragma once

#include <vector>
#include <string>

struct Price {
    std::string timestamp;
    std::vector<double> bid;
    std::vector<double> ask;
};