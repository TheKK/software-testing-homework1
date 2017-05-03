#include <gtest/gtest.h>

#include "triangleMachine.hpp"

using namespace testing;

TEST(TriangleTests, sideAIsInvalid) {
    const auto& result = caculateTriangleType(-10, 10, 10);
    EXPECT_EQ(result, TriangleType::InvalidInput);
}

TEST(TriangleTests, sideBIsInvalid) {
    const auto& result = caculateTriangleType(10, -10, 10);
    EXPECT_EQ(result, TriangleType::InvalidInput);
}

TEST(TriangleTests, sideCIsInvalid) {
    const auto& result = caculateTriangleType(10, 10, -10);
    EXPECT_EQ(result, TriangleType::InvalidInput);
}

TEST(TriangleTests, notTriangleA) {
    const auto& result = caculateTriangleType(100, 10, 10);
    EXPECT_EQ(result, TriangleType::NotATriangle);
}

TEST(TriangleTests, notTriangleB) {
    const auto& result = caculateTriangleType(10, 100, 10);
    EXPECT_EQ(result, TriangleType::NotATriangle);
}

TEST(TriangleTests, notTriangleC) {
    const auto& result = caculateTriangleType(10, 10, 100);
    EXPECT_EQ(result, TriangleType::NotATriangle);
}

TEST(TriangleTests, isEquilateralTriangle) {
    const auto& result = caculateTriangleType(10, 10, 10);
    EXPECT_EQ(result, TriangleType::Equilateral);
}

TEST(TriangleTests, isABSideIsoscelesTriangle) {
    const auto& result = caculateTriangleType(10, 10, 15);
    EXPECT_EQ(result, TriangleType::Isosceles);
}

TEST(TriangleTests, isACSideIsoscelesTriangle) {
    const auto& result = caculateTriangleType(10, 15, 10);
    EXPECT_EQ(result, TriangleType::Isosceles);
}

TEST(TriangleTests, isBCSideIsoscelesTriangle) {
    const auto& result = caculateTriangleType(15, 10, 10);
    EXPECT_EQ(result, TriangleType::Isosceles);
}

TEST(TriangleTests, isScaleneTriangle) {
    const auto& result = caculateTriangleType(3, 4, 5);
    EXPECT_EQ(result, TriangleType::Scalene);
}
