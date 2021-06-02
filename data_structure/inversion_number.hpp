#include "BIT.hpp"

// vは {0, 1, ... , N-1} からなる重複を許した数列
// この数列の転倒数を返す
template<class T>
T inversion_number(const vector<int>& v) {
    int N = (int)v.size();
    BIT<int> bt(N);
    T res = 0;
    REP(i, N) {
        res += i - bt.sum(v[i]+1);
        bt.add(v[i], 1);
    }
    return res;
}