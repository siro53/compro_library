#pragma once

#include <utility>

class BarrettReduction {
public:
    BarrettReduction(): BarrettReduction(1) {}
    BarrettReduction(unsigned int m)
        : m(m), m_inv((unsigned long long)(-1) / m + 1) {}
    unsigned int mul(unsigned int a, unsigned int b) const {
        unsigned long long z = (unsigned long long)a * b;
        unsigned long long v =  (unsigned long long)(((__uint128_t)z * m_inv) >> 64);
        unsigned int result = (unsigned int)(z - v * m);
        if(m <= result) result += m;
        return result;
    }
    unsigned int quo(unsigned int a) const {
        unsigned int result = (unsigned int)(((__uint128_t)a * m_inv) >> 64);
        return result;
    }
    unsigned int rem(unsigned long long a) const {
        unsigned long long v = (unsigned long long)(((__uint128_t)a * m_inv) >> 64);
        unsigned int result = (unsigned int)(a - v * m);
        if(m <= result) result += m;
        return result;
    }
    std::pair<unsigned int, unsigned int> quorem(unsigned int a) const {
        unsigned long long v =  (unsigned long long)(((__uint128_t)a * m_inv) >> 64);
        unsigned int r = (unsigned int)((unsigned long long)a - v * m);
        if(m <= r) r += m;
        return {v, r};
    }
private:
    unsigned int m;
    unsigned long long m_inv;
};