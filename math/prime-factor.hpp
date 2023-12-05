#pragma once

#include <map>
#include <type_traits>

template <class T, std::enable_if_t<std::is_integral<T>::value, int> = 0>
std::map<T, int> prime_factor(T n) {
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