#pragma once

constexpr long long pow_mod(long long x, long long k, int m) {
    unsigned int mod = m;
    unsigned long long res = 1;
    unsigned long long mul = (x >= 0 ? x % mod : x % mod + mod);
    while(k) {
        if(k & 1) (res *= mul) %= m;
        (mul *= mul) %= m;
        k >>= 1;
    }
    return res;
}