#pragma once

#include <utility>

template <typename T> struct MonoidAffine {
    using S = std::pair<T, T>;
    using value_type = S;
    inline static S op(const S &l, const S &r) {
        return S(l.first * r.first, l.second * r.first + r.second);
    }
    inline static S e() { return S(T(1), T(0)); }
};