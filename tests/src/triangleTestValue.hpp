#pragma once

#include <array>
#include <ostream>

#include "triangleMachine.hpp"

// These should make testing and testing result more easy to understand and mantain.
struct TriangleTestValue {
    std::array<std::int32_t, 3> inputs;
    TriangleType expetation;
};

std::ostream&
operator<<(std::ostream& os, const TriangleTestValue& val) {
    os << "inputs: ";
    for (const auto& input : val.inputs) {
        os << input << ", ";
    }
    os << "Expetation: " << val.expetation;

    return os;
}
