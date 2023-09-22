#pragma once

#include <limits>
#include <algorithm>

template <typename T> struct MonoidKadane {
    struct S {
        T lmax, rmax, allmax, sum;
        S() = default;
        S(T lmax, T rmax, T allmax, T sum)
            : lmax(lmax), rmax(rmax), allmax(allmax), sum(sum) {}
    };
    using value_type = S;
    inline static S op(const S &l, const S &r) {
        T lmax = std::max(l.lmax, l.sum + r.lmax);
        T rmax = std::max(r.rmax, l.rmax + r.sum);
        T allmax = std::max({l.allmax, r.allmax, l.rmax + r.lmax});
        T sum = l.sum + r.sum;
        return S(lmax, rmax, allmax, sum);
    }
    inline static S e() {
        T m = std::numeric_limits<T>::min();
        return S(m, m, m, T(0));
    }
};