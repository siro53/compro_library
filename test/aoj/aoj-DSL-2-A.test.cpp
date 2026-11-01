#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include "../../template/template.cpp"
#include "../../data-structure/monoid/min.hpp"
#include "../../data-structure/segtree/segtree.hpp"

int main() {
    INT(N, Q);
    Segtree<MonoidMin<int>> seg(N);
    while(Q--) {
        INT(t, x, y);
        if(t == 0) seg.set(x, y);
        else print(seg.prod(x, y + 1));
    }
}
