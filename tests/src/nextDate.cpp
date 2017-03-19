#include <gtest/gtest.h>

#include "nextDateBoundaryTestcase.hpp"
#include "nextDateMachine.hpp"
#include "nextDateTestValue.hpp"

using namespace testing;

struct NextDateTest : public TestWithParam<NextDateTestValue> {};

TEST_P(NextDateTest, ShouldGiveUsRightAnswer) {
    const auto& testValue = GetParam();

    const auto& input = testValue.input;

    const auto actual = nextDate(input);
    const auto& expected = testValue.expetation;

    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_CASE_P(BoundaryValue, NextDateTest, ValuesIn(boundaryValueTestcase));