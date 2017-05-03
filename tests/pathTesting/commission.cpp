#include <gtest/gtest.h>

#include "commissionMachine.hpp"

using namespace testing;

TEST(CommissionTest, soldLockToFew) {
    const auto& result = caculateCommision(PartsSelled{0, 10, 10});
    EXPECT_EQ(result, boost::none);
}

TEST(CommissionTest, soldLockToMuch) {
    const auto& result = caculateCommision(PartsSelled{100, 10, 10});
    EXPECT_EQ(result, boost::none);
}

TEST(CommissionTest, soldStockToFew) {
    const auto& result = caculateCommision(PartsSelled{10, 0, 10});
    EXPECT_EQ(result, boost::none);
}

TEST(CommissionTest, soldStockToMuch) {
    const auto& result = caculateCommision(PartsSelled{10, 100, 10});
    EXPECT_EQ(result, boost::none);
}

TEST(CommissionTest, soldBarrelToFew) {
    const auto& result = caculateCommision(PartsSelled{10, 10, 0});
    EXPECT_EQ(result, boost::none);
}

TEST(CommissionTest, soldBarrelToMuch) {
    const auto& result = caculateCommision(PartsSelled{10, 10, 100});
    EXPECT_EQ(result, boost::none);
}

TEST(CommissionTest, profitMoreThan1800) {
    const auto& result = caculateCommision(PartsSelled{70, 1, 1});
    EXPECT_EQ(result.is_initialized(), true);
}

TEST(CommissionTest, profitMoreThan1000) {
    const auto& result = caculateCommision(PartsSelled{23, 1, 1});
    EXPECT_EQ(result.is_initialized(), true);
}

TEST(CommissionTest, profitLessThan1000) {
    const auto& result = caculateCommision(PartsSelled{1, 1, 1});
    EXPECT_EQ(result.is_initialized(), true);
}
