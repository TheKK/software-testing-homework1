#pragma once

#include <ostream>

enum class TriangleType {
    Equilateral,
    Scalene,
    Isosceles,
    NotATriangle,

    // XXX This is only for convenience. Don't use this code in production!!
    InvalidInput,
};

std::ostream& operator<<(std::ostream& os, const TriangleType& val);

TriangleType caculateTriangleType(int sideA, int sideB, int sideC) noexcept;
