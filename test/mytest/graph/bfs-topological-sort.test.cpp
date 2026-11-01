#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../graph/shortest-path/bfs.hpp"
#include "../../../graph/topological-sort.hpp"

int main() {
    assert(topological_sort(Graph<int>(0)).empty());
    mt19937 rng(20261104);
    for(int n = 1; n <= 10; ++n) for(int trial = 0; trial < 100; ++trial) {
        Graph<ll> g(n);
        vector<vector<int>> edges(n, vector<int>(n));
        vector<vector<int>> distance(n, vector<int>(n, 1000));
        for(int i = 0; i < n; ++i) distance[i][i] = 0;
        for(int u = 0; u < n; ++u) for(int v = 0; v < n; ++v) {
            if(rng() % 5) continue;
            // Include self-loops, parallel edges and non-unit stored costs.
            edges[u][v] = 1;
            g.add_directed_edge(u, v, 20);
            if(rng() % 2) g.add_directed_edge(u, v, 30);
            distance[u][v] = min(distance[u][v], 1);
        }
        for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
        for(int source = 0; source < n; ++source) for(ll initial : {-13LL, 0LL, 29LL}) {
            const ll unreachable = 1000000000000LL;
            auto [dist, prev] = bfs(g, source, initial, unreachable);
            auto defaults = bfs(g, source);
            auto initial_only = bfs(g, source, initial);
            assert(int(dist.size()) == n && int(prev.size()) == n);
            for(int v = 0; v < n; ++v) {
                if(distance[source][v] == 1000) {
                    assert(dist[v] == unreachable && prev[v] == -1);
                    assert(defaults.first[v] == numeric_limits<ll>::max());
                    assert(initial_only.first[v] == numeric_limits<ll>::max());
                    continue;
                }
                assert(dist[v] == initial + distance[source][v]);
                assert(defaults.first[v] == distance[source][v]);
                assert(initial_only.first[v] == dist[v]);
                int current = v, length = 0;
                while(current != source) {
                    int parent = prev[current];
                    assert(parent >= 0 && parent < n && edges[parent][current]);
                    assert(dist[parent] + 1 == dist[current]);
                    current = parent;
                    assert(++length <= n);
                }
                assert(prev[source] == -1 && length == distance[source][v]);
            }
        }
        auto order = topological_sort(g);
        vector<int> position(n, -1);
        for(int i = 0; i < int(order.size()); ++i) {
            int v = order[i];
            assert(0 <= v && v < n && position[v] == -1);
            position[v] = i;
        }
        // A vertex is omitted exactly when a directed cycle can reach it.
        for(int v = 0; v < n; ++v) {
            bool blocked = false;
            for(int u = 0; u < n; ++u) {
                bool cycle = edges[u][u];
                for(int k = 0; k < n; ++k) if(k != u) {
                    cycle |= distance[u][k] < 1000 && distance[k][u] < 1000;
                }
                blocked |= cycle && distance[u][v] < 1000;
            }
            assert((position[v] == -1) == blocked);
            if(position[v] != -1) for(int u = 0; u < n; ++u) if(edges[u][v]) {
                assert(position[u] >= 0 && position[u] < position[v]);
            }
        }
    }
    INT(a, b);
    print(a + b);
}
