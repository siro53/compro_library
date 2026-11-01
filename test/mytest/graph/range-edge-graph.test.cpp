#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../graph/range-edge-graph.hpp"
#include "../../../graph/shortest-path/dijkstra.hpp"

void regression_test() {
    mt19937 rng(53);
    for(int n = 1; n <= 10; n++) {
        RangeEdgeGraph<int> ranges(n, 30);
        Graph<int> naive(n);
        for(int step = 0; step < 30; step++) {
            int l = rng() % n, r = l + 1 + rng() % (n - l);
            int a = rng() % n, b = a + 1 + rng() % (n - a);
            int cost = rng() % 10;
            ranges.add_edge(l, r, a, b, cost);
            for(int u = l; u < r; u++) for(int v = a; v < b; v++) naive.add_directed_edge(u, v, cost);
            Graph<int> expanded = ranges;
            for(int s = 0; s < n; s++) {
                auto expected = dijkstra(naive, s).first;
                auto actual = dijkstra(expanded, s).first;
                for(int v = 0; v < n; v++) assert(actual[v] == expected[v]);
            }
        }
    }
}

int main() {
    regression_test();
    INT(a, b);
    print(a + b);
}
