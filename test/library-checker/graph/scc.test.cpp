#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../../../template/template.cpp"
#include "../../../graph/scc.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    SCC scc(N);
    REP(i, M) {
        int from, to;
        cin >> from >> to;
        scc.add_directed_edge(from, to);
    }
    scc.build();

    vector<vector<int>> res(scc.size());
    REP(i, N) res[scc[i]].push_back(i);
    cout << scc.size() << '\n';
    REP(i, SZ(res)) {
        cout << SZ(res[i]) << ' ';
        REP(j, SZ(res[i])) cout << res[i][j] << " \n"[j + 1 == SZ(res[i])];
    }
}