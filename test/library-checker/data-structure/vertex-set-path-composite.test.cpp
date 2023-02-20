#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "../../../template/template.cpp"
#include "../../../data-structure/monoid/affine.hpp"
#include "../../../data-structure/segtree/segtree.hpp"
#include "../../../graph/tree/hld.hpp"
#include "../../../modint/modint.hpp"

using mint = ModInt<MOD2>;
using AffineLeft = MonoidAffine<mint, false>;
using AffineRight = MonoidAffine<mint, true>;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<pair<mint, mint>> af(N);
    REP(i, N) {
        mint a, b;
        cin >> a >> b;
        af[i] = {a, b};
    }
    HeavyLightDecomposition hld(N);
    REP(_, N-1) {
        int u, v;
        cin >> u >> v;
        hld.add_edge(u, v);
    }
    hld.build();
    Segtree<AffineLeft> seg(N);
    Segtree<AffineRight> seg_rev(N);
    REP(i, N) {
        seg.set(hld[i], af[i]);
        seg_rev.set(hld[i], af[i]);
    }

    while(Q--) {
        int type;
        cin >> type;
        if(type == 0) {
            int p;
            mint c, d;
            cin >> p >> c >> d;
            seg.set(hld[p], make_pair(c, d));
            seg_rev.set(hld[p], make_pair(c, d));
        } else {
            int u, v;
            mint x;
            cin >> u >> v >> x;
            pair<mint, mint> res_l = AffineLeft::e(), res_r = AffineRight::e();
            auto f = [&](int l, int r) {
                res_l = AffineLeft::op(seg.prod(l, r), res_l);
            };
            auto f_rev = [&](int l, int r) {
                res_r = AffineRight::op(seg_rev.prod(l, r), res_r);
            };
            hld.path_query<decltype(f), decltype(f_rev)>(u, v, f, f_rev);
            auto [a, b] = AffineLeft::op(res_r, res_l);
            mint ans = a * x + b;
            cout << ans << '\n';
        }
    }
}