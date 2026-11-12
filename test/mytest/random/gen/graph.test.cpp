#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../../template/template.cpp"
#include "../../../../data-structure/unionfind.hpp"
#include "../../../../random/gen/graph.hpp"

bool is_simple(int n, const vector<pair<int, int>> &edges) {
    set<pair<int, int>> s;
    for(auto [u, v] : edges) {
        if(u < 0 || u >= n || v < 0 || v >= n || u == v) return false;
        if(!s.emplace(min(u, v), max(u, v)).second) return false;
    }
    return true;
}

bool is_connected(int n, const vector<pair<int, int>> &edges) {
    UnionFind uf(n);
    int comp = n;
    for(auto [u, v] : edges) comp -= uf.merge(u, v);
    return comp == 1;
}

bool is_acyclic(int n, const vector<pair<int, int>> &edges) {
    vector<vector<int>> g(n);
    vector<int> indeg(n);
    for(auto [u, v] : edges) g[u].push_back(v), indeg[v]++;
    vector<int> st;
    for(int i = 0; i < n; i++) if(!indeg[i]) st.push_back(i);
    int seen = 0;
    while(!st.empty()) {
        int u = st.back();
        st.pop_back();
        seen++;
        for(int v : g[u]) if(--indeg[v] == 0) st.push_back(v);
    }
    return seen == n;
}

int main() {
    Random rng(5);
    for(int n = 0; n <= 12; n++) {
        const long long total = (long long)n * (n - 1) / 2;
        for(long long m = 0; m <= total; m++) {
            auto g = random_simple_graph(rng, n, m);
            assert((long long)g.size() == m && is_simple(n, g));
            auto d = random_dag(rng, n, m);
            assert((long long)d.size() == m && is_simple(n, d) && is_acyclic(n, d));
            if(n >= 1 && m >= n - 1) {
                auto c = random_connected_graph(rng, n, m);
                assert((long long)c.size() == m && is_simple(n, c) && is_connected(n, c));
            }
        }
    }
    // 一様性: 4 頂点 3 辺の単純グラフは C(6, 3) = 20 通り
    {
        map<set<pair<int, int>>, int> cnt;
        for(int iter = 0; iter < 20000; iter++) {
            set<pair<int, int>> s;
            for(auto [u, v] : random_simple_graph(rng, 4, 3)) s.emplace(min(u, v), max(u, v));
            cnt[s]++;
        }
        assert(cnt.size() == 20);
        for(auto [s, c] : cnt) assert(700 < c && c < 1300);
    }
    // 疎な大きいグラフ (棄却側) と密なグラフ (列挙側)
    {
        auto g = random_connected_graph(rng, 100000, 200000);
        assert(g.size() == 200000 && is_simple(100000, g) && is_connected(100000, g));
        auto h = random_simple_graph(rng, 300, 300 * 299 / 2 - 5);
        assert(is_simple(300, h));
    }
    {
        auto w = add_random_weights(rng, random_tree(rng, 10), 1, 4LL);
        static_assert(is_same<decltype(w), vector<tuple<int, int, long long>>>::value);
        assert(w.size() == 9);
        for(auto [u, v, c] : w) assert(0 <= u && u < 10 && 0 <= v && v < 10 && 1 <= c && c < 4);
        assert(add_random_weights(rng, {}, 0, 1).empty());
    }
    INT(a, b);
    print(a + b);
}
