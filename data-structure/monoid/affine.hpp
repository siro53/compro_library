#pragma once

#include <utility>

template <typename T, bool rev = false> struct MonoidAffine {
    using S = std::pair<T, T>;
    using value_type = S;
    inline static S op(const S &l, const S &r) {
        if(rev) return S(r.first * l.first, r.first * l.second + r.second);
        return S(l.first * r.first, l.first * r.second + l.second);
    }
    inline static S e() { return S(T(1), T(0)); }
};