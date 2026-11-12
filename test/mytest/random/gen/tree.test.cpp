#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../../template/template.cpp"
#include "../../../../data-structure/unionfind.hpp"
#include "../../../../random/gen/tree.hpp"

bool is_tree(int n, const vector<pair<int, int>> &edges) {
    if((int)edges.size() != n - 1) return false;
    UnionFind uf(n);
    for(auto [u, v] : edges) {
        if(u < 0 || u >= n || v < 0 || v >= n || !uf.merge(u, v)) return false;
    }
    return true;
}

vector<pair<int, int>> normalize(vector<pair<int, int>> edges) {
    for(auto &[u, v] : edges) if(u > v) swap(u, v);
    sort(edges.begin(), edges.end());
    return edges;
}

int main() {
    Random rng(11);
    // 一様性: 4 頂点のラベル付き木は 4^2 = 16 通り
    {
        map<vector<pair<int, int>>, int> cnt;
        for(int iter = 0; iter < 16000; iter++) {
            auto e = random_tree(rng, 4);
            assert(is_tree(4, e));
            cnt[normalize(e)]++;
        }
        assert(cnt.size() == 16);
        for(auto [e, c] : cnt) assert(700 < c && c < 1300);
    }
    // 向きも順序もランダム
    {
        bool forward = false, backward = false;
        set<vector<pair<int, int>>> orders;
        for(int iter = 0; iter < 200; iter++) {
            auto e = random_tree(rng, 3);
            for(auto [u, v] : e) (u < v ? forward : backward) = true;
            orders.insert(e);
        }
        assert(forward && backward && orders.size() > 6);
    }
    for(int n = 1; n <= 50; n++) {
        assert(is_tree(n, random_tree(rng, n)));
        auto path = random_path_tree(rng, n);
        assert(is_tree(n, path));
        vector<int> deg(n);
        for(auto [u, v] : path) deg[u]++, deg[v]++;
        for(int d : deg) assert(d <= 2);
        auto star = random_star_tree(rng, n);
        assert(is_tree(n, star));
        if(n >= 3) {
            vector<int> sd(n);
            for(auto [u, v] : star) sd[u]++, sd[v]++;
            assert(*max_element(sd.begin(), sd.end()) == n - 1);
        }
        auto par = random_parent_array(rng, n);
        assert((int)par.size() == n && par[0] == -1);
        for(int i = 1; i < n; i++) assert(0 <= par[i] && par[i] < i);
    }
    {
        set<int> centers;
        for(int iter = 0; iter < 200; iter++) {
            vector<int> sd(5);
            for(auto [u, v] : random_star_tree(rng, 5)) sd[u]++, sd[v]++;
            centers.insert(int(max_element(sd.begin(), sd.end()) - sd.begin()));
        }
        assert(centers.size() == 5);
    }
    {
        auto e = relabel_edges(rng, 3, {{0, 1}, {1, 2}});
        assert(is_tree(3, e));
        assert(relabel_edges(rng, 2, {}).empty());
    }
    INT(a, b);
    print(a + b);
}
