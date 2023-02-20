#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "../../../template/template.cpp"
#include "../../../data-structure/monoid/add.hpp"
#include "../../../data-structure/segtree/segtree.hpp"
#include "../../../graph/tree/hld.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    REP(i, N) cin >> a[i];
    HeavyLightDecomposition hld(N);
    REP(i, 1, N) {
        int p;
        cin >> p;
        hld.add_edge(p, i);
    }
    hld.build();
    Segtree<MonoidAdd<ll>> seg(N);
    REP(i, N) seg.set(hld[i], a[i]);

    REP(_, Q) {
        int type;
        cin >> type;
        if(type == 0) {
            int u;
            ll x;
            cin >> u >> x;
            seg.set(hld[u], seg.get(hld[u]) + x);
        } else {
            int u;
            cin >> u;
            ll ans = 0;
            auto f = [&](int l, int r) -> void {
                ans += seg.prod(l, r);
            };
            hld.subtree_query<decltype(f)>(u, f);
            cout << ans << '\n';
        }
    }
}