enum class TriangleType {
    Equilateral,
    Scalene,
    Isosceles,
    NotATriangle,
};

TriangleType caculateTriangleType(int sideA, int sideB, int sideC) noexcept;
