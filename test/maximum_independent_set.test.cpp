#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"
#include "../template/template.cpp"
#include "../graph/maximum_independent_set.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    vector G(N, vector<int>(N, 0));
    REP(i, M) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }

    auto res = maximum_independent_set(N, G);
    cout << res.size() << "\n";
    REP(i, res.size()) cout << res[i] << " \n"[i + 1 == res.size()];
}