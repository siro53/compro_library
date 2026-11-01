#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"
#include "../../template/template.cpp"
#include "../../graph/topological-sort.hpp"

int main() {
    INT(N, M);
    Graph<int> g(N);
    REP(i, M) {
        INT(s, t);
        g.add_directed_edge(s, t);
    }
    auto order = topological_sort(g);
    if(int(order.size()) == N) {
        vector<int> position(N, -1);
        REP(i, N) {
            assert(position[order[i]] == -1);
            position[order[i]] = i;
        }
        REP(u, N) {
            for(const auto &e : g[u]) assert(position[u] < position[e.to]);
        }
    }
    print(int(order.size()) != N ? 1 : 0);
}
