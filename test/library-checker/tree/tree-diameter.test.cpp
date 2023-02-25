#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "../../../template/template.cpp"
#include "../../../graph/tree/diameter.hpp"

int main() {
    int N;
    cin >> N;
    Graph<ll> G(N);
    REP(_, N-1) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        G.add_undirected_edge(a, b, c);
    }
    auto [diam, path] = get_diameter(G);
    cout << diam << ' ' << SZ(path) << '\n';
    REP(i, SZ(path)) cout << path[i] << " \n"[i == SZ(path) - 1];
}