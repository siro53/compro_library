#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../graph/tree/hld.hpp"
#include "../../../graph/tree/lca.hpp"
#include "../../../graph/tree/diameter.hpp"
#include "../../../graph/tree/centroid-decomposition.hpp"
#include "../../../graph/tree/tree-hash.hpp"
#include "../../../graph/namori.hpp"


int main() {
    mt19937 rng(66);
    for(int n = 1; n <= 20; ++n) {
        Graph<int> g(n); vector<vector<int>> d(n, vector<int>(n, 1000));
        for(int i = 0; i < n; ++i) d[i][i] = 0;
        vector<pair<int, int>> edges;
        for(int i = 1; i < n; ++i) { int p = rng() % i; g.add_undirected_edge(p, i); edges.emplace_back(p, i); d[i][p] = d[p][i] = 1; }
        for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        auto [length, path] = get_diameter(g);
        int expected_diameter = 0; for(auto& row : d) for(int x : row) expected_diameter = max(expected_diameter, x);
        assert(length == expected_diameter && int(path.size()) == length + 1);
        for(int i = 1; i < int(path.size()); ++i) assert(d[path[i - 1]][path[i]] == 1);
        for(int root : {0, n - 1}) {
            HeavyLightDecomposition<int> hld(n);
            for(auto [u, v] : edges) hld.add_edge(u, v);
            hld.build(root); HeavyLightDecomposition<int> copied(g);
            LCA<int> empty_lca;
            LCA<int> lca(g, root);
            LCA<int> default_root(g); assert(default_root.get_lca(0, n - 1) == 0);
            vector<int> parent(n, -1), depth(n), stack{root}, rev(n);
            for(int i = 0; i < int(stack.size()); ++i) for(int v : g[stack[i]]) if(v != parent[stack[i]]) {
                parent[v] = stack[i]; depth[v] = depth[stack[i]] + 1; stack.push_back(v);
            }
            for(int i = 0; i < n; ++i) rev[hld[i]] = i;
            for(int u = 0; u < n; ++u) {
                int ancestor = u;
                for(int k = 0; k <= depth[u] + 1; ++k) { assert(hld.la(u, k) == ancestor); if(ancestor != -1) ancestor = parent[ancestor]; }
                vector<int> subtree;
                hld.subtree_query(u, [&](int l, int r) { for(int i = l; i < r; ++i) subtree.push_back(rev[i]); });
                sort(subtree.begin(), subtree.end()); vector<int> wanted;
                for(int v = 0; v < n; ++v) { int x = v; while(x != -1 && x != u) x = parent[x]; if(x == u) wanted.push_back(v); }
                assert(subtree == wanted);
                for(int v = 0; v < n; ++v) {
                    int x = u, y = v; while(depth[x] > depth[y]) x = parent[x]; while(depth[y] > depth[x]) y = parent[y];
                    while(x != y) { x = parent[x]; y = parent[y]; }
                    assert(hld.lca(u, v) == x && lca.get_lca(u, v) == x);
                    assert(hld.dist(u, v) == d[u][v] && lca.get_dist(u, v) == d[u][v] && copied.dist(u, v) == d[u][v]);
                    for(bool edge : {false, true}) {
                        vector<int> actual, expected;
                        auto collect = [&](int l, int r) { for(int i = l; i < r; ++i) actual.push_back(rev[i]); };
                        hld.path_query(u, v, collect, edge);
                        for(int z = u; z != x; z = parent[z]) expected.push_back(z);
                        for(int z = v; z != x; z = parent[z]) expected.push_back(z);
                        if(!edge) expected.push_back(x);
                        sort(expected.begin(), expected.end()); sort(actual.begin(), actual.end()); assert(actual == expected);
                        actual.clear(); hld.path_query(u, v, collect, collect, edge); sort(actual.begin(), actual.end()); assert(actual == expected);
                    }
                }
            }
        }
        CentroidDecomposition centroid(g);
        assert(&centroid.G == &g && centroid.parent == vector<int>(n, -1) && centroid.removed == vector<bool>(n, false));
        centroid.get_subtree_size(0, -1); assert(centroid.subtree_size[0] == n);
        centroid.decomp(0, -1); assert(count(centroid.parent.begin(), centroid.parent.end(), -1) == 1);
        for(int u = 0; u < n; ++u) {
            assert(centroid.removed[u]);
            vector<int> component;
            for(int v = 0; v < n; ++v) { int x = v; while(x != -1 && x != u) x = centroid.parent[x]; if(x == u) component.push_back(v); }
            vector<bool> present(n); for(int v : component) present[v] = true; present[u] = false;
            for(int v : g[u]) if(present[v]) {
                vector<int> todo{v}; vector<bool> visited(n); visited[v] = true;
                for(int i = 0; i < int(todo.size()); ++i) for(int w : g[todo[i]]) if(present[w] && !visited[w]) { visited[w] = true; todo.push_back(w); }
                assert(todo.size() * 2 <= component.size());
            }
        }
        TreeHash<int> first(g), relabeled(n);
        vector<int> permutation(n); iota(permutation.begin(), permutation.end(), 0); shuffle(permutation.begin(), permutation.end(), rng);
        for(auto [u, v] : edges) relabeled.add_edge(permutation[u], permutation[v]);
        assert(first.get_hash() == relabeled.get_hash() && first.get_hash() == first.get_hash());
    }
    for(int cycle = 3; cycle <= 8; ++cycle) {
        int n = cycle + 15; Namori<int> graph(n); vector<int> attached(n);
        for(int i = 0; i < cycle; ++i) { graph.add_undirected_edge(i, (i + 1) % cycle); attached[i] = i; }
        for(int i = cycle; i < n; ++i) { int p = rng() % i; graph.add_undirected_edge(i, p); attached[i] = attached[p]; }
        assert(graph.size() == unsigned(n)); graph.build();
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) assert((graph[i] == graph[j]) == (attached[i] == attached[j]));
    }
    INT(a, b); print(a + b);
}
