#pragma once

#include <algorithm>
#include <cassert>
#include <random>
#include <string>
#include <vector>

#include "../modint/modint_2_61.hpp"

struct RollingHash {
    using u64 = unsigned long long;
    using mint = ModInt_2_61;
    static constexpr u64 mod = (1ULL << 61) - 1;
    const u64 base;
    std::vector<mint> hashed, power;

    explicit RollingHash(const std::vector<int> &v, u64 base) : base(base) {
        int n = (int)v.size();
        hashed.assign(n + 1, 0);
        power.assign(n + 1, 0);
        power[0] = 1;
        for(int i = 0; i < n; i++) {
            power[i + 1] = power[i] * base;
            hashed[i + 1] = (hashed[i] * base) + v[i];
        }
    }
    explicit RollingHash(const std::string &s, u64 base) : base(base) {
        int n = (int)s.size();
        hashed.assign(n + 1, 0);
        power.assign(n + 1, 0);
        power[0] = 1;
        for(int i = 0; i < n; i++) {
            power[i + 1] = power[i] * base;
            hashed[i + 1] = (hashed[i] * base) + s[i];
        }
    }
    static inline u64 gen_base() {
        std::random_device seed_gen;
        std::mt19937_64 engine(seed_gen());
        std::uniform_int_distribution<u64> rand(2, mod - 2);
        return rand(engine);
    }
    mint get(int l, int r) {
        assert(0 <= l);
        assert(l <= r);
        assert(r < (int)power.size());
        return (hashed[r] - (hashed[l] * power[r - l]));
    }
    mint connect(mint h1, mint h2, int h2len) {
        return (h1 * power[h2len] + h2);
    }
    int get_lcp(RollingHash &b, int l1, int r1, int l2, int r2) {
        assert(mod == b.mod);
        int len = std::min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while(high - low > 1) {
            int mid = (low + high) >> 1;
            if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};