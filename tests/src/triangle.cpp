#include <array>
#include <iostream>
#include <tuple>
#include <type_traits>
#include <vector>

#include <gtest/gtest.h>

#include "triangleMachine.hpp"

using namespace testing;

namespace {

struct TestValue {
    std::array<std::int32_t, 3> inputs;
    TriangleType expetation;
};

std::ostream&
operator<<(std::ostream& os, const TestValue& val) {
    os << std::endl << "inputs: ";
    for (const auto& input : val.inputs) {
        os << input << ", ";
    }
    os << std::endl;

    os << "Expetation: ";
    switch (val.expetation) {
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
    }
    os << std::endl;

    return os;
}

std::vector<TestValue> weakNormalTestValues{
        {{0, 0, 0}, TriangleType::Equilateral}, {{100, -10, -10}, TriangleType::Equilateral},
};
std::vector<TestValue> weakRobustTestValues{
        {{0, 0, 0}, TriangleType::Equilateral}, {{100, -10, -10}, TriangleType::Equilateral},
};
std::vector<TestValue> strongNormalTestValues{
        {{0, 0, 0}, TriangleType::Equilateral}, {{100, -10, -10}, TriangleType::Equilateral},
};
std::vector<TestValue> strongRobustTestValues{
        {{0, 0, 0}, TriangleType::Equilateral}, {{100, -10, -10}, TriangleType::Equilateral},
};

} // namespace

struct TriangleTests : public TestWithParam<TestValue> {};

TEST_P(TriangleTests, ShouldGiveUsRightAnswer) {
    const auto& testValue = GetParam();

    const auto& expected = testValue.expetation;
    const auto& actual =
            caculateTriangleType(testValue.inputs[0], testValue.inputs[1], testValue.inputs[2]);

    ASSERT_EQ(expected, actual) << testValue;
}

INSTANTIATE_TEST_CASE_P(WeakNormalTriangleTests, TriangleTests, ValuesIn(weakNormalTestValues));
INSTANTIATE_TEST_CASE_P(WeakRobustTriangleTests, TriangleTests, ValuesIn(weakRobustTestValues));
INSTANTIATE_TEST_CASE_P(StrongNormalTriangleTests, TriangleTests, ValuesIn(strongNormalTestValues));
INSTANTIATE_TEST_CASE_P(StrongRobustTriangleTests, TriangleTests, ValuesIn(strongRobustTestValues));
