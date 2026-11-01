#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"
#include "../../template/template.cpp"
#include "../../graph/shortest-path/bfs.hpp"

int main() {
    INT(N);
    Graph<int> g(N);
    REP(i, N) {
        INT(u, k);
        REP(j, k) {
            INT(v);
            g.add_directed_edge(u - 1, v - 1);
        }
    }
    auto [dist, prev] = bfs(g, 0);
    REP(i, N) {
        print(i + 1, dist[i] == numeric_limits<int>::max() ? -1 : dist[i]);
    }
}
