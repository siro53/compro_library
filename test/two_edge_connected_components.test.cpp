#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include "../template/template.cpp"
#include "../graph/bi_edge_connected_components.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    BECC becc(N);
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        becc.add_edge(a, b);
    }
    becc.build();
    int K = becc.size();
    vector<vector<int>> res(K);
    REP(i, N) res[becc[i]].push_back(i);
    
    cout << K << "\n";
    REP(i, K) {
        int sz = res[i].size();
        cout << sz << " ";
        REP(j, sz) cout << res[i][j] << " \n"[j == sz-1];
    }
}
