#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/range-BIT.hpp"

int main() {
    mt19937 rng(20261101);
    RangeBIT<ll> assigned;
    assigned = RangeBIT<ll>(0);
    assert(assigned.sum(0) == 0 && assigned.sum(0, 0) == 0);
    for(int n : {1, 2, 3, 8, 31}) {
        RangeBIT<ll> bit(n);
        vector<ll> values(n);
        for(int step = 0; step < 300; ++step) {
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if(l > r) swap(l, r);
            ll delta = ll(rng() % 20000000001ULL) - 10000000000LL;
            if(step % 2 == 0) {
                bit.add(l, r, delta);
                for(int i = l; i < r; ++i) values[i] += delta;
            } else {
                int p = rng() % n;
                bit.add(p, delta);
                values[p] += delta;
            }
            for(int a = 0; a <= n; ++a) {
                assert(bit.sum(a) == accumulate(values.begin(), values.begin() + a, 0LL));
                ll expected = 0;
                for(int b = a; b <= n; ++b) {
                    assert(bit.sum(a, b) == expected);
                    if(b < n) expected += values[b];
                }
            }
        }
    }
    INT(a, b);
    print(a + b);
}
