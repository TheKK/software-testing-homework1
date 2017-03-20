#include "commissionMachine.hpp"

#include <iostream>

std::ostream&
operator<<(std::ostream& os, const PartsSelled& selled) {
    os << "locks: " << selled.lockNum << ", stocks: " << selled.stockNum
       << ", barrels: " << selled.barrelNum;

    return os;
}

boost::optional<double>
caculateCommision(PartsSelled selled) noexcept {
    if ((selled.lockNum < 1 || selled.lockNum > 70) || (selled.stockNum < 1 || selled.stockNum > 80)
        || (selled.barrelNum < 1 || selled.barrelNum > 90)) {
        return boost::none;
    }

    const auto total_profit =
        (45 * selled.lockNum) + (30 * selled.stockNum) + (25 * selled.barrelNum);

    if (total_profit >= 1800) {
        return (0.10 * 1000.0) + (0.15 * 800.0) + (total_profit - 1800.0) * 0.2;

    } else if (total_profit >= 1000) {
        return (0.10 * 1000.0) + (total_profit - 1000.0) * 0.15;

    } else {
        return 0.10 * total_profit;
    }
}
