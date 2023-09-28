#pragma once

#include <array>

#include "pow_mod.hpp"

/*
ref: Fast Primality Testing for Integers That Fit into a Machine Word
Michal Foriˇsek and Jakub Janˇcina
*/

constexpr bool is_prime(int n) {
    if(n <= 1) return false;
    if(n == 2 or n == 7 or n == 61) return true;
    if((n & 1) == 0) return false;
    long long d = n - 1;
    while((d & 1) == 0) d >>= 1;
    constexpr std::array<int, 3> bases = {2, 7, 61};
    for(int a : bases) {
        long long t = d;
        long long y = pow_mod(a, t, n);
        while(t != n - 1 && y != 1 && y != n - 1) {
            (y *= y) %= n;
            t <<= 1;
        }
        if(y != n - 1 && (t & 1) == 0) return false;
    }
    return true;
}

constexpr bool is_prime(long long n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if((n & 1) == 0) return false;
    long long d = n - 1;
    while((d & 1) == 0) d >>= 1;
    constexpr std::array<long long, 7> bases = {
        2, 325, 9375, 28178, 450775, 9780504, 1795265022
    };
    for(long long a : bases) {
        a %= n;
        if(a == 0) continue;
        long long t = d;
        long long y = pow_mod(a, t, n);
        while(t != n - 1 && y != 1 && y != n - 1) {
            y = (__int128_t)y * y % n;
            t <<= 1;
        }
        if(y != n - 1 && (t & 1) == 0) return false;
    }
    return true;
}