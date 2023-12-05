#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2821"
#include "../../template/template.cpp"
#include "../../graph/tree/tree-hash.hpp"

int main() {
    INT(N1, M1);
    Graph<int> G1(N1);
    for(int i = 0; i < M1; i++) {
        INT(a, b);
        a--;
        b--;
        G1.add_undirected_edge(a, b);
    }
    INT(N2);
    TreeHash<int> G2(N2);
    for(int i = 0; i < N2 - 1; i++) {
        INT(a, b);
        a--;
        b--;
        G2.add_edge(a, b);
    }
    auto g2hash = G2.get_hash();

    int ans = 0;
    vector<bool> used(N1, false);

    for(int i = 0; i < N1; i++) {
        if(!used[i]) {
            map<int, int> toid;
            int sz = 0;
            auto dfs1 = [&](auto &&dfs1, int v, int p, int &k) -> void {
                used[v] = true;
                toid[v] = k++;
                for(const auto& e : G1[v]) {
                    if(e.to != p) {
                        dfs1(dfs1, e.to, v, k);
                    }
                }
            };
            dfs1(dfs1, i, -1, sz);
            TreeHash<int> g1(sz);
            auto dfs2 = [&](auto &&dfs2, int v, int p) -> void {
                for(const auto& e : G1[v]) {
                    if(e.to == p) {
                        continue;
                    }
                    g1.add_edge(toid[e.to], toid[v]);
                    dfs2(dfs2, e.to, v);
                }
            };
            dfs2(dfs2, i, -1);
            auto g1hash = g1.get_hash();
            ans += (g1hash == g2hash);
        }
    }

    print(ans);
}