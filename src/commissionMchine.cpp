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
    return boost::none;
}
