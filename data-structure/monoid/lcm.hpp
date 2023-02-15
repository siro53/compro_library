#pragma once

#include <numeric>

template <typename T> struct MonoidLCM {
    using value_type = T;
    inline static T op(const T& l, const T& r) {
        return std::lcm(l, r);
    }
    inline static T e() { return T(1); }
};