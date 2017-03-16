#include "triangleMachine.hpp"

TriangleType
caculateTriangleType(int sideA, int sideB, int sideC) noexcept {
    return TriangleType::NotATriangle;
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
