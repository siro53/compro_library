#pragma once

#include <algorithm>
#include <limits>
#include <utility>

template <typename T> struct MonoidMinWithIndex {
    using S = std::pair<T, int>;
    using value_type = S;
    inline static S op(const S &l, const S &r) { return std::min(l, r); }
    inline static S e() {
        return std::make_pair(std::numeric_limits<T>::max(), -1);
    }
};