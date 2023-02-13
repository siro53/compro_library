#pragma once

#include <utility>

class BarrettReduction {
public:
    using u32 = unsigned int;
    using u64 = unsigned long long;

    explicit BarrettReduction(u32 mod)
        : m(mod), m_inv((u64)(-1) / m + 1) {}
    u32 mul(u32 a, u32 b) const {
        u64 z = (u64)a * b;
        u64 v =  (u64)(((__uint128_t)z * m_inv) >> 64);
        u32 result = (u32)(z - v * m);
        if(m <= result) result += m;
        return result;
    }
    u32 div(u32 a) const {
        u32 result = (u32)(((__uint128_t)a * m_inv) >> 64);
        return result;
    }
    std::pair<u32, u32> div_with_rem(u32 a) const {
        u64 v =  (u64)(((__uint128_t)a * m_inv) >> 64);
        u32 r = (u32)((u64)a - v * m);
        if(m <= r) r += m;
        return {v, r};
    }
private:
    u32 m;
    u64 m_inv;
};