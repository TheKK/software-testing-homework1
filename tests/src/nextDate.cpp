#include <gtest/gtest.h>

#include "nextDateBoundaryTestcase.hpp"
#include "nextDateDecisionTableTestcase.hpp"
#include "nextDateEquvalenceClssTestcase.hpp"
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
INSTANTIATE_TEST_CASE_P(EquivalenceClass, NextDateTest, ValuesIn(equivalenceClassTestcase));
INSTANTIATE_TEST_CASE_P(DecisionTable, NextDateTest, ValuesIn(decisionTableValueTestcase));
