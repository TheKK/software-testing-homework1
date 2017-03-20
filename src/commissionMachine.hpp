#pragma once

#include <boost/optional.hpp>

struct PartsSelled final {
    std::uint8_t lockNum;
    std::uint8_t stockNum;
    std::uint8_t barrelNum;
};
std::ostream& operator<<(std::ostream& os, const PartsSelled& val);

boost::optional<double> caculateCommision(PartsSelled selled) noexcept;
