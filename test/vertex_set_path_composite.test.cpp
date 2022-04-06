#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "../template/template.cpp"

#include "../math/modint.hpp"
using mint = ModInt<MOD2>;
#include "../graph/hld.hpp"
#include "../data_structure/segtree/segtree.hpp"

struct S {
    mint a, b;
    S() {}
    S(mint a, mint b): a(a), b(b) {}
    inline mint eval(mint x) { return a*x + b; }
};
S op(S x, S y) { // fx(fy())
    return S(x.a * y.a, x.a * y.b + x.b);
}
S op_rev(S x, S y) { // fy(fx())
    return S(y.a * x.a, y.a * x.b + y.b);
}
S e() {
    return S(1, 0);
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> fs(N);
    for(auto& [a, b]: fs) cin >> a >> b;
    HeavyLightDecomposition hld(N);
    REP(_, N-1) {
        int u, v;
        cin >> u >> v;
        hld.add_edge(u, v);
    }
    hld.build();
    segtree<S, op, e> seg(N);
    segtree<S, op_rev, e> seg_rev(N);
    REP(i, N) {
        auto [a, b] = fs[i];
        int id = hld[i];
        seg.set(id, S(a, b));
        seg_rev.set(id, S(a, b));
    }
    REP(_, Q) {
        int t;
        cin >> t;
        if(t == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            int id = hld[p];
            seg.set(id, S(c, d));
            seg_rev.set(id, S(c, d));
        } else {
            int u, v, x;
            cin >> u >> v >> x;
            int LCA = hld.lca(u, v);
            S resl = e(), resr = e();
            for(const auto& [l, r] : hld.path(u, LCA)) {
                resl = op(seg.prod(l, r), resl);
            }
            for(const auto& [l, r] : hld.path_edge(LCA, v)) {
                resr = op_rev(seg_rev.prod(l, r), resr);
            }
            auto res = op(resr, resl);
            cout << res.eval(x) << '\n'; 
        }
    }
}