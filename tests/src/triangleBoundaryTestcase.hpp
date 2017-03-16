#pragma once

#include <vector>

#include "triangleTestValue.hpp"

// Here stores all kinds of boundary value testcase.
//
// Valid value = {1..200} as integer
// Boundary value = {1, 2, 199, 200}
// Robust value = {0, 201}
//
std::vector<TriangleTestValue> boundaryValueTestcase{
    // Normal boundary
    {{1, 100, 100}, TriangleType::Isosceles},
    {{2, 100, 100}, TriangleType::Isosceles},
    {{199, 100, 100}, TriangleType::Isosceles},
    {{200, 100, 100}, TriangleType::NotATriangle},
    // Skip the rest...

    // Robust normal boundary
    {{0, 100, 100}, TriangleType::InvalidInput},
    {{201, 100, 100}, TriangleType::InvalidInput},
    // Skip the rest...

    // Worst case boundary (two from three variables)
    {{1, 1, 100}, TriangleType::NotATriangle},
    {{1, 2, 100}, TriangleType::NotATriangle},
    {{1, 199, 100}, TriangleType::NotATriangle},
    {{1, 200, 100}, TriangleType::NotATriangle},

    {{2, 1, 100}, TriangleType::NotATriangle},
    {{2, 2, 100}, TriangleType::NotATriangle},
    {{2, 199, 100}, TriangleType::NotATriangle},
    {{2, 200, 100}, TriangleType::NotATriangle},

    {{199, 1, 100}, TriangleType::NotATriangle},
    {{199, 2, 100}, TriangleType::NotATriangle},
    {{199, 199, 100}, TriangleType::Isosceles},
    {{199, 200, 100}, TriangleType::Scalene},

    {{200, 1, 100}, TriangleType::NotATriangle},
    {{200, 2, 100}, TriangleType::NotATriangle},
    {{200, 199, 100}, TriangleType::Scalene},
    {{200, 200, 100}, TriangleType::Isosceles},
    // Skip the rest...

    // Worst case boundary (three from three variables)
    {{1, 1, 1}, TriangleType::Equilateral},
    {{2, 2, 2}, TriangleType::Equilateral},
    {{199, 199, 199}, TriangleType::Equilateral},
    {{200, 200, 200}, TriangleType::Equilateral},

    {{1, 1, 2}, TriangleType::NotATriangle},
    {{1, 1, 199}, TriangleType::NotATriangle},
    {{1, 1, 200}, TriangleType::NotATriangle},

    {{2, 2, 1}, TriangleType::Isosceles},
    {{2, 2, 199}, TriangleType::NotATriangle},
    {{2, 2, 200}, TriangleType::NotATriangle},

    {{199, 199, 1}, TriangleType::Isosceles},
    {{199, 199, 2}, TriangleType::Isosceles},
    {{199, 199, 200}, TriangleType::Isosceles},

    {{200, 200, 1}, TriangleType::Isosceles},
    {{200, 200, 2}, TriangleType::Isosceles},
    {{200, 200, 199}, TriangleType::Isosceles},
    // Skip the rest...

    // Robust worst case boundary (two from three variables)
    {{100, 0, 0}, TriangleType::InvalidInput},
    {{100, 0, 201}, TriangleType::InvalidInput},
    {{100, 201, 201}, TriangleType::InvalidInput},
    // Skip the rest...

    // Robust worst case boundary (three from three variables)
    {{0, 0, 0}, TriangleType::InvalidInput},
    {{201, 201, 201}, TriangleType::InvalidInput},

    {{0, 0, 201}, TriangleType::InvalidInput},
    {{201, 201, 0}, TriangleType::InvalidInput},
    // Skip the rest...
};
