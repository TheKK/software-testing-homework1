#pragma once

#include <vector>

#include "nextDateTestValue.hpp"

// Here stores all kinds of testcase from decision table.
//
// Please check out `draft.org` for detail decision table.
//
const std::vector<NextDateTestValue> decisionTableValueTestcase{
    // February
    {{999, 2, 10}, Date{999, 2, 11}},

    {{2001, 2, 28}, Date{2001, 3, 1}},
    {{2000, 2, 28}, Date{2000, 2, 29}},

    {{2001, 2, 29}, boost::none},
    {{2000, 2, 29}, Date{2000, 3, 1}},

    {{999, 2, 30}, boost::none},
    {{999, 2, 31}, boost::none},

    // Month with 30 days
    {{999, 4, 10}, Date{999, 4, 11}},
    {{999, 4, 28}, Date{999, 4, 29}},
    {{999, 4, 29}, Date{999, 4, 30}},
    {{999, 4, 30}, Date{999, 5, 1}},
    {{999, 4, 31}, boost::none},

    // Month with 31 days
    {{999, 1, 10}, Date{999, 1, 11}},
    {{999, 1, 28}, Date{999, 1, 29}},
    {{999, 1, 29}, Date{999, 1, 30}},
    {{999, 1, 30}, Date{999, 1, 31}},
    {{999, 1, 31}, Date{999, 2, 1}},

    // December
    {{999, 12, 10}, Date{999, 12, 11}},
    {{999, 12, 28}, Date{999, 12, 29}},
    {{999, 12, 29}, Date{999, 12, 30}},
    {{999, 12, 30}, Date{999, 12, 31}},
    {{999, 12, 31}, Date{1000, 1, 1}},
};
