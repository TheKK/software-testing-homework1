#include <gtest/gtest.h>

#include "commissionBoundaryTestcase.hpp"
#include "commissionMachine.hpp"
#include "commissionTestValue.hpp"

using namespace testing;

struct CommissionTest : public TestWithParam<CommissionTestValue> {};

TEST_P(CommissionTest, ShouldGiveUsRightAnswer) {
    const auto& testValue = GetParam();

    const auto& input = testValue.input;

    const auto actual = caculateCommision(input);
    const auto& expected = testValue.expetation;

    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_CASE_P(BoundaryValue, CommissionTest, ValuesIn(boundaryValueTestcase));
