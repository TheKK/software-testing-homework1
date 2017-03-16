#pragma once

#include <vector>

#include "triangleTestValue.hpp"

// Here stores all kinds of equivalence class testcase.
//
//  - C1 = {a, b, c, which form an equilateral triangle}
//  - C2 = {a, b, c, which form an isosceles triangle}
//  - C3 = {a, b, c, which form an scalene triangle}
//  - C4 = {a, b, c, which unable to form an triangle}
//
std::vector<TriangleTestValue> equivalenceClassTestcase{
    // Weak normal
    {{42, 42, 42}, TriangleType::Equilateral},
    {{42, 42, 10}, TriangleType::Isosceles},
    {{42, 41, 10}, TriangleType::Scalene},
    {{42, 9, 9}, TriangleType::NotATriangle},

    // Weak robust
    {{0, 42, 42}, TriangleType::InvalidInput},
    {{201, 42, 42}, TriangleType::InvalidInput},
    {{0, 42, 41}, TriangleType::InvalidInput},
    {{201, 42, 41}, TriangleType::InvalidInput},

    // Strong normal (impssible for triangle problem)
    // Skip

    // Strong robust
    {{0, 0, 42}, TriangleType::InvalidInput},
    {{0, 0, 0}, TriangleType::InvalidInput},
    {{201, 201, 42}, TriangleType::InvalidInput},
    {{201, 201, 201}, TriangleType::InvalidInput},
};
