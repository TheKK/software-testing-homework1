#pragma once

#include <ostream>

#include <boost/optional.hpp>

struct Date {
    int year, month, day;
};

std::ostream& operator<<(std::ostream& os, const Date& val);

boost::optional<Date> nextDate(const Date& today) noexcept;
