#pragma once

constexpr long long pow_mod(long long x, long long k, long long m) {
    long long res = 1;
    long long mul = (x >= 0 ? x % m : x % m + m);
    while(k) {
        if(k & 1) res = res * mul % m;
        mul = mul * mul % m;
        k >>= 1;
    }
    return res;
}