#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"
#include "../template/template.cpp"
#include "../graph/chromatic_number.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(N, 0));
    REP(i, M) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    cout << chromatic_number(N, G) << "\n";
}