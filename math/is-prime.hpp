#pragma once

#include <type_traits>

template <class T = int> bool is_prime(T n) {
    static_assert(std::is_integral<T>::value == true, "type 'T' should be integer.");
    if(n <= 1) return false;
    for(T i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}