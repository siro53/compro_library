#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../template/template.cpp"
#include "../graph/scc.hpp"

int main() {
    int N, M;
    cin >> N >> M;

    SCC scc(N);
    REP(i, M) {
        int a, b; cin >> a >> b;
        scc.add_edge(a, b);
    }
    scc.build();

    vector<vector<int>> res(scc.size());
    for(int i = 0; i < N; i++) {
        res[scc[i]].emplace_back(i);
    }
    cout << scc.size() << "\n";
    for(int i = 0; i < res.size(); i++) {
        int sz = res[i].size();
        cout << sz << " ";
        for(int j = 0; j < sz; j++) {
            cout << res[i][j] << " \n"[j == sz - 1];
        }
    }
}