#pragma once

#include <ostream>

#include <boost/optional.hpp>

struct Date {
    int year, month, day;

    bool
    operator==(const Date& rhs) const {
        return this->year == rhs.year && this->month == rhs.month && this->day == rhs.day;
    }
};

std::ostream& operator<<(std::ostream& os, const Date& val);

boost::optional<Date> nextDate(const Date& today) noexcept;
