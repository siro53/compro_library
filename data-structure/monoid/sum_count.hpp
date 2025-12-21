#pragma once

template <typename sum_t, typename count_t> struct MonoidSumCount {
    struct S {
        sum_t sum;
        count_t cnt;
        S() = default;
        S(sum_t sum, count_t cnt): sum(sum), cnt(cnt) {}
    };
    using value_type = S;
    inline static S op(const S& l, const S& r) {
        return S(l.sum + r.sum, l.cnt + r.cnt);
    }
    inline static S e() { return S(sum_t(0), count_t(0)); }
};