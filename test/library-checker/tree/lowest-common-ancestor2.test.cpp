#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../../template/template.cpp"
#include "../../../graph/tree/hld.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    HeavyLightDecomposition hld(N);
    REP(i, 1, N) {
        int p;
        cin >> p;   
        hld.add_edge(i, p);
    }
    hld.build();
    REP(_, Q) {
        int u, v;
        cin >> u >> v;
        cout << hld.lca(u, v) << '\n';
    }
}