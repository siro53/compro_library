#pragma once

#include <numeric>

template <typename T> struct MonoidGCD {
    using value_type = T;
    inline static T op(const T& l, const T& r) {
        return std::gcd(l, r);
    }
    inline static T e() { return T(0); }
};