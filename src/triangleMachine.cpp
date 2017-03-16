#include "triangleMachine.hpp"

namespace {
inline bool
isValidInput(int side) {
    return (side > 0 && side <= 200);
}
} // namespace

TriangleType
caculateTriangleType(int sideA, int sideB, int sideC) noexcept {
    if (!isValidInput(sideA) || !isValidInput(sideB) || !isValidInput(sideC)) {
        return TriangleType::InvalidInput;
    }

    if (!(sideA < sideB + sideC) || !(sideB < sideA + sideC) || !(sideC < sideA + sideB)) {
        return TriangleType::NotATriangle;
    }

    const auto abEq = sideA == sideB;
    const auto acEq = sideA == sideC;
    const auto bcEq = sideB == sideC;

    if (abEq && bcEq) {
        return TriangleType::Equilateral;

    } else if (abEq || acEq || bcEq) {
        return TriangleType::Isosceles;

    } else {
        return TriangleType::Scalene;
    }
}

std::ostream&
operator<<(std::ostream& os, const TriangleType& val) {
    switch (val) {
    case TriangleType::Equilateral:
        os << "Equilateral";
        break;

    case TriangleType::Isosceles:
        os << "Isosceles";
        break;

    case TriangleType::Scalene:
        os << "Scalene";
        break;

    case TriangleType::NotATriangle:
        os << "NotATriangle";
        break;

    case TriangleType::InvalidInput:
        os << "InvalidInput";
        break;
    }

    return os;
}
