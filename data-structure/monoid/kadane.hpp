#pragma once

#include <limits>
#include <algorithm>

// ref: https://hotman78.hatenablog.com/entry/2020/06/17/102519
template <typename T> struct MonoidKadane {
    struct S {
        T lmax, rmax, allmax, sum;
        S() = default;
        S(T lmax, T rmax, T allmax, T sum)
            : lmax(lmax), rmax(rmax), allmax(allmax), sum(sum) {}
    };
    using value_type = S;
    inline static S op(const S &l, const S &r) {
        const T m = std::numeric_limits<T>::lowest();
        if(l.lmax == m && l.rmax == m && l.allmax == m && l.sum == T(0)) return r;
        if(r.lmax == m && r.rmax == m && r.allmax == m && r.sum == T(0)) return l;
        T lmax = std::max(l.lmax, l.sum + r.lmax);
        T rmax = std::max(r.rmax, l.rmax + r.sum);
        T allmax = std::max({l.allmax, r.allmax, l.rmax + r.lmax});
        T sum = l.sum + r.sum;
        return S(lmax, rmax, allmax, sum);
    }
    inline static S e() {
        T m = std::numeric_limits<T>::lowest();
        return S(m, m, m, T(0));
    }
};