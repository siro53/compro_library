#pragma once

#include <algorithm>
#include <vector>

template<typename T>
std::vector<T> divisor(T n) {
    static_assert(std::is_integral<T>::value == true, "type 'T' should be integer.");
    std::vector<T> ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    std::sort(ret.begin(), ret.end());
    return ret;
}