#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include "../../template/template.cpp"
#include "../../data-structure/range-BIT.hpp"

int main() {
    INT(N, Q);
    RangeBIT<ll> bit(N);
    while(Q--) {
        INT(t, l, r);
        // AOJ uses 1-based inclusive intervals.
        --l;
        if(t == 0) {
            LL(x);
            bit.add(l, r, x);
        } else {
            print(bit.sum(l, r));
        }
    }
}
