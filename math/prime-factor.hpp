#pragma once

#include <map>

template <typename T = int> std::map<T, int> prime_factor(T n) {
    static_assert(std::is_integral<T>::value == true, "type 'T' should be integer.");
    std::map<T, int> ret;
    for(T i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            int cnt = 0;
            while(n % i == 0) {
                n /= i;
                cnt++;
            }
            ret[i] = cnt;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}