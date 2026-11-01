#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../graph/graph_template.hpp"
#include "../../../graph/scc.hpp"
#include "../../../graph/shortest-path/dijkstra.hpp"
#include "../../../math/two_sat.hpp"


int main() {
    Edge<int> edge; edge = Edge<int>(2, 3);
    assert(edge.from == 2 && int(edge) == 3 && edge.cost == 1 && edge.id == -1);
    edge = Edge<int>(1, 2, 7, 4); assert(edge.to == 2 && edge.cost == 7 && edge.id == 4);
    Graph<int> undirected; undirected = Graph<int>(3); undirected.add_undirected_edge(0, 1);
    undirected.add_undirected_edge(1, 2, 7);
    const auto& const_graph = undirected;
    assert(const_graph.size() == 3 && const_graph[0][0].id == const_graph[1][0].id);
    assert(const_graph[1][1].cost == 7 && const_graph[2][0].from == 2);
    mt19937 rng(65);
    for(int n = 0; n <= 10; ++n) for(int trial = 0; trial < 20; ++trial) {
        Graph<ll> g(n); SCC<ll> built(n);
        const ll inf = 1000000000000LL;
        vector<vector<ll>> d(n, vector<ll>(n, inf));
        for(int i = 0; i < n; ++i) d[i][i] = 0;
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) if(rng() % 4 == 0) {
            ll w = rng() % 10; g.add_directed_edge(i, j, w); built.add_directed_edge(i, j); d[i][j] = min(d[i][j], w);
        }
        for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        SCC<ll> from_graph(g); built.build();
        set<int> ids;
        for(int i = 0; i < n; ++i) {
            ids.insert(built[i]);
            for(int j = 0; j < n; ++j) {
                bool same = d[i][j] < inf && d[j][i] < inf;
                assert((built[i] == built[j]) == same && (from_graph[i] == from_graph[j]) == same);
            }
        }
        assert(built.size() == ids.size() && from_graph.size() == ids.size());
        auto contracted = from_graph.get_contracted_graph();
        multiset<tuple<int, int, ll>> expected, actual;
        for(int u = 0; u < n; ++u) for(auto e : g[u]) if(from_graph[u] != from_graph[e.to]) {
            expected.emplace(from_graph[u], from_graph[e.to], e.cost);
        }
        for(int u = 0; u < int(contracted.size()); ++u) for(auto e : contracted[u]) {
            assert(u < e.to); actual.emplace(u, e.to, e.cost);
        }
        assert(actual == expected);
        for(int s = 0; s < n; ++s) {
            auto [distance, previous] = dijkstra(g, s, 17LL, inf);
            auto defaults = dijkstra(g, s); auto initial_only = dijkstra(g, s, 17LL);
            for(int v = 0; v < n; ++v) {
                if(d[s][v] == inf) {
                    assert(distance[v] == inf && previous[v] == -1);
                    assert(defaults.first[v] == LLONG_MAX && initial_only.first[v] == LLONG_MAX);
                } else {
                    assert(distance[v] == 17 + d[s][v] && defaults.first[v] == d[s][v] && initial_only.first[v] == distance[v]);
                    int u = v, length = 0;
                    while(u != s) {
                        int p = previous[u]; assert(p >= 0 && p < n);
                        bool found = false; for(auto e : g[p]) if(e.to == u && distance[p] + e.cost == distance[u]) found = true;
                        assert(found); u = p; assert(++length <= n);
                    }
                    assert(previous[s] == -1);
                }
            }
        }
    }
    for(int n = 0; n <= 5; ++n) for(int trial = 0; trial < 100; ++trial) {
        TwoSat sat(n); vector<tuple<int, bool, int, bool>> clauses;
        if(n) for(int k = 0; k < 10; ++k) {
            int i = rng() % n, j = rng() % n; bool a = rng() % 2, b = rng() % 2;
            clauses.emplace_back(i, a, j, b); sat.add_clause(i, a, j, b);
        }
        auto valid = [&](const vector<bool>& value) {
            for(auto [i, a, j, b] : clauses) if(value[i] != a && value[j] != b) return false;
            return true;
        };
        bool exists = false;
        for(int mask = 0; mask < (1 << n); ++mask) {
            vector<bool> values(n); for(int i = 0; i < n; ++i) values[i] = mask >> i & 1;
            exists |= valid(values);
        }
        assert(sat.satisfiable() == exists);
        if(exists) { auto answer = sat.get_answer(); assert(int(answer.size()) == n && valid(answer)); }
    }
    INT(a, b); print(a + b);
}
