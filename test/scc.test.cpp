#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../template/template.cpp"
#include "../graph/scc.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b);
    }
    SCC scc(G);
    vector<vector<int>> res(scc.cnt);
    for(int i = 0; i < n; i++) {
        res[scc.comp[i]].emplace_back(i);
    }
    cout << scc.cnt << "\n";
    for(int i = 0; i < res.size(); i++) {
        int sz = res[i].size();
        cout << sz << " ";
        for(int j = 0; j < sz; j++) {
            cout << res[i][j] << " \n"[j == sz - 1];
        }
    }
}