#pragma once

#include <ostream>

#include <boost/optional/optional_io.hpp>

#include "commissionMachine.hpp"

struct CommissionTestValue {
    PartsSelled input;
    boost::optional<double> expetation;
};

std::ostream&
operator<<(std::ostream& os, const CommissionTestValue& val) {
    os << "inputs: " << val.input << ", ";
    os << "Expetation: " << val.expetation;

    return os;
}
