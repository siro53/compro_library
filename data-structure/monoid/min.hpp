#pragma once

#include <algorithm>
#include <limits>

template <typename T, T INF = std::numeric_limits<T>::max()> struct MonoidMin {
    using value_type = T;
    inline static T op(const T &l, const T &r) { return std::min(l, r); }
    inline static T e() { return INF; }
};