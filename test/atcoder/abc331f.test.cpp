#define PROBLEM "https://atcoder.jp/contests/abc331/tasks/abc331_f"
#include "../../template/template.cpp"
#include "../../data-structure/segtree/segtree.hpp"
#include "../../data-structure/monoid/rolling_hash.hpp"

using Monoid = MonoidRollingHash<1000010>;
using segtree = Segtree<Monoid>;

int main() {
    INT(N, Q);
    STRING(s);
    segtree seg(N), seg_r(N);
    REP(i, N) {
        seg.set(i, Monoid::S(s[i], 1));
        seg_r.set(i, Monoid::S(s[N-1-i], 1));
    }
    REP(_, Q) {
        INT(t);
        if(t == 1) {
            INT(x);
            CHAR(c);
            x--;
            seg.set(x, Monoid::S(c, 1));
            seg_r.set(N - 1 - x, Monoid::S(c, 1));
        } else {
            INT(L, R);
            L--;
            if(seg.prod(L, R).h == seg_r.prod(N - R, N - L).h) {
                print("Yes");
            } else {
                print("No");
            }
        }
    }
}