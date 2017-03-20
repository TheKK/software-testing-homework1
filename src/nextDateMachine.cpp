#include "nextDateMachine.hpp"

namespace {

bool
dateIsValid(const Date& today) {
    const auto yearIsValid = (today.year >= 1 && today.year <= 3000);
    const auto monthIsValid = (today.month >= 1 && today.month <= 12);
    auto dayIsValid = false;

    switch (today.month) {
    // February
    case 2: {
        const auto isLeapYear = (today.year % 4 == 0);

        dayIsValid =
            isLeapYear ? (today.day >= 0 && today.day <= 29) : (today.day >= 0 && today.day <= 28);
    } break;
    // month with 30 days
    case 4:
    case 6:
    case 9:
    case 11:
        dayIsValid = (today.day >= 0 && today.day <= 30);
        break;
    // month with 31 days
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        dayIsValid = (today.day >= 0 && today.day <= 31);
        break;
    }

    return (yearIsValid && monthIsValid && dayIsValid);
}

} // namespace

boost::optional<Date>
nextDate(const Date& today) noexcept {
    if (!dateIsValid(today)) {
        return boost::none;
    }

    switch (today.month) {
    // February
    case 2: {
        const auto isLeapYear = (today.year % 4 == 0);
        const auto dayOfFeb = isLeapYear ? 29 : 28;

        if (today.day + 1 > dayOfFeb) {
            return Date{today.year, 3, 1};

        } else {
            return Date{today.year, 2, today.day + 1};
        }
    } break;

    // December
    case 12:
        if (today.day + 1 > 31) {
            const auto nextDate = Date{today.year + 1, 1, 1};

            if (dateIsValid(nextDate)) {
                return nextDate;

            } else {
                return boost::none;
            }
        }
        break;

    // month with 30 days
    case 4:
    case 6:
    case 9:
    case 11:
        if (today.day + 1 > 30) {
            return Date{today.year, today.month + 1, 1};

        } else {
            return Date{today.year, today.month, today.day + 1};
        }
        break;

    // month with 31 days
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        if (today.day + 1 > 31) {
            return Date{today.year, today.month + 1, 1};

        } else {
            return Date{today.year, today.month, today.day + 1};
        }
        break;
    }

    return boost::none;
}

std::ostream&
operator<<(std::ostream& os, const Date& val) {
    os << val.year << ", " << val.month << ", " << val.day;

    return os;
}
