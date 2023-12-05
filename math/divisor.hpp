#pragma once

#include <algorithm>
#include <type_traits>
#include <vector>

template <typename T, std::enable_if_t<std::is_integral<T>::value, int> = 0>
std::vector<T> divisor(T n) {
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