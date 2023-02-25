#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../../../template/template.cpp"
#include "../../../modint/modint.hpp"
#include "../../../data-structure/monoid/affine.hpp"
#include "../../../data-structure/segtree/segtree.hpp"

using mint = ModInt<MOD2>;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<pair<mint, mint>> v(N);
    REP(i, N) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    Segtree<MonoidAffine<mint>> seg(v);
    while(Q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            seg.set(p, pair<mint, mint>(c, d));
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            auto [a, b] = seg.prod(l, r);
            cout << (a * x + b) << '\n';
        }
    }
}