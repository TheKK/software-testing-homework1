#include <gtest/gtest.h>

#include "commissionBoundaryTestcase.hpp"
#include "commissionDecisionTableTestcase.hpp"
#include "commissionMachine.hpp"
#include "commissionTestValue.hpp"

using namespace testing;

struct CommissionTest : public TestWithParam<CommissionTestValue> {};

TEST_P(CommissionTest, ShouldGiveUsRightAnswer) {
    const auto& testValue = GetParam();

    const auto& input = testValue.input;

    const auto actual = caculateCommision(input);
    const auto& expected = testValue.expetation;

    // All be valid result or invalid result
    ASSERT_EQ(!actual, !expected);

    if (actual && expected) {
        EXPECT_FLOAT_EQ(*expected, *actual);
    }
}

INSTANTIATE_TEST_CASE_P(BoundaryValue, CommissionTest, ValuesIn(boundaryValueTestcase));
INSTANTIATE_TEST_CASE_P(DecisionTable, CommissionTest, ValuesIn(decisionTableValueTestcase));
