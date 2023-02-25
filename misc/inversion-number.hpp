#pragma once

#include "../data-structure/BIT.hpp"

template<class T>
T inversion_number(const std::vector<int>& v) {
    int N = (int)v.size();
    BIT<int> bt(N);
    T res = 0;
    for(int i = 0; i < N; i++) {
        res += i - bt.sum(v[i]+1);
        bt.add(v[i], 1);
    }
    return res;
}