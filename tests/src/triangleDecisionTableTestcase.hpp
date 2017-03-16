#pragma once

#include <vector>

#include "triangleTestValue.hpp"

// Here stores all kinds of testcase from decision table.
//
// Please check out `draft.org` for detail decision table.
//
std::vector<TriangleTestValue> decisionTableValueTestcase{
    {{42, 42, 42}, TriangleType::Equilateral},

    {{42, 42, 3}, TriangleType::Isosceles},
    {{42, 3, 42}, TriangleType::Isosceles},
    {{3, 42, 42}, TriangleType::Isosceles},

    {{3, 4, 5}, TriangleType::Scalene},

    {{100, 4, 5}, TriangleType::NotATriangle},
    {{3, 100, 5}, TriangleType::NotATriangle},
    {{3, 4, 100}, TriangleType::NotATriangle},
};
