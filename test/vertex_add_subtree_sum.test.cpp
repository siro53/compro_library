#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "../template/template.cpp"

#include "../graph/hld.hpp"
#include "../data_structure/segtree/segtree.hpp"

ll op(ll a, ll b) { return a+b; }
ll e() { return 0; }

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
    vector<ll> init(N);
    REP(i, N) init[hld[i]] = a[i];
    segtree<ll, op, e> seg(init);
    REP(_, Q) {
        int t;
        cin >> t;
        if(t == 0) {
            int u; ll x;
            cin >> u >> x;
            seg.set(hld[u], seg.get(hld[u]) + x);
        } else {
            int u;
            cin >> u;
            const auto& [l, r] = hld.subtree(u);
            cout << seg.prod(l, r) << '\n';
        }
    }
}