#include "nextDateMachine.hpp"

boost::optional<Date>
nextDate(const Date& today) noexcept {
    return boost::none;
}

std::ostream&
operator<<(std::ostream& os, const Date& val) {
    os << val.year << ", " << val.month << ", " << val.day;

    return os;
}
