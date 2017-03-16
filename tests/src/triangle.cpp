#include <array>
#include <iostream>
#include <tuple>
#include <type_traits>
#include <vector>

#include <gtest/gtest.h>

#include "triangleBoundaryTestcase.hpp"
#include "triangleEquivalenceClassTestcass.hpp"
#include "triangleTestValue.hpp"

#include "triangleMachine.hpp"

using namespace testing;

namespace {

std::vector<TriangleTestValue> strongNormalTestValues{
    {{0, 0, 0}, TriangleType::Equilateral},
    {{100, -10, -10}, TriangleType::Equilateral},
    {{100, -10, -10}, TriangleType::Equilateral},
};
std::vector<TriangleTestValue> strongRobustTestValues{
    {{0, 0, 0}, TriangleType::Equilateral},
    {{100, -10, -10}, TriangleType::Equilateral},
    {{100, -10, -10}, TriangleType::Equilateral},
};

} // namespace

struct TriangleTests : public TestWithParam<TriangleTestValue> {};

TEST_P(TriangleTests, ShouldGiveUsRightAnswer) {
    const auto& testValue = GetParam();

    const auto& expected = testValue.expetation;
    const auto& actualVec = std::vector<TriangleType>{
        caculateTriangleType(testValue.inputs[0], testValue.inputs[1], testValue.inputs[2]),
        caculateTriangleType(testValue.inputs[2], testValue.inputs[0], testValue.inputs[1]),
        caculateTriangleType(testValue.inputs[1], testValue.inputs[2], testValue.inputs[0]),

        caculateTriangleType(testValue.inputs[2], testValue.inputs[1], testValue.inputs[0]),
        caculateTriangleType(testValue.inputs[1], testValue.inputs[0], testValue.inputs[2]),
        caculateTriangleType(testValue.inputs[0], testValue.inputs[2], testValue.inputs[1]),
    };

    for (const auto& actual : actualVec) {
        EXPECT_EQ(expected, actual);
    }
}

INSTANTIATE_TEST_CASE_P(BoundaryValue, TriangleTests, ValuesIn(boundaryValueTestcase));
INSTANTIATE_TEST_CASE_P(EquivalenceClass, TriangleTests, ValuesIn(equivalenceClassTestcase));
INSTANTIATE_TEST_CASE_P(StrongNormalTriangleTests, TriangleTests, ValuesIn(strongNormalTestValues));
INSTANTIATE_TEST_CASE_P(StrongRobustTriangleTests, TriangleTests, ValuesIn(strongRobustTestValues));
