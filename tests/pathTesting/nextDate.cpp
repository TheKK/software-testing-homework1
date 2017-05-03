#include <gtest/gtest.h>

#include "nextDateMachine.hpp"

using namespace testing;

TEST(NextDateTest, invalidDate) {
    const auto& result = nextDate(Date{19999, 99999, 99999});
    EXPECT_EQ(result, boost::none);
}

TEST(NextDateTest, fabruaryWithLeapYearChangeMonth) {
    const auto& result = nextDate(Date{2000, 2, 29});
    const auto& expected = Date{2000, 3, 1};

    EXPECT_EQ(*result, expected);
}

TEST(NextDateTest, fabruaryWithNonLeapYearChangeMonth) {
    const auto& result = nextDate(Date{2001, 2, 28});
    const auto& expected = Date{2001, 3, 1};

    EXPECT_EQ(*result, expected);
}

TEST(NextDateTest, fabruaryWithLeapYearNotChangeMonth) {
    const auto& result = nextDate(Date{2001, 2, 10});
    const auto& expected = Date{2001, 2, 11};

    EXPECT_EQ(*result, expected);
}

TEST(NextDateTest, fabruaryWithNonLeapYearNotChangeMonth) {
    const auto& result = nextDate(Date{2000, 2, 10});
    const auto& expected = Date{2000, 2, 11};

    EXPECT_EQ(*result, expected);
}

TEST(NextDateTest, December31WithValidNextDate) {
    const auto& result = nextDate(Date{2000, 12, 31});
    const auto& expected = Date{2001, 1, 1};

    EXPECT_EQ(*result, expected);
}

TEST(NextDateTest, December31WithInalidNextDate) {
    const auto& result = nextDate(Date{3000, 12, 31});
    EXPECT_EQ(result, boost::none);
}

TEST(NextDateTest, DecemberNot31) {
    const auto& result = nextDate(Date{2000, 12, 10});
    const auto& expected = Date{2000, 12, 11};

    EXPECT_EQ(*result, expected);
}

TEST(NextDateTest, monthWith31DaysChangeMonth) {
    const auto& result = nextDate(Date{2000, 1, 31});
    const auto& expected = Date{2000, 2, 1};

    EXPECT_EQ(*result, expected);
}

TEST(NextDateTest, monthWith31DaysNotChangeMonth) {
    const auto& result = nextDate(Date{2000, 1, 30});
    const auto& expected = Date{2000, 1, 31};

    EXPECT_EQ(*result, expected);
}

TEST(NextDateTest, monthWith30DaysChangeMonth) {
    const auto& result = nextDate(Date{2000, 4, 30});
    const auto& expected = Date{2000, 5, 1};

    EXPECT_EQ(*result, expected);
}

TEST(NextDateTest, monthWith30DaysNotChangeMonth) {
    const auto& result = nextDate(Date{2000, 4, 10});
    const auto& expected = Date{2000, 4, 11};

    EXPECT_EQ(*result, expected);
}
