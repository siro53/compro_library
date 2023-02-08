#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "../../../template/template.cpp"
#include "../../../graph/tree/lca.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    Graph<int> G(N);
    REP(i, 1, N) {
        int p;
        cin >> p;   
        G.add_undirected_edge(i, p);
    }
    LCA<int> lca(G);
    REP(_, Q) {
        int u, v;
        cin >> u >> v;
        cout << lca.getLCA(u, v) << '\n';
    }
}