#pragma once

#include <ostream>

#include <boost/optional/optional_io.hpp>

#include "nextDateMachine.hpp"

struct NextDateTestValue {
    Date input;
    boost::optional<Date> expetation;
};

std::ostream&
operator<<(std::ostream& os, const NextDateTestValue& val) {
    os << "inputs: " << val.input << ", ";
    os << "Expetation: " << val.expetation;

    return os;
}
