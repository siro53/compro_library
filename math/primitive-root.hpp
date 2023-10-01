#pragma once

#include "pow_mod.hpp"

constexpr int primitive_root(int p) {
    if(p == 2) return 1;
    if(p == 998244353) return 3;
    int primes[31] = {};
    int sz = 0, t = p - 1;
    for(int i = 2; i * i <= t; i++) {
        if(t % i == 0) {
            primes[sz++] = i;
            while(t % i == 0) t /= i;
        }
    }
    if(t > 1) primes[sz++] = t;
    for(int g = 2;;g++) {
        bool f = true;
        for(int i = 0; i < sz; i++) {
            if(pow_mod(g, (p - 1) / primes[i], p) == 1) {
                f = false;
                break;
            }
        }   
        if(f) return g;
    }
}