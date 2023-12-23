#pragma once

#include <algorithm>
#include <limits>
#include <utility>

template <typename T, T MINUS_INF = std::numeric_limits<T>::min()> struct MonoidMaxWithIndex {
    using S = std::pair<T, int>;
    using value_type = S;
    inline static S op(const S &l, const S &r) { return std::max(l, r); }
    inline static S e() {
        return std::make_pair(MINUS_INF, -1);
    }
};