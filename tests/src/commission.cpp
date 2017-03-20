#include <gtest/gtest.h>

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
