#pragma once

#include <vector>

#include "commissionTestValue.hpp"

std::vector<CommissionTestValue> decisionTableValueTestcase{
    {{0, 10, 10}, boost::none},

    // profit >= 1800
    {{44, 1, 1}, 267.00000},

    // 1800 > profit >= 1000
    {{22, 1, 1}, 106.75000},

    // profit < 1000
    {{1, 1, 1}, 10.00000},
};
