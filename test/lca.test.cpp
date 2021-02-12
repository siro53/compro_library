#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../template/template.cpp"
#include "../graph/lca.hpp"

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[i].emplace_back(p);
        g[p].emplace_back(i);
    }

    LCA lca(g, 0);

    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << lca.get_lca(u, v) << endl;
    }
}