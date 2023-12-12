#pragma once

#include <array>
#include <utility>

#include "../../string/rolling-hash.hpp"

template <int N> struct MonoidRollingHash {
  public:
    using mint = ModInt_2_61;
    struct S {
        mint h;
        int len;
        S() {}
        S(mint h, int len) : h(h), len(len) {}
    };
    using value_type = S;

    static inline S op(const S &a, const S &b) {
        static auto [base, powers] = gen();
        mint h = a.h + b.h * powers[a.len];
        int len = a.len + b.len;
        return S(h, len);
    }
    static inline S e() { return S(0, 0); }

  private:
    static std::pair<mint, std::array<mint, N>> gen() {
        mint base = RollingHash::gen_base();
        std::array<mint, N> powers;
        powers[0] = 1;
        for(int i = 1; i < N; i++) powers[i] = powers[i - 1] * base;
        return std::make_pair(base, powers);
    }
};