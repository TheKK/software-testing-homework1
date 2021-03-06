#pragma once

#include <vector>

#include "nextDateTestValue.hpp"

// Here stores all kinds of equivalence class testcase.
//
//  m1 = { month has 30 days }
//  m2 = { month has 31 days }
//  m3 = { February }
//  mx+ = { + invalid month }
//  mx- = { - invalid month }
//
//  d1 = { 1 <= day <= 28 }
//  d2 = { day == 29 }
//  d3 = { day == 30 }
//  d4 = { day == 31 }
//  md+ = { + invalid day }
//  md- = { - invalid day }
//
//  y1 = { leap year }
//  y2 = { common year }
//  yx+ = { + invalid year }
//  yx- = { -invalid year }
//
const std::vector<NextDateTestValue> equivalenceClassTestcase{
    // Weak normal
    {{2012, 4, 10}, Date{2012, 4, 11}},
    {{2012, 1, 29}, Date{2012, 1, 30}},
    {{2012, 2, 30}, boost::none},
    {{2011, 2, 30}, boost::none},

    // Strong normal
    {{2012, 4, 10}, Date{2012, 4, 11}},
    {{2012, 4, 29}, Date{2012, 4, 30}},
    {{2012, 4, 30}, Date{2012, 5, 1}},
    {{2012, 4, 31}, boost::none},
    {{2012, 1, 10}, Date{2012, 1, 11}},
    {{2012, 1, 29}, Date{2012, 1, 30}},
    {{2012, 1, 30}, Date{2012, 1, 31}},
    {{2012, 1, 31}, Date{2012, 2, 1}},
    {{2012, 2, 10}, Date{2012, 2, 11}},
    {{2012, 2, 29}, Date{2012, 3, 1}},
    {{2012, 2, 30}, boost::none},
    {{2012, 2, 31}, boost::none},

    // Weak robust
    {{2012, 19, 40}, boost::none},
    {{2011, 0, 0}, boost::none},
    {{0, 4, 0}, boost::none},
    {{9999, 1, 40}, boost::none},
    {{9999, 2, 0}, boost::none},
    {{0, 0, 10}, boost::none},
    {{0, 0, 29}, boost::none},
    {{0, 0, 30}, boost::none},
    {{0, 0, 31}, boost::none},
    {{9999, 19, 40}, boost::none},
    {{9999, 0, 0}, boost::none},
    {{0, 0, 0}, boost::none},

    // Strong robus
    {{0, 0, 0}, boost::none},
    {{0, 0, 10}, boost::none},
    {{0, 0, 29}, boost::none},
    {{0, 0, 30}, boost::none},
    {{0, 0, 31}, boost::none},
    {{0, 0, 40}, boost::none},
    {{0, 4, 0}, boost::none},
    {{0, 4, 10}, boost::none},
    {{0, 4, 29}, boost::none},
    {{0, 4, 30}, boost::none},
    {{0, 4, 31}, boost::none},
    {{0, 4, 40}, boost::none},
    {{0, 1, 0}, boost::none},
    {{0, 1, 10}, boost::none},
    {{0, 1, 29}, boost::none},
    {{0, 1, 30}, boost::none},
    {{0, 1, 31}, boost::none},
    {{0, 1, 40}, boost::none},
    {{0, 2, 0}, boost::none},
    {{0, 2, 10}, boost::none},
    {{0, 2, 29}, boost::none},
    {{0, 2, 30}, boost::none},
    {{0, 2, 31}, boost::none},
    {{0, 2, 40}, boost::none},
    {{0, 19, 0}, boost::none},
    {{0, 19, 10}, boost::none},
    {{0, 19, 29}, boost::none},
    {{0, 19, 30}, boost::none},
    {{0, 19, 31}, boost::none},
    {{0, 19, 40}, boost::none},
    {{2012, 0, 0}, boost::none},
    {{2012, 0, 10}, boost::none},
    {{2012, 0, 29}, boost::none},
    {{2012, 0, 30}, boost::none},
    {{2012, 0, 31}, boost::none},
    {{2012, 0, 40}, boost::none},
    {{2012, 14, 0}, boost::none},
    {{2012, 14, 10}, boost::none},
    {{2012, 14, 29}, boost::none},
    {{2012, 14, 30}, boost::none},
    {{2012, 14, 31}, boost::none},
    {{2012, 14, 40}, boost::none},
    {{2012, 19, 0}, boost::none},
    {{2012, 19, 10}, boost::none},
    {{2012, 19, 29}, boost::none},
    {{2012, 19, 30}, boost::none},
    {{2012, 19, 31}, boost::none},
    {{2012, 19, 40}, boost::none},
    {{9999, 0, 0}, boost::none},
    {{9999, 0, 10}, boost::none},
    {{9999, 0, 29}, boost::none},
    {{9999, 0, 30}, boost::none},
    {{9999, 0, 31}, boost::none},
    {{9999, 0, 40}, boost::none},
    {{9999, 4, 0}, boost::none},
    {{9999, 4, 10}, boost::none},
    {{9999, 4, 29}, boost::none},
    {{9999, 4, 30}, boost::none},
    {{9999, 4, 31}, boost::none},
    {{9999, 4, 40}, boost::none},
    {{9999, 1, 0}, boost::none},
    {{9999, 1, 10}, boost::none},
    {{9999, 1, 29}, boost::none},
    {{9999, 1, 30}, boost::none},
    {{9999, 1, 31}, boost::none},
    {{9999, 1, 40}, boost::none},
    {{9999, 2, 0}, boost::none},
    {{9999, 2, 10}, boost::none},
    {{9999, 2, 29}, boost::none},
    {{9999, 2, 30}, boost::none},
    {{9999, 2, 31}, boost::none},
    {{9999, 2, 40}, boost::none},
    {{9999, 19, 0}, boost::none},
    {{9999, 19, 10}, boost::none},
    {{9999, 19, 29}, boost::none},
    {{9999, 19, 30}, boost::none},
    {{9999, 19, 31}, boost::none},
    {{9999, 19, 40}, boost::none},
};
