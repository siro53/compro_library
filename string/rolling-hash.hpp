#pragma once

#include <algorithm>
#include <cassert>
#include <random>
#include <string>
#include <vector>

class RollingHash {
public:
    using u64 = unsigned long long;
    using u128 = __uint128_t;

    explicit RollingHash(const std::vector<int>& v, u64 base): base(base) {
        int n = (int)v.size();
        hashed.assign(n + 1, 0);
        power.assign(n + 1, 0);
        power[0] = 1;
        for(int i = 0; i < n; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = add(mul(hashed[i], base), v[i]);
        }
    }
    explicit RollingHash(const std::string& s, u64 base): base(base) {
        std::vector<int> v(s.size());
        for(int i = 0; i < (int)s.size(); i++) v[i] = s[i];
        RollingHash(v, base);
    }
    static inline u64 genBase() {
        std::random_device seed_gen;
        std::mt19937_64 engine(seed_gen());
        std::uniform_int_distribution<u64> rand(2, mod - 2);
        return rand(engine);
    }
    u64 get(int l, int r) {
        return add(hashed[r], mod - mul(hashed[l], power[r - l]));
    }
    u64 connect(u64 h1, u64 h2, int h2len) {
        return add(mul(h1, power[h2len]), h2);
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

private:
    static const u64 mod = (1ULL << 61) - 1;
    const u64 base;
    std::vector<u64> hashed, power;

    inline u64 add(u64 a, u64 b) const {
        if((a += b) >= mod) a -= mod;
        return a;
    }
    inline u64 mul(u64 a, u64 b) const {
        u128 t = (u128)a * b;
        u64 na = t >> 61;
        u64 nb = t & mod;
        if((na += nb) >= mod) na -= mod;
        return na;
    }
};