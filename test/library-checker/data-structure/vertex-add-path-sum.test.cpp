#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
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
    REP(_, N-1) {
        int u, v;
        cin >> u >> v;
        hld.add_edge(u, v);
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
            int u, v;
            cin >> u >> v;
            ll ans = 0;
            auto f = [&](int l, int r) -> void {
                ans += seg.prod(l, r);
            };
            hld.path_query<decltype(f)>(u, v, f);
            cout << ans << '\n';
        }
    }
}