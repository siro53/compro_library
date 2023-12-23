#pragma once

#include <algorithm>
#include <limits>

template <typename T, T MINUS_INF = std::numeric_limits<T>::min()> struct MonoidMax {
    using value_type = T;
    inline static T op(const T &l, const T &r) { return std::max(l, r); }
    inline static T e() { return MINUS_INF; }
};